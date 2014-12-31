#include <hxcpp.h>

#ifndef INCLUDED_hxDaedalus_ai_EntityAI
#include <hxDaedalus/ai/EntityAI.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_Object
#include <hxDaedalus/data/Object.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_math_Matrix2D
#include <hxDaedalus/data/math/Matrix2D.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace hxDaedalus{
namespace ai{

Void EntityAI_obj::__construct()
{
HX_STACK_FRAME("hxDaedalus.ai.EntityAI","new",0x0dd1688a,"hxDaedalus.ai.EntityAI.new","hxDaedalus/ai/EntityAI.hx",29,0xf8158386)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(30)
	this->_radius = (int)10;
	HX_STACK_LINE(31)
	Float _g = this->y = (int)0;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(31)
	this->x = _g;
	HX_STACK_LINE(32)
	this->dirNormX = (int)1;
	HX_STACK_LINE(33)
	this->dirNormY = (int)0;
	HX_STACK_LINE(34)
	this->angleFOV = (int)60;
}
;
	return null();
}

//EntityAI_obj::~EntityAI_obj() { }

Dynamic EntityAI_obj::__CreateEmpty() { return  new EntityAI_obj; }
hx::ObjectPtr< EntityAI_obj > EntityAI_obj::__new()
{  hx::ObjectPtr< EntityAI_obj > result = new EntityAI_obj();
	result->__construct();
	return result;}

Dynamic EntityAI_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< EntityAI_obj > result = new EntityAI_obj();
	result->__construct();
	return result;}

