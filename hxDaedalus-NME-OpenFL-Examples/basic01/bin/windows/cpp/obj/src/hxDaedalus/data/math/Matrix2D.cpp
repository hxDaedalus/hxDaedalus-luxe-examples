#include <hxcpp.h>

#ifndef INCLUDED_hxDaedalus_data_math_Matrix2D
#include <hxDaedalus/data/math/Matrix2D.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_math_Point2D
#include <hxDaedalus/data/math/Point2D.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace hxDaedalus{
namespace data{
namespace math{

Void Matrix2D_obj::__construct(hx::Null< Float >  __o_a_,hx::Null< Float >  __o_b_,hx::Null< Float >  __o_c_,hx::Null< Float >  __o_d_,hx::Null< Float >  __o_e_,hx::Null< Float >  __o_f_)
{
HX_STACK_FRAME("hxDaedalus.data.math.Matrix2D","new",0xe8db2d00,"hxDaedalus.data.math.Matrix2D.new","hxDaedalus/data/math/Matrix2D.hx",22,0x2feefc6f)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_a_,"a_")
HX_STACK_ARG(__o_b_,"b_")
HX_STACK_ARG(__o_c_,"c_")
HX_STACK_ARG(__o_d_,"d_")
HX_STACK_ARG(__o_e_,"e_")
HX_STACK_ARG(__o_f_,"f_")
Float a_ = __o_a_.Default(1);
Float b_ = __o_b_.Default(0);
Float c_ = __o_c_.Default(0);
Float d_ = __o_d_.Default(1);
Float e_ = __o_e_.Default(0);
Float f_ = __o_f_.Default(0);
{
	HX_STACK_LINE(23)
	this->a = a_;
	HX_STACK_LINE(24)
	this->b = b_;
	HX_STACK_LINE(25)
	this->c = c_;
	HX_STACK_LINE(26)
	this->d = d_;
	HX_STACK_LINE(27)
	this->e = e_;
	HX_STACK_LINE(28)
	this->f = f_;
}
;
	return null();
}

//Matrix2D_obj::~Matrix2D_obj() { }

Dynamic Matrix2D_obj::__CreateEmpty() { return  new Matrix2D_obj; }
hx::ObjectPtr< Matrix2D_obj > Matrix2D_obj::__new(hx::Null< Float >  __o_a_,hx::Null< Float >  __o_b_,hx::Null< Float >  __o_c_,hx::Null< Float >  __o_d_,hx::Null< Float >  __o_e_,hx::Null< Float >  __o_f_)
{  hx::ObjectPtr< Matrix2D_obj > result = new Matrix2D_obj();
	result->__construct(__o_a_,__o_b_,__o_c_,__o_d_,__o_e_,__o_f_);
	return result;}

Dynamic Matrix2D_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Matrix2D_obj > result = new Matrix2D_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5]);
	return result;}

