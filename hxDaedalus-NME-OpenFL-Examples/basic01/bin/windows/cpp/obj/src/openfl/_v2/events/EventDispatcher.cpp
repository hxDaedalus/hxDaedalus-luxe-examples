#include <hxcpp.h>

#ifndef INCLUDED_IMap
#include <IMap.h>
#endif
#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
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
#ifndef INCLUDED_openfl__v2_events_Listener
#include <openfl/_v2/events/Listener.h>
#endif
#ifndef INCLUDED_openfl__v2_utils_WeakRef
#include <openfl/_v2/utils/WeakRef.h>
#endif
#ifndef INCLUDED_openfl_events_ErrorEvent
#include <openfl/events/ErrorEvent.h>
#endif
#ifndef INCLUDED_openfl_events_EventPhase
#include <openfl/events/EventPhase.h>
#endif
#ifndef INCLUDED_openfl_events_IOErrorEvent
#include <openfl/events/IOErrorEvent.h>
#endif
#ifndef INCLUDED_openfl_events_TextEvent
#include <openfl/events/TextEvent.h>
#endif
namespace openfl{
namespace _v2{
namespace events{

Void EventDispatcher_obj::__construct(::openfl::_v2::events::IEventDispatcher target)
{
HX_STACK_FRAME("openfl._v2.events.EventDispatcher","new",0x8d197b6f,"openfl._v2.events.EventDispatcher.new","openfl/_v2/events/EventDispatcher.hx",18,0x3e68c260)
HX_STACK_THIS(this)
HX_STACK_ARG(target,"target")
{
	HX_STACK_LINE(20)
	if (((target == null()))){
		HX_STACK_LINE(20)
		this->__target = hx::ObjectPtr<OBJ_>(this);
	}
	else{
		HX_STACK_LINE(20)
		this->__target = target;
	}
	HX_STACK_LINE(21)
	this->__eventMap = null();
}
;
	return null();
}

//EventDispatcher_obj::~EventDispatcher_obj() { }

Dynamic EventDispatcher_obj::__CreateEmpty() { return  new EventDispatcher_obj; }
hx::ObjectPtr< EventDispatcher_obj > EventDispatcher_obj::__new(::openfl::_v2::events::IEventDispatcher target)
{  hx::ObjectPtr< EventDispatcher_obj > result = new EventDispatcher_obj();
	result->__construct(target);
	return result;}

Dynamic EventDispatcher_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< EventDispatcher_obj > result = new EventDispatcher_obj();
	result->__construct(inArgs[0]);
	return result;}

hx::Object *EventDispatcher_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::openfl::_v2::events::IEventDispatcher_obj)) return operator ::openfl::_v2::events::IEventDispatcher_obj *();
	return super::__ToInterface(inType);
}

