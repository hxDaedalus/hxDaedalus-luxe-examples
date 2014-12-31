#ifndef INCLUDED_hxDaedalus_data_Edge
#define INCLUDED_hxDaedalus_data_Edge

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(hxDaedalus,data,ConstraintSegment)
HX_DECLARE_CLASS2(hxDaedalus,data,Edge)
HX_DECLARE_CLASS2(hxDaedalus,data,Face)
HX_DECLARE_CLASS2(hxDaedalus,data,Vertex)
namespace hxDaedalus{
namespace data{


class HXCPP_CLASS_ATTRIBUTES  Edge_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Edge_obj OBJ_;
		Edge_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Edge_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Edge_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Edge"); }

		Array< ::Dynamic > fromConstraintSegments;
		int _id;
		bool _isReal;
		bool _isConstrained;
		::hxDaedalus::data::Vertex _originVertex;
		::hxDaedalus::data::Edge _oppositeEdge;
		::hxDaedalus::data::Edge _nextLeftEdge;
		::hxDaedalus::data::Face _leftFace;
		int colorDebug;
		virtual int get_id( );
		Dynamic get_id_dyn();

		virtual bool get_isReal( );
		Dynamic get_isReal_dyn();

		virtual bool get_isConstrained( );
		Dynamic get_isConstrained_dyn();

		virtual Void setDatas( ::hxDaedalus::data::Vertex originVertex,::hxDaedalus::data::Edge oppositeEdge,::hxDaedalus::data::Edge nextLeftEdge,::hxDaedalus::data::Face leftFace,hx::Null< bool >  isReal,hx::Null< bool >  isConstrained);
		Dynamic setDatas_dyn();

		virtual Void addFromConstraintSegment( ::hxDaedalus::data::ConstraintSegment segment);
		Dynamic addFromConstraintSegment_dyn();

		virtual Void removeFromConstraintSegment( ::hxDaedalus::data::ConstraintSegment segment);
		Dynamic removeFromConstraintSegment_dyn();

		virtual ::hxDaedalus::data::Vertex set_originVertex( ::hxDaedalus::data::Vertex value);
		Dynamic set_originVertex_dyn();

		virtual ::hxDaedalus::data::Edge set_nextLeftEdge( ::hxDaedalus::data::Edge value);
		Dynamic set_nextLeftEdge_dyn();

		virtual ::hxDaedalus::data::Face set_leftFace( ::hxDaedalus::data::Face value);
		Dynamic set_leftFace_dyn();

		virtual bool set_isConstrained( bool value);
		Dynamic set_isConstrained_dyn();

		virtual Void dispose( );
		Dynamic dispose_dyn();

		virtual ::hxDaedalus::data::Vertex get_originVertex( );
		Dynamic get_originVertex_dyn();

		virtual ::hxDaedalus::data::Vertex get_destinationVertex( );
		Dynamic get_destinationVertex_dyn();

		virtual ::hxDaedalus::data::Edge get_oppositeEdge( );
		Dynamic get_oppositeEdge_dyn();

		virtual ::hxDaedalus::data::Edge get_nextLeftEdge( );
		Dynamic get_nextLeftEdge_dyn();

		virtual ::hxDaedalus::data::Edge get_prevLeftEdge( );
		Dynamic get_prevLeftEdge_dyn();

		virtual ::hxDaedalus::data::Edge get_nextRightEdge( );
		Dynamic get_nextRightEdge_dyn();

		virtual ::hxDaedalus::data::Edge get_prevRightEdge( );
		Dynamic get_prevRightEdge_dyn();

		virtual ::hxDaedalus::data::Edge get_rotLeftEdge( );
		Dynamic get_rotLeftEdge_dyn();

		virtual ::hxDaedalus::data::Edge get_rotRightEdge( );
		Dynamic get_rotRightEdge_dyn();

		virtual ::hxDaedalus::data::Face get_leftFace( );
		Dynamic get_leftFace_dyn();

		virtual ::hxDaedalus::data::Face get_rightFace( );
		Dynamic get_rightFace_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

		static int INC;
};

} // end namespace hxDaedalus
} // end namespace data

#endif /* INCLUDED_hxDaedalus_data_Edge */ 
