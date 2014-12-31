#ifndef INCLUDED_hxDaedalus_data_ConstraintShape
#define INCLUDED_hxDaedalus_data_ConstraintShape

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(hxDaedalus,data,ConstraintSegment)
HX_DECLARE_CLASS2(hxDaedalus,data,ConstraintShape)
namespace hxDaedalus{
namespace data{


class HXCPP_CLASS_ATTRIBUTES  ConstraintShape_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef ConstraintShape_obj OBJ_;
		ConstraintShape_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< ConstraintShape_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~ConstraintShape_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("ConstraintShape"); }

		Array< ::Dynamic > segments;
		int _id;
		virtual int get_id( );
		Dynamic get_id_dyn();

		virtual Void dispose( );
		Dynamic dispose_dyn();

		static int INC;
};

} // end namespace hxDaedalus
} // end namespace data

#endif /* INCLUDED_hxDaedalus_data_ConstraintShape */ 
