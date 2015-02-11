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
		da = clean( da_ );
		fin = fin_;
		lastPortalWaypoint = cast da.get(0);
		count = 0;
	}

	public function clean( da_: DA<AStarWaypoint> ): DA<AStarWaypoint>{
		var daOut: DA<AStarWaypoint> = new DA<AStarWaypoint>();
		var len = da_.size();
		var first: PortalWaypoint = cast da_.front();
		var last: PortalWaypoint = cast da_.back();
		if( first.layer == last.layer ){
			daOut.pushBack( first );
			daOut.pushBack( last );
			return daOut;
		}
		var startLayer = first.layer;
		var currLayer = startLayer;
		var lastLayer = last.layer;
		var curr: PortalWaypoint; 
		var prev: PortalWaypoint = null ;
		daOut.pushBack( first );
		for( i in 1...(len-1) ){
			curr = cast da_.get( i );
			if( curr.layer == currLayer ){
				prev = curr;
				continue;
			}
			if( prev != null ) { if( prev != first ) daOut.pushBack( prev ); }
			daOut.pushBack( curr );
			currLayer = curr.layer;
		}
		daOut.pushBack( last );
		return daOut;
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
