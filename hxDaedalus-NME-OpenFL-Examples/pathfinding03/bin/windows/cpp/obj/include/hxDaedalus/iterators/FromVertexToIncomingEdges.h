#ifndef INCLUDED_hxDaedalus_iterators_FromVertexToIncomingEdges
#define INCLUDED_hxDaedalus_iterators_FromVertexToIncomingEdges

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(hxDaedalus,data,Edge)
HX_DECLARE_CLASS2(hxDaedalus,data,Vertex)
HX_DECLARE_CLASS2(hxDaedalus,iterators,FromVertexToIncomingEdges)
namespace hxDaedalus{
namespace iterators{


class HXCPP_CLASS_ATTRIBUTES  FromVertexToIncomingEdges_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef FromVertexToIncomingEdges_obj OBJ_;
		FromVertexToIncomingEdges_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< FromVertexToIncomingEdges_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~FromVertexToIncomingEdges_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("FromVertexToIncomingEdges"); }

		::hxDaedalus::data::Vertex _fromVertex;
		::hxDaedalus::data::Edge _nextEdge;
		::hxDaedalus::data::Edge _resultEdge;
		virtual ::hxDaedalus::data::Vertex set_fromVertex( ::hxDaedalus::data::Vertex value);
		Dynamic set_fromVertex_dyn();

		virtual ::hxDaedalus::data::Edge next( );
		Dynamic next_dyn();

};

} // end namespace hxDaedalus
} // end namespace iterators

#endif /* INCLUDED_hxDaedalus_iterators_FromVertexToIncomingEdges */ 
