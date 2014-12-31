#include <hxcpp.h>

#ifndef INCLUDED_hxDaedalus_data_math_Matrix2D
#include <hxDaedalus/data/math/Matrix2D.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_math_Point2D
#include <hxDaedalus/data/math/Point2D.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace hxDaedalus{
namespace data{
namespace math{

Void Point2D_obj::__construct(hx::Null< Float >  __o_x_,hx::Null< Float >  __o_y_)
{
HX_STACK_FRAME("hxDaedalus.data.math.Point2D","new",0x53bf1c39,"hxDaedalus.data.math.Point2D.new","hxDaedalus/data/math/Point2D.hx",7,0x70eb0838)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_x_,"x_")
HX_STACK_ARG(__o_y_,"y_")
Float x_ = __o_x_.Default(0);
Float y_ = __o_y_.Default(0);
{
	HX_STACK_LINE(8)
	this->x = x_;
	HX_STACK_LINE(9)
	this->y = y_;
}
;
	return null();
}

//Point2D_obj::~Point2D_obj() { }

Dynamic Point2D_obj::__CreateEmpty() { return  new Point2D_obj; }
hx::ObjectPtr< Point2D_obj > Point2D_obj::__new(hx::Null< Float >  __o_x_,hx::Null< Float >  __o_y_)
{  hx::ObjectPtr< Point2D_obj > result = new Point2D_obj();
	result->__construct(__o_x_,__o_y_);
	return result;}

Dynamic Point2D_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Point2D_obj > result = new Point2D_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void Point2D_obj::transform( ::hxDaedalus::data::math::Matrix2D matrix){
{
		HX_STACK_FRAME("hxDaedalus.data.math.Point2D","transform",0x84ba6205,"hxDaedalus.data.math.Point2D.transform","hxDaedalus/data/math/Point2D.hx",13,0x70eb0838)
		HX_STACK_THIS(this)
		HX_STACK_ARG(matrix,"matrix")
		HX_STACK_LINE(13)
		matrix->tranform(hx::ObjectPtr<OBJ_>(this));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Point2D_obj,transform,(void))

Void Point2D_obj::setXY( Float x_,Float y_){
{
		HX_STACK_FRAME("hxDaedalus.data.math.Point2D","setXY",0xf7e8493c,"hxDaedalus.data.math.Point2D.setXY","hxDaedalus/data/math/Point2D.hx",16,0x70eb0838)
		HX_STACK_THIS(this)
		HX_STACK_ARG(x_,"x_")
		HX_STACK_ARG(y_,"y_")
		HX_STACK_LINE(17)
		this->x = x_;
		HX_STACK_LINE(18)
		this->y = y_;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Point2D_obj,setXY,(void))

::hxDaedalus::data::math::Point2D Point2D_obj::clone( ){
	HX_STACK_FRAME("hxDaedalus.data.math.Point2D","clone",0xc61bc776,"hxDaedalus.data.math.Point2D.clone","hxDaedalus/data/math/Point2D.hx",22,0x70eb0838)
	HX_STACK_THIS(this)
	HX_STACK_LINE(22)
	return ::hxDaedalus::data::math::Point2D_obj::__new(this->x,this->y);
}


HX_DEFINE_DYNAMIC_FUNC0(Point2D_obj,clone,return )

Void Point2D_obj::substract( ::hxDaedalus::data::math::Point2D p){
{
		HX_STACK_FRAME("hxDaedalus.data.math.Point2D","substract",0x22090b5a,"hxDaedalus.data.math.Point2D.substract","hxDaedalus/data/math/Point2D.hx",25,0x70eb0838)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p,"p")
		HX_STACK_LINE(26)
		hx::SubEq(this->x,p->x);
		HX_STACK_LINE(27)
		hx::SubEq(this->y,p->y);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Point2D_obj,substract,(void))

Float Point2D_obj::get_length( ){
	HX_STACK_FRAME("hxDaedalus.data.math.Point2D","get_length",0x92b5d5f6,"hxDaedalus.data.math.Point2D.get_length","hxDaedalus/data/math/Point2D.hx",31,0x70eb0838)
	HX_STACK_THIS(this)
	HX_STACK_LINE(31)
	return ::Math_obj::sqrt(((this->x * this->x) + (this->y * this->y)));
}


HX_DEFINE_DYNAMIC_FUNC0(Point2D_obj,get_length,return )

Void Point2D_obj::normalize( ){
{
		HX_STACK_FRAME("hxDaedalus.data.math.Point2D","normalize",0xeac86c26,"hxDaedalus.data.math.Point2D.normalize","hxDaedalus/data/math/Point2D.hx",34,0x70eb0838)
		HX_STACK_THIS(this)
		HX_STACK_LINE(35)
		Float norm = this->get_length();		HX_STACK_VAR(norm,"norm");
		HX_STACK_LINE(36)
		this->x = (Float(this->x) / Float(norm));
		HX_STACK_LINE(37)
		this->y = (Float(this->y) / Float(norm));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Point2D_obj,normalize,(void))

Void Point2D_obj::scale( Float s){
{
		HX_STACK_FRAME("hxDaedalus.data.math.Point2D","scale",0xf68782a3,"hxDaedalus.data.math.Point2D.scale","hxDaedalus/data/math/Point2D.hx",40,0x70eb0838)
		HX_STACK_THIS(this)
		HX_STACK_ARG(s,"s")
		HX_STACK_LINE(41)
		this->x = (this->x * s);
		HX_STACK_LINE(42)
		this->y = (this->y * s);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Point2D_obj,scale,(void))

Float Point2D_obj::distanceTo( ::hxDaedalus::data::math::Point2D p){
	HX_STACK_FRAME("hxDaedalus.data.math.Point2D","distanceTo",0x8f13a557,"hxDaedalus.data.math.Point2D.distanceTo","hxDaedalus/data/math/Point2D.hx",45,0x70eb0838)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p,"p")
	HX_STACK_LINE(46)
	Float diffX = (this->x - p->x);		HX_STACK_VAR(diffX,"diffX");
	HX_STACK_LINE(47)
	Float diffY = (this->y - p->y);		HX_STACK_VAR(diffY,"diffY");
	HX_STACK_LINE(48)
	return ::Math_obj::sqrt(((diffX * diffX) + (diffY * diffY)));
}


HX_DEFINE_DYNAMIC_FUNC1(Point2D_obj,distanceTo,return )


Point2D_obj::Point2D_obj()
{
}

Dynamic Point2D_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { return x; }
		if (HX_FIELD_EQ(inName,"y") ) { return y; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"setXY") ) { return setXY_dyn(); }
		if (HX_FIELD_EQ(inName,"clone") ) { return clone_dyn(); }
		if (HX_FIELD_EQ(inName,"scale") ) { return scale_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { return get_length(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"transform") ) { return transform_dyn(); }
		if (HX_FIELD_EQ(inName,"substract") ) { return substract_dyn(); }
		if (HX_FIELD_EQ(inName,"normalize") ) { return normalize_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_length") ) { return get_length_dyn(); }
		if (HX_FIELD_EQ(inName,"distanceTo") ) { return distanceTo_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Point2D_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { x=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"y") ) { y=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Point2D_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("length"));
	outFields->push(HX_CSTRING("x"));
	outFields->push(HX_CSTRING("y"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsFloat,(int)offsetof(Point2D_obj,x),HX_CSTRING("x")},
	{hx::fsFloat,(int)offsetof(Point2D_obj,y),HX_CSTRING("y")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("x"),
	HX_CSTRING("y"),
	HX_CSTRING("transform"),
	HX_CSTRING("setXY"),
	HX_CSTRING("clone"),
	HX_CSTRING("substract"),
	HX_CSTRING("get_length"),
	HX_CSTRING("normalize"),
	HX_CSTRING("scale"),
	HX_CSTRING("distanceTo"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Point2D_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Point2D_obj::__mClass,"__mClass");
};

#endif

Class Point2D_obj::__mClass;

void Point2D_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDaedalus.data.math.Point2D"), hx::TCanCast< Point2D_obj> ,sStaticFields,sMemberFields,
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

void Point2D_obj::__boot()
{
}

} // end namespace hxDaedalus
} // end namespace data
} // end namespace math
