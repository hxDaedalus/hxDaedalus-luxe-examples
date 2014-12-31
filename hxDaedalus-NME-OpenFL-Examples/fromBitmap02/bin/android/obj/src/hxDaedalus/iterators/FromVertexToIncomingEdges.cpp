#include <hxcpp.h>

#ifndef INCLUDED_hxDaedalus_data_Edge
#include <hxDaedalus/data/Edge.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_Vertex
#include <hxDaedalus/data/Vertex.h>
#endif
#ifndef INCLUDED_hxDaedalus_iterators_FromVertexToIncomingEdges
#include <hxDaedalus/iterators/FromVertexToIncomingEdges.h>
#endif
namespace hxDaedalus{
namespace iterators{

Void FromVertexToIncomingEdges_obj::__construct()
{
HX_STACK_FRAME("hxDaedalus.iterators.FromVertexToIncomingEdges","new",0x47d08b57,"hxDaedalus.iterators.FromVertexToIncomingEdges.new","hxDaedalus/iterators/FromVertexToIncomingEdges.hx",11,0x8a8dd63b)
HX_STACK_THIS(this)
{
}
;
	return null();
}

//FromVertexToIncomingEdges_obj::~FromVertexToIncomingEdges_obj() { }

Dynamic FromVertexToIncomingEdges_obj::__CreateEmpty() { return  new FromVertexToIncomingEdges_obj; }
hx::ObjectPtr< FromVertexToIncomingEdges_obj > FromVertexToIncomingEdges_obj::__new()
{  hx::ObjectPtr< FromVertexToIncomingEdges_obj > result = new FromVertexToIncomingEdges_obj();
	result->__construct();
	return result;}

Dynamic FromVertexToIncomingEdges_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FromVertexToIncomingEdges_obj > result = new FromVertexToIncomingEdges_obj();
	result->__construct();
	return result;}

::hxDaedalus::data::Vertex FromVertexToIncomingEdges_obj::set_fromVertex( ::hxDaedalus::data::Vertex value){
	HX_STACK_FRAME("hxDaedalus.iterators.FromVertexToIncomingEdges","set_fromVertex",0x31fd9b94,"hxDaedalus.iterators.FromVertexToIncomingEdges.set_fromVertex","hxDaedalus/iterators/FromVertexToIncomingEdges.hx",13,0x8a8dd63b)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(14)
	this->_fromVertex = value;
	HX_STACK_LINE(15)
	::hxDaedalus::data::Edge _g = this->_fromVertex->get_edge();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(15)
	this->_nextEdge = _g;
	HX_STACK_LINE(16)
	while((true)){
		HX_STACK_LINE(16)
		if ((!((!(this->_nextEdge->get_isReal()))))){
			HX_STACK_LINE(16)
			break;
		}
		HX_STACK_LINE(17)
		::hxDaedalus::data::Edge _g1 = this->_nextEdge->get_rotLeftEdge();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(17)
		this->_nextEdge = _g1;
	}
	HX_STACK_LINE(19)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(FromVertexToIncomingEdges_obj,set_fromVertex,return )

::hxDaedalus::data::Edge FromVertexToIncomingEdges_obj::next( ){
	HX_STACK_FRAME("hxDaedalus.iterators.FromVertexToIncomingEdges","next",0x8ea9621c,"hxDaedalus.iterators.FromVertexToIncomingEdges.next","hxDaedalus/iterators/FromVertexToIncomingEdges.hx",23,0x8a8dd63b)
	HX_STACK_THIS(this)
	HX_STACK_LINE(24)
	if (((this->_nextEdge != null()))){
		HX_STACK_LINE(25)
		::hxDaedalus::data::Edge _g = this->_nextEdge->get_oppositeEdge();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(25)
		this->_resultEdge = _g;
		HX_STACK_LINE(26)
		while((true)){
			HX_STACK_LINE(27)
			::hxDaedalus::data::Edge _g1 = this->_nextEdge->get_rotLeftEdge();		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(27)
			this->_nextEdge = _g1;
			HX_STACK_LINE(28)
			::hxDaedalus::data::Edge _g2 = this->_fromVertex->get_edge();		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(28)
			if (((this->_nextEdge == _g2))){
				HX_STACK_LINE(29)
				this->_nextEdge = null();
				HX_STACK_LINE(30)
				break;
			}
			HX_STACK_LINE(26)
			if ((!((!(this->_nextEdge->get_isReal()))))){
				HX_STACK_LINE(26)
				break;
			}
		}
	}
	else{
		HX_STACK_LINE(34)
		this->_resultEdge = null();
	}
	HX_STACK_LINE(36)
	return this->_resultEdge;
}


HX_DEFINE_DYNAMIC_FUNC0(FromVertexToIncomingEdges_obj,next,return )


FromVertexToIncomingEdges_obj::FromVertexToIncomingEdges_obj()
{
}

void FromVertexToIncomingEdges_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FromVertexToIncomingEdges);
	HX_MARK_MEMBER_NAME(_fromVertex,"_fromVertex");
	HX_MARK_MEMBER_NAME(_nextEdge,"_nextEdge");
	HX_MARK_MEMBER_NAME(_resultEdge,"_resultEdge");
	HX_MARK_END_CLASS();
}

void FromVertexToIncomingEdges_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_fromVertex,"_fromVertex");
	HX_VISIT_MEMBER_NAME(_nextEdge,"_nextEdge");
	HX_VISIT_MEMBER_NAME(_resultEdge,"_resultEdge");
}

Dynamic FromVertexToIncomingEdges_obj::__Field(const ::String &inName,bool inCallProp)
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
	case 14:
		if (HX_FIELD_EQ(inName,"set_fromVertex") ) { return set_fromVertex_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FromVertexToIncomingEdges_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
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
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FromVertexToIncomingEdges_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("fromVertex"));
	outFields->push(HX_CSTRING("_fromVertex"));
	outFields->push(HX_CSTRING("_nextEdge"));
	outFields->push(HX_CSTRING("_resultEdge"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::hxDaedalus::data::Vertex*/ ,(int)offsetof(FromVertexToIncomingEdges_obj,_fromVertex),HX_CSTRING("_fromVertex")},
	{hx::fsObject /*::hxDaedalus::data::Edge*/ ,(int)offsetof(FromVertexToIncomingEdges_obj,_nextEdge),HX_CSTRING("_nextEdge")},
	{hx::fsObject /*::hxDaedalus::data::Edge*/ ,(int)offsetof(FromVertexToIncomingEdges_obj,_resultEdge),HX_CSTRING("_resultEdge")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("_fromVertex"),
	HX_CSTRING("_nextEdge"),
	HX_CSTRING("_resultEdge"),
	HX_CSTRING("set_fromVertex"),
	HX_CSTRING("next"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FromVertexToIncomingEdges_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FromVertexToIncomingEdges_obj::__mClass,"__mClass");
};

#endif

Class FromVertexToIncomingEdges_obj::__mClass;

void FromVertexToIncomingEdges_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDaedalus.iterators.FromVertexToIncomingEdges"), hx::TCanCast< FromVertexToIncomingEdges_obj> ,sStaticFields,sMemberFields,
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

void FromVertexToIncomingEdges_obj::__boot()
{
}

} // end namespace hxDaedalus
} // end namespace iterators
