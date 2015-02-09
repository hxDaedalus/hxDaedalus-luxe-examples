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

class SubGraph
{
	public var portals: Array<{x:Float,y:Float}>;
	public var portalWaypoints: Array<PortalWaypoint>;
	public var graph: Graph<AStarWaypoint>;
	public var layer: Layer;
	public var internalPortal: {x:Float,y:Float};
	public var meshWaypointPortal: PortalWaypoint;
	
	public function new( graph_: Graph<AStarWaypoint>, layer_: Layer ){
		graph = graph_;
		layer = layer_;
		portalWaypoints = new Array<PortalWaypoint>();
	}
	
	public function addPortalPairs(){
		// add mesh portal nodes to the graph
		for( i in 0...portals.length ){
			var pwp = new PortalWaypoint();
			pwp.portal = portals[i];
			pwp.layer = layer;
			pwp.node = graph.addNode(graph.createNode(pwp));
			portalWaypoints.push( pwp );
		}
		
		var possSeconds: Array<PortalWaypoint> = portalWaypoints.slice(0);
		var first: PortalWaypoint;//AStarWaypoint
		var second: PortalWaypoint;
		var firstWp: AStarWaypoint;
		var secondWp: AStarWaypoint;
		var len: Int;
		var count: Int = 0;
		// create arc's between portals with cost based on mesh path lengths
		while( possSeconds.length > 0 ){
			first = possSeconds.pop();
			firstWp = first;
			for( i in 0...possSeconds.length ){
				second = possSeconds[i];
				len = layer.findPathNodeLength( first.portal, second.portal );
				if( len == 0 ) trace( 'portal connection failed ' + i + ' ' + ( count+i ) );
				secondWp = second;
				if( len != 0 ) graph.addMutualArc( firstWp.node, secondWp.node, len ); 
			}
			count++;
		}
	}
	
	public function addMeshPoint( internalPortal_: { x: Float, y: Float } ){
		
		removeMeshPoint();
		internalPortal = internalPortal_;			
		meshWaypointPortal = new PortalWaypoint();
		meshWaypointPortal.layer = layer;
		meshWaypointPortal.portal = internalPortal_;
		meshWaypointPortal.node = graph.addNode(graph.createNode(meshWaypointPortal));
		var len: Int;
		for( pw in portalWaypoints ){
			len = layer.findPathNodeLength( internalPortal_, pw.portal );
			graph.addMutualArc( meshWaypointPortal.node, pw.node, len );
		}
	}
	
	public function removeMeshPoint(){
		var wp: AStarWaypoint = meshWaypointPortal;
		if( meshWaypointPortal != null ) graph.unlink( wp.node );
	}

}