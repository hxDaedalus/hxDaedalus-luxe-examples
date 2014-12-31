#ifndef INCLUDED_hxDaedalus_data_math_Geom2D
#define INCLUDED_hxDaedalus_data_math_Geom2D

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(hxDaedalus,data,Edge)
HX_DECLARE_CLASS2(hxDaedalus,data,Face)
HX_DECLARE_CLASS2(hxDaedalus,data,Mesh)
HX_DECLARE_CLASS2(hxDaedalus,data,Vertex)
HX_DECLARE_CLASS3(hxDaedalus,data,math,Geom2D)
HX_DECLARE_CLASS3(hxDaedalus,data,math,Intersection)
HX_DECLARE_CLASS3(hxDaedalus,data,math,Point2D)
HX_DECLARE_CLASS3(hxDaedalus,data,math,RandGenerator)
namespace hxDaedalus{
namespace data{
namespace math{


class HXCPP_CLASS_ATTRIBUTES  Geom2D_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Geom2D_obj OBJ_;
		Geom2D_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Geom2D_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Geom2D_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("Geom2D"); }

		static ::hxDaedalus::data::math::RandGenerator _randGen;
		static Array< ::Dynamic > __samples;
		static ::hxDaedalus::data::math::Intersection locatePosition( Float x,Float y,::hxDaedalus::data::Mesh mesh);
		static Dynamic locatePosition_dyn();

		static bool isCircleIntersectingAnyConstraint( Float x,Float y,Float radius,::hxDaedalus::data::Mesh mesh);
		static Dynamic isCircleIntersectingAnyConstraint_dyn();

		static int getDirection( Float x1,Float y1,Float x2,Float y2,Float x3,Float y3);
		static Dynamic getDirection_dyn();

		static int getDirection2( Float x1,Float y1,Float x2,Float y2,Float x3,Float y3);
		static Dynamic getDirection2_dyn();

		static int getRelativePosition( Float x,Float y,::hxDaedalus::data::Edge eUp);
		static Dynamic getRelativePosition_dyn();

		static int getRelativePosition2( Float x,Float y,::hxDaedalus::data::Edge eUp);
		static Dynamic getRelativePosition2_dyn();

		static ::hxDaedalus::data::math::Intersection isInFace( Float x,Float y,::hxDaedalus::data::Face polygon);
		static Dynamic isInFace_dyn();

		static bool clipSegmentByTriangle( Float s1x,Float s1y,Float s2x,Float s2y,Float t1x,Float t1y,Float t2x,Float t2y,Float t3x,Float t3y,::hxDaedalus::data::math::Point2D pResult1,::hxDaedalus::data::math::Point2D pResult2);
		static Dynamic clipSegmentByTriangle_dyn();

		static bool isSegmentIntersectingTriangle( Float s1x,Float s1y,Float s2x,Float s2y,Float t1x,Float t1y,Float t2x,Float t2y,Float t3x,Float t3y);
		static Dynamic isSegmentIntersectingTriangle_dyn();

		static ::hxDaedalus::data::math::Point2D __circumcenter;
		static bool isDelaunay( ::hxDaedalus::data::Edge edge);
		static Dynamic isDelaunay_dyn();

		static ::hxDaedalus::data::math::Point2D getCircumcenter( Float x1,Float y1,Float x2,Float y2,Float x3,Float y3,::hxDaedalus::data::math::Point2D result);
		static Dynamic getCircumcenter_dyn();

		static bool intersections2segments( Float s1p1x,Float s1p1y,Float s1p2x,Float s1p2y,Float s2p1x,Float s2p1y,Float s2p2x,Float s2p2y,::hxDaedalus::data::math::Point2D posIntersection,Array< Float > paramIntersection,hx::Null< bool >  infiniteLineMode);
		static Dynamic intersections2segments_dyn();

		static bool intersections2edges( ::hxDaedalus::data::Edge edge1,::hxDaedalus::data::Edge edge2,::hxDaedalus::data::math::Point2D posIntersection,Array< Float > paramIntersection,hx::Null< bool >  infiniteLineMode);
		static Dynamic intersections2edges_dyn();

		static bool isConvex( ::hxDaedalus::data::Edge edge);
		static Dynamic isConvex_dyn();

		static Void projectOrthogonaly( ::hxDaedalus::data::math::Point2D vertexPos,::hxDaedalus::data::Edge edge);
		static Dynamic projectOrthogonaly_dyn();

		static bool intersections2Circles( Float cx1,Float cy1,Float r1,Float cx2,Float cy2,Float r2,Array< Float > result);
		static Dynamic intersections2Circles_dyn();

		static bool intersectionsSegmentCircle( Float p0x,Float p0y,Float p1x,Float p1y,Float cx,Float cy,Float r,Array< Float > result);
		static Dynamic intersectionsSegmentCircle_dyn();

		static bool intersectionsLineCircle( Float p0x,Float p0y,Float p1x,Float p1y,Float cx,Float cy,Float r,Array< Float > result);
		static Dynamic intersectionsLineCircle_dyn();

		static bool tangentsPointToCircle( Float px,Float py,Float cx,Float cy,Float r,Array< Float > result);
		static Dynamic tangentsPointToCircle_dyn();

		static bool tangentsCrossCircleToCircle( Float r,Float c1x,Float c1y,Float c2x,Float c2y,Array< Float > result);
		static Dynamic tangentsCrossCircleToCircle_dyn();

		static Void tangentsParalCircleToCircle( Float r,Float c1x,Float c1y,Float c2x,Float c2y,Array< Float > result);
		static Dynamic tangentsParalCircleToCircle_dyn();

		static Float distanceSquaredPointToLine( Float px,Float py,Float ax,Float ay,Float bx,Float by);
		static Dynamic distanceSquaredPointToLine_dyn();

		static Float distanceSquaredPointToSegment( Float px,Float py,Float ax,Float ay,Float bx,Float by);
		static Dynamic distanceSquaredPointToSegment_dyn();

		static Float distanceSquaredVertexToEdge( ::hxDaedalus::data::Vertex vertex,::hxDaedalus::data::Edge edge);
		static Dynamic distanceSquaredVertexToEdge_dyn();

		static Float pathLength( Array< Float > path);
		static Dynamic pathLength_dyn();

};

} // end namespace hxDaedalus
} // end namespace data
} // end namespace math

#endif /* INCLUDED_hxDaedalus_data_math_Geom2D */ 
