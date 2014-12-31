#ifndef INCLUDED_hxDaedalus_iterators_FromVertexToOutgoingEdges
#define INCLUDED_hxDaedalus_iterators_FromVertexToOutgoingEdges

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(hxDaedalus,data,Edge)
HX_DECLARE_CLASS2(hxDaedalus,data,Vertex)
HX_DECLARE_CLASS2(hxDaedalus,iterators,FromVertexToOutgoingEdges)
namespace hxDaedalus{
namespace iterators{


class HXCPP_CLASS_ATTRIBUTES  FromVertexToOutgoingEdges_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef FromVertexToOutgoingEdges_obj OBJ_;
		FromVertexToOutgoingEdges_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< FromVertexToOutgoingEdges_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~FromVertexToOutgoingEdges_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("FromVertexToOutgoingEdges"); }

		::hxDaedalus::data::Vertex _fromVertex;
		::hxDaedalus::data::Edge _nextEdge;
		bool realEdgesOnly;
		virtual ::hxDaedalus::data::Vertex set_fromVertex( ::hxDaedalus::data::Vertex value);
		Dynamic set_fromVertex_dyn();

		::hxDaedalus::data::Edge _resultEdge;
		virtual ::hxDaedalus::data::Edge next( );
		Dynamic next_dyn();

};

} // end namespace hxDaedalus
} // end namespace iterators

#endif /* INCLUDED_hxDaedalus_iterators_FromVertexToOutgoingEdges */ 
