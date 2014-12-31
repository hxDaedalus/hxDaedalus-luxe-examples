#include <hxcpp.h>

#ifndef INCLUDED_hxDaedalus_data_math_Geom2D
#include <hxDaedalus/data/math/Geom2D.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_math_ShapeSimplifier
#include <hxDaedalus/data/math/ShapeSimplifier.h>
#endif
namespace hxDaedalus{
namespace data{
namespace math{

Void ShapeSimplifier_obj::__construct()
{
	return null();
}

//ShapeSimplifier_obj::~ShapeSimplifier_obj() { }

Dynamic ShapeSimplifier_obj::__CreateEmpty() { return  new ShapeSimplifier_obj; }
hx::ObjectPtr< ShapeSimplifier_obj > ShapeSimplifier_obj::__new()
{  hx::ObjectPtr< ShapeSimplifier_obj > result = new ShapeSimplifier_obj();
	result->__construct();
	return result;}

Dynamic ShapeSimplifier_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ShapeSimplifier_obj > result = new ShapeSimplifier_obj();
	result->__construct();
	return result;}

Array< Float > ShapeSimplifier_obj::simplify( Array< Float > coords,hx::Null< Float >  __o_epsilon){
Float epsilon = __o_epsilon.Default(1);
	HX_STACK_FRAME("hxDaedalus.data.math.ShapeSimplifier","simplify",0xd3c3bceb,"hxDaedalus.data.math.ShapeSimplifier.simplify","hxDaedalus/data/math/ShapeSimplifier.hx",16,0x78b88f53)
	HX_STACK_ARG(coords,"coords")
	HX_STACK_ARG(epsilon,"epsilon")
{
		HX_STACK_LINE(17)
		int len = coords->length;		HX_STACK_VAR(len,"len");
		HX_STACK_LINE(20)
		if (((len <= (int)4))){
			HX_STACK_LINE(21)
			return Array_obj< Float >::__new()->concat(coords);
		}
		HX_STACK_LINE(24)
		Float firstPointX = coords->__get((int)0);		HX_STACK_VAR(firstPointX,"firstPointX");
		HX_STACK_LINE(25)
		Float firstPointY = coords->__get((int)1);		HX_STACK_VAR(firstPointY,"firstPointY");
		HX_STACK_LINE(26)
		Float lastPointX = coords->__get((len - (int)2));		HX_STACK_VAR(lastPointX,"lastPointX");
		HX_STACK_LINE(27)
		Float lastPointY = coords->__get((len - (int)1));		HX_STACK_VAR(lastPointY,"lastPointY");
		HX_STACK_LINE(29)
		int index = (int)-1;		HX_STACK_VAR(index,"index");
		HX_STACK_LINE(30)
		Float dist = 0.;		HX_STACK_VAR(dist,"dist");
		HX_STACK_LINE(31)
		{
			HX_STACK_LINE(31)
			int _g1 = (int)1;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(31)
			int _g = (int(len) >> int((int)1));		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(31)
			while((true)){
				HX_STACK_LINE(31)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(31)
					break;
				}
				HX_STACK_LINE(31)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(32)
				Float currDist = ::hxDaedalus::data::math::Geom2D_obj::distanceSquaredPointToSegment(coords->__get((int(i) << int((int)1))),coords->__get((((int(i) << int((int)1))) + (int)1)),firstPointX,firstPointY,lastPointX,lastPointY);		HX_STACK_VAR(currDist,"currDist");
				HX_STACK_LINE(33)
				if (((currDist > dist))){
					HX_STACK_LINE(34)
					dist = currDist;
					HX_STACK_LINE(35)
					index = i;
				}
			}
		}
		HX_STACK_LINE(39)
		if (((dist > (epsilon * epsilon)))){
			HX_STACK_LINE(41)
			Array< Float > l1 = coords->slice((int)0,(((int(index) << int((int)1))) + (int)2));		HX_STACK_VAR(l1,"l1");
			HX_STACK_LINE(42)
			Array< Float > l2 = coords->slice((int(index) << int((int)1)),null());		HX_STACK_VAR(l2,"l2");
			HX_STACK_LINE(43)
			Array< Float > r1 = ::hxDaedalus::data::math::ShapeSimplifier_obj::simplify(l1,epsilon);		HX_STACK_VAR(r1,"r1");
			HX_STACK_LINE(44)
			Array< Float > r2 = ::hxDaedalus::data::math::ShapeSimplifier_obj::simplify(l2,epsilon);		HX_STACK_VAR(r2,"r2");
			HX_STACK_LINE(46)
			Array< Float > rs = r1->slice((int)0,(r1->length - (int)2))->concat(r2);		HX_STACK_VAR(rs,"rs");
			HX_STACK_LINE(47)
			return rs;
		}
		else{
			HX_STACK_LINE(49)
			return Array_obj< Float >::__new().Add(firstPointX).Add(firstPointY).Add(lastPointX).Add(lastPointY);
		}
		HX_STACK_LINE(39)
		return null();
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(ShapeSimplifier_obj,simplify,return )


ShapeSimplifier_obj::ShapeSimplifier_obj()
{
}

Dynamic ShapeSimplifier_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"simplify") ) { return simplify_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ShapeSimplifier_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void ShapeSimplifier_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("simplify"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ShapeSimplifier_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ShapeSimplifier_obj::__mClass,"__mClass");
};

#endif

Class ShapeSimplifier_obj::__mClass;

void ShapeSimplifier_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDaedalus.data.math.ShapeSimplifier"), hx::TCanCast< ShapeSimplifier_obj> ,sStaticFields,sMemberFields,
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

void ShapeSimplifier_obj::__boot()
{
}

} // end namespace hxDaedalus
} // end namespace data
} // end namespace math
