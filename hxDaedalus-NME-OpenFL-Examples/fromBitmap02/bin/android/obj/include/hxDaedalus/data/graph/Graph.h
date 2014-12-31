#ifndef INCLUDED_hxDaedalus_data_graph_Graph
#define INCLUDED_hxDaedalus_data_graph_Graph

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(hxDaedalus,data,graph,Graph)
HX_DECLARE_CLASS3(hxDaedalus,data,graph,GraphEdge)
HX_DECLARE_CLASS3(hxDaedalus,data,graph,GraphNode)
namespace hxDaedalus{
namespace data{
namespace graph{


class HXCPP_CLASS_ATTRIBUTES  Graph_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Graph_obj OBJ_;
		Graph_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Graph_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Graph_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Graph"); }

		virtual int get_id( );
		Dynamic get_id_dyn();

		virtual ::hxDaedalus::data::graph::GraphEdge get_edge( );
		Dynamic get_edge_dyn();

		virtual ::hxDaedalus::data::graph::GraphNode get_node( );
		Dynamic get_node_dyn();

		int _id;
		::hxDaedalus::data::graph::GraphNode _node;
		::hxDaedalus::data::graph::GraphEdge _edge;
		virtual Void dispose( );
		Dynamic dispose_dyn();

		virtual ::hxDaedalus::data::graph::GraphNode insertNode( );
		Dynamic insertNode_dyn();

		virtual Void deleteNode( ::hxDaedalus::data::graph::GraphNode node);
		Dynamic deleteNode_dyn();

		virtual ::hxDaedalus::data::graph::GraphEdge insertEdge( ::hxDaedalus::data::graph::GraphNode fromNode,::hxDaedalus::data::graph::GraphNode toNode);
		Dynamic insertEdge_dyn();

		virtual Void deleteEdge( ::hxDaedalus::data::graph::GraphEdge edge);
		Dynamic deleteEdge_dyn();

		static int INC;
};

} // end namespace hxDaedalus
} // end namespace data
} // end namespace graph

#endif /* INCLUDED_hxDaedalus_data_graph_Graph */ 
