#include <hxcpp.h>

#ifndef INCLUDED_hxDaedalus_data_Edge
#include <hxDaedalus/data/Edge.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_Face
#include <hxDaedalus/data/Face.h>
#endif
#ifndef INCLUDED_hxDaedalus_iterators_FromFaceToInnerEdges
#include <hxDaedalus/iterators/FromFaceToInnerEdges.h>
#endif
namespace hxDaedalus{
namespace iterators{

Void FromFaceToInnerEdges_obj::__construct()
{
HX_STACK_FRAME("hxDaedalus.iterators.FromFaceToInnerEdges","new",0xb4451e96,"hxDaedalus.iterators.FromFaceToInnerEdges.new","hxDaedalus/iterators/FromFaceToInnerEdges.hx",10,0x6cbd0298)
HX_STACK_THIS(this)
{
}
;
	return null();
}

//FromFaceToInnerEdges_obj::~FromFaceToInnerEdges_obj() { }

Dynamic FromFaceToInnerEdges_obj::__CreateEmpty() { return  new FromFaceToInnerEdges_obj; }
hx::ObjectPtr< FromFaceToInnerEdges_obj > FromFaceToInnerEdges_obj::__new()
{  hx::ObjectPtr< FromFaceToInnerEdges_obj > result = new FromFaceToInnerEdges_obj();
	result->__construct();
	return result;}

Dynamic FromFaceToInnerEdges_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FromFaceToInnerEdges_obj > result = new FromFaceToInnerEdges_obj();
	result->__construct();
	return result;}

::hxDaedalus::data::Face FromFaceToInnerEdges_obj::set_fromFace( ::hxDaedalus::data::Face value){
	HX_STACK_FRAME("hxDaedalus.iterators.FromFaceToInnerEdges","set_fromFace",0x71be95ae,"hxDaedalus.iterators.FromFaceToInnerEdges.set_fromFace","hxDaedalus/iterators/FromFaceToInnerEdges.hx",12,0x6cbd0298)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(13)
	this->_fromFace = value;
	HX_STACK_LINE(14)
	::hxDaedalus::data::Edge _g = this->_fromFace->get_edge();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(14)
	this->_nextEdge = _g;
	HX_STACK_LINE(15)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(FromFaceToInnerEdges_obj,set_fromFace,return )

::hxDaedalus::data::Edge FromFaceToInnerEdges_obj::next( ){
	HX_STACK_FRAME("hxDaedalus.iterators.FromFaceToInnerEdges","next",0x0835a5fd,"hxDaedalus.iterators.FromFaceToInnerEdges.next","hxDaedalus/iterators/FromFaceToInnerEdges.hx",18,0x6cbd0298)
	HX_STACK_THIS(this)
	HX_STACK_LINE(19)
	if (((this->_nextEdge != null()))){
		HX_STACK_LINE(20)
		this->_resultEdge = this->_nextEdge;
		HX_STACK_LINE(21)
		::hxDaedalus::data::Edge _g = this->_nextEdge->get_nextLeftEdge();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(21)
		this->_nextEdge = _g;
		HX_STACK_LINE(22)
		::hxDaedalus::data::Edge _g1 = this->_fromFace->get_edge();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(22)
		if (((this->_nextEdge == _g1))){
			HX_STACK_LINE(22)
			this->_nextEdge = null();
		}
	}
	else{
		HX_STACK_LINE(24)
		this->_resultEdge = null();
	}
	HX_STACK_LINE(26)
	return this->_resultEdge;
}


HX_DEFINE_DYNAMIC_FUNC0(FromFaceToInnerEdges_obj,next,return )


FromFaceToInnerEdges_obj::FromFaceToInnerEdges_obj()
{
}

void FromFaceToInnerEdges_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FromFaceToInnerEdges);
	HX_MARK_MEMBER_NAME(_fromFace,"_fromFace");
	HX_MARK_MEMBER_NAME(_nextEdge,"_nextEdge");
	HX_MARK_MEMBER_NAME(_resultEdge,"_resultEdge");
	HX_MARK_END_CLASS();
}

void FromFaceToInnerEdges_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_fromFace,"_fromFace");
	HX_VISIT_MEMBER_NAME(_nextEdge,"_nextEdge");
	HX_VISIT_MEMBER_NAME(_resultEdge,"_resultEdge");
}

Dynamic FromFaceToInnerEdges_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"next") ) { return next_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_fromFace") ) { return _fromFace; }
		if (HX_FIELD_EQ(inName,"_nextEdge") ) { return _nextEdge; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_resultEdge") ) { return _resultEdge; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"set_fromFace") ) { return set_fromFace_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FromFaceToInnerEdges_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"fromFace") ) { return set_fromFace(inValue); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_fromFace") ) { _fromFace=inValue.Cast< ::hxDaedalus::data::Face >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_nextEdge") ) { _nextEdge=inValue.Cast< ::hxDaedalus::data::Edge >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_resultEdge") ) { _resultEdge=inValue.Cast< ::hxDaedalus::data::Edge >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FromFaceToInnerEdges_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("fromFace"));
	outFields->push(HX_CSTRING("_fromFace"));
	outFields->push(HX_CSTRING("_nextEdge"));
	outFields->push(HX_CSTRING("_resultEdge"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::hxDaedalus::data::Face*/ ,(int)offsetof(FromFaceToInnerEdges_obj,_fromFace),HX_CSTRING("_fromFace")},
	{hx::fsObject /*::hxDaedalus::data::Edge*/ ,(int)offsetof(FromFaceToInnerEdges_obj,_nextEdge),HX_CSTRING("_nextEdge")},
	{hx::fsObject /*::hxDaedalus::data::Edge*/ ,(int)offsetof(FromFaceToInnerEdges_obj,_resultEdge),HX_CSTRING("_resultEdge")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("_fromFace"),
	HX_CSTRING("_nextEdge"),
	HX_CSTRING("_resultEdge"),
	HX_CSTRING("set_fromFace"),
	HX_CSTRING("next"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FromFaceToInnerEdges_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FromFaceToInnerEdges_obj::__mClass,"__mClass");
};

#endif

Class FromFaceToInnerEdges_obj::__mClass;

void FromFaceToInnerEdges_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDaedalus.iterators.FromFaceToInnerEdges"), hx::TCanCast< FromFaceToInnerEdges_obj> ,sStaticFields,sMemberFields,
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

void FromFaceToInnerEdges_obj::__boot()
{
}

} // end namespace hxDaedalus
} // end namespace iterators
