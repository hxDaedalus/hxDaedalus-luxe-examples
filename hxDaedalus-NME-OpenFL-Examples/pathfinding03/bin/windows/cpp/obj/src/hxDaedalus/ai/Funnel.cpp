#include <hxcpp.h>

#ifndef INCLUDED_IMap
#include <IMap.h>
#endif
#ifndef INCLUDED_haxe_ds_ObjectMap
#include <haxe/ds/ObjectMap.h>
#endif
#ifndef INCLUDED_hxDaedalus_ai_Funnel
#include <hxDaedalus/ai/Funnel.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_Edge
#include <hxDaedalus/data/Edge.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_Face
#include <hxDaedalus/data/Face.h>
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
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace hxDaedalus{
namespace ai{

Void Funnel_obj::__construct()
{
HX_STACK_FRAME("hxDaedalus.ai.Funnel","new",0x3a129775,"hxDaedalus.ai.Funnel.new","hxDaedalus/ai/Funnel.hx",17,0x7110c2fb)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(49)
	this->_currPoolPointsIndex = (int)0;
	HX_STACK_LINE(47)
	this->_poolPointsSize = (int)3000;
	HX_STACK_LINE(24)
	this->_numSamplesCircle = (int)16;
	HX_STACK_LINE(23)
	this->_radiusSquared = (int)0;
	HX_STACK_LINE(22)
	this->_radius = (int)0;
	HX_STACK_LINE(35)
	Array< ::Dynamic > _g = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(35)
	this->_poolPoints = _g;
	HX_STACK_LINE(36)
	{
		HX_STACK_LINE(36)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(36)
		int _g2 = this->_poolPointsSize;		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(36)
		while((true)){
			HX_STACK_LINE(36)
			if ((!(((_g1 < _g2))))){
				HX_STACK_LINE(36)
				break;
			}
			HX_STACK_LINE(36)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(37)
			::hxDaedalus::data::math::Point2D _g11 = ::hxDaedalus::data::math::Point2D_obj::__new(null(),null());		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(37)
			this->_poolPoints->push(_g11);
		}
	}
}
;
	return null();
}

//Funnel_obj::~Funnel_obj() { }

Dynamic Funnel_obj::__CreateEmpty() { return  new Funnel_obj; }
hx::ObjectPtr< Funnel_obj > Funnel_obj::__new()
{  hx::ObjectPtr< Funnel_obj > result = new Funnel_obj();
	result->__construct();
	return result;}

Dynamic Funnel_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Funnel_obj > result = new Funnel_obj();
	result->__construct();
	return result;}

