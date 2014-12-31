#include <hxcpp.h>

#ifndef INCLUDED_IMap
#include <IMap.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_haxe_ds_ObjectMap
#include <haxe/ds/ObjectMap.h>
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
#ifndef INCLUDED_hxDaedalus_data_math_RandGenerator
#include <hxDaedalus/data/math/RandGenerator.h>
#endif
#ifndef INCLUDED_hxDaedalus_iterators_FromFaceToInnerEdges
#include <hxDaedalus/iterators/FromFaceToInnerEdges.h>
#endif
#ifndef INCLUDED_hxDaedalus_iterators_FromVertexToHoldingFaces
#include <hxDaedalus/iterators/FromVertexToHoldingFaces.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace hxDaedalus{
namespace data{
namespace math{

Void Geom2D_obj::__construct()
{
HX_STACK_FRAME("hxDaedalus.data.math.Geom2D","new",0x100c6efb,"hxDaedalus.data.math.Geom2D.new","hxDaedalus/data/math/Geom2D.hx",1020,0x9a728514)
HX_STACK_THIS(this)
{
}
;
	return null();
}

//Geom2D_obj::~Geom2D_obj() { }

Dynamic Geom2D_obj::__CreateEmpty() { return  new Geom2D_obj; }
hx::ObjectPtr< Geom2D_obj > Geom2D_obj::__new()
{  hx::ObjectPtr< Geom2D_obj > result = new Geom2D_obj();
	result->__construct();
	return result;}

Dynamic Geom2D_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Geom2D_obj > result = new Geom2D_obj();
	result->__construct();
	return result;}

::hxDaedalus::data::math::RandGenerator Geom2D_obj::_randGen;

Array< ::Dynamic > Geom2D_obj::__samples;

::hxDaedalus::data::math::Intersection Geom2D_obj::locatePosition( Float x,Float y,::hxDaedalus::data::Mesh mesh){
	HX_STACK_FRAME("hxDaedalus.data.math.Geom2D","locatePosition",0xb0643ba0,"hxDaedalus.data.math.Geom2D.locatePosition","hxDaedalus/data/math/Geom2D.hx",52,0x9a728514)
	HX_STACK_ARG(x,"x")
	HX_STACK_ARG(y,"y")
	HX_STACK_ARG(mesh,"mesh")
	HX_STACK_LINE(55)
	if (((::hxDaedalus::data::math::Geom2D_obj::_randGen == null()))){
		HX_STACK_LINE(55)
		::hxDaedalus::data::math::RandGenerator _g = ::hxDaedalus::data::math::RandGenerator_obj::__new(null(),null(),null());		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(55)
		::hxDaedalus::data::math::Geom2D_obj::_randGen = _g;
	}
	HX_STACK_LINE(56)
	int _g1 = ::Std_obj::_int(((x * (int)10) + ((int)4 * y)));		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(56)
	::hxDaedalus::data::math::Geom2D_obj::_randGen->set_seed(_g1);
	HX_STACK_LINE(58)
	int i;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(60)
	::hxDaedalus::data::math::Geom2D_obj::__samples->splice((int)0,::hxDaedalus::data::math::Geom2D_obj::__samples->length);
	HX_STACK_LINE(61)
	Float _g2 = ::Math_obj::pow(mesh->_vertices->length,0.33333333333333331);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(61)
	int numSamples = ::Std_obj::_int(_g2);		HX_STACK_VAR(numSamples,"numSamples");
	HX_STACK_LINE(62)
	::hxDaedalus::data::math::Geom2D_obj::_randGen->rangeMin = (int)0;
	HX_STACK_LINE(63)
	::hxDaedalus::data::math::Geom2D_obj::_randGen->rangeMax = (mesh->_vertices->length - (int)1);
	HX_STACK_LINE(64)
	{
		HX_STACK_LINE(64)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(64)
		while((true)){
			HX_STACK_LINE(64)
			if ((!(((_g < numSamples))))){
				HX_STACK_LINE(64)
				break;
			}
			HX_STACK_LINE(64)
			int i1 = (_g)++;		HX_STACK_VAR(i1,"i1");
			HX_STACK_LINE(65)
			int _rnd = ::hxDaedalus::data::math::Geom2D_obj::_randGen->next();		HX_STACK_VAR(_rnd,"_rnd");
			HX_STACK_LINE(69)
			::hxDaedalus::data::math::Geom2D_obj::__samples->push(mesh->_vertices->__get(_rnd).StaticCast< ::hxDaedalus::data::Vertex >());
		}
	}
	HX_STACK_LINE(72)
	::hxDaedalus::data::Vertex currVertex;		HX_STACK_VAR(currVertex,"currVertex");
	HX_STACK_LINE(73)
	::hxDaedalus::data::math::Point2D currVertexPos;		HX_STACK_VAR(currVertexPos,"currVertexPos");
	HX_STACK_LINE(74)
	Float distSquared;		HX_STACK_VAR(distSquared,"distSquared");
	HX_STACK_LINE(75)
	Float minDistSquared = ::Math_obj::POSITIVE_INFINITY;		HX_STACK_VAR(minDistSquared,"minDistSquared");
	HX_STACK_LINE(76)
	::hxDaedalus::data::Vertex closedVertex = null();		HX_STACK_VAR(closedVertex,"closedVertex");
	HX_STACK_LINE(77)
	{
		HX_STACK_LINE(77)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(77)
		while((true)){
			HX_STACK_LINE(77)
			if ((!(((_g < numSamples))))){
				HX_STACK_LINE(77)
				break;
			}
			HX_STACK_LINE(77)
			int i1 = (_g)++;		HX_STACK_VAR(i1,"i1");
			HX_STACK_LINE(78)
			currVertex = ::hxDaedalus::data::math::Geom2D_obj::__samples->__get(i1).StaticCast< ::hxDaedalus::data::Vertex >();
			HX_STACK_LINE(79)
			::hxDaedalus::data::math::Point2D _g3 = currVertex->get_pos();		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(79)
			currVertexPos = _g3;
			HX_STACK_LINE(80)
			distSquared = ((((currVertexPos->x - x)) * ((currVertexPos->x - x))) + (((currVertexPos->y - y)) * ((currVertexPos->y - y))));
			HX_STACK_LINE(81)
			if (((distSquared < minDistSquared))){
				HX_STACK_LINE(83)
				minDistSquared = distSquared;
				HX_STACK_LINE(84)
				closedVertex = currVertex;
			}
		}
	}
	HX_STACK_LINE(88)
	::hxDaedalus::data::Face currFace;		HX_STACK_VAR(currFace,"currFace");
	HX_STACK_LINE(89)
	::hxDaedalus::iterators::FromVertexToHoldingFaces iterFace = ::hxDaedalus::iterators::FromVertexToHoldingFaces_obj::__new();		HX_STACK_VAR(iterFace,"iterFace");
	HX_STACK_LINE(90)
	iterFace->set_fromVertex(closedVertex);
	HX_STACK_LINE(91)
	::hxDaedalus::data::Face _g4 = iterFace->next();		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(91)
	currFace = _g4;
	HX_STACK_LINE(93)
	::haxe::ds::ObjectMap faceVisited = ::haxe::ds::ObjectMap_obj::__new();		HX_STACK_VAR(faceVisited,"faceVisited");
	HX_STACK_LINE(94)
	::hxDaedalus::data::Edge currEdge;		HX_STACK_VAR(currEdge,"currEdge");
	HX_STACK_LINE(95)
	::hxDaedalus::iterators::FromFaceToInnerEdges iterEdge = ::hxDaedalus::iterators::FromFaceToInnerEdges_obj::__new();		HX_STACK_VAR(iterEdge,"iterEdge");
	HX_STACK_LINE(96)
	::hxDaedalus::data::math::Intersection objectContainer = ::hxDaedalus::data::math::Intersection_obj::ENull;		HX_STACK_VAR(objectContainer,"objectContainer");
	HX_STACK_LINE(97)
	int relativPos;		HX_STACK_VAR(relativPos,"relativPos");
	HX_STACK_LINE(98)
	int numIter = (int)0;		HX_STACK_VAR(numIter,"numIter");
	HX_STACK_LINE(100)
	while((true)){
		struct _Function_2_1{
			inline static bool Block( ::hxDaedalus::data::math::Intersection &objectContainer,Float &x,::hxDaedalus::data::Face &currFace,Float &y){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","hxDaedalus/data/math/Geom2D.hx",100,0x9a728514)
				{
					HX_STACK_LINE(100)
					::hxDaedalus::data::math::Intersection _g5 = ::hxDaedalus::data::math::Geom2D_obj::isInFace(x,y,currFace);		HX_STACK_VAR(_g5,"_g5");
					HX_STACK_LINE(100)
					::hxDaedalus::data::math::Intersection _g = objectContainer = _g5;		HX_STACK_VAR(_g,"_g");
					struct _Function_3_1{
						inline static bool Block( ::hxDaedalus::data::math::Intersection &_g){
							HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","hxDaedalus/data/math/Geom2D.hx",100,0x9a728514)
							{
								HX_STACK_LINE(100)
								switch( (int)(_g->__Index())){
									case (int)3: {
										HX_STACK_LINE(100)
										return true;
									}
									;break;
									default: {
										HX_STACK_LINE(100)
										return false;
									}
								}
							}
							return null();
						}
					};
					HX_STACK_LINE(100)
					return _Function_3_1::Block(_g);
				}
				return null();
			}
		};
		HX_STACK_LINE(100)
		if ((!(((  ((!(faceVisited->get(currFace)))) ? bool(_Function_2_1::Block(objectContainer,x,currFace,y)) : bool(true) ))))){
			HX_STACK_LINE(100)
			break;
		}
		HX_STACK_LINE(102)
		faceVisited->get(currFace);
		HX_STACK_LINE(104)
		(numIter)++;
		HX_STACK_LINE(105)
		if (((numIter == (int)50))){
			HX_STACK_LINE(107)
			Dynamic();
		}
		HX_STACK_LINE(109)
		iterEdge->set_fromFace(currFace);
		HX_STACK_LINE(110)
		while((true)){
			HX_STACK_LINE(112)
			::hxDaedalus::data::Edge _g6 = iterEdge->next();		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(112)
			currEdge = _g6;
			HX_STACK_LINE(113)
			if (((currEdge == null()))){
				HX_STACK_LINE(116)
				return ::hxDaedalus::data::math::Intersection_obj::ENull;
			}
			HX_STACK_LINE(118)
			int _g7 = ::hxDaedalus::data::math::Geom2D_obj::getRelativePosition(x,y,currEdge);		HX_STACK_VAR(_g7,"_g7");
			HX_STACK_LINE(118)
			relativPos = _g7;
			HX_STACK_LINE(110)
			if ((!(((bool((relativPos == (int)1)) || bool((relativPos == (int)0))))))){
				HX_STACK_LINE(110)
				break;
			}
		}
		HX_STACK_LINE(121)
		::hxDaedalus::data::Face _g8 = currEdge->get_rightFace();		HX_STACK_VAR(_g8,"_g8");
		HX_STACK_LINE(121)
		currFace = _g8;
	}
	HX_STACK_LINE(124)
	return objectContainer;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Geom2D_obj,locatePosition,return )

bool Geom2D_obj::isCircleIntersectingAnyConstraint( Float x,Float y,Float radius,::hxDaedalus::data::Mesh mesh){
	HX_STACK_FRAME("hxDaedalus.data.math.Geom2D","isCircleIntersectingAnyConstraint",0x39b463e7,"hxDaedalus.data.math.Geom2D.isCircleIntersectingAnyConstraint","hxDaedalus/data/math/Geom2D.hx",128,0x9a728514)
	HX_STACK_ARG(x,"x")
	HX_STACK_ARG(y,"y")
	HX_STACK_ARG(radius,"radius")
	HX_STACK_ARG(mesh,"mesh")
	struct _Function_1_1{
		inline static bool Block( ::hxDaedalus::data::Mesh &mesh,Float &x){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","hxDaedalus/data/math/Geom2D.hx",129,0x9a728514)
			{
				HX_STACK_LINE(129)
				Float _g = mesh->get_width();		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(129)
				return (x >= _g);
			}
			return null();
		}
	};
	struct _Function_1_2{
		inline static bool Block( ::hxDaedalus::data::Mesh &mesh,Float &y){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","hxDaedalus/data/math/Geom2D.hx",129,0x9a728514)
			{
				HX_STACK_LINE(129)
				Float _g1 = mesh->get_height();		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(129)
				return (y >= _g1);
			}
			return null();
		}
	};
	HX_STACK_LINE(129)
	if (((  ((!(((  ((!(((  ((!(((x <= (int)0))))) ? bool(_Function_1_1::Block(mesh,x)) : bool(true) ))))) ? bool((y <= (int)0)) : bool(true) ))))) ? bool(_Function_1_2::Block(mesh,y)) : bool(true) ))){
		HX_STACK_LINE(129)
		return true;
	}
	HX_STACK_LINE(131)
	::hxDaedalus::data::math::Intersection loc = ::hxDaedalus::data::math::Geom2D_obj::locatePosition(x,y,mesh);		HX_STACK_VAR(loc,"loc");
	HX_STACK_LINE(132)
	::hxDaedalus::data::Face face;		HX_STACK_VAR(face,"face");
	HX_STACK_LINE(133)
	switch( (int)(loc->__Index())){
		case (int)0: {
			HX_STACK_LINE(133)
			::hxDaedalus::data::Vertex vertex = (::hxDaedalus::data::math::Intersection(loc))->__Param(0);		HX_STACK_VAR(vertex,"vertex");
			HX_STACK_LINE(134)
			{
				HX_STACK_LINE(135)
				::hxDaedalus::data::Face _g2 = vertex->get_edge()->get_leftFace();		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(135)
				face = _g2;
			}
		}
		;break;
		case (int)1: {
			HX_STACK_LINE(133)
			::hxDaedalus::data::Edge edge = (::hxDaedalus::data::math::Intersection(loc))->__Param(0);		HX_STACK_VAR(edge,"edge");
			HX_STACK_LINE(136)
			{
				HX_STACK_LINE(137)
				::hxDaedalus::data::Face _g3 = edge->get_leftFace();		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(137)
				face = _g3;
			}
		}
		;break;
		case (int)2: {
			HX_STACK_LINE(133)
			::hxDaedalus::data::Face face_ = (::hxDaedalus::data::math::Intersection(loc))->__Param(0);		HX_STACK_VAR(face_,"face_");
			HX_STACK_LINE(139)
			face = face_;
		}
		;break;
		case (int)3: {
			HX_STACK_LINE(141)
			face = null();
		}
		;break;
	}
	HX_STACK_LINE(146)
	Float radiusSquared = (radius * radius);		HX_STACK_VAR(radiusSquared,"radiusSquared");
	HX_STACK_LINE(147)
	::hxDaedalus::data::math::Point2D pos;		HX_STACK_VAR(pos,"pos");
	HX_STACK_LINE(148)
	Float distSquared;		HX_STACK_VAR(distSquared,"distSquared");
	HX_STACK_LINE(149)
	::hxDaedalus::data::math::Point2D _g4 = face->get_edge()->get_originVertex()->get_pos();		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(149)
	pos = _g4;
	HX_STACK_LINE(150)
	distSquared = ((((pos->x - x)) * ((pos->x - x))) + (((pos->y - y)) * ((pos->y - y))));
	HX_STACK_LINE(151)
	if (((distSquared <= radiusSquared))){
		HX_STACK_LINE(153)
		return true;
	}
	HX_STACK_LINE(155)
	::hxDaedalus::data::math::Point2D _g5 = face->get_edge()->get_nextLeftEdge()->get_originVertex()->get_pos();		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(155)
	pos = _g5;
	HX_STACK_LINE(156)
	distSquared = ((((pos->x - x)) * ((pos->x - x))) + (((pos->y - y)) * ((pos->y - y))));
	HX_STACK_LINE(157)
	if (((distSquared <= radiusSquared))){
		HX_STACK_LINE(159)
		return true;
	}
	HX_STACK_LINE(161)
	::hxDaedalus::data::math::Point2D _g6 = face->get_edge()->get_nextLeftEdge()->get_nextLeftEdge()->get_originVertex()->get_pos();		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(161)
	pos = _g6;
	HX_STACK_LINE(162)
	distSquared = ((((pos->x - x)) * ((pos->x - x))) + (((pos->y - y)) * ((pos->y - y))));
	HX_STACK_LINE(163)
	if (((distSquared <= radiusSquared))){
		HX_STACK_LINE(165)
		return true;
	}
	HX_STACK_LINE(170)
	Array< ::Dynamic > edgesToCheck = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(edgesToCheck,"edgesToCheck");
	HX_STACK_LINE(171)
	::hxDaedalus::data::Edge _g7 = face->get_edge();		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(171)
	edgesToCheck->push(_g7);
	HX_STACK_LINE(172)
	::hxDaedalus::data::Edge _g8 = face->get_edge()->get_nextLeftEdge();		HX_STACK_VAR(_g8,"_g8");
	HX_STACK_LINE(172)
	edgesToCheck->push(_g8);
	HX_STACK_LINE(173)
	::hxDaedalus::data::Edge _g9 = face->get_edge()->get_nextLeftEdge()->get_nextLeftEdge();		HX_STACK_VAR(_g9,"_g9");
	HX_STACK_LINE(173)
	edgesToCheck->push(_g9);
	HX_STACK_LINE(175)
	::hxDaedalus::data::Edge edge;		HX_STACK_VAR(edge,"edge");
	HX_STACK_LINE(176)
	::hxDaedalus::data::math::Point2D pos1;		HX_STACK_VAR(pos1,"pos1");
	HX_STACK_LINE(177)
	::hxDaedalus::data::math::Point2D pos2;		HX_STACK_VAR(pos2,"pos2");
	HX_STACK_LINE(178)
	::haxe::ds::ObjectMap checkedEdges = ::haxe::ds::ObjectMap_obj::__new();		HX_STACK_VAR(checkedEdges,"checkedEdges");
	HX_STACK_LINE(179)
	bool intersecting;		HX_STACK_VAR(intersecting,"intersecting");
	HX_STACK_LINE(180)
	while((true)){
		HX_STACK_LINE(180)
		if ((!(((edgesToCheck->length > (int)0))))){
			HX_STACK_LINE(180)
			break;
		}
		HX_STACK_LINE(182)
		::hxDaedalus::data::Edge _g10 = edgesToCheck->pop().StaticCast< ::hxDaedalus::data::Edge >();		HX_STACK_VAR(_g10,"_g10");
		HX_STACK_LINE(182)
		edge = _g10;
		HX_STACK_LINE(183)
		{
			HX_STACK_LINE(183)
			checkedEdges->set(edge,true);
			HX_STACK_LINE(183)
			true;
		}
		HX_STACK_LINE(184)
		::hxDaedalus::data::math::Point2D _g11 = edge->get_originVertex()->get_pos();		HX_STACK_VAR(_g11,"_g11");
		HX_STACK_LINE(184)
		pos1 = _g11;
		HX_STACK_LINE(185)
		::hxDaedalus::data::math::Point2D _g12 = edge->get_destinationVertex()->get_pos();		HX_STACK_VAR(_g12,"_g12");
		HX_STACK_LINE(185)
		pos2 = _g12;
		HX_STACK_LINE(186)
		bool _g13 = ::hxDaedalus::data::math::Geom2D_obj::intersectionsSegmentCircle(pos1->x,pos1->y,pos2->x,pos2->y,x,y,radius,null());		HX_STACK_VAR(_g13,"_g13");
		HX_STACK_LINE(186)
		intersecting = _g13;
		HX_STACK_LINE(187)
		if ((intersecting)){
			HX_STACK_LINE(189)
			if ((edge->get_isConstrained())){
				HX_STACK_LINE(190)
				return true;
			}
			else{
				HX_STACK_LINE(192)
				::hxDaedalus::data::Edge _g14 = edge->get_oppositeEdge()->get_nextLeftEdge();		HX_STACK_VAR(_g14,"_g14");
				HX_STACK_LINE(192)
				edge = _g14;
				struct _Function_4_1{
					inline static Dynamic Block( ::hxDaedalus::data::Edge &edge,::haxe::ds::ObjectMap &checkedEdges){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","hxDaedalus/data/math/Geom2D.hx",193,0x9a728514)
						{
							HX_STACK_LINE(193)
							::hxDaedalus::data::Edge key = edge->get_oppositeEdge();		HX_STACK_VAR(key,"key");
							HX_STACK_LINE(193)
							return checkedEdges->get(key);
						}
						return null();
					}
				};
				struct _Function_4_2{
					inline static bool Block( ::hxDaedalus::data::Edge &edge,Array< ::Dynamic > &edgesToCheck){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","hxDaedalus/data/math/Geom2D.hx",193,0x9a728514)
						{
							HX_STACK_LINE(193)
							int _g15 = edgesToCheck->indexOf(edge,null());		HX_STACK_VAR(_g15,"_g15");
							HX_STACK_LINE(193)
							return (_g15 == (int)-1);
						}
						return null();
					}
				};
				struct _Function_4_3{
					inline static bool Block( ::hxDaedalus::data::Edge &edge,Array< ::Dynamic > &edgesToCheck){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","hxDaedalus/data/math/Geom2D.hx",193,0x9a728514)
						{
							HX_STACK_LINE(193)
							::hxDaedalus::data::Edge _g16 = edge->get_oppositeEdge();		HX_STACK_VAR(_g16,"_g16");
							HX_STACK_LINE(193)
							int _g17 = edgesToCheck->indexOf(_g16,null());		HX_STACK_VAR(_g17,"_g17");
							HX_STACK_LINE(193)
							return (_g17 == (int)-1);
						}
						return null();
					}
				};
				HX_STACK_LINE(193)
				if (((  (((  (((  ((!(checkedEdges->get(edge)))) ? bool(!(_Function_4_1::Block(edge,checkedEdges))) : bool(false) ))) ? bool(_Function_4_2::Block(edge,edgesToCheck)) : bool(false) ))) ? bool(_Function_4_3::Block(edge,edgesToCheck)) : bool(false) ))){
					HX_STACK_LINE(195)
					edgesToCheck->push(edge);
				}
				HX_STACK_LINE(197)
				::hxDaedalus::data::Edge _g18 = edge->get_nextLeftEdge();		HX_STACK_VAR(_g18,"_g18");
				HX_STACK_LINE(197)
				edge = _g18;
				struct _Function_4_4{
					inline static Dynamic Block( ::hxDaedalus::data::Edge &edge,::haxe::ds::ObjectMap &checkedEdges){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","hxDaedalus/data/math/Geom2D.hx",198,0x9a728514)
						{
							HX_STACK_LINE(198)
							::hxDaedalus::data::Edge key = edge->get_oppositeEdge();		HX_STACK_VAR(key,"key");
							HX_STACK_LINE(198)
							return checkedEdges->get(key);
						}
						return null();
					}
				};
				struct _Function_4_5{
					inline static bool Block( ::hxDaedalus::data::Edge &edge,Array< ::Dynamic > &edgesToCheck){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","hxDaedalus/data/math/Geom2D.hx",198,0x9a728514)
						{
							HX_STACK_LINE(198)
							int _g19 = edgesToCheck->indexOf(edge,null());		HX_STACK_VAR(_g19,"_g19");
							HX_STACK_LINE(198)
							return (_g19 == (int)-1);
						}
						return null();
					}
				};
				struct _Function_4_6{
					inline static bool Block( ::hxDaedalus::data::Edge &edge,Array< ::Dynamic > &edgesToCheck){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","hxDaedalus/data/math/Geom2D.hx",198,0x9a728514)
						{
							HX_STACK_LINE(198)
							::hxDaedalus::data::Edge _g20 = edge->get_oppositeEdge();		HX_STACK_VAR(_g20,"_g20");
							HX_STACK_LINE(198)
							int _g21 = edgesToCheck->indexOf(_g20,null());		HX_STACK_VAR(_g21,"_g21");
							HX_STACK_LINE(198)
							return (_g21 == (int)-1);
						}
						return null();
					}
				};
				HX_STACK_LINE(198)
				if (((  (((  (((  ((!(checkedEdges->get(edge)))) ? bool(!(_Function_4_4::Block(edge,checkedEdges))) : bool(false) ))) ? bool(_Function_4_5::Block(edge,edgesToCheck)) : bool(false) ))) ? bool(_Function_4_6::Block(edge,edgesToCheck)) : bool(false) ))){
					HX_STACK_LINE(200)
					edgesToCheck->push(edge);
				}
			}
		}
	}
	HX_STACK_LINE(206)
	return false;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Geom2D_obj,isCircleIntersectingAnyConstraint,return )

int Geom2D_obj::getDirection( Float x1,Float y1,Float x2,Float y2,Float x3,Float y3){
	HX_STACK_FRAME("hxDaedalus.data.math.Geom2D","getDirection",0xbbf134ce,"hxDaedalus.data.math.Geom2D.getDirection","hxDaedalus/data/math/Geom2D.hx",215,0x9a728514)
	HX_STACK_ARG(x1,"x1")
	HX_STACK_ARG(y1,"y1")
	HX_STACK_ARG(x2,"x2")
	HX_STACK_ARG(y2,"y2")
	HX_STACK_ARG(x3,"x3")
	HX_STACK_ARG(y3,"y3")
	HX_STACK_LINE(218)
	Float dot = ((((x3 - x1)) * ((y2 - y1))) + (((y3 - y1)) * ((-(x2) + x1))));		HX_STACK_VAR(dot,"dot");
	HX_STACK_LINE(221)
	if (((dot == (int)0))){
		HX_STACK_LINE(221)
		return (int)0;
	}
	else{
		HX_STACK_LINE(221)
		if (((dot > (int)0))){
			HX_STACK_LINE(221)
			return (int)1;
		}
		else{
			HX_STACK_LINE(221)
			return (int)-1;
		}
	}
	HX_STACK_LINE(221)
	return (int)0;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC6(Geom2D_obj,getDirection,return )

int Geom2D_obj::getDirection2( Float x1,Float y1,Float x2,Float y2,Float x3,Float y3){
	HX_STACK_FRAME("hxDaedalus.data.math.Geom2D","getDirection2",0xb71cffa4,"hxDaedalus.data.math.Geom2D.getDirection2","hxDaedalus/data/math/Geom2D.hx",231,0x9a728514)
	HX_STACK_ARG(x1,"x1")
	HX_STACK_ARG(y1,"y1")
	HX_STACK_ARG(x2,"x2")
	HX_STACK_ARG(y2,"y2")
	HX_STACK_ARG(x3,"x3")
	HX_STACK_ARG(y3,"y3")
	HX_STACK_LINE(233)
	Float dot = ((((x3 - x1)) * ((y2 - y1))) + (((y3 - y1)) * ((-(x2) + x1))));		HX_STACK_VAR(dot,"dot");
	HX_STACK_LINE(236)
	if (((dot == (int)0))){
		HX_STACK_LINE(238)
		return (int)0;
	}
	else{
		HX_STACK_LINE(240)
		if (((dot > (int)0))){
			HX_STACK_LINE(242)
			Float _g = ::hxDaedalus::data::math::Geom2D_obj::distanceSquaredPointToLine(x3,y3,x1,y1,x2,y2);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(242)
			if (((_g <= 0.0001))){
				HX_STACK_LINE(243)
				return (int)0;
			}
			else{
				HX_STACK_LINE(245)
				return (int)1;
			}
		}
		else{
			HX_STACK_LINE(250)
			Float _g1 = ::hxDaedalus::data::math::Geom2D_obj::distanceSquaredPointToLine(x3,y3,x1,y1,x2,y2);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(250)
			if (((_g1 <= 0.0001))){
				HX_STACK_LINE(251)
				return (int)0;
			}
			else{
				HX_STACK_LINE(253)
				return (int)-1;
			}
		}
	}
	HX_STACK_LINE(256)
	return (int)0;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC6(Geom2D_obj,getDirection2,return )

int Geom2D_obj::getRelativePosition( Float x,Float y,::hxDaedalus::data::Edge eUp){
	HX_STACK_FRAME("hxDaedalus.data.math.Geom2D","getRelativePosition",0xaf17f2e6,"hxDaedalus.data.math.Geom2D.getRelativePosition","hxDaedalus/data/math/Geom2D.hx",266,0x9a728514)
	HX_STACK_ARG(x,"x")
	HX_STACK_ARG(y,"y")
	HX_STACK_ARG(eUp,"eUp")
	HX_STACK_LINE(266)
	return ::hxDaedalus::data::math::Geom2D_obj::getDirection(eUp->get_originVertex()->get_pos()->x,eUp->get_originVertex()->get_pos()->y,eUp->get_destinationVertex()->get_pos()->x,eUp->get_destinationVertex()->get_pos()->y,x,y);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Geom2D_obj,getRelativePosition,return )

int Geom2D_obj::getRelativePosition2( Float x,Float y,::hxDaedalus::data::Edge eUp){
	HX_STACK_FRAME("hxDaedalus.data.math.Geom2D","getRelativePosition2",0x85dc968c,"hxDaedalus.data.math.Geom2D.getRelativePosition2","hxDaedalus/data/math/Geom2D.hx",271,0x9a728514)
	HX_STACK_ARG(x,"x")
	HX_STACK_ARG(y,"y")
	HX_STACK_ARG(eUp,"eUp")
	HX_STACK_LINE(271)
	return ::hxDaedalus::data::math::Geom2D_obj::getDirection2(eUp->get_originVertex()->get_pos()->x,eUp->get_originVertex()->get_pos()->y,eUp->get_destinationVertex()->get_pos()->x,eUp->get_destinationVertex()->get_pos()->y,x,y);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Geom2D_obj,getRelativePosition2,return )

::hxDaedalus::data::math::Intersection Geom2D_obj::isInFace( Float x,Float y,::hxDaedalus::data::Face polygon){
	HX_STACK_FRAME("hxDaedalus.data.math.Geom2D","isInFace",0x2a20be31,"hxDaedalus.data.math.Geom2D.isInFace","hxDaedalus/data/math/Geom2D.hx",280,0x9a728514)
	HX_STACK_ARG(x,"x")
	HX_STACK_ARG(y,"y")
	HX_STACK_ARG(polygon,"polygon")
	HX_STACK_LINE(284)
	::hxDaedalus::data::math::Intersection result = ::hxDaedalus::data::math::Intersection_obj::ENull;		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(286)
	::hxDaedalus::data::Edge e1_2 = polygon->get_edge();		HX_STACK_VAR(e1_2,"e1_2");
	HX_STACK_LINE(287)
	::hxDaedalus::data::Edge e2_3 = e1_2->get_nextLeftEdge();		HX_STACK_VAR(e2_3,"e2_3");
	HX_STACK_LINE(288)
	::hxDaedalus::data::Edge e3_1 = e2_3->get_nextLeftEdge();		HX_STACK_VAR(e3_1,"e3_1");
	HX_STACK_LINE(289)
	int _g = ::hxDaedalus::data::math::Geom2D_obj::getRelativePosition(x,y,e1_2);		HX_STACK_VAR(_g,"_g");
	struct _Function_1_1{
		inline static bool Block( Float &x,Float &y,::hxDaedalus::data::Edge &e2_3){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","hxDaedalus/data/math/Geom2D.hx",289,0x9a728514)
			{
				HX_STACK_LINE(289)
				int _g1 = ::hxDaedalus::data::math::Geom2D_obj::getRelativePosition(x,y,e2_3);		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(289)
				return (_g1 >= (int)0);
			}
			return null();
		}
	};
	struct _Function_1_2{
		inline static bool Block( ::hxDaedalus::data::Edge &e3_1,Float &x,Float &y){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","hxDaedalus/data/math/Geom2D.hx",289,0x9a728514)
			{
				HX_STACK_LINE(289)
				int _g2 = ::hxDaedalus::data::math::Geom2D_obj::getRelativePosition(x,y,e3_1);		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(289)
				return (_g2 >= (int)0);
			}
			return null();
		}
	};
	HX_STACK_LINE(289)
	if (((  (((  (((_g >= (int)0))) ? bool(_Function_1_1::Block(x,y,e2_3)) : bool(false) ))) ? bool(_Function_1_2::Block(e3_1,x,y)) : bool(false) ))){
		HX_STACK_LINE(291)
		::hxDaedalus::data::Vertex v1 = e1_2->get_originVertex();		HX_STACK_VAR(v1,"v1");
		HX_STACK_LINE(292)
		::hxDaedalus::data::Vertex v2 = e2_3->get_originVertex();		HX_STACK_VAR(v2,"v2");
		HX_STACK_LINE(293)
		::hxDaedalus::data::Vertex v3 = e3_1->get_originVertex();		HX_STACK_VAR(v3,"v3");
		HX_STACK_LINE(295)
		Float x1 = v1->get_pos()->x;		HX_STACK_VAR(x1,"x1");
		HX_STACK_LINE(296)
		Float y1 = v1->get_pos()->y;		HX_STACK_VAR(y1,"y1");
		HX_STACK_LINE(297)
		Float x2 = v2->get_pos()->x;		HX_STACK_VAR(x2,"x2");
		HX_STACK_LINE(298)
		Float y2 = v2->get_pos()->y;		HX_STACK_VAR(y2,"y2");
		HX_STACK_LINE(299)
		Float x3 = v3->get_pos()->x;		HX_STACK_VAR(x3,"x3");
		HX_STACK_LINE(300)
		Float y3 = v3->get_pos()->y;		HX_STACK_VAR(y3,"y3");
		HX_STACK_LINE(302)
		Float v_v1squaredLength = ((((x1 - x)) * ((x1 - x))) + (((y1 - y)) * ((y1 - y))));		HX_STACK_VAR(v_v1squaredLength,"v_v1squaredLength");
		HX_STACK_LINE(303)
		Float v_v2squaredLength = ((((x2 - x)) * ((x2 - x))) + (((y2 - y)) * ((y2 - y))));		HX_STACK_VAR(v_v2squaredLength,"v_v2squaredLength");
		HX_STACK_LINE(304)
		Float v_v3squaredLength = ((((x3 - x)) * ((x3 - x))) + (((y3 - y)) * ((y3 - y))));		HX_STACK_VAR(v_v3squaredLength,"v_v3squaredLength");
		HX_STACK_LINE(305)
		Float v1_v2squaredLength = ((((x2 - x1)) * ((x2 - x1))) + (((y2 - y1)) * ((y2 - y1))));		HX_STACK_VAR(v1_v2squaredLength,"v1_v2squaredLength");
		HX_STACK_LINE(306)
		Float v2_v3squaredLength = ((((x3 - x2)) * ((x3 - x2))) + (((y3 - y2)) * ((y3 - y2))));		HX_STACK_VAR(v2_v3squaredLength,"v2_v3squaredLength");
		HX_STACK_LINE(307)
		Float v3_v1squaredLength = ((((x1 - x3)) * ((x1 - x3))) + (((y1 - y3)) * ((y1 - y3))));		HX_STACK_VAR(v3_v1squaredLength,"v3_v1squaredLength");
		HX_STACK_LINE(309)
		Float dot_v_v1v2 = ((((x - x1)) * ((x2 - x1))) + (((y - y1)) * ((y2 - y1))));		HX_STACK_VAR(dot_v_v1v2,"dot_v_v1v2");
		HX_STACK_LINE(310)
		Float dot_v_v2v3 = ((((x - x2)) * ((x3 - x2))) + (((y - y2)) * ((y3 - y2))));		HX_STACK_VAR(dot_v_v2v3,"dot_v_v2v3");
		HX_STACK_LINE(311)
		Float dot_v_v3v1 = ((((x - x3)) * ((x1 - x3))) + (((y - y3)) * ((y1 - y3))));		HX_STACK_VAR(dot_v_v3v1,"dot_v_v3v1");
		HX_STACK_LINE(313)
		Float v_e1_2squaredLength = (v_v1squaredLength - (Float((dot_v_v1v2 * dot_v_v1v2)) / Float(v1_v2squaredLength)));		HX_STACK_VAR(v_e1_2squaredLength,"v_e1_2squaredLength");
		HX_STACK_LINE(314)
		Float v_e2_3squaredLength = (v_v2squaredLength - (Float((dot_v_v2v3 * dot_v_v2v3)) / Float(v2_v3squaredLength)));		HX_STACK_VAR(v_e2_3squaredLength,"v_e2_3squaredLength");
		HX_STACK_LINE(315)
		Float v_e3_1squaredLength = (v_v3squaredLength - (Float((dot_v_v3v1 * dot_v_v3v1)) / Float(v3_v1squaredLength)));		HX_STACK_VAR(v_e3_1squaredLength,"v_e3_1squaredLength");
		HX_STACK_LINE(317)
		bool closeTo_e1_2 = (v_e1_2squaredLength <= 0.0001);		HX_STACK_VAR(closeTo_e1_2,"closeTo_e1_2");
		HX_STACK_LINE(318)
		bool closeTo_e2_3 = (v_e2_3squaredLength <= 0.0001);		HX_STACK_VAR(closeTo_e2_3,"closeTo_e2_3");
		HX_STACK_LINE(319)
		bool closeTo_e3_1 = (v_e3_1squaredLength <= 0.0001);		HX_STACK_VAR(closeTo_e3_1,"closeTo_e3_1");
		HX_STACK_LINE(321)
		if ((closeTo_e1_2)){
			HX_STACK_LINE(322)
			if ((closeTo_e3_1)){
				HX_STACK_LINE(323)
				::hxDaedalus::data::math::Intersection _g3 = ::hxDaedalus::data::math::Intersection_obj::EVertex(v1);		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(323)
				result = _g3;
			}
			else{
				HX_STACK_LINE(324)
				if ((closeTo_e2_3)){
					HX_STACK_LINE(325)
					::hxDaedalus::data::math::Intersection _g4 = ::hxDaedalus::data::math::Intersection_obj::EVertex(v2);		HX_STACK_VAR(_g4,"_g4");
					HX_STACK_LINE(325)
					result = _g4;
				}
				else{
					HX_STACK_LINE(327)
					::hxDaedalus::data::math::Intersection _g5 = ::hxDaedalus::data::math::Intersection_obj::EEdge(e1_2);		HX_STACK_VAR(_g5,"_g5");
					HX_STACK_LINE(327)
					result = _g5;
				}
			}
		}
		else{
			HX_STACK_LINE(329)
			if ((closeTo_e2_3)){
				HX_STACK_LINE(330)
				if ((closeTo_e3_1)){
					HX_STACK_LINE(331)
					::hxDaedalus::data::math::Intersection _g6 = ::hxDaedalus::data::math::Intersection_obj::EVertex(v3);		HX_STACK_VAR(_g6,"_g6");
					HX_STACK_LINE(331)
					result = _g6;
				}
				else{
					HX_STACK_LINE(333)
					::hxDaedalus::data::math::Intersection _g7 = ::hxDaedalus::data::math::Intersection_obj::EEdge(e2_3);		HX_STACK_VAR(_g7,"_g7");
					HX_STACK_LINE(333)
					result = _g7;
				}
			}
			else{
				HX_STACK_LINE(335)
				if ((closeTo_e3_1)){
					HX_STACK_LINE(336)
					::hxDaedalus::data::math::Intersection _g8 = ::hxDaedalus::data::math::Intersection_obj::EEdge(e3_1);		HX_STACK_VAR(_g8,"_g8");
					HX_STACK_LINE(336)
					result = _g8;
				}
				else{
					HX_STACK_LINE(338)
					::hxDaedalus::data::math::Intersection _g9 = ::hxDaedalus::data::math::Intersection_obj::EFace(polygon);		HX_STACK_VAR(_g9,"_g9");
					HX_STACK_LINE(338)
					result = _g9;
				}
			}
		}
	}
	HX_STACK_LINE(342)
	return result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Geom2D_obj,isInFace,return )

bool Geom2D_obj::clipSegmentByTriangle( Float s1x,Float s1y,Float s2x,Float s2y,Float t1x,Float t1y,Float t2x,Float t2y,Float t3x,Float t3y,::hxDaedalus::data::math::Point2D pResult1,::hxDaedalus::data::math::Point2D pResult2){
	HX_STACK_FRAME("hxDaedalus.data.math.Geom2D","clipSegmentByTriangle",0xbdce99bd,"hxDaedalus.data.math.Geom2D.clipSegmentByTriangle","hxDaedalus/data/math/Geom2D.hx",355,0x9a728514)
	HX_STACK_ARG(s1x,"s1x")
	HX_STACK_ARG(s1y,"s1y")
	HX_STACK_ARG(s2x,"s2x")
	HX_STACK_ARG(s2y,"s2y")
	HX_STACK_ARG(t1x,"t1x")
	HX_STACK_ARG(t1y,"t1y")
	HX_STACK_ARG(t2x,"t2x")
	HX_STACK_ARG(t2y,"t2y")
	HX_STACK_ARG(t3x,"t3x")
	HX_STACK_ARG(t3y,"t3y")
	HX_STACK_ARG(pResult1,"pResult1")
	HX_STACK_ARG(pResult2,"pResult2")
	HX_STACK_LINE(356)
	int side1_1;		HX_STACK_VAR(side1_1,"side1_1");
	HX_STACK_LINE(357)
	int side1_2;		HX_STACK_VAR(side1_2,"side1_2");
	HX_STACK_LINE(358)
	int _g = ::hxDaedalus::data::math::Geom2D_obj::getDirection(t1x,t1y,t2x,t2y,s1x,s1y);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(358)
	side1_1 = _g;
	HX_STACK_LINE(359)
	int _g1 = ::hxDaedalus::data::math::Geom2D_obj::getDirection(t1x,t1y,t2x,t2y,s2x,s2y);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(359)
	side1_2 = _g1;
	HX_STACK_LINE(361)
	if (((bool((side1_1 <= (int)0)) && bool((side1_2 <= (int)0))))){
		HX_STACK_LINE(362)
		return false;
	}
	HX_STACK_LINE(364)
	int side2_1;		HX_STACK_VAR(side2_1,"side2_1");
	HX_STACK_LINE(365)
	int side2_2;		HX_STACK_VAR(side2_2,"side2_2");
	HX_STACK_LINE(366)
	int _g2 = ::hxDaedalus::data::math::Geom2D_obj::getDirection(t2x,t2y,t3x,t3y,s1x,s1y);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(366)
	side2_1 = _g2;
	HX_STACK_LINE(367)
	int _g3 = ::hxDaedalus::data::math::Geom2D_obj::getDirection(t2x,t2y,t3x,t3y,s2x,s2y);		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(367)
	side2_2 = _g3;
	HX_STACK_LINE(369)
	if (((bool((side2_1 <= (int)0)) && bool((side2_2 <= (int)0))))){
		HX_STACK_LINE(370)
		return false;
	}
	HX_STACK_LINE(372)
	int side3_1;		HX_STACK_VAR(side3_1,"side3_1");
	HX_STACK_LINE(373)
	int side3_2;		HX_STACK_VAR(side3_2,"side3_2");
	HX_STACK_LINE(374)
	int _g4 = ::hxDaedalus::data::math::Geom2D_obj::getDirection(t3x,t3y,t1x,t1y,s1x,s1y);		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(374)
	side3_1 = _g4;
	HX_STACK_LINE(375)
	int _g5 = ::hxDaedalus::data::math::Geom2D_obj::getDirection(t3x,t3y,t1x,t1y,s2x,s2y);		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(375)
	side3_2 = _g5;
	HX_STACK_LINE(377)
	if (((bool((side3_1 <= (int)0)) && bool((side3_2 <= (int)0))))){
		HX_STACK_LINE(378)
		return false;
	}
	HX_STACK_LINE(382)
	if (((bool((bool((bool((side1_1 >= (int)0)) && bool((side2_1 >= (int)0)))) && bool((side3_1 >= (int)0)))) && bool(((bool((bool((side1_2 >= (int)0)) && bool((side2_2 >= (int)0)))) && bool((side3_2 >= (int)0)))))))){
		HX_STACK_LINE(384)
		pResult1->x = s1x;
		HX_STACK_LINE(385)
		pResult1->y = s1y;
		HX_STACK_LINE(386)
		pResult2->x = s2x;
		HX_STACK_LINE(387)
		pResult2->y = s2y;
		HX_STACK_LINE(388)
		return true;
	}
	HX_STACK_LINE(391)
	int n = (int)0;		HX_STACK_VAR(n,"n");
	HX_STACK_LINE(393)
	if ((::hxDaedalus::data::math::Geom2D_obj::intersections2segments(s1x,s1y,s2x,s2y,t1x,t1y,t2x,t2y,pResult1,null(),null()))){
		HX_STACK_LINE(395)
		(n)++;
	}
	HX_STACK_LINE(400)
	if (((n == (int)0))){
		HX_STACK_LINE(403)
		if ((::hxDaedalus::data::math::Geom2D_obj::intersections2segments(s1x,s1y,s2x,s2y,t2x,t2y,t3x,t3y,pResult1,null(),null()))){
			HX_STACK_LINE(405)
			(n)++;
		}
	}
	else{
		HX_STACK_LINE(410)
		if ((::hxDaedalus::data::math::Geom2D_obj::intersections2segments(s1x,s1y,s2x,s2y,t2x,t2y,t3x,t3y,pResult2,null(),null()))){
			HX_STACK_LINE(413)
			if (((bool((bool((bool((-0.01 > (pResult1->x - pResult2->x))) || bool(((pResult1->x - pResult2->x) > 0.01)))) || bool((-0.01 > (pResult1->y - pResult2->y))))) || bool(((pResult1->y - pResult2->y) > 0.01))))){
				HX_STACK_LINE(415)
				(n)++;
			}
		}
	}
	HX_STACK_LINE(422)
	if (((n == (int)0))){
		HX_STACK_LINE(424)
		if ((::hxDaedalus::data::math::Geom2D_obj::intersections2segments(s1x,s1y,s2x,s2y,t3x,t3y,t1x,t1y,pResult1,null(),null()))){
			HX_STACK_LINE(426)
			(n)++;
		}
	}
	else{
		HX_STACK_LINE(430)
		if (((n == (int)1))){
			HX_STACK_LINE(432)
			if ((::hxDaedalus::data::math::Geom2D_obj::intersections2segments(s1x,s1y,s2x,s2y,t3x,t3y,t1x,t1y,pResult2,null(),null()))){
				HX_STACK_LINE(434)
				if (((bool((bool((bool((-0.01 > (pResult1->x - pResult2->x))) || bool(((pResult1->x - pResult2->x) > 0.01)))) || bool((-0.01 > (pResult1->y - pResult2->y))))) || bool(((pResult1->y - pResult2->y) > 0.01))))){
					HX_STACK_LINE(436)
					(n)++;
				}
			}
		}
	}
	HX_STACK_LINE(443)
	if (((n == (int)1))){
		HX_STACK_LINE(445)
		if (((bool((bool((side1_1 >= (int)0)) && bool((side2_1 >= (int)0)))) && bool((side3_1 >= (int)0))))){
			HX_STACK_LINE(447)
			pResult2->x = s1x;
			HX_STACK_LINE(448)
			pResult2->y = s1y;
		}
		else{
			HX_STACK_LINE(450)
			if (((bool((bool((side1_2 >= (int)0)) && bool((side2_2 >= (int)0)))) && bool((side3_2 >= (int)0))))){
				HX_STACK_LINE(452)
				pResult2->x = s2x;
				HX_STACK_LINE(453)
				pResult2->y = s2y;
			}
			else{
				HX_STACK_LINE(458)
				n = (int)0;
			}
		}
	}
	HX_STACK_LINE(462)
	if (((n > (int)0))){
		HX_STACK_LINE(463)
		return true;
	}
	else{
		HX_STACK_LINE(465)
		return false;
	}
	HX_STACK_LINE(462)
	return false;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC12(Geom2D_obj,clipSegmentByTriangle,return )

bool Geom2D_obj::isSegmentIntersectingTriangle( Float s1x,Float s1y,Float s2x,Float s2y,Float t1x,Float t1y,Float t2x,Float t2y,Float t3x,Float t3y){
	HX_STACK_FRAME("hxDaedalus.data.math.Geom2D","isSegmentIntersectingTriangle",0x78216f2f,"hxDaedalus.data.math.Geom2D.isSegmentIntersectingTriangle","hxDaedalus/data/math/Geom2D.hx",470,0x9a728514)
	HX_STACK_ARG(s1x,"s1x")
	HX_STACK_ARG(s1y,"s1y")
	HX_STACK_ARG(s2x,"s2x")
	HX_STACK_ARG(s2y,"s2y")
	HX_STACK_ARG(t1x,"t1x")
	HX_STACK_ARG(t1y,"t1y")
	HX_STACK_ARG(t2x,"t2x")
	HX_STACK_ARG(t2y,"t2y")
	HX_STACK_ARG(t3x,"t3x")
	HX_STACK_ARG(t3y,"t3y")
	HX_STACK_LINE(473)
	int side1_1;		HX_STACK_VAR(side1_1,"side1_1");
	HX_STACK_LINE(474)
	int side1_2;		HX_STACK_VAR(side1_2,"side1_2");
	HX_STACK_LINE(475)
	int _g = ::hxDaedalus::data::math::Geom2D_obj::getDirection(t1x,t1y,t2x,t2y,s1x,s1y);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(475)
	side1_1 = _g;
	HX_STACK_LINE(476)
	int _g1 = ::hxDaedalus::data::math::Geom2D_obj::getDirection(t1x,t1y,t2x,t2y,s2x,s2y);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(476)
	side1_2 = _g1;
	HX_STACK_LINE(478)
	if (((bool((side1_1 <= (int)0)) && bool((side1_2 <= (int)0))))){
		HX_STACK_LINE(479)
		return false;
	}
	HX_STACK_LINE(481)
	int side2_1;		HX_STACK_VAR(side2_1,"side2_1");
	HX_STACK_LINE(482)
	int side2_2;		HX_STACK_VAR(side2_2,"side2_2");
	HX_STACK_LINE(483)
	int _g2 = ::hxDaedalus::data::math::Geom2D_obj::getDirection(t2x,t2y,t3x,t3y,s1x,s1y);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(483)
	side2_1 = _g2;
	HX_STACK_LINE(484)
	int _g3 = ::hxDaedalus::data::math::Geom2D_obj::getDirection(t2x,t2y,t3x,t3y,s2x,s2y);		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(484)
	side2_2 = _g3;
	HX_STACK_LINE(486)
	if (((bool((side2_1 <= (int)0)) && bool((side2_2 <= (int)0))))){
		HX_STACK_LINE(487)
		return false;
	}
	HX_STACK_LINE(489)
	int side3_1;		HX_STACK_VAR(side3_1,"side3_1");
	HX_STACK_LINE(490)
	int side3_2;		HX_STACK_VAR(side3_2,"side3_2");
	HX_STACK_LINE(491)
	int _g4 = ::hxDaedalus::data::math::Geom2D_obj::getDirection(t3x,t3y,t1x,t1y,s1x,s1y);		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(491)
	side3_1 = _g4;
	HX_STACK_LINE(492)
	int _g5 = ::hxDaedalus::data::math::Geom2D_obj::getDirection(t3x,t3y,t1x,t1y,s2x,s2y);		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(492)
	side3_2 = _g5;
	HX_STACK_LINE(494)
	if (((bool((side3_1 <= (int)0)) && bool((side3_2 <= (int)0))))){
		HX_STACK_LINE(495)
		return false;
	}
	HX_STACK_LINE(499)
	if (((bool((bool((side1_1 == (int)1)) && bool((side2_1 == (int)1)))) && bool((side3_1 == (int)1))))){
		HX_STACK_LINE(500)
		return true;
	}
	HX_STACK_LINE(504)
	if (((bool((bool((side1_1 == (int)1)) && bool((side2_1 == (int)1)))) && bool((side3_1 == (int)1))))){
		HX_STACK_LINE(505)
		return true;
	}
	HX_STACK_LINE(507)
	int side1;		HX_STACK_VAR(side1,"side1");
	HX_STACK_LINE(508)
	int side2;		HX_STACK_VAR(side2,"side2");
	HX_STACK_LINE(510)
	if (((bool((bool((side1_1 == (int)1)) && bool((side1_2 <= (int)0)))) || bool((bool((side1_1 <= (int)0)) && bool((side1_2 == (int)1))))))){
		HX_STACK_LINE(512)
		int _g6 = ::hxDaedalus::data::math::Geom2D_obj::getDirection(s1x,s1y,s2x,s2y,t1x,t1y);		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(512)
		side1 = _g6;
		HX_STACK_LINE(513)
		int _g7 = ::hxDaedalus::data::math::Geom2D_obj::getDirection(s1x,s1y,s2x,s2y,t2x,t2y);		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(513)
		side2 = _g7;
		HX_STACK_LINE(514)
		if (((bool((bool((side1 == (int)1)) && bool((side2 <= (int)0)))) || bool((bool((side1 <= (int)0)) && bool((side2 == (int)1))))))){
			HX_STACK_LINE(516)
			return true;
		}
	}
	HX_STACK_LINE(520)
	if (((bool((bool((side2_1 == (int)1)) && bool((side2_2 <= (int)0)))) || bool((bool((side2_1 <= (int)0)) && bool((side2_2 == (int)1))))))){
		HX_STACK_LINE(522)
		int _g8 = ::hxDaedalus::data::math::Geom2D_obj::getDirection(s1x,s1y,s2x,s2y,t2x,t2y);		HX_STACK_VAR(_g8,"_g8");
		HX_STACK_LINE(522)
		side1 = _g8;
		HX_STACK_LINE(523)
		int _g9 = ::hxDaedalus::data::math::Geom2D_obj::getDirection(s1x,s1y,s2x,s2y,t3x,t3y);		HX_STACK_VAR(_g9,"_g9");
		HX_STACK_LINE(523)
		side2 = _g9;
		HX_STACK_LINE(524)
		if (((bool((bool((side1 == (int)1)) && bool((side2 <= (int)0)))) || bool((bool((side1 <= (int)0)) && bool((side2 == (int)1))))))){
			HX_STACK_LINE(526)
			return true;
		}
	}
	HX_STACK_LINE(530)
	if (((bool((bool((side3_1 == (int)1)) && bool((side3_2 <= (int)0)))) || bool((bool((side3_1 <= (int)0)) && bool((side3_2 == (int)1))))))){
		HX_STACK_LINE(532)
		int _g10 = ::hxDaedalus::data::math::Geom2D_obj::getDirection(s1x,s1y,s2x,s2y,t3x,t3y);		HX_STACK_VAR(_g10,"_g10");
		HX_STACK_LINE(532)
		side1 = _g10;
		HX_STACK_LINE(533)
		int _g11 = ::hxDaedalus::data::math::Geom2D_obj::getDirection(s1x,s1y,s2x,s2y,t1x,t1y);		HX_STACK_VAR(_g11,"_g11");
		HX_STACK_LINE(533)
		side2 = _g11;
		HX_STACK_LINE(534)
		if (((bool((bool((side1 == (int)1)) && bool((side2 <= (int)0)))) || bool((bool((side1 <= (int)0)) && bool((side2 == (int)1))))))){
			HX_STACK_LINE(536)
			return true;
		}
	}
	HX_STACK_LINE(540)
	return false;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC10(Geom2D_obj,isSegmentIntersectingTriangle,return )

::hxDaedalus::data::math::Point2D Geom2D_obj::__circumcenter;

bool Geom2D_obj::isDelaunay( ::hxDaedalus::data::Edge edge){
	HX_STACK_FRAME("hxDaedalus.data.math.Geom2D","isDelaunay",0x2bb0bb96,"hxDaedalus.data.math.Geom2D.isDelaunay","hxDaedalus/data/math/Geom2D.hx",545,0x9a728514)
	HX_STACK_ARG(edge,"edge")
	HX_STACK_LINE(546)
	::hxDaedalus::data::Vertex vLeft = edge->get_originVertex();		HX_STACK_VAR(vLeft,"vLeft");
	HX_STACK_LINE(547)
	::hxDaedalus::data::Vertex vRight = edge->get_destinationVertex();		HX_STACK_VAR(vRight,"vRight");
	HX_STACK_LINE(548)
	::hxDaedalus::data::Vertex vCorner = edge->get_nextLeftEdge()->get_destinationVertex();		HX_STACK_VAR(vCorner,"vCorner");
	HX_STACK_LINE(549)
	::hxDaedalus::data::Vertex vOpposite = edge->get_nextRightEdge()->get_destinationVertex();		HX_STACK_VAR(vOpposite,"vOpposite");
	HX_STACK_LINE(600)
	::hxDaedalus::data::math::Geom2D_obj::getCircumcenter(vCorner->get_pos()->x,vCorner->get_pos()->y,vLeft->get_pos()->x,vLeft->get_pos()->y,vRight->get_pos()->x,vRight->get_pos()->y,::hxDaedalus::data::math::Geom2D_obj::__circumcenter);
	HX_STACK_LINE(603)
	Float squaredRadius = ((((vCorner->get_pos()->x - ::hxDaedalus::data::math::Geom2D_obj::__circumcenter->x)) * ((vCorner->get_pos()->x - ::hxDaedalus::data::math::Geom2D_obj::__circumcenter->x))) + (((vCorner->get_pos()->y - ::hxDaedalus::data::math::Geom2D_obj::__circumcenter->y)) * ((vCorner->get_pos()->y - ::hxDaedalus::data::math::Geom2D_obj::__circumcenter->y))));		HX_STACK_VAR(squaredRadius,"squaredRadius");
	HX_STACK_LINE(604)
	Float squaredDistance = ((((vOpposite->get_pos()->x - ::hxDaedalus::data::math::Geom2D_obj::__circumcenter->x)) * ((vOpposite->get_pos()->x - ::hxDaedalus::data::math::Geom2D_obj::__circumcenter->x))) + (((vOpposite->get_pos()->y - ::hxDaedalus::data::math::Geom2D_obj::__circumcenter->y)) * ((vOpposite->get_pos()->y - ::hxDaedalus::data::math::Geom2D_obj::__circumcenter->y))));		HX_STACK_VAR(squaredDistance,"squaredDistance");
	HX_STACK_LINE(606)
	return (squaredDistance >= squaredRadius);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Geom2D_obj,isDelaunay,return )

::hxDaedalus::data::math::Point2D Geom2D_obj::getCircumcenter( Float x1,Float y1,Float x2,Float y2,Float x3,Float y3,::hxDaedalus::data::math::Point2D result){
	HX_STACK_FRAME("hxDaedalus.data.math.Geom2D","getCircumcenter",0x4af72dd5,"hxDaedalus.data.math.Geom2D.getCircumcenter","hxDaedalus/data/math/Geom2D.hx",610,0x9a728514)
	HX_STACK_ARG(x1,"x1")
	HX_STACK_ARG(y1,"y1")
	HX_STACK_ARG(x2,"x2")
	HX_STACK_ARG(y2,"y2")
	HX_STACK_ARG(x3,"x3")
	HX_STACK_ARG(y3,"y3")
	HX_STACK_ARG(result,"result")
	HX_STACK_LINE(611)
	if (((result == null()))){
		HX_STACK_LINE(613)
		::hxDaedalus::data::math::Point2D _g = ::hxDaedalus::data::math::Point2D_obj::__new(null(),null());		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(613)
		result = _g;
	}
	HX_STACK_LINE(618)
	Float m1 = (Float(((x1 + x2))) / Float((int)2));		HX_STACK_VAR(m1,"m1");
	HX_STACK_LINE(619)
	Float m2 = (Float(((y1 + y2))) / Float((int)2));		HX_STACK_VAR(m2,"m2");
	HX_STACK_LINE(620)
	Float m3 = (Float(((x1 + x3))) / Float((int)2));		HX_STACK_VAR(m3,"m3");
	HX_STACK_LINE(621)
	Float m4 = (Float(((y1 + y3))) / Float((int)2));		HX_STACK_VAR(m4,"m4");
	HX_STACK_LINE(641)
	Float t1 = (Float(((((m1 * ((x1 - x3))) + (((m2 - m4)) * ((y1 - y3)))) + (m3 * ((x3 - x1)))))) / Float(((((x1 * ((y3 - y2))) + (x2 * ((y1 - y3)))) + (x3 * ((y2 - y1)))))));		HX_STACK_VAR(t1,"t1");
	HX_STACK_LINE(643)
	result->x = (m1 + (t1 * ((y2 - y1))));
	HX_STACK_LINE(644)
	result->y = (m2 - (t1 * ((x2 - x1))));
	HX_STACK_LINE(646)
	return result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC7(Geom2D_obj,getCircumcenter,return )

bool Geom2D_obj::intersections2segments( Float s1p1x,Float s1p1y,Float s1p2x,Float s1p2y,Float s2p1x,Float s2p1y,Float s2p2x,Float s2p2y,::hxDaedalus::data::math::Point2D posIntersection,Array< Float > paramIntersection,hx::Null< bool >  __o_infiniteLineMode){
bool infiniteLineMode = __o_infiniteLineMode.Default(false);
	HX_STACK_FRAME("hxDaedalus.data.math.Geom2D","intersections2segments",0x4d7fce8d,"hxDaedalus.data.math.Geom2D.intersections2segments","hxDaedalus/data/math/Geom2D.hx",650,0x9a728514)
	HX_STACK_ARG(s1p1x,"s1p1x")
	HX_STACK_ARG(s1p1y,"s1p1y")
	HX_STACK_ARG(s1p2x,"s1p2x")
	HX_STACK_ARG(s1p2y,"s1p2y")
	HX_STACK_ARG(s2p1x,"s2p1x")
	HX_STACK_ARG(s2p1y,"s2p1y")
	HX_STACK_ARG(s2p2x,"s2p2x")
	HX_STACK_ARG(s2p2y,"s2p2y")
	HX_STACK_ARG(posIntersection,"posIntersection")
	HX_STACK_ARG(paramIntersection,"paramIntersection")
	HX_STACK_ARG(infiniteLineMode,"infiniteLineMode")
{
		HX_STACK_LINE(651)
		Float t1 = (int)0;		HX_STACK_VAR(t1,"t1");
		HX_STACK_LINE(652)
		Float t2 = (int)0;		HX_STACK_VAR(t2,"t2");
		HX_STACK_LINE(654)
		bool result;		HX_STACK_VAR(result,"result");
		HX_STACK_LINE(655)
		Float divisor = ((((s1p1x - s1p2x)) * ((s2p1y - s2p2y))) + (((s1p2y - s1p1y)) * ((s2p1x - s2p2x))));		HX_STACK_VAR(divisor,"divisor");
		HX_STACK_LINE(656)
		if (((divisor == (int)0))){
			HX_STACK_LINE(658)
			result = false;
		}
		else{
			HX_STACK_LINE(662)
			result = true;
			HX_STACK_LINE(664)
			if (((bool((bool(!(infiniteLineMode)) || bool((posIntersection != null())))) || bool((paramIntersection != null()))))){
				HX_STACK_LINE(667)
				t1 = (Float((((((s1p1x * ((s2p1y - s2p2y))) + (s1p1y * ((s2p2x - s2p1x)))) + (s2p1x * s2p2y)) - (s2p1y * s2p2x)))) / Float(divisor));
				HX_STACK_LINE(668)
				t2 = (Float((((((s1p1x * ((s2p1y - s1p2y))) + (s1p1y * ((s1p2x - s2p1x)))) - (s1p2x * s2p1y)) + (s1p2y * s2p1x)))) / Float(divisor));
				HX_STACK_LINE(669)
				if (((bool(!(infiniteLineMode)) && bool(!(((bool((bool((bool(((int)0 <= t1)) && bool((t1 <= (int)1)))) && bool(((int)0 <= t2)))) && bool((t2 <= (int)1))))))))){
					HX_STACK_LINE(670)
					result = false;
				}
			}
		}
		HX_STACK_LINE(674)
		if ((result)){
			HX_STACK_LINE(676)
			if (((posIntersection != null()))){
				HX_STACK_LINE(678)
				posIntersection->x = (s1p1x + (t1 * ((s1p2x - s1p1x))));
				HX_STACK_LINE(679)
				posIntersection->y = (s1p1y + (t1 * ((s1p2y - s1p1y))));
			}
			HX_STACK_LINE(681)
			if (((paramIntersection != null()))){
				HX_STACK_LINE(683)
				paramIntersection->push(t1);
				HX_STACK_LINE(684)
				paramIntersection->push(t2);
			}
		}
		HX_STACK_LINE(688)
		return result;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC11(Geom2D_obj,intersections2segments,return )

bool Geom2D_obj::intersections2edges( ::hxDaedalus::data::Edge edge1,::hxDaedalus::data::Edge edge2,::hxDaedalus::data::math::Point2D posIntersection,Array< Float > paramIntersection,hx::Null< bool >  __o_infiniteLineMode){
bool infiniteLineMode = __o_infiniteLineMode.Default(false);
	HX_STACK_FRAME("hxDaedalus.data.math.Geom2D","intersections2edges",0xcc2abe49,"hxDaedalus.data.math.Geom2D.intersections2edges","hxDaedalus/data/math/Geom2D.hx",693,0x9a728514)
	HX_STACK_ARG(edge1,"edge1")
	HX_STACK_ARG(edge2,"edge2")
	HX_STACK_ARG(posIntersection,"posIntersection")
	HX_STACK_ARG(paramIntersection,"paramIntersection")
	HX_STACK_ARG(infiniteLineMode,"infiniteLineMode")
{
		HX_STACK_LINE(693)
		return ::hxDaedalus::data::math::Geom2D_obj::intersections2segments(edge1->get_originVertex()->get_pos()->x,edge1->get_originVertex()->get_pos()->y,edge1->get_destinationVertex()->get_pos()->x,edge1->get_destinationVertex()->get_pos()->y,edge2->get_originVertex()->get_pos()->x,edge2->get_originVertex()->get_pos()->y,edge2->get_destinationVertex()->get_pos()->x,edge2->get_destinationVertex()->get_pos()->y,posIntersection,paramIntersection,infiniteLineMode);
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(Geom2D_obj,intersections2edges,return )

bool Geom2D_obj::isConvex( ::hxDaedalus::data::Edge edge){
	HX_STACK_FRAME("hxDaedalus.data.math.Geom2D","isConvex",0x71e3a276,"hxDaedalus.data.math.Geom2D.isConvex","hxDaedalus/data/math/Geom2D.hx",698,0x9a728514)
	HX_STACK_ARG(edge,"edge")
	HX_STACK_LINE(699)
	bool result = true;		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(701)
	::hxDaedalus::data::Edge eLeft;		HX_STACK_VAR(eLeft,"eLeft");
	HX_STACK_LINE(702)
	::hxDaedalus::data::Vertex vRight;		HX_STACK_VAR(vRight,"vRight");
	HX_STACK_LINE(704)
	::hxDaedalus::data::Edge _g = edge->get_nextLeftEdge()->get_oppositeEdge();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(704)
	eLeft = _g;
	HX_STACK_LINE(705)
	::hxDaedalus::data::Vertex _g1 = edge->get_nextRightEdge()->get_destinationVertex();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(705)
	vRight = _g1;
	HX_STACK_LINE(706)
	int _g2 = ::hxDaedalus::data::math::Geom2D_obj::getRelativePosition(vRight->get_pos()->x,vRight->get_pos()->y,eLeft);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(706)
	if (((_g2 != (int)-1))){
		HX_STACK_LINE(708)
		result = false;
	}
	else{
		HX_STACK_LINE(712)
		::hxDaedalus::data::Edge _g3 = edge->get_prevRightEdge();		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(712)
		eLeft = _g3;
		HX_STACK_LINE(713)
		::hxDaedalus::data::Vertex _g4 = edge->get_prevLeftEdge()->get_originVertex();		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(713)
		vRight = _g4;
		HX_STACK_LINE(714)
		int _g5 = ::hxDaedalus::data::math::Geom2D_obj::getRelativePosition(vRight->get_pos()->x,vRight->get_pos()->y,eLeft);		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(714)
		if (((_g5 != (int)-1))){
			HX_STACK_LINE(716)
			result = false;
		}
	}
	HX_STACK_LINE(720)
	return result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Geom2D_obj,isConvex,return )

Void Geom2D_obj::projectOrthogonaly( ::hxDaedalus::data::math::Point2D vertexPos,::hxDaedalus::data::Edge edge){
{
		HX_STACK_FRAME("hxDaedalus.data.math.Geom2D","projectOrthogonaly",0x50790a4c,"hxDaedalus.data.math.Geom2D.projectOrthogonaly","hxDaedalus/data/math/Geom2D.hx",724,0x9a728514)
		HX_STACK_ARG(vertexPos,"vertexPos")
		HX_STACK_ARG(edge,"edge")
		HX_STACK_LINE(738)
		Float a = edge->get_originVertex()->get_pos()->x;		HX_STACK_VAR(a,"a");
		HX_STACK_LINE(739)
		Float b = edge->get_originVertex()->get_pos()->y;		HX_STACK_VAR(b,"b");
		HX_STACK_LINE(740)
		Float c = edge->get_destinationVertex()->get_pos()->x;		HX_STACK_VAR(c,"c");
		HX_STACK_LINE(741)
		Float d = edge->get_destinationVertex()->get_pos()->y;		HX_STACK_VAR(d,"d");
		HX_STACK_LINE(742)
		Float e = vertexPos->x;		HX_STACK_VAR(e,"e");
		HX_STACK_LINE(743)
		Float f = vertexPos->y;		HX_STACK_VAR(f,"f");
		HX_STACK_LINE(750)
		Float t1 = (Float((((((((((a * a) - (a * c)) - (a * e)) + (b * b)) - (b * d)) - (b * f)) + (c * e)) + (d * f)))) / Float((((((((a * a) - (((int)2 * a) * c)) + (b * b)) - (((int)2 * b) * d)) + (c * c)) + (d * d)))));		HX_STACK_VAR(t1,"t1");
		HX_STACK_LINE(753)
		vertexPos->x = (a + (t1 * ((c - a))));
		HX_STACK_LINE(754)
		vertexPos->y = (b + (t1 * ((d - b))));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Geom2D_obj,projectOrthogonaly,(void))

bool Geom2D_obj::intersections2Circles( Float cx1,Float cy1,Float r1,Float cx2,Float cy2,Float r2,Array< Float > result){
	HX_STACK_FRAME("hxDaedalus.data.math.Geom2D","intersections2Circles",0x090da7b6,"hxDaedalus.data.math.Geom2D.intersections2Circles","hxDaedalus/data/math/Geom2D.hx",761,0x9a728514)
	HX_STACK_ARG(cx1,"cx1")
	HX_STACK_ARG(cy1,"cy1")
	HX_STACK_ARG(r1,"r1")
	HX_STACK_ARG(cx2,"cx2")
	HX_STACK_ARG(cy2,"cy2")
	HX_STACK_ARG(r2,"r2")
	HX_STACK_ARG(result,"result")
	HX_STACK_LINE(762)
	Float distRadiusSQRD = ((((cx2 - cx1)) * ((cx2 - cx1))) + (((cy2 - cy1)) * ((cy2 - cy1))));		HX_STACK_VAR(distRadiusSQRD,"distRadiusSQRD");
	HX_STACK_LINE(764)
	if (((bool((bool(((bool((cx1 != cx2)) || bool((cy1 != cy2))))) && bool((distRadiusSQRD <= (((r1 + r2)) * ((r1 + r2))))))) && bool((distRadiusSQRD >= (((r1 - r2)) * ((r1 - r2)))))))){
		HX_STACK_LINE(768)
		Float transcendPart = ::Math_obj::sqrt(((((((r1 + r2)) * ((r1 + r2))) - distRadiusSQRD)) * ((distRadiusSQRD - (((r2 - r1)) * ((r2 - r1)))))));		HX_STACK_VAR(transcendPart,"transcendPart");
		HX_STACK_LINE(770)
		Float xFirstPart = ((Float(((cx1 + cx2))) / Float((int)2)) + (Float((((cx2 - cx1)) * (((r1 * r1) - (r2 * r2))))) / Float((((int)2 * distRadiusSQRD)))));		HX_STACK_VAR(xFirstPart,"xFirstPart");
		HX_STACK_LINE(771)
		Float yFirstPart = ((Float(((cy1 + cy2))) / Float((int)2)) + (Float((((cy2 - cy1)) * (((r1 * r1) - (r2 * r2))))) / Float((((int)2 * distRadiusSQRD)))));		HX_STACK_VAR(yFirstPart,"yFirstPart");
		HX_STACK_LINE(772)
		Float xFactor = (Float(((cy2 - cy1))) / Float((((int)2 * distRadiusSQRD))));		HX_STACK_VAR(xFactor,"xFactor");
		HX_STACK_LINE(773)
		Float yFactor = (Float(((cx2 - cx1))) / Float((((int)2 * distRadiusSQRD))));		HX_STACK_VAR(yFactor,"yFactor");
		HX_STACK_LINE(775)
		if (((result != null()))){
			HX_STACK_LINE(777)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(777)
			Array< Float > _g1 = Array_obj< Float >::__new().Add((xFirstPart + (xFactor * transcendPart))).Add((yFirstPart - (yFactor * transcendPart))).Add((xFirstPart - (xFactor * transcendPart))).Add((yFirstPart + (yFactor * transcendPart)));		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(777)
			while((true)){
				HX_STACK_LINE(777)
				if ((!(((_g < _g1->length))))){
					HX_STACK_LINE(777)
					break;
				}
				HX_STACK_LINE(777)
				Float f = _g1->__get(_g);		HX_STACK_VAR(f,"f");
				HX_STACK_LINE(777)
				++(_g);
				HX_STACK_LINE(778)
				result->push(f);
			}
		}
		HX_STACK_LINE(781)
		return true;
	}
	else{
		HX_STACK_LINE(784)
		return false;
	}
	HX_STACK_LINE(764)
	return false;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC7(Geom2D_obj,intersections2Circles,return )

bool Geom2D_obj::intersectionsSegmentCircle( Float p0x,Float p0y,Float p1x,Float p1y,Float cx,Float cy,Float r,Array< Float > result){
	HX_STACK_FRAME("hxDaedalus.data.math.Geom2D","intersectionsSegmentCircle",0x73b5467e,"hxDaedalus.data.math.Geom2D.intersectionsSegmentCircle","hxDaedalus/data/math/Geom2D.hx",788,0x9a728514)
	HX_STACK_ARG(p0x,"p0x")
	HX_STACK_ARG(p0y,"p0y")
	HX_STACK_ARG(p1x,"p1x")
	HX_STACK_ARG(p1y,"p1y")
	HX_STACK_ARG(cx,"cx")
	HX_STACK_ARG(cy,"cy")
	HX_STACK_ARG(r,"r")
	HX_STACK_ARG(result,"result")
	HX_STACK_LINE(790)
	Float p0xSQD = (p0x * p0x);		HX_STACK_VAR(p0xSQD,"p0xSQD");
	HX_STACK_LINE(791)
	Float p0ySQD = (p0y * p0y);		HX_STACK_VAR(p0ySQD,"p0ySQD");
	HX_STACK_LINE(792)
	Float a = ((((((p1y * p1y) - (((int)2 * p1y) * p0y)) + p0ySQD) + (p1x * p1x)) - (((int)2 * p1x) * p0x)) + p0xSQD);		HX_STACK_VAR(a,"a");
	HX_STACK_LINE(793)
	Float b = ((((((((((int)2 * p0y) * cy) - ((int)2 * p0xSQD)) + (((int)2 * p1y) * p0y)) - ((int)2 * p0ySQD)) + (((int)2 * p1x) * p0x)) - (((int)2 * p1x) * cx)) + (((int)2 * p0x) * cx)) - (((int)2 * p1y) * cy));		HX_STACK_VAR(b,"b");
	HX_STACK_LINE(794)
	Float c = ((((((p0ySQD + (cy * cy)) + (cx * cx)) - (((int)2 * p0y) * cy)) - (((int)2 * p0x) * cx)) + p0xSQD) - (r * r));		HX_STACK_VAR(c,"c");
	HX_STACK_LINE(795)
	Float delta = ((b * b) - (((int)4 * a) * c));		HX_STACK_VAR(delta,"delta");
	HX_STACK_LINE(796)
	Float deltaSQRT;		HX_STACK_VAR(deltaSQRT,"deltaSQRT");
	HX_STACK_LINE(798)
	Float t0;		HX_STACK_VAR(t0,"t0");
	HX_STACK_LINE(799)
	Float t1;		HX_STACK_VAR(t1,"t1");
	HX_STACK_LINE(800)
	if (((delta < (int)0))){
		HX_STACK_LINE(803)
		return false;
	}
	else{
		HX_STACK_LINE(805)
		if (((delta == (int)0))){
			HX_STACK_LINE(808)
			t0 = (Float(-(b)) / Float((((int)2 * a))));
			HX_STACK_LINE(809)
			if (((bool((t0 < (int)0)) || bool((t0 > (int)1))))){
				HX_STACK_LINE(810)
				return false;
			}
			HX_STACK_LINE(814)
			if (((result != null()))){
				HX_STACK_LINE(815)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(815)
				Array< Float > _g1 = Array_obj< Float >::__new().Add((p0x + (t0 * ((p1x - p0x))))).Add((p0y + (t0 * ((p1y - p0y))))).Add(t0);		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(815)
				while((true)){
					HX_STACK_LINE(815)
					if ((!(((_g < _g1->length))))){
						HX_STACK_LINE(815)
						break;
					}
					HX_STACK_LINE(815)
					Float f = _g1->__get(_g);		HX_STACK_VAR(f,"f");
					HX_STACK_LINE(815)
					++(_g);
					HX_STACK_LINE(816)
					result->push(f);
				}
			}
			HX_STACK_LINE(818)
			return true;
		}
		else{
			HX_STACK_LINE(823)
			Float _g = ::Math_obj::sqrt(delta);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(823)
			deltaSQRT = _g;
			HX_STACK_LINE(824)
			t0 = (Float(((-(b) + deltaSQRT))) / Float((((int)2 * a))));
			HX_STACK_LINE(825)
			t1 = (Float(((-(b) - deltaSQRT))) / Float((((int)2 * a))));
			HX_STACK_LINE(829)
			bool intersecting = false;		HX_STACK_VAR(intersecting,"intersecting");
			HX_STACK_LINE(830)
			if (((bool(((int)0 <= t0)) && bool((t0 <= (int)1))))){
				HX_STACK_LINE(832)
				if (((result != null()))){
					HX_STACK_LINE(833)
					int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(833)
					Array< Float > _g11 = Array_obj< Float >::__new().Add((p0x + (t0 * ((p1x - p0x))))).Add((p0y + (t0 * ((p1y - p0y))))).Add(t0);		HX_STACK_VAR(_g11,"_g11");
					HX_STACK_LINE(833)
					while((true)){
						HX_STACK_LINE(833)
						if ((!(((_g1 < _g11->length))))){
							HX_STACK_LINE(833)
							break;
						}
						HX_STACK_LINE(833)
						Float f = _g11->__get(_g1);		HX_STACK_VAR(f,"f");
						HX_STACK_LINE(833)
						++(_g1);
						HX_STACK_LINE(834)
						result->push(f);
					}
				}
				HX_STACK_LINE(835)
				intersecting = true;
			}
			HX_STACK_LINE(837)
			if (((bool(((int)0 <= t1)) && bool((t1 <= (int)1))))){
				HX_STACK_LINE(839)
				if (((result != null()))){
					HX_STACK_LINE(840)
					int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(840)
					Array< Float > _g11 = Array_obj< Float >::__new().Add((p0x + (t1 * ((p1x - p0x))))).Add((p0y + (t1 * ((p1y - p0y))))).Add(t1);		HX_STACK_VAR(_g11,"_g11");
					HX_STACK_LINE(840)
					while((true)){
						HX_STACK_LINE(840)
						if ((!(((_g1 < _g11->length))))){
							HX_STACK_LINE(840)
							break;
						}
						HX_STACK_LINE(840)
						Float f = _g11->__get(_g1);		HX_STACK_VAR(f,"f");
						HX_STACK_LINE(840)
						++(_g1);
						HX_STACK_LINE(841)
						result->push(f);
					}
				}
				HX_STACK_LINE(842)
				intersecting = true;
			}
			HX_STACK_LINE(845)
			return intersecting;
		}
	}
	HX_STACK_LINE(800)
	return false;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC8(Geom2D_obj,intersectionsSegmentCircle,return )

bool Geom2D_obj::intersectionsLineCircle( Float p0x,Float p0y,Float p1x,Float p1y,Float cx,Float cy,Float r,Array< Float > result){
	HX_STACK_FRAME("hxDaedalus.data.math.Geom2D","intersectionsLineCircle",0x01472de9,"hxDaedalus.data.math.Geom2D.intersectionsLineCircle","hxDaedalus/data/math/Geom2D.hx",850,0x9a728514)
	HX_STACK_ARG(p0x,"p0x")
	HX_STACK_ARG(p0y,"p0y")
	HX_STACK_ARG(p1x,"p1x")
	HX_STACK_ARG(p1y,"p1y")
	HX_STACK_ARG(cx,"cx")
	HX_STACK_ARG(cy,"cy")
	HX_STACK_ARG(r,"r")
	HX_STACK_ARG(result,"result")
	HX_STACK_LINE(851)
	Float p0xSQD = (p0x * p0x);		HX_STACK_VAR(p0xSQD,"p0xSQD");
	HX_STACK_LINE(852)
	Float p0ySQD = (p0y * p0y);		HX_STACK_VAR(p0ySQD,"p0ySQD");
	HX_STACK_LINE(853)
	Float a = ((((((p1y * p1y) - (((int)2 * p1y) * p0y)) + p0ySQD) + (p1x * p1x)) - (((int)2 * p1x) * p0x)) + p0xSQD);		HX_STACK_VAR(a,"a");
	HX_STACK_LINE(854)
	Float b = ((((((((((int)2 * p0y) * cy) - ((int)2 * p0xSQD)) + (((int)2 * p1y) * p0y)) - ((int)2 * p0ySQD)) + (((int)2 * p1x) * p0x)) - (((int)2 * p1x) * cx)) + (((int)2 * p0x) * cx)) - (((int)2 * p1y) * cy));		HX_STACK_VAR(b,"b");
	HX_STACK_LINE(855)
	Float c = ((((((p0ySQD + (cy * cy)) + (cx * cx)) - (((int)2 * p0y) * cy)) - (((int)2 * p0x) * cx)) + p0xSQD) - (r * r));		HX_STACK_VAR(c,"c");
	HX_STACK_LINE(856)
	Float delta = ((b * b) - (((int)4 * a) * c));		HX_STACK_VAR(delta,"delta");
	HX_STACK_LINE(857)
	Float deltaSQRT;		HX_STACK_VAR(deltaSQRT,"deltaSQRT");
	HX_STACK_LINE(859)
	Float t0;		HX_STACK_VAR(t0,"t0");
	HX_STACK_LINE(860)
	Float t1;		HX_STACK_VAR(t1,"t1");
	HX_STACK_LINE(861)
	if (((delta < (int)0))){
		HX_STACK_LINE(864)
		return false;
	}
	else{
		HX_STACK_LINE(866)
		if (((delta == (int)0))){
			HX_STACK_LINE(869)
			t0 = (Float(-(b)) / Float((((int)2 * a))));
			HX_STACK_LINE(872)
			{
				HX_STACK_LINE(872)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(872)
				Array< Float > _g1 = Array_obj< Float >::__new().Add((p0x + (t0 * ((p1x - p0x))))).Add((p0y + (t0 * ((p1y - p0y))))).Add(t0);		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(872)
				while((true)){
					HX_STACK_LINE(872)
					if ((!(((_g < _g1->length))))){
						HX_STACK_LINE(872)
						break;
					}
					HX_STACK_LINE(872)
					Float f = _g1->__get(_g);		HX_STACK_VAR(f,"f");
					HX_STACK_LINE(872)
					++(_g);
					HX_STACK_LINE(873)
					result->push(f);
				}
			}
		}
		else{
			HX_STACK_LINE(875)
			if (((delta > (int)0))){
				HX_STACK_LINE(877)
				Float _g = ::Math_obj::sqrt(delta);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(877)
				deltaSQRT = _g;
				HX_STACK_LINE(878)
				t0 = (Float(((-(b) + deltaSQRT))) / Float((((int)2 * a))));
				HX_STACK_LINE(879)
				t1 = (Float(((-(b) - deltaSQRT))) / Float((((int)2 * a))));
				HX_STACK_LINE(883)
				{
					HX_STACK_LINE(883)
					int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(883)
					Array< Float > _g11 = Array_obj< Float >::__new().Add((p0x + (t0 * ((p1x - p0x))))).Add((p0y + (t0 * ((p1y - p0y))))).Add(t0).Add((p0x + (t1 * ((p1x - p0x))))).Add((p0y + (t1 * ((p1y - p0y))))).Add(t1);		HX_STACK_VAR(_g11,"_g11");
					HX_STACK_LINE(883)
					while((true)){
						HX_STACK_LINE(883)
						if ((!(((_g1 < _g11->length))))){
							HX_STACK_LINE(883)
							break;
						}
						HX_STACK_LINE(883)
						Float f = _g11->__get(_g1);		HX_STACK_VAR(f,"f");
						HX_STACK_LINE(883)
						++(_g1);
						HX_STACK_LINE(884)
						result->push(f);
					}
				}
			}
		}
	}
	HX_STACK_LINE(887)
	return true;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC8(Geom2D_obj,intersectionsLineCircle,return )

bool Geom2D_obj::tangentsPointToCircle( Float px,Float py,Float cx,Float cy,Float r,Array< Float > result){
	HX_STACK_FRAME("hxDaedalus.data.math.Geom2D","tangentsPointToCircle",0x4b4b0ac8,"hxDaedalus.data.math.Geom2D.tangentsPointToCircle","hxDaedalus/data/math/Geom2D.hx",895,0x9a728514)
	HX_STACK_ARG(px,"px")
	HX_STACK_ARG(py,"py")
	HX_STACK_ARG(cx,"cx")
	HX_STACK_ARG(cy,"cy")
	HX_STACK_ARG(r,"r")
	HX_STACK_ARG(result,"result")
	HX_STACK_LINE(896)
	Float c2x = (Float(((px + cx))) / Float((int)2));		HX_STACK_VAR(c2x,"c2x");
	HX_STACK_LINE(897)
	Float c2y = (Float(((py + cy))) / Float((int)2));		HX_STACK_VAR(c2y,"c2y");
	HX_STACK_LINE(898)
	Float _g = ::Math_obj::sqrt(((((px - cx)) * ((px - cx))) + (((py - cy)) * ((py - cy)))));		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(898)
	Float r2 = (0.5 * _g);		HX_STACK_VAR(r2,"r2");
	HX_STACK_LINE(900)
	return ::hxDaedalus::data::math::Geom2D_obj::intersections2Circles(c2x,c2y,r2,cx,cy,r,result);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC6(Geom2D_obj,tangentsPointToCircle,return )

bool Geom2D_obj::tangentsCrossCircleToCircle( Float r,Float c1x,Float c1y,Float c2x,Float c2y,Array< Float > result){
	HX_STACK_FRAME("hxDaedalus.data.math.Geom2D","tangentsCrossCircleToCircle",0x6dec2be8,"hxDaedalus.data.math.Geom2D.tangentsCrossCircleToCircle","hxDaedalus/data/math/Geom2D.hx",905,0x9a728514)
	HX_STACK_ARG(r,"r")
	HX_STACK_ARG(c1x,"c1x")
	HX_STACK_ARG(c1y,"c1y")
	HX_STACK_ARG(c2x,"c2x")
	HX_STACK_ARG(c2y,"c2y")
	HX_STACK_ARG(result,"result")
	HX_STACK_LINE(906)
	Float distance = ::Math_obj::sqrt(((((c1x - c2x)) * ((c1x - c2x))) + (((c1y - c2y)) * ((c1y - c2y)))));		HX_STACK_VAR(distance,"distance");
	HX_STACK_LINE(909)
	Float radius = (Float(distance) / Float((int)4));		HX_STACK_VAR(radius,"radius");
	HX_STACK_LINE(910)
	Float centerX = (c1x + (Float(((c2x - c1x))) / Float((int)4)));		HX_STACK_VAR(centerX,"centerX");
	HX_STACK_LINE(911)
	Float centerY = (c1y + (Float(((c2y - c1y))) / Float((int)4)));		HX_STACK_VAR(centerY,"centerY");
	HX_STACK_LINE(913)
	if ((::hxDaedalus::data::math::Geom2D_obj::intersections2Circles(c1x,c1y,r,centerX,centerY,radius,result))){
		HX_STACK_LINE(915)
		Float t1x = result->__get((int)0);		HX_STACK_VAR(t1x,"t1x");
		HX_STACK_LINE(916)
		Float t1y = result->__get((int)1);		HX_STACK_VAR(t1y,"t1y");
		HX_STACK_LINE(917)
		Float t2x = result->__get((int)2);		HX_STACK_VAR(t2x,"t2x");
		HX_STACK_LINE(918)
		Float t2y = result->__get((int)3);		HX_STACK_VAR(t2y,"t2y");
		HX_STACK_LINE(920)
		Float midX = (Float(((c1x + c2x))) / Float((int)2));		HX_STACK_VAR(midX,"midX");
		HX_STACK_LINE(921)
		Float midY = (Float(((c1y + c2y))) / Float((int)2));		HX_STACK_VAR(midY,"midY");
		HX_STACK_LINE(922)
		Float dotProd = ((((t1x - midX)) * ((c2y - c1y))) + (((t1y - midY)) * ((-(c2x) + c1x))));		HX_STACK_VAR(dotProd,"dotProd");
		HX_STACK_LINE(923)
		Float tproj = (Float(dotProd) / Float(((distance * distance))));		HX_STACK_VAR(tproj,"tproj");
		HX_STACK_LINE(924)
		Float projx = (midX + (tproj * ((c2y - c1y))));		HX_STACK_VAR(projx,"projx");
		HX_STACK_LINE(925)
		Float projy = (midY - (tproj * ((c2x - c1x))));		HX_STACK_VAR(projy,"projy");
		HX_STACK_LINE(928)
		Float t4x = (((int)2 * projx) - t1x);		HX_STACK_VAR(t4x,"t4x");
		HX_STACK_LINE(929)
		Float t4y = (((int)2 * projy) - t1y);		HX_STACK_VAR(t4y,"t4y");
		HX_STACK_LINE(931)
		Float t3x = ((t4x + t2x) - t1x);		HX_STACK_VAR(t3x,"t3x");
		HX_STACK_LINE(932)
		Float t3y = ((t2y + t4y) - t1y);		HX_STACK_VAR(t3y,"t3y");
		HX_STACK_LINE(934)
		{
			HX_STACK_LINE(934)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(934)
			Array< Float > _g1 = Array_obj< Float >::__new().Add(t3x).Add(t3y).Add(t4x).Add(t4y);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(934)
			while((true)){
				HX_STACK_LINE(934)
				if ((!(((_g < _g1->length))))){
					HX_STACK_LINE(934)
					break;
				}
				HX_STACK_LINE(934)
				Float f = _g1->__get(_g);		HX_STACK_VAR(f,"f");
				HX_STACK_LINE(934)
				++(_g);
				HX_STACK_LINE(934)
				result->push(f);
			}
		}
		HX_STACK_LINE(936)
		return true;
	}
	else{
		HX_STACK_LINE(941)
		return false;
	}
	HX_STACK_LINE(913)
	return false;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC6(Geom2D_obj,tangentsCrossCircleToCircle,return )

Void Geom2D_obj::tangentsParalCircleToCircle( Float r,Float c1x,Float c1y,Float c2x,Float c2y,Array< Float > result){
{
		HX_STACK_FRAME("hxDaedalus.data.math.Geom2D","tangentsParalCircleToCircle",0xeb8a89f4,"hxDaedalus.data.math.Geom2D.tangentsParalCircleToCircle","hxDaedalus/data/math/Geom2D.hx",947,0x9a728514)
		HX_STACK_ARG(r,"r")
		HX_STACK_ARG(c1x,"c1x")
		HX_STACK_ARG(c1y,"c1y")
		HX_STACK_ARG(c2x,"c2x")
		HX_STACK_ARG(c2y,"c2y")
		HX_STACK_ARG(result,"result")
		HX_STACK_LINE(948)
		Float distance = ::Math_obj::sqrt(((((c1x - c2x)) * ((c1x - c2x))) + (((c1y - c2y)) * ((c1y - c2y)))));		HX_STACK_VAR(distance,"distance");
		HX_STACK_LINE(949)
		Float t1x = (c1x + (Float((r * ((c2y - c1y)))) / Float(distance)));		HX_STACK_VAR(t1x,"t1x");
		HX_STACK_LINE(950)
		Float t1y = (c1y + (Float((r * ((-(c2x) + c1x)))) / Float(distance)));		HX_STACK_VAR(t1y,"t1y");
		HX_STACK_LINE(951)
		Float t2x = (((int)2 * c1x) - t1x);		HX_STACK_VAR(t2x,"t2x");
		HX_STACK_LINE(952)
		Float t2y = (((int)2 * c1y) - t1y);		HX_STACK_VAR(t2y,"t2y");
		HX_STACK_LINE(953)
		Float t3x = ((t2x + c2x) - c1x);		HX_STACK_VAR(t3x,"t3x");
		HX_STACK_LINE(954)
		Float t3y = ((t2y + c2y) - c1y);		HX_STACK_VAR(t3y,"t3y");
		HX_STACK_LINE(955)
		Float t4x = ((t1x + c2x) - c1x);		HX_STACK_VAR(t4x,"t4x");
		HX_STACK_LINE(956)
		Float t4y = ((t1y + c2y) - c1y);		HX_STACK_VAR(t4y,"t4y");
		HX_STACK_LINE(957)
		{
			HX_STACK_LINE(957)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(957)
			Array< Float > _g1 = Array_obj< Float >::__new().Add(t1x).Add(t1y).Add(t2x).Add(t2y).Add(t3x).Add(t3y).Add(t4x).Add(t4y);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(957)
			while((true)){
				HX_STACK_LINE(957)
				if ((!(((_g < _g1->length))))){
					HX_STACK_LINE(957)
					break;
				}
				HX_STACK_LINE(957)
				Float f = _g1->__get(_g);		HX_STACK_VAR(f,"f");
				HX_STACK_LINE(957)
				++(_g);
				HX_STACK_LINE(958)
				result->push(f);
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC6(Geom2D_obj,tangentsParalCircleToCircle,(void))

Float Geom2D_obj::distanceSquaredPointToLine( Float px,Float py,Float ax,Float ay,Float bx,Float by){
	HX_STACK_FRAME("hxDaedalus.data.math.Geom2D","distanceSquaredPointToLine",0x9c85a6f2,"hxDaedalus.data.math.Geom2D.distanceSquaredPointToLine","hxDaedalus/data/math/Geom2D.hx",963,0x9a728514)
	HX_STACK_ARG(px,"px")
	HX_STACK_ARG(py,"py")
	HX_STACK_ARG(ax,"ax")
	HX_STACK_ARG(ay,"ay")
	HX_STACK_ARG(bx,"bx")
	HX_STACK_ARG(by,"by")
	HX_STACK_LINE(964)
	Float a_b_squaredLength = ((((bx - ax)) * ((bx - ax))) + (((by - ay)) * ((by - ay))));		HX_STACK_VAR(a_b_squaredLength,"a_b_squaredLength");
	HX_STACK_LINE(965)
	Float dotProduct = ((((px - ax)) * ((bx - ax))) + (((py - ay)) * ((by - ay))));		HX_STACK_VAR(dotProduct,"dotProduct");
	HX_STACK_LINE(966)
	Float p_a_squaredLength = ((((ax - px)) * ((ax - px))) + (((ay - py)) * ((ay - py))));		HX_STACK_VAR(p_a_squaredLength,"p_a_squaredLength");
	HX_STACK_LINE(967)
	return (p_a_squaredLength - (Float((dotProduct * dotProduct)) / Float(a_b_squaredLength)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC6(Geom2D_obj,distanceSquaredPointToLine,return )

Float Geom2D_obj::distanceSquaredPointToSegment( Float px,Float py,Float ax,Float ay,Float bx,Float by){
	HX_STACK_FRAME("hxDaedalus.data.math.Geom2D","distanceSquaredPointToSegment",0x256d3375,"hxDaedalus.data.math.Geom2D.distanceSquaredPointToSegment","hxDaedalus/data/math/Geom2D.hx",972,0x9a728514)
	HX_STACK_ARG(px,"px")
	HX_STACK_ARG(py,"py")
	HX_STACK_ARG(ax,"ax")
	HX_STACK_ARG(ay,"ay")
	HX_STACK_ARG(bx,"bx")
	HX_STACK_ARG(by,"by")
	HX_STACK_LINE(973)
	Float a_b_squaredLength = ((((bx - ax)) * ((bx - ax))) + (((by - ay)) * ((by - ay))));		HX_STACK_VAR(a_b_squaredLength,"a_b_squaredLength");
	HX_STACK_LINE(974)
	Float dotProduct = (Float((((((px - ax)) * ((bx - ax))) + (((py - ay)) * ((by - ay)))))) / Float(a_b_squaredLength));		HX_STACK_VAR(dotProduct,"dotProduct");
	HX_STACK_LINE(975)
	if (((dotProduct < (int)0))){
		HX_STACK_LINE(977)
		return ((((px - ax)) * ((px - ax))) + (((py - ay)) * ((py - ay))));
	}
	else{
		HX_STACK_LINE(979)
		if (((dotProduct <= (int)1))){
			HX_STACK_LINE(981)
			Float p_a_squaredLength = ((((ax - px)) * ((ax - px))) + (((ay - py)) * ((ay - py))));		HX_STACK_VAR(p_a_squaredLength,"p_a_squaredLength");
			HX_STACK_LINE(982)
			return (p_a_squaredLength - ((dotProduct * dotProduct) * a_b_squaredLength));
		}
		else{
			HX_STACK_LINE(986)
			return ((((px - bx)) * ((px - bx))) + (((py - by)) * ((py - by))));
		}
	}
	HX_STACK_LINE(975)
	return 0.;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC6(Geom2D_obj,distanceSquaredPointToSegment,return )

Float Geom2D_obj::distanceSquaredVertexToEdge( ::hxDaedalus::data::Vertex vertex,::hxDaedalus::data::Edge edge){
	HX_STACK_FRAME("hxDaedalus.data.math.Geom2D","distanceSquaredVertexToEdge",0x511fcb09,"hxDaedalus.data.math.Geom2D.distanceSquaredVertexToEdge","hxDaedalus/data/math/Geom2D.hx",992,0x9a728514)
	HX_STACK_ARG(vertex,"vertex")
	HX_STACK_ARG(edge,"edge")
	HX_STACK_LINE(992)
	return ::hxDaedalus::data::math::Geom2D_obj::distanceSquaredPointToSegment(vertex->get_pos()->x,vertex->get_pos()->y,edge->get_originVertex()->get_pos()->x,edge->get_originVertex()->get_pos()->y,edge->get_destinationVertex()->get_pos()->x,edge->get_destinationVertex()->get_pos()->y);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Geom2D_obj,distanceSquaredVertexToEdge,return )

Float Geom2D_obj::pathLength( Array< Float > path){
	HX_STACK_FRAME("hxDaedalus.data.math.Geom2D","pathLength",0x4c7f7330,"hxDaedalus.data.math.Geom2D.pathLength","hxDaedalus/data/math/Geom2D.hx",995,0x9a728514)
	HX_STACK_ARG(path,"path")
	HX_STACK_LINE(996)
	Float sumDistance = 0.;		HX_STACK_VAR(sumDistance,"sumDistance");
	HX_STACK_LINE(997)
	Float fromX = path->__get((int)0);		HX_STACK_VAR(fromX,"fromX");
	HX_STACK_LINE(998)
	Float fromY = path->__get((int)1);		HX_STACK_VAR(fromY,"fromY");
	HX_STACK_LINE(999)
	Float nextX;		HX_STACK_VAR(nextX,"nextX");
	HX_STACK_LINE(1000)
	Float nextY;		HX_STACK_VAR(nextY,"nextY");
	HX_STACK_LINE(1001)
	Float x;		HX_STACK_VAR(x,"x");
	HX_STACK_LINE(1002)
	Float y;		HX_STACK_VAR(y,"y");
	HX_STACK_LINE(1003)
	Float distance;		HX_STACK_VAR(distance,"distance");
	HX_STACK_LINE(1004)
	int i = (int)2;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(1005)
	while((true)){
		HX_STACK_LINE(1005)
		if ((!(((i < path->length))))){
			HX_STACK_LINE(1005)
			break;
		}
		HX_STACK_LINE(1006)
		nextX = path->__get(i);
		HX_STACK_LINE(1007)
		nextY = path->__get((i + (int)1));
		HX_STACK_LINE(1008)
		x = (nextX - fromX);
		HX_STACK_LINE(1009)
		y = (nextY - fromY);
		HX_STACK_LINE(1010)
		Float _g = ::Math_obj::sqrt(((x * x) + (y * y)));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(1010)
		distance = _g;
		HX_STACK_LINE(1011)
		hx::AddEq(sumDistance,distance);
		HX_STACK_LINE(1012)
		fromX = nextX;
		HX_STACK_LINE(1013)
		fromY = nextY;
		HX_STACK_LINE(1014)
		hx::AddEq(i,(int)2);
	}
	HX_STACK_LINE(1017)
	return sumDistance;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Geom2D_obj,pathLength,return )


Geom2D_obj::Geom2D_obj()
{
}

Dynamic Geom2D_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"_randGen") ) { return _randGen; }
		if (HX_FIELD_EQ(inName,"isInFace") ) { return isInFace_dyn(); }
		if (HX_FIELD_EQ(inName,"isConvex") ) { return isConvex_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"__samples") ) { return __samples; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"isDelaunay") ) { return isDelaunay_dyn(); }
		if (HX_FIELD_EQ(inName,"pathLength") ) { return pathLength_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"getDirection") ) { return getDirection_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"getDirection2") ) { return getDirection2_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"locatePosition") ) { return locatePosition_dyn(); }
		if (HX_FIELD_EQ(inName,"__circumcenter") ) { return __circumcenter; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"getCircumcenter") ) { return getCircumcenter_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"projectOrthogonaly") ) { return projectOrthogonaly_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"getRelativePosition") ) { return getRelativePosition_dyn(); }
		if (HX_FIELD_EQ(inName,"intersections2edges") ) { return intersections2edges_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"getRelativePosition2") ) { return getRelativePosition2_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"clipSegmentByTriangle") ) { return clipSegmentByTriangle_dyn(); }
		if (HX_FIELD_EQ(inName,"intersections2Circles") ) { return intersections2Circles_dyn(); }
		if (HX_FIELD_EQ(inName,"tangentsPointToCircle") ) { return tangentsPointToCircle_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"intersections2segments") ) { return intersections2segments_dyn(); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"intersectionsLineCircle") ) { return intersectionsLineCircle_dyn(); }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"intersectionsSegmentCircle") ) { return intersectionsSegmentCircle_dyn(); }
		if (HX_FIELD_EQ(inName,"distanceSquaredPointToLine") ) { return distanceSquaredPointToLine_dyn(); }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"tangentsCrossCircleToCircle") ) { return tangentsCrossCircleToCircle_dyn(); }
		if (HX_FIELD_EQ(inName,"tangentsParalCircleToCircle") ) { return tangentsParalCircleToCircle_dyn(); }
		if (HX_FIELD_EQ(inName,"distanceSquaredVertexToEdge") ) { return distanceSquaredVertexToEdge_dyn(); }
		break;
	case 29:
		if (HX_FIELD_EQ(inName,"isSegmentIntersectingTriangle") ) { return isSegmentIntersectingTriangle_dyn(); }
		if (HX_FIELD_EQ(inName,"distanceSquaredPointToSegment") ) { return distanceSquaredPointToSegment_dyn(); }
		break;
	case 33:
		if (HX_FIELD_EQ(inName,"isCircleIntersectingAnyConstraint") ) { return isCircleIntersectingAnyConstraint_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Geom2D_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"_randGen") ) { _randGen=inValue.Cast< ::hxDaedalus::data::math::RandGenerator >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"__samples") ) { __samples=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"__circumcenter") ) { __circumcenter=inValue.Cast< ::hxDaedalus::data::math::Point2D >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Geom2D_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("_randGen"),
	HX_CSTRING("__samples"),
	HX_CSTRING("locatePosition"),
	HX_CSTRING("isCircleIntersectingAnyConstraint"),
	HX_CSTRING("getDirection"),
	HX_CSTRING("getDirection2"),
	HX_CSTRING("getRelativePosition"),
	HX_CSTRING("getRelativePosition2"),
	HX_CSTRING("isInFace"),
	HX_CSTRING("clipSegmentByTriangle"),
	HX_CSTRING("isSegmentIntersectingTriangle"),
	HX_CSTRING("__circumcenter"),
	HX_CSTRING("isDelaunay"),
	HX_CSTRING("getCircumcenter"),
	HX_CSTRING("intersections2segments"),
	HX_CSTRING("intersections2edges"),
	HX_CSTRING("isConvex"),
	HX_CSTRING("projectOrthogonaly"),
	HX_CSTRING("intersections2Circles"),
	HX_CSTRING("intersectionsSegmentCircle"),
	HX_CSTRING("intersectionsLineCircle"),
	HX_CSTRING("tangentsPointToCircle"),
	HX_CSTRING("tangentsCrossCircleToCircle"),
	HX_CSTRING("tangentsParalCircleToCircle"),
	HX_CSTRING("distanceSquaredPointToLine"),
	HX_CSTRING("distanceSquaredPointToSegment"),
	HX_CSTRING("distanceSquaredVertexToEdge"),
	HX_CSTRING("pathLength"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Geom2D_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Geom2D_obj::_randGen,"_randGen");
	HX_MARK_MEMBER_NAME(Geom2D_obj::__samples,"__samples");
	HX_MARK_MEMBER_NAME(Geom2D_obj::__circumcenter,"__circumcenter");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Geom2D_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Geom2D_obj::_randGen,"_randGen");
	HX_VISIT_MEMBER_NAME(Geom2D_obj::__samples,"__samples");
	HX_VISIT_MEMBER_NAME(Geom2D_obj::__circumcenter,"__circumcenter");
};

#endif

Class Geom2D_obj::__mClass;

void Geom2D_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDaedalus.data.math.Geom2D"), hx::TCanCast< Geom2D_obj> ,sStaticFields,sMemberFields,
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

void Geom2D_obj::__boot()
{
	__samples= Array_obj< ::Dynamic >::__new();
	__circumcenter= ::hxDaedalus::data::math::Point2D_obj::__new(null(),null());
}

} // end namespace hxDaedalus
} // end namespace data
} // end namespace math
