package;

import de.polygonal.ds.DA;
import de.polygonal.ds.Graph;
import de.polygonal.ds.GraphNode;
import de.polygonal.ai.pathfinding.AStar;
import de.polygonal.ai.pathfinding.AStarWaypoint;

import PortalWaypoint;
import Layer;
import MultiLayerData;
import SubGraph;

class SubGraph {
	public var portals: Array<{x:Float,y:Float}>;
	public var portalWaypoints: Array<PortalWaypoint>;
	public var layer: Layer;
	var dynamicWaypoints: Array<PortalWaypoint>;
	var graph: Graph<AStarWaypoint>;
	
	public function new( graph_: Graph<AStarWaypoint>, layer_: Layer ){
		graph = graph_;
		layer = layer_;
		portalWaypoints = new Array<PortalWaypoint>();
		dynamicWaypoints = new Array<PortalWaypoint>();
	}
	
	public function addPortalPairs(){
		for( i in 0...portals.length ){	// add mesh portal nodes to the graph
			var pwp = new PortalWaypoint();
			pwp.portal = portals[i];
			pwp.layer = layer;
			pwp.node = graph.addNode( graph.createNode( pwp ) );
			portalWaypoints.push( pwp );
		}
		var possSeconds: Array<PortalWaypoint> = portalWaypoints.slice( 0 );
		var first: PortalWaypoint;
		var second: PortalWaypoint;
		var firstWp: AStarWaypoint;
		var secondWp: AStarWaypoint;
		var len: Int;
		var count: Int = 0;
		while( possSeconds.length > 0 ){ // create arc's between portals with cost based on mesh path lengths
			first = possSeconds.pop();
			firstWp = first;
			for( i in 0...possSeconds.length ){
				second = possSeconds[ i ];
				len = layer.findPathNodeLength( first.portal, second.portal );
				if( len == 0 ) trace( 'portal connection failed ' + i + ' ' + ( count + i ) );
				secondWp = second;
				if( len != 0 ) graph.addMutualArc( firstWp.node, secondWp.node, len ); 
			}
			count++;
		}
	}
	
	public function addMeshPoint( dynamicPortal_: { x: Float, y: Float } ){		
		var wp = new PortalWaypoint();
		wp.layer = layer;
		wp.portal = dynamicPortal_;
		wp.node = graph.addNode( graph.createNode( wp ) );
		var len: Int;
		for( pw in portalWaypoints ){
			len = layer.findPathNodeLength( dynamicPortal_, pw.portal );
			if( len == 0 ) trace( 'portal connection failed ');
			if( len != 0 ) graph.addMutualArc( wp.node, pw.node, len );
		}
		dynamicWaypoints.push( wp );
		portalWaypoints.push( wp );
		return wp;
	}
	
	public function removeMeshPoint(){
		for( wp in dynamicWaypoints ) {
			portalWaypoints.remove( wp );
			graph.unlink( wp.node );
		}
		dynamicWaypoints = new Array<PortalWaypoint>();
	}

}