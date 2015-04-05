package;

import hxDaedalus.data.math.Tools;
/*
import hxDaedalus.data.Mesh;
import hxDaedalus.data.Object;
import hxDaedalus.factories.BitmapObject;
import hxDaedalus.factories.RectMesh;
import hxDaedalus.graphics.Pixels;
*/
import hxDaedalus.graphics.TargetCanvas;
import hxDaedalus.graphics.SimpleDrawingContext;
import hxDaedalus.data.math.Point2D;
//import hxDaedalus.view.SimpleView;

import luxe.Input.Key;
import luxe.Input.KeyEvent;
import luxe.Sprite;
import luxe.Vector;
import phoenix.Texture;


class Main extends luxe.Game {
	
	// entry point
    override function ready() {

		// white background
		Luxe.renderer.clear_color.rgb(0xFFFFFF);
		
        // load the asset
        Luxe.loadTexture('assets/MeshExtractionFromBitmap.png', onLoaded);

    } // ready

	function onLoaded(texture):Void {
		
		// show the image
		var sprite = new Sprite({
			texture: texture,
			centered: false,
			pos: new Vector(110, 220),
			depth: -1
		});
		
        var vertices = new Array<Point2D>();
        var triangles = new Array<Int>();
		
		
		Tools.extractMeshFromBitmap( texture, vertices, triangles);
		
        // create a viewport
		var g = new SimpleDrawingContext( new TargetCanvas() );
		var dx = 200;
		var dy = 200;
		g.lineStyle(1, 0xFF0000);
		// use a 3 iterator instead?
		var i: Int = 0;
		while( i < triangles.length ){
			g.moveTo(vertices[triangles[i]].x + dx, vertices[triangles[i]].y + dy);
		   	g.lineTo(vertices[triangles[i+1]].x + dx, vertices[triangles[i+1]].y + dy);
		    g.lineTo(vertices[triangles[i+2]].x + dx, vertices[triangles[i+2]].y + dy);
		    g.lineTo(vertices[triangles[i]].x + dx, vertices[triangles[i]].y + dy);
			i+=3;
	    }
		
		
	}
	
	override function onkeyup(e:KeyEvent) {

        if (e.keycode == Key.escape) {
            Luxe.shutdown();
        }

    } // onkeyup

} // Main