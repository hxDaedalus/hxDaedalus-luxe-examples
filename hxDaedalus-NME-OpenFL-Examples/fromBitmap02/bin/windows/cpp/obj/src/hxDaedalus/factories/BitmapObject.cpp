#include <hxcpp.h>

#ifndef INCLUDED_hxDaedalus_data_Object
#include <hxDaedalus/data/Object.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_graph_Graph
#include <hxDaedalus/data/graph/Graph.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_math_Potrace
#include <hxDaedalus/data/math/Potrace.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_math_ShapeSimplifier
#include <hxDaedalus/data/math/ShapeSimplifier.h>
#endif
#ifndef INCLUDED_hxDaedalus_factories_BitmapObject
#include <hxDaedalus/factories/BitmapObject.h>
#endif
#ifndef INCLUDED_hxDaedalus_graphics_ISimpleDrawingContext
#include <hxDaedalus/graphics/ISimpleDrawingContext.h>
#endif
#ifndef INCLUDED_hxDaedalus_graphics__Pixels_PixelsData
#include <hxDaedalus/graphics/_Pixels/PixelsData.h>
#endif
#ifndef INCLUDED_hxDaedalus_graphics_flash_SimpleDrawingContext
#include <hxDaedalus/graphics/flash/SimpleDrawingContext.h>
#endif
namespace hxDaedalus{
namespace factories{

Void BitmapObject_obj::__construct()
{
HX_STACK_FRAME("hxDaedalus.factories.BitmapObject","new",0x7be5371f,"hxDaedalus.factories.BitmapObject.new","hxDaedalus/factories/BitmapObject.hx",21,0x1a22e02f)
HX_STACK_THIS(this)
{
}
;
	return null();
}

//BitmapObject_obj::~BitmapObject_obj() { }

Dynamic BitmapObject_obj::__CreateEmpty() { return  new BitmapObject_obj; }
hx::ObjectPtr< BitmapObject_obj > BitmapObject_obj::__new()
{  hx::ObjectPtr< BitmapObject_obj > result = new BitmapObject_obj();
	result->__construct();
	return result;}

Dynamic BitmapObject_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BitmapObject_obj > result = new BitmapObject_obj();
	result->__construct();
	return result;}

::hxDaedalus::data::Object BitmapObject_obj::buildFromBmpData( ::hxDaedalus::graphics::_Pixels::PixelsData bmpData,hx::Null< Float >  __o_simplificationEpsilon,::hxDaedalus::graphics::_Pixels::PixelsData debugBmp,::hxDaedalus::graphics::flash::SimpleDrawingContext debugShape){
Float simplificationEpsilon = __o_simplificationEpsilon.Default(1);
	HX_STACK_FRAME("hxDaedalus.factories.BitmapObject","buildFromBmpData",0x1f890618,"hxDaedalus.factories.BitmapObject.buildFromBmpData","hxDaedalus/factories/BitmapObject.hx",27,0x1a22e02f)
	HX_STACK_ARG(bmpData,"bmpData")
	HX_STACK_ARG(simplificationEpsilon,"simplificationEpsilon")
	HX_STACK_ARG(debugBmp,"debugBmp")
	HX_STACK_ARG(debugShape,"debugShape")
{
		HX_STACK_LINE(28)
		int i;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(29)
		int j;		HX_STACK_VAR(j,"j");
		HX_STACK_LINE(34)
		Array< ::Dynamic > shapes = ::hxDaedalus::data::math::Potrace_obj::buildShapes(bmpData,debugBmp,debugShape);		HX_STACK_VAR(shapes,"shapes");
		HX_STACK_LINE(37)
		if (((simplificationEpsilon >= (int)1))){
			HX_STACK_LINE(38)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(38)
			int _g = shapes->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(38)
			while((true)){
				HX_STACK_LINE(38)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(38)
					break;
				}
				HX_STACK_LINE(38)
				int i1 = (_g1)++;		HX_STACK_VAR(i1,"i1");
				HX_STACK_LINE(39)
				shapes[i1] = ::hxDaedalus::data::math::ShapeSimplifier_obj::simplify(shapes->__get(i1).StaticCast< Array< Float > >(),simplificationEpsilon);
			}
		}
		HX_STACK_LINE(44)
		Array< ::Dynamic > graphs = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(graphs,"graphs");
		HX_STACK_LINE(45)
		{
			HX_STACK_LINE(45)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(45)
			int _g = shapes->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(45)
			while((true)){
				HX_STACK_LINE(45)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(45)
					break;
				}
				HX_STACK_LINE(45)
				int i1 = (_g1)++;		HX_STACK_VAR(i1,"i1");
				HX_STACK_LINE(46)
				::hxDaedalus::data::graph::Graph _g2 = ::hxDaedalus::data::math::Potrace_obj::buildGraph(shapes->__get(i1).StaticCast< Array< Float > >());		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(46)
				graphs->push(_g2);
			}
		}
		HX_STACK_LINE(50)
		Array< ::Dynamic > polygons = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(polygons,"polygons");
		HX_STACK_LINE(51)
		{
			HX_STACK_LINE(51)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(51)
			int _g = graphs->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(51)
			while((true)){
				HX_STACK_LINE(51)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(51)
					break;
				}
				HX_STACK_LINE(51)
				int i1 = (_g1)++;		HX_STACK_VAR(i1,"i1");
				HX_STACK_LINE(52)
				Array< Float > _g11 = ::hxDaedalus::data::math::Potrace_obj::buildPolygon(graphs->__get(i1).StaticCast< ::hxDaedalus::data::graph::Graph >(),debugShape);		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(52)
				polygons->push(_g11);
			}
		}
		HX_STACK_LINE(56)
		::hxDaedalus::data::Object obj = ::hxDaedalus::data::Object_obj::__new();		HX_STACK_VAR(obj,"obj");
		HX_STACK_LINE(57)
		{
			HX_STACK_LINE(57)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(57)
			int _g = polygons->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(57)
			while((true)){
				HX_STACK_LINE(57)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(57)
					break;
				}
				HX_STACK_LINE(57)
				int i1 = (_g1)++;		HX_STACK_VAR(i1,"i1");
				HX_STACK_LINE(58)
				j = (int)0;
				HX_STACK_LINE(59)
				while((true)){
					HX_STACK_LINE(59)
					if ((!(((j < (polygons->__get(i1).StaticCast< Array< Float > >()->length - (int)2)))))){
						HX_STACK_LINE(59)
						break;
					}
					HX_STACK_LINE(61)
					obj->get_coordinates()->push(polygons->__get(i1).StaticCast< Array< Float > >()->__get(j));
					HX_STACK_LINE(62)
					obj->get_coordinates()->push(polygons->__get(i1).StaticCast< Array< Float > >()->__get((j + (int)1)));
					HX_STACK_LINE(63)
					obj->get_coordinates()->push(polygons->__get(i1).StaticCast< Array< Float > >()->__get((j + (int)2)));
					HX_STACK_LINE(64)
					obj->get_coordinates()->push(polygons->__get(i1).StaticCast< Array< Float > >()->__get((j + (int)3)));
					HX_STACK_LINE(65)
					hx::AddEq(j,(int)2);
				}
				HX_STACK_LINE(67)
				obj->get_coordinates()->push(polygons->__get(i1).StaticCast< Array< Float > >()->__get((int)0));
				HX_STACK_LINE(68)
				obj->get_coordinates()->push(polygons->__get(i1).StaticCast< Array< Float > >()->__get((int)1));
				HX_STACK_LINE(69)
				obj->get_coordinates()->push(polygons->__get(i1).StaticCast< Array< Float > >()->__get(j));
				HX_STACK_LINE(70)
				obj->get_coordinates()->push(polygons->__get(i1).StaticCast< Array< Float > >()->__get((j + (int)1)));
			}
		}
		HX_STACK_LINE(72)
		return obj;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(BitmapObject_obj,buildFromBmpData,return )


BitmapObject_obj::BitmapObject_obj()
{
}

Dynamic BitmapObject_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 16:
		if (HX_FIELD_EQ(inName,"buildFromBmpData") ) { return buildFromBmpData_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic BitmapObject_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void BitmapObject_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("buildFromBmpData"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BitmapObject_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BitmapObject_obj::__mClass,"__mClass");
};

#endif

Class BitmapObject_obj::__mClass;

void BitmapObject_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDaedalus.factories.BitmapObject"), hx::TCanCast< BitmapObject_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatics
#endif
#ifdef HXCPP_SCRIPTABLE
    , sMemberStorageInfo
#endif
);
}

void BitmapObject_obj::__boot()
{
}

} // end namespace hxDaedalus
} // end namespace factories