Void EventDispatcher_obj::addEventListener( ::String type,Dynamic listener,hx::Null< bool >  __o_useCapture,hx::Null< int >  __o_priority,hx::Null< bool >  __o_useWeakReference){
bool useCapture = __o_useCapture.Default(false);
int priority = __o_priority.Default(0);
bool useWeakReference = __o_useWeakReference.Default(false);
	HX_STACK_FRAME("openfl._v2.events.EventDispatcher","addEventListener",0x3c57635e,"openfl._v2.events.EventDispatcher.addEventListener","openfl/_v2/events/EventDispatcher.hx",26,0x3e68c260)
	HX_STACK_THIS(this)
	HX_STACK_ARG(type,"type")
	HX_STACK_ARG(listener,"listener")
	HX_STACK_ARG(useCapture,"useCapture")
	HX_STACK_ARG(priority,"priority")
	HX_STACK_ARG(useWeakReference,"useWeakReference")
{
		HX_STACK_LINE(28)
		if ((useWeakReference)){
			HX_STACK_LINE(30)
			::haxe::Log_obj::trace(HX_CSTRING("WARNING: Weak listener not supported for native (using hard reference)"),hx::SourceInfo(HX_CSTRING("EventDispatcher.hx"),30,HX_CSTRING("openfl._v2.events.EventDispatcher"),HX_CSTRING("addEventListener")));
			HX_STACK_LINE(31)
			useWeakReference = false;
		}
		HX_STACK_LINE(35)
		if (((this->__eventMap == null()))){
			HX_STACK_LINE(37)
			::haxe::ds::StringMap _g = ::haxe::ds::StringMap_obj::__new();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(37)
			this->__eventMap = _g;
		}
		HX_STACK_LINE(41)
		Array< ::Dynamic > list = this->__eventMap->get(type);		HX_STACK_VAR(list,"list");
		HX_STACK_LINE(43)
		if (((list == null()))){
			HX_STACK_LINE(45)
			Array< ::Dynamic > _g1 = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(45)
			list = _g1;
			HX_STACK_LINE(46)
			this->__eventMap->set(type,list);
		}
		HX_STACK_LINE(50)
		::openfl::_v2::utils::WeakRef _g2 = ::openfl::_v2::utils::WeakRef_obj::__new(listener,useWeakReference);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(50)
		::openfl::_v2::events::Listener _g3 = ::openfl::_v2::events::Listener_obj::__new(_g2,useCapture,priority);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(50)
		list->push(_g3);
		HX_STACK_LINE(51)
		list->sort(::openfl::_v2::events::EventDispatcher_obj::__sortEvents_dyn());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(EventDispatcher_obj,addEventListener,(void))

bool EventDispatcher_obj::dispatchEvent( ::openfl::_v2::events::Event event){
	HX_STACK_FRAME("openfl._v2.events.EventDispatcher","dispatchEvent",0xfa167acf,"openfl._v2.events.EventDispatcher.dispatchEvent","openfl/_v2/events/EventDispatcher.hx",56,0x3e68c260)
	HX_STACK_THIS(this)
	HX_STACK_ARG(event,"event")
	HX_STACK_LINE(58)
	if (((this->__eventMap == null()))){
		HX_STACK_LINE(60)
		return false;
	}
	HX_STACK_LINE(64)
	Dynamic _g = event->get_target();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(64)
	if (((_g == null()))){
		HX_STACK_LINE(66)
		event->set_target(this->__target);
	}
	HX_STACK_LINE(70)
	Dynamic _g1 = event->get_currentTarget();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(70)
	if (((_g1 == null()))){
		HX_STACK_LINE(72)
		event->set_currentTarget(this->__target);
	}
	HX_STACK_LINE(76)
	::String _g2 = event->get_type();		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(76)
	Array< ::Dynamic > list = this->__eventMap->get(_g2);		HX_STACK_VAR(list,"list");
	HX_STACK_LINE(77)
	::openfl::events::EventPhase _g3 = event->get_eventPhase();		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(77)
	bool capture = (_g3 == ::openfl::events::EventPhase_obj::CAPTURING_PHASE);		HX_STACK_VAR(capture,"capture");
	HX_STACK_LINE(79)
	if (((list != null()))){
		HX_STACK_LINE(81)
		int index = (int)0;		HX_STACK_VAR(index,"index");
		HX_STACK_LINE(82)
		int length = list->length;		HX_STACK_VAR(length,"length");
		HX_STACK_LINE(84)
		::openfl::_v2::events::Listener listItem;		HX_STACK_VAR(listItem,"listItem");
		HX_STACK_LINE(84)
		::openfl::_v2::events::Listener listener;		HX_STACK_VAR(listener,"listener");
		HX_STACK_LINE(86)
		while((true)){
			HX_STACK_LINE(86)
			if ((!(((index < length))))){
				HX_STACK_LINE(86)
				break;
			}
			HX_STACK_LINE(88)
			listItem = list->__get(index).StaticCast< ::openfl::_v2::events::Listener >();
			HX_STACK_LINE(89)
			::openfl::_v2::events::Listener _g5;		HX_STACK_VAR(_g5,"_g5");
			struct _Function_3_1{
				inline static bool Block( ::openfl::_v2::events::Listener &listItem){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","openfl/_v2/events/EventDispatcher.hx",89,0x3e68c260)
					{
						HX_STACK_LINE(89)
						Dynamic _g4 = listItem->listener->get();		HX_STACK_VAR(_g4,"_g4");
						HX_STACK_LINE(89)
						return (_g4 != null());
					}
					return null();
				}
			};
			HX_STACK_LINE(89)
			if (((  (((listItem != null()))) ? bool(_Function_3_1::Block(listItem)) : bool(false) ))){
				HX_STACK_LINE(89)
				_g5 = listItem;
			}
			else{
				HX_STACK_LINE(89)
				_g5 = null();
			}
			HX_STACK_LINE(89)
			listener = _g5;
			HX_STACK_LINE(91)
			if (((listener == null()))){
				HX_STACK_LINE(93)
				list->splice(index,(int)1);
				HX_STACK_LINE(94)
				(length)--;
			}
			else{
				HX_STACK_LINE(98)
				if (((listener->useCapture == capture))){
					HX_STACK_LINE(100)
					listener->dispatchEvent(event);
					HX_STACK_LINE(102)
					if ((event->__getIsCancelledNow())){
						HX_STACK_LINE(104)
						return true;
					}
				}
				HX_STACK_LINE(110)
				(index)++;
			}
		}
		HX_STACK_LINE(116)
		return true;
	}
	HX_STACK_LINE(120)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(EventDispatcher_obj,dispatchEvent,return )

bool EventDispatcher_obj::hasEventListener( ::String type){
	HX_STACK_FRAME("openfl._v2.events.EventDispatcher","hasEventListener",0x57dd8685,"openfl._v2.events.EventDispatcher.hasEventListener","openfl/_v2/events/EventDispatcher.hx",125,0x3e68c260)
	HX_STACK_THIS(this)
	HX_STACK_ARG(type,"type")
	HX_STACK_LINE(127)
	if (((this->__eventMap == null()))){
		HX_STACK_LINE(129)
		return false;
	}
	HX_STACK_LINE(133)
	Array< ::Dynamic > list = this->__eventMap->get(type);		HX_STACK_VAR(list,"list");
	HX_STACK_LINE(135)
	if (((list != null()))){
		HX_STACK_LINE(137)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(137)
		while((true)){
			HX_STACK_LINE(137)
			if ((!(((_g < list->length))))){
				HX_STACK_LINE(137)
				break;
			}
			HX_STACK_LINE(137)
			::openfl::_v2::events::Listener item = list->__get(_g).StaticCast< ::openfl::_v2::events::Listener >();		HX_STACK_VAR(item,"item");
			HX_STACK_LINE(137)
			++(_g);
			HX_STACK_LINE(139)
			if (((item != null()))){
				HX_STACK_LINE(139)
				return true;
			}
		}
	}
	HX_STACK_LINE(145)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(EventDispatcher_obj,hasEventListener,return )

Void EventDispatcher_obj::removeEventListener( ::String type,Dynamic listener,hx::Null< bool >  __o_capture){
bool capture = __o_capture.Default(false);
	HX_STACK_FRAME("openfl._v2.events.EventDispatcher","removeEventListener",0x05ca80d9,"openfl._v2.events.EventDispatcher.removeEventListener","openfl/_v2/events/EventDispatcher.hx",150,0x3e68c260)
	HX_STACK_THIS(this)
	HX_STACK_ARG(type,"type")
	HX_STACK_ARG(listener,"listener")
	HX_STACK_ARG(capture,"capture")
{
		HX_STACK_LINE(152)
		if (((  ((!(((this->__eventMap == null()))))) ? bool(!(this->__eventMap->exists(type))) : bool(true) ))){
			HX_STACK_LINE(154)
			return null();
		}
		HX_STACK_LINE(158)
		Array< ::Dynamic > list = this->__eventMap->get(type);		HX_STACK_VAR(list,"list");
		HX_STACK_LINE(159)
		::openfl::_v2::events::Listener item;		HX_STACK_VAR(item,"item");
		HX_STACK_LINE(161)
		{
			HX_STACK_LINE(161)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(161)
			int _g = list->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(161)
			while((true)){
				HX_STACK_LINE(161)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(161)
					break;
				}
				HX_STACK_LINE(161)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(163)
				if (((list->__get(i).StaticCast< ::openfl::_v2::events::Listener >() != null()))){
					HX_STACK_LINE(165)
					item = list->__get(i).StaticCast< ::openfl::_v2::events::Listener >();
					HX_STACK_LINE(166)
					if (((  (((item != null()))) ? bool(item->is(listener,capture)) : bool(false) ))){
						HX_STACK_LINE(168)
						list[i] = null();
						HX_STACK_LINE(169)
						return null();
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(EventDispatcher_obj,removeEventListener,(void))

::String EventDispatcher_obj::toString( ){
	HX_STACK_FRAME("openfl._v2.events.EventDispatcher","toString",0x4797af3d,"openfl._v2.events.EventDispatcher.toString","openfl/_v2/events/EventDispatcher.hx",180,0x3e68c260)
	HX_STACK_THIS(this)
	HX_STACK_LINE(182)
	::Class _g = ::Type_obj::getClass(hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(182)
	::String _g1 = ::Type_obj::getClassName(_g);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(182)
	::String _g2 = (HX_CSTRING("[object ") + _g1);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(182)
	return (_g2 + HX_CSTRING("]"));
}


HX_DEFINE_DYNAMIC_FUNC0(EventDispatcher_obj,toString,return )

bool EventDispatcher_obj::willTrigger( ::String type){
	HX_STACK_FRAME("openfl._v2.events.EventDispatcher","willTrigger",0xcf4dc655,"openfl._v2.events.EventDispatcher.willTrigger","openfl/_v2/events/EventDispatcher.hx",187,0x3e68c260)
	HX_STACK_THIS(this)
	HX_STACK_ARG(type,"type")
	HX_STACK_LINE(189)
	if (((this->__eventMap == null()))){
		HX_STACK_LINE(191)
		return false;
	}
	HX_STACK_LINE(195)
	return this->__eventMap->exists(type);
}


HX_DEFINE_DYNAMIC_FUNC1(EventDispatcher_obj,willTrigger,return )

Void EventDispatcher_obj::__dispatchCompleteEvent( ){
{
		HX_STACK_FRAME("openfl._v2.events.EventDispatcher","__dispatchCompleteEvent",0x9e9092f6,"openfl._v2.events.EventDispatcher.__dispatchCompleteEvent","openfl/_v2/events/EventDispatcher.hx",200,0x3e68c260)
		HX_STACK_THIS(this)
		HX_STACK_LINE(202)
		::openfl::_v2::events::Event _g = ::openfl::_v2::events::Event_obj::__new(::openfl::_v2::events::Event_obj::COMPLETE,null(),null());		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(202)
		this->dispatchEvent(_g);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(EventDispatcher_obj,__dispatchCompleteEvent,(void))

Void EventDispatcher_obj::__dispatchIOErrorEvent( ){
{
		HX_STACK_FRAME("openfl._v2.events.EventDispatcher","__dispatchIOErrorEvent",0x434e91e3,"openfl._v2.events.EventDispatcher.__dispatchIOErrorEvent","openfl/_v2/events/EventDispatcher.hx",207,0x3e68c260)
		HX_STACK_THIS(this)
		HX_STACK_LINE(209)
		::openfl::events::IOErrorEvent _g = ::openfl::events::IOErrorEvent_obj::__new(::openfl::events::IOErrorEvent_obj::IO_ERROR,null(),null(),null(),null());		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(209)
		this->dispatchEvent(_g);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(EventDispatcher_obj,__dispatchIOErrorEvent,(void))

int EventDispatcher_obj::__sortEvents( ::openfl::_v2::events::Listener a,::openfl::_v2::events::Listener b){
	HX_STACK_FRAME("openfl._v2.events.EventDispatcher","__sortEvents",0x60ed3b48,"openfl._v2.events.EventDispatcher.__sortEvents","openfl/_v2/events/EventDispatcher.hx",214,0x3e68c260)
	HX_STACK_ARG(a,"a")
	HX_STACK_ARG(b,"b")
	HX_STACK_LINE(216)
	if (((bool((a == null())) || bool((b == null()))))){
		HX_STACK_LINE(218)
		return (int)0;
	}
	HX_STACK_LINE(222)
	::openfl::_v2::events::Listener al = a;		HX_STACK_VAR(al,"al");
	HX_STACK_LINE(223)
	::openfl::_v2::events::Listener bl = b;		HX_STACK_VAR(bl,"bl");
	HX_STACK_LINE(225)
	if (((bool((al == null())) || bool((bl == null()))))){
		HX_STACK_LINE(227)
		return (int)0;
	}
	HX_STACK_LINE(231)
	if (((al->priority == bl->priority))){
		HX_STACK_LINE(233)
		if (((al->id == bl->id))){
			HX_STACK_LINE(233)
			return (int)0;
		}
		else{
			HX_STACK_LINE(233)
			if (((al->id > bl->id))){
				HX_STACK_LINE(233)
				return (int)1;
			}
			else{
				HX_STACK_LINE(233)
				return (int)-1;
			}
		}
	}
	else{
		HX_STACK_LINE(237)
		if (((al->priority < bl->priority))){
			HX_STACK_LINE(237)
			return (int)1;
		}
		else{
			HX_STACK_LINE(237)
			return (int)-1;
		}
	}
	HX_STACK_LINE(231)
	return (int)0;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(EventDispatcher_obj,__sortEvents,return )


EventDispatcher_obj::EventDispatcher_obj()
{
}

void EventDispatcher_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(EventDispatcher);
	HX_MARK_MEMBER_NAME(__eventMap,"__eventMap");
	HX_MARK_MEMBER_NAME(__target,"__target");
	HX_MARK_END_CLASS();
}

void EventDispatcher_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(__eventMap,"__eventMap");
	HX_VISIT_MEMBER_NAME(__target,"__target");
}

Dynamic EventDispatcher_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"__target") ) { return __target; }
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"__eventMap") ) { return __eventMap; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"willTrigger") ) { return willTrigger_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"__sortEvents") ) { return __sortEvents_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"dispatchEvent") ) { return dispatchEvent_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"addEventListener") ) { return addEventListener_dyn(); }
		if (HX_FIELD_EQ(inName,"hasEventListener") ) { return hasEventListener_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"removeEventListener") ) { return removeEventListener_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"__dispatchIOErrorEvent") ) { return __dispatchIOErrorEvent_dyn(); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"__dispatchCompleteEvent") ) { return __dispatchCompleteEvent_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic EventDispatcher_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"__target") ) { __target=inValue.Cast< ::openfl::_v2::events::IEventDispatcher >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"__eventMap") ) { __eventMap=inValue.Cast< ::haxe::ds::StringMap >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void EventDispatcher_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("__eventMap"));
	outFields->push(HX_CSTRING("__target"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("__sortEvents"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxe::ds::StringMap*/ ,(int)offsetof(EventDispatcher_obj,__eventMap),HX_CSTRING("__eventMap")},
	{hx::fsObject /*::openfl::_v2::events::IEventDispatcher*/ ,(int)offsetof(EventDispatcher_obj,__target),HX_CSTRING("__target")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("__eventMap"),
	HX_CSTRING("__target"),
	HX_CSTRING("addEventListener"),
	HX_CSTRING("dispatchEvent"),
	HX_CSTRING("hasEventListener"),
	HX_CSTRING("removeEventListener"),
	HX_CSTRING("toString"),
	HX_CSTRING("willTrigger"),
	HX_CSTRING("__dispatchCompleteEvent"),
	HX_CSTRING("__dispatchIOErrorEvent"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(EventDispatcher_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(EventDispatcher_obj::__mClass,"__mClass");
};

#endif

Class EventDispatcher_obj::__mClass;

void EventDispatcher_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("openfl._v2.events.EventDispatcher"), hx::TCanCast< EventDispatcher_obj> ,sStaticFields,sMemberFields,
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

void EventDispatcher_obj::__boot()
{
}

} // end namespace openfl
} // end namespace _v2
} // end namespace events
