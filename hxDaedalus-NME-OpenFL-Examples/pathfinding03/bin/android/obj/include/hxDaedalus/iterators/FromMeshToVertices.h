#ifndef INCLUDED_hxDaedalus_iterators_FromMeshToVertices
#define INCLUDED_hxDaedalus_iterators_FromMeshToVertices

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(hxDaedalus,data,Mesh)
HX_DECLARE_CLASS2(hxDaedalus,data,Vertex)
HX_DECLARE_CLASS2(hxDaedalus,iterators,FromMeshToVertices)
namespace hxDaedalus{
namespace iterators{


class HXCPP_CLASS_ATTRIBUTES  FromMeshToVertices_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef FromMeshToVertices_obj OBJ_;
		FromMeshToVertices_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< FromMeshToVertices_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~FromMeshToVertices_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("FromMeshToVertices"); }

		::hxDaedalus::data::Mesh _fromMesh;
		int _currIndex;
		::hxDaedalus::data::Vertex _resultVertex;
		virtual ::hxDaedalus::data::Mesh set_fromMesh( ::hxDaedalus::data::Mesh value);
		Dynamic set_fromMesh_dyn();

		virtual ::hxDaedalus::data::Vertex next( );
		Dynamic next_dyn();

};

} // end namespace hxDaedalus
} // end namespace iterators

#endif /* INCLUDED_hxDaedalus_iterators_FromMeshToVertices */ 
