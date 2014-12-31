#ifndef INCLUDED_hxDaedalus_view_SimpleView
#define INCLUDED_hxDaedalus_view_SimpleView

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(hxDaedalus,ai,EntityAI)
HX_DECLARE_CLASS2(hxDaedalus,data,Edge)
HX_DECLARE_CLASS2(hxDaedalus,data,Mesh)
HX_DECLARE_CLASS2(hxDaedalus,data,Vertex)
HX_DECLARE_CLASS2(hxDaedalus,graphics,ISimpleDrawingContext)
HX_DECLARE_CLASS3(hxDaedalus,graphics,flash,SimpleDrawingContext)
HX_DECLARE_CLASS2(hxDaedalus,view,SimpleView)
HX_DECLARE_CLASS3(openfl,_v2,display,Graphics)
namespace hxDaedalus{
namespace view{


class HXCPP_CLASS_ATTRIBUTES  SimpleView_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef SimpleView_obj OBJ_;
		SimpleView_obj();
		Void __construct(::openfl::_v2::display::Graphics targetCanvas);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< SimpleView_obj > __new(::openfl::_v2::display::Graphics targetCanvas);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~SimpleView_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("SimpleView"); }

		int edgesColor;
		Float edgesWidth;
		Float edgesAlpha;
		int constraintsColor;
		Float constraintsWidth;
		Float constraintsAlpha;
		int verticesColor;
		Float verticesRadius;
		Float verticesAlpha;
		int pathsColor;
		Float pathsWidth;
		Float pathsAlpha;
		int entitiesColor;
		Float entitiesWidth;
		Float entitiesAlpha;
		::hxDaedalus::graphics::flash::SimpleDrawingContext graphics;
		virtual Void drawVertex( ::hxDaedalus::data::Vertex vertex);
		Dynamic drawVertex_dyn();

		virtual Void drawEdge( ::hxDaedalus::data::Edge edge);
		Dynamic drawEdge_dyn();

		virtual Void drawMesh( ::hxDaedalus::data::Mesh mesh,hx::Null< bool >  cleanBefore);
		Dynamic drawMesh_dyn();

		virtual Void drawEntity( ::hxDaedalus::ai::EntityAI entity,hx::Null< bool >  cleanBefore);
		Dynamic drawEntity_dyn();

		virtual Void drawEntities( Array< ::Dynamic > vEntities,hx::Null< bool >  cleanBefore);
		Dynamic drawEntities_dyn();

		virtual Void drawPath( Array< Float > path,hx::Null< bool >  cleanBefore);
		Dynamic drawPath_dyn();

};

} // end namespace hxDaedalus
} // end namespace view

#endif /* INCLUDED_hxDaedalus_view_SimpleView */ 
