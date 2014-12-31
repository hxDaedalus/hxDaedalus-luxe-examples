#ifndef INCLUDED_hxDaedalus_ai_PathFinder
#define INCLUDED_hxDaedalus_ai_PathFinder

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(hxDaedalus,ai,AStar)
HX_DECLARE_CLASS2(hxDaedalus,ai,EntityAI)
HX_DECLARE_CLASS2(hxDaedalus,ai,Funnel)
HX_DECLARE_CLASS2(hxDaedalus,ai,PathFinder)
HX_DECLARE_CLASS2(hxDaedalus,data,Edge)
HX_DECLARE_CLASS2(hxDaedalus,data,Face)
HX_DECLARE_CLASS2(hxDaedalus,data,Mesh)
namespace hxDaedalus{
namespace ai{


class HXCPP_CLASS_ATTRIBUTES  PathFinder_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef PathFinder_obj OBJ_;
		PathFinder_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< PathFinder_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~PathFinder_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("PathFinder"); }

		::hxDaedalus::ai::EntityAI entity;
		::hxDaedalus::data::Mesh _mesh;
		::hxDaedalus::ai::AStar astar;
		::hxDaedalus::ai::Funnel funnel;
		Float radius;
		Array< ::Dynamic > listFaces;
		Array< ::Dynamic > listEdges;
		virtual Void dispose( );
		Dynamic dispose_dyn();

		virtual ::hxDaedalus::data::Mesh get_mesh( );
		Dynamic get_mesh_dyn();

		virtual ::hxDaedalus::data::Mesh set_mesh( ::hxDaedalus::data::Mesh value);
		Dynamic set_mesh_dyn();

		virtual Void findPath( Float toX,Float toY,Array< Float > resultPath);
		Dynamic findPath_dyn();

};

} // end namespace hxDaedalus
} // end namespace ai

#endif /* INCLUDED_hxDaedalus_ai_PathFinder */ 
