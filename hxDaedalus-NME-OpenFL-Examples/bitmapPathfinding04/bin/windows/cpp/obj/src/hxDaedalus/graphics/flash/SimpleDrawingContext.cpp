#include <hxcpp.h>

#ifndef INCLUDED_hxDaedalus_graphics_ISimpleDrawingContext
#include <hxDaedalus/graphics/ISimpleDrawingContext.h>
#endif
#ifndef INCLUDED_hxDaedalus_graphics_flash_SimpleDrawingContext
#include <hxDaedalus/graphics/flash/SimpleDrawingContext.h>
#endif
#ifndef INCLUDED_openfl__v2_display_CapsStyle
#include <openfl/_v2/display/CapsStyle.h>
#endif
#ifndef INCLUDED_openfl__v2_display_Graphics
#include <openfl/_v2/display/Graphics.h>
#endif
#ifndef INCLUDED_openfl__v2_display_JointStyle
#include <openfl/_v2/display/JointStyle.h>
#endif
#ifndef INCLUDED_openfl__v2_display_LineScaleMode
#include <openfl/_v2/display/LineScaleMode.h>
#endif
namespace hxDaedalus{
namespace graphics{
namespace flash{

Void SimpleDrawingContext_obj::__construct(::openfl::_v2::display::Graphics graphics)
{
HX_STACK_FRAME("hxDaedalus.graphics.flash.SimpleDrawingContext","new",0xea9a223d,"hxDaedalus.graphics.flash.SimpleDrawingContext.new","hxDaedalus/graphics/flash/SimpleDrawingContext.hx",12,0xf0b6f012)
HX_STACK_THIS(this)
HX_STACK_ARG(graphics,"graphics")
{
	HX_STACK_LINE(12)
	this->graphics = graphics;
}
;
	return null();
}

//SimpleDrawingContext_obj::~SimpleDrawingContext_obj() { }

Dynamic SimpleDrawingContext_obj::__CreateEmpty() { return  new SimpleDrawingContext_obj; }
hx::ObjectPtr< SimpleDrawingContext_obj > SimpleDrawingContext_obj::__new(::openfl::_v2::display::Graphics graphics)
{  hx::ObjectPtr< SimpleDrawingContext_obj > result = new SimpleDrawingContext_obj();
	result->__construct(graphics);
	return result;}

Dynamic SimpleDrawingContext_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SimpleDrawingContext_obj > result = new SimpleDrawingContext_obj();
	result->__construct(inArgs[0]);
	return result;}

hx::Object *SimpleDrawingContext_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::hxDaedalus::graphics::ISimpleDrawingContext_obj)) return operator ::hxDaedalus::graphics::ISimpleDrawingContext_obj *();
	return super::__ToInterface(inType);
}

