#ifndef INCLUDED_hxDaedalus_data_Vertex
#define INCLUDED_hxDaedalus_data_Vertex

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(hxDaedalus,data,ConstraintSegment)
HX_DECLARE_CLASS2(hxDaedalus,data,Edge)
HX_DECLARE_CLASS2(hxDaedalus,data,Vertex)
HX_DECLARE_CLASS3(hxDaedalus,data,math,Point2D)
namespace hxDaedalus{
namespace data{


class HXCPP_CLASS_ATTRIBUTES  Vertex_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Vertex_obj OBJ_;
		Vertex_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Vertex_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Vertex_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Vertex"); }

		int _id;
		::hxDaedalus::data::math::Point2D _pos;
		bool _isReal;
		::hxDaedalus::data::Edge _edge;
		Array< ::Dynamic > _fromConstraintSegments;
		int colorDebug;
		virtual int get_id( );
		Dynamic get_id_dyn();

		virtual bool get_isReal( );
		Dynamic get_isReal_dyn();

		virtual ::hxDaedalus::data::math::Point2D get_pos( );
		Dynamic get_pos_dyn();

		virtual Array< ::Dynamic > get_fromConstraintSegments( );
		Dynamic get_fromConstraintSegments_dyn();

		virtual Array< ::Dynamic > set_fromConstraintSegments( Array< ::Dynamic > value);
		Dynamic set_fromConstraintSegments_dyn();

		virtual Void setDatas( ::hxDaedalus::data::Edge edge,hx::Null< bool >  isReal);
		Dynamic setDatas_dyn();

		virtual Void addFromConstraintSegment( ::hxDaedalus::data::ConstraintSegment segment);
		Dynamic addFromConstraintSegment_dyn();

		virtual Void removeFromConstraintSegment( ::hxDaedalus::data::ConstraintSegment segment);
		Dynamic removeFromConstraintSegment_dyn();

		virtual Void dispose( );
		Dynamic dispose_dyn();

		virtual ::hxDaedalus::data::Edge get_edge( );
		Dynamic get_edge_dyn();

		virtual ::hxDaedalus::data::Edge set_edge( ::hxDaedalus::data::Edge value);
		Dynamic set_edge_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

		static int INC;
};

} // end namespace hxDaedalus
} // end namespace data

#endif /* INCLUDED_hxDaedalus_data_Vertex */ 
