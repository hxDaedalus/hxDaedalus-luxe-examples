#include <hxcpp.h>

#ifndef INCLUDED_hxDaedalus_ai_AStar
#include <hxDaedalus/ai/AStar.h>
#endif
#ifndef INCLUDED_hxDaedalus_ai_EntityAI
#include <hxDaedalus/ai/EntityAI.h>
#endif
#ifndef INCLUDED_hxDaedalus_ai_Funnel
#include <hxDaedalus/ai/Funnel.h>
#endif
#ifndef INCLUDED_hxDaedalus_ai_PathFinder
#include <hxDaedalus/ai/PathFinder.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_Edge
#include <hxDaedalus/data/Edge.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_Face
#include <hxDaedalus/data/Face.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_Mesh
#include <hxDaedalus/data/Mesh.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_math_Geom2D
#include <hxDaedalus/data/math/Geom2D.h>
#endif
namespace hxDaedalus{
namespace ai{

Void PathFinder_obj::__construct()
{
HX_STACK_FRAME("hxDaedalus.ai.PathFinder","new",0x6035576a,"hxDaedalus.ai.PathFinder.new","hxDaedalus/ai/PathFinder.hx",21,0x853328a6)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(22)
	::hxDaedalus::ai::AStar _g = ::hxDaedalus::ai::AStar_obj::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(22)
	this->astar = _g;
	HX_STACK_LINE(23)
	::hxDaedalus::ai::Funnel _g1 = ::hxDaedalus::ai::Funnel_obj::__new();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(23)
	this->funnel = _g1;
	HX_STACK_LINE(24)
	Array< ::Dynamic > _g2 = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(24)
	this->listFaces = _g2;
	HX_STACK_LINE(25)
	Array< ::Dynamic > _g3 = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(25)
	this->listEdges = _g3;
}
;
	return null();
}

//PathFinder_obj::~PathFinder_obj() { }

Dynamic PathFinder_obj::__CreateEmpty() { return  new PathFinder_obj; }
hx::ObjectPtr< PathFinder_obj > PathFinder_obj::__new()
{  hx::ObjectPtr< PathFinder_obj > result = new PathFinder_obj();
	result->__construct();
	return result;}

Dynamic PathFinder_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< PathFinder_obj > result = new PathFinder_obj();
	result->__construct();
	return result;}

