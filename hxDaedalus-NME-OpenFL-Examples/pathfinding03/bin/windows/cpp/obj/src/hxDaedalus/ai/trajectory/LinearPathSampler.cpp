#include <hxcpp.h>

#ifndef INCLUDED_hxDaedalus_ai_EntityAI
#include <hxDaedalus/ai/EntityAI.h>
#endif
#ifndef INCLUDED_hxDaedalus_ai_trajectory_LinearPathSampler
#include <hxDaedalus/ai/trajectory/LinearPathSampler.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace hxDaedalus{
namespace ai{
namespace trajectory{

Void LinearPathSampler_obj::__construct()
{
HX_STACK_FRAME("hxDaedalus.ai.trajectory.LinearPathSampler","new",0xb535ec56,"hxDaedalus.ai.trajectory.LinearPathSampler.new","hxDaedalus/ai/trajectory/LinearPathSampler.hx",7,0x1191d3bb)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(23)
	this->_samplingDistanceSquared = (int)1;
	HX_STACK_LINE(22)
	this->_samplingDistance = (int)1;
	HX_STACK_LINE(33)
	Array< Float > _g = Array_obj< Float >::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(33)
	this->_preCompX = _g;
	HX_STACK_LINE(34)
	Array< Float > _g1 = Array_obj< Float >::__new();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(34)
	this->_preCompY = _g1;
}
;
	return null();
}

//LinearPathSampler_obj::~LinearPathSampler_obj() { }

Dynamic LinearPathSampler_obj::__CreateEmpty() { return  new LinearPathSampler_obj; }
hx::ObjectPtr< LinearPathSampler_obj > LinearPathSampler_obj::__new()
{  hx::ObjectPtr< LinearPathSampler_obj > result = new LinearPathSampler_obj();
	result->__construct();
	return result;}

Dynamic LinearPathSampler_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< LinearPathSampler_obj > result = new LinearPathSampler_obj();
	result->__construct();
	return result;}

