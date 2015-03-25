package;

import hxDaedalus.ai.EntityAI;
import hxDaedalus.ai.PathFinder;
import hxDaedalus.ai.trajectory.LinearPathSampler;
import hxDaedalus.data.Mesh;
import hxDaedalus.data.Object;
import hxDaedalus.factories.BitmapObject;
import hxDaedalus.factories.RectMesh;
import hxDaedalus.graphics.TargetCanvas;
import hxDaedalus.view.SimpleView;
import luxe.Input.Key;
import luxe.Input.KeyEvent;
import luxe.Input.MouseEvent;
import luxe.Parcel;
import luxe.ParcelProgress;
import luxe.Sprite;
import luxe.Vector;
import phoenix.Texture;


class Main extends luxe.Game {

    var mouse:Vector = new Vector(0, 0);

	var _inited:Bool = false;
	
	var _mesh:Mesh;
	var _entityAI:EntityAI;
	var _pathfinder:PathFinder;
	var _path:Array<Float>;
	var _pathSampler:LinearPathSampler;
	var _object:Object;
	var _meshView:SimpleView;
	var _pathView:SimpleView;

    var _newPath:Bool = false;

	var textureColor:Texture;
	var textureBW:Texture;
	
	// entry point
    override function ready() {

        // fetch a list of assets to load from the json file
        Luxe.loadJSON('assets/parcel.json', function (asset):Void {

			// then create a parcel to load it for us
			var parcel = new Parcel();
			parcel.from_json(asset.json);

			// but, we also want a progress bar for the parcel,
			// this is a default one, you can do your own
			new ParcelProgress({
				parcel      : parcel,
				oncomplete  : onLoaded
			});

			// go!
			parcel.load();
			
		});

    } // ready

	function onLoaded(_):Void {
		
		// load the images
		textureColor = Luxe.loadTexture("assets/galapagosColor.png");
		textureBW = Luxe.loadTexture("assets/galapagosBW.png");
		
		// build a rectangular 2 polygons mesh
		_mesh = RectMesh.buildRectangle( 1024, 780 );
		
		// show the image
		var galapagos = new Sprite({
			texture: textureColor,
			centered: false,
			depth: -1
		});
		
		_meshView = new SimpleView(new TargetCanvas());
		_pathView = new SimpleView(new TargetCanvas());
		
		// create an object from texture
		_object = BitmapObject.buildFromBmpData( textureBW, 1.8 );
		_object.x = 0;
		_object.y = 0;

		_mesh.insertObject( _object );

		// display result mesh
		
		// draw the mesh
		_meshView.drawMesh( _mesh );
		
		// we need an entity
		_entityAI = new EntityAI();
		
		// set radius size for your entity
		_entityAI.radius = 4;
		
		// set a position
		_entityAI.x = 50;
		_entityAI.y = 50;
		
		// show entity on screen
		_pathView.drawEntity( _entityAI, false );
		
		// now configure the pathfinder
		_pathfinder = new PathFinder();
		_pathfinder.entity = _entityAI; // set the entity
		_pathfinder.mesh = _mesh; // set the mesh
		
		// we need a vector to store the path
		_path = new Array<Float>();
		
		// then configure the path sampler
		_pathSampler = new LinearPathSampler();
		_pathSampler.entity = _entityAI;
		_pathSampler.samplingDistance = 10;
		_pathSampler.path = _path;

		_inited = true;
	}
	
    override function onmousedown( e:MouseEvent ) {
        
		mouse.set_xy(e.x,e.y);
		_newPath = true;
		
    } //onmousedown

    override function onmouseup( e:MouseEvent ) {

        mouse.set_xy(e.x,e.y);
		_newPath = false;
		
    } //onmouseup

    override function onmousemove( e:MouseEvent ) {
        
		mouse.set_xy(e.x,e.y);
		
    } //onmousemove

	override function onkeyup(e:KeyEvent) {

        if (e.keycode == Key.escape) {
            Luxe.shutdown();
        }

    } // onkeyup

    override function update(dt:Float) {
		if (!_inited) return;
		
		if ( _newPath ) {
			
			_pathView.graphics.clear();

			// find path !
            _pathfinder.findPath( mouse.x, mouse.y, _path );
            
			// show path on screen
            _pathView.drawPath( _path );
            
			// reset the path sampler to manage new generated path
            _pathSampler.reset();
            
			// show entity position on screen
			_pathView.drawEntity(_entityAI);
        }
        
        // animate !
        if ( _pathSampler.hasNext ) {
			
			// move entity
            _pathSampler.next();            
            
			// show entity position on screen
			_pathView.drawEntity(_entityAI);
        }
		
    } // update

} // Main