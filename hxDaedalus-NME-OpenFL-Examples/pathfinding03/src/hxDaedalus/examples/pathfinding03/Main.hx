package hxDaedalus.examples.pathfinding03;

import hxDaedalus.ai.EntityAI;
import hxDaedalus.ai.PathFinder;
import hxDaedalus.ai.trajectory.LinearPathSampler;
import hxDaedalus.data.Mesh;
import hxDaedalus.data.Object;
import hxDaedalus.data.math.Point2D;
import hxDaedalus.data.math.RandGenerator;
import hxDaedalus.factories.RectMesh;
import hxDaedalus.view.SimpleView;

import flash.Lib;
import flash.display.Sprite;
import flash.events.Event;
import flash.events.MouseEvent;
import flash.events.KeyboardEvent;

class Main extends Sprite 
{
	var inited:Bool;

	/* ENTRY POINT */
	var _mesh : Mesh;
    var _view : SimpleView;
    
    var _entityAI : EntityAI;
    var _pathfinder : PathFinder;
    var _path : Array<Float>;
    var _pathSampler : LinearPathSampler;
    
    var _newPath:Bool = false;
	
	function resize(e) 
	{
		if (!inited) init();
		// else (resize or orientation change)
	}
	
	function init() 
	{
		if (inited) return;
		inited = true;

        // build a rectangular 2 polygons mesh of 600x600
        _mesh = RectMesh.buildRectangle(600, 600);
		
        // create a viewport
		var viewSprite = new Sprite();
        _view = new SimpleView(viewSprite.graphics);
        addChild(viewSprite);
        
		var meshView = new SimpleView(this.graphics);
		
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
        
        meshView.drawMesh(_mesh);
		
        // we need an entity
        _entityAI = new EntityAI();
        // set radius as size for your entity
        _entityAI.radius = 4;
        // set a position
        _entityAI.x = 20;
        _entityAI.y = 20;
        
        // show entity on screen
        _view.drawEntity(_entityAI);
        
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
        
        // click/drag
        Lib.current.stage.addEventListener(MouseEvent.MOUSE_DOWN, _onMouseDown);
        Lib.current.stage.addEventListener(MouseEvent.MOUSE_UP, _onMouseUp);
        
        // animate
        Lib.current.stage.addEventListener(Event.ENTER_FRAME, _onEnterFrame);
        
        // key presses
        Lib.current.stage.addEventListener(KeyboardEvent.KEY_DOWN, _onKeyDown);
		
	#if openfl
		var fps = new openfl.display.FPS();
		Lib.current.stage.addChild(fps);
	#end
	}
    
    function _onMouseUp( event: MouseEvent ): Void {
		_newPath = false;
    }
    
    function _onMouseDown( event: MouseEvent ): Void {
        _newPath = true;
    }
    
    function _onEnterFrame( event: Event ): Void {
		if (_newPath) _view.graphics.clear();

        if ( _newPath ) {
            // find path !
            _pathfinder.findPath( stage.mouseX, stage.mouseY, _path );
            
			// show path on screen
            _view.drawPath( _path );
            
			// reset the path sampler to manage new generated path
            _pathSampler.reset();
        }
        
        // animate !
        if ( _pathSampler.hasNext ) {
            // move entity
            _pathSampler.next();            
        }
		
		// show entity position on screen
		_view.drawEntity(_entityAI);
    }
    
    function _onKeyDown( event:KeyboardEvent ): Void {
        if( event.keyCode == 27 ) {  // ESC
		#if flash
			flash.system.System.exit(1);
		#elseif sys
			Sys.exit(1);
		#end
        }
    }		

	/* SETUP */

	public function new() 
	{
		super();	
		addEventListener(Event.ADDED_TO_STAGE, added);
	}

	function added(e) 
	{
		removeEventListener(Event.ADDED_TO_STAGE, added);
		stage.addEventListener(Event.RESIZE, resize);
		#if ios
		haxe.Timer.delay(init, 100); // iOS 6
		#else
		init();
		#end
	}
	
	public static function main() 
	{
		// static entry point
		Lib.current.stage.align = flash.display.StageAlign.TOP_LEFT;
		Lib.current.stage.scaleMode = flash.display.StageScaleMode.NO_SCALE;
		Lib.current.addChild(new Main());
	}
}
