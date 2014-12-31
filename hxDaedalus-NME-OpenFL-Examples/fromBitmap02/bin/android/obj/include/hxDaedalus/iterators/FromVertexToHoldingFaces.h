#ifndef INCLUDED_hxDaedalus_iterators_FromVertexToHoldingFaces
#define INCLUDED_hxDaedalus_iterators_FromVertexToHoldingFaces

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(hxDaedalus,data,Edge)
HX_DECLARE_CLASS2(hxDaedalus,data,Face)
HX_DECLARE_CLASS2(hxDaedalus,data,Vertex)
HX_DECLARE_CLASS2(hxDaedalus,iterators,FromVertexToHoldingFaces)
namespace hxDaedalus{
namespace iterators{


class HXCPP_CLASS_ATTRIBUTES  FromVertexToHoldingFaces_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef FromVertexToHoldingFaces_obj OBJ_;
		FromVertexToHoldingFaces_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< FromVertexToHoldingFaces_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~FromVertexToHoldingFaces_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("FromVertexToHoldingFaces"); }

		::hxDaedalus::data::Vertex _fromVertex;
		::hxDaedalus::data::Edge _nextEdge;
		::hxDaedalus::data::Face _resultFace;
		virtual ::hxDaedalus::data::Vertex set_fromVertex( ::hxDaedalus::data::Vertex value);
		Dynamic set_fromVertex_dyn();

		virtual ::hxDaedalus::data::Face next( );
		Dynamic next_dyn();

};

} // end namespace hxDaedalus
} // end namespace iterators

#endif /* INCLUDED_hxDaedalus_iterators_FromVertexToHoldingFaces */ 
