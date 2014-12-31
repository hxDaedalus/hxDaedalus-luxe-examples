#ifndef INCLUDED_hxDaedalus_data_math_RandGenerator
#define INCLUDED_hxDaedalus_data_math_RandGenerator

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(hxDaedalus,data,math,RandGenerator)
namespace hxDaedalus{
namespace data{
namespace math{


class HXCPP_CLASS_ATTRIBUTES  RandGenerator_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef RandGenerator_obj OBJ_;
		RandGenerator_obj();
		Void __construct(hx::Null< int >  __o_seed,hx::Null< int >  __o_rangeMin_,hx::Null< int >  __o_rangeMax_);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< RandGenerator_obj > __new(hx::Null< int >  __o_seed,hx::Null< int >  __o_rangeMin_,hx::Null< int >  __o_rangeMax_);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~RandGenerator_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("RandGenerator"); }

		int rangeMin;
		int rangeMax;
		int _originalSeed;
		int _currSeed;
		int _rangeMin;
		int _rangeMax;
		int _numIter;
		::String _tempString;
		virtual int set_seed( int value);
		Dynamic set_seed_dyn();

		virtual int get_seed( );
		Dynamic get_seed_dyn();

		virtual Void reset( );
		Dynamic reset_dyn();

		virtual int next( );
		Dynamic next_dyn();

		virtual int nextInRange( int rangeMin,int rangeMax);
		Dynamic nextInRange_dyn();

		virtual Void shuffle( Dynamic array);
		Dynamic shuffle_dyn();

};

} // end namespace hxDaedalus
} // end namespace data
} // end namespace math

#endif /* INCLUDED_hxDaedalus_data_math_RandGenerator */ 
