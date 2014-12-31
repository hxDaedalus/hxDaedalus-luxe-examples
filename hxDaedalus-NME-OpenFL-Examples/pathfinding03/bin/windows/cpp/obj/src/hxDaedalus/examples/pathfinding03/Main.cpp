#include <hxcpp.h>

#ifndef INCLUDED_Sys
#include <Sys.h>
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
#ifndef INCLUDED_hxDaedalus_data_math_RandGenerator
#include <hxDaedalus/data/math/RandGenerator.h>
#endif
#ifndef INCLUDED_hxDaedalus_examples_pathfinding03_Main
#include <hxDaedalus/examples/pathfinding03/Main.h>
#endif
#ifndef INCLUDED_hxDaedalus_factories_RectMesh
#include <hxDaedalus/factories/RectMesh.h>
#endif
#ifndef INCLUDED_hxDaedalus_graphics_ISimpleDrawingContext
#include <hxDaedalus/graphics/ISimpleDrawingContext.h>
#endif
#ifndef INCLUDED_hxDaedalus_graphics_flash_SimpleDrawingContext
#include <hxDaedalus/graphics/flash/SimpleDrawingContext.h>
#endif
#ifndef INCLUDED_hxDaedalus_view_SimpleView
#include <hxDaedalus/view/SimpleView.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
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
#ifndef INCLUDED_openfl__v2_events_MouseEvent
#include <openfl/_v2/events/MouseEvent.h>
#endif
#ifndef INCLUDED_openfl__v2_text_TextField
#include <openfl/_v2/text/TextField.h>
#endif
#ifndef INCLUDED_openfl_display_FPS
#include <openfl/display/FPS.h>
#endif
#ifndef INCLUDED_openfl_display_StageAlign
#include <openfl/display/StageAlign.h>
#endif
#ifndef INCLUDED_openfl_display_StageScaleMode
#include <openfl/display/StageScaleMode.h>
#endif
namespace hxDaedalus{
namespace examples{
namespace pathfinding03{

Void Main_obj::__construct()
{
HX_STACK_FRAME("hxDaedalus.examples.pathfinding03.Main","new",0x71db1d7e,"hxDaedalus.examples.pathfinding03.Main.new","hxDaedalus/examples/pathfinding03/Main.hx",24,0x8f4d49f1)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(37)
	this->_newPath = false;
	HX_STACK_LINE(179)
	super::__construct();
	HX_STACK_LINE(180)
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
		HX_STACK_FRAME("hxDaedalus.examples.pathfinding03.Main","resize",0xfe969396,"hxDaedalus.examples.pathfinding03.Main.resize","hxDaedalus/examples/pathfinding03/Main.hx",41,0x8f4d49f1)
		HX_STACK_THIS(this)
		HX_STACK_ARG(e,"e")
		HX_STACK_LINE(41)
		if ((!(this->inited))){
			HX_STACK_LINE(41)
			this->init();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,resize,(void))

Void Main_obj::init( ){
{
		HX_STACK_FRAME("hxDaedalus.examples.pathfinding03.Main","init",0x2a976832,"hxDaedalus.examples.pathfinding03.Main.init","hxDaedalus/examples/pathfinding03/Main.hx",46,0x8f4d49f1)
		HX_STACK_THIS(this)
		HX_STACK_LINE(47)
		if ((this->inited)){
			HX_STACK_LINE(47)
			return null();
		}
		HX_STACK_LINE(48)
		this->inited = true;
		HX_STACK_LINE(51)
		::hxDaedalus::data::Mesh _g = ::hxDaedalus::factories::RectMesh_obj::buildRectangle((int)600,(int)600);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(51)
		this->_mesh = _g;
		HX_STACK_LINE(54)
		::openfl::_v2::display::Sprite viewSprite = ::openfl::_v2::display::Sprite_obj::__new();		HX_STACK_VAR(viewSprite,"viewSprite");
		HX_STACK_LINE(55)
		::openfl::_v2::display::Graphics _g1 = viewSprite->get_graphics();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(55)
		::hxDaedalus::view::SimpleView _g2 = ::hxDaedalus::view::SimpleView_obj::__new(_g1);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(55)
		this->_view = _g2;
		HX_STACK_LINE(56)
		this->addChild(viewSprite);
		HX_STACK_LINE(58)
		::openfl::_v2::display::Graphics _g3 = this->get_graphics();		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(58)
		::hxDaedalus::view::SimpleView meshView = ::hxDaedalus::view::SimpleView_obj::__new(_g3);		HX_STACK_VAR(meshView,"meshView");
		HX_STACK_LINE(61)
		::hxDaedalus::data::math::RandGenerator randGen;		HX_STACK_VAR(randGen,"randGen");
		HX_STACK_LINE(62)
		::hxDaedalus::data::math::RandGenerator _g4 = ::hxDaedalus::data::math::RandGenerator_obj::__new(null(),null(),null());		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(62)
		randGen = _g4;
		HX_STACK_LINE(63)
		randGen->set_seed((int)7259);
		HX_STACK_LINE(66)
		::hxDaedalus::data::Object object;		HX_STACK_VAR(object,"object");
		HX_STACK_LINE(67)
		Array< Float > shapeCoords;		HX_STACK_VAR(shapeCoords,"shapeCoords");
		HX_STACK_LINE(68)
		{
			HX_STACK_LINE(68)
			int _g5 = (int)0;		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(68)
			while((true)){
				HX_STACK_LINE(68)
				if ((!(((_g5 < (int)50))))){
					HX_STACK_LINE(68)
					break;
				}
				HX_STACK_LINE(68)
				int i = (_g5)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(69)
				::hxDaedalus::data::Object _g51 = ::hxDaedalus::data::Object_obj::__new();		HX_STACK_VAR(_g51,"_g51");
				HX_STACK_LINE(69)
				object = _g51;
				HX_STACK_LINE(70)
				Array< Float > _g6 = Array_obj< Float >::__new();		HX_STACK_VAR(_g6,"_g6");
				HX_STACK_LINE(70)
				shapeCoords = _g6;
				HX_STACK_LINE(71)
				shapeCoords = Array_obj< Float >::__new().Add((int)-1).Add((int)-1).Add((int)1).Add((int)-1).Add((int)1).Add((int)-1).Add((int)1).Add((int)1).Add((int)1).Add((int)1).Add((int)-1).Add((int)1).Add((int)-1).Add((int)1).Add((int)-1).Add((int)-1);
				HX_STACK_LINE(75)
				object->set_coordinates(shapeCoords);
				HX_STACK_LINE(76)
				randGen->rangeMin = (int)10;
				HX_STACK_LINE(77)
				randGen->rangeMax = (int)40;
				HX_STACK_LINE(78)
				int _g7 = randGen->next();		HX_STACK_VAR(_g7,"_g7");
				HX_STACK_LINE(78)
				object->set_scaleX(_g7);
				HX_STACK_LINE(79)
				int _g8 = randGen->next();		HX_STACK_VAR(_g8,"_g8");
				HX_STACK_LINE(79)
				object->set_scaleY(_g8);
				HX_STACK_LINE(80)
				randGen->rangeMin = (int)0;
				HX_STACK_LINE(81)
				randGen->rangeMax = (int)1000;
				HX_STACK_LINE(82)
				int _g9 = randGen->next();		HX_STACK_VAR(_g9,"_g9");
				HX_STACK_LINE(82)
				Float _g10 = (Float(_g9) / Float((int)1000));		HX_STACK_VAR(_g10,"_g10");
				HX_STACK_LINE(82)
				Float _g11 = (_g10 * ::Math_obj::PI);		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(82)
				Float _g12 = (Float(_g11) / Float((int)2));		HX_STACK_VAR(_g12,"_g12");
				HX_STACK_LINE(82)
				object->set_rotation(_g12);
				HX_STACK_LINE(83)
				randGen->rangeMin = (int)50;
				HX_STACK_LINE(84)
				randGen->rangeMax = (int)600;
				HX_STACK_LINE(85)
				int _g13 = randGen->next();		HX_STACK_VAR(_g13,"_g13");
				HX_STACK_LINE(85)
				object->set_x(_g13);
				HX_STACK_LINE(86)
				int _g14 = randGen->next();		HX_STACK_VAR(_g14,"_g14");
				HX_STACK_LINE(86)
				object->set_y(_g14);
				HX_STACK_LINE(87)
				this->_mesh->insertObject(object);
			}
		}
		HX_STACK_LINE(90)
		meshView->drawMesh(this->_mesh,null());
		HX_STACK_LINE(93)
		::hxDaedalus::ai::EntityAI _g15 = ::hxDaedalus::ai::EntityAI_obj::__new();		HX_STACK_VAR(_g15,"_g15");
		HX_STACK_LINE(93)
		this->_entityAI = _g15;
		HX_STACK_LINE(95)
		this->_entityAI->set_radius((int)4);
		HX_STACK_LINE(97)
		this->_entityAI->x = (int)20;
		HX_STACK_LINE(98)
		this->_entityAI->y = (int)20;
		HX_STACK_LINE(101)
		this->_view->drawEntity(this->_entityAI,null());
		HX_STACK_LINE(104)
		::hxDaedalus::ai::PathFinder _g16 = ::hxDaedalus::ai::PathFinder_obj::__new();		HX_STACK_VAR(_g16,"_g16");
		HX_STACK_LINE(104)
		this->_pathfinder = _g16;
		HX_STACK_LINE(105)
		this->_pathfinder->entity = this->_entityAI;
		HX_STACK_LINE(106)
		this->_pathfinder->set_mesh(this->_mesh);
		HX_STACK_LINE(109)
		Array< Float > _g17 = Array_obj< Float >::__new();		HX_STACK_VAR(_g17,"_g17");
		HX_STACK_LINE(109)
		this->_path = _g17;
		HX_STACK_LINE(112)
		::hxDaedalus::ai::trajectory::LinearPathSampler _g18 = ::hxDaedalus::ai::trajectory::LinearPathSampler_obj::__new();		HX_STACK_VAR(_g18,"_g18");
		HX_STACK_LINE(112)
		this->_pathSampler = _g18;
		HX_STACK_LINE(113)
		this->_pathSampler->entity = this->_entityAI;
		HX_STACK_LINE(114)
		this->_pathSampler->set_samplingDistance((int)10);
		HX_STACK_LINE(115)
		this->_pathSampler->set_path(this->_path);
		HX_STACK_LINE(118)
		::openfl::_v2::Lib_obj::get_current()->get_stage()->addEventListener(::openfl::_v2::events::MouseEvent_obj::MOUSE_DOWN,this->_onMouseDown_dyn(),null(),null(),null());
		HX_STACK_LINE(119)
		::openfl::_v2::Lib_obj::get_current()->get_stage()->addEventListener(::openfl::_v2::events::MouseEvent_obj::MOUSE_UP,this->_onMouseUp_dyn(),null(),null(),null());
		HX_STACK_LINE(122)
		::openfl::_v2::Lib_obj::get_current()->get_stage()->addEventListener(::openfl::_v2::events::Event_obj::ENTER_FRAME,this->_onEnterFrame_dyn(),null(),null(),null());
		HX_STACK_LINE(125)
		::openfl::_v2::Lib_obj::get_current()->get_stage()->addEventListener(::openfl::_v2::events::KeyboardEvent_obj::KEY_DOWN,this->_onKeyDown_dyn(),null(),null(),null());
		HX_STACK_LINE(128)
		::openfl::display::FPS fps = ::openfl::display::FPS_obj::__new(null(),null(),null());		HX_STACK_VAR(fps,"fps");
		HX_STACK_LINE(129)
		::openfl::_v2::Lib_obj::get_current()->get_stage()->addChild(fps);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Main_obj,init,(void))

Void Main_obj::_onMouseUp( ::openfl::_v2::events::MouseEvent event){
{
		HX_STACK_FRAME("hxDaedalus.examples.pathfinding03.Main","_onMouseUp",0xb155dae4,"hxDaedalus.examples.pathfinding03.Main._onMouseUp","hxDaedalus/examples/pathfinding03/Main.hx",134,0x8f4d49f1)
		HX_STACK_THIS(this)
		HX_STACK_ARG(event,"event")
		HX_STACK_LINE(134)
		this->_newPath = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,_onMouseUp,(void))

Void Main_obj::_onMouseDown( ::openfl::_v2::events::MouseEvent event){
{
		HX_STACK_FRAME("hxDaedalus.examples.pathfinding03.Main","_onMouseDown",0x0b70612b,"hxDaedalus.examples.pathfinding03.Main._onMouseDown","hxDaedalus/examples/pathfinding03/Main.hx",138,0x8f4d49f1)
		HX_STACK_THIS(this)
		HX_STACK_ARG(event,"event")
		HX_STACK_LINE(138)
		this->_newPath = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,_onMouseDown,(void))

Void Main_obj::_onEnterFrame( ::openfl::_v2::events::Event event){
{
		HX_STACK_FRAME("hxDaedalus.examples.pathfinding03.Main","_onEnterFrame",0xfd9c5771,"hxDaedalus.examples.pathfinding03.Main._onEnterFrame","hxDaedalus/examples/pathfinding03/Main.hx",141,0x8f4d49f1)
		HX_STACK_THIS(this)
		HX_STACK_ARG(event,"event")
		HX_STACK_LINE(142)
		if ((this->_newPath)){
			HX_STACK_LINE(142)
			this->_view->graphics->graphics->clear();
		}
		HX_STACK_LINE(144)
		if ((this->_newPath)){
			HX_STACK_LINE(146)
			Float _g = this->get_stage()->get_mouseX();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(146)
			Float _g1 = this->get_stage()->get_mouseY();		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(146)
			this->_pathfinder->findPath(_g,_g1,this->_path);
			HX_STACK_LINE(149)
			this->_view->drawPath(this->_path,null());
			HX_STACK_LINE(152)
			this->_pathSampler->reset();
		}
		HX_STACK_LINE(156)
		if ((this->_pathSampler->get_hasNext())){
			HX_STACK_LINE(158)
			this->_pathSampler->next();
		}
		HX_STACK_LINE(162)
		this->_view->drawEntity(this->_entityAI,null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,_onEnterFrame,(void))

Void Main_obj::_onKeyDown( ::openfl::_v2::events::KeyboardEvent event){
{
		HX_STACK_FRAME("hxDaedalus.examples.pathfinding03.Main","_onKeyDown",0x8d2a50a5,"hxDaedalus.examples.pathfinding03.Main._onKeyDown","hxDaedalus/examples/pathfinding03/Main.hx",166,0x8f4d49f1)
		HX_STACK_THIS(this)
		HX_STACK_ARG(event,"event")
		HX_STACK_LINE(166)
		if (((event->keyCode == (int)27))){
			HX_STACK_LINE(170)
			::Sys_obj::exit((int)1);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,_onKeyDown,(void))

Void Main_obj::added( Dynamic e){
{
		HX_STACK_FRAME("hxDaedalus.examples.pathfinding03.Main","added",0x780f255e,"hxDaedalus.examples.pathfinding03.Main.added","hxDaedalus/examples/pathfinding03/Main.hx",184,0x8f4d49f1)
		HX_STACK_THIS(this)
		HX_STACK_ARG(e,"e")
		HX_STACK_LINE(185)
		this->removeEventListener(::openfl::_v2::events::Event_obj::ADDED_TO_STAGE,this->added_dyn(),null());
		HX_STACK_LINE(186)
		this->get_stage()->addEventListener(::openfl::_v2::events::Event_obj::RESIZE,this->resize_dyn(),null(),null(),null());
		HX_STACK_LINE(190)
		this->init();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,added,(void))

Void Main_obj::main( ){
{
		HX_STACK_FRAME("hxDaedalus.examples.pathfinding03.Main","main",0x2d32655b,"hxDaedalus.examples.pathfinding03.Main.main","hxDaedalus/examples/pathfinding03/Main.hx",195,0x8f4d49f1)
		HX_STACK_LINE(197)
		::openfl::_v2::Lib_obj::get_current()->get_stage()->set_align(::openfl::display::StageAlign_obj::TOP_LEFT);
		HX_STACK_LINE(198)
		::openfl::_v2::Lib_obj::get_current()->get_stage()->set_scaleMode(::openfl::display::StageScaleMode_obj::NO_SCALE);
		HX_STACK_LINE(199)
		::hxDaedalus::examples::pathfinding03::Main _g = ::hxDaedalus::examples::pathfinding03::Main_obj::__new();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(199)
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
	HX_VISIT_MEMBER_NAME(_newPath,"_newPath");
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
		if (HX_FIELD_EQ(inName,"_path") ) { return _path; }
		if (HX_FIELD_EQ(inName,"added") ) { return added_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"inited") ) { return inited; }
		if (HX_FIELD_EQ(inName,"resize") ) { return resize_dyn(); }
		break;
	case 8:
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
	case 5:
		if (HX_FIELD_EQ(inName,"_mesh") ) { _mesh=inValue.Cast< ::hxDaedalus::data::Mesh >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_view") ) { _view=inValue.Cast< ::hxDaedalus::view::SimpleView >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_path") ) { _path=inValue.Cast< Array< Float > >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"inited") ) { inited=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
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
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDaedalus.examples.pathfinding03.Main"), hx::TCanCast< Main_obj> ,sStaticFields,sMemberFields,
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
} // end namespace pathfinding03
