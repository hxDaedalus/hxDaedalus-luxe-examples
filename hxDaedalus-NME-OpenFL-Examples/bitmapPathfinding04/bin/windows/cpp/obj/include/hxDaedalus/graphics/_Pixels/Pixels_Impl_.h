#ifndef INCLUDED_hxDaedalus_graphics__Pixels_Pixels_Impl_
#define INCLUDED_hxDaedalus_graphics__Pixels_Pixels_Impl_

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(hxDaedalus,graphics,_Pixels,PixelsData)
HX_DECLARE_CLASS3(hxDaedalus,graphics,_Pixels,Pixels_Impl_)
HX_DECLARE_CLASS3(openfl,_v2,display,BitmapData)
HX_DECLARE_CLASS3(openfl,_v2,display,IBitmapDrawable)
namespace hxDaedalus{
namespace graphics{
namespace _Pixels{


class HXCPP_CLASS_ATTRIBUTES  Pixels_Impl__obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Pixels_Impl__obj OBJ_;
		Pixels_Impl__obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Pixels_Impl__obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Pixels_Impl__obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("Pixels_Impl_"); }

		static ::hxDaedalus::graphics::_Pixels::PixelsData _new( int width,int height,hx::Null< bool >  alloc);
		static Dynamic _new_dyn();

		static int getByte( ::hxDaedalus::graphics::_Pixels::PixelsData this1,int i);
		static Dynamic getByte_dyn();

		static int getPixel( ::hxDaedalus::graphics::_Pixels::PixelsData this1,int x,int y);
		static Dynamic getPixel_dyn();

		static int getPixel32( ::hxDaedalus::graphics::_Pixels::PixelsData this1,int x,int y);
		static Dynamic getPixel32_dyn();

		static Void setByte( ::hxDaedalus::graphics::_Pixels::PixelsData this1,int i,int value);
		static Dynamic setByte_dyn();

		static Void setPixel( ::hxDaedalus::graphics::_Pixels::PixelsData this1,int x,int y,int value);
		static Dynamic setPixel_dyn();

		static Void setPixel32( ::hxDaedalus::graphics::_Pixels::PixelsData this1,int x,int y,int value);
		static Dynamic setPixel32_dyn();

		static ::hxDaedalus::graphics::_Pixels::PixelsData fromBitmapData( ::openfl::_v2::display::BitmapData bmd);
		static Dynamic fromBitmapData_dyn();

		static ::openfl::_v2::display::BitmapData toBitmapData( ::hxDaedalus::graphics::_Pixels::PixelsData this1);
		static Dynamic toBitmapData_dyn();

		static ::openfl::_v2::display::BitmapData applyTo( ::hxDaedalus::graphics::_Pixels::PixelsData this1,::openfl::_v2::display::BitmapData bmd);
		static Dynamic applyTo_dyn();

};

} // end namespace hxDaedalus
} // end namespace graphics
} // end namespace _Pixels

#endif /* INCLUDED_hxDaedalus_graphics__Pixels_Pixels_Impl_ */ 
