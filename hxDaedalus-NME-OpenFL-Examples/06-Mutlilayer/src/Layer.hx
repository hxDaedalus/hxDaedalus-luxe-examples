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
import hxDaedalus.data.math.Point2D;

class Layer{

	var mesh: Mesh;
	var view: SimpleView;
	var entity: EntityAI;
	var pathfinder:PathFinder;
	public var path: Array<Float>;
	var sampler: LinearPathSampler;
	var obj: Object;
	var bmp:Bitmap;
	var matrix: Matrix;
	var viewSprite: Sprite;
	var pos: Point2D;
	var entityPos: Point2D;
	
	public function new( scope: Sprite,  entityPos: Point2D,pos_: Point2D, bmp_: Bitmap ){
		
		pos = pos_;
		bmp = bmp_;
		
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
		
		// stamp it on the overlay bitmap
		//_overlay.bitmapData.draw(viewSpriteLower,_matrixLower );
		//_overlay.bitmapData.draw(viewSpriteUpper, _matrixUpper );
		
		// we need an entity
		entity = new EntityAI();
		
		// set radius size for your entity
		entity.radius = 2;
		
		// set a position
		entity.x = entityPos.x;
		entity.y = entityPos.y;

		// show entity on screen
		view.drawEntity( entity, false );
		
		// now configure the pathfinder
		pathfinder = new PathFinder();
		pathfinder.entity = entity; // set the entity
		pathfinder.mesh = mesh; // set the mesh
		
		// we need a vector to store the path
		path = new Array<Float>();
		
		// then configure the path sampler
		sampler = new LinearPathSampler();
		sampler.entity = entity;
		sampler.samplingDistance = 5;
		sampler.path = path;
	
	}
	
	public function sampledPathReInit(){
		sampler.path = path;
	}
	
	public function findPath( x_: Float, y_: Float, path_: Array<Float> ){
		pathfinder.findPath( x_ - pos.x, y_ - pos.y, path_ );
	}
	
	public function samplerReset()
	{
		sampler.reset();
	}
	
	public function entitySetPos( p: Point2D ){
		entity.x = p.x;
		entity.y = p.y;
	}
	
	public function entityPosition( x_: Float, y_: Float )
	{
		entity.x = x_ - pos.x;
		entity.y = y_ - pos.y;
	}
	
	public function clear(){
		view.graphics.clear();
	}
	
	public function drawEntity(){
		view.drawEntity( entity );
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