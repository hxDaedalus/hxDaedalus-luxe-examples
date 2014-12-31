#include <hxcpp.h>

#ifndef INCLUDED_IMap
#include <IMap.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_graph_Graph
#include <hxDaedalus/data/graph/Graph.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_graph_GraphEdge
#include <hxDaedalus/data/graph/GraphEdge.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_graph_GraphNode
#include <hxDaedalus/data/graph/GraphNode.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_math_EdgeData
#include <hxDaedalus/data/math/EdgeData.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_math_Geom2D
#include <hxDaedalus/data/math/Geom2D.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_math_NodeData
#include <hxDaedalus/data/math/NodeData.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_math_Point2D
#include <hxDaedalus/data/math/Point2D.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_math_Potrace
#include <hxDaedalus/data/math/Potrace.h>
#endif
#ifndef INCLUDED_hxDaedalus_graphics_ISimpleDrawingContext
#include <hxDaedalus/graphics/ISimpleDrawingContext.h>
#endif
#ifndef INCLUDED_hxDaedalus_graphics__Pixels_PixelsData
#include <hxDaedalus/graphics/_Pixels/PixelsData.h>
#endif
#ifndef INCLUDED_hxDaedalus_graphics_flash_SimpleDrawingContext
#include <hxDaedalus/graphics/flash/SimpleDrawingContext.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
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
namespace data{
namespace math{

Void Potrace_obj::__construct()
{
HX_STACK_FRAME("hxDaedalus.data.math.Potrace","new",0xca866a3d,"hxDaedalus.data.math.Potrace.new","hxDaedalus/data/math/Potrace.hx",269,0x401666b4)
HX_STACK_THIS(this)
{
}
;
	return null();
}

//Potrace_obj::~Potrace_obj() { }

Dynamic Potrace_obj::__CreateEmpty() { return  new Potrace_obj; }
hx::ObjectPtr< Potrace_obj > Potrace_obj::__new()
{  hx::ObjectPtr< Potrace_obj > result = new Potrace_obj();
	result->__construct();
	return result;}

Dynamic Potrace_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Potrace_obj > result = new Potrace_obj();
	result->__construct();
	return result;}

int Potrace_obj::MAX_INT;

Float Potrace_obj::maxDistance;

Array< ::Dynamic > Potrace_obj::buildShapes( ::hxDaedalus::graphics::_Pixels::PixelsData bmpData,::hxDaedalus::graphics::_Pixels::PixelsData debugBmp,::hxDaedalus::graphics::flash::SimpleDrawingContext debugShape){
	HX_STACK_FRAME("hxDaedalus.data.math.Potrace","buildShapes",0x1bf5fedd,"hxDaedalus.data.math.Potrace.buildShapes","hxDaedalus/data/math/Potrace.hx",26,0x401666b4)
	HX_STACK_ARG(bmpData,"bmpData")
	HX_STACK_ARG(debugBmp,"debugBmp")
	HX_STACK_ARG(debugShape,"debugShape")
	HX_STACK_LINE(28)
	Array< ::Dynamic > shapes = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(shapes,"shapes");
	HX_STACK_LINE(29)
	::haxe::ds::StringMap dictPixelsDone = ::haxe::ds::StringMap_obj::__new();		HX_STACK_VAR(dictPixelsDone,"dictPixelsDone");
	HX_STACK_LINE(30)
	{
		HX_STACK_LINE(30)
		int _g1 = (int)1;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(30)
		int _g = (bmpData->height - (int)1);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(30)
		while((true)){
			HX_STACK_LINE(30)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(30)
				break;
			}
			HX_STACK_LINE(30)
			int row = (_g1)++;		HX_STACK_VAR(row,"row");
			HX_STACK_LINE(31)
			{
				HX_STACK_LINE(31)
				int _g3 = (int)0;		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(31)
				int _g2 = (bmpData->width - (int)1);		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(31)
				while((true)){
					HX_STACK_LINE(31)
					if ((!(((_g3 < _g2))))){
						HX_STACK_LINE(31)
						break;
					}
					HX_STACK_LINE(31)
					int col = (_g3)++;		HX_STACK_VAR(col,"col");
					struct _Function_5_1{
						inline static int Block( ::hxDaedalus::graphics::_Pixels::PixelsData &bmpData,int &col,int &row){
							HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","hxDaedalus/data/math/Potrace.hx",32,0x401666b4)
							{
								HX_STACK_LINE(32)
								int pos = (int(((row * bmpData->width) + col)) << int((int)2));		HX_STACK_VAR(pos,"pos");
								HX_STACK_LINE(32)
								int r = (int(bmpData->bytes->b->__get((pos + (int)1))) << int((int)16));		HX_STACK_VAR(r,"r");
								HX_STACK_LINE(32)
								int g = (int(bmpData->bytes->b->__get((pos + (int)2))) << int((int)8));		HX_STACK_VAR(g,"g");
								HX_STACK_LINE(32)
								int b = bmpData->bytes->b->__get((pos + (int)3));		HX_STACK_VAR(b,"b");
								HX_STACK_LINE(32)
								return (int((int(r) | int(g))) | int(b));
							}
							return null();
						}
					};
					struct _Function_5_2{
						inline static int Block( ::hxDaedalus::graphics::_Pixels::PixelsData &bmpData,int &col,int &row){
							HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","hxDaedalus/data/math/Potrace.hx",32,0x401666b4)
							{
								HX_STACK_LINE(32)
								int pos = (int(((row * bmpData->width) + ((col + (int)1)))) << int((int)2));		HX_STACK_VAR(pos,"pos");
								HX_STACK_LINE(32)
								int r = (int(bmpData->bytes->b->__get((pos + (int)1))) << int((int)16));		HX_STACK_VAR(r,"r");
								HX_STACK_LINE(32)
								int g = (int(bmpData->bytes->b->__get((pos + (int)2))) << int((int)8));		HX_STACK_VAR(g,"g");
								HX_STACK_LINE(32)
								int b = bmpData->bytes->b->__get((pos + (int)3));		HX_STACK_VAR(b,"b");
								HX_STACK_LINE(32)
								return (int((int(r) | int(g))) | int(b));
							}
							return null();
						}
					};
					HX_STACK_LINE(32)
					if (((bool((_Function_5_1::Block(bmpData,col,row) == (int)16777215)) && bool((_Function_5_2::Block(bmpData,col,row) < (int)16777215))))){
						HX_STACK_LINE(34)
						if ((!(dictPixelsDone->get((((col + (int)1) + HX_CSTRING("_")) + row))))){
							HX_STACK_LINE(35)
							Array< Float > _g4 = ::hxDaedalus::data::math::Potrace_obj::buildShape(bmpData,row,(col + (int)1),dictPixelsDone,debugBmp,debugShape);		HX_STACK_VAR(_g4,"_g4");
							HX_STACK_LINE(35)
							shapes->push(_g4);
						}
					}
				}
			}
		}
	}
	HX_STACK_LINE(40)
	return shapes;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Potrace_obj,buildShapes,return )

