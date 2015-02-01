package;

class WithinLayer {
	
	var layer: Layer;
	
	public function new(){
	
	}
	
	public function setup( mX: Float, mY: Float, layer_: Layer ){
		layer = layer_;
		layer.findPath( mX, mY, layer.path );
		layer.drawPath();
		layer.samplerReset();
	}
	
	public function animate(): Bool{
		var continueAnimate: Bool = false;
        // animate !			// move entity
        if ( layer.hasNext() ) {
			layer.next();
			continueAnimate = true;
		}
		// show entity position on screen
		layer.drawEntity();
		return continueAnimate;
	}	


}