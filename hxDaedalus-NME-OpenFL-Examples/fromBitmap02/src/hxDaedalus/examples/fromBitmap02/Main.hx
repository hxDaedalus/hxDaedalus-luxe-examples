package hxDaedalus.examples.fromBitmap02;

import hxDaedalus.data.Mesh;
import hxDaedalus.data.Object;
import hxDaedalus.factories.BitmapObject;
import hxDaedalus.factories.RectMesh;
import hxDaedalus.view.SimpleView;
import flash.Lib;
import flash.display.Bitmap;
import flash.display.Sprite;
import flash.display.BitmapData;
import flash.events.Event;
import flash.events.KeyboardEvent;

@:bitmap("assets/img/FromBitmap.png")
class TestImage extends flash.display.BitmapData { }

class Main extends Sprite 
{
	var inited:Bool;

	/* ENTRY POINT */
	var _mesh : Mesh;
	var _view : SimpleView;
	var _object : Object;
	var _bmp : Bitmap;	
	
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
		_mesh = RectMesh.buildRectangle( 600, 600 );
		// show the source bmp
		#if html5 // load as openfl asset: see DemoFromBitmap.xml
			_bmp = new Bitmap(openfl.Assets.getBitmapData("TestImage"));
		#else
			_bmp = new Bitmap(new TestImage(0, 0));
		#end
		_bmp.x = 110;
		_bmp.y = 220;
		addChild( _bmp );
		// create a viewport
		var viewSprite = new Sprite();
		_view = new SimpleView(viewSprite.graphics);
		addChild( viewSprite );
		// create an object from bitmap
		_object = BitmapObject.buildFromBmpData(_bmp.bitmapData);
		_object.x = 110;
		_object.y = 220;
		_mesh.insertObject( _object );
		// display result mesh
		_view.drawMesh( _mesh );
		// key presses
		Lib.current.stage.addEventListener(KeyboardEvent.KEY_DOWN, _onKeyDown);
	}
		
	function _onKeyDown(event:KeyboardEvent):Void
	{
		if (event.keyCode == 27) { // ESC
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
