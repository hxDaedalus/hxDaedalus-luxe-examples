#include <hxcpp.h>

#ifndef INCLUDED_hxDaedalus_data_ConstraintSegment
#include <hxDaedalus/data/ConstraintSegment.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_ConstraintShape
#include <hxDaedalus/data/ConstraintShape.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_Edge
#include <hxDaedalus/data/Edge.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_Object
#include <hxDaedalus/data/Object.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_math_Matrix2D
#include <hxDaedalus/data/math/Matrix2D.h>
#endif
namespace hxDaedalus{
namespace data{

Void Object_obj::__construct()
{
HX_STACK_FRAME("hxDaedalus.data.Object","new",0x12ab72fc,"hxDaedalus.data.Object.new","hxDaedalus/data/Object.hx",40,0x947f1794)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(41)
	this->_id = ::hxDaedalus::data::Object_obj::INC;
	HX_STACK_LINE(42)
	(::hxDaedalus::data::Object_obj::INC)++;
	HX_STACK_LINE(44)
	this->_pivotX = (int)0;
	HX_STACK_LINE(45)
	this->_pivotY = (int)0;
	HX_STACK_LINE(47)
	::hxDaedalus::data::math::Matrix2D _g = ::hxDaedalus::data::math::Matrix2D_obj::__new(null(),null(),null(),null(),null(),null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(47)
	this->_matrix = _g;
	HX_STACK_LINE(48)
	this->_scaleX = (int)1;
	HX_STACK_LINE(49)
	this->_scaleY = (int)1;
	HX_STACK_LINE(50)
	this->_rotation = (int)0;
	HX_STACK_LINE(51)
	this->_x = (int)0;
	HX_STACK_LINE(52)
	this->_y = (int)0;
	HX_STACK_LINE(54)
	Array< Float > _g1 = Array_obj< Float >::__new();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(54)
	this->_coordinates = _g1;
	HX_STACK_LINE(56)
	this->_hasChanged = false;
}
;
	return null();
}

//Object_obj::~Object_obj() { }

Dynamic Object_obj::__CreateEmpty() { return  new Object_obj; }
hx::ObjectPtr< Object_obj > Object_obj::__new()
{  hx::ObjectPtr< Object_obj > result = new Object_obj();
	result->__construct();
	return result;}

Dynamic Object_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Object_obj > result = new Object_obj();
	result->__construct();
	return result;}

int Object_obj::get_id( ){
	HX_STACK_FRAME("hxDaedalus.data.Object","get_id",0xdce6da08,"hxDaedalus.data.Object.get_id","hxDaedalus/data/Object.hx",60,0x947f1794)
	HX_STACK_THIS(this)
	HX_STACK_LINE(60)
	return this->_id;
}


HX_DEFINE_DYNAMIC_FUNC0(Object_obj,get_id,return )

Void Object_obj::dispose( ){
{
		HX_STACK_FRAME("hxDaedalus.data.Object","dispose",0x019fa13b,"hxDaedalus.data.Object.dispose","hxDaedalus/data/Object.hx",63,0x947f1794)
		HX_STACK_THIS(this)
		HX_STACK_LINE(64)
		this->_matrix = null();
		HX_STACK_LINE(65)
		this->_coordinates = null();
		HX_STACK_LINE(66)
		this->_constraintShape = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Object_obj,dispose,(void))

Void Object_obj::updateValuesFromMatrix( ){
{
		HX_STACK_FRAME("hxDaedalus.data.Object","updateValuesFromMatrix",0x3ad964da,"hxDaedalus.data.Object.updateValuesFromMatrix","hxDaedalus/data/Object.hx",69,0x947f1794)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Object_obj,updateValuesFromMatrix,(void))

Void Object_obj::updateMatrixFromValues( ){
{
		HX_STACK_FRAME("hxDaedalus.data.Object","updateMatrixFromValues",0x9d95b19a,"hxDaedalus.data.Object.updateMatrixFromValues","hxDaedalus/data/Object.hx",74,0x947f1794)
		HX_STACK_THIS(this)
		HX_STACK_LINE(75)
		this->_matrix->identity();
		HX_STACK_LINE(76)
		this->_matrix->translate(-(this->_pivotX),-(this->_pivotY));
		HX_STACK_LINE(77)
		this->_matrix->scale(this->_scaleX,this->_scaleY);
		HX_STACK_LINE(78)
		this->_matrix->rotate(this->_rotation);
		HX_STACK_LINE(79)
		this->_matrix->translate(this->_x,this->_y);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Object_obj,updateMatrixFromValues,(void))

Float Object_obj::get_pivotX( ){
	HX_STACK_FRAME("hxDaedalus.data.Object","get_pivotX",0x3964b803,"hxDaedalus.data.Object.get_pivotX","hxDaedalus/data/Object.hx",83,0x947f1794)
	HX_STACK_THIS(this)
	HX_STACK_LINE(83)
	return this->_pivotX;
}


HX_DEFINE_DYNAMIC_FUNC0(Object_obj,get_pivotX,return )

Float Object_obj::set_pivotX( Float value){
	HX_STACK_FRAME("hxDaedalus.data.Object","set_pivotX",0x3ce25677,"hxDaedalus.data.Object.set_pivotX","hxDaedalus/data/Object.hx",86,0x947f1794)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(87)
	this->_pivotX = value;
	HX_STACK_LINE(88)
	this->_hasChanged = true;
	HX_STACK_LINE(89)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Object_obj,set_pivotX,return )

Float Object_obj::get_pivotY( ){
	HX_STACK_FRAME("hxDaedalus.data.Object","get_pivotY",0x3964b804,"hxDaedalus.data.Object.get_pivotY","hxDaedalus/data/Object.hx",93,0x947f1794)
	HX_STACK_THIS(this)
	HX_STACK_LINE(93)
	return this->_pivotY;
}


HX_DEFINE_DYNAMIC_FUNC0(Object_obj,get_pivotY,return )

Float Object_obj::set_pivotY( Float value){
	HX_STACK_FRAME("hxDaedalus.data.Object","set_pivotY",0x3ce25678,"hxDaedalus.data.Object.set_pivotY","hxDaedalus/data/Object.hx",96,0x947f1794)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(97)
	this->_pivotY = value;
	HX_STACK_LINE(98)
	this->_hasChanged = true;
	HX_STACK_LINE(99)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Object_obj,set_pivotY,return )

Float Object_obj::get_scaleX( ){
	HX_STACK_FRAME("hxDaedalus.data.Object","get_scaleX",0xea2b833b,"hxDaedalus.data.Object.get_scaleX","hxDaedalus/data/Object.hx",103,0x947f1794)
	HX_STACK_THIS(this)
	HX_STACK_LINE(103)
	return this->_scaleX;
}


HX_DEFINE_DYNAMIC_FUNC0(Object_obj,get_scaleX,return )

Float Object_obj::set_scaleX( Float value){
	HX_STACK_FRAME("hxDaedalus.data.Object","set_scaleX",0xeda921af,"hxDaedalus.data.Object.set_scaleX","hxDaedalus/data/Object.hx",106,0x947f1794)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(107)
	if (((this->_scaleX != value))){
		HX_STACK_LINE(108)
		this->_scaleX = value;
		HX_STACK_LINE(109)
		this->_hasChanged = true;
	}
	HX_STACK_LINE(111)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Object_obj,set_scaleX,return )

Float Object_obj::get_scaleY( ){
	HX_STACK_FRAME("hxDaedalus.data.Object","get_scaleY",0xea2b833c,"hxDaedalus.data.Object.get_scaleY","hxDaedalus/data/Object.hx",115,0x947f1794)
	HX_STACK_THIS(this)
	HX_STACK_LINE(115)
	return this->_scaleY;
}


HX_DEFINE_DYNAMIC_FUNC0(Object_obj,get_scaleY,return )

Float Object_obj::set_scaleY( Float value){
	HX_STACK_FRAME("hxDaedalus.data.Object","set_scaleY",0xeda921b0,"hxDaedalus.data.Object.set_scaleY","hxDaedalus/data/Object.hx",118,0x947f1794)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(119)
	if (((this->_scaleY != value))){
		HX_STACK_LINE(120)
		this->_scaleY = value;
		HX_STACK_LINE(121)
		this->_hasChanged = true;
	}
	HX_STACK_LINE(123)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Object_obj,set_scaleY,return )

Float Object_obj::get_rotation( ){
	HX_STACK_FRAME("hxDaedalus.data.Object","get_rotation",0x75a51b2b,"hxDaedalus.data.Object.get_rotation","hxDaedalus/data/Object.hx",127,0x947f1794)
	HX_STACK_THIS(this)
	HX_STACK_LINE(127)
	return this->_rotation;
}


HX_DEFINE_DYNAMIC_FUNC0(Object_obj,get_rotation,return )

Float Object_obj::set_rotation( Float value){
	HX_STACK_FRAME("hxDaedalus.data.Object","set_rotation",0x8a9e3e9f,"hxDaedalus.data.Object.set_rotation","hxDaedalus/data/Object.hx",130,0x947f1794)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(131)
	if (((this->_rotation != value))){
		HX_STACK_LINE(132)
		this->_rotation = value;
		HX_STACK_LINE(133)
		this->_hasChanged = true;
	}
	HX_STACK_LINE(135)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Object_obj,set_rotation,return )

Float Object_obj::get_x( ){
	HX_STACK_FRAME("hxDaedalus.data.Object","get_x",0xa2db26eb,"hxDaedalus.data.Object.get_x","hxDaedalus/data/Object.hx",139,0x947f1794)
	HX_STACK_THIS(this)
	HX_STACK_LINE(139)
	return this->_x;
}


HX_DEFINE_DYNAMIC_FUNC0(Object_obj,get_x,return )

Float Object_obj::set_x( Float value){
	HX_STACK_FRAME("hxDaedalus.data.Object","set_x",0x8baa1cf7,"hxDaedalus.data.Object.set_x","hxDaedalus/data/Object.hx",142,0x947f1794)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(143)
	if (((this->_x != value))){
		HX_STACK_LINE(144)
		this->_x = value;
		HX_STACK_LINE(145)
		this->_hasChanged = true;
	}
	HX_STACK_LINE(147)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Object_obj,set_x,return )

Float Object_obj::get_y( ){
	HX_STACK_FRAME("hxDaedalus.data.Object","get_y",0xa2db26ec,"hxDaedalus.data.Object.get_y","hxDaedalus/data/Object.hx",151,0x947f1794)
	HX_STACK_THIS(this)
	HX_STACK_LINE(151)
	return this->_y;
}


HX_DEFINE_DYNAMIC_FUNC0(Object_obj,get_y,return )

Float Object_obj::set_y( Float value){
	HX_STACK_FRAME("hxDaedalus.data.Object","set_y",0x8baa1cf8,"hxDaedalus.data.Object.set_y","hxDaedalus/data/Object.hx",154,0x947f1794)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(155)
	if (((this->_y != value))){
		HX_STACK_LINE(156)
		this->_y = value;
		HX_STACK_LINE(157)
		this->_hasChanged = true;
	}
	HX_STACK_LINE(159)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Object_obj,set_y,return )

::hxDaedalus::data::math::Matrix2D Object_obj::get_matrix( ){
	HX_STACK_FRAME("hxDaedalus.data.Object","get_matrix",0x69cdceee,"hxDaedalus.data.Object.get_matrix","hxDaedalus/data/Object.hx",163,0x947f1794)
	HX_STACK_THIS(this)
	HX_STACK_LINE(163)
	return this->_matrix;
}


HX_DEFINE_DYNAMIC_FUNC0(Object_obj,get_matrix,return )

::hxDaedalus::data::math::Matrix2D Object_obj::set_matrix( ::hxDaedalus::data::math::Matrix2D value){
	HX_STACK_FRAME("hxDaedalus.data.Object","set_matrix",0x6d4b6d62,"hxDaedalus.data.Object.set_matrix","hxDaedalus/data/Object.hx",166,0x947f1794)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(167)
	this->_matrix = value;
	HX_STACK_LINE(168)
	this->_hasChanged = true;
	HX_STACK_LINE(169)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Object_obj,set_matrix,return )

Array< Float > Object_obj::get_coordinates( ){
	HX_STACK_FRAME("hxDaedalus.data.Object","get_coordinates",0xc046c72e,"hxDaedalus.data.Object.get_coordinates","hxDaedalus/data/Object.hx",173,0x947f1794)
	HX_STACK_THIS(this)
	HX_STACK_LINE(173)
	return this->_coordinates;
}


HX_DEFINE_DYNAMIC_FUNC0(Object_obj,get_coordinates,return )

Array< Float > Object_obj::set_coordinates( Array< Float > value){
	HX_STACK_FRAME("hxDaedalus.data.Object","set_coordinates",0xbc12443a,"hxDaedalus.data.Object.set_coordinates","hxDaedalus/data/Object.hx",176,0x947f1794)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(177)
	this->_coordinates = value;
	HX_STACK_LINE(178)
	this->_hasChanged = true;
	HX_STACK_LINE(179)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Object_obj,set_coordinates,return )

::hxDaedalus::data::ConstraintShape Object_obj::get_constraintShape( ){
	HX_STACK_FRAME("hxDaedalus.data.Object","get_constraintShape",0x53094b37,"hxDaedalus.data.Object.get_constraintShape","hxDaedalus/data/Object.hx",184,0x947f1794)
	HX_STACK_THIS(this)
	HX_STACK_LINE(184)
	return this->_constraintShape;
}


HX_DEFINE_DYNAMIC_FUNC0(Object_obj,get_constraintShape,return )

::hxDaedalus::data::ConstraintShape Object_obj::set_constraintShape( ::hxDaedalus::data::ConstraintShape value){
	HX_STACK_FRAME("hxDaedalus.data.Object","set_constraintShape",0x8fa63e43,"hxDaedalus.data.Object.set_constraintShape","hxDaedalus/data/Object.hx",187,0x947f1794)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(188)
	this->_constraintShape = value;
	HX_STACK_LINE(189)
	this->_hasChanged = true;
	HX_STACK_LINE(190)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Object_obj,set_constraintShape,return )

bool Object_obj::get_hasChanged( ){
	HX_STACK_FRAME("hxDaedalus.data.Object","get_hasChanged",0x70848be7,"hxDaedalus.data.Object.get_hasChanged","hxDaedalus/data/Object.hx",194,0x947f1794)
	HX_STACK_THIS(this)
	HX_STACK_LINE(194)
	return this->_hasChanged;
}


HX_DEFINE_DYNAMIC_FUNC0(Object_obj,get_hasChanged,return )

bool Object_obj::set_hasChanged( bool value){
	HX_STACK_FRAME("hxDaedalus.data.Object","set_hasChanged",0x90a4745b,"hxDaedalus.data.Object.set_hasChanged","hxDaedalus/data/Object.hx",197,0x947f1794)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(198)
	this->_hasChanged = value;
	HX_STACK_LINE(199)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Object_obj,set_hasChanged,return )

Array< ::Dynamic > Object_obj::get_edges( ){
	HX_STACK_FRAME("hxDaedalus.data.Object","get_edges",0x875b4989,"hxDaedalus.data.Object.get_edges","hxDaedalus/data/Object.hx",202,0x947f1794)
	HX_STACK_THIS(this)
	HX_STACK_LINE(204)
	Array< ::Dynamic > res = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(res,"res");
	HX_STACK_LINE(205)
	Array< ::Dynamic > seg = this->_constraintShape->segments;		HX_STACK_VAR(seg,"seg");
	HX_STACK_LINE(206)
	{
		HX_STACK_LINE(206)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(206)
		int _g = seg->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(206)
		while((true)){
			HX_STACK_LINE(206)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(206)
				break;
			}
			HX_STACK_LINE(206)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(207)
			{
				HX_STACK_LINE(207)
				int _g3 = (int)0;		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(207)
				int _g2 = seg->__get(i).StaticCast< ::hxDaedalus::data::ConstraintSegment >()->get_edges()->length;		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(207)
				while((true)){
					HX_STACK_LINE(207)
					if ((!(((_g3 < _g2))))){
						HX_STACK_LINE(207)
						break;
					}
					HX_STACK_LINE(207)
					int j = (_g3)++;		HX_STACK_VAR(j,"j");
					HX_STACK_LINE(208)
					Array< ::Dynamic > _g4 = seg->__get(i).StaticCast< ::hxDaedalus::data::ConstraintSegment >()->get_edges();		HX_STACK_VAR(_g4,"_g4");
					HX_STACK_LINE(208)
					::hxDaedalus::data::Edge _g11 = _g4->__get(j).StaticCast< ::hxDaedalus::data::Edge >();		HX_STACK_VAR(_g11,"_g11");
					HX_STACK_LINE(208)
					res->push(_g11);
				}
			}
		}
	}
	HX_STACK_LINE(212)
	return res;
}


HX_DEFINE_DYNAMIC_FUNC0(Object_obj,get_edges,return )

int Object_obj::INC;


Object_obj::Object_obj()
{
}

void Object_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Object);
	HX_MARK_MEMBER_NAME(_id,"_id");
	HX_MARK_MEMBER_NAME(_matrix,"_matrix");
	HX_MARK_MEMBER_NAME(_coordinates,"_coordinates");
	HX_MARK_MEMBER_NAME(_constraintShape,"_constraintShape");
	HX_MARK_MEMBER_NAME(_pivotX,"_pivotX");
	HX_MARK_MEMBER_NAME(_pivotY,"_pivotY");
	HX_MARK_MEMBER_NAME(_scaleX,"_scaleX");
	HX_MARK_MEMBER_NAME(_scaleY,"_scaleY");
	HX_MARK_MEMBER_NAME(_rotation,"_rotation");
	HX_MARK_MEMBER_NAME(_x,"_x");
	HX_MARK_MEMBER_NAME(_y,"_y");
	HX_MARK_MEMBER_NAME(_hasChanged,"_hasChanged");
	HX_MARK_END_CLASS();
}

void Object_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_id,"_id");
	HX_VISIT_MEMBER_NAME(_matrix,"_matrix");
	HX_VISIT_MEMBER_NAME(_coordinates,"_coordinates");
	HX_VISIT_MEMBER_NAME(_constraintShape,"_constraintShape");
	HX_VISIT_MEMBER_NAME(_pivotX,"_pivotX");
	HX_VISIT_MEMBER_NAME(_pivotY,"_pivotY");
	HX_VISIT_MEMBER_NAME(_scaleX,"_scaleX");
	HX_VISIT_MEMBER_NAME(_scaleY,"_scaleY");
	HX_VISIT_MEMBER_NAME(_rotation,"_rotation");
	HX_VISIT_MEMBER_NAME(_x,"_x");
	HX_VISIT_MEMBER_NAME(_y,"_y");
	HX_VISIT_MEMBER_NAME(_hasChanged,"_hasChanged");
}

