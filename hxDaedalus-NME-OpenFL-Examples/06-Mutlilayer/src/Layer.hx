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
import flash.events.KeyboardEvent;
import flash.geom.Matrix;


class Layer{
	public var name: String;
	var mesh: Mesh;
	var view: SimpleView;
	public var entity: EntityAI;
	public var secondEntity: EntityAI;
	var pathfinder:PathFinder;
	public var path: Array<Float>;
	var sampler: LinearPathSampler;
	var obj: Object;
	var bmp:Bitmap;
	var matrix: Matrix;
	var viewSprite: Sprite;
	var pos: {x:Float,y:Float};
	var entityPos: {x:Float,y:Float};
	var w: Float;
	var h: Float;
	var right: Float;
	var bottom: Float;
	
	public function new( scope: Sprite, pos_: {x:Float,y:Float}, bmp_: Bitmap, name_: String = '' ){
		
		name = name_;
		pos = pos_;
		bmp = bmp_;
		
		w = bmp.width;
		h = bmp.height;
		right = pos.x + w;
		bottom = pos.y + h;
		
		// build a rectangular 2 polygons mesh
		mesh = RectMesh.buildRectangle( bmp.width, bmp.height );
		
		viewSprite = new Sprite();
		viewSprite.x = pos.x;
		viewSprite.y = pos.y;
		view = new SimpleView(viewSprite.graphics);
		scope.addChild( viewSprite );
		
		// create an object from bitmap
		obj = BitmapObject.buildFromBmpData( bmp.bitmapData, 1.8 );
		obj.x = 0;
		obj.y = 0;
		
		mesh.insertObject( obj );
		
		// display result mesh
		
		// draw the mesh
		view.drawMesh( mesh );
		
		// setup offset matrix
		matrix = new Matrix();
		matrix.translate( pos.x, pos.y );
		
		// we need an entity
		entity = new EntityAI();
		secondEntity = new EntityAI();
		// set radius size for your entity
		entity.radius = 0.8;
		secondEntity.radius = 4;

		// now configure the pathfinder
		pathfinder = new PathFinder();
		pathfinder.entity = entity; // set the entity
		pathfinder.mesh = mesh; // set the mesh
		
		// we need a vector to store the path
		path = new Array<Float>();
		
		// then configure the path sampler
		sampler = new LinearPathSampler();
		sampler.entity = entity;
		sampler.samplingDistance = 1;
		sampler.path = path;
	
	}
	
	public function hitTest( x_: Float, y_: Float ){
		return ( x_ > pos.x && y_ > pos.y && x_ < right && y_ < bottom );
	}
	
	public function drawEntityFalse(){
		view.drawEntity( entity, false );
		view.drawEntity( secondEntity, false );
	}
	
	public function sampledPathReInit(){
		sampler.path = path;
	}
	
	public function findPath( pStart:{x:Float,y:Float}, pEnd: {x:Float,y:Float} ): Array<Float>{
		sampler.reset();
		//path = new Array<Float>();
		
		entity.x = pStart.x - pos.x;
		entity.y = pStart.y - pos.y;
		sampler.entity = entity;
		pathfinder.findPath( pEnd.x - pos.x, pEnd.y - pos.y, path );
		return path;
	}
	
	public function findPathNodeLength( pStart: {x: Float, y: Float}, pEnd: {x: Float, y: Float} ){
		sampler.reset();
		//path = new Array<Float>();
		//sampler.path = path;
		entity.x = pStart.x - pos.x;
		entity.y = pStart.y - pos.y;
		pathfinder.findPath( pEnd.x - pos.x, pEnd.y - pos.y, path );
		return path.length;
	}
	
	public function samplerReset()
	{
		sampler.reset();
	}
	
	public function entityPosition( x_: Float, y_: Float ){
		entity.x = x_ - pos.x;
		entity.y = y_ - pos.y;
	}
	
	public function entitySecondPosition( x_: Float, y_: Float ){
		secondEntity.x = x_ - pos.x;
		secondEntity.y = y_ - pos.y;
	}
	
	public function clear(){
		view.graphics.clear();
	}
	
	public function drawEntity(){
		view.drawEntity( entity );
	}
	
	public function drawMesh(){
		view.drawMesh( mesh );
	}
	
	public function hasNext(): Bool{
		return sampler.hasNext;
	}
	
	public function next(){
		return sampler.next();
	}
	
	public function drawPath(){
		view.drawPath( path );
	}
	
}