Void PathFinder_obj::dispose( ){
{
		HX_STACK_FRAME("hxDaedalus.ai.PathFinder","dispose",0xf9ff54a9,"hxDaedalus.ai.PathFinder.dispose","hxDaedalus/ai/PathFinder.hx",28,0x853328a6)
		HX_STACK_THIS(this)
		HX_STACK_LINE(29)
		this->_mesh = null();
		HX_STACK_LINE(30)
		this->astar->dispose();
		HX_STACK_LINE(31)
		this->astar = null();
		HX_STACK_LINE(32)
		this->funnel->dispose();
		HX_STACK_LINE(33)
		this->funnel = null();
		HX_STACK_LINE(34)
		this->listEdges = null();
		HX_STACK_LINE(35)
		this->listFaces = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PathFinder_obj,dispose,(void))

::hxDaedalus::data::Mesh PathFinder_obj::get_mesh( ){
	HX_STACK_FRAME("hxDaedalus.ai.PathFinder","get_mesh",0x65daba2c,"hxDaedalus.ai.PathFinder.get_mesh","hxDaedalus/ai/PathFinder.hx",39,0x853328a6)
	HX_STACK_THIS(this)
	HX_STACK_LINE(39)
	return this->_mesh;
}


HX_DEFINE_DYNAMIC_FUNC0(PathFinder_obj,get_mesh,return )

::hxDaedalus::data::Mesh PathFinder_obj::set_mesh( ::hxDaedalus::data::Mesh value){
	HX_STACK_FRAME("hxDaedalus.ai.PathFinder","set_mesh",0x143813a0,"hxDaedalus.ai.PathFinder.set_mesh","hxDaedalus/ai/PathFinder.hx",43,0x853328a6)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(44)
	this->_mesh = value;
	HX_STACK_LINE(45)
	this->astar->set_mesh(this->_mesh);
	HX_STACK_LINE(46)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(PathFinder_obj,set_mesh,return )

Void PathFinder_obj::findPath( Float toX,Float toY,Array< Float > resultPath){
{
		HX_STACK_FRAME("hxDaedalus.ai.PathFinder","findPath",0x3aaca734,"hxDaedalus.ai.PathFinder.findPath","hxDaedalus/ai/PathFinder.hx",49,0x853328a6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(toX,"toX")
		HX_STACK_ARG(toY,"toY")
		HX_STACK_ARG(resultPath,"resultPath")
		HX_STACK_LINE(50)
		resultPath->splice((int)0,resultPath->length);
		HX_STACK_LINE(54)
		Float _g = this->entity->get_radius();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(54)
		if ((::hxDaedalus::data::math::Geom2D_obj::isCircleIntersectingAnyConstraint(toX,toY,_g,this->_mesh))){
			HX_STACK_LINE(54)
			return null();
		}
		HX_STACK_LINE(56)
		Float _g1 = this->entity->get_radius();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(56)
		this->astar->set_radius(_g1);
		HX_STACK_LINE(57)
		Float _g2 = this->entity->get_radius();		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(57)
		this->funnel->set_radius(_g2);
		HX_STACK_LINE(59)
		this->listFaces->splice((int)0,this->listFaces->length);
		HX_STACK_LINE(60)
		this->listEdges->splice((int)0,this->listEdges->length);
		HX_STACK_LINE(61)
		this->astar->findPath(this->entity->x,this->entity->y,toX,toY,this->listFaces,this->listEdges);
		HX_STACK_LINE(62)
		if (((this->listFaces->length == (int)0))){
			HX_STACK_LINE(64)
			return null();
		}
		HX_STACK_LINE(67)
		this->funnel->findPath(this->entity->x,this->entity->y,toX,toY,this->listFaces,this->listEdges,resultPath);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(PathFinder_obj,findPath,(void))


PathFinder_obj::PathFinder_obj()
{
}

void PathFinder_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(PathFinder);
	HX_MARK_MEMBER_NAME(entity,"entity");
	HX_MARK_MEMBER_NAME(_mesh,"_mesh");
	HX_MARK_MEMBER_NAME(astar,"astar");
	HX_MARK_MEMBER_NAME(funnel,"funnel");
	HX_MARK_MEMBER_NAME(radius,"radius");
	HX_MARK_MEMBER_NAME(listFaces,"listFaces");
	HX_MARK_MEMBER_NAME(listEdges,"listEdges");
	HX_MARK_END_CLASS();
}

void PathFinder_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(entity,"entity");
	HX_VISIT_MEMBER_NAME(_mesh,"_mesh");
	HX_VISIT_MEMBER_NAME(astar,"astar");
	HX_VISIT_MEMBER_NAME(funnel,"funnel");
	HX_VISIT_MEMBER_NAME(radius,"radius");
	HX_VISIT_MEMBER_NAME(listFaces,"listFaces");
	HX_VISIT_MEMBER_NAME(listEdges,"listEdges");
}

Dynamic PathFinder_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"mesh") ) { return get_mesh(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_mesh") ) { return _mesh; }
		if (HX_FIELD_EQ(inName,"astar") ) { return astar; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"entity") ) { return entity; }
		if (HX_FIELD_EQ(inName,"funnel") ) { return funnel; }
		if (HX_FIELD_EQ(inName,"radius") ) { return radius; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"get_mesh") ) { return get_mesh_dyn(); }
		if (HX_FIELD_EQ(inName,"set_mesh") ) { return set_mesh_dyn(); }
		if (HX_FIELD_EQ(inName,"findPath") ) { return findPath_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"listFaces") ) { return listFaces; }
		if (HX_FIELD_EQ(inName,"listEdges") ) { return listEdges; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic PathFinder_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"mesh") ) { return set_mesh(inValue); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_mesh") ) { _mesh=inValue.Cast< ::hxDaedalus::data::Mesh >(); return inValue; }
		if (HX_FIELD_EQ(inName,"astar") ) { astar=inValue.Cast< ::hxDaedalus::ai::AStar >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"entity") ) { entity=inValue.Cast< ::hxDaedalus::ai::EntityAI >(); return inValue; }
		if (HX_FIELD_EQ(inName,"funnel") ) { funnel=inValue.Cast< ::hxDaedalus::ai::Funnel >(); return inValue; }
		if (HX_FIELD_EQ(inName,"radius") ) { radius=inValue.Cast< Float >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"listFaces") ) { listFaces=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"listEdges") ) { listEdges=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void PathFinder_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("entity"));
	outFields->push(HX_CSTRING("mesh"));
	outFields->push(HX_CSTRING("_mesh"));
	outFields->push(HX_CSTRING("astar"));
	outFields->push(HX_CSTRING("funnel"));
	outFields->push(HX_CSTRING("radius"));
	outFields->push(HX_CSTRING("listFaces"));
	outFields->push(HX_CSTRING("listEdges"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::hxDaedalus::ai::EntityAI*/ ,(int)offsetof(PathFinder_obj,entity),HX_CSTRING("entity")},
	{hx::fsObject /*::hxDaedalus::data::Mesh*/ ,(int)offsetof(PathFinder_obj,_mesh),HX_CSTRING("_mesh")},
	{hx::fsObject /*::hxDaedalus::ai::AStar*/ ,(int)offsetof(PathFinder_obj,astar),HX_CSTRING("astar")},
	{hx::fsObject /*::hxDaedalus::ai::Funnel*/ ,(int)offsetof(PathFinder_obj,funnel),HX_CSTRING("funnel")},
	{hx::fsFloat,(int)offsetof(PathFinder_obj,radius),HX_CSTRING("radius")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(PathFinder_obj,listFaces),HX_CSTRING("listFaces")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(PathFinder_obj,listEdges),HX_CSTRING("listEdges")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("entity"),
	HX_CSTRING("_mesh"),
	HX_CSTRING("astar"),
	HX_CSTRING("funnel"),
	HX_CSTRING("radius"),
	HX_CSTRING("listFaces"),
	HX_CSTRING("listEdges"),
	HX_CSTRING("dispose"),
	HX_CSTRING("get_mesh"),
	HX_CSTRING("set_mesh"),
	HX_CSTRING("findPath"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(PathFinder_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(PathFinder_obj::__mClass,"__mClass");
};

#endif

Class PathFinder_obj::__mClass;

void PathFinder_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDaedalus.ai.PathFinder"), hx::TCanCast< PathFinder_obj> ,sStaticFields,sMemberFields,
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

void PathFinder_obj::__boot()
{
}

} // end namespace hxDaedalus
} // end namespace ai
