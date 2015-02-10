package;

import hxDaedalus.ai.EntityAI;
import hxDaedalus.ai.PathFinder;
import hxDaedalus.ai.trajectory.LinearPathSampler;
import hxDaedalus.data.Mesh;
import hxDaedalus.data.Object;
import hxDaedalus.factories.BitmapObject;
import hxDaedalus.factories.RectMesh;
import hxDaedalus.view.SimpleView;

import flash.display.MovieClip;
import flash.display.Stage;
import flash.events.Event;
import flash.events.MouseEvent;
import flash.display.Bitmap;
import flash.display.Sprite;
import flash.display.Graphics;
import flash.events.KeyboardEvent;
import flash.geom.Matrix;
import flash.Lib;
import hxDaedalus.data.math.Point2D;

// polygonal
import de.polygonal.ds.DA;
import de.polygonal.ds.Graph;
import de.polygonal.ds.GraphNode;
import de.polygonal.ai.pathfinding.AStar;
import de.polygonal.ai.pathfinding.AStarWaypoint;

import PortalWaypoint;
import Layer;
import MultiLayerData;
import SubGraph;

class Main extends Sprite {
	
	//var interconnect: Interconnect;
    var newPath:Bool = false;
	var graph: Graph<AStarWaypoint>;
	var aStar: AStar;
	var data: MultiLayerData;
	var layers: Array<Layer> = new Array<Layer>();
	var subGraphs: Array<SubGraph> = new Array<SubGraph>();
	var path: DA<AStarWaypoint>;
	var renderPathIterator: RenderPathIterator;
	var start: PortalWaypoint;
	
	public static function main(): Void {
		Lib.current.addChild(new Main());
	}
	
	public function new() {
		super();
		
		graph = new Graph<AStarWaypoint>();
		aStar = new AStar(graph);
		data = new MultiLayerData(onDataLoaded);
		
		var stage = Lib.current.stage;

		stage.addEventListener(MouseEvent.MOUSE_UP, onMouseUp);
		
		// key presses
		stage.addEventListener(KeyboardEvent.KEY_DOWN, onKeyDown);
		
		//var fps = new openfl.display.FPS();
		//Lib.current.stage.addChild(fps);
		/**/
	}
	
	public function onDataLoaded(_) {
		subGraphs = new Array<SubGraph>();
		var layerNames = ['left layer','top layer','right layer','bottom left','bottom right' ];
		var layer: Layer;
		var subGraph: SubGraph;
		
		for( i in 0...data.bmps.length ){
			layer = new Layer( this, data.pos[i], data.bmps[i], layerNames[i] );
			layers.push( layer );
			subGraph = new SubGraph( graph, layer );
			subGraph.portals = data.portals[i];
			subGraph.addPortalPairs();
			subGraphs.push(subGraph);
		}
		
		var node0: GraphNode<AStarWaypoint>;
		var node1: GraphNode<AStarWaypoint>;
		var wp0: AStarWaypoint;
		var wp1: AStarWaypoint;
		
		var mc = new Sprite();
		addChild( mc );
		var g = mc.graphics;
		for( wp in data.connections ){
			wp0 = subGraphs[wp[0]].portalWaypoints[wp[1]];
			wp1 = subGraphs[wp[2]].portalWaypoints[wp[3]];
			node0 = wp0.node;
			node1 = wp1.node;
			g.lineStyle( 0, 0xffcc00, 5 );
			g.moveTo( wp0.x, wp0.y );
			g.lineTo( wp1.x, wp1.y );
			graph.addMutualArc( node0, node1, 1 ); 
		}
		
		start = subGraphs[4].portalWaypoints[3];
	}
	
	public function removeEf(){
		var stage = Lib.current.stage;
		stage.removeEventListener(Event.ENTER_FRAME, onEnterFrame);
	}
	
    function onEnterFrame( event: Event ): Void {
		renderPathIterator.animate();
    }
	
    function onMouseUp( event: MouseEvent ): Void {		
		var mX = stage.mouseX;
		var mY = stage.mouseY;
		var subGraph;
		if( renderPathIterator != null ){
			var pos = renderPathIterator.currEntityPos();
			if( pos != null ){
				subGraph = subGraphHitTest( pos.x, pos.y );
				start = subGraph.addMeshPoint( pos );
			}
		}
		subGraph = subGraphHitTest( mX, mY );
		
		var end = subGraph.addMeshPoint( { x: mX, y: mY } );
		//trace( end.layer.name );
		path = new DA<AStarWaypoint>();
		var pathExists = aStar.find( graph, start, end, path );
		if( pathExists ){
			renderPathIterator = new RenderPathIterator( path, removeEf );
			var stage = Lib.current.stage;
			stage.addEventListener(Event.ENTER_FRAME, onEnterFrame);
		}
    }
    
	function clearMeshPoint(){
		for( sg in subGraphs ) sg.removeMeshPoint();
	}
	
	function subGraphHitTest( x: Float, y: Float ): SubGraph {
		for( sg in subGraphs ) if( sg.layer.hitTest( x, y ) ) return sg;
		return null;
	}    
	
	function onKeyDown(event:KeyboardEvent):Void
	{
		if (event.keyCode == 27) {  // ESC
			#if flash
				flash.system.System.exit(1);
			#elseif sys
				Sys.exit(1);
			#end
		}
	}
	
}