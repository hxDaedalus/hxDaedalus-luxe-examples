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
#ifndef INCLUDED_hxDaedalus_iterators_FromVertexToHoldingFaces
#include <hxDaedalus/iterators/FromVertexToHoldingFaces.h>
#endif
namespace hxDaedalus{
namespace iterators{

Void FromVertexToHoldingFaces_obj::__construct()
{
HX_STACK_FRAME("hxDaedalus.iterators.FromVertexToHoldingFaces","new",0xde8c3db0,"hxDaedalus.iterators.FromVertexToHoldingFaces.new","hxDaedalus/iterators/FromVertexToHoldingFaces.hx",11,0x95b51bbe)
HX_STACK_THIS(this)
{
}
;
	return null();
}

//FromVertexToHoldingFaces_obj::~FromVertexToHoldingFaces_obj() { }

Dynamic FromVertexToHoldingFaces_obj::__CreateEmpty() { return  new FromVertexToHoldingFaces_obj; }
hx::ObjectPtr< FromVertexToHoldingFaces_obj > FromVertexToHoldingFaces_obj::__new()
{  hx::ObjectPtr< FromVertexToHoldingFaces_obj > result = new FromVertexToHoldingFaces_obj();
	result->__construct();
	return result;}

Dynamic FromVertexToHoldingFaces_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FromVertexToHoldingFaces_obj > result = new FromVertexToHoldingFaces_obj();
	result->__construct();
	return result;}

::hxDaedalus::data::Vertex FromVertexToHoldingFaces_obj::set_fromVertex( ::hxDaedalus::data::Vertex value){
	HX_STACK_FRAME("hxDaedalus.iterators.FromVertexToHoldingFaces","set_fromVertex",0x64e845db,"hxDaedalus.iterators.FromVertexToHoldingFaces.set_fromVertex","hxDaedalus/iterators/FromVertexToHoldingFaces.hx",13,0x95b51bbe)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(14)
	this->_fromVertex = value;
	HX_STACK_LINE(15)
	::hxDaedalus::data::Edge _g = this->_fromVertex->get_edge();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(15)
	this->_nextEdge = _g;
	HX_STACK_LINE(16)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(FromVertexToHoldingFaces_obj,set_fromVertex,return )

::hxDaedalus::data::Face FromVertexToHoldingFaces_obj::next( ){
	HX_STACK_FRAME("hxDaedalus.iterators.FromVertexToHoldingFaces","next",0xdc29bda3,"hxDaedalus.iterators.FromVertexToHoldingFaces.next","hxDaedalus/iterators/FromVertexToHoldingFaces.hx",19,0x95b51bbe)
	HX_STACK_THIS(this)
	HX_STACK_LINE(20)
	if (((this->_nextEdge != null()))){
		HX_STACK_LINE(21)
		while((true)){
			HX_STACK_LINE(22)
			::hxDaedalus::data::Face _g = this->_nextEdge->get_leftFace();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(22)
			this->_resultFace = _g;
			HX_STACK_LINE(23)
			::hxDaedalus::data::Edge _g1 = this->_nextEdge->get_rotLeftEdge();		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(23)
			this->_nextEdge = _g1;
			HX_STACK_LINE(24)
			::hxDaedalus::data::Edge _g2 = this->_fromVertex->get_edge();		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(24)
			if (((this->_nextEdge == _g2))){
				HX_STACK_LINE(25)
				this->_nextEdge = null();
				HX_STACK_LINE(26)
				if ((!(this->_resultFace->get_isReal()))){
					HX_STACK_LINE(26)
					this->_resultFace = null();
				}
				HX_STACK_LINE(27)
				break;
			}
			HX_STACK_LINE(21)
			if ((!((!(this->_resultFace->get_isReal()))))){
				HX_STACK_LINE(21)
				break;
			}
		}
	}
	else{
		HX_STACK_LINE(31)
		this->_resultFace = null();
	}
	HX_STACK_LINE(33)
	return this->_resultFace;
}


HX_DEFINE_DYNAMIC_FUNC0(FromVertexToHoldingFaces_obj,next,return )


FromVertexToHoldingFaces_obj::FromVertexToHoldingFaces_obj()
{
}

void FromVertexToHoldingFaces_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FromVertexToHoldingFaces);
	HX_MARK_MEMBER_NAME(_fromVertex,"_fromVertex");
	HX_MARK_MEMBER_NAME(_nextEdge,"_nextEdge");
	HX_MARK_MEMBER_NAME(_resultFace,"_resultFace");
	HX_MARK_END_CLASS();
}

void FromVertexToHoldingFaces_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_fromVertex,"_fromVertex");
	HX_VISIT_MEMBER_NAME(_nextEdge,"_nextEdge");
	HX_VISIT_MEMBER_NAME(_resultFace,"_resultFace");
}

Dynamic FromVertexToHoldingFaces_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"next") ) { return next_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_nextEdge") ) { return _nextEdge; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_fromVertex") ) { return _fromVertex; }
		if (HX_FIELD_EQ(inName,"_resultFace") ) { return _resultFace; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"set_fromVertex") ) { return set_fromVertex_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FromVertexToHoldingFaces_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"_nextEdge") ) { _nextEdge=inValue.Cast< ::hxDaedalus::data::Edge >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"fromVertex") ) { return set_fromVertex(inValue); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_fromVertex") ) { _fromVertex=inValue.Cast< ::hxDaedalus::data::Vertex >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_resultFace") ) { _resultFace=inValue.Cast< ::hxDaedalus::data::Face >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FromVertexToHoldingFaces_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("fromVertex"));
	outFields->push(HX_CSTRING("_fromVertex"));
	outFields->push(HX_CSTRING("_nextEdge"));
	outFields->push(HX_CSTRING("_resultFace"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::hxDaedalus::data::Vertex*/ ,(int)offsetof(FromVertexToHoldingFaces_obj,_fromVertex),HX_CSTRING("_fromVertex")},
	{hx::fsObject /*::hxDaedalus::data::Edge*/ ,(int)offsetof(FromVertexToHoldingFaces_obj,_nextEdge),HX_CSTRING("_nextEdge")},
	{hx::fsObject /*::hxDaedalus::data::Face*/ ,(int)offsetof(FromVertexToHoldingFaces_obj,_resultFace),HX_CSTRING("_resultFace")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("_fromVertex"),
	HX_CSTRING("_nextEdge"),
	HX_CSTRING("_resultFace"),
	HX_CSTRING("set_fromVertex"),
	HX_CSTRING("next"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FromVertexToHoldingFaces_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FromVertexToHoldingFaces_obj::__mClass,"__mClass");
};

#endif

Class FromVertexToHoldingFaces_obj::__mClass;

void FromVertexToHoldingFaces_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDaedalus.iterators.FromVertexToHoldingFaces"), hx::TCanCast< FromVertexToHoldingFaces_obj> ,sStaticFields,sMemberFields,
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

void FromVertexToHoldingFaces_obj::__boot()
{
}

} // end namespace hxDaedalus
} // end namespace iterators
