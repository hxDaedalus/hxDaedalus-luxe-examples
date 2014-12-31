#include <hxcpp.h>

#ifndef INCLUDED_hxDaedalus_data_Edge
#include <hxDaedalus/data/Edge.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_Face
#include <hxDaedalus/data/Face.h>
#endif
namespace hxDaedalus{
namespace data{

Void Face_obj::__construct()
{
HX_STACK_FRAME("hxDaedalus.data.Face","new",0x2012d71a,"hxDaedalus.data.Face.new","hxDaedalus/data/Face.hx",4,0xc1acf936)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(17)
	this->colorDebug = (int)-1;
	HX_STACK_LINE(20)
	this->_id = ::hxDaedalus::data::Face_obj::INC;
	HX_STACK_LINE(21)
	(::hxDaedalus::data::Face_obj::INC)++;
}
;
	return null();
}

//Face_obj::~Face_obj() { }

Dynamic Face_obj::__CreateEmpty() { return  new Face_obj; }
hx::ObjectPtr< Face_obj > Face_obj::__new()
{  hx::ObjectPtr< Face_obj > result = new Face_obj();
	result->__construct();
	return result;}

Dynamic Face_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Face_obj > result = new Face_obj();
	result->__construct();
	return result;}

int Face_obj::get_id( ){
	HX_STACK_FRAME("hxDaedalus.data.Face","get_id",0x170a5caa,"hxDaedalus.data.Face.get_id","hxDaedalus/data/Face.hx",25,0xc1acf936)
	HX_STACK_THIS(this)
	HX_STACK_LINE(25)
	return this->_id;
}


HX_DEFINE_DYNAMIC_FUNC0(Face_obj,get_id,return )

bool Face_obj::get_isReal( ){
	HX_STACK_FRAME("hxDaedalus.data.Face","get_isReal",0xfd0a24b7,"hxDaedalus.data.Face.get_isReal","hxDaedalus/data/Face.hx",29,0xc1acf936)
	HX_STACK_THIS(this)
	HX_STACK_LINE(29)
	return this->_isReal;
}


HX_DEFINE_DYNAMIC_FUNC0(Face_obj,get_isReal,return )

Void Face_obj::set_datas( ::hxDaedalus::data::Edge edge){
{
		HX_STACK_FRAME("hxDaedalus.data.Face","set_datas",0xabe225a6,"hxDaedalus.data.Face.set_datas","hxDaedalus/data/Face.hx",32,0xc1acf936)
		HX_STACK_THIS(this)
		HX_STACK_ARG(edge,"edge")
		HX_STACK_LINE(33)
		this->_isReal = true;
		HX_STACK_LINE(34)
		this->_edge = edge;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Face_obj,set_datas,(void))

Void Face_obj::setDatas( ::hxDaedalus::data::Edge edge,hx::Null< bool >  __o_isReal){
bool isReal = __o_isReal.Default(true);
	HX_STACK_FRAME("hxDaedalus.data.Face","setDatas",0xd128cf0d,"hxDaedalus.data.Face.setDatas","hxDaedalus/data/Face.hx",38,0xc1acf936)
	HX_STACK_THIS(this)
	HX_STACK_ARG(edge,"edge")
	HX_STACK_ARG(isReal,"isReal")
{
		HX_STACK_LINE(39)
		this->_isReal = isReal;
		HX_STACK_LINE(40)
		this->_edge = edge;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Face_obj,setDatas,(void))

Void Face_obj::dispose( ){
{
		HX_STACK_FRAME("hxDaedalus.data.Face","dispose",0xa68e6c59,"hxDaedalus.data.Face.dispose","hxDaedalus/data/Face.hx",44,0xc1acf936)
		HX_STACK_THIS(this)
		HX_STACK_LINE(44)
		this->_edge = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Face_obj,dispose,(void))

::hxDaedalus::data::Edge Face_obj::get_edge( ){
	HX_STACK_FRAME("hxDaedalus.data.Face","get_edge",0xb135dacc,"hxDaedalus.data.Face.get_edge","hxDaedalus/data/Face.hx",48,0xc1acf936)
	HX_STACK_THIS(this)
	HX_STACK_LINE(48)
	return this->_edge;
}


HX_DEFINE_DYNAMIC_FUNC0(Face_obj,get_edge,return )

int Face_obj::INC;


Face_obj::Face_obj()
{
}

void Face_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Face);
	HX_MARK_MEMBER_NAME(_id,"_id");
	HX_MARK_MEMBER_NAME(_isReal,"_isReal");
	HX_MARK_MEMBER_NAME(_edge,"_edge");
	HX_MARK_MEMBER_NAME(colorDebug,"colorDebug");
	HX_MARK_END_CLASS();
}

void Face_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_id,"_id");
	HX_VISIT_MEMBER_NAME(_isReal,"_isReal");
	HX_VISIT_MEMBER_NAME(_edge,"_edge");
	HX_VISIT_MEMBER_NAME(colorDebug,"colorDebug");
}

Dynamic Face_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { return get_id(); }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"INC") ) { return INC; }
		if (HX_FIELD_EQ(inName,"_id") ) { return _id; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"edge") ) { return get_edge(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_edge") ) { return _edge; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"isReal") ) { return get_isReal(); }
		if (HX_FIELD_EQ(inName,"get_id") ) { return get_id_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_isReal") ) { return _isReal; }
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"setDatas") ) { return setDatas_dyn(); }
		if (HX_FIELD_EQ(inName,"get_edge") ) { return get_edge_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"set_datas") ) { return set_datas_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"colorDebug") ) { return colorDebug; }
		if (HX_FIELD_EQ(inName,"get_isReal") ) { return get_isReal_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Face_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"INC") ) { INC=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_id") ) { _id=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_edge") ) { _edge=inValue.Cast< ::hxDaedalus::data::Edge >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_isReal") ) { _isReal=inValue.Cast< bool >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"colorDebug") ) { colorDebug=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Face_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("id"));
	outFields->push(HX_CSTRING("isReal"));
	outFields->push(HX_CSTRING("edge"));
	outFields->push(HX_CSTRING("_id"));
	outFields->push(HX_CSTRING("_isReal"));
	outFields->push(HX_CSTRING("_edge"));
	outFields->push(HX_CSTRING("colorDebug"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("INC"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(Face_obj,_id),HX_CSTRING("_id")},
	{hx::fsBool,(int)offsetof(Face_obj,_isReal),HX_CSTRING("_isReal")},
	{hx::fsObject /*::hxDaedalus::data::Edge*/ ,(int)offsetof(Face_obj,_edge),HX_CSTRING("_edge")},
	{hx::fsInt,(int)offsetof(Face_obj,colorDebug),HX_CSTRING("colorDebug")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("_id"),
	HX_CSTRING("_isReal"),
	HX_CSTRING("_edge"),
	HX_CSTRING("colorDebug"),
	HX_CSTRING("get_id"),
	HX_CSTRING("get_isReal"),
	HX_CSTRING("set_datas"),
	HX_CSTRING("setDatas"),
	HX_CSTRING("dispose"),
	HX_CSTRING("get_edge"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Face_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Face_obj::INC,"INC");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Face_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Face_obj::INC,"INC");
};

#endif

Class Face_obj::__mClass;

void Face_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDaedalus.data.Face"), hx::TCanCast< Face_obj> ,sStaticFields,sMemberFields,
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

void Face_obj::__boot()
{
	INC= (int)0;
}

} // end namespace hxDaedalus
} // end namespace data