Void EntityAI_obj::buildApproximation( ){
{
		HX_STACK_FRAME("hxDaedalus.ai.EntityAI","buildApproximation",0xf63aaa7f,"hxDaedalus.ai.EntityAI.buildApproximation","hxDaedalus/ai/EntityAI.hx",37,0xf8158386)
		HX_STACK_THIS(this)
		HX_STACK_LINE(38)
		::hxDaedalus::data::Object _g = ::hxDaedalus::data::Object_obj::__new();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(38)
		this->_approximateObject = _g;
		HX_STACK_LINE(39)
		this->_approximateObject->get_matrix()->translate(this->x,this->y);
		HX_STACK_LINE(40)
		Array< Float > coordinates = Array_obj< Float >::__new();		HX_STACK_VAR(coordinates,"coordinates");
		HX_STACK_LINE(41)
		this->_approximateObject->set_coordinates(coordinates);
		HX_STACK_LINE(43)
		if (((this->_radius == (int)0))){
			HX_STACK_LINE(43)
			return null();
		}
		HX_STACK_LINE(45)
		{
			HX_STACK_LINE(45)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(45)
			while((true)){
				HX_STACK_LINE(45)
				if ((!(((_g1 < (int)6))))){
					HX_STACK_LINE(45)
					break;
				}
				HX_STACK_LINE(45)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(46)
				Float _g11 = ::Math_obj::cos((Float((((int)2 * ::Math_obj::PI) * i)) / Float((int)6)));		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(46)
				Float _g2 = (this->_radius * _g11);		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(46)
				coordinates->push(_g2);
				HX_STACK_LINE(47)
				Float _g3 = ::Math_obj::sin((Float((((int)2 * ::Math_obj::PI) * i)) / Float((int)6)));		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(47)
				Float _g4 = (this->_radius * _g3);		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(47)
				coordinates->push(_g4);
				HX_STACK_LINE(48)
				Float _g5 = ::Math_obj::cos((Float((((int)2 * ::Math_obj::PI) * ((i + (int)1)))) / Float((int)6)));		HX_STACK_VAR(_g5,"_g5");
				HX_STACK_LINE(48)
				Float _g6 = (this->_radius * _g5);		HX_STACK_VAR(_g6,"_g6");
				HX_STACK_LINE(48)
				coordinates->push(_g6);
				HX_STACK_LINE(49)
				Float _g7 = ::Math_obj::sin((Float((((int)2 * ::Math_obj::PI) * ((i + (int)1)))) / Float((int)6)));		HX_STACK_VAR(_g7,"_g7");
				HX_STACK_LINE(49)
				Float _g8 = (this->_radius * _g7);		HX_STACK_VAR(_g8,"_g8");
				HX_STACK_LINE(49)
				coordinates->push(_g8);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(EntityAI_obj,buildApproximation,(void))

::hxDaedalus::data::Object EntityAI_obj::get_approximateObject( ){
	HX_STACK_FRAME("hxDaedalus.ai.EntityAI","get_approximateObject",0x3f91a3b4,"hxDaedalus.ai.EntityAI.get_approximateObject","hxDaedalus/ai/EntityAI.hx",54,0xf8158386)
	HX_STACK_THIS(this)
	HX_STACK_LINE(55)
	this->_approximateObject->get_matrix()->identity();
	HX_STACK_LINE(56)
	this->_approximateObject->get_matrix()->translate(this->x,this->y);
	HX_STACK_LINE(57)
	return this->_approximateObject;
}


HX_DEFINE_DYNAMIC_FUNC0(EntityAI_obj,get_approximateObject,return )

Float EntityAI_obj::get_radius( ){
	HX_STACK_FRAME("hxDaedalus.ai.EntityAI","get_radius",0x43aa6131,"hxDaedalus.ai.EntityAI.get_radius","hxDaedalus/ai/EntityAI.hx",62,0xf8158386)
	HX_STACK_THIS(this)
	HX_STACK_LINE(62)
	return this->_radius;
}


HX_DEFINE_DYNAMIC_FUNC0(EntityAI_obj,get_radius,return )

Float EntityAI_obj::get_radiusSquared( ){
	HX_STACK_FRAME("hxDaedalus.ai.EntityAI","get_radiusSquared",0x3d9b47f6,"hxDaedalus.ai.EntityAI.get_radiusSquared","hxDaedalus/ai/EntityAI.hx",67,0xf8158386)
	HX_STACK_THIS(this)
	HX_STACK_LINE(67)
	return this->_radiusSquared;
}


HX_DEFINE_DYNAMIC_FUNC0(EntityAI_obj,get_radiusSquared,return )

Float EntityAI_obj::set_radius( Float value){
	HX_STACK_FRAME("hxDaedalus.ai.EntityAI","set_radius",0x4727ffa5,"hxDaedalus.ai.EntityAI.set_radius","hxDaedalus/ai/EntityAI.hx",71,0xf8158386)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(72)
	this->_radius = value;
	HX_STACK_LINE(73)
	this->_radiusSquared = (this->_radius * this->_radius);
	HX_STACK_LINE(74)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(EntityAI_obj,set_radius,return )

int EntityAI_obj::NUM_SEGMENTS;


EntityAI_obj::EntityAI_obj()
{
}

void EntityAI_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(EntityAI);
	HX_MARK_MEMBER_NAME(angleFOV,"angleFOV");
	HX_MARK_MEMBER_NAME(dirNormY,"dirNormY");
	HX_MARK_MEMBER_NAME(dirNormX,"dirNormX");
	HX_MARK_MEMBER_NAME(y,"y");
	HX_MARK_MEMBER_NAME(x,"x");
	HX_MARK_MEMBER_NAME(_radius,"_radius");
	HX_MARK_MEMBER_NAME(_radiusSquared,"_radiusSquared");
	HX_MARK_MEMBER_NAME(_x,"_x");
	HX_MARK_MEMBER_NAME(_y,"_y");
	HX_MARK_MEMBER_NAME(_dirNormX,"_dirNormX");
	HX_MARK_MEMBER_NAME(_dirNormY,"_dirNormY");
	HX_MARK_MEMBER_NAME(_angleFOV,"_angleFOV");
	HX_MARK_MEMBER_NAME(_approximateObject,"_approximateObject");
	HX_MARK_END_CLASS();
}

void EntityAI_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(angleFOV,"angleFOV");
	HX_VISIT_MEMBER_NAME(dirNormY,"dirNormY");
	HX_VISIT_MEMBER_NAME(dirNormX,"dirNormX");
	HX_VISIT_MEMBER_NAME(y,"y");
	HX_VISIT_MEMBER_NAME(x,"x");
	HX_VISIT_MEMBER_NAME(_radius,"_radius");
	HX_VISIT_MEMBER_NAME(_radiusSquared,"_radiusSquared");
	HX_VISIT_MEMBER_NAME(_x,"_x");
	HX_VISIT_MEMBER_NAME(_y,"_y");
	HX_VISIT_MEMBER_NAME(_dirNormX,"_dirNormX");
	HX_VISIT_MEMBER_NAME(_dirNormY,"_dirNormY");
	HX_VISIT_MEMBER_NAME(_angleFOV,"_angleFOV");
	HX_VISIT_MEMBER_NAME(_approximateObject,"_approximateObject");
}

Dynamic EntityAI_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"y") ) { return y; }
		if (HX_FIELD_EQ(inName,"x") ) { return x; }
		break;
	case 2:
		if (HX_FIELD_EQ(inName,"_x") ) { return _x; }
		if (HX_FIELD_EQ(inName,"_y") ) { return _y; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"radius") ) { return get_radius(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_radius") ) { return _radius; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"angleFOV") ) { return angleFOV; }
		if (HX_FIELD_EQ(inName,"dirNormY") ) { return dirNormY; }
		if (HX_FIELD_EQ(inName,"dirNormX") ) { return dirNormX; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_dirNormX") ) { return _dirNormX; }
		if (HX_FIELD_EQ(inName,"_dirNormY") ) { return _dirNormY; }
		if (HX_FIELD_EQ(inName,"_angleFOV") ) { return _angleFOV; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_radius") ) { return get_radius_dyn(); }
		if (HX_FIELD_EQ(inName,"set_radius") ) { return set_radius_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"radiusSquared") ) { return get_radiusSquared(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_radiusSquared") ) { return _radiusSquared; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"approximateObject") ) { return get_approximateObject(); }
		if (HX_FIELD_EQ(inName,"get_radiusSquared") ) { return get_radiusSquared_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"_approximateObject") ) { return _approximateObject; }
		if (HX_FIELD_EQ(inName,"buildApproximation") ) { return buildApproximation_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"get_approximateObject") ) { return get_approximateObject_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic EntityAI_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"y") ) { y=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"x") ) { x=inValue.Cast< Float >(); return inValue; }
		break;
	case 2:
		if (HX_FIELD_EQ(inName,"_x") ) { _x=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_y") ) { _y=inValue.Cast< Float >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"radius") ) { return set_radius(inValue); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_radius") ) { _radius=inValue.Cast< Float >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"angleFOV") ) { angleFOV=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"dirNormY") ) { dirNormY=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"dirNormX") ) { dirNormX=inValue.Cast< Float >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_dirNormX") ) { _dirNormX=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_dirNormY") ) { _dirNormY=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_angleFOV") ) { _angleFOV=inValue.Cast< Float >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_radiusSquared") ) { _radiusSquared=inValue.Cast< Float >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"_approximateObject") ) { _approximateObject=inValue.Cast< ::hxDaedalus::data::Object >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void EntityAI_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("approximateObject"));
	outFields->push(HX_CSTRING("angleFOV"));
	outFields->push(HX_CSTRING("dirNormY"));
	outFields->push(HX_CSTRING("dirNormX"));
	outFields->push(HX_CSTRING("y"));
	outFields->push(HX_CSTRING("x"));
	outFields->push(HX_CSTRING("radius"));
	outFields->push(HX_CSTRING("radiusSquared"));
	outFields->push(HX_CSTRING("_radius"));
	outFields->push(HX_CSTRING("_radiusSquared"));
	outFields->push(HX_CSTRING("_x"));
	outFields->push(HX_CSTRING("_y"));
	outFields->push(HX_CSTRING("_dirNormX"));
	outFields->push(HX_CSTRING("_dirNormY"));
	outFields->push(HX_CSTRING("_angleFOV"));
	outFields->push(HX_CSTRING("_approximateObject"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("NUM_SEGMENTS"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsFloat,(int)offsetof(EntityAI_obj,angleFOV),HX_CSTRING("angleFOV")},
	{hx::fsFloat,(int)offsetof(EntityAI_obj,dirNormY),HX_CSTRING("dirNormY")},
	{hx::fsFloat,(int)offsetof(EntityAI_obj,dirNormX),HX_CSTRING("dirNormX")},
	{hx::fsFloat,(int)offsetof(EntityAI_obj,y),HX_CSTRING("y")},
	{hx::fsFloat,(int)offsetof(EntityAI_obj,x),HX_CSTRING("x")},
	{hx::fsFloat,(int)offsetof(EntityAI_obj,_radius),HX_CSTRING("_radius")},
	{hx::fsFloat,(int)offsetof(EntityAI_obj,_radiusSquared),HX_CSTRING("_radiusSquared")},
	{hx::fsFloat,(int)offsetof(EntityAI_obj,_x),HX_CSTRING("_x")},
	{hx::fsFloat,(int)offsetof(EntityAI_obj,_y),HX_CSTRING("_y")},
	{hx::fsFloat,(int)offsetof(EntityAI_obj,_dirNormX),HX_CSTRING("_dirNormX")},
	{hx::fsFloat,(int)offsetof(EntityAI_obj,_dirNormY),HX_CSTRING("_dirNormY")},
	{hx::fsFloat,(int)offsetof(EntityAI_obj,_angleFOV),HX_CSTRING("_angleFOV")},
	{hx::fsObject /*::hxDaedalus::data::Object*/ ,(int)offsetof(EntityAI_obj,_approximateObject),HX_CSTRING("_approximateObject")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("angleFOV"),
	HX_CSTRING("dirNormY"),
	HX_CSTRING("dirNormX"),
	HX_CSTRING("y"),
	HX_CSTRING("x"),
	HX_CSTRING("_radius"),
	HX_CSTRING("_radiusSquared"),
	HX_CSTRING("_x"),
	HX_CSTRING("_y"),
	HX_CSTRING("_dirNormX"),
	HX_CSTRING("_dirNormY"),
	HX_CSTRING("_angleFOV"),
	HX_CSTRING("_approximateObject"),
	HX_CSTRING("buildApproximation"),
	HX_CSTRING("get_approximateObject"),
	HX_CSTRING("get_radius"),
	HX_CSTRING("get_radiusSquared"),
	HX_CSTRING("set_radius"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(EntityAI_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(EntityAI_obj::NUM_SEGMENTS,"NUM_SEGMENTS");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(EntityAI_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(EntityAI_obj::NUM_SEGMENTS,"NUM_SEGMENTS");
};

#endif

Class EntityAI_obj::__mClass;

void EntityAI_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDaedalus.ai.EntityAI"), hx::TCanCast< EntityAI_obj> ,sStaticFields,sMemberFields,
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

void EntityAI_obj::__boot()
{
	NUM_SEGMENTS= (int)6;
}

} // end namespace hxDaedalus
} // end namespace ai
