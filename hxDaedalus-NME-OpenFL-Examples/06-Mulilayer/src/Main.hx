package;

import hxDaedalus.ai.EntityAI;
import hxDaedalus.ai.PathFinder;
import hxDaedalus.ai.trajectory.LinearPathSampler;
import hxDaedalus.data.Mesh;
import hxDaedalus.data.Object;
import hxDaedalus.factories.BitmapObject;
import hxDaedalus.factories.RectMesh;
import hxDaedalus.view.SimpleView;

import flash.display.MovieClip;
import flash.display.Stage;
import flash.events.Event;
import flash.events.MouseEvent;
import flash.display.Bitmap;
import flash.display.Sprite;
import flash.events.KeyboardEvent;
import flash.geom.Matrix;
import flash.Lib;
import hxDaedalus.data.math.Point2D;

typedef Portals = {
	p1: Point2D,
	p2: Point2D
}

@:bitmap("assets/lower.png")
class Lower extends flash.display.BitmapData {}

@:bitmap("assets/upper.png")
class Upper extends flash.display.BitmapData {}

@:bitmap("assets/castle.png")
class Castle extends flash.display.BitmapData {}

class Main extends Sprite {

	var _meshLower: Mesh;
	var _meshUpper: Mesh;
	var _viewLower: SimpleView;
	var _viewUpper: SimpleView;
	var _entityAILower: EntityAI;
	var _entityAIUpper: EntityAI;
	var _pathfinderLower:PathFinder;
	var _pathfinderUpper:PathFinder;
	var _pathLower: Array<Float>;
	var _pathUpper: Array<Float>;
	var _pathSamplerLower: LinearPathSampler;
	var _pathSamplerUpper: LinearPathSampler;
	var _objectUpper: Object;
	var _objectLower: Object;
	var _bmpLower:Bitmap;
	var _bmpUpper:Bitmap;
	var _overlay: Bitmap;
	var _matrixLower: Matrix;
	var _matrixUpper: Matrix;
	var viewSpriteLower: Sprite;
	var viewSpriteUpper: Sprite;
	var _portals: Array<Portals>;
    var _newPath:Bool = false;
	
	public static function main(): Void {
		Lib.current.addChild(new Main());
	}

	public function new() {
		super();
		
		// build a rectangular 2 polygons mesh
		_meshLower = RectMesh.buildRectangle( 450, 450 );
		_meshUpper = RectMesh.buildRectangle( 450, 450 );
		
		// show the source bmp
    #if html5	// load as openfl asset: see application.xml
        _bmpLower = new Bitmap(openfl.Assets.getBitmapData("Lower"));
		_bmpUpper= new Bitmap(openfl.Assets.getBitmapData("Upper"));
		
    #else		
        _bmpLower = new Bitmap(new Lower(0, 0));
		_bmpUpper = new Bitmap(new Upper(0, 0));
	#end
		_bmpLower.x = 0;// 14;
		_bmpLower.y = 0;// 30;
		_bmpUpper.x = 0;// 519;
		_bmpUpper.y = 0;// 29;
		
		// show the image bmp
    #if html5	// load as openfl asset: see application.xml
        _overlay = new Bitmap(openfl.Assets.getBitmapData("Castle"));
    #else		
        _overlay = new Bitmap(new Castle(0, 0));	
	#end
		_overlay.x = 0;
		_overlay.y = 0;
		_overlay.alpha = 0.3;
		addChild(_overlay);
		
		viewSpriteLower = new Sprite();
		viewSpriteLower.x = 14;
		viewSpriteLower.y = 30;
		_viewLower = new SimpleView(viewSpriteLower.graphics);
		addChild( viewSpriteLower );
		
		viewSpriteUpper = new Sprite();
		viewSpriteUpper.x = 519;
		viewSpriteUpper.y = 29;
		addChild( viewSpriteUpper );
		_viewUpper = new SimpleView(viewSpriteUpper.graphics);

		
		// create an object from bitmap
		_objectLower = BitmapObject.buildFromBmpData( _bmpLower.bitmapData, 1.8 );
		_objectLower.x = 0;
		_objectLower.y = 0;
		
		_objectUpper = BitmapObject.buildFromBmpData( _bmpUpper.bitmapData, 1.8 );
		_objectUpper.x = 0;
		_objectUpper.y = 0;
		
		var s = haxe.Timer.stamp();
		_meshLower.insertObject( _objectLower );
		_meshUpper.insertObject( _objectUpper );
		
		// display result mesh
		
		// draw the mesh
		_viewUpper.drawMesh( _meshUpper );
		_viewLower.drawMesh( _meshLower );
		
		// setup offset matrix
		_matrixLower = new Matrix();
		_matrixLower.translate( 14, 30 );
		
		_matrixUpper = new Matrix();
		_matrixUpper.translate( 519, 29 );
		
		// stamp it on the overlay bitmap
		_overlay.bitmapData.draw(viewSpriteLower,_matrixLower );
		_overlay.bitmapData.draw(viewSpriteUpper, _matrixUpper );
		
		// we need an entity
		_entityAILower = new EntityAI();
		_entityAIUpper = new EntityAI();
		
		// set radius size for your entity
		_entityAILower.radius = 2;
		_entityAIUpper.radius = 2;
		
		// set a position
		_entityAILower.x = 50;
		_entityAILower.y = 50;
		// set a position
			_entityAIUpper.x = 702 - 519;
			_entityAIUpper.y = 180 - 29;
		
		// show entity on screen
		_viewLower.drawEntity( _entityAILower, false );
		_viewUpper.drawEntity( _entityAIUpper, false );
		
		// now configure the pathfinder
		_pathfinderLower = new PathFinder();
		_pathfinderLower.entity = _entityAILower; // set the entity
		_pathfinderLower.mesh = _meshLower; // set the mesh
		
		// now configure the pathfinder
		_pathfinderUpper = new PathFinder();
		_pathfinderUpper.entity = _entityAIUpper; // set the entity
		_pathfinderUpper.mesh = _meshUpper; // set the mesh
		
		// we need a vector to store the path
		_pathLower = new Array<Float>();
		_pathUpper = new Array<Float>();
		
		// then configure the path sampler
		_pathSamplerLower = new LinearPathSampler();
		_pathSamplerLower.entity = _entityAILower;
		_pathSamplerLower.samplingDistance = 5;
		_pathSamplerLower.path = _pathLower;

		// then configure the path sampler
		_pathSamplerUpper = new LinearPathSampler();
		_pathSamplerUpper.entity = _entityAIUpper;
		_pathSamplerUpper.samplingDistance = 3;
		_pathSamplerUpper.path = _pathUpper;
		
		_portals = [  { p1: new Point2D( 184, 179 ), p2: new Point2D( 702, 180 ) }, 
					  { p1: new Point2D( 274, 179 ), p2: new Point2D( 765, 180 ) },
					  { p1: new Point2D( 107, 331 ), p2: new Point2D( 613, 332 ) } ];
		
		// click/drag
		Lib.current.stage.addEventListener(MouseEvent.MOUSE_DOWN, _onMouseDown);
		Lib.current.stage.addEventListener(MouseEvent.MOUSE_UP, _onMouseUp);
		
		// animate
		Lib.current.stage.addEventListener(Event.ENTER_FRAME, _onEnterFrame);
		
		// key presses
		Lib.current.stage.addEventListener(KeyboardEvent.KEY_DOWN, _onKeyDown);
		
		//var fps = new openfl.display.FPS();
		//Lib.current.stage.addChild(fps);
		/**/
	}
	
