#include <hxcpp.h>

#ifndef INCLUDED_IMap
#include <IMap.h>
#endif
#ifndef INCLUDED_haxe_ds_ObjectMap
#include <haxe/ds/ObjectMap.h>
#endif
#ifndef INCLUDED_hxDaedalus_ai_AStar
#include <hxDaedalus/ai/AStar.h>
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
#ifndef INCLUDED_hxDaedalus_data_math_Geom2D
#include <hxDaedalus/data/math/Geom2D.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_math_Intersection
#include <hxDaedalus/data/math/Intersection.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_math_Point2D
#include <hxDaedalus/data/math/Point2D.h>
#endif
#ifndef INCLUDED_hxDaedalus_iterators_FromFaceToInnerEdges
#include <hxDaedalus/iterators/FromFaceToInnerEdges.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace hxDaedalus{
namespace ai{

Void AStar_obj::__construct()
{
HX_STACK_FRAME("hxDaedalus.ai.AStar","new",0xcde38dd8,"hxDaedalus.ai.AStar.new","hxDaedalus/ai/AStar.hx",42,0x36e7cb38)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(43)
	::hxDaedalus::iterators::FromFaceToInnerEdges _g = ::hxDaedalus::iterators::FromFaceToInnerEdges_obj::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(43)
	this->iterEdge = _g;
}
;
	return null();
}

//AStar_obj::~AStar_obj() { }

Dynamic AStar_obj::__CreateEmpty() { return  new AStar_obj; }
hx::ObjectPtr< AStar_obj > AStar_obj::__new()
{  hx::ObjectPtr< AStar_obj > result = new AStar_obj();
	result->__construct();
	return result;}

Dynamic AStar_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AStar_obj > result = new AStar_obj();
	result->__construct();
	return result;}

