package;

import flash.display.Bitmap;
import flash.display.BitmapData;
import flash.geom.Rectangle;
import flash.geom.Point;

@:bitmap("assets/tiled_meshes.png")
class TiledMeshes extends flash.display.BitmapData {}

class MultiLayerData{

	public var bmps: Array<Bitmap> = new Array<Bitmap>();
	
	private var tiledMeshes:BitmapData;
	private var loadedCallback:MultiLayerData->Void;
	
	public function new(loadedCallback:MultiLayerData->Void){
		
		this.loadedCallback = loadedCallback;
		
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
		var clipRect = new Rectangle(0, 0, sideSize, sideSize);
		var zero = new Point(0, 0);
		
		while (num > 0) {
			var bmd = new BitmapData(sideSize, sideSize, true);
			bmd.copyPixels(tiledMeshes, clipRect, zero);
			bmps.push(new Bitmap(bmd));
			
			// setup clipRect of next mesh to grab
			clipRect.x += sideSize;
			if (clipRect.x >= tiledMeshes.width) {
				clipRect.x = 0;
				clipRect.y += sideSize;
			}
			num--;
		}
		
		tiledMeshes.dispose();
		tiledMeshes = null;
		loadedCallback(this);
	}
	
	public var pos: Array<{x:Float,y:Float}> = [ 	{ x: 80, y: 190 }
												, 	{ x: 381, y: 33 }
												, 	{ x: 687, y: 192 }
												, 	{ x: 235, y: 492 }
												, 	{ x: 545, y: 492 } 
												];
	public var names: Array<String> = [	'Bm2'
									,	'Bm3'
									,	'Bm4'
									,	'Bm0'
									,	'Bm1' 
									];										
	/*		
	public var names: Array<String> = [	'randomHitMesh2_256'
									,	'randomHitMesh3_256'
									,	'randomHitMesh4_256'
									,	'randomHitMesh0_256'
									,	'randomHitMest1_256' 
									];
	*/		
	public var portals: Array<Array<{x:Float,y:Float}>> = 	[	[ 	{ x: 111, y: 216 }
																,	{ x: 324, y: 421 }
																,	{ x: 108, y: 437 }
																,	{ x: 192, y: 236 }
																]
															,	[	{ x: 399, y: 81 }
																,	{ x: 622, y: 114 }
																,	{ x: 399, y: 259 }
																,	{ x: 616, y: 268 }
																]
															,	[	{ x: 708, y: 208 }
																,	{ x: 922, y: 212 }
																,	{ x: 705, y: 430 }
																,	{ x: 924, y: 428 }
																]
															,	[	{ x: 269, y: 528 }
																,	{ x: 311, y: 688 }
																,	{ x: 478, y: 729 }
																,	{ x: 248, y: 731 }
																]
															,	[	{ x: 590, y: 520 }
																,	{ x: 722, y: 508 }
																,	{ x: 784, y: 600 }
																,	{ x: 781, y: 732 }
																,	{ x: 576, y: 725 }
																]
															];
	// mappings between SubGraph portals
	public var connections: Array<Array<Int>> = 	[	[ 0, 0, 1, 0 ]
													,	[ 0, 1, 1, 2 ]
													,	[ 0, 2, 3, 1 ]
													,	[ 0, 3, 1, 2 ]
													,	[ 1, 1, 2, 1 ]
													,	[ 1, 3, 2, 0 ]
													,	[ 2, 2, 4, 1 ]
													,	[ 3, 2, 4, 4 ]
													,	[ 3, 0, 4, 0 ]
													,	[ 2, 3, 4, 2 ]
													/*,	[ 2, 3, 4, 1 ]
													,	[ 3, 1, 4, 0 ]
													,	[ 3, 3, 4, 2 ]*/
													];

}