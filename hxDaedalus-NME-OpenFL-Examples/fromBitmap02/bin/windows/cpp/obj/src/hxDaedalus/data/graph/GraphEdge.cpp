#include <hxcpp.h>

#ifndef INCLUDED_hxDaedalus_data_graph_GraphEdge
#include <hxDaedalus/data/graph/GraphEdge.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_graph_GraphNode
#include <hxDaedalus/data/graph/GraphNode.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_math_EdgeData
#include <hxDaedalus/data/math/EdgeData.h>
#endif
namespace hxDaedalus{
namespace data{
namespace graph{

Void GraphEdge_obj::__construct()
{
HX_STACK_FRAME("hxDaedalus.data.graph.GraphEdge","new",0xd56d0ad2,"hxDaedalus.data.graph.GraphEdge.new","hxDaedalus/data/graph/GraphEdge.hx",29,0x04a026bf)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(30)
	this->_id = ::hxDaedalus::data::graph::GraphEdge_obj::INC;
	HX_STACK_LINE(31)
	(::hxDaedalus::data::graph::GraphEdge_obj::INC)++;
}
;
	return null();
}

//GraphEdge_obj::~GraphEdge_obj() { }

Dynamic GraphEdge_obj::__CreateEmpty() { return  new GraphEdge_obj; }
hx::ObjectPtr< GraphEdge_obj > GraphEdge_obj::__new()
{  hx::ObjectPtr< GraphEdge_obj > result = new GraphEdge_obj();
	result->__construct();
	return result;}

Dynamic GraphEdge_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< GraphEdge_obj > result = new GraphEdge_obj();
	result->__construct();
	return result;}

int GraphEdge_obj::get_id( ){
	HX_STACK_FRAME("hxDaedalus.data.graph.GraphEdge","get_id",0xe5714bf2,"hxDaedalus.data.graph.GraphEdge.get_id","hxDaedalus/data/graph/GraphEdge.hx",9,0x04a026bf)
	HX_STACK_THIS(this)
	HX_STACK_LINE(9)
	return this->_id;
}


HX_DEFINE_DYNAMIC_FUNC0(GraphEdge_obj,get_id,return )

Void GraphEdge_obj::dispose( ){
{
		HX_STACK_FRAME("hxDaedalus.data.graph.GraphEdge","dispose",0x7238dc11,"hxDaedalus.data.graph.GraphEdge.dispose","hxDaedalus/data/graph/GraphEdge.hx",34,0x04a026bf)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GraphEdge_obj,dispose,(void))

::hxDaedalus::data::graph::GraphEdge GraphEdge_obj::get_prev( ){
	HX_STACK_FRAME("hxDaedalus.data.graph.GraphEdge","get_prev",0x21fd22ca,"hxDaedalus.data.graph.GraphEdge.get_prev","hxDaedalus/data/graph/GraphEdge.hx",37,0x04a026bf)
	HX_STACK_THIS(this)
	HX_STACK_LINE(37)
	return this->_prev;
}


HX_DEFINE_DYNAMIC_FUNC0(GraphEdge_obj,get_prev,return )

::hxDaedalus::data::graph::GraphEdge GraphEdge_obj::set_prev( ::hxDaedalus::data::graph::GraphEdge value){
	HX_STACK_FRAME("hxDaedalus.data.graph.GraphEdge","set_prev",0xd05a7c3e,"hxDaedalus.data.graph.GraphEdge.set_prev","hxDaedalus/data/graph/GraphEdge.hx",40,0x04a026bf)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(41)
	this->_prev = value;
	HX_STACK_LINE(42)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(GraphEdge_obj,set_prev,return )

::hxDaedalus::data::graph::GraphEdge GraphEdge_obj::get_next( ){
	HX_STACK_FRAME("hxDaedalus.data.graph.GraphEdge","get_next",0x20a0e8ca,"hxDaedalus.data.graph.GraphEdge.get_next","hxDaedalus/data/graph/GraphEdge.hx",46,0x04a026bf)
	HX_STACK_THIS(this)
	HX_STACK_LINE(46)
	return this->_next;
}


HX_DEFINE_DYNAMIC_FUNC0(GraphEdge_obj,get_next,return )

::hxDaedalus::data::graph::GraphEdge GraphEdge_obj::set_next( ::hxDaedalus::data::graph::GraphEdge value){
	HX_STACK_FRAME("hxDaedalus.data.graph.GraphEdge","set_next",0xcefe423e,"hxDaedalus.data.graph.GraphEdge.set_next","hxDaedalus/data/graph/GraphEdge.hx",49,0x04a026bf)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(50)
	this->_next = value;
	HX_STACK_LINE(51)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(GraphEdge_obj,set_next,return )

::hxDaedalus::data::graph::GraphEdge GraphEdge_obj::get_rotPrevEdge( ){
	HX_STACK_FRAME("hxDaedalus.data.graph.GraphEdge","get_rotPrevEdge",0x41e98b10,"hxDaedalus.data.graph.GraphEdge.get_rotPrevEdge","hxDaedalus/data/graph/GraphEdge.hx",55,0x04a026bf)
	HX_STACK_THIS(this)
	HX_STACK_LINE(55)
	return this->_rotPrevEdge;
}


HX_DEFINE_DYNAMIC_FUNC0(GraphEdge_obj,get_rotPrevEdge,return )

::hxDaedalus::data::graph::GraphEdge GraphEdge_obj::set_rotPrevEdge( ::hxDaedalus::data::graph::GraphEdge value){
	HX_STACK_FRAME("hxDaedalus.data.graph.GraphEdge","set_rotPrevEdge",0x3db5081c,"hxDaedalus.data.graph.GraphEdge.set_rotPrevEdge","hxDaedalus/data/graph/GraphEdge.hx",59,0x04a026bf)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(60)
	this->_rotPrevEdge = value;
	HX_STACK_LINE(61)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(GraphEdge_obj,set_rotPrevEdge,return )

::hxDaedalus::data::graph::GraphEdge GraphEdge_obj::get_rotNextEdge( ){
	HX_STACK_FRAME("hxDaedalus.data.graph.GraphEdge","get_rotNextEdge",0x24e85110,"hxDaedalus.data.graph.GraphEdge.get_rotNextEdge","hxDaedalus/data/graph/GraphEdge.hx",65,0x04a026bf)
	HX_STACK_THIS(this)
	HX_STACK_LINE(65)
	return this->_rotNextEdge;
}


HX_DEFINE_DYNAMIC_FUNC0(GraphEdge_obj,get_rotNextEdge,return )

::hxDaedalus::data::graph::GraphEdge GraphEdge_obj::set_rotNextEdge( ::hxDaedalus::data::graph::GraphEdge value){
	HX_STACK_FRAME("hxDaedalus.data.graph.GraphEdge","set_rotNextEdge",0x20b3ce1c,"hxDaedalus.data.graph.GraphEdge.set_rotNextEdge","hxDaedalus/data/graph/GraphEdge.hx",68,0x04a026bf)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(69)
	this->_rotNextEdge = value;
	HX_STACK_LINE(70)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(GraphEdge_obj,set_rotNextEdge,return )

::hxDaedalus::data::graph::GraphEdge GraphEdge_obj::get_oppositeEdge( ){
	HX_STACK_FRAME("hxDaedalus.data.graph.GraphEdge","get_oppositeEdge",0x1b465f9b,"hxDaedalus.data.graph.GraphEdge.get_oppositeEdge","hxDaedalus/data/graph/GraphEdge.hx",74,0x04a026bf)
	HX_STACK_THIS(this)
	HX_STACK_LINE(74)
	return this->_oppositeEdge;
}


HX_DEFINE_DYNAMIC_FUNC0(GraphEdge_obj,get_oppositeEdge,return )

::hxDaedalus::data::graph::GraphEdge GraphEdge_obj::set_oppositeEdge( ::hxDaedalus::data::graph::GraphEdge value){
	HX_STACK_FRAME("hxDaedalus.data.graph.GraphEdge","set_oppositeEdge",0x71884d0f,"hxDaedalus.data.graph.GraphEdge.set_oppositeEdge","hxDaedalus/data/graph/GraphEdge.hx",78,0x04a026bf)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(79)
	this->_oppositeEdge = value;
	HX_STACK_LINE(80)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(GraphEdge_obj,set_oppositeEdge,return )

::hxDaedalus::data::graph::GraphNode GraphEdge_obj::get_sourceNode( ){
	HX_STACK_FRAME("hxDaedalus.data.graph.GraphEdge","get_sourceNode",0x8cff4f94,"hxDaedalus.data.graph.GraphEdge.get_sourceNode","hxDaedalus/data/graph/GraphEdge.hx",85,0x04a026bf)
	HX_STACK_THIS(this)
	HX_STACK_LINE(85)
	return this->_sourceNode;
}


HX_DEFINE_DYNAMIC_FUNC0(GraphEdge_obj,get_sourceNode,return )

::hxDaedalus::data::graph::GraphNode GraphEdge_obj::set_sourceNode( ::hxDaedalus::data::graph::GraphNode value){
	HX_STACK_FRAME("hxDaedalus.data.graph.GraphEdge","set_sourceNode",0xad1f3808,"hxDaedalus.data.graph.GraphEdge.set_sourceNode","hxDaedalus/data/graph/GraphEdge.hx",89,0x04a026bf)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(90)
	this->_sourceNode = value;
	HX_STACK_LINE(91)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(GraphEdge_obj,set_sourceNode,return )

::hxDaedalus::data::graph::GraphNode GraphEdge_obj::get_destinationNode( ){
	HX_STACK_FRAME("hxDaedalus.data.graph.GraphEdge","get_destinationNode",0xde9dad39,"hxDaedalus.data.graph.GraphEdge.get_destinationNode","hxDaedalus/data/graph/GraphEdge.hx",96,0x04a026bf)
	HX_STACK_THIS(this)
	HX_STACK_LINE(96)
	return this->_destinationNode;
}


HX_DEFINE_DYNAMIC_FUNC0(GraphEdge_obj,get_destinationNode,return )

::hxDaedalus::data::graph::GraphNode GraphEdge_obj::set_destinationNode( ::hxDaedalus::data::graph::GraphNode value){
	HX_STACK_FRAME("hxDaedalus.data.graph.GraphEdge","set_destinationNode",0x1b3aa045,"hxDaedalus.data.graph.GraphEdge.set_destinationNode","hxDaedalus/data/graph/GraphEdge.hx",99,0x04a026bf)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(100)
	this->_destinationNode = value;
	HX_STACK_LINE(101)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(GraphEdge_obj,set_destinationNode,return )

::hxDaedalus::data::math::EdgeData GraphEdge_obj::get_data( ){
	HX_STACK_FRAME("hxDaedalus.data.graph.GraphEdge","get_data",0x1a01ba01,"hxDaedalus.data.graph.GraphEdge.get_data","hxDaedalus/data/graph/GraphEdge.hx",108,0x04a026bf)
	HX_STACK_THIS(this)
	HX_STACK_LINE(108)
	return this->_data;
}


HX_DEFINE_DYNAMIC_FUNC0(GraphEdge_obj,get_data,return )

::hxDaedalus::data::math::EdgeData GraphEdge_obj::set_data( ::hxDaedalus::data::math::EdgeData value){
	HX_STACK_FRAME("hxDaedalus.data.graph.GraphEdge","set_data",0xc85f1375,"hxDaedalus.data.graph.GraphEdge.set_data","hxDaedalus/data/graph/GraphEdge.hx",112,0x04a026bf)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(113)
	this->_data = value;
	HX_STACK_LINE(114)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(GraphEdge_obj,set_data,return )

int GraphEdge_obj::INC;


GraphEdge_obj::GraphEdge_obj()
{
}

void GraphEdge_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(GraphEdge);
	HX_MARK_MEMBER_NAME(_id,"_id");
	HX_MARK_MEMBER_NAME(_prev,"_prev");
	HX_MARK_MEMBER_NAME(_next,"_next");
	HX_MARK_MEMBER_NAME(_rotPrevEdge,"_rotPrevEdge");
	HX_MARK_MEMBER_NAME(_rotNextEdge,"_rotNextEdge");
	HX_MARK_MEMBER_NAME(_oppositeEdge,"_oppositeEdge");
	HX_MARK_MEMBER_NAME(_sourceNode,"_sourceNode");
	HX_MARK_MEMBER_NAME(_destinationNode,"_destinationNode");
	HX_MARK_MEMBER_NAME(_data,"_data");
	HX_MARK_END_CLASS();
}

void GraphEdge_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_id,"_id");
	HX_VISIT_MEMBER_NAME(_prev,"_prev");
	HX_VISIT_MEMBER_NAME(_next,"_next");
	HX_VISIT_MEMBER_NAME(_rotPrevEdge,"_rotPrevEdge");
	HX_VISIT_MEMBER_NAME(_rotNextEdge,"_rotNextEdge");
	HX_VISIT_MEMBER_NAME(_oppositeEdge,"_oppositeEdge");
	HX_VISIT_MEMBER_NAME(_sourceNode,"_sourceNode");
	HX_VISIT_MEMBER_NAME(_destinationNode,"_destinationNode");
	HX_VISIT_MEMBER_NAME(_data,"_data");
}

Dynamic GraphEdge_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { return get_id(); }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"INC") ) { return INC; }
		if (HX_FIELD_EQ(inName,"_id") ) { return _id; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"prev") ) { return get_prev(); }
		if (HX_FIELD_EQ(inName,"next") ) { return get_next(); }
		if (HX_FIELD_EQ(inName,"data") ) { return get_data(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_prev") ) { return _prev; }
		if (HX_FIELD_EQ(inName,"_next") ) { return _next; }
		if (HX_FIELD_EQ(inName,"_data") ) { return _data; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"get_id") ) { return get_id_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"get_prev") ) { return get_prev_dyn(); }
		if (HX_FIELD_EQ(inName,"set_prev") ) { return set_prev_dyn(); }
		if (HX_FIELD_EQ(inName,"get_next") ) { return get_next_dyn(); }
		if (HX_FIELD_EQ(inName,"set_next") ) { return set_next_dyn(); }
		if (HX_FIELD_EQ(inName,"get_data") ) { return get_data_dyn(); }
		if (HX_FIELD_EQ(inName,"set_data") ) { return set_data_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"sourceNode") ) { return get_sourceNode(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"rotPrevEdge") ) { return get_rotPrevEdge(); }
		if (HX_FIELD_EQ(inName,"rotNextEdge") ) { return get_rotNextEdge(); }
		if (HX_FIELD_EQ(inName,"_sourceNode") ) { return _sourceNode; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"oppositeEdge") ) { return get_oppositeEdge(); }
		if (HX_FIELD_EQ(inName,"_rotPrevEdge") ) { return _rotPrevEdge; }
		if (HX_FIELD_EQ(inName,"_rotNextEdge") ) { return _rotNextEdge; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_oppositeEdge") ) { return _oppositeEdge; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"get_sourceNode") ) { return get_sourceNode_dyn(); }
		if (HX_FIELD_EQ(inName,"set_sourceNode") ) { return set_sourceNode_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"destinationNode") ) { return get_destinationNode(); }
		if (HX_FIELD_EQ(inName,"get_rotPrevEdge") ) { return get_rotPrevEdge_dyn(); }
		if (HX_FIELD_EQ(inName,"set_rotPrevEdge") ) { return set_rotPrevEdge_dyn(); }
		if (HX_FIELD_EQ(inName,"get_rotNextEdge") ) { return get_rotNextEdge_dyn(); }
		if (HX_FIELD_EQ(inName,"set_rotNextEdge") ) { return set_rotNextEdge_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_destinationNode") ) { return _destinationNode; }
		if (HX_FIELD_EQ(inName,"get_oppositeEdge") ) { return get_oppositeEdge_dyn(); }
		if (HX_FIELD_EQ(inName,"set_oppositeEdge") ) { return set_oppositeEdge_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"get_destinationNode") ) { return get_destinationNode_dyn(); }
		if (HX_FIELD_EQ(inName,"set_destinationNode") ) { return set_destinationNode_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic GraphEdge_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"INC") ) { INC=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_id") ) { _id=inValue.Cast< int >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"prev") ) { return set_prev(inValue); }
		if (HX_FIELD_EQ(inName,"next") ) { return set_next(inValue); }
		if (HX_FIELD_EQ(inName,"data") ) { return set_data(inValue); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_prev") ) { _prev=inValue.Cast< ::hxDaedalus::data::graph::GraphEdge >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_next") ) { _next=inValue.Cast< ::hxDaedalus::data::graph::GraphEdge >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_data") ) { _data=inValue.Cast< ::hxDaedalus::data::math::EdgeData >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"sourceNode") ) { return set_sourceNode(inValue); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"rotPrevEdge") ) { return set_rotPrevEdge(inValue); }
		if (HX_FIELD_EQ(inName,"rotNextEdge") ) { return set_rotNextEdge(inValue); }
		if (HX_FIELD_EQ(inName,"_sourceNode") ) { _sourceNode=inValue.Cast< ::hxDaedalus::data::graph::GraphNode >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"oppositeEdge") ) { return set_oppositeEdge(inValue); }
		if (HX_FIELD_EQ(inName,"_rotPrevEdge") ) { _rotPrevEdge=inValue.Cast< ::hxDaedalus::data::graph::GraphEdge >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_rotNextEdge") ) { _rotNextEdge=inValue.Cast< ::hxDaedalus::data::graph::GraphEdge >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_oppositeEdge") ) { _oppositeEdge=inValue.Cast< ::hxDaedalus::data::graph::GraphEdge >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"destinationNode") ) { return set_destinationNode(inValue); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_destinationNode") ) { _destinationNode=inValue.Cast< ::hxDaedalus::data::graph::GraphNode >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void GraphEdge_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("id"));
	outFields->push(HX_CSTRING("prev"));
	outFields->push(HX_CSTRING("next"));
	outFields->push(HX_CSTRING("rotPrevEdge"));
	outFields->push(HX_CSTRING("rotNextEdge"));
	outFields->push(HX_CSTRING("oppositeEdge"));
	outFields->push(HX_CSTRING("sourceNode"));
	outFields->push(HX_CSTRING("destinationNode"));
	outFields->push(HX_CSTRING("data"));
	outFields->push(HX_CSTRING("_id"));
	outFields->push(HX_CSTRING("_prev"));
	outFields->push(HX_CSTRING("_next"));
	outFields->push(HX_CSTRING("_rotPrevEdge"));
	outFields->push(HX_CSTRING("_rotNextEdge"));
	outFields->push(HX_CSTRING("_oppositeEdge"));
	outFields->push(HX_CSTRING("_sourceNode"));
	outFields->push(HX_CSTRING("_destinationNode"));
	outFields->push(HX_CSTRING("_data"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("INC"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(GraphEdge_obj,_id),HX_CSTRING("_id")},
	{hx::fsObject /*::hxDaedalus::data::graph::GraphEdge*/ ,(int)offsetof(GraphEdge_obj,_prev),HX_CSTRING("_prev")},
	{hx::fsObject /*::hxDaedalus::data::graph::GraphEdge*/ ,(int)offsetof(GraphEdge_obj,_next),HX_CSTRING("_next")},
	{hx::fsObject /*::hxDaedalus::data::graph::GraphEdge*/ ,(int)offsetof(GraphEdge_obj,_rotPrevEdge),HX_CSTRING("_rotPrevEdge")},
	{hx::fsObject /*::hxDaedalus::data::graph::GraphEdge*/ ,(int)offsetof(GraphEdge_obj,_rotNextEdge),HX_CSTRING("_rotNextEdge")},
	{hx::fsObject /*::hxDaedalus::data::graph::GraphEdge*/ ,(int)offsetof(GraphEdge_obj,_oppositeEdge),HX_CSTRING("_oppositeEdge")},
	{hx::fsObject /*::hxDaedalus::data::graph::GraphNode*/ ,(int)offsetof(GraphEdge_obj,_sourceNode),HX_CSTRING("_sourceNode")},
	{hx::fsObject /*::hxDaedalus::data::graph::GraphNode*/ ,(int)offsetof(GraphEdge_obj,_destinationNode),HX_CSTRING("_destinationNode")},
	{hx::fsObject /*::hxDaedalus::data::math::EdgeData*/ ,(int)offsetof(GraphEdge_obj,_data),HX_CSTRING("_data")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("get_id"),
	HX_CSTRING("_id"),
	HX_CSTRING("_prev"),
	HX_CSTRING("_next"),
	HX_CSTRING("_rotPrevEdge"),
	HX_CSTRING("_rotNextEdge"),
	HX_CSTRING("_oppositeEdge"),
	HX_CSTRING("_sourceNode"),
	HX_CSTRING("_destinationNode"),
	HX_CSTRING("_data"),
	HX_CSTRING("dispose"),
	HX_CSTRING("get_prev"),
	HX_CSTRING("set_prev"),
	HX_CSTRING("get_next"),
	HX_CSTRING("set_next"),
	HX_CSTRING("get_rotPrevEdge"),
	HX_CSTRING("set_rotPrevEdge"),
	HX_CSTRING("get_rotNextEdge"),
	HX_CSTRING("set_rotNextEdge"),
	HX_CSTRING("get_oppositeEdge"),
	HX_CSTRING("set_oppositeEdge"),
	HX_CSTRING("get_sourceNode"),
	HX_CSTRING("set_sourceNode"),
	HX_CSTRING("get_destinationNode"),
	HX_CSTRING("set_destinationNode"),
	HX_CSTRING("get_data"),
	HX_CSTRING("set_data"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(GraphEdge_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(GraphEdge_obj::INC,"INC");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(GraphEdge_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(GraphEdge_obj::INC,"INC");
};

#endif

Class GraphEdge_obj::__mClass;

void GraphEdge_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDaedalus.data.graph.GraphEdge"), hx::TCanCast< GraphEdge_obj> ,sStaticFields,sMemberFields,
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

void GraphEdge_obj::__boot()
{
	INC= (int)0;
}

} // end namespace hxDaedalus
} // end namespace data
} // end namespace graph
