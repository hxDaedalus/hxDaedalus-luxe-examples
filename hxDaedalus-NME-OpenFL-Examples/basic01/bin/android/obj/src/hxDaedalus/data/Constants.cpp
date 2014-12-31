#include <hxcpp.h>

#ifndef INCLUDED_hxDaedalus_data_Constants
#include <hxDaedalus/data/Constants.h>
#endif
namespace hxDaedalus{
namespace data{

Void Constants_obj::__construct()
{
	return null();
}

//Constants_obj::~Constants_obj() { }

Dynamic Constants_obj::__CreateEmpty() { return  new Constants_obj; }
hx::ObjectPtr< Constants_obj > Constants_obj::__new()
{  hx::ObjectPtr< Constants_obj > result = new Constants_obj();
	result->__construct();
	return result;}

Dynamic Constants_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Constants_obj > result = new Constants_obj();
	result->__construct();
	return result;}

Float Constants_obj::EPSILON;

Float Constants_obj::EPSILON_SQUARED;


Constants_obj::Constants_obj()
{
}

Dynamic Constants_obj::__Field(const ::String &inName,bool inCallProp)
{
	return super::__Field(inName,inCallProp);
}

Dynamic Constants_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void Constants_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("EPSILON"),
	HX_CSTRING("EPSILON_SQUARED"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Constants_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Constants_obj::EPSILON,"EPSILON");
	HX_MARK_MEMBER_NAME(Constants_obj::EPSILON_SQUARED,"EPSILON_SQUARED");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Constants_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Constants_obj::EPSILON,"EPSILON");
	HX_VISIT_MEMBER_NAME(Constants_obj::EPSILON_SQUARED,"EPSILON_SQUARED");
};

#endif

Class Constants_obj::__mClass;

void Constants_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDaedalus.data.Constants"), hx::TCanCast< Constants_obj> ,sStaticFields,sMemberFields,
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

void Constants_obj::__boot()
{
	EPSILON= 0.01;
	EPSILON_SQUARED= 0.0001;
}

} // end namespace hxDaedalus
} // end namespace data
