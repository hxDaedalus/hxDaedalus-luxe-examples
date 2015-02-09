package;

import flash.display.Bitmap;

@:bitmap("assets/randomHitMesh0_256.gif")
class Bm0 extends flash.display.BitmapData {}
@:bitmap("assets/randomHitMesh1_256.gif")
class Bm1 extends flash.display.BitmapData {}
@:bitmap("assets/randomHitMesh2_256.gif")
class Bm2 extends flash.display.BitmapData {}
@:bitmap("assets/randomHitMesh3_256.gif")
class Bm3 extends flash.display.BitmapData {}
@:bitmap("assets/randomHitMesh4_256.gif")
class Bm4 extends flash.display.BitmapData {}

class MultiLayerData{

	public var bmps: Array<Bitmap> = new Array<Bitmap>();
	public function new(){
		#if html5
			for( name in names ){
		    	bmps.push( new Bitmap(openfl.Assets.getBitmapData(name));
			}
		#else		
			bmps.push( new Bitmap( new Bm2(0, 0) ));
			bmps.push( new Bitmap( new Bm3(0, 0) ));
			bmps.push( new Bitmap( new Bm4(0, 0) ));
			bmps.push( new Bitmap( new Bm0(0, 0) ));
			bmps.push( new Bitmap( new Bm1(0, 0) ));
		#end
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
															,	[	{ x: 519, y: 517 }
																,	{ x: 704, y: 508 }
																,	{ x: 781, y: 732 }
																,	{ x: 576, y: 725 }
																]
															];
	// mappings between SubGraph portals
	public var connections: Array<Array<Int>> = 	[	[ 0, 0, 1, 0 ]
													,	[ 0, 1, 1, 2 ]
													,	[ 0, 2, 3, 2 ]
													,	[ 0, 3, 1, 2 ]
													,	[ 1, 1, 2, 1 ]
													,	[ 1, 3, 2, 0 ]
													,	[ 2, 2, 4, 1 ]
													,	[ 2, 3, 4, 3 ]
													,	[ 3, 1, 4, 0 ]
													,	[ 3, 3, 4, 2 ]
													];

}