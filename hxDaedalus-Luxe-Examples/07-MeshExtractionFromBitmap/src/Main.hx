package;

import hxDaedalus.data.math.Tools;
import wings.core.TargetCanvas;
import wings.core.SimpleDrawingContext;
import hxDaedalus.data.math.Point2D;
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

		// get the texture
		var texture = Luxe.resources.texture('assets/MeshExtractionFromBitmap.png');

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
		var dx = 310;
		var dy = 220;
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

	// standard setup type stuff
	override function config( config: luxe.AppConfig ) {

    	config.preload.textures = [
        	{ id:'assets/MeshExtractionFromBitmap.png' }
    		];
    		config.render.antialiasing = 4;
    		return config;
		}

} // Main
