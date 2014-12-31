#include <hxcpp.h>

#ifndef INCLUDED_IMap
#include <IMap.h>
#endif
#ifndef INCLUDED_haxe_ds_ObjectMap
#include <haxe/ds/ObjectMap.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_graph_Graph
#include <hxDaedalus/data/graph/Graph.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_graph_GraphEdge
#include <hxDaedalus/data/graph/GraphEdge.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_graph_GraphNode
#include <hxDaedalus/data/graph/GraphNode.h>
#endif
namespace hxDaedalus{
namespace data{
namespace graph{

Void Graph_obj::__construct()
{
HX_STACK_FRAME("hxDaedalus.data.graph.Graph","new",0x5052a675,"hxDaedalus.data.graph.Graph.new","hxDaedalus/data/graph/Graph.hx",19,0xa30e4bfc)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(20)
	this->_id = ::hxDaedalus::data::graph::Graph_obj::INC;
	HX_STACK_LINE(21)
	(::hxDaedalus::data::graph::Graph_obj::INC)++;
}
;
	return null();
}

//Graph_obj::~Graph_obj() { }

Dynamic Graph_obj::__CreateEmpty() { return  new Graph_obj; }
hx::ObjectPtr< Graph_obj > Graph_obj::__new()
{  hx::ObjectPtr< Graph_obj > result = new Graph_obj();
	result->__construct();
	return result;}

Dynamic Graph_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Graph_obj > result = new Graph_obj();
	result->__construct();
	return result;}

int Graph_obj::get_id( ){
	HX_STACK_FRAME("hxDaedalus.data.graph.Graph","get_id",0x677c582f,"hxDaedalus.data.graph.Graph.get_id","hxDaedalus/data/graph/Graph.hx",9,0xa30e4bfc)
	HX_STACK_THIS(this)
	HX_STACK_LINE(9)
	return this->_id;
}


HX_DEFINE_DYNAMIC_FUNC0(Graph_obj,get_id,return )

::hxDaedalus::data::graph::GraphEdge Graph_obj::get_edge( ){
	HX_STACK_FRAME("hxDaedalus.data.graph.Graph","get_edge",0x7ec18191,"hxDaedalus.data.graph.Graph.get_edge","hxDaedalus/data/graph/Graph.hx",11,0xa30e4bfc)
	HX_STACK_THIS(this)
	HX_STACK_LINE(11)
	return this->_edge;
}


HX_DEFINE_DYNAMIC_FUNC0(Graph_obj,get_edge,return )

::hxDaedalus::data::graph::GraphNode Graph_obj::get_node( ){
	HX_STACK_FRAME("hxDaedalus.data.graph.Graph","get_node",0x84bcc356,"hxDaedalus.data.graph.Graph.get_node","hxDaedalus/data/graph/Graph.hx",13,0xa30e4bfc)
	HX_STACK_THIS(this)
	HX_STACK_LINE(13)
	return this->_node;
}


HX_DEFINE_DYNAMIC_FUNC0(Graph_obj,get_node,return )

Void Graph_obj::dispose( ){
{
		HX_STACK_FRAME("hxDaedalus.data.graph.Graph","dispose",0xb9d88534,"hxDaedalus.data.graph.Graph.dispose","hxDaedalus/data/graph/Graph.hx",25,0xa30e4bfc)
		HX_STACK_THIS(this)
		HX_STACK_LINE(25)
		while((true)){
			HX_STACK_LINE(25)
			if ((!(((this->_node != null()))))){
				HX_STACK_LINE(25)
				break;
			}
			HX_STACK_LINE(25)
			this->deleteNode(this->_node);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Graph_obj,dispose,(void))

::hxDaedalus::data::graph::GraphNode Graph_obj::insertNode( ){
	HX_STACK_FRAME("hxDaedalus.data.graph.Graph","insertNode",0xd7405066,"hxDaedalus.data.graph.Graph.insertNode","hxDaedalus/data/graph/Graph.hx",28,0xa30e4bfc)
	HX_STACK_THIS(this)
	HX_STACK_LINE(29)
	::hxDaedalus::data::graph::GraphNode node = ::hxDaedalus::data::graph::GraphNode_obj::__new();		HX_STACK_VAR(node,"node");
	HX_STACK_LINE(30)
	if (((this->_node != null()))){
		HX_STACK_LINE(31)
		node->set_next(this->_node);
		HX_STACK_LINE(32)
		this->_node->set_prev(node);
	}
	HX_STACK_LINE(34)
	this->_node = node;
	HX_STACK_LINE(35)
	return node;
}


HX_DEFINE_DYNAMIC_FUNC0(Graph_obj,insertNode,return )

Void Graph_obj::deleteNode( ::hxDaedalus::data::graph::GraphNode node){
{
		HX_STACK_FRAME("hxDaedalus.data.graph.Graph","deleteNode",0x44a22e58,"hxDaedalus.data.graph.Graph.deleteNode","hxDaedalus/data/graph/Graph.hx",38,0xa30e4bfc)
		HX_STACK_THIS(this)
		HX_STACK_ARG(node,"node")
		HX_STACK_LINE(39)
		while((true)){
			HX_STACK_LINE(39)
			::hxDaedalus::data::graph::GraphEdge _g = node->get_outgoingEdge();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(39)
			if ((!(((_g != null()))))){
				HX_STACK_LINE(39)
				break;
			}
			HX_STACK_LINE(40)
			::hxDaedalus::data::graph::GraphEdge _g1 = node->get_outgoingEdge()->get_oppositeEdge();		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(40)
			if (((_g1 != null()))){
				HX_STACK_LINE(40)
				::hxDaedalus::data::graph::GraphEdge _g2 = node->get_outgoingEdge()->get_oppositeEdge();		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(40)
				this->deleteEdge(_g2);
			}
			HX_STACK_LINE(41)
			::hxDaedalus::data::graph::GraphEdge _g3 = node->get_outgoingEdge();		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(41)
			this->deleteEdge(_g3);
		}
		HX_STACK_LINE(44)
		::hxDaedalus::data::graph::GraphNode otherNode = this->_node;		HX_STACK_VAR(otherNode,"otherNode");
		HX_STACK_LINE(45)
		::hxDaedalus::data::graph::GraphEdge incomingEdge;		HX_STACK_VAR(incomingEdge,"incomingEdge");
		HX_STACK_LINE(46)
		while((true)){
			HX_STACK_LINE(46)
			if ((!(((otherNode != null()))))){
				HX_STACK_LINE(46)
				break;
			}
			HX_STACK_LINE(47)
			::hxDaedalus::data::graph::GraphEdge _g4;		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(47)
			{
				HX_STACK_LINE(47)
				::IMap this1 = otherNode->get_successorNodes();		HX_STACK_VAR(this1,"this1");
				HX_STACK_LINE(47)
				_g4 = this1->get(node);
			}
			HX_STACK_LINE(47)
			incomingEdge = _g4;
			HX_STACK_LINE(48)
			if (((incomingEdge != null()))){
				HX_STACK_LINE(48)
				this->deleteEdge(incomingEdge);
			}
			HX_STACK_LINE(49)
			::hxDaedalus::data::graph::GraphNode _g5 = otherNode->get_next();		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(49)
			otherNode = _g5;
		}
		HX_STACK_LINE(52)
		if (((this->_node == node))){
			HX_STACK_LINE(53)
			::hxDaedalus::data::graph::GraphNode _g6 = node->get_next();		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(53)
			if (((_g6 != null()))){
				HX_STACK_LINE(54)
				node->get_next()->set_prev(null());
				HX_STACK_LINE(55)
				::hxDaedalus::data::graph::GraphNode _g7 = node->get_next();		HX_STACK_VAR(_g7,"_g7");
				HX_STACK_LINE(55)
				this->_node = _g7;
			}
			else{
				HX_STACK_LINE(57)
				this->_node = null();
			}
		}
		else{
			HX_STACK_LINE(60)
			::hxDaedalus::data::graph::GraphNode _g8 = node->get_next();		HX_STACK_VAR(_g8,"_g8");
			HX_STACK_LINE(60)
			if (((_g8 != null()))){
				HX_STACK_LINE(61)
				::hxDaedalus::data::graph::GraphNode _g9 = node->get_next();		HX_STACK_VAR(_g9,"_g9");
				HX_STACK_LINE(61)
				node->get_prev()->set_next(_g9);
				HX_STACK_LINE(62)
				::hxDaedalus::data::graph::GraphNode _g10 = node->get_prev();		HX_STACK_VAR(_g10,"_g10");
				HX_STACK_LINE(62)
				node->get_next()->set_prev(_g10);
			}
			else{
				HX_STACK_LINE(64)
				node->get_prev()->set_next(null());
			}
		}
		HX_STACK_LINE(68)
		node->dispose();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Graph_obj,deleteNode,(void))

::hxDaedalus::data::graph::GraphEdge Graph_obj::insertEdge( ::hxDaedalus::data::graph::GraphNode fromNode,::hxDaedalus::data::graph::GraphNode toNode){
	HX_STACK_FRAME("hxDaedalus.data.graph.Graph","insertEdge",0xd1450ea1,"hxDaedalus.data.graph.Graph.insertEdge","hxDaedalus/data/graph/Graph.hx",71,0xa30e4bfc)
	HX_STACK_THIS(this)
	HX_STACK_ARG(fromNode,"fromNode")
	HX_STACK_ARG(toNode,"toNode")
	HX_STACK_LINE(72)
	::hxDaedalus::data::graph::GraphEdge _g;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(72)
	{
		HX_STACK_LINE(72)
		::IMap this1 = fromNode->get_successorNodes();		HX_STACK_VAR(this1,"this1");
		HX_STACK_LINE(72)
		_g = this1->get(toNode);
	}
	HX_STACK_LINE(72)
	if (((_g != null()))){
		HX_STACK_LINE(72)
		return null();
	}
	HX_STACK_LINE(74)
	::hxDaedalus::data::graph::GraphEdge edge = ::hxDaedalus::data::graph::GraphEdge_obj::__new();		HX_STACK_VAR(edge,"edge");
	HX_STACK_LINE(75)
	if (((this->_edge != null()))){
		HX_STACK_LINE(76)
		this->_edge->set_prev(edge);
		HX_STACK_LINE(77)
		edge->set_next(this->_edge);
	}
	HX_STACK_LINE(79)
	this->_edge = edge;
	HX_STACK_LINE(81)
	edge->set_sourceNode(fromNode);
	HX_STACK_LINE(82)
	edge->set_destinationNode(toNode);
	HX_STACK_LINE(83)
	{
		HX_STACK_LINE(83)
		::IMap this1 = fromNode->get_successorNodes();		HX_STACK_VAR(this1,"this1");
		HX_STACK_LINE(83)
		this1->set(toNode,edge);
		HX_STACK_LINE(83)
		edge;
	}
	HX_STACK_LINE(84)
	::hxDaedalus::data::graph::GraphEdge _g1 = fromNode->get_outgoingEdge();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(84)
	if (((_g1 != null()))){
		HX_STACK_LINE(85)
		fromNode->get_outgoingEdge()->set_rotPrevEdge(edge);
		HX_STACK_LINE(86)
		::hxDaedalus::data::graph::GraphEdge _g2 = fromNode->get_outgoingEdge();		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(86)
		edge->set_rotNextEdge(_g2);
		HX_STACK_LINE(87)
		fromNode->set_outgoingEdge(edge);
	}
	else{
		HX_STACK_LINE(89)
		fromNode->set_outgoingEdge(edge);
	}
	HX_STACK_LINE(92)
	::hxDaedalus::data::graph::GraphEdge oppositeEdge;		HX_STACK_VAR(oppositeEdge,"oppositeEdge");
	HX_STACK_LINE(92)
	{
		HX_STACK_LINE(92)
		::IMap this1 = toNode->get_successorNodes();		HX_STACK_VAR(this1,"this1");
		HX_STACK_LINE(92)
		oppositeEdge = this1->get(fromNode);
	}
	HX_STACK_LINE(93)
	if (((oppositeEdge != null()))){
		HX_STACK_LINE(94)
		edge->set_oppositeEdge(oppositeEdge);
		HX_STACK_LINE(95)
		oppositeEdge->set_oppositeEdge(edge);
	}
	HX_STACK_LINE(98)
	return edge;
}


HX_DEFINE_DYNAMIC_FUNC2(Graph_obj,insertEdge,return )

Void Graph_obj::deleteEdge( ::hxDaedalus::data::graph::GraphEdge edge){
{
		HX_STACK_FRAME("hxDaedalus.data.graph.Graph","deleteEdge",0x3ea6ec93,"hxDaedalus.data.graph.Graph.deleteEdge","hxDaedalus/data/graph/Graph.hx",101,0xa30e4bfc)
		HX_STACK_THIS(this)
		HX_STACK_ARG(edge,"edge")
		HX_STACK_LINE(102)
		if (((this->_edge == edge))){
			HX_STACK_LINE(103)
			::hxDaedalus::data::graph::GraphEdge _g = edge->get_next();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(103)
			if (((_g != null()))){
				HX_STACK_LINE(104)
				edge->get_next()->set_prev(null());
				HX_STACK_LINE(105)
				::hxDaedalus::data::graph::GraphEdge _g1 = edge->get_next();		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(105)
				this->_edge = _g1;
			}
			else{
				HX_STACK_LINE(107)
				this->_edge = null();
			}
		}
		else{
			HX_STACK_LINE(110)
			::hxDaedalus::data::graph::GraphEdge _g2 = edge->get_next();		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(110)
			if (((_g2 != null()))){
				HX_STACK_LINE(111)
				::hxDaedalus::data::graph::GraphEdge _g3 = edge->get_next();		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(111)
				edge->get_prev()->set_next(_g3);
				HX_STACK_LINE(112)
				::hxDaedalus::data::graph::GraphEdge _g4 = edge->get_prev();		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(112)
				edge->get_next()->set_prev(_g4);
			}
			else{
				HX_STACK_LINE(114)
				edge->get_prev()->set_next(null());
			}
		}
		HX_STACK_LINE(118)
		::hxDaedalus::data::graph::GraphEdge _g5 = edge->get_sourceNode()->get_outgoingEdge();		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(118)
		if (((_g5 == edge))){
			HX_STACK_LINE(119)
			::hxDaedalus::data::graph::GraphEdge _g6 = edge->get_rotNextEdge();		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(119)
			if (((_g6 != null()))){
				HX_STACK_LINE(120)
				edge->get_rotNextEdge()->set_rotPrevEdge(null());
				HX_STACK_LINE(121)
				::hxDaedalus::data::graph::GraphEdge _g7 = edge->get_rotNextEdge();		HX_STACK_VAR(_g7,"_g7");
				HX_STACK_LINE(121)
				edge->get_sourceNode()->set_outgoingEdge(_g7);
			}
			else{
				HX_STACK_LINE(123)
				edge->get_sourceNode()->set_outgoingEdge(null());
			}
		}
		else{
			HX_STACK_LINE(126)
			::hxDaedalus::data::graph::GraphEdge _g8 = edge->get_rotNextEdge();		HX_STACK_VAR(_g8,"_g8");
			HX_STACK_LINE(126)
			if (((_g8 != null()))){
				HX_STACK_LINE(127)
				::hxDaedalus::data::graph::GraphEdge _g9 = edge->get_rotNextEdge();		HX_STACK_VAR(_g9,"_g9");
				HX_STACK_LINE(127)
				edge->get_rotPrevEdge()->set_rotNextEdge(_g9);
				HX_STACK_LINE(128)
				::hxDaedalus::data::graph::GraphEdge _g10 = edge->get_rotPrevEdge();		HX_STACK_VAR(_g10,"_g10");
				HX_STACK_LINE(128)
				edge->get_rotNextEdge()->set_rotPrevEdge(_g10);
			}
			else{
				HX_STACK_LINE(130)
				edge->get_rotPrevEdge()->set_rotNextEdge(null());
			}
		}
		HX_STACK_LINE(133)
		edge->dispose();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Graph_obj,deleteEdge,(void))

int Graph_obj::INC;


Graph_obj::Graph_obj()
{
}

void Graph_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Graph);
	HX_MARK_MEMBER_NAME(_id,"_id");
	HX_MARK_MEMBER_NAME(_node,"_node");
	HX_MARK_MEMBER_NAME(_edge,"_edge");
	HX_MARK_END_CLASS();
}

void Graph_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_id,"_id");
	HX_VISIT_MEMBER_NAME(_node,"_node");
	HX_VISIT_MEMBER_NAME(_edge,"_edge");
}

Dynamic Graph_obj::__Field(const ::String &inName,bool inCallProp)
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
		if (HX_FIELD_EQ(inName,"edge") ) { return get_edge(); }
		if (HX_FIELD_EQ(inName,"node") ) { return get_node(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_node") ) { return _node; }
		if (HX_FIELD_EQ(inName,"_edge") ) { return _edge; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"get_id") ) { return get_id_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"get_edge") ) { return get_edge_dyn(); }
		if (HX_FIELD_EQ(inName,"get_node") ) { return get_node_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"insertNode") ) { return insertNode_dyn(); }
		if (HX_FIELD_EQ(inName,"deleteNode") ) { return deleteNode_dyn(); }
		if (HX_FIELD_EQ(inName,"insertEdge") ) { return insertEdge_dyn(); }
		if (HX_FIELD_EQ(inName,"deleteEdge") ) { return deleteEdge_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Graph_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"INC") ) { INC=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_id") ) { _id=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_node") ) { _node=inValue.Cast< ::hxDaedalus::data::graph::GraphNode >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_edge") ) { _edge=inValue.Cast< ::hxDaedalus::data::graph::GraphEdge >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Graph_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("id"));
	outFields->push(HX_CSTRING("edge"));
	outFields->push(HX_CSTRING("node"));
	outFields->push(HX_CSTRING("_id"));
	outFields->push(HX_CSTRING("_node"));
	outFields->push(HX_CSTRING("_edge"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("INC"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(Graph_obj,_id),HX_CSTRING("_id")},
	{hx::fsObject /*::hxDaedalus::data::graph::GraphNode*/ ,(int)offsetof(Graph_obj,_node),HX_CSTRING("_node")},
	{hx::fsObject /*::hxDaedalus::data::graph::GraphEdge*/ ,(int)offsetof(Graph_obj,_edge),HX_CSTRING("_edge")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("get_id"),
	HX_CSTRING("get_edge"),
	HX_CSTRING("get_node"),
	HX_CSTRING("_id"),
	HX_CSTRING("_node"),
	HX_CSTRING("_edge"),
	HX_CSTRING("dispose"),
	HX_CSTRING("insertNode"),
	HX_CSTRING("deleteNode"),
	HX_CSTRING("insertEdge"),
	HX_CSTRING("deleteEdge"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Graph_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Graph_obj::INC,"INC");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Graph_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Graph_obj::INC,"INC");
};

#endif

Class Graph_obj::__mClass;

void Graph_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDaedalus.data.graph.Graph"), hx::TCanCast< Graph_obj> ,sStaticFields,sMemberFields,
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

void Graph_obj::__boot()
{
	INC= (int)0;
}

} // end namespace hxDaedalus
} // end namespace data
} // end namespace graph
