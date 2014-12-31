#include <hxcpp.h>

#ifndef INCLUDED_hxDaedalus_debug_Debug
#include <hxDaedalus/debug/Debug.h>
#endif
namespace hxDaedalus{
namespace debug{

Void Debug_obj::__construct()
{
	return null();
}

//Debug_obj::~Debug_obj() { }

Dynamic Debug_obj::__CreateEmpty() { return  new Debug_obj; }
hx::ObjectPtr< Debug_obj > Debug_obj::__new()
{  hx::ObjectPtr< Debug_obj > result = new Debug_obj();
	result->__construct();
	return result;}

Dynamic Debug_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Debug_obj > result = new Debug_obj();
	result->__construct();
	return result;}

Void Debug_obj::assertTrue( bool cond,::String message,Dynamic pos){
{
		HX_STACK_FRAME("hxDaedalus.debug.Debug","assertTrue",0x447b2f03,"hxDaedalus.debug.Debug.assertTrue","hxDaedalus/debug/Debug.hx",37,0x6d40b6a1)
		HX_STACK_ARG(cond,"cond")
		HX_STACK_ARG(message,"message")
		HX_STACK_ARG(pos,"pos")
		HX_STACK_LINE(37)
		return null();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Debug_obj,assertTrue,(void))

Void Debug_obj::assertFalse( bool cond,::String message,Dynamic pos){
{
		HX_STACK_FRAME("hxDaedalus.debug.Debug","assertFalse",0x8c6e6c4e,"hxDaedalus.debug.Debug.assertFalse","hxDaedalus/debug/Debug.hx",41,0x6d40b6a1)
		HX_STACK_ARG(cond,"cond")
		HX_STACK_ARG(message,"message")
		HX_STACK_ARG(pos,"pos")
		HX_STACK_LINE(41)
		return null();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Debug_obj,assertFalse,(void))

Void Debug_obj::assertEquals( Dynamic expected,Dynamic actual,::String message,Dynamic pos){
{
		HX_STACK_FRAME("hxDaedalus.debug.Debug","assertEquals",0x2a238d34,"hxDaedalus.debug.Debug.assertEquals","hxDaedalus/debug/Debug.hx",45,0x6d40b6a1)
		HX_STACK_ARG(expected,"expected")
		HX_STACK_ARG(actual,"actual")
		HX_STACK_ARG(message,"message")
		HX_STACK_ARG(pos,"pos")
		HX_STACK_LINE(45)
		return null();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Debug_obj,assertEquals,(void))

Void Debug_obj::trace( Dynamic value,Dynamic pos){
{
		HX_STACK_FRAME("hxDaedalus.debug.Debug","trace",0xa2fea716,"hxDaedalus.debug.Debug.trace","hxDaedalus/debug/Debug.hx",60,0x6d40b6a1)
		HX_STACK_ARG(value,"value")
		HX_STACK_ARG(pos,"pos")
		HX_STACK_LINE(60)
		return null();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Debug_obj,trace,(void))


Debug_obj::Debug_obj()
{
}

Dynamic Debug_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"trace") ) { return trace_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"assertTrue") ) { return assertTrue_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"assertFalse") ) { return assertFalse_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"assertEquals") ) { return assertEquals_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Debug_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void Debug_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("assertTrue"),
	HX_CSTRING("assertFalse"),
	HX_CSTRING("assertEquals"),
	HX_CSTRING("trace"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Debug_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Debug_obj::__mClass,"__mClass");
};

#endif

Class Debug_obj::__mClass;

void Debug_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDaedalus.debug.Debug"), hx::TCanCast< Debug_obj> ,sStaticFields,sMemberFields,
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

void Debug_obj::__boot()
{
}

} // end namespace hxDaedalus
} // end namespace debug
