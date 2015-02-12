package;

import flash.display.Bitmap;
import flash.display.BitmapData;
import flash.geom.Rectangle;
import flash.geom.Point;

@:bitmap("assets/tiled_meshes.png")
class TiledMeshes extends flash.display.BitmapData {}
	
class TileMeshLoader {

	var tiledMeshes: BitmapData;
	public var loadedCallback: Array<Bitmap>->Void;
	
	public function new( loadedCallback_: Array<Bitmap>->Void ){
		loadedCallback = loadedCallback_;
	#if html5
		tiledMeshes = new TiledMeshes(0, 0, onLoaded);
	#else
		tiledMeshes = new TiledMeshes(0, 0);
		onLoaded();
	#end
	}
	
	public function onLoaded() {
		// split meshes into individual 256x256 BitmapDatas
		var sideSize = 256;
		var num = 5;
		var clipRect = new Rectangle( 0, 0, sideSize, sideSize );
		var zero = new Point( 0, 0 );
		var bmd: BitmapData;
		var bmps: Array<Bitmap> = new Array<Bitmap>();
		
		while (num > 0) {
			bmd = new BitmapData( sideSize, sideSize, true );
			bmd.copyPixels( tiledMeshes, clipRect, zero );
			bmps.push( new Bitmap( bmd ) );
			
			// setup clipRect of next mesh to grab
			clipRect.x += sideSize;
			if( clipRect.x >= tiledMeshes.width ){
				clipRect.x = 0;
				clipRect.y += sideSize;
			}
			num--;
		}
		
		tiledMeshes.dispose();
		tiledMeshes = null;
		loadedCallback( bmps );
	}
	
}