#include <hxcpp.h>

#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_hxDaedalus_graphics_Converter
#include <hxDaedalus/graphics/Converter.h>
#endif
namespace hxDaedalus{
namespace graphics{

Void Converter_obj::__construct()
{
	return null();
}

//Converter_obj::~Converter_obj() { }

Dynamic Converter_obj::__CreateEmpty() { return  new Converter_obj; }
hx::ObjectPtr< Converter_obj > Converter_obj::__new()
{  hx::ObjectPtr< Converter_obj > result = new Converter_obj();
	result->__construct();
	return result;}

Dynamic Converter_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Converter_obj > result = new Converter_obj();
	result->__construct();
	return result;}

Void Converter_obj::ARGB2RGBA( ::haxe::io::Bytes inBytesARGB,::haxe::io::Bytes outBytesRGBA){
{
		HX_STACK_FRAME("hxDaedalus.graphics.Converter","ARGB2RGBA",0x2e520cc2,"hxDaedalus.graphics.Converter.ARGB2RGBA","hxDaedalus/graphics/Pixels.hx",237,0x4a911ac7)
		HX_STACK_ARG(inBytesARGB,"inBytesARGB")
		HX_STACK_ARG(outBytesRGBA,"outBytesRGBA")
		HX_STACK_LINE(238)
		bool convertInPlace = (outBytesRGBA == null());		HX_STACK_VAR(convertInPlace,"convertInPlace");
		HX_STACK_LINE(240)
		if ((!(convertInPlace))){
			HX_STACK_LINE(241)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(241)
			int _g = inBytesARGB->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(241)
			while((true)){
				HX_STACK_LINE(241)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(241)
					break;
				}
				HX_STACK_LINE(241)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(242)
				int pos;		HX_STACK_VAR(pos,"pos");
				HX_STACK_LINE(242)
				if (((hx::Mod(i,(int)4) != (int)0))){
					HX_STACK_LINE(242)
					pos = (i - (int)1);
				}
				else{
					HX_STACK_LINE(242)
					pos = (i + (int)3);
				}
				HX_STACK_LINE(243)
				outBytesRGBA->b[pos] = inBytesARGB->b->__get(i);
			}
		}
		else{
			HX_STACK_LINE(246)
			outBytesRGBA = inBytesARGB;
			HX_STACK_LINE(248)
			{
				HX_STACK_LINE(248)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(248)
				int _g = (int(inBytesARGB->length) >> int((int)2));		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(248)
				while((true)){
					HX_STACK_LINE(248)
					if ((!(((_g1 < _g))))){
						HX_STACK_LINE(248)
						break;
					}
					HX_STACK_LINE(248)
					int i = (_g1)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(249)
					int pos = (int(i) << int((int)2));		HX_STACK_VAR(pos,"pos");
					HX_STACK_LINE(250)
					int a = inBytesARGB->b->__get(pos);		HX_STACK_VAR(a,"a");
					HX_STACK_LINE(251)
					int r = inBytesARGB->b->__get((pos + (int)1));		HX_STACK_VAR(r,"r");
					HX_STACK_LINE(252)
					int g = inBytesARGB->b->__get((pos + (int)2));		HX_STACK_VAR(g,"g");
					HX_STACK_LINE(253)
					int b = inBytesARGB->b->__get((pos + (int)3));		HX_STACK_VAR(b,"b");
					HX_STACK_LINE(255)
					outBytesRGBA->b[(pos + (int)3)] = a;
					HX_STACK_LINE(256)
					outBytesRGBA->b[pos] = r;
					HX_STACK_LINE(257)
					outBytesRGBA->b[(pos + (int)1)] = g;
					HX_STACK_LINE(258)
					outBytesRGBA->b[(pos + (int)2)] = b;
				}
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Converter_obj,ARGB2RGBA,(void))

Void Converter_obj::RGBA2ARGB( ::haxe::io::Bytes inBytesRGBA,::haxe::io::Bytes outBytesARGB){
{
		HX_STACK_FRAME("hxDaedalus.graphics.Converter","RGBA2ARGB",0x79b42cf2,"hxDaedalus.graphics.Converter.RGBA2ARGB","hxDaedalus/graphics/Pixels.hx",264,0x4a911ac7)
		HX_STACK_ARG(inBytesRGBA,"inBytesRGBA")
		HX_STACK_ARG(outBytesARGB,"outBytesARGB")
		HX_STACK_LINE(265)
		bool convertInPlace = (outBytesARGB == null());		HX_STACK_VAR(convertInPlace,"convertInPlace");
		HX_STACK_LINE(267)
		if ((!(convertInPlace))){
			HX_STACK_LINE(268)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(268)
			int _g = inBytesRGBA->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(268)
			while((true)){
				HX_STACK_LINE(268)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(268)
					break;
				}
				HX_STACK_LINE(268)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(269)
				int pos;		HX_STACK_VAR(pos,"pos");
				HX_STACK_LINE(269)
				if (((hx::Mod(i,(int)4) <= (int)3))){
					HX_STACK_LINE(269)
					pos = (i + (int)1);
				}
				else{
					HX_STACK_LINE(269)
					pos = (i - (int)3);
				}
				HX_STACK_LINE(270)
				outBytesARGB->b[pos] = inBytesRGBA->b->__get(i);
			}
		}
		else{
			HX_STACK_LINE(273)
			outBytesARGB = inBytesRGBA;
			HX_STACK_LINE(275)
			{
				HX_STACK_LINE(275)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(275)
				int _g = (int(inBytesRGBA->length) >> int((int)2));		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(275)
				while((true)){
					HX_STACK_LINE(275)
					if ((!(((_g1 < _g))))){
						HX_STACK_LINE(275)
						break;
					}
					HX_STACK_LINE(275)
					int i = (_g1)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(276)
					int pos = (int(i) << int((int)2));		HX_STACK_VAR(pos,"pos");
					HX_STACK_LINE(277)
					int a = inBytesRGBA->b->__get((pos + (int)3));		HX_STACK_VAR(a,"a");
					HX_STACK_LINE(278)
					int r = inBytesRGBA->b->__get(pos);		HX_STACK_VAR(r,"r");
					HX_STACK_LINE(279)
					int g = inBytesRGBA->b->__get((pos + (int)1));		HX_STACK_VAR(g,"g");
					HX_STACK_LINE(280)
					int b = inBytesRGBA->b->__get((pos + (int)2));		HX_STACK_VAR(b,"b");
					HX_STACK_LINE(282)
					outBytesARGB->b[pos] = a;
					HX_STACK_LINE(283)
					outBytesARGB->b[(pos + (int)1)] = r;
					HX_STACK_LINE(284)
					outBytesARGB->b[(pos + (int)2)] = g;
					HX_STACK_LINE(285)
					outBytesARGB->b[(pos + (int)3)] = b;
				}
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Converter_obj,RGBA2ARGB,(void))


Converter_obj::Converter_obj()
{
}

Dynamic Converter_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"ARGB2RGBA") ) { return ARGB2RGBA_dyn(); }
		if (HX_FIELD_EQ(inName,"RGBA2ARGB") ) { return RGBA2ARGB_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Converter_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void Converter_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("ARGB2RGBA"),
	HX_CSTRING("RGBA2ARGB"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Converter_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Converter_obj::__mClass,"__mClass");
};

#endif

Class Converter_obj::__mClass;

void Converter_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDaedalus.graphics.Converter"), hx::TCanCast< Converter_obj> ,sStaticFields,sMemberFields,
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

void Converter_obj::__boot()
{
}

} // end namespace hxDaedalus
} // end namespace graphics
