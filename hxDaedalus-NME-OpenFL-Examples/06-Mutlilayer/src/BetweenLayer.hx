package;

import hxDaedalus.data.math.Point2D;
import Interconnect;

class BetweenLayer{
	var interconnect: Interconnect;
	var drawUpperPath: Bool = false;
	var start: Point2D;
	var end: Point2D;
	
	public function new( interconnect_: Interconnect ){
		interconnect = interconnect_;
	}
	
	public function setup( start_: Point2D, end_: Point2D, layer: Layer ){
		start = start_;
		end = end_;
		interconnect.findPaths( start_, end_, layer );
		interconnect.firstLayer.drawPath();
	}
	
	public function animate():Bool{
		var continueAnimate = true;
        // animate !
        if ( interconnect.hasNext() ){
			interconnect.next();	
		} else {
			if( start.x != end.x || start.y != start.y ) {
				start.x = end.x;
				start.y = end.y;
				interconnect.resetSamplePath();
				continueAnimate = false;
			}
		}
		if( interconnect.firstLayer.hasNext() ) {
			// show entity position on screen
			interconnect.firstLayer.drawEntity();
			drawUpperPath = true;  
		} else if( drawUpperPath == true ){
			interconnect.secondLayer.drawPath();
			// show entity position on screen
			interconnect.secondLayer.drawEntity();
			drawUpperPath = false;
		} else {
			interconnect.secondLayer.drawEntity();
		}
		return continueAnimate;
	}
	
}