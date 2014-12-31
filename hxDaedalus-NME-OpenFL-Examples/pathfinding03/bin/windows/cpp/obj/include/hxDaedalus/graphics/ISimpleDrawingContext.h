#ifndef INCLUDED_hxDaedalus_graphics_ISimpleDrawingContext
#define INCLUDED_hxDaedalus_graphics_ISimpleDrawingContext

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(hxDaedalus,graphics,ISimpleDrawingContext)
namespace hxDaedalus{
namespace graphics{


class HXCPP_CLASS_ATTRIBUTES  ISimpleDrawingContext_obj : public hx::Interface{
	public:
		typedef hx::Interface super;
		typedef ISimpleDrawingContext_obj OBJ_;
		HX_DO_INTERFACE_RTTI;
		static void __boot();
virtual Void clear( )=0;
		Dynamic clear_dyn();
virtual Void lineStyle( Float thickness,int color,Dynamic alpha)=0;
		Dynamic lineStyle_dyn();
virtual Void beginFill( int color,Dynamic alpha)=0;
		Dynamic beginFill_dyn();
virtual Void endFill( )=0;
		Dynamic endFill_dyn();
virtual Void moveTo( Float x,Float y)=0;
		Dynamic moveTo_dyn();
virtual Void lineTo( Float x,Float y)=0;
		Dynamic lineTo_dyn();
virtual Void drawCircle( Float cx,Float cy,Float radius)=0;
		Dynamic drawCircle_dyn();
virtual Void drawRect( Float x,Float y,Float width,Float height)=0;
		Dynamic drawRect_dyn();
};

#define DELEGATE_hxDaedalus_graphics_ISimpleDrawingContext \
virtual Void clear( ) { return mDelegate->clear();}  \
virtual Dynamic clear_dyn() { return mDelegate->clear_dyn();}  \
virtual Void lineStyle( Float thickness,int color,Dynamic alpha) { return mDelegate->lineStyle(thickness,color,alpha);}  \
virtual Dynamic lineStyle_dyn() { return mDelegate->lineStyle_dyn();}  \
virtual Void beginFill( int color,Dynamic alpha) { return mDelegate->beginFill(color,alpha);}  \
virtual Dynamic beginFill_dyn() { return mDelegate->beginFill_dyn();}  \
virtual Void endFill( ) { return mDelegate->endFill();}  \
virtual Dynamic endFill_dyn() { return mDelegate->endFill_dyn();}  \
virtual Void moveTo( Float x,Float y) { return mDelegate->moveTo(x,y);}  \
virtual Dynamic moveTo_dyn() { return mDelegate->moveTo_dyn();}  \
virtual Void lineTo( Float x,Float y) { return mDelegate->lineTo(x,y);}  \
virtual Dynamic lineTo_dyn() { return mDelegate->lineTo_dyn();}  \
virtual Void drawCircle( Float cx,Float cy,Float radius) { return mDelegate->drawCircle(cx,cy,radius);}  \
virtual Dynamic drawCircle_dyn() { return mDelegate->drawCircle_dyn();}  \
virtual Void drawRect( Float x,Float y,Float width,Float height) { return mDelegate->drawRect(x,y,width,height);}  \
virtual Dynamic drawRect_dyn() { return mDelegate->drawRect_dyn();}  \


template<typename IMPL>
class ISimpleDrawingContext_delegate_ : public ISimpleDrawingContext_obj
{
	protected:
		IMPL *mDelegate;
	public:
		ISimpleDrawingContext_delegate_(IMPL *inDelegate) : mDelegate(inDelegate) {}
		hx::Object *__GetRealObject() { return mDelegate; }
		void __Visit(HX_VISIT_PARAMS) { HX_VISIT_OBJECT(mDelegate); }
		DELEGATE_hxDaedalus_graphics_ISimpleDrawingContext
};

} // end namespace hxDaedalus
} // end namespace graphics

#endif /* INCLUDED_hxDaedalus_graphics_ISimpleDrawingContext */ 
