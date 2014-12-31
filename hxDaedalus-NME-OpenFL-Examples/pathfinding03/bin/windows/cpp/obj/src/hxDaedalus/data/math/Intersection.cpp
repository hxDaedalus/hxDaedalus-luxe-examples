#include <hxcpp.h>

#ifndef INCLUDED_hxDaedalus_data_Edge
#include <hxDaedalus/data/Edge.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_Face
#include <hxDaedalus/data/Face.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_Vertex
#include <hxDaedalus/data/Vertex.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_math_Intersection
#include <hxDaedalus/data/math/Intersection.h>
#endif
namespace hxDaedalus{
namespace data{
namespace math{

::hxDaedalus::data::math::Intersection  Intersection_obj::EEdge(::hxDaedalus::data::Edge edge)
	{ return hx::CreateEnum< Intersection_obj >(HX_CSTRING("EEdge"),1,hx::DynamicArray(0,1).Add(edge)); }

::hxDaedalus::data::math::Intersection  Intersection_obj::EFace(::hxDaedalus::data::Face face)
	{ return hx::CreateEnum< Intersection_obj >(HX_CSTRING("EFace"),2,hx::DynamicArray(0,1).Add(face)); }

::hxDaedalus::data::math::Intersection Intersection_obj::ENull;

::hxDaedalus::data::math::Intersection  Intersection_obj::EVertex(::hxDaedalus::data::Vertex vertex)
	{ return hx::CreateEnum< Intersection_obj >(HX_CSTRING("EVertex"),0,hx::DynamicArray(0,1).Add(vertex)); }

HX_DEFINE_CREATE_ENUM(Intersection_obj)

int Intersection_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("EEdge")) return 1;
	if (inName==HX_CSTRING("EFace")) return 2;
	if (inName==HX_CSTRING("ENull")) return 3;
	if (inName==HX_CSTRING("EVertex")) return 0;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(Intersection_obj,EEdge,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(Intersection_obj,EFace,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(Intersection_obj,EVertex,return)

int Intersection_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("EEdge")) return 1;
	if (inName==HX_CSTRING("EFace")) return 1;
	if (inName==HX_CSTRING("ENull")) return 0;
	if (inName==HX_CSTRING("EVertex")) return 1;
	return super::__FindArgCount(inName);
}

Dynamic Intersection_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("EEdge")) return EEdge_dyn();
	if (inName==HX_CSTRING("EFace")) return EFace_dyn();
	if (inName==HX_CSTRING("ENull")) return ENull;
	if (inName==HX_CSTRING("EVertex")) return EVertex_dyn();
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("EVertex"),
	HX_CSTRING("EEdge"),
	HX_CSTRING("EFace"),
	HX_CSTRING("ENull"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Intersection_obj::ENull,"ENull");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Intersection_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Intersection_obj::ENull,"ENull");
};
#endif

static ::String sMemberFields[] = { ::String(null()) };
Class Intersection_obj::__mClass;

Dynamic __Create_Intersection_obj() { return new Intersection_obj; }

void Intersection_obj::__register()
{

hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDaedalus.data.math.Intersection"), hx::TCanCast< Intersection_obj >,sStaticFields,sMemberFields,
	&__Create_Intersection_obj, &__Create,
	&super::__SGetClass(), &CreateIntersection_obj, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatic
#endif
#ifdef HXCPP_SCRIPTABLE
    , 0
#endif
);
}

void Intersection_obj::__boot()
{
hx::Static(ENull) = hx::CreateEnum< Intersection_obj >(HX_CSTRING("ENull"),3);
}


} // end namespace hxDaedalus
} // end namespace data
} // end namespace math
