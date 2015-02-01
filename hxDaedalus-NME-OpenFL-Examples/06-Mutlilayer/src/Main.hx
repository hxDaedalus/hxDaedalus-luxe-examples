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

import Layer;
import Interconnect;
import WithinLayer;


@:bitmap("assets/lower.png")
class Lower extends flash.display.BitmapData {}

@:bitmap("assets/upper.png")
class Upper extends flash.display.BitmapData {}

@:bitmap("assets/castle.png")
class Castle extends flash.display.BitmapData {}

class Main extends Sprite {
	
	var bmpLower:Bitmap;
	var bmpUpper:Bitmap;
	var overlay: Bitmap;
	var portals: Array<Portal> = [  	{ p1: new Point2D( 184, 179 ), p2: new Point2D( 702, 180 ) }, 
					  					{ p1: new Point2D( 274, 179 ), p2: new Point2D( 765, 180 ) },
					  				  	{ p1: new Point2D( 107, 331 ), p2: new Point2D( 613, 332 ) } ];
	var interconnect: Interconnect;
    var newPath:Bool = false;
	var upper: Layer;
	var lower: Layer;
	var lowerPos: Point2D = new Point2D(14,30);
	var upperPos: Point2D = new Point2D(519,29);
	var start: Point2D = new Point2D( 50, 50 );
	var end: Point2D = new Point2D( 50, 50 );
	var drawUpperPath: Bool = false;
	var lastHitLayer: Layer = null;
	var twoLayers: Bool;
	var withinLayer: WithinLayer;
	var betweenLayer: BetweenLayer;
	var enableAnimate: Bool = false;
	
	public static function main(): Void {
		Lib.current.addChild(new Main());
	}

	public function new() {
		super();
		
		// show the image bmp
    #if html5	// load as openfl asset: see application.xml
        overlay = new Bitmap(openfl.Assets.getBitmapData("Castle"));
    #else		
        overlay = new Bitmap(new Castle(0, 0));	
	#end
		overlay.x = 0;
		overlay.y = 0;
		overlay.alpha = 0.3;
		addChild(overlay);
		
		
		// show the source bmp
    #if html5	// load as openfl asset: see application.xml
        bmpLower = new Bitmap(openfl.Assets.getBitmapData("Lower"));
		bmpUpper= new Bitmap(openfl.Assets.getBitmapData("Upper"));
		
    #else		
        bmpLower = new Bitmap(new Lower(0, 0));
		bmpUpper = new Bitmap(new Upper(0, 0));
	#end
		bmpLower.x = 0;// 14;
		bmpLower.y = 0;// 30;
		bmpUpper.x = 0;// 519;
		bmpUpper.y = 0;// 29;
		//702 - _upperPos.x;
		
		lower = new Layer( this, new Point2D( 50, 50 ),lowerPos, bmpLower,'ground' );
		upper = new Layer( this, new Point2D( portals[0].p2.x- upperPos.x, portals[0].p2.y - upperPos.y ), upperPos, bmpUpper, 'first floor' );
		
		interconnect = new Interconnect( lower, upper, portals );
		withinLayer = new WithinLayer();
		betweenLayer = new BetweenLayer( interconnect );
		
		
		var s = haxe.Timer.stamp();
		
		var stage = Lib.current.stage;
		// click/drag
		stage.addEventListener(MouseEvent.MOUSE_DOWN, onMouseDown);
		stage.addEventListener(MouseEvent.MOUSE_UP, onMouseUp);
		
		// animate
		stage.addEventListener(Event.ENTER_FRAME, onEnterFrame);
		
		// key presses
		stage.addEventListener(KeyboardEvent.KEY_DOWN, onKeyDown);
		
		//var fps = new openfl.display.FPS();
		//Lib.current.stage.addChild(fps);
		/**/
	}
	
    function onMouseUp( event: MouseEvent ): Void {
		newPath = false;
    }
    
	
    function onMouseDown( event: MouseEvent ): Void {
		// find path !
		var mX = stage.mouseX;
		var mY = stage.mouseY;
		end = new Point2D( mX, mY );
		var isLowerHit = lower.hitTest( mX, mY );
		var isUpperHit = upper.hitTest( mX, mY );
		interconnect.clear();
		if( isLowerHit && lower != lastHitLayer ){
			lastHitLayer = lower;
			twoLayers = true;
			betweenLayer.setup( start, end, upper );
			enableAnimate = true;
		} else if( isUpperHit && upper != lastHitLayer ){
			lastHitLayer = upper;
			twoLayers = true;
			betweenLayer.setup( start, end, lower );
			enableAnimate = true;
		} else {
			twoLayers = false;
			if( isUpperHit )
			{
				lastHitLayer = upper;
				withinLayer.setup( mX, mY, upper );
				enableAnimate = true;
			} else if( isLowerHit ){
				lastHitLayer = lower;
				withinLayer.setup( mX, mY, lower );
				enableAnimate = true;
			} else{
				enableAnimate = false;
				return;
			}
		}
		newPath = true;
    }
    
    function onEnterFrame( event: Event ): Void {
		
		if (!newPath && enableAnimate ) {
			if( twoLayers = true ){
		        // animate !
				betweenLayer.animate();
			} else {
		        // animate !
		        withinLayer.animate();
			}
		}
    }
	
	function onKeyDown(event:KeyboardEvent):Void
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