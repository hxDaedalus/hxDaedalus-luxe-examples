#include <hxcpp.h>

#ifndef INCLUDED_hxDaedalus_data_ConstraintSegment
#include <hxDaedalus/data/ConstraintSegment.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_ConstraintShape
#include <hxDaedalus/data/ConstraintShape.h>
#endif
namespace hxDaedalus{
namespace data{

Void ConstraintShape_obj::__construct()
{
HX_STACK_FRAME("hxDaedalus.data.ConstraintShape","new",0x89073b4b,"hxDaedalus.data.ConstraintShape.new","hxDaedalus/data/ConstraintShape.hx",10,0x529eeae5)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(11)
	this->_id = ::hxDaedalus::data::ConstraintShape_obj::INC;
	HX_STACK_LINE(12)
	(::hxDaedalus::data::ConstraintShape_obj::INC)++;
	HX_STACK_LINE(13)
	Array< ::Dynamic > _g = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(13)
	this->segments = _g;
}
;
	return null();
}

//ConstraintShape_obj::~ConstraintShape_obj() { }

Dynamic ConstraintShape_obj::__CreateEmpty() { return  new ConstraintShape_obj; }
hx::ObjectPtr< ConstraintShape_obj > ConstraintShape_obj::__new()
{  hx::ObjectPtr< ConstraintShape_obj > result = new ConstraintShape_obj();
	result->__construct();
	return result;}

Dynamic ConstraintShape_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ConstraintShape_obj > result = new ConstraintShape_obj();
	result->__construct();
	return result;}

int ConstraintShape_obj::get_id( ){
	HX_STACK_FRAME("hxDaedalus.data.ConstraintShape","get_id",0xf84fed19,"hxDaedalus.data.ConstraintShape.get_id","hxDaedalus/data/ConstraintShape.hx",17,0x529eeae5)
	HX_STACK_THIS(this)
	HX_STACK_LINE(17)
	return this->_id;
}


HX_DEFINE_DYNAMIC_FUNC0(ConstraintShape_obj,get_id,return )

Void ConstraintShape_obj::dispose( ){
{
		HX_STACK_FRAME("hxDaedalus.data.ConstraintShape","dispose",0xe2273d0a,"hxDaedalus.data.ConstraintShape.dispose","hxDaedalus/data/ConstraintShape.hx",20,0x529eeae5)
		HX_STACK_THIS(this)
		HX_STACK_LINE(21)
		while((true)){
			HX_STACK_LINE(21)
			if ((!(((this->segments->length > (int)0))))){
				HX_STACK_LINE(21)
				break;
			}
			HX_STACK_LINE(21)
			this->segments->pop().StaticCast< ::hxDaedalus::data::ConstraintSegment >()->dispose();
		}
		HX_STACK_LINE(22)
		this->segments = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ConstraintShape_obj,dispose,(void))

int ConstraintShape_obj::INC;


ConstraintShape_obj::ConstraintShape_obj()
{
}

void ConstraintShape_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ConstraintShape);
	HX_MARK_MEMBER_NAME(segments,"segments");
	HX_MARK_MEMBER_NAME(_id,"_id");
	HX_MARK_END_CLASS();
}

void ConstraintShape_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(segments,"segments");
	HX_VISIT_MEMBER_NAME(_id,"_id");
}

Dynamic ConstraintShape_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { return get_id(); }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"INC") ) { return INC; }
		if (HX_FIELD_EQ(inName,"_id") ) { return _id; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"get_id") ) { return get_id_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"segments") ) { return segments; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ConstraintShape_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"INC") ) { INC=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_id") ) { _id=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"segments") ) { segments=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ConstraintShape_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("id"));
	outFields->push(HX_CSTRING("segments"));
	outFields->push(HX_CSTRING("_id"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("INC"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(ConstraintShape_obj,segments),HX_CSTRING("segments")},
	{hx::fsInt,(int)offsetof(ConstraintShape_obj,_id),HX_CSTRING("_id")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("segments"),
	HX_CSTRING("_id"),
	HX_CSTRING("get_id"),
	HX_CSTRING("dispose"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ConstraintShape_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(ConstraintShape_obj::INC,"INC");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ConstraintShape_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(ConstraintShape_obj::INC,"INC");
};

#endif

Class ConstraintShape_obj::__mClass;

void ConstraintShape_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDaedalus.data.ConstraintShape"), hx::TCanCast< ConstraintShape_obj> ,sStaticFields,sMemberFields,
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

void ConstraintShape_obj::__boot()
{
	INC= (int)0;
}

} // end namespace hxDaedalus
} // end namespace data
