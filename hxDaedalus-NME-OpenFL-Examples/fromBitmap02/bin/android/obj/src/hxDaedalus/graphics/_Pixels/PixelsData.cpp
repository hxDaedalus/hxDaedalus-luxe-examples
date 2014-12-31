#include <hxcpp.h>

#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_hxDaedalus_graphics__Pixels_PixelsData
#include <hxDaedalus/graphics/_Pixels/PixelsData.h>
#endif
namespace hxDaedalus{
namespace graphics{
namespace _Pixels{

Void PixelsData_obj::__construct(int width,int height,hx::Null< bool >  __o_alloc)
{
HX_STACK_FRAME("hxDaedalus.graphics._Pixels.PixelsData","new",0x7834daf5,"hxDaedalus.graphics._Pixels.PixelsData.new","hxDaedalus/graphics/Pixels.hx",224,0x4a911ac7)
HX_STACK_THIS(this)
HX_STACK_ARG(width,"width")
HX_STACK_ARG(height,"height")
HX_STACK_ARG(__o_alloc,"alloc")
bool alloc = __o_alloc.Default(true);
{
	HX_STACK_LINE(225)
	this->length = (width * height);
	HX_STACK_LINE(227)
	if ((alloc)){
		HX_STACK_LINE(227)
		::haxe::io::Bytes _g = ::haxe::io::Bytes_obj::alloc((int(this->length) << int((int)2)));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(227)
		this->bytes = _g;
	}
	HX_STACK_LINE(229)
	this->width = width;
	HX_STACK_LINE(230)
	this->height = height;
}
;
	return null();
}

//PixelsData_obj::~PixelsData_obj() { }

Dynamic PixelsData_obj::__CreateEmpty() { return  new PixelsData_obj; }
hx::ObjectPtr< PixelsData_obj > PixelsData_obj::__new(int width,int height,hx::Null< bool >  __o_alloc)
{  hx::ObjectPtr< PixelsData_obj > result = new PixelsData_obj();
	result->__construct(width,height,__o_alloc);
	return result;}

Dynamic PixelsData_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< PixelsData_obj > result = new PixelsData_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}


PixelsData_obj::PixelsData_obj()
{
}

void PixelsData_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(PixelsData);
	HX_MARK_MEMBER_NAME(length,"length");
	HX_MARK_MEMBER_NAME(bytes,"bytes");
	HX_MARK_MEMBER_NAME(width,"width");
	HX_MARK_MEMBER_NAME(height,"height");
	HX_MARK_END_CLASS();
}

void PixelsData_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(length,"length");
	HX_VISIT_MEMBER_NAME(bytes,"bytes");
	HX_VISIT_MEMBER_NAME(width,"width");
	HX_VISIT_MEMBER_NAME(height,"height");
}

Dynamic PixelsData_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"bytes") ) { return bytes; }
		if (HX_FIELD_EQ(inName,"width") ) { return width; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { return length; }
		if (HX_FIELD_EQ(inName,"height") ) { return height; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic PixelsData_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"bytes") ) { bytes=inValue.Cast< ::haxe::io::Bytes >(); return inValue; }
		if (HX_FIELD_EQ(inName,"width") ) { width=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { length=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"height") ) { height=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void PixelsData_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("length"));
	outFields->push(HX_CSTRING("bytes"));
	outFields->push(HX_CSTRING("width"));
	outFields->push(HX_CSTRING("height"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(PixelsData_obj,length),HX_CSTRING("length")},
	{hx::fsObject /*::haxe::io::Bytes*/ ,(int)offsetof(PixelsData_obj,bytes),HX_CSTRING("bytes")},
	{hx::fsInt,(int)offsetof(PixelsData_obj,width),HX_CSTRING("width")},
	{hx::fsInt,(int)offsetof(PixelsData_obj,height),HX_CSTRING("height")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("length"),
	HX_CSTRING("bytes"),
	HX_CSTRING("width"),
	HX_CSTRING("height"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(PixelsData_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(PixelsData_obj::__mClass,"__mClass");
};

#endif

Class PixelsData_obj::__mClass;

void PixelsData_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDaedalus.graphics._Pixels.PixelsData"), hx::TCanCast< PixelsData_obj> ,sStaticFields,sMemberFields,
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

void PixelsData_obj::__boot()
{
}

} // end namespace hxDaedalus
} // end namespace graphics
} // end namespace _Pixels
