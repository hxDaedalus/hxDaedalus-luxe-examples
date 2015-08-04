package;

import hxDaedalus.data.ConstraintSegment;
import hxDaedalus.data.Mesh;
import hxDaedalus.data.Object;
import hxDaedalus.data.Vertex;
import hxDaedalus.factories.RectMesh;
import wings.core.TargetCanvas;
import hxDaedalus.view.SimpleView;
import luxe.Color;
import luxe.Input.Key;
import luxe.Input.KeyEvent;
import luxe.Visual;


class Main extends luxe.Game {

    var _mesh : Mesh;
    var _view : SimpleView;
    var _object : Object;

	// entry point
    override function ready() {

		var background = new Visual({
			size: Luxe.screen.size,
			color: new Color(1, 1, 1),
			depth: -1
		});

        // build a rectangular 2 polygons mesh of 600x400
        _mesh = RectMesh.buildRectangle(600, 400);

        // create a viewport
        _view = new SimpleView(new TargetCanvas());

        // SINGLE VERTEX INSERTION / DELETION
        // insert a vertex in mesh at coordinates (550, 50)
        var vertex : Vertex = _mesh.insertVertex(550, 50);

		// if you want to delete that vertex :
        //_mesh.deleteVertex(vertex);


        // SINGLE CONSTRAINT SEGMENT INSERTION / DELETION
        // insert a segment in mesh with end points (70, 300) and (530, 320)
        var segment : ConstraintSegment = _mesh.insertConstraintSegment(70, 300, 530, 320);

		// if you want to delete that edge
        //_mesh.deleteConstraintSegment(segment);


        // CONSTRAINT SHAPE INSERTION / DELETION
        // insert a shape in mesh (a crossed square)
        var shape = _mesh.insertConstraintShape( [
                         50.,  50., 100.,  50.,      /* 1st segment with end points (50, 50) and (100, 50)       */
                        100.,  50., 100., 100.,      /* 2nd segment with end points (100, 50) and (100, 100)     */
                        100., 100.,  50., 100.,      /* 3rd segment with end points (100, 100) and (50, 100)     */
                         50., 100.,  50.,  50.,      /* 4rd segment with end points (50, 100) and (50, 50)       */
                         20.,  50., 130., 100.       /* 5rd segment with end points (20, 50) and (130, 100)      */
                                                ] );
        // if you want to delete that shape
        //_mesh.deleteConstraintShape(shape);


        // OBJECT INSERTION / TRANSFORMATION / DELETION
        // insert an object in mesh (a cross)
        var objectCoords : Array<Float> = new Array<Float>();

        _object = new Object();
        _object.coordinates = [ -50.,   0.,  50.,  0.,
                                  0., -50.,   0., 50.,
                                -30., -30.,  30., 30.,
                                 30., -30., -30., 30.
                                ];
        _mesh.insertObject( _object );  // insert after coordinates are setted

		// you can transform objects with x, y, rotation, scaleX, scaleY, pivotX, pivotY
        _object.x = 400;
        _object.y = 200;
        _object.scaleX = 2;
        _object.scaleY = 2;

		// if you want to delete that object
        //_mesh.deleteObject(_object);

    } // ready

	override function onkeyup(e:KeyEvent) {

        if (e.keycode == Key.escape) {
            Luxe.shutdown();
        }

    } // onkeyup

    override function update(dt:Float) {

		// objects can be transformed at any time
		_object.rotation += 0.05;

		_mesh.updateObjects();  // don't forget to update

		// render mesh
		_view.drawMesh(_mesh, true);

	} // update

} // Main
