#include <hxcpp.h>

#ifndef INCLUDED_hxDaedalus_data_ConstraintSegment
#include <hxDaedalus/data/ConstraintSegment.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_Edge
#include <hxDaedalus/data/Edge.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_Vertex
#include <hxDaedalus/data/Vertex.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_math_Point2D
#include <hxDaedalus/data/math/Point2D.h>
#endif
namespace hxDaedalus{
namespace data{

Void Vertex_obj::__construct()
{
HX_STACK_FRAME("hxDaedalus.data.Vertex","new",0x212f8621,"hxDaedalus.data.Vertex.new","hxDaedalus/data/Vertex.hx",4,0x7a28700f)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(23)
	this->colorDebug = (int)-1;
	HX_STACK_LINE(27)
	this->_id = ::hxDaedalus::data::Vertex_obj::INC;
	HX_STACK_LINE(28)
	(::hxDaedalus::data::Vertex_obj::INC)++;
	HX_STACK_LINE(30)
	::hxDaedalus::data::math::Point2D _g = ::hxDaedalus::data::math::Point2D_obj::__new(null(),null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(30)
	this->_pos = _g;
	HX_STACK_LINE(32)
	Array< ::Dynamic > _g1 = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(32)
	this->_fromConstraintSegments = _g1;
}
;
	return null();
}

//Vertex_obj::~Vertex_obj() { }

Dynamic Vertex_obj::__CreateEmpty() { return  new Vertex_obj; }
hx::ObjectPtr< Vertex_obj > Vertex_obj::__new()
{  hx::ObjectPtr< Vertex_obj > result = new Vertex_obj();
	result->__construct();
	return result;}

Dynamic Vertex_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Vertex_obj > result = new Vertex_obj();
	result->__construct();
	return result;}

int Vertex_obj::get_id( ){
	HX_STACK_FRAME("hxDaedalus.data.Vertex","get_id",0x60658c03,"hxDaedalus.data.Vertex.get_id","hxDaedalus/data/Vertex.hx",37,0x7a28700f)
	HX_STACK_THIS(this)
	HX_STACK_LINE(37)
	return this->_id;
}


HX_DEFINE_DYNAMIC_FUNC0(Vertex_obj,get_id,return )

bool Vertex_obj::get_isReal( ){
	HX_STACK_FRAME("hxDaedalus.data.Vertex","get_isReal",0xa3d27490,"hxDaedalus.data.Vertex.get_isReal","hxDaedalus/data/Vertex.hx",42,0x7a28700f)
	HX_STACK_THIS(this)
	HX_STACK_LINE(42)
	return this->_isReal;
}


HX_DEFINE_DYNAMIC_FUNC0(Vertex_obj,get_isReal,return )

::hxDaedalus::data::math::Point2D Vertex_obj::get_pos( ){
	HX_STACK_FRAME("hxDaedalus.data.Vertex","get_pos",0xf87a506c,"hxDaedalus.data.Vertex.get_pos","hxDaedalus/data/Vertex.hx",47,0x7a28700f)
	HX_STACK_THIS(this)
	HX_STACK_LINE(47)
	return this->_pos;
}


HX_DEFINE_DYNAMIC_FUNC0(Vertex_obj,get_pos,return )

Array< ::Dynamic > Vertex_obj::get_fromConstraintSegments( ){
	HX_STACK_FRAME("hxDaedalus.data.Vertex","get_fromConstraintSegments",0x1c796f0f,"hxDaedalus.data.Vertex.get_fromConstraintSegments","hxDaedalus/data/Vertex.hx",51,0x7a28700f)
	HX_STACK_THIS(this)
	HX_STACK_LINE(51)
	return this->_fromConstraintSegments;
}


HX_DEFINE_DYNAMIC_FUNC0(Vertex_obj,get_fromConstraintSegments,return )

Array< ::Dynamic > Vertex_obj::set_fromConstraintSegments( Array< ::Dynamic > value){
	HX_STACK_FRAME("hxDaedalus.data.Vertex","set_fromConstraintSegments",0x7c0e3583,"hxDaedalus.data.Vertex.set_fromConstraintSegments","hxDaedalus/data/Vertex.hx",55,0x7a28700f)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(55)
	return this->_fromConstraintSegments = value;
}


HX_DEFINE_DYNAMIC_FUNC1(Vertex_obj,set_fromConstraintSegments,return )

Void Vertex_obj::setDatas( ::hxDaedalus::data::Edge edge,hx::Null< bool >  __o_isReal){
bool isReal = __o_isReal.Default(true);
	HX_STACK_FRAME("hxDaedalus.data.Vertex","setDatas",0x8b3146a6,"hxDaedalus.data.Vertex.setDatas","hxDaedalus/data/Vertex.hx",59,0x7a28700f)
	HX_STACK_THIS(this)
	HX_STACK_ARG(edge,"edge")
	HX_STACK_ARG(isReal,"isReal")
{
		HX_STACK_LINE(60)
		this->_isReal = isReal;
		HX_STACK_LINE(61)
		this->_edge = edge;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Vertex_obj,setDatas,(void))

Void Vertex_obj::addFromConstraintSegment( ::hxDaedalus::data::ConstraintSegment segment){
{
		HX_STACK_FRAME("hxDaedalus.data.Vertex","addFromConstraintSegment",0x44f1a0ca,"hxDaedalus.data.Vertex.addFromConstraintSegment","hxDaedalus/data/Vertex.hx",64,0x7a28700f)
		HX_STACK_THIS(this)
		HX_STACK_ARG(segment,"segment")
		HX_STACK_LINE(65)
		int _g = this->_fromConstraintSegments->indexOf(segment,null());		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(65)
		if (((_g == (int)-1))){
			HX_STACK_LINE(65)
			this->_fromConstraintSegments->push(segment);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Vertex_obj,addFromConstraintSegment,(void))

Void Vertex_obj::removeFromConstraintSegment( ::hxDaedalus::data::ConstraintSegment segment){
{
		HX_STACK_FRAME("hxDaedalus.data.Vertex","removeFromConstraintSegment",0x4430d5e9,"hxDaedalus.data.Vertex.removeFromConstraintSegment","hxDaedalus/data/Vertex.hx",69,0x7a28700f)
		HX_STACK_THIS(this)
		HX_STACK_ARG(segment,"segment")
		HX_STACK_LINE(70)
		int index = this->_fromConstraintSegments->indexOf(segment,null());		HX_STACK_VAR(index,"index");
		HX_STACK_LINE(71)
		if (((index != (int)-1))){
			HX_STACK_LINE(72)
			this->_fromConstraintSegments->splice(index,(int)1);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Vertex_obj,removeFromConstraintSegment,(void))

Void Vertex_obj::dispose( ){
{
		HX_STACK_FRAME("hxDaedalus.data.Vertex","dispose",0x8cfcaae0,"hxDaedalus.data.Vertex.dispose","hxDaedalus/data/Vertex.hx",76,0x7a28700f)
		HX_STACK_THIS(this)
		HX_STACK_LINE(77)
		this->_pos = null();
		HX_STACK_LINE(78)
		this->_edge = null();
		HX_STACK_LINE(79)
		this->_fromConstraintSegments = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Vertex_obj,dispose,(void))

::hxDaedalus::data::Edge Vertex_obj::get_edge( ){
	HX_STACK_FRAME("hxDaedalus.data.Vertex","get_edge",0x6b3e5265,"hxDaedalus.data.Vertex.get_edge","hxDaedalus/data/Vertex.hx",83,0x7a28700f)
	HX_STACK_THIS(this)
	HX_STACK_LINE(83)
	return this->_edge;
}


HX_DEFINE_DYNAMIC_FUNC0(Vertex_obj,get_edge,return )

::hxDaedalus::data::Edge Vertex_obj::set_edge( ::hxDaedalus::data::Edge value){
	HX_STACK_FRAME("hxDaedalus.data.Vertex","set_edge",0x199babd9,"hxDaedalus.data.Vertex.set_edge","hxDaedalus/data/Vertex.hx",87,0x7a28700f)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(87)
	return this->_edge = value;
}


HX_DEFINE_DYNAMIC_FUNC1(Vertex_obj,set_edge,return )

::String Vertex_obj::toString( ){
	HX_STACK_FRAME("hxDaedalus.data.Vertex","toString",0xe0e39f4b,"hxDaedalus.data.Vertex.toString","hxDaedalus/data/Vertex.hx",91,0x7a28700f)
	HX_STACK_THIS(this)
	HX_STACK_LINE(91)
	return (HX_CSTRING("ver_id ") + this->_id);
}


HX_DEFINE_DYNAMIC_FUNC0(Vertex_obj,toString,return )

int Vertex_obj::INC;


Vertex_obj::Vertex_obj()
{
}

void Vertex_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Vertex);
	HX_MARK_MEMBER_NAME(_id,"_id");
	HX_MARK_MEMBER_NAME(_pos,"_pos");
	HX_MARK_MEMBER_NAME(_isReal,"_isReal");
	HX_MARK_MEMBER_NAME(_edge,"_edge");
	HX_MARK_MEMBER_NAME(_fromConstraintSegments,"_fromConstraintSegments");
	HX_MARK_MEMBER_NAME(colorDebug,"colorDebug");
	HX_MARK_END_CLASS();
}

void Vertex_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_id,"_id");
	HX_VISIT_MEMBER_NAME(_pos,"_pos");
	HX_VISIT_MEMBER_NAME(_isReal,"_isReal");
	HX_VISIT_MEMBER_NAME(_edge,"_edge");
	HX_VISIT_MEMBER_NAME(_fromConstraintSegments,"_fromConstraintSegments");
	HX_VISIT_MEMBER_NAME(colorDebug,"colorDebug");
}

Dynamic Vertex_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { return get_id(); }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"INC") ) { return INC; }
		if (HX_FIELD_EQ(inName,"pos") ) { return get_pos(); }
		if (HX_FIELD_EQ(inName,"_id") ) { return _id; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"edge") ) { return get_edge(); }
		if (HX_FIELD_EQ(inName,"_pos") ) { return _pos; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_edge") ) { return _edge; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"isReal") ) { return get_isReal(); }
		if (HX_FIELD_EQ(inName,"get_id") ) { return get_id_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_isReal") ) { return _isReal; }
		if (HX_FIELD_EQ(inName,"get_pos") ) { return get_pos_dyn(); }
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"setDatas") ) { return setDatas_dyn(); }
		if (HX_FIELD_EQ(inName,"get_edge") ) { return get_edge_dyn(); }
		if (HX_FIELD_EQ(inName,"set_edge") ) { return set_edge_dyn(); }
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"colorDebug") ) { return colorDebug; }
		if (HX_FIELD_EQ(inName,"get_isReal") ) { return get_isReal_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"fromConstraintSegments") ) { return get_fromConstraintSegments(); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"_fromConstraintSegments") ) { return _fromConstraintSegments; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"addFromConstraintSegment") ) { return addFromConstraintSegment_dyn(); }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"get_fromConstraintSegments") ) { return get_fromConstraintSegments_dyn(); }
		if (HX_FIELD_EQ(inName,"set_fromConstraintSegments") ) { return set_fromConstraintSegments_dyn(); }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"removeFromConstraintSegment") ) { return removeFromConstraintSegment_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Vertex_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"INC") ) { INC=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_id") ) { _id=inValue.Cast< int >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"edge") ) { return set_edge(inValue); }
		if (HX_FIELD_EQ(inName,"_pos") ) { _pos=inValue.Cast< ::hxDaedalus::data::math::Point2D >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_edge") ) { _edge=inValue.Cast< ::hxDaedalus::data::Edge >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_isReal") ) { _isReal=inValue.Cast< bool >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"colorDebug") ) { colorDebug=inValue.Cast< int >(); return inValue; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"fromConstraintSegments") ) { return set_fromConstraintSegments(inValue); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"_fromConstraintSegments") ) { _fromConstraintSegments=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Vertex_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("id"));
	outFields->push(HX_CSTRING("isReal"));
	outFields->push(HX_CSTRING("pos"));
	outFields->push(HX_CSTRING("fromConstraintSegments"));
	outFields->push(HX_CSTRING("edge"));
	outFields->push(HX_CSTRING("_id"));
	outFields->push(HX_CSTRING("_pos"));
	outFields->push(HX_CSTRING("_isReal"));
	outFields->push(HX_CSTRING("_edge"));
	outFields->push(HX_CSTRING("_fromConstraintSegments"));
	outFields->push(HX_CSTRING("colorDebug"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("INC"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(Vertex_obj,_id),HX_CSTRING("_id")},
	{hx::fsObject /*::hxDaedalus::data::math::Point2D*/ ,(int)offsetof(Vertex_obj,_pos),HX_CSTRING("_pos")},
	{hx::fsBool,(int)offsetof(Vertex_obj,_isReal),HX_CSTRING("_isReal")},
	{hx::fsObject /*::hxDaedalus::data::Edge*/ ,(int)offsetof(Vertex_obj,_edge),HX_CSTRING("_edge")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(Vertex_obj,_fromConstraintSegments),HX_CSTRING("_fromConstraintSegments")},
	{hx::fsInt,(int)offsetof(Vertex_obj,colorDebug),HX_CSTRING("colorDebug")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("_id"),
	HX_CSTRING("_pos"),
	HX_CSTRING("_isReal"),
	HX_CSTRING("_edge"),
	HX_CSTRING("_fromConstraintSegments"),
	HX_CSTRING("colorDebug"),
	HX_CSTRING("get_id"),
	HX_CSTRING("get_isReal"),
	HX_CSTRING("get_pos"),
	HX_CSTRING("get_fromConstraintSegments"),
	HX_CSTRING("set_fromConstraintSegments"),
	HX_CSTRING("setDatas"),
	HX_CSTRING("addFromConstraintSegment"),
	HX_CSTRING("removeFromConstraintSegment"),
	HX_CSTRING("dispose"),
	HX_CSTRING("get_edge"),
	HX_CSTRING("set_edge"),
	HX_CSTRING("toString"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Vertex_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Vertex_obj::INC,"INC");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Vertex_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Vertex_obj::INC,"INC");
};

#endif

Class Vertex_obj::__mClass;

void Vertex_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDaedalus.data.Vertex"), hx::TCanCast< Vertex_obj> ,sStaticFields,sMemberFields,
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

void Vertex_obj::__boot()
{
	INC= (int)0;
}

} // end namespace hxDaedalus
} // end namespace data
