#include <hxcpp.h>

#ifndef INCLUDED_Sys
#include <Sys.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_Mesh
#include <hxDaedalus/data/Mesh.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_Object
#include <hxDaedalus/data/Object.h>
#endif
#ifndef INCLUDED_hxDaedalus_examples_fromBitmap02_Main
#include <hxDaedalus/examples/fromBitmap02/Main.h>
#endif
#ifndef INCLUDED_hxDaedalus_examples_fromBitmap02_TestImage
#include <hxDaedalus/examples/fromBitmap02/TestImage.h>
#endif
#ifndef INCLUDED_hxDaedalus_factories_BitmapObject
#include <hxDaedalus/factories/BitmapObject.h>
#endif
#ifndef INCLUDED_hxDaedalus_factories_RectMesh
#include <hxDaedalus/factories/RectMesh.h>
#endif
#ifndef INCLUDED_hxDaedalus_graphics_ISimpleDrawingContext
#include <hxDaedalus/graphics/ISimpleDrawingContext.h>
#endif
#ifndef INCLUDED_hxDaedalus_graphics__Pixels_PixelsData
#include <hxDaedalus/graphics/_Pixels/PixelsData.h>
#endif
#ifndef INCLUDED_hxDaedalus_graphics__Pixels_Pixels_Impl_
#include <hxDaedalus/graphics/_Pixels/Pixels_Impl_.h>
#endif
#ifndef INCLUDED_hxDaedalus_graphics_flash_SimpleDrawingContext
#include <hxDaedalus/graphics/flash/SimpleDrawingContext.h>
#endif
#ifndef INCLUDED_hxDaedalus_view_SimpleView
#include <hxDaedalus/view/SimpleView.h>
#endif
#ifndef INCLUDED_openfl__v2_Lib
#include <openfl/_v2/Lib.h>
#endif
#ifndef INCLUDED_openfl__v2_display_Bitmap
#include <openfl/_v2/display/Bitmap.h>
#endif
#ifndef INCLUDED_openfl__v2_display_BitmapData
#include <openfl/_v2/display/BitmapData.h>
#endif
#ifndef INCLUDED_openfl__v2_display_DisplayObject
#include <openfl/_v2/display/DisplayObject.h>
#endif
#ifndef INCLUDED_openfl__v2_display_DisplayObjectContainer
#include <openfl/_v2/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_openfl__v2_display_Graphics
#include <openfl/_v2/display/Graphics.h>
#endif
#ifndef INCLUDED_openfl__v2_display_IBitmapDrawable
#include <openfl/_v2/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_openfl__v2_display_InteractiveObject
#include <openfl/_v2/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_openfl__v2_display_MovieClip
#include <openfl/_v2/display/MovieClip.h>
#endif
#ifndef INCLUDED_openfl__v2_display_Sprite
#include <openfl/_v2/display/Sprite.h>
#endif
#ifndef INCLUDED_openfl__v2_display_Stage
#include <openfl/_v2/display/Stage.h>
#endif
#ifndef INCLUDED_openfl__v2_events_Event
#include <openfl/_v2/events/Event.h>
#endif
#ifndef INCLUDED_openfl__v2_events_EventDispatcher
#include <openfl/_v2/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_openfl__v2_events_IEventDispatcher
#include <openfl/_v2/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_openfl__v2_events_KeyboardEvent
#include <openfl/_v2/events/KeyboardEvent.h>
#endif
#ifndef INCLUDED_openfl_display_PixelSnapping
#include <openfl/display/PixelSnapping.h>
#endif
#ifndef INCLUDED_openfl_display_StageAlign
#include <openfl/display/StageAlign.h>
#endif
#ifndef INCLUDED_openfl_display_StageScaleMode
#include <openfl/display/StageScaleMode.h>
#endif
namespace hxDaedalus{
namespace examples{
namespace fromBitmap02{

Void Main_obj::__construct()
{
HX_STACK_FRAME("hxDaedalus.examples.fromBitmap02.Main","new",0x960c8232,"hxDaedalus.examples.fromBitmap02.Main.new","hxDaedalus/examples/fromBitmap02/Main.hx",83,0xf854637d)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(84)
	super::__construct();
	HX_STACK_LINE(85)
	this->addEventListener(::openfl::_v2::events::Event_obj::ADDED_TO_STAGE,this->added_dyn(),null(),null(),null());
}
;
	return null();
}

//Main_obj::~Main_obj() { }

Dynamic Main_obj::__CreateEmpty() { return  new Main_obj; }
hx::ObjectPtr< Main_obj > Main_obj::__new()
{  hx::ObjectPtr< Main_obj > result = new Main_obj();
	result->__construct();
	return result;}

Dynamic Main_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Main_obj > result = new Main_obj();
	result->__construct();
	return result;}

Void Main_obj::resize( Dynamic e){
{
		HX_STACK_FRAME("hxDaedalus.examples.fromBitmap02.Main","resize",0x5f561762,"hxDaedalus.examples.fromBitmap02.Main.resize","hxDaedalus/examples/fromBitmap02/Main.hx",34,0xf854637d)
		HX_STACK_THIS(this)
		HX_STACK_ARG(e,"e")
		HX_STACK_LINE(34)
		if ((!(this->inited))){
			HX_STACK_LINE(34)
			this->init();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,resize,(void))

Void Main_obj::init( ){
{
		HX_STACK_FRAME("hxDaedalus.examples.fromBitmap02.Main","init",0xb19e20fe,"hxDaedalus.examples.fromBitmap02.Main.init","hxDaedalus/examples/fromBitmap02/Main.hx",39,0xf854637d)
		HX_STACK_THIS(this)
		HX_STACK_LINE(40)
		if ((this->inited)){
			HX_STACK_LINE(40)
			return null();
		}
		HX_STACK_LINE(41)
		this->inited = true;
		HX_STACK_LINE(44)
		::hxDaedalus::data::Mesh _g = ::hxDaedalus::factories::RectMesh_obj::buildRectangle((int)600,(int)600);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(44)
		this->_mesh = _g;
		HX_STACK_LINE(49)
		::hxDaedalus::examples::fromBitmap02::TestImage _g1 = ::hxDaedalus::examples::fromBitmap02::TestImage_obj::__new((int)0,(int)0,null(),null());		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(49)
		::openfl::_v2::display::Bitmap _g2 = ::openfl::_v2::display::Bitmap_obj::__new(_g1,null(),null());		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(49)
		this->_bmp = _g2;
		HX_STACK_LINE(51)
		this->_bmp->set_x((int)110);
		HX_STACK_LINE(52)
		this->_bmp->set_y((int)220);
		HX_STACK_LINE(53)
		this->addChild(this->_bmp);
		HX_STACK_LINE(55)
		::openfl::_v2::display::Sprite viewSprite = ::openfl::_v2::display::Sprite_obj::__new();		HX_STACK_VAR(viewSprite,"viewSprite");
		HX_STACK_LINE(56)
		::openfl::_v2::display::Graphics _g3 = viewSprite->get_graphics();		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(56)
		::hxDaedalus::view::SimpleView _g4 = ::hxDaedalus::view::SimpleView_obj::__new(_g3);		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(56)
		this->_view = _g4;
		HX_STACK_LINE(57)
		this->addChild(viewSprite);
		HX_STACK_LINE(59)
		::hxDaedalus::graphics::_Pixels::PixelsData _g5 = ::hxDaedalus::graphics::_Pixels::Pixels_Impl__obj::fromBitmapData(this->_bmp->bitmapData);		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(59)
		::hxDaedalus::data::Object _g6 = ::hxDaedalus::factories::BitmapObject_obj::buildFromBmpData(_g5,null(),null(),null());		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(59)
		this->_object = _g6;
		HX_STACK_LINE(60)
		this->_object->set_x((int)110);
		HX_STACK_LINE(61)
		this->_object->set_y((int)220);
		HX_STACK_LINE(62)
		this->_mesh->insertObject(this->_object);
		HX_STACK_LINE(64)
		this->_view->drawMesh(this->_mesh,null());
		HX_STACK_LINE(66)
		::openfl::_v2::Lib_obj::get_current()->get_stage()->addEventListener(::openfl::_v2::events::KeyboardEvent_obj::KEY_DOWN,this->_onKeyDown_dyn(),null(),null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Main_obj,init,(void))

Void Main_obj::_onKeyDown( ::openfl::_v2::events::KeyboardEvent event){
{
		HX_STACK_FRAME("hxDaedalus.examples.fromBitmap02.Main","_onKeyDown",0xad25aa71,"hxDaedalus.examples.fromBitmap02.Main._onKeyDown","hxDaedalus/examples/fromBitmap02/Main.hx",71,0xf854637d)
		HX_STACK_THIS(this)
		HX_STACK_ARG(event,"event")
		HX_STACK_LINE(71)
		if (((event->keyCode == (int)27))){
			HX_STACK_LINE(75)
			::Sys_obj::exit((int)1);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,_onKeyDown,(void))

Void Main_obj::added( Dynamic e){
{
		HX_STACK_FRAME("hxDaedalus.examples.fromBitmap02.Main","added",0x16ea1f12,"hxDaedalus.examples.fromBitmap02.Main.added","hxDaedalus/examples/fromBitmap02/Main.hx",89,0xf854637d)
		HX_STACK_THIS(this)
		HX_STACK_ARG(e,"e")
		HX_STACK_LINE(90)
		this->removeEventListener(::openfl::_v2::events::Event_obj::ADDED_TO_STAGE,this->added_dyn(),null());
		HX_STACK_LINE(91)
		this->get_stage()->addEventListener(::openfl::_v2::events::Event_obj::RESIZE,this->resize_dyn(),null(),null(),null());
		HX_STACK_LINE(95)
		this->init();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,added,(void))

Void Main_obj::main( ){
{
		HX_STACK_FRAME("hxDaedalus.examples.fromBitmap02.Main","main",0xb4391e27,"hxDaedalus.examples.fromBitmap02.Main.main","hxDaedalus/examples/fromBitmap02/Main.hx",100,0xf854637d)
		HX_STACK_LINE(102)
		::openfl::_v2::Lib_obj::get_current()->get_stage()->set_align(::openfl::display::StageAlign_obj::TOP_LEFT);
		HX_STACK_LINE(103)
		::openfl::_v2::Lib_obj::get_current()->get_stage()->set_scaleMode(::openfl::display::StageScaleMode_obj::NO_SCALE);
		HX_STACK_LINE(104)
		::hxDaedalus::examples::fromBitmap02::Main _g = ::hxDaedalus::examples::fromBitmap02::Main_obj::__new();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(104)
		::openfl::_v2::Lib_obj::get_current()->addChild(_g);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Main_obj,main,(void))


Main_obj::Main_obj()
{
}

void Main_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Main);
	HX_MARK_MEMBER_NAME(inited,"inited");
	HX_MARK_MEMBER_NAME(_mesh,"_mesh");
	HX_MARK_MEMBER_NAME(_view,"_view");
	HX_MARK_MEMBER_NAME(_object,"_object");
	HX_MARK_MEMBER_NAME(_bmp,"_bmp");
	::openfl::_v2::display::DisplayObjectContainer_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Main_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(inited,"inited");
	HX_VISIT_MEMBER_NAME(_mesh,"_mesh");
	HX_VISIT_MEMBER_NAME(_view,"_view");
	HX_VISIT_MEMBER_NAME(_object,"_object");
	HX_VISIT_MEMBER_NAME(_bmp,"_bmp");
	::openfl::_v2::display::DisplayObjectContainer_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Main_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"main") ) { return main_dyn(); }
		if (HX_FIELD_EQ(inName,"_bmp") ) { return _bmp; }
		if (HX_FIELD_EQ(inName,"init") ) { return init_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_mesh") ) { return _mesh; }
		if (HX_FIELD_EQ(inName,"_view") ) { return _view; }
		if (HX_FIELD_EQ(inName,"added") ) { return added_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"inited") ) { return inited; }
		if (HX_FIELD_EQ(inName,"resize") ) { return resize_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_object") ) { return _object; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_onKeyDown") ) { return _onKeyDown_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Main_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"_bmp") ) { _bmp=inValue.Cast< ::openfl::_v2::display::Bitmap >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_mesh") ) { _mesh=inValue.Cast< ::hxDaedalus::data::Mesh >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_view") ) { _view=inValue.Cast< ::hxDaedalus::view::SimpleView >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"inited") ) { inited=inValue.Cast< bool >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_object") ) { _object=inValue.Cast< ::hxDaedalus::data::Object >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Main_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("inited"));
	outFields->push(HX_CSTRING("_mesh"));
	outFields->push(HX_CSTRING("_view"));
	outFields->push(HX_CSTRING("_object"));
	outFields->push(HX_CSTRING("_bmp"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("main"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsBool,(int)offsetof(Main_obj,inited),HX_CSTRING("inited")},
	{hx::fsObject /*::hxDaedalus::data::Mesh*/ ,(int)offsetof(Main_obj,_mesh),HX_CSTRING("_mesh")},
	{hx::fsObject /*::hxDaedalus::view::SimpleView*/ ,(int)offsetof(Main_obj,_view),HX_CSTRING("_view")},
	{hx::fsObject /*::hxDaedalus::data::Object*/ ,(int)offsetof(Main_obj,_object),HX_CSTRING("_object")},
	{hx::fsObject /*::openfl::_v2::display::Bitmap*/ ,(int)offsetof(Main_obj,_bmp),HX_CSTRING("_bmp")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("inited"),
	HX_CSTRING("_mesh"),
	HX_CSTRING("_view"),
	HX_CSTRING("_object"),
	HX_CSTRING("_bmp"),
	HX_CSTRING("resize"),
	HX_CSTRING("init"),
	HX_CSTRING("_onKeyDown"),
	HX_CSTRING("added"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Main_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Main_obj::__mClass,"__mClass");
};

#endif

Class Main_obj::__mClass;

void Main_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDaedalus.examples.fromBitmap02.Main"), hx::TCanCast< Main_obj> ,sStaticFields,sMemberFields,
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

void Main_obj::__boot()
{
}

} // end namespace hxDaedalus
} // end namespace examples
} // end namespace fromBitmap02
