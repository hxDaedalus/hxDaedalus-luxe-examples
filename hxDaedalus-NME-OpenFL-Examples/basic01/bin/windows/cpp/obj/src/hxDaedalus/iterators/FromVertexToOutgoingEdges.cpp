#include <hxcpp.h>

#ifndef INCLUDED_hxDaedalus_data_Edge
#include <hxDaedalus/data/Edge.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_Vertex
#include <hxDaedalus/data/Vertex.h>
#endif
#ifndef INCLUDED_hxDaedalus_iterators_FromVertexToOutgoingEdges
#include <hxDaedalus/iterators/FromVertexToOutgoingEdges.h>
#endif
namespace hxDaedalus{
namespace iterators{

Void FromVertexToOutgoingEdges_obj::__construct()
{
HX_STACK_FRAME("hxDaedalus.iterators.FromVertexToOutgoingEdges","new",0x26a49311,"hxDaedalus.iterators.FromVertexToOutgoingEdges.new","hxDaedalus/iterators/FromVertexToOutgoingEdges.hx",7,0x8b8da3c1)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(15)
	this->realEdgesOnly = true;
}
;
	return null();
}

//FromVertexToOutgoingEdges_obj::~FromVertexToOutgoingEdges_obj() { }

Dynamic FromVertexToOutgoingEdges_obj::__CreateEmpty() { return  new FromVertexToOutgoingEdges_obj; }
hx::ObjectPtr< FromVertexToOutgoingEdges_obj > FromVertexToOutgoingEdges_obj::__new()
{  hx::ObjectPtr< FromVertexToOutgoingEdges_obj > result = new FromVertexToOutgoingEdges_obj();
	result->__construct();
	return result;}

Dynamic FromVertexToOutgoingEdges_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FromVertexToOutgoingEdges_obj > result = new FromVertexToOutgoingEdges_obj();
	result->__construct();
	return result;}

::hxDaedalus::data::Vertex FromVertexToOutgoingEdges_obj::set_fromVertex( ::hxDaedalus::data::Vertex value){
	HX_STACK_FRAME("hxDaedalus.iterators.FromVertexToOutgoingEdges","set_fromVertex",0xdcbe9a1a,"hxDaedalus.iterators.FromVertexToOutgoingEdges.set_fromVertex","hxDaedalus/iterators/FromVertexToOutgoingEdges.hx",24,0x8b8da3c1)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(25)
	this->_fromVertex = value;
	HX_STACK_LINE(26)
	::hxDaedalus::data::Edge _g = this->_fromVertex->get_edge();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(26)
	this->_nextEdge = _g;
	HX_STACK_LINE(27)
	while((true)){
		HX_STACK_LINE(27)
		if ((!(((  ((this->realEdgesOnly)) ? bool(!(this->_nextEdge->get_isReal())) : bool(false) ))))){
			HX_STACK_LINE(27)
			break;
		}
		HX_STACK_LINE(29)
		::hxDaedalus::data::Edge _g1 = this->_nextEdge->get_rotLeftEdge();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(29)
		this->_nextEdge = _g1;
	}
	HX_STACK_LINE(31)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(FromVertexToOutgoingEdges_obj,set_fromVertex,return )

::hxDaedalus::data::Edge FromVertexToOutgoingEdges_obj::next( ){
	HX_STACK_FRAME("hxDaedalus.iterators.FromVertexToOutgoingEdges","next",0xa95c1d22,"hxDaedalus.iterators.FromVertexToOutgoingEdges.next","hxDaedalus/iterators/FromVertexToOutgoingEdges.hx",37,0x8b8da3c1)
	HX_STACK_THIS(this)
	HX_STACK_LINE(38)
	if (((this->_nextEdge != null()))){
		HX_STACK_LINE(40)
		this->_resultEdge = this->_nextEdge;
		HX_STACK_LINE(41)
		while((true)){
			HX_STACK_LINE(43)
			::hxDaedalus::data::Edge _g = this->_nextEdge->get_rotLeftEdge();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(43)
			this->_nextEdge = _g;
			HX_STACK_LINE(44)
			::hxDaedalus::data::Edge _g1 = this->_fromVertex->get_edge();		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(44)
			if (((this->_nextEdge == _g1))){
				HX_STACK_LINE(46)
				this->_nextEdge = null();
				HX_STACK_LINE(47)
				break;
			}
			HX_STACK_LINE(41)
			if ((!(((  ((this->realEdgesOnly)) ? bool(!(this->_nextEdge->get_isReal())) : bool(false) ))))){
				HX_STACK_LINE(41)
				break;
			}
		}
	}
	else{
		HX_STACK_LINE(53)
		this->_resultEdge = null();
	}
	HX_STACK_LINE(56)
	return this->_resultEdge;
}


HX_DEFINE_DYNAMIC_FUNC0(FromVertexToOutgoingEdges_obj,next,return )


FromVertexToOutgoingEdges_obj::FromVertexToOutgoingEdges_obj()
{
}

void FromVertexToOutgoingEdges_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FromVertexToOutgoingEdges);
	HX_MARK_MEMBER_NAME(_fromVertex,"_fromVertex");
	HX_MARK_MEMBER_NAME(_nextEdge,"_nextEdge");
	HX_MARK_MEMBER_NAME(realEdgesOnly,"realEdgesOnly");
	HX_MARK_MEMBER_NAME(_resultEdge,"_resultEdge");
	HX_MARK_END_CLASS();
}