Void AStar_obj::dispose( ){
{
		HX_STACK_FRAME("hxDaedalus.ai.AStar","dispose",0xd0145a17,"hxDaedalus.ai.AStar.dispose","hxDaedalus/ai/AStar.hx",46,0x36e7cb38)
		HX_STACK_THIS(this)
		HX_STACK_LINE(47)
		this->_mesh = null();
		HX_STACK_LINE(48)
		this->closedFaces = null();
		HX_STACK_LINE(49)
		this->sortedOpenedFaces = null();
		HX_STACK_LINE(50)
		this->openedFaces = null();
		HX_STACK_LINE(51)
		this->entryEdges = null();
		HX_STACK_LINE(52)
		this->entryX = null();
		HX_STACK_LINE(53)
		this->entryY = null();
		HX_STACK_LINE(54)
		this->scoreF = null();
		HX_STACK_LINE(55)
		this->scoreG = null();
		HX_STACK_LINE(56)
		this->scoreH = null();
		HX_STACK_LINE(57)
		this->predecessor = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AStar_obj,dispose,(void))

Float AStar_obj::get_radius( ){
	HX_STACK_FRAME("hxDaedalus.ai.AStar","get_radius",0x41b5a1a3,"hxDaedalus.ai.AStar.get_radius","hxDaedalus/ai/AStar.hx",61,0x36e7cb38)
	HX_STACK_THIS(this)
	HX_STACK_LINE(61)
	return this->_radius;
}


HX_DEFINE_DYNAMIC_FUNC0(AStar_obj,get_radius,return )

Float AStar_obj::set_radius( Float value){
	HX_STACK_FRAME("hxDaedalus.ai.AStar","set_radius",0x45334017,"hxDaedalus.ai.AStar.set_radius","hxDaedalus/ai/AStar.hx",64,0x36e7cb38)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(65)
	this->_radius = value;
	HX_STACK_LINE(66)
	this->radiusSquared = (this->_radius * this->_radius);
	HX_STACK_LINE(67)
	this->diameter = (this->_radius * (int)2);
	HX_STACK_LINE(68)
	this->diameterSquared = (this->diameter * this->diameter);
	HX_STACK_LINE(69)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(AStar_obj,set_radius,return )

::hxDaedalus::data::Mesh AStar_obj::set_mesh( ::hxDaedalus::data::Mesh value){
	HX_STACK_FRAME("hxDaedalus.ai.AStar","set_mesh",0x9087ce72,"hxDaedalus.ai.AStar.set_mesh","hxDaedalus/ai/AStar.hx",72,0x36e7cb38)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(73)
	this->_mesh = value;
	HX_STACK_LINE(74)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(AStar_obj,set_mesh,return )

Void AStar_obj::findPath( Float fromX,Float fromY,Float toX,Float toY,Array< ::Dynamic > resultListFaces,Array< ::Dynamic > resultListEdges){
{
		HX_STACK_FRAME("hxDaedalus.ai.AStar","findPath",0xb6fc6206,"hxDaedalus.ai.AStar.findPath","hxDaedalus/ai/AStar.hx",80,0x36e7cb38)
		HX_STACK_THIS(this)
		HX_STACK_ARG(fromX,"fromX")
		HX_STACK_ARG(fromY,"fromY")
		HX_STACK_ARG(toX,"toX")
		HX_STACK_ARG(toY,"toY")
		HX_STACK_ARG(resultListFaces,"resultListFaces")
		HX_STACK_ARG(resultListEdges,"resultListEdges")
		HX_STACK_LINE(82)
		::haxe::ds::ObjectMap _g = ::haxe::ds::ObjectMap_obj::__new();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(82)
		this->closedFaces = _g;
		HX_STACK_LINE(83)
		Array< ::Dynamic > _g1 = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(83)
		this->sortedOpenedFaces = _g1;
		HX_STACK_LINE(84)
		::haxe::ds::ObjectMap _g2 = ::haxe::ds::ObjectMap_obj::__new();		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(84)
		this->openedFaces = _g2;
		HX_STACK_LINE(85)
		::haxe::ds::ObjectMap _g3 = ::haxe::ds::ObjectMap_obj::__new();		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(85)
		this->entryEdges = _g3;
		HX_STACK_LINE(86)
		::haxe::ds::ObjectMap _g4 = ::haxe::ds::ObjectMap_obj::__new();		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(86)
		this->entryX = _g4;
		HX_STACK_LINE(87)
		::haxe::ds::ObjectMap _g5 = ::haxe::ds::ObjectMap_obj::__new();		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(87)
		this->entryY = _g5;
		HX_STACK_LINE(88)
		::haxe::ds::ObjectMap _g6 = ::haxe::ds::ObjectMap_obj::__new();		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(88)
		this->scoreF = _g6;
		HX_STACK_LINE(89)
		::haxe::ds::ObjectMap _g7 = ::haxe::ds::ObjectMap_obj::__new();		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(89)
		this->scoreG = _g7;
		HX_STACK_LINE(90)
		::haxe::ds::ObjectMap _g8 = ::haxe::ds::ObjectMap_obj::__new();		HX_STACK_VAR(_g8,"_g8");
		HX_STACK_LINE(90)
		this->scoreH = _g8;
		HX_STACK_LINE(91)
		::haxe::ds::ObjectMap _g9 = ::haxe::ds::ObjectMap_obj::__new();		HX_STACK_VAR(_g9,"_g9");
		HX_STACK_LINE(91)
		this->predecessor = _g9;
		HX_STACK_LINE(93)
		::hxDaedalus::data::math::Intersection loc;		HX_STACK_VAR(loc,"loc");
		HX_STACK_LINE(94)
		::hxDaedalus::data::Edge locEdge;		HX_STACK_VAR(locEdge,"locEdge");
		HX_STACK_LINE(95)
		::hxDaedalus::data::Vertex locVertex;		HX_STACK_VAR(locVertex,"locVertex");
		HX_STACK_LINE(96)
		Float distance;		HX_STACK_VAR(distance,"distance");
		HX_STACK_LINE(97)
		::hxDaedalus::data::math::Point2D p1;		HX_STACK_VAR(p1,"p1");
		HX_STACK_LINE(98)
		::hxDaedalus::data::math::Point2D p2;		HX_STACK_VAR(p2,"p2");
		HX_STACK_LINE(99)
		::hxDaedalus::data::math::Point2D p3;		HX_STACK_VAR(p3,"p3");
		HX_STACK_LINE(101)
		::hxDaedalus::data::math::Intersection _g10 = ::hxDaedalus::data::math::Geom2D_obj::locatePosition(fromX,fromY,this->_mesh);		HX_STACK_VAR(_g10,"_g10");
		HX_STACK_LINE(101)
		loc = _g10;
		HX_STACK_LINE(102)
		switch( (int)(loc->__Index())){
			case (int)0: {
				HX_STACK_LINE(102)
				::hxDaedalus::data::Vertex vertex = (::hxDaedalus::data::math::Intersection(loc))->__Param(0);		HX_STACK_VAR(vertex,"vertex");
				HX_STACK_LINE(103)
				{
					HX_STACK_LINE(104)
					locVertex = vertex;
					HX_STACK_LINE(105)
					return null();
				}
			}
			;break;
			case (int)1: {
				HX_STACK_LINE(102)
				::hxDaedalus::data::Edge edge = (::hxDaedalus::data::math::Intersection(loc))->__Param(0);		HX_STACK_VAR(edge,"edge");
				HX_STACK_LINE(106)
				{
					HX_STACK_LINE(107)
					locEdge = edge;
					HX_STACK_LINE(108)
					if ((locEdge->get_isConstrained())){
						HX_STACK_LINE(108)
						return null();
					}
					HX_STACK_LINE(109)
					::hxDaedalus::data::Face _g11 = locEdge->get_leftFace();		HX_STACK_VAR(_g11,"_g11");
					HX_STACK_LINE(109)
					this->fromFace = _g11;
				}
			}
			;break;
			case (int)2: {
				HX_STACK_LINE(102)
				::hxDaedalus::data::Face face = (::hxDaedalus::data::math::Intersection(loc))->__Param(0);		HX_STACK_VAR(face,"face");
				HX_STACK_LINE(111)
				this->fromFace = face;
			}
			;break;
			case (int)3: {
			}
			;break;
		}
		HX_STACK_LINE(117)
		::hxDaedalus::data::math::Intersection _g12 = ::hxDaedalus::data::math::Geom2D_obj::locatePosition(toX,toY,this->_mesh);		HX_STACK_VAR(_g12,"_g12");
		HX_STACK_LINE(117)
		loc = _g12;
		HX_STACK_LINE(118)
		switch( (int)(loc->__Index())){
			case (int)0: {
				HX_STACK_LINE(118)
				::hxDaedalus::data::Vertex vertex = (::hxDaedalus::data::math::Intersection(loc))->__Param(0);		HX_STACK_VAR(vertex,"vertex");
				HX_STACK_LINE(119)
				{
					HX_STACK_LINE(120)
					locVertex = vertex;
					HX_STACK_LINE(121)
					::hxDaedalus::data::Face _g13 = locVertex->get_edge()->get_leftFace();		HX_STACK_VAR(_g13,"_g13");
					HX_STACK_LINE(121)
					this->toFace = _g13;
				}
			}
			;break;
			case (int)1: {
				HX_STACK_LINE(118)
				::hxDaedalus::data::Edge edge = (::hxDaedalus::data::math::Intersection(loc))->__Param(0);		HX_STACK_VAR(edge,"edge");
				HX_STACK_LINE(122)
				{
					HX_STACK_LINE(123)
					locEdge = edge;
					HX_STACK_LINE(124)
					::hxDaedalus::data::Face _g14 = locEdge->get_leftFace();		HX_STACK_VAR(_g14,"_g14");
					HX_STACK_LINE(124)
					this->toFace = _g14;
				}
			}
			;break;
			case (int)2: {
				HX_STACK_LINE(118)
				::hxDaedalus::data::Face face = (::hxDaedalus::data::math::Intersection(loc))->__Param(0);		HX_STACK_VAR(face,"face");
				HX_STACK_LINE(126)
				this->toFace = face;
			}
			;break;
			case (int)3: {
			}
			;break;
		}
		HX_STACK_LINE(136)
		this->sortedOpenedFaces->push(this->fromFace);
		HX_STACK_LINE(137)
		{
			HX_STACK_LINE(137)
			this->entryEdges->set(this->fromFace,null());
			HX_STACK_LINE(137)
			Dynamic();
		}
		HX_STACK_LINE(138)
		{
			HX_STACK_LINE(138)
			this->entryX->set(this->fromFace,fromX);
			HX_STACK_LINE(138)
			fromX;
		}
		HX_STACK_LINE(139)
		{
			HX_STACK_LINE(139)
			this->entryY->set(this->fromFace,fromY);
			HX_STACK_LINE(139)
			fromY;
		}
		HX_STACK_LINE(140)
		{
			HX_STACK_LINE(140)
			this->scoreG->set(this->fromFace,(int)0);
			HX_STACK_LINE(140)
			(int)0;
		}
		HX_STACK_LINE(141)
		Float dist = ::Math_obj::sqrt(((((toX - fromX)) * ((toX - fromX))) + (((toY - fromY)) * ((toY - fromY)))));		HX_STACK_VAR(dist,"dist");
		HX_STACK_LINE(142)
		{
			HX_STACK_LINE(142)
			this->scoreH->set(this->fromFace,dist);
			HX_STACK_LINE(142)
			dist;
		}
		HX_STACK_LINE(143)
		{
			HX_STACK_LINE(143)
			this->scoreF->set(this->fromFace,dist);
			HX_STACK_LINE(143)
			dist;
		}
		HX_STACK_LINE(145)
		::hxDaedalus::data::Edge innerEdge;		HX_STACK_VAR(innerEdge,"innerEdge");
		HX_STACK_LINE(146)
		::hxDaedalus::data::Face neighbourFace;		HX_STACK_VAR(neighbourFace,"neighbourFace");
		HX_STACK_LINE(147)
		Float f;		HX_STACK_VAR(f,"f");
		HX_STACK_LINE(148)
		Float g;		HX_STACK_VAR(g,"g");
		HX_STACK_LINE(149)
		Float h;		HX_STACK_VAR(h,"h");
		HX_STACK_LINE(150)
		::hxDaedalus::data::math::Point2D fromPoint = ::hxDaedalus::data::math::Point2D_obj::__new(null(),null());		HX_STACK_VAR(fromPoint,"fromPoint");
		HX_STACK_LINE(151)
		::hxDaedalus::data::math::Point2D entryPoint = ::hxDaedalus::data::math::Point2D_obj::__new(null(),null());		HX_STACK_VAR(entryPoint,"entryPoint");
		HX_STACK_LINE(152)
		::hxDaedalus::data::math::Point2D distancePoint = ::hxDaedalus::data::math::Point2D_obj::__new(null(),null());		HX_STACK_VAR(distancePoint,"distancePoint");
		HX_STACK_LINE(153)
		bool fillDatas;		HX_STACK_VAR(fillDatas,"fillDatas");
		HX_STACK_LINE(154)
		while((true)){
			HX_STACK_LINE(156)
			if (((this->sortedOpenedFaces->length == (int)0))){
				HX_STACK_LINE(158)
				this->curFace = null();
				HX_STACK_LINE(159)
				break;
			}
			HX_STACK_LINE(162)
			::hxDaedalus::data::Face _g15 = this->sortedOpenedFaces->pop().StaticCast< ::hxDaedalus::data::Face >();		HX_STACK_VAR(_g15,"_g15");
			HX_STACK_LINE(162)
			this->curFace = _g15;
			HX_STACK_LINE(163)
			if (((this->curFace == this->toFace))){
				HX_STACK_LINE(163)
				break;
			}
			HX_STACK_LINE(165)
			this->iterEdge->set_fromFace(this->curFace);
			HX_STACK_LINE(166)
			while((true)){
				HX_STACK_LINE(166)
				::hxDaedalus::data::Edge _g16 = this->iterEdge->next();		HX_STACK_VAR(_g16,"_g16");
				HX_STACK_LINE(166)
				::hxDaedalus::data::Edge _g17 = innerEdge = _g16;		HX_STACK_VAR(_g17,"_g17");
				HX_STACK_LINE(166)
				if ((!(((_g17 != null()))))){
					HX_STACK_LINE(166)
					break;
				}
				HX_STACK_LINE(167)
				if ((innerEdge->get_isConstrained())){
					HX_STACK_LINE(167)
					continue;
				}
				HX_STACK_LINE(168)
				::hxDaedalus::data::Face _g18 = innerEdge->get_rightFace();		HX_STACK_VAR(_g18,"_g18");
				HX_STACK_LINE(168)
				neighbourFace = _g18;
				HX_STACK_LINE(169)
				if ((!(this->closedFaces->get(neighbourFace)))){
					struct _Function_4_1{
						inline static bool Block( hx::ObjectPtr< ::hxDaedalus::ai::AStar_obj > __this,::hxDaedalus::data::Edge &innerEdge){
							HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","hxDaedalus/ai/AStar.hx",170,0x36e7cb38)
							{
								HX_STACK_LINE(170)
								::hxDaedalus::data::Edge _g19 = __this->entryEdges->get(__this->curFace);		HX_STACK_VAR(_g19,"_g19");
								HX_STACK_LINE(170)
								return !(__this->isWalkableByRadius(_g19,__this->curFace,innerEdge));
							}
							return null();
						}
					};
					HX_STACK_LINE(170)
					if (((  (((bool((this->curFace != this->fromFace)) && bool((this->_radius > (int)0))))) ? bool(_Function_4_1::Block(this,innerEdge)) : bool(false) ))){
						HX_STACK_LINE(175)
						continue;
					}
					HX_STACK_LINE(178)
					Dynamic _g20 = this->entryX->get(this->curFace);		HX_STACK_VAR(_g20,"_g20");
					HX_STACK_LINE(178)
					fromPoint->x = _g20;
					HX_STACK_LINE(179)
					Dynamic _g21 = this->entryY->get(this->curFace);		HX_STACK_VAR(_g21,"_g21");
					HX_STACK_LINE(179)
					fromPoint->y = _g21;
					HX_STACK_LINE(180)
					entryPoint->x = fromPoint->x;
					HX_STACK_LINE(181)
					entryPoint->y = fromPoint->y;
					HX_STACK_LINE(182)
					entryPoint->x = (Float(((innerEdge->get_originVertex()->get_pos()->x + innerEdge->get_destinationVertex()->get_pos()->x))) / Float((int)2));
					HX_STACK_LINE(183)
					entryPoint->y = (Float(((innerEdge->get_originVertex()->get_pos()->y + innerEdge->get_destinationVertex()->get_pos()->y))) / Float((int)2));
					HX_STACK_LINE(184)
					distancePoint->x = (entryPoint->x - toX);
					HX_STACK_LINE(185)
					distancePoint->y = (entryPoint->y - toY);
					HX_STACK_LINE(186)
					Float _g22 = distancePoint->get_length();		HX_STACK_VAR(_g22,"_g22");
					HX_STACK_LINE(186)
					h = _g22;
					HX_STACK_LINE(187)
					distancePoint->x = (fromPoint->x - entryPoint->x);
					HX_STACK_LINE(188)
					distancePoint->y = (fromPoint->y - entryPoint->y);
					HX_STACK_LINE(189)
					Dynamic _g23 = this->scoreG->get(this->curFace);		HX_STACK_VAR(_g23,"_g23");
					HX_STACK_LINE(189)
					Float _g24 = distancePoint->get_length();		HX_STACK_VAR(_g24,"_g24");
					HX_STACK_LINE(189)
					Float _g25 = (_g23 + _g24);		HX_STACK_VAR(_g25,"_g25");
					HX_STACK_LINE(189)
					g = _g25;
					HX_STACK_LINE(190)
					f = (h + g);
					HX_STACK_LINE(191)
					fillDatas = false;
					HX_STACK_LINE(192)
					Dynamic _g26 = this->openedFaces->get(neighbourFace);		HX_STACK_VAR(_g26,"_g26");
					HX_STACK_LINE(192)
					if (((  ((!(((_g26 == null()))))) ? bool(!(this->openedFaces->get(neighbourFace))) : bool(true) ))){
						HX_STACK_LINE(194)
						this->sortedOpenedFaces->push(neighbourFace);
						HX_STACK_LINE(195)
						{
							HX_STACK_LINE(195)
							this->openedFaces->set(neighbourFace,true);
							HX_STACK_LINE(195)
							true;
						}
						HX_STACK_LINE(196)
						fillDatas = true;
					}
					else{
						HX_STACK_LINE(198)
						Dynamic _g27 = this->scoreF->get(neighbourFace);		HX_STACK_VAR(_g27,"_g27");
						HX_STACK_LINE(198)
						if (((_g27 > f))){
							HX_STACK_LINE(200)
							fillDatas = true;
						}
					}
					HX_STACK_LINE(202)
					if ((fillDatas)){
						HX_STACK_LINE(204)
						{
							HX_STACK_LINE(204)
							this->entryEdges->set(neighbourFace,innerEdge);
							HX_STACK_LINE(204)
							innerEdge;
						}
						HX_STACK_LINE(205)
						{
							HX_STACK_LINE(205)
							Float v = entryPoint->x;		HX_STACK_VAR(v,"v");
							HX_STACK_LINE(205)
							this->entryX->set(neighbourFace,v);
							HX_STACK_LINE(205)
							v;
						}
						HX_STACK_LINE(206)
						{
							HX_STACK_LINE(206)
							Float v = entryPoint->y;		HX_STACK_VAR(v,"v");
							HX_STACK_LINE(206)
							this->entryY->set(neighbourFace,v);
							HX_STACK_LINE(206)
							v;
						}
						HX_STACK_LINE(207)
						{
							HX_STACK_LINE(207)
							this->scoreF->set(neighbourFace,f);
							HX_STACK_LINE(207)
							f;
						}
						HX_STACK_LINE(208)
						{
							HX_STACK_LINE(208)
							this->scoreG->set(neighbourFace,g);
							HX_STACK_LINE(208)
							g;
						}
						HX_STACK_LINE(209)
						{
							HX_STACK_LINE(209)
							this->scoreH->set(neighbourFace,h);
							HX_STACK_LINE(209)
							h;
						}
						HX_STACK_LINE(210)
						{
							HX_STACK_LINE(210)
							::hxDaedalus::data::Face v = this->curFace;		HX_STACK_VAR(v,"v");
							HX_STACK_LINE(210)
							this->predecessor->set(neighbourFace,v);
							HX_STACK_LINE(210)
							v;
						}
					}
				}
			}
			HX_STACK_LINE(215)
			{
				HX_STACK_LINE(215)
				this->openedFaces->set(this->curFace,false);
				HX_STACK_LINE(215)
				false;
			}
			HX_STACK_LINE(216)
			{
				HX_STACK_LINE(216)
				this->closedFaces->set(this->curFace,true);
				HX_STACK_LINE(216)
				true;
			}
			HX_STACK_LINE(217)
			this->sortedOpenedFaces->sort(this->sortingFaces_dyn());
		}
		HX_STACK_LINE(222)
		if (((this->curFace == null()))){
			HX_STACK_LINE(223)
			return null();
		}
		HX_STACK_LINE(227)
		resultListFaces->push(this->curFace);
		HX_STACK_LINE(229)
		while((true)){
			HX_STACK_LINE(229)
			if ((!(((this->curFace != this->fromFace))))){
				HX_STACK_LINE(229)
				break;
			}
			HX_STACK_LINE(230)
			::hxDaedalus::data::Edge _g28 = this->entryEdges->get(this->curFace);		HX_STACK_VAR(_g28,"_g28");
			HX_STACK_LINE(230)
			resultListEdges->unshift(_g28);
			HX_STACK_LINE(233)
			::hxDaedalus::data::Face _g29 = this->predecessor->get(this->curFace);		HX_STACK_VAR(_g29,"_g29");
			HX_STACK_LINE(233)
			this->curFace = _g29;
			HX_STACK_LINE(235)
			resultListFaces->unshift(this->curFace);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC6(AStar_obj,findPath,(void))

int AStar_obj::sortingFaces( ::hxDaedalus::data::Face a,::hxDaedalus::data::Face b){
	HX_STACK_FRAME("hxDaedalus.ai.AStar","sortingFaces",0x57164dda,"hxDaedalus.ai.AStar.sortingFaces","hxDaedalus/ai/AStar.hx",240,0x36e7cb38)
	HX_STACK_THIS(this)
	HX_STACK_ARG(a,"a")
	HX_STACK_ARG(b,"b")
	HX_STACK_LINE(241)
	Dynamic _g = this->scoreF->get(a);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(241)
	Dynamic _g1 = this->scoreF->get(b);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(241)
	if (((_g == _g1))){
		HX_STACK_LINE(242)
		return (int)0;
	}
	else{
		HX_STACK_LINE(243)
		Dynamic _g2 = this->scoreF->get(a);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(243)
		Dynamic _g3 = this->scoreF->get(b);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(243)
		if (((_g2 < _g3))){
			HX_STACK_LINE(244)
			return (int)1;
		}
		else{
			HX_STACK_LINE(246)
			return (int)-1;
		}
	}
	HX_STACK_LINE(241)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC2(AStar_obj,sortingFaces,return )

bool AStar_obj::isWalkableByRadius( ::hxDaedalus::data::Edge fromEdge,::hxDaedalus::data::Face throughFace,::hxDaedalus::data::Edge toEdge){
	HX_STACK_FRAME("hxDaedalus.ai.AStar","isWalkableByRadius",0x6796055e,"hxDaedalus.ai.AStar.isWalkableByRadius","hxDaedalus/ai/AStar.hx",250,0x36e7cb38)
	HX_STACK_THIS(this)
	HX_STACK_ARG(fromEdge,"fromEdge")
	HX_STACK_ARG(throughFace,"throughFace")
	HX_STACK_ARG(toEdge,"toEdge")
	HX_STACK_LINE(251)
	::hxDaedalus::data::Vertex vA = null();		HX_STACK_VAR(vA,"vA");
	HX_STACK_LINE(252)
	::hxDaedalus::data::Vertex vB = null();		HX_STACK_VAR(vB,"vB");
	HX_STACK_LINE(253)
	::hxDaedalus::data::Vertex vC = null();		HX_STACK_VAR(vC,"vC");
	HX_STACK_LINE(256)
	::hxDaedalus::data::Vertex _g = fromEdge->get_originVertex();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(256)
	::hxDaedalus::data::Vertex _g1 = toEdge->get_originVertex();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(256)
	if (((_g == _g1))){
		HX_STACK_LINE(258)
		::hxDaedalus::data::Vertex _g2 = fromEdge->get_destinationVertex();		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(258)
		vA = _g2;
		HX_STACK_LINE(259)
		::hxDaedalus::data::Vertex _g3 = toEdge->get_destinationVertex();		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(259)
		vB = _g3;
		HX_STACK_LINE(260)
		::hxDaedalus::data::Vertex _g4 = fromEdge->get_originVertex();		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(260)
		vC = _g4;
	}
	else{
		HX_STACK_LINE(262)
		::hxDaedalus::data::Vertex _g5 = fromEdge->get_destinationVertex();		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(262)
		::hxDaedalus::data::Vertex _g6 = toEdge->get_destinationVertex();		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(262)
		if (((_g5 == _g6))){
			HX_STACK_LINE(264)
			::hxDaedalus::data::Vertex _g7 = fromEdge->get_originVertex();		HX_STACK_VAR(_g7,"_g7");
			HX_STACK_LINE(264)
			vA = _g7;
			HX_STACK_LINE(265)
			::hxDaedalus::data::Vertex _g8 = toEdge->get_originVertex();		HX_STACK_VAR(_g8,"_g8");
			HX_STACK_LINE(265)
			vB = _g8;
			HX_STACK_LINE(266)
			::hxDaedalus::data::Vertex _g9 = fromEdge->get_destinationVertex();		HX_STACK_VAR(_g9,"_g9");
			HX_STACK_LINE(266)
			vC = _g9;
		}
		else{
			HX_STACK_LINE(268)
			::hxDaedalus::data::Vertex _g10 = fromEdge->get_originVertex();		HX_STACK_VAR(_g10,"_g10");
			HX_STACK_LINE(268)
			::hxDaedalus::data::Vertex _g11 = toEdge->get_destinationVertex();		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(268)
			if (((_g10 == _g11))){
				HX_STACK_LINE(270)
				::hxDaedalus::data::Vertex _g12 = fromEdge->get_destinationVertex();		HX_STACK_VAR(_g12,"_g12");
				HX_STACK_LINE(270)
				vA = _g12;
				HX_STACK_LINE(271)
				::hxDaedalus::data::Vertex _g13 = toEdge->get_originVertex();		HX_STACK_VAR(_g13,"_g13");
				HX_STACK_LINE(271)
				vB = _g13;
				HX_STACK_LINE(272)
				::hxDaedalus::data::Vertex _g14 = fromEdge->get_originVertex();		HX_STACK_VAR(_g14,"_g14");
				HX_STACK_LINE(272)
				vC = _g14;
			}
			else{
				HX_STACK_LINE(274)
				::hxDaedalus::data::Vertex _g15 = fromEdge->get_destinationVertex();		HX_STACK_VAR(_g15,"_g15");
				HX_STACK_LINE(274)
				::hxDaedalus::data::Vertex _g16 = toEdge->get_originVertex();		HX_STACK_VAR(_g16,"_g16");
				HX_STACK_LINE(274)
				if (((_g15 == _g16))){
					HX_STACK_LINE(276)
					::hxDaedalus::data::Vertex _g17 = fromEdge->get_originVertex();		HX_STACK_VAR(_g17,"_g17");
					HX_STACK_LINE(276)
					vA = _g17;
					HX_STACK_LINE(277)
					::hxDaedalus::data::Vertex _g18 = toEdge->get_destinationVertex();		HX_STACK_VAR(_g18,"_g18");
					HX_STACK_LINE(277)
					vB = _g18;
					HX_STACK_LINE(278)
					::hxDaedalus::data::Vertex _g19 = fromEdge->get_destinationVertex();		HX_STACK_VAR(_g19,"_g19");
					HX_STACK_LINE(278)
					vC = _g19;
				}
			}
		}
	}
	HX_STACK_LINE(281)
	Float dot;		HX_STACK_VAR(dot,"dot");
	HX_STACK_LINE(282)
	bool result;		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(283)
	Float distSquared;		HX_STACK_VAR(distSquared,"distSquared");
	HX_STACK_LINE(286)
	dot = ((((vC->get_pos()->x - vA->get_pos()->x)) * ((vB->get_pos()->x - vA->get_pos()->x))) + (((vC->get_pos()->y - vA->get_pos()->y)) * ((vB->get_pos()->y - vA->get_pos()->y))));
	HX_STACK_LINE(287)
	if (((dot <= (int)0))){
		HX_STACK_LINE(289)
		distSquared = ((((vC->get_pos()->x - vA->get_pos()->x)) * ((vC->get_pos()->x - vA->get_pos()->x))) + (((vC->get_pos()->y - vA->get_pos()->y)) * ((vC->get_pos()->y - vA->get_pos()->y))));
		HX_STACK_LINE(290)
		if (((distSquared >= this->diameterSquared))){
			HX_STACK_LINE(291)
			return true;
		}
		else{
			HX_STACK_LINE(293)
			return false;
		}
	}
	HX_STACK_LINE(299)
	dot = ((((vC->get_pos()->x - vB->get_pos()->x)) * ((vA->get_pos()->x - vB->get_pos()->x))) + (((vC->get_pos()->y - vB->get_pos()->y)) * ((vA->get_pos()->y - vB->get_pos()->y))));
	HX_STACK_LINE(300)
	if (((dot <= (int)0))){
		HX_STACK_LINE(302)
		distSquared = ((((vC->get_pos()->x - vB->get_pos()->x)) * ((vC->get_pos()->x - vB->get_pos()->x))) + (((vC->get_pos()->y - vB->get_pos()->y)) * ((vC->get_pos()->y - vB->get_pos()->y))));
		HX_STACK_LINE(303)
		if (((distSquared >= this->diameterSquared))){
			HX_STACK_LINE(304)
			return true;
		}
		else{
			HX_STACK_LINE(306)
			return false;
		}
	}
	HX_STACK_LINE(312)
	::hxDaedalus::data::Edge adjEdge;		HX_STACK_VAR(adjEdge,"adjEdge");
	HX_STACK_LINE(313)
	::hxDaedalus::data::Edge _g20 = throughFace->get_edge();		HX_STACK_VAR(_g20,"_g20");
	struct _Function_1_1{
		inline static bool Block( ::hxDaedalus::data::Edge &fromEdge,::hxDaedalus::data::Face &throughFace){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","hxDaedalus/ai/AStar.hx",313,0x36e7cb38)
			{
				HX_STACK_LINE(313)
				::hxDaedalus::data::Edge _g21 = throughFace->get_edge()->get_oppositeEdge();		HX_STACK_VAR(_g21,"_g21");
				HX_STACK_LINE(313)
				return (_g21 != fromEdge);
			}
			return null();
		}
	};
	struct _Function_1_2{
		inline static bool Block( ::hxDaedalus::data::Edge &toEdge,::hxDaedalus::data::Face &throughFace){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","hxDaedalus/ai/AStar.hx",313,0x36e7cb38)
			{
				HX_STACK_LINE(313)
				::hxDaedalus::data::Edge _g22 = throughFace->get_edge();		HX_STACK_VAR(_g22,"_g22");
				HX_STACK_LINE(313)
				return (_g22 != toEdge);
			}
			return null();
		}
	};
	struct _Function_1_3{
		inline static bool Block( ::hxDaedalus::data::Edge &toEdge,::hxDaedalus::data::Face &throughFace){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","hxDaedalus/ai/AStar.hx",313,0x36e7cb38)
			{
				HX_STACK_LINE(313)
				::hxDaedalus::data::Edge _g23 = throughFace->get_edge()->get_oppositeEdge();		HX_STACK_VAR(_g23,"_g23");
				HX_STACK_LINE(313)
				return (_g23 != toEdge);
			}
			return null();
		}
	};
	HX_STACK_LINE(313)
	if (((  (((  (((  (((_g20 != fromEdge))) ? bool(_Function_1_1::Block(fromEdge,throughFace)) : bool(false) ))) ? bool(_Function_1_2::Block(toEdge,throughFace)) : bool(false) ))) ? bool(_Function_1_3::Block(toEdge,throughFace)) : bool(false) ))){
		HX_STACK_LINE(314)
		::hxDaedalus::data::Edge _g24 = throughFace->get_edge();		HX_STACK_VAR(_g24,"_g24");
		HX_STACK_LINE(314)
		adjEdge = _g24;
	}
	else{
		HX_STACK_LINE(315)
		::hxDaedalus::data::Edge _g25 = throughFace->get_edge()->get_nextLeftEdge();		HX_STACK_VAR(_g25,"_g25");
		struct _Function_2_1{
			inline static bool Block( ::hxDaedalus::data::Edge &fromEdge,::hxDaedalus::data::Face &throughFace){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","hxDaedalus/ai/AStar.hx",315,0x36e7cb38)
				{
					HX_STACK_LINE(315)
					::hxDaedalus::data::Edge _g26 = throughFace->get_edge()->get_nextLeftEdge()->get_oppositeEdge();		HX_STACK_VAR(_g26,"_g26");
					HX_STACK_LINE(315)
					return (_g26 != fromEdge);
				}
				return null();
			}
		};
		struct _Function_2_2{
			inline static bool Block( ::hxDaedalus::data::Edge &toEdge,::hxDaedalus::data::Face &throughFace){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","hxDaedalus/ai/AStar.hx",315,0x36e7cb38)
				{
					HX_STACK_LINE(315)
					::hxDaedalus::data::Edge _g27 = throughFace->get_edge()->get_nextLeftEdge();		HX_STACK_VAR(_g27,"_g27");
					HX_STACK_LINE(315)
					return (_g27 != toEdge);
				}
				return null();
			}
		};
		struct _Function_2_3{
			inline static bool Block( ::hxDaedalus::data::Edge &toEdge,::hxDaedalus::data::Face &throughFace){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","hxDaedalus/ai/AStar.hx",315,0x36e7cb38)
				{
					HX_STACK_LINE(315)
					::hxDaedalus::data::Edge _g28 = throughFace->get_edge()->get_nextLeftEdge()->get_oppositeEdge();		HX_STACK_VAR(_g28,"_g28");
					HX_STACK_LINE(315)
					return (_g28 != toEdge);
				}
				return null();
			}
		};
		HX_STACK_LINE(315)
		if (((  (((  (((  (((_g25 != fromEdge))) ? bool(_Function_2_1::Block(fromEdge,throughFace)) : bool(false) ))) ? bool(_Function_2_2::Block(toEdge,throughFace)) : bool(false) ))) ? bool(_Function_2_3::Block(toEdge,throughFace)) : bool(false) ))){
			HX_STACK_LINE(316)
			::hxDaedalus::data::Edge _g29 = throughFace->get_edge()->get_nextLeftEdge();		HX_STACK_VAR(_g29,"_g29");
			HX_STACK_LINE(316)
			adjEdge = _g29;
		}
		else{
			HX_STACK_LINE(318)
			::hxDaedalus::data::Edge _g30 = throughFace->get_edge()->get_prevLeftEdge();		HX_STACK_VAR(_g30,"_g30");
			HX_STACK_LINE(318)
			adjEdge = _g30;
		}
	}
	HX_STACK_LINE(321)
	if ((adjEdge->get_isConstrained())){
		HX_STACK_LINE(322)
		::hxDaedalus::data::math::Point2D proj = ::hxDaedalus::data::math::Point2D_obj::__new(vC->get_pos()->x,vC->get_pos()->y);		HX_STACK_VAR(proj,"proj");
		HX_STACK_LINE(323)
		::hxDaedalus::data::math::Geom2D_obj::projectOrthogonaly(proj,adjEdge);
		HX_STACK_LINE(324)
		distSquared = ((((proj->x - vC->get_pos()->x)) * ((proj->x - vC->get_pos()->x))) + (((proj->y - vC->get_pos()->y)) * ((proj->y - vC->get_pos()->y))));
		HX_STACK_LINE(325)
		if (((distSquared >= this->diameterSquared))){
			HX_STACK_LINE(326)
			return true;
		}
		else{
			HX_STACK_LINE(328)
			return false;
		}
	}
	else{
		HX_STACK_LINE(334)
		Float distSquaredA = ((((vC->get_pos()->x - vA->get_pos()->x)) * ((vC->get_pos()->x - vA->get_pos()->x))) + (((vC->get_pos()->y - vA->get_pos()->y)) * ((vC->get_pos()->y - vA->get_pos()->y))));		HX_STACK_VAR(distSquaredA,"distSquaredA");
		HX_STACK_LINE(335)
		Float distSquaredB = ((((vC->get_pos()->x - vB->get_pos()->x)) * ((vC->get_pos()->x - vB->get_pos()->x))) + (((vC->get_pos()->y - vB->get_pos()->y)) * ((vC->get_pos()->y - vB->get_pos()->y))));		HX_STACK_VAR(distSquaredB,"distSquaredB");
		HX_STACK_LINE(336)
		if (((bool((distSquaredA < this->diameterSquared)) || bool((distSquaredB < this->diameterSquared))))){
			HX_STACK_LINE(337)
			return false;
		}
		else{
			HX_STACK_LINE(339)
			Array< ::Dynamic > vFaceToCheck = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(vFaceToCheck,"vFaceToCheck");
			HX_STACK_LINE(340)
			Array< ::Dynamic > vFaceIsFromEdge = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(vFaceIsFromEdge,"vFaceIsFromEdge");
			HX_STACK_LINE(341)
			::haxe::ds::ObjectMap facesDone = ::haxe::ds::ObjectMap_obj::__new();		HX_STACK_VAR(facesDone,"facesDone");
			HX_STACK_LINE(342)
			vFaceIsFromEdge->push(adjEdge);
			HX_STACK_LINE(343)
			::hxDaedalus::data::Face _g31 = adjEdge->get_leftFace();		HX_STACK_VAR(_g31,"_g31");
			HX_STACK_LINE(343)
			if (((_g31 == throughFace))){
				HX_STACK_LINE(344)
				::hxDaedalus::data::Face _g32 = adjEdge->get_rightFace();		HX_STACK_VAR(_g32,"_g32");
				HX_STACK_LINE(344)
				vFaceToCheck->push(_g32);
				HX_STACK_LINE(345)
				{
					HX_STACK_LINE(345)
					::hxDaedalus::data::Face k = adjEdge->get_rightFace();		HX_STACK_VAR(k,"k");
					HX_STACK_LINE(345)
					facesDone->set(k,true);
					HX_STACK_LINE(345)
					true;
				}
			}
			else{
				HX_STACK_LINE(347)
				::hxDaedalus::data::Face _g33 = adjEdge->get_leftFace();		HX_STACK_VAR(_g33,"_g33");
				HX_STACK_LINE(347)
				vFaceToCheck->push(_g33);
				HX_STACK_LINE(348)
				{
					HX_STACK_LINE(348)
					::hxDaedalus::data::Face k = adjEdge->get_leftFace();		HX_STACK_VAR(k,"k");
					HX_STACK_LINE(348)
					facesDone->set(k,true);
					HX_STACK_LINE(348)
					true;
				}
			}
			HX_STACK_LINE(351)
			::hxDaedalus::data::Face currFace;		HX_STACK_VAR(currFace,"currFace");
			HX_STACK_LINE(352)
			::hxDaedalus::data::Edge faceFromEdge;		HX_STACK_VAR(faceFromEdge,"faceFromEdge");
			HX_STACK_LINE(353)
			::hxDaedalus::data::Edge currEdgeA;		HX_STACK_VAR(currEdgeA,"currEdgeA");
			HX_STACK_LINE(354)
			::hxDaedalus::data::Face nextFaceA;		HX_STACK_VAR(nextFaceA,"nextFaceA");
			HX_STACK_LINE(355)
			::hxDaedalus::data::Edge currEdgeB;		HX_STACK_VAR(currEdgeB,"currEdgeB");
			HX_STACK_LINE(356)
			::hxDaedalus::data::Face nextFaceB;		HX_STACK_VAR(nextFaceB,"nextFaceB");
			HX_STACK_LINE(357)
			while((true)){
				HX_STACK_LINE(357)
				if ((!(((vFaceToCheck->length > (int)0))))){
					HX_STACK_LINE(357)
					break;
				}
				HX_STACK_LINE(358)
				::hxDaedalus::data::Face _g34 = vFaceToCheck->shift().StaticCast< ::hxDaedalus::data::Face >();		HX_STACK_VAR(_g34,"_g34");
				HX_STACK_LINE(358)
				currFace = _g34;
				HX_STACK_LINE(359)
				::hxDaedalus::data::Edge _g35 = vFaceIsFromEdge->shift().StaticCast< ::hxDaedalus::data::Edge >();		HX_STACK_VAR(_g35,"_g35");
				HX_STACK_LINE(359)
				faceFromEdge = _g35;
				HX_STACK_LINE(362)
				::hxDaedalus::data::Edge _g36 = currFace->get_edge();		HX_STACK_VAR(_g36,"_g36");
				struct _Function_4_1{
					inline static bool Block( ::hxDaedalus::data::Face &currFace,::hxDaedalus::data::Edge &faceFromEdge){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","hxDaedalus/ai/AStar.hx",362,0x36e7cb38)
						{
							HX_STACK_LINE(362)
							::hxDaedalus::data::Edge _g37 = currFace->get_edge();		HX_STACK_VAR(_g37,"_g37");
							HX_STACK_LINE(362)
							::hxDaedalus::data::Edge _g38 = faceFromEdge->get_oppositeEdge();		HX_STACK_VAR(_g38,"_g38");
							HX_STACK_LINE(362)
							return (_g37 == _g38);
						}
						return null();
					}
				};
				HX_STACK_LINE(362)
				if (((  ((!(((_g36 == faceFromEdge))))) ? bool(_Function_4_1::Block(currFace,faceFromEdge)) : bool(true) ))){
					HX_STACK_LINE(364)
					::hxDaedalus::data::Edge _g39 = currFace->get_edge()->get_nextLeftEdge();		HX_STACK_VAR(_g39,"_g39");
					HX_STACK_LINE(364)
					currEdgeA = _g39;
					HX_STACK_LINE(365)
					::hxDaedalus::data::Edge _g40 = currFace->get_edge()->get_nextLeftEdge()->get_nextLeftEdge();		HX_STACK_VAR(_g40,"_g40");
					HX_STACK_LINE(365)
					currEdgeB = _g40;
				}
				else{
					HX_STACK_LINE(366)
					::hxDaedalus::data::Edge _g41 = currFace->get_edge()->get_nextLeftEdge();		HX_STACK_VAR(_g41,"_g41");
					struct _Function_5_1{
						inline static bool Block( ::hxDaedalus::data::Face &currFace,::hxDaedalus::data::Edge &faceFromEdge){
							HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","hxDaedalus/ai/AStar.hx",366,0x36e7cb38)
							{
								HX_STACK_LINE(366)
								::hxDaedalus::data::Edge _g42 = currFace->get_edge()->get_nextLeftEdge();		HX_STACK_VAR(_g42,"_g42");
								HX_STACK_LINE(366)
								::hxDaedalus::data::Edge _g43 = faceFromEdge->get_oppositeEdge();		HX_STACK_VAR(_g43,"_g43");
								HX_STACK_LINE(366)
								return (_g42 == _g43);
							}
							return null();
						}
					};
					HX_STACK_LINE(366)
					if (((  ((!(((_g41 == faceFromEdge))))) ? bool(_Function_5_1::Block(currFace,faceFromEdge)) : bool(true) ))){
						HX_STACK_LINE(368)
						::hxDaedalus::data::Edge _g44 = currFace->get_edge();		HX_STACK_VAR(_g44,"_g44");
						HX_STACK_LINE(368)
						currEdgeA = _g44;
						HX_STACK_LINE(369)
						::hxDaedalus::data::Edge _g45 = currFace->get_edge()->get_nextLeftEdge()->get_nextLeftEdge();		HX_STACK_VAR(_g45,"_g45");
						HX_STACK_LINE(369)
						currEdgeB = _g45;
					}
					else{
						HX_STACK_LINE(371)
						::hxDaedalus::data::Edge _g46 = currFace->get_edge();		HX_STACK_VAR(_g46,"_g46");
						HX_STACK_LINE(371)
						currEdgeA = _g46;
						HX_STACK_LINE(372)
						::hxDaedalus::data::Edge _g47 = currFace->get_edge()->get_nextLeftEdge();		HX_STACK_VAR(_g47,"_g47");
						HX_STACK_LINE(372)
						currEdgeB = _g47;
					}
				}
				HX_STACK_LINE(375)
				::hxDaedalus::data::Face _g48 = currEdgeA->get_leftFace();		HX_STACK_VAR(_g48,"_g48");
				HX_STACK_LINE(375)
				if (((_g48 == currFace))){
					HX_STACK_LINE(376)
					::hxDaedalus::data::Face _g49 = currEdgeA->get_rightFace();		HX_STACK_VAR(_g49,"_g49");
					HX_STACK_LINE(376)
					nextFaceA = _g49;
				}
				else{
					HX_STACK_LINE(378)
					::hxDaedalus::data::Face _g50 = currEdgeA->get_leftFace();		HX_STACK_VAR(_g50,"_g50");
					HX_STACK_LINE(378)
					nextFaceA = _g50;
				}
				HX_STACK_LINE(380)
				::hxDaedalus::data::Face _g51 = currEdgeB->get_leftFace();		HX_STACK_VAR(_g51,"_g51");
				HX_STACK_LINE(380)
				if (((_g51 == currFace))){
					HX_STACK_LINE(381)
					::hxDaedalus::data::Face _g52 = currEdgeB->get_rightFace();		HX_STACK_VAR(_g52,"_g52");
					HX_STACK_LINE(381)
					nextFaceB = _g52;
				}
				else{
					HX_STACK_LINE(383)
					::hxDaedalus::data::Face _g53 = currEdgeB->get_leftFace();		HX_STACK_VAR(_g53,"_g53");
					HX_STACK_LINE(383)
					nextFaceB = _g53;
				}
				struct _Function_4_2{
					inline static bool Block( ::hxDaedalus::data::Edge &currEdgeA,hx::ObjectPtr< ::hxDaedalus::ai::AStar_obj > __this,::hxDaedalus::data::Vertex &vC){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","hxDaedalus/ai/AStar.hx",387,0x36e7cb38)
						{
							HX_STACK_LINE(387)
							Float _g54 = ::hxDaedalus::data::math::Geom2D_obj::distanceSquaredVertexToEdge(vC,currEdgeA);		HX_STACK_VAR(_g54,"_g54");
							HX_STACK_LINE(387)
							return (_g54 < __this->diameterSquared);
						}
						return null();
					}
				};
				HX_STACK_LINE(387)
				if (((  ((!(facesDone->get(nextFaceA)))) ? bool(_Function_4_2::Block(currEdgeA,this,vC)) : bool(false) ))){
					HX_STACK_LINE(389)
					if ((currEdgeA->get_isConstrained())){
						HX_STACK_LINE(391)
						return false;
					}
					else{
						HX_STACK_LINE(394)
						vFaceToCheck->push(nextFaceA);
						HX_STACK_LINE(395)
						vFaceIsFromEdge->push(currEdgeA);
						HX_STACK_LINE(396)
						{
							HX_STACK_LINE(396)
							facesDone->set(nextFaceA,true);
							HX_STACK_LINE(396)
							true;
						}
					}
				}
				struct _Function_4_3{
					inline static bool Block( hx::ObjectPtr< ::hxDaedalus::ai::AStar_obj > __this,::hxDaedalus::data::Edge &currEdgeB,::hxDaedalus::data::Vertex &vC){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","hxDaedalus/ai/AStar.hx",400,0x36e7cb38)
						{
							HX_STACK_LINE(400)
							Float _g55 = ::hxDaedalus::data::math::Geom2D_obj::distanceSquaredVertexToEdge(vC,currEdgeB);		HX_STACK_VAR(_g55,"_g55");
							HX_STACK_LINE(400)
							return (_g55 < __this->diameterSquared);
						}
						return null();
					}
				};
				HX_STACK_LINE(400)
				if (((  ((!(facesDone->get(nextFaceB)))) ? bool(_Function_4_3::Block(this,currEdgeB,vC)) : bool(false) ))){
					HX_STACK_LINE(402)
					if ((currEdgeB->get_isConstrained())){
						HX_STACK_LINE(404)
						return false;
					}
					else{
						HX_STACK_LINE(407)
						vFaceToCheck->push(nextFaceB);
						HX_STACK_LINE(408)
						vFaceIsFromEdge->push(currEdgeB);
						HX_STACK_LINE(409)
						{
							HX_STACK_LINE(409)
							facesDone->set(nextFaceB,true);
							HX_STACK_LINE(409)
							true;
						}
					}
				}
			}
			HX_STACK_LINE(414)
			return true;
		}
	}
	HX_STACK_LINE(418)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC3(AStar_obj,isWalkableByRadius,return )


AStar_obj::AStar_obj()
{
}

void AStar_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(AStar);
	HX_MARK_MEMBER_NAME(_radius,"_radius");
	HX_MARK_MEMBER_NAME(_mesh,"_mesh");
	HX_MARK_MEMBER_NAME(closedFaces,"closedFaces");
	HX_MARK_MEMBER_NAME(sortedOpenedFaces,"sortedOpenedFaces");
	HX_MARK_MEMBER_NAME(openedFaces,"openedFaces");
	HX_MARK_MEMBER_NAME(entryEdges,"entryEdges");
	HX_MARK_MEMBER_NAME(entryX,"entryX");
	HX_MARK_MEMBER_NAME(entryY,"entryY");
	HX_MARK_MEMBER_NAME(scoreF,"scoreF");
	HX_MARK_MEMBER_NAME(scoreG,"scoreG");
	HX_MARK_MEMBER_NAME(scoreH,"scoreH");
	HX_MARK_MEMBER_NAME(predecessor,"predecessor");
	HX_MARK_MEMBER_NAME(iterEdge,"iterEdge");
	HX_MARK_MEMBER_NAME(radiusSquared,"radiusSquared");
	HX_MARK_MEMBER_NAME(diameter,"diameter");
	HX_MARK_MEMBER_NAME(diameterSquared,"diameterSquared");
	HX_MARK_MEMBER_NAME(fromFace,"fromFace");
	HX_MARK_MEMBER_NAME(toFace,"toFace");
	HX_MARK_MEMBER_NAME(curFace,"curFace");
	HX_MARK_END_CLASS();
}

void AStar_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_radius,"_radius");
	HX_VISIT_MEMBER_NAME(_mesh,"_mesh");
	HX_VISIT_MEMBER_NAME(closedFaces,"closedFaces");
	HX_VISIT_MEMBER_NAME(sortedOpenedFaces,"sortedOpenedFaces");
	HX_VISIT_MEMBER_NAME(openedFaces,"openedFaces");
	HX_VISIT_MEMBER_NAME(entryEdges,"entryEdges");
	HX_VISIT_MEMBER_NAME(entryX,"entryX");
	HX_VISIT_MEMBER_NAME(entryY,"entryY");
	HX_VISIT_MEMBER_NAME(scoreF,"scoreF");
	HX_VISIT_MEMBER_NAME(scoreG,"scoreG");
	HX_VISIT_MEMBER_NAME(scoreH,"scoreH");
	HX_VISIT_MEMBER_NAME(predecessor,"predecessor");
	HX_VISIT_MEMBER_NAME(iterEdge,"iterEdge");
	HX_VISIT_MEMBER_NAME(radiusSquared,"radiusSquared");
	HX_VISIT_MEMBER_NAME(diameter,"diameter");
	HX_VISIT_MEMBER_NAME(diameterSquared,"diameterSquared");
	HX_VISIT_MEMBER_NAME(fromFace,"fromFace");
	HX_VISIT_MEMBER_NAME(toFace,"toFace");
	HX_VISIT_MEMBER_NAME(curFace,"curFace");
}

Dynamic AStar_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"_mesh") ) { return _mesh; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"radius") ) { return get_radius(); }
		if (HX_FIELD_EQ(inName,"entryX") ) { return entryX; }
		if (HX_FIELD_EQ(inName,"entryY") ) { return entryY; }
		if (HX_FIELD_EQ(inName,"scoreF") ) { return scoreF; }
		if (HX_FIELD_EQ(inName,"scoreG") ) { return scoreG; }
		if (HX_FIELD_EQ(inName,"scoreH") ) { return scoreH; }
		if (HX_FIELD_EQ(inName,"toFace") ) { return toFace; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_radius") ) { return _radius; }
		if (HX_FIELD_EQ(inName,"curFace") ) { return curFace; }
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"iterEdge") ) { return iterEdge; }
		if (HX_FIELD_EQ(inName,"diameter") ) { return diameter; }
		if (HX_FIELD_EQ(inName,"fromFace") ) { return fromFace; }
		if (HX_FIELD_EQ(inName,"set_mesh") ) { return set_mesh_dyn(); }
		if (HX_FIELD_EQ(inName,"findPath") ) { return findPath_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"entryEdges") ) { return entryEdges; }
		if (HX_FIELD_EQ(inName,"get_radius") ) { return get_radius_dyn(); }
		if (HX_FIELD_EQ(inName,"set_radius") ) { return set_radius_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"closedFaces") ) { return closedFaces; }
		if (HX_FIELD_EQ(inName,"openedFaces") ) { return openedFaces; }
		if (HX_FIELD_EQ(inName,"predecessor") ) { return predecessor; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"sortingFaces") ) { return sortingFaces_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"radiusSquared") ) { return radiusSquared; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"diameterSquared") ) { return diameterSquared; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"sortedOpenedFaces") ) { return sortedOpenedFaces; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"isWalkableByRadius") ) { return isWalkableByRadius_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic AStar_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"mesh") ) { return set_mesh(inValue); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_mesh") ) { _mesh=inValue.Cast< ::hxDaedalus::data::Mesh >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"radius") ) { return set_radius(inValue); }
		if (HX_FIELD_EQ(inName,"entryX") ) { entryX=inValue.Cast< ::haxe::ds::ObjectMap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"entryY") ) { entryY=inValue.Cast< ::haxe::ds::ObjectMap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scoreF") ) { scoreF=inValue.Cast< ::haxe::ds::ObjectMap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scoreG") ) { scoreG=inValue.Cast< ::haxe::ds::ObjectMap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scoreH") ) { scoreH=inValue.Cast< ::haxe::ds::ObjectMap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"toFace") ) { toFace=inValue.Cast< ::hxDaedalus::data::Face >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_radius") ) { _radius=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"curFace") ) { curFace=inValue.Cast< ::hxDaedalus::data::Face >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"iterEdge") ) { iterEdge=inValue.Cast< ::hxDaedalus::iterators::FromFaceToInnerEdges >(); return inValue; }
		if (HX_FIELD_EQ(inName,"diameter") ) { diameter=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"fromFace") ) { fromFace=inValue.Cast< ::hxDaedalus::data::Face >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"entryEdges") ) { entryEdges=inValue.Cast< ::haxe::ds::ObjectMap >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"closedFaces") ) { closedFaces=inValue.Cast< ::haxe::ds::ObjectMap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"openedFaces") ) { openedFaces=inValue.Cast< ::haxe::ds::ObjectMap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"predecessor") ) { predecessor=inValue.Cast< ::haxe::ds::ObjectMap >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"radiusSquared") ) { radiusSquared=inValue.Cast< Float >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"diameterSquared") ) { diameterSquared=inValue.Cast< Float >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"sortedOpenedFaces") ) { sortedOpenedFaces=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void AStar_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("radius"));
	outFields->push(HX_CSTRING("_radius"));
	outFields->push(HX_CSTRING("mesh"));
	outFields->push(HX_CSTRING("_mesh"));
	outFields->push(HX_CSTRING("closedFaces"));
	outFields->push(HX_CSTRING("sortedOpenedFaces"));
	outFields->push(HX_CSTRING("openedFaces"));
	outFields->push(HX_CSTRING("entryEdges"));
	outFields->push(HX_CSTRING("entryX"));
	outFields->push(HX_CSTRING("entryY"));
	outFields->push(HX_CSTRING("scoreF"));
	outFields->push(HX_CSTRING("scoreG"));
	outFields->push(HX_CSTRING("scoreH"));
	outFields->push(HX_CSTRING("predecessor"));
	outFields->push(HX_CSTRING("iterEdge"));
	outFields->push(HX_CSTRING("radiusSquared"));
	outFields->push(HX_CSTRING("diameter"));
	outFields->push(HX_CSTRING("diameterSquared"));
	outFields->push(HX_CSTRING("fromFace"));
	outFields->push(HX_CSTRING("toFace"));
	outFields->push(HX_CSTRING("curFace"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsFloat,(int)offsetof(AStar_obj,_radius),HX_CSTRING("_radius")},
	{hx::fsObject /*::hxDaedalus::data::Mesh*/ ,(int)offsetof(AStar_obj,_mesh),HX_CSTRING("_mesh")},
	{hx::fsObject /*::haxe::ds::ObjectMap*/ ,(int)offsetof(AStar_obj,closedFaces),HX_CSTRING("closedFaces")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(AStar_obj,sortedOpenedFaces),HX_CSTRING("sortedOpenedFaces")},
	{hx::fsObject /*::haxe::ds::ObjectMap*/ ,(int)offsetof(AStar_obj,openedFaces),HX_CSTRING("openedFaces")},
	{hx::fsObject /*::haxe::ds::ObjectMap*/ ,(int)offsetof(AStar_obj,entryEdges),HX_CSTRING("entryEdges")},
	{hx::fsObject /*::haxe::ds::ObjectMap*/ ,(int)offsetof(AStar_obj,entryX),HX_CSTRING("entryX")},
	{hx::fsObject /*::haxe::ds::ObjectMap*/ ,(int)offsetof(AStar_obj,entryY),HX_CSTRING("entryY")},
	{hx::fsObject /*::haxe::ds::ObjectMap*/ ,(int)offsetof(AStar_obj,scoreF),HX_CSTRING("scoreF")},
	{hx::fsObject /*::haxe::ds::ObjectMap*/ ,(int)offsetof(AStar_obj,scoreG),HX_CSTRING("scoreG")},
	{hx::fsObject /*::haxe::ds::ObjectMap*/ ,(int)offsetof(AStar_obj,scoreH),HX_CSTRING("scoreH")},
	{hx::fsObject /*::haxe::ds::ObjectMap*/ ,(int)offsetof(AStar_obj,predecessor),HX_CSTRING("predecessor")},
	{hx::fsObject /*::hxDaedalus::iterators::FromFaceToInnerEdges*/ ,(int)offsetof(AStar_obj,iterEdge),HX_CSTRING("iterEdge")},
	{hx::fsFloat,(int)offsetof(AStar_obj,radiusSquared),HX_CSTRING("radiusSquared")},
	{hx::fsFloat,(int)offsetof(AStar_obj,diameter),HX_CSTRING("diameter")},
	{hx::fsFloat,(int)offsetof(AStar_obj,diameterSquared),HX_CSTRING("diameterSquared")},
	{hx::fsObject /*::hxDaedalus::data::Face*/ ,(int)offsetof(AStar_obj,fromFace),HX_CSTRING("fromFace")},
	{hx::fsObject /*::hxDaedalus::data::Face*/ ,(int)offsetof(AStar_obj,toFace),HX_CSTRING("toFace")},
	{hx::fsObject /*::hxDaedalus::data::Face*/ ,(int)offsetof(AStar_obj,curFace),HX_CSTRING("curFace")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("_radius"),
	HX_CSTRING("_mesh"),
	HX_CSTRING("closedFaces"),
	HX_CSTRING("sortedOpenedFaces"),
	HX_CSTRING("openedFaces"),
	HX_CSTRING("entryEdges"),
	HX_CSTRING("entryX"),
	HX_CSTRING("entryY"),
	HX_CSTRING("scoreF"),
	HX_CSTRING("scoreG"),
	HX_CSTRING("scoreH"),
	HX_CSTRING("predecessor"),
	HX_CSTRING("iterEdge"),
	HX_CSTRING("radiusSquared"),
	HX_CSTRING("diameter"),
	HX_CSTRING("diameterSquared"),
	HX_CSTRING("fromFace"),
	HX_CSTRING("toFace"),
	HX_CSTRING("curFace"),
	HX_CSTRING("dispose"),
	HX_CSTRING("get_radius"),
	HX_CSTRING("set_radius"),
	HX_CSTRING("set_mesh"),
	HX_CSTRING("findPath"),
	HX_CSTRING("sortingFaces"),
	HX_CSTRING("isWalkableByRadius"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(AStar_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(AStar_obj::__mClass,"__mClass");
};

#endif

Class AStar_obj::__mClass;

void AStar_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDaedalus.ai.AStar"), hx::TCanCast< AStar_obj> ,sStaticFields,sMemberFields,
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

void AStar_obj::__boot()
{
}

} // end namespace hxDaedalus
} // end namespace ai
