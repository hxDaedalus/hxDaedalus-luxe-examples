#ifndef INCLUDED_hxDaedalus_graphics_Converter
#define INCLUDED_hxDaedalus_graphics_Converter

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS2(hxDaedalus,graphics,Converter)
namespace hxDaedalus{
namespace graphics{


class HXCPP_CLASS_ATTRIBUTES  Converter_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Converter_obj OBJ_;
		Converter_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Converter_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Converter_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("Converter"); }

		static Void ARGB2RGBA( ::haxe::io::Bytes inBytesARGB,::haxe::io::Bytes outBytesRGBA);
		static Dynamic ARGB2RGBA_dyn();

		static Void RGBA2ARGB( ::haxe::io::Bytes inBytesRGBA,::haxe::io::Bytes outBytesARGB);
		static Dynamic RGBA2ARGB_dyn();

};

} // end namespace hxDaedalus
} // end namespace graphics

#endif /* INCLUDED_hxDaedalus_graphics_Converter */ 
