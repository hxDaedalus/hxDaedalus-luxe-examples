package;

import hxDaedalus.ai.EntityAI;
import hxDaedalus.ai.PathFinder;
import hxDaedalus.ai.trajectory.LinearPathSampler;
import hxDaedalus.data.math.RandGenerator;
import hxDaedalus.data.Mesh;
import hxDaedalus.data.Object;
import hxDaedalus.factories.RectMesh;
import hxDaedalus.graphics.TargetCanvas;
import hxDaedalus.view.SimpleView;
import luxe.Input.Key;
import luxe.Input.KeyEvent;
import luxe.Input.MouseEvent;
import luxe.Vector;


class Main extends luxe.Game {

    var mouse : Vector = new Vector(0, 0);

    var _mesh : Mesh;
    var _meshView : SimpleView;
    var _pathView : SimpleView;
    
    var _entityAI : EntityAI;
    var _pathfinder : PathFinder;
    var _path : Array<Float>;
    var _pathSampler : LinearPathSampler;
    
    var _newPath:Bool = false;
	
	// entry point
    override function ready() {
		
		// white background
		Luxe.renderer.clear_color.rgb(0xFFFFFF);
		
        // build a rectangular 2 polygons mesh of 600x600
        _mesh = RectMesh.buildRectangle(600, 600);
		
        // create viewports
        _pathView = new SimpleView(new TargetCanvas());
		_meshView = new SimpleView(new TargetCanvas());
		
        // pseudo random generator
        var randGen : RandGenerator;
        randGen = new RandGenerator();
        randGen.seed = 7259;  // put a 4 digits number here  
        
        // populate mesh with many square objects
        var object : Object;
        var shapeCoords : Array<Float>;
        for (i in 0...50){
            object = new Object();
            shapeCoords = new Array<Float>();
            shapeCoords = [ -1, -1, 1, -1,
                             1, -1, 1, 1,
                            1, 1, -1, 1,
                            -1, 1, -1, -1];
            object.coordinates = shapeCoords;
            randGen.rangeMin = 10;
            randGen.rangeMax = 40;
            object.scaleX = randGen.next();
            object.scaleY = randGen.next();
            randGen.rangeMin = 0;
            randGen.rangeMax = 1000;
            object.rotation = (randGen.next() / 1000) * Math.PI / 2;
            randGen.rangeMin = 50;
            randGen.rangeMax = 600;
            object.x = randGen.next();
            object.y = randGen.next();
            _mesh.insertObject(object);
        }  // show result mesh on screen  
        
        _meshView.drawMesh(_mesh);
		
        // we need an entity
        _entityAI = new EntityAI();
        // set radius as size for your entity
        _entityAI.radius = 4;
        // set a position
        _entityAI.x = 20;
        _entityAI.y = 20;
        
        // show entity on screen
        _pathView.drawEntity(_entityAI);
        
        // now configure the pathfinder
        _pathfinder = new PathFinder();
        _pathfinder.entity = _entityAI;  // set the entity  
        _pathfinder.mesh = _mesh;  // set the mesh  
        
        // we need a vector to store the path
        _path = new Array<Float>();
        
        // then configure the path sampler
        _pathSampler = new LinearPathSampler();
        _pathSampler.entity = _entityAI;
        _pathSampler.samplingDistance = 10;
        _pathSampler.path = _path;
        
    } // ready

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