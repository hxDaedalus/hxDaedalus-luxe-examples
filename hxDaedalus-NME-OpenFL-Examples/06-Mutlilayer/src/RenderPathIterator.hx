package;

import de.polygonal.ai.pathfinding.AStarWaypoint;
import de.polygonal.ds.DA;
import PortalWaypoint;
import Layer;

class RenderPathIterator{
	
	var da: DA<AStarWaypoint>;
	var count: Int;
	var lastPortalWaypoint: PortalWaypoint;
	var fin: Void->Void;
	var layer: Layer;
	
	public function new( da_: DA<AStarWaypoint>, fin_: Void->Void ){
		init( da_, fin_ );
	}

	public function init( da_: DA<AStarWaypoint>, fin_: Void->Void ){
		da = da_;
		fin = fin_;
		lastPortalWaypoint = cast da.get(0);
		count = 0;
	}

	public function hasNext(): Bool {
		return count + 1 < da.size(); 
	}

	public function next(){
		count++;
		var currPortalWaypoint: PortalWaypoint = cast da.get(count);
		var acrossLayer = ( lastPortalWaypoint.layer == currPortalWaypoint.layer );
		if( acrossLayer ){ // find next mesh path
			layer = lastPortalWaypoint.layer;
			var len = layer.findPathNodeLength( lastPortalWaypoint.portal, currPortalWaypoint.portal );
			layer.samplerReset();
			if( len == 0 ) next();
		} else {
			layer = null;// render between portals here
		}
		lastPortalWaypoint = currPortalWaypoint;
	}
	
    public function currEntityPos():{ x: Float, y: Float }{
		if( layer != null )return layer.getEntityPos();
		return null;
	}
	
	public function animate(){
		if( layer == null ) next();
		if( layer.hasNext() ){
			layer.next();
			layer.drawEntity();
		} else {
			if( hasNext() ){
				next();
			} else {
				fin();
			}
		}
	}
}
