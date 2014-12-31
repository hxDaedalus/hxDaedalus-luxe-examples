#ifndef INCLUDED_hxDaedalus_data_math_NodeData
#define INCLUDED_hxDaedalus_data_math_NodeData

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(hxDaedalus,data,math,NodeData)
HX_DECLARE_CLASS3(hxDaedalus,data,math,Point2D)
namespace hxDaedalus{
namespace data{
namespace math{


class HXCPP_CLASS_ATTRIBUTES  NodeData_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef NodeData_obj OBJ_;
		NodeData_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< NodeData_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~NodeData_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("NodeData"); }

		int index;
		::hxDaedalus::data::math::Point2D point;
};

} // end namespace hxDaedalus
} // end namespace data
} // end namespace math

#endif /* INCLUDED_hxDaedalus_data_math_NodeData */ 
