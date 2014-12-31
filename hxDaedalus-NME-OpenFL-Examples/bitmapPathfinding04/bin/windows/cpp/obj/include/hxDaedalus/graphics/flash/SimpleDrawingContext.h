#ifndef INCLUDED_hxDaedalus_graphics_flash_SimpleDrawingContext
#define INCLUDED_hxDaedalus_graphics_flash_SimpleDrawingContext

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <hxDaedalus/graphics/ISimpleDrawingContext.h>
HX_DECLARE_CLASS2(hxDaedalus,graphics,ISimpleDrawingContext)
HX_DECLARE_CLASS3(hxDaedalus,graphics,flash,SimpleDrawingContext)
HX_DECLARE_CLASS3(openfl,_v2,display,Graphics)
namespace hxDaedalus{
namespace graphics{
namespace flash{


class HXCPP_CLASS_ATTRIBUTES  SimpleDrawingContext_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef SimpleDrawingContext_obj OBJ_;
		SimpleDrawingContext_obj();
		Void __construct(::openfl::_v2::display::Graphics graphics);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< SimpleDrawingContext_obj > __new(::openfl::_v2::display::Graphics graphics);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~SimpleDrawingContext_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::hxDaedalus::graphics::ISimpleDrawingContext_obj *()
			{ return new ::hxDaedalus::graphics::ISimpleDrawingContext_delegate_< SimpleDrawingContext_obj >(this); }
		hx::Object *__ToInterface(const hx::type_info &inType);
		::String __ToString() const { return HX_CSTRING("SimpleDrawingContext"); }

		::openfl::_v2::display::Graphics graphics;
		virtual Void clear( );
		Dynamic clear_dyn();

		virtual Void lineStyle( Float thickness,int color,Dynamic alpha);
		Dynamic lineStyle_dyn();

		virtual Void beginFill( int color,Dynamic alpha);
		Dynamic beginFill_dyn();

		virtual Void endFill( );
		Dynamic endFill_dyn();

		virtual Void moveTo( Float x,Float y);
		Dynamic moveTo_dyn();

		virtual Void lineTo( Float x,Float y);
		Dynamic lineTo_dyn();

		virtual Void drawCircle( Float cx,Float cy,Float radius);
		Dynamic drawCircle_dyn();

		virtual Void drawRect( Float x,Float y,Float width,Float height);
		Dynamic drawRect_dyn();

};

} // end namespace hxDaedalus
} // end namespace graphics
} // end namespace flash

#endif /* INCLUDED_hxDaedalus_graphics_flash_SimpleDrawingContext */ 
