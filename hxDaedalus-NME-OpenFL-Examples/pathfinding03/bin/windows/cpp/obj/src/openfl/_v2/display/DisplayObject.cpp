#include <hxcpp.h>

#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_openfl__v2_Lib
#include <openfl/_v2/Lib.h>
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
#ifndef INCLUDED_openfl__v2_display_LoaderInfo
#include <openfl/_v2/display/LoaderInfo.h>
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
#ifndef INCLUDED_openfl__v2_geom_ColorTransform
#include <openfl/_v2/geom/ColorTransform.h>
#endif
#ifndef INCLUDED_openfl__v2_geom_Matrix
#include <openfl/_v2/geom/Matrix.h>
#endif
#ifndef INCLUDED_openfl__v2_geom_Point
#include <openfl/_v2/geom/Point.h>
#endif
#ifndef INCLUDED_openfl__v2_geom_Rectangle
#include <openfl/_v2/geom/Rectangle.h>
#endif
#ifndef INCLUDED_openfl__v2_geom_Transform
#include <openfl/_v2/geom/Transform.h>
#endif
#ifndef INCLUDED_openfl__v2_net_URLLoader
#include <openfl/_v2/net/URLLoader.h>
#endif
#ifndef INCLUDED_openfl_display_PixelSnapping
#include <openfl/display/PixelSnapping.h>
#endif
#ifndef INCLUDED_openfl_events_EventPhase
#include <openfl/events/EventPhase.h>
#endif
namespace openfl{
namespace _v2{
namespace display{

Void DisplayObject_obj::__construct(Dynamic handle,::String type)
{
HX_STACK_FRAME("openfl._v2.display.DisplayObject","new",0xbc292e56,"openfl._v2.display.DisplayObject.new","openfl/_v2/display/DisplayObject.hx",58,0xfffdca5d)
HX_STACK_THIS(this)
HX_STACK_ARG(handle,"handle")
HX_STACK_ARG(type,"type")
{
	HX_STACK_LINE(60)
	super::__construct(hx::ObjectPtr<OBJ_>(this));
	HX_STACK_LINE(62)
	this->__parent = null();
	HX_STACK_LINE(63)
	this->__handle = handle;
	HX_STACK_LINE(64)
	int _g = ::openfl::_v2::display::DisplayObject_obj::lime_display_object_get_id(this->__handle);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(64)
	this->__id = _g;
	HX_STACK_LINE(65)
	this->set_name(((type + HX_CSTRING(" ")) + this->__id));
}
;
	return null();
}

//DisplayObject_obj::~DisplayObject_obj() { }

Dynamic DisplayObject_obj::__CreateEmpty() { return  new DisplayObject_obj; }
hx::ObjectPtr< DisplayObject_obj > DisplayObject_obj::__new(Dynamic handle,::String type)
{  hx::ObjectPtr< DisplayObject_obj > result = new DisplayObject_obj();
	result->__construct(handle,type);
	return result;}

Dynamic DisplayObject_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< DisplayObject_obj > result = new DisplayObject_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

hx::Object *DisplayObject_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::openfl::_v2::display::IBitmapDrawable_obj)) return operator ::openfl::_v2::display::IBitmapDrawable_obj *();
	return super::__ToInterface(inType);
}

bool DisplayObject_obj::dispatchEvent( ::openfl::_v2::events::Event event){
	HX_STACK_FRAME("openfl._v2.display.DisplayObject","dispatchEvent",0x212b7476,"openfl._v2.display.DisplayObject.dispatchEvent","openfl/_v2/display/DisplayObject.hx",70,0xfffdca5d)
	HX_STACK_THIS(this)
	HX_STACK_ARG(event,"event")
	HX_STACK_LINE(72)
	bool result = this->__dispatchEvent(event);		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(74)
	if ((event->__getIsCancelled())){
		HX_STACK_LINE(75)
		return true;
	}
	struct _Function_1_1{
		inline static bool Block( hx::ObjectPtr< ::openfl::_v2::display::DisplayObject_obj > __this){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","openfl/_v2/display/DisplayObject.hx",77,0xfffdca5d)
			{
				HX_STACK_LINE(77)
				::openfl::_v2::display::DisplayObjectContainer _g = __this->get_parent();		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(77)
				return (_g != null());
			}
			return null();
		}
	};
	HX_STACK_LINE(77)
	if (((  ((event->get_bubbles())) ? bool(_Function_1_1::Block(this)) : bool(false) ))){
		HX_STACK_LINE(79)
		this->get_parent()->dispatchEvent(event);
	}
	HX_STACK_LINE(83)
	return result;
}


::openfl::_v2::geom::Rectangle DisplayObject_obj::getBounds( ::openfl::_v2::display::DisplayObject targetCoordinateSpace){
	HX_STACK_FRAME("openfl._v2.display.DisplayObject","getBounds",0xedcd4a21,"openfl._v2.display.DisplayObject.getBounds","openfl/_v2/display/DisplayObject.hx",88,0xfffdca5d)
	HX_STACK_THIS(this)
	HX_STACK_ARG(targetCoordinateSpace,"targetCoordinateSpace")
	HX_STACK_LINE(90)
	::openfl::_v2::geom::Rectangle result = ::openfl::_v2::geom::Rectangle_obj::__new(null(),null(),null(),null());		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(91)
	::openfl::_v2::display::DisplayObject_obj::lime_display_object_get_bounds(this->__handle,targetCoordinateSpace->__handle,result,true);
	HX_STACK_LINE(92)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,getBounds,return )

::openfl::_v2::geom::Rectangle DisplayObject_obj::getRect( ::openfl::_v2::display::DisplayObject targetCoordinateSpace){
	HX_STACK_FRAME("openfl._v2.display.DisplayObject","getRect",0xd1048dd0,"openfl._v2.display.DisplayObject.getRect","openfl/_v2/display/DisplayObject.hx",97,0xfffdca5d)
	HX_STACK_THIS(this)
	HX_STACK_ARG(targetCoordinateSpace,"targetCoordinateSpace")
	HX_STACK_LINE(99)
	::openfl::_v2::geom::Rectangle result = ::openfl::_v2::geom::Rectangle_obj::__new(null(),null(),null(),null());		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(100)
	::openfl::_v2::display::DisplayObject_obj::lime_display_object_get_bounds(this->__handle,targetCoordinateSpace->__handle,result,false);
	HX_STACK_LINE(101)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,getRect,return )

::openfl::_v2::geom::Point DisplayObject_obj::globalToLocal( ::openfl::_v2::geom::Point point){
	HX_STACK_FRAME("openfl._v2.display.DisplayObject","globalToLocal",0xc674fc43,"openfl._v2.display.DisplayObject.globalToLocal","openfl/_v2/display/DisplayObject.hx",106,0xfffdca5d)
	HX_STACK_THIS(this)
	HX_STACK_ARG(point,"point")
	HX_STACK_LINE(108)
	::openfl::_v2::geom::Point result = point->clone();		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(109)
	::openfl::_v2::display::DisplayObject_obj::lime_display_object_global_to_local(this->__handle,result);
	HX_STACK_LINE(110)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,globalToLocal,return )

