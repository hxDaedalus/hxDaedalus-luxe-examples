#include <hxcpp.h>

#ifndef INCLUDED_hxDaedalus_data_Mesh
#include <hxDaedalus/data/Mesh.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_Vertex
#include <hxDaedalus/data/Vertex.h>
#endif
#ifndef INCLUDED_hxDaedalus_iterators_FromMeshToVertices
#include <hxDaedalus/iterators/FromMeshToVertices.h>
#endif
namespace hxDaedalus{
namespace iterators{

Void FromMeshToVertices_obj::__construct()
{
HX_STACK_FRAME("hxDaedalus.iterators.FromMeshToVertices","new",0x3db22b3f,"hxDaedalus.iterators.FromMeshToVertices.new","hxDaedalus/iterators/FromMeshToVertices.hx",12,0x3bd2228f)
HX_STACK_THIS(this)
{
}
;
	return null();
}

//FromMeshToVertices_obj::~FromMeshToVertices_obj() { }

Dynamic FromMeshToVertices_obj::__CreateEmpty() { return  new FromMeshToVertices_obj; }
hx::ObjectPtr< FromMeshToVertices_obj > FromMeshToVertices_obj::__new()
{  hx::ObjectPtr< FromMeshToVertices_obj > result = new FromMeshToVertices_obj();
	result->__construct();
	return result;}

Dynamic FromMeshToVertices_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FromMeshToVertices_obj > result = new FromMeshToVertices_obj();
	result->__construct();
	return result;}

::hxDaedalus::data::Mesh FromMeshToVertices_obj::set_fromMesh( ::hxDaedalus::data::Mesh value){
	HX_STACK_FRAME("hxDaedalus.iterators.FromMeshToVertices","set_fromMesh",0x461cc135,"hxDaedalus.iterators.FromMeshToVertices.set_fromMesh","hxDaedalus/iterators/FromMeshToVertices.hx",14,0x3bd2228f)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(15)
	this->_fromMesh = value;
	HX_STACK_LINE(16)
	this->_currIndex = (int)0;
	HX_STACK_LINE(17)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(FromMeshToVertices_obj,set_fromMesh,return )

::hxDaedalus::data::Vertex FromMeshToVertices_obj::next( ){
	HX_STACK_FRAME("hxDaedalus.iterators.FromMeshToVertices","next",0xbe33ad34,"hxDaedalus.iterators.FromMeshToVertices.next","hxDaedalus/iterators/FromMeshToVertices.hx",20,0x3bd2228f)
	HX_STACK_THIS(this)
	HX_STACK_LINE(21)
	while((true)){
		HX_STACK_LINE(22)
		if (((this->_currIndex < this->_fromMesh->_vertices->length))){
			HX_STACK_LINE(23)
			this->_resultVertex = this->_fromMesh->_vertices->__get(this->_currIndex).StaticCast< ::hxDaedalus::data::Vertex >();
			HX_STACK_LINE(24)
			(this->_currIndex)++;
		}
		else{
			HX_STACK_LINE(26)
			this->_resultVertex = null();
			HX_STACK_LINE(27)
			break;
		}
		HX_STACK_LINE(21)
		if ((!((!(this->_resultVertex->get_isReal()))))){
			HX_STACK_LINE(21)
			break;
		}
	}
	HX_STACK_LINE(30)
	return this->_resultVertex;
}


HX_DEFINE_DYNAMIC_FUNC0(FromMeshToVertices_obj,next,return )


FromMeshToVertices_obj::FromMeshToVertices_obj()
{
}

void FromMeshToVertices_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FromMeshToVertices);
	HX_MARK_MEMBER_NAME(_fromMesh,"_fromMesh");
	HX_MARK_MEMBER_NAME(_currIndex,"_currIndex");
	HX_MARK_MEMBER_NAME(_resultVertex,"_resultVertex");
	HX_MARK_END_CLASS();
}

void FromMeshToVertices_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_fromMesh,"_fromMesh");
	HX_VISIT_MEMBER_NAME(_currIndex,"_currIndex");
	HX_VISIT_MEMBER_NAME(_resultVertex,"_resultVertex");
}

Dynamic FromMeshToVertices_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"next") ) { return next_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_fromMesh") ) { return _fromMesh; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_currIndex") ) { return _currIndex; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"set_fromMesh") ) { return set_fromMesh_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_resultVertex") ) { return _resultVertex; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FromMeshToVertices_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"fromMesh") ) { return set_fromMesh(inValue); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_fromMesh") ) { _fromMesh=inValue.Cast< ::hxDaedalus::data::Mesh >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_currIndex") ) { _currIndex=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_resultVertex") ) { _resultVertex=inValue.Cast< ::hxDaedalus::data::Vertex >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FromMeshToVertices_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("fromMesh"));
	outFields->push(HX_CSTRING("_fromMesh"));
	outFields->push(HX_CSTRING("_currIndex"));
	outFields->push(HX_CSTRING("_resultVertex"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::hxDaedalus::data::Mesh*/ ,(int)offsetof(FromMeshToVertices_obj,_fromMesh),HX_CSTRING("_fromMesh")},
	{hx::fsInt,(int)offsetof(FromMeshToVertices_obj,_currIndex),HX_CSTRING("_currIndex")},
	{hx::fsObject /*::hxDaedalus::data::Vertex*/ ,(int)offsetof(FromMeshToVertices_obj,_resultVertex),HX_CSTRING("_resultVertex")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("_fromMesh"),
	HX_CSTRING("_currIndex"),
	HX_CSTRING("_resultVertex"),
	HX_CSTRING("set_fromMesh"),
	HX_CSTRING("next"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FromMeshToVertices_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FromMeshToVertices_obj::__mClass,"__mClass");
};

#endif

Class FromMeshToVertices_obj::__mClass;

void FromMeshToVertices_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDaedalus.iterators.FromMeshToVertices"), hx::TCanCast< FromMeshToVertices_obj> ,sStaticFields,sMemberFields,
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

void FromMeshToVertices_obj::__boot()
{
}

} // end namespace hxDaedalus
} // end namespace iterators
