#ifndef INCLUDED_hxDaedalus_data_graph_GraphEdge
#define INCLUDED_hxDaedalus_data_graph_GraphEdge

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(hxDaedalus,data,graph,GraphEdge)
HX_DECLARE_CLASS3(hxDaedalus,data,graph,GraphNode)
HX_DECLARE_CLASS3(hxDaedalus,data,math,EdgeData)
namespace hxDaedalus{
namespace data{
namespace graph{


class HXCPP_CLASS_ATTRIBUTES  GraphEdge_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef GraphEdge_obj OBJ_;
		GraphEdge_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< GraphEdge_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~GraphEdge_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("GraphEdge"); }

		virtual int get_id( );
		Dynamic get_id_dyn();

		int _id;
		::hxDaedalus::data::graph::GraphEdge _prev;
		::hxDaedalus::data::graph::GraphEdge _next;
		::hxDaedalus::data::graph::GraphEdge _rotPrevEdge;
		::hxDaedalus::data::graph::GraphEdge _rotNextEdge;
		::hxDaedalus::data::graph::GraphEdge _oppositeEdge;
		::hxDaedalus::data::graph::GraphNode _sourceNode;
		::hxDaedalus::data::graph::GraphNode _destinationNode;
		::hxDaedalus::data::math::EdgeData _data;
		virtual Void dispose( );
		Dynamic dispose_dyn();

		virtual ::hxDaedalus::data::graph::GraphEdge get_prev( );
		Dynamic get_prev_dyn();

		virtual ::hxDaedalus::data::graph::GraphEdge set_prev( ::hxDaedalus::data::graph::GraphEdge value);
		Dynamic set_prev_dyn();

		virtual ::hxDaedalus::data::graph::GraphEdge get_next( );
		Dynamic get_next_dyn();

		virtual ::hxDaedalus::data::graph::GraphEdge set_next( ::hxDaedalus::data::graph::GraphEdge value);
		Dynamic set_next_dyn();

		virtual ::hxDaedalus::data::graph::GraphEdge get_rotPrevEdge( );
		Dynamic get_rotPrevEdge_dyn();

		virtual ::hxDaedalus::data::graph::GraphEdge set_rotPrevEdge( ::hxDaedalus::data::graph::GraphEdge value);
		Dynamic set_rotPrevEdge_dyn();

		virtual ::hxDaedalus::data::graph::GraphEdge get_rotNextEdge( );
		Dynamic get_rotNextEdge_dyn();

		virtual ::hxDaedalus::data::graph::GraphEdge set_rotNextEdge( ::hxDaedalus::data::graph::GraphEdge value);
		Dynamic set_rotNextEdge_dyn();

		virtual ::hxDaedalus::data::graph::GraphEdge get_oppositeEdge( );
		Dynamic get_oppositeEdge_dyn();

		virtual ::hxDaedalus::data::graph::GraphEdge set_oppositeEdge( ::hxDaedalus::data::graph::GraphEdge value);
		Dynamic set_oppositeEdge_dyn();

		virtual ::hxDaedalus::data::graph::GraphNode get_sourceNode( );
		Dynamic get_sourceNode_dyn();

		virtual ::hxDaedalus::data::graph::GraphNode set_sourceNode( ::hxDaedalus::data::graph::GraphNode value);
		Dynamic set_sourceNode_dyn();

		virtual ::hxDaedalus::data::graph::GraphNode get_destinationNode( );
		Dynamic get_destinationNode_dyn();

		virtual ::hxDaedalus::data::graph::GraphNode set_destinationNode( ::hxDaedalus::data::graph::GraphNode value);
		Dynamic set_destinationNode_dyn();

		virtual ::hxDaedalus::data::math::EdgeData get_data( );
		Dynamic get_data_dyn();

		virtual ::hxDaedalus::data::math::EdgeData set_data( ::hxDaedalus::data::math::EdgeData value);
		Dynamic set_data_dyn();

		static int INC;
};

} // end namespace hxDaedalus
} // end namespace data
} // end namespace graph

#endif /* INCLUDED_hxDaedalus_data_graph_GraphEdge */ 
