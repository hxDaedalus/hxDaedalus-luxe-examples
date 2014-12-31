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
#ifndef INCLUDED_hxDaedalus_data_Object
#include <hxDaedalus/data/Object.h>
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
#ifndef INCLUDED_hxDaedalus_data_math_Matrix2D
#include <hxDaedalus/data/math/Matrix2D.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_math_Point2D
#include <hxDaedalus/data/math/Point2D.h>
#endif
#ifndef INCLUDED_hxDaedalus_iterators_FromMeshToVertices
#include <hxDaedalus/iterators/FromMeshToVertices.h>
#endif
#ifndef INCLUDED_hxDaedalus_iterators_FromVertexToIncomingEdges
#include <hxDaedalus/iterators/FromVertexToIncomingEdges.h>
#endif
#ifndef INCLUDED_hxDaedalus_iterators_FromVertexToOutgoingEdges
#include <hxDaedalus/iterators/FromVertexToOutgoingEdges.h>
#endif
namespace hxDaedalus{
namespace data{

Void Mesh_obj::__construct(Float width,Float height)
{
HX_STACK_FRAME("hxDaedalus.data.Mesh","new",0x76b3546a,"hxDaedalus.data.Mesh.new","hxDaedalus/data/Mesh.hx",14,0xb69595e6)
HX_STACK_THIS(this)
HX_STACK_ARG(width,"width")
HX_STACK_ARG(height,"height")
{
	HX_STACK_LINE(178)
	this->__objectsUpdateInProgress = false;
	HX_STACK_LINE(38)
	this->__edgesToCheck = null();
	HX_STACK_LINE(37)
	this->__centerVertex = null();
	HX_STACK_LINE(34)
	this->_objects = null();
	HX_STACK_LINE(33)
	this->_constraintShapes = null();
	HX_STACK_LINE(32)
	this->_faces = null();
	HX_STACK_LINE(31)
	this->_edges = null();
	HX_STACK_LINE(30)
	this->_vertices = null();
	HX_STACK_LINE(28)
	this->_clipping = false;
	HX_STACK_LINE(27)
	this->_height = (int)0;
	HX_STACK_LINE(26)
	this->_width = (int)0;
	HX_STACK_LINE(42)
	this->_id = ::hxDaedalus::data::Mesh_obj::INC;
	HX_STACK_LINE(43)
	(::hxDaedalus::data::Mesh_obj::INC)++;
	HX_STACK_LINE(45)
	this->_width = width;
	HX_STACK_LINE(46)
	this->_height = height;
	HX_STACK_LINE(47)
	this->_clipping = true;
	HX_STACK_LINE(49)
	Array< ::Dynamic > _g = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(49)
	this->_vertices = _g;
	HX_STACK_LINE(50)
	Array< ::Dynamic > _g1 = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(50)
	this->_edges = _g1;
	HX_STACK_LINE(51)
	Array< ::Dynamic > _g2 = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(51)
	this->_faces = _g2;
	HX_STACK_LINE(52)
	Array< ::Dynamic > _g3 = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(52)
	this->_constraintShapes = _g3;
	HX_STACK_LINE(53)
	Array< ::Dynamic > _g4 = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(53)
	this->_objects = _g4;
	HX_STACK_LINE(55)
	Array< ::Dynamic > _g5 = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(55)
	this->__edgesToCheck = _g5;
}
;
	return null();
}

//Mesh_obj::~Mesh_obj() { }

Dynamic Mesh_obj::__CreateEmpty() { return  new Mesh_obj; }
hx::ObjectPtr< Mesh_obj > Mesh_obj::__new(Float width,Float height)
{  hx::ObjectPtr< Mesh_obj > result = new Mesh_obj();
	result->__construct(width,height);
	return result;}

Dynamic Mesh_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Mesh_obj > result = new Mesh_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Float Mesh_obj::get_height( ){
	HX_STACK_FRAME("hxDaedalus.data.Mesh","get_height",0xd524e8e6,"hxDaedalus.data.Mesh.get_height","hxDaedalus/data/Mesh.hx",60,0xb69595e6)
	HX_STACK_THIS(this)
	HX_STACK_LINE(60)
	return this->_height;
}


HX_DEFINE_DYNAMIC_FUNC0(Mesh_obj,get_height,return )

Float Mesh_obj::get_width( ){
	HX_STACK_FRAME("hxDaedalus.data.Mesh","get_width",0xc6bd39e7,"hxDaedalus.data.Mesh.get_width","hxDaedalus/data/Mesh.hx",65,0xb69595e6)
	HX_STACK_THIS(this)
	HX_STACK_LINE(65)
	return this->_width;
}


HX_DEFINE_DYNAMIC_FUNC0(Mesh_obj,get_width,return )

bool Mesh_obj::get_clipping( ){
	HX_STACK_FRAME("hxDaedalus.data.Mesh","get_clipping",0x4fd46801,"hxDaedalus.data.Mesh.get_clipping","hxDaedalus/data/Mesh.hx",70,0xb69595e6)
	HX_STACK_THIS(this)
	HX_STACK_LINE(70)
	return this->_clipping;
}


HX_DEFINE_DYNAMIC_FUNC0(Mesh_obj,get_clipping,return )

bool Mesh_obj::set_clipping( bool value){
	HX_STACK_FRAME("hxDaedalus.data.Mesh","set_clipping",0x64cd8b75,"hxDaedalus.data.Mesh.set_clipping","hxDaedalus/data/Mesh.hx",74,0xb69595e6)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(75)
	this->_clipping = value;
	HX_STACK_LINE(76)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Mesh_obj,set_clipping,return )

int Mesh_obj::get_id( ){
	HX_STACK_FRAME("hxDaedalus.data.Mesh","get_id",0x78f7115a,"hxDaedalus.data.Mesh.get_id","hxDaedalus/data/Mesh.hx",81,0xb69595e6)
	HX_STACK_THIS(this)
	HX_STACK_LINE(81)
	return this->_id;
}


HX_DEFINE_DYNAMIC_FUNC0(Mesh_obj,get_id,return )

Void Mesh_obj::dispose( ){
{
		HX_STACK_FRAME("hxDaedalus.data.Mesh","dispose",0xf3bfd1a9,"hxDaedalus.data.Mesh.dispose","hxDaedalus/data/Mesh.hx",85,0xb69595e6)
		HX_STACK_THIS(this)
		HX_STACK_LINE(86)
		while((true)){
			HX_STACK_LINE(86)
			if ((!(((this->_vertices->length > (int)0))))){
				HX_STACK_LINE(86)
				break;
			}
			HX_STACK_LINE(86)
			this->_vertices->pop().StaticCast< ::hxDaedalus::data::Vertex >()->dispose();
		}
		HX_STACK_LINE(87)
		this->_vertices = null();
		HX_STACK_LINE(88)
		while((true)){
			HX_STACK_LINE(88)
			if ((!(((this->_edges->length > (int)0))))){
				HX_STACK_LINE(88)
				break;
			}
			HX_STACK_LINE(88)
			this->_edges->pop().StaticCast< ::hxDaedalus::data::Edge >()->dispose();
		}
		HX_STACK_LINE(89)
		this->_edges = null();
		HX_STACK_LINE(90)
		while((true)){
			HX_STACK_LINE(90)
			if ((!(((this->_faces->length > (int)0))))){
				HX_STACK_LINE(90)
				break;
			}
			HX_STACK_LINE(90)
			this->_faces->pop().StaticCast< ::hxDaedalus::data::Face >()->dispose();
		}
		HX_STACK_LINE(91)
		this->_faces = null();
		HX_STACK_LINE(92)
		while((true)){
			HX_STACK_LINE(92)
			if ((!(((this->_constraintShapes->length > (int)0))))){
				HX_STACK_LINE(92)
				break;
			}
			HX_STACK_LINE(92)
			this->_constraintShapes->pop().StaticCast< ::hxDaedalus::data::ConstraintShape >()->dispose();
		}
		HX_STACK_LINE(93)
		this->_constraintShapes = null();
		HX_STACK_LINE(94)
		while((true)){
			HX_STACK_LINE(94)
			if ((!(((this->_objects->length > (int)0))))){
				HX_STACK_LINE(94)
				break;
			}
			HX_STACK_LINE(94)
			this->_objects->pop().StaticCast< ::hxDaedalus::data::Object >()->dispose();
		}
		HX_STACK_LINE(95)
		this->_objects = null();
		HX_STACK_LINE(97)
		this->__edgesToCheck = null();
		HX_STACK_LINE(98)
		this->__centerVertex = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Mesh_obj,dispose,(void))

Array< ::Dynamic > Mesh_obj::get___constraintShapes( ){
	HX_STACK_FRAME("hxDaedalus.data.Mesh","get___constraintShapes",0xf3cce90e,"hxDaedalus.data.Mesh.get___constraintShapes","hxDaedalus/data/Mesh.hx",103,0xb69595e6)
	HX_STACK_THIS(this)
	HX_STACK_LINE(103)
	return this->_constraintShapes;
}


HX_DEFINE_DYNAMIC_FUNC0(Mesh_obj,get___constraintShapes,return )

Void Mesh_obj::buildFromRecord( ::String rec){
{
		HX_STACK_FRAME("hxDaedalus.data.Mesh","buildFromRecord",0xec1dcb73,"hxDaedalus.data.Mesh.buildFromRecord","hxDaedalus/data/Mesh.hx",107,0xb69595e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(rec,"rec")
		HX_STACK_LINE(108)
		Dynamic positions = rec.split(HX_CSTRING(";"));		HX_STACK_VAR(positions,"positions");
		HX_STACK_LINE(109)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(110)
		while((true)){
			HX_STACK_LINE(110)
			if ((!(((i < positions->__Field(HX_CSTRING("length"),true)))))){
				HX_STACK_LINE(110)
				break;
			}
			HX_STACK_LINE(111)
			Float _g = ::Std_obj::parseFloat(positions->__GetItem(i));		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(111)
			Float _g1 = ::Std_obj::parseFloat(positions->__GetItem((i + (int)1)));		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(111)
			Float _g2 = ::Std_obj::parseFloat(positions->__GetItem((i + (int)2)));		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(111)
			Float _g3 = ::Std_obj::parseFloat(positions->__GetItem((i + (int)3)));		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(111)
			this->insertConstraintSegment(_g,_g1,_g2,_g3);
			HX_STACK_LINE(112)
			hx::AddEq(i,(int)4);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Mesh_obj,buildFromRecord,(void))

Void Mesh_obj::insertObject( ::hxDaedalus::data::Object object){
{
		HX_STACK_FRAME("hxDaedalus.data.Mesh","insertObject",0xba45918e,"hxDaedalus.data.Mesh.insertObject","hxDaedalus/data/Mesh.hx",117,0xb69595e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(object,"object")
		HX_STACK_LINE(118)
		::hxDaedalus::data::ConstraintShape _g = object->get_constraintShape();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(118)
		if (((_g != null()))){
			HX_STACK_LINE(118)
			this->deleteObject(object);
		}
		HX_STACK_LINE(120)
		::hxDaedalus::data::ConstraintShape shape = ::hxDaedalus::data::ConstraintShape_obj::__new();		HX_STACK_VAR(shape,"shape");
		HX_STACK_LINE(121)
		::hxDaedalus::data::ConstraintSegment segment;		HX_STACK_VAR(segment,"segment");
		HX_STACK_LINE(122)
		Array< Float > coordinates = object->get_coordinates();		HX_STACK_VAR(coordinates,"coordinates");
		HX_STACK_LINE(123)
		::hxDaedalus::data::math::Matrix2D m = object->get_matrix();		HX_STACK_VAR(m,"m");
		HX_STACK_LINE(125)
		object->updateMatrixFromValues();
		HX_STACK_LINE(126)
		Float x1;		HX_STACK_VAR(x1,"x1");
		HX_STACK_LINE(127)
		Float y1;		HX_STACK_VAR(y1,"y1");
		HX_STACK_LINE(128)
		Float x2;		HX_STACK_VAR(x2,"x2");
		HX_STACK_LINE(129)
		Float y2;		HX_STACK_VAR(y2,"y2");
		HX_STACK_LINE(130)
		Float transfx1;		HX_STACK_VAR(transfx1,"transfx1");
		HX_STACK_LINE(131)
		Float transfy1;		HX_STACK_VAR(transfy1,"transfy1");
		HX_STACK_LINE(132)
		Float transfx2;		HX_STACK_VAR(transfx2,"transfx2");
		HX_STACK_LINE(133)
		Float transfy2;		HX_STACK_VAR(transfy2,"transfy2");
		HX_STACK_LINE(135)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(136)
		while((true)){
			HX_STACK_LINE(136)
			if ((!(((i < coordinates->length))))){
				HX_STACK_LINE(136)
				break;
			}
			HX_STACK_LINE(137)
			x1 = coordinates->__get(i);
			HX_STACK_LINE(138)
			y1 = coordinates->__get((i + (int)1));
			HX_STACK_LINE(139)
			x2 = coordinates->__get((i + (int)2));
			HX_STACK_LINE(140)
			y2 = coordinates->__get((i + (int)3));
			HX_STACK_LINE(141)
			Float _g1 = m->transformX(x1,y1);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(141)
			transfx1 = _g1;
			HX_STACK_LINE(142)
			Float _g2 = m->transformY(x1,y1);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(142)
			transfy1 = _g2;
			HX_STACK_LINE(143)
			Float _g3 = m->transformX(x2,y2);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(143)
			transfx2 = _g3;
			HX_STACK_LINE(144)
			Float _g4 = m->transformY(x2,y2);		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(144)
			transfy2 = _g4;
			HX_STACK_LINE(146)
			::hxDaedalus::data::ConstraintSegment _g5 = this->insertConstraintSegment(transfx1,transfy1,transfx2,transfy2);		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(146)
			segment = _g5;
			HX_STACK_LINE(147)
			if (((segment != null()))){
				HX_STACK_LINE(149)
				segment->fromShape = shape;
				HX_STACK_LINE(150)
				shape->segments->push(segment);
			}
			HX_STACK_LINE(152)
			hx::AddEq(i,(int)4);
		}
		HX_STACK_LINE(155)
		this->_constraintShapes->push(shape);
		HX_STACK_LINE(156)
		object->set_constraintShape(shape);
		HX_STACK_LINE(158)
		if ((!(this->__objectsUpdateInProgress))){
			HX_STACK_LINE(159)
			this->_objects->push(object);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Mesh_obj,insertObject,(void))

Void Mesh_obj::deleteObject( ::hxDaedalus::data::Object object){
{
		HX_STACK_FRAME("hxDaedalus.data.Mesh","deleteObject",0xaa505000,"hxDaedalus.data.Mesh.deleteObject","hxDaedalus/data/Mesh.hx",164,0xb69595e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(object,"object")
		HX_STACK_LINE(165)
		::hxDaedalus::data::ConstraintShape _g = object->get_constraintShape();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(165)
		if (((_g == null()))){
			HX_STACK_LINE(165)
			return null();
		}
		HX_STACK_LINE(168)
		::hxDaedalus::data::ConstraintShape _g1 = object->get_constraintShape();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(168)
		this->deleteConstraintShape(_g1);
		HX_STACK_LINE(169)
		object->set_constraintShape(null());
		HX_STACK_LINE(171)
		if ((!(this->__objectsUpdateInProgress))){
			HX_STACK_LINE(173)
			int index = this->_objects->indexOf(object,null());		HX_STACK_VAR(index,"index");
			HX_STACK_LINE(174)
			this->_objects->splice(index,(int)1);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Mesh_obj,deleteObject,(void))

Void Mesh_obj::updateObjects( ){
{
		HX_STACK_FRAME("hxDaedalus.data.Mesh","updateObjects",0xc8da8255,"hxDaedalus.data.Mesh.updateObjects","hxDaedalus/data/Mesh.hx",180,0xb69595e6)
		HX_STACK_THIS(this)
		HX_STACK_LINE(181)
		this->__objectsUpdateInProgress = true;
		HX_STACK_LINE(182)
		{
			HX_STACK_LINE(182)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(182)
			int _g = this->_objects->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(182)
			while((true)){
				HX_STACK_LINE(182)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(182)
					break;
				}
				HX_STACK_LINE(182)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(183)
				if ((this->_objects->__get(i).StaticCast< ::hxDaedalus::data::Object >()->get_hasChanged())){
					HX_STACK_LINE(185)
					this->deleteObject(this->_objects->__get(i).StaticCast< ::hxDaedalus::data::Object >());
					HX_STACK_LINE(186)
					this->insertObject(this->_objects->__get(i).StaticCast< ::hxDaedalus::data::Object >());
					HX_STACK_LINE(187)
					this->_objects->__get(i).StaticCast< ::hxDaedalus::data::Object >()->set_hasChanged(false);
				}
			}
		}
		HX_STACK_LINE(190)
		this->__objectsUpdateInProgress = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Mesh_obj,updateObjects,(void))

::hxDaedalus::data::ConstraintShape Mesh_obj::insertConstraintShape( Array< Float > coordinates){
	HX_STACK_FRAME("hxDaedalus.data.Mesh","insertConstraintShape",0x830d7cd5,"hxDaedalus.data.Mesh.insertConstraintShape","hxDaedalus/data/Mesh.hx",200,0xb69595e6)
	HX_STACK_THIS(this)
	HX_STACK_ARG(coordinates,"coordinates")
	HX_STACK_LINE(201)
	::hxDaedalus::data::ConstraintShape shape = ::hxDaedalus::data::ConstraintShape_obj::__new();		HX_STACK_VAR(shape,"shape");
	HX_STACK_LINE(202)
	::hxDaedalus::data::ConstraintSegment segment = null();		HX_STACK_VAR(segment,"segment");
	HX_STACK_LINE(204)
	int i = (int)0;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(205)
	while((true)){
		HX_STACK_LINE(205)
		if ((!(((i < coordinates->length))))){
			HX_STACK_LINE(205)
			break;
		}
		HX_STACK_LINE(206)
		::hxDaedalus::data::ConstraintSegment _g = this->insertConstraintSegment(coordinates->__get(i),coordinates->__get((i + (int)1)),coordinates->__get((i + (int)2)),coordinates->__get((i + (int)3)));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(206)
		segment = _g;
		HX_STACK_LINE(207)
		if (((segment != null()))){
			HX_STACK_LINE(209)
			segment->fromShape = shape;
			HX_STACK_LINE(210)
			shape->segments->push(segment);
		}
		HX_STACK_LINE(212)
		hx::AddEq(i,(int)4);
	}
	HX_STACK_LINE(215)
	this->_constraintShapes->push(shape);
	HX_STACK_LINE(217)
	return shape;
}


HX_DEFINE_DYNAMIC_FUNC1(Mesh_obj,insertConstraintShape,return )

Void Mesh_obj::deleteConstraintShape( ::hxDaedalus::data::ConstraintShape shape){
{
		HX_STACK_FRAME("hxDaedalus.data.Mesh","deleteConstraintShape",0x27e46023,"hxDaedalus.data.Mesh.deleteConstraintShape","hxDaedalus/data/Mesh.hx",221,0xb69595e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(shape,"shape")
		HX_STACK_LINE(222)
		{
			HX_STACK_LINE(222)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(222)
			int _g = shape->segments->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(222)
			while((true)){
				HX_STACK_LINE(222)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(222)
					break;
				}
				HX_STACK_LINE(222)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(222)
				this->deleteConstraintSegment(shape->segments->__get(i).StaticCast< ::hxDaedalus::data::ConstraintSegment >());
			}
		}
		HX_STACK_LINE(223)
		shape->dispose();
		HX_STACK_LINE(224)
		int _g = this->_constraintShapes->indexOf(shape,null());		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(224)
		this->_constraintShapes->splice(_g,(int)1);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Mesh_obj,deleteConstraintShape,(void))

::hxDaedalus::data::ConstraintSegment Mesh_obj::insertConstraintSegment( Float x1,Float y1,Float x2,Float y2){
	HX_STACK_FRAME("hxDaedalus.data.Mesh","insertConstraintSegment",0xbe603e67,"hxDaedalus.data.Mesh.insertConstraintSegment","hxDaedalus/data/Mesh.hx",228,0xb69595e6)
	HX_STACK_THIS(this)
	HX_STACK_ARG(x1,"x1")
	HX_STACK_ARG(y1,"y1")
	HX_STACK_ARG(x2,"x2")
	HX_STACK_ARG(y2,"y2")
	HX_STACK_LINE(238)
	int p1pos = this->findPositionFromBounds(x1,y1);		HX_STACK_VAR(p1pos,"p1pos");
	HX_STACK_LINE(239)
	int p2pos = this->findPositionFromBounds(x2,y2);		HX_STACK_VAR(p2pos,"p2pos");
	HX_STACK_LINE(241)
	Float newX1 = x1;		HX_STACK_VAR(newX1,"newX1");
	HX_STACK_LINE(242)
	Float newY1 = y1;		HX_STACK_VAR(newY1,"newY1");
	HX_STACK_LINE(243)
	Float newX2 = x2;		HX_STACK_VAR(newX2,"newX2");
	HX_STACK_LINE(244)
	Float newY2 = y2;		HX_STACK_VAR(newY2,"newY2");
	HX_STACK_LINE(246)
	if (((bool(this->_clipping) && bool(((bool((p1pos != (int)0)) || bool((p2pos != (int)0)))))))){
		HX_STACK_LINE(248)
		::hxDaedalus::data::math::Point2D intersectPoint = ::hxDaedalus::data::math::Point2D_obj::__new(null(),null());		HX_STACK_VAR(intersectPoint,"intersectPoint");
		HX_STACK_LINE(251)
		if (((bool((p1pos != (int)0)) && bool((p2pos != (int)0))))){
			HX_STACK_LINE(254)
			if (((bool((bool((bool((bool((x1 <= (int)0)) && bool((x2 <= (int)0)))) || bool((bool((x1 >= this->_width)) && bool((x2 >= this->_width)))))) || bool((bool((y1 <= (int)0)) && bool((y2 <= (int)0)))))) || bool((bool((y1 >= this->_height)) && bool((y2 >= this->_height))))))){
				HX_STACK_LINE(255)
				return null();
			}
			HX_STACK_LINE(259)
			if (((bool((bool((p1pos == (int)8)) && bool((p2pos == (int)4)))) || bool((bool((p1pos == (int)4)) && bool((p2pos == (int)8))))))){
				HX_STACK_LINE(262)
				::hxDaedalus::data::math::Geom2D_obj::intersections2segments(x1,y1,x2,y2,(int)0,(int)0,(int)0,this->_height,intersectPoint,null(),null());
				HX_STACK_LINE(263)
				newX1 = intersectPoint->x;
				HX_STACK_LINE(264)
				newY1 = intersectPoint->y;
				HX_STACK_LINE(266)
				::hxDaedalus::data::math::Geom2D_obj::intersections2segments(x1,y1,x2,y2,this->_width,(int)0,this->_width,this->_height,intersectPoint,null(),null());
				HX_STACK_LINE(267)
				newX2 = intersectPoint->x;
				HX_STACK_LINE(268)
				newY2 = intersectPoint->y;
			}
			else{
				HX_STACK_LINE(271)
				if (((bool((bool((p1pos == (int)2)) && bool((p2pos == (int)6)))) || bool((bool((p1pos == (int)6)) && bool((p2pos == (int)2))))))){
					HX_STACK_LINE(274)
					::hxDaedalus::data::math::Geom2D_obj::intersections2segments(x1,y1,x2,y2,(int)0,(int)0,this->_width,(int)0,intersectPoint,null(),null());
					HX_STACK_LINE(275)
					newX1 = intersectPoint->x;
					HX_STACK_LINE(276)
					newY1 = intersectPoint->y;
					HX_STACK_LINE(278)
					::hxDaedalus::data::math::Geom2D_obj::intersections2segments(x1,y1,x2,y2,(int)0,this->_height,this->_width,this->_height,intersectPoint,null(),null());
					HX_STACK_LINE(279)
					newX2 = intersectPoint->x;
					HX_STACK_LINE(280)
					newY2 = intersectPoint->y;
				}
				else{
					HX_STACK_LINE(283)
					if (((bool((bool((p1pos == (int)2)) && bool((p2pos == (int)8)))) || bool((bool((p1pos == (int)8)) && bool((p2pos == (int)2))))))){
						HX_STACK_LINE(286)
						if ((::hxDaedalus::data::math::Geom2D_obj::intersections2segments(x1,y1,x2,y2,(int)0,(int)0,this->_width,(int)0,intersectPoint,null(),null()))){
							HX_STACK_LINE(288)
							newX1 = intersectPoint->x;
							HX_STACK_LINE(289)
							newY1 = intersectPoint->y;
							HX_STACK_LINE(292)
							::hxDaedalus::data::math::Geom2D_obj::intersections2segments(x1,y1,x2,y2,(int)0,(int)0,(int)0,this->_height,intersectPoint,null(),null());
							HX_STACK_LINE(293)
							newX2 = intersectPoint->x;
							HX_STACK_LINE(294)
							newY2 = intersectPoint->y;
						}
						else{
							HX_STACK_LINE(296)
							return null();
						}
					}
					else{
						HX_STACK_LINE(299)
						if (((bool((bool((p1pos == (int)2)) && bool((p2pos == (int)4)))) || bool((bool((p1pos == (int)4)) && bool((p2pos == (int)2))))))){
							HX_STACK_LINE(302)
							if ((::hxDaedalus::data::math::Geom2D_obj::intersections2segments(x1,y1,x2,y2,(int)0,(int)0,this->_width,(int)0,intersectPoint,null(),null()))){
								HX_STACK_LINE(304)
								newX1 = intersectPoint->x;
								HX_STACK_LINE(305)
								newY1 = intersectPoint->y;
								HX_STACK_LINE(308)
								::hxDaedalus::data::math::Geom2D_obj::intersections2segments(x1,y1,x2,y2,this->_width,(int)0,this->_width,this->_height,intersectPoint,null(),null());
								HX_STACK_LINE(309)
								newX2 = intersectPoint->x;
								HX_STACK_LINE(310)
								newY2 = intersectPoint->y;
							}
							else{
								HX_STACK_LINE(312)
								return null();
							}
						}
						else{
							HX_STACK_LINE(315)
							if (((bool((bool((p1pos == (int)6)) && bool((p2pos == (int)4)))) || bool((bool((p1pos == (int)4)) && bool((p2pos == (int)6))))))){
								HX_STACK_LINE(318)
								if ((::hxDaedalus::data::math::Geom2D_obj::intersections2segments(x1,y1,x2,y2,(int)0,this->_height,this->_width,this->_height,intersectPoint,null(),null()))){
									HX_STACK_LINE(320)
									newX1 = intersectPoint->x;
									HX_STACK_LINE(321)
									newY1 = intersectPoint->y;
									HX_STACK_LINE(324)
									::hxDaedalus::data::math::Geom2D_obj::intersections2segments(x1,y1,x2,y2,this->_width,(int)0,this->_width,this->_height,intersectPoint,null(),null());
									HX_STACK_LINE(325)
									newX2 = intersectPoint->x;
									HX_STACK_LINE(326)
									newY2 = intersectPoint->y;
								}
								else{
									HX_STACK_LINE(328)
									return null();
								}
							}
							else{
								HX_STACK_LINE(331)
								if (((bool((bool((p1pos == (int)8)) && bool((p2pos == (int)6)))) || bool((bool((p1pos == (int)6)) && bool((p2pos == (int)8))))))){
									HX_STACK_LINE(334)
									if ((::hxDaedalus::data::math::Geom2D_obj::intersections2segments(x1,y1,x2,y2,(int)0,this->_height,this->_width,this->_height,intersectPoint,null(),null()))){
										HX_STACK_LINE(336)
										newX1 = intersectPoint->x;
										HX_STACK_LINE(337)
										newY1 = intersectPoint->y;
										HX_STACK_LINE(340)
										::hxDaedalus::data::math::Geom2D_obj::intersections2segments(x1,y1,x2,y2,(int)0,(int)0,(int)0,this->_height,intersectPoint,null(),null());
										HX_STACK_LINE(341)
										newX2 = intersectPoint->x;
										HX_STACK_LINE(342)
										newY2 = intersectPoint->y;
									}
									else{
										HX_STACK_LINE(344)
										return null();
									}
								}
								else{
									HX_STACK_LINE(349)
									bool firstDone = false;		HX_STACK_VAR(firstDone,"firstDone");
									HX_STACK_LINE(350)
									bool secondDone = false;		HX_STACK_VAR(secondDone,"secondDone");
									HX_STACK_LINE(352)
									if ((::hxDaedalus::data::math::Geom2D_obj::intersections2segments(x1,y1,x2,y2,(int)0,(int)0,this->_width,(int)0,intersectPoint,null(),null()))){
										HX_STACK_LINE(354)
										newX1 = intersectPoint->x;
										HX_STACK_LINE(355)
										newY1 = intersectPoint->y;
										HX_STACK_LINE(356)
										firstDone = true;
									}
									HX_STACK_LINE(359)
									if ((::hxDaedalus::data::math::Geom2D_obj::intersections2segments(x1,y1,x2,y2,this->_width,(int)0,this->_width,this->_height,intersectPoint,null(),null()))){
										HX_STACK_LINE(361)
										if ((!(firstDone))){
											HX_STACK_LINE(363)
											newX1 = intersectPoint->x;
											HX_STACK_LINE(364)
											newY1 = intersectPoint->y;
											HX_STACK_LINE(365)
											firstDone = true;
										}
										else{
											HX_STACK_LINE(369)
											newX2 = intersectPoint->x;
											HX_STACK_LINE(370)
											newY2 = intersectPoint->y;
											HX_STACK_LINE(371)
											secondDone = true;
										}
									}
									HX_STACK_LINE(375)
									if (((  ((!(secondDone))) ? bool(::hxDaedalus::data::math::Geom2D_obj::intersections2segments(x1,y1,x2,y2,(int)0,this->_height,this->_width,this->_height,intersectPoint,null(),null())) : bool(false) ))){
										HX_STACK_LINE(377)
										if ((!(firstDone))){
											HX_STACK_LINE(379)
											newX1 = intersectPoint->x;
											HX_STACK_LINE(380)
											newY1 = intersectPoint->y;
											HX_STACK_LINE(381)
											firstDone = true;
										}
										else{
											HX_STACK_LINE(385)
											newX2 = intersectPoint->x;
											HX_STACK_LINE(386)
											newY2 = intersectPoint->y;
											HX_STACK_LINE(387)
											secondDone = true;
										}
									}
									HX_STACK_LINE(391)
									if (((  ((!(secondDone))) ? bool(::hxDaedalus::data::math::Geom2D_obj::intersections2segments(x1,y1,x2,y2,(int)0,(int)0,(int)0,this->_height,intersectPoint,null(),null())) : bool(false) ))){
										HX_STACK_LINE(392)
										newX2 = intersectPoint->x;
										HX_STACK_LINE(393)
										newY2 = intersectPoint->y;
									}
									HX_STACK_LINE(396)
									if ((!(firstDone))){
										HX_STACK_LINE(396)
										return null();
									}
								}
							}
						}
					}
				}
			}
		}
		else{
			HX_STACK_LINE(403)
			if (((bool((p1pos == (int)2)) || bool((p2pos == (int)2))))){
				HX_STACK_LINE(405)
				::hxDaedalus::data::math::Geom2D_obj::intersections2segments(x1,y1,x2,y2,(int)0,(int)0,this->_width,(int)0,intersectPoint,null(),null());
			}
			else{
				HX_STACK_LINE(408)
				if (((bool((p1pos == (int)4)) || bool((p2pos == (int)4))))){
					HX_STACK_LINE(410)
					::hxDaedalus::data::math::Geom2D_obj::intersections2segments(x1,y1,x2,y2,this->_width,(int)0,this->_width,this->_height,intersectPoint,null(),null());
				}
				else{
					HX_STACK_LINE(413)
					if (((bool((p1pos == (int)6)) || bool((p2pos == (int)6))))){
						HX_STACK_LINE(415)
						::hxDaedalus::data::math::Geom2D_obj::intersections2segments(x1,y1,x2,y2,(int)0,this->_height,this->_width,this->_height,intersectPoint,null(),null());
					}
					else{
						HX_STACK_LINE(418)
						if (((bool((p1pos == (int)8)) || bool((p2pos == (int)8))))){
							HX_STACK_LINE(420)
							::hxDaedalus::data::math::Geom2D_obj::intersections2segments(x1,y1,x2,y2,(int)0,(int)0,(int)0,this->_height,intersectPoint,null(),null());
						}
						else{
							HX_STACK_LINE(426)
							if ((!(::hxDaedalus::data::math::Geom2D_obj::intersections2segments(x1,y1,x2,y2,(int)0,(int)0,this->_width,(int)0,intersectPoint,null(),null())))){
								HX_STACK_LINE(429)
								if ((!(::hxDaedalus::data::math::Geom2D_obj::intersections2segments(x1,y1,x2,y2,this->_width,(int)0,this->_width,this->_height,intersectPoint,null(),null())))){
									HX_STACK_LINE(432)
									if ((!(::hxDaedalus::data::math::Geom2D_obj::intersections2segments(x1,y1,x2,y2,(int)0,this->_height,this->_width,this->_height,intersectPoint,null(),null())))){
										HX_STACK_LINE(435)
										::hxDaedalus::data::math::Geom2D_obj::intersections2segments(x1,y1,x2,y2,(int)0,(int)0,(int)0,this->_height,intersectPoint,null(),null());
									}
								}
							}
						}
					}
				}
			}
			HX_STACK_LINE(441)
			if (((p1pos == (int)0))){
				HX_STACK_LINE(442)
				newX1 = x1;
				HX_STACK_LINE(443)
				newY1 = y1;
			}
			else{
				HX_STACK_LINE(445)
				newX1 = x2;
				HX_STACK_LINE(446)
				newY1 = y2;
			}
			HX_STACK_LINE(448)
			newX2 = intersectPoint->x;
			HX_STACK_LINE(449)
			newY2 = intersectPoint->y;
		}
	}
	HX_STACK_LINE(455)
	::hxDaedalus::data::Vertex vertexDown = this->insertVertex(newX1,newY1);		HX_STACK_VAR(vertexDown,"vertexDown");
	HX_STACK_LINE(456)
	if (((vertexDown == null()))){
		HX_STACK_LINE(456)
		return null();
	}
	HX_STACK_LINE(457)
	::hxDaedalus::data::Vertex vertexUp = this->insertVertex(newX2,newY2);		HX_STACK_VAR(vertexUp,"vertexUp");
	HX_STACK_LINE(458)
	if (((vertexUp == null()))){
		HX_STACK_LINE(458)
		return null();
	}
	HX_STACK_LINE(459)
	if (((vertexDown == vertexUp))){
		HX_STACK_LINE(459)
		return null();
	}
	HX_STACK_LINE(461)
	::hxDaedalus::iterators::FromVertexToOutgoingEdges iterVertexToOutEdges = ::hxDaedalus::iterators::FromVertexToOutgoingEdges_obj::__new();		HX_STACK_VAR(iterVertexToOutEdges,"iterVertexToOutEdges");
	HX_STACK_LINE(462)
	::hxDaedalus::data::Vertex currVertex;		HX_STACK_VAR(currVertex,"currVertex");
	HX_STACK_LINE(463)
	::hxDaedalus::data::Edge currEdge;		HX_STACK_VAR(currEdge,"currEdge");
	HX_STACK_LINE(464)
	int i;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(467)
	::hxDaedalus::data::ConstraintSegment segment = ::hxDaedalus::data::ConstraintSegment_obj::__new();		HX_STACK_VAR(segment,"segment");
	HX_STACK_LINE(469)
	::hxDaedalus::data::Edge tempEdgeDownUp = ::hxDaedalus::data::Edge_obj::__new();		HX_STACK_VAR(tempEdgeDownUp,"tempEdgeDownUp");
	HX_STACK_LINE(470)
	::hxDaedalus::data::Edge tempSdgeUpDown = ::hxDaedalus::data::Edge_obj::__new();		HX_STACK_VAR(tempSdgeUpDown,"tempSdgeUpDown");
	HX_STACK_LINE(471)
	tempEdgeDownUp->setDatas(vertexDown,tempSdgeUpDown,null(),null(),true,true);
	HX_STACK_LINE(472)
	tempSdgeUpDown->setDatas(vertexUp,tempEdgeDownUp,null(),null(),true,true);
	HX_STACK_LINE(474)
	Array< ::Dynamic > intersectedEdges = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(intersectedEdges,"intersectedEdges");
	HX_STACK_LINE(475)
	Array< ::Dynamic > leftBoundingEdges = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(leftBoundingEdges,"leftBoundingEdges");
	HX_STACK_LINE(476)
	Array< ::Dynamic > rightBoundingEdges = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(rightBoundingEdges,"rightBoundingEdges");
	HX_STACK_LINE(478)
	::hxDaedalus::data::math::Intersection currObjet;		HX_STACK_VAR(currObjet,"currObjet");
	HX_STACK_LINE(479)
	::hxDaedalus::data::math::Point2D pIntersect = ::hxDaedalus::data::math::Point2D_obj::__new(null(),null());		HX_STACK_VAR(pIntersect,"pIntersect");
	HX_STACK_LINE(480)
	::hxDaedalus::data::Edge edgeLeft;		HX_STACK_VAR(edgeLeft,"edgeLeft");
	HX_STACK_LINE(481)
	::hxDaedalus::data::Edge newEdgeDownUp;		HX_STACK_VAR(newEdgeDownUp,"newEdgeDownUp");
	HX_STACK_LINE(482)
	::hxDaedalus::data::Edge newEdgeUpDown;		HX_STACK_VAR(newEdgeUpDown,"newEdgeUpDown");
	HX_STACK_LINE(483)
	bool done;		HX_STACK_VAR(done,"done");
	HX_STACK_LINE(484)
	currVertex = vertexDown;
	HX_STACK_LINE(485)
	::hxDaedalus::data::math::Intersection _g = ::hxDaedalus::data::math::Intersection_obj::EVertex(currVertex);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(485)
	currObjet = _g;
	HX_STACK_LINE(486)
	while((true)){
		HX_STACK_LINE(488)
		done = false;
		HX_STACK_LINE(490)
		switch( (int)(currObjet->__Index())){
			case (int)0: {
				HX_STACK_LINE(490)
				::hxDaedalus::data::Vertex vertex = (::hxDaedalus::data::math::Intersection(currObjet))->__Param(0);		HX_STACK_VAR(vertex,"vertex");
				HX_STACK_LINE(491)
				{
					HX_STACK_LINE(494)
					currVertex = vertex;
					HX_STACK_LINE(495)
					iterVertexToOutEdges->set_fromVertex(currVertex);
					HX_STACK_LINE(496)
					while((true)){
						HX_STACK_LINE(496)
						::hxDaedalus::data::Edge _g1 = iterVertexToOutEdges->next();		HX_STACK_VAR(_g1,"_g1");
						HX_STACK_LINE(496)
						::hxDaedalus::data::Edge _g2 = currEdge = _g1;		HX_STACK_VAR(_g2,"_g2");
						HX_STACK_LINE(496)
						if ((!(((_g2 != null()))))){
							HX_STACK_LINE(496)
							break;
						}
						HX_STACK_LINE(499)
						::hxDaedalus::data::Vertex _g3 = currEdge->get_destinationVertex();		HX_STACK_VAR(_g3,"_g3");
						HX_STACK_LINE(499)
						if (((_g3 == vertexUp))){
							HX_STACK_LINE(502)
							if ((!(currEdge->get_isConstrained()))){
								HX_STACK_LINE(504)
								currEdge->set_isConstrained(true);
								HX_STACK_LINE(505)
								currEdge->get_oppositeEdge()->set_isConstrained(true);
							}
							HX_STACK_LINE(507)
							currEdge->addFromConstraintSegment(segment);
							HX_STACK_LINE(508)
							currEdge->get_oppositeEdge()->fromConstraintSegments = currEdge->fromConstraintSegments;
							HX_STACK_LINE(509)
							vertexDown->addFromConstraintSegment(segment);
							HX_STACK_LINE(510)
							vertexUp->addFromConstraintSegment(segment);
							HX_STACK_LINE(511)
							segment->addEdge(currEdge);
							HX_STACK_LINE(512)
							return segment;
						}
						HX_STACK_LINE(515)
						::hxDaedalus::data::Vertex _g4 = currEdge->get_destinationVertex();		HX_STACK_VAR(_g4,"_g4");
						HX_STACK_LINE(515)
						Float _g5 = ::hxDaedalus::data::math::Geom2D_obj::distanceSquaredVertexToEdge(_g4,tempEdgeDownUp);		HX_STACK_VAR(_g5,"_g5");
						HX_STACK_LINE(515)
						if (((_g5 <= 0.0001))){
							HX_STACK_LINE(518)
							if ((!(currEdge->get_isConstrained()))){
								HX_STACK_LINE(521)
								currEdge->set_isConstrained(true);
								HX_STACK_LINE(522)
								currEdge->get_oppositeEdge()->set_isConstrained(true);
							}
							HX_STACK_LINE(524)
							currEdge->addFromConstraintSegment(segment);
							HX_STACK_LINE(525)
							currEdge->get_oppositeEdge()->fromConstraintSegments = currEdge->fromConstraintSegments;
							HX_STACK_LINE(526)
							vertexDown->addFromConstraintSegment(segment);
							HX_STACK_LINE(527)
							segment->addEdge(currEdge);
							HX_STACK_LINE(528)
							::hxDaedalus::data::Vertex _g6 = currEdge->get_destinationVertex();		HX_STACK_VAR(_g6,"_g6");
							HX_STACK_LINE(528)
							vertexDown = _g6;
							HX_STACK_LINE(529)
							tempEdgeDownUp->set_originVertex(vertexDown);
							HX_STACK_LINE(530)
							::hxDaedalus::data::math::Intersection _g7 = ::hxDaedalus::data::math::Intersection_obj::EVertex(vertexDown);		HX_STACK_VAR(_g7,"_g7");
							HX_STACK_LINE(530)
							currObjet = _g7;
							HX_STACK_LINE(531)
							done = true;
							HX_STACK_LINE(532)
							break;
						}
					}
					HX_STACK_LINE(536)
					if ((done)){
						HX_STACK_LINE(537)
						continue;
					}
					HX_STACK_LINE(539)
					iterVertexToOutEdges->set_fromVertex(currVertex);
					HX_STACK_LINE(540)
					while((true)){
						HX_STACK_LINE(540)
						::hxDaedalus::data::Edge _g8 = iterVertexToOutEdges->next();		HX_STACK_VAR(_g8,"_g8");
						HX_STACK_LINE(540)
						::hxDaedalus::data::Edge _g9 = currEdge = _g8;		HX_STACK_VAR(_g9,"_g9");
						HX_STACK_LINE(540)
						if ((!(((_g9 != null()))))){
							HX_STACK_LINE(540)
							break;
						}
						HX_STACK_LINE(542)
						::hxDaedalus::data::Edge _g10 = currEdge->get_nextLeftEdge();		HX_STACK_VAR(_g10,"_g10");
						HX_STACK_LINE(542)
						currEdge = _g10;
						HX_STACK_LINE(543)
						if ((::hxDaedalus::data::math::Geom2D_obj::intersections2edges(currEdge,tempEdgeDownUp,pIntersect,null(),null()))){
							HX_STACK_LINE(546)
							if ((currEdge->get_isConstrained())){
								HX_STACK_LINE(549)
								::hxDaedalus::data::Vertex _g11 = this->splitEdge(currEdge,pIntersect->x,pIntersect->y);		HX_STACK_VAR(_g11,"_g11");
								HX_STACK_LINE(549)
								vertexDown = _g11;
								HX_STACK_LINE(550)
								iterVertexToOutEdges->set_fromVertex(currVertex);
								HX_STACK_LINE(551)
								while((true)){
									HX_STACK_LINE(551)
									::hxDaedalus::data::Edge _g12 = iterVertexToOutEdges->next();		HX_STACK_VAR(_g12,"_g12");
									HX_STACK_LINE(551)
									::hxDaedalus::data::Edge _g13 = currEdge = _g12;		HX_STACK_VAR(_g13,"_g13");
									HX_STACK_LINE(551)
									if ((!(((_g13 != null()))))){
										HX_STACK_LINE(551)
										break;
									}
									HX_STACK_LINE(553)
									::hxDaedalus::data::Vertex _g14 = currEdge->get_destinationVertex();		HX_STACK_VAR(_g14,"_g14");
									HX_STACK_LINE(553)
									if (((_g14 == vertexDown))){
										HX_STACK_LINE(555)
										currEdge->set_isConstrained(true);
										HX_STACK_LINE(556)
										currEdge->get_oppositeEdge()->set_isConstrained(true);
										HX_STACK_LINE(557)
										currEdge->addFromConstraintSegment(segment);
										HX_STACK_LINE(558)
										currEdge->get_oppositeEdge()->fromConstraintSegments = currEdge->fromConstraintSegments;
										HX_STACK_LINE(559)
										segment->addEdge(currEdge);
										HX_STACK_LINE(560)
										break;
									}
								}
								HX_STACK_LINE(563)
								currVertex->addFromConstraintSegment(segment);
								HX_STACK_LINE(564)
								tempEdgeDownUp->set_originVertex(vertexDown);
								HX_STACK_LINE(565)
								::hxDaedalus::data::math::Intersection _g15 = ::hxDaedalus::data::math::Intersection_obj::EVertex(vertexDown);		HX_STACK_VAR(_g15,"_g15");
								HX_STACK_LINE(565)
								currObjet = _g15;
							}
							else{
								HX_STACK_LINE(570)
								intersectedEdges->push(currEdge);
								HX_STACK_LINE(571)
								::hxDaedalus::data::Edge _g16 = currEdge->get_nextLeftEdge();		HX_STACK_VAR(_g16,"_g16");
								HX_STACK_LINE(571)
								leftBoundingEdges->unshift(_g16);
								HX_STACK_LINE(572)
								::hxDaedalus::data::Edge _g17 = currEdge->get_prevLeftEdge();		HX_STACK_VAR(_g17,"_g17");
								HX_STACK_LINE(572)
								rightBoundingEdges->push(_g17);
								HX_STACK_LINE(573)
								::hxDaedalus::data::Edge _g18 = currEdge->get_oppositeEdge();		HX_STACK_VAR(_g18,"_g18");
								HX_STACK_LINE(573)
								currEdge = _g18;
								HX_STACK_LINE(574)
								::hxDaedalus::data::math::Intersection _g19 = ::hxDaedalus::data::math::Intersection_obj::EEdge(currEdge);		HX_STACK_VAR(_g19,"_g19");
								HX_STACK_LINE(574)
								currObjet = _g19;
							}
							HX_STACK_LINE(576)
							break;
						}
					}
				}
			}
			;break;
			case (int)1: {
				HX_STACK_LINE(490)
				::hxDaedalus::data::Edge edge = (::hxDaedalus::data::math::Intersection(currObjet))->__Param(0);		HX_STACK_VAR(edge,"edge");
				HX_STACK_LINE(581)
				{
					HX_STACK_LINE(582)
					currEdge = edge;
					HX_STACK_LINE(584)
					::hxDaedalus::data::Edge _g20 = currEdge->get_nextLeftEdge();		HX_STACK_VAR(_g20,"_g20");
					HX_STACK_LINE(584)
					edgeLeft = _g20;
					HX_STACK_LINE(585)
					::hxDaedalus::data::Vertex _g21 = edgeLeft->get_destinationVertex();		HX_STACK_VAR(_g21,"_g21");
					HX_STACK_LINE(585)
					if (((_g21 == vertexUp))){
						HX_STACK_LINE(588)
						::hxDaedalus::data::Edge _g22 = edgeLeft->get_nextLeftEdge();		HX_STACK_VAR(_g22,"_g22");
						HX_STACK_LINE(588)
						leftBoundingEdges->unshift(_g22);
						HX_STACK_LINE(589)
						rightBoundingEdges->push(edgeLeft);
						HX_STACK_LINE(591)
						::hxDaedalus::data::Edge _g23 = ::hxDaedalus::data::Edge_obj::__new();		HX_STACK_VAR(_g23,"_g23");
						HX_STACK_LINE(591)
						newEdgeDownUp = _g23;
						HX_STACK_LINE(592)
						::hxDaedalus::data::Edge _g24 = ::hxDaedalus::data::Edge_obj::__new();		HX_STACK_VAR(_g24,"_g24");
						HX_STACK_LINE(592)
						newEdgeUpDown = _g24;
						HX_STACK_LINE(593)
						newEdgeDownUp->setDatas(vertexDown,newEdgeUpDown,null(),null(),true,true);
						HX_STACK_LINE(594)
						newEdgeUpDown->setDatas(vertexUp,newEdgeDownUp,null(),null(),true,true);
						HX_STACK_LINE(595)
						leftBoundingEdges->push(newEdgeDownUp);
						HX_STACK_LINE(596)
						rightBoundingEdges->push(newEdgeUpDown);
						HX_STACK_LINE(597)
						this->insertNewConstrainedEdge(segment,newEdgeDownUp,intersectedEdges,leftBoundingEdges,rightBoundingEdges);
						HX_STACK_LINE(599)
						return segment;
					}
					else{
						HX_STACK_LINE(601)
						::hxDaedalus::data::Vertex _g25 = edgeLeft->get_destinationVertex();		HX_STACK_VAR(_g25,"_g25");
						HX_STACK_LINE(601)
						Float _g26 = ::hxDaedalus::data::math::Geom2D_obj::distanceSquaredVertexToEdge(_g25,tempEdgeDownUp);		HX_STACK_VAR(_g26,"_g26");
						HX_STACK_LINE(601)
						if (((_g26 <= 0.0001))){
							HX_STACK_LINE(604)
							::hxDaedalus::data::Edge _g27 = edgeLeft->get_nextLeftEdge();		HX_STACK_VAR(_g27,"_g27");
							HX_STACK_LINE(604)
							leftBoundingEdges->unshift(_g27);
							HX_STACK_LINE(605)
							rightBoundingEdges->push(edgeLeft);
							HX_STACK_LINE(607)
							::hxDaedalus::data::Edge _g28 = ::hxDaedalus::data::Edge_obj::__new();		HX_STACK_VAR(_g28,"_g28");
							HX_STACK_LINE(607)
							newEdgeDownUp = _g28;
							HX_STACK_LINE(608)
							::hxDaedalus::data::Edge _g29 = ::hxDaedalus::data::Edge_obj::__new();		HX_STACK_VAR(_g29,"_g29");
							HX_STACK_LINE(608)
							newEdgeUpDown = _g29;
							HX_STACK_LINE(609)
							newEdgeDownUp->setDatas(vertexDown,newEdgeUpDown,null(),null(),true,true);
							HX_STACK_LINE(610)
							::hxDaedalus::data::Vertex _g30 = edgeLeft->get_destinationVertex();		HX_STACK_VAR(_g30,"_g30");
							HX_STACK_LINE(610)
							newEdgeUpDown->setDatas(_g30,newEdgeDownUp,null(),null(),true,true);
							HX_STACK_LINE(611)
							leftBoundingEdges->push(newEdgeDownUp);
							HX_STACK_LINE(612)
							rightBoundingEdges->push(newEdgeUpDown);
							HX_STACK_LINE(613)
							this->insertNewConstrainedEdge(segment,newEdgeDownUp,intersectedEdges,leftBoundingEdges,rightBoundingEdges);
							HX_STACK_LINE(615)
							intersectedEdges->splice((int)0,intersectedEdges->length);
							HX_STACK_LINE(616)
							leftBoundingEdges->splice((int)0,leftBoundingEdges->length);
							HX_STACK_LINE(617)
							rightBoundingEdges->splice((int)0,rightBoundingEdges->length);
							HX_STACK_LINE(619)
							::hxDaedalus::data::Vertex _g31 = edgeLeft->get_destinationVertex();		HX_STACK_VAR(_g31,"_g31");
							HX_STACK_LINE(619)
							vertexDown = _g31;
							HX_STACK_LINE(620)
							tempEdgeDownUp->set_originVertex(vertexDown);
							HX_STACK_LINE(621)
							::hxDaedalus::data::math::Intersection _g32 = ::hxDaedalus::data::math::Intersection_obj::EVertex(vertexDown);		HX_STACK_VAR(_g32,"_g32");
							HX_STACK_LINE(621)
							currObjet = _g32;
						}
						else{
							HX_STACK_LINE(625)
							if ((::hxDaedalus::data::math::Geom2D_obj::intersections2edges(edgeLeft,tempEdgeDownUp,pIntersect,null(),null()))){
								HX_STACK_LINE(628)
								if ((edgeLeft->get_isConstrained())){
									HX_STACK_LINE(631)
									::hxDaedalus::data::Vertex _g33 = this->splitEdge(edgeLeft,pIntersect->x,pIntersect->y);		HX_STACK_VAR(_g33,"_g33");
									HX_STACK_LINE(631)
									currVertex = _g33;
									HX_STACK_LINE(633)
									iterVertexToOutEdges->set_fromVertex(currVertex);
									HX_STACK_LINE(634)
									while((true)){
										HX_STACK_LINE(634)
										::hxDaedalus::data::Edge _g34 = iterVertexToOutEdges->next();		HX_STACK_VAR(_g34,"_g34");
										HX_STACK_LINE(634)
										::hxDaedalus::data::Edge _g35 = currEdge = _g34;		HX_STACK_VAR(_g35,"_g35");
										HX_STACK_LINE(634)
										if ((!(((_g35 != null()))))){
											HX_STACK_LINE(634)
											break;
										}
										HX_STACK_LINE(636)
										::hxDaedalus::data::Vertex _g36 = currEdge->get_destinationVertex();		HX_STACK_VAR(_g36,"_g36");
										HX_STACK_LINE(636)
										::hxDaedalus::data::Vertex _g37 = leftBoundingEdges->__get((int)0).StaticCast< ::hxDaedalus::data::Edge >()->get_originVertex();		HX_STACK_VAR(_g37,"_g37");
										HX_STACK_LINE(636)
										if (((_g36 == _g37))){
											HX_STACK_LINE(638)
											leftBoundingEdges->unshift(currEdge);
										}
										HX_STACK_LINE(640)
										::hxDaedalus::data::Vertex _g38 = currEdge->get_destinationVertex();		HX_STACK_VAR(_g38,"_g38");
										HX_STACK_LINE(640)
										::hxDaedalus::data::Vertex _g39 = rightBoundingEdges->__get((rightBoundingEdges->length - (int)1)).StaticCast< ::hxDaedalus::data::Edge >()->get_destinationVertex();		HX_STACK_VAR(_g39,"_g39");
										HX_STACK_LINE(640)
										if (((_g38 == _g39))){
											HX_STACK_LINE(642)
											::hxDaedalus::data::Edge _g40 = currEdge->get_oppositeEdge();		HX_STACK_VAR(_g40,"_g40");
											HX_STACK_LINE(642)
											rightBoundingEdges->push(_g40);
										}
									}
									HX_STACK_LINE(646)
									::hxDaedalus::data::Edge _g41 = ::hxDaedalus::data::Edge_obj::__new();		HX_STACK_VAR(_g41,"_g41");
									HX_STACK_LINE(646)
									newEdgeDownUp = _g41;
									HX_STACK_LINE(647)
									::hxDaedalus::data::Edge _g42 = ::hxDaedalus::data::Edge_obj::__new();		HX_STACK_VAR(_g42,"_g42");
									HX_STACK_LINE(647)
									newEdgeUpDown = _g42;
									HX_STACK_LINE(648)
									newEdgeDownUp->setDatas(vertexDown,newEdgeUpDown,null(),null(),true,true);
									HX_STACK_LINE(649)
									newEdgeUpDown->setDatas(currVertex,newEdgeDownUp,null(),null(),true,true);
									HX_STACK_LINE(650)
									leftBoundingEdges->push(newEdgeDownUp);
									HX_STACK_LINE(651)
									rightBoundingEdges->push(newEdgeUpDown);
									HX_STACK_LINE(652)
									this->insertNewConstrainedEdge(segment,newEdgeDownUp,intersectedEdges,leftBoundingEdges,rightBoundingEdges);
									HX_STACK_LINE(654)
									intersectedEdges->splice((int)0,intersectedEdges->length);
									HX_STACK_LINE(655)
									leftBoundingEdges->splice((int)0,leftBoundingEdges->length);
									HX_STACK_LINE(656)
									rightBoundingEdges->splice((int)0,rightBoundingEdges->length);
									HX_STACK_LINE(657)
									vertexDown = currVertex;
									HX_STACK_LINE(658)
									tempEdgeDownUp->set_originVertex(vertexDown);
									HX_STACK_LINE(659)
									::hxDaedalus::data::math::Intersection _g43 = ::hxDaedalus::data::math::Intersection_obj::EVertex(vertexDown);		HX_STACK_VAR(_g43,"_g43");
									HX_STACK_LINE(659)
									currObjet = _g43;
								}
								else{
									HX_STACK_LINE(664)
									intersectedEdges->push(edgeLeft);
									HX_STACK_LINE(665)
									::hxDaedalus::data::Edge _g44 = edgeLeft->get_nextLeftEdge();		HX_STACK_VAR(_g44,"_g44");
									HX_STACK_LINE(665)
									leftBoundingEdges->unshift(_g44);
									HX_STACK_LINE(666)
									::hxDaedalus::data::Edge _g45 = edgeLeft->get_oppositeEdge();		HX_STACK_VAR(_g45,"_g45");
									HX_STACK_LINE(666)
									currEdge = _g45;
									HX_STACK_LINE(667)
									::hxDaedalus::data::math::Intersection _g46 = ::hxDaedalus::data::math::Intersection_obj::EEdge(currEdge);		HX_STACK_VAR(_g46,"_g46");
									HX_STACK_LINE(667)
									currObjet = _g46;
								}
							}
							else{
								HX_STACK_LINE(673)
								::hxDaedalus::data::Edge _g47 = edgeLeft->get_nextLeftEdge();		HX_STACK_VAR(_g47,"_g47");
								HX_STACK_LINE(673)
								edgeLeft = _g47;
								HX_STACK_LINE(674)
								::hxDaedalus::data::math::Geom2D_obj::intersections2edges(edgeLeft,tempEdgeDownUp,pIntersect,null(),null());
								HX_STACK_LINE(675)
								if ((edgeLeft->get_isConstrained())){
									HX_STACK_LINE(678)
									::hxDaedalus::data::Vertex _g48 = this->splitEdge(edgeLeft,pIntersect->x,pIntersect->y);		HX_STACK_VAR(_g48,"_g48");
									HX_STACK_LINE(678)
									currVertex = _g48;
									HX_STACK_LINE(680)
									iterVertexToOutEdges->set_fromVertex(currVertex);
									HX_STACK_LINE(681)
									while((true)){
										HX_STACK_LINE(681)
										::hxDaedalus::data::Edge _g49 = iterVertexToOutEdges->next();		HX_STACK_VAR(_g49,"_g49");
										HX_STACK_LINE(681)
										::hxDaedalus::data::Edge _g50 = currEdge = _g49;		HX_STACK_VAR(_g50,"_g50");
										HX_STACK_LINE(681)
										if ((!(((_g50 != null()))))){
											HX_STACK_LINE(681)
											break;
										}
										HX_STACK_LINE(683)
										::hxDaedalus::data::Vertex _g51 = currEdge->get_destinationVertex();		HX_STACK_VAR(_g51,"_g51");
										HX_STACK_LINE(683)
										::hxDaedalus::data::Vertex _g52 = leftBoundingEdges->__get((int)0).StaticCast< ::hxDaedalus::data::Edge >()->get_originVertex();		HX_STACK_VAR(_g52,"_g52");
										HX_STACK_LINE(683)
										if (((_g51 == _g52))){
											HX_STACK_LINE(685)
											leftBoundingEdges->unshift(currEdge);
										}
										HX_STACK_LINE(687)
										::hxDaedalus::data::Vertex _g53 = currEdge->get_destinationVertex();		HX_STACK_VAR(_g53,"_g53");
										HX_STACK_LINE(687)
										::hxDaedalus::data::Vertex _g54 = rightBoundingEdges->__get((rightBoundingEdges->length - (int)1)).StaticCast< ::hxDaedalus::data::Edge >()->get_destinationVertex();		HX_STACK_VAR(_g54,"_g54");
										HX_STACK_LINE(687)
										if (((_g53 == _g54))){
											HX_STACK_LINE(689)
											::hxDaedalus::data::Edge _g55 = currEdge->get_oppositeEdge();		HX_STACK_VAR(_g55,"_g55");
											HX_STACK_LINE(689)
											rightBoundingEdges->push(_g55);
										}
									}
									HX_STACK_LINE(693)
									::hxDaedalus::data::Edge _g56 = ::hxDaedalus::data::Edge_obj::__new();		HX_STACK_VAR(_g56,"_g56");
									HX_STACK_LINE(693)
									newEdgeDownUp = _g56;
									HX_STACK_LINE(694)
									::hxDaedalus::data::Edge _g57 = ::hxDaedalus::data::Edge_obj::__new();		HX_STACK_VAR(_g57,"_g57");
									HX_STACK_LINE(694)
									newEdgeUpDown = _g57;
									HX_STACK_LINE(695)
									newEdgeDownUp->setDatas(vertexDown,newEdgeUpDown,null(),null(),true,true);
									HX_STACK_LINE(696)
									newEdgeUpDown->setDatas(currVertex,newEdgeDownUp,null(),null(),true,true);
									HX_STACK_LINE(697)
									leftBoundingEdges->push(newEdgeDownUp);
									HX_STACK_LINE(698)
									rightBoundingEdges->push(newEdgeUpDown);
									HX_STACK_LINE(699)
									this->insertNewConstrainedEdge(segment,newEdgeDownUp,intersectedEdges,leftBoundingEdges,rightBoundingEdges);
									HX_STACK_LINE(701)
									intersectedEdges->splice((int)0,intersectedEdges->length);
									HX_STACK_LINE(702)
									leftBoundingEdges->splice((int)0,leftBoundingEdges->length);
									HX_STACK_LINE(703)
									rightBoundingEdges->splice((int)0,rightBoundingEdges->length);
									HX_STACK_LINE(704)
									vertexDown = currVertex;
									HX_STACK_LINE(705)
									tempEdgeDownUp->set_originVertex(vertexDown);
									HX_STACK_LINE(706)
									::hxDaedalus::data::math::Intersection _g58 = ::hxDaedalus::data::math::Intersection_obj::EVertex(vertexDown);		HX_STACK_VAR(_g58,"_g58");
									HX_STACK_LINE(706)
									currObjet = _g58;
								}
								else{
									HX_STACK_LINE(711)
									intersectedEdges->push(edgeLeft);
									HX_STACK_LINE(712)
									::hxDaedalus::data::Edge _g59 = edgeLeft->get_prevLeftEdge();		HX_STACK_VAR(_g59,"_g59");
									HX_STACK_LINE(712)
									rightBoundingEdges->push(_g59);
									HX_STACK_LINE(713)
									::hxDaedalus::data::Edge _g60 = edgeLeft->get_oppositeEdge();		HX_STACK_VAR(_g60,"_g60");
									HX_STACK_LINE(713)
									currEdge = _g60;
									HX_STACK_LINE(714)
									::hxDaedalus::data::math::Intersection _g61 = ::hxDaedalus::data::math::Intersection_obj::EEdge(currEdge);		HX_STACK_VAR(_g61,"_g61");
									HX_STACK_LINE(714)
									currObjet = _g61;
								}
							}
						}
					}
				}
			}
			;break;
			case (int)2: {
				HX_STACK_LINE(490)
				::hxDaedalus::data::Face face = (::hxDaedalus::data::math::Intersection(currObjet))->__Param(0);		HX_STACK_VAR(face,"face");
				HX_STACK_LINE(719)
				{
				}
			}
			;break;
			case (int)3: {
			}
			;break;
		}
	}
	HX_STACK_LINE(727)
	return segment;
}


HX_DEFINE_DYNAMIC_FUNC4(Mesh_obj,insertConstraintSegment,return )

Void Mesh_obj::insertNewConstrainedEdge( ::hxDaedalus::data::ConstraintSegment fromSegment,::hxDaedalus::data::Edge edgeDownUp,Array< ::Dynamic > intersectedEdges,Array< ::Dynamic > leftBoundingEdges,Array< ::Dynamic > rightBoundingEdges){
{
		HX_STACK_FRAME("hxDaedalus.data.Mesh","insertNewConstrainedEdge",0x82144c82,"hxDaedalus.data.Mesh.insertNewConstrainedEdge","hxDaedalus/data/Mesh.hx",731,0xb69595e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(fromSegment,"fromSegment")
		HX_STACK_ARG(edgeDownUp,"edgeDownUp")
		HX_STACK_ARG(intersectedEdges,"intersectedEdges")
		HX_STACK_ARG(leftBoundingEdges,"leftBoundingEdges")
		HX_STACK_ARG(rightBoundingEdges,"rightBoundingEdges")
		HX_STACK_LINE(733)
		this->_edges->push(edgeDownUp);
		HX_STACK_LINE(734)
		::hxDaedalus::data::Edge _g = edgeDownUp->get_oppositeEdge();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(734)
		this->_edges->push(_g);
		HX_STACK_LINE(736)
		edgeDownUp->addFromConstraintSegment(fromSegment);
		HX_STACK_LINE(737)
		edgeDownUp->get_oppositeEdge()->fromConstraintSegments = edgeDownUp->fromConstraintSegments;
		HX_STACK_LINE(739)
		fromSegment->addEdge(edgeDownUp);
		HX_STACK_LINE(741)
		edgeDownUp->get_originVertex()->addFromConstraintSegment(fromSegment);
		HX_STACK_LINE(742)
		edgeDownUp->get_destinationVertex()->addFromConstraintSegment(fromSegment);
		HX_STACK_LINE(744)
		this->untriangulate(intersectedEdges);
		HX_STACK_LINE(746)
		this->triangulate(leftBoundingEdges,true);
		HX_STACK_LINE(747)
		this->triangulate(rightBoundingEdges,true);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(Mesh_obj,insertNewConstrainedEdge,(void))

Void Mesh_obj::deleteConstraintSegment( ::hxDaedalus::data::ConstraintSegment segment){
{
		HX_STACK_FRAME("hxDaedalus.data.Mesh","deleteConstraintSegment",0x71311135,"hxDaedalus.data.Mesh.deleteConstraintSegment","hxDaedalus/data/Mesh.hx",751,0xb69595e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(segment,"segment")
		HX_STACK_LINE(753)
		int i;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(754)
		Array< ::Dynamic > vertexToDelete = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(vertexToDelete,"vertexToDelete");
		HX_STACK_LINE(755)
		::hxDaedalus::data::Edge edge = null();		HX_STACK_VAR(edge,"edge");
		HX_STACK_LINE(756)
		::hxDaedalus::data::Vertex vertex;		HX_STACK_VAR(vertex,"vertex");
		HX_STACK_LINE(757)
		Array< ::Dynamic > fromConstraintSegment;		HX_STACK_VAR(fromConstraintSegment,"fromConstraintSegment");
		HX_STACK_LINE(758)
		{
			HX_STACK_LINE(758)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(758)
			int _g = segment->get_edges()->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(758)
			while((true)){
				HX_STACK_LINE(758)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(758)
					break;
				}
				HX_STACK_LINE(758)
				int i1 = (_g1)++;		HX_STACK_VAR(i1,"i1");
				HX_STACK_LINE(759)
				Array< ::Dynamic > _g2 = segment->get_edges();		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(759)
				::hxDaedalus::data::Edge _g11 = _g2->__get(i1).StaticCast< ::hxDaedalus::data::Edge >();		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(759)
				edge = _g11;
				HX_STACK_LINE(761)
				edge->removeFromConstraintSegment(segment);
				HX_STACK_LINE(762)
				if (((edge->fromConstraintSegments->length == (int)0))){
					HX_STACK_LINE(764)
					edge->set_isConstrained(false);
					HX_STACK_LINE(765)
					edge->get_oppositeEdge()->set_isConstrained(false);
				}
				HX_STACK_LINE(768)
				::hxDaedalus::data::Vertex _g21 = edge->get_originVertex();		HX_STACK_VAR(_g21,"_g21");
				HX_STACK_LINE(768)
				vertex = _g21;
				HX_STACK_LINE(769)
				vertex->removeFromConstraintSegment(segment);
				HX_STACK_LINE(770)
				vertexToDelete->push(vertex);
			}
		}
		HX_STACK_LINE(774)
		::hxDaedalus::data::Vertex _g3 = edge->get_destinationVertex();		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(774)
		vertex = _g3;
		HX_STACK_LINE(775)
		vertex->removeFromConstraintSegment(segment);
		HX_STACK_LINE(776)
		vertexToDelete->push(vertex);
		HX_STACK_LINE(780)
		{
			HX_STACK_LINE(780)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(780)
			int _g = vertexToDelete->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(780)
			while((true)){
				HX_STACK_LINE(780)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(780)
					break;
				}
				HX_STACK_LINE(780)
				int i1 = (_g1)++;		HX_STACK_VAR(i1,"i1");
				HX_STACK_LINE(781)
				this->deleteVertex(vertexToDelete->__get(i1).StaticCast< ::hxDaedalus::data::Vertex >());
			}
		}
		HX_STACK_LINE(786)
		segment->dispose();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Mesh_obj,deleteConstraintSegment,(void))

Void Mesh_obj::check( ){
{
		HX_STACK_FRAME("hxDaedalus.data.Mesh","check",0xb606b352,"hxDaedalus.data.Mesh.check","hxDaedalus/data/Mesh.hx",790,0xb69595e6)
		HX_STACK_THIS(this)
		HX_STACK_LINE(791)
		{
			HX_STACK_LINE(791)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(791)
			int _g = this->_edges->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(791)
			while((true)){
				HX_STACK_LINE(791)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(791)
					break;
				}
				HX_STACK_LINE(791)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(792)
				::hxDaedalus::data::Edge _g2 = this->_edges->__get(i).StaticCast< ::hxDaedalus::data::Edge >()->get_nextLeftEdge();		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(792)
				if (((_g2 == null()))){
					HX_STACK_LINE(795)
					return null();
				}
			}
		}
		HX_STACK_LINE(798)
		Dynamic();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Mesh_obj,check,(void))

::hxDaedalus::data::Vertex Mesh_obj::insertVertex( Float x,Float y){
	HX_STACK_FRAME("hxDaedalus.data.Mesh","insertVertex",0x464dee33,"hxDaedalus.data.Mesh.insertVertex","hxDaedalus/data/Mesh.hx",802,0xb69595e6)
	HX_STACK_THIS(this)
	HX_STACK_ARG(x,"x")
	HX_STACK_ARG(y,"y")
	HX_STACK_LINE(804)
	if (((bool((bool((bool((x < (int)0)) || bool((y < (int)0)))) || bool((x > this->_width)))) || bool((y > this->_height))))){
		HX_STACK_LINE(804)
		return null();
	}
	HX_STACK_LINE(806)
	this->__edgesToCheck->splice((int)0,this->__edgesToCheck->length);
	HX_STACK_LINE(808)
	::hxDaedalus::data::math::Intersection inObject = ::hxDaedalus::data::math::Geom2D_obj::locatePosition(x,y,hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(inObject,"inObject");
	HX_STACK_LINE(809)
	::hxDaedalus::data::Vertex newVertex = null();		HX_STACK_VAR(newVertex,"newVertex");
	HX_STACK_LINE(811)
	switch( (int)(inObject->__Index())){
		case (int)0: {
			HX_STACK_LINE(811)
			::hxDaedalus::data::Vertex vertex = (::hxDaedalus::data::math::Intersection(inObject))->__Param(0);		HX_STACK_VAR(vertex,"vertex");
			HX_STACK_LINE(814)
			newVertex = vertex;
		}
		;break;
		case (int)1: {
			HX_STACK_LINE(811)
			::hxDaedalus::data::Edge edge = (::hxDaedalus::data::math::Intersection(inObject))->__Param(0);		HX_STACK_VAR(edge,"edge");
			HX_STACK_LINE(815)
			{
				HX_STACK_LINE(817)
				::hxDaedalus::data::Vertex _g = this->splitEdge(edge,x,y);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(817)
				newVertex = _g;
			}
		}
		;break;
		case (int)2: {
			HX_STACK_LINE(811)
			::hxDaedalus::data::Face face = (::hxDaedalus::data::math::Intersection(inObject))->__Param(0);		HX_STACK_VAR(face,"face");
			HX_STACK_LINE(818)
			{
				HX_STACK_LINE(820)
				::hxDaedalus::data::Vertex _g1 = this->splitFace(face,x,y);		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(820)
				newVertex = _g1;
			}
		}
		;break;
		case (int)3: {
		}
		;break;
	}
	HX_STACK_LINE(825)
	this->restoreAsDelaunay();
	HX_STACK_LINE(827)
	return newVertex;
}


HX_DEFINE_DYNAMIC_FUNC2(Mesh_obj,insertVertex,return )

::hxDaedalus::data::Edge Mesh_obj::flipEdge( ::hxDaedalus::data::Edge edge){
	HX_STACK_FRAME("hxDaedalus.data.Mesh","flipEdge",0x27dcf940,"hxDaedalus.data.Mesh.flipEdge","hxDaedalus/data/Mesh.hx",831,0xb69595e6)
	HX_STACK_THIS(this)
	HX_STACK_ARG(edge,"edge")
	HX_STACK_LINE(833)
	::hxDaedalus::data::Edge eBot_Top = edge;		HX_STACK_VAR(eBot_Top,"eBot_Top");
	HX_STACK_LINE(834)
	::hxDaedalus::data::Edge eTop_Bot = edge->get_oppositeEdge();		HX_STACK_VAR(eTop_Bot,"eTop_Bot");
	HX_STACK_LINE(835)
	::hxDaedalus::data::Edge eLeft_Right = ::hxDaedalus::data::Edge_obj::__new();		HX_STACK_VAR(eLeft_Right,"eLeft_Right");
	HX_STACK_LINE(836)
	::hxDaedalus::data::Edge eRight_Left = ::hxDaedalus::data::Edge_obj::__new();		HX_STACK_VAR(eRight_Left,"eRight_Left");
	HX_STACK_LINE(837)
	::hxDaedalus::data::Edge eTop_Left = eBot_Top->get_nextLeftEdge();		HX_STACK_VAR(eTop_Left,"eTop_Left");
	HX_STACK_LINE(838)
	::hxDaedalus::data::Edge eLeft_Bot = eTop_Left->get_nextLeftEdge();		HX_STACK_VAR(eLeft_Bot,"eLeft_Bot");
	HX_STACK_LINE(839)
	::hxDaedalus::data::Edge eBot_Right = eTop_Bot->get_nextLeftEdge();		HX_STACK_VAR(eBot_Right,"eBot_Right");
	HX_STACK_LINE(840)
	::hxDaedalus::data::Edge eRight_Top = eBot_Right->get_nextLeftEdge();		HX_STACK_VAR(eRight_Top,"eRight_Top");
	HX_STACK_LINE(842)
	::hxDaedalus::data::Vertex vBot = eBot_Top->get_originVertex();		HX_STACK_VAR(vBot,"vBot");
	HX_STACK_LINE(843)
	::hxDaedalus::data::Vertex vTop = eTop_Bot->get_originVertex();		HX_STACK_VAR(vTop,"vTop");
	HX_STACK_LINE(844)
	::hxDaedalus::data::Vertex vLeft = eLeft_Bot->get_originVertex();		HX_STACK_VAR(vLeft,"vLeft");
	HX_STACK_LINE(845)
	::hxDaedalus::data::Vertex vRight = eRight_Top->get_originVertex();		HX_STACK_VAR(vRight,"vRight");
	HX_STACK_LINE(847)
	::hxDaedalus::data::Face fLeft = eBot_Top->get_leftFace();		HX_STACK_VAR(fLeft,"fLeft");
	HX_STACK_LINE(848)
	::hxDaedalus::data::Face fRight = eTop_Bot->get_leftFace();		HX_STACK_VAR(fRight,"fRight");
	HX_STACK_LINE(849)
	::hxDaedalus::data::Face fBot = ::hxDaedalus::data::Face_obj::__new();		HX_STACK_VAR(fBot,"fBot");
	HX_STACK_LINE(850)
	::hxDaedalus::data::Face fTop = ::hxDaedalus::data::Face_obj::__new();		HX_STACK_VAR(fTop,"fTop");
	HX_STACK_LINE(853)
	this->_edges->push(eLeft_Right);
	HX_STACK_LINE(854)
	this->_edges->push(eRight_Left);
	HX_STACK_LINE(857)
	this->_faces->push(fTop);
	HX_STACK_LINE(858)
	this->_faces->push(fBot);
	HX_STACK_LINE(861)
	bool _g = edge->get_isReal();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(861)
	bool _g1 = edge->get_isConstrained();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(861)
	eLeft_Right->setDatas(vLeft,eRight_Left,eRight_Top,fTop,_g,_g1);
	HX_STACK_LINE(862)
	bool _g2 = edge->get_isReal();		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(862)
	bool _g3 = edge->get_isConstrained();		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(862)
	eRight_Left->setDatas(vRight,eLeft_Right,eLeft_Bot,fBot,_g2,_g3);
	HX_STACK_LINE(865)
	fTop->setDatas(eLeft_Right,null());
	HX_STACK_LINE(866)
	fBot->setDatas(eRight_Left,null());
	HX_STACK_LINE(869)
	::hxDaedalus::data::Edge _g4 = vTop->get_edge();		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(869)
	if (((_g4 == eTop_Bot))){
		HX_STACK_LINE(870)
		vTop->setDatas(eTop_Left,null());
	}
	HX_STACK_LINE(872)
	::hxDaedalus::data::Edge _g5 = vBot->get_edge();		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(872)
	if (((_g5 == eBot_Top))){
		HX_STACK_LINE(873)
		vBot->setDatas(eBot_Right,null());
	}
	HX_STACK_LINE(877)
	eTop_Left->set_nextLeftEdge(eLeft_Right);
	HX_STACK_LINE(878)
	eTop_Left->set_leftFace(fTop);
	HX_STACK_LINE(879)
	eLeft_Bot->set_nextLeftEdge(eBot_Right);
	HX_STACK_LINE(880)
	eLeft_Bot->set_leftFace(fBot);
	HX_STACK_LINE(881)
	eBot_Right->set_nextLeftEdge(eRight_Left);
	HX_STACK_LINE(882)
	eBot_Right->set_leftFace(fBot);
	HX_STACK_LINE(883)
	eRight_Top->set_nextLeftEdge(eTop_Left);
	HX_STACK_LINE(884)
	eRight_Top->set_leftFace(fTop);
	HX_STACK_LINE(887)
	eBot_Top->dispose();
	HX_STACK_LINE(888)
	eTop_Bot->dispose();
	HX_STACK_LINE(889)
	int _g6 = this->_edges->indexOf(eBot_Top,null());		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(889)
	this->_edges->splice(_g6,(int)1);
	HX_STACK_LINE(890)
	int _g7 = this->_edges->indexOf(eTop_Bot,null());		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(890)
	this->_edges->splice(_g7,(int)1);
	HX_STACK_LINE(893)
	fLeft->dispose();
	HX_STACK_LINE(894)
	fRight->dispose();
	HX_STACK_LINE(895)
	int _g8 = this->_faces->indexOf(fLeft,null());		HX_STACK_VAR(_g8,"_g8");
	HX_STACK_LINE(895)
	this->_faces->splice(_g8,(int)1);
	HX_STACK_LINE(896)
	int _g9 = this->_faces->indexOf(fRight,null());		HX_STACK_VAR(_g9,"_g9");
	HX_STACK_LINE(896)
	this->_faces->splice(_g9,(int)1);
	HX_STACK_LINE(898)
	return eRight_Left;
}


HX_DEFINE_DYNAMIC_FUNC1(Mesh_obj,flipEdge,return )

::hxDaedalus::data::Vertex Mesh_obj::splitEdge( ::hxDaedalus::data::Edge edge,Float x,Float y){
	HX_STACK_FRAME("hxDaedalus.data.Mesh","splitEdge",0x001f7bc1,"hxDaedalus.data.Mesh.splitEdge","hxDaedalus/data/Mesh.hx",902,0xb69595e6)
	HX_STACK_THIS(this)
	HX_STACK_ARG(edge,"edge")
	HX_STACK_ARG(x,"x")
	HX_STACK_ARG(y,"y")
	HX_STACK_LINE(904)
	this->__edgesToCheck->splice((int)0,this->__edgesToCheck->length);
	HX_STACK_LINE(907)
	::hxDaedalus::data::Edge eLeft_Right = edge;		HX_STACK_VAR(eLeft_Right,"eLeft_Right");
	HX_STACK_LINE(908)
	::hxDaedalus::data::Edge eRight_Left = eLeft_Right->get_oppositeEdge();		HX_STACK_VAR(eRight_Left,"eRight_Left");
	HX_STACK_LINE(909)
	::hxDaedalus::data::Edge eRight_Top = eLeft_Right->get_nextLeftEdge();		HX_STACK_VAR(eRight_Top,"eRight_Top");
	HX_STACK_LINE(910)
	::hxDaedalus::data::Edge eTop_Left = eRight_Top->get_nextLeftEdge();		HX_STACK_VAR(eTop_Left,"eTop_Left");
	HX_STACK_LINE(911)
	::hxDaedalus::data::Edge eLeft_Bot = eRight_Left->get_nextLeftEdge();		HX_STACK_VAR(eLeft_Bot,"eLeft_Bot");
	HX_STACK_LINE(912)
	::hxDaedalus::data::Edge eBot_Right = eLeft_Bot->get_nextLeftEdge();		HX_STACK_VAR(eBot_Right,"eBot_Right");
	HX_STACK_LINE(914)
	::hxDaedalus::data::Vertex vTop = eTop_Left->get_originVertex();		HX_STACK_VAR(vTop,"vTop");
	HX_STACK_LINE(915)
	::hxDaedalus::data::Vertex vLeft = eLeft_Right->get_originVertex();		HX_STACK_VAR(vLeft,"vLeft");
	HX_STACK_LINE(916)
	::hxDaedalus::data::Vertex vBot = eBot_Right->get_originVertex();		HX_STACK_VAR(vBot,"vBot");
	HX_STACK_LINE(917)
	::hxDaedalus::data::Vertex vRight = eRight_Left->get_originVertex();		HX_STACK_VAR(vRight,"vRight");
	HX_STACK_LINE(919)
	::hxDaedalus::data::Face fTop = eLeft_Right->get_leftFace();		HX_STACK_VAR(fTop,"fTop");
	HX_STACK_LINE(920)
	::hxDaedalus::data::Face fBot = eRight_Left->get_leftFace();		HX_STACK_VAR(fBot,"fBot");
	HX_STACK_LINE(923)
	if (((((((vLeft->get_pos()->x - x)) * ((vLeft->get_pos()->x - x))) + (((vLeft->get_pos()->y - y)) * ((vLeft->get_pos()->y - y)))) <= 0.0001))){
		HX_STACK_LINE(924)
		return vLeft;
	}
	HX_STACK_LINE(925)
	if (((((((vRight->get_pos()->x - x)) * ((vRight->get_pos()->x - x))) + (((vRight->get_pos()->y - y)) * ((vRight->get_pos()->y - y)))) <= 0.0001))){
		HX_STACK_LINE(926)
		return vRight;
	}
	HX_STACK_LINE(930)
	::hxDaedalus::data::Vertex vCenter = ::hxDaedalus::data::Vertex_obj::__new();		HX_STACK_VAR(vCenter,"vCenter");
	HX_STACK_LINE(932)
	::hxDaedalus::data::Edge eTop_Center = ::hxDaedalus::data::Edge_obj::__new();		HX_STACK_VAR(eTop_Center,"eTop_Center");
	HX_STACK_LINE(933)
	::hxDaedalus::data::Edge eCenter_Top = ::hxDaedalus::data::Edge_obj::__new();		HX_STACK_VAR(eCenter_Top,"eCenter_Top");
	HX_STACK_LINE(934)
	::hxDaedalus::data::Edge eBot_Center = ::hxDaedalus::data::Edge_obj::__new();		HX_STACK_VAR(eBot_Center,"eBot_Center");
	HX_STACK_LINE(935)
	::hxDaedalus::data::Edge eCenter_Bot = ::hxDaedalus::data::Edge_obj::__new();		HX_STACK_VAR(eCenter_Bot,"eCenter_Bot");
	HX_STACK_LINE(937)
	::hxDaedalus::data::Edge eLeft_Center = ::hxDaedalus::data::Edge_obj::__new();		HX_STACK_VAR(eLeft_Center,"eLeft_Center");
	HX_STACK_LINE(938)
	::hxDaedalus::data::Edge eCenter_Left = ::hxDaedalus::data::Edge_obj::__new();		HX_STACK_VAR(eCenter_Left,"eCenter_Left");
	HX_STACK_LINE(939)
	::hxDaedalus::data::Edge eRight_Center = ::hxDaedalus::data::Edge_obj::__new();		HX_STACK_VAR(eRight_Center,"eRight_Center");
	HX_STACK_LINE(940)
	::hxDaedalus::data::Edge eCenter_Right = ::hxDaedalus::data::Edge_obj::__new();		HX_STACK_VAR(eCenter_Right,"eCenter_Right");
	HX_STACK_LINE(942)
	::hxDaedalus::data::Face fTopLeft = ::hxDaedalus::data::Face_obj::__new();		HX_STACK_VAR(fTopLeft,"fTopLeft");
	HX_STACK_LINE(943)
	::hxDaedalus::data::Face fBotLeft = ::hxDaedalus::data::Face_obj::__new();		HX_STACK_VAR(fBotLeft,"fBotLeft");
	HX_STACK_LINE(944)
	::hxDaedalus::data::Face fBotRight = ::hxDaedalus::data::Face_obj::__new();		HX_STACK_VAR(fBotRight,"fBotRight");
	HX_STACK_LINE(945)
	::hxDaedalus::data::Face fTopRight = ::hxDaedalus::data::Face_obj::__new();		HX_STACK_VAR(fTopRight,"fTopRight");
	HX_STACK_LINE(948)
	this->_vertices->push(vCenter);
	HX_STACK_LINE(951)
	this->_edges->push(eCenter_Top);
	HX_STACK_LINE(952)
	this->_edges->push(eTop_Center);
	HX_STACK_LINE(953)
	this->_edges->push(eCenter_Left);
	HX_STACK_LINE(954)
	this->_edges->push(eLeft_Center);
	HX_STACK_LINE(955)
	this->_edges->push(eCenter_Bot);
	HX_STACK_LINE(956)
	this->_edges->push(eBot_Center);
	HX_STACK_LINE(957)
	this->_edges->push(eCenter_Right);
	HX_STACK_LINE(958)
	this->_edges->push(eRight_Center);
	HX_STACK_LINE(961)
	this->_faces->push(fTopRight);
	HX_STACK_LINE(962)
	this->_faces->push(fBotRight);
	HX_STACK_LINE(963)
	this->_faces->push(fBotLeft);
	HX_STACK_LINE(964)
	this->_faces->push(fTopLeft);
	HX_STACK_LINE(967)
	::hxDaedalus::data::Edge _g;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(967)
	if ((fTop->get_isReal())){
		HX_STACK_LINE(967)
		_g = eCenter_Top;
	}
	else{
		HX_STACK_LINE(967)
		_g = eCenter_Bot;
	}
	HX_STACK_LINE(967)
	vCenter->setDatas(_g,null());
	HX_STACK_LINE(968)
	vCenter->get_pos()->x = x;
	HX_STACK_LINE(969)
	vCenter->get_pos()->y = y;
	HX_STACK_LINE(970)
	::hxDaedalus::data::math::Point2D _g1 = vCenter->get_pos();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(970)
	::hxDaedalus::data::math::Geom2D_obj::projectOrthogonaly(_g1,eLeft_Right);
	HX_STACK_LINE(973)
	bool _g2 = fTop->get_isReal();		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(973)
	eCenter_Top->setDatas(vCenter,eTop_Center,eTop_Left,fTopLeft,_g2,null());
	HX_STACK_LINE(974)
	bool _g3 = fTop->get_isReal();		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(974)
	eTop_Center->setDatas(vTop,eCenter_Top,eCenter_Right,fTopRight,_g3,null());
	HX_STACK_LINE(975)
	bool _g4 = edge->get_isReal();		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(975)
	bool _g5 = edge->get_isConstrained();		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(975)
	eCenter_Left->setDatas(vCenter,eLeft_Center,eLeft_Bot,fBotLeft,_g4,_g5);
	HX_STACK_LINE(976)
	bool _g6 = edge->get_isReal();		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(976)
	bool _g7 = edge->get_isConstrained();		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(976)
	eLeft_Center->setDatas(vLeft,eCenter_Left,eCenter_Top,fTopLeft,_g6,_g7);
	HX_STACK_LINE(977)
	bool _g8 = fBot->get_isReal();		HX_STACK_VAR(_g8,"_g8");
	HX_STACK_LINE(977)
	eCenter_Bot->setDatas(vCenter,eBot_Center,eBot_Right,fBotRight,_g8,null());
	HX_STACK_LINE(978)
	bool _g9 = fBot->get_isReal();		HX_STACK_VAR(_g9,"_g9");
	HX_STACK_LINE(978)
	eBot_Center->setDatas(vBot,eCenter_Bot,eCenter_Left,fBotLeft,_g9,null());
	HX_STACK_LINE(979)
	bool _g10 = edge->get_isReal();		HX_STACK_VAR(_g10,"_g10");
	HX_STACK_LINE(979)
	bool _g11 = edge->get_isConstrained();		HX_STACK_VAR(_g11,"_g11");
	HX_STACK_LINE(979)
	eCenter_Right->setDatas(vCenter,eRight_Center,eRight_Top,fTopRight,_g10,_g11);
	HX_STACK_LINE(980)
	bool _g12 = edge->get_isReal();		HX_STACK_VAR(_g12,"_g12");
	HX_STACK_LINE(980)
	bool _g13 = edge->get_isConstrained();		HX_STACK_VAR(_g13,"_g13");
	HX_STACK_LINE(980)
	eRight_Center->setDatas(vRight,eCenter_Right,eCenter_Bot,fBotRight,_g12,_g13);
	HX_STACK_LINE(983)
	bool _g14 = fTop->get_isReal();		HX_STACK_VAR(_g14,"_g14");
	HX_STACK_LINE(983)
	fTopLeft->setDatas(eCenter_Top,_g14);
	HX_STACK_LINE(984)
	bool _g15 = fBot->get_isReal();		HX_STACK_VAR(_g15,"_g15");
	HX_STACK_LINE(984)
	fBotLeft->setDatas(eCenter_Left,_g15);
	HX_STACK_LINE(985)
	bool _g16 = fBot->get_isReal();		HX_STACK_VAR(_g16,"_g16");
	HX_STACK_LINE(985)
	fBotRight->setDatas(eCenter_Bot,_g16);
	HX_STACK_LINE(986)
	bool _g17 = fTop->get_isReal();		HX_STACK_VAR(_g17,"_g17");
	HX_STACK_LINE(986)
	fTopRight->setDatas(eCenter_Right,_g17);
	HX_STACK_LINE(989)
	::hxDaedalus::data::Edge _g18 = vLeft->get_edge();		HX_STACK_VAR(_g18,"_g18");
	HX_STACK_LINE(989)
	if (((_g18 == eLeft_Right))){
		HX_STACK_LINE(989)
		vLeft->setDatas(eLeft_Center,null());
	}
	HX_STACK_LINE(990)
	::hxDaedalus::data::Edge _g19 = vRight->get_edge();		HX_STACK_VAR(_g19,"_g19");
	HX_STACK_LINE(990)
	if (((_g19 == eRight_Left))){
		HX_STACK_LINE(990)
		vRight->setDatas(eRight_Center,null());
	}
	HX_STACK_LINE(994)
	eTop_Left->set_nextLeftEdge(eLeft_Center);
	HX_STACK_LINE(995)
	eTop_Left->set_leftFace(fTopLeft);
	HX_STACK_LINE(996)
	eLeft_Bot->set_nextLeftEdge(eBot_Center);
	HX_STACK_LINE(997)
	eLeft_Bot->set_leftFace(fBotLeft);
	HX_STACK_LINE(998)
	eBot_Right->set_nextLeftEdge(eRight_Center);
	HX_STACK_LINE(999)
	eBot_Right->set_leftFace(fBotRight);
	HX_STACK_LINE(1000)
	eRight_Top->set_nextLeftEdge(eTop_Center);
	HX_STACK_LINE(1001)
	eRight_Top->set_leftFace(fTopRight);
	HX_STACK_LINE(1007)
	if ((eLeft_Right->get_isConstrained())){
		HX_STACK_LINE(1009)
		Array< ::Dynamic > fromSegments = eLeft_Right->fromConstraintSegments;		HX_STACK_VAR(fromSegments,"fromSegments");
		HX_STACK_LINE(1010)
		Array< ::Dynamic > _g20 = fromSegments->slice((int)0,null());		HX_STACK_VAR(_g20,"_g20");
		HX_STACK_LINE(1010)
		eLeft_Center->fromConstraintSegments = _g20;
		HX_STACK_LINE(1011)
		eCenter_Left->fromConstraintSegments = eLeft_Center->fromConstraintSegments;
		HX_STACK_LINE(1012)
		Array< ::Dynamic > _g21 = fromSegments->slice((int)0,null());		HX_STACK_VAR(_g21,"_g21");
		HX_STACK_LINE(1012)
		eCenter_Right->fromConstraintSegments = _g21;
		HX_STACK_LINE(1013)
		eRight_Center->fromConstraintSegments = eCenter_Right->fromConstraintSegments;
		HX_STACK_LINE(1015)
		Array< ::Dynamic > edges;		HX_STACK_VAR(edges,"edges");
		HX_STACK_LINE(1016)
		int index;		HX_STACK_VAR(index,"index");
		HX_STACK_LINE(1017)
		{
			HX_STACK_LINE(1017)
			int _g110 = (int)0;		HX_STACK_VAR(_g110,"_g110");
			HX_STACK_LINE(1017)
			int _g22 = eLeft_Right->fromConstraintSegments->length;		HX_STACK_VAR(_g22,"_g22");
			HX_STACK_LINE(1017)
			while((true)){
				HX_STACK_LINE(1017)
				if ((!(((_g110 < _g22))))){
					HX_STACK_LINE(1017)
					break;
				}
				HX_STACK_LINE(1017)
				int i = (_g110)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(1018)
				Array< ::Dynamic > _g221 = eLeft_Right->fromConstraintSegments->__get(i).StaticCast< ::hxDaedalus::data::ConstraintSegment >()->get_edges();		HX_STACK_VAR(_g221,"_g221");
				HX_STACK_LINE(1018)
				edges = _g221;
				HX_STACK_LINE(1019)
				int _g23 = edges->indexOf(eLeft_Right,null());		HX_STACK_VAR(_g23,"_g23");
				HX_STACK_LINE(1019)
				index = _g23;
				HX_STACK_LINE(1020)
				if (((index != (int)-1))){
					HX_STACK_LINE(1022)
					edges->splice(index,(int)1);
					HX_STACK_LINE(1023)
					edges->insert(index,eLeft_Center);
					HX_STACK_LINE(1024)
					edges->insert((index + (int)1),eCenter_Right);
				}
				else{
					HX_STACK_LINE(1026)
					int index2 = edges->indexOf(eRight_Left,null());		HX_STACK_VAR(index2,"index2");
					HX_STACK_LINE(1028)
					edges->splice(index2,(int)1);
					HX_STACK_LINE(1029)
					edges->insert(index2,eRight_Center);
					HX_STACK_LINE(1030)
					edges->insert(index2,eCenter_Left);
				}
			}
		}
		HX_STACK_LINE(1034)
		Array< ::Dynamic > _g24 = fromSegments->slice((int)0,null());		HX_STACK_VAR(_g24,"_g24");
		HX_STACK_LINE(1034)
		vCenter->set_fromConstraintSegments(_g24);
	}
	HX_STACK_LINE(1039)
	eLeft_Right->dispose();
	HX_STACK_LINE(1040)
	eRight_Left->dispose();
	HX_STACK_LINE(1041)
	int _g25 = this->_edges->indexOf(eLeft_Right,null());		HX_STACK_VAR(_g25,"_g25");
	HX_STACK_LINE(1041)
	this->_edges->splice(_g25,(int)1);
	HX_STACK_LINE(1042)
	int _g26 = this->_edges->indexOf(eRight_Left,null());		HX_STACK_VAR(_g26,"_g26");
	HX_STACK_LINE(1042)
	this->_edges->splice(_g26,(int)1);
	HX_STACK_LINE(1045)
	fTop->dispose();
	HX_STACK_LINE(1046)
	fBot->dispose();
	HX_STACK_LINE(1047)
	int _g27 = this->_faces->indexOf(fTop,null());		HX_STACK_VAR(_g27,"_g27");
	HX_STACK_LINE(1047)
	this->_faces->splice(_g27,(int)1);
	HX_STACK_LINE(1048)
	int _g28 = this->_faces->indexOf(fBot,null());		HX_STACK_VAR(_g28,"_g28");
	HX_STACK_LINE(1048)
	this->_faces->splice(_g28,(int)1);
	HX_STACK_LINE(1051)
	this->__centerVertex = vCenter;
	HX_STACK_LINE(1052)
	this->__edgesToCheck->push(eTop_Left);
	HX_STACK_LINE(1053)
	this->__edgesToCheck->push(eLeft_Bot);
	HX_STACK_LINE(1054)
	this->__edgesToCheck->push(eBot_Right);
	HX_STACK_LINE(1055)
	this->__edgesToCheck->push(eRight_Top);
	HX_STACK_LINE(1057)
	return vCenter;
}


HX_DEFINE_DYNAMIC_FUNC3(Mesh_obj,splitEdge,return )

::hxDaedalus::data::Vertex Mesh_obj::splitFace( ::hxDaedalus::data::Face face,Float x,Float y){
	HX_STACK_FRAME("hxDaedalus.data.Mesh","splitFace",0x00c66821,"hxDaedalus.data.Mesh.splitFace","hxDaedalus/data/Mesh.hx",1061,0xb69595e6)
	HX_STACK_THIS(this)
	HX_STACK_ARG(face,"face")
	HX_STACK_ARG(x,"x")
	HX_STACK_ARG(y,"y")
	HX_STACK_LINE(1063)
	this->__edgesToCheck->splice((int)0,this->__edgesToCheck->length);
	HX_STACK_LINE(1066)
	::hxDaedalus::data::Edge eTop_Left = face->get_edge();		HX_STACK_VAR(eTop_Left,"eTop_Left");
	HX_STACK_LINE(1067)
	::hxDaedalus::data::Edge eLeft_Right = eTop_Left->get_nextLeftEdge();		HX_STACK_VAR(eLeft_Right,"eLeft_Right");
	HX_STACK_LINE(1068)
	::hxDaedalus::data::Edge eRight_Top = eLeft_Right->get_nextLeftEdge();		HX_STACK_VAR(eRight_Top,"eRight_Top");
	HX_STACK_LINE(1070)
	::hxDaedalus::data::Vertex vTop = eTop_Left->get_originVertex();		HX_STACK_VAR(vTop,"vTop");
	HX_STACK_LINE(1071)
	::hxDaedalus::data::Vertex vLeft = eLeft_Right->get_originVertex();		HX_STACK_VAR(vLeft,"vLeft");
	HX_STACK_LINE(1072)
	::hxDaedalus::data::Vertex vRight = eRight_Top->get_originVertex();		HX_STACK_VAR(vRight,"vRight");
	HX_STACK_LINE(1075)
	::hxDaedalus::data::Vertex vCenter = ::hxDaedalus::data::Vertex_obj::__new();		HX_STACK_VAR(vCenter,"vCenter");
	HX_STACK_LINE(1077)
	::hxDaedalus::data::Edge eTop_Center = ::hxDaedalus::data::Edge_obj::__new();		HX_STACK_VAR(eTop_Center,"eTop_Center");
	HX_STACK_LINE(1078)
	::hxDaedalus::data::Edge eCenter_Top = ::hxDaedalus::data::Edge_obj::__new();		HX_STACK_VAR(eCenter_Top,"eCenter_Top");
	HX_STACK_LINE(1079)
	::hxDaedalus::data::Edge eLeft_Center = ::hxDaedalus::data::Edge_obj::__new();		HX_STACK_VAR(eLeft_Center,"eLeft_Center");
	HX_STACK_LINE(1080)
	::hxDaedalus::data::Edge eCenter_Left = ::hxDaedalus::data::Edge_obj::__new();		HX_STACK_VAR(eCenter_Left,"eCenter_Left");
	HX_STACK_LINE(1081)
	::hxDaedalus::data::Edge eRight_Center = ::hxDaedalus::data::Edge_obj::__new();		HX_STACK_VAR(eRight_Center,"eRight_Center");
	HX_STACK_LINE(1082)
	::hxDaedalus::data::Edge eCenter_Right = ::hxDaedalus::data::Edge_obj::__new();		HX_STACK_VAR(eCenter_Right,"eCenter_Right");
	HX_STACK_LINE(1084)
	::hxDaedalus::data::Face fTopLeft = ::hxDaedalus::data::Face_obj::__new();		HX_STACK_VAR(fTopLeft,"fTopLeft");
	HX_STACK_LINE(1085)
	::hxDaedalus::data::Face fBot = ::hxDaedalus::data::Face_obj::__new();		HX_STACK_VAR(fBot,"fBot");
	HX_STACK_LINE(1086)
	::hxDaedalus::data::Face fTopRight = ::hxDaedalus::data::Face_obj::__new();		HX_STACK_VAR(fTopRight,"fTopRight");
	HX_STACK_LINE(1089)
	this->_vertices->push(vCenter);
	HX_STACK_LINE(1092)
	this->_edges->push(eTop_Center);
	HX_STACK_LINE(1093)
	this->_edges->push(eCenter_Top);
	HX_STACK_LINE(1094)
	this->_edges->push(eLeft_Center);
	HX_STACK_LINE(1095)
	this->_edges->push(eCenter_Left);
	HX_STACK_LINE(1096)
	this->_edges->push(eRight_Center);
	HX_STACK_LINE(1097)
	this->_edges->push(eCenter_Right);
	HX_STACK_LINE(1100)
	this->_faces->push(fTopLeft);
	HX_STACK_LINE(1101)
	this->_faces->push(fBot);
	HX_STACK_LINE(1102)
	this->_faces->push(fTopRight);
	HX_STACK_LINE(1105)
	vCenter->setDatas(eCenter_Top,null());
	HX_STACK_LINE(1106)
	vCenter->get_pos()->x = x;
	HX_STACK_LINE(1107)
	vCenter->get_pos()->y = y;
	HX_STACK_LINE(1110)
	eTop_Center->setDatas(vTop,eCenter_Top,eCenter_Right,fTopRight,null(),null());
	HX_STACK_LINE(1111)
	eCenter_Top->setDatas(vCenter,eTop_Center,eTop_Left,fTopLeft,null(),null());
	HX_STACK_LINE(1112)
	eLeft_Center->setDatas(vLeft,eCenter_Left,eCenter_Top,fTopLeft,null(),null());
	HX_STACK_LINE(1113)
	eCenter_Left->setDatas(vCenter,eLeft_Center,eLeft_Right,fBot,null(),null());
	HX_STACK_LINE(1114)
	eRight_Center->setDatas(vRight,eCenter_Right,eCenter_Left,fBot,null(),null());
	HX_STACK_LINE(1115)
	eCenter_Right->setDatas(vCenter,eRight_Center,eRight_Top,fTopRight,null(),null());
	HX_STACK_LINE(1118)
	fTopLeft->setDatas(eCenter_Top,null());
	HX_STACK_LINE(1119)
	fBot->setDatas(eCenter_Left,null());
	HX_STACK_LINE(1120)
	fTopRight->setDatas(eCenter_Right,null());
	HX_STACK_LINE(1123)
	eTop_Left->set_nextLeftEdge(eLeft_Center);
	HX_STACK_LINE(1124)
	eTop_Left->set_leftFace(fTopLeft);
	HX_STACK_LINE(1125)
	eLeft_Right->set_nextLeftEdge(eRight_Center);
	HX_STACK_LINE(1126)
	eLeft_Right->set_leftFace(fBot);
	HX_STACK_LINE(1127)
	eRight_Top->set_nextLeftEdge(eTop_Center);
	HX_STACK_LINE(1128)
	eRight_Top->set_leftFace(fTopRight);
	HX_STACK_LINE(1131)
	face->dispose();
	HX_STACK_LINE(1132)
	int _g = this->_faces->indexOf(face,null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(1132)
	this->_faces->splice(_g,(int)1);
	HX_STACK_LINE(1135)
	this->__centerVertex = vCenter;
	HX_STACK_LINE(1136)
	this->__edgesToCheck->push(eTop_Left);
	HX_STACK_LINE(1137)
	this->__edgesToCheck->push(eLeft_Right);
	HX_STACK_LINE(1138)
	this->__edgesToCheck->push(eRight_Top);
	HX_STACK_LINE(1140)
	return vCenter;
}


HX_DEFINE_DYNAMIC_FUNC3(Mesh_obj,splitFace,return )

Void Mesh_obj::restoreAsDelaunay( ){
{
		HX_STACK_FRAME("hxDaedalus.data.Mesh","restoreAsDelaunay",0xbb3a5c51,"hxDaedalus.data.Mesh.restoreAsDelaunay","hxDaedalus/data/Mesh.hx",1144,0xb69595e6)
		HX_STACK_THIS(this)
		HX_STACK_LINE(1145)
		::hxDaedalus::data::Edge edge;		HX_STACK_VAR(edge,"edge");
		HX_STACK_LINE(1146)
		while((true)){
			HX_STACK_LINE(1146)
			if ((!(((this->__edgesToCheck->length > (int)0))))){
				HX_STACK_LINE(1146)
				break;
			}
			HX_STACK_LINE(1148)
			::hxDaedalus::data::Edge _g = this->__edgesToCheck->shift().StaticCast< ::hxDaedalus::data::Edge >();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(1148)
			edge = _g;
			HX_STACK_LINE(1149)
			if (((  (((  ((edge->get_isReal())) ? bool(!(edge->get_isConstrained())) : bool(false) ))) ? bool(!(::hxDaedalus::data::math::Geom2D_obj::isDelaunay(edge))) : bool(false) ))){
				HX_STACK_LINE(1151)
				::hxDaedalus::data::Vertex _g1 = edge->get_nextLeftEdge()->get_destinationVertex();		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(1151)
				if (((_g1 == this->__centerVertex))){
					HX_STACK_LINE(1153)
					::hxDaedalus::data::Edge _g2 = edge->get_nextRightEdge();		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(1153)
					this->__edgesToCheck->push(_g2);
					HX_STACK_LINE(1154)
					::hxDaedalus::data::Edge _g3 = edge->get_prevRightEdge();		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(1154)
					this->__edgesToCheck->push(_g3);
				}
				else{
					HX_STACK_LINE(1158)
					::hxDaedalus::data::Edge _g4 = edge->get_nextLeftEdge();		HX_STACK_VAR(_g4,"_g4");
					HX_STACK_LINE(1158)
					this->__edgesToCheck->push(_g4);
					HX_STACK_LINE(1159)
					::hxDaedalus::data::Edge _g5 = edge->get_prevLeftEdge();		HX_STACK_VAR(_g5,"_g5");
					HX_STACK_LINE(1159)
					this->__edgesToCheck->push(_g5);
				}
				HX_STACK_LINE(1161)
				this->flipEdge(edge);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Mesh_obj,restoreAsDelaunay,(void))

bool Mesh_obj::deleteVertex( ::hxDaedalus::data::Vertex vertex){
	HX_STACK_FRAME("hxDaedalus.data.Mesh","deleteVertex",0x3658aca5,"hxDaedalus.data.Mesh.deleteVertex","hxDaedalus/data/Mesh.hx",1171,0xb69595e6)
	HX_STACK_THIS(this)
	HX_STACK_ARG(vertex,"vertex")
	HX_STACK_LINE(1173)
	int i;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(1174)
	bool freeOfConstraint;		HX_STACK_VAR(freeOfConstraint,"freeOfConstraint");
	HX_STACK_LINE(1175)
	::hxDaedalus::iterators::FromVertexToOutgoingEdges iterEdges = ::hxDaedalus::iterators::FromVertexToOutgoingEdges_obj::__new();		HX_STACK_VAR(iterEdges,"iterEdges");
	HX_STACK_LINE(1176)
	iterEdges->set_fromVertex(vertex);
	HX_STACK_LINE(1177)
	iterEdges->realEdgesOnly = false;
	HX_STACK_LINE(1178)
	::hxDaedalus::data::Edge edge;		HX_STACK_VAR(edge,"edge");
	HX_STACK_LINE(1179)
	Array< ::Dynamic > outgoingEdges = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(outgoingEdges,"outgoingEdges");
	HX_STACK_LINE(1181)
	freeOfConstraint = (vertex->get_fromConstraintSegments()->length == (int)0);
	HX_STACK_LINE(1185)
	Array< ::Dynamic > bound = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(bound,"bound");
	HX_STACK_LINE(1188)
	bool realA = false;		HX_STACK_VAR(realA,"realA");
	HX_STACK_LINE(1189)
	bool realB = false;		HX_STACK_VAR(realB,"realB");
	HX_STACK_LINE(1190)
	Array< ::Dynamic > boundA = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(boundA,"boundA");
	HX_STACK_LINE(1191)
	Array< ::Dynamic > boundB = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(boundB,"boundB");
	HX_STACK_LINE(1193)
	if ((freeOfConstraint)){
		HX_STACK_LINE(1195)
		while((true)){
			HX_STACK_LINE(1195)
			::hxDaedalus::data::Edge _g = iterEdges->next();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(1195)
			::hxDaedalus::data::Edge _g1 = edge = _g;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(1195)
			if ((!(((_g1 != null()))))){
				HX_STACK_LINE(1195)
				break;
			}
			HX_STACK_LINE(1197)
			outgoingEdges->push(edge);
			HX_STACK_LINE(1198)
			::hxDaedalus::data::Edge _g2 = edge->get_nextLeftEdge();		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(1198)
			bound->push(_g2);
		}
	}
	else{
		HX_STACK_LINE(1204)
		Array< ::Dynamic > edges;		HX_STACK_VAR(edges,"edges");
		HX_STACK_LINE(1205)
		{
			HX_STACK_LINE(1205)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(1205)
			int _g = vertex->get_fromConstraintSegments()->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(1205)
			while((true)){
				HX_STACK_LINE(1205)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(1205)
					break;
				}
				HX_STACK_LINE(1205)
				int i1 = (_g1)++;		HX_STACK_VAR(i1,"i1");
				HX_STACK_LINE(1206)
				Array< ::Dynamic > _g3 = vertex->get_fromConstraintSegments();		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(1206)
				Array< ::Dynamic > _g4 = _g3->__get(i1).StaticCast< ::hxDaedalus::data::ConstraintSegment >()->get_edges();		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(1206)
				edges = _g4;
				HX_STACK_LINE(1207)
				::hxDaedalus::data::Vertex _g5 = edges->__get((int)0).StaticCast< ::hxDaedalus::data::Edge >()->get_originVertex();		HX_STACK_VAR(_g5,"_g5");
				struct _Function_4_1{
					inline static bool Block( Array< ::Dynamic > &edges,::hxDaedalus::data::Vertex &vertex){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","hxDaedalus/data/Mesh.hx",1207,0xb69595e6)
						{
							HX_STACK_LINE(1207)
							::hxDaedalus::data::Vertex _g6 = edges->__get((edges->length - (int)1)).StaticCast< ::hxDaedalus::data::Edge >()->get_destinationVertex();		HX_STACK_VAR(_g6,"_g6");
							HX_STACK_LINE(1207)
							return (_g6 == vertex);
						}
						return null();
					}
				};
				HX_STACK_LINE(1207)
				if (((  ((!(((_g5 == vertex))))) ? bool(_Function_4_1::Block(edges,vertex)) : bool(true) ))){
					HX_STACK_LINE(1210)
					return false;
				}
			}
		}
		HX_STACK_LINE(1216)
		int count = (int)0;		HX_STACK_VAR(count,"count");
		HX_STACK_LINE(1217)
		while((true)){
			HX_STACK_LINE(1217)
			::hxDaedalus::data::Edge _g7 = iterEdges->next();		HX_STACK_VAR(_g7,"_g7");
			HX_STACK_LINE(1217)
			::hxDaedalus::data::Edge _g8 = edge = _g7;		HX_STACK_VAR(_g8,"_g8");
			HX_STACK_LINE(1217)
			if ((!(((_g8 != null()))))){
				HX_STACK_LINE(1217)
				break;
			}
			HX_STACK_LINE(1219)
			outgoingEdges->push(edge);
			HX_STACK_LINE(1221)
			if ((edge->get_isConstrained())){
				HX_STACK_LINE(1223)
				(count)++;
				HX_STACK_LINE(1224)
				if (((count > (int)2))){
					HX_STACK_LINE(1227)
					return false;
				}
			}
		}
		HX_STACK_LINE(1236)
		Array< ::Dynamic > _g9 = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g9,"_g9");
		HX_STACK_LINE(1236)
		boundA = _g9;
		HX_STACK_LINE(1237)
		Array< ::Dynamic > _g10 = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g10,"_g10");
		HX_STACK_LINE(1237)
		boundB = _g10;
		HX_STACK_LINE(1238)
		::hxDaedalus::data::Edge constrainedEdgeA = null();		HX_STACK_VAR(constrainedEdgeA,"constrainedEdgeA");
		HX_STACK_LINE(1239)
		::hxDaedalus::data::Edge constrainedEdgeB = null();		HX_STACK_VAR(constrainedEdgeB,"constrainedEdgeB");
		HX_STACK_LINE(1240)
		::hxDaedalus::data::Edge edgeA = ::hxDaedalus::data::Edge_obj::__new();		HX_STACK_VAR(edgeA,"edgeA");
		HX_STACK_LINE(1241)
		::hxDaedalus::data::Edge edgeB = ::hxDaedalus::data::Edge_obj::__new();		HX_STACK_VAR(edgeB,"edgeB");
		HX_STACK_LINE(1245)
		this->_edges->push(edgeA);
		HX_STACK_LINE(1246)
		this->_edges->push(edgeB);
		HX_STACK_LINE(1247)
		{
			HX_STACK_LINE(1247)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(1247)
			int _g = outgoingEdges->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(1247)
			while((true)){
				HX_STACK_LINE(1247)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(1247)
					break;
				}
				HX_STACK_LINE(1247)
				int i1 = (_g1)++;		HX_STACK_VAR(i1,"i1");
				HX_STACK_LINE(1248)
				edge = outgoingEdges->__get(i1).StaticCast< ::hxDaedalus::data::Edge >();
				HX_STACK_LINE(1249)
				if ((edge->get_isConstrained())){
					HX_STACK_LINE(1251)
					if (((constrainedEdgeA == null()))){
						HX_STACK_LINE(1253)
						::hxDaedalus::data::Vertex _g11 = edge->get_destinationVertex();		HX_STACK_VAR(_g11,"_g11");
						HX_STACK_LINE(1253)
						edgeB->setDatas(_g11,edgeA,null(),null(),true,true);
						HX_STACK_LINE(1254)
						boundA->push(edgeA);
						HX_STACK_LINE(1255)
						::hxDaedalus::data::Edge _g12 = edge->get_nextLeftEdge();		HX_STACK_VAR(_g12,"_g12");
						HX_STACK_LINE(1255)
						boundA->push(_g12);
						HX_STACK_LINE(1256)
						boundB->push(edgeB);
						HX_STACK_LINE(1257)
						constrainedEdgeA = edge;
					}
					else{
						HX_STACK_LINE(1259)
						if (((constrainedEdgeB == null()))){
							HX_STACK_LINE(1261)
							::hxDaedalus::data::Vertex _g13 = edge->get_destinationVertex();		HX_STACK_VAR(_g13,"_g13");
							HX_STACK_LINE(1261)
							edgeA->setDatas(_g13,edgeB,null(),null(),true,true);
							HX_STACK_LINE(1262)
							::hxDaedalus::data::Edge _g14 = edge->get_nextLeftEdge();		HX_STACK_VAR(_g14,"_g14");
							HX_STACK_LINE(1262)
							boundB->push(_g14);
							HX_STACK_LINE(1263)
							constrainedEdgeB = edge;
						}
					}
				}
				else{
					HX_STACK_LINE(1268)
					if (((constrainedEdgeA == null()))){
						HX_STACK_LINE(1269)
						::hxDaedalus::data::Edge _g15 = edge->get_nextLeftEdge();		HX_STACK_VAR(_g15,"_g15");
						HX_STACK_LINE(1269)
						boundB->push(_g15);
					}
					else{
						HX_STACK_LINE(1270)
						if (((constrainedEdgeB == null()))){
							HX_STACK_LINE(1271)
							::hxDaedalus::data::Edge _g16 = edge->get_nextLeftEdge();		HX_STACK_VAR(_g16,"_g16");
							HX_STACK_LINE(1271)
							boundA->push(_g16);
						}
						else{
							HX_STACK_LINE(1273)
							::hxDaedalus::data::Edge _g17 = edge->get_nextLeftEdge();		HX_STACK_VAR(_g17,"_g17");
							HX_STACK_LINE(1273)
							boundB->push(_g17);
						}
					}
				}
			}
		}
		HX_STACK_LINE(1279)
		bool _g18 = constrainedEdgeA->get_leftFace()->get_isReal();		HX_STACK_VAR(_g18,"_g18");
		HX_STACK_LINE(1279)
		realA = _g18;
		HX_STACK_LINE(1280)
		bool _g19 = constrainedEdgeB->get_leftFace()->get_isReal();		HX_STACK_VAR(_g19,"_g19");
		HX_STACK_LINE(1280)
		realB = _g19;
		HX_STACK_LINE(1283)
		Array< ::Dynamic > _g20 = constrainedEdgeA->fromConstraintSegments->slice((int)0,null());		HX_STACK_VAR(_g20,"_g20");
		HX_STACK_LINE(1283)
		edgeA->fromConstraintSegments = _g20;
		HX_STACK_LINE(1284)
		edgeB->fromConstraintSegments = edgeA->fromConstraintSegments;
		HX_STACK_LINE(1285)
		int index;		HX_STACK_VAR(index,"index");
		HX_STACK_LINE(1286)
		{
			HX_STACK_LINE(1286)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(1286)
			int _g = vertex->get_fromConstraintSegments()->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(1286)
			while((true)){
				HX_STACK_LINE(1286)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(1286)
					break;
				}
				HX_STACK_LINE(1286)
				int i1 = (_g1)++;		HX_STACK_VAR(i1,"i1");
				HX_STACK_LINE(1287)
				Array< ::Dynamic > _g21 = vertex->get_fromConstraintSegments();		HX_STACK_VAR(_g21,"_g21");
				HX_STACK_LINE(1287)
				Array< ::Dynamic > _g22 = _g21->__get(i1).StaticCast< ::hxDaedalus::data::ConstraintSegment >()->get_edges();		HX_STACK_VAR(_g22,"_g22");
				HX_STACK_LINE(1287)
				edges = _g22;
				HX_STACK_LINE(1288)
				int _g23 = edges->indexOf(constrainedEdgeA,null());		HX_STACK_VAR(_g23,"_g23");
				HX_STACK_LINE(1288)
				index = _g23;
				HX_STACK_LINE(1289)
				if (((index != (int)-1))){
					HX_STACK_LINE(1291)
					edges->splice((index - (int)1),(int)2);
					HX_STACK_LINE(1293)
					edges->insert((index - (int)1),edgeA);
				}
				else{
					HX_STACK_LINE(1297)
					int _g24 = edges->indexOf(constrainedEdgeB,null());		HX_STACK_VAR(_g24,"_g24");
					HX_STACK_LINE(1297)
					int index2 = (_g24 - (int)1);		HX_STACK_VAR(index2,"index2");
					HX_STACK_LINE(1298)
					edges->splice(index2,(int)2);
					HX_STACK_LINE(1299)
					edges->insert(index2,edgeB);
				}
			}
		}
	}
	HX_STACK_LINE(1306)
	::hxDaedalus::data::Face faceToDelete;		HX_STACK_VAR(faceToDelete,"faceToDelete");
	HX_STACK_LINE(1307)
	{
		HX_STACK_LINE(1307)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(1307)
		int _g = outgoingEdges->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(1307)
		while((true)){
			HX_STACK_LINE(1307)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(1307)
				break;
			}
			HX_STACK_LINE(1307)
			int i1 = (_g1)++;		HX_STACK_VAR(i1,"i1");
			HX_STACK_LINE(1308)
			edge = outgoingEdges->__get(i1).StaticCast< ::hxDaedalus::data::Edge >();
			HX_STACK_LINE(1310)
			::hxDaedalus::data::Face _g25 = edge->get_leftFace();		HX_STACK_VAR(_g25,"_g25");
			HX_STACK_LINE(1310)
			faceToDelete = _g25;
			HX_STACK_LINE(1311)
			int _g26 = this->_faces->indexOf(faceToDelete,null());		HX_STACK_VAR(_g26,"_g26");
			HX_STACK_LINE(1311)
			this->_faces->splice(_g26,(int)1);
			HX_STACK_LINE(1312)
			faceToDelete->dispose();
			HX_STACK_LINE(1314)
			::hxDaedalus::data::Edge _g27 = edge->get_nextLeftEdge();		HX_STACK_VAR(_g27,"_g27");
			HX_STACK_LINE(1314)
			edge->get_destinationVertex()->set_edge(_g27);
			HX_STACK_LINE(1316)
			::hxDaedalus::data::Edge _g28 = edge->get_oppositeEdge();		HX_STACK_VAR(_g28,"_g28");
			HX_STACK_LINE(1316)
			int _g29 = this->_edges->indexOf(_g28,null());		HX_STACK_VAR(_g29,"_g29");
			HX_STACK_LINE(1316)
			this->_edges->splice(_g29,(int)1);
			HX_STACK_LINE(1317)
			edge->get_oppositeEdge()->dispose();
			HX_STACK_LINE(1318)
			int _g30 = this->_edges->indexOf(edge,null());		HX_STACK_VAR(_g30,"_g30");
			HX_STACK_LINE(1318)
			this->_edges->splice(_g30,(int)1);
			HX_STACK_LINE(1319)
			edge->dispose();
		}
	}
	HX_STACK_LINE(1322)
	int _g31 = this->_vertices->indexOf(vertex,null());		HX_STACK_VAR(_g31,"_g31");
	HX_STACK_LINE(1322)
	this->_vertices->splice(_g31,(int)1);
	HX_STACK_LINE(1323)
	vertex->dispose();
	HX_STACK_LINE(1326)
	if ((freeOfConstraint)){
		HX_STACK_LINE(1329)
		this->triangulate(bound,true);
	}
	else{
		HX_STACK_LINE(1334)
		this->triangulate(boundA,realA);
		HX_STACK_LINE(1335)
		this->triangulate(boundB,realB);
	}
	HX_STACK_LINE(1340)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC1(Mesh_obj,deleteVertex,return )

Void Mesh_obj::untriangulate( Array< ::Dynamic > edgesList){
{
		HX_STACK_FRAME("hxDaedalus.data.Mesh","untriangulate",0x85f48ffd,"hxDaedalus.data.Mesh.untriangulate","hxDaedalus/data/Mesh.hx",1350,0xb69595e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(edgesList,"edgesList")
		HX_STACK_LINE(1352)
		int i;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(1353)
		::haxe::ds::ObjectMap verticesCleaned = ::haxe::ds::ObjectMap_obj::__new();		HX_STACK_VAR(verticesCleaned,"verticesCleaned");
		HX_STACK_LINE(1354)
		::hxDaedalus::data::Edge currEdge;		HX_STACK_VAR(currEdge,"currEdge");
		HX_STACK_LINE(1355)
		::hxDaedalus::data::Edge outEdge;		HX_STACK_VAR(outEdge,"outEdge");
		HX_STACK_LINE(1356)
		{
			HX_STACK_LINE(1356)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(1356)
			int _g = edgesList->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(1356)
			while((true)){
				HX_STACK_LINE(1356)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(1356)
					break;
				}
				HX_STACK_LINE(1356)
				int i1 = (_g1)++;		HX_STACK_VAR(i1,"i1");
				HX_STACK_LINE(1357)
				currEdge = edgesList->__get(i1).StaticCast< ::hxDaedalus::data::Edge >();
				HX_STACK_LINE(1359)
				Dynamic _g2;		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(1359)
				{
					HX_STACK_LINE(1359)
					::hxDaedalus::data::Vertex key = currEdge->get_originVertex();		HX_STACK_VAR(key,"key");
					HX_STACK_LINE(1359)
					_g2 = verticesCleaned->get(key);
				}
				HX_STACK_LINE(1359)
				if (((_g2 == null()))){
					HX_STACK_LINE(1361)
					::hxDaedalus::data::Edge _g11 = currEdge->get_prevLeftEdge()->get_oppositeEdge();		HX_STACK_VAR(_g11,"_g11");
					HX_STACK_LINE(1361)
					currEdge->get_originVertex()->set_edge(_g11);
					HX_STACK_LINE(1362)
					{
						HX_STACK_LINE(1362)
						::hxDaedalus::data::Vertex k = currEdge->get_originVertex();		HX_STACK_VAR(k,"k");
						HX_STACK_LINE(1362)
						verticesCleaned->set(k,true);
						HX_STACK_LINE(1362)
						true;
					}
				}
				HX_STACK_LINE(1364)
				Dynamic _g21;		HX_STACK_VAR(_g21,"_g21");
				HX_STACK_LINE(1364)
				{
					HX_STACK_LINE(1364)
					::hxDaedalus::data::Vertex key = currEdge->get_destinationVertex();		HX_STACK_VAR(key,"key");
					HX_STACK_LINE(1364)
					_g21 = verticesCleaned->get(key);
				}
				HX_STACK_LINE(1364)
				if (((_g21 == null()))){
					HX_STACK_LINE(1366)
					::hxDaedalus::data::Edge _g3 = currEdge->get_nextLeftEdge();		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(1366)
					currEdge->get_destinationVertex()->set_edge(_g3);
					HX_STACK_LINE(1367)
					{
						HX_STACK_LINE(1367)
						::hxDaedalus::data::Vertex k = currEdge->get_destinationVertex();		HX_STACK_VAR(k,"k");
						HX_STACK_LINE(1367)
						verticesCleaned->set(k,true);
						HX_STACK_LINE(1367)
						true;
					}
				}
				HX_STACK_LINE(1370)
				::hxDaedalus::data::Face _g4 = currEdge->get_leftFace();		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(1370)
				int _g5 = this->_faces->indexOf(_g4,null());		HX_STACK_VAR(_g5,"_g5");
				HX_STACK_LINE(1370)
				this->_faces->splice(_g5,(int)1);
				HX_STACK_LINE(1371)
				currEdge->get_leftFace()->dispose();
				HX_STACK_LINE(1372)
				if (((i1 == (edgesList->length - (int)1)))){
					HX_STACK_LINE(1374)
					::hxDaedalus::data::Face _g6 = currEdge->get_rightFace();		HX_STACK_VAR(_g6,"_g6");
					HX_STACK_LINE(1374)
					int _g7 = this->_faces->indexOf(_g6,null());		HX_STACK_VAR(_g7,"_g7");
					HX_STACK_LINE(1374)
					this->_faces->splice(_g7,(int)1);
					HX_STACK_LINE(1375)
					currEdge->get_rightFace()->dispose();
				}
			}
		}
		HX_STACK_LINE(1381)
		{
			HX_STACK_LINE(1381)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(1381)
			int _g = edgesList->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(1381)
			while((true)){
				HX_STACK_LINE(1381)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(1381)
					break;
				}
				HX_STACK_LINE(1381)
				int i1 = (_g1)++;		HX_STACK_VAR(i1,"i1");
				HX_STACK_LINE(1382)
				currEdge = edgesList->__get(i1).StaticCast< ::hxDaedalus::data::Edge >();
				HX_STACK_LINE(1383)
				::hxDaedalus::data::Edge _g8 = currEdge->get_oppositeEdge();		HX_STACK_VAR(_g8,"_g8");
				HX_STACK_LINE(1383)
				int _g9 = this->_edges->indexOf(_g8,null());		HX_STACK_VAR(_g9,"_g9");
				HX_STACK_LINE(1383)
				this->_edges->splice(_g9,(int)1);
				HX_STACK_LINE(1384)
				int _g10 = this->_edges->indexOf(currEdge,null());		HX_STACK_VAR(_g10,"_g10");
				HX_STACK_LINE(1384)
				this->_edges->splice(_g10,(int)1);
				HX_STACK_LINE(1385)
				currEdge->get_oppositeEdge()->dispose();
				HX_STACK_LINE(1386)
				currEdge->dispose();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Mesh_obj,untriangulate,(void))

Void Mesh_obj::triangulate( Array< ::Dynamic > bound,bool isReal){
{
		HX_STACK_FRAME("hxDaedalus.data.Mesh","triangulate",0x0e8f0336,"hxDaedalus.data.Mesh.triangulate","hxDaedalus/data/Mesh.hx",1394,0xb69595e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(bound,"bound")
		HX_STACK_ARG(isReal,"isReal")
		HX_STACK_LINE(1394)
		if (((bound->length < (int)2))){
			HX_STACK_LINE(1397)
			return null();
		}
		else{
			HX_STACK_LINE(1400)
			if (((bound->length == (int)2))){
				HX_STACK_LINE(1404)
				{
					HX_STACK_LINE(1404)
					int _g = bound->__get((int)0).StaticCast< ::hxDaedalus::data::Edge >()->get_originVertex()->get_id();		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(1404)
					::String _g1 = (HX_CSTRING("  - edge0: ") + _g);		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(1404)
					::String _g2 = (_g1 + HX_CSTRING(" -> "));		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(1404)
					int _g3 = bound->__get((int)0).StaticCast< ::hxDaedalus::data::Edge >()->get_destinationVertex()->get_id();		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(1404)
					Dynamic value = (_g2 + _g3);		HX_STACK_VAR(value,"value");
					HX_STACK_LINE(1404)
					Dynamic();
				}
				HX_STACK_LINE(1405)
				{
					HX_STACK_LINE(1405)
					int _g4 = bound->__get((int)1).StaticCast< ::hxDaedalus::data::Edge >()->get_originVertex()->get_id();		HX_STACK_VAR(_g4,"_g4");
					HX_STACK_LINE(1405)
					::String _g5 = (HX_CSTRING("  - edge1: ") + _g4);		HX_STACK_VAR(_g5,"_g5");
					HX_STACK_LINE(1405)
					::String _g6 = (_g5 + HX_CSTRING(" -> "));		HX_STACK_VAR(_g6,"_g6");
					HX_STACK_LINE(1405)
					int _g7 = bound->__get((int)1).StaticCast< ::hxDaedalus::data::Edge >()->get_destinationVertex()->get_id();		HX_STACK_VAR(_g7,"_g7");
					HX_STACK_LINE(1405)
					Dynamic value = (_g6 + _g7);		HX_STACK_VAR(value,"value");
					HX_STACK_LINE(1405)
					Dynamic();
				}
				HX_STACK_LINE(1406)
				return null();
			}
			else{
				HX_STACK_LINE(1409)
				if (((bound->length == (int)3))){
					HX_STACK_LINE(1415)
					::hxDaedalus::data::Face f = ::hxDaedalus::data::Face_obj::__new();		HX_STACK_VAR(f,"f");
					HX_STACK_LINE(1416)
					f->setDatas(bound->__get((int)0).StaticCast< ::hxDaedalus::data::Edge >(),isReal);
					HX_STACK_LINE(1417)
					this->_faces->push(f);
					HX_STACK_LINE(1418)
					bound->__get((int)0).StaticCast< ::hxDaedalus::data::Edge >()->set_leftFace(f);
					HX_STACK_LINE(1419)
					bound->__get((int)1).StaticCast< ::hxDaedalus::data::Edge >()->set_leftFace(f);
					HX_STACK_LINE(1420)
					bound->__get((int)2).StaticCast< ::hxDaedalus::data::Edge >()->set_leftFace(f);
					HX_STACK_LINE(1421)
					bound->__get((int)0).StaticCast< ::hxDaedalus::data::Edge >()->set_nextLeftEdge(bound->__get((int)1).StaticCast< ::hxDaedalus::data::Edge >());
					HX_STACK_LINE(1422)
					bound->__get((int)1).StaticCast< ::hxDaedalus::data::Edge >()->set_nextLeftEdge(bound->__get((int)2).StaticCast< ::hxDaedalus::data::Edge >());
					HX_STACK_LINE(1423)
					bound->__get((int)2).StaticCast< ::hxDaedalus::data::Edge >()->set_nextLeftEdge(bound->__get((int)0).StaticCast< ::hxDaedalus::data::Edge >());
				}
				else{
					HX_STACK_LINE(1434)
					::hxDaedalus::data::Edge baseEdge = bound->__get((int)0).StaticCast< ::hxDaedalus::data::Edge >();		HX_STACK_VAR(baseEdge,"baseEdge");
					HX_STACK_LINE(1435)
					::hxDaedalus::data::Vertex vertexA = baseEdge->get_originVertex();		HX_STACK_VAR(vertexA,"vertexA");
					HX_STACK_LINE(1436)
					::hxDaedalus::data::Vertex vertexB = baseEdge->get_destinationVertex();		HX_STACK_VAR(vertexB,"vertexB");
					HX_STACK_LINE(1437)
					::hxDaedalus::data::Vertex vertexC;		HX_STACK_VAR(vertexC,"vertexC");
					HX_STACK_LINE(1438)
					::hxDaedalus::data::Vertex vertexCheck;		HX_STACK_VAR(vertexCheck,"vertexCheck");
					HX_STACK_LINE(1439)
					::hxDaedalus::data::math::Point2D circumcenter = ::hxDaedalus::data::math::Point2D_obj::__new(null(),null());		HX_STACK_VAR(circumcenter,"circumcenter");
					HX_STACK_LINE(1440)
					Float radiusSquared;		HX_STACK_VAR(radiusSquared,"radiusSquared");
					HX_STACK_LINE(1441)
					Float distanceSquared;		HX_STACK_VAR(distanceSquared,"distanceSquared");
					HX_STACK_LINE(1442)
					bool isDelaunay = false;		HX_STACK_VAR(isDelaunay,"isDelaunay");
					HX_STACK_LINE(1443)
					int index = (int)0;		HX_STACK_VAR(index,"index");
					HX_STACK_LINE(1444)
					int i;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(1445)
					{
						HX_STACK_LINE(1445)
						int _g1 = (int)2;		HX_STACK_VAR(_g1,"_g1");
						HX_STACK_LINE(1445)
						int _g = bound->length;		HX_STACK_VAR(_g,"_g");
						HX_STACK_LINE(1445)
						while((true)){
							HX_STACK_LINE(1445)
							if ((!(((_g1 < _g))))){
								HX_STACK_LINE(1445)
								break;
							}
							HX_STACK_LINE(1445)
							int i1 = (_g1)++;		HX_STACK_VAR(i1,"i1");
							HX_STACK_LINE(1446)
							::hxDaedalus::data::Vertex _g8 = bound->__get(i1).StaticCast< ::hxDaedalus::data::Edge >()->get_originVertex();		HX_STACK_VAR(_g8,"_g8");
							HX_STACK_LINE(1446)
							vertexC = _g8;
							HX_STACK_LINE(1447)
							int _g9 = ::hxDaedalus::data::math::Geom2D_obj::getRelativePosition2(vertexC->get_pos()->x,vertexC->get_pos()->y,baseEdge);		HX_STACK_VAR(_g9,"_g9");
							HX_STACK_LINE(1447)
							if (((_g9 == (int)1))){
								HX_STACK_LINE(1449)
								index = i1;
								HX_STACK_LINE(1450)
								isDelaunay = true;
								HX_STACK_LINE(1451)
								::hxDaedalus::data::math::Geom2D_obj::getCircumcenter(vertexA->get_pos()->x,vertexA->get_pos()->y,vertexB->get_pos()->x,vertexB->get_pos()->y,vertexC->get_pos()->x,vertexC->get_pos()->y,circumcenter);
								HX_STACK_LINE(1452)
								radiusSquared = ((((vertexA->get_pos()->x - circumcenter->x)) * ((vertexA->get_pos()->x - circumcenter->x))) + (((vertexA->get_pos()->y - circumcenter->y)) * ((vertexA->get_pos()->y - circumcenter->y))));
								HX_STACK_LINE(1454)
								hx::SubEq(radiusSquared,0.0001);
								HX_STACK_LINE(1455)
								{
									HX_STACK_LINE(1455)
									int _g3 = (int)2;		HX_STACK_VAR(_g3,"_g3");
									HX_STACK_LINE(1455)
									int _g2 = bound->length;		HX_STACK_VAR(_g2,"_g2");
									HX_STACK_LINE(1455)
									while((true)){
										HX_STACK_LINE(1455)
										if ((!(((_g3 < _g2))))){
											HX_STACK_LINE(1455)
											break;
										}
										HX_STACK_LINE(1455)
										int j = (_g3)++;		HX_STACK_VAR(j,"j");
										HX_STACK_LINE(1456)
										if (((j != i1))){
											HX_STACK_LINE(1458)
											::hxDaedalus::data::Vertex _g10 = bound->__get(j).StaticCast< ::hxDaedalus::data::Edge >()->get_originVertex();		HX_STACK_VAR(_g10,"_g10");
											HX_STACK_LINE(1458)
											vertexCheck = _g10;
											HX_STACK_LINE(1459)
											distanceSquared = ((((vertexCheck->get_pos()->x - circumcenter->x)) * ((vertexCheck->get_pos()->x - circumcenter->x))) + (((vertexCheck->get_pos()->y - circumcenter->y)) * ((vertexCheck->get_pos()->y - circumcenter->y))));
											HX_STACK_LINE(1460)
											if (((distanceSquared < radiusSquared))){
												HX_STACK_LINE(1462)
												isDelaunay = false;
												HX_STACK_LINE(1463)
												break;
											}
										}
									}
								}
								HX_STACK_LINE(1468)
								if ((isDelaunay)){
									HX_STACK_LINE(1469)
									break;
								}
							}
						}
					}
					HX_STACK_LINE(1473)
					if ((!(isDelaunay))){
						HX_STACK_LINE(1477)
						::String s = HX_CSTRING("");		HX_STACK_VAR(s,"s");
						HX_STACK_LINE(1478)
						{
							HX_STACK_LINE(1478)
							int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
							HX_STACK_LINE(1478)
							int _g = bound->length;		HX_STACK_VAR(_g,"_g");
							HX_STACK_LINE(1478)
							while((true)){
								HX_STACK_LINE(1478)
								if ((!(((_g1 < _g))))){
									HX_STACK_LINE(1478)
									break;
								}
								HX_STACK_LINE(1478)
								int i1 = (_g1)++;		HX_STACK_VAR(i1,"i1");
								HX_STACK_LINE(1479)
								hx::AddEq(s,(bound->__get(i1).StaticCast< ::hxDaedalus::data::Edge >()->get_originVertex()->get_pos()->x + HX_CSTRING(" , ")));
								HX_STACK_LINE(1480)
								hx::AddEq(s,(bound->__get(i1).StaticCast< ::hxDaedalus::data::Edge >()->get_originVertex()->get_pos()->y + HX_CSTRING(" , ")));
								HX_STACK_LINE(1481)
								hx::AddEq(s,(bound->__get(i1).StaticCast< ::hxDaedalus::data::Edge >()->get_destinationVertex()->get_pos()->x + HX_CSTRING(" , ")));
								HX_STACK_LINE(1482)
								hx::AddEq(s,(bound->__get(i1).StaticCast< ::hxDaedalus::data::Edge >()->get_destinationVertex()->get_pos()->y + HX_CSTRING(" , ")));
							}
						}
						HX_STACK_LINE(1486)
						index = (int)2;
					}
					HX_STACK_LINE(1490)
					::hxDaedalus::data::Edge edgeA = null();		HX_STACK_VAR(edgeA,"edgeA");
					HX_STACK_LINE(1491)
					::hxDaedalus::data::Edge edgeAopp = null();		HX_STACK_VAR(edgeAopp,"edgeAopp");
					HX_STACK_LINE(1492)
					::hxDaedalus::data::Edge edgeB = null();		HX_STACK_VAR(edgeB,"edgeB");
					HX_STACK_LINE(1493)
					::hxDaedalus::data::Edge edgeBopp;		HX_STACK_VAR(edgeBopp,"edgeBopp");
					HX_STACK_LINE(1494)
					Array< ::Dynamic > boundA;		HX_STACK_VAR(boundA,"boundA");
					HX_STACK_LINE(1495)
					Array< ::Dynamic > boundM;		HX_STACK_VAR(boundM,"boundM");
					HX_STACK_LINE(1498)
					Array< ::Dynamic > boundB;		HX_STACK_VAR(boundB,"boundB");
					HX_STACK_LINE(1500)
					if (((index < (bound->length - (int)1)))){
						HX_STACK_LINE(1502)
						::hxDaedalus::data::Edge _g11 = ::hxDaedalus::data::Edge_obj::__new();		HX_STACK_VAR(_g11,"_g11");
						HX_STACK_LINE(1502)
						edgeA = _g11;
						HX_STACK_LINE(1503)
						::hxDaedalus::data::Edge _g12 = ::hxDaedalus::data::Edge_obj::__new();		HX_STACK_VAR(_g12,"_g12");
						HX_STACK_LINE(1503)
						edgeAopp = _g12;
						HX_STACK_LINE(1504)
						this->_edges->push(edgeA);
						HX_STACK_LINE(1505)
						this->_edges->push(edgeAopp);
						HX_STACK_LINE(1506)
						edgeA->setDatas(vertexA,edgeAopp,null(),null(),isReal,false);
						HX_STACK_LINE(1507)
						::hxDaedalus::data::Vertex _g13 = bound->__get(index).StaticCast< ::hxDaedalus::data::Edge >()->get_originVertex();		HX_STACK_VAR(_g13,"_g13");
						HX_STACK_LINE(1507)
						edgeAopp->setDatas(_g13,edgeA,null(),null(),isReal,false);
						HX_STACK_LINE(1508)
						Array< ::Dynamic > _g14 = bound->slice(index,null());		HX_STACK_VAR(_g14,"_g14");
						HX_STACK_LINE(1508)
						boundA = _g14;
						HX_STACK_LINE(1509)
						boundA->push(edgeA);
						HX_STACK_LINE(1510)
						this->triangulate(boundA,isReal);
					}
					HX_STACK_LINE(1513)
					if (((index > (int)2))){
						HX_STACK_LINE(1515)
						::hxDaedalus::data::Edge _g15 = ::hxDaedalus::data::Edge_obj::__new();		HX_STACK_VAR(_g15,"_g15");
						HX_STACK_LINE(1515)
						edgeB = _g15;
						HX_STACK_LINE(1516)
						::hxDaedalus::data::Edge _g16 = ::hxDaedalus::data::Edge_obj::__new();		HX_STACK_VAR(_g16,"_g16");
						HX_STACK_LINE(1516)
						edgeBopp = _g16;
						HX_STACK_LINE(1517)
						this->_edges->push(edgeB);
						HX_STACK_LINE(1518)
						this->_edges->push(edgeBopp);
						HX_STACK_LINE(1519)
						::hxDaedalus::data::Vertex _g17 = bound->__get((int)1).StaticCast< ::hxDaedalus::data::Edge >()->get_originVertex();		HX_STACK_VAR(_g17,"_g17");
						HX_STACK_LINE(1519)
						edgeB->setDatas(_g17,edgeBopp,null(),null(),isReal,false);
						HX_STACK_LINE(1520)
						::hxDaedalus::data::Vertex _g18 = bound->__get(index).StaticCast< ::hxDaedalus::data::Edge >()->get_originVertex();		HX_STACK_VAR(_g18,"_g18");
						HX_STACK_LINE(1520)
						edgeBopp->setDatas(_g18,edgeB,null(),null(),isReal,false);
						HX_STACK_LINE(1521)
						Array< ::Dynamic > _g19 = bound->slice((int)1,index);		HX_STACK_VAR(_g19,"_g19");
						HX_STACK_LINE(1521)
						boundB = _g19;
						HX_STACK_LINE(1522)
						boundB->push(edgeBopp);
						HX_STACK_LINE(1523)
						this->triangulate(boundB,isReal);
					}
					HX_STACK_LINE(1526)
					if (((index == (int)2))){
						HX_STACK_LINE(1527)
						boundM = Array_obj< ::Dynamic >::__new().Add(baseEdge).Add(bound->__get((int)1).StaticCast< ::hxDaedalus::data::Edge >()).Add(edgeAopp);
					}
					else{
						HX_STACK_LINE(1528)
						if (((index == (bound->length - (int)1)))){
							HX_STACK_LINE(1529)
							boundM = Array_obj< ::Dynamic >::__new().Add(baseEdge).Add(edgeB).Add(bound->__get(index).StaticCast< ::hxDaedalus::data::Edge >());
						}
						else{
							HX_STACK_LINE(1531)
							boundM = Array_obj< ::Dynamic >::__new().Add(baseEdge).Add(edgeB).Add(edgeAopp);
						}
					}
					HX_STACK_LINE(1534)
					this->triangulate(boundM,isReal);
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Mesh_obj,triangulate,(void))

int Mesh_obj::findPositionFromBounds( Float x,Float y){
	HX_STACK_FRAME("hxDaedalus.data.Mesh","findPositionFromBounds",0x4596de57,"hxDaedalus.data.Mesh.findPositionFromBounds","hxDaedalus/data/Mesh.hx",1549,0xb69595e6)
	HX_STACK_THIS(this)
	HX_STACK_ARG(x,"x")
	HX_STACK_ARG(y,"y")
	HX_STACK_LINE(1549)
	if (((x <= (int)0))){
		HX_STACK_LINE(1550)
		if (((y <= (int)0))){
			HX_STACK_LINE(1550)
			return (int)1;
		}
		else{
			HX_STACK_LINE(1551)
			if (((y >= this->_height))){
				HX_STACK_LINE(1551)
				return (int)7;
			}
			else{
				HX_STACK_LINE(1552)
				return (int)8;
			}
		}
	}
	else{
		HX_STACK_LINE(1553)
		if (((x >= this->_width))){
			HX_STACK_LINE(1554)
			if (((y <= (int)0))){
				HX_STACK_LINE(1554)
				return (int)3;
			}
			else{
				HX_STACK_LINE(1555)
				if (((y >= this->_height))){
					HX_STACK_LINE(1555)
					return (int)5;
				}
				else{
					HX_STACK_LINE(1556)
					return (int)4;
				}
			}
		}
		else{
			HX_STACK_LINE(1558)
			if (((y <= (int)0))){
				HX_STACK_LINE(1558)
				return (int)2;
			}
			else{
				HX_STACK_LINE(1559)
				if (((y >= this->_height))){
					HX_STACK_LINE(1559)
					return (int)6;
				}
				else{
					HX_STACK_LINE(1560)
					return (int)0;
				}
			}
		}
	}
	HX_STACK_LINE(1549)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC2(Mesh_obj,findPositionFromBounds,return )

Void Mesh_obj::debug( ){
{
		HX_STACK_FRAME("hxDaedalus.data.Mesh","debug",0x476f6cdd,"hxDaedalus.data.Mesh.debug","hxDaedalus/data/Mesh.hx",1565,0xb69595e6)
		HX_STACK_THIS(this)
		HX_STACK_LINE(1566)
		int i;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(1567)
		{
			HX_STACK_LINE(1567)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(1567)
			int _g = this->_vertices->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(1567)
			while((true)){
				HX_STACK_LINE(1567)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(1567)
					break;
				}
				HX_STACK_LINE(1567)
				int i1 = (_g1)++;		HX_STACK_VAR(i1,"i1");
				HX_STACK_LINE(1568)
				{
					HX_STACK_LINE(1568)
					int _g2 = this->_vertices->__get(i1).StaticCast< ::hxDaedalus::data::Vertex >()->get_id();		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(1568)
					Dynamic value = (HX_CSTRING("-- vertex ") + _g2);		HX_STACK_VAR(value,"value");
					HX_STACK_LINE(1568)
					Dynamic();
				}
				HX_STACK_LINE(1569)
				{
					HX_STACK_LINE(1569)
					int _g11 = this->_vertices->__get(i1).StaticCast< ::hxDaedalus::data::Vertex >()->get_edge()->get_id();		HX_STACK_VAR(_g11,"_g11");
					HX_STACK_LINE(1569)
					::String _g2 = (HX_CSTRING("  edge ") + _g11);		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(1569)
					::String _g3 = (_g2 + HX_CSTRING(" - "));		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(1569)
					::hxDaedalus::data::Edge _g4 = this->_vertices->__get(i1).StaticCast< ::hxDaedalus::data::Vertex >()->get_edge();		HX_STACK_VAR(_g4,"_g4");
					HX_STACK_LINE(1569)
					::String _g5 = ::Std_obj::string(_g4);		HX_STACK_VAR(_g5,"_g5");
					HX_STACK_LINE(1569)
					Dynamic value = (_g3 + _g5);		HX_STACK_VAR(value,"value");
					HX_STACK_LINE(1569)
					Dynamic();
				}
				HX_STACK_LINE(1570)
				{
					HX_STACK_LINE(1570)
					bool _g6 = this->_vertices->__get(i1).StaticCast< ::hxDaedalus::data::Vertex >()->get_edge()->get_isReal();		HX_STACK_VAR(_g6,"_g6");
					HX_STACK_LINE(1570)
					::String _g7 = ::Std_obj::string(_g6);		HX_STACK_VAR(_g7,"_g7");
					HX_STACK_LINE(1570)
					Dynamic value = (HX_CSTRING("  edge isReal: ") + _g7);		HX_STACK_VAR(value,"value");
					HX_STACK_LINE(1570)
					Dynamic();
				}
			}
		}
		HX_STACK_LINE(1572)
		{
			HX_STACK_LINE(1572)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(1572)
			int _g = this->_edges->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(1572)
			while((true)){
				HX_STACK_LINE(1572)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(1572)
					break;
				}
				HX_STACK_LINE(1572)
				int i1 = (_g1)++;		HX_STACK_VAR(i1,"i1");
				HX_STACK_LINE(1573)
				{
					HX_STACK_LINE(1573)
					::String _g8 = ::Std_obj::string(this->_edges->__get(i1).StaticCast< ::hxDaedalus::data::Edge >());		HX_STACK_VAR(_g8,"_g8");
					HX_STACK_LINE(1573)
					Dynamic value = (HX_CSTRING("-- edge ") + _g8);		HX_STACK_VAR(value,"value");
					HX_STACK_LINE(1573)
					Dynamic();
				}
				HX_STACK_LINE(1574)
				{
					HX_STACK_LINE(1574)
					int _g9 = this->_edges->__get(i1).StaticCast< ::hxDaedalus::data::Edge >()->get_id();		HX_STACK_VAR(_g9,"_g9");
					HX_STACK_LINE(1574)
					::String _g10 = (HX_CSTRING("  isReal ") + _g9);		HX_STACK_VAR(_g10,"_g10");
					HX_STACK_LINE(1574)
					::String _g11 = (_g10 + HX_CSTRING(" - "));		HX_STACK_VAR(_g11,"_g11");
					HX_STACK_LINE(1574)
					bool _g12 = this->_edges->__get(i1).StaticCast< ::hxDaedalus::data::Edge >()->get_isReal();		HX_STACK_VAR(_g12,"_g12");
					HX_STACK_LINE(1574)
					::String _g13 = ::Std_obj::string(_g12);		HX_STACK_VAR(_g13,"_g13");
					HX_STACK_LINE(1574)
					Dynamic value = (_g11 + _g13);		HX_STACK_VAR(value,"value");
					HX_STACK_LINE(1574)
					Dynamic();
				}
				HX_STACK_LINE(1575)
				{
					HX_STACK_LINE(1575)
					::hxDaedalus::data::Edge _g14 = this->_edges->__get(i1).StaticCast< ::hxDaedalus::data::Edge >()->get_nextLeftEdge();		HX_STACK_VAR(_g14,"_g14");
					HX_STACK_LINE(1575)
					::String _g15 = ::Std_obj::string(_g14);		HX_STACK_VAR(_g15,"_g15");
					HX_STACK_LINE(1575)
					Dynamic value = (HX_CSTRING("  nextLeftEdge ") + _g15);		HX_STACK_VAR(value,"value");
					HX_STACK_LINE(1575)
					Dynamic();
				}
				HX_STACK_LINE(1576)
				{
					HX_STACK_LINE(1576)
					::hxDaedalus::data::Edge _g16 = this->_edges->__get(i1).StaticCast< ::hxDaedalus::data::Edge >()->get_oppositeEdge();		HX_STACK_VAR(_g16,"_g16");
					HX_STACK_LINE(1576)
					::String _g17 = ::Std_obj::string(_g16);		HX_STACK_VAR(_g17,"_g17");
					HX_STACK_LINE(1576)
					Dynamic value = (HX_CSTRING("  oppositeEdge ") + _g17);		HX_STACK_VAR(value,"value");
					HX_STACK_LINE(1576)
					Dynamic();
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Mesh_obj,debug,(void))

Void Mesh_obj::traverse( Dynamic onVertex,Dynamic onEdge){
{
		HX_STACK_FRAME("hxDaedalus.data.Mesh","traverse",0x98de1568,"hxDaedalus.data.Mesh.traverse","hxDaedalus/data/Mesh.hx",1581,0xb69595e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(onVertex,"onVertex")
		HX_STACK_ARG(onEdge,"onEdge")
		HX_STACK_LINE(1582)
		::hxDaedalus::data::Vertex vertex;		HX_STACK_VAR(vertex,"vertex");
		HX_STACK_LINE(1583)
		::hxDaedalus::data::Edge incomingEdge;		HX_STACK_VAR(incomingEdge,"incomingEdge");
		HX_STACK_LINE(1584)
		::hxDaedalus::data::Face holdingFace;		HX_STACK_VAR(holdingFace,"holdingFace");
		HX_STACK_LINE(1586)
		::hxDaedalus::iterators::FromMeshToVertices iterVertices;		HX_STACK_VAR(iterVertices,"iterVertices");
		HX_STACK_LINE(1587)
		::hxDaedalus::iterators::FromMeshToVertices _g = ::hxDaedalus::iterators::FromMeshToVertices_obj::__new();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(1587)
		iterVertices = _g;
		HX_STACK_LINE(1588)
		iterVertices->set_fromMesh(hx::ObjectPtr<OBJ_>(this));
		HX_STACK_LINE(1590)
		::hxDaedalus::iterators::FromVertexToIncomingEdges iterEdges;		HX_STACK_VAR(iterEdges,"iterEdges");
		HX_STACK_LINE(1591)
		::hxDaedalus::iterators::FromVertexToIncomingEdges _g1 = ::hxDaedalus::iterators::FromVertexToIncomingEdges_obj::__new();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(1591)
		iterEdges = _g1;
		HX_STACK_LINE(1592)
		::haxe::ds::ObjectMap dictVerticesDone = ::haxe::ds::ObjectMap_obj::__new();		HX_STACK_VAR(dictVerticesDone,"dictVerticesDone");
		HX_STACK_LINE(1594)
		while((true)){
			HX_STACK_LINE(1594)
			::hxDaedalus::data::Vertex _g2 = iterVertices->next();		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(1594)
			::hxDaedalus::data::Vertex _g3 = vertex = _g2;		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(1594)
			if ((!(((_g3 != null()))))){
				HX_STACK_LINE(1594)
				break;
			}
			HX_STACK_LINE(1596)
			{
				HX_STACK_LINE(1596)
				dictVerticesDone->set(vertex,true);
				HX_STACK_LINE(1596)
				true;
			}
			HX_STACK_LINE(1597)
			if ((!(this->vertexIsInsideAABB(vertex,hx::ObjectPtr<OBJ_>(this))))){
				HX_STACK_LINE(1598)
				continue;
			}
			HX_STACK_LINE(1600)
			onVertex(vertex).Cast< Void >();
			HX_STACK_LINE(1602)
			iterEdges->set_fromVertex(vertex);
			HX_STACK_LINE(1603)
			while((true)){
				HX_STACK_LINE(1603)
				::hxDaedalus::data::Edge _g4 = iterEdges->next();		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(1603)
				::hxDaedalus::data::Edge _g5 = incomingEdge = _g4;		HX_STACK_VAR(_g5,"_g5");
				HX_STACK_LINE(1603)
				if ((!(((_g5 != null()))))){
					HX_STACK_LINE(1603)
					break;
				}
				struct _Function_3_1{
					inline static Dynamic Block( ::hxDaedalus::data::Edge &incomingEdge,::haxe::ds::ObjectMap &dictVerticesDone){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","hxDaedalus/data/Mesh.hx",1605,0xb69595e6)
						{
							HX_STACK_LINE(1605)
							::hxDaedalus::data::Vertex key = incomingEdge->get_originVertex();		HX_STACK_VAR(key,"key");
							HX_STACK_LINE(1605)
							return dictVerticesDone->get(key);
						}
						return null();
					}
				};
				HX_STACK_LINE(1605)
				if ((!(_Function_3_1::Block(incomingEdge,dictVerticesDone)))){
					HX_STACK_LINE(1607)
					onEdge(incomingEdge).Cast< Void >();
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Mesh_obj,traverse,(void))

bool Mesh_obj::vertexIsInsideAABB( ::hxDaedalus::data::Vertex vertex,::hxDaedalus::data::Mesh mesh){
	HX_STACK_FRAME("hxDaedalus.data.Mesh","vertexIsInsideAABB",0x2eabc5e0,"hxDaedalus.data.Mesh.vertexIsInsideAABB","hxDaedalus/data/Mesh.hx",1615,0xb69595e6)
	HX_STACK_THIS(this)
	HX_STACK_ARG(vertex,"vertex")
	HX_STACK_ARG(mesh,"mesh")
	struct _Function_1_1{
		inline static bool Block( ::hxDaedalus::data::Mesh &mesh,::hxDaedalus::data::Vertex &vertex){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","hxDaedalus/data/Mesh.hx",1615,0xb69595e6)
			{
				HX_STACK_LINE(1615)
				Float _g = mesh->get_width();		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(1615)
				return (vertex->get_pos()->x > _g);
			}
			return null();
		}
	};
	struct _Function_1_2{
		inline static bool Block( ::hxDaedalus::data::Mesh &mesh,::hxDaedalus::data::Vertex &vertex){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","hxDaedalus/data/Mesh.hx",1615,0xb69595e6)
			{
				HX_STACK_LINE(1615)
				Float _g1 = mesh->get_height();		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(1615)
				return (vertex->get_pos()->y > _g1);
			}
			return null();
		}
	};
	HX_STACK_LINE(1615)
	if (((  ((!(((  ((!(((  ((!(((vertex->get_pos()->x < (int)0))))) ? bool(_Function_1_1::Block(mesh,vertex)) : bool(true) ))))) ? bool((vertex->get_pos()->y < (int)0)) : bool(true) ))))) ? bool(_Function_1_2::Block(mesh,vertex)) : bool(true) ))){
		HX_STACK_LINE(1616)
		return false;
	}
	else{
		HX_STACK_LINE(1618)
		return true;
	}
	HX_STACK_LINE(1615)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC2(Mesh_obj,vertexIsInsideAABB,return )

int Mesh_obj::INC;


Mesh_obj::Mesh_obj()
{
}

void Mesh_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Mesh);
	HX_MARK_MEMBER_NAME(_id,"_id");
	HX_MARK_MEMBER_NAME(_width,"_width");
	HX_MARK_MEMBER_NAME(_height,"_height");
	HX_MARK_MEMBER_NAME(_clipping,"_clipping");
	HX_MARK_MEMBER_NAME(_vertices,"_vertices");
	HX_MARK_MEMBER_NAME(_edges,"_edges");
	HX_MARK_MEMBER_NAME(_faces,"_faces");
	HX_MARK_MEMBER_NAME(_constraintShapes,"_constraintShapes");
	HX_MARK_MEMBER_NAME(_objects,"_objects");
	HX_MARK_MEMBER_NAME(__centerVertex,"__centerVertex");
	HX_MARK_MEMBER_NAME(__edgesToCheck,"__edgesToCheck");
	HX_MARK_MEMBER_NAME(__objectsUpdateInProgress,"__objectsUpdateInProgress");
	HX_MARK_END_CLASS();
}

void Mesh_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_id,"_id");
	HX_VISIT_MEMBER_NAME(_width,"_width");
	HX_VISIT_MEMBER_NAME(_height,"_height");
	HX_VISIT_MEMBER_NAME(_clipping,"_clipping");
	HX_VISIT_MEMBER_NAME(_vertices,"_vertices");
	HX_VISIT_MEMBER_NAME(_edges,"_edges");
	HX_VISIT_MEMBER_NAME(_faces,"_faces");
	HX_VISIT_MEMBER_NAME(_constraintShapes,"_constraintShapes");
	HX_VISIT_MEMBER_NAME(_objects,"_objects");
	HX_VISIT_MEMBER_NAME(__centerVertex,"__centerVertex");
	HX_VISIT_MEMBER_NAME(__edgesToCheck,"__edgesToCheck");
	HX_VISIT_MEMBER_NAME(__objectsUpdateInProgress,"__objectsUpdateInProgress");
}

Dynamic Mesh_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { return get_id(); }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"INC") ) { return INC; }
		if (HX_FIELD_EQ(inName,"_id") ) { return _id; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"width") ) { return get_width(); }
		if (HX_FIELD_EQ(inName,"check") ) { return check_dyn(); }
		if (HX_FIELD_EQ(inName,"debug") ) { return debug_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"height") ) { return get_height(); }
		if (HX_FIELD_EQ(inName,"_width") ) { return _width; }
		if (HX_FIELD_EQ(inName,"_edges") ) { return _edges; }
		if (HX_FIELD_EQ(inName,"_faces") ) { return _faces; }
		if (HX_FIELD_EQ(inName,"get_id") ) { return get_id_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_height") ) { return _height; }
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"clipping") ) { return get_clipping(); }
		if (HX_FIELD_EQ(inName,"_objects") ) { return _objects; }
		if (HX_FIELD_EQ(inName,"flipEdge") ) { return flipEdge_dyn(); }
		if (HX_FIELD_EQ(inName,"traverse") ) { return traverse_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_clipping") ) { return _clipping; }
		if (HX_FIELD_EQ(inName,"_vertices") ) { return _vertices; }
		if (HX_FIELD_EQ(inName,"get_width") ) { return get_width_dyn(); }
		if (HX_FIELD_EQ(inName,"splitEdge") ) { return splitEdge_dyn(); }
		if (HX_FIELD_EQ(inName,"splitFace") ) { return splitFace_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_height") ) { return get_height_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"triangulate") ) { return triangulate_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"get_clipping") ) { return get_clipping_dyn(); }
		if (HX_FIELD_EQ(inName,"set_clipping") ) { return set_clipping_dyn(); }
		if (HX_FIELD_EQ(inName,"insertObject") ) { return insertObject_dyn(); }
		if (HX_FIELD_EQ(inName,"deleteObject") ) { return deleteObject_dyn(); }
		if (HX_FIELD_EQ(inName,"insertVertex") ) { return insertVertex_dyn(); }
		if (HX_FIELD_EQ(inName,"deleteVertex") ) { return deleteVertex_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"updateObjects") ) { return updateObjects_dyn(); }
		if (HX_FIELD_EQ(inName,"untriangulate") ) { return untriangulate_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"__centerVertex") ) { return __centerVertex; }
		if (HX_FIELD_EQ(inName,"__edgesToCheck") ) { return __edgesToCheck; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"buildFromRecord") ) { return buildFromRecord_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"_constraintShapes") ) { return _constraintShapes; }
		if (HX_FIELD_EQ(inName,"restoreAsDelaunay") ) { return restoreAsDelaunay_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"__constraintShapes") ) { return get___constraintShapes(); }
		if (HX_FIELD_EQ(inName,"vertexIsInsideAABB") ) { return vertexIsInsideAABB_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"insertConstraintShape") ) { return insertConstraintShape_dyn(); }
		if (HX_FIELD_EQ(inName,"deleteConstraintShape") ) { return deleteConstraintShape_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"get___constraintShapes") ) { return get___constraintShapes_dyn(); }
		if (HX_FIELD_EQ(inName,"findPositionFromBounds") ) { return findPositionFromBounds_dyn(); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"insertConstraintSegment") ) { return insertConstraintSegment_dyn(); }
		if (HX_FIELD_EQ(inName,"deleteConstraintSegment") ) { return deleteConstraintSegment_dyn(); }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"insertNewConstrainedEdge") ) { return insertNewConstrainedEdge_dyn(); }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"__objectsUpdateInProgress") ) { return __objectsUpdateInProgress; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Mesh_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"INC") ) { INC=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_id") ) { _id=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_width") ) { _width=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_edges") ) { _edges=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_faces") ) { _faces=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_height") ) { _height=inValue.Cast< Float >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"clipping") ) { return set_clipping(inValue); }
		if (HX_FIELD_EQ(inName,"_objects") ) { _objects=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_clipping") ) { _clipping=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_vertices") ) { _vertices=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"__centerVertex") ) { __centerVertex=inValue.Cast< ::hxDaedalus::data::Vertex >(); return inValue; }
		if (HX_FIELD_EQ(inName,"__edgesToCheck") ) { __edgesToCheck=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"_constraintShapes") ) { _constraintShapes=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"__objectsUpdateInProgress") ) { __objectsUpdateInProgress=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Mesh_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("height"));
	outFields->push(HX_CSTRING("width"));
	outFields->push(HX_CSTRING("clipping"));
	outFields->push(HX_CSTRING("id"));
	outFields->push(HX_CSTRING("__constraintShapes"));
	outFields->push(HX_CSTRING("_id"));
	outFields->push(HX_CSTRING("_width"));
	outFields->push(HX_CSTRING("_height"));
	outFields->push(HX_CSTRING("_clipping"));
	outFields->push(HX_CSTRING("_vertices"));
	outFields->push(HX_CSTRING("_edges"));
	outFields->push(HX_CSTRING("_faces"));
	outFields->push(HX_CSTRING("_constraintShapes"));
	outFields->push(HX_CSTRING("_objects"));
	outFields->push(HX_CSTRING("__centerVertex"));
	outFields->push(HX_CSTRING("__edgesToCheck"));
	outFields->push(HX_CSTRING("__objectsUpdateInProgress"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("INC"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(Mesh_obj,_id),HX_CSTRING("_id")},
	{hx::fsFloat,(int)offsetof(Mesh_obj,_width),HX_CSTRING("_width")},
	{hx::fsFloat,(int)offsetof(Mesh_obj,_height),HX_CSTRING("_height")},
	{hx::fsBool,(int)offsetof(Mesh_obj,_clipping),HX_CSTRING("_clipping")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(Mesh_obj,_vertices),HX_CSTRING("_vertices")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(Mesh_obj,_edges),HX_CSTRING("_edges")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(Mesh_obj,_faces),HX_CSTRING("_faces")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(Mesh_obj,_constraintShapes),HX_CSTRING("_constraintShapes")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(Mesh_obj,_objects),HX_CSTRING("_objects")},
	{hx::fsObject /*::hxDaedalus::data::Vertex*/ ,(int)offsetof(Mesh_obj,__centerVertex),HX_CSTRING("__centerVertex")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(Mesh_obj,__edgesToCheck),HX_CSTRING("__edgesToCheck")},
	{hx::fsBool,(int)offsetof(Mesh_obj,__objectsUpdateInProgress),HX_CSTRING("__objectsUpdateInProgress")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("_id"),
	HX_CSTRING("_width"),
	HX_CSTRING("_height"),
	HX_CSTRING("_clipping"),
	HX_CSTRING("_vertices"),
	HX_CSTRING("_edges"),
	HX_CSTRING("_faces"),
	HX_CSTRING("_constraintShapes"),
	HX_CSTRING("_objects"),
	HX_CSTRING("__centerVertex"),
	HX_CSTRING("__edgesToCheck"),
	HX_CSTRING("get_height"),
	HX_CSTRING("get_width"),
	HX_CSTRING("get_clipping"),
	HX_CSTRING("set_clipping"),
	HX_CSTRING("get_id"),
	HX_CSTRING("dispose"),
	HX_CSTRING("get___constraintShapes"),
	HX_CSTRING("buildFromRecord"),
	HX_CSTRING("insertObject"),
	HX_CSTRING("deleteObject"),
	HX_CSTRING("__objectsUpdateInProgress"),
	HX_CSTRING("updateObjects"),
	HX_CSTRING("insertConstraintShape"),
	HX_CSTRING("deleteConstraintShape"),
	HX_CSTRING("insertConstraintSegment"),
	HX_CSTRING("insertNewConstrainedEdge"),
	HX_CSTRING("deleteConstraintSegment"),
	HX_CSTRING("check"),
	HX_CSTRING("insertVertex"),
	HX_CSTRING("flipEdge"),
	HX_CSTRING("splitEdge"),
	HX_CSTRING("splitFace"),
	HX_CSTRING("restoreAsDelaunay"),
	HX_CSTRING("deleteVertex"),
	HX_CSTRING("untriangulate"),
	HX_CSTRING("triangulate"),
	HX_CSTRING("findPositionFromBounds"),
	HX_CSTRING("debug"),
	HX_CSTRING("traverse"),
	HX_CSTRING("vertexIsInsideAABB"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Mesh_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Mesh_obj::INC,"INC");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Mesh_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Mesh_obj::INC,"INC");
};

#endif

Class Mesh_obj::__mClass;

void Mesh_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDaedalus.data.Mesh"), hx::TCanCast< Mesh_obj> ,sStaticFields,sMemberFields,
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

void Mesh_obj::__boot()
{
	INC= (int)0;
}

} // end namespace hxDaedalus
} // end namespace data
