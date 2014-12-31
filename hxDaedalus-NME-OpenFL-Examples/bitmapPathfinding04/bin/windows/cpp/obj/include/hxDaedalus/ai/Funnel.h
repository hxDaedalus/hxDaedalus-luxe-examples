#ifndef INCLUDED_hxDaedalus_ai_Funnel
#define INCLUDED_hxDaedalus_ai_Funnel

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(IMap)
HX_DECLARE_CLASS2(haxe,ds,ObjectMap)
HX_DECLARE_CLASS2(hxDaedalus,ai,Funnel)
HX_DECLARE_CLASS2(hxDaedalus,data,Edge)
HX_DECLARE_CLASS2(hxDaedalus,data,Face)
HX_DECLARE_CLASS3(hxDaedalus,data,math,Point2D)
namespace hxDaedalus{
namespace ai{


class HXCPP_CLASS_ATTRIBUTES  Funnel_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Funnel_obj OBJ_;
		Funnel_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Funnel_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Funnel_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Funnel"); }

		Float _radius;
		Float _radiusSquared;
		int _numSamplesCircle;
		Array< ::Dynamic > _sampleCircle;
		Float _sampleCircleDistanceSquared;
		virtual Void dispose( );
		Dynamic dispose_dyn();

		int _poolPointsSize;
		Array< ::Dynamic > _poolPoints;
		int _currPoolPointsIndex;
		::hxDaedalus::data::math::Point2D __point;
		virtual ::hxDaedalus::data::math::Point2D getPoint( hx::Null< Float >  x,hx::Null< Float >  y);
		Dynamic getPoint_dyn();

		virtual ::hxDaedalus::data::math::Point2D getCopyPoint( ::hxDaedalus::data::math::Point2D pointToCopy);
		Dynamic getCopyPoint_dyn();

		virtual Float get_radius( );
		Dynamic get_radius_dyn();

		virtual Float set_radius( Float value);
		Dynamic set_radius_dyn();

		virtual Void findPath( Float fromX,Float fromY,Float toX,Float toY,Array< ::Dynamic > listFaces,Array< ::Dynamic > listEdges,Array< Float > resultPath);
		Dynamic findPath_dyn();

		virtual Void adjustWithTangents( ::hxDaedalus::data::math::Point2D p1,bool applyRadiusToP1,::hxDaedalus::data::math::Point2D p2,bool applyRadiusToP2,::haxe::ds::ObjectMap pointSides,::haxe::ds::ObjectMap pointSuccessor,Array< ::Dynamic > newPath,Array< ::Dynamic > adjustedPoints);
		Dynamic adjustWithTangents_dyn();

		virtual Void checkAdjustedPath( Array< ::Dynamic > newPath,Array< ::Dynamic > adjustedPoints,::haxe::ds::ObjectMap pointSides);
		Dynamic checkAdjustedPath_dyn();

		virtual Void smoothAngle( ::hxDaedalus::data::math::Point2D prevPoint,::hxDaedalus::data::math::Point2D pointToSmooth,::hxDaedalus::data::math::Point2D nextPoint,int side,Array< ::Dynamic > encirclePoints);
		Dynamic smoothAngle_dyn();

};

} // end namespace hxDaedalus
} // end namespace ai

#endif /* INCLUDED_hxDaedalus_ai_Funnel */ 