bool DisplayObject_obj::hitTestObject( ::openfl::_v2::display::DisplayObject obj){
	HX_STACK_FRAME("openfl._v2.display.DisplayObject","hitTestObject",0x322b025a,"openfl._v2.display.DisplayObject.hitTestObject","openfl/_v2/display/DisplayObject.hx",115,0xfffdca5d)
	HX_STACK_THIS(this)
	HX_STACK_ARG(obj,"obj")
	struct _Function_1_1{
		inline static bool Block( ::openfl::_v2::display::DisplayObject &obj){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","openfl/_v2/display/DisplayObject.hx",117,0xfffdca5d)
			{
				HX_STACK_LINE(117)
				::openfl::_v2::display::DisplayObjectContainer _g = obj->get_parent();		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(117)
				return (_g != null());
			}
			return null();
		}
	};
	struct _Function_1_2{
		inline static bool Block( hx::ObjectPtr< ::openfl::_v2::display::DisplayObject_obj > __this){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","openfl/_v2/display/DisplayObject.hx",117,0xfffdca5d)
			{
				HX_STACK_LINE(117)
				::openfl::_v2::display::DisplayObjectContainer _g1 = __this->get_parent();		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(117)
				return (_g1 != null());
			}
			return null();
		}
	};
	HX_STACK_LINE(117)
	if (((  (((  (((obj != null()))) ? bool(_Function_1_1::Block(obj)) : bool(false) ))) ? bool(_Function_1_2::Block(this)) : bool(false) ))){
		HX_STACK_LINE(119)
		::openfl::_v2::geom::Rectangle currentBounds = this->getBounds(hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(currentBounds,"currentBounds");
		HX_STACK_LINE(120)
		::openfl::_v2::geom::Rectangle targetBounds = obj->getBounds(hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(targetBounds,"targetBounds");
		HX_STACK_LINE(122)
		return currentBounds->intersects(targetBounds);
	}
	HX_STACK_LINE(126)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,hitTestObject,return )

bool DisplayObject_obj::hitTestPoint( Float x,Float y,hx::Null< bool >  __o_shapeFlag){
bool shapeFlag = __o_shapeFlag.Default(false);
	HX_STACK_FRAME("openfl._v2.display.DisplayObject","hitTestPoint",0x5ac7dd15,"openfl._v2.display.DisplayObject.hitTestPoint","openfl/_v2/display/DisplayObject.hx",133,0xfffdca5d)
	HX_STACK_THIS(this)
	HX_STACK_ARG(x,"x")
	HX_STACK_ARG(y,"y")
	HX_STACK_ARG(shapeFlag,"shapeFlag")
{
		HX_STACK_LINE(133)
		return ::openfl::_v2::display::DisplayObject_obj::lime_display_object_hit_test_point(this->__handle,x,y,shapeFlag,true);
	}
}


HX_DEFINE_DYNAMIC_FUNC3(DisplayObject_obj,hitTestPoint,return )

::openfl::_v2::geom::Point DisplayObject_obj::localToGlobal( ::openfl::_v2::geom::Point point){
	HX_STACK_FRAME("openfl._v2.display.DisplayObject","localToGlobal",0xa2b1ef3f,"openfl._v2.display.DisplayObject.localToGlobal","openfl/_v2/display/DisplayObject.hx",138,0xfffdca5d)
	HX_STACK_THIS(this)
	HX_STACK_ARG(point,"point")
	HX_STACK_LINE(140)
	::openfl::_v2::geom::Point result = point->clone();		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(141)
	::openfl::_v2::display::DisplayObject_obj::lime_display_object_local_to_global(this->__handle,result);
	HX_STACK_LINE(142)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,localToGlobal,return )

::String DisplayObject_obj::toString( ){
	HX_STACK_FRAME("openfl._v2.display.DisplayObject","toString",0x04d316f6,"openfl._v2.display.DisplayObject.toString","openfl/_v2/display/DisplayObject.hx",149,0xfffdca5d)
	HX_STACK_THIS(this)
	HX_STACK_LINE(149)
	return this->get_name();
}


::openfl::_v2::display::InteractiveObject DisplayObject_obj::__asInteractiveObject( ){
	HX_STACK_FRAME("openfl._v2.display.DisplayObject","__asInteractiveObject",0x4e80b545,"openfl._v2.display.DisplayObject.__asInteractiveObject","openfl/_v2/display/DisplayObject.hx",156,0xfffdca5d)
	HX_STACK_THIS(this)
	HX_STACK_LINE(156)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,__asInteractiveObject,return )

Void DisplayObject_obj::__broadcast( ::openfl::_v2::events::Event event){
{
		HX_STACK_FRAME("openfl._v2.display.DisplayObject","__broadcast",0x8d3b2fd7,"openfl._v2.display.DisplayObject.__broadcast","openfl/_v2/display/DisplayObject.hx",163,0xfffdca5d)
		HX_STACK_THIS(this)
		HX_STACK_ARG(event,"event")
		HX_STACK_LINE(163)
		this->__dispatchEvent(event);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,__broadcast,(void))

bool DisplayObject_obj::__contains( ::openfl::_v2::display::DisplayObject child){
	HX_STACK_FRAME("openfl._v2.display.DisplayObject","__contains",0xb26dba09,"openfl._v2.display.DisplayObject.__contains","openfl/_v2/display/DisplayObject.hx",170,0xfffdca5d)
	HX_STACK_THIS(this)
	HX_STACK_ARG(child,"child")
	HX_STACK_LINE(170)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,__contains,return )

bool DisplayObject_obj::__dispatchEvent( ::openfl::_v2::events::Event event){
	HX_STACK_FRAME("openfl._v2.display.DisplayObject","__dispatchEvent",0xe9fc76d6,"openfl._v2.display.DisplayObject.__dispatchEvent","openfl/_v2/display/DisplayObject.hx",175,0xfffdca5d)
	HX_STACK_THIS(this)
	HX_STACK_ARG(event,"event")
	HX_STACK_LINE(177)
	Dynamic _g = event->get_target();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(177)
	if (((_g == null()))){
		HX_STACK_LINE(179)
		event->set_target(hx::ObjectPtr<OBJ_>(this));
	}
	HX_STACK_LINE(183)
	event->set_currentTarget(hx::ObjectPtr<OBJ_>(this));
	HX_STACK_LINE(184)
	return this->super::dispatchEvent(event);
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,__dispatchEvent,return )

Void DisplayObject_obj::__drawToSurface( Dynamic surface,::openfl::_v2::geom::Matrix matrix,::openfl::_v2::geom::ColorTransform colorTransform,::String blendMode,::openfl::_v2::geom::Rectangle clipRect,bool smoothing){
{
		HX_STACK_FRAME("openfl._v2.display.DisplayObject","__drawToSurface",0x0f9c6124,"openfl._v2.display.DisplayObject.__drawToSurface","openfl/_v2/display/DisplayObject.hx",191,0xfffdca5d)
		HX_STACK_THIS(this)
		HX_STACK_ARG(surface,"surface")
		HX_STACK_ARG(matrix,"matrix")
		HX_STACK_ARG(colorTransform,"colorTransform")
		HX_STACK_ARG(blendMode,"blendMode")
		HX_STACK_ARG(clipRect,"clipRect")
		HX_STACK_ARG(smoothing,"smoothing")
		HX_STACK_LINE(191)
		::openfl::_v2::display::DisplayObject_obj::lime_display_object_draw_to_surface(this->__handle,surface,matrix,colorTransform,blendMode,clipRect);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC6(DisplayObject_obj,__drawToSurface,(void))

::openfl::_v2::display::DisplayObject DisplayObject_obj::__findByID( int id){
	HX_STACK_FRAME("openfl._v2.display.DisplayObject","__findByID",0x19a96635,"openfl._v2.display.DisplayObject.__findByID","openfl/_v2/display/DisplayObject.hx",196,0xfffdca5d)
	HX_STACK_THIS(this)
	HX_STACK_ARG(id,"id")
	HX_STACK_LINE(200)
	if (((this->__id == id))){
		HX_STACK_LINE(202)
		return hx::ObjectPtr<OBJ_>(this);
	}
	HX_STACK_LINE(206)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,__findByID,return )

Void DisplayObject_obj::__fireEvent( ::openfl::_v2::events::Event event){
{
		HX_STACK_FRAME("openfl._v2.display.DisplayObject","__fireEvent",0x1f8ebd5a,"openfl._v2.display.DisplayObject.__fireEvent","openfl/_v2/display/DisplayObject.hx",211,0xfffdca5d)
		HX_STACK_THIS(this)
		HX_STACK_ARG(event,"event")
		HX_STACK_LINE(213)
		Array< ::Dynamic > stack = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(stack,"stack");
		HX_STACK_LINE(215)
		if (((this->__parent != null()))){
			HX_STACK_LINE(217)
			this->__parent->__getInteractiveObjectStack(stack);
		}
		HX_STACK_LINE(221)
		int length = stack->length;		HX_STACK_VAR(length,"length");
		HX_STACK_LINE(223)
		if (((stack->length > (int)0))){
			HX_STACK_LINE(225)
			event->__setPhase(::openfl::events::EventPhase_obj::CAPTURING_PHASE);
			HX_STACK_LINE(226)
			event->set_target(hx::ObjectPtr<OBJ_>(this));
			HX_STACK_LINE(227)
			int i = (length - (int)1);		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(229)
			while((true)){
				HX_STACK_LINE(229)
				if ((!(((i >= (int)0))))){
					HX_STACK_LINE(229)
					break;
				}
				HX_STACK_LINE(231)
				stack->__get(i).StaticCast< ::openfl::_v2::display::InteractiveObject >()->__dispatchEvent(event);
				HX_STACK_LINE(233)
				if ((event->__getIsCancelled())){
					HX_STACK_LINE(235)
					return null();
				}
				HX_STACK_LINE(239)
				(i)--;
			}
		}
		HX_STACK_LINE(245)
		event->__setPhase(::openfl::events::EventPhase_obj::AT_TARGET);
		HX_STACK_LINE(246)
		this->__dispatchEvent(event);
		HX_STACK_LINE(248)
		if ((event->__getIsCancelled())){
			HX_STACK_LINE(250)
			return null();
		}
		HX_STACK_LINE(254)
		if ((event->get_bubbles())){
			HX_STACK_LINE(256)
			event->__setPhase(::openfl::events::EventPhase_obj::BUBBLING_PHASE);
			HX_STACK_LINE(258)
			{
				HX_STACK_LINE(258)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(258)
				while((true)){
					HX_STACK_LINE(258)
					if ((!(((_g < length))))){
						HX_STACK_LINE(258)
						break;
					}
					HX_STACK_LINE(258)
					int i = (_g)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(260)
					stack->__get(i).StaticCast< ::openfl::_v2::display::InteractiveObject >()->__dispatchEvent(event);
					HX_STACK_LINE(262)
					if ((event->__getIsCancelled())){
						HX_STACK_LINE(264)
						return null();
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,__fireEvent,(void))

::openfl::_v2::geom::ColorTransform DisplayObject_obj::__getColorTransform( ){
	HX_STACK_FRAME("openfl._v2.display.DisplayObject","__getColorTransform",0xb20ed995,"openfl._v2.display.DisplayObject.__getColorTransform","openfl/_v2/display/DisplayObject.hx",275,0xfffdca5d)
	HX_STACK_THIS(this)
	HX_STACK_LINE(277)
	::openfl::_v2::geom::ColorTransform colorTransform = ::openfl::_v2::geom::ColorTransform_obj::__new(null(),null(),null(),null(),null(),null(),null(),null());		HX_STACK_VAR(colorTransform,"colorTransform");
	HX_STACK_LINE(278)
	::openfl::_v2::display::DisplayObject_obj::lime_display_object_get_color_transform(this->__handle,colorTransform,false);
	HX_STACK_LINE(279)
	return colorTransform;
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,__getColorTransform,return )

::openfl::_v2::geom::ColorTransform DisplayObject_obj::__getConcatenatedColorTransform( ){
	HX_STACK_FRAME("openfl._v2.display.DisplayObject","__getConcatenatedColorTransform",0xbcaacd04,"openfl._v2.display.DisplayObject.__getConcatenatedColorTransform","openfl/_v2/display/DisplayObject.hx",284,0xfffdca5d)
	HX_STACK_THIS(this)
	HX_STACK_LINE(286)
	::openfl::_v2::geom::ColorTransform colorTransform = ::openfl::_v2::geom::ColorTransform_obj::__new(null(),null(),null(),null(),null(),null(),null(),null());		HX_STACK_VAR(colorTransform,"colorTransform");
	HX_STACK_LINE(287)
	::openfl::_v2::display::DisplayObject_obj::lime_display_object_get_color_transform(this->__handle,colorTransform,true);
	HX_STACK_LINE(288)
	return colorTransform;
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,__getConcatenatedColorTransform,return )

::openfl::_v2::geom::Matrix DisplayObject_obj::__getConcatenatedMatrix( ){
	HX_STACK_FRAME("openfl._v2.display.DisplayObject","__getConcatenatedMatrix",0xc6e3b8bc,"openfl._v2.display.DisplayObject.__getConcatenatedMatrix","openfl/_v2/display/DisplayObject.hx",293,0xfffdca5d)
	HX_STACK_THIS(this)
	HX_STACK_LINE(295)
	::openfl::_v2::geom::Matrix matrix = ::openfl::_v2::geom::Matrix_obj::__new(null(),null(),null(),null(),null(),null());		HX_STACK_VAR(matrix,"matrix");
	HX_STACK_LINE(296)
	::openfl::_v2::display::DisplayObject_obj::lime_display_object_get_matrix(this->__handle,matrix,true);
	HX_STACK_LINE(297)
	return matrix;
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,__getConcatenatedMatrix,return )

Void DisplayObject_obj::__getInteractiveObjectStack( Array< ::Dynamic > stack){
{
		HX_STACK_FRAME("openfl._v2.display.DisplayObject","__getInteractiveObjectStack",0x91c3b353,"openfl._v2.display.DisplayObject.__getInteractiveObjectStack","openfl/_v2/display/DisplayObject.hx",302,0xfffdca5d)
		HX_STACK_THIS(this)
		HX_STACK_ARG(stack,"stack")
		HX_STACK_LINE(304)
		::openfl::_v2::display::InteractiveObject interactive = this->__asInteractiveObject();		HX_STACK_VAR(interactive,"interactive");
		HX_STACK_LINE(306)
		if (((interactive != null()))){
			HX_STACK_LINE(308)
			stack->push(interactive);
		}
		HX_STACK_LINE(312)
		if (((this->__parent != null()))){
			HX_STACK_LINE(314)
			this->__parent->__getInteractiveObjectStack(stack);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,__getInteractiveObjectStack,(void))

::openfl::_v2::geom::Matrix DisplayObject_obj::__getMatrix( ){
	HX_STACK_FRAME("openfl._v2.display.DisplayObject","__getMatrix",0xe6404c4d,"openfl._v2.display.DisplayObject.__getMatrix","openfl/_v2/display/DisplayObject.hx",321,0xfffdca5d)
	HX_STACK_THIS(this)
	HX_STACK_LINE(323)
	::openfl::_v2::geom::Matrix matrix = ::openfl::_v2::geom::Matrix_obj::__new(null(),null(),null(),null(),null(),null());		HX_STACK_VAR(matrix,"matrix");
	HX_STACK_LINE(324)
	::openfl::_v2::display::DisplayObject_obj::lime_display_object_get_matrix(this->__handle,matrix,false);
	HX_STACK_LINE(325)
	return matrix;
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,__getMatrix,return )

Void DisplayObject_obj::__getObjectsUnderPoint( ::openfl::_v2::geom::Point point,Array< ::Dynamic > result){
{
		HX_STACK_FRAME("openfl._v2.display.DisplayObject","__getObjectsUnderPoint",0x5a4ca780,"openfl._v2.display.DisplayObject.__getObjectsUnderPoint","openfl/_v2/display/DisplayObject.hx",332,0xfffdca5d)
		HX_STACK_THIS(this)
		HX_STACK_ARG(point,"point")
		HX_STACK_ARG(result,"result")
		HX_STACK_LINE(332)
		if ((::openfl::_v2::display::DisplayObject_obj::lime_display_object_hit_test_point(this->__handle,point->x,point->y,true,false))){
			HX_STACK_LINE(334)
			result->push(hx::ObjectPtr<OBJ_>(this));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(DisplayObject_obj,__getObjectsUnderPoint,(void))

::openfl::_v2::geom::Rectangle DisplayObject_obj::__getPixelBounds( ){
	HX_STACK_FRAME("openfl._v2.display.DisplayObject","__getPixelBounds",0x606ae80f,"openfl._v2.display.DisplayObject.__getPixelBounds","openfl/_v2/display/DisplayObject.hx",341,0xfffdca5d)
	HX_STACK_THIS(this)
	HX_STACK_LINE(343)
	::openfl::_v2::geom::Rectangle bounds = ::openfl::_v2::geom::Rectangle_obj::__new(null(),null(),null(),null());		HX_STACK_VAR(bounds,"bounds");
	HX_STACK_LINE(344)
	::openfl::_v2::display::DisplayObject_obj::lime_display_object_get_pixel_bounds(this->__handle,bounds);
	HX_STACK_LINE(345)
	return bounds;
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,__getPixelBounds,return )

Void DisplayObject_obj::__onAdded( ::openfl::_v2::display::DisplayObject object,bool isOnStage){
{
		HX_STACK_FRAME("openfl._v2.display.DisplayObject","__onAdded",0x3f28fe77,"openfl._v2.display.DisplayObject.__onAdded","openfl/_v2/display/DisplayObject.hx",350,0xfffdca5d)
		HX_STACK_THIS(this)
		HX_STACK_ARG(object,"object")
		HX_STACK_ARG(isOnStage,"isOnStage")
		HX_STACK_LINE(352)
		if (((object == hx::ObjectPtr<OBJ_>(this)))){
			HX_STACK_LINE(354)
			::openfl::_v2::events::Event event = ::openfl::_v2::events::Event_obj::__new(::openfl::_v2::events::Event_obj::ADDED,true,false);		HX_STACK_VAR(event,"event");
			HX_STACK_LINE(355)
			event->set_target(hx::ObjectPtr<OBJ_>(this));
			HX_STACK_LINE(356)
			this->dispatchEvent(event);
		}
		HX_STACK_LINE(360)
		if ((isOnStage)){
			HX_STACK_LINE(362)
			::openfl::_v2::events::Event event = ::openfl::_v2::events::Event_obj::__new(::openfl::_v2::events::Event_obj::ADDED_TO_STAGE,false,false);		HX_STACK_VAR(event,"event");
			HX_STACK_LINE(363)
			event->set_target(hx::ObjectPtr<OBJ_>(this));
			HX_STACK_LINE(364)
			this->dispatchEvent(event);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(DisplayObject_obj,__onAdded,(void))

Void DisplayObject_obj::__onRemoved( ::openfl::_v2::display::DisplayObject object,bool wasOnStage){
{
		HX_STACK_FRAME("openfl._v2.display.DisplayObject","__onRemoved",0x78cc6517,"openfl._v2.display.DisplayObject.__onRemoved","openfl/_v2/display/DisplayObject.hx",371,0xfffdca5d)
		HX_STACK_THIS(this)
		HX_STACK_ARG(object,"object")
		HX_STACK_ARG(wasOnStage,"wasOnStage")
		HX_STACK_LINE(373)
		if (((object == hx::ObjectPtr<OBJ_>(this)))){
			HX_STACK_LINE(375)
			::openfl::_v2::events::Event event = ::openfl::_v2::events::Event_obj::__new(::openfl::_v2::events::Event_obj::REMOVED,true,false);		HX_STACK_VAR(event,"event");
			HX_STACK_LINE(376)
			event->set_target(hx::ObjectPtr<OBJ_>(this));
			HX_STACK_LINE(377)
			this->dispatchEvent(event);
		}
		HX_STACK_LINE(381)
		if ((wasOnStage)){
			HX_STACK_LINE(383)
			::openfl::_v2::events::Event event = ::openfl::_v2::events::Event_obj::__new(::openfl::_v2::events::Event_obj::REMOVED_FROM_STAGE,false,false);		HX_STACK_VAR(event,"event");
			HX_STACK_LINE(384)
			event->set_target(hx::ObjectPtr<OBJ_>(this));
			HX_STACK_LINE(385)
			this->dispatchEvent(event);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(DisplayObject_obj,__onRemoved,(void))

Void DisplayObject_obj::__setColorTransform( ::openfl::_v2::geom::ColorTransform colorTransform){
{
		HX_STACK_FRAME("openfl._v2.display.DisplayObject","__setColorTransform",0xd57cb1a1,"openfl._v2.display.DisplayObject.__setColorTransform","openfl/_v2/display/DisplayObject.hx",394,0xfffdca5d)
		HX_STACK_THIS(this)
		HX_STACK_ARG(colorTransform,"colorTransform")
		HX_STACK_LINE(394)
		::openfl::_v2::display::DisplayObject_obj::lime_display_object_set_color_transform(this->__handle,colorTransform);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,__setColorTransform,(void))

Void DisplayObject_obj::__setMatrix( ::openfl::_v2::geom::Matrix matrix){
{
		HX_STACK_FRAME("openfl._v2.display.DisplayObject","__setMatrix",0xc9913859,"openfl._v2.display.DisplayObject.__setMatrix","openfl/_v2/display/DisplayObject.hx",401,0xfffdca5d)
		HX_STACK_THIS(this)
		HX_STACK_ARG(matrix,"matrix")
		HX_STACK_LINE(401)
		::openfl::_v2::display::DisplayObject_obj::lime_display_object_set_matrix(this->__handle,matrix);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,__setMatrix,(void))

::openfl::_v2::display::DisplayObjectContainer DisplayObject_obj::__setParent( ::openfl::_v2::display::DisplayObjectContainer parent){
	HX_STACK_FRAME("openfl._v2.display.DisplayObject","__setParent",0xfb470742,"openfl._v2.display.DisplayObject.__setParent","openfl/_v2/display/DisplayObject.hx",406,0xfffdca5d)
	HX_STACK_THIS(this)
	HX_STACK_ARG(parent,"parent")
	HX_STACK_LINE(408)
	if (((parent == this->__parent))){
		HX_STACK_LINE(410)
		return parent;
	}
	HX_STACK_LINE(414)
	if (((this->__parent != null()))){
		HX_STACK_LINE(416)
		this->__parent->__removeChildFromArray(hx::ObjectPtr<OBJ_>(this));
		HX_STACK_LINE(417)
		::openfl::_v2::display::Stage _g = this->get_stage();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(417)
		bool _g1 = (_g != null());		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(417)
		this->__onRemoved(hx::ObjectPtr<OBJ_>(this),_g1);
	}
	HX_STACK_LINE(421)
	this->__parent = parent;
	HX_STACK_LINE(423)
	if (((parent != null()))){
		HX_STACK_LINE(425)
		::openfl::_v2::display::Stage _g2 = this->get_stage();		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(425)
		bool _g3 = (_g2 != null());		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(425)
		this->__onAdded(hx::ObjectPtr<OBJ_>(this),_g3);
	}
	HX_STACK_LINE(429)
	return parent;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,__setParent,return )

Float DisplayObject_obj::get_alpha( ){
	HX_STACK_FRAME("openfl._v2.display.DisplayObject","get_alpha",0x70993e2b,"openfl._v2.display.DisplayObject.get_alpha","openfl/_v2/display/DisplayObject.hx",441,0xfffdca5d)
	HX_STACK_THIS(this)
	HX_STACK_LINE(441)
	return ::openfl::_v2::display::DisplayObject_obj::lime_display_object_get_alpha(this->__handle);
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,get_alpha,return )

Float DisplayObject_obj::set_alpha( Float value){
	HX_STACK_FRAME("openfl._v2.display.DisplayObject","set_alpha",0x53ea2a37,"openfl._v2.display.DisplayObject.set_alpha","openfl/_v2/display/DisplayObject.hx",442,0xfffdca5d)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(444)
	::openfl::_v2::display::DisplayObject_obj::lime_display_object_set_alpha(this->__handle,value);
	HX_STACK_LINE(445)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,set_alpha,return )

Dynamic DisplayObject_obj::get_opaqueBackground( ){
	HX_STACK_FRAME("openfl._v2.display.DisplayObject","get_opaqueBackground",0xd76baa82,"openfl._v2.display.DisplayObject.get_opaqueBackground","openfl/_v2/display/DisplayObject.hx",450,0xfffdca5d)
	HX_STACK_THIS(this)
	HX_STACK_LINE(452)
	int i = ::openfl::_v2::display::DisplayObject_obj::lime_display_object_get_bg(this->__handle);		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(454)
	if (((((int(i) & int((int)16777216))) == (int)0))){
		HX_STACK_LINE(456)
		return null();
	}
	HX_STACK_LINE(460)
	return (int(i) & int((int)16777215));
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,get_opaqueBackground,return )

Dynamic DisplayObject_obj::set_opaqueBackground( Dynamic value){
	HX_STACK_FRAME("openfl._v2.display.DisplayObject","set_opaqueBackground",0xa42361f6,"openfl._v2.display.DisplayObject.set_opaqueBackground","openfl/_v2/display/DisplayObject.hx",465,0xfffdca5d)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(467)
	if (((value == null()))){
		HX_STACK_LINE(469)
		::openfl::_v2::display::DisplayObject_obj::lime_display_object_set_bg(this->__handle,(int)0);
	}
	else{
		HX_STACK_LINE(473)
		::openfl::_v2::display::DisplayObject_obj::lime_display_object_set_bg(this->__handle,value);
	}
	HX_STACK_LINE(477)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,set_opaqueBackground,return )

::openfl::_v2::display::BlendMode DisplayObject_obj::get_blendMode( ){
	HX_STACK_FRAME("openfl._v2.display.DisplayObject","get_blendMode",0x286265a1,"openfl._v2.display.DisplayObject.get_blendMode","openfl/_v2/display/DisplayObject.hx",482,0xfffdca5d)
	HX_STACK_THIS(this)
	HX_STACK_LINE(484)
	int i = ::openfl::_v2::display::DisplayObject_obj::lime_display_object_get_blend_mode(this->__handle);		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(485)
	return ::Type_obj::createEnumIndex(hx::ClassOf< ::openfl::_v2::display::BlendMode >(),i,null());
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,get_blendMode,return )

::openfl::_v2::display::BlendMode DisplayObject_obj::set_blendMode( ::openfl::_v2::display::BlendMode value){
	HX_STACK_FRAME("openfl._v2.display.DisplayObject","set_blendMode",0x6d6847ad,"openfl._v2.display.DisplayObject.set_blendMode","openfl/_v2/display/DisplayObject.hx",490,0xfffdca5d)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(492)
	int _g = value->__Index();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(492)
	::openfl::_v2::display::DisplayObject_obj::lime_display_object_set_blend_mode(this->__handle,_g);
	HX_STACK_LINE(493)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,set_blendMode,return )

bool DisplayObject_obj::get_cacheAsBitmap( ){
	HX_STACK_FRAME("openfl._v2.display.DisplayObject","get_cacheAsBitmap",0xe9e92eb0,"openfl._v2.display.DisplayObject.get_cacheAsBitmap","openfl/_v2/display/DisplayObject.hx",498,0xfffdca5d)
	HX_STACK_THIS(this)
	HX_STACK_LINE(498)
	return ::openfl::_v2::display::DisplayObject_obj::lime_display_object_get_cache_as_bitmap(this->__handle);
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,get_cacheAsBitmap,return )

bool DisplayObject_obj::set_cacheAsBitmap( bool value){
	HX_STACK_FRAME("openfl._v2.display.DisplayObject","set_cacheAsBitmap",0x0d5706bc,"openfl._v2.display.DisplayObject.set_cacheAsBitmap","openfl/_v2/display/DisplayObject.hx",499,0xfffdca5d)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(501)
	::openfl::_v2::display::DisplayObject_obj::lime_display_object_set_cache_as_bitmap(this->__handle,value);
	HX_STACK_LINE(502)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,set_cacheAsBitmap,return )

bool DisplayObject_obj::get_pedanticBitmapCaching( ){
	HX_STACK_FRAME("openfl._v2.display.DisplayObject","get_pedanticBitmapCaching",0xc56e05eb,"openfl._v2.display.DisplayObject.get_pedanticBitmapCaching","openfl/_v2/display/DisplayObject.hx",507,0xfffdca5d)
	HX_STACK_THIS(this)
	HX_STACK_LINE(507)
	return ::openfl::_v2::display::DisplayObject_obj::lime_display_object_get_pedantic_bitmap_caching(this->__handle);
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,get_pedanticBitmapCaching,return )

bool DisplayObject_obj::set_pedanticBitmapCaching( bool value){
	HX_STACK_FRAME("openfl._v2.display.DisplayObject","set_pedanticBitmapCaching",0x31c4c9f7,"openfl._v2.display.DisplayObject.set_pedanticBitmapCaching","openfl/_v2/display/DisplayObject.hx",508,0xfffdca5d)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(510)
	::openfl::_v2::display::DisplayObject_obj::lime_display_object_set_pedantic_bitmap_caching(this->__handle,value);
	HX_STACK_LINE(511)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,set_pedanticBitmapCaching,return )

::openfl::display::PixelSnapping DisplayObject_obj::get_pixelSnapping( ){
	HX_STACK_FRAME("openfl._v2.display.DisplayObject","get_pixelSnapping",0x387b5a2f,"openfl._v2.display.DisplayObject.get_pixelSnapping","openfl/_v2/display/DisplayObject.hx",516,0xfffdca5d)
	HX_STACK_THIS(this)
	HX_STACK_LINE(518)
	int i = ::openfl::_v2::display::DisplayObject_obj::lime_display_object_get_pixel_snapping(this->__handle);		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(519)
	return ::Type_obj::createEnumIndex(hx::ClassOf< ::openfl::display::PixelSnapping >(),i,null());
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,get_pixelSnapping,return )

::openfl::display::PixelSnapping DisplayObject_obj::set_pixelSnapping( ::openfl::display::PixelSnapping value){
	HX_STACK_FRAME("openfl._v2.display.DisplayObject","set_pixelSnapping",0x5be9323b,"openfl._v2.display.DisplayObject.set_pixelSnapping","openfl/_v2/display/DisplayObject.hx",524,0xfffdca5d)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(526)
	if (((value == null()))){
		HX_STACK_LINE(528)
		::openfl::_v2::display::DisplayObject_obj::lime_display_object_set_pixel_snapping(this->__handle,(int)0);
	}
	else{
		HX_STACK_LINE(532)
		int _g = value->__Index();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(532)
		::openfl::_v2::display::DisplayObject_obj::lime_display_object_set_pixel_snapping(this->__handle,_g);
	}
	HX_STACK_LINE(536)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,set_pixelSnapping,return )

Dynamic DisplayObject_obj::get_filters( ){
	HX_STACK_FRAME("openfl._v2.display.DisplayObject","get_filters",0x0f3645c8,"openfl._v2.display.DisplayObject.get_filters","openfl/_v2/display/DisplayObject.hx",541,0xfffdca5d)
	HX_STACK_THIS(this)
	HX_STACK_LINE(543)
	if (((this->__filters == null()))){
		HX_STACK_LINE(543)
		return Dynamic( Array_obj<Dynamic>::__new());
	}
	HX_STACK_LINE(544)
	Dynamic result = Dynamic( Array_obj<Dynamic>::__new() );		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(546)
	{
		HX_STACK_LINE(546)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(546)
		Dynamic _g1 = this->__filters;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(546)
		while((true)){
			HX_STACK_LINE(546)
			if ((!(((_g < _g1->__Field(HX_CSTRING("length"),true)))))){
				HX_STACK_LINE(546)
				break;
			}
			HX_STACK_LINE(546)
			Dynamic filter = _g1->__GetItem(_g);		HX_STACK_VAR(filter,"filter");
			HX_STACK_LINE(546)
			++(_g);
			HX_STACK_LINE(548)
			Dynamic _g2 = filter->__Field(HX_CSTRING("clone"),true)();		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(548)
			result->__Field(HX_CSTRING("push"),true)(_g2);
		}
	}
	HX_STACK_LINE(552)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,get_filters,return )

Dynamic DisplayObject_obj::set_filters( Dynamic value){
	HX_STACK_FRAME("openfl._v2.display.DisplayObject","set_filters",0x19a34cd4,"openfl._v2.display.DisplayObject.set_filters","openfl/_v2/display/DisplayObject.hx",557,0xfffdca5d)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(559)
	Dynamic _g = this->get_filters();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(559)
	if (((  ((!(((_g == null()))))) ? bool((value == null())) : bool(true) ))){
		HX_STACK_LINE(561)
		this->__filters = null();
	}
	else{
		HX_STACK_LINE(565)
		Dynamic _g1 = Dynamic( Array_obj<Dynamic>::__new() );		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(565)
		this->__filters = _g1;
		HX_STACK_LINE(567)
		{
			HX_STACK_LINE(567)
			int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(567)
			while((true)){
				HX_STACK_LINE(567)
				if ((!(((_g2 < value->__Field(HX_CSTRING("length"),true)))))){
					HX_STACK_LINE(567)
					break;
				}
				HX_STACK_LINE(567)
				Dynamic filter = value->__GetItem(_g2);		HX_STACK_VAR(filter,"filter");
				HX_STACK_LINE(567)
				++(_g2);
				HX_STACK_LINE(569)
				if (((filter != null()))){
					HX_STACK_LINE(571)
					Dynamic _g21 = filter->__Field(HX_CSTRING("clone"),true)();		HX_STACK_VAR(_g21,"_g21");
					HX_STACK_LINE(571)
					this->__filters->__Field(HX_CSTRING("push"),true)(_g21);
				}
			}
		}
	}
	HX_STACK_LINE(579)
	::openfl::_v2::display::DisplayObject_obj::lime_display_object_set_filters(this->__handle,this->__filters);
	HX_STACK_LINE(580)
	return this->get_filters();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,set_filters,return )

::openfl::_v2::display::Graphics DisplayObject_obj::get_graphics( ){
	HX_STACK_FRAME("openfl._v2.display.DisplayObject","get_graphics",0x3e27e01e,"openfl._v2.display.DisplayObject.get_graphics","openfl/_v2/display/DisplayObject.hx",585,0xfffdca5d)
	HX_STACK_THIS(this)
	HX_STACK_LINE(587)
	if (((this->__graphicsCache == null()))){
		HX_STACK_LINE(589)
		Dynamic _g = ::openfl::_v2::display::DisplayObject_obj::lime_display_object_get_graphics(this->__handle);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(589)
		::openfl::_v2::display::Graphics _g1 = ::openfl::_v2::display::Graphics_obj::__new(_g);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(589)
		this->__graphicsCache = _g1;
	}
	HX_STACK_LINE(593)
	return this->__graphicsCache;
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,get_graphics,return )

Float DisplayObject_obj::get_height( ){
	HX_STACK_FRAME("openfl._v2.display.DisplayObject","get_height",0xd58d647a,"openfl._v2.display.DisplayObject.get_height","openfl/_v2/display/DisplayObject.hx",598,0xfffdca5d)
	HX_STACK_THIS(this)
	HX_STACK_LINE(598)
	return ::openfl::_v2::display::DisplayObject_obj::lime_display_object_get_height(this->__handle);
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,get_height,return )

Float DisplayObject_obj::set_height( Float value){
	HX_STACK_FRAME("openfl._v2.display.DisplayObject","set_height",0xd90b02ee,"openfl._v2.display.DisplayObject.set_height","openfl/_v2/display/DisplayObject.hx",599,0xfffdca5d)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(601)
	::openfl::_v2::display::DisplayObject_obj::lime_display_object_set_height(this->__handle,value);
	HX_STACK_LINE(602)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,set_height,return )

::openfl::_v2::display::DisplayObject DisplayObject_obj::set_mask( ::openfl::_v2::display::DisplayObject value){
	HX_STACK_FRAME("openfl._v2.display.DisplayObject","set_mask",0x42d29c33,"openfl._v2.display.DisplayObject.set_mask","openfl/_v2/display/DisplayObject.hx",607,0xfffdca5d)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(609)
	this->mask = value;
	HX_STACK_LINE(610)
	::openfl::_v2::display::DisplayObject_obj::lime_display_object_set_mask(this->__handle,(  (((value == null()))) ? Dynamic(null()) : Dynamic(value->__handle) ));
	HX_STACK_LINE(611)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,set_mask,return )

Float DisplayObject_obj::get_mouseX( ){
	HX_STACK_FRAME("openfl._v2.display.DisplayObject","get_mouseX",0x9f4fa726,"openfl._v2.display.DisplayObject.get_mouseX","openfl/_v2/display/DisplayObject.hx",616,0xfffdca5d)
	HX_STACK_THIS(this)
	HX_STACK_LINE(616)
	return ::openfl::_v2::display::DisplayObject_obj::lime_display_object_get_mouse_x(this->__handle);
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,get_mouseX,return )

Float DisplayObject_obj::get_mouseY( ){
	HX_STACK_FRAME("openfl._v2.display.DisplayObject","get_mouseY",0x9f4fa727,"openfl._v2.display.DisplayObject.get_mouseY","openfl/_v2/display/DisplayObject.hx",617,0xfffdca5d)
	HX_STACK_THIS(this)
	HX_STACK_LINE(617)
	return ::openfl::_v2::display::DisplayObject_obj::lime_display_object_get_mouse_y(this->__handle);
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,get_mouseY,return )

::String DisplayObject_obj::get_name( ){
	HX_STACK_FRAME("openfl._v2.display.DisplayObject","get_name",0x951e741e,"openfl._v2.display.DisplayObject.get_name","openfl/_v2/display/DisplayObject.hx",620,0xfffdca5d)
	HX_STACK_THIS(this)
	HX_STACK_LINE(620)
	return ::openfl::_v2::display::DisplayObject_obj::lime_display_object_get_name(this->__handle);
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,get_name,return )

::String DisplayObject_obj::set_name( ::String value){
	HX_STACK_FRAME("openfl._v2.display.DisplayObject","set_name",0x437bcd92,"openfl._v2.display.DisplayObject.set_name","openfl/_v2/display/DisplayObject.hx",621,0xfffdca5d)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(623)
	::openfl::_v2::display::DisplayObject_obj::lime_display_object_set_name(this->__handle,value);
	HX_STACK_LINE(624)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,set_name,return )

::openfl::_v2::display::DisplayObjectContainer DisplayObject_obj::get_parent( ){
	HX_STACK_FRAME("openfl._v2.display.DisplayObject","get_parent",0xc0bf61bd,"openfl._v2.display.DisplayObject.get_parent","openfl/_v2/display/DisplayObject.hx",629,0xfffdca5d)
	HX_STACK_THIS(this)
	HX_STACK_LINE(629)
	return this->__parent;
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,get_parent,return )

::openfl::_v2::display::DisplayObject DisplayObject_obj::get_root( ){
	HX_STACK_FRAME("openfl._v2.display.DisplayObject","get_root",0x97cdeff5,"openfl._v2.display.DisplayObject.get_root","openfl/_v2/display/DisplayObject.hx",632,0xfffdca5d)
	HX_STACK_THIS(this)
	HX_STACK_LINE(634)
	::openfl::_v2::display::Stage _g = this->get_stage();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(634)
	if (((_g != null()))){
		HX_STACK_LINE(636)
		return ::openfl::_v2::Lib_obj::get_current();
	}
	HX_STACK_LINE(640)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,get_root,return )

Float DisplayObject_obj::get_rotation( ){
	HX_STACK_FRAME("openfl._v2.display.DisplayObject","get_rotation",0x34462491,"openfl._v2.display.DisplayObject.get_rotation","openfl/_v2/display/DisplayObject.hx",645,0xfffdca5d)
	HX_STACK_THIS(this)
	HX_STACK_LINE(645)
	return ::openfl::_v2::display::DisplayObject_obj::lime_display_object_get_rotation(this->__handle);
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,get_rotation,return )

Float DisplayObject_obj::set_rotation( Float value){
	HX_STACK_FRAME("openfl._v2.display.DisplayObject","set_rotation",0x493f4805,"openfl._v2.display.DisplayObject.set_rotation","openfl/_v2/display/DisplayObject.hx",646,0xfffdca5d)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(648)
	::openfl::_v2::display::DisplayObject_obj::lime_display_object_set_rotation(this->__handle,value);
	HX_STACK_LINE(649)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,set_rotation,return )

::openfl::_v2::geom::Rectangle DisplayObject_obj::get_scale9Grid( ){
	HX_STACK_FRAME("openfl._v2.display.DisplayObject","get_scale9Grid",0x1828f2e8,"openfl._v2.display.DisplayObject.get_scale9Grid","openfl/_v2/display/DisplayObject.hx",654,0xfffdca5d)
	HX_STACK_THIS(this)
	HX_STACK_LINE(654)
	if (((this->__scale9Grid == null()))){
		HX_STACK_LINE(654)
		return null();
	}
	else{
		HX_STACK_LINE(654)
		return this->__scale9Grid->clone();
	}
	HX_STACK_LINE(654)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,get_scale9Grid,return )

::openfl::_v2::geom::Rectangle DisplayObject_obj::set_scale9Grid( ::openfl::_v2::geom::Rectangle value){
	HX_STACK_FRAME("openfl._v2.display.DisplayObject","set_scale9Grid",0x3848db5c,"openfl._v2.display.DisplayObject.set_scale9Grid","openfl/_v2/display/DisplayObject.hx",655,0xfffdca5d)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(657)
	::openfl::_v2::geom::Rectangle _g;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(657)
	if (((value == null()))){
		HX_STACK_LINE(657)
		_g = null();
	}
	else{
		HX_STACK_LINE(657)
		_g = value->clone();
	}
	HX_STACK_LINE(657)
	this->__scale9Grid = _g;
	HX_STACK_LINE(658)
	::openfl::_v2::display::DisplayObject_obj::lime_display_object_set_scale9_grid(this->__handle,this->__scale9Grid);
	HX_STACK_LINE(659)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,set_scale9Grid,return )

Float DisplayObject_obj::get_scaleX( ){
	HX_STACK_FRAME("openfl._v2.display.DisplayObject","get_scaleX",0x0f674721,"openfl._v2.display.DisplayObject.get_scaleX","openfl/_v2/display/DisplayObject.hx",664,0xfffdca5d)
	HX_STACK_THIS(this)
	HX_STACK_LINE(664)
	return ::openfl::_v2::display::DisplayObject_obj::lime_display_object_get_scale_x(this->__handle);
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,get_scaleX,return )

Float DisplayObject_obj::set_scaleX( Float value){
	HX_STACK_FRAME("openfl._v2.display.DisplayObject","set_scaleX",0x12e4e595,"openfl._v2.display.DisplayObject.set_scaleX","openfl/_v2/display/DisplayObject.hx",665,0xfffdca5d)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(667)
	::openfl::_v2::display::DisplayObject_obj::lime_display_object_set_scale_x(this->__handle,value);
	HX_STACK_LINE(668)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,set_scaleX,return )

Float DisplayObject_obj::get_scaleY( ){
	HX_STACK_FRAME("openfl._v2.display.DisplayObject","get_scaleY",0x0f674722,"openfl._v2.display.DisplayObject.get_scaleY","openfl/_v2/display/DisplayObject.hx",673,0xfffdca5d)
	HX_STACK_THIS(this)
	HX_STACK_LINE(673)
	return ::openfl::_v2::display::DisplayObject_obj::lime_display_object_get_scale_y(this->__handle);
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,get_scaleY,return )

Float DisplayObject_obj::set_scaleY( Float value){
	HX_STACK_FRAME("openfl._v2.display.DisplayObject","set_scaleY",0x12e4e596,"openfl._v2.display.DisplayObject.set_scaleY","openfl/_v2/display/DisplayObject.hx",674,0xfffdca5d)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(676)
	::openfl::_v2::display::DisplayObject_obj::lime_display_object_set_scale_y(this->__handle,value);
	HX_STACK_LINE(677)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,set_scaleY,return )

::openfl::_v2::geom::Rectangle DisplayObject_obj::get_scrollRect( ){
	HX_STACK_FRAME("openfl._v2.display.DisplayObject","get_scrollRect",0x926d7de4,"openfl._v2.display.DisplayObject.get_scrollRect","openfl/_v2/display/DisplayObject.hx",682,0xfffdca5d)
	HX_STACK_THIS(this)
	HX_STACK_LINE(682)
	if (((this->__scrollRect == null()))){
		HX_STACK_LINE(682)
		return null();
	}
	else{
		HX_STACK_LINE(682)
		return this->__scrollRect->clone();
	}
	HX_STACK_LINE(682)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,get_scrollRect,return )

::openfl::_v2::geom::Rectangle DisplayObject_obj::set_scrollRect( ::openfl::_v2::geom::Rectangle value){
	HX_STACK_FRAME("openfl._v2.display.DisplayObject","set_scrollRect",0xb28d6658,"openfl._v2.display.DisplayObject.set_scrollRect","openfl/_v2/display/DisplayObject.hx",683,0xfffdca5d)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(685)
	::openfl::_v2::geom::Rectangle _g;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(685)
	if (((value == null()))){
		HX_STACK_LINE(685)
		_g = null();
	}
	else{
		HX_STACK_LINE(685)
		_g = value->clone();
	}
	HX_STACK_LINE(685)
	this->__scrollRect = _g;
	HX_STACK_LINE(686)
	::openfl::_v2::display::DisplayObject_obj::lime_display_object_set_scroll_rect(this->__handle,this->__scrollRect);
	HX_STACK_LINE(687)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,set_scrollRect,return )

::openfl::_v2::display::Stage DisplayObject_obj::get_stage( ){
	HX_STACK_FRAME("openfl._v2.display.DisplayObject","get_stage",0xd30e018b,"openfl._v2.display.DisplayObject.get_stage","openfl/_v2/display/DisplayObject.hx",692,0xfffdca5d)
	HX_STACK_THIS(this)
	HX_STACK_LINE(694)
	if (((this->__parent != null()))){
		HX_STACK_LINE(696)
		return this->__parent->get_stage();
	}
	HX_STACK_LINE(700)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,get_stage,return )

::openfl::_v2::geom::Transform DisplayObject_obj::get_transform( ){
	HX_STACK_FRAME("openfl._v2.display.DisplayObject","get_transform",0x61bdaeb9,"openfl._v2.display.DisplayObject.get_transform","openfl/_v2/display/DisplayObject.hx",705,0xfffdca5d)
	HX_STACK_THIS(this)
	HX_STACK_LINE(705)
	return ::openfl::_v2::geom::Transform_obj::__new(hx::ObjectPtr<OBJ_>(this));
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,get_transform,return )

::openfl::_v2::geom::Transform DisplayObject_obj::set_transform( ::openfl::_v2::geom::Transform value){
	HX_STACK_FRAME("openfl._v2.display.DisplayObject","set_transform",0xa6c390c5,"openfl._v2.display.DisplayObject.set_transform","openfl/_v2/display/DisplayObject.hx",706,0xfffdca5d)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(708)
	::openfl::_v2::geom::Matrix _g = value->get_matrix();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(708)
	this->__setMatrix(_g);
	HX_STACK_LINE(709)
	::openfl::_v2::geom::ColorTransform _g1 = value->get_colorTransform();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(709)
	this->__setColorTransform(_g1);
	HX_STACK_LINE(710)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,set_transform,return )

bool DisplayObject_obj::get_visible( ){
	HX_STACK_FRAME("openfl._v2.display.DisplayObject","get_visible",0xa9141c7f,"openfl._v2.display.DisplayObject.get_visible","openfl/_v2/display/DisplayObject.hx",715,0xfffdca5d)
	HX_STACK_THIS(this)
	HX_STACK_LINE(715)
	return ::openfl::_v2::display::DisplayObject_obj::lime_display_object_get_visible(this->__handle);
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,get_visible,return )

bool DisplayObject_obj::set_visible( bool value){
	HX_STACK_FRAME("openfl._v2.display.DisplayObject","set_visible",0xb381238b,"openfl._v2.display.DisplayObject.set_visible","openfl/_v2/display/DisplayObject.hx",716,0xfffdca5d)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(718)
	::openfl::_v2::display::DisplayObject_obj::lime_display_object_set_visible(this->__handle,value);
	HX_STACK_LINE(719)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,set_visible,return )

Float DisplayObject_obj::get_width( ){
	HX_STACK_FRAME("openfl._v2.display.DisplayObject","get_width",0x19654cd3,"openfl._v2.display.DisplayObject.get_width","openfl/_v2/display/DisplayObject.hx",724,0xfffdca5d)
	HX_STACK_THIS(this)
	HX_STACK_LINE(724)
	return ::openfl::_v2::display::DisplayObject_obj::lime_display_object_get_width(this->__handle);
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,get_width,return )

Float DisplayObject_obj::set_width( Float value){
	HX_STACK_FRAME("openfl._v2.display.DisplayObject","set_width",0xfcb638df,"openfl._v2.display.DisplayObject.set_width","openfl/_v2/display/DisplayObject.hx",725,0xfffdca5d)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(727)
	::openfl::_v2::display::DisplayObject_obj::lime_display_object_set_width(this->__handle,value);
	HX_STACK_LINE(728)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,set_width,return )

Float DisplayObject_obj::get_x( ){
	HX_STACK_FRAME("openfl._v2.display.DisplayObject","get_x",0xf3c1ecc5,"openfl._v2.display.DisplayObject.get_x","openfl/_v2/display/DisplayObject.hx",733,0xfffdca5d)
	HX_STACK_THIS(this)
	HX_STACK_LINE(733)
	return ::openfl::_v2::display::DisplayObject_obj::lime_display_object_get_x(this->__handle);
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,get_x,return )

Float DisplayObject_obj::set_x( Float value){
	HX_STACK_FRAME("openfl._v2.display.DisplayObject","set_x",0xdc90e2d1,"openfl._v2.display.DisplayObject.set_x","openfl/_v2/display/DisplayObject.hx",734,0xfffdca5d)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(736)
	::openfl::_v2::display::DisplayObject_obj::lime_display_object_set_x(this->__handle,value);
	HX_STACK_LINE(737)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,set_x,return )

Float DisplayObject_obj::get_y( ){
	HX_STACK_FRAME("openfl._v2.display.DisplayObject","get_y",0xf3c1ecc6,"openfl._v2.display.DisplayObject.get_y","openfl/_v2/display/DisplayObject.hx",742,0xfffdca5d)
	HX_STACK_THIS(this)
	HX_STACK_LINE(742)
	return ::openfl::_v2::display::DisplayObject_obj::lime_display_object_get_y(this->__handle);
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,get_y,return )

Float DisplayObject_obj::set_y( Float value){
	HX_STACK_FRAME("openfl._v2.display.DisplayObject","set_y",0xdc90e2d2,"openfl._v2.display.DisplayObject.set_y","openfl/_v2/display/DisplayObject.hx",743,0xfffdca5d)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(745)
	::openfl::_v2::display::DisplayObject_obj::lime_display_object_set_y(this->__handle,value);
	HX_STACK_LINE(746)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,set_y,return )

Float DisplayObject_obj::get_z( ){
	HX_STACK_FRAME("openfl._v2.display.DisplayObject","get_z",0xf3c1ecc7,"openfl._v2.display.DisplayObject.get_z","openfl/_v2/display/DisplayObject.hx",751,0xfffdca5d)
	HX_STACK_THIS(this)
	HX_STACK_LINE(751)
	return ::openfl::_v2::display::DisplayObject_obj::lime_display_object_get_z(this->__handle);
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,get_z,return )

Float DisplayObject_obj::set_z( Float value){
	HX_STACK_FRAME("openfl._v2.display.DisplayObject","set_z",0xdc90e2d3,"openfl._v2.display.DisplayObject.set_z","openfl/_v2/display/DisplayObject.hx",752,0xfffdca5d)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(754)
	::openfl::_v2::display::DisplayObject_obj::lime_display_object_set_z(this->__handle,value);
	HX_STACK_LINE(755)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,set_z,return )

Dynamic DisplayObject_obj::lime_create_display_object;

Dynamic DisplayObject_obj::lime_display_object_get_graphics;

Dynamic DisplayObject_obj::lime_display_object_draw_to_surface;

Dynamic DisplayObject_obj::lime_display_object_get_id;

Dynamic DisplayObject_obj::lime_display_object_get_x;

Dynamic DisplayObject_obj::lime_display_object_set_x;

Dynamic DisplayObject_obj::lime_display_object_get_y;

Dynamic DisplayObject_obj::lime_display_object_set_y;

Dynamic DisplayObject_obj::lime_display_object_get_z;

Dynamic DisplayObject_obj::lime_display_object_set_z;

Dynamic DisplayObject_obj::lime_display_object_get_scale_x;

Dynamic DisplayObject_obj::lime_display_object_set_scale_x;

Dynamic DisplayObject_obj::lime_display_object_get_scale_y;

Dynamic DisplayObject_obj::lime_display_object_set_scale_y;

Dynamic DisplayObject_obj::lime_display_object_get_mouse_x;

Dynamic DisplayObject_obj::lime_display_object_get_mouse_y;

Dynamic DisplayObject_obj::lime_display_object_get_rotation;

Dynamic DisplayObject_obj::lime_display_object_set_rotation;

Dynamic DisplayObject_obj::lime_display_object_get_bg;

Dynamic DisplayObject_obj::lime_display_object_set_bg;

Dynamic DisplayObject_obj::lime_display_object_get_name;

Dynamic DisplayObject_obj::lime_display_object_set_name;

Dynamic DisplayObject_obj::lime_display_object_get_width;

Dynamic DisplayObject_obj::lime_display_object_set_width;

Dynamic DisplayObject_obj::lime_display_object_get_height;

Dynamic DisplayObject_obj::lime_display_object_set_height;

Dynamic DisplayObject_obj::lime_display_object_get_alpha;

Dynamic DisplayObject_obj::lime_display_object_set_alpha;

Dynamic DisplayObject_obj::lime_display_object_get_blend_mode;

Dynamic DisplayObject_obj::lime_display_object_set_blend_mode;

Dynamic DisplayObject_obj::lime_display_object_get_cache_as_bitmap;

Dynamic DisplayObject_obj::lime_display_object_set_cache_as_bitmap;

Dynamic DisplayObject_obj::lime_display_object_get_pedantic_bitmap_caching;

Dynamic DisplayObject_obj::lime_display_object_set_pedantic_bitmap_caching;

Dynamic DisplayObject_obj::lime_display_object_get_pixel_snapping;

Dynamic DisplayObject_obj::lime_display_object_set_pixel_snapping;

Dynamic DisplayObject_obj::lime_display_object_get_visible;

Dynamic DisplayObject_obj::lime_display_object_set_visible;

Dynamic DisplayObject_obj::lime_display_object_set_filters;

Dynamic DisplayObject_obj::lime_display_object_global_to_local;

Dynamic DisplayObject_obj::lime_display_object_local_to_global;

Dynamic DisplayObject_obj::lime_display_object_set_scale9_grid;

Dynamic DisplayObject_obj::lime_display_object_set_scroll_rect;

Dynamic DisplayObject_obj::lime_display_object_set_mask;

Dynamic DisplayObject_obj::lime_display_object_set_matrix;

Dynamic DisplayObject_obj::lime_display_object_get_matrix;

Dynamic DisplayObject_obj::lime_display_object_get_color_transform;

Dynamic DisplayObject_obj::lime_display_object_set_color_transform;

Dynamic DisplayObject_obj::lime_display_object_get_pixel_bounds;

Dynamic DisplayObject_obj::lime_display_object_get_bounds;

Dynamic DisplayObject_obj::lime_display_object_hit_test_point;


DisplayObject_obj::DisplayObject_obj()
{
}

void DisplayObject_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(DisplayObject);
	HX_MARK_MEMBER_NAME(graphics,"graphics");
	HX_MARK_MEMBER_NAME(loaderInfo,"loaderInfo");
	HX_MARK_MEMBER_NAME(mask,"mask");
	HX_MARK_MEMBER_NAME(mouseX,"mouseX");
	HX_MARK_MEMBER_NAME(mouseY,"mouseY");
	HX_MARK_MEMBER_NAME(parent,"parent");
	HX_MARK_MEMBER_NAME(root,"root");
	HX_MARK_MEMBER_NAME(stage,"stage");
	HX_MARK_MEMBER_NAME(__handle,"__handle");
	HX_MARK_MEMBER_NAME(__filters,"__filters");
	HX_MARK_MEMBER_NAME(__graphicsCache,"__graphicsCache");
	HX_MARK_MEMBER_NAME(__id,"__id");
	HX_MARK_MEMBER_NAME(__parent,"__parent");
	HX_MARK_MEMBER_NAME(__scale9Grid,"__scale9Grid");
	HX_MARK_MEMBER_NAME(__scrollRect,"__scrollRect");
	::openfl::_v2::events::EventDispatcher_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void DisplayObject_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(graphics,"graphics");
	HX_VISIT_MEMBER_NAME(loaderInfo,"loaderInfo");
	HX_VISIT_MEMBER_NAME(mask,"mask");
	HX_VISIT_MEMBER_NAME(mouseX,"mouseX");
	HX_VISIT_MEMBER_NAME(mouseY,"mouseY");
	HX_VISIT_MEMBER_NAME(parent,"parent");
	HX_VISIT_MEMBER_NAME(root,"root");
	HX_VISIT_MEMBER_NAME(stage,"stage");
	HX_VISIT_MEMBER_NAME(__handle,"__handle");
	HX_VISIT_MEMBER_NAME(__filters,"__filters");
	HX_VISIT_MEMBER_NAME(__graphicsCache,"__graphicsCache");
	HX_VISIT_MEMBER_NAME(__id,"__id");
	HX_VISIT_MEMBER_NAME(__parent,"__parent");
	HX_VISIT_MEMBER_NAME(__scale9Grid,"__scale9Grid");
	HX_VISIT_MEMBER_NAME(__scrollRect,"__scrollRect");
	::openfl::_v2::events::EventDispatcher_obj::__Visit(HX_VISIT_ARG);
}

Dynamic DisplayObject_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { return get_x(); }
		if (HX_FIELD_EQ(inName,"y") ) { return get_y(); }
		if (HX_FIELD_EQ(inName,"z") ) { return get_z(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"mask") ) { return mask; }
		if (HX_FIELD_EQ(inName,"name") ) { return get_name(); }
		if (HX_FIELD_EQ(inName,"root") ) { return inCallProp ? get_root() : root; }
		if (HX_FIELD_EQ(inName,"__id") ) { return __id; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"alpha") ) { return get_alpha(); }
		if (HX_FIELD_EQ(inName,"stage") ) { return inCallProp ? get_stage() : stage; }
		if (HX_FIELD_EQ(inName,"width") ) { return get_width(); }
		if (HX_FIELD_EQ(inName,"get_x") ) { return get_x_dyn(); }
		if (HX_FIELD_EQ(inName,"set_x") ) { return set_x_dyn(); }
		if (HX_FIELD_EQ(inName,"get_y") ) { return get_y_dyn(); }
		if (HX_FIELD_EQ(inName,"set_y") ) { return set_y_dyn(); }
		if (HX_FIELD_EQ(inName,"get_z") ) { return get_z_dyn(); }
		if (HX_FIELD_EQ(inName,"set_z") ) { return set_z_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"height") ) { return get_height(); }
		if (HX_FIELD_EQ(inName,"mouseX") ) { return inCallProp ? get_mouseX() : mouseX; }
		if (HX_FIELD_EQ(inName,"mouseY") ) { return inCallProp ? get_mouseY() : mouseY; }
		if (HX_FIELD_EQ(inName,"parent") ) { return inCallProp ? get_parent() : parent; }
		if (HX_FIELD_EQ(inName,"scaleX") ) { return get_scaleX(); }
		if (HX_FIELD_EQ(inName,"scaleY") ) { return get_scaleY(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"filters") ) { return get_filters(); }
		if (HX_FIELD_EQ(inName,"visible") ) { return get_visible(); }
		if (HX_FIELD_EQ(inName,"getRect") ) { return getRect_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"graphics") ) { return inCallProp ? get_graphics() : graphics; }
		if (HX_FIELD_EQ(inName,"rotation") ) { return get_rotation(); }
		if (HX_FIELD_EQ(inName,"__handle") ) { return __handle; }
		if (HX_FIELD_EQ(inName,"__parent") ) { return __parent; }
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		if (HX_FIELD_EQ(inName,"set_mask") ) { return set_mask_dyn(); }
		if (HX_FIELD_EQ(inName,"get_name") ) { return get_name_dyn(); }
		if (HX_FIELD_EQ(inName,"set_name") ) { return set_name_dyn(); }
		if (HX_FIELD_EQ(inName,"get_root") ) { return get_root_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"blendMode") ) { return get_blendMode(); }
		if (HX_FIELD_EQ(inName,"transform") ) { return get_transform(); }
		if (HX_FIELD_EQ(inName,"__filters") ) { return __filters; }
		if (HX_FIELD_EQ(inName,"getBounds") ) { return getBounds_dyn(); }
		if (HX_FIELD_EQ(inName,"__onAdded") ) { return __onAdded_dyn(); }
		if (HX_FIELD_EQ(inName,"get_alpha") ) { return get_alpha_dyn(); }
		if (HX_FIELD_EQ(inName,"set_alpha") ) { return set_alpha_dyn(); }
		if (HX_FIELD_EQ(inName,"get_stage") ) { return get_stage_dyn(); }
		if (HX_FIELD_EQ(inName,"get_width") ) { return get_width_dyn(); }
		if (HX_FIELD_EQ(inName,"set_width") ) { return set_width_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"loaderInfo") ) { return loaderInfo; }
		if (HX_FIELD_EQ(inName,"scale9Grid") ) { return get_scale9Grid(); }
		if (HX_FIELD_EQ(inName,"scrollRect") ) { return get_scrollRect(); }
		if (HX_FIELD_EQ(inName,"__contains") ) { return __contains_dyn(); }
		if (HX_FIELD_EQ(inName,"__findByID") ) { return __findByID_dyn(); }
		if (HX_FIELD_EQ(inName,"get_height") ) { return get_height_dyn(); }
		if (HX_FIELD_EQ(inName,"set_height") ) { return set_height_dyn(); }
		if (HX_FIELD_EQ(inName,"get_mouseX") ) { return get_mouseX_dyn(); }
		if (HX_FIELD_EQ(inName,"get_mouseY") ) { return get_mouseY_dyn(); }
		if (HX_FIELD_EQ(inName,"get_parent") ) { return get_parent_dyn(); }
		if (HX_FIELD_EQ(inName,"get_scaleX") ) { return get_scaleX_dyn(); }
		if (HX_FIELD_EQ(inName,"set_scaleX") ) { return set_scaleX_dyn(); }
		if (HX_FIELD_EQ(inName,"get_scaleY") ) { return get_scaleY_dyn(); }
		if (HX_FIELD_EQ(inName,"set_scaleY") ) { return set_scaleY_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"__broadcast") ) { return __broadcast_dyn(); }
		if (HX_FIELD_EQ(inName,"__fireEvent") ) { return __fireEvent_dyn(); }
		if (HX_FIELD_EQ(inName,"__getMatrix") ) { return __getMatrix_dyn(); }
		if (HX_FIELD_EQ(inName,"__onRemoved") ) { return __onRemoved_dyn(); }
		if (HX_FIELD_EQ(inName,"__setMatrix") ) { return __setMatrix_dyn(); }
		if (HX_FIELD_EQ(inName,"__setParent") ) { return __setParent_dyn(); }
		if (HX_FIELD_EQ(inName,"get_filters") ) { return get_filters_dyn(); }
		if (HX_FIELD_EQ(inName,"set_filters") ) { return set_filters_dyn(); }
		if (HX_FIELD_EQ(inName,"get_visible") ) { return get_visible_dyn(); }
		if (HX_FIELD_EQ(inName,"set_visible") ) { return set_visible_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"__scale9Grid") ) { return __scale9Grid; }
		if (HX_FIELD_EQ(inName,"__scrollRect") ) { return __scrollRect; }
		if (HX_FIELD_EQ(inName,"hitTestPoint") ) { return hitTestPoint_dyn(); }
		if (HX_FIELD_EQ(inName,"get_graphics") ) { return get_graphics_dyn(); }
		if (HX_FIELD_EQ(inName,"get_rotation") ) { return get_rotation_dyn(); }
		if (HX_FIELD_EQ(inName,"set_rotation") ) { return set_rotation_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"cacheAsBitmap") ) { return get_cacheAsBitmap(); }
		if (HX_FIELD_EQ(inName,"pixelSnapping") ) { return get_pixelSnapping(); }
		if (HX_FIELD_EQ(inName,"dispatchEvent") ) { return dispatchEvent_dyn(); }
		if (HX_FIELD_EQ(inName,"globalToLocal") ) { return globalToLocal_dyn(); }
		if (HX_FIELD_EQ(inName,"hitTestObject") ) { return hitTestObject_dyn(); }
		if (HX_FIELD_EQ(inName,"localToGlobal") ) { return localToGlobal_dyn(); }
		if (HX_FIELD_EQ(inName,"get_blendMode") ) { return get_blendMode_dyn(); }
		if (HX_FIELD_EQ(inName,"set_blendMode") ) { return set_blendMode_dyn(); }
		if (HX_FIELD_EQ(inName,"get_transform") ) { return get_transform_dyn(); }
		if (HX_FIELD_EQ(inName,"set_transform") ) { return set_transform_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"get_scale9Grid") ) { return get_scale9Grid_dyn(); }
		if (HX_FIELD_EQ(inName,"set_scale9Grid") ) { return set_scale9Grid_dyn(); }
		if (HX_FIELD_EQ(inName,"get_scrollRect") ) { return get_scrollRect_dyn(); }
		if (HX_FIELD_EQ(inName,"set_scrollRect") ) { return set_scrollRect_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"__graphicsCache") ) { return __graphicsCache; }
		if (HX_FIELD_EQ(inName,"__dispatchEvent") ) { return __dispatchEvent_dyn(); }
		if (HX_FIELD_EQ(inName,"__drawToSurface") ) { return __drawToSurface_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"opaqueBackground") ) { return get_opaqueBackground(); }
		if (HX_FIELD_EQ(inName,"__getPixelBounds") ) { return __getPixelBounds_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"get_cacheAsBitmap") ) { return get_cacheAsBitmap_dyn(); }
		if (HX_FIELD_EQ(inName,"set_cacheAsBitmap") ) { return set_cacheAsBitmap_dyn(); }
		if (HX_FIELD_EQ(inName,"get_pixelSnapping") ) { return get_pixelSnapping_dyn(); }
		if (HX_FIELD_EQ(inName,"set_pixelSnapping") ) { return set_pixelSnapping_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"__getColorTransform") ) { return __getColorTransform_dyn(); }
		if (HX_FIELD_EQ(inName,"__setColorTransform") ) { return __setColorTransform_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"get_opaqueBackground") ) { return get_opaqueBackground_dyn(); }
		if (HX_FIELD_EQ(inName,"set_opaqueBackground") ) { return set_opaqueBackground_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"pedanticBitmapCaching") ) { return get_pedanticBitmapCaching(); }
		if (HX_FIELD_EQ(inName,"__asInteractiveObject") ) { return __asInteractiveObject_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"__getObjectsUnderPoint") ) { return __getObjectsUnderPoint_dyn(); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"__getConcatenatedMatrix") ) { return __getConcatenatedMatrix_dyn(); }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"lime_display_object_get_x") ) { return lime_display_object_get_x; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_x") ) { return lime_display_object_set_x; }
		if (HX_FIELD_EQ(inName,"lime_display_object_get_y") ) { return lime_display_object_get_y; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_y") ) { return lime_display_object_set_y; }
		if (HX_FIELD_EQ(inName,"lime_display_object_get_z") ) { return lime_display_object_get_z; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_z") ) { return lime_display_object_set_z; }
		if (HX_FIELD_EQ(inName,"get_pedanticBitmapCaching") ) { return get_pedanticBitmapCaching_dyn(); }
		if (HX_FIELD_EQ(inName,"set_pedanticBitmapCaching") ) { return set_pedanticBitmapCaching_dyn(); }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"lime_create_display_object") ) { return lime_create_display_object; }
		if (HX_FIELD_EQ(inName,"lime_display_object_get_id") ) { return lime_display_object_get_id; }
		if (HX_FIELD_EQ(inName,"lime_display_object_get_bg") ) { return lime_display_object_get_bg; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_bg") ) { return lime_display_object_set_bg; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"__getInteractiveObjectStack") ) { return __getInteractiveObjectStack_dyn(); }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"lime_display_object_get_name") ) { return lime_display_object_get_name; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_name") ) { return lime_display_object_set_name; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_mask") ) { return lime_display_object_set_mask; }
		break;
	case 29:
		if (HX_FIELD_EQ(inName,"lime_display_object_get_width") ) { return lime_display_object_get_width; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_width") ) { return lime_display_object_set_width; }
		if (HX_FIELD_EQ(inName,"lime_display_object_get_alpha") ) { return lime_display_object_get_alpha; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_alpha") ) { return lime_display_object_set_alpha; }
		break;
	case 30:
		if (HX_FIELD_EQ(inName,"lime_display_object_get_height") ) { return lime_display_object_get_height; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_height") ) { return lime_display_object_set_height; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_matrix") ) { return lime_display_object_set_matrix; }
		if (HX_FIELD_EQ(inName,"lime_display_object_get_matrix") ) { return lime_display_object_get_matrix; }
		if (HX_FIELD_EQ(inName,"lime_display_object_get_bounds") ) { return lime_display_object_get_bounds; }
		break;
	case 31:
		if (HX_FIELD_EQ(inName,"lime_display_object_get_scale_x") ) { return lime_display_object_get_scale_x; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_scale_x") ) { return lime_display_object_set_scale_x; }
		if (HX_FIELD_EQ(inName,"lime_display_object_get_scale_y") ) { return lime_display_object_get_scale_y; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_scale_y") ) { return lime_display_object_set_scale_y; }
		if (HX_FIELD_EQ(inName,"lime_display_object_get_mouse_x") ) { return lime_display_object_get_mouse_x; }
		if (HX_FIELD_EQ(inName,"lime_display_object_get_mouse_y") ) { return lime_display_object_get_mouse_y; }
		if (HX_FIELD_EQ(inName,"lime_display_object_get_visible") ) { return lime_display_object_get_visible; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_visible") ) { return lime_display_object_set_visible; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_filters") ) { return lime_display_object_set_filters; }
		if (HX_FIELD_EQ(inName,"__getConcatenatedColorTransform") ) { return __getConcatenatedColorTransform_dyn(); }
		break;
	case 32:
		if (HX_FIELD_EQ(inName,"lime_display_object_get_graphics") ) { return lime_display_object_get_graphics; }
		if (HX_FIELD_EQ(inName,"lime_display_object_get_rotation") ) { return lime_display_object_get_rotation; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_rotation") ) { return lime_display_object_set_rotation; }
		break;
	case 34:
		if (HX_FIELD_EQ(inName,"lime_display_object_get_blend_mode") ) { return lime_display_object_get_blend_mode; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_blend_mode") ) { return lime_display_object_set_blend_mode; }
		if (HX_FIELD_EQ(inName,"lime_display_object_hit_test_point") ) { return lime_display_object_hit_test_point; }
		break;
	case 35:
		if (HX_FIELD_EQ(inName,"lime_display_object_draw_to_surface") ) { return lime_display_object_draw_to_surface; }
		if (HX_FIELD_EQ(inName,"lime_display_object_global_to_local") ) { return lime_display_object_global_to_local; }
		if (HX_FIELD_EQ(inName,"lime_display_object_local_to_global") ) { return lime_display_object_local_to_global; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_scale9_grid") ) { return lime_display_object_set_scale9_grid; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_scroll_rect") ) { return lime_display_object_set_scroll_rect; }
		break;
	case 36:
		if (HX_FIELD_EQ(inName,"lime_display_object_get_pixel_bounds") ) { return lime_display_object_get_pixel_bounds; }
		break;
	case 38:
		if (HX_FIELD_EQ(inName,"lime_display_object_get_pixel_snapping") ) { return lime_display_object_get_pixel_snapping; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_pixel_snapping") ) { return lime_display_object_set_pixel_snapping; }
		break;
	case 39:
		if (HX_FIELD_EQ(inName,"lime_display_object_get_cache_as_bitmap") ) { return lime_display_object_get_cache_as_bitmap; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_cache_as_bitmap") ) { return lime_display_object_set_cache_as_bitmap; }
		if (HX_FIELD_EQ(inName,"lime_display_object_get_color_transform") ) { return lime_display_object_get_color_transform; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_color_transform") ) { return lime_display_object_set_color_transform; }
		break;
	case 47:
		if (HX_FIELD_EQ(inName,"lime_display_object_get_pedantic_bitmap_caching") ) { return lime_display_object_get_pedantic_bitmap_caching; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_pedantic_bitmap_caching") ) { return lime_display_object_set_pedantic_bitmap_caching; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic DisplayObject_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { return set_x(inValue); }
		if (HX_FIELD_EQ(inName,"y") ) { return set_y(inValue); }
		if (HX_FIELD_EQ(inName,"z") ) { return set_z(inValue); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"mask") ) { if (inCallProp) return set_mask(inValue);mask=inValue.Cast< ::openfl::_v2::display::DisplayObject >(); return inValue; }
		if (HX_FIELD_EQ(inName,"name") ) { return set_name(inValue); }
		if (HX_FIELD_EQ(inName,"root") ) { root=inValue.Cast< ::openfl::_v2::display::DisplayObject >(); return inValue; }
		if (HX_FIELD_EQ(inName,"__id") ) { __id=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"alpha") ) { return set_alpha(inValue); }
		if (HX_FIELD_EQ(inName,"stage") ) { stage=inValue.Cast< ::openfl::_v2::display::Stage >(); return inValue; }
		if (HX_FIELD_EQ(inName,"width") ) { return set_width(inValue); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"height") ) { return set_height(inValue); }
		if (HX_FIELD_EQ(inName,"mouseX") ) { mouseX=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mouseY") ) { mouseY=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"parent") ) { parent=inValue.Cast< ::openfl::_v2::display::DisplayObjectContainer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scaleX") ) { return set_scaleX(inValue); }
		if (HX_FIELD_EQ(inName,"scaleY") ) { return set_scaleY(inValue); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"filters") ) { return set_filters(inValue); }
		if (HX_FIELD_EQ(inName,"visible") ) { return set_visible(inValue); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"graphics") ) { graphics=inValue.Cast< ::openfl::_v2::display::Graphics >(); return inValue; }
		if (HX_FIELD_EQ(inName,"rotation") ) { return set_rotation(inValue); }
		if (HX_FIELD_EQ(inName,"__handle") ) { __handle=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"__parent") ) { __parent=inValue.Cast< ::openfl::_v2::display::DisplayObjectContainer >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"blendMode") ) { return set_blendMode(inValue); }
		if (HX_FIELD_EQ(inName,"transform") ) { return set_transform(inValue); }
		if (HX_FIELD_EQ(inName,"__filters") ) { __filters=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"loaderInfo") ) { loaderInfo=inValue.Cast< ::openfl::_v2::display::LoaderInfo >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scale9Grid") ) { return set_scale9Grid(inValue); }
		if (HX_FIELD_EQ(inName,"scrollRect") ) { return set_scrollRect(inValue); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"__scale9Grid") ) { __scale9Grid=inValue.Cast< ::openfl::_v2::geom::Rectangle >(); return inValue; }
		if (HX_FIELD_EQ(inName,"__scrollRect") ) { __scrollRect=inValue.Cast< ::openfl::_v2::geom::Rectangle >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"cacheAsBitmap") ) { return set_cacheAsBitmap(inValue); }
		if (HX_FIELD_EQ(inName,"pixelSnapping") ) { return set_pixelSnapping(inValue); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"__graphicsCache") ) { __graphicsCache=inValue.Cast< ::openfl::_v2::display::Graphics >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"opaqueBackground") ) { return set_opaqueBackground(inValue); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"pedanticBitmapCaching") ) { return set_pedanticBitmapCaching(inValue); }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"lime_display_object_get_x") ) { lime_display_object_get_x=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_x") ) { lime_display_object_set_x=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_get_y") ) { lime_display_object_get_y=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_y") ) { lime_display_object_set_y=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_get_z") ) { lime_display_object_get_z=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_z") ) { lime_display_object_set_z=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"lime_create_display_object") ) { lime_create_display_object=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_get_id") ) { lime_display_object_get_id=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_get_bg") ) { lime_display_object_get_bg=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_bg") ) { lime_display_object_set_bg=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"lime_display_object_get_name") ) { lime_display_object_get_name=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_name") ) { lime_display_object_set_name=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_mask") ) { lime_display_object_set_mask=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 29:
		if (HX_FIELD_EQ(inName,"lime_display_object_get_width") ) { lime_display_object_get_width=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_width") ) { lime_display_object_set_width=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_get_alpha") ) { lime_display_object_get_alpha=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_alpha") ) { lime_display_object_set_alpha=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 30:
		if (HX_FIELD_EQ(inName,"lime_display_object_get_height") ) { lime_display_object_get_height=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_height") ) { lime_display_object_set_height=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_matrix") ) { lime_display_object_set_matrix=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_get_matrix") ) { lime_display_object_get_matrix=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_get_bounds") ) { lime_display_object_get_bounds=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 31:
		if (HX_FIELD_EQ(inName,"lime_display_object_get_scale_x") ) { lime_display_object_get_scale_x=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_scale_x") ) { lime_display_object_set_scale_x=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_get_scale_y") ) { lime_display_object_get_scale_y=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_scale_y") ) { lime_display_object_set_scale_y=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_get_mouse_x") ) { lime_display_object_get_mouse_x=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_get_mouse_y") ) { lime_display_object_get_mouse_y=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_get_visible") ) { lime_display_object_get_visible=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_visible") ) { lime_display_object_set_visible=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_filters") ) { lime_display_object_set_filters=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 32:
		if (HX_FIELD_EQ(inName,"lime_display_object_get_graphics") ) { lime_display_object_get_graphics=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_get_rotation") ) { lime_display_object_get_rotation=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_rotation") ) { lime_display_object_set_rotation=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 34:
		if (HX_FIELD_EQ(inName,"lime_display_object_get_blend_mode") ) { lime_display_object_get_blend_mode=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_blend_mode") ) { lime_display_object_set_blend_mode=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_hit_test_point") ) { lime_display_object_hit_test_point=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 35:
		if (HX_FIELD_EQ(inName,"lime_display_object_draw_to_surface") ) { lime_display_object_draw_to_surface=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_global_to_local") ) { lime_display_object_global_to_local=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_local_to_global") ) { lime_display_object_local_to_global=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_scale9_grid") ) { lime_display_object_set_scale9_grid=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_scroll_rect") ) { lime_display_object_set_scroll_rect=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 36:
		if (HX_FIELD_EQ(inName,"lime_display_object_get_pixel_bounds") ) { lime_display_object_get_pixel_bounds=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 38:
		if (HX_FIELD_EQ(inName,"lime_display_object_get_pixel_snapping") ) { lime_display_object_get_pixel_snapping=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_pixel_snapping") ) { lime_display_object_set_pixel_snapping=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 39:
		if (HX_FIELD_EQ(inName,"lime_display_object_get_cache_as_bitmap") ) { lime_display_object_get_cache_as_bitmap=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_cache_as_bitmap") ) { lime_display_object_set_cache_as_bitmap=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_get_color_transform") ) { lime_display_object_get_color_transform=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_color_transform") ) { lime_display_object_set_color_transform=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 47:
		if (HX_FIELD_EQ(inName,"lime_display_object_get_pedantic_bitmap_caching") ) { lime_display_object_get_pedantic_bitmap_caching=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_pedantic_bitmap_caching") ) { lime_display_object_set_pedantic_bitmap_caching=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void DisplayObject_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("alpha"));
	outFields->push(HX_CSTRING("blendMode"));
	outFields->push(HX_CSTRING("cacheAsBitmap"));
	outFields->push(HX_CSTRING("filters"));
	outFields->push(HX_CSTRING("graphics"));
	outFields->push(HX_CSTRING("height"));
	outFields->push(HX_CSTRING("loaderInfo"));
	outFields->push(HX_CSTRING("mask"));
	outFields->push(HX_CSTRING("mouseX"));
	outFields->push(HX_CSTRING("mouseY"));
	outFields->push(HX_CSTRING("name"));
	outFields->push(HX_CSTRING("opaqueBackground"));
	outFields->push(HX_CSTRING("parent"));
	outFields->push(HX_CSTRING("pedanticBitmapCaching"));
	outFields->push(HX_CSTRING("pixelSnapping"));
	outFields->push(HX_CSTRING("root"));
	outFields->push(HX_CSTRING("rotation"));
	outFields->push(HX_CSTRING("scale9Grid"));
	outFields->push(HX_CSTRING("scaleX"));
	outFields->push(HX_CSTRING("scaleY"));
	outFields->push(HX_CSTRING("scrollRect"));
	outFields->push(HX_CSTRING("stage"));
	outFields->push(HX_CSTRING("transform"));
	outFields->push(HX_CSTRING("visible"));
	outFields->push(HX_CSTRING("width"));
	outFields->push(HX_CSTRING("x"));
	outFields->push(HX_CSTRING("y"));
	outFields->push(HX_CSTRING("z"));
	outFields->push(HX_CSTRING("__handle"));
	outFields->push(HX_CSTRING("__filters"));
	outFields->push(HX_CSTRING("__graphicsCache"));
	outFields->push(HX_CSTRING("__id"));
	outFields->push(HX_CSTRING("__parent"));
	outFields->push(HX_CSTRING("__scale9Grid"));
	outFields->push(HX_CSTRING("__scrollRect"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("lime_create_display_object"),
	HX_CSTRING("lime_display_object_get_graphics"),
	HX_CSTRING("lime_display_object_draw_to_surface"),
	HX_CSTRING("lime_display_object_get_id"),
	HX_CSTRING("lime_display_object_get_x"),
	HX_CSTRING("lime_display_object_set_x"),
	HX_CSTRING("lime_display_object_get_y"),
	HX_CSTRING("lime_display_object_set_y"),
	HX_CSTRING("lime_display_object_get_z"),
	HX_CSTRING("lime_display_object_set_z"),
	HX_CSTRING("lime_display_object_get_scale_x"),
	HX_CSTRING("lime_display_object_set_scale_x"),
	HX_CSTRING("lime_display_object_get_scale_y"),
	HX_CSTRING("lime_display_object_set_scale_y"),
	HX_CSTRING("lime_display_object_get_mouse_x"),
	HX_CSTRING("lime_display_object_get_mouse_y"),
	HX_CSTRING("lime_display_object_get_rotation"),
	HX_CSTRING("lime_display_object_set_rotation"),
	HX_CSTRING("lime_display_object_get_bg"),
	HX_CSTRING("lime_display_object_set_bg"),
	HX_CSTRING("lime_display_object_get_name"),
	HX_CSTRING("lime_display_object_set_name"),
	HX_CSTRING("lime_display_object_get_width"),
	HX_CSTRING("lime_display_object_set_width"),
	HX_CSTRING("lime_display_object_get_height"),
	HX_CSTRING("lime_display_object_set_height"),
	HX_CSTRING("lime_display_object_get_alpha"),
	HX_CSTRING("lime_display_object_set_alpha"),
	HX_CSTRING("lime_display_object_get_blend_mode"),
	HX_CSTRING("lime_display_object_set_blend_mode"),
	HX_CSTRING("lime_display_object_get_cache_as_bitmap"),
	HX_CSTRING("lime_display_object_set_cache_as_bitmap"),
	HX_CSTRING("lime_display_object_get_pedantic_bitmap_caching"),
	HX_CSTRING("lime_display_object_set_pedantic_bitmap_caching"),
	HX_CSTRING("lime_display_object_get_pixel_snapping"),
	HX_CSTRING("lime_display_object_set_pixel_snapping"),
	HX_CSTRING("lime_display_object_get_visible"),
	HX_CSTRING("lime_display_object_set_visible"),
	HX_CSTRING("lime_display_object_set_filters"),
	HX_CSTRING("lime_display_object_global_to_local"),
	HX_CSTRING("lime_display_object_local_to_global"),
	HX_CSTRING("lime_display_object_set_scale9_grid"),
	HX_CSTRING("lime_display_object_set_scroll_rect"),
	HX_CSTRING("lime_display_object_set_mask"),
	HX_CSTRING("lime_display_object_set_matrix"),
	HX_CSTRING("lime_display_object_get_matrix"),
	HX_CSTRING("lime_display_object_get_color_transform"),
	HX_CSTRING("lime_display_object_set_color_transform"),
	HX_CSTRING("lime_display_object_get_pixel_bounds"),
	HX_CSTRING("lime_display_object_get_bounds"),
	HX_CSTRING("lime_display_object_hit_test_point"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::openfl::_v2::display::Graphics*/ ,(int)offsetof(DisplayObject_obj,graphics),HX_CSTRING("graphics")},
	{hx::fsObject /*::openfl::_v2::display::LoaderInfo*/ ,(int)offsetof(DisplayObject_obj,loaderInfo),HX_CSTRING("loaderInfo")},
	{hx::fsObject /*::openfl::_v2::display::DisplayObject*/ ,(int)offsetof(DisplayObject_obj,mask),HX_CSTRING("mask")},
	{hx::fsFloat,(int)offsetof(DisplayObject_obj,mouseX),HX_CSTRING("mouseX")},
	{hx::fsFloat,(int)offsetof(DisplayObject_obj,mouseY),HX_CSTRING("mouseY")},
	{hx::fsObject /*::openfl::_v2::display::DisplayObjectContainer*/ ,(int)offsetof(DisplayObject_obj,parent),HX_CSTRING("parent")},
	{hx::fsObject /*::openfl::_v2::display::DisplayObject*/ ,(int)offsetof(DisplayObject_obj,root),HX_CSTRING("root")},
	{hx::fsObject /*::openfl::_v2::display::Stage*/ ,(int)offsetof(DisplayObject_obj,stage),HX_CSTRING("stage")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(DisplayObject_obj,__handle),HX_CSTRING("__handle")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(DisplayObject_obj,__filters),HX_CSTRING("__filters")},
	{hx::fsObject /*::openfl::_v2::display::Graphics*/ ,(int)offsetof(DisplayObject_obj,__graphicsCache),HX_CSTRING("__graphicsCache")},
	{hx::fsInt,(int)offsetof(DisplayObject_obj,__id),HX_CSTRING("__id")},
	{hx::fsObject /*::openfl::_v2::display::DisplayObjectContainer*/ ,(int)offsetof(DisplayObject_obj,__parent),HX_CSTRING("__parent")},
	{hx::fsObject /*::openfl::_v2::geom::Rectangle*/ ,(int)offsetof(DisplayObject_obj,__scale9Grid),HX_CSTRING("__scale9Grid")},
	{hx::fsObject /*::openfl::_v2::geom::Rectangle*/ ,(int)offsetof(DisplayObject_obj,__scrollRect),HX_CSTRING("__scrollRect")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("graphics"),
	HX_CSTRING("loaderInfo"),
	HX_CSTRING("mask"),
	HX_CSTRING("mouseX"),
	HX_CSTRING("mouseY"),
	HX_CSTRING("parent"),
	HX_CSTRING("root"),
	HX_CSTRING("stage"),
	HX_CSTRING("__handle"),
	HX_CSTRING("__filters"),
	HX_CSTRING("__graphicsCache"),
	HX_CSTRING("__id"),
	HX_CSTRING("__parent"),
	HX_CSTRING("__scale9Grid"),
	HX_CSTRING("__scrollRect"),
	HX_CSTRING("dispatchEvent"),
	HX_CSTRING("getBounds"),
	HX_CSTRING("getRect"),
	HX_CSTRING("globalToLocal"),
	HX_CSTRING("hitTestObject"),
	HX_CSTRING("hitTestPoint"),
	HX_CSTRING("localToGlobal"),
	HX_CSTRING("toString"),
	HX_CSTRING("__asInteractiveObject"),
	HX_CSTRING("__broadcast"),
	HX_CSTRING("__contains"),
	HX_CSTRING("__dispatchEvent"),
	HX_CSTRING("__drawToSurface"),
	HX_CSTRING("__findByID"),
	HX_CSTRING("__fireEvent"),
	HX_CSTRING("__getColorTransform"),
	HX_CSTRING("__getConcatenatedColorTransform"),
	HX_CSTRING("__getConcatenatedMatrix"),
	HX_CSTRING("__getInteractiveObjectStack"),
	HX_CSTRING("__getMatrix"),
	HX_CSTRING("__getObjectsUnderPoint"),
	HX_CSTRING("__getPixelBounds"),
	HX_CSTRING("__onAdded"),
	HX_CSTRING("__onRemoved"),
	HX_CSTRING("__setColorTransform"),
	HX_CSTRING("__setMatrix"),
	HX_CSTRING("__setParent"),
	HX_CSTRING("get_alpha"),
	HX_CSTRING("set_alpha"),
	HX_CSTRING("get_opaqueBackground"),
	HX_CSTRING("set_opaqueBackground"),
	HX_CSTRING("get_blendMode"),
	HX_CSTRING("set_blendMode"),
	HX_CSTRING("get_cacheAsBitmap"),
	HX_CSTRING("set_cacheAsBitmap"),
	HX_CSTRING("get_pedanticBitmapCaching"),
	HX_CSTRING("set_pedanticBitmapCaching"),
	HX_CSTRING("get_pixelSnapping"),
	HX_CSTRING("set_pixelSnapping"),
	HX_CSTRING("get_filters"),
	HX_CSTRING("set_filters"),
	HX_CSTRING("get_graphics"),
	HX_CSTRING("get_height"),
	HX_CSTRING("set_height"),
	HX_CSTRING("set_mask"),
	HX_CSTRING("get_mouseX"),
	HX_CSTRING("get_mouseY"),
	HX_CSTRING("get_name"),
	HX_CSTRING("set_name"),
	HX_CSTRING("get_parent"),
	HX_CSTRING("get_root"),
	HX_CSTRING("get_rotation"),
	HX_CSTRING("set_rotation"),
	HX_CSTRING("get_scale9Grid"),
	HX_CSTRING("set_scale9Grid"),
	HX_CSTRING("get_scaleX"),
	HX_CSTRING("set_scaleX"),
	HX_CSTRING("get_scaleY"),
	HX_CSTRING("set_scaleY"),
	HX_CSTRING("get_scrollRect"),
	HX_CSTRING("set_scrollRect"),
	HX_CSTRING("get_stage"),
	HX_CSTRING("get_transform"),
	HX_CSTRING("set_transform"),
	HX_CSTRING("get_visible"),
	HX_CSTRING("set_visible"),
	HX_CSTRING("get_width"),
	HX_CSTRING("set_width"),
	HX_CSTRING("get_x"),
	HX_CSTRING("set_x"),
	HX_CSTRING("get_y"),
	HX_CSTRING("set_y"),
	HX_CSTRING("get_z"),
	HX_CSTRING("set_z"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(DisplayObject_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_create_display_object,"lime_create_display_object");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_graphics,"lime_display_object_get_graphics");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_draw_to_surface,"lime_display_object_draw_to_surface");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_id,"lime_display_object_get_id");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_x,"lime_display_object_get_x");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_x,"lime_display_object_set_x");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_y,"lime_display_object_get_y");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_y,"lime_display_object_set_y");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_z,"lime_display_object_get_z");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_z,"lime_display_object_set_z");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_scale_x,"lime_display_object_get_scale_x");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_scale_x,"lime_display_object_set_scale_x");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_scale_y,"lime_display_object_get_scale_y");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_scale_y,"lime_display_object_set_scale_y");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_mouse_x,"lime_display_object_get_mouse_x");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_mouse_y,"lime_display_object_get_mouse_y");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_rotation,"lime_display_object_get_rotation");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_rotation,"lime_display_object_set_rotation");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_bg,"lime_display_object_get_bg");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_bg,"lime_display_object_set_bg");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_name,"lime_display_object_get_name");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_name,"lime_display_object_set_name");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_width,"lime_display_object_get_width");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_width,"lime_display_object_set_width");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_height,"lime_display_object_get_height");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_height,"lime_display_object_set_height");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_alpha,"lime_display_object_get_alpha");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_alpha,"lime_display_object_set_alpha");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_blend_mode,"lime_display_object_get_blend_mode");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_blend_mode,"lime_display_object_set_blend_mode");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_cache_as_bitmap,"lime_display_object_get_cache_as_bitmap");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_cache_as_bitmap,"lime_display_object_set_cache_as_bitmap");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_pedantic_bitmap_caching,"lime_display_object_get_pedantic_bitmap_caching");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_pedantic_bitmap_caching,"lime_display_object_set_pedantic_bitmap_caching");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_pixel_snapping,"lime_display_object_get_pixel_snapping");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_pixel_snapping,"lime_display_object_set_pixel_snapping");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_visible,"lime_display_object_get_visible");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_visible,"lime_display_object_set_visible");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_filters,"lime_display_object_set_filters");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_global_to_local,"lime_display_object_global_to_local");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_local_to_global,"lime_display_object_local_to_global");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_scale9_grid,"lime_display_object_set_scale9_grid");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_scroll_rect,"lime_display_object_set_scroll_rect");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_mask,"lime_display_object_set_mask");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_matrix,"lime_display_object_set_matrix");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_matrix,"lime_display_object_get_matrix");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_color_transform,"lime_display_object_get_color_transform");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_color_transform,"lime_display_object_set_color_transform");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_pixel_bounds,"lime_display_object_get_pixel_bounds");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_bounds,"lime_display_object_get_bounds");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_hit_test_point,"lime_display_object_hit_test_point");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_create_display_object,"lime_create_display_object");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_graphics,"lime_display_object_get_graphics");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_draw_to_surface,"lime_display_object_draw_to_surface");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_id,"lime_display_object_get_id");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_x,"lime_display_object_get_x");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_x,"lime_display_object_set_x");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_y,"lime_display_object_get_y");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_y,"lime_display_object_set_y");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_z,"lime_display_object_get_z");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_z,"lime_display_object_set_z");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_scale_x,"lime_display_object_get_scale_x");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_scale_x,"lime_display_object_set_scale_x");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_scale_y,"lime_display_object_get_scale_y");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_scale_y,"lime_display_object_set_scale_y");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_mouse_x,"lime_display_object_get_mouse_x");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_mouse_y,"lime_display_object_get_mouse_y");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_rotation,"lime_display_object_get_rotation");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_rotation,"lime_display_object_set_rotation");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_bg,"lime_display_object_get_bg");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_bg,"lime_display_object_set_bg");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_name,"lime_display_object_get_name");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_name,"lime_display_object_set_name");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_width,"lime_display_object_get_width");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_width,"lime_display_object_set_width");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_height,"lime_display_object_get_height");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_height,"lime_display_object_set_height");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_alpha,"lime_display_object_get_alpha");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_alpha,"lime_display_object_set_alpha");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_blend_mode,"lime_display_object_get_blend_mode");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_blend_mode,"lime_display_object_set_blend_mode");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_cache_as_bitmap,"lime_display_object_get_cache_as_bitmap");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_cache_as_bitmap,"lime_display_object_set_cache_as_bitmap");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_pedantic_bitmap_caching,"lime_display_object_get_pedantic_bitmap_caching");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_pedantic_bitmap_caching,"lime_display_object_set_pedantic_bitmap_caching");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_pixel_snapping,"lime_display_object_get_pixel_snapping");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_pixel_snapping,"lime_display_object_set_pixel_snapping");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_visible,"lime_display_object_get_visible");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_visible,"lime_display_object_set_visible");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_filters,"lime_display_object_set_filters");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_global_to_local,"lime_display_object_global_to_local");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_local_to_global,"lime_display_object_local_to_global");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_scale9_grid,"lime_display_object_set_scale9_grid");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_scroll_rect,"lime_display_object_set_scroll_rect");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_mask,"lime_display_object_set_mask");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_matrix,"lime_display_object_set_matrix");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_matrix,"lime_display_object_get_matrix");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_color_transform,"lime_display_object_get_color_transform");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_color_transform,"lime_display_object_set_color_transform");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_pixel_bounds,"lime_display_object_get_pixel_bounds");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_bounds,"lime_display_object_get_bounds");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_hit_test_point,"lime_display_object_hit_test_point");
};

