#ifndef INCLUDED_hxDaedalus_data_Object
#define INCLUDED_hxDaedalus_data_Object

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(hxDaedalus,data,ConstraintShape)
HX_DECLARE_CLASS2(hxDaedalus,data,Edge)
HX_DECLARE_CLASS2(hxDaedalus,data,Object)
HX_DECLARE_CLASS3(hxDaedalus,data,math,Matrix2D)
namespace hxDaedalus{
namespace data{


class HXCPP_CLASS_ATTRIBUTES  Object_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Object_obj OBJ_;
		Object_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Object_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Object_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Object"); }

		int _id;
		::hxDaedalus::data::math::Matrix2D _matrix;
		Array< Float > _coordinates;
		::hxDaedalus::data::ConstraintShape _constraintShape;
		Float _pivotX;
		Float _pivotY;
		Float _scaleX;
		Float _scaleY;
		Float _rotation;
		Float _x;
		Float _y;
		bool _hasChanged;
		virtual int get_id( );
		Dynamic get_id_dyn();

		virtual Void dispose( );
		Dynamic dispose_dyn();

		virtual Void updateValuesFromMatrix( );
		Dynamic updateValuesFromMatrix_dyn();

		virtual Void updateMatrixFromValues( );
		Dynamic updateMatrixFromValues_dyn();

		virtual Float get_pivotX( );
		Dynamic get_pivotX_dyn();

		virtual Float set_pivotX( Float value);
		Dynamic set_pivotX_dyn();

		virtual Float get_pivotY( );
		Dynamic get_pivotY_dyn();

		virtual Float set_pivotY( Float value);
		Dynamic set_pivotY_dyn();

		virtual Float get_scaleX( );
		Dynamic get_scaleX_dyn();

		virtual Float set_scaleX( Float value);
		Dynamic set_scaleX_dyn();

		virtual Float get_scaleY( );
		Dynamic get_scaleY_dyn();

		virtual Float set_scaleY( Float value);
		Dynamic set_scaleY_dyn();

		virtual Float get_rotation( );
		Dynamic get_rotation_dyn();

		virtual Float set_rotation( Float value);
		Dynamic set_rotation_dyn();

		virtual Float get_x( );
		Dynamic get_x_dyn();

		virtual Float set_x( Float value);
		Dynamic set_x_dyn();

		virtual Float get_y( );
		Dynamic get_y_dyn();

		virtual Float set_y( Float value);
		Dynamic set_y_dyn();

		virtual ::hxDaedalus::data::math::Matrix2D get_matrix( );
		Dynamic get_matrix_dyn();

		virtual ::hxDaedalus::data::math::Matrix2D set_matrix( ::hxDaedalus::data::math::Matrix2D value);
		Dynamic set_matrix_dyn();

		virtual Array< Float > get_coordinates( );
		Dynamic get_coordinates_dyn();

		virtual Array< Float > set_coordinates( Array< Float > value);
		Dynamic set_coordinates_dyn();

		virtual ::hxDaedalus::data::ConstraintShape get_constraintShape( );
		Dynamic get_constraintShape_dyn();

		virtual ::hxDaedalus::data::ConstraintShape set_constraintShape( ::hxDaedalus::data::ConstraintShape value);
		Dynamic set_constraintShape_dyn();

		virtual bool get_hasChanged( );
		Dynamic get_hasChanged_dyn();

		virtual bool set_hasChanged( bool value);
		Dynamic set_hasChanged_dyn();

		virtual Array< ::Dynamic > get_edges( );
		Dynamic get_edges_dyn();

		static int INC;
};

} // end namespace hxDaedalus
} // end namespace data

#endif /* INCLUDED_hxDaedalus_data_Object */ 
