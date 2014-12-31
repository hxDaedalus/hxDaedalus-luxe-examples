#ifndef INCLUDED_hxDaedalus_factories_RectMesh
#define INCLUDED_hxDaedalus_factories_RectMesh

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(hxDaedalus,data,Mesh)
HX_DECLARE_CLASS2(hxDaedalus,factories,RectMesh)
namespace hxDaedalus{
namespace factories{


class HXCPP_CLASS_ATTRIBUTES  RectMesh_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef RectMesh_obj OBJ_;
		RectMesh_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< RectMesh_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~RectMesh_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("RectMesh"); }

		static ::hxDaedalus::data::Mesh buildRectangle( Float width,Float height);
		static Dynamic buildRectangle_dyn();

};

} // end namespace hxDaedalus
} // end namespace factories

#endif /* INCLUDED_hxDaedalus_factories_RectMesh */ 
