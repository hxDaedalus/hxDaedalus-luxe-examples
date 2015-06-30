package;

import hxDaedalus.data.Mesh;
import hxDaedalus.data.Object;
import hxDaedalus.factories.BitmapObject;
import hxDaedalus.factories.RectMesh;
import hxPixels.Pixels;
import wings.core.TargetCanvas;
import hxDaedalus.view.SimpleView;
import luxe.Input.Key;
import luxe.Input.KeyEvent;
import luxe.Sprite;
import luxe.Vector;
import phoenix.Texture;


class Main extends luxe.Game {

    var mesh : Mesh;
    var view : SimpleView;
    var object : Object;

	var texture : Texture;

	// entry point
    override function ready() {

		// white background
		Luxe.renderer.clear_color.rgb(0xFFFFFF);

		// get the texture
		texture = Luxe.resources.texture('assets/FromBitmap.png');

		// build a rectangular 2 polygons mesh
		mesh = RectMesh.buildRectangle( 600, 600 );

		// show the image
		var sprite = new Sprite({
			texture: texture,
			centered: false,
			pos: new Vector(110, 220),
			depth: -1
		});

        // create a viewport
		view = new SimpleView( new TargetCanvas() );

        // create an object from bitmap
        object = BitmapObject.buildFromBmpData( texture );
        object.x = 110;
        object.y = 220;
        mesh.insertObject( object );

        // display result mesh
        view.drawMesh( mesh );
	}

	override function onkeyup(e:KeyEvent) {

        if (e.keycode == Key.escape) {
            Luxe.shutdown();
        }

    } // onkeyup

	// standard setup type stuff
	override function config( config: luxe.AppConfig ) {

    	config.preload.textures = [
	        { id : 'assets/FromBitmap.png'}
    		];
    		config.render.antialiasing = 4;
    		return config;
	}
} // Main
