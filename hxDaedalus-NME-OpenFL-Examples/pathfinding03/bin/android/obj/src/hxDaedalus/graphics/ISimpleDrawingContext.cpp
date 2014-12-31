#include <hxcpp.h>

#ifndef INCLUDED_hxDaedalus_graphics_ISimpleDrawingContext
#include <hxDaedalus/graphics/ISimpleDrawingContext.h>
#endif
namespace hxDaedalus{
namespace graphics{

HX_DEFINE_DYNAMIC_FUNC0(ISimpleDrawingContext_obj,clear,)

HX_DEFINE_DYNAMIC_FUNC3(ISimpleDrawingContext_obj,lineStyle,)

HX_DEFINE_DYNAMIC_FUNC2(ISimpleDrawingContext_obj,beginFill,)

HX_DEFINE_DYNAMIC_FUNC0(ISimpleDrawingContext_obj,endFill,)

HX_DEFINE_DYNAMIC_FUNC2(ISimpleDrawingContext_obj,moveTo,)

HX_DEFINE_DYNAMIC_FUNC2(ISimpleDrawingContext_obj,lineTo,)

HX_DEFINE_DYNAMIC_FUNC3(ISimpleDrawingContext_obj,drawCircle,)

HX_DEFINE_DYNAMIC_FUNC4(ISimpleDrawingContext_obj,drawRect,)


static ::String sMemberFields[] = {
	HX_CSTRING("clear"),
	HX_CSTRING("lineStyle"),
	HX_CSTRING("beginFill"),
	HX_CSTRING("endFill"),
	HX_CSTRING("moveTo"),
	HX_CSTRING("lineTo"),
	HX_CSTRING("drawCircle"),
	HX_CSTRING("drawRect"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ISimpleDrawingContext_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ISimpleDrawingContext_obj::__mClass,"__mClass");
};

#endif

Class ISimpleDrawingContext_obj::__mClass;

void ISimpleDrawingContext_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDaedalus.graphics.ISimpleDrawingContext"), hx::TCanCast< ISimpleDrawingContext_obj> ,0,sMemberFields,
	0, 0,
	&super::__SGetClass(), 0, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatics
#endif
#ifdef HXCPP_SCRIPTABLE
    , 0
#endif
);
}

void ISimpleDrawingContext_obj::__boot()
{
}

} // end namespace hxDaedalus
} // end namespace graphics
