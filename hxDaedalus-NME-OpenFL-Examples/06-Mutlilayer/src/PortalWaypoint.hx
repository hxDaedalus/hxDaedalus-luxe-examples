package;
import SubGraph;
import Layer;
import de.polygonal.ai.pathfinding.AStarWaypoint;

class PortalWaypoint extends AStarWaypoint {
	
	public var layer: Layer;
	public var internal: Bool = false;
	
	public var portal( get, set ): {x:Float,y:Float};
	
	var _portal:{x:Float,y:Float};
	
	function set_portal( portal_: { x: Float , y: Float } ): { x: Float, y: Float } {
		_portal = portal_;
		x = portal_.x;
		y = portal_.y;
		return _portal;
	}
	
	function get_portal(): { x: Float, y: Float } {
		return _portal;
	}
	
	public function new(){
		super();
	}
	
	override public function distanceTo(wp:AStarWaypoint): Float {
		return 1;
	}

}