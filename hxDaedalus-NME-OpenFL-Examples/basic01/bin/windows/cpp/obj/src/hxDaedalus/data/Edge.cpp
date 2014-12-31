#include <hxcpp.h>

#ifndef INCLUDED_hxDaedalus_data_ConstraintSegment
#include <hxDaedalus/data/ConstraintSegment.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_Edge
#include <hxDaedalus/data/Edge.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_Face
#include <hxDaedalus/data/Face.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_Vertex
#include <hxDaedalus/data/Vertex.h>
#endif
namespace hxDaedalus{
namespace data{

Void Edge_obj::__construct()
{
HX_STACK_FRAME("hxDaedalus.data.Edge","new",0xfd0e3aba,"hxDaedalus.data.Edge.new","hxDaedalus/data/Edge.hx",5,0x18c3e996)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(35)
	this->colorDebug = (int)-1;
	HX_STACK_LINE(38)
	this->_id = ::hxDaedalus::data::Edge_obj::INC;
	HX_STACK_LINE(39)
	(::hxDaedalus::data::Edge_obj::INC)++;
	HX_STACK_LINE(40)
	Array< ::Dynamic > _g = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(40)
	this->fromConstraintSegments = _g;
}
;
	return null();
}

//Edge_obj::~Edge_obj() { }

Dynamic Edge_obj::__CreateEmpty() { return  new Edge_obj; }
hx::ObjectPtr< Edge_obj > Edge_obj::__new()
{  hx::ObjectPtr< Edge_obj > result = new Edge_obj();
	result->__construct();
	return result;}

Dynamic Edge_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Edge_obj > result = new Edge_obj();
	result->__construct();
	return result;}

int Edge_obj::get_id( ){
	HX_STACK_FRAME("hxDaedalus.data.Edge","get_id",0x22d0fd0a,"hxDaedalus.data.Edge.get_id","hxDaedalus/data/Edge.hx",44,0x18c3e996)
	HX_STACK_THIS(this)
	HX_STACK_LINE(44)
	return this->_id;
}


HX_DEFINE_DYNAMIC_FUNC0(Edge_obj,get_id,return )

bool Edge_obj::get_isReal( ){
	HX_STACK_FRAME("hxDaedalus.data.Edge","get_isReal",0xc7187517,"hxDaedalus.data.Edge.get_isReal","hxDaedalus/data/Edge.hx",48,0x18c3e996)
	HX_STACK_THIS(this)
	HX_STACK_LINE(48)
	return this->_isReal;
}


HX_DEFINE_DYNAMIC_FUNC0(Edge_obj,get_isReal,return )

bool Edge_obj::get_isConstrained( ){
	HX_STACK_FRAME("hxDaedalus.data.Edge","get_isConstrained",0xc61eb3bd,"hxDaedalus.data.Edge.get_isConstrained","hxDaedalus/data/Edge.hx",52,0x18c3e996)
	HX_STACK_THIS(this)
	HX_STACK_LINE(52)
	return this->_isConstrained;
}


HX_DEFINE_DYNAMIC_FUNC0(Edge_obj,get_isConstrained,return )