    function _onMouseUp( event: MouseEvent ): Void {
		_newPath = false;
    }
    
    function _onMouseDown( event: MouseEvent ): Void {
        _newPath = true;
    }
    
    function _onEnterFrame( event: Event ): Void {
		if (_newPath) {
			_viewLower.graphics.clear();
			_viewUpper.graphics.clear();	
			// stamp it on the overlay bitmap
			//_overlay.bitmapData.draw(viewSpriteLower,_matrixLower );
			//_overlay.bitmapData.draw(viewSpriteUpper,_matrixUpper );
		}
		if ( _newPath ) {
			

			// find path !
			var lowerTemp = [];
			var upperTemp = [];
			var portal: Portals;
			var choosenI: Int =0;
			for ( i in 0..._portals.length )
			{			
				_entityAILower.x = 50;
				_entityAILower.y = 50;
				portal = _portals[i];				
				// reset the path sampler to manage new generated path
				_pathSamplerUpper.reset();
				// reset the path sampler to manage new generated path
				_pathSamplerLower.reset(); 
				_pathfinderLower.findPath( portal.p1.x - 14, portal.p1.y - 30, lowerTemp );
				_entityAIUpper.x = portal.p2.x - 519;
				_entityAIUpper.y = portal.p2.y - 29;
				_pathfinderUpper.findPath( stage.mouseX - 519, stage.mouseY - 29, upperTemp );			
				if ( i == 0 )
				{
					choosenI = 0;
					_pathLower = lowerTemp.slice( 0 );
					_pathUpper = upperTemp.slice( 0 );
				}
				else if( (lowerTemp.length + upperTemp.length) < (_pathLower.length + _pathUpper.length) )
				{
					choosenI = i;
					_pathLower = lowerTemp.slice( 0 );
					_pathUpper = upperTemp.slice( 0 );
				}
			}
			//portal = _portals[choosenI];		
			
			_pathSamplerLower.path = _pathLower;
			_pathSamplerUpper.path = _pathUpper;
			
			if ( _pathSamplerLower.hasNext && _pathSamplerUpper.hasNext ) {
				// show path on screen
				_viewLower.drawPath( _pathLower );
				// show path on screen
				_viewUpper.drawPath( _pathUpper );
			}
        }

        // animate !
        if ( _pathSamplerLower.hasNext && _pathSamplerUpper.hasNext ) {
			// move entity
            _pathSamplerLower.next();            
        } else if ( _pathSamplerUpper.hasNext ) {
			// move entity
            _pathSamplerUpper.next();            
        }
		
		// show entity position on screen
		_viewLower.drawEntity(_entityAILower );
		_viewUpper.drawEntity(_entityAIUpper );
    }
	
	function _onKeyDown(event:KeyboardEvent):Void
	{
		if (event.keyCode == 27) {  // ESC
			#if flash
				flash.system.System.exit(1);
			#elseif sys
				Sys.exit(1);
			#end
		}
	}
	
}