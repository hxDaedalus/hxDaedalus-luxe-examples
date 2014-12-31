#include <hxcpp.h>

#ifndef INCLUDED_hxDaedalus_ai_EntityAI
#include <hxDaedalus/ai/EntityAI.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_Edge
#include <hxDaedalus/data/Edge.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_Mesh
#include <hxDaedalus/data/Mesh.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_Vertex
#include <hxDaedalus/data/Vertex.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_math_Point2D
#include <hxDaedalus/data/math/Point2D.h>
#endif
#ifndef INCLUDED_hxDaedalus_graphics_ISimpleDrawingContext
#include <hxDaedalus/graphics/ISimpleDrawingContext.h>
#endif
#ifndef INCLUDED_hxDaedalus_graphics_flash_SimpleDrawingContext
#include <hxDaedalus/graphics/flash/SimpleDrawingContext.h>
#endif
#ifndef INCLUDED_hxDaedalus_view_SimpleView
#include <hxDaedalus/view/SimpleView.h>
#endif
#ifndef INCLUDED_openfl__v2_display_CapsStyle
#include <openfl/_v2/display/CapsStyle.h>
#endif
#ifndef INCLUDED_openfl__v2_display_Graphics
#include <openfl/_v2/display/Graphics.h>
#endif
#ifndef INCLUDED_openfl__v2_display_JointStyle
#include <openfl/_v2/display/JointStyle.h>
#endif
#ifndef INCLUDED_openfl__v2_display_LineScaleMode
#include <openfl/_v2/display/LineScaleMode.h>
#endif
namespace hxDaedalus{
namespace view{

Void SimpleView_obj::__construct(::openfl::_v2::display::Graphics targetCanvas)
{
HX_STACK_FRAME("hxDaedalus.view.SimpleView","new",0x521c9399,"hxDaedalus.view.SimpleView.new","hxDaedalus/view/SimpleView.hx",15,0x30900997)
HX_STACK_THIS(this)
HX_STACK_ARG(targetCanvas,"targetCanvas")
{
	HX_STACK_LINE(35)
	this->entitiesAlpha = .75;
	HX_STACK_LINE(34)
	this->entitiesWidth = (int)1;
	HX_STACK_LINE(33)
	this->entitiesColor = (int)65280;
	HX_STACK_LINE(31)
	this->pathsAlpha = .75;
	HX_STACK_LINE(30)
	this->pathsWidth = 1.5;
	HX_STACK_LINE(29)
	this->pathsColor = (int)16760848;
	HX_STACK_LINE(27)
	this->verticesAlpha = .25;
	HX_STACK_LINE(26)
	this->verticesRadius = .5;
	HX_STACK_LINE(25)
	this->verticesColor = (int)255;
	HX_STACK_LINE(23)
	this->constraintsAlpha = 1.0;
	HX_STACK_LINE(22)
	this->constraintsWidth = (int)2;
	HX_STACK_LINE(21)
	this->constraintsColor = (int)16711680;
	HX_STACK_LINE(19)
	this->edgesAlpha = .25;
	HX_STACK_LINE(18)
	this->edgesWidth = (int)1;
	HX_STACK_LINE(17)
	this->edgesColor = (int)10066329;
	HX_STACK_LINE(47)
	::hxDaedalus::graphics::flash::SimpleDrawingContext _g = ::hxDaedalus::graphics::flash::SimpleDrawingContext_obj::__new(targetCanvas);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(47)
	this->graphics = _g;
}
;
	return null();
}

//SimpleView_obj::~SimpleView_obj() { }

Dynamic SimpleView_obj::__CreateEmpty() { return  new SimpleView_obj; }
hx::ObjectPtr< SimpleView_obj > SimpleView_obj::__new(::openfl::_v2::display::Graphics targetCanvas)
{  hx::ObjectPtr< SimpleView_obj > result = new SimpleView_obj();
	result->__construct(targetCanvas);
	return result;}

Dynamic SimpleView_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SimpleView_obj > result = new SimpleView_obj();
	result->__construct(inArgs[0]);
	return result;}

Void SimpleView_obj::drawVertex( ::hxDaedalus::data::Vertex vertex){
{
		HX_STACK_FRAME("hxDaedalus.view.SimpleView","drawVertex",0x036c5c6f,"hxDaedalus.view.SimpleView.drawVertex","hxDaedalus/view/SimpleView.hx",51,0x30900997)
		HX_STACK_THIS(this)
		HX_STACK_ARG(vertex,"vertex")
		HX_STACK_LINE(52)
		this->graphics->graphics->lineStyle(this->verticesRadius,this->verticesColor,this->verticesAlpha,null(),null(),null(),null(),null());
		HX_STACK_LINE(53)
		this->graphics->graphics->beginFill(this->verticesColor,this->verticesAlpha);
		HX_STACK_LINE(54)
		this->graphics->graphics->drawCircle(vertex->get_pos()->x,vertex->get_pos()->y,this->verticesRadius);
		HX_STACK_LINE(55)
		this->graphics->graphics->endFill();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SimpleView_obj,drawVertex,(void))

Void SimpleView_obj::drawEdge( ::hxDaedalus::data::Edge edge){
{
		HX_STACK_FRAME("hxDaedalus.view.SimpleView","drawEdge",0xf2646088,"hxDaedalus.view.SimpleView.drawEdge","hxDaedalus/view/SimpleView.hx",70,0x30900997)
		HX_STACK_THIS(this)
		HX_STACK_ARG(edge,"edge")
		HX_STACK_LINE(70)
		if ((edge->get_isConstrained())){
			HX_STACK_LINE(72)
			this->graphics->graphics->lineStyle(this->constraintsWidth,this->constraintsColor,this->constraintsAlpha,null(),null(),null(),null(),null());
			HX_STACK_LINE(73)
			this->graphics->graphics->moveTo(edge->get_originVertex()->get_pos()->x,edge->get_originVertex()->get_pos()->y);
			HX_STACK_LINE(74)
			this->graphics->graphics->lineTo(edge->get_destinationVertex()->get_pos()->x,edge->get_destinationVertex()->get_pos()->y);
		}
		else{
			HX_STACK_LINE(78)
			this->graphics->graphics->lineStyle(this->edgesWidth,this->edgesColor,this->edgesAlpha,null(),null(),null(),null(),null());
			HX_STACK_LINE(79)
			this->graphics->graphics->moveTo(edge->get_originVertex()->get_pos()->x,edge->get_originVertex()->get_pos()->y);
			HX_STACK_LINE(80)
			this->graphics->graphics->lineTo(edge->get_destinationVertex()->get_pos()->x,edge->get_destinationVertex()->get_pos()->y);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SimpleView_obj,drawEdge,(void))

Void SimpleView_obj::drawMesh( ::hxDaedalus::data::Mesh mesh,hx::Null< bool >  __o_cleanBefore){
bool cleanBefore = __o_cleanBefore.Default(false);
	HX_STACK_FRAME("hxDaedalus.view.SimpleView","drawMesh",0xf7aee238,"hxDaedalus.view.SimpleView.drawMesh","hxDaedalus/view/SimpleView.hx",86,0x30900997)
	HX_STACK_THIS(this)
	HX_STACK_ARG(mesh,"mesh")
	HX_STACK_ARG(cleanBefore,"cleanBefore")
{
		HX_STACK_LINE(87)
		if ((cleanBefore)){
			HX_STACK_LINE(87)
			this->graphics->graphics->clear();
		}
		HX_STACK_LINE(89)
		mesh->traverse(this->drawVertex_dyn(),this->drawEdge_dyn());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(SimpleView_obj,drawMesh,(void))

Void SimpleView_obj::drawEntity( ::hxDaedalus::ai::EntityAI entity,hx::Null< bool >  __o_cleanBefore){
bool cleanBefore = __o_cleanBefore.Default(false);
	HX_STACK_FRAME("hxDaedalus.view.SimpleView","drawEntity",0x6740942e,"hxDaedalus.view.SimpleView.drawEntity","hxDaedalus/view/SimpleView.hx",93,0x30900997)
	HX_STACK_THIS(this)
	HX_STACK_ARG(entity,"entity")
	HX_STACK_ARG(cleanBefore,"cleanBefore")
{
		HX_STACK_LINE(94)
		if ((cleanBefore)){
			HX_STACK_LINE(94)
			this->graphics->graphics->clear();
		}
		HX_STACK_LINE(96)
		this->graphics->graphics->lineStyle(this->entitiesWidth,this->entitiesColor,this->entitiesAlpha,null(),null(),null(),null(),null());
		HX_STACK_LINE(97)
		this->graphics->graphics->beginFill(this->entitiesColor,this->entitiesAlpha);
		HX_STACK_LINE(98)
		{
			HX_STACK_LINE(98)
			Float radius = entity->get_radius();		HX_STACK_VAR(radius,"radius");
			HX_STACK_LINE(98)
			this->graphics->graphics->drawCircle(entity->x,entity->y,radius);
		}
		HX_STACK_LINE(99)
		this->graphics->graphics->endFill();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(SimpleView_obj,drawEntity,(void))

Void SimpleView_obj::drawEntities( Array< ::Dynamic > vEntities,hx::Null< bool >  __o_cleanBefore){
bool cleanBefore = __o_cleanBefore.Default(false);
	HX_STACK_FRAME("hxDaedalus.view.SimpleView","drawEntities",0x27a4b00c,"hxDaedalus.view.SimpleView.drawEntities","hxDaedalus/view/SimpleView.hx",103,0x30900997)
	HX_STACK_THIS(this)
	HX_STACK_ARG(vEntities,"vEntities")
	HX_STACK_ARG(cleanBefore,"cleanBefore")
{
		HX_STACK_LINE(104)
		if ((cleanBefore)){
			HX_STACK_LINE(104)
			this->graphics->graphics->clear();
		}
		HX_STACK_LINE(106)
		{
			HX_STACK_LINE(106)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(106)
			int _g = vEntities->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(106)
			while((true)){
				HX_STACK_LINE(106)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(106)
					break;
				}
				HX_STACK_LINE(106)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(107)
				this->drawEntity(vEntities->__get(i).StaticCast< ::hxDaedalus::ai::EntityAI >(),false);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(SimpleView_obj,drawEntities,(void))

Void SimpleView_obj::drawPath( Array< Float > path,hx::Null< bool >  __o_cleanBefore){
bool cleanBefore = __o_cleanBefore.Default(false);
	HX_STACK_FRAME("hxDaedalus.view.SimpleView","drawPath",0xf9a77df0,"hxDaedalus.view.SimpleView.drawPath","hxDaedalus/view/SimpleView.hx",112,0x30900997)
	HX_STACK_THIS(this)
	HX_STACK_ARG(path,"path")
	HX_STACK_ARG(cleanBefore,"cleanBefore")
{
		HX_STACK_LINE(113)
		if ((cleanBefore)){
			HX_STACK_LINE(113)
			this->graphics->graphics->clear();
		}
		HX_STACK_LINE(115)
		if (((path->length == (int)0))){
			HX_STACK_LINE(115)
			return null();
		}
		HX_STACK_LINE(117)
		this->graphics->graphics->lineStyle(this->pathsWidth,this->pathsColor,this->pathsAlpha,null(),null(),null(),null(),null());
		HX_STACK_LINE(119)
		this->graphics->graphics->moveTo(path->__get((int)0),path->__get((int)1));
		HX_STACK_LINE(120)
		int i = (int)2;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(121)
		while((true)){
			HX_STACK_LINE(121)
			if ((!(((i < path->length))))){
				HX_STACK_LINE(121)
				break;
			}
			HX_STACK_LINE(124)
			this->graphics->graphics->beginFill((int)0,(int)1);
			HX_STACK_LINE(126)
			this->graphics->graphics->lineTo(path->__get(i),path->__get((i + (int)1)));
			HX_STACK_LINE(128)
			this->graphics->graphics->endFill();
			HX_STACK_LINE(130)
			this->graphics->graphics->moveTo(path->__get(i),path->__get((i + (int)1)));
			HX_STACK_LINE(131)
			hx::AddEq(i,(int)2);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(SimpleView_obj,drawPath,(void))


SimpleView_obj::SimpleView_obj()
{
}

void SimpleView_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(SimpleView);
	HX_MARK_MEMBER_NAME(edgesColor,"edgesColor");
	HX_MARK_MEMBER_NAME(edgesWidth,"edgesWidth");
	HX_MARK_MEMBER_NAME(edgesAlpha,"edgesAlpha");
	HX_MARK_MEMBER_NAME(constraintsColor,"constraintsColor");
	HX_MARK_MEMBER_NAME(constraintsWidth,"constraintsWidth");
	HX_MARK_MEMBER_NAME(constraintsAlpha,"constraintsAlpha");
	HX_MARK_MEMBER_NAME(verticesColor,"verticesColor");
	HX_MARK_MEMBER_NAME(verticesRadius,"verticesRadius");
	HX_MARK_MEMBER_NAME(verticesAlpha,"verticesAlpha");
	HX_MARK_MEMBER_NAME(pathsColor,"pathsColor");
	HX_MARK_MEMBER_NAME(pathsWidth,"pathsWidth");
	HX_MARK_MEMBER_NAME(pathsAlpha,"pathsAlpha");
	HX_MARK_MEMBER_NAME(entitiesColor,"entitiesColor");
	HX_MARK_MEMBER_NAME(entitiesWidth,"entitiesWidth");
	HX_MARK_MEMBER_NAME(entitiesAlpha,"entitiesAlpha");
	HX_MARK_MEMBER_NAME(graphics,"graphics");
	HX_MARK_END_CLASS();
}

void SimpleView_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(edgesColor,"edgesColor");
	HX_VISIT_MEMBER_NAME(edgesWidth,"edgesWidth");
	HX_VISIT_MEMBER_NAME(edgesAlpha,"edgesAlpha");
	HX_VISIT_MEMBER_NAME(constraintsColor,"constraintsColor");
	HX_VISIT_MEMBER_NAME(constraintsWidth,"constraintsWidth");
	HX_VISIT_MEMBER_NAME(constraintsAlpha,"constraintsAlpha");
	HX_VISIT_MEMBER_NAME(verticesColor,"verticesColor");
	HX_VISIT_MEMBER_NAME(verticesRadius,"verticesRadius");
	HX_VISIT_MEMBER_NAME(verticesAlpha,"verticesAlpha");
	HX_VISIT_MEMBER_NAME(pathsColor,"pathsColor");
	HX_VISIT_MEMBER_NAME(pathsWidth,"pathsWidth");
	HX_VISIT_MEMBER_NAME(pathsAlpha,"pathsAlpha");
	HX_VISIT_MEMBER_NAME(entitiesColor,"entitiesColor");
	HX_VISIT_MEMBER_NAME(entitiesWidth,"entitiesWidth");
	HX_VISIT_MEMBER_NAME(entitiesAlpha,"entitiesAlpha");
	HX_VISIT_MEMBER_NAME(graphics,"graphics");
}

Dynamic SimpleView_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"graphics") ) { return graphics; }
		if (HX_FIELD_EQ(inName,"drawEdge") ) { return drawEdge_dyn(); }
		if (HX_FIELD_EQ(inName,"drawMesh") ) { return drawMesh_dyn(); }
		if (HX_FIELD_EQ(inName,"drawPath") ) { return drawPath_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"edgesColor") ) { return edgesColor; }
		if (HX_FIELD_EQ(inName,"edgesWidth") ) { return edgesWidth; }
		if (HX_FIELD_EQ(inName,"edgesAlpha") ) { return edgesAlpha; }
		if (HX_FIELD_EQ(inName,"pathsColor") ) { return pathsColor; }
		if (HX_FIELD_EQ(inName,"pathsWidth") ) { return pathsWidth; }
		if (HX_FIELD_EQ(inName,"pathsAlpha") ) { return pathsAlpha; }
		if (HX_FIELD_EQ(inName,"drawVertex") ) { return drawVertex_dyn(); }
		if (HX_FIELD_EQ(inName,"drawEntity") ) { return drawEntity_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"drawEntities") ) { return drawEntities_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"verticesColor") ) { return verticesColor; }
		if (HX_FIELD_EQ(inName,"verticesAlpha") ) { return verticesAlpha; }
		if (HX_FIELD_EQ(inName,"entitiesColor") ) { return entitiesColor; }
		if (HX_FIELD_EQ(inName,"entitiesWidth") ) { return entitiesWidth; }
		if (HX_FIELD_EQ(inName,"entitiesAlpha") ) { return entitiesAlpha; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"verticesRadius") ) { return verticesRadius; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"constraintsColor") ) { return constraintsColor; }
		if (HX_FIELD_EQ(inName,"constraintsWidth") ) { return constraintsWidth; }
		if (HX_FIELD_EQ(inName,"constraintsAlpha") ) { return constraintsAlpha; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic SimpleView_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"graphics") ) { graphics=inValue.Cast< ::hxDaedalus::graphics::flash::SimpleDrawingContext >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"edgesColor") ) { edgesColor=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"edgesWidth") ) { edgesWidth=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"edgesAlpha") ) { edgesAlpha=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"pathsColor") ) { pathsColor=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"pathsWidth") ) { pathsWidth=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"pathsAlpha") ) { pathsAlpha=inValue.Cast< Float >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"verticesColor") ) { verticesColor=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"verticesAlpha") ) { verticesAlpha=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"entitiesColor") ) { entitiesColor=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"entitiesWidth") ) { entitiesWidth=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"entitiesAlpha") ) { entitiesAlpha=inValue.Cast< Float >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"verticesRadius") ) { verticesRadius=inValue.Cast< Float >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"constraintsColor") ) { constraintsColor=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"constraintsWidth") ) { constraintsWidth=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"constraintsAlpha") ) { constraintsAlpha=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void SimpleView_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("edgesColor"));
	outFields->push(HX_CSTRING("edgesWidth"));
	outFields->push(HX_CSTRING("edgesAlpha"));
	outFields->push(HX_CSTRING("constraintsColor"));
	outFields->push(HX_CSTRING("constraintsWidth"));
	outFields->push(HX_CSTRING("constraintsAlpha"));
	outFields->push(HX_CSTRING("verticesColor"));
	outFields->push(HX_CSTRING("verticesRadius"));
	outFields->push(HX_CSTRING("verticesAlpha"));
	outFields->push(HX_CSTRING("pathsColor"));
	outFields->push(HX_CSTRING("pathsWidth"));
	outFields->push(HX_CSTRING("pathsAlpha"));
	outFields->push(HX_CSTRING("entitiesColor"));
	outFields->push(HX_CSTRING("entitiesWidth"));
	outFields->push(HX_CSTRING("entitiesAlpha"));
	outFields->push(HX_CSTRING("graphics"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(SimpleView_obj,edgesColor),HX_CSTRING("edgesColor")},
	{hx::fsFloat,(int)offsetof(SimpleView_obj,edgesWidth),HX_CSTRING("edgesWidth")},
	{hx::fsFloat,(int)offsetof(SimpleView_obj,edgesAlpha),HX_CSTRING("edgesAlpha")},
	{hx::fsInt,(int)offsetof(SimpleView_obj,constraintsColor),HX_CSTRING("constraintsColor")},
	{hx::fsFloat,(int)offsetof(SimpleView_obj,constraintsWidth),HX_CSTRING("constraintsWidth")},
	{hx::fsFloat,(int)offsetof(SimpleView_obj,constraintsAlpha),HX_CSTRING("constraintsAlpha")},
	{hx::fsInt,(int)offsetof(SimpleView_obj,verticesColor),HX_CSTRING("verticesColor")},
	{hx::fsFloat,(int)offsetof(SimpleView_obj,verticesRadius),HX_CSTRING("verticesRadius")},
	{hx::fsFloat,(int)offsetof(SimpleView_obj,verticesAlpha),HX_CSTRING("verticesAlpha")},
	{hx::fsInt,(int)offsetof(SimpleView_obj,pathsColor),HX_CSTRING("pathsColor")},
	{hx::fsFloat,(int)offsetof(SimpleView_obj,pathsWidth),HX_CSTRING("pathsWidth")},
	{hx::fsFloat,(int)offsetof(SimpleView_obj,pathsAlpha),HX_CSTRING("pathsAlpha")},
	{hx::fsInt,(int)offsetof(SimpleView_obj,entitiesColor),HX_CSTRING("entitiesColor")},
	{hx::fsFloat,(int)offsetof(SimpleView_obj,entitiesWidth),HX_CSTRING("entitiesWidth")},
	{hx::fsFloat,(int)offsetof(SimpleView_obj,entitiesAlpha),HX_CSTRING("entitiesAlpha")},
	{hx::fsObject /*::hxDaedalus::graphics::flash::SimpleDrawingContext*/ ,(int)offsetof(SimpleView_obj,graphics),HX_CSTRING("graphics")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("edgesColor"),
	HX_CSTRING("edgesWidth"),
	HX_CSTRING("edgesAlpha"),
	HX_CSTRING("constraintsColor"),
	HX_CSTRING("constraintsWidth"),
	HX_CSTRING("constraintsAlpha"),
	HX_CSTRING("verticesColor"),
	HX_CSTRING("verticesRadius"),
	HX_CSTRING("verticesAlpha"),
	HX_CSTRING("pathsColor"),
	HX_CSTRING("pathsWidth"),
	HX_CSTRING("pathsAlpha"),
	HX_CSTRING("entitiesColor"),
	HX_CSTRING("entitiesWidth"),
	HX_CSTRING("entitiesAlpha"),
	HX_CSTRING("graphics"),
	HX_CSTRING("drawVertex"),
	HX_CSTRING("drawEdge"),
	HX_CSTRING("drawMesh"),
	HX_CSTRING("drawEntity"),
	HX_CSTRING("drawEntities"),
	HX_CSTRING("drawPath"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(SimpleView_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(SimpleView_obj::__mClass,"__mClass");
};

#endif

Class SimpleView_obj::__mClass;

void SimpleView_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDaedalus.view.SimpleView"), hx::TCanCast< SimpleView_obj> ,sStaticFields,sMemberFields,
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

void SimpleView_obj::__boot()
{
}

} // end namespace hxDaedalus
} // end namespace view
