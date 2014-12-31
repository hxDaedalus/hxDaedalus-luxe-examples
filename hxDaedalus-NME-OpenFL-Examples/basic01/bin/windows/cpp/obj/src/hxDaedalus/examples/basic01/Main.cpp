#include <hxcpp.h>

#ifndef INCLUDED_Sys
#include <Sys.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_ConstraintSegment
#include <hxDaedalus/data/ConstraintSegment.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_ConstraintShape
#include <hxDaedalus/data/ConstraintShape.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_Mesh
#include <hxDaedalus/data/Mesh.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_Object
#include <hxDaedalus/data/Object.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_Vertex
#include <hxDaedalus/data/Vertex.h>
#endif
#ifndef INCLUDED_hxDaedalus_examples_basic01_Main
#include <hxDaedalus/examples/basic01/Main.h>
#endif
#ifndef INCLUDED_hxDaedalus_factories_RectMesh
#include <hxDaedalus/factories/RectMesh.h>
#endif
#ifndef INCLUDED_hxDaedalus_view_SimpleView
#include <hxDaedalus/view/SimpleView.h>
#endif
#ifndef INCLUDED_openfl__v2_Lib
#include <openfl/_v2/Lib.h>
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
#ifndef INCLUDED_openfl_display_StageAlign
#include <openfl/display/StageAlign.h>
#endif
#ifndef INCLUDED_openfl_display_StageScaleMode
#include <openfl/display/StageScaleMode.h>
#endif
namespace hxDaedalus{
namespace examples{
namespace basic01{

Void Main_obj::__construct()
{
HX_STACK_FRAME("hxDaedalus.examples.basic01.Main","new",0x6a06ed96,"hxDaedalus.examples.basic01.Main.new","hxDaedalus/examples/basic01/Main.hx",128,0x83932cd9)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(129)
	super::__construct();
	HX_STACK_LINE(130)
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
		HX_STACK_FRAME("hxDaedalus.examples.basic01.Main","resize",0xbf89e27e,"hxDaedalus.examples.basic01.Main.resize","hxDaedalus/examples/basic01/Main.hx",32,0x83932cd9)
		HX_STACK_THIS(this)
		HX_STACK_ARG(e,"e")
		HX_STACK_LINE(32)
		if ((!(this->inited))){
			HX_STACK_LINE(32)
			this->init();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,resize,(void))

Void Main_obj::init( ){
{
		HX_STACK_FRAME("hxDaedalus.examples.basic01.Main","init",0x58c1ad1a,"hxDaedalus.examples.basic01.Main.init","hxDaedalus/examples/basic01/Main.hx",37,0x83932cd9)
		HX_STACK_THIS(this)
		HX_STACK_LINE(38)
		if ((this->inited)){
			HX_STACK_LINE(38)
			return null();
		}
		HX_STACK_LINE(39)
		this->inited = true;
		HX_STACK_LINE(42)
		::hxDaedalus::data::Mesh _g = ::hxDaedalus::factories::RectMesh_obj::buildRectangle((int)600,(int)400);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(42)
		this->_mesh = _g;
		HX_STACK_LINE(46)
		::openfl::_v2::display::Sprite viewSprite = ::openfl::_v2::display::Sprite_obj::__new();		HX_STACK_VAR(viewSprite,"viewSprite");
		HX_STACK_LINE(47)
		::openfl::_v2::display::Graphics _g1 = viewSprite->get_graphics();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(47)
		::hxDaedalus::view::SimpleView _g2 = ::hxDaedalus::view::SimpleView_obj::__new(_g1);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(47)
		this->_view = _g2;
		HX_STACK_LINE(48)
		this->addChild(viewSprite);
		HX_STACK_LINE(53)
		::hxDaedalus::data::Vertex vertex = this->_mesh->insertVertex((int)550,(int)50);		HX_STACK_VAR(vertex,"vertex");
		HX_STACK_LINE(60)
		::hxDaedalus::data::ConstraintSegment segment = this->_mesh->insertConstraintSegment((int)70,(int)300,(int)530,(int)320);		HX_STACK_VAR(segment,"segment");
		HX_STACK_LINE(67)
		::hxDaedalus::data::ConstraintShape shape = this->_mesh->insertConstraintShape(Array_obj< Float >::__new().Add(50.).Add(50.).Add(100.).Add(50.).Add(100.).Add(50.).Add(100.).Add(100.).Add(100.).Add(100.).Add(50.).Add(100.).Add(50.).Add(100.).Add(50.).Add(50.).Add(20.).Add(50.).Add(130.).Add(100.));		HX_STACK_VAR(shape,"shape");
		HX_STACK_LINE(80)
		Array< Float > objectCoords = Array_obj< Float >::__new();		HX_STACK_VAR(objectCoords,"objectCoords");
		HX_STACK_LINE(82)
		::hxDaedalus::data::Object _g3 = ::hxDaedalus::data::Object_obj::__new();		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(82)
		this->_object = _g3;
		HX_STACK_LINE(83)
		this->_object->set_coordinates(Array_obj< Float >::__new().Add(-50.).Add(0.).Add(50.).Add(0.).Add(0.).Add(-50.).Add(0.).Add(50.).Add(-30.).Add(-30.).Add(30.).Add(30.).Add(30.).Add(-30.).Add(-30.).Add(30.));
		HX_STACK_LINE(88)
		this->_mesh->insertObject(this->_object);
		HX_STACK_LINE(90)
		this->_object->set_x((int)400);
		HX_STACK_LINE(91)
		this->_object->set_y((int)200);
		HX_STACK_LINE(92)
		this->_object->set_scaleX((int)2);
		HX_STACK_LINE(93)
		this->_object->set_scaleY((int)2);
		HX_STACK_LINE(98)
		::openfl::_v2::Lib_obj::get_current()->get_stage()->addEventListener(::openfl::_v2::events::Event_obj::ENTER_FRAME,this->_onEnterFrame_dyn(),null(),null(),null());
		HX_STACK_LINE(101)
		::openfl::_v2::Lib_obj::get_current()->get_stage()->addEventListener(::openfl::_v2::events::KeyboardEvent_obj::KEY_DOWN,this->_onKeyDown_dyn(),null(),null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Main_obj,init,(void))

Void Main_obj::_onEnterFrame( ::openfl::_v2::events::Event event){
{
		HX_STACK_FRAME("hxDaedalus.examples.basic01.Main","_onEnterFrame",0xc5863589,"hxDaedalus.examples.basic01.Main._onEnterFrame","hxDaedalus/examples/basic01/Main.hx",104,0x83932cd9)
		HX_STACK_THIS(this)
		HX_STACK_ARG(event,"event")
		HX_STACK_LINE(106)
		{
			HX_STACK_LINE(106)
			::hxDaedalus::data::Object _g = this->_object;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(106)
			Float _g1 = _g->get_rotation();		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(106)
			Float _g11 = (_g1 + 0.05);		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(106)
			_g->set_rotation(_g11);
		}
		HX_STACK_LINE(108)
		this->_mesh->updateObjects();
		HX_STACK_LINE(111)
		this->_view->drawMesh(this->_mesh,true);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,_onEnterFrame,(void))

Void Main_obj::_onKeyDown( ::openfl::_v2::events::KeyboardEvent event){
{
		HX_STACK_FRAME("hxDaedalus.examples.basic01.Main","_onKeyDown",0x19d3338d,"hxDaedalus.examples.basic01.Main._onKeyDown","hxDaedalus/examples/basic01/Main.hx",116,0x83932cd9)
		HX_STACK_THIS(this)
		HX_STACK_ARG(event,"event")
		HX_STACK_LINE(116)
		if (((event->keyCode == (int)27))){
			HX_STACK_LINE(120)
			::Sys_obj::exit((int)1);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,_onKeyDown,(void))

Void Main_obj::added( Dynamic e){
{
		HX_STACK_FRAME("hxDaedalus.examples.basic01.Main","added",0xaee12b76,"hxDaedalus.examples.basic01.Main.added","hxDaedalus/examples/basic01/Main.hx",134,0x83932cd9)
		HX_STACK_THIS(this)
		HX_STACK_ARG(e,"e")
		HX_STACK_LINE(135)
		this->removeEventListener(::openfl::_v2::events::Event_obj::ADDED_TO_STAGE,this->added_dyn(),null());
		HX_STACK_LINE(136)
		this->get_stage()->addEventListener(::openfl::_v2::events::Event_obj::RESIZE,this->resize_dyn(),null(),null(),null());
		HX_STACK_LINE(140)
		this->init();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,added,(void))

Void Main_obj::main( ){
{
		HX_STACK_FRAME("hxDaedalus.examples.basic01.Main","main",0x5b5caa43,"hxDaedalus.examples.basic01.Main.main","hxDaedalus/examples/basic01/Main.hx",145,0x83932cd9)
		HX_STACK_LINE(147)
		::openfl::_v2::Lib_obj::get_current()->get_stage()->set_align(::openfl::display::StageAlign_obj::TOP_LEFT);
		HX_STACK_LINE(148)
		::openfl::_v2::Lib_obj::get_current()->get_stage()->set_scaleMode(::openfl::display::StageScaleMode_obj::NO_SCALE);
		HX_STACK_LINE(149)
		::hxDaedalus::examples::basic01::Main _g = ::hxDaedalus::examples::basic01::Main_obj::__new();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(149)
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
	::openfl::_v2::display::DisplayObjectContainer_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Main_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(inited,"inited");
	HX_VISIT_MEMBER_NAME(_mesh,"_mesh");
	HX_VISIT_MEMBER_NAME(_view,"_view");
	HX_VISIT_MEMBER_NAME(_object,"_object");
	::openfl::_v2::display::DisplayObjectContainer_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Main_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"main") ) { return main_dyn(); }
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
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_onEnterFrame") ) { return _onEnterFrame_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Main_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
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
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("inited"),
	HX_CSTRING("_mesh"),
	HX_CSTRING("_view"),
	HX_CSTRING("_object"),
	HX_CSTRING("resize"),
	HX_CSTRING("init"),
	HX_CSTRING("_onEnterFrame"),
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
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDaedalus.examples.basic01.Main"), hx::TCanCast< Main_obj> ,sStaticFields,sMemberFields,
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
} // end namespace basic01
