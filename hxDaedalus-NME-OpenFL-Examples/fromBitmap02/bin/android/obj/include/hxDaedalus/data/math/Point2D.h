#ifndef INCLUDED_hxDaedalus_data_math_Point2D
#define INCLUDED_hxDaedalus_data_math_Point2D

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(hxDaedalus,data,math,Matrix2D)
HX_DECLARE_CLASS3(hxDaedalus,data,math,Point2D)
namespace hxDaedalus{
namespace data{
namespace math{


class HXCPP_CLASS_ATTRIBUTES  Point2D_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Point2D_obj OBJ_;
		Point2D_obj();
		Void __construct(hx::Null< Float >  __o_x_,hx::Null< Float >  __o_y_);

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Point2D_obj > __new(hx::Null< Float >  __o_x_,hx::Null< Float >  __o_y_);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Point2D_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("Point2D"); }

		Float x;
		Float y;
		virtual Void transform( ::hxDaedalus::data::math::Matrix2D matrix);
		Dynamic transform_dyn();

		virtual Void setXY( Float x_,Float y_);
		Dynamic setXY_dyn();

		virtual ::hxDaedalus::data::math::Point2D clone( );
		Dynamic clone_dyn();

		virtual Void substract( ::hxDaedalus::data::math::Point2D p);
		Dynamic substract_dyn();

		virtual Float get_length( );
		Dynamic get_length_dyn();

		virtual Void normalize( );
		Dynamic normalize_dyn();

		virtual Void scale( Float s);
		Dynamic scale_dyn();

		virtual Float distanceTo( ::hxDaedalus::data::math::Point2D p);
		Dynamic distanceTo_dyn();

};

} // end namespace hxDaedalus
} // end namespace data
} // end namespace math

#endif /* INCLUDED_hxDaedalus_data_math_Point2D */ 
