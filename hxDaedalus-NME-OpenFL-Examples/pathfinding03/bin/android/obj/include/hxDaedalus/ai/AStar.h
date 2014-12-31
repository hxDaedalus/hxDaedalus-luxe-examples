#ifndef INCLUDED_hxDaedalus_ai_AStar
#define INCLUDED_hxDaedalus_ai_AStar

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(IMap)
HX_DECLARE_CLASS2(haxe,ds,ObjectMap)
HX_DECLARE_CLASS2(hxDaedalus,ai,AStar)
HX_DECLARE_CLASS2(hxDaedalus,data,Edge)
HX_DECLARE_CLASS2(hxDaedalus,data,Face)
HX_DECLARE_CLASS2(hxDaedalus,data,Mesh)
HX_DECLARE_CLASS2(hxDaedalus,iterators,FromFaceToInnerEdges)
namespace hxDaedalus{
namespace ai{


class HXCPP_CLASS_ATTRIBUTES  AStar_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef AStar_obj OBJ_;
		AStar_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< AStar_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~AStar_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("AStar"); }

		Float _radius;
		::hxDaedalus::data::Mesh _mesh;
		::haxe::ds::ObjectMap closedFaces;
		Array< ::Dynamic > sortedOpenedFaces;
		::haxe::ds::ObjectMap openedFaces;
		::haxe::ds::ObjectMap entryEdges;
		::haxe::ds::ObjectMap entryX;
		::haxe::ds::ObjectMap entryY;
		::haxe::ds::ObjectMap scoreF;
		::haxe::ds::ObjectMap scoreG;
		::haxe::ds::ObjectMap scoreH;
		::haxe::ds::ObjectMap predecessor;
		::hxDaedalus::iterators::FromFaceToInnerEdges iterEdge;
		Float radiusSquared;
		Float diameter;
		Float diameterSquared;
		::hxDaedalus::data::Face fromFace;
		::hxDaedalus::data::Face toFace;
		::hxDaedalus::data::Face curFace;
		virtual Void dispose( );
		Dynamic dispose_dyn();

		virtual Float get_radius( );
		Dynamic get_radius_dyn();

		virtual Float set_radius( Float value);
		Dynamic set_radius_dyn();

		virtual ::hxDaedalus::data::Mesh set_mesh( ::hxDaedalus::data::Mesh value);
		Dynamic set_mesh_dyn();

		virtual Void findPath( Float fromX,Float fromY,Float toX,Float toY,Array< ::Dynamic > resultListFaces,Array< ::Dynamic > resultListEdges);
		Dynamic findPath_dyn();

		virtual int sortingFaces( ::hxDaedalus::data::Face a,::hxDaedalus::data::Face b);
		Dynamic sortingFaces_dyn();

		virtual bool isWalkableByRadius( ::hxDaedalus::data::Edge fromEdge,::hxDaedalus::data::Face throughFace,::hxDaedalus::data::Edge toEdge);
		Dynamic isWalkableByRadius_dyn();

};

} // end namespace hxDaedalus
} // end namespace ai

#endif /* INCLUDED_hxDaedalus_ai_AStar */ 
