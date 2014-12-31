#ifndef INCLUDED_hxDaedalus_data_math_Potrace
#define INCLUDED_hxDaedalus_data_math_Potrace

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(IMap)
HX_DECLARE_CLASS2(haxe,ds,StringMap)
HX_DECLARE_CLASS3(hxDaedalus,data,graph,Graph)
HX_DECLARE_CLASS3(hxDaedalus,data,math,Potrace)
HX_DECLARE_CLASS2(hxDaedalus,graphics,ISimpleDrawingContext)
HX_DECLARE_CLASS3(hxDaedalus,graphics,_Pixels,PixelsData)
HX_DECLARE_CLASS3(hxDaedalus,graphics,flash,SimpleDrawingContext)
namespace hxDaedalus{
namespace data{
namespace math{


class HXCPP_CLASS_ATTRIBUTES  Potrace_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Potrace_obj OBJ_;
		Potrace_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Potrace_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Potrace_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("Potrace"); }

		static int MAX_INT;
		static Float maxDistance;
		static Array< ::Dynamic > buildShapes( ::hxDaedalus::graphics::_Pixels::PixelsData bmpData,::hxDaedalus::graphics::_Pixels::PixelsData debugBmp,::hxDaedalus::graphics::flash::SimpleDrawingContext debugShape);
		static Dynamic buildShapes_dyn();

		static Array< Float > buildShape( ::hxDaedalus::graphics::_Pixels::PixelsData bmpData,int fromPixelRow,int fromPixelCol,::haxe::ds::StringMap dictPixelsDone,::hxDaedalus::graphics::_Pixels::PixelsData debugBmp,::hxDaedalus::graphics::flash::SimpleDrawingContext debugShape);
		static Dynamic buildShape_dyn();

		static ::hxDaedalus::data::graph::Graph buildGraph( Array< Float > shape);
		static Dynamic buildGraph_dyn();

		static Array< Float > buildPolygon( ::hxDaedalus::data::graph::Graph graph,Dynamic debugShape);
		static Dynamic buildPolygon_dyn();

};

} // end namespace hxDaedalus
} // end namespace data
} // end namespace math

#endif /* INCLUDED_hxDaedalus_data_math_Potrace */ 
