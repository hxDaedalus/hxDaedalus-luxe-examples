#ifndef INCLUDED_hxDaedalus_iterators_FromFaceToInnerEdges
#define INCLUDED_hxDaedalus_iterators_FromFaceToInnerEdges

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(hxDaedalus,data,Edge)
HX_DECLARE_CLASS2(hxDaedalus,data,Face)
HX_DECLARE_CLASS2(hxDaedalus,iterators,FromFaceToInnerEdges)
namespace hxDaedalus{
namespace iterators{


class HXCPP_CLASS_ATTRIBUTES  FromFaceToInnerEdges_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef FromFaceToInnerEdges_obj OBJ_;
		FromFaceToInnerEdges_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< FromFaceToInnerEdges_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~FromFaceToInnerEdges_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("FromFaceToInnerEdges"); }

		::hxDaedalus::data::Face _fromFace;
		::hxDaedalus::data::Edge _nextEdge;
		::hxDaedalus::data::Edge _resultEdge;
		virtual ::hxDaedalus::data::Face set_fromFace( ::hxDaedalus::data::Face value);
		Dynamic set_fromFace_dyn();

		virtual ::hxDaedalus::data::Edge next( );
		Dynamic next_dyn();

};

} // end namespace hxDaedalus
} // end namespace iterators

#endif /* INCLUDED_hxDaedalus_iterators_FromFaceToInnerEdges */ 
