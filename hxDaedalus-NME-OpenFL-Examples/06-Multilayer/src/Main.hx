package;

import hxDaedalus.ai.EntityAI;
import hxDaedalus.ai.PathFinder;
import hxDaedalus.ai.trajectory.LinearPathSampler;
import hxDaedalus.data.Mesh;
import hxDaedalus.data.Object;
import hxDaedalus.factories.BitmapObject;
import hxDaedalus.factories.RectMesh;
import hxDaedalus.view.SimpleView;
import flash.display.BitmapData;
import flash.display.MovieClip;
import flash.display.Stage;
import flash.events.Event;
import flash.events.MouseEvent;
import flash.display.Bitmap;
import flash.display.Sprite;
import flash.display.Graphics;
import flash.events.KeyboardEvent;
import flash.geom.Matrix;
import flash.geom.Point;
import flash.Lib;
import hxDaedalus.data.math.Point2D;
import de.polygonal.ds.DA;
import de.polygonal.ds.Graph;
import de.polygonal.ds.GraphNode;
import de.polygonal.ai.pathfinding.AStar;
import de.polygonal.ai.pathfinding.AStarWaypoint;
import PortalWaypoint;
import Layer;
import MultiLayerData;
import SubGraph;
import TileMeshLoader;

class Main extends Sprite {
	
    var newPath:Bool = false;
	var graph: Graph<AStarWaypoint>;
	var aStar: AStar;
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
		aStar = new AStar( graph );
		new TileMeshLoader( onTileLoaded );
		var stage = Lib.current.stage;
		stage.addEventListener( KeyboardEvent.KEY_DOWN, onKeyDown );
		//Lib.current.stage.addChild(new openfl.display.FPS());
	}
	
	function onTileLoaded(bmps:Array<Bitmap>) {
		createMeshLayers( bmps );
		connectTiles();
		start = subGraphs[4].portalWaypoints[3];
		start.internal = true;	
		var stage = Lib.current.stage;
		stage.addEventListener( MouseEvent.MOUSE_UP, onMouseUp );
	}
	
	function createMeshLayers(bmps:Array<Bitmap>) {
		subGraphs = new Array<SubGraph>();
		var layer: Layer;
		var subGraph: SubGraph;
		var pos = MultiLayerData.pos;
		var portals = MultiLayerData.portals;
		var layerNames = MultiLayerData.layerNames;
		var stage = Lib.current.stage;
		var stampedMeshes = new Bitmap( new BitmapData( stage.stageWidth, stage.stageHeight, true, 0 ) );
		var translationMatrix = new Matrix();
		addChild( stampedMeshes );
		for( i in 0...bmps.length ){
			var p = pos[ i ];
			layer = new Layer( this, p, bmps[ i ], layerNames[ i ] );
			// stamp meshes on bitmap (so we only draw them once)
			translationMatrix.identity();
			translationMatrix.translate( p.x, p.y );
			var bmd = bmps[i].bitmapData;
			bmd.threshold( bmd, bmd.rect, new Point(), ">", 0x020202, 0, 0xFFFFFF ); // remove non-black pixels
			stampedMeshes.bitmapData.draw( bmd, translationMatrix );
			stampedMeshes.bitmapData.draw( layer.viewSprite, translationMatrix );
			layer.clear();
			layers.push( layer );
			subGraph = new SubGraph( graph, layer );
			subGraph.portals = portals[ i ];
			subGraph.addPortalPairs();
			subGraphs.push( subGraph );
		}	
	}
	
	function connectTiles(){
		var node0: GraphNode<AStarWaypoint>;
		var node1: GraphNode<AStarWaypoint>;
		var wp0: AStarWaypoint;
		var wp1: AStarWaypoint;
		var mc = new Sprite();
		addChild( mc );
		var g = mc.graphics;
		var connections = MultiLayerData.connections;
		for( wp in connections ){
			wp0 = subGraphs[wp[0]].portalWaypoints[wp[1]];
			wp1 = subGraphs[wp[2]].portalWaypoints[wp[3]];
			node0 = wp0.node;
			node1 = wp1.node;
			g.lineStyle( 0, 0xffcc00, 5 );
			g.moveTo( wp0.x, wp0.y );
			g.lineTo( wp1.x, wp1.y );
			graph.addMutualArc( node0, node1, 1 ); 
		}
	}
	
	function removeEf(){
		var stage = Lib.current.stage;
		stage.removeEventListener(Event.ENTER_FRAME, onEnterFrame);
	}
	
    function onEnterFrame( event: Event ): Void {
		renderPathIterator.animate();
    }
	
    function onMouseUp( event: MouseEvent ): Void {		
		var stage = Lib.current.stage;
		startRoute( stage.mouseX, stage.mouseY );
	}
		
	function startRoute( mX: Float, mY: Float ){
		var subGraph;
		if( renderPathIterator != null ){
			var pos = renderPathIterator.currEntityPos();
			if( pos != null ){
				clearMeshPoint();
				subGraph = subGraphHitTest( pos.x, pos.y );
				start = subGraph.addMeshPoint( pos );
				start.internal = true;
			}
		}
		subGraph = subGraphHitTest( mX, mY );
		var end = subGraph.addMeshPoint( { x: mX, y: mY } );
		end.internal = true;
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
	
	function onKeyDown(event:KeyboardEvent): Void {
		if (event.keyCode == 27) {  // ESC
			#if flash
				flash.system.System.exit(1);
			#elseif sys
				Sys.exit(1);
			#end
		}
	}
}