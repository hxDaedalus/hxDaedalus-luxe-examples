#ifndef INCLUDED_hxDaedalus_data_ConstraintSegment
#define INCLUDED_hxDaedalus_data_ConstraintSegment

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(hxDaedalus,data,ConstraintSegment)
HX_DECLARE_CLASS2(hxDaedalus,data,ConstraintShape)
HX_DECLARE_CLASS2(hxDaedalus,data,Edge)
namespace hxDaedalus{
namespace data{


class HXCPP_CLASS_ATTRIBUTES  ConstraintSegment_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef ConstraintSegment_obj OBJ_;
		ConstraintSegment_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< ConstraintSegment_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~ConstraintSegment_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("ConstraintSegment"); }

		::hxDaedalus::data::ConstraintShape fromShape;
		int _id;
		Array< ::Dynamic > _edges;
		virtual int get_id( );
		Dynamic get_id_dyn();

		virtual Void addEdge( ::hxDaedalus::data::Edge edge);
		Dynamic addEdge_dyn();

		virtual Void removeEdge( ::hxDaedalus::data::Edge edge);
		Dynamic removeEdge_dyn();

		virtual Array< ::Dynamic > get_edges( );
		Dynamic get_edges_dyn();

		virtual Void dispose( );
		Dynamic dispose_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

		static int INC;
};

} // end namespace hxDaedalus
} // end namespace data

#endif /* INCLUDED_hxDaedalus_data_ConstraintSegment */ 
