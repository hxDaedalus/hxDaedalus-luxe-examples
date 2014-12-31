#ifndef INCLUDED_hxDaedalus_data_Mesh
#define INCLUDED_hxDaedalus_data_Mesh

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(hxDaedalus,data,ConstraintSegment)
HX_DECLARE_CLASS2(hxDaedalus,data,ConstraintShape)
HX_DECLARE_CLASS2(hxDaedalus,data,Edge)
HX_DECLARE_CLASS2(hxDaedalus,data,Face)
HX_DECLARE_CLASS2(hxDaedalus,data,Mesh)
HX_DECLARE_CLASS2(hxDaedalus,data,Object)
HX_DECLARE_CLASS2(hxDaedalus,data,Vertex)
namespace hxDaedalus{
namespace data{


class HXCPP_CLASS_ATTRIBUTES  Mesh_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Mesh_obj OBJ_;
		Mesh_obj();
		Void __construct(Float width,Float height);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Mesh_obj > __new(Float width,Float height);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Mesh_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Mesh"); }

		int _id;
		Float _width;
		Float _height;
		bool _clipping;
		Array< ::Dynamic > _vertices;
		Array< ::Dynamic > _edges;
		Array< ::Dynamic > _faces;
		Array< ::Dynamic > _constraintShapes;
		Array< ::Dynamic > _objects;
		::hxDaedalus::data::Vertex __centerVertex;
		Array< ::Dynamic > __edgesToCheck;
		virtual Float get_height( );
		Dynamic get_height_dyn();

		virtual Float get_width( );
		Dynamic get_width_dyn();

		virtual bool get_clipping( );
		Dynamic get_clipping_dyn();

		virtual bool set_clipping( bool value);
		Dynamic set_clipping_dyn();

		virtual int get_id( );
		Dynamic get_id_dyn();

		virtual Void dispose( );
		Dynamic dispose_dyn();

		virtual Array< ::Dynamic > get___constraintShapes( );
		Dynamic get___constraintShapes_dyn();

		virtual Void buildFromRecord( ::String rec);
		Dynamic buildFromRecord_dyn();

		virtual Void insertObject( ::hxDaedalus::data::Object object);
		Dynamic insertObject_dyn();

		virtual Void deleteObject( ::hxDaedalus::data::Object object);
		Dynamic deleteObject_dyn();

		bool __objectsUpdateInProgress;
		virtual Void updateObjects( );
		Dynamic updateObjects_dyn();

		virtual ::hxDaedalus::data::ConstraintShape insertConstraintShape( Array< Float > coordinates);
		Dynamic insertConstraintShape_dyn();

		virtual Void deleteConstraintShape( ::hxDaedalus::data::ConstraintShape shape);
		Dynamic deleteConstraintShape_dyn();

		virtual ::hxDaedalus::data::ConstraintSegment insertConstraintSegment( Float x1,Float y1,Float x2,Float y2);
		Dynamic insertConstraintSegment_dyn();

		virtual Void insertNewConstrainedEdge( ::hxDaedalus::data::ConstraintSegment fromSegment,::hxDaedalus::data::Edge edgeDownUp,Array< ::Dynamic > intersectedEdges,Array< ::Dynamic > leftBoundingEdges,Array< ::Dynamic > rightBoundingEdges);
		Dynamic insertNewConstrainedEdge_dyn();

		virtual Void deleteConstraintSegment( ::hxDaedalus::data::ConstraintSegment segment);
		Dynamic deleteConstraintSegment_dyn();

		virtual Void check( );
		Dynamic check_dyn();

		virtual ::hxDaedalus::data::Vertex insertVertex( Float x,Float y);
		Dynamic insertVertex_dyn();

		virtual ::hxDaedalus::data::Edge flipEdge( ::hxDaedalus::data::Edge edge);
		Dynamic flipEdge_dyn();

		virtual ::hxDaedalus::data::Vertex splitEdge( ::hxDaedalus::data::Edge edge,Float x,Float y);
		Dynamic splitEdge_dyn();

		virtual ::hxDaedalus::data::Vertex splitFace( ::hxDaedalus::data::Face face,Float x,Float y);
		Dynamic splitFace_dyn();

		virtual Void restoreAsDelaunay( );
		Dynamic restoreAsDelaunay_dyn();

		virtual bool deleteVertex( ::hxDaedalus::data::Vertex vertex);
		Dynamic deleteVertex_dyn();

		virtual Void untriangulate( Array< ::Dynamic > edgesList);
		Dynamic untriangulate_dyn();

		virtual Void triangulate( Array< ::Dynamic > bound,bool isReal);
		Dynamic triangulate_dyn();

		virtual int findPositionFromBounds( Float x,Float y);
		Dynamic findPositionFromBounds_dyn();

		virtual Void debug( );
		Dynamic debug_dyn();

		virtual Void traverse( Dynamic onVertex,Dynamic onEdge);
		Dynamic traverse_dyn();

		virtual bool vertexIsInsideAABB( ::hxDaedalus::data::Vertex vertex,::hxDaedalus::data::Mesh mesh);
		Dynamic vertexIsInsideAABB_dyn();

		static int INC;
};

} // end namespace hxDaedalus
} // end namespace data

#endif /* INCLUDED_hxDaedalus_data_Mesh */ 