Void LinearPathSampler_obj::dispose( ){
{
		HX_STACK_FRAME("hxDaedalus.ai.trajectory.LinearPathSampler","dispose",0xff6acf95,"hxDaedalus.ai.trajectory.LinearPathSampler.dispose","hxDaedalus/ai/trajectory/LinearPathSampler.hx",37,0x1191d3bb)
		HX_STACK_THIS(this)
		HX_STACK_LINE(38)
		this->entity = null();
		HX_STACK_LINE(39)
		this->_path = null();
		HX_STACK_LINE(40)
		this->_preCompX = null();
		HX_STACK_LINE(41)
		this->_preCompY = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(LinearPathSampler_obj,dispose,(void))

Float LinearPathSampler_obj::get_x( ){
	HX_STACK_FRAME("hxDaedalus.ai.trajectory.LinearPathSampler","get_x",0xd7fa2ac5,"hxDaedalus.ai.trajectory.LinearPathSampler.get_x","hxDaedalus/ai/trajectory/LinearPathSampler.hx",45,0x1191d3bb)
	HX_STACK_THIS(this)
	HX_STACK_LINE(45)
	return this->_currentX;
}


HX_DEFINE_DYNAMIC_FUNC0(LinearPathSampler_obj,get_x,return )

Float LinearPathSampler_obj::get_y( ){
	HX_STACK_FRAME("hxDaedalus.ai.trajectory.LinearPathSampler","get_y",0xd7fa2ac6,"hxDaedalus.ai.trajectory.LinearPathSampler.get_y","hxDaedalus/ai/trajectory/LinearPathSampler.hx",49,0x1191d3bb)
	HX_STACK_THIS(this)
	HX_STACK_LINE(49)
	return this->_currentY;
}


HX_DEFINE_DYNAMIC_FUNC0(LinearPathSampler_obj,get_y,return )

bool LinearPathSampler_obj::get_hasPrev( ){
	HX_STACK_FRAME("hxDaedalus.ai.trajectory.LinearPathSampler","get_hasPrev",0x308d417a,"hxDaedalus.ai.trajectory.LinearPathSampler.get_hasPrev","hxDaedalus/ai/trajectory/LinearPathSampler.hx",53,0x1191d3bb)
	HX_STACK_THIS(this)
	HX_STACK_LINE(53)
	return this->_hasPrev;
}


HX_DEFINE_DYNAMIC_FUNC0(LinearPathSampler_obj,get_hasPrev,return )

bool LinearPathSampler_obj::get_hasNext( ){
	HX_STACK_FRAME("hxDaedalus.ai.trajectory.LinearPathSampler","get_hasNext",0x2f31077a,"hxDaedalus.ai.trajectory.LinearPathSampler.get_hasNext","hxDaedalus/ai/trajectory/LinearPathSampler.hx",57,0x1191d3bb)
	HX_STACK_THIS(this)
	HX_STACK_LINE(57)
	return this->_hasNext;
}


HX_DEFINE_DYNAMIC_FUNC0(LinearPathSampler_obj,get_hasNext,return )

int LinearPathSampler_obj::get_count( ){
	HX_STACK_FRAME("hxDaedalus.ai.trajectory.LinearPathSampler","get_count",0xd195199c,"hxDaedalus.ai.trajectory.LinearPathSampler.get_count","hxDaedalus/ai/trajectory/LinearPathSampler.hx",61,0x1191d3bb)
	HX_STACK_THIS(this)
	HX_STACK_LINE(61)
	return this->_count;
}


HX_DEFINE_DYNAMIC_FUNC0(LinearPathSampler_obj,get_count,return )

int LinearPathSampler_obj::set_count( int value){
	HX_STACK_FRAME("hxDaedalus.ai.trajectory.LinearPathSampler","set_count",0xb4e605a8,"hxDaedalus.ai.trajectory.LinearPathSampler.set_count","hxDaedalus/ai/trajectory/LinearPathSampler.hx",64,0x1191d3bb)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(65)
	this->_count = value;
	HX_STACK_LINE(66)
	if (((this->_count < (int)0))){
		HX_STACK_LINE(66)
		this->_count = (int)0;
	}
	HX_STACK_LINE(67)
	int _g = this->get_countMax();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(67)
	int _g1 = (_g - (int)1);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(67)
	if (((this->_count > _g1))){
		HX_STACK_LINE(67)
		int _g2 = this->get_countMax();		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(67)
		int _g3 = (_g2 - (int)1);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(67)
		this->_count = _g3;
	}
	HX_STACK_LINE(68)
	if (((this->_count == (int)0))){
		HX_STACK_LINE(68)
		this->_hasPrev = false;
	}
	else{
		HX_STACK_LINE(68)
		this->_hasPrev = true;
	}
	HX_STACK_LINE(69)
	int _g4 = this->get_countMax();		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(69)
	int _g5 = (_g4 - (int)1);		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(69)
	bool _g6;		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(69)
	if (((this->_count == _g5))){
		HX_STACK_LINE(69)
		_g6 = false;
	}
	else{
		HX_STACK_LINE(69)
		_g6 = true;
	}
	HX_STACK_LINE(69)
	this->_hasNext = _g6;
	HX_STACK_LINE(70)
	this->_currentX = this->_preCompX->__get(this->_count);
	HX_STACK_LINE(71)
	this->_currentY = this->_preCompY->__get(this->_count);
	HX_STACK_LINE(72)
	this->updateEntity();
	HX_STACK_LINE(74)
	return this->_count;
}


HX_DEFINE_DYNAMIC_FUNC1(LinearPathSampler_obj,set_count,return )

int LinearPathSampler_obj::get_countMax( ){
	HX_STACK_FRAME("hxDaedalus.ai.trajectory.LinearPathSampler","get_countMax",0x87389268,"hxDaedalus.ai.trajectory.LinearPathSampler.get_countMax","hxDaedalus/ai/trajectory/LinearPathSampler.hx",78,0x1191d3bb)
	HX_STACK_THIS(this)
	HX_STACK_LINE(78)
	return (this->_preCompX->length - (int)1);
}


HX_DEFINE_DYNAMIC_FUNC0(LinearPathSampler_obj,get_countMax,return )

Float LinearPathSampler_obj::get_samplingDistance( ){
	HX_STACK_FRAME("hxDaedalus.ai.trajectory.LinearPathSampler","get_samplingDistance",0xb4472a8f,"hxDaedalus.ai.trajectory.LinearPathSampler.get_samplingDistance","hxDaedalus/ai/trajectory/LinearPathSampler.hx",82,0x1191d3bb)
	HX_STACK_THIS(this)
	HX_STACK_LINE(82)
	return this->_samplingDistance;
}


HX_DEFINE_DYNAMIC_FUNC0(LinearPathSampler_obj,get_samplingDistance,return )

Float LinearPathSampler_obj::set_samplingDistance( Float value){
	HX_STACK_FRAME("hxDaedalus.ai.trajectory.LinearPathSampler","set_samplingDistance",0x80fee203,"hxDaedalus.ai.trajectory.LinearPathSampler.set_samplingDistance","hxDaedalus/ai/trajectory/LinearPathSampler.hx",85,0x1191d3bb)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(86)
	this->_samplingDistance = value;
	HX_STACK_LINE(87)
	this->_samplingDistanceSquared = (this->_samplingDistance * this->_samplingDistance);
	HX_STACK_LINE(88)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(LinearPathSampler_obj,set_samplingDistance,return )

Array< Float > LinearPathSampler_obj::set_path( Array< Float > value){
	HX_STACK_FRAME("hxDaedalus.ai.trajectory.LinearPathSampler","set_path",0xced0c2ec,"hxDaedalus.ai.trajectory.LinearPathSampler.set_path","hxDaedalus/ai/trajectory/LinearPathSampler.hx",91,0x1191d3bb)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(92)
	this->_path = value;
	HX_STACK_LINE(93)
	this->_preComputed = false;
	HX_STACK_LINE(94)
	this->reset();
	HX_STACK_LINE(95)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(LinearPathSampler_obj,set_path,return )

Void LinearPathSampler_obj::reset( ){
{
		HX_STACK_FRAME("hxDaedalus.ai.trajectory.LinearPathSampler","reset",0x2d61cf45,"hxDaedalus.ai.trajectory.LinearPathSampler.reset","hxDaedalus/ai/trajectory/LinearPathSampler.hx",99,0x1191d3bb)
		HX_STACK_THIS(this)
		HX_STACK_LINE(99)
		if (((this->_path->length > (int)0))){
			HX_STACK_LINE(102)
			this->_currentX = this->_path->__get((int)0);
			HX_STACK_LINE(103)
			this->_currentY = this->_path->__get((int)1);
			HX_STACK_LINE(104)
			this->_iPrev = (int)0;
			HX_STACK_LINE(105)
			this->_iNext = (int)2;
			HX_STACK_LINE(106)
			this->_hasPrev = false;
			HX_STACK_LINE(107)
			this->_hasNext = true;
			HX_STACK_LINE(108)
			this->_count = (int)0;
			HX_STACK_LINE(109)
			this->updateEntity();
		}
		else{
			HX_STACK_LINE(111)
			this->_hasPrev = false;
			HX_STACK_LINE(112)
			this->_hasNext = false;
			HX_STACK_LINE(113)
			this->_count = (int)0;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(LinearPathSampler_obj,reset,(void))

Void LinearPathSampler_obj::preCompute( ){
{
		HX_STACK_FRAME("hxDaedalus.ai.trajectory.LinearPathSampler","preCompute",0xc5a6985e,"hxDaedalus.ai.trajectory.LinearPathSampler.preCompute","hxDaedalus/ai/trajectory/LinearPathSampler.hx",117,0x1191d3bb)
		HX_STACK_THIS(this)
		HX_STACK_LINE(118)
		this->_preCompX->splice((int)0,this->_preCompX->length);
		HX_STACK_LINE(119)
		this->_preCompY->splice((int)0,this->_preCompY->length);
		HX_STACK_LINE(120)
		this->_count = (int)0;
		HX_STACK_LINE(121)
		this->_preCompX->push(this->_currentX);
		HX_STACK_LINE(122)
		this->_preCompY->push(this->_currentY);
		HX_STACK_LINE(123)
		this->_preComputed = false;
		HX_STACK_LINE(124)
		while((true)){
			HX_STACK_LINE(124)
			if ((!(this->next()))){
				HX_STACK_LINE(124)
				break;
			}
			HX_STACK_LINE(125)
			this->_preCompX->push(this->_currentX);
			HX_STACK_LINE(126)
			this->_preCompY->push(this->_currentY);
		}
		HX_STACK_LINE(128)
		this->reset();
		HX_STACK_LINE(129)
		this->_preComputed = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(LinearPathSampler_obj,preCompute,(void))

bool LinearPathSampler_obj::prev( ){
	HX_STACK_FRAME("hxDaedalus.ai.trajectory.LinearPathSampler","prev",0xdb551a3d,"hxDaedalus.ai.trajectory.LinearPathSampler.prev","hxDaedalus/ai/trajectory/LinearPathSampler.hx",137,0x1191d3bb)
	HX_STACK_THIS(this)
	HX_STACK_LINE(138)
	if ((!(this->_hasPrev))){
		HX_STACK_LINE(138)
		return false;
	}
	HX_STACK_LINE(139)
	this->_hasNext = true;
	HX_STACK_LINE(140)
	if ((this->_preComputed)){
		HX_STACK_LINE(141)
		(this->_count)--;
		HX_STACK_LINE(142)
		if (((this->_count == (int)0))){
			HX_STACK_LINE(142)
			this->_hasPrev = false;
		}
		HX_STACK_LINE(143)
		this->_currentX = this->_preCompX->__get(this->_count);
		HX_STACK_LINE(144)
		this->_currentY = this->_preCompY->__get(this->_count);
		HX_STACK_LINE(145)
		this->updateEntity();
		HX_STACK_LINE(146)
		return true;
	}
	HX_STACK_LINE(148)
	Float remainingDist;		HX_STACK_VAR(remainingDist,"remainingDist");
	HX_STACK_LINE(149)
	Float dist;		HX_STACK_VAR(dist,"dist");
	HX_STACK_LINE(150)
	remainingDist = this->_samplingDistance;
	HX_STACK_LINE(151)
	while((true)){
		HX_STACK_LINE(152)
		Float pathPrev = this->_path->__get(this->_iPrev);		HX_STACK_VAR(pathPrev,"pathPrev");
		HX_STACK_LINE(153)
		Float pathPrev1 = this->_path->__get((this->_iPrev + (int)1));		HX_STACK_VAR(pathPrev1,"pathPrev1");
		HX_STACK_LINE(154)
		Float _g;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(154)
		{
			HX_STACK_LINE(154)
			Float a = (this->_currentX - pathPrev);		HX_STACK_VAR(a,"a");
			HX_STACK_LINE(154)
			Float b = (this->_currentY - pathPrev1);		HX_STACK_VAR(b,"b");
			HX_STACK_LINE(154)
			_g = ::Math_obj::sqrt(((a * a) + (b * b)));
		}
		HX_STACK_LINE(154)
		dist = _g;
		HX_STACK_LINE(155)
		if (((dist < remainingDist))){
			HX_STACK_LINE(156)
			hx::SubEq(remainingDist,dist);
			HX_STACK_LINE(157)
			hx::SubEq(this->_iPrev,(int)2);
			HX_STACK_LINE(158)
			hx::SubEq(this->_iNext,(int)2);
			HX_STACK_LINE(159)
			if (((this->_iNext == (int)0))){
				HX_STACK_LINE(159)
				break;
			}
		}
		else{
			HX_STACK_LINE(161)
			break;
		}
	}
	HX_STACK_LINE(164)
	if (((this->_iNext == (int)0))){
		HX_STACK_LINE(165)
		this->_currentX = this->_path->__get((int)0);
		HX_STACK_LINE(166)
		this->_currentY = this->_path->__get((int)1);
		HX_STACK_LINE(167)
		this->_hasPrev = false;
		HX_STACK_LINE(168)
		this->_iNext = (int)2;
		HX_STACK_LINE(169)
		this->_iPrev = (int)0;
		HX_STACK_LINE(170)
		this->updateEntity();
		HX_STACK_LINE(171)
		return true;
	}
	else{
		HX_STACK_LINE(173)
		this->_currentX = (this->_currentX + (Float((((this->_path->__get(this->_iPrev) - this->_currentX)) * remainingDist)) / Float(dist)));
		HX_STACK_LINE(174)
		this->_currentY = (this->_currentY + (Float((((this->_path->__get((this->_iPrev + (int)1)) - this->_currentY)) * remainingDist)) / Float(dist)));
		HX_STACK_LINE(175)
		this->updateEntity();
		HX_STACK_LINE(176)
		return true;
	}
	HX_STACK_LINE(164)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(LinearPathSampler_obj,prev,return )

bool LinearPathSampler_obj::next( ){
	HX_STACK_FRAME("hxDaedalus.ai.trajectory.LinearPathSampler","next",0xd9f8e03d,"hxDaedalus.ai.trajectory.LinearPathSampler.next","hxDaedalus/ai/trajectory/LinearPathSampler.hx",180,0x1191d3bb)
	HX_STACK_THIS(this)
	HX_STACK_LINE(181)
	if ((!(this->_hasNext))){
		HX_STACK_LINE(181)
		return false;
	}
	HX_STACK_LINE(182)
	this->_hasPrev = true;
	HX_STACK_LINE(183)
	if ((this->_preComputed)){
		HX_STACK_LINE(184)
		(this->_count)++;
		HX_STACK_LINE(185)
		if (((this->_count == (this->_preCompX->length - (int)1)))){
			HX_STACK_LINE(186)
			this->_hasNext = false;
		}
		HX_STACK_LINE(187)
		this->_currentX = this->_preCompX->__get(this->_count);
		HX_STACK_LINE(188)
		this->_currentY = this->_preCompY->__get(this->_count);
		HX_STACK_LINE(189)
		this->updateEntity();
		HX_STACK_LINE(190)
		return true;
	}
	HX_STACK_LINE(192)
	Float remainingDist;		HX_STACK_VAR(remainingDist,"remainingDist");
	HX_STACK_LINE(193)
	Float dist;		HX_STACK_VAR(dist,"dist");
	HX_STACK_LINE(194)
	remainingDist = this->_samplingDistance;
	HX_STACK_LINE(195)
	while((true)){
		HX_STACK_LINE(197)
		Float pathNext = this->_path->__get(this->_iNext);		HX_STACK_VAR(pathNext,"pathNext");
		HX_STACK_LINE(198)
		Float pathNext1 = this->_path->__get((this->_iNext + (int)1));		HX_STACK_VAR(pathNext1,"pathNext1");
		HX_STACK_LINE(199)
		Float _g;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(199)
		{
			HX_STACK_LINE(199)
			Float a = (this->_currentX - pathNext);		HX_STACK_VAR(a,"a");
			HX_STACK_LINE(199)
			Float b = (this->_currentY - pathNext1);		HX_STACK_VAR(b,"b");
			HX_STACK_LINE(199)
			_g = ::Math_obj::sqrt(((a * a) + (b * b)));
		}
		HX_STACK_LINE(199)
		dist = _g;
		HX_STACK_LINE(200)
		if (((dist < remainingDist))){
			HX_STACK_LINE(201)
			hx::SubEq(remainingDist,dist);
			HX_STACK_LINE(202)
			this->_currentX = this->_path->__get(this->_iNext);
			HX_STACK_LINE(203)
			this->_currentY = this->_path->__get((this->_iNext + (int)1));
			HX_STACK_LINE(204)
			hx::AddEq(this->_iPrev,(int)2);
			HX_STACK_LINE(205)
			hx::AddEq(this->_iNext,(int)2);
			HX_STACK_LINE(206)
			if (((this->_iNext == this->_path->length))){
				HX_STACK_LINE(206)
				break;
			}
		}
		else{
			HX_STACK_LINE(208)
			break;
		}
	}
	HX_STACK_LINE(210)
	if (((this->_iNext == this->_path->length))){
		HX_STACK_LINE(211)
		this->_currentX = this->_path->__get(this->_iPrev);
		HX_STACK_LINE(212)
		this->_currentY = this->_path->__get((this->_iPrev + (int)1));
		HX_STACK_LINE(213)
		this->_hasNext = false;
		HX_STACK_LINE(214)
		this->_iNext = (this->_path->length - (int)2);
		HX_STACK_LINE(215)
		this->_iPrev = (this->_iNext - (int)2);
		HX_STACK_LINE(216)
		this->updateEntity();
		HX_STACK_LINE(217)
		return true;
	}
	else{
		HX_STACK_LINE(219)
		this->_currentX = (this->_currentX + (Float((((this->_path->__get(this->_iNext) - this->_currentX)) * remainingDist)) / Float(dist)));
		HX_STACK_LINE(220)
		this->_currentY = (this->_currentY + (Float((((this->_path->__get((this->_iNext + (int)1)) - this->_currentY)) * remainingDist)) / Float(dist)));
		HX_STACK_LINE(221)
		this->updateEntity();
		HX_STACK_LINE(222)
		return true;
	}
	HX_STACK_LINE(210)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(LinearPathSampler_obj,next,return )

Void LinearPathSampler_obj::updateEntity( ){
{
		HX_STACK_FRAME("hxDaedalus.ai.trajectory.LinearPathSampler","updateEntity",0x45f16f56,"hxDaedalus.ai.trajectory.LinearPathSampler.updateEntity","hxDaedalus/ai/trajectory/LinearPathSampler.hx",226,0x1191d3bb)
		HX_STACK_THIS(this)
		HX_STACK_LINE(227)
		if (((this->entity == null()))){
			HX_STACK_LINE(227)
			return null();
		}
		HX_STACK_LINE(228)
		{
			HX_STACK_LINE(228)
			bool cond;		HX_STACK_VAR(cond,"cond");
			HX_STACK_LINE(228)
			if ((::Math_obj::isNaN(this->_currentX))){
				HX_STACK_LINE(228)
				cond = ::Math_obj::isNaN(this->_currentY);
			}
			else{
				HX_STACK_LINE(228)
				cond = false;
			}
			HX_STACK_LINE(228)
			Dynamic();
		}
		HX_STACK_LINE(229)
		this->entity->x = this->_currentX;
		HX_STACK_LINE(230)
		this->entity->y = this->_currentY;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(LinearPathSampler_obj,updateEntity,(void))

Float LinearPathSampler_obj::pythag( Float a,Float b){
	HX_STACK_FRAME("hxDaedalus.ai.trajectory.LinearPathSampler","pythag",0x402bdbad,"hxDaedalus.ai.trajectory.LinearPathSampler.pythag","hxDaedalus/ai/trajectory/LinearPathSampler.hx",134,0x1191d3bb)
	HX_STACK_ARG(a,"a")
	HX_STACK_ARG(b,"b")
	HX_STACK_LINE(134)
	return ::Math_obj::sqrt(((a * a) + (b * b)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(LinearPathSampler_obj,pythag,return )


LinearPathSampler_obj::LinearPathSampler_obj()
{
}

void LinearPathSampler_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(LinearPathSampler);
	HX_MARK_MEMBER_NAME(entity,"entity");
	HX_MARK_MEMBER_NAME(_entity,"_entity");
	HX_MARK_MEMBER_NAME(_currentX,"_currentX");
	HX_MARK_MEMBER_NAME(_currentY,"_currentY");
	HX_MARK_MEMBER_NAME(_hasPrev,"_hasPrev");
	HX_MARK_MEMBER_NAME(_hasNext,"_hasNext");
	HX_MARK_MEMBER_NAME(_samplingDistance,"_samplingDistance");
	HX_MARK_MEMBER_NAME(_samplingDistanceSquared,"_samplingDistanceSquared");
	HX_MARK_MEMBER_NAME(_path,"_path");
	HX_MARK_MEMBER_NAME(_iPrev,"_iPrev");
	HX_MARK_MEMBER_NAME(_iNext,"_iNext");
	HX_MARK_MEMBER_NAME(_preComputed,"_preComputed");
	HX_MARK_MEMBER_NAME(_count,"_count");
	HX_MARK_MEMBER_NAME(_preCompX,"_preCompX");
	HX_MARK_MEMBER_NAME(_preCompY,"_preCompY");
	HX_MARK_END_CLASS();
}

void LinearPathSampler_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(entity,"entity");
	HX_VISIT_MEMBER_NAME(_entity,"_entity");
	HX_VISIT_MEMBER_NAME(_currentX,"_currentX");
	HX_VISIT_MEMBER_NAME(_currentY,"_currentY");
	HX_VISIT_MEMBER_NAME(_hasPrev,"_hasPrev");
	HX_VISIT_MEMBER_NAME(_hasNext,"_hasNext");
	HX_VISIT_MEMBER_NAME(_samplingDistance,"_samplingDistance");
	HX_VISIT_MEMBER_NAME(_samplingDistanceSquared,"_samplingDistanceSquared");
	HX_VISIT_MEMBER_NAME(_path,"_path");
	HX_VISIT_MEMBER_NAME(_iPrev,"_iPrev");
	HX_VISIT_MEMBER_NAME(_iNext,"_iNext");
	HX_VISIT_MEMBER_NAME(_preComputed,"_preComputed");
	HX_VISIT_MEMBER_NAME(_count,"_count");
	HX_VISIT_MEMBER_NAME(_preCompX,"_preCompX");
	HX_VISIT_MEMBER_NAME(_preCompY,"_preCompY");
}

Dynamic LinearPathSampler_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { return get_x(); }
		if (HX_FIELD_EQ(inName,"y") ) { return get_y(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"prev") ) { return prev_dyn(); }
		if (HX_FIELD_EQ(inName,"next") ) { return next_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"count") ) { return get_count(); }
		if (HX_FIELD_EQ(inName,"_path") ) { return _path; }
		if (HX_FIELD_EQ(inName,"get_x") ) { return get_x_dyn(); }
		if (HX_FIELD_EQ(inName,"get_y") ) { return get_y_dyn(); }
		if (HX_FIELD_EQ(inName,"reset") ) { return reset_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"pythag") ) { return pythag_dyn(); }
		if (HX_FIELD_EQ(inName,"entity") ) { return entity; }
		if (HX_FIELD_EQ(inName,"_iPrev") ) { return _iPrev; }
		if (HX_FIELD_EQ(inName,"_iNext") ) { return _iNext; }
		if (HX_FIELD_EQ(inName,"_count") ) { return _count; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"hasPrev") ) { return get_hasPrev(); }
		if (HX_FIELD_EQ(inName,"hasNext") ) { return get_hasNext(); }
		if (HX_FIELD_EQ(inName,"_entity") ) { return _entity; }
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"countMax") ) { return get_countMax(); }
		if (HX_FIELD_EQ(inName,"_hasPrev") ) { return _hasPrev; }
		if (HX_FIELD_EQ(inName,"_hasNext") ) { return _hasNext; }
		if (HX_FIELD_EQ(inName,"set_path") ) { return set_path_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_currentX") ) { return _currentX; }
		if (HX_FIELD_EQ(inName,"_currentY") ) { return _currentY; }
		if (HX_FIELD_EQ(inName,"_preCompX") ) { return _preCompX; }
		if (HX_FIELD_EQ(inName,"_preCompY") ) { return _preCompY; }
		if (HX_FIELD_EQ(inName,"get_count") ) { return get_count_dyn(); }
		if (HX_FIELD_EQ(inName,"set_count") ) { return set_count_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"preCompute") ) { return preCompute_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"get_hasPrev") ) { return get_hasPrev_dyn(); }
		if (HX_FIELD_EQ(inName,"get_hasNext") ) { return get_hasNext_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_preComputed") ) { return _preComputed; }
		if (HX_FIELD_EQ(inName,"get_countMax") ) { return get_countMax_dyn(); }
		if (HX_FIELD_EQ(inName,"updateEntity") ) { return updateEntity_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"samplingDistance") ) { return get_samplingDistance(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"_samplingDistance") ) { return _samplingDistance; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"get_samplingDistance") ) { return get_samplingDistance_dyn(); }
		if (HX_FIELD_EQ(inName,"set_samplingDistance") ) { return set_samplingDistance_dyn(); }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"_samplingDistanceSquared") ) { return _samplingDistanceSquared; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic LinearPathSampler_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"path") ) { return set_path(inValue); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"count") ) { return set_count(inValue); }
		if (HX_FIELD_EQ(inName,"_path") ) { _path=inValue.Cast< Array< Float > >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"entity") ) { entity=inValue.Cast< ::hxDaedalus::ai::EntityAI >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_iPrev") ) { _iPrev=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_iNext") ) { _iNext=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_count") ) { _count=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_entity") ) { _entity=inValue.Cast< ::hxDaedalus::ai::EntityAI >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_hasPrev") ) { _hasPrev=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_hasNext") ) { _hasNext=inValue.Cast< bool >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_currentX") ) { _currentX=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_currentY") ) { _currentY=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_preCompX") ) { _preCompX=inValue.Cast< Array< Float > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_preCompY") ) { _preCompY=inValue.Cast< Array< Float > >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_preComputed") ) { _preComputed=inValue.Cast< bool >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"samplingDistance") ) { return set_samplingDistance(inValue); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"_samplingDistance") ) { _samplingDistance=inValue.Cast< Float >(); return inValue; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"_samplingDistanceSquared") ) { _samplingDistanceSquared=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void LinearPathSampler_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("entity"));
	outFields->push(HX_CSTRING("x"));
	outFields->push(HX_CSTRING("y"));
	outFields->push(HX_CSTRING("hasPrev"));
	outFields->push(HX_CSTRING("hasNext"));
	outFields->push(HX_CSTRING("count"));
	outFields->push(HX_CSTRING("countMax"));
	outFields->push(HX_CSTRING("samplingDistance"));
	outFields->push(HX_CSTRING("path"));
	outFields->push(HX_CSTRING("_entity"));
	outFields->push(HX_CSTRING("_currentX"));
	outFields->push(HX_CSTRING("_currentY"));
	outFields->push(HX_CSTRING("_hasPrev"));
	outFields->push(HX_CSTRING("_hasNext"));
	outFields->push(HX_CSTRING("_samplingDistance"));
	outFields->push(HX_CSTRING("_samplingDistanceSquared"));
	outFields->push(HX_CSTRING("_path"));
	outFields->push(HX_CSTRING("_iPrev"));
	outFields->push(HX_CSTRING("_iNext"));
	outFields->push(HX_CSTRING("_preComputed"));
	outFields->push(HX_CSTRING("_count"));
	outFields->push(HX_CSTRING("_preCompX"));
	outFields->push(HX_CSTRING("_preCompY"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("pythag"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::hxDaedalus::ai::EntityAI*/ ,(int)offsetof(LinearPathSampler_obj,entity),HX_CSTRING("entity")},
	{hx::fsObject /*::hxDaedalus::ai::EntityAI*/ ,(int)offsetof(LinearPathSampler_obj,_entity),HX_CSTRING("_entity")},
	{hx::fsFloat,(int)offsetof(LinearPathSampler_obj,_currentX),HX_CSTRING("_currentX")},
	{hx::fsFloat,(int)offsetof(LinearPathSampler_obj,_currentY),HX_CSTRING("_currentY")},
	{hx::fsBool,(int)offsetof(LinearPathSampler_obj,_hasPrev),HX_CSTRING("_hasPrev")},
	{hx::fsBool,(int)offsetof(LinearPathSampler_obj,_hasNext),HX_CSTRING("_hasNext")},
	{hx::fsFloat,(int)offsetof(LinearPathSampler_obj,_samplingDistance),HX_CSTRING("_samplingDistance")},
	{hx::fsFloat,(int)offsetof(LinearPathSampler_obj,_samplingDistanceSquared),HX_CSTRING("_samplingDistanceSquared")},
	{hx::fsObject /*Array< Float >*/ ,(int)offsetof(LinearPathSampler_obj,_path),HX_CSTRING("_path")},
	{hx::fsInt,(int)offsetof(LinearPathSampler_obj,_iPrev),HX_CSTRING("_iPrev")},
	{hx::fsInt,(int)offsetof(LinearPathSampler_obj,_iNext),HX_CSTRING("_iNext")},
	{hx::fsBool,(int)offsetof(LinearPathSampler_obj,_preComputed),HX_CSTRING("_preComputed")},
	{hx::fsInt,(int)offsetof(LinearPathSampler_obj,_count),HX_CSTRING("_count")},
	{hx::fsObject /*Array< Float >*/ ,(int)offsetof(LinearPathSampler_obj,_preCompX),HX_CSTRING("_preCompX")},
	{hx::fsObject /*Array< Float >*/ ,(int)offsetof(LinearPathSampler_obj,_preCompY),HX_CSTRING("_preCompY")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("entity"),
	HX_CSTRING("_entity"),
	HX_CSTRING("_currentX"),
	HX_CSTRING("_currentY"),
	HX_CSTRING("_hasPrev"),
	HX_CSTRING("_hasNext"),
	HX_CSTRING("_samplingDistance"),
	HX_CSTRING("_samplingDistanceSquared"),
	HX_CSTRING("_path"),
	HX_CSTRING("_iPrev"),
	HX_CSTRING("_iNext"),
	HX_CSTRING("_preComputed"),
	HX_CSTRING("_count"),
	HX_CSTRING("_preCompX"),
	HX_CSTRING("_preCompY"),
	HX_CSTRING("dispose"),
	HX_CSTRING("get_x"),
	HX_CSTRING("get_y"),
	HX_CSTRING("get_hasPrev"),
	HX_CSTRING("get_hasNext"),
	HX_CSTRING("get_count"),
	HX_CSTRING("set_count"),
	HX_CSTRING("get_countMax"),
	HX_CSTRING("get_samplingDistance"),
	HX_CSTRING("set_samplingDistance"),
	HX_CSTRING("set_path"),
	HX_CSTRING("reset"),
	HX_CSTRING("preCompute"),
	HX_CSTRING("prev"),
	HX_CSTRING("next"),
	HX_CSTRING("updateEntity"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(LinearPathSampler_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(LinearPathSampler_obj::__mClass,"__mClass");
};

#endif

Class LinearPathSampler_obj::__mClass;

void LinearPathSampler_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDaedalus.ai.trajectory.LinearPathSampler"), hx::TCanCast< LinearPathSampler_obj> ,sStaticFields,sMemberFields,
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

void LinearPathSampler_obj::__boot()
{
}

} // end namespace hxDaedalus
} // end namespace ai
} // end namespace trajectory
