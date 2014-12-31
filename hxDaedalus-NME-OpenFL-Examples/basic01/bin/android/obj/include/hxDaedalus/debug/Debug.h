#ifndef INCLUDED_hxDaedalus_debug_Debug
#define INCLUDED_hxDaedalus_debug_Debug

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(hxDaedalus,debug,Debug)
namespace hxDaedalus{
namespace debug{


class HXCPP_CLASS_ATTRIBUTES  Debug_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Debug_obj OBJ_;
		Debug_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Debug_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Debug_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("Debug"); }

		static Void assertTrue( bool cond,::String message,Dynamic pos);
		static Dynamic assertTrue_dyn();

		static Void assertFalse( bool cond,::String message,Dynamic pos);
		static Dynamic assertFalse_dyn();

		static Void assertEquals( Dynamic expected,Dynamic actual,::String message,Dynamic pos);
		static Dynamic assertEquals_dyn();

		static Void trace( Dynamic value,Dynamic pos);
		static Dynamic trace_dyn();

};

} // end namespace hxDaedalus
} // end namespace debug

#endif /* INCLUDED_hxDaedalus_debug_Debug */ 
