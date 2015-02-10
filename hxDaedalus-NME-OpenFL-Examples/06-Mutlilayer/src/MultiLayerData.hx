package;


class MultiLayerData{
	
	public static var layerNames = 
			[	'left layer'
			,	'top layer'
			,	'right layer'
			,	'bottom left'
			,	'bottom right' 
			];
	public static var names: Array<String> = 
			[	'Bm2'
			,	'Bm3'
			,	'Bm4'
			,	'Bm0'
			,	'Bm1' 
			];								
	public static var pos: Array<{ x: Float, y: Float }> = 
			[ 	{ x: 80, y: 190 }
			, 	{ x: 381, y: 33 }
			, 	{ x: 687, y: 192 }
			, 	{ x: 235, y: 492 }
			, 	{ x: 545, y: 492 } 
			];										
	public static var portals: Array<Array<{ x: Float, y: Float }>> = 	
		[	[ 	{ x: 111, y: 216 }
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
	public static var connections: Array<Array<Int>> = 	
			[	[ 0, 0, 1, 0 ]
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