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

    var mesh : Mesh;

	var pathView:SimpleView;
	var meshView:SimpleView;
    
    var entityAI : EntityAI;
    var pathfinder : PathFinder;
    var path : Array<Float>;
    var pathSampler : LinearPathSampler;
    
    var newPath:Bool = false;
	
	var rows:Int = 15;
	var cols:Int = 15;
	
	// entry point
    override function ready() {
		
		// white background
		Luxe.renderer.clear_color.rgb(0xFFFFFF);
		
		// build a rectangular 2 polygons mesh of 600x600
        mesh = RectMesh.buildRectangle(600, 600);
        
        // create viewports
		meshView = new SimpleView(new TargetCanvas());
        pathView = new SimpleView(new TargetCanvas());
        
		GridMaze.generate(600, 600, cols, rows);
		mesh.insertObject(GridMaze.object);
		
		meshView.constraintsWidth = 4;
        meshView.drawMesh(mesh);
		
        // we need an entity
        entityAI = new EntityAI();
        // set radius as size for your entity
        entityAI.radius = GridMaze.tileWidth * .3;
        // set a position
        entityAI.x = GridMaze.tileWidth / 2;
        entityAI.y = GridMaze.tileHeight / 2;
        
        // show entity on screen
        pathView.drawEntity(entityAI);
        
        // now configure the pathfinder
        pathfinder = new PathFinder();
        pathfinder.entity = entityAI;  // set the entity  
        pathfinder.mesh = mesh;  // set the mesh  
        
        // we need a vector to store the path
        path = new Array<Float>();
        
        // then configure the path sampler
        pathSampler = new LinearPathSampler();
        pathSampler.entity = entityAI;
        pathSampler.samplingDistance = GridMaze.tileWidth * .7;
        pathSampler.path = path;
        
    } // ready

    override function onmousedown( e:MouseEvent ) {
        
		mouse.set_xy(e.x,e.y);
		newPath = true;
		
    } //onmousedown

    override function onmouseup( e:MouseEvent ) {

        mouse.set_xy(e.x,e.y);
		newPath = false;
		
    } //onmouseup

    override function onmousemove( e:MouseEvent ) {
        
		mouse.set_xy(e.x,e.y);
		
    } //onmousemove

	override function onkeyup(e:KeyEvent) {

        if (e.keycode == Key.escape) {
            Luxe.shutdown();
        } else if (e.keycode == Key.space) {
			reset(true);
		} else if (e.keycode == Key.enter) {
			reset(false);
		}

    } // onkeyup

    override function update(dt:Float) {

		if ( newPath ) {
			
			pathView.graphics.clear();

			// find path !
            pathfinder.findPath( mouse.x, mouse.y, path );
            
			// show path on screen
            pathView.drawPath( path );
            
			// reset the path sampler to manage new generated path
            pathSampler.reset();
            
			// show entity position on screen
			pathView.drawEntity(entityAI);
        }
        
        // animate !
        if ( pathSampler.hasNext ) {
			
			// move entity
            pathSampler.next();            
            
			// show entity position on screen
			pathView.drawEntity(entityAI);
        }

	} // update
	
	function reset(newMaze:Bool = false):Void {
		var seed = Std.int(Math.random() * 10000 + 1000);
		if (newMaze) {
			mesh = RectMesh.buildRectangle(600, 600);
			GridMaze.generate(600, 600, 30, 30, seed);
			GridMaze.object.scaleX = .92;
			GridMaze.object.scaleY = .92;
			GridMaze.object.x = 23;
			GridMaze.object.y = 23;
			mesh.insertObject(GridMaze.object);
			meshView.drawMesh(mesh, true);
		}
        entityAI.radius = GridMaze.tileWidth * .27;
        pathSampler.samplingDistance = GridMaze.tileWidth * .7;
		pathfinder.mesh = mesh;
		entityAI.x = GridMaze.tileWidth / 2;
		entityAI.y = GridMaze.tileHeight / 2;
		pathView.drawEntity(entityAI, true);
		path = [];
		pathSampler.path = path;
	}

} // Main