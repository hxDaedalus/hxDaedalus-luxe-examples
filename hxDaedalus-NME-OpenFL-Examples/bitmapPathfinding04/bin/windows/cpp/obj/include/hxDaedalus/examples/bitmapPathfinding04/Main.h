#ifndef INCLUDED_hxDaedalus_examples_bitmapPathfinding04_Main
#define INCLUDED_hxDaedalus_examples_bitmapPathfinding04_Main

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <openfl/_v2/display/Sprite.h>
HX_DECLARE_CLASS2(hxDaedalus,ai,EntityAI)
HX_DECLARE_CLASS2(hxDaedalus,ai,PathFinder)
HX_DECLARE_CLASS3(hxDaedalus,ai,trajectory,LinearPathSampler)
HX_DECLARE_CLASS2(hxDaedalus,data,Mesh)
HX_DECLARE_CLASS2(hxDaedalus,data,Object)
HX_DECLARE_CLASS3(hxDaedalus,examples,bitmapPathfinding04,Main)
HX_DECLARE_CLASS2(hxDaedalus,view,SimpleView)
HX_DECLARE_CLASS3(openfl,_v2,display,Bitmap)
HX_DECLARE_CLASS3(openfl,_v2,display,DisplayObject)
HX_DECLARE_CLASS3(openfl,_v2,display,DisplayObjectContainer)
HX_DECLARE_CLASS3(openfl,_v2,display,IBitmapDrawable)
HX_DECLARE_CLASS3(openfl,_v2,display,InteractiveObject)
HX_DECLARE_CLASS3(openfl,_v2,display,Sprite)
HX_DECLARE_CLASS3(openfl,_v2,events,Event)
HX_DECLARE_CLASS3(openfl,_v2,events,EventDispatcher)
HX_DECLARE_CLASS3(openfl,_v2,events,IEventDispatcher)
HX_DECLARE_CLASS3(openfl,_v2,events,KeyboardEvent)
HX_DECLARE_CLASS3(openfl,_v2,events,MouseEvent)
namespace hxDaedalus{
namespace examples{
namespace bitmapPathfinding04{


class HXCPP_CLASS_ATTRIBUTES  Main_obj : public ::openfl::_v2::display::Sprite_obj{
	public:
		typedef ::openfl::_v2::display::Sprite_obj super;
		typedef Main_obj OBJ_;
		Main_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Main_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Main_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Main"); }

		bool inited;
		::hxDaedalus::data::Mesh _mesh;
		::hxDaedalus::view::SimpleView _view;
		::hxDaedalus::ai::EntityAI _entityAI;
		::hxDaedalus::ai::PathFinder _pathfinder;
		Array< Float > _path;
		::hxDaedalus::ai::trajectory::LinearPathSampler _pathSampler;
		::hxDaedalus::data::Object _object;
		::openfl::_v2::display::Bitmap _bmp;
		::openfl::_v2::display::Bitmap _overlay;
		bool _newPath;
		virtual Void resize( Dynamic e);
		Dynamic resize_dyn();

		virtual Void init( );
		Dynamic init_dyn();

		virtual Void _onMouseUp( ::openfl::_v2::events::MouseEvent event);
		Dynamic _onMouseUp_dyn();

		virtual Void _onMouseDown( ::openfl::_v2::events::MouseEvent event);
		Dynamic _onMouseDown_dyn();

		virtual Void _onEnterFrame( ::openfl::_v2::events::Event event);
		Dynamic _onEnterFrame_dyn();

		virtual Void _onKeyDown( ::openfl::_v2::events::KeyboardEvent event);
		Dynamic _onKeyDown_dyn();

		virtual Void added( Dynamic e);
		Dynamic added_dyn();

		static Void main( );
		static Dynamic main_dyn();

};

} // end namespace hxDaedalus
} // end namespace examples
} // end namespace bitmapPathfinding04

#endif /* INCLUDED_hxDaedalus_examples_bitmapPathfinding04_Main */ 
