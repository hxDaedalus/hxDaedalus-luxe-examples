#include <hxcpp.h>

#ifndef INCLUDED_hxDaedalus_data_math_NodeData
#include <hxDaedalus/data/math/NodeData.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_math_Point2D
#include <hxDaedalus/data/math/Point2D.h>
#endif
namespace hxDaedalus{
namespace data{
namespace math{

Void NodeData_obj::__construct()
{
HX_STACK_FRAME("hxDaedalus.data.math.NodeData","new",0x914f1e79,"hxDaedalus.data.math.NodeData.new","hxDaedalus/data/math/NodeData.hx",8,0xfd079d16)
HX_STACK_THIS(this)
{
}
;
	return null();
}

//NodeData_obj::~NodeData_obj() { }

Dynamic NodeData_obj::__CreateEmpty() { return  new NodeData_obj; }
hx::ObjectPtr< NodeData_obj > NodeData_obj::__new()
{  hx::ObjectPtr< NodeData_obj > result = new NodeData_obj();
	result->__construct();
	return result;}

Dynamic NodeData_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< NodeData_obj > result = new NodeData_obj();
	result->__construct();
	return result;}


NodeData_obj::NodeData_obj()
{
}

void NodeData_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(NodeData);
	HX_MARK_MEMBER_NAME(index,"index");
	HX_MARK_MEMBER_NAME(point,"point");
	HX_MARK_END_CLASS();
}

void NodeData_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(index,"index");
	HX_VISIT_MEMBER_NAME(point,"point");
}

Dynamic NodeData_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"index") ) { return index; }
		if (HX_FIELD_EQ(inName,"point") ) { return point; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic NodeData_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"index") ) { index=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"point") ) { point=inValue.Cast< ::hxDaedalus::data::math::Point2D >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void NodeData_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("index"));
	outFields->push(HX_CSTRING("point"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(NodeData_obj,index),HX_CSTRING("index")},
	{hx::fsObject /*::hxDaedalus::data::math::Point2D*/ ,(int)offsetof(NodeData_obj,point),HX_CSTRING("point")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("index"),
	HX_CSTRING("point"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(NodeData_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(NodeData_obj::__mClass,"__mClass");
};

#endif

Class NodeData_obj::__mClass;

void NodeData_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDaedalus.data.math.NodeData"), hx::TCanCast< NodeData_obj> ,sStaticFields,sMemberFields,
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

void NodeData_obj::__boot()
{
}

} // end namespace hxDaedalus
} // end namespace data
} // end namespace math