#endif

Class DisplayObject_obj::__mClass;

void DisplayObject_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("openfl._v2.display.DisplayObject"), hx::TCanCast< DisplayObject_obj> ,sStaticFields,sMemberFields,
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

void DisplayObject_obj::__boot()
{
	lime_create_display_object= ::openfl::_v2::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_create_display_object"),(int)0);
	lime_display_object_get_graphics= ::openfl::_v2::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_get_graphics"),(int)1);
	lime_display_object_draw_to_surface= ::openfl::_v2::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_draw_to_surface"),(int)-1);
	lime_display_object_get_id= ::openfl::_v2::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_get_id"),(int)1);
	lime_display_object_get_x= ::openfl::_v2::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_get_x"),(int)1);
	lime_display_object_set_x= ::openfl::_v2::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_set_x"),(int)2);
	lime_display_object_get_y= ::openfl::_v2::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_get_y"),(int)1);
	lime_display_object_set_y= ::openfl::_v2::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_set_y"),(int)2);
	lime_display_object_get_z= ::openfl::_v2::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_get_z"),(int)1);
	lime_display_object_set_z= ::openfl::_v2::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_set_z"),(int)2);
	lime_display_object_get_scale_x= ::openfl::_v2::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_get_scale_x"),(int)1);
	lime_display_object_set_scale_x= ::openfl::_v2::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_set_scale_x"),(int)2);
	lime_display_object_get_scale_y= ::openfl::_v2::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_get_scale_y"),(int)1);
	lime_display_object_set_scale_y= ::openfl::_v2::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_set_scale_y"),(int)2);
	lime_display_object_get_mouse_x= ::openfl::_v2::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_get_mouse_x"),(int)1);
	lime_display_object_get_mouse_y= ::openfl::_v2::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_get_mouse_y"),(int)1);
	lime_display_object_get_rotation= ::openfl::_v2::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_get_rotation"),(int)1);
	lime_display_object_set_rotation= ::openfl::_v2::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_set_rotation"),(int)2);
	lime_display_object_get_bg= ::openfl::_v2::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_get_bg"),(int)1);
	lime_display_object_set_bg= ::openfl::_v2::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_set_bg"),(int)2);
	lime_display_object_get_name= ::openfl::_v2::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_get_name"),(int)1);
	lime_display_object_set_name= ::openfl::_v2::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_set_name"),(int)2);
	lime_display_object_get_width= ::openfl::_v2::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_get_width"),(int)1);
	lime_display_object_set_width= ::openfl::_v2::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_set_width"),(int)2);
	lime_display_object_get_height= ::openfl::_v2::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_get_height"),(int)1);
	lime_display_object_set_height= ::openfl::_v2::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_set_height"),(int)2);
	lime_display_object_get_alpha= ::openfl::_v2::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_get_alpha"),(int)1);
	lime_display_object_set_alpha= ::openfl::_v2::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_set_alpha"),(int)2);
	lime_display_object_get_blend_mode= ::openfl::_v2::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_get_blend_mode"),(int)1);
	lime_display_object_set_blend_mode= ::openfl::_v2::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_set_blend_mode"),(int)2);
	lime_display_object_get_cache_as_bitmap= ::openfl::_v2::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_get_cache_as_bitmap"),(int)1);
	lime_display_object_set_cache_as_bitmap= ::openfl::_v2::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_set_cache_as_bitmap"),(int)2);
	lime_display_object_get_pedantic_bitmap_caching= ::openfl::_v2::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_get_pedantic_bitmap_caching"),(int)1);
	lime_display_object_set_pedantic_bitmap_caching= ::openfl::_v2::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_set_pedantic_bitmap_caching"),(int)2);
	lime_display_object_get_pixel_snapping= ::openfl::_v2::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_get_pixel_snapping"),(int)1);
	lime_display_object_set_pixel_snapping= ::openfl::_v2::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_set_pixel_snapping"),(int)2);
	lime_display_object_get_visible= ::openfl::_v2::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_get_visible"),(int)1);
	lime_display_object_set_visible= ::openfl::_v2::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_set_visible"),(int)2);
	lime_display_object_set_filters= ::openfl::_v2::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_set_filters"),(int)2);
	lime_display_object_global_to_local= ::openfl::_v2::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_global_to_local"),(int)2);
	lime_display_object_local_to_global= ::openfl::_v2::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_local_to_global"),(int)2);
	lime_display_object_set_scale9_grid= ::openfl::_v2::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_set_scale9_grid"),(int)2);
	lime_display_object_set_scroll_rect= ::openfl::_v2::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_set_scroll_rect"),(int)2);
	lime_display_object_set_mask= ::openfl::_v2::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_set_mask"),(int)2);
	lime_display_object_set_matrix= ::openfl::_v2::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_set_matrix"),(int)2);
	lime_display_object_get_matrix= ::openfl::_v2::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_get_matrix"),(int)3);
	lime_display_object_get_color_transform= ::openfl::_v2::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_get_color_transform"),(int)3);
	lime_display_object_set_color_transform= ::openfl::_v2::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_set_color_transform"),(int)2);
	lime_display_object_get_pixel_bounds= ::openfl::_v2::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_get_pixel_bounds"),(int)2);
	lime_display_object_get_bounds= ::openfl::_v2::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_get_bounds"),(int)4);
	lime_display_object_hit_test_point= ::openfl::_v2::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_hit_test_point"),(int)5);
}

} // end namespace openfl
} // end namespace _v2
} // end namespace display
