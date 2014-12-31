#include <hxcpp.h>

#ifndef INCLUDED_hxDaedalus_data_math_EdgeData
#include <hxDaedalus/data/math/EdgeData.h>
#endif
namespace hxDaedalus{
namespace data{
namespace math{

Void EdgeData_obj::__construct()
{
HX_STACK_FRAME("hxDaedalus.data.math.EdgeData","new",0xf8e50fb4,"hxDaedalus.data.math.EdgeData.new","hxDaedalus/data/math/EdgeData.hx",8,0xaad6ec3b)
HX_STACK_THIS(this)
{
}
;
	return null();
}

//EdgeData_obj::~EdgeData_obj() { }

Dynamic EdgeData_obj::__CreateEmpty() { return  new EdgeData_obj; }
hx::ObjectPtr< EdgeData_obj > EdgeData_obj::__new()
{  hx::ObjectPtr< EdgeData_obj > result = new EdgeData_obj();
	result->__construct();
	return result;}

Dynamic EdgeData_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< EdgeData_obj > result = new EdgeData_obj();
	result->__construct();
	return result;}


EdgeData_obj::EdgeData_obj()
{
}

Dynamic EdgeData_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { return length; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"nodesCount") ) { return nodesCount; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"sumDistancesSquared") ) { return sumDistancesSquared; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic EdgeData_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { length=inValue.Cast< Float >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"nodesCount") ) { nodesCount=inValue.Cast< int >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"sumDistancesSquared") ) { sumDistancesSquared=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void EdgeData_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("sumDistancesSquared"));
	outFields->push(HX_CSTRING("length"));
	outFields->push(HX_CSTRING("nodesCount"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsFloat,(int)offsetof(EdgeData_obj,sumDistancesSquared),HX_CSTRING("sumDistancesSquared")},
	{hx::fsFloat,(int)offsetof(EdgeData_obj,length),HX_CSTRING("length")},
	{hx::fsInt,(int)offsetof(EdgeData_obj,nodesCount),HX_CSTRING("nodesCount")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("sumDistancesSquared"),
	HX_CSTRING("length"),
	HX_CSTRING("nodesCount"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(EdgeData_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(EdgeData_obj::__mClass,"__mClass");
};

#endif

Class EdgeData_obj::__mClass;

void EdgeData_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDaedalus.data.math.EdgeData"), hx::TCanCast< EdgeData_obj> ,sStaticFields,sMemberFields,
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

void EdgeData_obj::__boot()
{
}

} // end namespace hxDaedalus
} // end namespace data
} // end namespace math