Array< Float > Potrace_obj::buildShape( ::hxDaedalus::graphics::_Pixels::PixelsData bmpData,int fromPixelRow,int fromPixelCol,::haxe::ds::StringMap dictPixelsDone,::hxDaedalus::graphics::_Pixels::PixelsData debugBmp,::hxDaedalus::graphics::flash::SimpleDrawingContext debugShape){
	HX_STACK_FRAME("hxDaedalus.data.math.Potrace","buildShape",0x575f3cd6,"hxDaedalus.data.math.Potrace.buildShape","hxDaedalus/data/math/Potrace.hx",44,0x401666b4)
	HX_STACK_ARG(bmpData,"bmpData")
	HX_STACK_ARG(fromPixelRow,"fromPixelRow")
	HX_STACK_ARG(fromPixelCol,"fromPixelCol")
	HX_STACK_ARG(dictPixelsDone,"dictPixelsDone")
	HX_STACK_ARG(debugBmp,"debugBmp")
	HX_STACK_ARG(debugShape,"debugShape")
	HX_STACK_LINE(45)
	Float newX = fromPixelCol;		HX_STACK_VAR(newX,"newX");
	HX_STACK_LINE(46)
	Float newY = fromPixelRow;		HX_STACK_VAR(newY,"newY");
	HX_STACK_LINE(47)
	Array< Float > path = Array_obj< Float >::__new().Add(newX).Add(newY);		HX_STACK_VAR(path,"path");
	HX_STACK_LINE(48)
	{
		HX_STACK_LINE(48)
		dictPixelsDone->set(((newX + HX_CSTRING("_")) + newY),true);
		HX_STACK_LINE(48)
		true;
	}
	HX_STACK_LINE(50)
	::hxDaedalus::data::math::Point2D curDir = ::hxDaedalus::data::math::Point2D_obj::__new((int)0,(int)1);		HX_STACK_VAR(curDir,"curDir");
	HX_STACK_LINE(51)
	::hxDaedalus::data::math::Point2D newDir = ::hxDaedalus::data::math::Point2D_obj::__new(null(),null());		HX_STACK_VAR(newDir,"newDir");
	HX_STACK_LINE(52)
	int newPixelRow;		HX_STACK_VAR(newPixelRow,"newPixelRow");
	HX_STACK_LINE(53)
	int newPixelCol;		HX_STACK_VAR(newPixelCol,"newPixelCol");
	HX_STACK_LINE(54)
	int count = (int)-1;		HX_STACK_VAR(count,"count");
	HX_STACK_LINE(55)
	while((true)){
		HX_STACK_LINE(57)
		if (((debugBmp != null()))){
			HX_STACK_LINE(59)
			int pos = (int(((fromPixelRow * debugBmp->width) + fromPixelCol)) << int((int)2));		HX_STACK_VAR(pos,"pos");
			HX_STACK_LINE(59)
			int a = (int)255;		HX_STACK_VAR(a,"a");
			HX_STACK_LINE(59)
			int r = (int)255;		HX_STACK_VAR(r,"r");
			HX_STACK_LINE(59)
			int g = (int)0;		HX_STACK_VAR(g,"g");
			HX_STACK_LINE(59)
			int b = (int)0;		HX_STACK_VAR(b,"b");
			HX_STACK_LINE(59)
			debugBmp->bytes->b[pos] = a;
			HX_STACK_LINE(59)
			debugBmp->bytes->b[(pos + (int)1)] = r;
			HX_STACK_LINE(59)
			debugBmp->bytes->b[(pos + (int)2)] = g;
			HX_STACK_LINE(59)
			debugBmp->bytes->b[(pos + (int)3)] = b;
		}
		HX_STACK_LINE(64)
		int _g = ::Std_obj::_int(((fromPixelRow + curDir->x) + curDir->y));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(64)
		newPixelRow = _g;
		HX_STACK_LINE(65)
		int _g1 = ::Std_obj::_int(((fromPixelCol + curDir->x) - curDir->y));		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(65)
		newPixelCol = _g1;
		struct _Function_2_1{
			inline static int Block( ::hxDaedalus::graphics::_Pixels::PixelsData &bmpData,int &newPixelCol,int &newPixelRow){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","hxDaedalus/data/math/Potrace.hx",68,0x401666b4)
				{
					HX_STACK_LINE(68)
					int pos = (int(((newPixelRow * bmpData->width) + newPixelCol)) << int((int)2));		HX_STACK_VAR(pos,"pos");
					HX_STACK_LINE(68)
					int r = (int(bmpData->bytes->b->__get((pos + (int)1))) << int((int)16));		HX_STACK_VAR(r,"r");
					HX_STACK_LINE(68)
					int g = (int(bmpData->bytes->b->__get((pos + (int)2))) << int((int)8));		HX_STACK_VAR(g,"g");
					HX_STACK_LINE(68)
					int b = bmpData->bytes->b->__get((pos + (int)3));		HX_STACK_VAR(b,"b");
					HX_STACK_LINE(68)
					return (int((int(r) | int(g))) | int(b));
				}
				return null();
			}
		};
		HX_STACK_LINE(68)
		if (((_Function_2_1::Block(bmpData,newPixelCol,newPixelRow) < (int)16777215))){
			HX_STACK_LINE(71)
			newDir->x = -(curDir->y);
			HX_STACK_LINE(72)
			newDir->y = curDir->x;
		}
		else{
			HX_STACK_LINE(78)
			int _g2 = ::Std_obj::_int((fromPixelRow + curDir->y));		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(78)
			newPixelRow = _g2;
			HX_STACK_LINE(79)
			int _g3 = ::Std_obj::_int((fromPixelCol + curDir->x));		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(79)
			newPixelCol = _g3;
			struct _Function_3_1{
				inline static int Block( ::hxDaedalus::graphics::_Pixels::PixelsData &bmpData,int &newPixelCol,int &newPixelRow){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","hxDaedalus/data/math/Potrace.hx",81,0x401666b4)
					{
						HX_STACK_LINE(81)
						int pos = (int(((newPixelRow * bmpData->width) + newPixelCol)) << int((int)2));		HX_STACK_VAR(pos,"pos");
						HX_STACK_LINE(81)
						int r = (int(bmpData->bytes->b->__get((pos + (int)1))) << int((int)16));		HX_STACK_VAR(r,"r");
						HX_STACK_LINE(81)
						int g = (int(bmpData->bytes->b->__get((pos + (int)2))) << int((int)8));		HX_STACK_VAR(g,"g");
						HX_STACK_LINE(81)
						int b = bmpData->bytes->b->__get((pos + (int)3));		HX_STACK_VAR(b,"b");
						HX_STACK_LINE(81)
						return (int((int(r) | int(g))) | int(b));
					}
					return null();
				}
			};
			HX_STACK_LINE(81)
			if (((_Function_3_1::Block(bmpData,newPixelCol,newPixelRow) < (int)16777215))){
				HX_STACK_LINE(84)
				newDir->x = curDir->x;
				HX_STACK_LINE(85)
				newDir->y = curDir->y;
			}
			else{
				HX_STACK_LINE(91)
				newPixelRow = fromPixelRow;
				HX_STACK_LINE(92)
				newPixelCol = fromPixelCol;
				HX_STACK_LINE(94)
				newDir->x = curDir->y;
				HX_STACK_LINE(95)
				newDir->y = -(curDir->x);
			}
		}
		HX_STACK_LINE(98)
		newX = (newX + curDir->x);
		HX_STACK_LINE(99)
		newY = (newY + curDir->y);
		HX_STACK_LINE(101)
		if (((bool((newX == path->__get((int)0))) && bool((newY == path->__get((int)1)))))){
			HX_STACK_LINE(103)
			break;
		}
		else{
			HX_STACK_LINE(107)
			path->push(newX);
			HX_STACK_LINE(108)
			path->push(newY);
			HX_STACK_LINE(109)
			{
				HX_STACK_LINE(109)
				dictPixelsDone->set(((newX + HX_CSTRING("_")) + newY),true);
				HX_STACK_LINE(109)
				true;
			}
			HX_STACK_LINE(110)
			fromPixelRow = newPixelRow;
			HX_STACK_LINE(111)
			fromPixelCol = newPixelCol;
			HX_STACK_LINE(112)
			curDir->x = newDir->x;
			HX_STACK_LINE(113)
			curDir->y = newDir->y;
		}
		HX_STACK_LINE(116)
		(count)--;
		HX_STACK_LINE(117)
		if (((count == (int)0))){
			HX_STACK_LINE(119)
			break;
		}
	}
	HX_STACK_LINE(123)
	if (((debugShape != null()))){
		HX_STACK_LINE(125)
		debugShape->graphics->lineStyle(0.5,(int)65280,(int)1,null(),null(),null(),null(),null());
		HX_STACK_LINE(126)
		debugShape->graphics->moveTo(path->__get((int)0),path->__get((int)1));
		HX_STACK_LINE(127)
		int i = (int)2;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(128)
		while((true)){
			HX_STACK_LINE(128)
			if ((!(((i < path->length))))){
				HX_STACK_LINE(128)
				break;
			}
			HX_STACK_LINE(129)
			debugShape->graphics->lineTo(path->__get(i),path->__get((i + (int)1)));
			HX_STACK_LINE(130)
			hx::AddEq(i,(int)2);
		}
		HX_STACK_LINE(132)
		debugShape->graphics->lineTo(path->__get((int)0),path->__get((int)1));
	}
	HX_STACK_LINE(135)
	return path;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC6(Potrace_obj,buildShape,return )

::hxDaedalus::data::graph::Graph Potrace_obj::buildGraph( Array< Float > shape){
	HX_STACK_FRAME("hxDaedalus.data.math.Potrace","buildGraph",0x752c6903,"hxDaedalus.data.math.Potrace.buildGraph","hxDaedalus/data/math/Potrace.hx",139,0x401666b4)
	HX_STACK_ARG(shape,"shape")
	HX_STACK_LINE(140)
	int i;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(141)
	::hxDaedalus::data::graph::Graph graph = ::hxDaedalus::data::graph::Graph_obj::__new();		HX_STACK_VAR(graph,"graph");
	HX_STACK_LINE(142)
	::hxDaedalus::data::graph::GraphNode node;		HX_STACK_VAR(node,"node");
	HX_STACK_LINE(143)
	i = (int)0;
	HX_STACK_LINE(144)
	while((true)){
		HX_STACK_LINE(144)
		if ((!(((i < shape->length))))){
			HX_STACK_LINE(144)
			break;
		}
		HX_STACK_LINE(145)
		::hxDaedalus::data::graph::GraphNode _g = graph->insertNode();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(145)
		node = _g;
		HX_STACK_LINE(146)
		::hxDaedalus::data::math::NodeData _g1 = ::hxDaedalus::data::math::NodeData_obj::__new();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(146)
		node->set_data(_g1);
		HX_STACK_LINE(147)
		node->get_data()->index = i;
		HX_STACK_LINE(148)
		::hxDaedalus::data::math::Point2D _g2 = ::hxDaedalus::data::math::Point2D_obj::__new(shape->__get(i),shape->__get((i + (int)1)));		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(148)
		node->get_data()->point = _g2;
		HX_STACK_LINE(149)
		hx::AddEq(i,(int)2);
	}
	HX_STACK_LINE(152)
	::hxDaedalus::data::graph::GraphNode node1;		HX_STACK_VAR(node1,"node1");
	HX_STACK_LINE(153)
	::hxDaedalus::data::graph::GraphNode node2;		HX_STACK_VAR(node2,"node2");
	HX_STACK_LINE(154)
	::hxDaedalus::data::graph::GraphNode subNode;		HX_STACK_VAR(subNode,"subNode");
	HX_STACK_LINE(155)
	Float distSqrd;		HX_STACK_VAR(distSqrd,"distSqrd");
	HX_STACK_LINE(156)
	Float sumDistSqrd;		HX_STACK_VAR(sumDistSqrd,"sumDistSqrd");
	HX_STACK_LINE(157)
	int count;		HX_STACK_VAR(count,"count");
	HX_STACK_LINE(158)
	bool isValid;		HX_STACK_VAR(isValid,"isValid");
	HX_STACK_LINE(159)
	::hxDaedalus::data::graph::GraphEdge edge;		HX_STACK_VAR(edge,"edge");
	HX_STACK_LINE(160)
	::hxDaedalus::data::math::EdgeData edgeData;		HX_STACK_VAR(edgeData,"edgeData");
	HX_STACK_LINE(161)
	::hxDaedalus::data::graph::GraphNode _g3 = graph->get_node();		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(161)
	node1 = _g3;
	HX_STACK_LINE(162)
	while((true)){
		HX_STACK_LINE(162)
		if ((!(((node1 != null()))))){
			HX_STACK_LINE(162)
			break;
		}
		HX_STACK_LINE(164)
		::hxDaedalus::data::graph::GraphNode _g4 = node1->get_next();		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(164)
		::hxDaedalus::data::graph::GraphNode _g5;		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(164)
		if (((_g4 != null()))){
			HX_STACK_LINE(164)
			_g5 = node1->get_next();
		}
		else{
			HX_STACK_LINE(164)
			_g5 = graph->get_node();
		}
		HX_STACK_LINE(164)
		node2 = _g5;
		HX_STACK_LINE(165)
		while((true)){
			HX_STACK_LINE(165)
			if ((!(((node2 != node1))))){
				HX_STACK_LINE(165)
				break;
			}
			HX_STACK_LINE(167)
			isValid = true;
			HX_STACK_LINE(168)
			::hxDaedalus::data::graph::GraphNode _g6 = node1->get_next();		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(168)
			::hxDaedalus::data::graph::GraphNode _g7;		HX_STACK_VAR(_g7,"_g7");
			HX_STACK_LINE(168)
			if (((_g6 != null()))){
				HX_STACK_LINE(168)
				_g7 = node1->get_next();
			}
			else{
				HX_STACK_LINE(168)
				_g7 = graph->get_node();
			}
			HX_STACK_LINE(168)
			subNode = _g7;
			HX_STACK_LINE(169)
			count = (int)2;
			HX_STACK_LINE(170)
			sumDistSqrd = (int)0;
			HX_STACK_LINE(171)
			while((true)){
				HX_STACK_LINE(171)
				if ((!(((subNode != node2))))){
					HX_STACK_LINE(171)
					break;
				}
				HX_STACK_LINE(173)
				Float _g8 = ::hxDaedalus::data::math::Geom2D_obj::distanceSquaredPointToSegment(subNode->get_data()->point->x,subNode->get_data()->point->y,node1->get_data()->point->x,node1->get_data()->point->y,node2->get_data()->point->x,node2->get_data()->point->y);		HX_STACK_VAR(_g8,"_g8");
				HX_STACK_LINE(173)
				distSqrd = _g8;
				HX_STACK_LINE(174)
				if (((distSqrd < (int)0))){
					HX_STACK_LINE(175)
					distSqrd = (int)0;
				}
				HX_STACK_LINE(176)
				if (((distSqrd >= ::hxDaedalus::data::math::Potrace_obj::maxDistance))){
					HX_STACK_LINE(179)
					isValid = false;
					HX_STACK_LINE(180)
					break;
				}
				HX_STACK_LINE(183)
				(count)++;
				HX_STACK_LINE(184)
				hx::AddEq(sumDistSqrd,distSqrd);
				HX_STACK_LINE(185)
				::hxDaedalus::data::graph::GraphNode _g9 = subNode->get_next();		HX_STACK_VAR(_g9,"_g9");
				HX_STACK_LINE(185)
				::hxDaedalus::data::graph::GraphNode _g10;		HX_STACK_VAR(_g10,"_g10");
				HX_STACK_LINE(185)
				if (((_g9 != null()))){
					HX_STACK_LINE(185)
					_g10 = subNode->get_next();
				}
				else{
					HX_STACK_LINE(185)
					_g10 = graph->get_node();
				}
				HX_STACK_LINE(185)
				subNode = _g10;
			}
			HX_STACK_LINE(188)
			if ((!(isValid))){
				HX_STACK_LINE(191)
				break;
			}
			HX_STACK_LINE(194)
			::hxDaedalus::data::graph::GraphEdge _g11 = graph->insertEdge(node1,node2);		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(194)
			edge = _g11;
			HX_STACK_LINE(195)
			::hxDaedalus::data::math::EdgeData _g12 = ::hxDaedalus::data::math::EdgeData_obj::__new();		HX_STACK_VAR(_g12,"_g12");
			HX_STACK_LINE(195)
			edgeData = _g12;
			HX_STACK_LINE(196)
			edgeData->sumDistancesSquared = sumDistSqrd;
			HX_STACK_LINE(197)
			Float _g13 = node1->get_data()->point->distanceTo(node2->get_data()->point);		HX_STACK_VAR(_g13,"_g13");
			HX_STACK_LINE(197)
			edgeData->length = _g13;
			HX_STACK_LINE(198)
			edgeData->nodesCount = count;
			HX_STACK_LINE(199)
			edge->set_data(edgeData);
			HX_STACK_LINE(201)
			::hxDaedalus::data::graph::GraphNode _g14 = node2->get_next();		HX_STACK_VAR(_g14,"_g14");
			HX_STACK_LINE(201)
			::hxDaedalus::data::graph::GraphNode _g15;		HX_STACK_VAR(_g15,"_g15");
			HX_STACK_LINE(201)
			if (((_g14 != null()))){
				HX_STACK_LINE(201)
				_g15 = node2->get_next();
			}
			else{
				HX_STACK_LINE(201)
				_g15 = graph->get_node();
			}
			HX_STACK_LINE(201)
			node2 = _g15;
		}
		HX_STACK_LINE(204)
		::hxDaedalus::data::graph::GraphNode _g16 = node1->get_next();		HX_STACK_VAR(_g16,"_g16");
		HX_STACK_LINE(204)
		node1 = _g16;
	}
	HX_STACK_LINE(207)
	return graph;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Potrace_obj,buildGraph,return )

Array< Float > Potrace_obj::buildPolygon( ::hxDaedalus::data::graph::Graph graph,Dynamic debugShape){
	HX_STACK_FRAME("hxDaedalus.data.math.Potrace","buildPolygon",0x0664f36f,"hxDaedalus.data.math.Potrace.buildPolygon","hxDaedalus/data/math/Potrace.hx",211,0x401666b4)
	HX_STACK_ARG(graph,"graph")
	HX_STACK_ARG(debugShape,"debugShape")
	HX_STACK_LINE(212)
	Array< Float > polygon = Array_obj< Float >::__new();		HX_STACK_VAR(polygon,"polygon");
	HX_STACK_LINE(214)
	::hxDaedalus::data::graph::GraphNode currNode;		HX_STACK_VAR(currNode,"currNode");
	HX_STACK_LINE(216)
	int minNodeIndex = (int)2147483647;		HX_STACK_VAR(minNodeIndex,"minNodeIndex");
	HX_STACK_LINE(217)
	::hxDaedalus::data::graph::GraphEdge edge;		HX_STACK_VAR(edge,"edge");
	HX_STACK_LINE(218)
	Float score;		HX_STACK_VAR(score,"score");
	HX_STACK_LINE(219)
	Float higherScore;		HX_STACK_VAR(higherScore,"higherScore");
	HX_STACK_LINE(220)
	::hxDaedalus::data::graph::GraphEdge lowerScoreEdge = null();		HX_STACK_VAR(lowerScoreEdge,"lowerScoreEdge");
	HX_STACK_LINE(221)
	::hxDaedalus::data::graph::GraphNode _g = graph->get_node();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(221)
	currNode = _g;
	HX_STACK_LINE(222)
	while((true)){
		HX_STACK_LINE(222)
		if ((!(((currNode->get_data()->index < minNodeIndex))))){
			HX_STACK_LINE(222)
			break;
		}
		HX_STACK_LINE(224)
		minNodeIndex = currNode->get_data()->index;
		HX_STACK_LINE(226)
		polygon->push(currNode->get_data()->point->x);
		HX_STACK_LINE(227)
		polygon->push(currNode->get_data()->point->y);
		HX_STACK_LINE(229)
		higherScore = (int)0;
		HX_STACK_LINE(231)
		::hxDaedalus::data::graph::GraphEdge _g1 = currNode->get_outgoingEdge();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(231)
		edge = _g1;
		HX_STACK_LINE(232)
		while((true)){
			HX_STACK_LINE(232)
			if ((!(((edge != null()))))){
				HX_STACK_LINE(232)
				break;
			}
			HX_STACK_LINE(234)
			Float _g2 = ::Math_obj::sqrt((Float(edge->get_data()->sumDistancesSquared) / Float(edge->get_data()->nodesCount)));		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(234)
			Float _g3 = (edge->get_data()->length * _g2);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(234)
			Float _g4 = (edge->get_data()->nodesCount - _g3);		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(234)
			score = _g4;
			HX_STACK_LINE(235)
			if (((score > higherScore))){
				HX_STACK_LINE(237)
				higherScore = score;
				HX_STACK_LINE(238)
				lowerScoreEdge = edge;
			}
			HX_STACK_LINE(241)
			::hxDaedalus::data::graph::GraphEdge _g5 = edge->get_rotNextEdge();		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(241)
			edge = _g5;
		}
		HX_STACK_LINE(244)
		::hxDaedalus::data::graph::GraphNode _g6 = lowerScoreEdge->get_destinationNode();		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(244)
		currNode = _g6;
	}
	HX_STACK_LINE(247)
	int _g7 = ::hxDaedalus::data::math::Geom2D_obj::getDirection(polygon->__get((polygon->length - (int)2)),polygon->__get((polygon->length - (int)1)),polygon->__get((int)0),polygon->__get((int)1),polygon->__get((int)2),polygon->__get((int)3));		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(247)
	if (((_g7 == (int)0))){
		HX_STACK_LINE(249)
		polygon->shift();
		HX_STACK_LINE(250)
		polygon->shift();
	}
	HX_STACK_LINE(253)
	if (((debugShape != null()))){
		HX_STACK_LINE(255)
		debugShape->__Field(HX_CSTRING("graphics"),true)->__Field(HX_CSTRING("lineStyle"),true)(0.5,(int)255);
		HX_STACK_LINE(256)
		debugShape->__Field(HX_CSTRING("graphics"),true)->__Field(HX_CSTRING("moveTo"),true)(polygon->__get((int)0),polygon->__get((int)1));
		HX_STACK_LINE(257)
		int i = (int)2;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(258)
		while((true)){
			HX_STACK_LINE(258)
			if ((!(((i < polygon->length))))){
				HX_STACK_LINE(258)
				break;
			}
			HX_STACK_LINE(259)
			debugShape->__Field(HX_CSTRING("graphics"),true)->__Field(HX_CSTRING("lineTo"),true)(polygon->__get(i),polygon->__get((i + (int)1)));
			HX_STACK_LINE(260)
			hx::AddEq(i,(int)2);
		}
		HX_STACK_LINE(262)
		debugShape->__Field(HX_CSTRING("graphics"),true)->__Field(HX_CSTRING("lineTo"),true)(polygon->__get((int)0),polygon->__get((int)1));
	}
	HX_STACK_LINE(265)
	return polygon;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Potrace_obj,buildPolygon,return )


Potrace_obj::Potrace_obj()
{
}

Dynamic Potrace_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"buildShape") ) { return buildShape_dyn(); }
		if (HX_FIELD_EQ(inName,"buildGraph") ) { return buildGraph_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"maxDistance") ) { return maxDistance; }
		if (HX_FIELD_EQ(inName,"buildShapes") ) { return buildShapes_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"buildPolygon") ) { return buildPolygon_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Potrace_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 11:
		if (HX_FIELD_EQ(inName,"maxDistance") ) { maxDistance=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Potrace_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("MAX_INT"),
	HX_CSTRING("maxDistance"),
	HX_CSTRING("buildShapes"),
	HX_CSTRING("buildShape"),
	HX_CSTRING("buildGraph"),
	HX_CSTRING("buildPolygon"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Potrace_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Potrace_obj::MAX_INT,"MAX_INT");
	HX_MARK_MEMBER_NAME(Potrace_obj::maxDistance,"maxDistance");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Potrace_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Potrace_obj::MAX_INT,"MAX_INT");
	HX_VISIT_MEMBER_NAME(Potrace_obj::maxDistance,"maxDistance");
};

#endif

Class Potrace_obj::__mClass;

void Potrace_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDaedalus.data.math.Potrace"), hx::TCanCast< Potrace_obj> ,sStaticFields,sMemberFields,
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

void Potrace_obj::__boot()
{
	MAX_INT= (int)2147483647;
	maxDistance= (int)1;
}

} // end namespace hxDaedalus
} // end namespace data
} // end namespace math
