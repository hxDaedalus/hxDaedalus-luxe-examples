#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_hxDaedalus_data_math_RandGenerator
#include <hxDaedalus/data/math/RandGenerator.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace hxDaedalus{
namespace data{
namespace math{

Void RandGenerator_obj::__construct(hx::Null< int >  __o_seed,hx::Null< int >  __o_rangeMin_,hx::Null< int >  __o_rangeMax_)
{
HX_STACK_FRAME("hxDaedalus.data.math.RandGenerator","new",0x90ba35c5,"hxDaedalus.data.math.RandGenerator.new","hxDaedalus/data/math/RandGenerator.hx",19,0xc5b542ec)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_seed,"seed")
HX_STACK_ARG(__o_rangeMin_,"rangeMin_")
HX_STACK_ARG(__o_rangeMax_,"rangeMax_")
int seed = __o_seed.Default(1234);
int rangeMin_ = __o_rangeMin_.Default(0);
int rangeMax_ = __o_rangeMax_.Default(1);
{
	HX_STACK_LINE(20)
	int _g = this->_currSeed = seed;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(20)
	this->_originalSeed = _g;
	HX_STACK_LINE(21)
	this->rangeMin = rangeMin_;
	HX_STACK_LINE(22)
	this->rangeMax = rangeMax_;
	HX_STACK_LINE(24)
	this->_numIter = (int)0;
}
;
	return null();
}

//RandGenerator_obj::~RandGenerator_obj() { }

Dynamic RandGenerator_obj::__CreateEmpty() { return  new RandGenerator_obj; }
hx::ObjectPtr< RandGenerator_obj > RandGenerator_obj::__new(hx::Null< int >  __o_seed,hx::Null< int >  __o_rangeMin_,hx::Null< int >  __o_rangeMax_)
{  hx::ObjectPtr< RandGenerator_obj > result = new RandGenerator_obj();
	result->__construct(__o_seed,__o_rangeMin_,__o_rangeMax_);
	return result;}

Dynamic RandGenerator_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< RandGenerator_obj > result = new RandGenerator_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

int RandGenerator_obj::set_seed( int value){
	HX_STACK_FRAME("hxDaedalus.data.math.RandGenerator","set_seed",0x25bf86e9,"hxDaedalus.data.math.RandGenerator.set_seed","hxDaedalus/data/math/RandGenerator.hx",27,0xc5b542ec)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(27)
	int _g = this->_currSeed = value;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(27)
	this->_originalSeed = _g;
	HX_STACK_LINE(28)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(RandGenerator_obj,set_seed,return )

int RandGenerator_obj::get_seed( ){
	HX_STACK_FRAME("hxDaedalus.data.math.RandGenerator","get_seed",0x77622d75,"hxDaedalus.data.math.RandGenerator.get_seed","hxDaedalus/data/math/RandGenerator.hx",32,0xc5b542ec)
	HX_STACK_THIS(this)
	HX_STACK_LINE(32)
	return this->_originalSeed;
}


HX_DEFINE_DYNAMIC_FUNC0(RandGenerator_obj,get_seed,return )

Void RandGenerator_obj::reset( ){
{
		HX_STACK_FRAME("hxDaedalus.data.math.RandGenerator","reset",0x299e9274,"hxDaedalus.data.math.RandGenerator.reset","hxDaedalus/data/math/RandGenerator.hx",37,0xc5b542ec)
		HX_STACK_THIS(this)
		HX_STACK_LINE(38)
		this->_currSeed = this->_originalSeed;
		HX_STACK_LINE(39)
		this->_numIter = (int)0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(RandGenerator_obj,reset,(void))

int RandGenerator_obj::next( ){
	HX_STACK_FRAME("hxDaedalus.data.math.RandGenerator","next",0x1234d7ee,"hxDaedalus.data.math.RandGenerator.next","hxDaedalus/data/math/RandGenerator.hx",43,0xc5b542ec)
	HX_STACK_THIS(this)
	HX_STACK_LINE(44)
	Float _floatSeed = (this->_currSeed * 1.0);		HX_STACK_VAR(_floatSeed,"_floatSeed");
	HX_STACK_LINE(45)
	::String _g = ::Std_obj::string((_floatSeed * _floatSeed));		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(45)
	this->_tempString = _g;
	HX_STACK_LINE(46)
	while((true)){
		HX_STACK_LINE(46)
		if ((!(((this->_tempString.length < (int)8))))){
			HX_STACK_LINE(46)
			break;
		}
		HX_STACK_LINE(46)
		this->_tempString = (HX_CSTRING("0") + this->_tempString);
	}
	HX_STACK_LINE(47)
	::String _g1 = this->_tempString.substr((int)1,(int)5);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(47)
	Dynamic _g2 = ::Std_obj::parseInt(_g1);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(47)
	this->_currSeed = _g2;
	HX_STACK_LINE(48)
	int res = ::Math_obj::round((this->rangeMin + ((Float(this->_currSeed) / Float((int)99999)) * ((this->rangeMax - this->rangeMin)))));		HX_STACK_VAR(res,"res");
	HX_STACK_LINE(49)
	if (((this->_currSeed == (int)0))){
		HX_STACK_LINE(49)
		this->_currSeed = (this->_originalSeed + this->_numIter);
	}
	HX_STACK_LINE(50)
	(this->_numIter)++;
	HX_STACK_LINE(51)
	if (((this->_numIter == (int)200))){
		HX_STACK_LINE(51)
		this->reset();
	}
	HX_STACK_LINE(52)
	return res;
}


HX_DEFINE_DYNAMIC_FUNC0(RandGenerator_obj,next,return )

int RandGenerator_obj::nextInRange( int rangeMin,int rangeMax){
	HX_STACK_FRAME("hxDaedalus.data.math.RandGenerator","nextInRange",0x3537c54a,"hxDaedalus.data.math.RandGenerator.nextInRange","hxDaedalus/data/math/RandGenerator.hx",56,0xc5b542ec)
	HX_STACK_THIS(this)
	HX_STACK_ARG(rangeMin,"rangeMin")
	HX_STACK_ARG(rangeMax,"rangeMax")
	HX_STACK_LINE(57)
	this->rangeMin = rangeMin;
	HX_STACK_LINE(58)
	this->rangeMax = rangeMax;
	HX_STACK_LINE(59)
	return this->next();
}


HX_DEFINE_DYNAMIC_FUNC2(RandGenerator_obj,nextInRange,return )

Void RandGenerator_obj::shuffle( Dynamic array){
{
		HX_STACK_FRAME("hxDaedalus.data.math.RandGenerator","shuffle",0x4052c1de,"hxDaedalus.data.math.RandGenerator.shuffle","hxDaedalus/data/math/RandGenerator.hx",63,0xc5b542ec)
		HX_STACK_THIS(this)
		HX_STACK_ARG(array,"array")
		HX_STACK_LINE(64)
		int currIdx = array->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(currIdx,"currIdx");
		HX_STACK_LINE(66)
		while((true)){
			HX_STACK_LINE(66)
			if ((!(((currIdx > (int)0))))){
				HX_STACK_LINE(66)
				break;
			}
			HX_STACK_LINE(67)
			int rndIdx = this->nextInRange((int)0,(currIdx - (int)1));		HX_STACK_VAR(rndIdx,"rndIdx");
			HX_STACK_LINE(68)
			(currIdx)--;
			HX_STACK_LINE(70)
			Dynamic tmp = array->__GetItem(currIdx);		HX_STACK_VAR(tmp,"tmp");
			HX_STACK_LINE(71)
			hx::IndexRef((array).mPtr,currIdx) = array->__GetItem(rndIdx);
			HX_STACK_LINE(72)
			hx::IndexRef((array).mPtr,rndIdx) = tmp;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(RandGenerator_obj,shuffle,(void))


RandGenerator_obj::RandGenerator_obj()
{
}

void RandGenerator_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(RandGenerator);
	HX_MARK_MEMBER_NAME(rangeMin,"rangeMin");
	HX_MARK_MEMBER_NAME(rangeMax,"rangeMax");
	HX_MARK_MEMBER_NAME(_originalSeed,"_originalSeed");
	HX_MARK_MEMBER_NAME(_currSeed,"_currSeed");
	HX_MARK_MEMBER_NAME(_rangeMin,"_rangeMin");
	HX_MARK_MEMBER_NAME(_rangeMax,"_rangeMax");
	HX_MARK_MEMBER_NAME(_numIter,"_numIter");
	HX_MARK_MEMBER_NAME(_tempString,"_tempString");
	HX_MARK_END_CLASS();
}

void RandGenerator_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(rangeMin,"rangeMin");
	HX_VISIT_MEMBER_NAME(rangeMax,"rangeMax");
	HX_VISIT_MEMBER_NAME(_originalSeed,"_originalSeed");
	HX_VISIT_MEMBER_NAME(_currSeed,"_currSeed");
	HX_VISIT_MEMBER_NAME(_rangeMin,"_rangeMin");
	HX_VISIT_MEMBER_NAME(_rangeMax,"_rangeMax");
	HX_VISIT_MEMBER_NAME(_numIter,"_numIter");
	HX_VISIT_MEMBER_NAME(_tempString,"_tempString");
}

Dynamic RandGenerator_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"seed") ) { return get_seed(); }
		if (HX_FIELD_EQ(inName,"next") ) { return next_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"reset") ) { return reset_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"shuffle") ) { return shuffle_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"rangeMin") ) { return rangeMin; }
		if (HX_FIELD_EQ(inName,"rangeMax") ) { return rangeMax; }
		if (HX_FIELD_EQ(inName,"_numIter") ) { return _numIter; }
		if (HX_FIELD_EQ(inName,"set_seed") ) { return set_seed_dyn(); }
		if (HX_FIELD_EQ(inName,"get_seed") ) { return get_seed_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_currSeed") ) { return _currSeed; }
		if (HX_FIELD_EQ(inName,"_rangeMin") ) { return _rangeMin; }
		if (HX_FIELD_EQ(inName,"_rangeMax") ) { return _rangeMax; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_tempString") ) { return _tempString; }
		if (HX_FIELD_EQ(inName,"nextInRange") ) { return nextInRange_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_originalSeed") ) { return _originalSeed; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic RandGenerator_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"seed") ) { return set_seed(inValue); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"rangeMin") ) { rangeMin=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"rangeMax") ) { rangeMax=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_numIter") ) { _numIter=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_currSeed") ) { _currSeed=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_rangeMin") ) { _rangeMin=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_rangeMax") ) { _rangeMax=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_tempString") ) { _tempString=inValue.Cast< ::String >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_originalSeed") ) { _originalSeed=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void RandGenerator_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("seed"));
	outFields->push(HX_CSTRING("rangeMin"));
	outFields->push(HX_CSTRING("rangeMax"));
	outFields->push(HX_CSTRING("_originalSeed"));
	outFields->push(HX_CSTRING("_currSeed"));
	outFields->push(HX_CSTRING("_rangeMin"));
	outFields->push(HX_CSTRING("_rangeMax"));
	outFields->push(HX_CSTRING("_numIter"));
	outFields->push(HX_CSTRING("_tempString"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(RandGenerator_obj,rangeMin),HX_CSTRING("rangeMin")},
	{hx::fsInt,(int)offsetof(RandGenerator_obj,rangeMax),HX_CSTRING("rangeMax")},
	{hx::fsInt,(int)offsetof(RandGenerator_obj,_originalSeed),HX_CSTRING("_originalSeed")},
	{hx::fsInt,(int)offsetof(RandGenerator_obj,_currSeed),HX_CSTRING("_currSeed")},
	{hx::fsInt,(int)offsetof(RandGenerator_obj,_rangeMin),HX_CSTRING("_rangeMin")},
	{hx::fsInt,(int)offsetof(RandGenerator_obj,_rangeMax),HX_CSTRING("_rangeMax")},
	{hx::fsInt,(int)offsetof(RandGenerator_obj,_numIter),HX_CSTRING("_numIter")},
	{hx::fsString,(int)offsetof(RandGenerator_obj,_tempString),HX_CSTRING("_tempString")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("rangeMin"),
	HX_CSTRING("rangeMax"),
	HX_CSTRING("_originalSeed"),
	HX_CSTRING("_currSeed"),
	HX_CSTRING("_rangeMin"),
	HX_CSTRING("_rangeMax"),
	HX_CSTRING("_numIter"),
	HX_CSTRING("_tempString"),
	HX_CSTRING("set_seed"),
	HX_CSTRING("get_seed"),
	HX_CSTRING("reset"),
	HX_CSTRING("next"),
	HX_CSTRING("nextInRange"),
	HX_CSTRING("shuffle"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(RandGenerator_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(RandGenerator_obj::__mClass,"__mClass");
};

#endif

Class RandGenerator_obj::__mClass;

void RandGenerator_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDaedalus.data.math.RandGenerator"), hx::TCanCast< RandGenerator_obj> ,sStaticFields,sMemberFields,
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

void RandGenerator_obj::__boot()
{
}

} // end namespace hxDaedalus
} // end namespace data
} // end namespace math
