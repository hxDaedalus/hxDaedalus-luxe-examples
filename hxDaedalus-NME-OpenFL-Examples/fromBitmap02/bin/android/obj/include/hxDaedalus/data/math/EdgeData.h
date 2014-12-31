#ifndef INCLUDED_hxDaedalus_data_math_EdgeData
#define INCLUDED_hxDaedalus_data_math_EdgeData

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(hxDaedalus,data,math,EdgeData)
namespace hxDaedalus{
namespace data{
namespace math{


class HXCPP_CLASS_ATTRIBUTES  EdgeData_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef EdgeData_obj OBJ_;
		EdgeData_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< EdgeData_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~EdgeData_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("EdgeData"); }

		Float sumDistancesSquared;
		Float length;
		int nodesCount;
};

} // end namespace hxDaedalus
} // end namespace data
} // end namespace math

#endif /* INCLUDED_hxDaedalus_data_math_EdgeData */ 