Dynamic Object_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { return get_x(); }
		if (HX_FIELD_EQ(inName,"y") ) { return get_y(); }
		break;
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { return get_id(); }
		if (HX_FIELD_EQ(inName,"_x") ) { return _x; }
		if (HX_FIELD_EQ(inName,"_y") ) { return _y; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"INC") ) { return INC; }
		if (HX_FIELD_EQ(inName,"_id") ) { return _id; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"edges") ) { return get_edges(); }
		if (HX_FIELD_EQ(inName,"get_x") ) { return get_x_dyn(); }
		if (HX_FIELD_EQ(inName,"set_x") ) { return set_x_dyn(); }
		if (HX_FIELD_EQ(inName,"get_y") ) { return get_y_dyn(); }
		if (HX_FIELD_EQ(inName,"set_y") ) { return set_y_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"pivotX") ) { return get_pivotX(); }
		if (HX_FIELD_EQ(inName,"pivotY") ) { return get_pivotY(); }
		if (HX_FIELD_EQ(inName,"scaleX") ) { return get_scaleX(); }
		if (HX_FIELD_EQ(inName,"scaleY") ) { return get_scaleY(); }
		if (HX_FIELD_EQ(inName,"matrix") ) { return get_matrix(); }
		if (HX_FIELD_EQ(inName,"get_id") ) { return get_id_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_matrix") ) { return _matrix; }
		if (HX_FIELD_EQ(inName,"_pivotX") ) { return _pivotX; }
		if (HX_FIELD_EQ(inName,"_pivotY") ) { return _pivotY; }
		if (HX_FIELD_EQ(inName,"_scaleX") ) { return _scaleX; }
		if (HX_FIELD_EQ(inName,"_scaleY") ) { return _scaleY; }
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"rotation") ) { return get_rotation(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_rotation") ) { return _rotation; }
		if (HX_FIELD_EQ(inName,"get_edges") ) { return get_edges_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"hasChanged") ) { return get_hasChanged(); }
		if (HX_FIELD_EQ(inName,"get_pivotX") ) { return get_pivotX_dyn(); }
		if (HX_FIELD_EQ(inName,"set_pivotX") ) { return set_pivotX_dyn(); }
		if (HX_FIELD_EQ(inName,"get_pivotY") ) { return get_pivotY_dyn(); }
		if (HX_FIELD_EQ(inName,"set_pivotY") ) { return set_pivotY_dyn(); }
		if (HX_FIELD_EQ(inName,"get_scaleX") ) { return get_scaleX_dyn(); }
		if (HX_FIELD_EQ(inName,"set_scaleX") ) { return set_scaleX_dyn(); }
		if (HX_FIELD_EQ(inName,"get_scaleY") ) { return get_scaleY_dyn(); }
		if (HX_FIELD_EQ(inName,"set_scaleY") ) { return set_scaleY_dyn(); }
		if (HX_FIELD_EQ(inName,"get_matrix") ) { return get_matrix_dyn(); }
		if (HX_FIELD_EQ(inName,"set_matrix") ) { return set_matrix_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"coordinates") ) { return get_coordinates(); }
		if (HX_FIELD_EQ(inName,"_hasChanged") ) { return _hasChanged; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_coordinates") ) { return _coordinates; }
		if (HX_FIELD_EQ(inName,"get_rotation") ) { return get_rotation_dyn(); }
		if (HX_FIELD_EQ(inName,"set_rotation") ) { return set_rotation_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"get_hasChanged") ) { return get_hasChanged_dyn(); }
		if (HX_FIELD_EQ(inName,"set_hasChanged") ) { return set_hasChanged_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"constraintShape") ) { return get_constraintShape(); }
		if (HX_FIELD_EQ(inName,"get_coordinates") ) { return get_coordinates_dyn(); }
		if (HX_FIELD_EQ(inName,"set_coordinates") ) { return set_coordinates_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_constraintShape") ) { return _constraintShape; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"get_constraintShape") ) { return get_constraintShape_dyn(); }
		if (HX_FIELD_EQ(inName,"set_constraintShape") ) { return set_constraintShape_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"updateValuesFromMatrix") ) { return updateValuesFromMatrix_dyn(); }
		if (HX_FIELD_EQ(inName,"updateMatrixFromValues") ) { return updateMatrixFromValues_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Object_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { return set_x(inValue); }
		if (HX_FIELD_EQ(inName,"y") ) { return set_y(inValue); }
		break;
	case 2:
		if (HX_FIELD_EQ(inName,"_x") ) { _x=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_y") ) { _y=inValue.Cast< Float >(); return inValue; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"INC") ) { INC=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_id") ) { _id=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"pivotX") ) { return set_pivotX(inValue); }
		if (HX_FIELD_EQ(inName,"pivotY") ) { return set_pivotY(inValue); }
		if (HX_FIELD_EQ(inName,"scaleX") ) { return set_scaleX(inValue); }
		if (HX_FIELD_EQ(inName,"scaleY") ) { return set_scaleY(inValue); }
		if (HX_FIELD_EQ(inName,"matrix") ) { return set_matrix(inValue); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_matrix") ) { _matrix=inValue.Cast< ::hxDaedalus::data::math::Matrix2D >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_pivotX") ) { _pivotX=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_pivotY") ) { _pivotY=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_scaleX") ) { _scaleX=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_scaleY") ) { _scaleY=inValue.Cast< Float >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"rotation") ) { return set_rotation(inValue); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_rotation") ) { _rotation=inValue.Cast< Float >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"hasChanged") ) { return set_hasChanged(inValue); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"coordinates") ) { return set_coordinates(inValue); }
		if (HX_FIELD_EQ(inName,"_hasChanged") ) { _hasChanged=inValue.Cast< bool >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_coordinates") ) { _coordinates=inValue.Cast< Array< Float > >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"constraintShape") ) { return set_constraintShape(inValue); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_constraintShape") ) { _constraintShape=inValue.Cast< ::hxDaedalus::data::ConstraintShape >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Object_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("id"));
	outFields->push(HX_CSTRING("pivotX"));
	outFields->push(HX_CSTRING("pivotY"));
	outFields->push(HX_CSTRING("scaleX"));
	outFields->push(HX_CSTRING("scaleY"));
	outFields->push(HX_CSTRING("rotation"));
	outFields->push(HX_CSTRING("x"));
	outFields->push(HX_CSTRING("y"));
	outFields->push(HX_CSTRING("matrix"));
	outFields->push(HX_CSTRING("coordinates"));
	outFields->push(HX_CSTRING("constraintShape"));
	outFields->push(HX_CSTRING("hasChanged"));
	outFields->push(HX_CSTRING("edges"));
	outFields->push(HX_CSTRING("_id"));
	outFields->push(HX_CSTRING("_matrix"));
	outFields->push(HX_CSTRING("_coordinates"));
	outFields->push(HX_CSTRING("_constraintShape"));
	outFields->push(HX_CSTRING("_pivotX"));
	outFields->push(HX_CSTRING("_pivotY"));
	outFields->push(HX_CSTRING("_scaleX"));
	outFields->push(HX_CSTRING("_scaleY"));
	outFields->push(HX_CSTRING("_rotation"));
	outFields->push(HX_CSTRING("_x"));
	outFields->push(HX_CSTRING("_y"));
	outFields->push(HX_CSTRING("_hasChanged"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("INC"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(Object_obj,_id),HX_CSTRING("_id")},
	{hx::fsObject /*::hxDaedalus::data::math::Matrix2D*/ ,(int)offsetof(Object_obj,_matrix),HX_CSTRING("_matrix")},
	{hx::fsObject /*Array< Float >*/ ,(int)offsetof(Object_obj,_coordinates),HX_CSTRING("_coordinates")},
	{hx::fsObject /*::hxDaedalus::data::ConstraintShape*/ ,(int)offsetof(Object_obj,_constraintShape),HX_CSTRING("_constraintShape")},
	{hx::fsFloat,(int)offsetof(Object_obj,_pivotX),HX_CSTRING("_pivotX")},
	{hx::fsFloat,(int)offsetof(Object_obj,_pivotY),HX_CSTRING("_pivotY")},
	{hx::fsFloat,(int)offsetof(Object_obj,_scaleX),HX_CSTRING("_scaleX")},
	{hx::fsFloat,(int)offsetof(Object_obj,_scaleY),HX_CSTRING("_scaleY")},
	{hx::fsFloat,(int)offsetof(Object_obj,_rotation),HX_CSTRING("_rotation")},
	{hx::fsFloat,(int)offsetof(Object_obj,_x),HX_CSTRING("_x")},
	{hx::fsFloat,(int)offsetof(Object_obj,_y),HX_CSTRING("_y")},
	{hx::fsBool,(int)offsetof(Object_obj,_hasChanged),HX_CSTRING("_hasChanged")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("_id"),
	HX_CSTRING("_matrix"),
	HX_CSTRING("_coordinates"),
	HX_CSTRING("_constraintShape"),
	HX_CSTRING("_pivotX"),
	HX_CSTRING("_pivotY"),
	HX_CSTRING("_scaleX"),
	HX_CSTRING("_scaleY"),
	HX_CSTRING("_rotation"),
	HX_CSTRING("_x"),
	HX_CSTRING("_y"),
	HX_CSTRING("_hasChanged"),
	HX_CSTRING("get_id"),
	HX_CSTRING("dispose"),
	HX_CSTRING("updateValuesFromMatrix"),
	HX_CSTRING("updateMatrixFromValues"),
	HX_CSTRING("get_pivotX"),
	HX_CSTRING("set_pivotX"),
	HX_CSTRING("get_pivotY"),
	HX_CSTRING("set_pivotY"),
	HX_CSTRING("get_scaleX"),
	HX_CSTRING("set_scaleX"),
	HX_CSTRING("get_scaleY"),
	HX_CSTRING("set_scaleY"),
	HX_CSTRING("get_rotation"),
	HX_CSTRING("set_rotation"),
	HX_CSTRING("get_x"),
	HX_CSTRING("set_x"),
	HX_CSTRING("get_y"),
	HX_CSTRING("set_y"),
	HX_CSTRING("get_matrix"),
	HX_CSTRING("set_matrix"),
	HX_CSTRING("get_coordinates"),
	HX_CSTRING("set_coordinates"),
	HX_CSTRING("get_constraintShape"),
	HX_CSTRING("set_constraintShape"),
	HX_CSTRING("get_hasChanged"),
	HX_CSTRING("set_hasChanged"),
	HX_CSTRING("get_edges"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Object_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Object_obj::INC,"INC");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Object_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Object_obj::INC,"INC");
};

#endif

Class Object_obj::__mClass;

void Object_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDaedalus.data.Object"), hx::TCanCast< Object_obj> ,sStaticFields,sMemberFields,
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

void Object_obj::__boot()
{
	INC= (int)0;
}

} // end namespace hxDaedalus
} // end namespace data
