#ifndef INCLUDED_hxDaedalus_graphics__Pixels_PixelsData
#define INCLUDED_hxDaedalus_graphics__Pixels_PixelsData

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS3(hxDaedalus,graphics,_Pixels,PixelsData)
namespace hxDaedalus{
namespace graphics{
namespace _Pixels{


class HXCPP_CLASS_ATTRIBUTES  PixelsData_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef PixelsData_obj OBJ_;
		PixelsData_obj();
		Void __construct(int width,int height,hx::Null< bool >  __o_alloc);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< PixelsData_obj > __new(int width,int height,hx::Null< bool >  __o_alloc);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~PixelsData_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("PixelsData"); }

		int length;
		::haxe::io::Bytes bytes;
		int width;
		int height;
};

} // end namespace hxDaedalus
} // end namespace graphics
} // end namespace _Pixels

#endif /* INCLUDED_hxDaedalus_graphics__Pixels_PixelsData */ 