Void Matrix2D_obj::identity( ){
{
		HX_STACK_FRAME("hxDaedalus.data.math.Matrix2D","identity",0x5594249e,"hxDaedalus.data.math.Matrix2D.identity","hxDaedalus/data/math/Matrix2D.hx",31,0x2feefc6f)
		HX_STACK_THIS(this)
		HX_STACK_LINE(38)
		this->a = (int)1;
		HX_STACK_LINE(39)
		this->b = (int)0;
		HX_STACK_LINE(40)
		this->c = (int)0;
		HX_STACK_LINE(41)
		this->d = (int)1;
		HX_STACK_LINE(42)
		this->e = (int)0;
		HX_STACK_LINE(43)
		this->f = (int)0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Matrix2D_obj,identity,(void))

Void Matrix2D_obj::translate( Float tx,Float ty){
{
		HX_STACK_FRAME("hxDaedalus.data.math.Matrix2D","translate",0x855e6bee,"hxDaedalus.data.math.Matrix2D.translate","hxDaedalus/data/math/Matrix2D.hx",46,0x2feefc6f)
		HX_STACK_THIS(this)
		HX_STACK_ARG(tx,"tx")
		HX_STACK_ARG(ty,"ty")
		HX_STACK_LINE(53)
		this->e = (this->e + tx);
		HX_STACK_LINE(54)
		this->f = (this->f + ty);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Matrix2D_obj,translate,(void))

Void Matrix2D_obj::scale( Float sx,Float sy){
{
		HX_STACK_FRAME("hxDaedalus.data.math.Matrix2D","scale",0x175e932a,"hxDaedalus.data.math.Matrix2D.scale","hxDaedalus/data/math/Matrix2D.hx",57,0x2feefc6f)
		HX_STACK_THIS(this)
		HX_STACK_ARG(sx,"sx")
		HX_STACK_ARG(sy,"sy")
		HX_STACK_LINE(63)
		this->a = (this->a * sx);
		HX_STACK_LINE(64)
		this->b = (this->b * sy);
		HX_STACK_LINE(65)
		this->c = (this->c * sx);
		HX_STACK_LINE(66)
		this->d = (this->d * sy);
		HX_STACK_LINE(67)
		this->e = (this->e * sx);
		HX_STACK_LINE(68)
		this->f = (this->f * sy);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Matrix2D_obj,scale,(void))

Void Matrix2D_obj::rotate( Float rad){
{
		HX_STACK_FRAME("hxDaedalus.data.math.Matrix2D","rotate",0xea5c8dbb,"hxDaedalus.data.math.Matrix2D.rotate","hxDaedalus/data/math/Matrix2D.hx",71,0x2feefc6f)
		HX_STACK_THIS(this)
		HX_STACK_ARG(rad,"rad")
		HX_STACK_LINE(81)
		Float cos = ::Math_obj::cos(rad);		HX_STACK_VAR(cos,"cos");
		HX_STACK_LINE(82)
		Float sin = ::Math_obj::sin(rad);		HX_STACK_VAR(sin,"sin");
		HX_STACK_LINE(83)
		Float a_ = ((this->a * cos) + (this->b * -(sin)));		HX_STACK_VAR(a_,"a_");
		HX_STACK_LINE(84)
		Float b_ = ((this->a * sin) + (this->b * cos));		HX_STACK_VAR(b_,"b_");
		HX_STACK_LINE(85)
		Float c_ = ((this->c * cos) + (this->d * -(sin)));		HX_STACK_VAR(c_,"c_");
		HX_STACK_LINE(86)
		Float d_ = ((this->c * sin) + (this->d * cos));		HX_STACK_VAR(d_,"d_");
		HX_STACK_LINE(87)
		Float e_ = ((this->e * cos) + (this->f * -(sin)));		HX_STACK_VAR(e_,"e_");
		HX_STACK_LINE(88)
		Float f_ = ((this->e * sin) + (this->f * cos));		HX_STACK_VAR(f_,"f_");
		HX_STACK_LINE(89)
		this->a = a_;
		HX_STACK_LINE(90)
		this->b = b_;
		HX_STACK_LINE(91)
		this->c = c_;
		HX_STACK_LINE(92)
		this->d = d_;
		HX_STACK_LINE(93)
		this->e = e_;
		HX_STACK_LINE(94)
		this->f = f_;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Matrix2D_obj,rotate,(void))

::hxDaedalus::data::math::Matrix2D Matrix2D_obj::clone( ){
	HX_STACK_FRAME("hxDaedalus.data.math.Matrix2D","clone",0xe6f2d7fd,"hxDaedalus.data.math.Matrix2D.clone","hxDaedalus/data/math/Matrix2D.hx",98,0x2feefc6f)
	HX_STACK_THIS(this)
	HX_STACK_LINE(98)
	return ::hxDaedalus::data::math::Matrix2D_obj::__new(this->a,this->b,this->c,this->d,this->e,this->f);
}


HX_DEFINE_DYNAMIC_FUNC0(Matrix2D_obj,clone,return )

Void Matrix2D_obj::tranform( ::hxDaedalus::data::math::Point2D point){
{
		HX_STACK_FRAME("hxDaedalus.data.math.Matrix2D","tranform",0x6e41a80f,"hxDaedalus.data.math.Matrix2D.tranform","hxDaedalus/data/math/Matrix2D.hx",101,0x2feefc6f)
		HX_STACK_THIS(this)
		HX_STACK_ARG(point,"point")
		HX_STACK_LINE(108)
		Float x = (((this->a * point->x) + (this->c * point->y)) + this->e);		HX_STACK_VAR(x,"x");
		HX_STACK_LINE(109)
		Float y = (((this->b * point->x) + (this->d * point->y)) + this->f);		HX_STACK_VAR(y,"y");
		HX_STACK_LINE(110)
		point->x = x;
		HX_STACK_LINE(111)
		point->y = y;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Matrix2D_obj,tranform,(void))

Float Matrix2D_obj::transformX( Float x,Float y){
	HX_STACK_FRAME("hxDaedalus.data.math.Matrix2D","transformX",0xc21808cc,"hxDaedalus.data.math.Matrix2D.transformX","hxDaedalus/data/math/Matrix2D.hx",115,0x2feefc6f)
	HX_STACK_THIS(this)
	HX_STACK_ARG(x,"x")
	HX_STACK_ARG(y,"y")
	HX_STACK_LINE(115)
	return (((this->a * x) + (this->c * y)) + this->e);
}


HX_DEFINE_DYNAMIC_FUNC2(Matrix2D_obj,transformX,return )

Float Matrix2D_obj::transformY( Float x,Float y){
	HX_STACK_FRAME("hxDaedalus.data.math.Matrix2D","transformY",0xc21808cd,"hxDaedalus.data.math.Matrix2D.transformY","hxDaedalus/data/math/Matrix2D.hx",119,0x2feefc6f)
	HX_STACK_THIS(this)
	HX_STACK_ARG(x,"x")
	HX_STACK_ARG(y,"y")
	HX_STACK_LINE(119)
	return (((this->b * x) + (this->d * y)) + this->f);
}


HX_DEFINE_DYNAMIC_FUNC2(Matrix2D_obj,transformY,return )

Void Matrix2D_obj::concat( ::hxDaedalus::data::math::Matrix2D matrix){
{
		HX_STACK_FRAME("hxDaedalus.data.math.Matrix2D","concat",0xe70c5074,"hxDaedalus.data.math.Matrix2D.concat","hxDaedalus/data/math/Matrix2D.hx",122,0x2feefc6f)
		HX_STACK_THIS(this)
		HX_STACK_ARG(matrix,"matrix")
		HX_STACK_LINE(123)
		Float a_ = ((this->a * matrix->a) + (this->b * matrix->c));		HX_STACK_VAR(a_,"a_");
		HX_STACK_LINE(124)
		Float b_ = ((this->a * matrix->b) + (this->b * matrix->d));		HX_STACK_VAR(b_,"b_");
		HX_STACK_LINE(125)
		Float c_ = ((this->c * matrix->a) + (this->d * matrix->c));		HX_STACK_VAR(c_,"c_");
		HX_STACK_LINE(126)
		Float d_ = ((this->c * matrix->b) + (this->d * matrix->d));		HX_STACK_VAR(d_,"d_");
		HX_STACK_LINE(127)
		Float e_ = (((this->e * matrix->a) + (this->f * matrix->c)) + matrix->e);		HX_STACK_VAR(e_,"e_");
		HX_STACK_LINE(128)
		Float f_ = (((this->e * matrix->b) + (this->f * matrix->d)) + matrix->f);		HX_STACK_VAR(f_,"f_");
		HX_STACK_LINE(129)
		this->a = a_;
		HX_STACK_LINE(130)
		this->b = b_;
		HX_STACK_LINE(131)
		this->c = c_;
		HX_STACK_LINE(132)
		this->d = d_;
		HX_STACK_LINE(133)
		this->e = e_;
		HX_STACK_LINE(134)
		this->f = f_;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Matrix2D_obj,concat,(void))


Matrix2D_obj::Matrix2D_obj()
{
}

Dynamic Matrix2D_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"a") ) { return a; }
		if (HX_FIELD_EQ(inName,"b") ) { return b; }
		if (HX_FIELD_EQ(inName,"c") ) { return c; }
		if (HX_FIELD_EQ(inName,"d") ) { return d; }
		if (HX_FIELD_EQ(inName,"e") ) { return e; }
		if (HX_FIELD_EQ(inName,"f") ) { return f; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"scale") ) { return scale_dyn(); }
		if (HX_FIELD_EQ(inName,"clone") ) { return clone_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"rotate") ) { return rotate_dyn(); }
		if (HX_FIELD_EQ(inName,"concat") ) { return concat_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"identity") ) { return identity_dyn(); }
		if (HX_FIELD_EQ(inName,"tranform") ) { return tranform_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"translate") ) { return translate_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"transformX") ) { return transformX_dyn(); }
		if (HX_FIELD_EQ(inName,"transformY") ) { return transformY_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Matrix2D_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"a") ) { a=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"b") ) { b=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"c") ) { c=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"d") ) { d=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"e") ) { e=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"f") ) { f=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Matrix2D_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("a"));
	outFields->push(HX_CSTRING("b"));
	outFields->push(HX_CSTRING("c"));
	outFields->push(HX_CSTRING("d"));
	outFields->push(HX_CSTRING("e"));
	outFields->push(HX_CSTRING("f"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsFloat,(int)offsetof(Matrix2D_obj,a),HX_CSTRING("a")},
	{hx::fsFloat,(int)offsetof(Matrix2D_obj,b),HX_CSTRING("b")},
	{hx::fsFloat,(int)offsetof(Matrix2D_obj,c),HX_CSTRING("c")},
	{hx::fsFloat,(int)offsetof(Matrix2D_obj,d),HX_CSTRING("d")},
	{hx::fsFloat,(int)offsetof(Matrix2D_obj,e),HX_CSTRING("e")},
	{hx::fsFloat,(int)offsetof(Matrix2D_obj,f),HX_CSTRING("f")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("a"),
	HX_CSTRING("b"),
	HX_CSTRING("c"),
	HX_CSTRING("d"),
	HX_CSTRING("e"),
	HX_CSTRING("f"),
	HX_CSTRING("identity"),
	HX_CSTRING("translate"),
	HX_CSTRING("scale"),
	HX_CSTRING("rotate"),
	HX_CSTRING("clone"),
	HX_CSTRING("tranform"),
	HX_CSTRING("transformX"),
	HX_CSTRING("transformY"),
	HX_CSTRING("concat"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Matrix2D_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Matrix2D_obj::__mClass,"__mClass");
};

#endif

Class Matrix2D_obj::__mClass;

void Matrix2D_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDaedalus.data.math.Matrix2D"), hx::TCanCast< Matrix2D_obj> ,sStaticFields,sMemberFields,
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

void Matrix2D_obj::__boot()
{
}

} // end namespace hxDaedalus
} // end namespace data
} // end namespace math
