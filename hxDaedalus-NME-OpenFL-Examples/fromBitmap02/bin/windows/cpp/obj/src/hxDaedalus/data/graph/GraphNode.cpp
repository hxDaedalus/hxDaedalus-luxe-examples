#include <hxcpp.h>

#ifndef INCLUDED_IMap
#include <IMap.h>
#endif
#ifndef INCLUDED_haxe_ds_ObjectMap
#include <haxe/ds/ObjectMap.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_graph_GraphEdge
#include <hxDaedalus/data/graph/GraphEdge.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_graph_GraphNode
#include <hxDaedalus/data/graph/GraphNode.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_math_NodeData
#include <hxDaedalus/data/math/NodeData.h>
#endif
namespace hxDaedalus{
namespace data{
namespace graph{

Void GraphNode_obj::__construct()
{
HX_STACK_FRAME("hxDaedalus.data.graph.GraphNode","new",0x6e8d1317,"hxDaedalus.data.graph.GraphNode.new","hxDaedalus/data/graph/GraphNode.hx",28,0x269a8e1a)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(29)
	this->_id = ::hxDaedalus::data::graph::GraphNode_obj::INC;
	HX_STACK_LINE(30)
	(::hxDaedalus::data::graph::GraphNode_obj::INC)++;
	HX_STACK_LINE(32)
	::haxe::ds::ObjectMap _g = ::haxe::ds::ObjectMap_obj::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(32)
	this->_successorNodes = _g;
}
;
	return null();
}

//GraphNode_obj::~GraphNode_obj() { }

Dynamic GraphNode_obj::__CreateEmpty() { return  new GraphNode_obj; }
hx::ObjectPtr< GraphNode_obj > GraphNode_obj::__new()
{  hx::ObjectPtr< GraphNode_obj > result = new GraphNode_obj();
	result->__construct();
	return result;}

Dynamic GraphNode_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< GraphNode_obj > result = new GraphNode_obj();
	result->__construct();
	return result;}

int GraphNode_obj::get_id( ){
	HX_STACK_FRAME("hxDaedalus.data.graph.GraphNode","get_id",0x37a1fccd,"hxDaedalus.data.graph.GraphNode.get_id","hxDaedalus/data/graph/GraphNode.hx",36,0x269a8e1a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(36)
	return this->_id;
}


HX_DEFINE_DYNAMIC_FUNC0(GraphNode_obj,get_id,return )

Void GraphNode_obj::dispose( ){
{
		HX_STACK_FRAME("hxDaedalus.data.graph.GraphNode","dispose",0x0aa2ead6,"hxDaedalus.data.graph.GraphNode.dispose","hxDaedalus/data/graph/GraphNode.hx",40,0x269a8e1a)
		HX_STACK_THIS(this)
		HX_STACK_LINE(41)
		this->_prev = null();
		HX_STACK_LINE(42)
		this->_next = null();
		HX_STACK_LINE(43)
		this->_outgoingEdge = null();
		HX_STACK_LINE(44)
		this->_successorNodes = null();
		HX_STACK_LINE(45)
		this->_data = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GraphNode_obj,dispose,(void))

::hxDaedalus::data::graph::GraphNode GraphNode_obj::get_prev( ){
	HX_STACK_FRAME("hxDaedalus.data.graph.GraphNode","get_prev",0xe6600065,"hxDaedalus.data.graph.GraphNode.get_prev","hxDaedalus/data/graph/GraphNode.hx",50,0x269a8e1a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(50)
	return this->_prev;
}


HX_DEFINE_DYNAMIC_FUNC0(GraphNode_obj,get_prev,return )

::hxDaedalus::data::graph::GraphNode GraphNode_obj::set_prev( ::hxDaedalus::data::graph::GraphNode value){
	HX_STACK_FRAME("hxDaedalus.data.graph.GraphNode","set_prev",0x94bd59d9,"hxDaedalus.data.graph.GraphNode.set_prev","hxDaedalus/data/graph/GraphNode.hx",54,0x269a8e1a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(55)
	this->_prev = value;
	HX_STACK_LINE(56)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(GraphNode_obj,set_prev,return )

::hxDaedalus::data::graph::GraphNode GraphNode_obj::get_next( ){
	HX_STACK_FRAME("hxDaedalus.data.graph.GraphNode","get_next",0xe503c665,"hxDaedalus.data.graph.GraphNode.get_next","hxDaedalus/data/graph/GraphNode.hx",61,0x269a8e1a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(61)
	return this->_next;
}


HX_DEFINE_DYNAMIC_FUNC0(GraphNode_obj,get_next,return )

::hxDaedalus::data::graph::GraphNode GraphNode_obj::set_next( ::hxDaedalus::data::graph::GraphNode value){
	HX_STACK_FRAME("hxDaedalus.data.graph.GraphNode","set_next",0x93611fd9,"hxDaedalus.data.graph.GraphNode.set_next","hxDaedalus/data/graph/GraphNode.hx",65,0x269a8e1a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(66)
	this->_next = value;
	HX_STACK_LINE(67)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(GraphNode_obj,set_next,return )

::hxDaedalus::data::graph::GraphEdge GraphNode_obj::get_outgoingEdge( ){
	HX_STACK_FRAME("hxDaedalus.data.graph.GraphNode","get_outgoingEdge",0xfb4eb63b,"hxDaedalus.data.graph.GraphNode.get_outgoingEdge","hxDaedalus/data/graph/GraphNode.hx",72,0x269a8e1a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(72)
	return this->_outgoingEdge;
}


HX_DEFINE_DYNAMIC_FUNC0(GraphNode_obj,get_outgoingEdge,return )

::hxDaedalus::data::graph::GraphEdge GraphNode_obj::set_outgoingEdge( ::hxDaedalus::data::graph::GraphEdge value){
	HX_STACK_FRAME("hxDaedalus.data.graph.GraphNode","set_outgoingEdge",0x5190a3af,"hxDaedalus.data.graph.GraphNode.set_outgoingEdge","hxDaedalus/data/graph/GraphNode.hx",76,0x269a8e1a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(77)
	this->_outgoingEdge = value;
	HX_STACK_LINE(78)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(GraphNode_obj,set_outgoingEdge,return )

::haxe::ds::ObjectMap GraphNode_obj::get_successorNodes( ){
	HX_STACK_FRAME("hxDaedalus.data.graph.GraphNode","get_successorNodes",0x9c4f749d,"hxDaedalus.data.graph.GraphNode.get_successorNodes","hxDaedalus/data/graph/GraphNode.hx",83,0x269a8e1a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(83)
	return this->_successorNodes;
}


HX_DEFINE_DYNAMIC_FUNC0(GraphNode_obj,get_successorNodes,return )

::haxe::ds::ObjectMap GraphNode_obj::set_successorNodes( ::haxe::ds::ObjectMap value){
	HX_STACK_FRAME("hxDaedalus.data.graph.GraphNode","set_successorNodes",0x78fea711,"hxDaedalus.data.graph.GraphNode.set_successorNodes","hxDaedalus/data/graph/GraphNode.hx",87,0x269a8e1a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(88)
	this->_successorNodes = value;
	HX_STACK_LINE(89)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(GraphNode_obj,set_successorNodes,return )

::hxDaedalus::data::math::NodeData GraphNode_obj::get_data( ){
	HX_STACK_FRAME("hxDaedalus.data.graph.GraphNode","get_data",0xde64979c,"hxDaedalus.data.graph.GraphNode.get_data","hxDaedalus/data/graph/GraphNode.hx",96,0x269a8e1a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(96)
	return this->_data;
}


HX_DEFINE_DYNAMIC_FUNC0(GraphNode_obj,get_data,return )

::hxDaedalus::data::math::NodeData GraphNode_obj::set_data( ::hxDaedalus::data::math::NodeData value){
	HX_STACK_FRAME("hxDaedalus.data.graph.GraphNode","set_data",0x8cc1f110,"hxDaedalus.data.graph.GraphNode.set_data","hxDaedalus/data/graph/GraphNode.hx",100,0x269a8e1a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(101)
	this->_data = value;
	HX_STACK_LINE(102)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(GraphNode_obj,set_data,return )

int GraphNode_obj::INC;


GraphNode_obj::GraphNode_obj()
{
}

void GraphNode_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(GraphNode);
	HX_MARK_MEMBER_NAME(_id,"_id");
	HX_MARK_MEMBER_NAME(_prev,"_prev");
	HX_MARK_MEMBER_NAME(_next,"_next");
	HX_MARK_MEMBER_NAME(_outgoingEdge,"_outgoingEdge");
	HX_MARK_MEMBER_NAME(_successorNodes,"_successorNodes");
	HX_MARK_MEMBER_NAME(_data,"_data");
	HX_MARK_END_CLASS();
}

void GraphNode_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_id,"_id");
	HX_VISIT_MEMBER_NAME(_prev,"_prev");
	HX_VISIT_MEMBER_NAME(_next,"_next");
	HX_VISIT_MEMBER_NAME(_outgoingEdge,"_outgoingEdge");
	HX_VISIT_MEMBER_NAME(_successorNodes,"_successorNodes");
	HX_VISIT_MEMBER_NAME(_data,"_data");
}

Dynamic GraphNode_obj::__Field(const ::String &inName,bool inCallProp)
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
	case 12:
		if (HX_FIELD_EQ(inName,"outgoingEdge") ) { return get_outgoingEdge(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_outgoingEdge") ) { return _outgoingEdge; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"successorNodes") ) { return get_successorNodes(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_successorNodes") ) { return _successorNodes; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"get_outgoingEdge") ) { return get_outgoingEdge_dyn(); }
		if (HX_FIELD_EQ(inName,"set_outgoingEdge") ) { return set_outgoingEdge_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"get_successorNodes") ) { return get_successorNodes_dyn(); }
		if (HX_FIELD_EQ(inName,"set_successorNodes") ) { return set_successorNodes_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic GraphNode_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
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
		if (HX_FIELD_EQ(inName,"_prev") ) { _prev=inValue.Cast< ::hxDaedalus::data::graph::GraphNode >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_next") ) { _next=inValue.Cast< ::hxDaedalus::data::graph::GraphNode >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_data") ) { _data=inValue.Cast< ::hxDaedalus::data::math::NodeData >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"outgoingEdge") ) { return set_outgoingEdge(inValue); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_outgoingEdge") ) { _outgoingEdge=inValue.Cast< ::hxDaedalus::data::graph::GraphEdge >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"successorNodes") ) { return set_successorNodes(inValue); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_successorNodes") ) { _successorNodes=inValue.Cast< ::haxe::ds::ObjectMap >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void GraphNode_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("id"));
	outFields->push(HX_CSTRING("prev"));
	outFields->push(HX_CSTRING("next"));
	outFields->push(HX_CSTRING("outgoingEdge"));
	outFields->push(HX_CSTRING("successorNodes"));
	outFields->push(HX_CSTRING("data"));
	outFields->push(HX_CSTRING("_id"));
	outFields->push(HX_CSTRING("_prev"));
	outFields->push(HX_CSTRING("_next"));
	outFields->push(HX_CSTRING("_outgoingEdge"));
	outFields->push(HX_CSTRING("_successorNodes"));
	outFields->push(HX_CSTRING("_data"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("INC"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(GraphNode_obj,_id),HX_CSTRING("_id")},
	{hx::fsObject /*::hxDaedalus::data::graph::GraphNode*/ ,(int)offsetof(GraphNode_obj,_prev),HX_CSTRING("_prev")},
	{hx::fsObject /*::hxDaedalus::data::graph::GraphNode*/ ,(int)offsetof(GraphNode_obj,_next),HX_CSTRING("_next")},
	{hx::fsObject /*::hxDaedalus::data::graph::GraphEdge*/ ,(int)offsetof(GraphNode_obj,_outgoingEdge),HX_CSTRING("_outgoingEdge")},
	{hx::fsObject /*::haxe::ds::ObjectMap*/ ,(int)offsetof(GraphNode_obj,_successorNodes),HX_CSTRING("_successorNodes")},
	{hx::fsObject /*::hxDaedalus::data::math::NodeData*/ ,(int)offsetof(GraphNode_obj,_data),HX_CSTRING("_data")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("_id"),
	HX_CSTRING("_prev"),
	HX_CSTRING("_next"),
	HX_CSTRING("_outgoingEdge"),
	HX_CSTRING("_successorNodes"),
	HX_CSTRING("_data"),
	HX_CSTRING("get_id"),
	HX_CSTRING("dispose"),
	HX_CSTRING("get_prev"),
	HX_CSTRING("set_prev"),
	HX_CSTRING("get_next"),
	HX_CSTRING("set_next"),
	HX_CSTRING("get_outgoingEdge"),
	HX_CSTRING("set_outgoingEdge"),
	HX_CSTRING("get_successorNodes"),
	HX_CSTRING("set_successorNodes"),
	HX_CSTRING("get_data"),
	HX_CSTRING("set_data"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(GraphNode_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(GraphNode_obj::INC,"INC");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(GraphNode_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(GraphNode_obj::INC,"INC");
};

#endif

Class GraphNode_obj::__mClass;

void GraphNode_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDaedalus.data.graph.GraphNode"), hx::TCanCast< GraphNode_obj> ,sStaticFields,sMemberFields,
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

void GraphNode_obj::__boot()
{
	INC= (int)0;
}

} // end namespace hxDaedalus
} // end namespace data
} // end namespace graph
