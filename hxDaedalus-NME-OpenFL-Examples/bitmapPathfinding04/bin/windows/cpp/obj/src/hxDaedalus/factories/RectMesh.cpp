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
#ifndef INCLUDED_hxDaedalus_data_Face
#include <hxDaedalus/data/Face.h>
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
#ifndef INCLUDED_hxDaedalus_factories_RectMesh
#include <hxDaedalus/factories/RectMesh.h>
#endif
namespace hxDaedalus{
namespace factories{

Void RectMesh_obj::__construct()
{
HX_STACK_FRAME("hxDaedalus.factories.RectMesh","new",0xa8444e42,"hxDaedalus.factories.RectMesh.new","hxDaedalus/factories/RectMesh.hx",135,0xd047676c)
HX_STACK_THIS(this)
{
}
;
	return null();
}

//RectMesh_obj::~RectMesh_obj() { }

Dynamic RectMesh_obj::__CreateEmpty() { return  new RectMesh_obj; }
hx::ObjectPtr< RectMesh_obj > RectMesh_obj::__new()
{  hx::ObjectPtr< RectMesh_obj > result = new RectMesh_obj();
	result->__construct();
	return result;}

Dynamic RectMesh_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< RectMesh_obj > result = new RectMesh_obj();
	result->__construct();
	return result;}

::hxDaedalus::data::Mesh RectMesh_obj::buildRectangle( Float width,Float height){
	HX_STACK_FRAME("hxDaedalus.factories.RectMesh","buildRectangle",0x96a86c7f,"hxDaedalus.factories.RectMesh.buildRectangle","hxDaedalus/factories/RectMesh.hx",16,0xd047676c)
	HX_STACK_ARG(width,"width")
	HX_STACK_ARG(height,"height")
	HX_STACK_LINE(30)
	::hxDaedalus::data::Vertex vTL = ::hxDaedalus::data::Vertex_obj::__new();		HX_STACK_VAR(vTL,"vTL");
	HX_STACK_LINE(31)
	::hxDaedalus::data::Vertex vTR = ::hxDaedalus::data::Vertex_obj::__new();		HX_STACK_VAR(vTR,"vTR");
	HX_STACK_LINE(32)
	::hxDaedalus::data::Vertex vBR = ::hxDaedalus::data::Vertex_obj::__new();		HX_STACK_VAR(vBR,"vBR");
	HX_STACK_LINE(33)
	::hxDaedalus::data::Vertex vBL = ::hxDaedalus::data::Vertex_obj::__new();		HX_STACK_VAR(vBL,"vBL");
	HX_STACK_LINE(35)
	::hxDaedalus::data::Edge eTL_TR = ::hxDaedalus::data::Edge_obj::__new();		HX_STACK_VAR(eTL_TR,"eTL_TR");
	HX_STACK_LINE(36)
	::hxDaedalus::data::Edge eTR_TL = ::hxDaedalus::data::Edge_obj::__new();		HX_STACK_VAR(eTR_TL,"eTR_TL");
	HX_STACK_LINE(37)
	::hxDaedalus::data::Edge eTR_BR = ::hxDaedalus::data::Edge_obj::__new();		HX_STACK_VAR(eTR_BR,"eTR_BR");
	HX_STACK_LINE(38)
	::hxDaedalus::data::Edge eBR_TR = ::hxDaedalus::data::Edge_obj::__new();		HX_STACK_VAR(eBR_TR,"eBR_TR");
	HX_STACK_LINE(39)
	::hxDaedalus::data::Edge eBR_BL = ::hxDaedalus::data::Edge_obj::__new();		HX_STACK_VAR(eBR_BL,"eBR_BL");
	HX_STACK_LINE(40)
	::hxDaedalus::data::Edge eBL_BR = ::hxDaedalus::data::Edge_obj::__new();		HX_STACK_VAR(eBL_BR,"eBL_BR");
	HX_STACK_LINE(41)
	::hxDaedalus::data::Edge eBL_TL = ::hxDaedalus::data::Edge_obj::__new();		HX_STACK_VAR(eBL_TL,"eBL_TL");
	HX_STACK_LINE(42)
	::hxDaedalus::data::Edge eTL_BL = ::hxDaedalus::data::Edge_obj::__new();		HX_STACK_VAR(eTL_BL,"eTL_BL");
	HX_STACK_LINE(43)
	::hxDaedalus::data::Edge eTR_BL = ::hxDaedalus::data::Edge_obj::__new();		HX_STACK_VAR(eTR_BL,"eTR_BL");
	HX_STACK_LINE(44)
	::hxDaedalus::data::Edge eBL_TR = ::hxDaedalus::data::Edge_obj::__new();		HX_STACK_VAR(eBL_TR,"eBL_TR");
	HX_STACK_LINE(45)
	::hxDaedalus::data::Edge eTL_BR = ::hxDaedalus::data::Edge_obj::__new();		HX_STACK_VAR(eTL_BR,"eTL_BR");
	HX_STACK_LINE(46)
	::hxDaedalus::data::Edge eBR_TL = ::hxDaedalus::data::Edge_obj::__new();		HX_STACK_VAR(eBR_TL,"eBR_TL");
	HX_STACK_LINE(48)
	::hxDaedalus::data::Face fTL_BL_TR = ::hxDaedalus::data::Face_obj::__new();		HX_STACK_VAR(fTL_BL_TR,"fTL_BL_TR");
	HX_STACK_LINE(49)
	::hxDaedalus::data::Face fTR_BL_BR = ::hxDaedalus::data::Face_obj::__new();		HX_STACK_VAR(fTR_BL_BR,"fTR_BL_BR");
	HX_STACK_LINE(50)
	::hxDaedalus::data::Face fTL_BR_BL = ::hxDaedalus::data::Face_obj::__new();		HX_STACK_VAR(fTL_BR_BL,"fTL_BR_BL");
	HX_STACK_LINE(51)
	::hxDaedalus::data::Face fTL_TR_BR = ::hxDaedalus::data::Face_obj::__new();		HX_STACK_VAR(fTL_TR_BR,"fTL_TR_BR");
	HX_STACK_LINE(53)
	::hxDaedalus::data::ConstraintShape boundShape = ::hxDaedalus::data::ConstraintShape_obj::__new();		HX_STACK_VAR(boundShape,"boundShape");
	HX_STACK_LINE(54)
	::hxDaedalus::data::ConstraintSegment segTop = ::hxDaedalus::data::ConstraintSegment_obj::__new();		HX_STACK_VAR(segTop,"segTop");
	HX_STACK_LINE(55)
	::hxDaedalus::data::ConstraintSegment segRight = ::hxDaedalus::data::ConstraintSegment_obj::__new();		HX_STACK_VAR(segRight,"segRight");
	HX_STACK_LINE(56)
	::hxDaedalus::data::ConstraintSegment segBot = ::hxDaedalus::data::ConstraintSegment_obj::__new();		HX_STACK_VAR(segBot,"segBot");
	HX_STACK_LINE(57)
	::hxDaedalus::data::ConstraintSegment segLeft = ::hxDaedalus::data::ConstraintSegment_obj::__new();		HX_STACK_VAR(segLeft,"segLeft");
	HX_STACK_LINE(59)
	::hxDaedalus::data::Mesh mesh = ::hxDaedalus::data::Mesh_obj::__new(width,height);		HX_STACK_VAR(mesh,"mesh");
	HX_STACK_LINE(63)
	Float offset = 10.;		HX_STACK_VAR(offset,"offset");
	HX_STACK_LINE(64)
	vTL->get_pos()->setXY(((int)0 - offset),((int)0 - offset));
	HX_STACK_LINE(65)
	vTR->get_pos()->setXY((width + offset),((int)0 - offset));
	HX_STACK_LINE(66)
	vBR->get_pos()->setXY((width + offset),(height + offset));
	HX_STACK_LINE(67)
	vBL->get_pos()->setXY(((int)0 - offset),(height + offset));
	HX_STACK_LINE(69)
	vTL->setDatas(eTL_TR,null());
	HX_STACK_LINE(70)
	vTR->setDatas(eTR_BR,null());
	HX_STACK_LINE(71)
	vBR->setDatas(eBR_BL,null());
	HX_STACK_LINE(72)
	vBL->setDatas(eBL_TL,null());
	HX_STACK_LINE(74)
	eTL_TR->setDatas(vTL,eTR_TL,eTR_BR,fTL_TR_BR,true,true);
	HX_STACK_LINE(75)
	eTR_TL->setDatas(vTR,eTL_TR,eTL_BL,fTL_BL_TR,true,true);
	HX_STACK_LINE(76)
	eTR_BR->setDatas(vTR,eBR_TR,eBR_TL,fTL_TR_BR,true,true);
	HX_STACK_LINE(77)
	eBR_TR->setDatas(vBR,eTR_BR,eTR_BL,fTR_BL_BR,true,true);
	HX_STACK_LINE(78)
	eBR_BL->setDatas(vBR,eBL_BR,eBL_TL,fTL_BR_BL,true,true);
	HX_STACK_LINE(79)
	eBL_BR->setDatas(vBL,eBR_BL,eBR_TR,fTR_BL_BR,true,true);
	HX_STACK_LINE(80)
	eBL_TL->setDatas(vBL,eTL_BL,eTL_BR,fTL_BR_BL,true,true);
	HX_STACK_LINE(81)
	eTL_BL->setDatas(vTL,eBL_TL,eBL_TR,fTL_BL_TR,true,true);
	HX_STACK_LINE(82)
	eTR_BL->setDatas(vTR,eBL_TR,eBL_BR,fTR_BL_BR,true,false);
	HX_STACK_LINE(83)
	eBL_TR->setDatas(vBL,eTR_BL,eTR_TL,fTL_BL_TR,true,false);
	HX_STACK_LINE(84)
	eTL_BR->setDatas(vTL,eBR_TL,eBR_BL,fTL_BR_BL,false,false);
	HX_STACK_LINE(85)
	eBR_TL->setDatas(vBR,eTL_BR,eTL_TR,fTL_TR_BR,false,false);
	HX_STACK_LINE(87)
	fTL_BL_TR->setDatas(eBL_TR,null());
	HX_STACK_LINE(88)
	fTR_BL_BR->setDatas(eTR_BL,null());
	HX_STACK_LINE(89)
	fTL_BR_BL->setDatas(eBR_BL,false);
	HX_STACK_LINE(90)
	fTL_TR_BR->setDatas(eTR_BR,false);
	HX_STACK_LINE(93)
	vTL->set_fromConstraintSegments(Array_obj< ::Dynamic >::__new().Add(segTop).Add(segLeft));
	HX_STACK_LINE(94)
	vTR->set_fromConstraintSegments(Array_obj< ::Dynamic >::__new().Add(segTop).Add(segRight));
	HX_STACK_LINE(95)
	vBR->set_fromConstraintSegments(Array_obj< ::Dynamic >::__new().Add(segRight).Add(segBot));
	HX_STACK_LINE(96)
	vBL->set_fromConstraintSegments(Array_obj< ::Dynamic >::__new().Add(segBot).Add(segLeft));
	HX_STACK_LINE(98)
	eTL_TR->fromConstraintSegments->push(segTop);
	HX_STACK_LINE(99)
	eTR_TL->fromConstraintSegments->push(segTop);
	HX_STACK_LINE(100)
	eTR_BR->fromConstraintSegments->push(segRight);
	HX_STACK_LINE(101)
	eBR_TR->fromConstraintSegments->push(segRight);
	HX_STACK_LINE(102)
	eBR_BL->fromConstraintSegments->push(segBot);
	HX_STACK_LINE(103)
	eBL_BR->fromConstraintSegments->push(segBot);
	HX_STACK_LINE(104)
	eBL_TL->fromConstraintSegments->push(segLeft);
	HX_STACK_LINE(105)
	eTL_BL->fromConstraintSegments->push(segLeft);
	HX_STACK_LINE(107)
	segTop->get_edges()->push(eTL_TR);
	HX_STACK_LINE(108)
	segRight->get_edges()->push(eTR_BR);
	HX_STACK_LINE(109)
	segBot->get_edges()->push(eBR_BL);
	HX_STACK_LINE(110)
	segLeft->get_edges()->push(eBL_TL);
	HX_STACK_LINE(111)
	segTop->fromShape = boundShape;
	HX_STACK_LINE(112)
	segRight->fromShape = boundShape;
	HX_STACK_LINE(113)
	segBot->fromShape = boundShape;
	HX_STACK_LINE(114)
	segLeft->fromShape = boundShape;
	HX_STACK_LINE(116)
	{
		HX_STACK_LINE(116)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(116)
		Array< ::Dynamic > _g1 = Array_obj< ::Dynamic >::__new().Add(segTop).Add(segRight).Add(segBot).Add(segLeft);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(116)
		while((true)){
			HX_STACK_LINE(116)
			if ((!(((_g < _g1->length))))){
				HX_STACK_LINE(116)
				break;
			}
			HX_STACK_LINE(116)
			::hxDaedalus::data::ConstraintSegment f = _g1->__get(_g).StaticCast< ::hxDaedalus::data::ConstraintSegment >();		HX_STACK_VAR(f,"f");
			HX_STACK_LINE(116)
			++(_g);
			HX_STACK_LINE(116)
			boundShape->segments->push(f);
		}
	}
	HX_STACK_LINE(117)
	{
		HX_STACK_LINE(117)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(117)
		Array< ::Dynamic > _g1 = Array_obj< ::Dynamic >::__new().Add(vTL).Add(vTR).Add(vBR).Add(vBL);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(117)
		while((true)){
			HX_STACK_LINE(117)
			if ((!(((_g < _g1->length))))){
				HX_STACK_LINE(117)
				break;
			}
			HX_STACK_LINE(117)
			::hxDaedalus::data::Vertex f = _g1->__get(_g).StaticCast< ::hxDaedalus::data::Vertex >();		HX_STACK_VAR(f,"f");
			HX_STACK_LINE(117)
			++(_g);
			HX_STACK_LINE(117)
			mesh->_vertices->push(f);
		}
	}
	HX_STACK_LINE(118)
	{
		HX_STACK_LINE(118)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(118)
		Array< ::Dynamic > _g1 = Array_obj< ::Dynamic >::__new().Add(eTL_TR).Add(eTR_TL).Add(eTR_BR).Add(eBR_TR).Add(eBR_BL).Add(eBL_BR).Add(eBL_TL).Add(eTL_BL).Add(eTR_BL).Add(eBL_TR).Add(eTL_BR).Add(eBR_TL);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(118)
		while((true)){
			HX_STACK_LINE(118)
			if ((!(((_g < _g1->length))))){
				HX_STACK_LINE(118)
				break;
			}
			HX_STACK_LINE(118)
			::hxDaedalus::data::Edge f = _g1->__get(_g).StaticCast< ::hxDaedalus::data::Edge >();		HX_STACK_VAR(f,"f");
			HX_STACK_LINE(118)
			++(_g);
			HX_STACK_LINE(118)
			mesh->_edges->push(f);
		}
	}
	HX_STACK_LINE(119)
	{
		HX_STACK_LINE(119)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(119)
		Array< ::Dynamic > _g1 = Array_obj< ::Dynamic >::__new().Add(fTL_BL_TR).Add(fTR_BL_BR).Add(fTL_BR_BL).Add(fTL_TR_BR);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(119)
		while((true)){
			HX_STACK_LINE(119)
			if ((!(((_g < _g1->length))))){
				HX_STACK_LINE(119)
				break;
			}
			HX_STACK_LINE(119)
			::hxDaedalus::data::Face f = _g1->__get(_g).StaticCast< ::hxDaedalus::data::Face >();		HX_STACK_VAR(f,"f");
			HX_STACK_LINE(119)
			++(_g);
			HX_STACK_LINE(119)
			mesh->_faces->push(f);
		}
	}
	HX_STACK_LINE(120)
	mesh->get___constraintShapes()->push(boundShape);
	HX_STACK_LINE(121)
	Array< Float > securityRect = Array_obj< Float >::__new();		HX_STACK_VAR(securityRect,"securityRect");
	HX_STACK_LINE(122)
	{
		HX_STACK_LINE(122)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(122)
		Array< Float > _g1 = Array_obj< Float >::__new().Add((int)0).Add((int)0).Add(width).Add((int)0);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(122)
		while((true)){
			HX_STACK_LINE(122)
			if ((!(((_g < _g1->length))))){
				HX_STACK_LINE(122)
				break;
			}
			HX_STACK_LINE(122)
			Float f = _g1->__get(_g);		HX_STACK_VAR(f,"f");
			HX_STACK_LINE(122)
			++(_g);
			HX_STACK_LINE(122)
			securityRect->push(f);
		}
	}
	HX_STACK_LINE(123)
	{
		HX_STACK_LINE(123)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(123)
		Array< Float > _g1 = Array_obj< Float >::__new().Add(width).Add((int)0).Add(width).Add(height);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(123)
		while((true)){
			HX_STACK_LINE(123)
			if ((!(((_g < _g1->length))))){
				HX_STACK_LINE(123)
				break;
			}
			HX_STACK_LINE(123)
			Float f = _g1->__get(_g);		HX_STACK_VAR(f,"f");
			HX_STACK_LINE(123)
			++(_g);
			HX_STACK_LINE(123)
			securityRect->push(f);
		}
	}
	HX_STACK_LINE(124)
	{
		HX_STACK_LINE(124)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(124)
		Array< Float > _g1 = Array_obj< Float >::__new().Add(width).Add(height).Add((int)0).Add(height);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(124)
		while((true)){
			HX_STACK_LINE(124)
			if ((!(((_g < _g1->length))))){
				HX_STACK_LINE(124)
				break;
			}
			HX_STACK_LINE(124)
			Float f = _g1->__get(_g);		HX_STACK_VAR(f,"f");
			HX_STACK_LINE(124)
			++(_g);
			HX_STACK_LINE(124)
			securityRect->push(f);
		}
	}
	HX_STACK_LINE(125)
	{
		HX_STACK_LINE(125)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(125)
		Array< Float > _g1 = Array_obj< Float >::__new().Add((int)0).Add(height).Add((int)0).Add((int)0);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(125)
		while((true)){
			HX_STACK_LINE(125)
			if ((!(((_g < _g1->length))))){
				HX_STACK_LINE(125)
				break;
			}
			HX_STACK_LINE(125)
			Float f = _g1->__get(_g);		HX_STACK_VAR(f,"f");
			HX_STACK_LINE(125)
			++(_g);
			HX_STACK_LINE(125)
			securityRect->push(f);
		}
	}
	HX_STACK_LINE(127)
	mesh->set_clipping(false);
	HX_STACK_LINE(128)
	mesh->insertConstraintShape(securityRect);
	HX_STACK_LINE(129)
	mesh->set_clipping(true);
	HX_STACK_LINE(131)
	return mesh;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(RectMesh_obj,buildRectangle,return )


RectMesh_obj::RectMesh_obj()
{
}

Dynamic RectMesh_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 14:
		if (HX_FIELD_EQ(inName,"buildRectangle") ) { return buildRectangle_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic RectMesh_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void RectMesh_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("buildRectangle"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(RectMesh_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(RectMesh_obj::__mClass,"__mClass");
};

#endif

Class RectMesh_obj::__mClass;

void RectMesh_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDaedalus.factories.RectMesh"), hx::TCanCast< RectMesh_obj> ,sStaticFields,sMemberFields,
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

void RectMesh_obj::__boot()
{
}

} // end namespace hxDaedalus
} // end namespace factories
