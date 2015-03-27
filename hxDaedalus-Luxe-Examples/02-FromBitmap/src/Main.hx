package;

import hxDaedalus.data.Mesh;
import hxDaedalus.data.Object;
import hxDaedalus.factories.BitmapObject;
import hxDaedalus.factories.RectMesh;
import hxDaedalus.graphics.Pixels;
import hxDaedalus.graphics.TargetCanvas;
import hxDaedalus.view.SimpleView;
import luxe.Input.Key;
import luxe.Input.KeyEvent;
import luxe.Sprite;
import luxe.Vector;
import phoenix.Texture;


class Main extends luxe.Game {

    var _mesh : Mesh;
    var _view : SimpleView;
    var _object : Object;

	var _texture : Texture;
	
	// entry point
    override function ready() {

		// white background
		Luxe.renderer.clear_color.rgb(0xFFFFFF);
		
        // load the asset
        Luxe.loadTexture('assets/FromBitmap.png', onLoaded);

    } // ready

	function onLoaded(texture):Void {
		
		_texture = texture;
		
		// build a rectangular 2 polygons mesh
		_mesh = RectMesh.buildRectangle( 600, 600 );
		
		// show the image
		var sprite = new Sprite({
			texture: _texture,
			centered: false,
			pos: new Vector(110, 220),
			depth: -1
		});
		
        // create a viewport
		_view = new SimpleView( new TargetCanvas() );
		
        // create an object from bitmap
        _object = BitmapObject.buildFromBmpData( _texture );
        _object.x = 110;
        _object.y = 220;
        _mesh.insertObject( _object );
        
        // display result mesh
        _view.drawMesh( _mesh );
	}
	
	override function onkeyup(e:KeyEvent) {

        if (e.keycode == Key.escape) {
            Luxe.shutdown();
        }

    } // onkeyup

} // Main