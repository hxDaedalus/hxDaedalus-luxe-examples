#ifndef INCLUDED_hxDaedalus_data_math_ShapeSimplifier
#define INCLUDED_hxDaedalus_data_math_ShapeSimplifier

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(hxDaedalus,data,math,ShapeSimplifier)
namespace hxDaedalus{
namespace data{
namespace math{


class HXCPP_CLASS_ATTRIBUTES  ShapeSimplifier_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef ShapeSimplifier_obj OBJ_;
		ShapeSimplifier_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< ShapeSimplifier_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~ShapeSimplifier_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("ShapeSimplifier"); }

		static Array< Float > simplify( Array< Float > coords,hx::Null< Float >  epsilon);
		static Dynamic simplify_dyn();

};

} // end namespace hxDaedalus
} // end namespace data
} // end namespace math

#endif /* INCLUDED_hxDaedalus_data_math_ShapeSimplifier */ 
