#ifndef INCLUDED_hxDaedalus_data_Face
#define INCLUDED_hxDaedalus_data_Face

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(hxDaedalus,data,Edge)
HX_DECLARE_CLASS2(hxDaedalus,data,Face)
namespace hxDaedalus{
namespace data{


class HXCPP_CLASS_ATTRIBUTES  Face_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Face_obj OBJ_;
		Face_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Face_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Face_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Face"); }

		int _id;
		bool _isReal;
		::hxDaedalus::data::Edge _edge;
		int colorDebug;
		virtual int get_id( );
		Dynamic get_id_dyn();

		virtual bool get_isReal( );
		Dynamic get_isReal_dyn();

		virtual Void set_datas( ::hxDaedalus::data::Edge edge);
		Dynamic set_datas_dyn();

		virtual Void setDatas( ::hxDaedalus::data::Edge edge,hx::Null< bool >  isReal);
		Dynamic setDatas_dyn();

		virtual Void dispose( );
		Dynamic dispose_dyn();

		virtual ::hxDaedalus::data::Edge get_edge( );
		Dynamic get_edge_dyn();

		static int INC;
};

} // end namespace hxDaedalus
} // end namespace data

#endif /* INCLUDED_hxDaedalus_data_Face */ 
