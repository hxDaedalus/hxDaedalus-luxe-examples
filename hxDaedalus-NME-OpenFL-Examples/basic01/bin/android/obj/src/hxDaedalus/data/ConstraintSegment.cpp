#include <hxcpp.h>

#ifndef INCLUDED_hxDaedalus_data_ConstraintSegment
#include <hxDaedalus/data/ConstraintSegment.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_ConstraintShape
#include <hxDaedalus/data/ConstraintShape.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_Edge
#include <hxDaedalus/data/Edge.h>
#endif
namespace hxDaedalus{
namespace data{

Void ConstraintSegment_obj::__construct()
{
HX_STACK_FRAME("hxDaedalus.data.ConstraintSegment","new",0x31d3f6dd,"hxDaedalus.data.ConstraintSegment.new","hxDaedalus/data/ConstraintSegment.hx",15,0xab511f93)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(16)
	this->_id = ::hxDaedalus::data::ConstraintSegment_obj::INC;
	HX_STACK_LINE(17)
	(::hxDaedalus::data::ConstraintSegment_obj::INC)++;
	HX_STACK_LINE(18)
	Array< ::Dynamic > _g = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(18)
	this->_edges = _g;
}
;
	return null();
}

//ConstraintSegment_obj::~ConstraintSegment_obj() { }

Dynamic ConstraintSegment_obj::__CreateEmpty() { return  new ConstraintSegment_obj; }
hx::ObjectPtr< ConstraintSegment_obj > ConstraintSegment_obj::__new()
{  hx::ObjectPtr< ConstraintSegment_obj > result = new ConstraintSegment_obj();
	result->__construct();
	return result;}

Dynamic ConstraintSegment_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ConstraintSegment_obj > result = new ConstraintSegment_obj();
	result->__construct();
	return result;}

int ConstraintSegment_obj::get_id( ){
	HX_STACK_FRAME("hxDaedalus.data.ConstraintSegment","get_id",0xd26b38c7,"hxDaedalus.data.ConstraintSegment.get_id","hxDaedalus/data/ConstraintSegment.hx",22,0xab511f93)
	HX_STACK_THIS(this)
	HX_STACK_LINE(22)
	return this->_id;
}


HX_DEFINE_DYNAMIC_FUNC0(ConstraintSegment_obj,get_id,return )

