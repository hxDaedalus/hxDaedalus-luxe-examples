#ifndef INCLUDED_hxDaedalus_data_graph_GraphNode
#define INCLUDED_hxDaedalus_data_graph_GraphNode

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(IMap)
HX_DECLARE_CLASS2(haxe,ds,ObjectMap)
HX_DECLARE_CLASS3(hxDaedalus,data,graph,GraphEdge)
HX_DECLARE_CLASS3(hxDaedalus,data,graph,GraphNode)
HX_DECLARE_CLASS3(hxDaedalus,data,math,NodeData)
namespace hxDaedalus{
namespace data{
namespace graph{


class HXCPP_CLASS_ATTRIBUTES  GraphNode_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef GraphNode_obj OBJ_;
		GraphNode_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< GraphNode_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~GraphNode_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("GraphNode"); }

		int _id;
		::hxDaedalus::data::graph::GraphNode _prev;
		::hxDaedalus::data::graph::GraphNode _next;
		::hxDaedalus::data::graph::GraphEdge _outgoingEdge;
		::haxe::ds::ObjectMap _successorNodes;
		::hxDaedalus::data::math::NodeData _data;
		virtual int get_id( );
		Dynamic get_id_dyn();

		virtual Void dispose( );
		Dynamic dispose_dyn();

		virtual ::hxDaedalus::data::graph::GraphNode get_prev( );
		Dynamic get_prev_dyn();

		virtual ::hxDaedalus::data::graph::GraphNode set_prev( ::hxDaedalus::data::graph::GraphNode value);
		Dynamic set_prev_dyn();

		virtual ::hxDaedalus::data::graph::GraphNode get_next( );
		Dynamic get_next_dyn();

		virtual ::hxDaedalus::data::graph::GraphNode set_next( ::hxDaedalus::data::graph::GraphNode value);
		Dynamic set_next_dyn();

		virtual ::hxDaedalus::data::graph::GraphEdge get_outgoingEdge( );
		Dynamic get_outgoingEdge_dyn();

		virtual ::hxDaedalus::data::graph::GraphEdge set_outgoingEdge( ::hxDaedalus::data::graph::GraphEdge value);
		Dynamic set_outgoingEdge_dyn();

		virtual ::haxe::ds::ObjectMap get_successorNodes( );
		Dynamic get_successorNodes_dyn();

		virtual ::haxe::ds::ObjectMap set_successorNodes( ::haxe::ds::ObjectMap value);
		Dynamic set_successorNodes_dyn();

		virtual ::hxDaedalus::data::math::NodeData get_data( );
		Dynamic get_data_dyn();

		virtual ::hxDaedalus::data::math::NodeData set_data( ::hxDaedalus::data::math::NodeData value);
		Dynamic set_data_dyn();

		static int INC;
};

} // end namespace hxDaedalus
} // end namespace data
} // end namespace graph

#endif /* INCLUDED_hxDaedalus_data_graph_GraphNode */ 