Void SimpleDrawingContext_obj::clear( ){
{
		HX_STACK_FRAME("hxDaedalus.graphics.flash.SimpleDrawingContext","clear",0x0e3fb4aa,"hxDaedalus.graphics.flash.SimpleDrawingContext.clear","hxDaedalus/graphics/flash/SimpleDrawingContext.hx",16,0xf0b6f012)
		HX_STACK_THIS(this)
		HX_STACK_LINE(16)
		this->graphics->clear();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(SimpleDrawingContext_obj,clear,(void))

Void SimpleDrawingContext_obj::lineStyle( Float thickness,int color,Dynamic __o_alpha){
Dynamic alpha = __o_alpha.Default(1);
	HX_STACK_FRAME("hxDaedalus.graphics.flash.SimpleDrawingContext","lineStyle",0xde793e3a,"hxDaedalus.graphics.flash.SimpleDrawingContext.lineStyle","hxDaedalus/graphics/flash/SimpleDrawingContext.hx",21,0xf0b6f012)
	HX_STACK_THIS(this)
	HX_STACK_ARG(thickness,"thickness")
	HX_STACK_ARG(color,"color")
	HX_STACK_ARG(alpha,"alpha")
{
		HX_STACK_LINE(21)
		this->graphics->lineStyle(thickness,color,alpha,null(),null(),null(),null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(SimpleDrawingContext_obj,lineStyle,(void))

Void SimpleDrawingContext_obj::beginFill( int color,Dynamic __o_alpha){
Dynamic alpha = __o_alpha.Default(1);
	HX_STACK_FRAME("hxDaedalus.graphics.flash.SimpleDrawingContext","beginFill",0x9ff642e9,"hxDaedalus.graphics.flash.SimpleDrawingContext.beginFill","hxDaedalus/graphics/flash/SimpleDrawingContext.hx",25,0xf0b6f012)
	HX_STACK_THIS(this)
	HX_STACK_ARG(color,"color")
	HX_STACK_ARG(alpha,"alpha")
{
		HX_STACK_LINE(25)
		this->graphics->beginFill(color,alpha);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(SimpleDrawingContext_obj,beginFill,(void))

Void SimpleDrawingContext_obj::endFill( ){
{
		HX_STACK_FRAME("hxDaedalus.graphics.flash.SimpleDrawingContext","endFill",0x5fb18c5b,"hxDaedalus.graphics.flash.SimpleDrawingContext.endFill","hxDaedalus/graphics/flash/SimpleDrawingContext.hx",29,0xf0b6f012)
		HX_STACK_THIS(this)
		HX_STACK_LINE(29)
		this->graphics->endFill();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(SimpleDrawingContext_obj,endFill,(void))

Void SimpleDrawingContext_obj::moveTo( Float x,Float y){
{
		HX_STACK_FRAME("hxDaedalus.graphics.flash.SimpleDrawingContext","moveTo",0x2e83492f,"hxDaedalus.graphics.flash.SimpleDrawingContext.moveTo","hxDaedalus/graphics/flash/SimpleDrawingContext.hx",33,0xf0b6f012)
		HX_STACK_THIS(this)
		HX_STACK_ARG(x,"x")
		HX_STACK_ARG(y,"y")
		HX_STACK_LINE(33)
		this->graphics->moveTo(x,y);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(SimpleDrawingContext_obj,moveTo,(void))

Void SimpleDrawingContext_obj::lineTo( Float x,Float y){
{
		HX_STACK_FRAME("hxDaedalus.graphics.flash.SimpleDrawingContext","lineTo",0x4e76bcd2,"hxDaedalus.graphics.flash.SimpleDrawingContext.lineTo","hxDaedalus/graphics/flash/SimpleDrawingContext.hx",37,0xf0b6f012)
		HX_STACK_THIS(this)
		HX_STACK_ARG(x,"x")
		HX_STACK_ARG(y,"y")
		HX_STACK_LINE(37)
		this->graphics->lineTo(x,y);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(SimpleDrawingContext_obj,lineTo,(void))

Void SimpleDrawingContext_obj::drawCircle( Float cx,Float cy,Float radius){
{
		HX_STACK_FRAME("hxDaedalus.graphics.flash.SimpleDrawingContext","drawCircle",0x78f340f7,"hxDaedalus.graphics.flash.SimpleDrawingContext.drawCircle","hxDaedalus/graphics/flash/SimpleDrawingContext.hx",41,0xf0b6f012)
		HX_STACK_THIS(this)
		HX_STACK_ARG(cx,"cx")
		HX_STACK_ARG(cy,"cy")
		HX_STACK_ARG(radius,"radius")
		HX_STACK_LINE(41)
		this->graphics->drawCircle(cx,cy,radius);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(SimpleDrawingContext_obj,drawCircle,(void))

Void SimpleDrawingContext_obj::drawRect( Float x,Float y,Float width,Float height){
{
		HX_STACK_FRAME("hxDaedalus.graphics.flash.SimpleDrawingContext","drawRect",0xbd23c44b,"hxDaedalus.graphics.flash.SimpleDrawingContext.drawRect","hxDaedalus/graphics/flash/SimpleDrawingContext.hx",45,0xf0b6f012)
		HX_STACK_THIS(this)
		HX_STACK_ARG(x,"x")
		HX_STACK_ARG(y,"y")
		HX_STACK_ARG(width,"width")
		HX_STACK_ARG(height,"height")
		HX_STACK_LINE(45)
		this->graphics->drawRect(x,y,width,height);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(SimpleDrawingContext_obj,drawRect,(void))


SimpleDrawingContext_obj::SimpleDrawingContext_obj()
{
}

void SimpleDrawingContext_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(SimpleDrawingContext);
	HX_MARK_MEMBER_NAME(graphics,"graphics");
	HX_MARK_END_CLASS();
}

void SimpleDrawingContext_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(graphics,"graphics");
}

Dynamic SimpleDrawingContext_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"clear") ) { return clear_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"moveTo") ) { return moveTo_dyn(); }
		if (HX_FIELD_EQ(inName,"lineTo") ) { return lineTo_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"endFill") ) { return endFill_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"graphics") ) { return graphics; }
		if (HX_FIELD_EQ(inName,"drawRect") ) { return drawRect_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"lineStyle") ) { return lineStyle_dyn(); }
		if (HX_FIELD_EQ(inName,"beginFill") ) { return beginFill_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"drawCircle") ) { return drawCircle_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic SimpleDrawingContext_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"graphics") ) { graphics=inValue.Cast< ::openfl::_v2::display::Graphics >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void SimpleDrawingContext_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("graphics"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::openfl::_v2::display::Graphics*/ ,(int)offsetof(SimpleDrawingContext_obj,graphics),HX_CSTRING("graphics")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("graphics"),
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
	HX_MARK_MEMBER_NAME(SimpleDrawingContext_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(SimpleDrawingContext_obj::__mClass,"__mClass");
};

#endif

Class SimpleDrawingContext_obj::__mClass;

void SimpleDrawingContext_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDaedalus.graphics.flash.SimpleDrawingContext"), hx::TCanCast< SimpleDrawingContext_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatics
#endif
#ifdef HXCPP_SCRIPTABLE
    , sMemberStorageInfo
#endif
);
}

void SimpleDrawingContext_obj::__boot()
{
}

} // end namespace hxDaedalus
} // end namespace graphics
} // end namespace flash
