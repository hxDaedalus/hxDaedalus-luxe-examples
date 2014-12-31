#ifndef INCLUDED_IMap
#define INCLUDED_IMap

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(IMap)


class HXCPP_CLASS_ATTRIBUTES  IMap_obj : public hx::Interface{
	public:
		typedef hx::Interface super;
		typedef IMap_obj OBJ_;
		HX_DO_INTERFACE_RTTI;
		static void __boot();
virtual Dynamic get( Dynamic k)=0;
		Dynamic get_dyn();
virtual Void set( Dynamic k,Dynamic v)=0;
		Dynamic set_dyn();
};

#define DELEGATE_IMap \
virtual Dynamic get( Dynamic k) { return mDelegate->get(k);}  \
virtual Dynamic get_dyn() { return mDelegate->get_dyn();}  \
virtual Void set( Dynamic k,Dynamic v) { return mDelegate->set(k,v);}  \
virtual Dynamic set_dyn() { return mDelegate->set_dyn();}  \


template<typename IMPL>
class IMap_delegate_ : public IMap_obj
{
	protected:
		IMPL *mDelegate;
	public:
		IMap_delegate_(IMPL *inDelegate) : mDelegate(inDelegate) {}
		hx::Object *__GetRealObject() { return mDelegate; }
		void __Visit(HX_VISIT_PARAMS) { HX_VISIT_OBJECT(mDelegate); }
		DELEGATE_IMap
};


#endif /* INCLUDED_IMap */ 
