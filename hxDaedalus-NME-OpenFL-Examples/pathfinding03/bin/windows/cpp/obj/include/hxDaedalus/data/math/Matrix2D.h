#ifndef INCLUDED_hxDaedalus_data_math_Matrix2D
#define INCLUDED_hxDaedalus_data_math_Matrix2D

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(hxDaedalus,data,math,Matrix2D)
HX_DECLARE_CLASS3(hxDaedalus,data,math,Point2D)
namespace hxDaedalus{
namespace data{
namespace math{


class HXCPP_CLASS_ATTRIBUTES  Matrix2D_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Matrix2D_obj OBJ_;
		Matrix2D_obj();
		Void __construct(hx::Null< Float >  __o_a_,hx::Null< Float >  __o_b_,hx::Null< Float >  __o_c_,hx::Null< Float >  __o_d_,hx::Null< Float >  __o_e_,hx::Null< Float >  __o_f_);

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Matrix2D_obj > __new(hx::Null< Float >  __o_a_,hx::Null< Float >  __o_b_,hx::Null< Float >  __o_c_,hx::Null< Float >  __o_d_,hx::Null< Float >  __o_e_,hx::Null< Float >  __o_f_);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Matrix2D_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("Matrix2D"); }

		Float a;
		Float b;
		Float c;
		Float d;
		Float e;
		Float f;
		virtual Void identity( );
		Dynamic identity_dyn();

		virtual Void translate( Float tx,Float ty);
		Dynamic translate_dyn();

		virtual Void scale( Float sx,Float sy);
		Dynamic scale_dyn();

		virtual Void rotate( Float rad);
		Dynamic rotate_dyn();

		virtual ::hxDaedalus::data::math::Matrix2D clone( );
		Dynamic clone_dyn();

		virtual Void tranform( ::hxDaedalus::data::math::Point2D point);
		Dynamic tranform_dyn();

		virtual Float transformX( Float x,Float y);
		Dynamic transformX_dyn();

		virtual Float transformY( Float x,Float y);
		Dynamic transformY_dyn();

		virtual Void concat( ::hxDaedalus::data::math::Matrix2D matrix);
		Dynamic concat_dyn();

};

} // end namespace hxDaedalus
} // end namespace data
} // end namespace math

#endif /* INCLUDED_hxDaedalus_data_math_Matrix2D */ 