void FromVertexToOutgoingEdges_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_fromVertex,"_fromVertex");
	HX_VISIT_MEMBER_NAME(_nextEdge,"_nextEdge");
	HX_VISIT_MEMBER_NAME(realEdgesOnly,"realEdgesOnly");
	HX_VISIT_MEMBER_NAME(_resultEdge,"_resultEdge");
}

Dynamic FromVertexToOutgoingEdges_obj::__Field(const ::String &inName,bool inCallProp)
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
		if (HX_FIELD_EQ(inName,"_resultEdge") ) { return _resultEdge; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"realEdgesOnly") ) { return realEdgesOnly; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"set_fromVertex") ) { return set_fromVertex_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FromVertexToOutgoingEdges_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
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
		if (HX_FIELD_EQ(inName,"_resultEdge") ) { _resultEdge=inValue.Cast< ::hxDaedalus::data::Edge >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"realEdgesOnly") ) { realEdgesOnly=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FromVertexToOutgoingEdges_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("fromVertex"));
	outFields->push(HX_CSTRING("_fromVertex"));
	outFields->push(HX_CSTRING("_nextEdge"));
	outFields->push(HX_CSTRING("realEdgesOnly"));
	outFields->push(HX_CSTRING("_resultEdge"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::hxDaedalus::data::Vertex*/ ,(int)offsetof(FromVertexToOutgoingEdges_obj,_fromVertex),HX_CSTRING("_fromVertex")},
	{hx::fsObject /*::hxDaedalus::data::Edge*/ ,(int)offsetof(FromVertexToOutgoingEdges_obj,_nextEdge),HX_CSTRING("_nextEdge")},
	{hx::fsBool,(int)offsetof(FromVertexToOutgoingEdges_obj,realEdgesOnly),HX_CSTRING("realEdgesOnly")},
	{hx::fsObject /*::hxDaedalus::data::Edge*/ ,(int)offsetof(FromVertexToOutgoingEdges_obj,_resultEdge),HX_CSTRING("_resultEdge")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("_fromVertex"),
	HX_CSTRING("_nextEdge"),
	HX_CSTRING("realEdgesOnly"),
	HX_CSTRING("set_fromVertex"),
	HX_CSTRING("_resultEdge"),
	HX_CSTRING("next"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FromVertexToOutgoingEdges_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FromVertexToOutgoingEdges_obj::__mClass,"__mClass");
};

#endif

Class FromVertexToOutgoingEdges_obj::__mClass;

void FromVertexToOutgoingEdges_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDaedalus.iterators.FromVertexToOutgoingEdges"), hx::TCanCast< FromVertexToOutgoingEdges_obj> ,sStaticFields,sMemberFields,
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

void FromVertexToOutgoingEdges_obj::__boot()
{
}

} // end namespace hxDaedalus
} // end namespace iterators
