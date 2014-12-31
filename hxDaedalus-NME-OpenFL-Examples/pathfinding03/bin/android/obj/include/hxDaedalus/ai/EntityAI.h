#ifndef INCLUDED_hxDaedalus_ai_EntityAI
#define INCLUDED_hxDaedalus_ai_EntityAI

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(hxDaedalus,ai,EntityAI)
HX_DECLARE_CLASS2(hxDaedalus,data,Object)
namespace hxDaedalus{
namespace ai{


class HXCPP_CLASS_ATTRIBUTES  EntityAI_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef EntityAI_obj OBJ_;
		EntityAI_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< EntityAI_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~EntityAI_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("EntityAI"); }

		Float angleFOV;
		Float dirNormY;
		Float dirNormX;
		Float y;
		Float x;
		Float _radius;
		Float _radiusSquared;
		Float _x;
		Float _y;
		Float _dirNormX;
		Float _dirNormY;
		Float _angleFOV;
		::hxDaedalus::data::Object _approximateObject;
		virtual Void buildApproximation( );
		Dynamic buildApproximation_dyn();

		virtual ::hxDaedalus::data::Object get_approximateObject( );
		Dynamic get_approximateObject_dyn();

		virtual Float get_radius( );
		Dynamic get_radius_dyn();

		virtual Float get_radiusSquared( );
		Dynamic get_radiusSquared_dyn();

		virtual Float set_radius( Float value);
		Dynamic set_radius_dyn();

		static int NUM_SEGMENTS;
};

} // end namespace hxDaedalus
} // end namespace ai

#endif /* INCLUDED_hxDaedalus_ai_EntityAI */ 
