#include <hxcpp.h>

#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_hxDaedalus_graphics__Pixels_PixelsData
#include <hxDaedalus/graphics/_Pixels/PixelsData.h>
#endif
#ifndef INCLUDED_hxDaedalus_graphics__Pixels_Pixels_Impl_
#include <hxDaedalus/graphics/_Pixels/Pixels_Impl_.h>
#endif
#ifndef INCLUDED_openfl__v2_display_BitmapData
#include <openfl/_v2/display/BitmapData.h>
#endif
#ifndef INCLUDED_openfl__v2_display_IBitmapDrawable
#include <openfl/_v2/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_openfl__v2_geom_Rectangle
#include <openfl/_v2/geom/Rectangle.h>
#endif
#ifndef INCLUDED_openfl__v2_utils_ByteArray
#include <openfl/_v2/utils/ByteArray.h>
#endif
#ifndef INCLUDED_openfl__v2_utils_IDataInput
#include <openfl/_v2/utils/IDataInput.h>
#endif
#ifndef INCLUDED_openfl__v2_utils_IDataOutput
#include <openfl/_v2/utils/IDataOutput.h>
#endif
#ifndef INCLUDED_openfl__v2_utils_IMemoryRange
#include <openfl/_v2/utils/IMemoryRange.h>
#endif
namespace hxDaedalus{
namespace graphics{
namespace _Pixels{

Void Pixels_Impl__obj::__construct()
{
	return null();
}

//Pixels_Impl__obj::~Pixels_Impl__obj() { }

Dynamic Pixels_Impl__obj::__CreateEmpty() { return  new Pixels_Impl__obj; }
hx::ObjectPtr< Pixels_Impl__obj > Pixels_Impl__obj::__new()
{  hx::ObjectPtr< Pixels_Impl__obj > result = new Pixels_Impl__obj();
	result->__construct();
	return result;}

Dynamic Pixels_Impl__obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Pixels_Impl__obj > result = new Pixels_Impl__obj();
	result->__construct();
	return result;}

::hxDaedalus::graphics::_Pixels::PixelsData Pixels_Impl__obj::_new( int width,int height,hx::Null< bool >  __o_alloc){
bool alloc = __o_alloc.Default(true);
	HX_STACK_FRAME("hxDaedalus.graphics._Pixels.Pixels_Impl_","_new",0xd8dab2d6,"hxDaedalus.graphics._Pixels.Pixels_Impl_._new","hxDaedalus/graphics/Pixels.hx",22,0x4a911ac7)
	HX_STACK_ARG(width,"width")
	HX_STACK_ARG(height,"height")
	HX_STACK_ARG(alloc,"alloc")
{
		HX_STACK_LINE(22)
		return ::hxDaedalus::graphics::_Pixels::PixelsData_obj::__new(width,height,alloc);
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Pixels_Impl__obj,_new,return )

int Pixels_Impl__obj::getByte( ::hxDaedalus::graphics::_Pixels::PixelsData this1,int i){
	HX_STACK_FRAME("hxDaedalus.graphics._Pixels.Pixels_Impl_","getByte",0x14a04869,"hxDaedalus.graphics._Pixels.Pixels_Impl_.getByte","hxDaedalus/graphics/Pixels.hx",26,0x4a911ac7)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_ARG(i,"i")
	HX_STACK_LINE(26)
	return this1->bytes->b->__get(i);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Pixels_Impl__obj,getByte,return )

int Pixels_Impl__obj::getPixel( ::hxDaedalus::graphics::_Pixels::PixelsData this1,int x,int y){
	HX_STACK_FRAME("hxDaedalus.graphics._Pixels.Pixels_Impl_","getPixel",0xfcaad205,"hxDaedalus.graphics._Pixels.Pixels_Impl_.getPixel","hxDaedalus/graphics/Pixels.hx",29,0x4a911ac7)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_ARG(x,"x")
	HX_STACK_ARG(y,"y")
	HX_STACK_LINE(30)
	int pos = (int(((y * this1->width) + x)) << int((int)2));		HX_STACK_VAR(pos,"pos");
	HX_STACK_LINE(31)
	int r = (int(this1->bytes->b->__get((pos + (int)1))) << int((int)16));		HX_STACK_VAR(r,"r");
	HX_STACK_LINE(32)
	int g = (int(this1->bytes->b->__get((pos + (int)2))) << int((int)8));		HX_STACK_VAR(g,"g");
	HX_STACK_LINE(33)
	int b = this1->bytes->b->__get((pos + (int)3));		HX_STACK_VAR(b,"b");
	HX_STACK_LINE(35)
	return (int((int(r) | int(g))) | int(b));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Pixels_Impl__obj,getPixel,return )

int Pixels_Impl__obj::getPixel32( ::hxDaedalus::graphics::_Pixels::PixelsData this1,int x,int y){
	HX_STACK_FRAME("hxDaedalus.graphics._Pixels.Pixels_Impl_","getPixel32",0x9a8749e4,"hxDaedalus.graphics._Pixels.Pixels_Impl_.getPixel32","hxDaedalus/graphics/Pixels.hx",38,0x4a911ac7)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_ARG(x,"x")
	HX_STACK_ARG(y,"y")
	HX_STACK_LINE(39)
	int pos = (int(((y * this1->width) + x)) << int((int)2));		HX_STACK_VAR(pos,"pos");
	HX_STACK_LINE(41)
	int a = (int(this1->bytes->b->__get(pos)) << int((int)24));		HX_STACK_VAR(a,"a");
	HX_STACK_LINE(42)
	int r = (int(this1->bytes->b->__get((pos + (int)1))) << int((int)16));		HX_STACK_VAR(r,"r");
	HX_STACK_LINE(43)
	int g = (int(this1->bytes->b->__get((pos + (int)2))) << int((int)8));		HX_STACK_VAR(g,"g");
	HX_STACK_LINE(44)
	int b = this1->bytes->b->__get((pos + (int)3));		HX_STACK_VAR(b,"b");
	HX_STACK_LINE(46)
	return (int((int((int(a) | int(r))) | int(g))) | int(b));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Pixels_Impl__obj,getPixel32,return )

Void Pixels_Impl__obj::setByte( ::hxDaedalus::graphics::_Pixels::PixelsData this1,int i,int value){
{
		HX_STACK_FRAME("hxDaedalus.graphics._Pixels.Pixels_Impl_","setByte",0x07a1d975,"hxDaedalus.graphics._Pixels.Pixels_Impl_.setByte","hxDaedalus/graphics/Pixels.hx",50,0x4a911ac7)
		HX_STACK_ARG(this1,"this1")
		HX_STACK_ARG(i,"i")
		HX_STACK_ARG(value,"value")
		HX_STACK_LINE(50)
		this1->bytes->b[i] = value;
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Pixels_Impl__obj,setByte,(void))

Void Pixels_Impl__obj::setPixel( ::hxDaedalus::graphics::_Pixels::PixelsData this1,int x,int y,int value){
{
		HX_STACK_FRAME("hxDaedalus.graphics._Pixels.Pixels_Impl_","setPixel",0xab082b79,"hxDaedalus.graphics._Pixels.Pixels_Impl_.setPixel","hxDaedalus/graphics/Pixels.hx",53,0x4a911ac7)
		HX_STACK_ARG(this1,"this1")
		HX_STACK_ARG(x,"x")
		HX_STACK_ARG(y,"y")
		HX_STACK_ARG(value,"value")
		HX_STACK_LINE(54)
		int pos = (int(((y * this1->width) + x)) << int((int)2));		HX_STACK_VAR(pos,"pos");
		HX_STACK_LINE(56)
		int r = (int((int(value) >> int((int)16))) & int((int)255));		HX_STACK_VAR(r,"r");
		HX_STACK_LINE(57)
		int g = (int((int(value) >> int((int)8))) & int((int)255));		HX_STACK_VAR(g,"g");
		HX_STACK_LINE(58)
		int b = (int(value) & int((int)255));		HX_STACK_VAR(b,"b");
		HX_STACK_LINE(60)
		this1->bytes->b[(pos + (int)1)] = r;
		HX_STACK_LINE(61)
		this1->bytes->b[(pos + (int)2)] = g;
		HX_STACK_LINE(62)
		this1->bytes->b[(pos + (int)3)] = b;
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Pixels_Impl__obj,setPixel,(void))

Void Pixels_Impl__obj::setPixel32( ::hxDaedalus::graphics::_Pixels::PixelsData this1,int x,int y,int value){
{
		HX_STACK_FRAME("hxDaedalus.graphics._Pixels.Pixels_Impl_","setPixel32",0x9e04e858,"hxDaedalus.graphics._Pixels.Pixels_Impl_.setPixel32","hxDaedalus/graphics/Pixels.hx",65,0x4a911ac7)
		HX_STACK_ARG(this1,"this1")
		HX_STACK_ARG(x,"x")
		HX_STACK_ARG(y,"y")
		HX_STACK_ARG(value,"value")
		HX_STACK_LINE(66)
		int pos = (int(((y * this1->width) + x)) << int((int)2));		HX_STACK_VAR(pos,"pos");
		HX_STACK_LINE(68)
		int a = (int((int(value) >> int((int)24))) & int((int)255));		HX_STACK_VAR(a,"a");
		HX_STACK_LINE(69)
		int r = (int((int(value) >> int((int)16))) & int((int)255));		HX_STACK_VAR(r,"r");
		HX_STACK_LINE(70)
		int g = (int((int(value) >> int((int)8))) & int((int)255));		HX_STACK_VAR(g,"g");
		HX_STACK_LINE(71)
		int b = (int(value) & int((int)255));		HX_STACK_VAR(b,"b");
		HX_STACK_LINE(73)
		this1->bytes->b[pos] = a;
		HX_STACK_LINE(74)
		this1->bytes->b[(pos + (int)1)] = r;
		HX_STACK_LINE(75)
		this1->bytes->b[(pos + (int)2)] = g;
		HX_STACK_LINE(76)
		this1->bytes->b[(pos + (int)3)] = b;
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Pixels_Impl__obj,setPixel32,(void))

::hxDaedalus::graphics::_Pixels::PixelsData Pixels_Impl__obj::fromBitmapData( ::openfl::_v2::display::BitmapData bmd){
	HX_STACK_FRAME("hxDaedalus.graphics._Pixels.Pixels_Impl_","fromBitmapData",0xaad5e978,"hxDaedalus.graphics._Pixels.Pixels_Impl_.fromBitmapData","hxDaedalus/graphics/Pixels.hx",100,0x4a911ac7)
	HX_STACK_ARG(bmd,"bmd")
	HX_STACK_LINE(118)
	::hxDaedalus::graphics::_Pixels::PixelsData pixels;		HX_STACK_VAR(pixels,"pixels");
	HX_STACK_LINE(118)
	{
		HX_STACK_LINE(118)
		int width = bmd->get_width();		HX_STACK_VAR(width,"width");
		HX_STACK_LINE(118)
		int height = bmd->get_height();		HX_STACK_VAR(height,"height");
		HX_STACK_LINE(118)
		pixels = ::hxDaedalus::graphics::_Pixels::PixelsData_obj::__new(width,height,false);
	}
	HX_STACK_LINE(119)
	::openfl::_v2::geom::Rectangle _g = bmd->get_rect();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(119)
	::openfl::_v2::utils::ByteArray ba = bmd->getPixels(_g);		HX_STACK_VAR(ba,"ba");
	HX_STACK_LINE(124)
	::haxe::io::Bytes _g1 = ::haxe::io::Bytes_obj::ofData(ba->b);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(124)
	pixels->bytes = _g1;
	HX_STACK_LINE(129)
	return pixels;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Pixels_Impl__obj,fromBitmapData,return )

::openfl::_v2::display::BitmapData Pixels_Impl__obj::toBitmapData( ::hxDaedalus::graphics::_Pixels::PixelsData this1){
	HX_STACK_FRAME("hxDaedalus.graphics._Pixels.Pixels_Impl_","toBitmapData",0x98158189,"hxDaedalus.graphics._Pixels.Pixels_Impl_.toBitmapData","hxDaedalus/graphics/Pixels.hx",132,0x4a911ac7)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_LINE(133)
	::openfl::_v2::display::BitmapData bmd = ::openfl::_v2::display::BitmapData_obj::__new(this1->width,this1->height,null(),null(),null());		HX_STACK_VAR(bmd,"bmd");
	HX_STACK_LINE(135)
	return ::hxDaedalus::graphics::_Pixels::Pixels_Impl__obj::applyTo(this1,bmd);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Pixels_Impl__obj,toBitmapData,return )

::openfl::_v2::display::BitmapData Pixels_Impl__obj::applyTo( ::hxDaedalus::graphics::_Pixels::PixelsData this1,::openfl::_v2::display::BitmapData bmd){
	HX_STACK_FRAME("hxDaedalus.graphics._Pixels.Pixels_Impl_","applyTo",0x4f350034,"hxDaedalus.graphics._Pixels.Pixels_Impl_.applyTo","hxDaedalus/graphics/Pixels.hx",138,0x4a911ac7)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_ARG(bmd,"bmd")
	HX_STACK_LINE(141)
	::openfl::_v2::geom::Rectangle _g = bmd->get_rect();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(141)
	::openfl::_v2::utils::ByteArray ba = bmd->getPixels(_g);		HX_STACK_VAR(ba,"ba");
	HX_STACK_LINE(144)
	ba->blit((int)0,this1->bytes,(int)0,this1->bytes->length);
	HX_STACK_LINE(150)
	ba->position = (int)0;
	HX_STACK_LINE(151)
	::openfl::_v2::geom::Rectangle _g1 = bmd->get_rect();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(151)
	bmd->setPixels(_g1,ba);
	HX_STACK_LINE(163)
	return bmd;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Pixels_Impl__obj,applyTo,return )


Pixels_Impl__obj::Pixels_Impl__obj()
{
}

Dynamic Pixels_Impl__obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"_new") ) { return _new_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"getByte") ) { return getByte_dyn(); }
		if (HX_FIELD_EQ(inName,"setByte") ) { return setByte_dyn(); }
		if (HX_FIELD_EQ(inName,"applyTo") ) { return applyTo_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"getPixel") ) { return getPixel_dyn(); }
		if (HX_FIELD_EQ(inName,"setPixel") ) { return setPixel_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"getPixel32") ) { return getPixel32_dyn(); }
		if (HX_FIELD_EQ(inName,"setPixel32") ) { return setPixel32_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"toBitmapData") ) { return toBitmapData_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"fromBitmapData") ) { return fromBitmapData_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Pixels_Impl__obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void Pixels_Impl__obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("_new"),
	HX_CSTRING("getByte"),
	HX_CSTRING("getPixel"),
	HX_CSTRING("getPixel32"),
	HX_CSTRING("setByte"),
	HX_CSTRING("setPixel"),
	HX_CSTRING("setPixel32"),
	HX_CSTRING("fromBitmapData"),
	HX_CSTRING("toBitmapData"),
	HX_CSTRING("applyTo"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Pixels_Impl__obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Pixels_Impl__obj::__mClass,"__mClass");
};

#endif

Class Pixels_Impl__obj::__mClass;

void Pixels_Impl__obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDaedalus.graphics._Pixels.Pixels_Impl_"), hx::TCanCast< Pixels_Impl__obj> ,sStaticFields,sMemberFields,
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

void Pixels_Impl__obj::__boot()
{
}

} // end namespace hxDaedalus
} // end namespace graphics
} // end namespace _Pixels