Void Funnel_obj::dispose( ){
{
		HX_STACK_FRAME("hxDaedalus.ai.Funnel","dispose",0x80e4f634,"hxDaedalus.ai.Funnel.dispose","hxDaedalus/ai/Funnel.hx",43,0x7110c2fb)
		HX_STACK_THIS(this)
		HX_STACK_LINE(43)
		this->_sampleCircle = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Funnel_obj,dispose,(void))

::hxDaedalus::data::math::Point2D Funnel_obj::getPoint( hx::Null< Float >  __o_x,hx::Null< Float >  __o_y){
Float x = __o_x.Default(0);
Float y = __o_y.Default(0);
	HX_STACK_FRAME("hxDaedalus.ai.Funnel","getPoint",0x463530a5,"hxDaedalus.ai.Funnel.getPoint","hxDaedalus/ai/Funnel.hx",52,0x7110c2fb)
	HX_STACK_THIS(this)
	HX_STACK_ARG(x,"x")
	HX_STACK_ARG(y,"y")
{
		HX_STACK_LINE(53)
		this->__point = this->_poolPoints->__get(this->_currPoolPointsIndex).StaticCast< ::hxDaedalus::data::math::Point2D >();
		HX_STACK_LINE(54)
		this->__point->setXY(x,y);
		HX_STACK_LINE(56)
		(this->_currPoolPointsIndex)++;
		HX_STACK_LINE(57)
		if (((this->_currPoolPointsIndex == this->_poolPointsSize))){
			HX_STACK_LINE(59)
			::hxDaedalus::data::math::Point2D _g = ::hxDaedalus::data::math::Point2D_obj::__new(null(),null());		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(59)
			this->_poolPoints->push(_g);
			HX_STACK_LINE(60)
			(this->_poolPointsSize)++;
		}
		HX_STACK_LINE(63)
		return this->__point;
	}
}


HX_DEFINE_DYNAMIC_FUNC2(Funnel_obj,getPoint,return )

::hxDaedalus::data::math::Point2D Funnel_obj::getCopyPoint( ::hxDaedalus::data::math::Point2D pointToCopy){
	HX_STACK_FRAME("hxDaedalus.ai.Funnel","getCopyPoint",0xa3ada330,"hxDaedalus.ai.Funnel.getCopyPoint","hxDaedalus/ai/Funnel.hx",67,0x7110c2fb)
	HX_STACK_THIS(this)
	HX_STACK_ARG(pointToCopy,"pointToCopy")
	HX_STACK_LINE(67)
	return this->getPoint(pointToCopy->x,pointToCopy->y);
}


HX_DEFINE_DYNAMIC_FUNC1(Funnel_obj,getCopyPoint,return )

Float Funnel_obj::get_radius( ){
	HX_STACK_FRAME("hxDaedalus.ai.Funnel","get_radius",0x2359b5a6,"hxDaedalus.ai.Funnel.get_radius","hxDaedalus/ai/Funnel.hx",72,0x7110c2fb)
	HX_STACK_THIS(this)
	HX_STACK_LINE(72)
	return this->_radius;
}


HX_DEFINE_DYNAMIC_FUNC0(Funnel_obj,get_radius,return )

Float Funnel_obj::set_radius( Float value){
	HX_STACK_FRAME("hxDaedalus.ai.Funnel","set_radius",0x26d7541a,"hxDaedalus.ai.Funnel.set_radius","hxDaedalus/ai/Funnel.hx",76,0x7110c2fb)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(77)
	Float _g = ::Math_obj::max((int)0,value);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(77)
	this->_radius = _g;
	HX_STACK_LINE(78)
	this->_radiusSquared = (this->_radius * this->_radius);
	HX_STACK_LINE(79)
	Array< ::Dynamic > _g1 = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(79)
	this->_sampleCircle = _g1;
	HX_STACK_LINE(80)
	Float _g2 = this->get_radius();		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(80)
	if (((_g2 == (int)0))){
		HX_STACK_LINE(80)
		return (int)0;
	}
	HX_STACK_LINE(81)
	{
		HX_STACK_LINE(81)
		int _g11 = (int)0;		HX_STACK_VAR(_g11,"_g11");
		HX_STACK_LINE(81)
		int _g3 = this->_numSamplesCircle;		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(81)
		while((true)){
			HX_STACK_LINE(81)
			if ((!(((_g11 < _g3))))){
				HX_STACK_LINE(81)
				break;
			}
			HX_STACK_LINE(81)
			int i = (_g11)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(82)
			Float _g31 = ::Math_obj::cos((Float((((int)-2 * ::Math_obj::PI) * i)) / Float(this->_numSamplesCircle)));		HX_STACK_VAR(_g31,"_g31");
			HX_STACK_LINE(82)
			Float _g4 = (this->_radius * _g31);		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(83)
			Float _g5 = ::Math_obj::sin((Float((((int)-2 * ::Math_obj::PI) * i)) / Float(this->_numSamplesCircle)));		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(83)
			Float _g6 = (this->_radius * _g5);		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(82)
			::hxDaedalus::data::math::Point2D _g7 = ::hxDaedalus::data::math::Point2D_obj::__new(_g4,_g6);		HX_STACK_VAR(_g7,"_g7");
			HX_STACK_LINE(82)
			this->_sampleCircle->push(_g7);
		}
	}
	HX_STACK_LINE(87)
	this->_sampleCircleDistanceSquared = ((((this->_sampleCircle->__get((int)0).StaticCast< ::hxDaedalus::data::math::Point2D >()->x - this->_sampleCircle->__get((int)1).StaticCast< ::hxDaedalus::data::math::Point2D >()->x)) * ((this->_sampleCircle->__get((int)0).StaticCast< ::hxDaedalus::data::math::Point2D >()->x - this->_sampleCircle->__get((int)1).StaticCast< ::hxDaedalus::data::math::Point2D >()->x))) + (((this->_sampleCircle->__get((int)0).StaticCast< ::hxDaedalus::data::math::Point2D >()->y - this->_sampleCircle->__get((int)1).StaticCast< ::hxDaedalus::data::math::Point2D >()->y)) * ((this->_sampleCircle->__get((int)0).StaticCast< ::hxDaedalus::data::math::Point2D >()->y - this->_sampleCircle->__get((int)1).StaticCast< ::hxDaedalus::data::math::Point2D >()->y))));
	HX_STACK_LINE(88)
	return this->_radius;
}


HX_DEFINE_DYNAMIC_FUNC1(Funnel_obj,set_radius,return )

Void Funnel_obj::findPath( Float fromX,Float fromY,Float toX,Float toY,Array< ::Dynamic > listFaces,Array< ::Dynamic > listEdges,Array< Float > resultPath){
{
		HX_STACK_FRAME("hxDaedalus.ai.Funnel","findPath",0xbcb45f49,"hxDaedalus.ai.Funnel.findPath","hxDaedalus/ai/Funnel.hx",95,0x7110c2fb)
		HX_STACK_THIS(this)
		HX_STACK_ARG(fromX,"fromX")
		HX_STACK_ARG(fromY,"fromY")
		HX_STACK_ARG(toX,"toX")
		HX_STACK_ARG(toY,"toY")
		HX_STACK_ARG(listFaces,"listFaces")
		HX_STACK_ARG(listEdges,"listEdges")
		HX_STACK_ARG(resultPath,"resultPath")
		HX_STACK_LINE(96)
		this->_currPoolPointsIndex = (int)0;
		HX_STACK_LINE(99)
		if (((this->_radius > (int)0))){
			HX_STACK_LINE(101)
			::hxDaedalus::data::Face checkFace = listFaces->__get((int)0).StaticCast< ::hxDaedalus::data::Face >();		HX_STACK_VAR(checkFace,"checkFace");
			HX_STACK_LINE(102)
			Float distanceSquared;		HX_STACK_VAR(distanceSquared,"distanceSquared");
			HX_STACK_LINE(103)
			Float distance;		HX_STACK_VAR(distance,"distance");
			HX_STACK_LINE(104)
			::hxDaedalus::data::math::Point2D p1;		HX_STACK_VAR(p1,"p1");
			HX_STACK_LINE(105)
			::hxDaedalus::data::math::Point2D p2;		HX_STACK_VAR(p2,"p2");
			HX_STACK_LINE(106)
			::hxDaedalus::data::math::Point2D p3;		HX_STACK_VAR(p3,"p3");
			HX_STACK_LINE(107)
			::hxDaedalus::data::math::Point2D _g = checkFace->get_edge()->get_originVertex()->get_pos();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(107)
			p1 = _g;
			HX_STACK_LINE(108)
			::hxDaedalus::data::math::Point2D _g1 = checkFace->get_edge()->get_destinationVertex()->get_pos();		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(108)
			p2 = _g1;
			HX_STACK_LINE(109)
			::hxDaedalus::data::math::Point2D _g2 = checkFace->get_edge()->get_nextLeftEdge()->get_destinationVertex()->get_pos();		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(109)
			p3 = _g2;
			HX_STACK_LINE(110)
			distanceSquared = ((((p1->x - fromX)) * ((p1->x - fromX))) + (((p1->y - fromY)) * ((p1->y - fromY))));
			HX_STACK_LINE(111)
			if (((distanceSquared <= this->_radiusSquared))){
				HX_STACK_LINE(113)
				Float _g3 = ::Math_obj::sqrt(distanceSquared);		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(113)
				distance = _g3;
				HX_STACK_LINE(114)
				fromX = (((this->_radius * 1.01) * ((Float(((fromX - p1->x))) / Float(distance)))) + p1->x);
				HX_STACK_LINE(115)
				fromY = (((this->_radius * 1.01) * ((Float(((fromY - p1->y))) / Float(distance)))) + p1->y);
			}
			else{
				HX_STACK_LINE(119)
				distanceSquared = ((((p2->x - fromX)) * ((p2->x - fromX))) + (((p2->y - fromY)) * ((p2->y - fromY))));
				HX_STACK_LINE(120)
				if (((distanceSquared <= this->_radiusSquared))){
					HX_STACK_LINE(122)
					Float _g4 = ::Math_obj::sqrt(distanceSquared);		HX_STACK_VAR(_g4,"_g4");
					HX_STACK_LINE(122)
					distance = _g4;
					HX_STACK_LINE(123)
					fromX = (((this->_radius * 1.01) * ((Float(((fromX - p2->x))) / Float(distance)))) + p2->x);
					HX_STACK_LINE(124)
					fromY = (((this->_radius * 1.01) * ((Float(((fromY - p2->y))) / Float(distance)))) + p2->y);
				}
				else{
					HX_STACK_LINE(128)
					distanceSquared = ((((p3->x - fromX)) * ((p3->x - fromX))) + (((p3->y - fromY)) * ((p3->y - fromY))));
					HX_STACK_LINE(129)
					if (((distanceSquared <= this->_radiusSquared))){
						HX_STACK_LINE(131)
						Float _g5 = ::Math_obj::sqrt(distanceSquared);		HX_STACK_VAR(_g5,"_g5");
						HX_STACK_LINE(131)
						distance = _g5;
						HX_STACK_LINE(132)
						fromX = (((this->_radius * 1.01) * ((Float(((fromX - p3->x))) / Float(distance)))) + p3->x);
						HX_STACK_LINE(133)
						fromY = (((this->_radius * 1.01) * ((Float(((fromY - p3->y))) / Float(distance)))) + p3->y);
					}
				}
			}
			HX_STACK_LINE(138)
			checkFace = listFaces->__get((listFaces->length - (int)1)).StaticCast< ::hxDaedalus::data::Face >();
			HX_STACK_LINE(139)
			::hxDaedalus::data::math::Point2D _g6 = checkFace->get_edge()->get_originVertex()->get_pos();		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(139)
			p1 = _g6;
			HX_STACK_LINE(140)
			::hxDaedalus::data::math::Point2D _g7 = checkFace->get_edge()->get_destinationVertex()->get_pos();		HX_STACK_VAR(_g7,"_g7");
			HX_STACK_LINE(140)
			p2 = _g7;
			HX_STACK_LINE(141)
			::hxDaedalus::data::math::Point2D _g8 = checkFace->get_edge()->get_nextLeftEdge()->get_destinationVertex()->get_pos();		HX_STACK_VAR(_g8,"_g8");
			HX_STACK_LINE(141)
			p3 = _g8;
			HX_STACK_LINE(142)
			distanceSquared = ((((p1->x - toX)) * ((p1->x - toX))) + (((p1->y - toY)) * ((p1->y - toY))));
			HX_STACK_LINE(143)
			if (((distanceSquared <= this->_radiusSquared))){
				HX_STACK_LINE(145)
				Float _g9 = ::Math_obj::sqrt(distanceSquared);		HX_STACK_VAR(_g9,"_g9");
				HX_STACK_LINE(145)
				distance = _g9;
				HX_STACK_LINE(146)
				toX = (((this->_radius * 1.01) * ((Float(((toX - p1->x))) / Float(distance)))) + p1->x);
				HX_STACK_LINE(147)
				toY = (((this->_radius * 1.01) * ((Float(((toY - p1->y))) / Float(distance)))) + p1->y);
			}
			else{
				HX_STACK_LINE(151)
				distanceSquared = ((((p2->x - toX)) * ((p2->x - toX))) + (((p2->y - toY)) * ((p2->y - toY))));
				HX_STACK_LINE(152)
				if (((distanceSquared <= this->_radiusSquared))){
					HX_STACK_LINE(154)
					Float _g10 = ::Math_obj::sqrt(distanceSquared);		HX_STACK_VAR(_g10,"_g10");
					HX_STACK_LINE(154)
					distance = _g10;
					HX_STACK_LINE(155)
					toX = (((this->_radius * 1.01) * ((Float(((toX - p2->x))) / Float(distance)))) + p2->x);
					HX_STACK_LINE(156)
					toY = (((this->_radius * 1.01) * ((Float(((toY - p2->y))) / Float(distance)))) + p2->y);
				}
				else{
					HX_STACK_LINE(160)
					distanceSquared = ((((p3->x - toX)) * ((p3->x - toX))) + (((p3->y - toY)) * ((p3->y - toY))));
					HX_STACK_LINE(161)
					if (((distanceSquared <= this->_radiusSquared))){
						HX_STACK_LINE(163)
						Float _g11 = ::Math_obj::sqrt(distanceSquared);		HX_STACK_VAR(_g11,"_g11");
						HX_STACK_LINE(163)
						distance = _g11;
						HX_STACK_LINE(164)
						toX = (((this->_radius * 1.01) * ((Float(((toX - p3->x))) / Float(distance)))) + p3->x);
						HX_STACK_LINE(165)
						toY = (((this->_radius * 1.01) * ((Float(((toY - p3->y))) / Float(distance)))) + p3->y);
					}
				}
			}
		}
		HX_STACK_LINE(175)
		::hxDaedalus::data::math::Point2D startPoint;		HX_STACK_VAR(startPoint,"startPoint");
		HX_STACK_LINE(176)
		::hxDaedalus::data::math::Point2D endPoint;		HX_STACK_VAR(endPoint,"endPoint");
		HX_STACK_LINE(177)
		::hxDaedalus::data::math::Point2D _g12 = ::hxDaedalus::data::math::Point2D_obj::__new(fromX,fromY);		HX_STACK_VAR(_g12,"_g12");
		HX_STACK_LINE(177)
		startPoint = _g12;
		HX_STACK_LINE(178)
		::hxDaedalus::data::math::Point2D _g13 = ::hxDaedalus::data::math::Point2D_obj::__new(toX,toY);		HX_STACK_VAR(_g13,"_g13");
		HX_STACK_LINE(178)
		endPoint = _g13;
		HX_STACK_LINE(180)
		if (((listFaces->length == (int)1))){
			HX_STACK_LINE(182)
			resultPath->push(startPoint->x);
			HX_STACK_LINE(183)
			resultPath->push(startPoint->y);
			HX_STACK_LINE(184)
			resultPath->push(endPoint->x);
			HX_STACK_LINE(185)
			resultPath->push(endPoint->y);
			HX_STACK_LINE(186)
			return null();
		}
		HX_STACK_LINE(191)
		int i;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(192)
		int j;		HX_STACK_VAR(j,"j");
		HX_STACK_LINE(193)
		int k;		HX_STACK_VAR(k,"k");
		HX_STACK_LINE(194)
		::hxDaedalus::data::Edge currEdge = null();		HX_STACK_VAR(currEdge,"currEdge");
		HX_STACK_LINE(195)
		::hxDaedalus::data::Vertex currVertex = null();		HX_STACK_VAR(currVertex,"currVertex");
		HX_STACK_LINE(196)
		int direction;		HX_STACK_VAR(direction,"direction");
		HX_STACK_LINE(203)
		{
			HX_STACK_LINE(203)
			::hxDaedalus::data::math::Intersection _g = ::hxDaedalus::data::math::Geom2D_obj::isInFace(fromX,fromY,listFaces->__get((int)0).StaticCast< ::hxDaedalus::data::Face >());		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(203)
			switch( (int)(_g->__Index())){
				case (int)1: {
					HX_STACK_LINE(203)
					::hxDaedalus::data::Edge edge = (::hxDaedalus::data::math::Intersection(_g))->__Param(0);		HX_STACK_VAR(edge,"edge");
					HX_STACK_LINE(206)
					if (((listEdges->__get((int)0).StaticCast< ::hxDaedalus::data::Edge >() == edge))){
						HX_STACK_LINE(208)
						listEdges->shift().StaticCast< ::hxDaedalus::data::Edge >();
						HX_STACK_LINE(209)
						listFaces->shift().StaticCast< ::hxDaedalus::data::Face >();
					}
				}
				;break;
				default: {
				}
			}
		}
		HX_STACK_LINE(218)
		Array< ::Dynamic > funnelLeft = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(funnelLeft,"funnelLeft");
		HX_STACK_LINE(219)
		Array< ::Dynamic > funnelRight = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(funnelRight,"funnelRight");
		HX_STACK_LINE(220)
		funnelLeft->push(startPoint);
		HX_STACK_LINE(221)
		funnelRight->push(startPoint);
		HX_STACK_LINE(224)
		::haxe::ds::ObjectMap verticesDoneSide = ::haxe::ds::ObjectMap_obj::__new();		HX_STACK_VAR(verticesDoneSide,"verticesDoneSide");
		HX_STACK_LINE(227)
		Array< ::Dynamic > pointsList = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(pointsList,"pointsList");
		HX_STACK_LINE(228)
		::haxe::ds::ObjectMap pointSides = ::haxe::ds::ObjectMap_obj::__new();		HX_STACK_VAR(pointSides,"pointSides");
		HX_STACK_LINE(230)
		::haxe::ds::ObjectMap pointSuccessor = ::haxe::ds::ObjectMap_obj::__new();		HX_STACK_VAR(pointSuccessor,"pointSuccessor");
		HX_STACK_LINE(232)
		{
			HX_STACK_LINE(232)
			pointSides->set(startPoint,(int)0);
			HX_STACK_LINE(232)
			(int)0;
		}
		HX_STACK_LINE(234)
		currEdge = listEdges->__get((int)0).StaticCast< ::hxDaedalus::data::Edge >();
		HX_STACK_LINE(235)
		int relativPos = ::hxDaedalus::data::math::Geom2D_obj::getRelativePosition2(fromX,fromY,currEdge);		HX_STACK_VAR(relativPos,"relativPos");
		HX_STACK_LINE(236)
		::hxDaedalus::data::math::Point2D prevPoint;		HX_STACK_VAR(prevPoint,"prevPoint");
		HX_STACK_LINE(237)
		::hxDaedalus::data::math::Point2D newPointA;		HX_STACK_VAR(newPointA,"newPointA");
		HX_STACK_LINE(238)
		::hxDaedalus::data::math::Point2D newPointB;		HX_STACK_VAR(newPointB,"newPointB");
		HX_STACK_LINE(239)
		::hxDaedalus::data::math::Point2D _g14 = currEdge->get_destinationVertex()->get_pos();		HX_STACK_VAR(_g14,"_g14");
		HX_STACK_LINE(239)
		::hxDaedalus::data::math::Point2D _g15 = this->getCopyPoint(_g14);		HX_STACK_VAR(_g15,"_g15");
		HX_STACK_LINE(239)
		newPointA = _g15;
		HX_STACK_LINE(240)
		::hxDaedalus::data::math::Point2D _g16 = currEdge->get_originVertex()->get_pos();		HX_STACK_VAR(_g16,"_g16");
		HX_STACK_LINE(240)
		::hxDaedalus::data::math::Point2D _g17 = this->getCopyPoint(_g16);		HX_STACK_VAR(_g17,"_g17");
		HX_STACK_LINE(240)
		newPointB = _g17;
		HX_STACK_LINE(242)
		pointsList->push(newPointA);
		HX_STACK_LINE(243)
		pointsList->push(newPointB);
		HX_STACK_LINE(244)
		{
			HX_STACK_LINE(244)
			pointSuccessor->set(startPoint,newPointA);
			HX_STACK_LINE(244)
			newPointA;
		}
		HX_STACK_LINE(245)
		{
			HX_STACK_LINE(245)
			pointSuccessor->set(newPointA,newPointB);
			HX_STACK_LINE(245)
			newPointB;
		}
		HX_STACK_LINE(246)
		prevPoint = newPointB;
		HX_STACK_LINE(247)
		if (((relativPos == (int)1))){
			HX_STACK_LINE(248)
			{
				HX_STACK_LINE(248)
				pointSides->set(newPointA,(int)1);
				HX_STACK_LINE(248)
				(int)1;
			}
			HX_STACK_LINE(249)
			{
				HX_STACK_LINE(249)
				pointSides->set(newPointB,(int)-1);
				HX_STACK_LINE(249)
				(int)-1;
			}
			HX_STACK_LINE(250)
			{
				HX_STACK_LINE(250)
				::hxDaedalus::data::Vertex k1 = currEdge->get_destinationVertex();		HX_STACK_VAR(k1,"k1");
				HX_STACK_LINE(250)
				verticesDoneSide->set(k1,(int)1);
				HX_STACK_LINE(250)
				(int)1;
			}
			HX_STACK_LINE(251)
			{
				HX_STACK_LINE(251)
				::hxDaedalus::data::Vertex k1 = currEdge->get_originVertex();		HX_STACK_VAR(k1,"k1");
				HX_STACK_LINE(251)
				verticesDoneSide->set(k1,(int)-1);
				HX_STACK_LINE(251)
				(int)-1;
			}
		}
		else{
			HX_STACK_LINE(252)
			if (((relativPos == (int)-1))){
				HX_STACK_LINE(253)
				{
					HX_STACK_LINE(253)
					pointSides->set(newPointA,(int)-1);
					HX_STACK_LINE(253)
					(int)-1;
				}
				HX_STACK_LINE(254)
				{
					HX_STACK_LINE(254)
					pointSides->set(newPointB,(int)1);
					HX_STACK_LINE(254)
					(int)1;
				}
				HX_STACK_LINE(255)
				{
					HX_STACK_LINE(255)
					::hxDaedalus::data::Vertex k1 = currEdge->get_destinationVertex();		HX_STACK_VAR(k1,"k1");
					HX_STACK_LINE(255)
					verticesDoneSide->set(k1,(int)-1);
					HX_STACK_LINE(255)
					(int)-1;
				}
				HX_STACK_LINE(256)
				{
					HX_STACK_LINE(256)
					::hxDaedalus::data::Vertex k1 = currEdge->get_originVertex();		HX_STACK_VAR(k1,"k1");
					HX_STACK_LINE(256)
					verticesDoneSide->set(k1,(int)1);
					HX_STACK_LINE(256)
					(int)1;
				}
			}
		}
		HX_STACK_LINE(261)
		::hxDaedalus::data::Vertex fromVertex = listEdges->__get((int)0).StaticCast< ::hxDaedalus::data::Edge >()->get_originVertex();		HX_STACK_VAR(fromVertex,"fromVertex");
		HX_STACK_LINE(262)
		::hxDaedalus::data::Vertex fromFromVertex = listEdges->__get((int)0).StaticCast< ::hxDaedalus::data::Edge >()->get_destinationVertex();		HX_STACK_VAR(fromFromVertex,"fromFromVertex");
		HX_STACK_LINE(263)
		{
			HX_STACK_LINE(263)
			int _g1 = (int)1;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(263)
			int _g = listEdges->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(263)
			while((true)){
				HX_STACK_LINE(263)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(263)
					break;
				}
				HX_STACK_LINE(263)
				int i1 = (_g1)++;		HX_STACK_VAR(i1,"i1");
				HX_STACK_LINE(265)
				currEdge = listEdges->__get(i1).StaticCast< ::hxDaedalus::data::Edge >();
				HX_STACK_LINE(266)
				::hxDaedalus::data::Vertex _g18 = currEdge->get_originVertex();		HX_STACK_VAR(_g18,"_g18");
				HX_STACK_LINE(266)
				if (((_g18 == fromVertex))){
					HX_STACK_LINE(268)
					::hxDaedalus::data::Vertex _g19 = currEdge->get_destinationVertex();		HX_STACK_VAR(_g19,"_g19");
					HX_STACK_LINE(268)
					currVertex = _g19;
				}
				else{
					HX_STACK_LINE(270)
					::hxDaedalus::data::Vertex _g20 = currEdge->get_destinationVertex();		HX_STACK_VAR(_g20,"_g20");
					HX_STACK_LINE(270)
					if (((_g20 == fromVertex))){
						HX_STACK_LINE(272)
						::hxDaedalus::data::Vertex _g21 = currEdge->get_originVertex();		HX_STACK_VAR(_g21,"_g21");
						HX_STACK_LINE(272)
						currVertex = _g21;
					}
					else{
						HX_STACK_LINE(274)
						::hxDaedalus::data::Vertex _g22 = currEdge->get_originVertex();		HX_STACK_VAR(_g22,"_g22");
						HX_STACK_LINE(274)
						if (((_g22 == fromFromVertex))){
							HX_STACK_LINE(276)
							::hxDaedalus::data::Vertex _g23 = currEdge->get_destinationVertex();		HX_STACK_VAR(_g23,"_g23");
							HX_STACK_LINE(276)
							currVertex = _g23;
							HX_STACK_LINE(277)
							fromVertex = fromFromVertex;
						}
						else{
							HX_STACK_LINE(279)
							::hxDaedalus::data::Vertex _g24 = currEdge->get_destinationVertex();		HX_STACK_VAR(_g24,"_g24");
							HX_STACK_LINE(279)
							if (((_g24 == fromFromVertex))){
								HX_STACK_LINE(281)
								::hxDaedalus::data::Vertex _g25 = currEdge->get_originVertex();		HX_STACK_VAR(_g25,"_g25");
								HX_STACK_LINE(281)
								currVertex = _g25;
								HX_STACK_LINE(282)
								fromVertex = fromFromVertex;
							}
							else{
								HX_STACK_LINE(286)
								Dynamic();
							}
						}
					}
				}
				HX_STACK_LINE(289)
				::hxDaedalus::data::math::Point2D _g26 = currVertex->get_pos();		HX_STACK_VAR(_g26,"_g26");
				HX_STACK_LINE(289)
				::hxDaedalus::data::math::Point2D _g27 = this->getCopyPoint(_g26);		HX_STACK_VAR(_g27,"_g27");
				HX_STACK_LINE(289)
				newPointA = _g27;
				HX_STACK_LINE(290)
				pointsList->push(newPointA);
				HX_STACK_LINE(291)
				int _g28 = -(verticesDoneSide->get(fromVertex));		HX_STACK_VAR(_g28,"_g28");
				HX_STACK_LINE(291)
				direction = _g28;
				HX_STACK_LINE(292)
				{
					HX_STACK_LINE(292)
					pointSides->set(newPointA,direction);
					HX_STACK_LINE(292)
					direction;
				}
				HX_STACK_LINE(293)
				{
					HX_STACK_LINE(293)
					pointSuccessor->set(prevPoint,newPointA);
					HX_STACK_LINE(293)
					newPointA;
				}
				HX_STACK_LINE(294)
				{
					HX_STACK_LINE(294)
					verticesDoneSide->set(currVertex,direction);
					HX_STACK_LINE(294)
					direction;
				}
				HX_STACK_LINE(295)
				prevPoint = newPointA;
				HX_STACK_LINE(296)
				fromFromVertex = fromVertex;
				HX_STACK_LINE(297)
				fromVertex = currVertex;
			}
		}
		HX_STACK_LINE(300)
		{
			HX_STACK_LINE(300)
			pointSuccessor->set(prevPoint,endPoint);
			HX_STACK_LINE(300)
			endPoint;
		}
		HX_STACK_LINE(301)
		{
			HX_STACK_LINE(301)
			pointSides->set(endPoint,(int)0);
			HX_STACK_LINE(301)
			(int)0;
		}
		HX_STACK_LINE(326)
		Array< ::Dynamic > pathPoints = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(pathPoints,"pathPoints");
		HX_STACK_LINE(327)
		::haxe::ds::ObjectMap pathSides = ::haxe::ds::ObjectMap_obj::__new();		HX_STACK_VAR(pathSides,"pathSides");
		HX_STACK_LINE(328)
		pathPoints->push(startPoint);
		HX_STACK_LINE(329)
		{
			HX_STACK_LINE(329)
			pathSides->set(startPoint,(int)0);
			HX_STACK_LINE(329)
			(int)0;
		}
		HX_STACK_LINE(332)
		::hxDaedalus::data::math::Point2D currPos;		HX_STACK_VAR(currPos,"currPos");
		HX_STACK_LINE(333)
		{
			HX_STACK_LINE(333)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(333)
			int _g = pointsList->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(333)
			while((true)){
				HX_STACK_LINE(333)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(333)
					break;
				}
				HX_STACK_LINE(333)
				int i1 = (_g1)++;		HX_STACK_VAR(i1,"i1");
				HX_STACK_LINE(334)
				currPos = pointsList->__get(i1).StaticCast< ::hxDaedalus::data::math::Point2D >();
				HX_STACK_LINE(337)
				Dynamic _g29 = pointSides->get(currPos);		HX_STACK_VAR(_g29,"_g29");
				HX_STACK_LINE(337)
				if (((_g29 == (int)-1))){
					HX_STACK_LINE(340)
					j = (funnelLeft->length - (int)2);
					HX_STACK_LINE(341)
					while((true)){
						HX_STACK_LINE(341)
						if ((!(((j >= (int)0))))){
							HX_STACK_LINE(341)
							break;
						}
						HX_STACK_LINE(342)
						int _g30 = ::hxDaedalus::data::math::Geom2D_obj::getDirection(funnelLeft->__get(j).StaticCast< ::hxDaedalus::data::math::Point2D >()->x,funnelLeft->__get(j).StaticCast< ::hxDaedalus::data::math::Point2D >()->y,funnelLeft->__get((j + (int)1)).StaticCast< ::hxDaedalus::data::math::Point2D >()->x,funnelLeft->__get((j + (int)1)).StaticCast< ::hxDaedalus::data::math::Point2D >()->y,currPos->x,currPos->y);		HX_STACK_VAR(_g30,"_g30");
						HX_STACK_LINE(342)
						direction = _g30;
						HX_STACK_LINE(343)
						if (((direction != (int)-1))){
							HX_STACK_LINE(347)
							funnelLeft->shift().StaticCast< ::hxDaedalus::data::math::Point2D >();
							HX_STACK_LINE(348)
							{
								HX_STACK_LINE(348)
								int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
								HX_STACK_LINE(348)
								while((true)){
									HX_STACK_LINE(348)
									if ((!(((_g2 < j))))){
										HX_STACK_LINE(348)
										break;
									}
									HX_STACK_LINE(348)
									int k1 = (_g2)++;		HX_STACK_VAR(k1,"k1");
									HX_STACK_LINE(349)
									pathPoints->push(funnelLeft->__get((int)0).StaticCast< ::hxDaedalus::data::math::Point2D >());
									HX_STACK_LINE(350)
									{
										HX_STACK_LINE(350)
										pathSides->set(funnelLeft->__get((int)0).StaticCast< ::hxDaedalus::data::math::Point2D >(),(int)1);
										HX_STACK_LINE(350)
										(int)1;
									}
									HX_STACK_LINE(351)
									funnelLeft->shift().StaticCast< ::hxDaedalus::data::math::Point2D >();
								}
							}
							HX_STACK_LINE(353)
							pathPoints->push(funnelLeft->__get((int)0).StaticCast< ::hxDaedalus::data::math::Point2D >());
							HX_STACK_LINE(354)
							{
								HX_STACK_LINE(354)
								pathSides->set(funnelLeft->__get((int)0).StaticCast< ::hxDaedalus::data::math::Point2D >(),(int)1);
								HX_STACK_LINE(354)
								(int)1;
							}
							HX_STACK_LINE(355)
							funnelRight->splice((int)0,funnelRight->length);
							HX_STACK_LINE(356)
							funnelRight->push(funnelLeft->__get((int)0).StaticCast< ::hxDaedalus::data::math::Point2D >());
							HX_STACK_LINE(357)
							funnelRight->push(currPos);
							HX_STACK_LINE(358)
							break;
						}
						HX_STACK_LINE(360)
						(j)--;
					}
					HX_STACK_LINE(363)
					funnelRight->push(currPos);
					HX_STACK_LINE(364)
					j = (funnelRight->length - (int)3);
					HX_STACK_LINE(365)
					while((true)){
						HX_STACK_LINE(365)
						if ((!(((j >= (int)0))))){
							HX_STACK_LINE(365)
							break;
						}
						HX_STACK_LINE(366)
						int _g31 = ::hxDaedalus::data::math::Geom2D_obj::getDirection(funnelRight->__get(j).StaticCast< ::hxDaedalus::data::math::Point2D >()->x,funnelRight->__get(j).StaticCast< ::hxDaedalus::data::math::Point2D >()->y,funnelRight->__get((j + (int)1)).StaticCast< ::hxDaedalus::data::math::Point2D >()->x,funnelRight->__get((j + (int)1)).StaticCast< ::hxDaedalus::data::math::Point2D >()->y,currPos->x,currPos->y);		HX_STACK_VAR(_g31,"_g31");
						HX_STACK_LINE(366)
						direction = _g31;
						HX_STACK_LINE(367)
						if (((direction == (int)-1))){
							HX_STACK_LINE(368)
							break;
						}
						else{
							HX_STACK_LINE(371)
							funnelRight->splice((j + (int)1),(int)1);
						}
						HX_STACK_LINE(373)
						(j)--;
					}
				}
				else{
					HX_STACK_LINE(379)
					j = (funnelRight->length - (int)2);
					HX_STACK_LINE(380)
					while((true)){
						HX_STACK_LINE(380)
						if ((!(((j >= (int)0))))){
							HX_STACK_LINE(380)
							break;
						}
						HX_STACK_LINE(381)
						int _g32 = ::hxDaedalus::data::math::Geom2D_obj::getDirection(funnelRight->__get(j).StaticCast< ::hxDaedalus::data::math::Point2D >()->x,funnelRight->__get(j).StaticCast< ::hxDaedalus::data::math::Point2D >()->y,funnelRight->__get((j + (int)1)).StaticCast< ::hxDaedalus::data::math::Point2D >()->x,funnelRight->__get((j + (int)1)).StaticCast< ::hxDaedalus::data::math::Point2D >()->y,currPos->x,currPos->y);		HX_STACK_VAR(_g32,"_g32");
						HX_STACK_LINE(381)
						direction = _g32;
						HX_STACK_LINE(382)
						if (((direction != (int)1))){
							HX_STACK_LINE(384)
							funnelRight->shift().StaticCast< ::hxDaedalus::data::math::Point2D >();
							HX_STACK_LINE(385)
							{
								HX_STACK_LINE(385)
								int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
								HX_STACK_LINE(385)
								while((true)){
									HX_STACK_LINE(385)
									if ((!(((_g2 < j))))){
										HX_STACK_LINE(385)
										break;
									}
									HX_STACK_LINE(385)
									int k1 = (_g2)++;		HX_STACK_VAR(k1,"k1");
									HX_STACK_LINE(386)
									pathPoints->push(funnelRight->__get((int)0).StaticCast< ::hxDaedalus::data::math::Point2D >());
									HX_STACK_LINE(387)
									{
										HX_STACK_LINE(387)
										pathSides->set(funnelRight->__get((int)0).StaticCast< ::hxDaedalus::data::math::Point2D >(),(int)-1);
										HX_STACK_LINE(387)
										(int)-1;
									}
									HX_STACK_LINE(388)
									funnelRight->shift().StaticCast< ::hxDaedalus::data::math::Point2D >();
								}
							}
							HX_STACK_LINE(390)
							pathPoints->push(funnelRight->__get((int)0).StaticCast< ::hxDaedalus::data::math::Point2D >());
							HX_STACK_LINE(391)
							{
								HX_STACK_LINE(391)
								pathSides->set(funnelRight->__get((int)0).StaticCast< ::hxDaedalus::data::math::Point2D >(),(int)-1);
								HX_STACK_LINE(391)
								(int)-1;
							}
							HX_STACK_LINE(392)
							funnelLeft->splice((int)0,funnelLeft->length);
							HX_STACK_LINE(393)
							funnelLeft->push(funnelRight->__get((int)0).StaticCast< ::hxDaedalus::data::math::Point2D >());
							HX_STACK_LINE(394)
							funnelLeft->push(currPos);
							HX_STACK_LINE(395)
							break;
						}
						HX_STACK_LINE(397)
						(j)--;
					}
					HX_STACK_LINE(400)
					funnelLeft->push(currPos);
					HX_STACK_LINE(401)
					j = (funnelLeft->length - (int)3);
					HX_STACK_LINE(402)
					while((true)){
						HX_STACK_LINE(402)
						if ((!(((j >= (int)0))))){
							HX_STACK_LINE(402)
							break;
						}
						HX_STACK_LINE(403)
						int _g33 = ::hxDaedalus::data::math::Geom2D_obj::getDirection(funnelLeft->__get(j).StaticCast< ::hxDaedalus::data::math::Point2D >()->x,funnelLeft->__get(j).StaticCast< ::hxDaedalus::data::math::Point2D >()->y,funnelLeft->__get((j + (int)1)).StaticCast< ::hxDaedalus::data::math::Point2D >()->x,funnelLeft->__get((j + (int)1)).StaticCast< ::hxDaedalus::data::math::Point2D >()->y,currPos->x,currPos->y);		HX_STACK_VAR(_g33,"_g33");
						HX_STACK_LINE(403)
						direction = _g33;
						HX_STACK_LINE(404)
						if (((direction == (int)1))){
							HX_STACK_LINE(405)
							break;
						}
						else{
							HX_STACK_LINE(408)
							funnelLeft->splice((j + (int)1),(int)1);
						}
						HX_STACK_LINE(410)
						(j)--;
					}
				}
			}
		}
		HX_STACK_LINE(417)
		bool blocked = false;		HX_STACK_VAR(blocked,"blocked");
		HX_STACK_LINE(419)
		j = (funnelRight->length - (int)2);
		HX_STACK_LINE(420)
		while((true)){
			HX_STACK_LINE(420)
			if ((!(((j >= (int)0))))){
				HX_STACK_LINE(420)
				break;
			}
			HX_STACK_LINE(421)
			int _g34 = ::hxDaedalus::data::math::Geom2D_obj::getDirection(funnelRight->__get(j).StaticCast< ::hxDaedalus::data::math::Point2D >()->x,funnelRight->__get(j).StaticCast< ::hxDaedalus::data::math::Point2D >()->y,funnelRight->__get((j + (int)1)).StaticCast< ::hxDaedalus::data::math::Point2D >()->x,funnelRight->__get((j + (int)1)).StaticCast< ::hxDaedalus::data::math::Point2D >()->y,toX,toY);		HX_STACK_VAR(_g34,"_g34");
			HX_STACK_LINE(421)
			direction = _g34;
			HX_STACK_LINE(423)
			if (((direction != (int)1))){
				HX_STACK_LINE(427)
				funnelRight->shift().StaticCast< ::hxDaedalus::data::math::Point2D >();
				HX_STACK_LINE(428)
				{
					HX_STACK_LINE(428)
					int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(428)
					int _g = (j + (int)1);		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(428)
					while((true)){
						HX_STACK_LINE(428)
						if ((!(((_g1 < _g))))){
							HX_STACK_LINE(428)
							break;
						}
						HX_STACK_LINE(428)
						int k1 = (_g1)++;		HX_STACK_VAR(k1,"k1");
						HX_STACK_LINE(429)
						pathPoints->push(funnelRight->__get((int)0).StaticCast< ::hxDaedalus::data::math::Point2D >());
						HX_STACK_LINE(430)
						{
							HX_STACK_LINE(430)
							pathSides->set(funnelRight->__get((int)0).StaticCast< ::hxDaedalus::data::math::Point2D >(),(int)-1);
							HX_STACK_LINE(430)
							(int)-1;
						}
						HX_STACK_LINE(431)
						funnelRight->shift().StaticCast< ::hxDaedalus::data::math::Point2D >();
					}
				}
				HX_STACK_LINE(433)
				pathPoints->push(endPoint);
				HX_STACK_LINE(434)
				{
					HX_STACK_LINE(434)
					pathSides->set(endPoint,(int)0);
					HX_STACK_LINE(434)
					(int)0;
				}
				HX_STACK_LINE(435)
				blocked = true;
				HX_STACK_LINE(436)
				break;
			}
			HX_STACK_LINE(438)
			(j)--;
		}
		HX_STACK_LINE(441)
		if ((!(blocked))){
			HX_STACK_LINE(445)
			j = (funnelLeft->length - (int)2);
			HX_STACK_LINE(446)
			while((true)){
				HX_STACK_LINE(446)
				if ((!(((j >= (int)0))))){
					HX_STACK_LINE(446)
					break;
				}
				HX_STACK_LINE(447)
				int _g35 = ::hxDaedalus::data::math::Geom2D_obj::getDirection(funnelLeft->__get(j).StaticCast< ::hxDaedalus::data::math::Point2D >()->x,funnelLeft->__get(j).StaticCast< ::hxDaedalus::data::math::Point2D >()->y,funnelLeft->__get((j + (int)1)).StaticCast< ::hxDaedalus::data::math::Point2D >()->x,funnelLeft->__get((j + (int)1)).StaticCast< ::hxDaedalus::data::math::Point2D >()->y,toX,toY);		HX_STACK_VAR(_g35,"_g35");
				HX_STACK_LINE(447)
				direction = _g35;
				HX_STACK_LINE(449)
				if (((direction != (int)-1))){
					HX_STACK_LINE(453)
					funnelLeft->shift().StaticCast< ::hxDaedalus::data::math::Point2D >();
					HX_STACK_LINE(454)
					{
						HX_STACK_LINE(454)
						int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
						HX_STACK_LINE(454)
						int _g = (j + (int)1);		HX_STACK_VAR(_g,"_g");
						HX_STACK_LINE(454)
						while((true)){
							HX_STACK_LINE(454)
							if ((!(((_g1 < _g))))){
								HX_STACK_LINE(454)
								break;
							}
							HX_STACK_LINE(454)
							int k1 = (_g1)++;		HX_STACK_VAR(k1,"k1");
							HX_STACK_LINE(455)
							pathPoints->push(funnelLeft->__get((int)0).StaticCast< ::hxDaedalus::data::math::Point2D >());
							HX_STACK_LINE(456)
							{
								HX_STACK_LINE(456)
								pathSides->set(funnelLeft->__get((int)0).StaticCast< ::hxDaedalus::data::math::Point2D >(),(int)1);
								HX_STACK_LINE(456)
								(int)1;
							}
							HX_STACK_LINE(457)
							funnelLeft->shift().StaticCast< ::hxDaedalus::data::math::Point2D >();
						}
					}
					HX_STACK_LINE(460)
					pathPoints->push(endPoint);
					HX_STACK_LINE(461)
					{
						HX_STACK_LINE(461)
						pathSides->set(endPoint,(int)0);
						HX_STACK_LINE(461)
						(int)0;
					}
					HX_STACK_LINE(462)
					blocked = true;
					HX_STACK_LINE(463)
					break;
				}
				HX_STACK_LINE(465)
				(j)--;
			}
		}
		HX_STACK_LINE(471)
		if ((!(blocked))){
			HX_STACK_LINE(473)
			pathPoints->push(endPoint);
			HX_STACK_LINE(474)
			{
				HX_STACK_LINE(474)
				pathSides->set(endPoint,(int)0);
				HX_STACK_LINE(474)
				(int)0;
			}
			HX_STACK_LINE(475)
			blocked = true;
		}
		HX_STACK_LINE(479)
		Array< ::Dynamic > adjustedPoints = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(adjustedPoints,"adjustedPoints");
		HX_STACK_LINE(480)
		Float _g36 = this->get_radius();		HX_STACK_VAR(_g36,"_g36");
		HX_STACK_LINE(480)
		if (((_g36 > (int)0))){
			HX_STACK_LINE(483)
			Array< ::Dynamic > newPath = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(newPath,"newPath");
			HX_STACK_LINE(485)
			if (((pathPoints->length == (int)2))){
				HX_STACK_LINE(487)
				this->adjustWithTangents(pathPoints->__get((int)0).StaticCast< ::hxDaedalus::data::math::Point2D >(),false,pathPoints->__get((int)1).StaticCast< ::hxDaedalus::data::math::Point2D >(),false,pointSides,pointSuccessor,newPath,adjustedPoints);
			}
			else{
				HX_STACK_LINE(489)
				if (((pathPoints->length > (int)2))){
					HX_STACK_LINE(492)
					this->adjustWithTangents(pathPoints->__get((int)0).StaticCast< ::hxDaedalus::data::math::Point2D >(),false,pathPoints->__get((int)1).StaticCast< ::hxDaedalus::data::math::Point2D >(),true,pointSides,pointSuccessor,newPath,adjustedPoints);
					HX_STACK_LINE(495)
					if (((pathPoints->length > (int)3))){
						HX_STACK_LINE(497)
						int _g1 = (int)1;		HX_STACK_VAR(_g1,"_g1");
						HX_STACK_LINE(497)
						int _g = ((pathPoints->length - (int)3) + (int)1);		HX_STACK_VAR(_g,"_g");
						HX_STACK_LINE(497)
						while((true)){
							HX_STACK_LINE(497)
							if ((!(((_g1 < _g))))){
								HX_STACK_LINE(497)
								break;
							}
							HX_STACK_LINE(497)
							int i1 = (_g1)++;		HX_STACK_VAR(i1,"i1");
							HX_STACK_LINE(498)
							this->adjustWithTangents(pathPoints->__get(i1).StaticCast< ::hxDaedalus::data::math::Point2D >(),true,pathPoints->__get((i1 + (int)1)).StaticCast< ::hxDaedalus::data::math::Point2D >(),true,pointSides,pointSuccessor,newPath,adjustedPoints);
						}
					}
					HX_STACK_LINE(504)
					int pathLength = pathPoints->length;		HX_STACK_VAR(pathLength,"pathLength");
					HX_STACK_LINE(505)
					this->adjustWithTangents(pathPoints->__get((pathLength - (int)2)).StaticCast< ::hxDaedalus::data::math::Point2D >(),true,pathPoints->__get((pathLength - (int)1)).StaticCast< ::hxDaedalus::data::math::Point2D >(),false,pointSides,pointSuccessor,newPath,adjustedPoints);
				}
			}
			HX_STACK_LINE(508)
			newPath->push(endPoint);
			HX_STACK_LINE(511)
			this->checkAdjustedPath(newPath,adjustedPoints,pointSides);
			HX_STACK_LINE(513)
			Array< ::Dynamic > smoothPoints = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(smoothPoints,"smoothPoints");
			HX_STACK_LINE(514)
			i = (newPath->length - (int)2);
			HX_STACK_LINE(515)
			while((true)){
				HX_STACK_LINE(515)
				if ((!(((i >= (int)1))))){
					HX_STACK_LINE(515)
					break;
				}
				HX_STACK_LINE(516)
				Dynamic _g37 = pointSides->get(newPath->__get(i).StaticCast< ::hxDaedalus::data::math::Point2D >());		HX_STACK_VAR(_g37,"_g37");
				HX_STACK_LINE(516)
				this->smoothAngle(adjustedPoints->__get(((i * (int)2) - (int)1)).StaticCast< ::hxDaedalus::data::math::Point2D >(),newPath->__get(i).StaticCast< ::hxDaedalus::data::math::Point2D >(),adjustedPoints->__get((i * (int)2)).StaticCast< ::hxDaedalus::data::math::Point2D >(),_g37,smoothPoints);
				HX_STACK_LINE(517)
				while((true)){
					HX_STACK_LINE(517)
					if ((!(((smoothPoints->length != (int)0))))){
						HX_STACK_LINE(517)
						break;
					}
					HX_STACK_LINE(519)
					int temp = (i * (int)2);		HX_STACK_VAR(temp,"temp");
					HX_STACK_LINE(520)
					adjustedPoints->splice(temp,(int)0);
					HX_STACK_LINE(521)
					::hxDaedalus::data::math::Point2D _g38 = smoothPoints->pop().StaticCast< ::hxDaedalus::data::math::Point2D >();		HX_STACK_VAR(_g38,"_g38");
					HX_STACK_LINE(521)
					adjustedPoints->insert(temp,_g38);
				}
				HX_STACK_LINE(523)
				(i)--;
			}
		}
		else{
			HX_STACK_LINE(528)
			adjustedPoints = pathPoints;
		}
		HX_STACK_LINE(533)
		{
			HX_STACK_LINE(533)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(533)
			int _g = adjustedPoints->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(533)
			while((true)){
				HX_STACK_LINE(533)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(533)
					break;
				}
				HX_STACK_LINE(533)
				int i1 = (_g1)++;		HX_STACK_VAR(i1,"i1");
				HX_STACK_LINE(534)
				resultPath->push(adjustedPoints->__get(i1).StaticCast< ::hxDaedalus::data::math::Point2D >()->x);
				HX_STACK_LINE(535)
				resultPath->push(adjustedPoints->__get(i1).StaticCast< ::hxDaedalus::data::math::Point2D >()->y);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC7(Funnel_obj,findPath,(void))

Void Funnel_obj::adjustWithTangents( ::hxDaedalus::data::math::Point2D p1,bool applyRadiusToP1,::hxDaedalus::data::math::Point2D p2,bool applyRadiusToP2,::haxe::ds::ObjectMap pointSides,::haxe::ds::ObjectMap pointSuccessor,Array< ::Dynamic > newPath,Array< ::Dynamic > adjustedPoints){
{
		HX_STACK_FRAME("hxDaedalus.ai.Funnel","adjustWithTangents",0x0bf4e3ee,"hxDaedalus.ai.Funnel.adjustWithTangents","hxDaedalus/ai/Funnel.hx",540,0x7110c2fb)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p1,"p1")
		HX_STACK_ARG(applyRadiusToP1,"applyRadiusToP1")
		HX_STACK_ARG(p2,"p2")
		HX_STACK_ARG(applyRadiusToP2,"applyRadiusToP2")
		HX_STACK_ARG(pointSides,"pointSides")
		HX_STACK_ARG(pointSuccessor,"pointSuccessor")
		HX_STACK_ARG(newPath,"newPath")
		HX_STACK_ARG(adjustedPoints,"adjustedPoints")
		HX_STACK_LINE(547)
		Array< Float > tangentsResult = Array_obj< Float >::__new();		HX_STACK_VAR(tangentsResult,"tangentsResult");
		HX_STACK_LINE(549)
		int side1 = pointSides->get(p1);		HX_STACK_VAR(side1,"side1");
		HX_STACK_LINE(550)
		int side2 = pointSides->get(p2);		HX_STACK_VAR(side2,"side2");
		HX_STACK_LINE(552)
		::hxDaedalus::data::math::Point2D pTangent1 = null();		HX_STACK_VAR(pTangent1,"pTangent1");
		HX_STACK_LINE(553)
		::hxDaedalus::data::math::Point2D pTangent2 = null();		HX_STACK_VAR(pTangent2,"pTangent2");
		HX_STACK_LINE(556)
		if (((bool(!(applyRadiusToP1)) && bool(!(applyRadiusToP2))))){
			HX_STACK_LINE(559)
			pTangent1 = p1;
			HX_STACK_LINE(560)
			pTangent2 = p2;
		}
		else{
			HX_STACK_LINE(563)
			if ((!(applyRadiusToP1))){
				HX_STACK_LINE(566)
				if ((::hxDaedalus::data::math::Geom2D_obj::tangentsPointToCircle(p1->x,p1->y,p2->x,p2->y,this->_radius,tangentsResult))){
					HX_STACK_LINE(568)
					if (((side2 == (int)1))){
						HX_STACK_LINE(570)
						pTangent1 = p1;
						HX_STACK_LINE(571)
						::hxDaedalus::data::math::Point2D _g = this->getPoint(tangentsResult->__get((int)2),tangentsResult->__get((int)3));		HX_STACK_VAR(_g,"_g");
						HX_STACK_LINE(571)
						pTangent2 = _g;
					}
					else{
						HX_STACK_LINE(576)
						pTangent1 = p1;
						HX_STACK_LINE(577)
						::hxDaedalus::data::math::Point2D _g1 = this->getPoint(tangentsResult->__get((int)0),tangentsResult->__get((int)1));		HX_STACK_VAR(_g1,"_g1");
						HX_STACK_LINE(577)
						pTangent2 = _g1;
					}
				}
				else{
					HX_STACK_LINE(581)
					return null();
				}
			}
			else{
				HX_STACK_LINE(585)
				if ((!(applyRadiusToP2))){
					HX_STACK_LINE(588)
					if ((::hxDaedalus::data::math::Geom2D_obj::tangentsPointToCircle(p2->x,p2->y,p1->x,p1->y,this->_radius,tangentsResult))){
						HX_STACK_LINE(589)
						if (((tangentsResult->length > (int)0))){
							HX_STACK_LINE(592)
							if (((side1 == (int)1))){
								HX_STACK_LINE(594)
								::hxDaedalus::data::math::Point2D _g2 = this->getPoint(tangentsResult->__get((int)0),tangentsResult->__get((int)1));		HX_STACK_VAR(_g2,"_g2");
								HX_STACK_LINE(594)
								pTangent1 = _g2;
								HX_STACK_LINE(595)
								pTangent2 = p2;
							}
							else{
								HX_STACK_LINE(600)
								::hxDaedalus::data::math::Point2D _g3 = this->getPoint(tangentsResult->__get((int)2),tangentsResult->__get((int)3));		HX_STACK_VAR(_g3,"_g3");
								HX_STACK_LINE(600)
								pTangent1 = _g3;
								HX_STACK_LINE(601)
								pTangent2 = p2;
							}
						}
					}
					else{
						HX_STACK_LINE(606)
						return null();
					}
				}
				else{
					HX_STACK_LINE(614)
					if (((bool((side1 == (int)1)) && bool((side2 == (int)1))))){
						HX_STACK_LINE(616)
						::hxDaedalus::data::math::Geom2D_obj::tangentsParalCircleToCircle(this->_radius,p1->x,p1->y,p2->x,p2->y,tangentsResult);
						HX_STACK_LINE(618)
						::hxDaedalus::data::math::Point2D _g4 = this->getPoint(tangentsResult->__get((int)2),tangentsResult->__get((int)3));		HX_STACK_VAR(_g4,"_g4");
						HX_STACK_LINE(618)
						pTangent1 = _g4;
						HX_STACK_LINE(619)
						::hxDaedalus::data::math::Point2D _g5 = this->getPoint(tangentsResult->__get((int)4),tangentsResult->__get((int)5));		HX_STACK_VAR(_g5,"_g5");
						HX_STACK_LINE(619)
						pTangent2 = _g5;
					}
					else{
						HX_STACK_LINE(622)
						if (((bool((side1 == (int)-1)) && bool((side2 == (int)-1))))){
							HX_STACK_LINE(624)
							::hxDaedalus::data::math::Geom2D_obj::tangentsParalCircleToCircle(this->_radius,p1->x,p1->y,p2->x,p2->y,tangentsResult);
							HX_STACK_LINE(626)
							::hxDaedalus::data::math::Point2D _g6 = this->getPoint(tangentsResult->__get((int)0),tangentsResult->__get((int)1));		HX_STACK_VAR(_g6,"_g6");
							HX_STACK_LINE(626)
							pTangent1 = _g6;
							HX_STACK_LINE(627)
							::hxDaedalus::data::math::Point2D _g7 = this->getPoint(tangentsResult->__get((int)6),tangentsResult->__get((int)7));		HX_STACK_VAR(_g7,"_g7");
							HX_STACK_LINE(627)
							pTangent2 = _g7;
						}
						else{
							HX_STACK_LINE(630)
							if (((bool((side1 == (int)1)) && bool((side2 == (int)-1))))){
								HX_STACK_LINE(632)
								if ((::hxDaedalus::data::math::Geom2D_obj::tangentsCrossCircleToCircle(this->_radius,p1->x,p1->y,p2->x,p2->y,tangentsResult))){
									HX_STACK_LINE(635)
									::hxDaedalus::data::math::Point2D _g8 = this->getPoint(tangentsResult->__get((int)2),tangentsResult->__get((int)3));		HX_STACK_VAR(_g8,"_g8");
									HX_STACK_LINE(635)
									pTangent1 = _g8;
									HX_STACK_LINE(636)
									::hxDaedalus::data::math::Point2D _g9 = this->getPoint(tangentsResult->__get((int)6),tangentsResult->__get((int)7));		HX_STACK_VAR(_g9,"_g9");
									HX_STACK_LINE(636)
									pTangent2 = _g9;
								}
								else{
									HX_STACK_LINE(643)
									return null();
								}
							}
							else{
								HX_STACK_LINE(649)
								if ((::hxDaedalus::data::math::Geom2D_obj::tangentsCrossCircleToCircle(this->_radius,p1->x,p1->y,p2->x,p2->y,tangentsResult))){
									HX_STACK_LINE(652)
									::hxDaedalus::data::math::Point2D _g10 = this->getPoint(tangentsResult->__get((int)0),tangentsResult->__get((int)1));		HX_STACK_VAR(_g10,"_g10");
									HX_STACK_LINE(652)
									pTangent1 = _g10;
									HX_STACK_LINE(653)
									::hxDaedalus::data::math::Point2D _g11 = this->getPoint(tangentsResult->__get((int)4),tangentsResult->__get((int)5));		HX_STACK_VAR(_g11,"_g11");
									HX_STACK_LINE(653)
									pTangent2 = _g11;
								}
								else{
									HX_STACK_LINE(660)
									return null();
								}
							}
						}
					}
				}
			}
		}
		HX_STACK_LINE(665)
		::hxDaedalus::data::math::Point2D successor = pointSuccessor->get(p1);		HX_STACK_VAR(successor,"successor");
		HX_STACK_LINE(666)
		Float distance;		HX_STACK_VAR(distance,"distance");
		HX_STACK_LINE(667)
		while((true)){
			HX_STACK_LINE(667)
			if ((!(((successor != p2))))){
				HX_STACK_LINE(667)
				break;
			}
			HX_STACK_LINE(669)
			Float _g12 = ::hxDaedalus::data::math::Geom2D_obj::distanceSquaredPointToSegment(successor->x,successor->y,pTangent1->x,pTangent1->y,pTangent2->x,pTangent2->y);		HX_STACK_VAR(_g12,"_g12");
			HX_STACK_LINE(669)
			distance = _g12;
			HX_STACK_LINE(670)
			if (((distance < this->_radiusSquared))){
				HX_STACK_LINE(672)
				this->adjustWithTangents(p1,applyRadiusToP1,successor,true,pointSides,pointSuccessor,newPath,adjustedPoints);
				HX_STACK_LINE(673)
				this->adjustWithTangents(successor,true,p2,applyRadiusToP2,pointSides,pointSuccessor,newPath,adjustedPoints);
				HX_STACK_LINE(674)
				return null();
			}
			else{
				HX_STACK_LINE(678)
				::hxDaedalus::data::math::Point2D _g13 = pointSuccessor->get(successor);		HX_STACK_VAR(_g13,"_g13");
				HX_STACK_LINE(678)
				successor = _g13;
			}
		}
		HX_STACK_LINE(697)
		adjustedPoints->push(pTangent1);
		HX_STACK_LINE(698)
		adjustedPoints->push(pTangent2);
		HX_STACK_LINE(699)
		newPath->push(p1);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC8(Funnel_obj,adjustWithTangents,(void))

Void Funnel_obj::checkAdjustedPath( Array< ::Dynamic > newPath,Array< ::Dynamic > adjustedPoints,::haxe::ds::ObjectMap pointSides){
{
		HX_STACK_FRAME("hxDaedalus.ai.Funnel","checkAdjustedPath",0xe800ba30,"hxDaedalus.ai.Funnel.checkAdjustedPath","hxDaedalus/ai/Funnel.hx",703,0x7110c2fb)
		HX_STACK_THIS(this)
		HX_STACK_ARG(newPath,"newPath")
		HX_STACK_ARG(adjustedPoints,"adjustedPoints")
		HX_STACK_ARG(pointSides,"pointSides")
		HX_STACK_LINE(705)
		bool needCheck = true;		HX_STACK_VAR(needCheck,"needCheck");
		HX_STACK_LINE(707)
		::hxDaedalus::data::math::Point2D point0;		HX_STACK_VAR(point0,"point0");
		HX_STACK_LINE(708)
		int point0Side;		HX_STACK_VAR(point0Side,"point0Side");
		HX_STACK_LINE(709)
		::hxDaedalus::data::math::Point2D point1;		HX_STACK_VAR(point1,"point1");
		HX_STACK_LINE(710)
		int point1Side;		HX_STACK_VAR(point1Side,"point1Side");
		HX_STACK_LINE(711)
		::hxDaedalus::data::math::Point2D point2;		HX_STACK_VAR(point2,"point2");
		HX_STACK_LINE(712)
		int point2Side;		HX_STACK_VAR(point2Side,"point2Side");
		HX_STACK_LINE(714)
		::hxDaedalus::data::math::Point2D pt1;		HX_STACK_VAR(pt1,"pt1");
		HX_STACK_LINE(715)
		::hxDaedalus::data::math::Point2D pt2;		HX_STACK_VAR(pt2,"pt2");
		HX_STACK_LINE(716)
		::hxDaedalus::data::math::Point2D pt3;		HX_STACK_VAR(pt3,"pt3");
		HX_STACK_LINE(717)
		Float dot;		HX_STACK_VAR(dot,"dot");
		HX_STACK_LINE(719)
		Array< Float > tangentsResult = Array_obj< Float >::__new();		HX_STACK_VAR(tangentsResult,"tangentsResult");
		HX_STACK_LINE(720)
		::hxDaedalus::data::math::Point2D pTangent1 = null();		HX_STACK_VAR(pTangent1,"pTangent1");
		HX_STACK_LINE(721)
		::hxDaedalus::data::math::Point2D pTangent2 = null();		HX_STACK_VAR(pTangent2,"pTangent2");
		HX_STACK_LINE(723)
		while((true)){
			HX_STACK_LINE(723)
			if ((!(needCheck))){
				HX_STACK_LINE(723)
				break;
			}
			HX_STACK_LINE(725)
			needCheck = false;
			HX_STACK_LINE(726)
			int i = (int)2;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(727)
			while((true)){
				HX_STACK_LINE(727)
				if ((!(((i < newPath->length))))){
					HX_STACK_LINE(727)
					break;
				}
				HX_STACK_LINE(728)
				point2 = newPath->__get(i).StaticCast< ::hxDaedalus::data::math::Point2D >();
				HX_STACK_LINE(729)
				Dynamic _g = pointSides->get(point2);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(729)
				point2Side = _g;
				HX_STACK_LINE(730)
				point1 = newPath->__get((i - (int)1)).StaticCast< ::hxDaedalus::data::math::Point2D >();
				HX_STACK_LINE(731)
				Dynamic _g1 = pointSides->get(point1);		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(731)
				point1Side = _g1;
				HX_STACK_LINE(732)
				point0 = newPath->__get((i - (int)2)).StaticCast< ::hxDaedalus::data::math::Point2D >();
				HX_STACK_LINE(733)
				Dynamic _g2 = pointSides->get(point0);		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(733)
				point0Side = _g2;
				HX_STACK_LINE(735)
				if (((point1Side == point2Side))){
					HX_STACK_LINE(737)
					pt1 = adjustedPoints->__get((((i - (int)2)) * (int)2)).StaticCast< ::hxDaedalus::data::math::Point2D >();
					HX_STACK_LINE(738)
					pt2 = adjustedPoints->__get(((((i - (int)1)) * (int)2) - (int)1)).StaticCast< ::hxDaedalus::data::math::Point2D >();
					HX_STACK_LINE(739)
					pt3 = adjustedPoints->__get((((i - (int)1)) * (int)2)).StaticCast< ::hxDaedalus::data::math::Point2D >();
					HX_STACK_LINE(740)
					dot = ((((pt1->x - pt2->x)) * ((pt3->x - pt2->x))) + (((pt1->y - pt2->y)) * ((pt3->y - pt2->y))));
					HX_STACK_LINE(741)
					if (((dot > (int)0))){
						HX_STACK_LINE(746)
						if (((i == (int)2))){
							HX_STACK_LINE(749)
							::hxDaedalus::data::math::Geom2D_obj::tangentsPointToCircle(point0->x,point0->y,point2->x,point2->y,this->_radius,tangentsResult);
							HX_STACK_LINE(751)
							if (((point2Side == (int)1))){
								HX_STACK_LINE(753)
								pTangent1 = point0;
								HX_STACK_LINE(754)
								::hxDaedalus::data::math::Point2D _g3 = this->getPoint(tangentsResult->__get((int)2),tangentsResult->__get((int)3));		HX_STACK_VAR(_g3,"_g3");
								HX_STACK_LINE(754)
								pTangent2 = _g3;
							}
							else{
								HX_STACK_LINE(758)
								pTangent1 = point0;
								HX_STACK_LINE(759)
								::hxDaedalus::data::math::Point2D _g4 = this->getPoint(tangentsResult->__get((int)0),tangentsResult->__get((int)1));		HX_STACK_VAR(_g4,"_g4");
								HX_STACK_LINE(759)
								pTangent2 = _g4;
							}
						}
						else{
							HX_STACK_LINE(762)
							if (((i == (newPath->length - (int)1)))){
								HX_STACK_LINE(765)
								::hxDaedalus::data::math::Geom2D_obj::tangentsPointToCircle(point2->x,point2->y,point0->x,point0->y,this->_radius,tangentsResult);
								HX_STACK_LINE(767)
								if (((point0Side == (int)1))){
									HX_STACK_LINE(769)
									::hxDaedalus::data::math::Point2D _g5 = this->getPoint(tangentsResult->__get((int)0),tangentsResult->__get((int)1));		HX_STACK_VAR(_g5,"_g5");
									HX_STACK_LINE(769)
									pTangent1 = _g5;
									HX_STACK_LINE(770)
									pTangent2 = point2;
								}
								else{
									HX_STACK_LINE(775)
									::hxDaedalus::data::math::Point2D _g6 = this->getPoint(tangentsResult->__get((int)2),tangentsResult->__get((int)3));		HX_STACK_VAR(_g6,"_g6");
									HX_STACK_LINE(775)
									pTangent1 = _g6;
									HX_STACK_LINE(776)
									pTangent2 = point2;
								}
							}
							else{
								HX_STACK_LINE(782)
								if (((bool((point0Side == (int)1)) && bool((point2Side == (int)-1))))){
									HX_STACK_LINE(785)
									::hxDaedalus::data::math::Geom2D_obj::tangentsCrossCircleToCircle(this->_radius,point0->x,point0->y,point2->x,point2->y,tangentsResult);
									HX_STACK_LINE(787)
									::hxDaedalus::data::math::Point2D _g7 = this->getPoint(tangentsResult->__get((int)2),tangentsResult->__get((int)3));		HX_STACK_VAR(_g7,"_g7");
									HX_STACK_LINE(787)
									pTangent1 = _g7;
									HX_STACK_LINE(788)
									::hxDaedalus::data::math::Point2D _g8 = this->getPoint(tangentsResult->__get((int)6),tangentsResult->__get((int)7));		HX_STACK_VAR(_g8,"_g8");
									HX_STACK_LINE(788)
									pTangent2 = _g8;
								}
								else{
									HX_STACK_LINE(791)
									if (((bool((point0Side == (int)-1)) && bool((point2Side == (int)1))))){
										HX_STACK_LINE(794)
										::hxDaedalus::data::math::Geom2D_obj::tangentsCrossCircleToCircle(this->_radius,point0->x,point0->y,point2->x,point2->y,tangentsResult);
										HX_STACK_LINE(796)
										::hxDaedalus::data::math::Point2D _g9 = this->getPoint(tangentsResult->__get((int)0),tangentsResult->__get((int)1));		HX_STACK_VAR(_g9,"_g9");
										HX_STACK_LINE(796)
										pTangent1 = _g9;
										HX_STACK_LINE(797)
										::hxDaedalus::data::math::Point2D _g10 = this->getPoint(tangentsResult->__get((int)4),tangentsResult->__get((int)5));		HX_STACK_VAR(_g10,"_g10");
										HX_STACK_LINE(797)
										pTangent2 = _g10;
									}
									else{
										HX_STACK_LINE(800)
										if (((bool((point0Side == (int)1)) && bool((point2Side == (int)1))))){
											HX_STACK_LINE(803)
											::hxDaedalus::data::math::Geom2D_obj::tangentsParalCircleToCircle(this->_radius,point0->x,point0->y,point2->x,point2->y,tangentsResult);
											HX_STACK_LINE(805)
											::hxDaedalus::data::math::Point2D _g11 = this->getPoint(tangentsResult->__get((int)2),tangentsResult->__get((int)3));		HX_STACK_VAR(_g11,"_g11");
											HX_STACK_LINE(805)
											pTangent1 = _g11;
											HX_STACK_LINE(806)
											::hxDaedalus::data::math::Point2D _g12 = this->getPoint(tangentsResult->__get((int)4),tangentsResult->__get((int)5));		HX_STACK_VAR(_g12,"_g12");
											HX_STACK_LINE(806)
											pTangent2 = _g12;
										}
										else{
											HX_STACK_LINE(809)
											if (((bool((point0Side == (int)-1)) && bool((point2Side == (int)-1))))){
												HX_STACK_LINE(812)
												::hxDaedalus::data::math::Geom2D_obj::tangentsParalCircleToCircle(this->_radius,point0->x,point0->y,point2->x,point2->y,tangentsResult);
												HX_STACK_LINE(814)
												::hxDaedalus::data::math::Point2D _g13 = this->getPoint(tangentsResult->__get((int)0),tangentsResult->__get((int)1));		HX_STACK_VAR(_g13,"_g13");
												HX_STACK_LINE(814)
												pTangent1 = _g13;
												HX_STACK_LINE(815)
												::hxDaedalus::data::math::Point2D _g14 = this->getPoint(tangentsResult->__get((int)6),tangentsResult->__get((int)7));		HX_STACK_VAR(_g14,"_g14");
												HX_STACK_LINE(815)
												pTangent2 = _g14;
											}
										}
									}
								}
							}
						}
						HX_STACK_LINE(818)
						int temp = (((i - (int)2)) * (int)2);		HX_STACK_VAR(temp,"temp");
						HX_STACK_LINE(819)
						adjustedPoints->splice(temp,(int)1);
						HX_STACK_LINE(820)
						adjustedPoints->insert(temp,pTangent1);
						HX_STACK_LINE(821)
						temp = ((i * (int)2) - (int)1);
						HX_STACK_LINE(822)
						adjustedPoints->splice(temp,(int)1);
						HX_STACK_LINE(823)
						adjustedPoints->insert(temp,pTangent2);
						HX_STACK_LINE(826)
						newPath->splice((i - (int)1),(int)1);
						HX_STACK_LINE(827)
						adjustedPoints->splice(((((i - (int)1)) * (int)2) - (int)1),(int)2);
						HX_STACK_LINE(829)
						tangentsResult->splice((int)0,tangentsResult->length);
						HX_STACK_LINE(830)
						(i)--;
					}
				}
				HX_STACK_LINE(833)
				(i)++;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Funnel_obj,checkAdjustedPath,(void))

Void Funnel_obj::smoothAngle( ::hxDaedalus::data::math::Point2D prevPoint,::hxDaedalus::data::math::Point2D pointToSmooth,::hxDaedalus::data::math::Point2D nextPoint,int side,Array< ::Dynamic > encirclePoints){
{
		HX_STACK_FRAME("hxDaedalus.ai.Funnel","smoothAngle",0x483da8da,"hxDaedalus.ai.Funnel.smoothAngle","hxDaedalus/ai/Funnel.hx",839,0x7110c2fb)
		HX_STACK_THIS(this)
		HX_STACK_ARG(prevPoint,"prevPoint")
		HX_STACK_ARG(pointToSmooth,"pointToSmooth")
		HX_STACK_ARG(nextPoint,"nextPoint")
		HX_STACK_ARG(side,"side")
		HX_STACK_ARG(encirclePoints,"encirclePoints")
		HX_STACK_LINE(840)
		int angleType = ::hxDaedalus::data::math::Geom2D_obj::getDirection(prevPoint->x,prevPoint->y,pointToSmooth->x,pointToSmooth->y,nextPoint->x,nextPoint->y);		HX_STACK_VAR(angleType,"angleType");
		HX_STACK_LINE(850)
		Float distanceSquared = ((((prevPoint->x - nextPoint->x)) * ((prevPoint->x - nextPoint->x))) + (((prevPoint->y - nextPoint->y)) * ((prevPoint->y - nextPoint->y))));		HX_STACK_VAR(distanceSquared,"distanceSquared");
		HX_STACK_LINE(851)
		if (((distanceSquared <= this->_sampleCircleDistanceSquared))){
			HX_STACK_LINE(852)
			return null();
		}
		HX_STACK_LINE(854)
		int index = (int)0;		HX_STACK_VAR(index,"index");
		HX_STACK_LINE(855)
		int side1;		HX_STACK_VAR(side1,"side1");
		HX_STACK_LINE(856)
		int side2;		HX_STACK_VAR(side2,"side2");
		HX_STACK_LINE(857)
		bool pointInArea;		HX_STACK_VAR(pointInArea,"pointInArea");
		HX_STACK_LINE(858)
		Float xToCheck;		HX_STACK_VAR(xToCheck,"xToCheck");
		HX_STACK_LINE(859)
		Float yToCheck;		HX_STACK_VAR(yToCheck,"yToCheck");
		HX_STACK_LINE(860)
		{
			HX_STACK_LINE(860)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(860)
			int _g = this->_numSamplesCircle;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(860)
			while((true)){
				HX_STACK_LINE(860)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(860)
					break;
				}
				HX_STACK_LINE(860)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(861)
				pointInArea = false;
				HX_STACK_LINE(862)
				xToCheck = (pointToSmooth->x + this->_sampleCircle->__get(i).StaticCast< ::hxDaedalus::data::math::Point2D >()->x);
				HX_STACK_LINE(863)
				yToCheck = (pointToSmooth->y + this->_sampleCircle->__get(i).StaticCast< ::hxDaedalus::data::math::Point2D >()->y);
				HX_STACK_LINE(864)
				int _g2 = ::hxDaedalus::data::math::Geom2D_obj::getDirection(prevPoint->x,prevPoint->y,pointToSmooth->x,pointToSmooth->y,xToCheck,yToCheck);		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(864)
				side1 = _g2;
				HX_STACK_LINE(865)
				int _g11 = ::hxDaedalus::data::math::Geom2D_obj::getDirection(pointToSmooth->x,pointToSmooth->y,nextPoint->x,nextPoint->y,xToCheck,yToCheck);		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(865)
				side2 = _g11;
				HX_STACK_LINE(868)
				if (((side == (int)1))){
					HX_STACK_LINE(872)
					if (((angleType == (int)-1))){
						HX_STACK_LINE(875)
						if (((bool((side1 == (int)-1)) && bool((side2 == (int)-1))))){
							HX_STACK_LINE(876)
							pointInArea = true;
						}
					}
					else{
						HX_STACK_LINE(882)
						if (((bool((side1 == (int)-1)) || bool((side2 == (int)-1))))){
							HX_STACK_LINE(883)
							pointInArea = true;
						}
					}
				}
				else{
					HX_STACK_LINE(890)
					if (((angleType == (int)1))){
						HX_STACK_LINE(892)
						if (((bool((side1 == (int)1)) && bool((side2 == (int)1))))){
							HX_STACK_LINE(893)
							pointInArea = true;
						}
					}
					else{
						HX_STACK_LINE(898)
						if (((bool((side1 == (int)1)) || bool((side2 == (int)1))))){
							HX_STACK_LINE(899)
							pointInArea = true;
						}
					}
				}
				HX_STACK_LINE(902)
				if ((pointInArea)){
					HX_STACK_LINE(904)
					encirclePoints->splice(index,(int)0);
					HX_STACK_LINE(905)
					::hxDaedalus::data::math::Point2D _g21 = ::hxDaedalus::data::math::Point2D_obj::__new(xToCheck,yToCheck);		HX_STACK_VAR(_g21,"_g21");
					HX_STACK_LINE(905)
					encirclePoints->insert(index,_g21);
					HX_STACK_LINE(906)
					(index)++;
				}
				else{
					HX_STACK_LINE(909)
					index = (int)0;
				}
			}
		}
		HX_STACK_LINE(911)
		if (((side == (int)-1))){
			HX_STACK_LINE(912)
			encirclePoints->reverse();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(Funnel_obj,smoothAngle,(void))


Funnel_obj::Funnel_obj()
{
}

void Funnel_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Funnel);
	HX_MARK_MEMBER_NAME(_radius,"_radius");
	HX_MARK_MEMBER_NAME(_radiusSquared,"_radiusSquared");
	HX_MARK_MEMBER_NAME(_numSamplesCircle,"_numSamplesCircle");
	HX_MARK_MEMBER_NAME(_sampleCircle,"_sampleCircle");
	HX_MARK_MEMBER_NAME(_sampleCircleDistanceSquared,"_sampleCircleDistanceSquared");
	HX_MARK_MEMBER_NAME(_poolPointsSize,"_poolPointsSize");
	HX_MARK_MEMBER_NAME(_poolPoints,"_poolPoints");
	HX_MARK_MEMBER_NAME(_currPoolPointsIndex,"_currPoolPointsIndex");
	HX_MARK_MEMBER_NAME(__point,"__point");
	HX_MARK_END_CLASS();
}

void Funnel_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_radius,"_radius");
	HX_VISIT_MEMBER_NAME(_radiusSquared,"_radiusSquared");
	HX_VISIT_MEMBER_NAME(_numSamplesCircle,"_numSamplesCircle");
	HX_VISIT_MEMBER_NAME(_sampleCircle,"_sampleCircle");
	HX_VISIT_MEMBER_NAME(_sampleCircleDistanceSquared,"_sampleCircleDistanceSquared");
	HX_VISIT_MEMBER_NAME(_poolPointsSize,"_poolPointsSize");
	HX_VISIT_MEMBER_NAME(_poolPoints,"_poolPoints");
	HX_VISIT_MEMBER_NAME(_currPoolPointsIndex,"_currPoolPointsIndex");
	HX_VISIT_MEMBER_NAME(__point,"__point");
}

Dynamic Funnel_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"radius") ) { return get_radius(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_radius") ) { return _radius; }
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		if (HX_FIELD_EQ(inName,"__point") ) { return __point; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"getPoint") ) { return getPoint_dyn(); }
		if (HX_FIELD_EQ(inName,"findPath") ) { return findPath_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_radius") ) { return get_radius_dyn(); }
		if (HX_FIELD_EQ(inName,"set_radius") ) { return set_radius_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_poolPoints") ) { return _poolPoints; }
		if (HX_FIELD_EQ(inName,"smoothAngle") ) { return smoothAngle_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"getCopyPoint") ) { return getCopyPoint_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_sampleCircle") ) { return _sampleCircle; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_radiusSquared") ) { return _radiusSquared; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_poolPointsSize") ) { return _poolPointsSize; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"_numSamplesCircle") ) { return _numSamplesCircle; }
		if (HX_FIELD_EQ(inName,"checkAdjustedPath") ) { return checkAdjustedPath_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"adjustWithTangents") ) { return adjustWithTangents_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"_currPoolPointsIndex") ) { return _currPoolPointsIndex; }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"_sampleCircleDistanceSquared") ) { return _sampleCircleDistanceSquared; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Funnel_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"radius") ) { return set_radius(inValue); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_radius") ) { _radius=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"__point") ) { __point=inValue.Cast< ::hxDaedalus::data::math::Point2D >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_poolPoints") ) { _poolPoints=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_sampleCircle") ) { _sampleCircle=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_radiusSquared") ) { _radiusSquared=inValue.Cast< Float >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_poolPointsSize") ) { _poolPointsSize=inValue.Cast< int >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"_numSamplesCircle") ) { _numSamplesCircle=inValue.Cast< int >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"_currPoolPointsIndex") ) { _currPoolPointsIndex=inValue.Cast< int >(); return inValue; }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"_sampleCircleDistanceSquared") ) { _sampleCircleDistanceSquared=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Funnel_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("radius"));
	outFields->push(HX_CSTRING("_radius"));
	outFields->push(HX_CSTRING("_radiusSquared"));
	outFields->push(HX_CSTRING("_numSamplesCircle"));
	outFields->push(HX_CSTRING("_sampleCircle"));
	outFields->push(HX_CSTRING("_sampleCircleDistanceSquared"));
	outFields->push(HX_CSTRING("_poolPointsSize"));
	outFields->push(HX_CSTRING("_poolPoints"));
	outFields->push(HX_CSTRING("_currPoolPointsIndex"));
	outFields->push(HX_CSTRING("__point"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsFloat,(int)offsetof(Funnel_obj,_radius),HX_CSTRING("_radius")},
	{hx::fsFloat,(int)offsetof(Funnel_obj,_radiusSquared),HX_CSTRING("_radiusSquared")},
	{hx::fsInt,(int)offsetof(Funnel_obj,_numSamplesCircle),HX_CSTRING("_numSamplesCircle")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(Funnel_obj,_sampleCircle),HX_CSTRING("_sampleCircle")},
	{hx::fsFloat,(int)offsetof(Funnel_obj,_sampleCircleDistanceSquared),HX_CSTRING("_sampleCircleDistanceSquared")},
	{hx::fsInt,(int)offsetof(Funnel_obj,_poolPointsSize),HX_CSTRING("_poolPointsSize")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(Funnel_obj,_poolPoints),HX_CSTRING("_poolPoints")},
	{hx::fsInt,(int)offsetof(Funnel_obj,_currPoolPointsIndex),HX_CSTRING("_currPoolPointsIndex")},
	{hx::fsObject /*::hxDaedalus::data::math::Point2D*/ ,(int)offsetof(Funnel_obj,__point),HX_CSTRING("__point")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("_radius"),
	HX_CSTRING("_radiusSquared"),
	HX_CSTRING("_numSamplesCircle"),
	HX_CSTRING("_sampleCircle"),
	HX_CSTRING("_sampleCircleDistanceSquared"),
	HX_CSTRING("dispose"),
	HX_CSTRING("_poolPointsSize"),
	HX_CSTRING("_poolPoints"),
	HX_CSTRING("_currPoolPointsIndex"),
	HX_CSTRING("__point"),
	HX_CSTRING("getPoint"),
	HX_CSTRING("getCopyPoint"),
	HX_CSTRING("get_radius"),
	HX_CSTRING("set_radius"),
	HX_CSTRING("findPath"),
	HX_CSTRING("adjustWithTangents"),
	HX_CSTRING("checkAdjustedPath"),
	HX_CSTRING("smoothAngle"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Funnel_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Funnel_obj::__mClass,"__mClass");
};

#endif

Class Funnel_obj::__mClass;

void Funnel_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDaedalus.ai.Funnel"), hx::TCanCast< Funnel_obj> ,sStaticFields,sMemberFields,
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

void Funnel_obj::__boot()
{
}

} // end namespace hxDaedalus
} // end namespace ai
