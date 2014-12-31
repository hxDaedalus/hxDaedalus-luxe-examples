#ifndef INCLUDED_hxDaedalus_data_math_Intersection
#define INCLUDED_hxDaedalus_data_math_Intersection

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(hxDaedalus,data,Edge)
HX_DECLARE_CLASS2(hxDaedalus,data,Face)
HX_DECLARE_CLASS2(hxDaedalus,data,Vertex)
HX_DECLARE_CLASS3(hxDaedalus,data,math,Intersection)
namespace hxDaedalus{
namespace data{
namespace math{


class Intersection_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef Intersection_obj OBJ_;

	public:
		Intersection_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("hxDaedalus.data.math.Intersection"); }
		::String __ToString() const { return HX_CSTRING("Intersection.") + tag; }

		static ::hxDaedalus::data::math::Intersection EEdge(::hxDaedalus::data::Edge edge);
		static Dynamic EEdge_dyn();
		static ::hxDaedalus::data::math::Intersection EFace(::hxDaedalus::data::Face face);
		static Dynamic EFace_dyn();
		static ::hxDaedalus::data::math::Intersection ENull;
		static inline ::hxDaedalus::data::math::Intersection ENull_dyn() { return ENull; }
		static ::hxDaedalus::data::math::Intersection EVertex(::hxDaedalus::data::Vertex vertex);
		static Dynamic EVertex_dyn();
};

} // end namespace hxDaedalus
} // end namespace data
} // end namespace math

#endif /* INCLUDED_hxDaedalus_data_math_Intersection */ 