Void Edge_obj::setDatas( ::hxDaedalus::data::Vertex originVertex,::hxDaedalus::data::Edge oppositeEdge,::hxDaedalus::data::Edge nextLeftEdge,::hxDaedalus::data::Face leftFace,hx::Null< bool >  __o_isReal,hx::Null< bool >  __o_isConstrained){
bool isReal = __o_isReal.Default(true);
bool isConstrained = __o_isConstrained.Default(false);
	HX_STACK_FRAME("hxDaedalus.data.Edge","setDatas",0x5420476d,"hxDaedalus.data.Edge.setDatas","hxDaedalus/data/Edge.hx",62,0x18c3e996)
	HX_STACK_THIS(this)
	HX_STACK_ARG(originVertex,"originVertex")
	HX_STACK_ARG(oppositeEdge,"oppositeEdge")
	HX_STACK_ARG(nextLeftEdge,"nextLeftEdge")
	HX_STACK_ARG(leftFace,"leftFace")
	HX_STACK_ARG(isReal,"isReal")
	HX_STACK_ARG(isConstrained,"isConstrained")
{
		HX_STACK_LINE(63)
		this->_isConstrained = isConstrained;
		HX_STACK_LINE(64)
		this->_isReal = isReal;
		HX_STACK_LINE(65)
		this->_originVertex = originVertex;
		HX_STACK_LINE(66)
		this->_oppositeEdge = oppositeEdge;
		HX_STACK_LINE(67)
		this->_nextLeftEdge = nextLeftEdge;
		HX_STACK_LINE(68)
		this->_leftFace = leftFace;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC6(Edge_obj,setDatas,(void))

Void Edge_obj::addFromConstraintSegment( ::hxDaedalus::data::ConstraintSegment segment){
{
		HX_STACK_FRAME("hxDaedalus.data.Edge","addFromConstraintSegment",0xe768df91,"hxDaedalus.data.Edge.addFromConstraintSegment","hxDaedalus/data/Edge.hx",71,0x18c3e996)
		HX_STACK_THIS(this)
		HX_STACK_ARG(segment,"segment")
		HX_STACK_LINE(72)
		int _g = this->fromConstraintSegments->indexOf(segment,null());		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(72)
		if (((_g == (int)-1))){
			HX_STACK_LINE(72)
			this->fromConstraintSegments->push(segment);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Edge_obj,addFromConstraintSegment,(void))

Void Edge_obj::removeFromConstraintSegment( ::hxDaedalus::data::ConstraintSegment segment){
{
		HX_STACK_FRAME("hxDaedalus.data.Edge","removeFromConstraintSegment",0xc4ddcd82,"hxDaedalus.data.Edge.removeFromConstraintSegment","hxDaedalus/data/Edge.hx",75,0x18c3e996)
		HX_STACK_THIS(this)
		HX_STACK_ARG(segment,"segment")
		HX_STACK_LINE(76)
		int index = this->fromConstraintSegments->indexOf(segment,null());		HX_STACK_VAR(index,"index");
		HX_STACK_LINE(77)
		if (((index != (int)-1))){
			HX_STACK_LINE(77)
			this->fromConstraintSegments->splice(index,(int)1);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Edge_obj,removeFromConstraintSegment,(void))

::hxDaedalus::data::Vertex Edge_obj::set_originVertex( ::hxDaedalus::data::Vertex value){
	HX_STACK_FRAME("hxDaedalus.data.Edge","set_originVertex",0x73da594d,"hxDaedalus.data.Edge.set_originVertex","hxDaedalus/data/Edge.hx",80,0x18c3e996)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(81)
	this->_originVertex = value;
	HX_STACK_LINE(82)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Edge_obj,set_originVertex,return )

::hxDaedalus::data::Edge Edge_obj::set_nextLeftEdge( ::hxDaedalus::data::Edge value){
	HX_STACK_FRAME("hxDaedalus.data.Edge","set_nextLeftEdge",0x9b64775a,"hxDaedalus.data.Edge.set_nextLeftEdge","hxDaedalus/data/Edge.hx",85,0x18c3e996)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(86)
	this->_nextLeftEdge = value;
	HX_STACK_LINE(87)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Edge_obj,set_nextLeftEdge,return )

::hxDaedalus::data::Face Edge_obj::set_leftFace( ::hxDaedalus::data::Face value){
	HX_STACK_FRAME("hxDaedalus.data.Edge","set_leftFace",0x209a4a27,"hxDaedalus.data.Edge.set_leftFace","hxDaedalus/data/Edge.hx",90,0x18c3e996)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(91)
	this->_leftFace = value;
	HX_STACK_LINE(92)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Edge_obj,set_leftFace,return )

bool Edge_obj::set_isConstrained( bool value){
	HX_STACK_FRAME("hxDaedalus.data.Edge","set_isConstrained",0xe98c8bc9,"hxDaedalus.data.Edge.set_isConstrained","hxDaedalus/data/Edge.hx",95,0x18c3e996)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(96)
	this->_isConstrained = value;
	HX_STACK_LINE(97)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Edge_obj,set_isConstrained,return )

Void Edge_obj::dispose( ){
{
		HX_STACK_FRAME("hxDaedalus.data.Edge","dispose",0xe8941ff9,"hxDaedalus.data.Edge.dispose","hxDaedalus/data/Edge.hx",101,0x18c3e996)
		HX_STACK_THIS(this)
		HX_STACK_LINE(102)
		this->_originVertex = null();
		HX_STACK_LINE(103)
		this->_oppositeEdge = null();
		HX_STACK_LINE(104)
		this->_nextLeftEdge = null();
		HX_STACK_LINE(105)
		this->_leftFace = null();
		HX_STACK_LINE(106)
		this->fromConstraintSegments = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Edge_obj,dispose,(void))

::hxDaedalus::data::Vertex Edge_obj::get_originVertex( ){
	HX_STACK_FRAME("hxDaedalus.data.Edge","get_originVertex",0x1d986bd9,"hxDaedalus.data.Edge.get_originVertex","hxDaedalus/data/Edge.hx",109,0x18c3e996)
	HX_STACK_THIS(this)
	HX_STACK_LINE(109)
	return this->_originVertex;
}


HX_DEFINE_DYNAMIC_FUNC0(Edge_obj,get_originVertex,return )

::hxDaedalus::data::Vertex Edge_obj::get_destinationVertex( ){
	HX_STACK_FRAME("hxDaedalus.data.Edge","get_destinationVertex",0x1be74443,"hxDaedalus.data.Edge.get_destinationVertex","hxDaedalus/data/Edge.hx",111,0x18c3e996)
	HX_STACK_THIS(this)
	HX_STACK_LINE(111)
	return this->get_oppositeEdge()->get_originVertex();
}


HX_DEFINE_DYNAMIC_FUNC0(Edge_obj,get_destinationVertex,return )

::hxDaedalus::data::Edge Edge_obj::get_oppositeEdge( ){
	HX_STACK_FRAME("hxDaedalus.data.Edge","get_oppositeEdge",0x42675eb3,"hxDaedalus.data.Edge.get_oppositeEdge","hxDaedalus/data/Edge.hx",114,0x18c3e996)
	HX_STACK_THIS(this)
	HX_STACK_LINE(114)
	return this->_oppositeEdge;
}


HX_DEFINE_DYNAMIC_FUNC0(Edge_obj,get_oppositeEdge,return )

::hxDaedalus::data::Edge Edge_obj::get_nextLeftEdge( ){
	HX_STACK_FRAME("hxDaedalus.data.Edge","get_nextLeftEdge",0x452289e6,"hxDaedalus.data.Edge.get_nextLeftEdge","hxDaedalus/data/Edge.hx",116,0x18c3e996)
	HX_STACK_THIS(this)
	HX_STACK_LINE(116)
	return this->_nextLeftEdge;
}


HX_DEFINE_DYNAMIC_FUNC0(Edge_obj,get_nextLeftEdge,return )

::hxDaedalus::data::Edge Edge_obj::get_prevLeftEdge( ){
	HX_STACK_FRAME("hxDaedalus.data.Edge","get_prevLeftEdge",0xb448c3e6,"hxDaedalus.data.Edge.get_prevLeftEdge","hxDaedalus/data/Edge.hx",118,0x18c3e996)
	HX_STACK_THIS(this)
	HX_STACK_LINE(118)
	return this->_nextLeftEdge->get_nextLeftEdge();
}


HX_DEFINE_DYNAMIC_FUNC0(Edge_obj,get_prevLeftEdge,return )

::hxDaedalus::data::Edge Edge_obj::get_nextRightEdge( ){
	HX_STACK_FRAME("hxDaedalus.data.Edge","get_nextRightEdge",0x682ae1f7,"hxDaedalus.data.Edge.get_nextRightEdge","hxDaedalus/data/Edge.hx",120,0x18c3e996)
	HX_STACK_THIS(this)
	HX_STACK_LINE(120)
	return this->_oppositeEdge->get_nextLeftEdge()->get_nextLeftEdge()->get_oppositeEdge();
}


HX_DEFINE_DYNAMIC_FUNC0(Edge_obj,get_nextRightEdge,return )

::hxDaedalus::data::Edge Edge_obj::get_prevRightEdge( ){
	HX_STACK_FRAME("hxDaedalus.data.Edge","get_prevRightEdge",0x3a7767f7,"hxDaedalus.data.Edge.get_prevRightEdge","hxDaedalus/data/Edge.hx",122,0x18c3e996)
	HX_STACK_THIS(this)
	HX_STACK_LINE(122)
	return this->_oppositeEdge->get_nextLeftEdge()->get_oppositeEdge();
}


HX_DEFINE_DYNAMIC_FUNC0(Edge_obj,get_prevRightEdge,return )

::hxDaedalus::data::Edge Edge_obj::get_rotLeftEdge( ){
	HX_STACK_FRAME("hxDaedalus.data.Edge","get_rotLeftEdge",0xa2b45a0c,"hxDaedalus.data.Edge.get_rotLeftEdge","hxDaedalus/data/Edge.hx",124,0x18c3e996)
	HX_STACK_THIS(this)
	HX_STACK_LINE(124)
	return this->_nextLeftEdge->get_nextLeftEdge()->get_oppositeEdge();
}


HX_DEFINE_DYNAMIC_FUNC0(Edge_obj,get_rotLeftEdge,return )

::hxDaedalus::data::Edge Edge_obj::get_rotRightEdge( ){
	HX_STACK_FRAME("hxDaedalus.data.Edge","get_rotRightEdge",0xea2f3311,"hxDaedalus.data.Edge.get_rotRightEdge","hxDaedalus/data/Edge.hx",126,0x18c3e996)
	HX_STACK_THIS(this)
	HX_STACK_LINE(126)
	return this->_oppositeEdge->get_nextLeftEdge();
}


HX_DEFINE_DYNAMIC_FUNC0(Edge_obj,get_rotRightEdge,return )

::hxDaedalus::data::Face Edge_obj::get_leftFace( ){
	HX_STACK_FRAME("hxDaedalus.data.Edge","get_leftFace",0x0ba126b3,"hxDaedalus.data.Edge.get_leftFace","hxDaedalus/data/Edge.hx",128,0x18c3e996)
	HX_STACK_THIS(this)
	HX_STACK_LINE(128)
	return this->_leftFace;
}


HX_DEFINE_DYNAMIC_FUNC0(Edge_obj,get_leftFace,return )

::hxDaedalus::data::Face Edge_obj::get_rightFace( ){
	HX_STACK_FRAME("hxDaedalus.data.Edge","get_rightFace",0xbfb47d4a,"hxDaedalus.data.Edge.get_rightFace","hxDaedalus/data/Edge.hx",130,0x18c3e996)
	HX_STACK_THIS(this)
	HX_STACK_LINE(130)
	return this->_oppositeEdge->get_leftFace();
}


HX_DEFINE_DYNAMIC_FUNC0(Edge_obj,get_rightFace,return )

::String Edge_obj::toString( ){
	HX_STACK_FRAME("hxDaedalus.data.Edge","toString",0xa9d2a012,"hxDaedalus.data.Edge.toString","hxDaedalus/data/Edge.hx",135,0x18c3e996)
	HX_STACK_THIS(this)
	HX_STACK_LINE(136)
	int _g = this->get_originVertex()->get_id();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(136)
	::String _g1 = (HX_CSTRING("edge ") + _g);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(136)
	::String _g2 = (_g1 + HX_CSTRING(" - "));		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(136)
	int _g3 = this->get_destinationVertex()->get_id();		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(136)
	return (_g2 + _g3);
}


HX_DEFINE_DYNAMIC_FUNC0(Edge_obj,toString,return )

int Edge_obj::INC;


Edge_obj::Edge_obj()
{
}

void Edge_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Edge);
	HX_MARK_MEMBER_NAME(fromConstraintSegments,"fromConstraintSegments");
	HX_MARK_MEMBER_NAME(_id,"_id");
	HX_MARK_MEMBER_NAME(_isReal,"_isReal");
	HX_MARK_MEMBER_NAME(_isConstrained,"_isConstrained");
	HX_MARK_MEMBER_NAME(_originVertex,"_originVertex");
	HX_MARK_MEMBER_NAME(_oppositeEdge,"_oppositeEdge");
	HX_MARK_MEMBER_NAME(_nextLeftEdge,"_nextLeftEdge");
	HX_MARK_MEMBER_NAME(_leftFace,"_leftFace");
	HX_MARK_MEMBER_NAME(colorDebug,"colorDebug");
	HX_MARK_END_CLASS();
}

void Edge_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(fromConstraintSegments,"fromConstraintSegments");
	HX_VISIT_MEMBER_NAME(_id,"_id");
	HX_VISIT_MEMBER_NAME(_isReal,"_isReal");
	HX_VISIT_MEMBER_NAME(_isConstrained,"_isConstrained");
	HX_VISIT_MEMBER_NAME(_originVertex,"_originVertex");
	HX_VISIT_MEMBER_NAME(_oppositeEdge,"_oppositeEdge");
	HX_VISIT_MEMBER_NAME(_nextLeftEdge,"_nextLeftEdge");
	HX_VISIT_MEMBER_NAME(_leftFace,"_leftFace");
	HX_VISIT_MEMBER_NAME(colorDebug,"colorDebug");
}

Dynamic Edge_obj::__Field(const ::String &inName,bool inCallProp)
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
		if (HX_FIELD_EQ(inName,"isReal") ) { return get_isReal(); }
		if (HX_FIELD_EQ(inName,"get_id") ) { return get_id_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_isReal") ) { return _isReal; }
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"leftFace") ) { return get_leftFace(); }
		if (HX_FIELD_EQ(inName,"setDatas") ) { return setDatas_dyn(); }
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"rightFace") ) { return get_rightFace(); }
		if (HX_FIELD_EQ(inName,"_leftFace") ) { return _leftFace; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"colorDebug") ) { return colorDebug; }
		if (HX_FIELD_EQ(inName,"get_isReal") ) { return get_isReal_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"rotLeftEdge") ) { return get_rotLeftEdge(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"originVertex") ) { return get_originVertex(); }
		if (HX_FIELD_EQ(inName,"nextLeftEdge") ) { return get_nextLeftEdge(); }
		if (HX_FIELD_EQ(inName,"oppositeEdge") ) { return get_oppositeEdge(); }
		if (HX_FIELD_EQ(inName,"prevLeftEdge") ) { return get_prevLeftEdge(); }
		if (HX_FIELD_EQ(inName,"rotRightEdge") ) { return get_rotRightEdge(); }
		if (HX_FIELD_EQ(inName,"set_leftFace") ) { return set_leftFace_dyn(); }
		if (HX_FIELD_EQ(inName,"get_leftFace") ) { return get_leftFace_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"isConstrained") ) { return get_isConstrained(); }
		if (HX_FIELD_EQ(inName,"nextRightEdge") ) { return get_nextRightEdge(); }
		if (HX_FIELD_EQ(inName,"prevRightEdge") ) { return get_prevRightEdge(); }
		if (HX_FIELD_EQ(inName,"_originVertex") ) { return _originVertex; }
		if (HX_FIELD_EQ(inName,"_oppositeEdge") ) { return _oppositeEdge; }
		if (HX_FIELD_EQ(inName,"_nextLeftEdge") ) { return _nextLeftEdge; }
		if (HX_FIELD_EQ(inName,"get_rightFace") ) { return get_rightFace_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_isConstrained") ) { return _isConstrained; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"get_rotLeftEdge") ) { return get_rotLeftEdge_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"set_originVertex") ) { return set_originVertex_dyn(); }
		if (HX_FIELD_EQ(inName,"set_nextLeftEdge") ) { return set_nextLeftEdge_dyn(); }
		if (HX_FIELD_EQ(inName,"get_originVertex") ) { return get_originVertex_dyn(); }
		if (HX_FIELD_EQ(inName,"get_oppositeEdge") ) { return get_oppositeEdge_dyn(); }
		if (HX_FIELD_EQ(inName,"get_nextLeftEdge") ) { return get_nextLeftEdge_dyn(); }
		if (HX_FIELD_EQ(inName,"get_prevLeftEdge") ) { return get_prevLeftEdge_dyn(); }
		if (HX_FIELD_EQ(inName,"get_rotRightEdge") ) { return get_rotRightEdge_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"destinationVertex") ) { return get_destinationVertex(); }
		if (HX_FIELD_EQ(inName,"get_isConstrained") ) { return get_isConstrained_dyn(); }
		if (HX_FIELD_EQ(inName,"set_isConstrained") ) { return set_isConstrained_dyn(); }
		if (HX_FIELD_EQ(inName,"get_nextRightEdge") ) { return get_nextRightEdge_dyn(); }
		if (HX_FIELD_EQ(inName,"get_prevRightEdge") ) { return get_prevRightEdge_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"get_destinationVertex") ) { return get_destinationVertex_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"fromConstraintSegments") ) { return fromConstraintSegments; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"addFromConstraintSegment") ) { return addFromConstraintSegment_dyn(); }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"removeFromConstraintSegment") ) { return removeFromConstraintSegment_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Edge_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"INC") ) { INC=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_id") ) { _id=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_isReal") ) { _isReal=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"leftFace") ) { return set_leftFace(inValue); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_leftFace") ) { _leftFace=inValue.Cast< ::hxDaedalus::data::Face >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"colorDebug") ) { colorDebug=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"originVertex") ) { return set_originVertex(inValue); }
		if (HX_FIELD_EQ(inName,"nextLeftEdge") ) { return set_nextLeftEdge(inValue); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"isConstrained") ) { return set_isConstrained(inValue); }
		if (HX_FIELD_EQ(inName,"_originVertex") ) { _originVertex=inValue.Cast< ::hxDaedalus::data::Vertex >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_oppositeEdge") ) { _oppositeEdge=inValue.Cast< ::hxDaedalus::data::Edge >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_nextLeftEdge") ) { _nextLeftEdge=inValue.Cast< ::hxDaedalus::data::Edge >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_isConstrained") ) { _isConstrained=inValue.Cast< bool >(); return inValue; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"fromConstraintSegments") ) { fromConstraintSegments=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Edge_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("id"));
	outFields->push(HX_CSTRING("isReal"));
	outFields->push(HX_CSTRING("isConstrained"));
	outFields->push(HX_CSTRING("originVertex"));
	outFields->push(HX_CSTRING("nextLeftEdge"));
	outFields->push(HX_CSTRING("leftFace"));
	outFields->push(HX_CSTRING("fromConstraintSegments"));
	outFields->push(HX_CSTRING("destinationVertex"));
	outFields->push(HX_CSTRING("oppositeEdge"));
	outFields->push(HX_CSTRING("prevLeftEdge"));
	outFields->push(HX_CSTRING("nextRightEdge"));
	outFields->push(HX_CSTRING("prevRightEdge"));
	outFields->push(HX_CSTRING("rotLeftEdge"));
	outFields->push(HX_CSTRING("rotRightEdge"));
	outFields->push(HX_CSTRING("rightFace"));
	outFields->push(HX_CSTRING("_id"));
	outFields->push(HX_CSTRING("_isReal"));
	outFields->push(HX_CSTRING("_isConstrained"));
	outFields->push(HX_CSTRING("_originVertex"));
	outFields->push(HX_CSTRING("_oppositeEdge"));
	outFields->push(HX_CSTRING("_nextLeftEdge"));
	outFields->push(HX_CSTRING("_leftFace"));
	outFields->push(HX_CSTRING("colorDebug"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("INC"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(Edge_obj,fromConstraintSegments),HX_CSTRING("fromConstraintSegments")},
	{hx::fsInt,(int)offsetof(Edge_obj,_id),HX_CSTRING("_id")},
	{hx::fsBool,(int)offsetof(Edge_obj,_isReal),HX_CSTRING("_isReal")},
	{hx::fsBool,(int)offsetof(Edge_obj,_isConstrained),HX_CSTRING("_isConstrained")},
	{hx::fsObject /*::hxDaedalus::data::Vertex*/ ,(int)offsetof(Edge_obj,_originVertex),HX_CSTRING("_originVertex")},
	{hx::fsObject /*::hxDaedalus::data::Edge*/ ,(int)offsetof(Edge_obj,_oppositeEdge),HX_CSTRING("_oppositeEdge")},
	{hx::fsObject /*::hxDaedalus::data::Edge*/ ,(int)offsetof(Edge_obj,_nextLeftEdge),HX_CSTRING("_nextLeftEdge")},
	{hx::fsObject /*::hxDaedalus::data::Face*/ ,(int)offsetof(Edge_obj,_leftFace),HX_CSTRING("_leftFace")},
	{hx::fsInt,(int)offsetof(Edge_obj,colorDebug),HX_CSTRING("colorDebug")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("fromConstraintSegments"),
	HX_CSTRING("_id"),
	HX_CSTRING("_isReal"),
	HX_CSTRING("_isConstrained"),
	HX_CSTRING("_originVertex"),
	HX_CSTRING("_oppositeEdge"),
	HX_CSTRING("_nextLeftEdge"),
	HX_CSTRING("_leftFace"),
	HX_CSTRING("colorDebug"),
	HX_CSTRING("get_id"),
	HX_CSTRING("get_isReal"),
	HX_CSTRING("get_isConstrained"),
	HX_CSTRING("setDatas"),
	HX_CSTRING("addFromConstraintSegment"),
	HX_CSTRING("removeFromConstraintSegment"),
	HX_CSTRING("set_originVertex"),
	HX_CSTRING("set_nextLeftEdge"),
	HX_CSTRING("set_leftFace"),
	HX_CSTRING("set_isConstrained"),
	HX_CSTRING("dispose"),
	HX_CSTRING("get_originVertex"),
	HX_CSTRING("get_destinationVertex"),
	HX_CSTRING("get_oppositeEdge"),
	HX_CSTRING("get_nextLeftEdge"),
	HX_CSTRING("get_prevLeftEdge"),
	HX_CSTRING("get_nextRightEdge"),
	HX_CSTRING("get_prevRightEdge"),
	HX_CSTRING("get_rotLeftEdge"),
	HX_CSTRING("get_rotRightEdge"),
	HX_CSTRING("get_leftFace"),
	HX_CSTRING("get_rightFace"),
	HX_CSTRING("toString"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Edge_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Edge_obj::INC,"INC");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Edge_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Edge_obj::INC,"INC");
};

#endif

Class Edge_obj::__mClass;

void Edge_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDaedalus.data.Edge"), hx::TCanCast< Edge_obj> ,sStaticFields,sMemberFields,
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

void Edge_obj::__boot()
{
	INC= (int)0;
}

} // end namespace hxDaedalus
} // end namespace data
