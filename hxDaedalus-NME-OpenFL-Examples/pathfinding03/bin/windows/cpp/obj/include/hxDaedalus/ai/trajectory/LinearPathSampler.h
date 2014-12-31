#ifndef INCLUDED_hxDaedalus_ai_trajectory_LinearPathSampler
#define INCLUDED_hxDaedalus_ai_trajectory_LinearPathSampler

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(hxDaedalus,ai,EntityAI)
HX_DECLARE_CLASS3(hxDaedalus,ai,trajectory,LinearPathSampler)
namespace hxDaedalus{
namespace ai{
namespace trajectory{


class HXCPP_CLASS_ATTRIBUTES  LinearPathSampler_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef LinearPathSampler_obj OBJ_;
		LinearPathSampler_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< LinearPathSampler_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~LinearPathSampler_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("LinearPathSampler"); }

		::hxDaedalus::ai::EntityAI entity;
		::hxDaedalus::ai::EntityAI _entity;
		Float _currentX;
		Float _currentY;
		bool _hasPrev;
		bool _hasNext;
		Float _samplingDistance;
		Float _samplingDistanceSquared;
		Array< Float > _path;
		int _iPrev;
		int _iNext;
		bool _preComputed;
		int _count;
		Array< Float > _preCompX;
		Array< Float > _preCompY;
		virtual Void dispose( );
		Dynamic dispose_dyn();

		virtual Float get_x( );
		Dynamic get_x_dyn();

		virtual Float get_y( );
		Dynamic get_y_dyn();

		virtual bool get_hasPrev( );
		Dynamic get_hasPrev_dyn();

		virtual bool get_hasNext( );
		Dynamic get_hasNext_dyn();

		virtual int get_count( );
		Dynamic get_count_dyn();

		virtual int set_count( int value);
		Dynamic set_count_dyn();

		virtual int get_countMax( );
		Dynamic get_countMax_dyn();

		virtual Float get_samplingDistance( );
		Dynamic get_samplingDistance_dyn();

		virtual Float set_samplingDistance( Float value);
		Dynamic set_samplingDistance_dyn();

		virtual Array< Float > set_path( Array< Float > value);
		Dynamic set_path_dyn();

		virtual Void reset( );
		Dynamic reset_dyn();

		virtual Void preCompute( );
		Dynamic preCompute_dyn();

		virtual bool prev( );
		Dynamic prev_dyn();

		virtual bool next( );
		Dynamic next_dyn();

		virtual Void updateEntity( );
		Dynamic updateEntity_dyn();

		static Float pythag( Float a,Float b);
		static Dynamic pythag_dyn();

};

} // end namespace hxDaedalus
} // end namespace ai
} // end namespace trajectory

#endif /* INCLUDED_hxDaedalus_ai_trajectory_LinearPathSampler */ 