Void ConstraintSegment_obj::addEdge( ::hxDaedalus::data::Edge edge){
{
		HX_STACK_FRAME("hxDaedalus.data.ConstraintSegment","addEdge",0xa3edb3fb,"hxDaedalus.data.ConstraintSegment.addEdge","hxDaedalus/data/ConstraintSegment.hx",26,0xab511f93)
		HX_STACK_THIS(this)
		HX_STACK_ARG(edge,"edge")
		HX_STACK_LINE(27)
		int _g = this->_edges->indexOf(edge,null());		HX_STACK_VAR(_g,"_g");
		struct _Function_1_1{
			inline static bool Block( ::hxDaedalus::data::Edge &edge,hx::ObjectPtr< ::hxDaedalus::data::ConstraintSegment_obj > __this){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","hxDaedalus/data/ConstraintSegment.hx",27,0xab511f93)
				{
					HX_STACK_LINE(27)
					::hxDaedalus::data::Edge _g1 = edge->get_oppositeEdge();		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(27)
					int _g2 = __this->_edges->indexOf(_g1,null());		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(27)
					return (_g2 == (int)-1);
				}
				return null();
			}
		};
		HX_STACK_LINE(27)
		if (((  (((_g == (int)-1))) ? bool(_Function_1_1::Block(edge,this)) : bool(false) ))){
			HX_STACK_LINE(27)
			this->_edges->push(edge);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ConstraintSegment_obj,addEdge,(void))

Void ConstraintSegment_obj::removeEdge( ::hxDaedalus::data::Edge edge){
{
		HX_STACK_FRAME("hxDaedalus.data.ConstraintSegment","removeEdge",0x294055c4,"hxDaedalus.data.ConstraintSegment.removeEdge","hxDaedalus/data/ConstraintSegment.hx",30,0xab511f93)
		HX_STACK_THIS(this)
		HX_STACK_ARG(edge,"edge")
		HX_STACK_LINE(31)
		int index;		HX_STACK_VAR(index,"index");
		HX_STACK_LINE(32)
		int _g = this->_edges->indexOf(edge,null());		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(32)
		index = _g;
		HX_STACK_LINE(33)
		if (((index == (int)-1))){
			HX_STACK_LINE(33)
			::hxDaedalus::data::Edge _g1 = edge->get_oppositeEdge();		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(33)
			int _g2 = this->_edges->indexOf(_g1,null());		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(33)
			index = _g2;
		}
		HX_STACK_LINE(34)
		if (((index != (int)-1))){
			HX_STACK_LINE(34)
			this->_edges->splice(index,(int)1);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ConstraintSegment_obj,removeEdge,(void))

Array< ::Dynamic > ConstraintSegment_obj::get_edges( ){
	HX_STACK_FRAME("hxDaedalus.data.ConstraintSegment","get_edges",0x7ca56c2a,"hxDaedalus.data.ConstraintSegment.get_edges","hxDaedalus/data/ConstraintSegment.hx",38,0xab511f93)
	HX_STACK_THIS(this)
	HX_STACK_LINE(38)
	return this->_edges;
}


HX_DEFINE_DYNAMIC_FUNC0(ConstraintSegment_obj,get_edges,return )

Void ConstraintSegment_obj::dispose( ){
{
		HX_STACK_FRAME("hxDaedalus.data.ConstraintSegment","dispose",0xdfee299c,"hxDaedalus.data.ConstraintSegment.dispose","hxDaedalus/data/ConstraintSegment.hx",41,0xab511f93)
		HX_STACK_THIS(this)
		HX_STACK_LINE(42)
		this->_edges = null();
		HX_STACK_LINE(43)
		this->fromShape = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ConstraintSegment_obj,dispose,(void))

::String ConstraintSegment_obj::toString( ){
	HX_STACK_FRAME("hxDaedalus.data.ConstraintSegment","toString",0x2141050f,"hxDaedalus.data.ConstraintSegment.toString","hxDaedalus/data/ConstraintSegment.hx",47,0xab511f93)
	HX_STACK_THIS(this)
	HX_STACK_LINE(47)
	return (HX_CSTRING("seg_id ") + this->_id);
}


HX_DEFINE_DYNAMIC_FUNC0(ConstraintSegment_obj,toString,return )

int ConstraintSegment_obj::INC;


ConstraintSegment_obj::ConstraintSegment_obj()
{
}

void ConstraintSegment_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ConstraintSegment);
	HX_MARK_MEMBER_NAME(fromShape,"fromShape");
	HX_MARK_MEMBER_NAME(_id,"_id");
	HX_MARK_MEMBER_NAME(_edges,"_edges");
	HX_MARK_END_CLASS();
}

void ConstraintSegment_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(fromShape,"fromShape");
	HX_VISIT_MEMBER_NAME(_id,"_id");
	HX_VISIT_MEMBER_NAME(_edges,"_edges");
}

Dynamic ConstraintSegment_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { return get_id(); }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"INC") ) { return INC; }
		if (HX_FIELD_EQ(inName,"_id") ) { return _id; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"edges") ) { return get_edges(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_edges") ) { return _edges; }
		if (HX_FIELD_EQ(inName,"get_id") ) { return get_id_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"addEdge") ) { return addEdge_dyn(); }
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"fromShape") ) { return fromShape; }
		if (HX_FIELD_EQ(inName,"get_edges") ) { return get_edges_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"removeEdge") ) { return removeEdge_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ConstraintSegment_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"INC") ) { INC=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_id") ) { _id=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_edges") ) { _edges=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"fromShape") ) { fromShape=inValue.Cast< ::hxDaedalus::data::ConstraintShape >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ConstraintSegment_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("id"));
	outFields->push(HX_CSTRING("fromShape"));
	outFields->push(HX_CSTRING("edges"));
	outFields->push(HX_CSTRING("_id"));
	outFields->push(HX_CSTRING("_edges"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("INC"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::hxDaedalus::data::ConstraintShape*/ ,(int)offsetof(ConstraintSegment_obj,fromShape),HX_CSTRING("fromShape")},
	{hx::fsInt,(int)offsetof(ConstraintSegment_obj,_id),HX_CSTRING("_id")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(ConstraintSegment_obj,_edges),HX_CSTRING("_edges")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("fromShape"),
	HX_CSTRING("_id"),
	HX_CSTRING("_edges"),
	HX_CSTRING("get_id"),
	HX_CSTRING("addEdge"),
	HX_CSTRING("removeEdge"),
	HX_CSTRING("get_edges"),
	HX_CSTRING("dispose"),
	HX_CSTRING("toString"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ConstraintSegment_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(ConstraintSegment_obj::INC,"INC");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ConstraintSegment_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(ConstraintSegment_obj::INC,"INC");
};

#endif

Class ConstraintSegment_obj::__mClass;

void ConstraintSegment_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDaedalus.data.ConstraintSegment"), hx::TCanCast< ConstraintSegment_obj> ,sStaticFields,sMemberFields,
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

void ConstraintSegment_obj::__boot()
{
	INC= (int)0;
}

} // end namespace hxDaedalus
} // end namespace data
