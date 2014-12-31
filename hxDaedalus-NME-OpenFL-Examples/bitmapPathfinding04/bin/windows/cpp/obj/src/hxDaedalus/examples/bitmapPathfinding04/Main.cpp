#include <hxcpp.h>

#ifndef INCLUDED_Sys
#include <Sys.h>
#endif
#ifndef INCLUDED_haxe_Timer
#include <haxe/Timer.h>
#endif
#ifndef INCLUDED_hxDaedalus_ai_EntityAI
#include <hxDaedalus/ai/EntityAI.h>
#endif
#ifndef INCLUDED_hxDaedalus_ai_PathFinder
#include <hxDaedalus/ai/PathFinder.h>
#endif
#ifndef INCLUDED_hxDaedalus_ai_trajectory_LinearPathSampler
#include <hxDaedalus/ai/trajectory/LinearPathSampler.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_Mesh
#include <hxDaedalus/data/Mesh.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_Object
#include <hxDaedalus/data/Object.h>
#endif
#ifndef INCLUDED_hxDaedalus_examples_bitmapPathfinding04_GalapagosBW
#include <hxDaedalus/examples/bitmapPathfinding04/GalapagosBW.h>
#endif
#ifndef INCLUDED_hxDaedalus_examples_bitmapPathfinding04_GalapagosColor
#include <hxDaedalus/examples/bitmapPathfinding04/GalapagosColor.h>
#endif
#ifndef INCLUDED_hxDaedalus_examples_bitmapPathfinding04_Main
#include <hxDaedalus/examples/bitmapPathfinding04/Main.h>
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
#ifndef INCLUDED_openfl__v2_display_BlendMode
#include <openfl/_v2/display/BlendMode.h>
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
#ifndef INCLUDED_openfl__v2_events_MouseEvent
#include <openfl/_v2/events/MouseEvent.h>
#endif
#ifndef INCLUDED_openfl__v2_geom_ColorTransform
#include <openfl/_v2/geom/ColorTransform.h>
#endif
#ifndef INCLUDED_openfl__v2_geom_Matrix
#include <openfl/_v2/geom/Matrix.h>
#endif
#ifndef INCLUDED_openfl__v2_geom_Rectangle
#include <openfl/_v2/geom/Rectangle.h>
#endif
#ifndef INCLUDED_openfl__v2_text_TextField
#include <openfl/_v2/text/TextField.h>
#endif
#ifndef INCLUDED_openfl_display_FPS
#include <openfl/display/FPS.h>
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
namespace bitmapPathfinding04{

Void Main_obj::__construct()
{
HX_STACK_FRAME("hxDaedalus.examples.bitmapPathfinding04.Main","new",0xfce1cdac,"hxDaedalus.examples.bitmapPathfinding04.Main.new","hxDaedalus/examples/bitmapPathfinding04/Main.hx",31,0x851c1183)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(46)
	this->_newPath = false;
	HX_STACK_LINE(192)
	super::__construct();
	HX_STACK_LINE(193)
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
		HX_STACK_FRAME("hxDaedalus.examples.bitmapPathfinding04.Main","resize",0x0f45b428,"hxDaedalus.examples.bitmapPathfinding04.Main.resize","hxDaedalus/examples/bitmapPathfinding04/Main.hx",50,0x851c1183)
		HX_STACK_THIS(this)
		HX_STACK_ARG(e,"e")
		HX_STACK_LINE(50)
		if ((!(this->inited))){
			HX_STACK_LINE(50)
			this->init();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,resize,(void))

Void Main_obj::init( ){
{
		HX_STACK_FRAME("hxDaedalus.examples.bitmapPathfinding04.Main","init",0x456ae044,"hxDaedalus.examples.bitmapPathfinding04.Main.init","hxDaedalus/examples/bitmapPathfinding04/Main.hx",55,0x851c1183)
		HX_STACK_THIS(this)
		HX_STACK_LINE(56)
		if ((this->inited)){
			HX_STACK_LINE(56)
			return null();
		}
		HX_STACK_LINE(57)
		this->inited = true;
		HX_STACK_LINE(61)
		::hxDaedalus::data::Mesh _g = ::hxDaedalus::factories::RectMesh_obj::buildRectangle((int)1024,(int)780);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(61)
		this->_mesh = _g;
		HX_STACK_LINE(67)
		::hxDaedalus::examples::bitmapPathfinding04::GalapagosBW _g1 = ::hxDaedalus::examples::bitmapPathfinding04::GalapagosBW_obj::__new((int)0,(int)0,null(),null());		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(67)
		::openfl::_v2::display::Bitmap _g2 = ::openfl::_v2::display::Bitmap_obj::__new(_g1,null(),null());		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(67)
		this->_bmp = _g2;
		HX_STACK_LINE(69)
		this->_bmp->set_x((int)0);
		HX_STACK_LINE(70)
		this->_bmp->set_y((int)0);
		HX_STACK_LINE(76)
		::hxDaedalus::examples::bitmapPathfinding04::GalapagosColor _g3 = ::hxDaedalus::examples::bitmapPathfinding04::GalapagosColor_obj::__new((int)0,(int)0,null(),null());		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(76)
		::openfl::_v2::display::Bitmap _g4 = ::openfl::_v2::display::Bitmap_obj::__new(_g3,null(),null());		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(76)
		this->_overlay = _g4;
		HX_STACK_LINE(78)
		this->_overlay->set_x((int)0);
		HX_STACK_LINE(79)
		this->_overlay->set_y((int)0);
		HX_STACK_LINE(80)
		this->addChild(this->_overlay);
		HX_STACK_LINE(82)
		::openfl::_v2::display::Sprite viewSprite = ::openfl::_v2::display::Sprite_obj::__new();		HX_STACK_VAR(viewSprite,"viewSprite");
		HX_STACK_LINE(83)
		::openfl::_v2::display::Graphics _g5 = viewSprite->get_graphics();		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(83)
		::hxDaedalus::view::SimpleView _g6 = ::hxDaedalus::view::SimpleView_obj::__new(_g5);		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(83)
		this->_view = _g6;
		HX_STACK_LINE(84)
		this->addChild(viewSprite);
		HX_STACK_LINE(87)
		::hxDaedalus::graphics::_Pixels::PixelsData _g7 = ::hxDaedalus::graphics::_Pixels::Pixels_Impl__obj::fromBitmapData(this->_bmp->bitmapData);		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(87)
		::hxDaedalus::data::Object _g8 = ::hxDaedalus::factories::BitmapObject_obj::buildFromBmpData(_g7,1.8,null(),null());		HX_STACK_VAR(_g8,"_g8");
		HX_STACK_LINE(87)
		this->_object = _g8;
		HX_STACK_LINE(88)
		this->_object->set_x((int)0);
		HX_STACK_LINE(89)
		this->_object->set_y((int)0);
		HX_STACK_LINE(90)
		Float s = ::haxe::Timer_obj::stamp();		HX_STACK_VAR(s,"s");
		HX_STACK_LINE(91)
		this->_mesh->insertObject(this->_object);
		HX_STACK_LINE(97)
		this->_view->drawMesh(this->_mesh,null());
		HX_STACK_LINE(100)
		this->_overlay->bitmapData->draw(viewSprite,null(),null(),null(),null(),null());
		HX_STACK_LINE(103)
		::hxDaedalus::ai::EntityAI _g9 = ::hxDaedalus::ai::EntityAI_obj::__new();		HX_STACK_VAR(_g9,"_g9");
		HX_STACK_LINE(103)
		this->_entityAI = _g9;
		HX_STACK_LINE(106)
		this->_entityAI->set_radius((int)4);
		HX_STACK_LINE(109)
		this->_entityAI->x = (int)50;
		HX_STACK_LINE(110)
		this->_entityAI->y = (int)50;
		HX_STACK_LINE(113)
		this->_view->drawEntity(this->_entityAI,false);
		HX_STACK_LINE(116)
		::hxDaedalus::ai::PathFinder _g10 = ::hxDaedalus::ai::PathFinder_obj::__new();		HX_STACK_VAR(_g10,"_g10");
		HX_STACK_LINE(116)
		this->_pathfinder = _g10;
		HX_STACK_LINE(117)
		this->_pathfinder->entity = this->_entityAI;
		HX_STACK_LINE(118)
		this->_pathfinder->set_mesh(this->_mesh);
		HX_STACK_LINE(121)
		Array< Float > _g11 = Array_obj< Float >::__new();		HX_STACK_VAR(_g11,"_g11");
		HX_STACK_LINE(121)
		this->_path = _g11;
		HX_STACK_LINE(124)
		::hxDaedalus::ai::trajectory::LinearPathSampler _g12 = ::hxDaedalus::ai::trajectory::LinearPathSampler_obj::__new();		HX_STACK_VAR(_g12,"_g12");
		HX_STACK_LINE(124)
		this->_pathSampler = _g12;
		HX_STACK_LINE(125)
		this->_pathSampler->entity = this->_entityAI;
		HX_STACK_LINE(126)
		this->_pathSampler->set_samplingDistance((int)10);
		HX_STACK_LINE(127)
		this->_pathSampler->set_path(this->_path);
		HX_STACK_LINE(130)
		::openfl::_v2::Lib_obj::get_current()->get_stage()->addEventListener(::openfl::_v2::events::MouseEvent_obj::MOUSE_DOWN,this->_onMouseDown_dyn(),null(),null(),null());
		HX_STACK_LINE(131)
		::openfl::_v2::Lib_obj::get_current()->get_stage()->addEventListener(::openfl::_v2::events::MouseEvent_obj::MOUSE_UP,this->_onMouseUp_dyn(),null(),null(),null());
		HX_STACK_LINE(134)
		::openfl::_v2::Lib_obj::get_current()->get_stage()->addEventListener(::openfl::_v2::events::Event_obj::ENTER_FRAME,this->_onEnterFrame_dyn(),null(),null(),null());
		HX_STACK_LINE(137)
		::openfl::_v2::Lib_obj::get_current()->get_stage()->addEventListener(::openfl::_v2::events::KeyboardEvent_obj::KEY_DOWN,this->_onKeyDown_dyn(),null(),null(),null());
		HX_STACK_LINE(140)
		::openfl::display::FPS fps = ::openfl::display::FPS_obj::__new(null(),null(),null());		HX_STACK_VAR(fps,"fps");
		HX_STACK_LINE(141)
		::openfl::_v2::Lib_obj::get_current()->get_stage()->addChild(fps);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Main_obj,init,(void))

Void Main_obj::_onMouseUp( ::openfl::_v2::events::MouseEvent event){
{
		HX_STACK_FRAME("hxDaedalus.examples.bitmapPathfinding04.Main","_onMouseUp",0x2895ac76,"hxDaedalus.examples.bitmapPathfinding04.Main._onMouseUp","hxDaedalus/examples/bitmapPathfinding04/Main.hx",146,0x851c1183)
		HX_STACK_THIS(this)
		HX_STACK_ARG(event,"event")
		HX_STACK_LINE(146)
		this->_newPath = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,_onMouseUp,(void))

Void Main_obj::_onMouseDown( ::openfl::_v2::events::MouseEvent event){
{
		HX_STACK_FRAME("hxDaedalus.examples.bitmapPathfinding04.Main","_onMouseDown",0xaf753b3d,"hxDaedalus.examples.bitmapPathfinding04.Main._onMouseDown","hxDaedalus/examples/bitmapPathfinding04/Main.hx",150,0x851c1183)
		HX_STACK_THIS(this)
		HX_STACK_ARG(event,"event")
		HX_STACK_LINE(150)
		this->_newPath = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,_onMouseDown,(void))

Void Main_obj::_onEnterFrame( ::openfl::_v2::events::Event event){
{
		HX_STACK_FRAME("hxDaedalus.examples.bitmapPathfinding04.Main","_onEnterFrame",0xddd64d1f,"hxDaedalus.examples.bitmapPathfinding04.Main._onEnterFrame","hxDaedalus/examples/bitmapPathfinding04/Main.hx",153,0x851c1183)
		HX_STACK_THIS(this)
		HX_STACK_ARG(event,"event")
		HX_STACK_LINE(154)
		if ((this->_newPath)){
			HX_STACK_LINE(154)
			this->_view->graphics->graphics->clear();
		}
		HX_STACK_LINE(156)
		if ((this->_newPath)){
			HX_STACK_LINE(158)
			Float _g = this->get_stage()->get_mouseX();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(158)
			Float _g1 = this->get_stage()->get_mouseY();		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(158)
			this->_pathfinder->findPath(_g,_g1,this->_path);
			HX_STACK_LINE(161)
			this->_view->drawPath(this->_path,null());
			HX_STACK_LINE(164)
			this->_pathSampler->reset();
		}
		HX_STACK_LINE(168)
		if ((this->_pathSampler->get_hasNext())){
			HX_STACK_LINE(170)
			this->_pathSampler->next();
		}
		HX_STACK_LINE(174)
		this->_view->drawEntity(this->_entityAI,null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,_onEnterFrame,(void))

Void Main_obj::_onKeyDown( ::openfl::_v2::events::KeyboardEvent event){
{
		HX_STACK_FRAME("hxDaedalus.examples.bitmapPathfinding04.Main","_onKeyDown",0x046a2237,"hxDaedalus.examples.bitmapPathfinding04.Main._onKeyDown","hxDaedalus/examples/bitmapPathfinding04/Main.hx",179,0x851c1183)
		HX_STACK_THIS(this)
		HX_STACK_ARG(event,"event")
		HX_STACK_LINE(179)
		if (((event->keyCode == (int)27))){
			HX_STACK_LINE(183)
			::Sys_obj::exit((int)1);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,_onKeyDown,(void))

Void Main_obj::added( Dynamic e){
{
		HX_STACK_FRAME("hxDaedalus.examples.bitmapPathfinding04.Main","added",0xd644bd0c,"hxDaedalus.examples.bitmapPathfinding04.Main.added","hxDaedalus/examples/bitmapPathfinding04/Main.hx",197,0x851c1183)
		HX_STACK_THIS(this)
		HX_STACK_ARG(e,"e")
		HX_STACK_LINE(198)
		this->removeEventListener(::openfl::_v2::events::Event_obj::ADDED_TO_STAGE,this->added_dyn(),null());
		HX_STACK_LINE(199)
		this->get_stage()->addEventListener(::openfl::_v2::events::Event_obj::RESIZE,this->resize_dyn(),null(),null(),null());
		HX_STACK_LINE(203)
		this->init();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,added,(void))

Void Main_obj::main( ){
{
		HX_STACK_FRAME("hxDaedalus.examples.bitmapPathfinding04.Main","main",0x4805dd6d,"hxDaedalus.examples.bitmapPathfinding04.Main.main","hxDaedalus/examples/bitmapPathfinding04/Main.hx",208,0x851c1183)
		HX_STACK_LINE(210)
		::openfl::_v2::Lib_obj::get_current()->get_stage()->set_align(::openfl::display::StageAlign_obj::TOP_LEFT);
		HX_STACK_LINE(211)
		::openfl::_v2::Lib_obj::get_current()->get_stage()->set_scaleMode(::openfl::display::StageScaleMode_obj::NO_SCALE);
		HX_STACK_LINE(212)
		::hxDaedalus::examples::bitmapPathfinding04::Main _g = ::hxDaedalus::examples::bitmapPathfinding04::Main_obj::__new();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(212)
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
	HX_MARK_MEMBER_NAME(_entityAI,"_entityAI");
	HX_MARK_MEMBER_NAME(_pathfinder,"_pathfinder");
	HX_MARK_MEMBER_NAME(_path,"_path");
	HX_MARK_MEMBER_NAME(_pathSampler,"_pathSampler");
	HX_MARK_MEMBER_NAME(_object,"_object");
	HX_MARK_MEMBER_NAME(_bmp,"_bmp");
	HX_MARK_MEMBER_NAME(_overlay,"_overlay");
	HX_MARK_MEMBER_NAME(_newPath,"_newPath");
	::openfl::_v2::display::DisplayObjectContainer_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Main_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(inited,"inited");
	HX_VISIT_MEMBER_NAME(_mesh,"_mesh");
	HX_VISIT_MEMBER_NAME(_view,"_view");
	HX_VISIT_MEMBER_NAME(_entityAI,"_entityAI");
	HX_VISIT_MEMBER_NAME(_pathfinder,"_pathfinder");
	HX_VISIT_MEMBER_NAME(_path,"_path");
	HX_VISIT_MEMBER_NAME(_pathSampler,"_pathSampler");
	HX_VISIT_MEMBER_NAME(_object,"_object");
	HX_VISIT_MEMBER_NAME(_bmp,"_bmp");
	HX_VISIT_MEMBER_NAME(_overlay,"_overlay");
	HX_VISIT_MEMBER_NAME(_newPath,"_newPath");
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
		if (HX_FIELD_EQ(inName,"_path") ) { return _path; }
		if (HX_FIELD_EQ(inName,"added") ) { return added_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"inited") ) { return inited; }
		if (HX_FIELD_EQ(inName,"resize") ) { return resize_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_object") ) { return _object; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_overlay") ) { return _overlay; }
		if (HX_FIELD_EQ(inName,"_newPath") ) { return _newPath; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_entityAI") ) { return _entityAI; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_onMouseUp") ) { return _onMouseUp_dyn(); }
		if (HX_FIELD_EQ(inName,"_onKeyDown") ) { return _onKeyDown_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_pathfinder") ) { return _pathfinder; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_pathSampler") ) { return _pathSampler; }
		if (HX_FIELD_EQ(inName,"_onMouseDown") ) { return _onMouseDown_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_onEnterFrame") ) { return _onEnterFrame_dyn(); }
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
		if (HX_FIELD_EQ(inName,"_path") ) { _path=inValue.Cast< Array< Float > >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"inited") ) { inited=inValue.Cast< bool >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_object") ) { _object=inValue.Cast< ::hxDaedalus::data::Object >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_overlay") ) { _overlay=inValue.Cast< ::openfl::_v2::display::Bitmap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_newPath") ) { _newPath=inValue.Cast< bool >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_entityAI") ) { _entityAI=inValue.Cast< ::hxDaedalus::ai::EntityAI >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_pathfinder") ) { _pathfinder=inValue.Cast< ::hxDaedalus::ai::PathFinder >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_pathSampler") ) { _pathSampler=inValue.Cast< ::hxDaedalus::ai::trajectory::LinearPathSampler >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Main_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("inited"));
	outFields->push(HX_CSTRING("_mesh"));
	outFields->push(HX_CSTRING("_view"));
	outFields->push(HX_CSTRING("_entityAI"));
	outFields->push(HX_CSTRING("_pathfinder"));
	outFields->push(HX_CSTRING("_path"));
	outFields->push(HX_CSTRING("_pathSampler"));
	outFields->push(HX_CSTRING("_object"));
	outFields->push(HX_CSTRING("_bmp"));
	outFields->push(HX_CSTRING("_overlay"));
	outFields->push(HX_CSTRING("_newPath"));
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
	{hx::fsObject /*::hxDaedalus::ai::EntityAI*/ ,(int)offsetof(Main_obj,_entityAI),HX_CSTRING("_entityAI")},
	{hx::fsObject /*::hxDaedalus::ai::PathFinder*/ ,(int)offsetof(Main_obj,_pathfinder),HX_CSTRING("_pathfinder")},
	{hx::fsObject /*Array< Float >*/ ,(int)offsetof(Main_obj,_path),HX_CSTRING("_path")},
	{hx::fsObject /*::hxDaedalus::ai::trajectory::LinearPathSampler*/ ,(int)offsetof(Main_obj,_pathSampler),HX_CSTRING("_pathSampler")},
	{hx::fsObject /*::hxDaedalus::data::Object*/ ,(int)offsetof(Main_obj,_object),HX_CSTRING("_object")},
	{hx::fsObject /*::openfl::_v2::display::Bitmap*/ ,(int)offsetof(Main_obj,_bmp),HX_CSTRING("_bmp")},
	{hx::fsObject /*::openfl::_v2::display::Bitmap*/ ,(int)offsetof(Main_obj,_overlay),HX_CSTRING("_overlay")},
	{hx::fsBool,(int)offsetof(Main_obj,_newPath),HX_CSTRING("_newPath")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("inited"),
	HX_CSTRING("_mesh"),
	HX_CSTRING("_view"),
	HX_CSTRING("_entityAI"),
	HX_CSTRING("_pathfinder"),
	HX_CSTRING("_path"),
	HX_CSTRING("_pathSampler"),
	HX_CSTRING("_object"),
	HX_CSTRING("_bmp"),
	HX_CSTRING("_overlay"),
	HX_CSTRING("_newPath"),
	HX_CSTRING("resize"),
	HX_CSTRING("init"),
	HX_CSTRING("_onMouseUp"),
	HX_CSTRING("_onMouseDown"),
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
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDaedalus.examples.bitmapPathfinding04.Main"), hx::TCanCast< Main_obj> ,sStaticFields,sMemberFields,
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
} // end namespace bitmapPathfinding04
