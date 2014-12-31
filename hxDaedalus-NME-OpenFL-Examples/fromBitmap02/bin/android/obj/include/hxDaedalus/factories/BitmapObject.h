#ifndef INCLUDED_hxDaedalus_factories_BitmapObject
#define INCLUDED_hxDaedalus_factories_BitmapObject

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(hxDaedalus,data,Object)
HX_DECLARE_CLASS2(hxDaedalus,factories,BitmapObject)
HX_DECLARE_CLASS2(hxDaedalus,graphics,ISimpleDrawingContext)
HX_DECLARE_CLASS3(hxDaedalus,graphics,_Pixels,PixelsData)
HX_DECLARE_CLASS3(hxDaedalus,graphics,flash,SimpleDrawingContext)
namespace hxDaedalus{
namespace factories{


class HXCPP_CLASS_ATTRIBUTES  BitmapObject_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef BitmapObject_obj OBJ_;
		BitmapObject_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< BitmapObject_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~BitmapObject_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("BitmapObject"); }

		static ::hxDaedalus::data::Object buildFromBmpData( ::hxDaedalus::graphics::_Pixels::PixelsData bmpData,hx::Null< Float >  simplificationEpsilon,::hxDaedalus::graphics::_Pixels::PixelsData debugBmp,::hxDaedalus::graphics::flash::SimpleDrawingContext debugShape);
		static Dynamic buildFromBmpData_dyn();

};

} // end namespace hxDaedalus
} // end namespace factories

#endif /* INCLUDED_hxDaedalus_factories_BitmapObject */ 
