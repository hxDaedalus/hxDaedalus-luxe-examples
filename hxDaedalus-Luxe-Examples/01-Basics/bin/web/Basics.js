(function (console) { "use strict";
var $estr = function() { return js_Boot.__string_rec(this,''); };
function $extend(from, fields) {
	function Inherit() {} Inherit.prototype = from; var proto = new Inherit();
	for (var name in fields) proto[name] = fields[name];
	if( fields.toString !== Object.prototype.toString ) proto.toString = fields.toString;
	return proto;
}
var EReg = function(r,opt) {
	opt = opt.split("u").join("");
	this.r = new RegExp(r,opt);
};
EReg.__name__ = true;
EReg.prototype = {
	match: function(s) {
		if(this.r.global) this.r.lastIndex = 0;
		this.r.m = this.r.exec(s);
		this.r.s = s;
		return this.r.m != null;
	}
	,matched: function(n) {
		if(this.r.m != null && n >= 0 && n < this.r.m.length) return this.r.m[n]; else throw new js__$Boot_HaxeError("EReg::matched");
	}
	,matchedRight: function() {
		if(this.r.m == null) throw new js__$Boot_HaxeError("No string matched");
		var sz = this.r.m.index + this.r.m[0].length;
		return HxOverrides.substr(this.r.s,sz,this.r.s.length - sz);
	}
	,replace: function(s,by) {
		return s.replace(this.r,by);
	}
	,__class__: EReg
};
var HxOverrides = function() { };
HxOverrides.__name__ = true;
HxOverrides.cca = function(s,index) {
	var x = s.charCodeAt(index);
	if(x != x) return undefined;
	return x;
};
HxOverrides.substr = function(s,pos,len) {
	if(pos != null && pos != 0 && len != null && len < 0) return "";
	if(len == null) len = s.length;
	if(pos < 0) {
		pos = s.length + pos;
		if(pos < 0) pos = 0;
	} else if(len < 0) len = s.length + len - pos;
	return s.substr(pos,len);
};
HxOverrides.indexOf = function(a,obj,i) {
	var len = a.length;
	if(i < 0) {
		i += len;
		if(i < 0) i = 0;
	}
	while(i < len) {
		if(a[i] === obj) return i;
		i++;
	}
	return -1;
};
HxOverrides.remove = function(a,obj) {
	var i = HxOverrides.indexOf(a,obj,0);
	if(i == -1) return false;
	a.splice(i,1);
	return true;
};
HxOverrides.iter = function(a) {
	return { cur : 0, arr : a, hasNext : function() {
		return this.cur < this.arr.length;
	}, next : function() {
		return this.arr[this.cur++];
	}};
};
var Lambda = function() { };
Lambda.__name__ = true;
Lambda.has = function(it,elt) {
	var $it0 = $iterator(it)();
	while( $it0.hasNext() ) {
		var x = $it0.next();
		if(x == elt) return true;
	}
	return false;
};
Lambda.count = function(it,pred) {
	var n = 0;
	if(pred == null) {
		var $it0 = $iterator(it)();
		while( $it0.hasNext() ) {
			var _ = $it0.next();
			n++;
		}
	} else {
		var $it1 = $iterator(it)();
		while( $it1.hasNext() ) {
			var x = $it1.next();
			if(pred(x)) n++;
		}
	}
	return n;
};
var List = function() {
	this.length = 0;
};
List.__name__ = true;
List.prototype = {
	add: function(item) {
		var x = [item];
		if(this.h == null) this.h = x; else this.q[1] = x;
		this.q = x;
		this.length++;
	}
	,push: function(item) {
		var x = [item,this.h];
		this.h = x;
		if(this.q == null) this.q = x;
		this.length++;
	}
	,remove: function(v) {
		var prev = null;
		var l = this.h;
		while(l != null) {
			if(l[0] == v) {
				if(prev == null) this.h = l[1]; else prev[1] = l[1];
				if(this.q == l) this.q = prev;
				this.length--;
				return true;
			}
			prev = l;
			l = l[1];
		}
		return false;
	}
	,__class__: List
};
var Luxe = function() { };
Luxe.__name__ = true;
Luxe.__properties__ = {set_alpha:"set_alpha",get_alpha:"get_alpha",set_cur_frame_start:"set_cur_frame_start",get_cur_frame_start:"get_cur_frame_start",set_current_time:"set_current_time",get_current_time:"get_current_time",set_last_frame_start:"set_last_frame_start",get_last_frame_start:"get_last_frame_start",set_delta_sim:"set_delta_sim",get_delta_sim:"get_delta_sim",set_dt:"set_dt",get_dt:"get_dt",set_max_frame_time:"set_max_frame_time",get_max_frame_time:"get_max_frame_time",set_update_rate:"set_update_rate",get_update_rate:"get_update_rate",set_fixed_delta:"set_fixed_delta",get_fixed_delta:"get_fixed_delta",set_timescale:"set_timescale",get_timescale:"get_timescale",get_screen:"get_screen",get_time:"get_time"}
Luxe.on = function(event,handler) {
	Luxe.core.emitter.on(event,handler,{ fileName : "Luxe.hx", lineNumber : 84, className : "Luxe", methodName : "on"});
};
Luxe.off = function(event,handler) {
	return Luxe.core.emitter.off(event,handler,{ fileName : "Luxe.hx", lineNumber : 89, className : "Luxe", methodName : "off"});
};
Luxe.get_screen = function() {
	return Luxe.core.screen;
};
Luxe.get_time = function() {
	return snow_Snow.core.timestamp();
};
Luxe.shutdown = function() {
	Luxe.core.shutdown();
};
Luxe.showConsole = function(_show) {
	Luxe.core.show_console(_show);
};
Luxe.loadJSON = function(_id,_onload) {
	if(Luxe.resources.json.exists(_id)) {
		haxe_Log.trace("     i / luxe / " + ("loadJSON - return existing " + _id),{ fileName : "Luxe.hx", lineNumber : 124, className : "Luxe", methodName : "loadJSON"});
		var res1 = Luxe.resources.find_json(_id);
		if(_onload != null) _onload(res1);
		return res1;
	}
	var res = new luxe_resource_JSONResource(_id,null,Luxe.resources);
	Luxe.core.app.assets.text(_id,{ onload : function(_asset) {
		res.json = JSON.parse(_asset.text);
		if(_onload != null) _onload(res);
		Luxe.resources.cache(res);
	}});
	return res;
};
Luxe.loadText = function(_id,_onload) {
	if(Luxe.resources.text.exists(_id)) {
		haxe_Log.trace("     i / luxe / " + ("loadText - return existing " + _id),{ fileName : "Luxe.hx", lineNumber : 155, className : "Luxe", methodName : "loadText"});
		var res1 = Luxe.resources.find_text(_id);
		if(_onload != null) _onload(res1);
		return res1;
	}
	var res = new luxe_resource_TextResource(_id,null,Luxe.resources);
	Luxe.core.app.assets.text(_id,{ onload : function(_asset) {
		res.text = _asset.text;
		if(_onload != null) _onload(res);
		Luxe.resources.cache(res);
	}});
	return res;
};
Luxe.loadData = function(_id,_onload) {
	if(Luxe.resources.data.exists(_id)) {
		haxe_Log.trace("     i / luxe / " + ("loadData - return existing " + _id),{ fileName : "Luxe.hx", lineNumber : 188, className : "Luxe", methodName : "loadData"});
		var res1 = Luxe.resources.find_data(_id);
		if(_onload != null) _onload(res1);
		return res1;
	}
	var res = new luxe_resource_DataResource(_id,null,Luxe.resources);
	Luxe.core.app.assets.bytes(_id,{ onload : function(_asset) {
		res.data = _asset.bytes;
		if(_onload != null) _onload(res);
		Luxe.resources.cache(res);
	}});
	return res;
};
Luxe.loadSound = function(_name,_id,_is_music,_onload) {
	if(_is_music == null) _is_music = false;
	if(Luxe.resources.sounds.exists(_id)) {
		haxe_Log.trace("     i / luxe / " + ("loadSound - return existing " + _id),{ fileName : "Luxe.hx", lineNumber : 220, className : "Luxe", methodName : "loadSound"});
		var res1 = Luxe.resources.find_sound(_id);
		if(_onload != null) _onload(res1);
		return res1;
	}
	Luxe.audio.create(_id,_name,_is_music);
	var res = new luxe_resource_SoundResource(_id,_name,Luxe.resources);
	if(_onload != null) _onload(res);
	Luxe.resources.cache(res);
	return res;
};
Luxe.loadTexture = function(_id,_onload,_silent) {
	if(_silent == null) _silent = false;
	return phoenix_Texture.load(_id,_onload,_silent);
};
Luxe.loadTextures = function(_ids,_onload,_silent) {
	if(_silent == null) _silent = false;
	var total_count = _ids.length;
	var loaded_count = 0;
	var loaded = [];
	var on_single_texture_complete = function(texture) {
		loaded.push(texture);
		loaded_count++;
		if(loaded_count == total_count) _onload(loaded);
	};
	var _g = 0;
	while(_g < _ids.length) {
		var _id = _ids[_g];
		++_g;
		Luxe.loadTexture(_id,on_single_texture_complete,_silent);
	}
};
Luxe.loadFont = function(_id,_texture_path,_onload,_silent) {
	if(_silent == null) _silent = false;
	if(Luxe.resources.fonts.exists(_id)) {
		haxe_Log.trace("     i / luxe / " + ("loadFont - return existing " + _id),{ fileName : "Luxe.hx", lineNumber : 277, className : "Luxe", methodName : "loadFont"});
		var res = Luxe.resources.find_font(_id);
		if(_onload != null) _onload(res);
		return res;
	}
	return phoenix_BitmapFont.load({ id : _id, texture_path : _texture_path, onload : _onload, silent : _silent});
};
Luxe.loadShader = function(_ps_id,_vs_id,_onload,_silent) {
	if(_silent == null) _silent = false;
	if(_vs_id == null) _vs_id = "default";
	if(_ps_id == null) _ps_id = "default";
	var _id = "" + _ps_id + "|" + _vs_id;
	if(Luxe.resources.shaders.exists(_id)) {
		haxe_Log.trace("     i / luxe / " + ("loadShader - return existing " + _id),{ fileName : "Luxe.hx", lineNumber : 294, className : "Luxe", methodName : "loadShader"});
		var res = Luxe.resources.find_shader(_id);
		if(_onload != null) _onload(res);
		return res;
	}
	return phoenix_Shader.load(_ps_id,_vs_id,_onload,_silent);
};
Luxe.get_timescale = function() {
	return Luxe.core.timescale;
};
Luxe.get_fixed_delta = function() {
	return Luxe.core.fixed_delta;
};
Luxe.get_update_rate = function() {
	return Luxe.core.update_rate;
};
Luxe.get_max_frame_time = function() {
	return Luxe.core.max_frame_time;
};
Luxe.get_dt = function() {
	return Luxe.core.delta_time;
};
Luxe.get_delta_sim = function() {
	return Luxe.core.delta_sim;
};
Luxe.get_last_frame_start = function() {
	return Luxe.core.last_frame_start;
};
Luxe.get_current_time = function() {
	return Luxe.core.current_time;
};
Luxe.get_cur_frame_start = function() {
	return Luxe.core.cur_frame_start;
};
Luxe.get_alpha = function() {
	return Luxe.core.alpha;
};
Luxe.set_timescale = function(value) {
	return Luxe.core.timescale = value;
};
Luxe.set_fixed_delta = function(value) {
	return Luxe.core.fixed_delta = value;
};
Luxe.set_update_rate = function(value) {
	return Luxe.core.update_rate = value;
};
Luxe.set_max_frame_time = function(value) {
	return Luxe.core.max_frame_time = value;
};
Luxe.set_dt = function(value) {
	return Luxe.core.delta_time = value;
};
Luxe.set_delta_sim = function(value) {
	return Luxe.core.delta_sim = value;
};
Luxe.set_last_frame_start = function(value) {
	return Luxe.core.last_frame_start = value;
};
Luxe.set_current_time = function(value) {
	return Luxe.core.current_time = value;
};
Luxe.set_cur_frame_start = function(value) {
	return Luxe.core.cur_frame_start = value;
};
Luxe.set_alpha = function(value) {
	return Luxe.core.alpha = value;
};
var LuxeApp = function() { };
LuxeApp.__name__ = true;
LuxeApp.main = function() {
	LuxeApp._conf = { window : { width : 960, height : 640, fullscreen : false, resizable : true, borderless : false, title : "luxe app"}};
	LuxeApp._conf.window.width = 600;
	LuxeApp._conf.window.height = 400;
	LuxeApp._conf.window.fullscreen = false;
	LuxeApp._conf.window.resizable = true;
	LuxeApp._conf.window.borderless = false;
	LuxeApp._conf.window.title = "Basics";
	LuxeApp._snow = new snow_Snow();
	LuxeApp._game = new Main();
	LuxeApp._core = new luxe_Core(LuxeApp._game,LuxeApp._conf);
	var _snow_config = { has_loop : true, config_custom_assets : false, config_custom_runtime : false, config_runtime_path : "config.json", config_assets_path : "manifest", app_package : "lib.hxDaedalus.examples"};
	LuxeApp._snow.init(_snow_config,LuxeApp._core);
};
var luxe_Emitter = function() {
	this._checking = false;
	this._to_remove = new List();
	this.connected = new List();
	this.bindings = new haxe_ds_IntMap();
};
luxe_Emitter.__name__ = true;
luxe_Emitter.prototype = {
	emit: function(event,data,pos) {
		this._check();
		var list = this.bindings.h[event];
		if(list != null && list.length > 0) {
			var _g = 0;
			while(_g < list.length) {
				var handler = list[_g];
				++_g;
				handler(data);
			}
		}
		this._check();
	}
	,on: function(event,handler,pos) {
		this._check();
		if(!this.bindings.h.hasOwnProperty(event)) {
			this.bindings.h[event] = [handler];
			this.connected.push({ handler : handler, event : event, pos : pos});
		} else {
			var list = this.bindings.h[event];
			if(HxOverrides.indexOf(list,handler,0) == -1) {
				list.push(handler);
				this.connected.push({ handler : handler, event : event, pos : pos});
			}
		}
	}
	,off: function(event,handler,pos) {
		this._check();
		var success = false;
		if(this.bindings.h.hasOwnProperty(event)) {
			this._to_remove.push({ event : event, handler : handler});
			var _g_head = this.connected.h;
			var _g_val = null;
			while(_g_head != null) {
				var _info;
				_info = (function($this) {
					var $r;
					_g_val = _g_head[0];
					_g_head = _g_head[1];
					$r = _g_val;
					return $r;
				}(this));
				if(_info.event == event && _info.handler == handler) this.connected.remove(_info);
			}
			success = true;
		}
		return success;
	}
	,connections: function(handler) {
		var list = [];
		var _g_head = this.connected.h;
		var _g_val = null;
		while(_g_head != null) {
			var _info;
			_info = (function($this) {
				var $r;
				_g_val = _g_head[0];
				_g_head = _g_head[1];
				$r = _g_val;
				return $r;
			}(this));
			if(_info.handler == handler) list.push(_info);
		}
		return list;
	}
	,_check: function() {
		if(this._checking) return;
		this._checking = true;
		if(this._to_remove.length > 0) {
			var _g_head = this._to_remove.h;
			var _g_val = null;
			while(_g_head != null) {
				var _node;
				_node = (function($this) {
					var $r;
					_g_val = _g_head[0];
					_g_head = _g_head[1];
					$r = _g_val;
					return $r;
				}(this));
				var list = this.bindings.h[_node.event];
				HxOverrides.remove(list,_node.handler);
				if(list.length == 0) this.bindings.remove(_node.event);
			}
			this._to_remove = null;
			this._to_remove = new List();
		}
		this._checking = false;
	}
	,__class__: luxe_Emitter
};
var luxe_Game = function() {
	luxe_Emitter.call(this);
};
luxe_Game.__name__ = true;
luxe_Game.__super__ = luxe_Emitter;
luxe_Game.prototype = $extend(luxe_Emitter.prototype,{
	config: function(config) {
		return config;
	}
	,ready: function() {
	}
	,update: function(dt) {
	}
	,onevent: function(event) {
	}
	,ondestroy: function() {
	}
	,onprerender: function() {
	}
	,onrender: function() {
	}
	,onpostrender: function() {
	}
	,oninputdown: function(_name,e) {
	}
	,oninputup: function(_name,e) {
	}
	,onmousedown: function(event) {
	}
	,onmouseup: function(event) {
	}
	,onmousewheel: function(event) {
	}
	,onmousemove: function(event) {
	}
	,onkeydown: function(event) {
	}
	,onkeyup: function(event) {
	}
	,ontextinput: function(event) {
	}
	,ontouchdown: function(event) {
	}
	,ontouchup: function(event) {
	}
	,ontouchmove: function(event) {
	}
	,ongamepadaxis: function(event) {
	}
	,ongamepaddown: function(event) {
	}
	,ongamepadup: function(event) {
	}
	,ongamepaddevice: function(event) {
	}
	,onwindowmoved: function(event) {
	}
	,onwindowresized: function(event) {
	}
	,onwindowsized: function(event) {
	}
	,onwindowminimized: function(event) {
	}
	,onwindowrestored: function(event) {
	}
	,__class__: luxe_Game
});
var Main = function() {
	luxe_Game.call(this);
};
Main.__name__ = true;
Main.__super__ = luxe_Game;
Main.prototype = $extend(luxe_Game.prototype,{
	ready: function() {
		var background = new luxe_Visual({ size : Luxe.core.screen.get_size(), color : new phoenix_Color(1,1,1), depth : -1},{ fileName : "Main.hx", lineNumber : 25, className : "Main", methodName : "ready"});
		this._mesh = hxDaedalus_factories_RectMesh.buildRectangle(600,400);
		this._view = new hxDaedalus_view_SimpleView([]);
		var vertex = this._mesh.insertVertex(550,50);
		var segment = this._mesh.insertConstraintSegment(70,300,530,320);
		var shape = this._mesh.insertConstraintShape([50.,50.,100.,50.,100.,50.,100.,100.,100.,100.,50.,100.,50.,100.,50.,50.,20.,50.,130.,100.]);
		var objectCoords = [];
		this._object = new hxDaedalus_data_Object();
		this._object.set_coordinates([-50.,0.,50.,0.,0.,-50.,0.,50.,-30.,-30.,30.,30.,30.,-30.,-30.,30.]);
		this._mesh.insertObject(this._object);
		this._object.set_x(400);
		this._object.set_y(200);
		this._object.set_scaleX(2);
		this._object.set_scaleY(2);
	}
	,onkeyup: function(e) {
		if(e.keycode == snow_input_Keycodes.escape) Luxe.shutdown();
	}
	,update: function(dt) {
		var _g = this._object;
		_g.set_rotation(_g.get_rotation() + 0.05);
		this._mesh.updateObjects();
		this._view.drawMesh(this._mesh,true);
	}
	,__class__: Main
});
Math.__name__ = true;
var Reflect = function() { };
Reflect.__name__ = true;
Reflect.field = function(o,field) {
	try {
		return o[field];
	} catch( e ) {
		if (e instanceof js__$Boot_HaxeError) e = e.val;
		return null;
	}
};
Reflect.setField = function(o,field,value) {
	o[field] = value;
};
Reflect.getProperty = function(o,field) {
	var tmp;
	if(o == null) return null; else if(o.__properties__ && (tmp = o.__properties__["get_" + field])) return o[tmp](); else return o[field];
};
Reflect.setProperty = function(o,field,value) {
	var tmp;
	if(o.__properties__ && (tmp = o.__properties__["set_" + field])) o[tmp](value); else o[field] = value;
};
Reflect.callMethod = function(o,func,args) {
	return func.apply(o,args);
};
Reflect.fields = function(o) {
	var a = [];
	if(o != null) {
		var hasOwnProperty = Object.prototype.hasOwnProperty;
		for( var f in o ) {
		if(f != "__id__" && f != "hx__closures__" && hasOwnProperty.call(o,f)) a.push(f);
		}
	}
	return a;
};
var Std = function() { };
Std.__name__ = true;
Std.string = function(s) {
	return js_Boot.__string_rec(s,"");
};
Std["int"] = function(x) {
	return x | 0;
};
Std.parseInt = function(x) {
	var v = parseInt(x,10);
	if(v == 0 && (HxOverrides.cca(x,1) == 120 || HxOverrides.cca(x,1) == 88)) v = parseInt(x);
	if(isNaN(v)) return null;
	return v;
};
Std.parseFloat = function(x) {
	return parseFloat(x);
};
Std.random = function(x) {
	if(x <= 0) return 0; else return Math.floor(Math.random() * x);
};
var StringBuf = function() {
	this.b = "";
};
StringBuf.__name__ = true;
StringBuf.prototype = {
	add: function(x) {
		this.b += Std.string(x);
	}
	,__class__: StringBuf
};
var StringTools = function() { };
StringTools.__name__ = true;
StringTools.isSpace = function(s,pos) {
	var c = HxOverrides.cca(s,pos);
	return c > 8 && c < 14 || c == 32;
};
StringTools.ltrim = function(s) {
	var l = s.length;
	var r = 0;
	while(r < l && StringTools.isSpace(s,r)) r++;
	if(r > 0) return HxOverrides.substr(s,r,l - r); else return s;
};
StringTools.rtrim = function(s) {
	var l = s.length;
	var r = 0;
	while(r < l && StringTools.isSpace(s,l - r - 1)) r++;
	if(r > 0) return HxOverrides.substr(s,0,l - r); else return s;
};
StringTools.trim = function(s) {
	return StringTools.ltrim(StringTools.rtrim(s));
};
StringTools.rpad = function(s,c,l) {
	if(c.length <= 0) return s;
	while(s.length < l) s = s + c;
	return s;
};
StringTools.replace = function(s,sub,by) {
	return s.split(sub).join(by);
};
StringTools.fastCodeAt = function(s,index) {
	return s.charCodeAt(index);
};
var Type = function() { };
Type.__name__ = true;
Type.createInstance = function(cl,args) {
	var _g = args.length;
	switch(_g) {
	case 0:
		return new cl();
	case 1:
		return new cl(args[0]);
	case 2:
		return new cl(args[0],args[1]);
	case 3:
		return new cl(args[0],args[1],args[2]);
	case 4:
		return new cl(args[0],args[1],args[2],args[3]);
	case 5:
		return new cl(args[0],args[1],args[2],args[3],args[4]);
	case 6:
		return new cl(args[0],args[1],args[2],args[3],args[4],args[5]);
	case 7:
		return new cl(args[0],args[1],args[2],args[3],args[4],args[5],args[6]);
	case 8:
		return new cl(args[0],args[1],args[2],args[3],args[4],args[5],args[6],args[7]);
	default:
		throw new js__$Boot_HaxeError("Too many arguments");
	}
	return null;
};
var _$UInt_UInt_$Impl_$ = {};
_$UInt_UInt_$Impl_$.__name__ = true;
_$UInt_UInt_$Impl_$.toFloat = function(this1) {
	var $int = this1;
	if($int < 0) return 4294967296.0 + $int; else return $int + 0.0;
};
var haxe_StackItem = { __ename__ : true, __constructs__ : ["CFunction","Module","FilePos","Method","LocalFunction"] };
haxe_StackItem.CFunction = ["CFunction",0];
haxe_StackItem.CFunction.toString = $estr;
haxe_StackItem.CFunction.__enum__ = haxe_StackItem;
haxe_StackItem.Module = function(m) { var $x = ["Module",1,m]; $x.__enum__ = haxe_StackItem; $x.toString = $estr; return $x; };
haxe_StackItem.FilePos = function(s,file,line) { var $x = ["FilePos",2,s,file,line]; $x.__enum__ = haxe_StackItem; $x.toString = $estr; return $x; };
haxe_StackItem.Method = function(classname,method) { var $x = ["Method",3,classname,method]; $x.__enum__ = haxe_StackItem; $x.toString = $estr; return $x; };
haxe_StackItem.LocalFunction = function(v) { var $x = ["LocalFunction",4,v]; $x.__enum__ = haxe_StackItem; $x.toString = $estr; return $x; };
var haxe_CallStack = function() { };
haxe_CallStack.__name__ = true;
haxe_CallStack.getStack = function(e) {
	var oldValue = Error.prepareStackTrace;
	Error.prepareStackTrace = function(error,callsites) {
		var stack = [];
		var _g = 0;
		while(_g < callsites.length) {
			var site = callsites[_g];
			++_g;
			if(haxe_CallStack.wrapCallSite != null) site = haxe_CallStack.wrapCallSite(site);
			var method = null;
			var fullName = site.getFunctionName();
			if(fullName != null) {
				var idx = fullName.lastIndexOf(".");
				if(idx >= 0) {
					var className = HxOverrides.substr(fullName,0,idx);
					var methodName = HxOverrides.substr(fullName,idx + 1,null);
					method = haxe_StackItem.Method(className,methodName);
				}
			}
			stack.push(haxe_StackItem.FilePos(method,site.getFileName(),site.getLineNumber()));
		}
		return stack;
	};
	var a = haxe_CallStack.makeStack(e.stack);
	Error.prepareStackTrace = oldValue;
	return a;
};
haxe_CallStack.callStack = function() {
	try {
		throw new Error();
	} catch( e ) {
		if (e instanceof js__$Boot_HaxeError) e = e.val;
		var a = haxe_CallStack.getStack(e);
		a.shift();
		return a;
	}
};
haxe_CallStack.makeStack = function(s) {
	if(s == null) return []; else if(typeof(s) == "string") {
		var stack = s.split("\n");
		if(stack[0] == "Error") stack.shift();
		var m = [];
		var rie10 = new EReg("^   at ([A-Za-z0-9_. ]+) \\(([^)]+):([0-9]+):([0-9]+)\\)$","");
		var _g = 0;
		while(_g < stack.length) {
			var line = stack[_g];
			++_g;
			if(rie10.match(line)) {
				var path = rie10.matched(1).split(".");
				var meth = path.pop();
				var file = rie10.matched(2);
				var line1 = Std.parseInt(rie10.matched(3));
				m.push(haxe_StackItem.FilePos(meth == "Anonymous function"?haxe_StackItem.LocalFunction():meth == "Global code"?null:haxe_StackItem.Method(path.join("."),meth),file,line1));
			} else m.push(haxe_StackItem.Module(StringTools.trim(line)));
		}
		return m;
	} else return s;
};
var haxe_IMap = function() { };
haxe_IMap.__name__ = true;
haxe_IMap.prototype = {
	__class__: haxe_IMap
};
var haxe__$Int64__$_$_$Int64 = function(high,low) {
	this.high = high;
	this.low = low;
};
haxe__$Int64__$_$_$Int64.__name__ = true;
haxe__$Int64__$_$_$Int64.prototype = {
	__class__: haxe__$Int64__$_$_$Int64
};
var haxe_Log = function() { };
haxe_Log.__name__ = true;
haxe_Log.trace = function(v,infos) {
	js_Boot.__trace(v,infos);
};
var haxe_Resource = function() { };
haxe_Resource.__name__ = true;
haxe_Resource.getString = function(name) {
	var _g = 0;
	var _g1 = haxe_Resource.content;
	while(_g < _g1.length) {
		var x = _g1[_g];
		++_g;
		if(x.name == name) {
			if(x.str != null) return x.str;
			var b = haxe_crypto_Base64.decode(x.data);
			return b.toString();
		}
	}
	return null;
};
haxe_Resource.getBytes = function(name) {
	var _g = 0;
	var _g1 = haxe_Resource.content;
	while(_g < _g1.length) {
		var x = _g1[_g];
		++_g;
		if(x.name == name) {
			if(x.str != null) return haxe_io_Bytes.ofString(x.str);
			return haxe_crypto_Base64.decode(x.data);
		}
	}
	return null;
};
var haxe_Timer = function() { };
haxe_Timer.__name__ = true;
haxe_Timer.stamp = function() {
	return new Date().getTime() / 1000;
};
var haxe_Utf8 = function(size) {
	this.__b = "";
};
haxe_Utf8.__name__ = true;
haxe_Utf8.prototype = {
	__class__: haxe_Utf8
};
var haxe_io_Bytes = function(data) {
	this.length = data.byteLength;
	this.b = new Uint8Array(data);
	data.hxBytes = this;
	data.bytes = this.b;
};
haxe_io_Bytes.__name__ = true;
haxe_io_Bytes.alloc = function(length) {
	return new haxe_io_Bytes(new ArrayBuffer(length));
};
haxe_io_Bytes.ofString = function(s) {
	var a = [];
	var i = 0;
	while(i < s.length) {
		var c = StringTools.fastCodeAt(s,i++);
		if(55296 <= c && c <= 56319) c = c - 55232 << 10 | StringTools.fastCodeAt(s,i++) & 1023;
		if(c <= 127) a.push(c); else if(c <= 2047) {
			a.push(192 | c >> 6);
			a.push(128 | c & 63);
		} else if(c <= 65535) {
			a.push(224 | c >> 12);
			a.push(128 | c >> 6 & 63);
			a.push(128 | c & 63);
		} else {
			a.push(240 | c >> 18);
			a.push(128 | c >> 12 & 63);
			a.push(128 | c >> 6 & 63);
			a.push(128 | c & 63);
		}
	}
	return new haxe_io_Bytes(new Uint8Array(a).buffer);
};
haxe_io_Bytes.prototype = {
	get: function(pos) {
		return this.b[pos];
	}
	,set: function(pos,v) {
		this.b[pos] = v & 255;
	}
	,blit: function(pos,src,srcpos,len) {
		if(pos < 0 || srcpos < 0 || len < 0 || pos + len > this.length || srcpos + len > src.length) throw new js__$Boot_HaxeError(haxe_io_Error.OutsideBounds);
		if(srcpos == 0 && len == src.length) this.b.set(src.b,pos); else this.b.set(src.b.subarray(srcpos,srcpos + len),pos);
	}
	,getString: function(pos,len) {
		if(pos < 0 || len < 0 || pos + len > this.length) throw new js__$Boot_HaxeError(haxe_io_Error.OutsideBounds);
		var s = "";
		var b = this.b;
		var fcc = String.fromCharCode;
		var i = pos;
		var max = pos + len;
		while(i < max) {
			var c = b[i++];
			if(c < 128) {
				if(c == 0) break;
				s += fcc(c);
			} else if(c < 224) s += fcc((c & 63) << 6 | b[i++] & 127); else if(c < 240) {
				var c2 = b[i++];
				s += fcc((c & 31) << 12 | (c2 & 127) << 6 | b[i++] & 127);
			} else {
				var c21 = b[i++];
				var c3 = b[i++];
				var u = (c & 15) << 18 | (c21 & 127) << 12 | (c3 & 127) << 6 | b[i++] & 127;
				s += fcc((u >> 10) + 55232);
				s += fcc(u & 1023 | 56320);
			}
		}
		return s;
	}
	,toString: function() {
		return this.getString(0,this.length);
	}
	,__class__: haxe_io_Bytes
};
var haxe_crypto_Base64 = function() { };
haxe_crypto_Base64.__name__ = true;
haxe_crypto_Base64.decode = function(str,complement) {
	if(complement == null) complement = true;
	if(complement) while(HxOverrides.cca(str,str.length - 1) == 61) str = HxOverrides.substr(str,0,-1);
	return new haxe_crypto_BaseCode(haxe_crypto_Base64.BYTES).decodeBytes(haxe_io_Bytes.ofString(str));
};
var haxe_crypto_BaseCode = function(base) {
	var len = base.length;
	var nbits = 1;
	while(len > 1 << nbits) nbits++;
	if(nbits > 8 || len != 1 << nbits) throw new js__$Boot_HaxeError("BaseCode : base length must be a power of two.");
	this.base = base;
	this.nbits = nbits;
};
haxe_crypto_BaseCode.__name__ = true;
haxe_crypto_BaseCode.prototype = {
	initTable: function() {
		var tbl = [];
		var _g = 0;
		while(_g < 256) {
			var i = _g++;
			tbl[i] = -1;
		}
		var _g1 = 0;
		var _g2 = this.base.length;
		while(_g1 < _g2) {
			var i1 = _g1++;
			tbl[this.base.b[i1]] = i1;
		}
		this.tbl = tbl;
	}
	,decodeBytes: function(b) {
		var nbits = this.nbits;
		var base = this.base;
		if(this.tbl == null) this.initTable();
		var tbl = this.tbl;
		var size = b.length * nbits >> 3;
		var out = haxe_io_Bytes.alloc(size);
		var buf = 0;
		var curbits = 0;
		var pin = 0;
		var pout = 0;
		while(pout < size) {
			while(curbits < 8) {
				curbits += nbits;
				buf <<= nbits;
				var i = tbl[b.get(pin++)];
				if(i == -1) throw new js__$Boot_HaxeError("BaseCode : invalid encoded char");
				buf |= i;
			}
			curbits -= 8;
			out.set(pout++,buf >> curbits & 255);
		}
		return out;
	}
	,__class__: haxe_crypto_BaseCode
};
var haxe_crypto_Crc32 = function() {
	this.crc = -1;
};
haxe_crypto_Crc32.__name__ = true;
haxe_crypto_Crc32.prototype = {
	'byte': function(b) {
		var tmp = (this.crc ^ b) & 255;
		var _g = 0;
		while(_g < 8) {
			var j = _g++;
			if((tmp & 1) == 1) tmp = tmp >>> 1 ^ -306674912; else tmp >>>= 1;
		}
		this.crc = this.crc >>> 8 ^ tmp;
	}
	,update: function(b,pos,len) {
		var b1 = b.b.buffer;
		var _g1 = pos;
		var _g = pos + len;
		while(_g1 < _g) {
			var i = _g1++;
			var tmp = (this.crc ^ b1.bytes[i]) & 255;
			var _g2 = 0;
			while(_g2 < 8) {
				var j = _g2++;
				if((tmp & 1) == 1) tmp = tmp >>> 1 ^ -306674912; else tmp >>>= 1;
			}
			this.crc = this.crc >>> 8 ^ tmp;
		}
	}
	,get: function() {
		return this.crc ^ -1;
	}
	,__class__: haxe_crypto_Crc32
};
var haxe_crypto_Md5 = function() {
};
haxe_crypto_Md5.__name__ = true;
haxe_crypto_Md5.encode = function(s) {
	var m = new haxe_crypto_Md5();
	var h = m.doEncode(haxe_crypto_Md5.str2blks(s));
	return m.hex(h);
};
haxe_crypto_Md5.str2blks = function(str) {
	var nblk = (str.length + 8 >> 6) + 1;
	var blks = [];
	var blksSize = nblk * 16;
	var _g = 0;
	while(_g < blksSize) {
		var i1 = _g++;
		blks[i1] = 0;
	}
	var i = 0;
	while(i < str.length) {
		blks[i >> 2] |= HxOverrides.cca(str,i) << (str.length * 8 + i) % 4 * 8;
		i++;
	}
	blks[i >> 2] |= 128 << (str.length * 8 + i) % 4 * 8;
	var l = str.length * 8;
	var k = nblk * 16 - 2;
	blks[k] = l & 255;
	blks[k] |= (l >>> 8 & 255) << 8;
	blks[k] |= (l >>> 16 & 255) << 16;
	blks[k] |= (l >>> 24 & 255) << 24;
	return blks;
};
haxe_crypto_Md5.prototype = {
	bitOR: function(a,b) {
		var lsb = a & 1 | b & 1;
		var msb31 = a >>> 1 | b >>> 1;
		return msb31 << 1 | lsb;
	}
	,bitXOR: function(a,b) {
		var lsb = a & 1 ^ b & 1;
		var msb31 = a >>> 1 ^ b >>> 1;
		return msb31 << 1 | lsb;
	}
	,bitAND: function(a,b) {
		var lsb = a & 1 & (b & 1);
		var msb31 = a >>> 1 & b >>> 1;
		return msb31 << 1 | lsb;
	}
	,addme: function(x,y) {
		var lsw = (x & 65535) + (y & 65535);
		var msw = (x >> 16) + (y >> 16) + (lsw >> 16);
		return msw << 16 | lsw & 65535;
	}
	,hex: function(a) {
		var str = "";
		var hex_chr = "0123456789abcdef";
		var _g = 0;
		while(_g < a.length) {
			var num = a[_g];
			++_g;
			var _g1 = 0;
			while(_g1 < 4) {
				var j = _g1++;
				str += hex_chr.charAt(num >> j * 8 + 4 & 15) + hex_chr.charAt(num >> j * 8 & 15);
			}
		}
		return str;
	}
	,rol: function(num,cnt) {
		return num << cnt | num >>> 32 - cnt;
	}
	,cmn: function(q,a,b,x,s,t) {
		return this.addme(this.rol(this.addme(this.addme(a,q),this.addme(x,t)),s),b);
	}
	,ff: function(a,b,c,d,x,s,t) {
		return this.cmn(this.bitOR(this.bitAND(b,c),this.bitAND(~b,d)),a,b,x,s,t);
	}
	,gg: function(a,b,c,d,x,s,t) {
		return this.cmn(this.bitOR(this.bitAND(b,d),this.bitAND(c,~d)),a,b,x,s,t);
	}
	,hh: function(a,b,c,d,x,s,t) {
		return this.cmn(this.bitXOR(this.bitXOR(b,c),d),a,b,x,s,t);
	}
	,ii: function(a,b,c,d,x,s,t) {
		return this.cmn(this.bitXOR(c,this.bitOR(b,~d)),a,b,x,s,t);
	}
	,doEncode: function(x) {
		var a = 1732584193;
		var b = -271733879;
		var c = -1732584194;
		var d = 271733878;
		var step;
		var i = 0;
		while(i < x.length) {
			var olda = a;
			var oldb = b;
			var oldc = c;
			var oldd = d;
			step = 0;
			a = this.ff(a,b,c,d,x[i],7,-680876936);
			d = this.ff(d,a,b,c,x[i + 1],12,-389564586);
			c = this.ff(c,d,a,b,x[i + 2],17,606105819);
			b = this.ff(b,c,d,a,x[i + 3],22,-1044525330);
			a = this.ff(a,b,c,d,x[i + 4],7,-176418897);
			d = this.ff(d,a,b,c,x[i + 5],12,1200080426);
			c = this.ff(c,d,a,b,x[i + 6],17,-1473231341);
			b = this.ff(b,c,d,a,x[i + 7],22,-45705983);
			a = this.ff(a,b,c,d,x[i + 8],7,1770035416);
			d = this.ff(d,a,b,c,x[i + 9],12,-1958414417);
			c = this.ff(c,d,a,b,x[i + 10],17,-42063);
			b = this.ff(b,c,d,a,x[i + 11],22,-1990404162);
			a = this.ff(a,b,c,d,x[i + 12],7,1804603682);
			d = this.ff(d,a,b,c,x[i + 13],12,-40341101);
			c = this.ff(c,d,a,b,x[i + 14],17,-1502002290);
			b = this.ff(b,c,d,a,x[i + 15],22,1236535329);
			a = this.gg(a,b,c,d,x[i + 1],5,-165796510);
			d = this.gg(d,a,b,c,x[i + 6],9,-1069501632);
			c = this.gg(c,d,a,b,x[i + 11],14,643717713);
			b = this.gg(b,c,d,a,x[i],20,-373897302);
			a = this.gg(a,b,c,d,x[i + 5],5,-701558691);
			d = this.gg(d,a,b,c,x[i + 10],9,38016083);
			c = this.gg(c,d,a,b,x[i + 15],14,-660478335);
			b = this.gg(b,c,d,a,x[i + 4],20,-405537848);
			a = this.gg(a,b,c,d,x[i + 9],5,568446438);
			d = this.gg(d,a,b,c,x[i + 14],9,-1019803690);
			c = this.gg(c,d,a,b,x[i + 3],14,-187363961);
			b = this.gg(b,c,d,a,x[i + 8],20,1163531501);
			a = this.gg(a,b,c,d,x[i + 13],5,-1444681467);
			d = this.gg(d,a,b,c,x[i + 2],9,-51403784);
			c = this.gg(c,d,a,b,x[i + 7],14,1735328473);
			b = this.gg(b,c,d,a,x[i + 12],20,-1926607734);
			a = this.hh(a,b,c,d,x[i + 5],4,-378558);
			d = this.hh(d,a,b,c,x[i + 8],11,-2022574463);
			c = this.hh(c,d,a,b,x[i + 11],16,1839030562);
			b = this.hh(b,c,d,a,x[i + 14],23,-35309556);
			a = this.hh(a,b,c,d,x[i + 1],4,-1530992060);
			d = this.hh(d,a,b,c,x[i + 4],11,1272893353);
			c = this.hh(c,d,a,b,x[i + 7],16,-155497632);
			b = this.hh(b,c,d,a,x[i + 10],23,-1094730640);
			a = this.hh(a,b,c,d,x[i + 13],4,681279174);
			d = this.hh(d,a,b,c,x[i],11,-358537222);
			c = this.hh(c,d,a,b,x[i + 3],16,-722521979);
			b = this.hh(b,c,d,a,x[i + 6],23,76029189);
			a = this.hh(a,b,c,d,x[i + 9],4,-640364487);
			d = this.hh(d,a,b,c,x[i + 12],11,-421815835);
			c = this.hh(c,d,a,b,x[i + 15],16,530742520);
			b = this.hh(b,c,d,a,x[i + 2],23,-995338651);
			a = this.ii(a,b,c,d,x[i],6,-198630844);
			d = this.ii(d,a,b,c,x[i + 7],10,1126891415);
			c = this.ii(c,d,a,b,x[i + 14],15,-1416354905);
			b = this.ii(b,c,d,a,x[i + 5],21,-57434055);
			a = this.ii(a,b,c,d,x[i + 12],6,1700485571);
			d = this.ii(d,a,b,c,x[i + 3],10,-1894986606);
			c = this.ii(c,d,a,b,x[i + 10],15,-1051523);
			b = this.ii(b,c,d,a,x[i + 1],21,-2054922799);
			a = this.ii(a,b,c,d,x[i + 8],6,1873313359);
			d = this.ii(d,a,b,c,x[i + 15],10,-30611744);
			c = this.ii(c,d,a,b,x[i + 6],15,-1560198380);
			b = this.ii(b,c,d,a,x[i + 13],21,1309151649);
			a = this.ii(a,b,c,d,x[i + 4],6,-145523070);
			d = this.ii(d,a,b,c,x[i + 11],10,-1120210379);
			c = this.ii(c,d,a,b,x[i + 2],15,718787259);
			b = this.ii(b,c,d,a,x[i + 9],21,-343485551);
			a = this.addme(a,olda);
			b = this.addme(b,oldb);
			c = this.addme(c,oldc);
			d = this.addme(d,oldd);
			i += 16;
		}
		return [a,b,c,d];
	}
	,__class__: haxe_crypto_Md5
};
var haxe_ds_IntMap = function() {
	this.h = { };
};
haxe_ds_IntMap.__name__ = true;
haxe_ds_IntMap.__interfaces__ = [haxe_IMap];
haxe_ds_IntMap.prototype = {
	set: function(key,value) {
		this.h[key] = value;
	}
	,get: function(key) {
		return this.h[key];
	}
	,exists: function(key) {
		return this.h.hasOwnProperty(key);
	}
	,remove: function(key) {
		if(!this.h.hasOwnProperty(key)) return false;
		delete(this.h[key]);
		return true;
	}
	,keys: function() {
		var a = [];
		for( var key in this.h ) {
		if(this.h.hasOwnProperty(key)) a.push(key | 0);
		}
		return HxOverrides.iter(a);
	}
	,iterator: function() {
		return { ref : this.h, it : this.keys(), hasNext : function() {
			return this.it.hasNext();
		}, next : function() {
			var i = this.it.next();
			return this.ref[i];
		}};
	}
	,__class__: haxe_ds_IntMap
};
var haxe_ds_ObjectMap = function() {
	this.h = { };
	this.h.__keys__ = { };
};
haxe_ds_ObjectMap.__name__ = true;
haxe_ds_ObjectMap.__interfaces__ = [haxe_IMap];
haxe_ds_ObjectMap.prototype = {
	set: function(key,value) {
		var id = key.__id__ || (key.__id__ = ++haxe_ds_ObjectMap.count);
		this.h[id] = value;
		this.h.__keys__[id] = key;
	}
	,get: function(key) {
		return this.h[key.__id__];
	}
	,exists: function(key) {
		return this.h.__keys__[key.__id__] != null;
	}
	,remove: function(key) {
		var id = key.__id__;
		if(this.h.__keys__[id] == null) return false;
		delete(this.h[id]);
		delete(this.h.__keys__[id]);
		return true;
	}
	,keys: function() {
		var a = [];
		for( var key in this.h.__keys__ ) {
		if(this.h.hasOwnProperty(key)) a.push(this.h.__keys__[key]);
		}
		return HxOverrides.iter(a);
	}
	,iterator: function() {
		return { ref : this.h, it : this.keys(), hasNext : function() {
			return this.it.hasNext();
		}, next : function() {
			var i = this.it.next();
			return this.ref[i.__id__];
		}};
	}
	,__class__: haxe_ds_ObjectMap
};
var haxe_ds__$StringMap_StringMapIterator = function(map,keys) {
	this.map = map;
	this.keys = keys;
	this.index = 0;
	this.count = keys.length;
};
haxe_ds__$StringMap_StringMapIterator.__name__ = true;
haxe_ds__$StringMap_StringMapIterator.prototype = {
	hasNext: function() {
		return this.index < this.count;
	}
	,next: function() {
		return this.map.get(this.keys[this.index++]);
	}
	,__class__: haxe_ds__$StringMap_StringMapIterator
};
var haxe_ds_StringMap = function() {
	this.h = { };
};
haxe_ds_StringMap.__name__ = true;
haxe_ds_StringMap.__interfaces__ = [haxe_IMap];
haxe_ds_StringMap.prototype = {
	set: function(key,value) {
		if(__map_reserved[key] != null) this.setReserved(key,value); else this.h[key] = value;
	}
	,get: function(key) {
		if(__map_reserved[key] != null) return this.getReserved(key);
		return this.h[key];
	}
	,exists: function(key) {
		if(__map_reserved[key] != null) return this.existsReserved(key);
		return this.h.hasOwnProperty(key);
	}
	,setReserved: function(key,value) {
		if(this.rh == null) this.rh = { };
		this.rh["$" + key] = value;
	}
	,getReserved: function(key) {
		if(this.rh == null) return null; else return this.rh["$" + key];
	}
	,existsReserved: function(key) {
		if(this.rh == null) return false;
		return this.rh.hasOwnProperty("$" + key);
	}
	,remove: function(key) {
		if(__map_reserved[key] != null) {
			key = "$" + key;
			if(this.rh == null || !this.rh.hasOwnProperty(key)) return false;
			delete(this.rh[key]);
			return true;
		} else {
			if(!this.h.hasOwnProperty(key)) return false;
			delete(this.h[key]);
			return true;
		}
	}
	,keys: function() {
		var _this = this.arrayKeys();
		return HxOverrides.iter(_this);
	}
	,arrayKeys: function() {
		var out = [];
		for( var key in this.h ) {
		if(this.h.hasOwnProperty(key)) out.push(key);
		}
		if(this.rh != null) {
			for( var key in this.rh ) {
			if(key.charCodeAt(0) == 36) out.push(key.substr(1));
			}
		}
		return out;
	}
	,iterator: function() {
		return new haxe_ds__$StringMap_StringMapIterator(this,this.arrayKeys());
	}
	,__class__: haxe_ds_StringMap
};
var haxe_io_BytesBuffer = function() {
	this.b = [];
};
haxe_io_BytesBuffer.__name__ = true;
haxe_io_BytesBuffer.prototype = {
	add: function(src) {
		var b1 = this.b;
		var b2 = src.b;
		var _g1 = 0;
		var _g = src.length;
		while(_g1 < _g) {
			var i = _g1++;
			this.b.push(b2[i]);
		}
	}
	,addBytes: function(src,pos,len) {
		if(pos < 0 || len < 0 || pos + len > src.length) throw new js__$Boot_HaxeError(haxe_io_Error.OutsideBounds);
		var b1 = this.b;
		var b2 = src.b;
		var _g1 = pos;
		var _g = pos + len;
		while(_g1 < _g) {
			var i = _g1++;
			this.b.push(b2[i]);
		}
	}
	,getBytes: function() {
		var bytes = new haxe_io_Bytes(new Uint8Array(this.b).buffer);
		this.b = null;
		return bytes;
	}
	,__class__: haxe_io_BytesBuffer
};
var haxe_io_Input = function() { };
haxe_io_Input.__name__ = true;
haxe_io_Input.prototype = {
	readByte: function() {
		throw new js__$Boot_HaxeError("Not implemented");
	}
	,readBytes: function(s,pos,len) {
		var k = len;
		var b = s.b;
		if(pos < 0 || len < 0 || pos + len > s.length) throw new js__$Boot_HaxeError(haxe_io_Error.OutsideBounds);
		while(k > 0) {
			b[pos] = this.readByte();
			pos++;
			k--;
		}
		return len;
	}
	,set_bigEndian: function(b) {
		this.bigEndian = b;
		return b;
	}
	,readFullBytes: function(s,pos,len) {
		while(len > 0) {
			var k = this.readBytes(s,pos,len);
			pos += k;
			len -= k;
		}
	}
	,read: function(nbytes) {
		var s = haxe_io_Bytes.alloc(nbytes);
		var p = 0;
		while(nbytes > 0) {
			var k = this.readBytes(s,p,nbytes);
			if(k == 0) throw new js__$Boot_HaxeError(haxe_io_Error.Blocked);
			p += k;
			nbytes -= k;
		}
		return s;
	}
	,readUInt16: function() {
		var ch1 = this.readByte();
		var ch2 = this.readByte();
		if(this.bigEndian) return ch2 | ch1 << 8; else return ch1 | ch2 << 8;
	}
	,readInt32: function() {
		var ch1 = this.readByte();
		var ch2 = this.readByte();
		var ch3 = this.readByte();
		var ch4 = this.readByte();
		if(this.bigEndian) return ch4 | ch3 << 8 | ch2 << 16 | ch1 << 24; else return ch1 | ch2 << 8 | ch3 << 16 | ch4 << 24;
	}
	,readString: function(len) {
		var b = haxe_io_Bytes.alloc(len);
		this.readFullBytes(b,0,len);
		return b.toString();
	}
	,__class__: haxe_io_Input
	,__properties__: {set_bigEndian:"set_bigEndian"}
};
var haxe_io_BytesInput = function(b,pos,len) {
	if(pos == null) pos = 0;
	if(len == null) len = b.length - pos;
	if(pos < 0 || len < 0 || pos + len > b.length) throw new js__$Boot_HaxeError(haxe_io_Error.OutsideBounds);
	this.b = b.b;
	this.pos = pos;
	this.len = len;
	this.totlen = len;
};
haxe_io_BytesInput.__name__ = true;
haxe_io_BytesInput.__super__ = haxe_io_Input;
haxe_io_BytesInput.prototype = $extend(haxe_io_Input.prototype,{
	readByte: function() {
		if(this.len == 0) throw new js__$Boot_HaxeError(new haxe_io_Eof());
		this.len--;
		return this.b[this.pos++];
	}
	,readBytes: function(buf,pos,len) {
		if(pos < 0 || len < 0 || pos + len > buf.length) throw new js__$Boot_HaxeError(haxe_io_Error.OutsideBounds);
		if(this.len == 0 && len > 0) throw new js__$Boot_HaxeError(new haxe_io_Eof());
		if(this.len < len) len = this.len;
		var b1 = this.b;
		var b2 = buf.b;
		var _g = 0;
		while(_g < len) {
			var i = _g++;
			b2[pos + i] = b1[this.pos + i];
		}
		this.pos += len;
		this.len -= len;
		return len;
	}
	,__class__: haxe_io_BytesInput
});
var haxe_io_Eof = function() {
};
haxe_io_Eof.__name__ = true;
haxe_io_Eof.prototype = {
	toString: function() {
		return "Eof";
	}
	,__class__: haxe_io_Eof
};
var haxe_io_Error = { __ename__ : true, __constructs__ : ["Blocked","Overflow","OutsideBounds","Custom"] };
haxe_io_Error.Blocked = ["Blocked",0];
haxe_io_Error.Blocked.toString = $estr;
haxe_io_Error.Blocked.__enum__ = haxe_io_Error;
haxe_io_Error.Overflow = ["Overflow",1];
haxe_io_Error.Overflow.toString = $estr;
haxe_io_Error.Overflow.__enum__ = haxe_io_Error;
haxe_io_Error.OutsideBounds = ["OutsideBounds",2];
haxe_io_Error.OutsideBounds.toString = $estr;
haxe_io_Error.OutsideBounds.__enum__ = haxe_io_Error;
haxe_io_Error.Custom = function(e) { var $x = ["Custom",3,e]; $x.__enum__ = haxe_io_Error; $x.toString = $estr; return $x; };
var haxe_io_FPHelper = function() { };
haxe_io_FPHelper.__name__ = true;
haxe_io_FPHelper.i32ToFloat = function(i) {
	var sign = 1 - (i >>> 31 << 1);
	var exp = i >>> 23 & 255;
	var sig = i & 8388607;
	if(sig == 0 && exp == 0) return 0.0;
	return sign * (1 + Math.pow(2,-23) * sig) * Math.pow(2,exp - 127);
};
haxe_io_FPHelper.floatToI32 = function(f) {
	if(f == 0) return 0;
	var af;
	if(f < 0) af = -f; else af = f;
	var exp = Math.floor(Math.log(af) / 0.6931471805599453);
	if(exp < -127) exp = -127; else if(exp > 128) exp = 128;
	var sig = Math.round((af / Math.pow(2,exp) - 1) * 8388608) & 8388607;
	return (f < 0?-2147483648:0) | exp + 127 << 23 | sig;
};
haxe_io_FPHelper.i64ToDouble = function(low,high) {
	var sign = 1 - (high >>> 31 << 1);
	var exp = (high >> 20 & 2047) - 1023;
	var sig = (high & 1048575) * 4294967296. + (low >>> 31) * 2147483648. + (low & 2147483647);
	if(sig == 0 && exp == -1023) return 0.0;
	return sign * (1.0 + Math.pow(2,-52) * sig) * Math.pow(2,exp);
};
haxe_io_FPHelper.doubleToI64 = function(v) {
	var i64 = haxe_io_FPHelper.i64tmp;
	if(v == 0) {
		i64.low = 0;
		i64.high = 0;
	} else {
		var av;
		if(v < 0) av = -v; else av = v;
		var exp = Math.floor(Math.log(av) / 0.6931471805599453);
		var sig;
		var v1 = (av / Math.pow(2,exp) - 1) * 4503599627370496.;
		sig = Math.round(v1);
		var sig_l = sig | 0;
		var sig_h = sig / 4294967296.0 | 0;
		i64.low = sig_l;
		i64.high = (v < 0?-2147483648:0) | exp + 1023 << 20 | sig_h;
	}
	return i64;
};
var haxe_io_Path = function(path) {
	switch(path) {
	case ".":case "..":
		this.dir = path;
		this.file = "";
		return;
	}
	var c1 = path.lastIndexOf("/");
	var c2 = path.lastIndexOf("\\");
	if(c1 < c2) {
		this.dir = HxOverrides.substr(path,0,c2);
		path = HxOverrides.substr(path,c2 + 1,null);
		this.backslash = true;
	} else if(c2 < c1) {
		this.dir = HxOverrides.substr(path,0,c1);
		path = HxOverrides.substr(path,c1 + 1,null);
	} else this.dir = null;
	var cp = path.lastIndexOf(".");
	if(cp != -1) {
		this.ext = HxOverrides.substr(path,cp + 1,null);
		this.file = HxOverrides.substr(path,0,cp);
	} else {
		this.ext = null;
		this.file = path;
	}
};
haxe_io_Path.__name__ = true;
haxe_io_Path.directory = function(path) {
	var s = new haxe_io_Path(path);
	if(s.dir == null) return "";
	return s.dir;
};
haxe_io_Path.extension = function(path) {
	var s = new haxe_io_Path(path);
	if(s.ext == null) return "";
	return s.ext;
};
haxe_io_Path.join = function(paths) {
	var paths1 = paths.filter(function(s) {
		return s != null && s != "";
	});
	if(paths1.length == 0) return "";
	var path = paths1[0];
	var _g1 = 1;
	var _g = paths1.length;
	while(_g1 < _g) {
		var i = _g1++;
		path = haxe_io_Path.addTrailingSlash(path);
		path += paths1[i];
	}
	return haxe_io_Path.normalize(path);
};
haxe_io_Path.normalize = function(path) {
	var slash = "/";
	path = path.split("\\").join("/");
	if(path == null || path == slash) return slash;
	var target = [];
	var _g = 0;
	var _g1 = path.split(slash);
	while(_g < _g1.length) {
		var token = _g1[_g];
		++_g;
		if(token == ".." && target.length > 0 && target[target.length - 1] != "..") target.pop(); else if(token != ".") target.push(token);
	}
	var tmp = target.join(slash);
	var regex = new EReg("([^:])/+","g");
	var result = regex.replace(tmp,"$1" + slash);
	var acc = new StringBuf();
	var colon = false;
	var slashes = false;
	var _g11 = 0;
	var _g2 = tmp.length;
	while(_g11 < _g2) {
		var i = _g11++;
		var _g21 = HxOverrides.cca(tmp,i);
		var i1 = _g21;
		if(_g21 != null) switch(_g21) {
		case 58:
			acc.b += ":";
			colon = true;
			break;
		case 47:
			if(colon == false) slashes = true; else {
				colon = false;
				if(slashes) {
					acc.b += "/";
					slashes = false;
				}
				acc.add(String.fromCharCode(i1));
			}
			break;
		default:
			colon = false;
			if(slashes) {
				acc.b += "/";
				slashes = false;
			}
			acc.add(String.fromCharCode(i1));
		} else {
			colon = false;
			if(slashes) {
				acc.b += "/";
				slashes = false;
			}
			acc.add(String.fromCharCode(i1));
		}
	}
	var result1 = acc.b;
	return result1;
};
haxe_io_Path.addTrailingSlash = function(path) {
	if(path.length == 0) return "/";
	var c1 = path.lastIndexOf("/");
	var c2 = path.lastIndexOf("\\");
	if(c1 < c2) {
		if(c2 != path.length - 1) return path + "\\"; else return path;
	} else if(c1 != path.length - 1) return path + "/"; else return path;
};
haxe_io_Path.prototype = {
	__class__: haxe_io_Path
};
var hxDaedalus_ai_EntityAI = function() {
	this._radius = 10;
	this.x = this.y = 0;
	this.dirNormX = 1;
	this.dirNormY = 0;
};
hxDaedalus_ai_EntityAI.__name__ = true;
hxDaedalus_ai_EntityAI.prototype = {
	buildApproximation: function() {
		this._approximateObject = new hxDaedalus_data_Object();
		this._approximateObject.get_matrix().translate(this.x,this.y);
		var coordinates = [];
		this._approximateObject.set_coordinates(coordinates);
		if(this._radius == 0) return;
		var _g = 0;
		while(_g < 6) {
			var i = _g++;
			coordinates.push(this._radius * Math.cos(2 * Math.PI * i / 6));
			coordinates.push(this._radius * Math.sin(2 * Math.PI * i / 6));
			coordinates.push(this._radius * Math.cos(2 * Math.PI * (i + 1) / 6));
			coordinates.push(this._radius * Math.sin(2 * Math.PI * (i + 1) / 6));
		}
	}
	,get_approximateObject: function() {
		this._approximateObject.get_matrix().identity();
		this._approximateObject.get_matrix().translate(this.x,this.y);
		return this._approximateObject;
	}
	,get_radius: function() {
		return this._radius;
	}
	,get_radiusSquared: function() {
		return this._radiusSquared;
	}
	,set_radius: function(value) {
		this._radius = value;
		this._radiusSquared = this._radius * this._radius;
		return value;
	}
	,__class__: hxDaedalus_ai_EntityAI
	,__properties__: {get_radiusSquared:"get_radiusSquared",set_radius:"set_radius",get_radius:"get_radius",get_approximateObject:"get_approximateObject"}
};
var hxDaedalus_data_Constants = function() { };
hxDaedalus_data_Constants.__name__ = true;
var hxDaedalus_data_ConstraintSegment = function() {
	this._id = hxDaedalus_data_ConstraintSegment.INC;
	hxDaedalus_data_ConstraintSegment.INC++;
	this._edges = [];
};
hxDaedalus_data_ConstraintSegment.__name__ = true;
hxDaedalus_data_ConstraintSegment.prototype = {
	get_id: function() {
		return this._id;
	}
	,addEdge: function(edge) {
		if(HxOverrides.indexOf(this._edges,edge,0) == -1 && (function($this) {
			var $r;
			var x = edge.get_oppositeEdge();
			$r = HxOverrides.indexOf($this._edges,x,0);
			return $r;
		}(this)) == -1) this._edges.push(edge);
	}
	,removeEdge: function(edge) {
		var index;
		index = HxOverrides.indexOf(this._edges,edge,0);
		if(index == -1) {
			var x = edge.get_oppositeEdge();
			index = HxOverrides.indexOf(this._edges,x,0);
		}
		if(index != -1) this._edges.splice(index,1);
	}
	,get_edges: function() {
		return this._edges;
	}
	,dispose: function() {
		this._edges = null;
		this.fromShape = null;
	}
	,toString: function() {
		return "seg_id " + this._id;
	}
	,__class__: hxDaedalus_data_ConstraintSegment
	,__properties__: {get_edges:"get_edges",get_id:"get_id"}
};
var hxDaedalus_data_ConstraintShape = function() {
	this._id = hxDaedalus_data_ConstraintShape.INC;
	hxDaedalus_data_ConstraintShape.INC++;
	this.segments = [];
};
hxDaedalus_data_ConstraintShape.__name__ = true;
hxDaedalus_data_ConstraintShape.prototype = {
	get_id: function() {
		return this._id;
	}
	,dispose: function() {
		while(this.segments.length > 0) this.segments.pop().dispose();
		this.segments = null;
	}
	,__class__: hxDaedalus_data_ConstraintShape
	,__properties__: {get_id:"get_id"}
};
var hxDaedalus_data_Edge = function() {
	this.colorDebug = -1;
	this._id = hxDaedalus_data_Edge.INC;
	hxDaedalus_data_Edge.INC++;
	this.fromConstraintSegments = [];
};
hxDaedalus_data_Edge.__name__ = true;
hxDaedalus_data_Edge.prototype = {
	get_id: function() {
		return this._id;
	}
	,get_isReal: function() {
		return this._isReal;
	}
	,get_isConstrained: function() {
		return this._isConstrained;
	}
	,setDatas: function(originVertex,oppositeEdge,nextLeftEdge,leftFace,isReal,isConstrained) {
		if(isConstrained == null) isConstrained = false;
		if(isReal == null) isReal = true;
		this._isConstrained = isConstrained;
		this._isReal = isReal;
		this._originVertex = originVertex;
		this._oppositeEdge = oppositeEdge;
		this._nextLeftEdge = nextLeftEdge;
		this._leftFace = leftFace;
	}
	,addFromConstraintSegment: function(segment) {
		if(HxOverrides.indexOf(this.fromConstraintSegments,segment,0) == -1) this.fromConstraintSegments.push(segment);
	}
	,removeFromConstraintSegment: function(segment) {
		var index = HxOverrides.indexOf(this.fromConstraintSegments,segment,0);
		if(index != -1) this.fromConstraintSegments.splice(index,1);
	}
	,set_originVertex: function(value) {
		this._originVertex = value;
		return value;
	}
	,set_nextLeftEdge: function(value) {
		this._nextLeftEdge = value;
		return value;
	}
	,set_leftFace: function(value) {
		this._leftFace = value;
		return value;
	}
	,set_isConstrained: function(value) {
		this._isConstrained = value;
		return value;
	}
	,dispose: function() {
		this._originVertex = null;
		this._oppositeEdge = null;
		this._nextLeftEdge = null;
		this._leftFace = null;
		this.fromConstraintSegments = null;
	}
	,get_originVertex: function() {
		return this._originVertex;
	}
	,get_destinationVertex: function() {
		return this.get_oppositeEdge().get_originVertex();
	}
	,get_oppositeEdge: function() {
		return this._oppositeEdge;
	}
	,get_nextLeftEdge: function() {
		return this._nextLeftEdge;
	}
	,get_prevLeftEdge: function() {
		return this._nextLeftEdge.get_nextLeftEdge();
	}
	,get_nextRightEdge: function() {
		return this._oppositeEdge.get_nextLeftEdge().get_nextLeftEdge().get_oppositeEdge();
	}
	,get_prevRightEdge: function() {
		return this._oppositeEdge.get_nextLeftEdge().get_oppositeEdge();
	}
	,get_rotLeftEdge: function() {
		return this._nextLeftEdge.get_nextLeftEdge().get_oppositeEdge();
	}
	,get_rotRightEdge: function() {
		return this._oppositeEdge.get_nextLeftEdge();
	}
	,get_leftFace: function() {
		return this._leftFace;
	}
	,get_rightFace: function() {
		return this._oppositeEdge.get_leftFace();
	}
	,toString: function() {
		return "edge " + this.get_originVertex().get_id() + " - " + this.get_destinationVertex().get_id();
	}
	,__class__: hxDaedalus_data_Edge
	,__properties__: {get_rightFace:"get_rightFace",get_rotRightEdge:"get_rotRightEdge",get_rotLeftEdge:"get_rotLeftEdge",get_prevRightEdge:"get_prevRightEdge",get_nextRightEdge:"get_nextRightEdge",get_prevLeftEdge:"get_prevLeftEdge",get_oppositeEdge:"get_oppositeEdge",get_destinationVertex:"get_destinationVertex",set_leftFace:"set_leftFace",get_leftFace:"get_leftFace",set_nextLeftEdge:"set_nextLeftEdge",get_nextLeftEdge:"get_nextLeftEdge",set_originVertex:"set_originVertex",get_originVertex:"get_originVertex",set_isConstrained:"set_isConstrained",get_isConstrained:"get_isConstrained",get_isReal:"get_isReal",get_id:"get_id"}
};
var hxDaedalus_data_Face = function() {
	this.colorDebug = -1;
	this._id = hxDaedalus_data_Face.INC;
	hxDaedalus_data_Face.INC++;
};
hxDaedalus_data_Face.__name__ = true;
hxDaedalus_data_Face.prototype = {
	get_id: function() {
		return this._id;
	}
	,get_isReal: function() {
		return this._isReal;
	}
	,set_datas: function(edge) {
		this._isReal = true;
		this._edge = edge;
	}
	,setDatas: function(edge,isReal) {
		if(isReal == null) isReal = true;
		this._isReal = isReal;
		this._edge = edge;
	}
	,dispose: function() {
		this._edge = null;
	}
	,get_edge: function() {
		return this._edge;
	}
	,__class__: hxDaedalus_data_Face
	,__properties__: {get_edge:"get_edge",get_isReal:"get_isReal",get_id:"get_id"}
};
var hxDaedalus_data_Mesh = function(width,height) {
	this.__objectsUpdateInProgress = false;
	this.__edgesToCheck = null;
	this.__centerVertex = null;
	this._objects = null;
	this._constraintShapes = null;
	this._faces = null;
	this._edges = null;
	this._vertices = null;
	this._clipping = false;
	this._height = 0;
	this._width = 0;
	this._id = hxDaedalus_data_Mesh.INC;
	hxDaedalus_data_Mesh.INC++;
	this._width = width;
	this._height = height;
	this._clipping = true;
	this._vertices = [];
	this._edges = [];
	this._faces = [];
	this._constraintShapes = [];
	this._objects = [];
	this.__edgesToCheck = [];
};
hxDaedalus_data_Mesh.__name__ = true;
hxDaedalus_data_Mesh.prototype = {
	get_height: function() {
		return this._height;
	}
	,get_width: function() {
		return this._width;
	}
	,get_clipping: function() {
		return this._clipping;
	}
	,set_clipping: function(value) {
		this._clipping = value;
		return value;
	}
	,get_id: function() {
		return this._id;
	}
	,dispose: function() {
		while(this._vertices.length > 0) this._vertices.pop().dispose();
		this._vertices = null;
		while(this._edges.length > 0) this._edges.pop().dispose();
		this._edges = null;
		while(this._faces.length > 0) this._faces.pop().dispose();
		this._faces = null;
		while(this._constraintShapes.length > 0) this._constraintShapes.pop().dispose();
		this._constraintShapes = null;
		while(this._objects.length > 0) this._objects.pop().dispose();
		this._objects = null;
		this.__edgesToCheck = null;
		this.__centerVertex = null;
	}
	,get___constraintShapes: function() {
		return this._constraintShapes;
	}
	,buildFromRecord: function(rec) {
		var positions = rec.split(";");
		var i = 0;
		while(i < positions.length) {
			this.insertConstraintSegment(Std.parseFloat(positions[i]),Std.parseFloat(positions[i + 1]),Std.parseFloat(positions[i + 2]),Std.parseFloat(positions[i + 3]));
			i += 4;
		}
	}
	,insertObject: function(object) {
		if(object.get_constraintShape() != null) this.deleteObject(object);
		var shape = new hxDaedalus_data_ConstraintShape();
		var segment;
		var coordinates = object.get_coordinates();
		var m = object.get_matrix();
		object.updateMatrixFromValues();
		var x1;
		var y1;
		var x2;
		var y2;
		var transfx1;
		var transfy1;
		var transfx2;
		var transfy2;
		var i = 0;
		while(i < coordinates.length) {
			x1 = coordinates[i];
			y1 = coordinates[i + 1];
			x2 = coordinates[i + 2];
			y2 = coordinates[i + 3];
			transfx1 = m.transformX(x1,y1);
			transfy1 = m.transformY(x1,y1);
			transfx2 = m.transformX(x2,y2);
			transfy2 = m.transformY(x2,y2);
			segment = this.insertConstraintSegment(transfx1,transfy1,transfx2,transfy2);
			if(segment != null) {
				segment.fromShape = shape;
				shape.segments.push(segment);
			}
			i += 4;
		}
		this._constraintShapes.push(shape);
		object.set_constraintShape(shape);
		if(!this.__objectsUpdateInProgress) this._objects.push(object);
	}
	,deleteObject: function(object) {
		if(object.get_constraintShape() == null) return;
		this.deleteConstraintShape(object.get_constraintShape());
		object.set_constraintShape(null);
		if(!this.__objectsUpdateInProgress) {
			var index = HxOverrides.indexOf(this._objects,object,0);
			this._objects.splice(index,1);
		}
	}
	,updateObjects: function() {
		this.__objectsUpdateInProgress = true;
		var _g1 = 0;
		var _g = this._objects.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(this._objects[i].get_hasChanged()) {
				this.deleteObject(this._objects[i]);
				this.insertObject(this._objects[i]);
				this._objects[i].set_hasChanged(false);
			}
		}
		this.__objectsUpdateInProgress = false;
	}
	,insertConstraintShape: function(coordinates) {
		var shape = new hxDaedalus_data_ConstraintShape();
		var segment = null;
		var i = 0;
		while(i < coordinates.length) {
			segment = this.insertConstraintSegment(coordinates[i],coordinates[i + 1],coordinates[i + 2],coordinates[i + 3]);
			if(segment != null) {
				segment.fromShape = shape;
				shape.segments.push(segment);
			}
			i += 4;
		}
		this._constraintShapes.push(shape);
		return shape;
	}
	,deleteConstraintShape: function(shape) {
		var _g1 = 0;
		var _g = shape.segments.length;
		while(_g1 < _g) {
			var i = _g1++;
			this.deleteConstraintSegment(shape.segments[i]);
		}
		shape.dispose();
		this._constraintShapes.splice(HxOverrides.indexOf(this._constraintShapes,shape,0),1);
	}
	,insertConstraintSegment: function(x1,y1,x2,y2) {
		var p1pos = this.findPositionFromBounds(x1,y1);
		var p2pos = this.findPositionFromBounds(x2,y2);
		var newX1 = x1;
		var newY1 = y1;
		var newX2 = x2;
		var newY2 = y2;
		if(this._clipping && (p1pos != 0 || p2pos != 0)) {
			var intersectPoint = new hxDaedalus_data_math_Point2D();
			if(p1pos != 0 && p2pos != 0) {
				if(x1 <= 0 && x2 <= 0 || x1 >= this._width && x2 >= this._width || y1 <= 0 && y2 <= 0 || y1 >= this._height && y2 >= this._height) return null;
				if(p1pos == 8 && p2pos == 4 || p1pos == 4 && p2pos == 8) {
					hxDaedalus_data_math_Geom2D.intersections2segments(x1,y1,x2,y2,0,0,0,this._height,intersectPoint);
					newX1 = intersectPoint.x;
					newY1 = intersectPoint.y;
					hxDaedalus_data_math_Geom2D.intersections2segments(x1,y1,x2,y2,this._width,0,this._width,this._height,intersectPoint);
					newX2 = intersectPoint.x;
					newY2 = intersectPoint.y;
				} else if(p1pos == 2 && p2pos == 6 || p1pos == 6 && p2pos == 2) {
					hxDaedalus_data_math_Geom2D.intersections2segments(x1,y1,x2,y2,0,0,this._width,0,intersectPoint);
					newX1 = intersectPoint.x;
					newY1 = intersectPoint.y;
					hxDaedalus_data_math_Geom2D.intersections2segments(x1,y1,x2,y2,0,this._height,this._width,this._height,intersectPoint);
					newX2 = intersectPoint.x;
					newY2 = intersectPoint.y;
				} else if(p1pos == 2 && p2pos == 8 || p1pos == 8 && p2pos == 2) {
					if(hxDaedalus_data_math_Geom2D.intersections2segments(x1,y1,x2,y2,0,0,this._width,0,intersectPoint)) {
						newX1 = intersectPoint.x;
						newY1 = intersectPoint.y;
						hxDaedalus_data_math_Geom2D.intersections2segments(x1,y1,x2,y2,0,0,0,this._height,intersectPoint);
						newX2 = intersectPoint.x;
						newY2 = intersectPoint.y;
					} else return null;
				} else if(p1pos == 2 && p2pos == 4 || p1pos == 4 && p2pos == 2) {
					if(hxDaedalus_data_math_Geom2D.intersections2segments(x1,y1,x2,y2,0,0,this._width,0,intersectPoint)) {
						newX1 = intersectPoint.x;
						newY1 = intersectPoint.y;
						hxDaedalus_data_math_Geom2D.intersections2segments(x1,y1,x2,y2,this._width,0,this._width,this._height,intersectPoint);
						newX2 = intersectPoint.x;
						newY2 = intersectPoint.y;
					} else return null;
				} else if(p1pos == 6 && p2pos == 4 || p1pos == 4 && p2pos == 6) {
					if(hxDaedalus_data_math_Geom2D.intersections2segments(x1,y1,x2,y2,0,this._height,this._width,this._height,intersectPoint)) {
						newX1 = intersectPoint.x;
						newY1 = intersectPoint.y;
						hxDaedalus_data_math_Geom2D.intersections2segments(x1,y1,x2,y2,this._width,0,this._width,this._height,intersectPoint);
						newX2 = intersectPoint.x;
						newY2 = intersectPoint.y;
					} else return null;
				} else if(p1pos == 8 && p2pos == 6 || p1pos == 6 && p2pos == 8) {
					if(hxDaedalus_data_math_Geom2D.intersections2segments(x1,y1,x2,y2,0,this._height,this._width,this._height,intersectPoint)) {
						newX1 = intersectPoint.x;
						newY1 = intersectPoint.y;
						hxDaedalus_data_math_Geom2D.intersections2segments(x1,y1,x2,y2,0,0,0,this._height,intersectPoint);
						newX2 = intersectPoint.x;
						newY2 = intersectPoint.y;
					} else return null;
				} else {
					var firstDone = false;
					var secondDone = false;
					if(hxDaedalus_data_math_Geom2D.intersections2segments(x1,y1,x2,y2,0,0,this._width,0,intersectPoint)) {
						newX1 = intersectPoint.x;
						newY1 = intersectPoint.y;
						firstDone = true;
					}
					if(hxDaedalus_data_math_Geom2D.intersections2segments(x1,y1,x2,y2,this._width,0,this._width,this._height,intersectPoint)) {
						if(!firstDone) {
							newX1 = intersectPoint.x;
							newY1 = intersectPoint.y;
							firstDone = true;
						} else {
							newX2 = intersectPoint.x;
							newY2 = intersectPoint.y;
							secondDone = true;
						}
					}
					if(!secondDone && hxDaedalus_data_math_Geom2D.intersections2segments(x1,y1,x2,y2,0,this._height,this._width,this._height,intersectPoint)) {
						if(!firstDone) {
							newX1 = intersectPoint.x;
							newY1 = intersectPoint.y;
							firstDone = true;
						} else {
							newX2 = intersectPoint.x;
							newY2 = intersectPoint.y;
							secondDone = true;
						}
					}
					if(!secondDone && hxDaedalus_data_math_Geom2D.intersections2segments(x1,y1,x2,y2,0,0,0,this._height,intersectPoint)) {
						newX2 = intersectPoint.x;
						newY2 = intersectPoint.y;
					}
					if(!firstDone) return null;
				}
			} else {
				if(p1pos == 2 || p2pos == 2) hxDaedalus_data_math_Geom2D.intersections2segments(x1,y1,x2,y2,0,0,this._width,0,intersectPoint); else if(p1pos == 4 || p2pos == 4) hxDaedalus_data_math_Geom2D.intersections2segments(x1,y1,x2,y2,this._width,0,this._width,this._height,intersectPoint); else if(p1pos == 6 || p2pos == 6) hxDaedalus_data_math_Geom2D.intersections2segments(x1,y1,x2,y2,0,this._height,this._width,this._height,intersectPoint); else if(p1pos == 8 || p2pos == 8) hxDaedalus_data_math_Geom2D.intersections2segments(x1,y1,x2,y2,0,0,0,this._height,intersectPoint); else if(!hxDaedalus_data_math_Geom2D.intersections2segments(x1,y1,x2,y2,0,0,this._width,0,intersectPoint)) {
					if(!hxDaedalus_data_math_Geom2D.intersections2segments(x1,y1,x2,y2,this._width,0,this._width,this._height,intersectPoint)) {
						if(!hxDaedalus_data_math_Geom2D.intersections2segments(x1,y1,x2,y2,0,this._height,this._width,this._height,intersectPoint)) hxDaedalus_data_math_Geom2D.intersections2segments(x1,y1,x2,y2,0,0,0,this._height,intersectPoint);
					}
				}
				if(p1pos == 0) {
					newX1 = x1;
					newY1 = y1;
				} else {
					newX1 = x2;
					newY1 = y2;
				}
				newX2 = intersectPoint.x;
				newY2 = intersectPoint.y;
			}
		}
		var vertexDown = this.insertVertex(newX1,newY1);
		if(vertexDown == null) return null;
		var vertexUp = this.insertVertex(newX2,newY2);
		if(vertexUp == null) return null;
		if(vertexDown == vertexUp) return null;
		var iterVertexToOutEdges = new hxDaedalus_iterators_FromVertexToOutgoingEdges();
		var currVertex;
		var currEdge;
		var i;
		var segment = new hxDaedalus_data_ConstraintSegment();
		var tempEdgeDownUp = new hxDaedalus_data_Edge();
		var tempSdgeUpDown = new hxDaedalus_data_Edge();
		tempEdgeDownUp.setDatas(vertexDown,tempSdgeUpDown,null,null,true,true);
		tempSdgeUpDown.setDatas(vertexUp,tempEdgeDownUp,null,null,true,true);
		var intersectedEdges = [];
		var leftBoundingEdges = [];
		var rightBoundingEdges = [];
		var currObjet;
		var pIntersect = new hxDaedalus_data_math_Point2D();
		var edgeLeft;
		var newEdgeDownUp;
		var newEdgeUpDown;
		var done;
		currVertex = vertexDown;
		currObjet = hxDaedalus_data_math_Intersection.EVertex(currVertex);
		while(true) {
			done = false;
			switch(currObjet[1]) {
			case 0:
				var vertex = currObjet[2];
				currVertex = vertex;
				iterVertexToOutEdges.set_fromVertex(currVertex);
				while((currEdge = iterVertexToOutEdges.next()) != null) {
					if(currEdge.get_destinationVertex() == vertexUp) {
						if(!currEdge.get_isConstrained()) {
							currEdge.set_isConstrained(true);
							currEdge.get_oppositeEdge().set_isConstrained(true);
						}
						currEdge.addFromConstraintSegment(segment);
						currEdge.get_oppositeEdge().fromConstraintSegments = currEdge.fromConstraintSegments;
						vertexDown.addFromConstraintSegment(segment);
						vertexUp.addFromConstraintSegment(segment);
						segment.addEdge(currEdge);
						return segment;
					}
					if(hxDaedalus_data_math_Geom2D.distanceSquaredVertexToEdge(currEdge.get_destinationVertex(),tempEdgeDownUp) <= 0.0001) {
						if(!currEdge.get_isConstrained()) {
							currEdge.set_isConstrained(true);
							currEdge.get_oppositeEdge().set_isConstrained(true);
						}
						currEdge.addFromConstraintSegment(segment);
						currEdge.get_oppositeEdge().fromConstraintSegments = currEdge.fromConstraintSegments;
						vertexDown.addFromConstraintSegment(segment);
						segment.addEdge(currEdge);
						vertexDown = currEdge.get_destinationVertex();
						tempEdgeDownUp.set_originVertex(vertexDown);
						currObjet = hxDaedalus_data_math_Intersection.EVertex(vertexDown);
						done = true;
						break;
					}
				}
				if(done) continue;
				iterVertexToOutEdges.set_fromVertex(currVertex);
				while((currEdge = iterVertexToOutEdges.next()) != null) {
					currEdge = currEdge.get_nextLeftEdge();
					if(hxDaedalus_data_math_Geom2D.intersections2edges(currEdge,tempEdgeDownUp,pIntersect)) {
						if(currEdge.get_isConstrained()) {
							vertexDown = this.splitEdge(currEdge,pIntersect.x,pIntersect.y);
							iterVertexToOutEdges.set_fromVertex(currVertex);
							while((currEdge = iterVertexToOutEdges.next()) != null) if(currEdge.get_destinationVertex() == vertexDown) {
								currEdge.set_isConstrained(true);
								currEdge.get_oppositeEdge().set_isConstrained(true);
								currEdge.addFromConstraintSegment(segment);
								currEdge.get_oppositeEdge().fromConstraintSegments = currEdge.fromConstraintSegments;
								segment.addEdge(currEdge);
								break;
							}
							currVertex.addFromConstraintSegment(segment);
							tempEdgeDownUp.set_originVertex(vertexDown);
							currObjet = hxDaedalus_data_math_Intersection.EVertex(vertexDown);
						} else {
							intersectedEdges.push(currEdge);
							leftBoundingEdges.unshift(currEdge.get_nextLeftEdge());
							rightBoundingEdges.push(currEdge.get_prevLeftEdge());
							currEdge = currEdge.get_oppositeEdge();
							currObjet = hxDaedalus_data_math_Intersection.EEdge(currEdge);
						}
						break;
					}
				}
				break;
			case 1:
				var edge = currObjet[2];
				currEdge = edge;
				edgeLeft = currEdge.get_nextLeftEdge();
				if(edgeLeft.get_destinationVertex() == vertexUp) {
					leftBoundingEdges.unshift(edgeLeft.get_nextLeftEdge());
					rightBoundingEdges.push(edgeLeft);
					newEdgeDownUp = new hxDaedalus_data_Edge();
					newEdgeUpDown = new hxDaedalus_data_Edge();
					newEdgeDownUp.setDatas(vertexDown,newEdgeUpDown,null,null,true,true);
					newEdgeUpDown.setDatas(vertexUp,newEdgeDownUp,null,null,true,true);
					leftBoundingEdges.push(newEdgeDownUp);
					rightBoundingEdges.push(newEdgeUpDown);
					this.insertNewConstrainedEdge(segment,newEdgeDownUp,intersectedEdges,leftBoundingEdges,rightBoundingEdges);
					return segment;
				} else if(hxDaedalus_data_math_Geom2D.distanceSquaredVertexToEdge(edgeLeft.get_destinationVertex(),tempEdgeDownUp) <= 0.0001) {
					leftBoundingEdges.unshift(edgeLeft.get_nextLeftEdge());
					rightBoundingEdges.push(edgeLeft);
					newEdgeDownUp = new hxDaedalus_data_Edge();
					newEdgeUpDown = new hxDaedalus_data_Edge();
					newEdgeDownUp.setDatas(vertexDown,newEdgeUpDown,null,null,true,true);
					newEdgeUpDown.setDatas(edgeLeft.get_destinationVertex(),newEdgeDownUp,null,null,true,true);
					leftBoundingEdges.push(newEdgeDownUp);
					rightBoundingEdges.push(newEdgeUpDown);
					this.insertNewConstrainedEdge(segment,newEdgeDownUp,intersectedEdges,leftBoundingEdges,rightBoundingEdges);
					intersectedEdges.splice(0,intersectedEdges.length);
					leftBoundingEdges.splice(0,leftBoundingEdges.length);
					rightBoundingEdges.splice(0,rightBoundingEdges.length);
					vertexDown = edgeLeft.get_destinationVertex();
					tempEdgeDownUp.set_originVertex(vertexDown);
					currObjet = hxDaedalus_data_math_Intersection.EVertex(vertexDown);
				} else if(hxDaedalus_data_math_Geom2D.intersections2edges(edgeLeft,tempEdgeDownUp,pIntersect)) {
					if(edgeLeft.get_isConstrained()) {
						currVertex = this.splitEdge(edgeLeft,pIntersect.x,pIntersect.y);
						iterVertexToOutEdges.set_fromVertex(currVertex);
						while((currEdge = iterVertexToOutEdges.next()) != null) {
							if(currEdge.get_destinationVertex() == leftBoundingEdges[0].get_originVertex()) leftBoundingEdges.unshift(currEdge);
							if(currEdge.get_destinationVertex() == rightBoundingEdges[rightBoundingEdges.length - 1].get_destinationVertex()) rightBoundingEdges.push(currEdge.get_oppositeEdge());
						}
						newEdgeDownUp = new hxDaedalus_data_Edge();
						newEdgeUpDown = new hxDaedalus_data_Edge();
						newEdgeDownUp.setDatas(vertexDown,newEdgeUpDown,null,null,true,true);
						newEdgeUpDown.setDatas(currVertex,newEdgeDownUp,null,null,true,true);
						leftBoundingEdges.push(newEdgeDownUp);
						rightBoundingEdges.push(newEdgeUpDown);
						this.insertNewConstrainedEdge(segment,newEdgeDownUp,intersectedEdges,leftBoundingEdges,rightBoundingEdges);
						intersectedEdges.splice(0,intersectedEdges.length);
						leftBoundingEdges.splice(0,leftBoundingEdges.length);
						rightBoundingEdges.splice(0,rightBoundingEdges.length);
						vertexDown = currVertex;
						tempEdgeDownUp.set_originVertex(vertexDown);
						currObjet = hxDaedalus_data_math_Intersection.EVertex(vertexDown);
					} else {
						intersectedEdges.push(edgeLeft);
						leftBoundingEdges.unshift(edgeLeft.get_nextLeftEdge());
						currEdge = edgeLeft.get_oppositeEdge();
						currObjet = hxDaedalus_data_math_Intersection.EEdge(currEdge);
					}
				} else {
					edgeLeft = edgeLeft.get_nextLeftEdge();
					hxDaedalus_data_math_Geom2D.intersections2edges(edgeLeft,tempEdgeDownUp,pIntersect);
					if(edgeLeft.get_isConstrained()) {
						currVertex = this.splitEdge(edgeLeft,pIntersect.x,pIntersect.y);
						iterVertexToOutEdges.set_fromVertex(currVertex);
						while((currEdge = iterVertexToOutEdges.next()) != null) {
							if(currEdge.get_destinationVertex() == leftBoundingEdges[0].get_originVertex()) leftBoundingEdges.unshift(currEdge);
							if(currEdge.get_destinationVertex() == rightBoundingEdges[rightBoundingEdges.length - 1].get_destinationVertex()) rightBoundingEdges.push(currEdge.get_oppositeEdge());
						}
						newEdgeDownUp = new hxDaedalus_data_Edge();
						newEdgeUpDown = new hxDaedalus_data_Edge();
						newEdgeDownUp.setDatas(vertexDown,newEdgeUpDown,null,null,true,true);
						newEdgeUpDown.setDatas(currVertex,newEdgeDownUp,null,null,true,true);
						leftBoundingEdges.push(newEdgeDownUp);
						rightBoundingEdges.push(newEdgeUpDown);
						this.insertNewConstrainedEdge(segment,newEdgeDownUp,intersectedEdges,leftBoundingEdges,rightBoundingEdges);
						intersectedEdges.splice(0,intersectedEdges.length);
						leftBoundingEdges.splice(0,leftBoundingEdges.length);
						rightBoundingEdges.splice(0,rightBoundingEdges.length);
						vertexDown = currVertex;
						tempEdgeDownUp.set_originVertex(vertexDown);
						currObjet = hxDaedalus_data_math_Intersection.EVertex(vertexDown);
					} else {
						intersectedEdges.push(edgeLeft);
						rightBoundingEdges.push(edgeLeft.get_prevLeftEdge());
						currEdge = edgeLeft.get_oppositeEdge();
						currObjet = hxDaedalus_data_math_Intersection.EEdge(currEdge);
					}
				}
				break;
			case 2:
				var face = currObjet[2];
				break;
			case 3:
				break;
			}
		}
		return segment;
	}
	,insertNewConstrainedEdge: function(fromSegment,edgeDownUp,intersectedEdges,leftBoundingEdges,rightBoundingEdges) {
		this._edges.push(edgeDownUp);
		this._edges.push(edgeDownUp.get_oppositeEdge());
		edgeDownUp.addFromConstraintSegment(fromSegment);
		edgeDownUp.get_oppositeEdge().fromConstraintSegments = edgeDownUp.fromConstraintSegments;
		fromSegment.addEdge(edgeDownUp);
		edgeDownUp.get_originVertex().addFromConstraintSegment(fromSegment);
		edgeDownUp.get_destinationVertex().addFromConstraintSegment(fromSegment);
		this.untriangulate(intersectedEdges);
		this.triangulate(leftBoundingEdges,true);
		this.triangulate(rightBoundingEdges,true);
	}
	,deleteConstraintSegment: function(segment) {
		var i;
		var vertexToDelete = [];
		var edge = null;
		var vertex;
		var fromConstraintSegment;
		var _g1 = 0;
		var _g = segment.get_edges().length;
		while(_g1 < _g) {
			var i1 = _g1++;
			edge = segment.get_edges()[i1];
			edge.removeFromConstraintSegment(segment);
			if(edge.fromConstraintSegments.length == 0) {
				edge.set_isConstrained(false);
				edge.get_oppositeEdge().set_isConstrained(false);
			}
			vertex = edge.get_originVertex();
			vertex.removeFromConstraintSegment(segment);
			vertexToDelete.push(vertex);
		}
		vertex = edge.get_destinationVertex();
		vertex.removeFromConstraintSegment(segment);
		vertexToDelete.push(vertex);
		var _g11 = 0;
		var _g2 = vertexToDelete.length;
		while(_g11 < _g2) {
			var i2 = _g11++;
			this.deleteVertex(vertexToDelete[i2]);
		}
		segment.dispose();
	}
	,check: function() {
		var _g1 = 0;
		var _g = this._edges.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(this._edges[i].get_nextLeftEdge() == null) return;
		}
		null;
	}
	,insertVertex: function(x,y) {
		if(x < 0 || y < 0 || x > this._width || y > this._height) return null;
		this.__edgesToCheck.splice(0,this.__edgesToCheck.length);
		var inObject = hxDaedalus_data_math_Geom2D.locatePosition(x,y,this);
		var newVertex = null;
		switch(inObject[1]) {
		case 0:
			var vertex = inObject[2];
			newVertex = vertex;
			break;
		case 1:
			var edge = inObject[2];
			newVertex = this.splitEdge(edge,x,y);
			break;
		case 2:
			var face = inObject[2];
			newVertex = this.splitFace(face,x,y);
			break;
		case 3:
			break;
		}
		this.restoreAsDelaunay();
		return newVertex;
	}
	,flipEdge: function(edge) {
		var eBot_Top = edge;
		var eTop_Bot = edge.get_oppositeEdge();
		var eLeft_Right = new hxDaedalus_data_Edge();
		var eRight_Left = new hxDaedalus_data_Edge();
		var eTop_Left = eBot_Top.get_nextLeftEdge();
		var eLeft_Bot = eTop_Left.get_nextLeftEdge();
		var eBot_Right = eTop_Bot.get_nextLeftEdge();
		var eRight_Top = eBot_Right.get_nextLeftEdge();
		var vBot = eBot_Top.get_originVertex();
		var vTop = eTop_Bot.get_originVertex();
		var vLeft = eLeft_Bot.get_originVertex();
		var vRight = eRight_Top.get_originVertex();
		var fLeft = eBot_Top.get_leftFace();
		var fRight = eTop_Bot.get_leftFace();
		var fBot = new hxDaedalus_data_Face();
		var fTop = new hxDaedalus_data_Face();
		this._edges.push(eLeft_Right);
		this._edges.push(eRight_Left);
		this._faces.push(fTop);
		this._faces.push(fBot);
		eLeft_Right.setDatas(vLeft,eRight_Left,eRight_Top,fTop,edge.get_isReal(),edge.get_isConstrained());
		eRight_Left.setDatas(vRight,eLeft_Right,eLeft_Bot,fBot,edge.get_isReal(),edge.get_isConstrained());
		fTop.setDatas(eLeft_Right);
		fBot.setDatas(eRight_Left);
		if(vTop.get_edge() == eTop_Bot) vTop.setDatas(eTop_Left);
		if(vBot.get_edge() == eBot_Top) vBot.setDatas(eBot_Right);
		eTop_Left.set_nextLeftEdge(eLeft_Right);
		eTop_Left.set_leftFace(fTop);
		eLeft_Bot.set_nextLeftEdge(eBot_Right);
		eLeft_Bot.set_leftFace(fBot);
		eBot_Right.set_nextLeftEdge(eRight_Left);
		eBot_Right.set_leftFace(fBot);
		eRight_Top.set_nextLeftEdge(eTop_Left);
		eRight_Top.set_leftFace(fTop);
		eBot_Top.dispose();
		eTop_Bot.dispose();
		this._edges.splice(HxOverrides.indexOf(this._edges,eBot_Top,0),1);
		this._edges.splice(HxOverrides.indexOf(this._edges,eTop_Bot,0),1);
		fLeft.dispose();
		fRight.dispose();
		this._faces.splice(HxOverrides.indexOf(this._faces,fLeft,0),1);
		this._faces.splice(HxOverrides.indexOf(this._faces,fRight,0),1);
		return eRight_Left;
	}
	,splitEdge: function(edge,x,y) {
		this.__edgesToCheck.splice(0,this.__edgesToCheck.length);
		var eLeft_Right = edge;
		var eRight_Left = eLeft_Right.get_oppositeEdge();
		var eRight_Top = eLeft_Right.get_nextLeftEdge();
		var eTop_Left = eRight_Top.get_nextLeftEdge();
		var eLeft_Bot = eRight_Left.get_nextLeftEdge();
		var eBot_Right = eLeft_Bot.get_nextLeftEdge();
		var vTop = eTop_Left.get_originVertex();
		var vLeft = eLeft_Right.get_originVertex();
		var vBot = eBot_Right.get_originVertex();
		var vRight = eRight_Left.get_originVertex();
		var fTop = eLeft_Right.get_leftFace();
		var fBot = eRight_Left.get_leftFace();
		if((vLeft.get_pos().x - x) * (vLeft.get_pos().x - x) + (vLeft.get_pos().y - y) * (vLeft.get_pos().y - y) <= 0.0001) return vLeft;
		if((vRight.get_pos().x - x) * (vRight.get_pos().x - x) + (vRight.get_pos().y - y) * (vRight.get_pos().y - y) <= 0.0001) return vRight;
		var vCenter = new hxDaedalus_data_Vertex();
		var eTop_Center = new hxDaedalus_data_Edge();
		var eCenter_Top = new hxDaedalus_data_Edge();
		var eBot_Center = new hxDaedalus_data_Edge();
		var eCenter_Bot = new hxDaedalus_data_Edge();
		var eLeft_Center = new hxDaedalus_data_Edge();
		var eCenter_Left = new hxDaedalus_data_Edge();
		var eRight_Center = new hxDaedalus_data_Edge();
		var eCenter_Right = new hxDaedalus_data_Edge();
		var fTopLeft = new hxDaedalus_data_Face();
		var fBotLeft = new hxDaedalus_data_Face();
		var fBotRight = new hxDaedalus_data_Face();
		var fTopRight = new hxDaedalus_data_Face();
		this._vertices.push(vCenter);
		this._edges.push(eCenter_Top);
		this._edges.push(eTop_Center);
		this._edges.push(eCenter_Left);
		this._edges.push(eLeft_Center);
		this._edges.push(eCenter_Bot);
		this._edges.push(eBot_Center);
		this._edges.push(eCenter_Right);
		this._edges.push(eRight_Center);
		this._faces.push(fTopRight);
		this._faces.push(fBotRight);
		this._faces.push(fBotLeft);
		this._faces.push(fTopLeft);
		vCenter.setDatas(fTop.get_isReal()?eCenter_Top:eCenter_Bot);
		vCenter.get_pos().x = x;
		vCenter.get_pos().y = y;
		hxDaedalus_data_math_Geom2D.projectOrthogonaly(vCenter.get_pos(),eLeft_Right);
		eCenter_Top.setDatas(vCenter,eTop_Center,eTop_Left,fTopLeft,fTop.get_isReal());
		eTop_Center.setDatas(vTop,eCenter_Top,eCenter_Right,fTopRight,fTop.get_isReal());
		eCenter_Left.setDatas(vCenter,eLeft_Center,eLeft_Bot,fBotLeft,edge.get_isReal(),edge.get_isConstrained());
		eLeft_Center.setDatas(vLeft,eCenter_Left,eCenter_Top,fTopLeft,edge.get_isReal(),edge.get_isConstrained());
		eCenter_Bot.setDatas(vCenter,eBot_Center,eBot_Right,fBotRight,fBot.get_isReal());
		eBot_Center.setDatas(vBot,eCenter_Bot,eCenter_Left,fBotLeft,fBot.get_isReal());
		eCenter_Right.setDatas(vCenter,eRight_Center,eRight_Top,fTopRight,edge.get_isReal(),edge.get_isConstrained());
		eRight_Center.setDatas(vRight,eCenter_Right,eCenter_Bot,fBotRight,edge.get_isReal(),edge.get_isConstrained());
		fTopLeft.setDatas(eCenter_Top,fTop.get_isReal());
		fBotLeft.setDatas(eCenter_Left,fBot.get_isReal());
		fBotRight.setDatas(eCenter_Bot,fBot.get_isReal());
		fTopRight.setDatas(eCenter_Right,fTop.get_isReal());
		if(vLeft.get_edge() == eLeft_Right) vLeft.setDatas(eLeft_Center);
		if(vRight.get_edge() == eRight_Left) vRight.setDatas(eRight_Center);
		eTop_Left.set_nextLeftEdge(eLeft_Center);
		eTop_Left.set_leftFace(fTopLeft);
		eLeft_Bot.set_nextLeftEdge(eBot_Center);
		eLeft_Bot.set_leftFace(fBotLeft);
		eBot_Right.set_nextLeftEdge(eRight_Center);
		eBot_Right.set_leftFace(fBotRight);
		eRight_Top.set_nextLeftEdge(eTop_Center);
		eRight_Top.set_leftFace(fTopRight);
		if(eLeft_Right.get_isConstrained()) {
			var fromSegments = eLeft_Right.fromConstraintSegments;
			eLeft_Center.fromConstraintSegments = fromSegments.slice(0);
			eCenter_Left.fromConstraintSegments = eLeft_Center.fromConstraintSegments;
			eCenter_Right.fromConstraintSegments = fromSegments.slice(0);
			eRight_Center.fromConstraintSegments = eCenter_Right.fromConstraintSegments;
			var edges;
			var index;
			var _g1 = 0;
			var _g = eLeft_Right.fromConstraintSegments.length;
			while(_g1 < _g) {
				var i = _g1++;
				edges = eLeft_Right.fromConstraintSegments[i].get_edges();
				index = HxOverrides.indexOf(edges,eLeft_Right,0);
				if(index != -1) {
					edges.splice(index,1);
					edges.splice(index,0,eLeft_Center);
					edges.splice(index + 1,0,eCenter_Right);
				} else {
					var index2 = HxOverrides.indexOf(edges,eRight_Left,0);
					edges.splice(index2,1);
					edges.splice(index2,0,eRight_Center);
					edges.splice(index2,0,eCenter_Left);
				}
			}
			vCenter.set_fromConstraintSegments(fromSegments.slice(0));
		}
		eLeft_Right.dispose();
		eRight_Left.dispose();
		this._edges.splice(HxOverrides.indexOf(this._edges,eLeft_Right,0),1);
		this._edges.splice(HxOverrides.indexOf(this._edges,eRight_Left,0),1);
		fTop.dispose();
		fBot.dispose();
		this._faces.splice(HxOverrides.indexOf(this._faces,fTop,0),1);
		this._faces.splice(HxOverrides.indexOf(this._faces,fBot,0),1);
		this.__centerVertex = vCenter;
		this.__edgesToCheck.push(eTop_Left);
		this.__edgesToCheck.push(eLeft_Bot);
		this.__edgesToCheck.push(eBot_Right);
		this.__edgesToCheck.push(eRight_Top);
		return vCenter;
	}
	,splitFace: function(face,x,y) {
		this.__edgesToCheck.splice(0,this.__edgesToCheck.length);
		var eTop_Left = face.get_edge();
		var eLeft_Right = eTop_Left.get_nextLeftEdge();
		var eRight_Top = eLeft_Right.get_nextLeftEdge();
		var vTop = eTop_Left.get_originVertex();
		var vLeft = eLeft_Right.get_originVertex();
		var vRight = eRight_Top.get_originVertex();
		var vCenter = new hxDaedalus_data_Vertex();
		var eTop_Center = new hxDaedalus_data_Edge();
		var eCenter_Top = new hxDaedalus_data_Edge();
		var eLeft_Center = new hxDaedalus_data_Edge();
		var eCenter_Left = new hxDaedalus_data_Edge();
		var eRight_Center = new hxDaedalus_data_Edge();
		var eCenter_Right = new hxDaedalus_data_Edge();
		var fTopLeft = new hxDaedalus_data_Face();
		var fBot = new hxDaedalus_data_Face();
		var fTopRight = new hxDaedalus_data_Face();
		this._vertices.push(vCenter);
		this._edges.push(eTop_Center);
		this._edges.push(eCenter_Top);
		this._edges.push(eLeft_Center);
		this._edges.push(eCenter_Left);
		this._edges.push(eRight_Center);
		this._edges.push(eCenter_Right);
		this._faces.push(fTopLeft);
		this._faces.push(fBot);
		this._faces.push(fTopRight);
		vCenter.setDatas(eCenter_Top);
		vCenter.get_pos().x = x;
		vCenter.get_pos().y = y;
		eTop_Center.setDatas(vTop,eCenter_Top,eCenter_Right,fTopRight);
		eCenter_Top.setDatas(vCenter,eTop_Center,eTop_Left,fTopLeft);
		eLeft_Center.setDatas(vLeft,eCenter_Left,eCenter_Top,fTopLeft);
		eCenter_Left.setDatas(vCenter,eLeft_Center,eLeft_Right,fBot);
		eRight_Center.setDatas(vRight,eCenter_Right,eCenter_Left,fBot);
		eCenter_Right.setDatas(vCenter,eRight_Center,eRight_Top,fTopRight);
		fTopLeft.setDatas(eCenter_Top);
		fBot.setDatas(eCenter_Left);
		fTopRight.setDatas(eCenter_Right);
		eTop_Left.set_nextLeftEdge(eLeft_Center);
		eTop_Left.set_leftFace(fTopLeft);
		eLeft_Right.set_nextLeftEdge(eRight_Center);
		eLeft_Right.set_leftFace(fBot);
		eRight_Top.set_nextLeftEdge(eTop_Center);
		eRight_Top.set_leftFace(fTopRight);
		face.dispose();
		this._faces.splice(HxOverrides.indexOf(this._faces,face,0),1);
		this.__centerVertex = vCenter;
		this.__edgesToCheck.push(eTop_Left);
		this.__edgesToCheck.push(eLeft_Right);
		this.__edgesToCheck.push(eRight_Top);
		return vCenter;
	}
	,restoreAsDelaunay: function() {
		var edge;
		while(this.__edgesToCheck.length > 0) {
			edge = this.__edgesToCheck.shift();
			if(edge.get_isReal() && !edge.get_isConstrained() && !hxDaedalus_data_math_Geom2D.isDelaunay(edge)) {
				if(edge.get_nextLeftEdge().get_destinationVertex() == this.__centerVertex) {
					this.__edgesToCheck.push(edge.get_nextRightEdge());
					this.__edgesToCheck.push(edge.get_prevRightEdge());
				} else {
					this.__edgesToCheck.push(edge.get_nextLeftEdge());
					this.__edgesToCheck.push(edge.get_prevLeftEdge());
				}
				this.flipEdge(edge);
			}
		}
	}
	,deleteVertex: function(vertex) {
		var i;
		var freeOfConstraint;
		var iterEdges = new hxDaedalus_iterators_FromVertexToOutgoingEdges();
		iterEdges.set_fromVertex(vertex);
		iterEdges.realEdgesOnly = false;
		var edge;
		var outgoingEdges = [];
		freeOfConstraint = vertex.get_fromConstraintSegments().length == 0;
		var bound = [];
		var realA = false;
		var realB = false;
		var boundA = [];
		var boundB = [];
		if(freeOfConstraint) while((edge = iterEdges.next()) != null) {
			outgoingEdges.push(edge);
			bound.push(edge.get_nextLeftEdge());
		} else {
			var edges;
			var _g1 = 0;
			var _g = vertex.get_fromConstraintSegments().length;
			while(_g1 < _g) {
				var i1 = _g1++;
				edges = vertex.get_fromConstraintSegments()[i1].get_edges();
				if(edges[0].get_originVertex() == vertex || edges[edges.length - 1].get_destinationVertex() == vertex) return false;
			}
			var count = 0;
			while((edge = iterEdges.next()) != null) {
				outgoingEdges.push(edge);
				if(edge.get_isConstrained()) {
					count++;
					if(count > 2) return false;
				}
			}
			boundA = [];
			boundB = [];
			var constrainedEdgeA = null;
			var constrainedEdgeB = null;
			var edgeA = new hxDaedalus_data_Edge();
			var edgeB = new hxDaedalus_data_Edge();
			this._edges.push(edgeA);
			this._edges.push(edgeB);
			var _g11 = 0;
			var _g2 = outgoingEdges.length;
			while(_g11 < _g2) {
				var i2 = _g11++;
				edge = outgoingEdges[i2];
				if(edge.get_isConstrained()) {
					if(constrainedEdgeA == null) {
						edgeB.setDatas(edge.get_destinationVertex(),edgeA,null,null,true,true);
						boundA.push(edgeA);
						boundA.push(edge.get_nextLeftEdge());
						boundB.push(edgeB);
						constrainedEdgeA = edge;
					} else if(constrainedEdgeB == null) {
						edgeA.setDatas(edge.get_destinationVertex(),edgeB,null,null,true,true);
						boundB.push(edge.get_nextLeftEdge());
						constrainedEdgeB = edge;
					}
				} else if(constrainedEdgeA == null) boundB.push(edge.get_nextLeftEdge()); else if(constrainedEdgeB == null) boundA.push(edge.get_nextLeftEdge()); else boundB.push(edge.get_nextLeftEdge());
			}
			realA = constrainedEdgeA.get_leftFace().get_isReal();
			realB = constrainedEdgeB.get_leftFace().get_isReal();
			edgeA.fromConstraintSegments = constrainedEdgeA.fromConstraintSegments.slice(0);
			edgeB.fromConstraintSegments = edgeA.fromConstraintSegments;
			var index;
			var _g12 = 0;
			var _g3 = vertex.get_fromConstraintSegments().length;
			while(_g12 < _g3) {
				var i3 = _g12++;
				edges = vertex.get_fromConstraintSegments()[i3].get_edges();
				index = HxOverrides.indexOf(edges,constrainedEdgeA,0);
				if(index != -1) {
					edges.splice(index - 1,2);
					edges.splice(index - 1,0,edgeA);
				} else {
					var index2 = HxOverrides.indexOf(edges,constrainedEdgeB,0) - 1;
					edges.splice(index2,2);
					edges.splice(index2,0,edgeB);
				}
			}
		}
		var faceToDelete;
		var _g13 = 0;
		var _g4 = outgoingEdges.length;
		while(_g13 < _g4) {
			var i4 = _g13++;
			edge = outgoingEdges[i4];
			faceToDelete = edge.get_leftFace();
			this._faces.splice(HxOverrides.indexOf(this._faces,faceToDelete,0),1);
			faceToDelete.dispose();
			edge.get_destinationVertex().set_edge(edge.get_nextLeftEdge());
			this._edges.splice((function($this) {
				var $r;
				var x = edge.get_oppositeEdge();
				$r = HxOverrides.indexOf($this._edges,x,0);
				return $r;
			}(this)),1);
			edge.get_oppositeEdge().dispose();
			this._edges.splice(HxOverrides.indexOf(this._edges,edge,0),1);
			edge.dispose();
		}
		this._vertices.splice(HxOverrides.indexOf(this._vertices,vertex,0),1);
		vertex.dispose();
		if(freeOfConstraint) this.triangulate(bound,true); else {
			this.triangulate(boundA,realA);
			this.triangulate(boundB,realB);
		}
		return true;
	}
	,untriangulate: function(edgesList) {
		var i;
		var verticesCleaned = new haxe_ds_ObjectMap();
		var currEdge;
		var outEdge;
		var _g1 = 0;
		var _g = edgesList.length;
		while(_g1 < _g) {
			var i1 = _g1++;
			currEdge = edgesList[i1];
			if((function($this) {
				var $r;
				var key = currEdge.get_originVertex();
				$r = verticesCleaned.h[key.__id__];
				return $r;
			}(this)) == null) {
				currEdge.get_originVertex().set_edge(currEdge.get_prevLeftEdge().get_oppositeEdge());
				var k = currEdge.get_originVertex();
				verticesCleaned.set(k,true);
				true;
			}
			if((function($this) {
				var $r;
				var key1 = currEdge.get_destinationVertex();
				$r = verticesCleaned.h[key1.__id__];
				return $r;
			}(this)) == null) {
				currEdge.get_destinationVertex().set_edge(currEdge.get_nextLeftEdge());
				var k1 = currEdge.get_destinationVertex();
				verticesCleaned.set(k1,true);
				true;
			}
			this._faces.splice((function($this) {
				var $r;
				var x = currEdge.get_leftFace();
				$r = HxOverrides.indexOf($this._faces,x,0);
				return $r;
			}(this)),1);
			currEdge.get_leftFace().dispose();
			if(i1 == edgesList.length - 1) {
				this._faces.splice((function($this) {
					var $r;
					var x1 = currEdge.get_rightFace();
					$r = HxOverrides.indexOf($this._faces,x1,0);
					return $r;
				}(this)),1);
				currEdge.get_rightFace().dispose();
			}
		}
		var _g11 = 0;
		var _g2 = edgesList.length;
		while(_g11 < _g2) {
			var i2 = _g11++;
			currEdge = edgesList[i2];
			this._edges.splice((function($this) {
				var $r;
				var x2 = currEdge.get_oppositeEdge();
				$r = HxOverrides.indexOf($this._edges,x2,0);
				return $r;
			}(this)),1);
			this._edges.splice(HxOverrides.indexOf(this._edges,currEdge,0),1);
			currEdge.get_oppositeEdge().dispose();
			currEdge.dispose();
		}
	}
	,triangulate: function(bound,isReal) {
		if(bound.length < 2) return; else if(bound.length == 2) {
			hxDaedalus_debug_Debug.trace("  - edge0: " + bound[0].get_originVertex().get_id() + " -> " + bound[0].get_destinationVertex().get_id(),{ fileName : "Mesh.hx", lineNumber : 1404, className : "hxDaedalus.data.Mesh", methodName : "triangulate"});
			hxDaedalus_debug_Debug.trace("  - edge1: " + bound[1].get_originVertex().get_id() + " -> " + bound[1].get_destinationVertex().get_id(),{ fileName : "Mesh.hx", lineNumber : 1405, className : "hxDaedalus.data.Mesh", methodName : "triangulate"});
			return;
		} else if(bound.length == 3) {
			var f = new hxDaedalus_data_Face();
			f.setDatas(bound[0],isReal);
			this._faces.push(f);
			bound[0].set_leftFace(f);
			bound[1].set_leftFace(f);
			bound[2].set_leftFace(f);
			bound[0].set_nextLeftEdge(bound[1]);
			bound[1].set_nextLeftEdge(bound[2]);
			bound[2].set_nextLeftEdge(bound[0]);
		} else {
			var baseEdge = bound[0];
			var vertexA = baseEdge.get_originVertex();
			var vertexB = baseEdge.get_destinationVertex();
			var vertexC;
			var vertexCheck;
			var circumcenter = new hxDaedalus_data_math_Point2D();
			var radiusSquared;
			var distanceSquared;
			var isDelaunay = false;
			var index = 0;
			var i;
			var _g1 = 2;
			var _g = bound.length;
			while(_g1 < _g) {
				var i1 = _g1++;
				vertexC = bound[i1].get_originVertex();
				if(hxDaedalus_data_math_Geom2D.getRelativePosition2(vertexC.get_pos().x,vertexC.get_pos().y,baseEdge) == 1) {
					index = i1;
					isDelaunay = true;
					hxDaedalus_data_math_Geom2D.getCircumcenter(vertexA.get_pos().x,vertexA.get_pos().y,vertexB.get_pos().x,vertexB.get_pos().y,vertexC.get_pos().x,vertexC.get_pos().y,circumcenter);
					radiusSquared = (vertexA.get_pos().x - circumcenter.x) * (vertexA.get_pos().x - circumcenter.x) + (vertexA.get_pos().y - circumcenter.y) * (vertexA.get_pos().y - circumcenter.y);
					radiusSquared -= 0.0001;
					var _g3 = 2;
					var _g2 = bound.length;
					while(_g3 < _g2) {
						var j = _g3++;
						if(j != i1) {
							vertexCheck = bound[j].get_originVertex();
							distanceSquared = (vertexCheck.get_pos().x - circumcenter.x) * (vertexCheck.get_pos().x - circumcenter.x) + (vertexCheck.get_pos().y - circumcenter.y) * (vertexCheck.get_pos().y - circumcenter.y);
							if(distanceSquared < radiusSquared) {
								isDelaunay = false;
								break;
							}
						}
					}
					if(isDelaunay) break;
				}
			}
			if(!isDelaunay) {
				var s = "";
				var _g11 = 0;
				var _g4 = bound.length;
				while(_g11 < _g4) {
					var i2 = _g11++;
					s += bound[i2].get_originVertex().get_pos().x + " , ";
					s += bound[i2].get_originVertex().get_pos().y + " , ";
					s += bound[i2].get_destinationVertex().get_pos().x + " , ";
					s += bound[i2].get_destinationVertex().get_pos().y + " , ";
				}
				index = 2;
			}
			var edgeA = null;
			var edgeAopp = null;
			var edgeB = null;
			var edgeBopp;
			var boundA;
			var boundM;
			var boundB;
			if(index < bound.length - 1) {
				edgeA = new hxDaedalus_data_Edge();
				edgeAopp = new hxDaedalus_data_Edge();
				this._edges.push(edgeA);
				this._edges.push(edgeAopp);
				edgeA.setDatas(vertexA,edgeAopp,null,null,isReal,false);
				edgeAopp.setDatas(bound[index].get_originVertex(),edgeA,null,null,isReal,false);
				boundA = bound.slice(index);
				boundA.push(edgeA);
				this.triangulate(boundA,isReal);
			}
			if(index > 2) {
				edgeB = new hxDaedalus_data_Edge();
				edgeBopp = new hxDaedalus_data_Edge();
				this._edges.push(edgeB);
				this._edges.push(edgeBopp);
				edgeB.setDatas(bound[1].get_originVertex(),edgeBopp,null,null,isReal,false);
				edgeBopp.setDatas(bound[index].get_originVertex(),edgeB,null,null,isReal,false);
				boundB = bound.slice(1,index);
				boundB.push(edgeBopp);
				this.triangulate(boundB,isReal);
			}
			if(index == 2) boundM = [baseEdge,bound[1],edgeAopp]; else if(index == bound.length - 1) boundM = [baseEdge,edgeB,bound[index]]; else boundM = [baseEdge,edgeB,edgeAopp];
			this.triangulate(boundM,isReal);
		}
	}
	,findPositionFromBounds: function(x,y) {
		if(x <= 0) {
			if(y <= 0) return 1; else if(y >= this._height) return 7; else return 8;
		} else if(x >= this._width) {
			if(y <= 0) return 3; else if(y >= this._height) return 5; else return 4;
		} else if(y <= 0) return 2; else if(y >= this._height) return 6; else return 0;
	}
	,debug: function() {
		var i;
		var _g1 = 0;
		var _g = this._vertices.length;
		while(_g1 < _g) {
			var i1 = _g1++;
			hxDaedalus_debug_Debug.trace("-- vertex " + this._vertices[i1].get_id(),{ fileName : "Mesh.hx", lineNumber : 1568, className : "hxDaedalus.data.Mesh", methodName : "debug"});
			hxDaedalus_debug_Debug.trace("  edge " + this._vertices[i1].get_edge().get_id() + " - " + Std.string(this._vertices[i1].get_edge()),{ fileName : "Mesh.hx", lineNumber : 1569, className : "hxDaedalus.data.Mesh", methodName : "debug"});
			hxDaedalus_debug_Debug.trace("  edge isReal: " + Std.string(this._vertices[i1].get_edge().get_isReal()),{ fileName : "Mesh.hx", lineNumber : 1570, className : "hxDaedalus.data.Mesh", methodName : "debug"});
		}
		var _g11 = 0;
		var _g2 = this._edges.length;
		while(_g11 < _g2) {
			var i2 = _g11++;
			hxDaedalus_debug_Debug.trace("  isReal " + this._edges[i2].get_id() + " - " + Std.string(this._edges[i2].get_isReal()),{ fileName : "Mesh.hx", lineNumber : 1574, className : "hxDaedalus.data.Mesh", methodName : "debug"});
			hxDaedalus_debug_Debug.trace("  nextLeftEdge " + Std.string(this._edges[i2].get_nextLeftEdge()),{ fileName : "Mesh.hx", lineNumber : 1575, className : "hxDaedalus.data.Mesh", methodName : "debug"});
			hxDaedalus_debug_Debug.trace("  oppositeEdge " + Std.string(this._edges[i2].get_oppositeEdge()),{ fileName : "Mesh.hx", lineNumber : 1576, className : "hxDaedalus.data.Mesh", methodName : "debug"});
		}
	}
	,traverse: function(onVertex,onEdge) {
		var vertex;
		var incomingEdge;
		var holdingFace;
		var iterVertices;
		iterVertices = new hxDaedalus_iterators_FromMeshToVertices();
		iterVertices.set_fromMesh(this);
		var iterEdges;
		iterEdges = new hxDaedalus_iterators_FromVertexToIncomingEdges();
		var dictVerticesDone = new haxe_ds_ObjectMap();
		while((vertex = iterVertices.next()) != null) {
			{
				dictVerticesDone.set(vertex,true);
				true;
			}
			if(!this.vertexIsInsideAABB(vertex,this)) continue;
			onVertex(vertex);
			iterEdges.set_fromVertex(vertex);
			while((incomingEdge = iterEdges.next()) != null) if(!(function($this) {
				var $r;
				var key = incomingEdge.get_originVertex();
				$r = dictVerticesDone.h[key.__id__];
				return $r;
			}(this))) onEdge(incomingEdge);
		}
	}
	,vertexIsInsideAABB: function(vertex,mesh) {
		if(vertex.get_pos().x < 0 || vertex.get_pos().x > mesh.get_width() || vertex.get_pos().y < 0 || vertex.get_pos().y > mesh.get_height()) return false; else return true;
	}
	,__class__: hxDaedalus_data_Mesh
	,__properties__: {get___constraintShapes:"get___constraintShapes",get_id:"get_id",set_clipping:"set_clipping",get_clipping:"get_clipping",get_width:"get_width",get_height:"get_height"}
};
var hxDaedalus_data_Object = function() {
	this._id = hxDaedalus_data_Object.INC;
	hxDaedalus_data_Object.INC++;
	this._pivotX = 0;
	this._pivotY = 0;
	this._matrix = new hxDaedalus_data_math_Matrix2D();
	this._scaleX = 1;
	this._scaleY = 1;
	this._rotation = 0;
	this._x = 0;
	this._y = 0;
	this._coordinates = [];
	this._hasChanged = false;
};
hxDaedalus_data_Object.__name__ = true;
hxDaedalus_data_Object.prototype = {
	get_id: function() {
		return this._id;
	}
	,dispose: function() {
		this._matrix = null;
		this._coordinates = null;
		this._constraintShape = null;
	}
	,updateValuesFromMatrix: function() {
	}
	,updateMatrixFromValues: function() {
		this._matrix.identity();
		this._matrix.translate(-this._pivotX,-this._pivotY);
		this._matrix.scale(this._scaleX,this._scaleY);
		this._matrix.rotate(this._rotation);
		this._matrix.translate(this._x,this._y);
	}
	,get_pivotX: function() {
		return this._pivotX;
	}
	,set_pivotX: function(value) {
		this._pivotX = value;
		this._hasChanged = true;
		return value;
	}
	,get_pivotY: function() {
		return this._pivotY;
	}
	,set_pivotY: function(value) {
		this._pivotY = value;
		this._hasChanged = true;
		return value;
	}
	,get_scaleX: function() {
		return this._scaleX;
	}
	,set_scaleX: function(value) {
		if(this._scaleX != value) {
			this._scaleX = value;
			this._hasChanged = true;
		}
		return value;
	}
	,get_scaleY: function() {
		return this._scaleY;
	}
	,set_scaleY: function(value) {
		if(this._scaleY != value) {
			this._scaleY = value;
			this._hasChanged = true;
		}
		return value;
	}
	,get_rotation: function() {
		return this._rotation;
	}
	,set_rotation: function(value) {
		if(this._rotation != value) {
			this._rotation = value;
			this._hasChanged = true;
		}
		return value;
	}
	,get_x: function() {
		return this._x;
	}
	,set_x: function(value) {
		if(this._x != value) {
			this._x = value;
			this._hasChanged = true;
		}
		return value;
	}
	,get_y: function() {
		return this._y;
	}
	,set_y: function(value) {
		if(this._y != value) {
			this._y = value;
			this._hasChanged = true;
		}
		return value;
	}
	,get_matrix: function() {
		return this._matrix;
	}
	,set_matrix: function(value) {
		this._matrix = value;
		this._hasChanged = true;
		return value;
	}
	,get_coordinates: function() {
		return this._coordinates;
	}
	,set_coordinates: function(value) {
		this._coordinates = value;
		this._hasChanged = true;
		return value;
	}
	,get_constraintShape: function() {
		return this._constraintShape;
	}
	,set_constraintShape: function(value) {
		this._constraintShape = value;
		this._hasChanged = true;
		return value;
	}
	,get_hasChanged: function() {
		return this._hasChanged;
	}
	,set_hasChanged: function(value) {
		this._hasChanged = value;
		return value;
	}
	,get_edges: function() {
		var res = [];
		var seg = this._constraintShape.segments;
		var _g1 = 0;
		var _g = seg.length;
		while(_g1 < _g) {
			var i = _g1++;
			var _g3 = 0;
			var _g2 = seg[i].get_edges().length;
			while(_g3 < _g2) {
				var j = _g3++;
				res.push(seg[i].get_edges()[j]);
			}
		}
		return res;
	}
	,__class__: hxDaedalus_data_Object
	,__properties__: {get_edges:"get_edges",set_hasChanged:"set_hasChanged",get_hasChanged:"get_hasChanged",set_constraintShape:"set_constraintShape",get_constraintShape:"get_constraintShape",set_coordinates:"set_coordinates",get_coordinates:"get_coordinates",set_matrix:"set_matrix",get_matrix:"get_matrix",set_y:"set_y",get_y:"get_y",set_x:"set_x",get_x:"get_x",set_rotation:"set_rotation",get_rotation:"get_rotation",set_scaleY:"set_scaleY",get_scaleY:"get_scaleY",set_scaleX:"set_scaleX",get_scaleX:"get_scaleX",set_pivotY:"set_pivotY",get_pivotY:"get_pivotY",set_pivotX:"set_pivotX",get_pivotX:"get_pivotX",get_id:"get_id"}
};
var hxDaedalus_data_Vertex = function() {
	this.colorDebug = -1;
	this._id = hxDaedalus_data_Vertex.INC;
	hxDaedalus_data_Vertex.INC++;
	this._pos = new hxDaedalus_data_math_Point2D();
	this._fromConstraintSegments = [];
};
hxDaedalus_data_Vertex.__name__ = true;
hxDaedalus_data_Vertex.prototype = {
	get_id: function() {
		return this._id;
	}
	,get_isReal: function() {
		return this._isReal;
	}
	,get_pos: function() {
		return this._pos;
	}
	,get_fromConstraintSegments: function() {
		return this._fromConstraintSegments;
	}
	,set_fromConstraintSegments: function(value) {
		return this._fromConstraintSegments = value;
	}
	,setDatas: function(edge,isReal) {
		if(isReal == null) isReal = true;
		this._isReal = isReal;
		this._edge = edge;
	}
	,addFromConstraintSegment: function(segment) {
		if(HxOverrides.indexOf(this._fromConstraintSegments,segment,0) == -1) this._fromConstraintSegments.push(segment);
	}
	,removeFromConstraintSegment: function(segment) {
		var index = HxOverrides.indexOf(this._fromConstraintSegments,segment,0);
		if(index != -1) this._fromConstraintSegments.splice(index,1);
	}
	,dispose: function() {
		this._pos = null;
		this._edge = null;
		this._fromConstraintSegments = null;
	}
	,get_edge: function() {
		return this._edge;
	}
	,set_edge: function(value) {
		return this._edge = value;
	}
	,toString: function() {
		return "ver_id " + this._id;
	}
	,__class__: hxDaedalus_data_Vertex
	,__properties__: {set_edge:"set_edge",get_edge:"get_edge",set_fromConstraintSegments:"set_fromConstraintSegments",get_fromConstraintSegments:"get_fromConstraintSegments",get_pos:"get_pos",get_isReal:"get_isReal",get_id:"get_id"}
};
var hxDaedalus_data_math_Intersection = { __ename__ : true, __constructs__ : ["EVertex","EEdge","EFace","ENull"] };
hxDaedalus_data_math_Intersection.EVertex = function(vertex) { var $x = ["EVertex",0,vertex]; $x.__enum__ = hxDaedalus_data_math_Intersection; $x.toString = $estr; return $x; };
hxDaedalus_data_math_Intersection.EEdge = function(edge) { var $x = ["EEdge",1,edge]; $x.__enum__ = hxDaedalus_data_math_Intersection; $x.toString = $estr; return $x; };
hxDaedalus_data_math_Intersection.EFace = function(face) { var $x = ["EFace",2,face]; $x.__enum__ = hxDaedalus_data_math_Intersection; $x.toString = $estr; return $x; };
hxDaedalus_data_math_Intersection.ENull = ["ENull",3];
hxDaedalus_data_math_Intersection.ENull.toString = $estr;
hxDaedalus_data_math_Intersection.ENull.__enum__ = hxDaedalus_data_math_Intersection;
var hxDaedalus_data_math_Point2D = function(x_,y_) {
	if(y_ == null) y_ = 0;
	if(x_ == null) x_ = 0;
	this.x = x_;
	this.y = y_;
};
hxDaedalus_data_math_Point2D.__name__ = true;
hxDaedalus_data_math_Point2D.prototype = {
	transform: function(matrix) {
		matrix.tranform(this);
	}
	,setXY: function(x_,y_) {
		this.x = x_;
		this.y = y_;
	}
	,clone: function() {
		return new hxDaedalus_data_math_Point2D(this.x,this.y);
	}
	,substract: function(p) {
		this.x -= p.x;
		this.y -= p.y;
	}
	,get_length: function() {
		return Math.sqrt(this.x * this.x + this.y * this.y);
	}
	,normalize: function() {
		var norm = this.get_length();
		this.x = this.x / norm;
		this.y = this.y / norm;
	}
	,scale: function(s) {
		this.x = this.x * s;
		this.y = this.y * s;
	}
	,distanceTo: function(p) {
		var diffX = this.x - p.x;
		var diffY = this.y - p.y;
		return Math.sqrt(diffX * diffX + diffY * diffY);
	}
	,__class__: hxDaedalus_data_math_Point2D
	,__properties__: {get_length:"get_length"}
};
var hxDaedalus_data_math_Geom2D = function() {
};
hxDaedalus_data_math_Geom2D.__name__ = true;
hxDaedalus_data_math_Geom2D.locatePosition = function(x,y,mesh) {
	if(hxDaedalus_data_math_Geom2D._randGen == null) hxDaedalus_data_math_Geom2D._randGen = new hxDaedalus_data_math_RandGenerator();
	hxDaedalus_data_math_Geom2D._randGen.set_seed(x * 10 + 4 * y | 0);
	var i;
	hxDaedalus_data_math_Geom2D.__samples.splice(0,hxDaedalus_data_math_Geom2D.__samples.length);
	var numSamples = Std["int"](Math.pow(mesh._vertices.length,0.33333333333333331));
	hxDaedalus_data_math_Geom2D._randGen.rangeMin = 0;
	hxDaedalus_data_math_Geom2D._randGen.rangeMax = mesh._vertices.length - 1;
	var _g = 0;
	while(_g < numSamples) {
		var i1 = _g++;
		var _rnd = hxDaedalus_data_math_Geom2D._randGen.next();
		hxDaedalus_data_math_Geom2D.__samples.push(mesh._vertices[_rnd]);
	}
	var currVertex;
	var currVertexPos;
	var distSquared;
	var minDistSquared = Infinity;
	var closedVertex = null;
	var _g1 = 0;
	while(_g1 < numSamples) {
		var i2 = _g1++;
		currVertex = hxDaedalus_data_math_Geom2D.__samples[i2];
		currVertexPos = currVertex.get_pos();
		distSquared = (currVertexPos.x - x) * (currVertexPos.x - x) + (currVertexPos.y - y) * (currVertexPos.y - y);
		if(distSquared < minDistSquared) {
			minDistSquared = distSquared;
			closedVertex = currVertex;
		}
	}
	var currFace;
	var iterFace = new hxDaedalus_iterators_FromVertexToHoldingFaces();
	iterFace.set_fromVertex(closedVertex);
	currFace = iterFace.next();
	var faceVisited = new haxe_ds_ObjectMap();
	var currEdge;
	var iterEdge = new hxDaedalus_iterators_FromFaceToInnerEdges();
	var objectContainer = hxDaedalus_data_math_Intersection.ENull;
	var relativPos;
	var numIter = 0;
	while(faceVisited.h[currFace.__id__] || (function($this) {
		var $r;
		var _g2 = objectContainer = hxDaedalus_data_math_Geom2D.isInFace(x,y,currFace);
		$r = (function($this) {
			var $r;
			switch(_g2[1]) {
			case 3:
				$r = true;
				break;
			default:
				$r = false;
			}
			return $r;
		}($this));
		return $r;
	}(this))) {
		faceVisited.h[currFace.__id__];
		numIter++;
		if(numIter == 50) null;
		iterEdge.set_fromFace(currFace);
		do {
			currEdge = iterEdge.next();
			if(currEdge == null) return hxDaedalus_data_math_Intersection.ENull;
			relativPos = hxDaedalus_data_math_Geom2D.getRelativePosition(x,y,currEdge);
		} while(relativPos == 1 || relativPos == 0);
		currFace = currEdge.get_rightFace();
	}
	return objectContainer;
};
hxDaedalus_data_math_Geom2D.isCircleIntersectingAnyConstraint = function(x,y,radius,mesh) {
	if(x <= 0 || x >= mesh.get_width() || y <= 0 || y >= mesh.get_height()) return true;
	var loc = hxDaedalus_data_math_Geom2D.locatePosition(x,y,mesh);
	var face;
	switch(loc[1]) {
	case 0:
		var vertex = loc[2];
		face = vertex.get_edge().get_leftFace();
		break;
	case 1:
		var edge1 = loc[2];
		face = edge1.get_leftFace();
		break;
	case 2:
		var face_ = loc[2];
		face = face_;
		break;
	case 3:
		face = null;
		break;
	}
	var radiusSquared = radius * radius;
	var pos;
	var distSquared;
	pos = face.get_edge().get_originVertex().get_pos();
	distSquared = (pos.x - x) * (pos.x - x) + (pos.y - y) * (pos.y - y);
	if(distSquared <= radiusSquared) return true;
	pos = face.get_edge().get_nextLeftEdge().get_originVertex().get_pos();
	distSquared = (pos.x - x) * (pos.x - x) + (pos.y - y) * (pos.y - y);
	if(distSquared <= radiusSquared) return true;
	pos = face.get_edge().get_nextLeftEdge().get_nextLeftEdge().get_originVertex().get_pos();
	distSquared = (pos.x - x) * (pos.x - x) + (pos.y - y) * (pos.y - y);
	if(distSquared <= radiusSquared) return true;
	var edgesToCheck = [];
	edgesToCheck.push(face.get_edge());
	edgesToCheck.push(face.get_edge().get_nextLeftEdge());
	edgesToCheck.push(face.get_edge().get_nextLeftEdge().get_nextLeftEdge());
	var edge;
	var pos1;
	var pos2;
	var checkedEdges = new haxe_ds_ObjectMap();
	var intersecting;
	while(edgesToCheck.length > 0) {
		edge = edgesToCheck.pop();
		{
			checkedEdges.set(edge,true);
			true;
		}
		pos1 = edge.get_originVertex().get_pos();
		pos2 = edge.get_destinationVertex().get_pos();
		intersecting = hxDaedalus_data_math_Geom2D.intersectionsSegmentCircle(pos1.x,pos1.y,pos2.x,pos2.y,x,y,radius);
		if(intersecting) {
			if(edge.get_isConstrained()) return true; else {
				edge = edge.get_oppositeEdge().get_nextLeftEdge();
				if(!checkedEdges.h[edge.__id__] && !(function($this) {
					var $r;
					var key = edge.get_oppositeEdge();
					$r = checkedEdges.h[key.__id__];
					return $r;
				}(this)) && HxOverrides.indexOf(edgesToCheck,edge,0) == -1 && (function($this) {
					var $r;
					var x1 = edge.get_oppositeEdge();
					$r = HxOverrides.indexOf(edgesToCheck,x1,0);
					return $r;
				}(this)) == -1) edgesToCheck.push(edge);
				edge = edge.get_nextLeftEdge();
				if(!checkedEdges.h[edge.__id__] && !(function($this) {
					var $r;
					var key1 = edge.get_oppositeEdge();
					$r = checkedEdges.h[key1.__id__];
					return $r;
				}(this)) && HxOverrides.indexOf(edgesToCheck,edge,0) == -1 && (function($this) {
					var $r;
					var x2 = edge.get_oppositeEdge();
					$r = HxOverrides.indexOf(edgesToCheck,x2,0);
					return $r;
				}(this)) == -1) edgesToCheck.push(edge);
			}
		}
	}
	return false;
};
hxDaedalus_data_math_Geom2D.getDirection = function(x1,y1,x2,y2,x3,y3) {
	var dot = (x3 - x1) * (y2 - y1) + (y3 - y1) * (-x2 + x1);
	if(dot == 0) return 0; else if(dot > 0) return 1; else return -1;
};
hxDaedalus_data_math_Geom2D.getDirection2 = function(x1,y1,x2,y2,x3,y3) {
	var dot = (x3 - x1) * (y2 - y1) + (y3 - y1) * (-x2 + x1);
	if(dot == 0) return 0; else if(dot > 0) {
		if(hxDaedalus_data_math_Geom2D.distanceSquaredPointToLine(x3,y3,x1,y1,x2,y2) <= 0.0001) return 0; else return 1;
	} else if(hxDaedalus_data_math_Geom2D.distanceSquaredPointToLine(x3,y3,x1,y1,x2,y2) <= 0.0001) return 0; else return -1;
	return 0;
};
hxDaedalus_data_math_Geom2D.getRelativePosition = function(x,y,eUp) {
	return hxDaedalus_data_math_Geom2D.getDirection(eUp.get_originVertex().get_pos().x,eUp.get_originVertex().get_pos().y,eUp.get_destinationVertex().get_pos().x,eUp.get_destinationVertex().get_pos().y,x,y);
};
hxDaedalus_data_math_Geom2D.getRelativePosition2 = function(x,y,eUp) {
	return hxDaedalus_data_math_Geom2D.getDirection2(eUp.get_originVertex().get_pos().x,eUp.get_originVertex().get_pos().y,eUp.get_destinationVertex().get_pos().x,eUp.get_destinationVertex().get_pos().y,x,y);
};
hxDaedalus_data_math_Geom2D.isInFace = function(x,y,polygon) {
	var result = hxDaedalus_data_math_Intersection.ENull;
	var e1_2 = polygon.get_edge();
	var e2_3 = e1_2.get_nextLeftEdge();
	var e3_1 = e2_3.get_nextLeftEdge();
	if(hxDaedalus_data_math_Geom2D.getRelativePosition(x,y,e1_2) >= 0 && hxDaedalus_data_math_Geom2D.getRelativePosition(x,y,e2_3) >= 0 && hxDaedalus_data_math_Geom2D.getRelativePosition(x,y,e3_1) >= 0) {
		var v1 = e1_2.get_originVertex();
		var v2 = e2_3.get_originVertex();
		var v3 = e3_1.get_originVertex();
		var x1 = v1.get_pos().x;
		var y1 = v1.get_pos().y;
		var x2 = v2.get_pos().x;
		var y2 = v2.get_pos().y;
		var x3 = v3.get_pos().x;
		var y3 = v3.get_pos().y;
		var v_v1squaredLength = (x1 - x) * (x1 - x) + (y1 - y) * (y1 - y);
		var v_v2squaredLength = (x2 - x) * (x2 - x) + (y2 - y) * (y2 - y);
		var v_v3squaredLength = (x3 - x) * (x3 - x) + (y3 - y) * (y3 - y);
		var v1_v2squaredLength = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
		var v2_v3squaredLength = (x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2);
		var v3_v1squaredLength = (x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3);
		var dot_v_v1v2 = (x - x1) * (x2 - x1) + (y - y1) * (y2 - y1);
		var dot_v_v2v3 = (x - x2) * (x3 - x2) + (y - y2) * (y3 - y2);
		var dot_v_v3v1 = (x - x3) * (x1 - x3) + (y - y3) * (y1 - y3);
		var v_e1_2squaredLength = v_v1squaredLength - dot_v_v1v2 * dot_v_v1v2 / v1_v2squaredLength;
		var v_e2_3squaredLength = v_v2squaredLength - dot_v_v2v3 * dot_v_v2v3 / v2_v3squaredLength;
		var v_e3_1squaredLength = v_v3squaredLength - dot_v_v3v1 * dot_v_v3v1 / v3_v1squaredLength;
		var closeTo_e1_2 = v_e1_2squaredLength <= 0.0001;
		var closeTo_e2_3 = v_e2_3squaredLength <= 0.0001;
		var closeTo_e3_1 = v_e3_1squaredLength <= 0.0001;
		if(closeTo_e1_2) {
			if(closeTo_e3_1) result = hxDaedalus_data_math_Intersection.EVertex(v1); else if(closeTo_e2_3) result = hxDaedalus_data_math_Intersection.EVertex(v2); else result = hxDaedalus_data_math_Intersection.EEdge(e1_2);
		} else if(closeTo_e2_3) {
			if(closeTo_e3_1) result = hxDaedalus_data_math_Intersection.EVertex(v3); else result = hxDaedalus_data_math_Intersection.EEdge(e2_3);
		} else if(closeTo_e3_1) result = hxDaedalus_data_math_Intersection.EEdge(e3_1); else result = hxDaedalus_data_math_Intersection.EFace(polygon);
	}
	return result;
};
hxDaedalus_data_math_Geom2D.clipSegmentByTriangle = function(s1x,s1y,s2x,s2y,t1x,t1y,t2x,t2y,t3x,t3y,pResult1,pResult2) {
	var side1_1;
	var side1_2;
	side1_1 = hxDaedalus_data_math_Geom2D.getDirection(t1x,t1y,t2x,t2y,s1x,s1y);
	side1_2 = hxDaedalus_data_math_Geom2D.getDirection(t1x,t1y,t2x,t2y,s2x,s2y);
	if(side1_1 <= 0 && side1_2 <= 0) return false;
	var side2_1;
	var side2_2;
	side2_1 = hxDaedalus_data_math_Geom2D.getDirection(t2x,t2y,t3x,t3y,s1x,s1y);
	side2_2 = hxDaedalus_data_math_Geom2D.getDirection(t2x,t2y,t3x,t3y,s2x,s2y);
	if(side2_1 <= 0 && side2_2 <= 0) return false;
	var side3_1;
	var side3_2;
	side3_1 = hxDaedalus_data_math_Geom2D.getDirection(t3x,t3y,t1x,t1y,s1x,s1y);
	side3_2 = hxDaedalus_data_math_Geom2D.getDirection(t3x,t3y,t1x,t1y,s2x,s2y);
	if(side3_1 <= 0 && side3_2 <= 0) return false;
	if(side1_1 >= 0 && side2_1 >= 0 && side3_1 >= 0 && (side1_2 >= 0 && side2_2 >= 0 && side3_2 >= 0)) {
		pResult1.x = s1x;
		pResult1.y = s1y;
		pResult2.x = s2x;
		pResult2.y = s2y;
		return true;
	}
	var n = 0;
	if(hxDaedalus_data_math_Geom2D.intersections2segments(s1x,s1y,s2x,s2y,t1x,t1y,t2x,t2y,pResult1,null)) n++;
	if(n == 0) {
		if(hxDaedalus_data_math_Geom2D.intersections2segments(s1x,s1y,s2x,s2y,t2x,t2y,t3x,t3y,pResult1,null)) n++;
	} else if(hxDaedalus_data_math_Geom2D.intersections2segments(s1x,s1y,s2x,s2y,t2x,t2y,t3x,t3y,pResult2,null)) {
		if(-0.01 > pResult1.x - pResult2.x || pResult1.x - pResult2.x > 0.01 || -0.01 > pResult1.y - pResult2.y || pResult1.y - pResult2.y > 0.01) n++;
	}
	if(n == 0) {
		if(hxDaedalus_data_math_Geom2D.intersections2segments(s1x,s1y,s2x,s2y,t3x,t3y,t1x,t1y,pResult1,null)) n++;
	} else if(n == 1) {
		if(hxDaedalus_data_math_Geom2D.intersections2segments(s1x,s1y,s2x,s2y,t3x,t3y,t1x,t1y,pResult2,null)) {
			if(-0.01 > pResult1.x - pResult2.x || pResult1.x - pResult2.x > 0.01 || -0.01 > pResult1.y - pResult2.y || pResult1.y - pResult2.y > 0.01) n++;
		}
	}
	if(n == 1) {
		if(side1_1 >= 0 && side2_1 >= 0 && side3_1 >= 0) {
			pResult2.x = s1x;
			pResult2.y = s1y;
		} else if(side1_2 >= 0 && side2_2 >= 0 && side3_2 >= 0) {
			pResult2.x = s2x;
			pResult2.y = s2y;
		} else n = 0;
	}
	if(n > 0) return true; else return false;
};
hxDaedalus_data_math_Geom2D.isSegmentIntersectingTriangle = function(s1x,s1y,s2x,s2y,t1x,t1y,t2x,t2y,t3x,t3y) {
	var side1_1;
	var side1_2;
	side1_1 = hxDaedalus_data_math_Geom2D.getDirection(t1x,t1y,t2x,t2y,s1x,s1y);
	side1_2 = hxDaedalus_data_math_Geom2D.getDirection(t1x,t1y,t2x,t2y,s2x,s2y);
	if(side1_1 <= 0 && side1_2 <= 0) return false;
	var side2_1;
	var side2_2;
	side2_1 = hxDaedalus_data_math_Geom2D.getDirection(t2x,t2y,t3x,t3y,s1x,s1y);
	side2_2 = hxDaedalus_data_math_Geom2D.getDirection(t2x,t2y,t3x,t3y,s2x,s2y);
	if(side2_1 <= 0 && side2_2 <= 0) return false;
	var side3_1;
	var side3_2;
	side3_1 = hxDaedalus_data_math_Geom2D.getDirection(t3x,t3y,t1x,t1y,s1x,s1y);
	side3_2 = hxDaedalus_data_math_Geom2D.getDirection(t3x,t3y,t1x,t1y,s2x,s2y);
	if(side3_1 <= 0 && side3_2 <= 0) return false;
	if(side1_1 == 1 && side2_1 == 1 && side3_1 == 1) return true;
	if(side1_1 == 1 && side2_1 == 1 && side3_1 == 1) return true;
	var side1;
	var side2;
	if(side1_1 == 1 && side1_2 <= 0 || side1_1 <= 0 && side1_2 == 1) {
		side1 = hxDaedalus_data_math_Geom2D.getDirection(s1x,s1y,s2x,s2y,t1x,t1y);
		side2 = hxDaedalus_data_math_Geom2D.getDirection(s1x,s1y,s2x,s2y,t2x,t2y);
		if(side1 == 1 && side2 <= 0 || side1 <= 0 && side2 == 1) return true;
	}
	if(side2_1 == 1 && side2_2 <= 0 || side2_1 <= 0 && side2_2 == 1) {
		side1 = hxDaedalus_data_math_Geom2D.getDirection(s1x,s1y,s2x,s2y,t2x,t2y);
		side2 = hxDaedalus_data_math_Geom2D.getDirection(s1x,s1y,s2x,s2y,t3x,t3y);
		if(side1 == 1 && side2 <= 0 || side1 <= 0 && side2 == 1) return true;
	}
	if(side3_1 == 1 && side3_2 <= 0 || side3_1 <= 0 && side3_2 == 1) {
		side1 = hxDaedalus_data_math_Geom2D.getDirection(s1x,s1y,s2x,s2y,t3x,t3y);
		side2 = hxDaedalus_data_math_Geom2D.getDirection(s1x,s1y,s2x,s2y,t1x,t1y);
		if(side1 == 1 && side2 <= 0 || side1 <= 0 && side2 == 1) return true;
	}
	return false;
};
hxDaedalus_data_math_Geom2D.isDelaunay = function(edge) {
	var vLeft = edge.get_originVertex();
	var vRight = edge.get_destinationVertex();
	var vCorner = edge.get_nextLeftEdge().get_destinationVertex();
	var vOpposite = edge.get_nextRightEdge().get_destinationVertex();
	hxDaedalus_data_math_Geom2D.getCircumcenter(vCorner.get_pos().x,vCorner.get_pos().y,vLeft.get_pos().x,vLeft.get_pos().y,vRight.get_pos().x,vRight.get_pos().y,hxDaedalus_data_math_Geom2D.__circumcenter);
	var squaredRadius = (vCorner.get_pos().x - hxDaedalus_data_math_Geom2D.__circumcenter.x) * (vCorner.get_pos().x - hxDaedalus_data_math_Geom2D.__circumcenter.x) + (vCorner.get_pos().y - hxDaedalus_data_math_Geom2D.__circumcenter.y) * (vCorner.get_pos().y - hxDaedalus_data_math_Geom2D.__circumcenter.y);
	var squaredDistance = (vOpposite.get_pos().x - hxDaedalus_data_math_Geom2D.__circumcenter.x) * (vOpposite.get_pos().x - hxDaedalus_data_math_Geom2D.__circumcenter.x) + (vOpposite.get_pos().y - hxDaedalus_data_math_Geom2D.__circumcenter.y) * (vOpposite.get_pos().y - hxDaedalus_data_math_Geom2D.__circumcenter.y);
	return squaredDistance >= squaredRadius;
};
hxDaedalus_data_math_Geom2D.getCircumcenter = function(x1,y1,x2,y2,x3,y3,result) {
	if(result == null) result = new hxDaedalus_data_math_Point2D();
	var m1 = (x1 + x2) / 2;
	var m2 = (y1 + y2) / 2;
	var m3 = (x1 + x3) / 2;
	var m4 = (y1 + y3) / 2;
	var t1 = (m1 * (x1 - x3) + (m2 - m4) * (y1 - y3) + m3 * (x3 - x1)) / (x1 * (y3 - y2) + x2 * (y1 - y3) + x3 * (y2 - y1));
	result.x = m1 + t1 * (y2 - y1);
	result.y = m2 - t1 * (x2 - x1);
	return result;
};
hxDaedalus_data_math_Geom2D.intersections2segments = function(s1p1x,s1p1y,s1p2x,s1p2y,s2p1x,s2p1y,s2p2x,s2p2y,posIntersection,paramIntersection,infiniteLineMode) {
	if(infiniteLineMode == null) infiniteLineMode = false;
	var t1 = 0;
	var t2 = 0;
	var result;
	var divisor = (s1p1x - s1p2x) * (s2p1y - s2p2y) + (s1p2y - s1p1y) * (s2p1x - s2p2x);
	if(divisor == 0) result = false; else {
		result = true;
		if(!infiniteLineMode || posIntersection != null || paramIntersection != null) {
			t1 = (s1p1x * (s2p1y - s2p2y) + s1p1y * (s2p2x - s2p1x) + s2p1x * s2p2y - s2p1y * s2p2x) / divisor;
			t2 = (s1p1x * (s2p1y - s1p2y) + s1p1y * (s1p2x - s2p1x) - s1p2x * s2p1y + s1p2y * s2p1x) / divisor;
			if(!infiniteLineMode && !(0 <= t1 && t1 <= 1 && 0 <= t2 && t2 <= 1)) result = false;
		}
	}
	if(result) {
		if(posIntersection != null) {
			posIntersection.x = s1p1x + t1 * (s1p2x - s1p1x);
			posIntersection.y = s1p1y + t1 * (s1p2y - s1p1y);
		}
		if(paramIntersection != null) {
			paramIntersection.push(t1);
			paramIntersection.push(t2);
		}
	}
	return result;
};
hxDaedalus_data_math_Geom2D.intersections2edges = function(edge1,edge2,posIntersection,paramIntersection,infiniteLineMode) {
	if(infiniteLineMode == null) infiniteLineMode = false;
	return hxDaedalus_data_math_Geom2D.intersections2segments(edge1.get_originVertex().get_pos().x,edge1.get_originVertex().get_pos().y,edge1.get_destinationVertex().get_pos().x,edge1.get_destinationVertex().get_pos().y,edge2.get_originVertex().get_pos().x,edge2.get_originVertex().get_pos().y,edge2.get_destinationVertex().get_pos().x,edge2.get_destinationVertex().get_pos().y,posIntersection,paramIntersection,infiniteLineMode);
};
hxDaedalus_data_math_Geom2D.isConvex = function(edge) {
	var result = true;
	var eLeft;
	var vRight;
	eLeft = edge.get_nextLeftEdge().get_oppositeEdge();
	vRight = edge.get_nextRightEdge().get_destinationVertex();
	if(hxDaedalus_data_math_Geom2D.getRelativePosition(vRight.get_pos().x,vRight.get_pos().y,eLeft) != -1) result = false; else {
		eLeft = edge.get_prevRightEdge();
		vRight = edge.get_prevLeftEdge().get_originVertex();
		if(hxDaedalus_data_math_Geom2D.getRelativePosition(vRight.get_pos().x,vRight.get_pos().y,eLeft) != -1) result = false;
	}
	return result;
};
hxDaedalus_data_math_Geom2D.projectOrthogonaly = function(vertexPos,edge) {
	var a = edge.get_originVertex().get_pos().x;
	var b = edge.get_originVertex().get_pos().y;
	var c = edge.get_destinationVertex().get_pos().x;
	var d = edge.get_destinationVertex().get_pos().y;
	var e = vertexPos.x;
	var f = vertexPos.y;
	var t1 = (a * a - a * c - a * e + b * b - b * d - b * f + c * e + d * f) / (a * a - 2 * a * c + b * b - 2 * b * d + c * c + d * d);
	vertexPos.x = a + t1 * (c - a);
	vertexPos.y = b + t1 * (d - b);
};
hxDaedalus_data_math_Geom2D.intersections2Circles = function(cx1,cy1,r1,cx2,cy2,r2,result) {
	var distRadiusSQRD = (cx2 - cx1) * (cx2 - cx1) + (cy2 - cy1) * (cy2 - cy1);
	if((cx1 != cx2 || cy1 != cy2) && distRadiusSQRD <= (r1 + r2) * (r1 + r2) && distRadiusSQRD >= (r1 - r2) * (r1 - r2)) {
		var transcendPart = Math.sqrt(((r1 + r2) * (r1 + r2) - distRadiusSQRD) * (distRadiusSQRD - (r2 - r1) * (r2 - r1)));
		var xFirstPart = (cx1 + cx2) / 2 + (cx2 - cx1) * (r1 * r1 - r2 * r2) / (2 * distRadiusSQRD);
		var yFirstPart = (cy1 + cy2) / 2 + (cy2 - cy1) * (r1 * r1 - r2 * r2) / (2 * distRadiusSQRD);
		var xFactor = (cy2 - cy1) / (2 * distRadiusSQRD);
		var yFactor = (cx2 - cx1) / (2 * distRadiusSQRD);
		if(result != null) {
			var _g = 0;
			var _g1 = [xFirstPart + xFactor * transcendPart,yFirstPart - yFactor * transcendPart,xFirstPart - xFactor * transcendPart,yFirstPart + yFactor * transcendPart];
			while(_g < _g1.length) {
				var f = _g1[_g];
				++_g;
				result.push(f);
			}
		}
		return true;
	} else return false;
};
hxDaedalus_data_math_Geom2D.intersectionsSegmentCircle = function(p0x,p0y,p1x,p1y,cx,cy,r,result) {
	var p0xSQD = p0x * p0x;
	var p0ySQD = p0y * p0y;
	var a = p1y * p1y - 2 * p1y * p0y + p0ySQD + p1x * p1x - 2 * p1x * p0x + p0xSQD;
	var b = 2 * p0y * cy - 2 * p0xSQD + 2 * p1y * p0y - 2 * p0ySQD + 2 * p1x * p0x - 2 * p1x * cx + 2 * p0x * cx - 2 * p1y * cy;
	var c = p0ySQD + cy * cy + cx * cx - 2 * p0y * cy - 2 * p0x * cx + p0xSQD - r * r;
	var delta = b * b - 4 * a * c;
	var deltaSQRT;
	var t0;
	var t1;
	if(delta < 0) return false; else if(delta == 0) {
		t0 = -b / (2 * a);
		if(t0 < 0 || t0 > 1) return false;
		if(result != null) {
			var _g = 0;
			var _g1 = [p0x + t0 * (p1x - p0x),p0y + t0 * (p1y - p0y),t0];
			while(_g < _g1.length) {
				var f = _g1[_g];
				++_g;
				result.push(f);
			}
		}
		return true;
	} else {
		deltaSQRT = Math.sqrt(delta);
		t0 = (-b + deltaSQRT) / (2 * a);
		t1 = (-b - deltaSQRT) / (2 * a);
		var intersecting = false;
		if(0 <= t0 && t0 <= 1) {
			if(result != null) {
				var _g2 = 0;
				var _g11 = [p0x + t0 * (p1x - p0x),p0y + t0 * (p1y - p0y),t0];
				while(_g2 < _g11.length) {
					var f1 = _g11[_g2];
					++_g2;
					result.push(f1);
				}
			}
			intersecting = true;
		}
		if(0 <= t1 && t1 <= 1) {
			if(result != null) {
				var _g3 = 0;
				var _g12 = [p0x + t1 * (p1x - p0x),p0y + t1 * (p1y - p0y),t1];
				while(_g3 < _g12.length) {
					var f2 = _g12[_g3];
					++_g3;
					result.push(f2);
				}
			}
			intersecting = true;
		}
		return intersecting;
	}
};
hxDaedalus_data_math_Geom2D.intersectionsLineCircle = function(p0x,p0y,p1x,p1y,cx,cy,r,result) {
	var p0xSQD = p0x * p0x;
	var p0ySQD = p0y * p0y;
	var a = p1y * p1y - 2 * p1y * p0y + p0ySQD + p1x * p1x - 2 * p1x * p0x + p0xSQD;
	var b = 2 * p0y * cy - 2 * p0xSQD + 2 * p1y * p0y - 2 * p0ySQD + 2 * p1x * p0x - 2 * p1x * cx + 2 * p0x * cx - 2 * p1y * cy;
	var c = p0ySQD + cy * cy + cx * cx - 2 * p0y * cy - 2 * p0x * cx + p0xSQD - r * r;
	var delta = b * b - 4 * a * c;
	var deltaSQRT;
	var t0;
	var t1;
	if(delta < 0) return false; else if(delta == 0) {
		t0 = -b / (2 * a);
		var _g = 0;
		var _g1 = [p0x + t0 * (p1x - p0x),p0y + t0 * (p1y - p0y),t0];
		while(_g < _g1.length) {
			var f = _g1[_g];
			++_g;
			result.push(f);
		}
	} else if(delta > 0) {
		deltaSQRT = Math.sqrt(delta);
		t0 = (-b + deltaSQRT) / (2 * a);
		t1 = (-b - deltaSQRT) / (2 * a);
		var _g2 = 0;
		var _g11 = [p0x + t0 * (p1x - p0x),p0y + t0 * (p1y - p0y),t0,p0x + t1 * (p1x - p0x),p0y + t1 * (p1y - p0y),t1];
		while(_g2 < _g11.length) {
			var f1 = _g11[_g2];
			++_g2;
			result.push(f1);
		}
	}
	return true;
};
hxDaedalus_data_math_Geom2D.tangentsPointToCircle = function(px,py,cx,cy,r,result) {
	var c2x = (px + cx) / 2;
	var c2y = (py + cy) / 2;
	var r2 = 0.5 * Math.sqrt((px - cx) * (px - cx) + (py - cy) * (py - cy));
	return hxDaedalus_data_math_Geom2D.intersections2Circles(c2x,c2y,r2,cx,cy,r,result);
};
hxDaedalus_data_math_Geom2D.tangentsCrossCircleToCircle = function(r,c1x,c1y,c2x,c2y,result) {
	var distance = Math.sqrt((c1x - c2x) * (c1x - c2x) + (c1y - c2y) * (c1y - c2y));
	var radius = distance / 4;
	var centerX = c1x + (c2x - c1x) / 4;
	var centerY = c1y + (c2y - c1y) / 4;
	if(hxDaedalus_data_math_Geom2D.intersections2Circles(c1x,c1y,r,centerX,centerY,radius,result)) {
		var t1x = result[0];
		var t1y = result[1];
		var t2x = result[2];
		var t2y = result[3];
		var midX = (c1x + c2x) / 2;
		var midY = (c1y + c2y) / 2;
		var dotProd = (t1x - midX) * (c2y - c1y) + (t1y - midY) * (-c2x + c1x);
		var tproj = dotProd / (distance * distance);
		var projx = midX + tproj * (c2y - c1y);
		var projy = midY - tproj * (c2x - c1x);
		var t4x = 2 * projx - t1x;
		var t4y = 2 * projy - t1y;
		var t3x = t4x + t2x - t1x;
		var t3y = t2y + t4y - t1y;
		var _g = 0;
		var _g1 = [t3x,t3y,t4x,t4y];
		while(_g < _g1.length) {
			var f = _g1[_g];
			++_g;
			result.push(f);
		}
		return true;
	} else return false;
};
hxDaedalus_data_math_Geom2D.tangentsParalCircleToCircle = function(r,c1x,c1y,c2x,c2y,result) {
	var distance = Math.sqrt((c1x - c2x) * (c1x - c2x) + (c1y - c2y) * (c1y - c2y));
	var t1x = c1x + r * (c2y - c1y) / distance;
	var t1y = c1y + r * (-c2x + c1x) / distance;
	var t2x = 2 * c1x - t1x;
	var t2y = 2 * c1y - t1y;
	var t3x = t2x + c2x - c1x;
	var t3y = t2y + c2y - c1y;
	var t4x = t1x + c2x - c1x;
	var t4y = t1y + c2y - c1y;
	var _g = 0;
	var _g1 = [t1x,t1y,t2x,t2y,t3x,t3y,t4x,t4y];
	while(_g < _g1.length) {
		var f = _g1[_g];
		++_g;
		result.push(f);
	}
};
hxDaedalus_data_math_Geom2D.distanceSquaredPointToLine = function(px,py,ax,ay,bx,by) {
	var a_b_squaredLength = (bx - ax) * (bx - ax) + (by - ay) * (by - ay);
	var dotProduct = (px - ax) * (bx - ax) + (py - ay) * (by - ay);
	var p_a_squaredLength = (ax - px) * (ax - px) + (ay - py) * (ay - py);
	return p_a_squaredLength - dotProduct * dotProduct / a_b_squaredLength;
};
hxDaedalus_data_math_Geom2D.distanceSquaredPointToSegment = function(px,py,ax,ay,bx,by) {
	var a_b_squaredLength = (bx - ax) * (bx - ax) + (by - ay) * (by - ay);
	var dotProduct = ((px - ax) * (bx - ax) + (py - ay) * (by - ay)) / a_b_squaredLength;
	if(dotProduct < 0) return (px - ax) * (px - ax) + (py - ay) * (py - ay); else if(dotProduct <= 1) {
		var p_a_squaredLength = (ax - px) * (ax - px) + (ay - py) * (ay - py);
		return p_a_squaredLength - dotProduct * dotProduct * a_b_squaredLength;
	} else return (px - bx) * (px - bx) + (py - by) * (py - by);
};
hxDaedalus_data_math_Geom2D.distanceSquaredVertexToEdge = function(vertex,edge) {
	return hxDaedalus_data_math_Geom2D.distanceSquaredPointToSegment(vertex.get_pos().x,vertex.get_pos().y,edge.get_originVertex().get_pos().x,edge.get_originVertex().get_pos().y,edge.get_destinationVertex().get_pos().x,edge.get_destinationVertex().get_pos().y);
};
hxDaedalus_data_math_Geom2D.pathLength = function(path) {
	var sumDistance = 0.;
	var fromX = path[0];
	var fromY = path[1];
	var nextX;
	var nextY;
	var x;
	var y;
	var distance;
	var i = 2;
	while(i < path.length) {
		nextX = path[i];
		nextY = path[i + 1];
		x = nextX - fromX;
		y = nextY - fromY;
		distance = Math.sqrt(x * x + y * y);
		sumDistance += distance;
		fromX = nextX;
		fromY = nextY;
		i += 2;
	}
	return sumDistance;
};
hxDaedalus_data_math_Geom2D.prototype = {
	__class__: hxDaedalus_data_math_Geom2D
};
var hxDaedalus_data_math_Matrix2D = function(a_,b_,c_,d_,e_,f_) {
	if(f_ == null) f_ = 0;
	if(e_ == null) e_ = 0;
	if(d_ == null) d_ = 1;
	if(c_ == null) c_ = 0;
	if(b_ == null) b_ = 0;
	if(a_ == null) a_ = 1;
	this.a = a_;
	this.b = b_;
	this.c = c_;
	this.d = d_;
	this.e = e_;
	this.f = f_;
};
hxDaedalus_data_math_Matrix2D.__name__ = true;
hxDaedalus_data_math_Matrix2D.prototype = {
	identity: function() {
		this.a = 1;
		this.b = 0;
		this.c = 0;
		this.d = 1;
		this.e = 0;
		this.f = 0;
	}
	,translate: function(tx,ty) {
		this.e = this.e + tx;
		this.f = this.f + ty;
	}
	,scale: function(sx,sy) {
		this.a = this.a * sx;
		this.b = this.b * sy;
		this.c = this.c * sx;
		this.d = this.d * sy;
		this.e = this.e * sx;
		this.f = this.f * sy;
	}
	,rotate: function(rad) {
		var cos = Math.cos(rad);
		var sin = Math.sin(rad);
		var a_ = this.a * cos + this.b * -sin;
		var b_ = this.a * sin + this.b * cos;
		var c_ = this.c * cos + this.d * -sin;
		var d_ = this.c * sin + this.d * cos;
		var e_ = this.e * cos + this.f * -sin;
		var f_ = this.e * sin + this.f * cos;
		this.a = a_;
		this.b = b_;
		this.c = c_;
		this.d = d_;
		this.e = e_;
		this.f = f_;
	}
	,clone: function() {
		return new hxDaedalus_data_math_Matrix2D(this.a,this.b,this.c,this.d,this.e,this.f);
	}
	,tranform: function(point) {
		var x = this.a * point.x + this.c * point.y + this.e;
		var y = this.b * point.x + this.d * point.y + this.f;
		point.x = x;
		point.y = y;
	}
	,transformX: function(x,y) {
		return this.a * x + this.c * y + this.e;
	}
	,transformY: function(x,y) {
		return this.b * x + this.d * y + this.f;
	}
	,concat: function(matrix) {
		var a_ = this.a * matrix.a + this.b * matrix.c;
		var b_ = this.a * matrix.b + this.b * matrix.d;
		var c_ = this.c * matrix.a + this.d * matrix.c;
		var d_ = this.c * matrix.b + this.d * matrix.d;
		var e_ = this.e * matrix.a + this.f * matrix.c + matrix.e;
		var f_ = this.e * matrix.b + this.f * matrix.d + matrix.f;
		this.a = a_;
		this.b = b_;
		this.c = c_;
		this.d = d_;
		this.e = e_;
		this.f = f_;
	}
	,__class__: hxDaedalus_data_math_Matrix2D
};
var hxDaedalus_data_math_RandGenerator = function(seed,rangeMin_,rangeMax_) {
	if(rangeMax_ == null) rangeMax_ = 1;
	if(rangeMin_ == null) rangeMin_ = 0;
	if(seed == null) seed = 1234;
	this._originalSeed = this._currSeed = seed;
	this.rangeMin = rangeMin_;
	this.rangeMax = rangeMax_;
	this._numIter = 0;
};
hxDaedalus_data_math_RandGenerator.__name__ = true;
hxDaedalus_data_math_RandGenerator.prototype = {
	set_seed: function(value) {
		this._originalSeed = this._currSeed = value;
		return value;
	}
	,get_seed: function() {
		return this._originalSeed;
	}
	,reset: function() {
		this._currSeed = this._originalSeed;
		this._numIter = 0;
	}
	,next: function() {
		var _floatSeed = this._currSeed * 1.0;
		this._tempString = Std.string(_floatSeed * _floatSeed);
		while(this._tempString.length < 8) this._tempString = "0" + this._tempString;
		this._currSeed = Std.parseInt(HxOverrides.substr(this._tempString,1,5));
		var res = Math.round(this.rangeMin + this._currSeed / 99999 * (this.rangeMax - this.rangeMin));
		if(this._currSeed == 0) this._currSeed = this._originalSeed + this._numIter;
		this._numIter++;
		if(this._numIter == 200) this.reset();
		return res;
	}
	,nextInRange: function(rangeMin,rangeMax) {
		this.rangeMin = rangeMin;
		this.rangeMax = rangeMax;
		return this.next();
	}
	,shuffle: function(array) {
		var currIdx = array.length;
		while(currIdx > 0) {
			var rndIdx = this.nextInRange(0,currIdx - 1);
			currIdx--;
			var tmp = array[currIdx];
			array[currIdx] = array[rndIdx];
			array[rndIdx] = tmp;
		}
	}
	,__class__: hxDaedalus_data_math_RandGenerator
	,__properties__: {set_seed:"set_seed",get_seed:"get_seed"}
};
var hxDaedalus_debug_Debug = function() { };
hxDaedalus_debug_Debug.__name__ = true;
hxDaedalus_debug_Debug.assertTrue = function(cond,message,pos) {
	return;
};
hxDaedalus_debug_Debug.assertFalse = function(cond,message,pos) {
	return;
};
hxDaedalus_debug_Debug.assertEquals = function(expected,actual,message,pos) {
	return;
};
hxDaedalus_debug_Debug.trace = function(value,pos) {
	return;
};
var hxDaedalus_factories_RectMesh = function() {
};
hxDaedalus_factories_RectMesh.__name__ = true;
hxDaedalus_factories_RectMesh.buildRectangle = function(width,height) {
	var vTL = new hxDaedalus_data_Vertex();
	var vTR = new hxDaedalus_data_Vertex();
	var vBR = new hxDaedalus_data_Vertex();
	var vBL = new hxDaedalus_data_Vertex();
	var eTL_TR = new hxDaedalus_data_Edge();
	var eTR_TL = new hxDaedalus_data_Edge();
	var eTR_BR = new hxDaedalus_data_Edge();
	var eBR_TR = new hxDaedalus_data_Edge();
	var eBR_BL = new hxDaedalus_data_Edge();
	var eBL_BR = new hxDaedalus_data_Edge();
	var eBL_TL = new hxDaedalus_data_Edge();
	var eTL_BL = new hxDaedalus_data_Edge();
	var eTR_BL = new hxDaedalus_data_Edge();
	var eBL_TR = new hxDaedalus_data_Edge();
	var eTL_BR = new hxDaedalus_data_Edge();
	var eBR_TL = new hxDaedalus_data_Edge();
	var fTL_BL_TR = new hxDaedalus_data_Face();
	var fTR_BL_BR = new hxDaedalus_data_Face();
	var fTL_BR_BL = new hxDaedalus_data_Face();
	var fTL_TR_BR = new hxDaedalus_data_Face();
	var boundShape = new hxDaedalus_data_ConstraintShape();
	var segTop = new hxDaedalus_data_ConstraintSegment();
	var segRight = new hxDaedalus_data_ConstraintSegment();
	var segBot = new hxDaedalus_data_ConstraintSegment();
	var segLeft = new hxDaedalus_data_ConstraintSegment();
	var mesh = new hxDaedalus_data_Mesh(width,height);
	var offset = 10.;
	vTL.get_pos().setXY(0 - offset,0 - offset);
	vTR.get_pos().setXY(width + offset,0 - offset);
	vBR.get_pos().setXY(width + offset,height + offset);
	vBL.get_pos().setXY(0 - offset,height + offset);
	vTL.setDatas(eTL_TR);
	vTR.setDatas(eTR_BR);
	vBR.setDatas(eBR_BL);
	vBL.setDatas(eBL_TL);
	eTL_TR.setDatas(vTL,eTR_TL,eTR_BR,fTL_TR_BR,true,true);
	eTR_TL.setDatas(vTR,eTL_TR,eTL_BL,fTL_BL_TR,true,true);
	eTR_BR.setDatas(vTR,eBR_TR,eBR_TL,fTL_TR_BR,true,true);
	eBR_TR.setDatas(vBR,eTR_BR,eTR_BL,fTR_BL_BR,true,true);
	eBR_BL.setDatas(vBR,eBL_BR,eBL_TL,fTL_BR_BL,true,true);
	eBL_BR.setDatas(vBL,eBR_BL,eBR_TR,fTR_BL_BR,true,true);
	eBL_TL.setDatas(vBL,eTL_BL,eTL_BR,fTL_BR_BL,true,true);
	eTL_BL.setDatas(vTL,eBL_TL,eBL_TR,fTL_BL_TR,true,true);
	eTR_BL.setDatas(vTR,eBL_TR,eBL_BR,fTR_BL_BR,true,false);
	eBL_TR.setDatas(vBL,eTR_BL,eTR_TL,fTL_BL_TR,true,false);
	eTL_BR.setDatas(vTL,eBR_TL,eBR_BL,fTL_BR_BL,false,false);
	eBR_TL.setDatas(vBR,eTL_BR,eTL_TR,fTL_TR_BR,false,false);
	fTL_BL_TR.setDatas(eBL_TR);
	fTR_BL_BR.setDatas(eTR_BL);
	fTL_BR_BL.setDatas(eBR_BL,false);
	fTL_TR_BR.setDatas(eTR_BR,false);
	vTL.set_fromConstraintSegments([segTop,segLeft]);
	vTR.set_fromConstraintSegments([segTop,segRight]);
	vBR.set_fromConstraintSegments([segRight,segBot]);
	vBL.set_fromConstraintSegments([segBot,segLeft]);
	eTL_TR.fromConstraintSegments.push(segTop);
	eTR_TL.fromConstraintSegments.push(segTop);
	eTR_BR.fromConstraintSegments.push(segRight);
	eBR_TR.fromConstraintSegments.push(segRight);
	eBR_BL.fromConstraintSegments.push(segBot);
	eBL_BR.fromConstraintSegments.push(segBot);
	eBL_TL.fromConstraintSegments.push(segLeft);
	eTL_BL.fromConstraintSegments.push(segLeft);
	segTop.get_edges().push(eTL_TR);
	segRight.get_edges().push(eTR_BR);
	segBot.get_edges().push(eBR_BL);
	segLeft.get_edges().push(eBL_TL);
	segTop.fromShape = boundShape;
	segRight.fromShape = boundShape;
	segBot.fromShape = boundShape;
	segLeft.fromShape = boundShape;
	var _g = 0;
	var _g1 = [segTop,segRight,segBot,segLeft];
	while(_g < _g1.length) {
		var f = _g1[_g];
		++_g;
		boundShape.segments.push(f);
	}
	var _g2 = 0;
	var _g11 = [vTL,vTR,vBR,vBL];
	while(_g2 < _g11.length) {
		var f1 = _g11[_g2];
		++_g2;
		mesh._vertices.push(f1);
	}
	var _g3 = 0;
	var _g12 = [eTL_TR,eTR_TL,eTR_BR,eBR_TR,eBR_BL,eBL_BR,eBL_TL,eTL_BL,eTR_BL,eBL_TR,eTL_BR,eBR_TL];
	while(_g3 < _g12.length) {
		var f2 = _g12[_g3];
		++_g3;
		mesh._edges.push(f2);
	}
	var _g4 = 0;
	var _g13 = [fTL_BL_TR,fTR_BL_BR,fTL_BR_BL,fTL_TR_BR];
	while(_g4 < _g13.length) {
		var f3 = _g13[_g4];
		++_g4;
		mesh._faces.push(f3);
	}
	mesh.get___constraintShapes().push(boundShape);
	var securityRect = [];
	var _g5 = 0;
	var _g14 = [0,0,width,0];
	while(_g5 < _g14.length) {
		var f4 = _g14[_g5];
		++_g5;
		securityRect.push(f4);
	}
	var _g6 = 0;
	var _g15 = [width,0,width,height];
	while(_g6 < _g15.length) {
		var f5 = _g15[_g6];
		++_g6;
		securityRect.push(f5);
	}
	var _g7 = 0;
	var _g16 = [width,height,0,height];
	while(_g7 < _g16.length) {
		var f6 = _g16[_g7];
		++_g7;
		securityRect.push(f6);
	}
	var _g8 = 0;
	var _g17 = [0,height,0,0];
	while(_g8 < _g17.length) {
		var f7 = _g17[_g8];
		++_g8;
		securityRect.push(f7);
	}
	mesh.set_clipping(false);
	mesh.insertConstraintShape(securityRect);
	mesh.set_clipping(true);
	return mesh;
};
hxDaedalus_factories_RectMesh.prototype = {
	__class__: hxDaedalus_factories_RectMesh
};
var hxDaedalus_graphics_ISimpleDrawingContext = function() { };
hxDaedalus_graphics_ISimpleDrawingContext.__name__ = true;
hxDaedalus_graphics_ISimpleDrawingContext.prototype = {
	__class__: hxDaedalus_graphics_ISimpleDrawingContext
};
var hxDaedalus_graphics_luxe_SimpleDrawingContext = function(graphics) {
	this._inFillingMode = false;
	this._fillColor = new phoenix_Color();
	this._lineColor = new phoenix_Color();
	this._prevY = 0;
	this._prevX = 0;
	this.graphics = graphics;
};
hxDaedalus_graphics_luxe_SimpleDrawingContext.__name__ = true;
hxDaedalus_graphics_luxe_SimpleDrawingContext.__interfaces__ = [hxDaedalus_graphics_ISimpleDrawingContext];
hxDaedalus_graphics_luxe_SimpleDrawingContext.prototype = {
	clear: function() {
		var geom;
		while((geom = this.graphics.pop()) != null) geom.drop();
	}
	,lineStyle: function(thickness,color,alpha) {
		if(alpha == null) alpha = 1;
		this._lineColor = new phoenix_Color().rgb(color);
		this._lineColor.a = alpha;
	}
	,beginFill: function(color,alpha) {
		if(alpha == null) alpha = 1;
		this._fillColor = new phoenix_Color().rgb(color);
		this._fillColor.a = alpha;
		this._inFillingMode = true;
	}
	,endFill: function() {
		this._inFillingMode = false;
	}
	,moveTo: function(x,y) {
		this._prevX = x;
		this._prevY = y;
	}
	,lineTo: function(x,y) {
		var geom = Luxe.draw.line({ p0 : new phoenix_Vector(this._prevX,this._prevY), p1 : new phoenix_Vector(x,y), color : this._lineColor});
		this._prevX = x;
		this._prevY = y;
		this.graphics.push(geom);
	}
	,drawCircle: function(cx,cy,radius) {
		if(this._inFillingMode) {
			var geom1 = Luxe.draw.circle({ x : cx, y : cy, r : radius, color : this._fillColor});
			this.graphics.push(geom1);
		}
		var geom = Luxe.draw.ring({ x : cx, y : cy, r : radius, color : this._lineColor});
		this.graphics.push(geom);
	}
	,drawRect: function(x,y,width,height) {
		if(this._inFillingMode) {
			var geom1 = Luxe.draw.box({ x : x, y : y, w : width, h : height, color : this._fillColor});
			this.graphics.push(geom1);
		}
		var geom = Luxe.draw.rectangle({ x : x, y : y, w : width, h : height, color : this._lineColor});
		this.graphics.push(geom);
	}
	,__class__: hxDaedalus_graphics_luxe_SimpleDrawingContext
};
var hxDaedalus_iterators_FromFaceToInnerEdges = function() {
};
hxDaedalus_iterators_FromFaceToInnerEdges.__name__ = true;
hxDaedalus_iterators_FromFaceToInnerEdges.prototype = {
	set_fromFace: function(value) {
		this._fromFace = value;
		this._nextEdge = this._fromFace.get_edge();
		return value;
	}
	,next: function() {
		if(this._nextEdge != null) {
			this._resultEdge = this._nextEdge;
			this._nextEdge = this._nextEdge.get_nextLeftEdge();
			if(this._nextEdge == this._fromFace.get_edge()) this._nextEdge = null;
		} else this._resultEdge = null;
		return this._resultEdge;
	}
	,__class__: hxDaedalus_iterators_FromFaceToInnerEdges
	,__properties__: {set_fromFace:"set_fromFace"}
};
var hxDaedalus_iterators_FromMeshToVertices = function() {
};
hxDaedalus_iterators_FromMeshToVertices.__name__ = true;
hxDaedalus_iterators_FromMeshToVertices.prototype = {
	set_fromMesh: function(value) {
		this._fromMesh = value;
		this._currIndex = 0;
		return value;
	}
	,next: function() {
		do if(this._currIndex < this._fromMesh._vertices.length) {
			this._resultVertex = this._fromMesh._vertices[this._currIndex];
			this._currIndex++;
		} else {
			this._resultVertex = null;
			break;
		} while(!this._resultVertex.get_isReal());
		return this._resultVertex;
	}
	,__class__: hxDaedalus_iterators_FromMeshToVertices
	,__properties__: {set_fromMesh:"set_fromMesh"}
};
var hxDaedalus_iterators_FromVertexToHoldingFaces = function() {
};
hxDaedalus_iterators_FromVertexToHoldingFaces.__name__ = true;
hxDaedalus_iterators_FromVertexToHoldingFaces.prototype = {
	set_fromVertex: function(value) {
		this._fromVertex = value;
		this._nextEdge = this._fromVertex.get_edge();
		return value;
	}
	,next: function() {
		if(this._nextEdge != null) do {
			this._resultFace = this._nextEdge.get_leftFace();
			this._nextEdge = this._nextEdge.get_rotLeftEdge();
			if(this._nextEdge == this._fromVertex.get_edge()) {
				this._nextEdge = null;
				if(!this._resultFace.get_isReal()) this._resultFace = null;
				break;
			}
		} while(!this._resultFace.get_isReal()); else this._resultFace = null;
		return this._resultFace;
	}
	,__class__: hxDaedalus_iterators_FromVertexToHoldingFaces
	,__properties__: {set_fromVertex:"set_fromVertex"}
};
var hxDaedalus_iterators_FromVertexToIncomingEdges = function() {
};
hxDaedalus_iterators_FromVertexToIncomingEdges.__name__ = true;
hxDaedalus_iterators_FromVertexToIncomingEdges.prototype = {
	set_fromVertex: function(value) {
		this._fromVertex = value;
		this._nextEdge = this._fromVertex.get_edge();
		while(!this._nextEdge.get_isReal()) this._nextEdge = this._nextEdge.get_rotLeftEdge();
		return value;
	}
	,next: function() {
		if(this._nextEdge != null) {
			this._resultEdge = this._nextEdge.get_oppositeEdge();
			do {
				this._nextEdge = this._nextEdge.get_rotLeftEdge();
				if(this._nextEdge == this._fromVertex.get_edge()) {
					this._nextEdge = null;
					break;
				}
			} while(!this._nextEdge.get_isReal());
		} else this._resultEdge = null;
		return this._resultEdge;
	}
	,__class__: hxDaedalus_iterators_FromVertexToIncomingEdges
	,__properties__: {set_fromVertex:"set_fromVertex"}
};
var hxDaedalus_iterators_FromVertexToOutgoingEdges = function() {
	this.realEdgesOnly = true;
};
hxDaedalus_iterators_FromVertexToOutgoingEdges.__name__ = true;
hxDaedalus_iterators_FromVertexToOutgoingEdges.prototype = {
	set_fromVertex: function(value) {
		this._fromVertex = value;
		this._nextEdge = this._fromVertex.get_edge();
		while(this.realEdgesOnly && !this._nextEdge.get_isReal()) this._nextEdge = this._nextEdge.get_rotLeftEdge();
		return value;
	}
	,next: function() {
		if(this._nextEdge != null) {
			this._resultEdge = this._nextEdge;
			do {
				this._nextEdge = this._nextEdge.get_rotLeftEdge();
				if(this._nextEdge == this._fromVertex.get_edge()) {
					this._nextEdge = null;
					break;
				}
			} while(this.realEdgesOnly && !this._nextEdge.get_isReal());
		} else this._resultEdge = null;
		return this._resultEdge;
	}
	,__class__: hxDaedalus_iterators_FromVertexToOutgoingEdges
	,__properties__: {set_fromVertex:"set_fromVertex"}
};
var hxDaedalus_view_SimpleView = function(targetCanvas) {
	this.entitiesAlpha = .75;
	this.entitiesWidth = 1;
	this.entitiesColor = 65280;
	this.pathsAlpha = .75;
	this.pathsWidth = 1.5;
	this.pathsColor = 16760848;
	this.verticesAlpha = .25;
	this.verticesRadius = .5;
	this.verticesColor = 255;
	this.constraintsAlpha = 1.0;
	this.constraintsWidth = 2;
	this.constraintsColor = 16711680;
	this.edgesAlpha = .25;
	this.edgesWidth = 1;
	this.edgesColor = 10066329;
	this.graphics = new hxDaedalus_graphics_luxe_SimpleDrawingContext(targetCanvas);
};
hxDaedalus_view_SimpleView.__name__ = true;
hxDaedalus_view_SimpleView.prototype = {
	drawVertex: function(vertex) {
		this.graphics.lineStyle(this.verticesRadius,this.verticesColor,this.verticesAlpha);
		this.graphics.beginFill(this.verticesColor,this.verticesAlpha);
		this.graphics.drawCircle(vertex.get_pos().x,vertex.get_pos().y,this.verticesRadius);
		this.graphics.endFill();
	}
	,drawEdge: function(edge) {
		if(edge.get_isConstrained()) {
			this.graphics.lineStyle(this.constraintsWidth,this.constraintsColor,this.constraintsAlpha);
			this.graphics.moveTo(edge.get_originVertex().get_pos().x,edge.get_originVertex().get_pos().y);
			this.graphics.lineTo(edge.get_destinationVertex().get_pos().x,edge.get_destinationVertex().get_pos().y);
		} else {
			this.graphics.lineStyle(this.edgesWidth,this.edgesColor,this.edgesAlpha);
			this.graphics.moveTo(edge.get_originVertex().get_pos().x,edge.get_originVertex().get_pos().y);
			this.graphics.lineTo(edge.get_destinationVertex().get_pos().x,edge.get_destinationVertex().get_pos().y);
		}
	}
	,drawMesh: function(mesh,cleanBefore) {
		if(cleanBefore == null) cleanBefore = false;
		if(cleanBefore) this.graphics.clear();
		mesh.traverse($bind(this,this.drawVertex),$bind(this,this.drawEdge));
	}
	,drawEntity: function(entity,cleanBefore) {
		if(cleanBefore == null) cleanBefore = false;
		if(cleanBefore) this.graphics.clear();
		this.graphics.lineStyle(this.entitiesWidth,this.entitiesColor,this.entitiesAlpha);
		this.graphics.beginFill(this.entitiesColor,this.entitiesAlpha);
		this.graphics.drawCircle(entity.x,entity.y,entity.get_radius());
		this.graphics.endFill();
	}
	,drawEntities: function(vEntities,cleanBefore) {
		if(cleanBefore == null) cleanBefore = false;
		if(cleanBefore) this.graphics.clear();
		var _g1 = 0;
		var _g = vEntities.length;
		while(_g1 < _g) {
			var i = _g1++;
			this.drawEntity(vEntities[i],false);
		}
	}
	,drawPath: function(path,cleanBefore) {
		if(cleanBefore == null) cleanBefore = false;
		if(cleanBefore) this.graphics.clear();
		if(path.length == 0) return;
		this.graphics.lineStyle(this.pathsWidth,this.pathsColor,this.pathsAlpha);
		this.graphics.moveTo(path[0],path[1]);
		var i = 2;
		while(i < path.length) {
			this.graphics.lineTo(path[i],path[i + 1]);
			this.graphics.moveTo(path[i],path[i + 1]);
			i += 2;
		}
	}
	,__class__: hxDaedalus_view_SimpleView
};
var js__$Boot_HaxeError = function(val) {
	Error.call(this);
	this.val = val;
	if(Error.captureStackTrace) Error.captureStackTrace(this,js__$Boot_HaxeError);
};
js__$Boot_HaxeError.__name__ = true;
js__$Boot_HaxeError.__super__ = Error;
js__$Boot_HaxeError.prototype = $extend(Error.prototype,{
	__class__: js__$Boot_HaxeError
});
var js_Boot = function() { };
js_Boot.__name__ = true;
js_Boot.__unhtml = function(s) {
	return s.split("&").join("&amp;").split("<").join("&lt;").split(">").join("&gt;");
};
js_Boot.__trace = function(v,i) {
	var msg;
	if(i != null) msg = i.fileName + ":" + i.lineNumber + ": "; else msg = "";
	msg += js_Boot.__string_rec(v,"");
	if(i != null && i.customParams != null) {
		var _g = 0;
		var _g1 = i.customParams;
		while(_g < _g1.length) {
			var v1 = _g1[_g];
			++_g;
			msg += "," + js_Boot.__string_rec(v1,"");
		}
	}
	var d;
	if(typeof(document) != "undefined" && (d = document.getElementById("haxe:trace")) != null) d.innerHTML += js_Boot.__unhtml(msg) + "<br/>"; else if(typeof console != "undefined" && console.log != null) console.log(msg);
};
js_Boot.getClass = function(o) {
	if((o instanceof Array) && o.__enum__ == null) return Array; else {
		var cl = o.__class__;
		if(cl != null) return cl;
		var name = js_Boot.__nativeClassName(o);
		if(name != null) return js_Boot.__resolveNativeClass(name);
		return null;
	}
};
js_Boot.__string_rec = function(o,s) {
	if(o == null) return "null";
	if(s.length >= 5) return "<...>";
	var t = typeof(o);
	if(t == "function" && (o.__name__ || o.__ename__)) t = "object";
	switch(t) {
	case "object":
		if(o instanceof Array) {
			if(o.__enum__) {
				if(o.length == 2) return o[0];
				var str2 = o[0] + "(";
				s += "\t";
				var _g1 = 2;
				var _g = o.length;
				while(_g1 < _g) {
					var i1 = _g1++;
					if(i1 != 2) str2 += "," + js_Boot.__string_rec(o[i1],s); else str2 += js_Boot.__string_rec(o[i1],s);
				}
				return str2 + ")";
			}
			var l = o.length;
			var i;
			var str1 = "[";
			s += "\t";
			var _g2 = 0;
			while(_g2 < l) {
				var i2 = _g2++;
				str1 += (i2 > 0?",":"") + js_Boot.__string_rec(o[i2],s);
			}
			str1 += "]";
			return str1;
		}
		var tostr;
		try {
			tostr = o.toString;
		} catch( e ) {
			if (e instanceof js__$Boot_HaxeError) e = e.val;
			return "???";
		}
		if(tostr != null && tostr != Object.toString && typeof(tostr) == "function") {
			var s2 = o.toString();
			if(s2 != "[object Object]") return s2;
		}
		var k = null;
		var str = "{\n";
		s += "\t";
		var hasp = o.hasOwnProperty != null;
		for( var k in o ) {
		if(hasp && !o.hasOwnProperty(k)) {
			continue;
		}
		if(k == "prototype" || k == "__class__" || k == "__super__" || k == "__interfaces__" || k == "__properties__") {
			continue;
		}
		if(str.length != 2) str += ", \n";
		str += s + k + " : " + js_Boot.__string_rec(o[k],s);
		}
		s = s.substring(1);
		str += "\n" + s + "}";
		return str;
	case "function":
		return "<function>";
	case "string":
		return o;
	default:
		return String(o);
	}
};
js_Boot.__interfLoop = function(cc,cl) {
	if(cc == null) return false;
	if(cc == cl) return true;
	var intf = cc.__interfaces__;
	if(intf != null) {
		var _g1 = 0;
		var _g = intf.length;
		while(_g1 < _g) {
			var i = _g1++;
			var i1 = intf[i];
			if(i1 == cl || js_Boot.__interfLoop(i1,cl)) return true;
		}
	}
	return js_Boot.__interfLoop(cc.__super__,cl);
};
js_Boot.__instanceof = function(o,cl) {
	if(cl == null) return false;
	switch(cl) {
	case Int:
		return (o|0) === o;
	case Float:
		return typeof(o) == "number";
	case Bool:
		return typeof(o) == "boolean";
	case String:
		return typeof(o) == "string";
	case Array:
		return (o instanceof Array) && o.__enum__ == null;
	case Dynamic:
		return true;
	default:
		if(o != null) {
			if(typeof(cl) == "function") {
				if(o instanceof cl) return true;
				if(js_Boot.__interfLoop(js_Boot.getClass(o),cl)) return true;
			} else if(typeof(cl) == "object" && js_Boot.__isNativeObj(cl)) {
				if(o instanceof cl) return true;
			}
		} else return false;
		if(cl == Class && o.__name__ != null) return true;
		if(cl == Enum && o.__ename__ != null) return true;
		return o.__enum__ == cl;
	}
};
js_Boot.__cast = function(o,t) {
	if(js_Boot.__instanceof(o,t)) return o; else throw new js__$Boot_HaxeError("Cannot cast " + Std.string(o) + " to " + Std.string(t));
};
js_Boot.__nativeClassName = function(o) {
	var name = js_Boot.__toStr.call(o).slice(8,-1);
	if(name == "Object" || name == "Function" || name == "Math" || name == "JSON") return null;
	return name;
};
js_Boot.__isNativeObj = function(o) {
	return js_Boot.__nativeClassName(o) != null;
};
js_Boot.__resolveNativeClass = function(name) {
	if(typeof window != "undefined") return window[name]; else return global[name];
};
var js_html__$CanvasElement_CanvasUtil = function() { };
js_html__$CanvasElement_CanvasUtil.__name__ = true;
js_html__$CanvasElement_CanvasUtil.getContextWebGL = function(canvas,attribs) {
	var _g = 0;
	var _g1 = ["webgl","experimental-webgl"];
	while(_g < _g1.length) {
		var name = _g1[_g];
		++_g;
		var ctx = canvas.getContext(name,attribs);
		if(ctx != null) return ctx;
	}
	return null;
};
var js_html_compat_ArrayBuffer = function(a) {
	if((a instanceof Array) && a.__enum__ == null) {
		this.a = a;
		this.byteLength = a.length;
	} else {
		var len = a;
		this.a = [];
		var _g = 0;
		while(_g < len) {
			var i = _g++;
			this.a[i] = 0;
		}
		this.byteLength = len;
	}
};
js_html_compat_ArrayBuffer.__name__ = true;
js_html_compat_ArrayBuffer.sliceImpl = function(begin,end) {
	var u = new Uint8Array(this,begin,end == null?null:end - begin);
	var result = new ArrayBuffer(u.byteLength);
	var resultArray = new Uint8Array(result);
	resultArray.set(u);
	return result;
};
js_html_compat_ArrayBuffer.prototype = {
	slice: function(begin,end) {
		return new js_html_compat_ArrayBuffer(this.a.slice(begin,end));
	}
	,__class__: js_html_compat_ArrayBuffer
};
var js_html_compat_DataView = function(buffer,byteOffset,byteLength) {
	this.buf = buffer;
	if(byteOffset == null) this.offset = 0; else this.offset = byteOffset;
	if(byteLength == null) this.length = buffer.byteLength - this.offset; else this.length = byteLength;
	if(this.offset < 0 || this.length < 0 || this.offset + this.length > buffer.byteLength) throw new js__$Boot_HaxeError(haxe_io_Error.OutsideBounds);
};
js_html_compat_DataView.__name__ = true;
js_html_compat_DataView.prototype = {
	getInt8: function(byteOffset) {
		var v = this.buf.a[this.offset + byteOffset];
		if(v >= 128) return v - 256; else return v;
	}
	,getUint8: function(byteOffset) {
		return this.buf.a[this.offset + byteOffset];
	}
	,getInt16: function(byteOffset,littleEndian) {
		var v = this.getUint16(byteOffset,littleEndian);
		if(v >= 32768) return v - 65536; else return v;
	}
	,getUint16: function(byteOffset,littleEndian) {
		if(littleEndian) return this.buf.a[this.offset + byteOffset] | this.buf.a[this.offset + byteOffset + 1] << 8; else return this.buf.a[this.offset + byteOffset] << 8 | this.buf.a[this.offset + byteOffset + 1];
	}
	,getInt32: function(byteOffset,littleEndian) {
		var p = this.offset + byteOffset;
		var a = this.buf.a[p++];
		var b = this.buf.a[p++];
		var c = this.buf.a[p++];
		var d = this.buf.a[p++];
		if(littleEndian) return a | b << 8 | c << 16 | d << 24; else return d | c << 8 | b << 16 | a << 24;
	}
	,getUint32: function(byteOffset,littleEndian) {
		var v = this.getInt32(byteOffset,littleEndian);
		if(v < 0) return v + 4294967296.; else return v;
	}
	,getFloat32: function(byteOffset,littleEndian) {
		return haxe_io_FPHelper.i32ToFloat(this.getInt32(byteOffset,littleEndian));
	}
	,getFloat64: function(byteOffset,littleEndian) {
		var a = this.getInt32(byteOffset,littleEndian);
		var b = this.getInt32(byteOffset + 4,littleEndian);
		return haxe_io_FPHelper.i64ToDouble(littleEndian?a:b,littleEndian?b:a);
	}
	,setInt8: function(byteOffset,value) {
		if(value < 0) this.buf.a[byteOffset + this.offset] = value + 128 & 255; else this.buf.a[byteOffset + this.offset] = value & 255;
	}
	,setUint8: function(byteOffset,value) {
		this.buf.a[byteOffset + this.offset] = value & 255;
	}
	,setInt16: function(byteOffset,value,littleEndian) {
		this.setUint16(byteOffset,value < 0?value + 65536:value,littleEndian);
	}
	,setUint16: function(byteOffset,value,littleEndian) {
		var p = byteOffset + this.offset;
		if(littleEndian) {
			this.buf.a[p] = value & 255;
			this.buf.a[p++] = value >> 8 & 255;
		} else {
			this.buf.a[p++] = value >> 8 & 255;
			this.buf.a[p] = value & 255;
		}
	}
	,setInt32: function(byteOffset,value,littleEndian) {
		this.setUint32(byteOffset,value,littleEndian);
	}
	,setUint32: function(byteOffset,value,littleEndian) {
		var p = byteOffset + this.offset;
		if(littleEndian) {
			this.buf.a[p++] = value & 255;
			this.buf.a[p++] = value >> 8 & 255;
			this.buf.a[p++] = value >> 16 & 255;
			this.buf.a[p++] = value >>> 24;
		} else {
			this.buf.a[p++] = value >>> 24;
			this.buf.a[p++] = value >> 16 & 255;
			this.buf.a[p++] = value >> 8 & 255;
			this.buf.a[p++] = value & 255;
		}
	}
	,setFloat32: function(byteOffset,value,littleEndian) {
		this.setUint32(byteOffset,haxe_io_FPHelper.floatToI32(value),littleEndian);
	}
	,setFloat64: function(byteOffset,value,littleEndian) {
		var i64 = haxe_io_FPHelper.doubleToI64(value);
		if(littleEndian) {
			this.setUint32(byteOffset,i64.low);
			this.setUint32(byteOffset,i64.high);
		} else {
			this.setUint32(byteOffset,i64.high);
			this.setUint32(byteOffset,i64.low);
		}
	}
	,__class__: js_html_compat_DataView
};
var js_html_compat_Uint8Array = function() { };
js_html_compat_Uint8Array.__name__ = true;
js_html_compat_Uint8Array._new = function(arg1,offset,length) {
	var arr;
	if(typeof(arg1) == "number") {
		arr = [];
		var _g = 0;
		while(_g < arg1) {
			var i = _g++;
			arr[i] = 0;
		}
		arr.byteLength = arr.length;
		arr.byteOffset = 0;
		arr.buffer = new js_html_compat_ArrayBuffer(arr);
	} else if(js_Boot.__instanceof(arg1,js_html_compat_ArrayBuffer)) {
		var buffer = arg1;
		if(offset == null) offset = 0;
		if(length == null) length = buffer.byteLength - offset;
		if(offset == 0) arr = buffer.a; else arr = buffer.a.slice(offset,offset + length);
		arr.byteLength = arr.length;
		arr.byteOffset = offset;
		arr.buffer = buffer;
	} else if((arg1 instanceof Array) && arg1.__enum__ == null) {
		arr = arg1.slice();
		arr.byteLength = arr.length;
		arr.byteOffset = 0;
		arr.buffer = new js_html_compat_ArrayBuffer(arr);
	} else throw new js__$Boot_HaxeError("TODO " + Std.string(arg1));
	arr.subarray = js_html_compat_Uint8Array._subarray;
	arr.set = js_html_compat_Uint8Array._set;
	return arr;
};
js_html_compat_Uint8Array._set = function(arg,offset) {
	var t = this;
	if(js_Boot.__instanceof(arg.buffer,js_html_compat_ArrayBuffer)) {
		var a = arg;
		if(arg.byteLength + offset > t.byteLength) throw new js__$Boot_HaxeError("set() outside of range");
		var _g1 = 0;
		var _g = arg.byteLength;
		while(_g1 < _g) {
			var i = _g1++;
			t[i + offset] = a[i];
		}
	} else if((arg instanceof Array) && arg.__enum__ == null) {
		var a1 = arg;
		if(a1.length + offset > t.byteLength) throw new js__$Boot_HaxeError("set() outside of range");
		var _g11 = 0;
		var _g2 = a1.length;
		while(_g11 < _g2) {
			var i1 = _g11++;
			t[i1 + offset] = a1[i1];
		}
	} else throw new js__$Boot_HaxeError("TODO");
};
js_html_compat_Uint8Array._subarray = function(start,end) {
	var t = this;
	var a = js_html_compat_Uint8Array._new(t.slice(start,end));
	a.byteOffset = start;
	return a;
};
var luxe_Audio = function(_core) {
	this.core = _core;
};
luxe_Audio.__name__ = true;
luxe_Audio.prototype = {
	init: function() {
		null;
	}
	,destroy: function() {
		null;
	}
	,create: function(_id,_name,_streaming) {
		if(_streaming == null) _streaming = false;
		if(_name == null) _name = "";
		return this.core.app.audio.create(_id,_name,_streaming);
	}
	,create_from_bytes: function(_id,_name,_bytes) {
		if(_name == null) _name = "";
		return this.core.app.audio.create_from_bytes(_id,_name,_bytes);
	}
	,uncreate: function(_name) {
		this.core.app.audio.uncreate(_name);
		return;
	}
	,on: function(_name,_event,_handler) {
		this.core.app.audio.on(_name,_event,_handler);
		return;
	}
	,off: function(_name,_event,_handler) {
		this.core.app.audio.off(_name,_event,_handler);
		return;
	}
	,get: function(_name) {
		return this.core.app.audio.get(_name);
	}
	,exists: function(_name) {
		return this.get(_name) != null;
	}
	,on_complete: function(_name,handler) {
	}
	,loop: function(_name) {
		this.core.app.audio.loop(_name);
		return;
	}
	,stop: function(_name) {
		this.core.app.audio.stop(_name);
		return;
	}
	,play: function(_name) {
		this.core.app.audio.play(_name);
		return;
	}
	,pause: function(_name) {
		this.core.app.audio.pause(_name);
		return;
	}
	,toggle: function(_name) {
		this.core.app.audio.toggle(_name);
		return;
	}
	,volume: function(_name,_volume) {
		return this.core.app.audio.volume(_name,_volume);
	}
	,pan: function(_name,_pan) {
		return this.core.app.audio.pan(_name,_pan);
	}
	,pitch: function(_name,_pitch) {
		return this.core.app.audio.pitch(_name,_pitch);
	}
	,position: function(_name,_position) {
		return this.core.app.audio.position(_name,_position);
	}
	,duration: function(_name) {
		return this.core.app.audio.duration(_name);
	}
	,process: function() {
	}
	,__class__: luxe_Audio
};
var luxe_SizeMode = { __ename__ : true, __constructs__ : ["fit","cover","contain"] };
luxe_SizeMode.fit = ["fit",0];
luxe_SizeMode.fit.toString = $estr;
luxe_SizeMode.fit.__enum__ = luxe_SizeMode;
luxe_SizeMode.cover = ["cover",1];
luxe_SizeMode.cover.toString = $estr;
luxe_SizeMode.cover.__enum__ = luxe_SizeMode;
luxe_SizeMode.contain = ["contain",2];
luxe_SizeMode.contain.toString = $estr;
luxe_SizeMode.contain.__enum__ = luxe_SizeMode;
var luxe_Objects = function(_name,_id) {
	if(_id == null) _id = "";
	if(_name == null) _name = "";
	this.name = "";
	this.id = "";
	luxe_Emitter.call(this);
	this.name = _name;
	if(_id == "") this.id = Luxe.utils.uniqueid(); else this.id = _id;
};
luxe_Objects.__name__ = true;
luxe_Objects.__super__ = luxe_Emitter;
luxe_Objects.prototype = $extend(luxe_Emitter.prototype,{
	__class__: luxe_Objects
});
var luxe_Entity = function(_options,_pos_info) {
	this.component_count = 0;
	this.active = true;
	this.fixed_rate = 0;
	this.started = false;
	this.inited = false;
	this.destroyed = false;
	luxe_Objects.call(this,"entity");
	this.name += "." + this.id;
	this.options = _options;
	this._components = new luxe_components_Components(this);
	this.children = [];
	this.events = new luxe_Events();
	if(this.options != null && this.options.transform != null) this.set_transform(this.options.transform); else this.set_transform(new phoenix_Transform());
	this.get_transform().listen_pos($bind(this,this.set_pos_from_transform));
	this.get_transform().listen_scale($bind(this,this.set_scale_from_transform));
	this.get_transform().listen_origin($bind(this,this.set_origin_from_transform));
	this.get_transform().listen_parent($bind(this,this.set_parent_from_transform));
	this.get_transform().listen_rotation($bind(this,this.set_rotation_from_transform));
	if(this.options != null) {
		if(this.options.name_unique == null) this.options.name_unique = false;
		if(this.options.name != null) {
			this.name = this.options.name;
			if(this.options.name_unique) this.name += "." + this.id;
		}
		if(this.options.pos != null) {
			var _op = this.options.pos;
			this.set_pos(new phoenix_Vector(_op.x,_op.y,_op.z,_op.w));
		}
		if(this.options.scale != null) {
			var _os = this.options.scale;
			this.set_scale(new phoenix_Vector(_os.x,_os.y,_os.z,_os.w));
		}
		var _should_add = true;
		if(this.options.no_scene != null) {
			if(this.options.no_scene == true) {
				_should_add = false;
				null;
			}
		}
		if(this.options.parent != null) {
			_should_add = false;
			this.set_parent(this.options.parent);
			null;
		}
		if(_should_add) {
			if(this.options.scene != null) {
				this.set_scene(this.options.scene);
				null;
			} else {
				this.set_scene(Luxe.scene);
				null;
			}
		}
	} else {
		this.set_scene(Luxe.scene);
		null;
	}
	if(this.get_scene() != null) this.get_scene().add(this,_pos_info); else null;
	null;
};
luxe_Entity.__name__ = true;
luxe_Entity.__super__ = luxe_Objects;
luxe_Entity.prototype = $extend(luxe_Objects.prototype,{
	init: function() {
	}
	,update: function(dt) {
	}
	,onfixedupdate: function(rate) {
	}
	,onreset: function() {
	}
	,ondestroy: function() {
	}
	,onkeyup: function(event) {
	}
	,onkeydown: function(event) {
	}
	,ontextinput: function(event) {
	}
	,oninputdown: function(name,event) {
	}
	,oninputup: function(name,event) {
	}
	,onmousedown: function(event) {
	}
	,onmouseup: function(event) {
	}
	,onmousemove: function(event) {
	}
	,onmousewheel: function(event) {
	}
	,ontouchdown: function(event) {
	}
	,ontouchup: function(event) {
	}
	,ontouchmove: function(event) {
	}
	,ongamepadup: function(event) {
	}
	,ongamepaddown: function(event) {
	}
	,ongamepadaxis: function(event) {
	}
	,ongamepaddevice: function(event) {
	}
	,onwindowmoved: function(event) {
	}
	,onwindowresized: function(event) {
	}
	,onwindowsized: function(event) {
	}
	,onwindowminimized: function(event) {
	}
	,onwindowrestored: function(event) {
	}
	,add: function(_component) {
		this.component_count++;
		return this._components.add(_component);
	}
	,remove: function(_name) {
		this.component_count--;
		return this._components.remove(_name);
	}
	,get: function(_name,_in_children) {
		if(_in_children == null) _in_children = false;
		return this._components.get(_name,_in_children);
	}
	,get_any: function(_name,_in_children,_first_only) {
		if(_first_only == null) _first_only = true;
		if(_in_children == null) _in_children = false;
		return this._components.get_any(_name,_in_children,_first_only);
	}
	,has: function(_name) {
		return this._components.has(_name);
	}
	,_init: function() {
		this.init();
		this.emit(2,null,{ fileName : "Entity.hx", lineNumber : 291, className : "luxe.Entity", methodName : "_init"});
		if(this.component_count > 0) {
			var _g_index = 0;
			var _g_map = this._components.components;
			while(_g_index < _g_map._keys.length) {
				var _component = _g_map.get(_g_map._keys[_g_index++]);
				_component.init();
			}
		}
		if(this.children.length > 0) {
			var _g = 0;
			var _g1 = this.children;
			while(_g < _g1.length) {
				var _child = _g1[_g];
				++_g;
				_child._init();
			}
		}
		this.inited = true;
	}
	,_reset: function(_) {
		this.onreset();
		this.emit(3,null,{ fileName : "Entity.hx", lineNumber : 321, className : "luxe.Entity", methodName : "_reset"});
		if(this.component_count > 0) {
			var _g_index = 0;
			var _g_map = this._components.components;
			while(_g_index < _g_map._keys.length) {
				var _component = _g_map.get(_g_map._keys[_g_index++]);
				_component.onreset();
			}
		}
		if(this.children.length > 0) {
			var _g = 0;
			var _g1 = this.children;
			while(_g < _g1.length) {
				var _child = _g1[_g];
				++_g;
				_child._reset(_);
				null;
			}
		}
		this._set_fixed_rate_timer(this.fixed_rate,{ fileName : "Entity.hx", lineNumber : 339, className : "luxe.Entity", methodName : "_reset"});
		this.started = true;
	}
	,destroy: function(_from_parent) {
		if(_from_parent == null) _from_parent = false;
		if(this.children.length > 0) {
			var _g = 0;
			var _g1 = this.children;
			while(_g < _g1.length) {
				var _child = _g1[_g];
				++_g;
				_child.destroy(true);
			}
		}
		this.children = null;
		this.children = [];
		if(this.component_count > 0) {
			var _g_index = 0;
			var _g_map = this._components.components;
			while(_g_index < _g_map._keys.length) {
				var _component = _g_map.get(_g_map._keys[_g_index++]);
				_component.onremoved();
				_component.ondestroy();
			}
		}
		this.emit(6,null,{ fileName : "Entity.hx", lineNumber : 372, className : "luxe.Entity", methodName : "destroy"});
		this.ondestroy();
		if(this.get_parent() != null && !_from_parent) this.get_parent()._remove_child(this);
		if(this.fixed_rate_timer != null) {
			this.fixed_rate_timer.stop();
			this.fixed_rate_timer = null;
		}
		this.destroyed = true;
		this.inited = false;
		this.started = false;
		if(this.get_scene() != null) this.get_scene().remove(this);
		if(this.events != null) {
			this.events.destroy();
			this.events = null;
		}
	}
	,_update: function(dt) {
		if(this.destroyed) return;
		if(!this.get_active() || !this.inited || !this.started) return;
		this.get_transform().clean_check();
		this.update(dt);
		if(this.events != null) this.events.process();
		if(this.component_count > 0) {
			var _g_index = 0;
			var _g_map = this._components.components;
			while(_g_index < _g_map._keys.length) {
				var _component = _g_map.get(_g_map._keys[_g_index++]);
				_component.update(dt);
			}
		}
		if(this.children.length > 0) {
			var _g = 0;
			var _g1 = this.children;
			while(_g < _g1.length) {
				var _child = _g1[_g];
				++_g;
				_child._update(dt);
			}
		}
	}
	,_fixed_update: function() {
		if(this.destroyed) return;
		if(!this.get_active() || !this.inited || !this.started) return;
		this.emit(5,null,{ fileName : "Entity.hx", lineNumber : 460, className : "luxe.Entity", methodName : "_fixed_update"});
		this.onfixedupdate(this.fixed_rate);
		if(this.component_count > 0) {
			var _g_index = 0;
			var _g_map = this._components.components;
			while(_g_index < _g_map._keys.length) {
				var _component = _g_map.get(_g_map._keys[_g_index++]);
				_component.onfixedupdate(this.fixed_rate);
			}
		}
		if(this.children.length > 0) {
			var _g = 0;
			var _g1 = this.children;
			while(_g < _g1.length) {
				var _child = _g1[_g];
				++_g;
				_child._fixed_update();
			}
		}
	}
	,_find_emit_source: function() {
		var source = null;
		if(this.get_scene() != null) source = this.get_scene(); else if(this.get_parent() != null) {
			var looking = true;
			while(looking) if(this.get_parent().get_scene() == null) {
				if(this.get_parent().get_parent() == null) {
					haxe_Log.trace("   i / entity / " + "entity has no parent or scene, currently no core events will reach it.",{ fileName : "Entity.hx", lineNumber : 498, className : "luxe.Entity", methodName : "_find_emit_source"});
					looking = false;
					break;
				} else {
				}
			} else {
				source = this.get_parent().get_scene();
				looking = false;
				break;
			}
		} else haxe_Log.trace("   i / entity / " + "entity has no parent or scene, currently no core events will reach it.",{ fileName : "Entity.hx", lineNumber : 517, className : "luxe.Entity", methodName : "_find_emit_source"});
		return source;
	}
	,_listen: function(_event,_handler,_self) {
		if(_self == null) _self = false;
		if(!_self) this.on(_event,_handler,{ fileName : "Entity.hx", lineNumber : 536, className : "luxe.Entity", methodName : "_listen"});
		var source = this._find_emit_source();
		if(source != null) switch(_event) {
		case 11:
			source.on(_event,$bind(this,this._keyup),{ fileName : "Entity.hx", lineNumber : 546, className : "luxe.Entity", methodName : "_listen"});
			break;
		case 10:
			source.on(_event,$bind(this,this._keydown),{ fileName : "Entity.hx", lineNumber : 547, className : "luxe.Entity", methodName : "_listen"});
			break;
		case 12:
			source.on(_event,$bind(this,this._textinput),{ fileName : "Entity.hx", lineNumber : 548, className : "luxe.Entity", methodName : "_listen"});
			break;
		case 15:
			source.on(_event,$bind(this,this._mousedown),{ fileName : "Entity.hx", lineNumber : 550, className : "luxe.Entity", methodName : "_listen"});
			break;
		case 16:
			source.on(_event,$bind(this,this._mouseup),{ fileName : "Entity.hx", lineNumber : 551, className : "luxe.Entity", methodName : "_listen"});
			break;
		case 17:
			source.on(_event,$bind(this,this._mousemove),{ fileName : "Entity.hx", lineNumber : 552, className : "luxe.Entity", methodName : "_listen"});
			break;
		case 18:
			source.on(_event,$bind(this,this._mousewheel),{ fileName : "Entity.hx", lineNumber : 553, className : "luxe.Entity", methodName : "_listen"});
			break;
		case 19:
			source.on(_event,$bind(this,this._touchdown),{ fileName : "Entity.hx", lineNumber : 555, className : "luxe.Entity", methodName : "_listen"});
			break;
		case 20:
			source.on(_event,$bind(this,this._touchup),{ fileName : "Entity.hx", lineNumber : 556, className : "luxe.Entity", methodName : "_listen"});
			break;
		case 21:
			source.on(_event,$bind(this,this._touchmove),{ fileName : "Entity.hx", lineNumber : 557, className : "luxe.Entity", methodName : "_listen"});
			break;
		case 14:
			source.on(_event,$bind(this,this._inputup),{ fileName : "Entity.hx", lineNumber : 559, className : "luxe.Entity", methodName : "_listen"});
			break;
		case 13:
			source.on(_event,$bind(this,this._inputdown),{ fileName : "Entity.hx", lineNumber : 560, className : "luxe.Entity", methodName : "_listen"});
			break;
		case 23:
			source.on(_event,$bind(this,this._gamepaddown),{ fileName : "Entity.hx", lineNumber : 562, className : "luxe.Entity", methodName : "_listen"});
			break;
		case 24:
			source.on(_event,$bind(this,this._gamepadup),{ fileName : "Entity.hx", lineNumber : 563, className : "luxe.Entity", methodName : "_listen"});
			break;
		case 22:
			source.on(_event,$bind(this,this._gamepadaxis),{ fileName : "Entity.hx", lineNumber : 564, className : "luxe.Entity", methodName : "_listen"});
			break;
		case 25:
			source.on(_event,$bind(this,this._gamepaddevice),{ fileName : "Entity.hx", lineNumber : 565, className : "luxe.Entity", methodName : "_listen"});
			break;
		case 27:
			source.on(_event,$bind(this,this._windowmoved),{ fileName : "Entity.hx", lineNumber : 567, className : "luxe.Entity", methodName : "_listen"});
			break;
		case 28:
			source.on(_event,$bind(this,this._windowresized),{ fileName : "Entity.hx", lineNumber : 568, className : "luxe.Entity", methodName : "_listen"});
			break;
		case 29:
			source.on(_event,$bind(this,this._windowsized),{ fileName : "Entity.hx", lineNumber : 569, className : "luxe.Entity", methodName : "_listen"});
			break;
		case 30:
			source.on(_event,$bind(this,this._windowminimized),{ fileName : "Entity.hx", lineNumber : 570, className : "luxe.Entity", methodName : "_listen"});
			break;
		case 31:
			source.on(_event,$bind(this,this._windowrestored),{ fileName : "Entity.hx", lineNumber : 571, className : "luxe.Entity", methodName : "_listen"});
			break;
		}
	}
	,_unlisten: function(_event,_handler,_self) {
		if(_self == null) _self = false;
		var source = this._find_emit_source();
		if(!_self) this.off(_event,_handler,{ fileName : "Entity.hx", lineNumber : 585, className : "luxe.Entity", methodName : "_unlisten"});
		if(source != null) switch(_event) {
		case 11:
			source.off(_event,$bind(this,this._keyup),{ fileName : "Entity.hx", lineNumber : 591, className : "luxe.Entity", methodName : "_unlisten"});
			break;
		case 10:
			source.off(_event,$bind(this,this._keydown),{ fileName : "Entity.hx", lineNumber : 592, className : "luxe.Entity", methodName : "_unlisten"});
			break;
		case 12:
			source.off(_event,$bind(this,this._textinput),{ fileName : "Entity.hx", lineNumber : 593, className : "luxe.Entity", methodName : "_unlisten"});
			break;
		case 15:
			source.off(_event,$bind(this,this._mousedown),{ fileName : "Entity.hx", lineNumber : 595, className : "luxe.Entity", methodName : "_unlisten"});
			break;
		case 16:
			source.off(_event,$bind(this,this._mouseup),{ fileName : "Entity.hx", lineNumber : 596, className : "luxe.Entity", methodName : "_unlisten"});
			break;
		case 17:
			source.off(_event,$bind(this,this._mousemove),{ fileName : "Entity.hx", lineNumber : 597, className : "luxe.Entity", methodName : "_unlisten"});
			break;
		case 18:
			source.off(_event,$bind(this,this._mousewheel),{ fileName : "Entity.hx", lineNumber : 598, className : "luxe.Entity", methodName : "_unlisten"});
			break;
		case 19:
			source.off(_event,$bind(this,this._touchdown),{ fileName : "Entity.hx", lineNumber : 600, className : "luxe.Entity", methodName : "_unlisten"});
			break;
		case 20:
			source.off(_event,$bind(this,this._touchup),{ fileName : "Entity.hx", lineNumber : 601, className : "luxe.Entity", methodName : "_unlisten"});
			break;
		case 21:
			source.off(_event,$bind(this,this._touchmove),{ fileName : "Entity.hx", lineNumber : 602, className : "luxe.Entity", methodName : "_unlisten"});
			break;
		case 14:
			source.off(_event,$bind(this,this._inputup),{ fileName : "Entity.hx", lineNumber : 604, className : "luxe.Entity", methodName : "_unlisten"});
			break;
		case 13:
			source.off(_event,$bind(this,this._inputdown),{ fileName : "Entity.hx", lineNumber : 605, className : "luxe.Entity", methodName : "_unlisten"});
			break;
		case 23:
			source.off(_event,$bind(this,this._gamepaddown),{ fileName : "Entity.hx", lineNumber : 607, className : "luxe.Entity", methodName : "_unlisten"});
			break;
		case 24:
			source.off(_event,$bind(this,this._gamepadup),{ fileName : "Entity.hx", lineNumber : 608, className : "luxe.Entity", methodName : "_unlisten"});
			break;
		case 22:
			source.off(_event,$bind(this,this._gamepadaxis),{ fileName : "Entity.hx", lineNumber : 609, className : "luxe.Entity", methodName : "_unlisten"});
			break;
		case 25:
			source.off(_event,$bind(this,this._gamepaddevice),{ fileName : "Entity.hx", lineNumber : 610, className : "luxe.Entity", methodName : "_unlisten"});
			break;
		case 27:
			source.off(_event,$bind(this,this._windowmoved),{ fileName : "Entity.hx", lineNumber : 612, className : "luxe.Entity", methodName : "_unlisten"});
			break;
		case 28:
			source.off(_event,$bind(this,this._windowresized),{ fileName : "Entity.hx", lineNumber : 613, className : "luxe.Entity", methodName : "_unlisten"});
			break;
		case 29:
			source.off(_event,$bind(this,this._windowsized),{ fileName : "Entity.hx", lineNumber : 614, className : "luxe.Entity", methodName : "_unlisten"});
			break;
		case 30:
			source.off(_event,$bind(this,this._windowminimized),{ fileName : "Entity.hx", lineNumber : 615, className : "luxe.Entity", methodName : "_unlisten"});
			break;
		case 31:
			source.off(_event,$bind(this,this._windowrestored),{ fileName : "Entity.hx", lineNumber : 616, className : "luxe.Entity", methodName : "_unlisten"});
			break;
		}
	}
	,_detach_scene: function() {
		if(this.get_scene() != null) {
			this.get_scene().off(3,$bind(this,this._reset),{ fileName : "Entity.hx", lineNumber : 630, className : "luxe.Entity", methodName : "_detach_scene"});
			this.get_scene().off(6,$bind(this,this.destroy),{ fileName : "Entity.hx", lineNumber : 631, className : "luxe.Entity", methodName : "_detach_scene"});
			this.get_scene().off(11,$bind(this,this._keyup),{ fileName : "Entity.hx", lineNumber : 634, className : "luxe.Entity", methodName : "_detach_scene"});
			this.get_scene().off(10,$bind(this,this._keydown),{ fileName : "Entity.hx", lineNumber : 635, className : "luxe.Entity", methodName : "_detach_scene"});
			this.get_scene().off(12,$bind(this,this._textinput),{ fileName : "Entity.hx", lineNumber : 636, className : "luxe.Entity", methodName : "_detach_scene"});
			this.get_scene().off(15,$bind(this,this._mousedown),{ fileName : "Entity.hx", lineNumber : 637, className : "luxe.Entity", methodName : "_detach_scene"});
			this.get_scene().off(16,$bind(this,this._mouseup),{ fileName : "Entity.hx", lineNumber : 638, className : "luxe.Entity", methodName : "_detach_scene"});
			this.get_scene().off(17,$bind(this,this._mousemove),{ fileName : "Entity.hx", lineNumber : 639, className : "luxe.Entity", methodName : "_detach_scene"});
			this.get_scene().off(18,$bind(this,this._mousewheel),{ fileName : "Entity.hx", lineNumber : 640, className : "luxe.Entity", methodName : "_detach_scene"});
			this.get_scene().off(19,$bind(this,this._touchdown),{ fileName : "Entity.hx", lineNumber : 641, className : "luxe.Entity", methodName : "_detach_scene"});
			this.get_scene().off(20,$bind(this,this._touchup),{ fileName : "Entity.hx", lineNumber : 642, className : "luxe.Entity", methodName : "_detach_scene"});
			this.get_scene().off(21,$bind(this,this._touchmove),{ fileName : "Entity.hx", lineNumber : 643, className : "luxe.Entity", methodName : "_detach_scene"});
			this.get_scene().off(14,$bind(this,this._inputup),{ fileName : "Entity.hx", lineNumber : 644, className : "luxe.Entity", methodName : "_detach_scene"});
			this.get_scene().off(13,$bind(this,this._inputdown),{ fileName : "Entity.hx", lineNumber : 645, className : "luxe.Entity", methodName : "_detach_scene"});
			this.get_scene().off(23,$bind(this,this._gamepaddown),{ fileName : "Entity.hx", lineNumber : 646, className : "luxe.Entity", methodName : "_detach_scene"});
			this.get_scene().off(24,$bind(this,this._gamepadup),{ fileName : "Entity.hx", lineNumber : 647, className : "luxe.Entity", methodName : "_detach_scene"});
			this.get_scene().off(22,$bind(this,this._gamepadaxis),{ fileName : "Entity.hx", lineNumber : 648, className : "luxe.Entity", methodName : "_detach_scene"});
			this.get_scene().off(25,$bind(this,this._gamepaddevice),{ fileName : "Entity.hx", lineNumber : 649, className : "luxe.Entity", methodName : "_detach_scene"});
			this.get_scene().off(27,$bind(this,this._windowmoved),{ fileName : "Entity.hx", lineNumber : 650, className : "luxe.Entity", methodName : "_detach_scene"});
			this.get_scene().off(28,$bind(this,this._windowresized),{ fileName : "Entity.hx", lineNumber : 651, className : "luxe.Entity", methodName : "_detach_scene"});
			this.get_scene().off(29,$bind(this,this._windowsized),{ fileName : "Entity.hx", lineNumber : 652, className : "luxe.Entity", methodName : "_detach_scene"});
			this.get_scene().off(30,$bind(this,this._windowminimized),{ fileName : "Entity.hx", lineNumber : 653, className : "luxe.Entity", methodName : "_detach_scene"});
			this.get_scene().off(31,$bind(this,this._windowrestored),{ fileName : "Entity.hx", lineNumber : 654, className : "luxe.Entity", methodName : "_detach_scene"});
		}
	}
	,_attach_scene: function() {
		if(this.get_scene() != null) {
			this.get_scene().on(3,$bind(this,this._reset),{ fileName : "Entity.hx", lineNumber : 663, className : "luxe.Entity", methodName : "_attach_scene"});
			this.get_scene().on(6,$bind(this,this.destroy),{ fileName : "Entity.hx", lineNumber : 664, className : "luxe.Entity", methodName : "_attach_scene"});
		}
	}
	,_keyup: function(_event) {
		if(!this.get_active() || !this.inited || !this.started) return;
		this.onkeyup(_event);
		this.emit(11,_event,{ fileName : "Entity.hx", lineNumber : 680, className : "luxe.Entity", methodName : "_keyup"});
	}
	,_keydown: function(_event) {
		if(!this.get_active() || !this.inited || !this.started) return;
		this.onkeydown(_event);
		this.emit(10,_event,{ fileName : "Entity.hx", lineNumber : 693, className : "luxe.Entity", methodName : "_keydown"});
	}
	,_textinput: function(_event) {
		if(!this.get_active() || !this.inited || !this.started) return;
		this.ontextinput(_event);
		this.emit(12,_event,{ fileName : "Entity.hx", lineNumber : 706, className : "luxe.Entity", methodName : "_textinput"});
	}
	,_mousedown: function(_event) {
		if(!this.get_active() || !this.inited || !this.started) return;
		this.onmousedown(_event);
		this.emit(15,_event,{ fileName : "Entity.hx", lineNumber : 722, className : "luxe.Entity", methodName : "_mousedown"});
	}
	,_mouseup: function(_event) {
		if(!this.get_active() || !this.inited || !this.started) return;
		this.onmouseup(_event);
		this.emit(16,_event,{ fileName : "Entity.hx", lineNumber : 736, className : "luxe.Entity", methodName : "_mouseup"});
	}
	,_mousewheel: function(_event) {
		if(!this.get_active() || !this.inited || !this.started) return;
		this.onmousewheel(_event);
		this.emit(18,_event,{ fileName : "Entity.hx", lineNumber : 749, className : "luxe.Entity", methodName : "_mousewheel"});
	}
	,_mousemove: function(_event) {
		if(!this.get_active() || !this.inited || !this.started) return;
		this.onmousemove(_event);
		this.emit(17,_event,{ fileName : "Entity.hx", lineNumber : 762, className : "luxe.Entity", methodName : "_mousemove"});
	}
	,_touchdown: function(_event) {
		if(!this.get_active() || !this.inited || !this.started) return;
		this.ontouchdown(_event);
		this.emit(19,_event,{ fileName : "Entity.hx", lineNumber : 776, className : "luxe.Entity", methodName : "_touchdown"});
	}
	,_touchup: function(_event) {
		if(!this.get_active() || !this.inited || !this.started) return;
		this.ontouchup(_event);
		this.emit(20,_event,{ fileName : "Entity.hx", lineNumber : 789, className : "luxe.Entity", methodName : "_touchup"});
	}
	,_touchmove: function(_event) {
		if(!this.get_active() || !this.inited || !this.started) return;
		this.ontouchmove(_event);
		this.emit(21,_event,{ fileName : "Entity.hx", lineNumber : 802, className : "luxe.Entity", methodName : "_touchmove"});
	}
	,_gamepadaxis: function(_event) {
		if(!this.get_active() || !this.inited || !this.started) return;
		this.ongamepadaxis(_event);
		this.emit(22,_event,{ fileName : "Entity.hx", lineNumber : 816, className : "luxe.Entity", methodName : "_gamepadaxis"});
	}
	,_gamepaddown: function(_event) {
		if(!this.get_active() || !this.inited || !this.started) return;
		this.ongamepaddown(_event);
		this.emit(23,_event,{ fileName : "Entity.hx", lineNumber : 829, className : "luxe.Entity", methodName : "_gamepaddown"});
	}
	,_gamepadup: function(_event) {
		if(!this.get_active() || !this.inited || !this.started) return;
		this.ongamepadup(_event);
		this.emit(24,_event,{ fileName : "Entity.hx", lineNumber : 842, className : "luxe.Entity", methodName : "_gamepadup"});
	}
	,_gamepaddevice: function(_event) {
		if(!this.get_active() || !this.inited || !this.started) return;
		this.ongamepaddevice(_event);
		this.emit(25,_event,{ fileName : "Entity.hx", lineNumber : 855, className : "luxe.Entity", methodName : "_gamepaddevice"});
	}
	,_windowmoved: function(_event) {
		if(!this.get_active() || !this.inited || !this.started) return;
		this.onwindowmoved(_event);
		this.emit(27,_event,{ fileName : "Entity.hx", lineNumber : 870, className : "luxe.Entity", methodName : "_windowmoved"});
	}
	,_windowresized: function(_event) {
		if(!this.get_active() || !this.inited || !this.started) return;
		this.onwindowresized(_event);
		this.emit(28,_event,{ fileName : "Entity.hx", lineNumber : 883, className : "luxe.Entity", methodName : "_windowresized"});
	}
	,_windowsized: function(_event) {
		if(!this.get_active() || !this.inited || !this.started) return;
		this.onwindowsized(_event);
		this.emit(29,_event,{ fileName : "Entity.hx", lineNumber : 896, className : "luxe.Entity", methodName : "_windowsized"});
	}
	,_windowminimized: function(_event) {
		if(!this.get_active() || !this.inited || !this.started) return;
		this.onwindowminimized(_event);
		this.emit(30,_event,{ fileName : "Entity.hx", lineNumber : 909, className : "luxe.Entity", methodName : "_windowminimized"});
	}
	,_windowrestored: function(_event) {
		if(!this.get_active() || !this.inited || !this.started) return;
		this.onwindowrestored(_event);
		this.emit(31,_event,{ fileName : "Entity.hx", lineNumber : 922, className : "luxe.Entity", methodName : "_windowrestored"});
	}
	,_inputdown: function(_event) {
		if(!this.get_active() || !this.inited || !this.started) return;
		this.oninputdown(_event.name,_event.event);
		this.emit(13,_event,{ fileName : "Entity.hx", lineNumber : 937, className : "luxe.Entity", methodName : "_inputdown"});
	}
	,_inputup: function(_event) {
		if(!this.get_active() || !this.inited || !this.started) return;
		this.oninputup(_event.name,_event.event);
		this.emit(14,_event,{ fileName : "Entity.hx", lineNumber : 950, className : "luxe.Entity", methodName : "_inputup"});
	}
	,get_fixed_rate: function() {
		return this.fixed_rate;
	}
	,set_fixed_rate: function(_rate) {
		this.fixed_rate = _rate;
		if(this.started) {
			if(this.fixed_rate_timer != null) {
				this.fixed_rate_timer.stop();
				this.fixed_rate_timer = null;
			}
			if(_rate != 0 && this.get_parent() == null && !this.destroyed) {
				this.fixed_rate_timer = new snow_utils_Timer(_rate);
				this.fixed_rate_timer.run = $bind(this,this._fixed_update);
			}
		}
		return this.fixed_rate;
	}
	,_stop_fixed_rate_timer: function() {
		if(this.fixed_rate_timer != null) {
			this.fixed_rate_timer.stop();
			this.fixed_rate_timer = null;
		}
	}
	,_set_fixed_rate_timer: function(_rate,_pos) {
		if(this.fixed_rate_timer != null) {
			this.fixed_rate_timer.stop();
			this.fixed_rate_timer = null;
		}
		if(_rate != 0 && this.get_parent() == null && !this.destroyed) {
			this.fixed_rate_timer = new snow_utils_Timer(_rate);
			this.fixed_rate_timer.run = $bind(this,this._fixed_update);
		}
	}
	,get_components: function() {
		return this._components.components;
	}
	,_add_child: function(child) {
		this.children.push(child);
		if(child.get_scene() != null) {
			var removed = child.get_scene().remove(child);
		} else null;
	}
	,_remove_child: function(child) {
		HxOverrides.remove(this.children,child);
	}
	,set_pos_from_transform: function(_pos) {
		if(this.component_count > 0) {
			var _g_index = 0;
			var _g_map = this._components.components;
			while(_g_index < _g_map._keys.length) {
				var _component = _g_map.get(_g_map._keys[_g_index++]);
				_component.entity_pos_change(_pos);
			}
		}
	}
	,set_rotation_from_transform: function(_rotation) {
		if(this.component_count > 0) {
			var _g_index = 0;
			var _g_map = this._components.components;
			while(_g_index < _g_map._keys.length) {
				var _component = _g_map.get(_g_map._keys[_g_index++]);
				_component.entity_rotation_change(_rotation);
			}
		}
	}
	,set_scale_from_transform: function(_scale) {
		if(this.component_count > 0) {
			var _g_index = 0;
			var _g_map = this._components.components;
			while(_g_index < _g_map._keys.length) {
				var _component = _g_map.get(_g_map._keys[_g_index++]);
				_component.entity_scale_change(_scale);
			}
		}
	}
	,set_origin_from_transform: function(_origin) {
		if(this.component_count > 0) {
			var _g_index = 0;
			var _g_map = this._components.components;
			while(_g_index < _g_map._keys.length) {
				var _component = _g_map.get(_g_map._keys[_g_index++]);
				_component.entity_origin_change(_origin);
			}
		}
	}
	,set_parent_from_transform: function(_parent) {
		if(this.component_count > 0) {
			var _g_index = 0;
			var _g_map = this._components.components;
			while(_g_index < _g_map._keys.length) {
				var _component = _g_map.get(_g_map._keys[_g_index++]);
				_component.entity_parent_change(_parent);
			}
		}
	}
	,set_pos: function(_p) {
		return this.get_transform().set_pos(_p);
	}
	,get_pos: function() {
		return this.get_transform().get_pos();
	}
	,set_rotation: function(_r) {
		return this.get_transform().set_rotation(_r);
	}
	,get_rotation: function() {
		return this.get_transform().get_rotation();
	}
	,set_scale: function(_s) {
		return this.get_transform().set_scale(_s);
	}
	,get_scale: function() {
		return this.get_transform().get_scale();
	}
	,set_origin: function(_origin) {
		return this.get_transform().set_origin(_origin);
	}
	,get_origin: function() {
		return this.get_transform().get_origin();
	}
	,set_transform: function(_transform) {
		return this.transform = _transform;
	}
	,get_transform: function() {
		return this.transform;
	}
	,set_parent: function(other) {
		if(this.get_parent() != null) this.get_parent()._remove_child(this);
		this.parent = other;
		if(this.get_parent() != null) {
			this.get_parent()._add_child(this);
			this.get_transform().set_parent(this.get_parent().get_transform());
		} else this.get_transform().set_parent(null);
		return this.get_parent();
	}
	,get_parent: function() {
		return this.parent;
	}
	,set_scene: function(_scene) {
		this._detach_scene();
		this.scene = _scene;
		this._attach_scene();
		return this.get_scene();
	}
	,get_scene: function() {
		return this.scene;
	}
	,set_active: function(_active) {
		return this.active = _active;
	}
	,get_active: function() {
		return this.active;
	}
	,__class__: luxe_Entity
	,__properties__: {set_origin:"set_origin",get_origin:"get_origin",set_scale:"set_scale",get_scale:"get_scale",set_rotation:"set_rotation",get_rotation:"get_rotation",set_pos:"set_pos",get_pos:"get_pos",set_transform:"set_transform",get_transform:"get_transform",set_active:"set_active",get_active:"get_active",set_scene:"set_scene",get_scene:"get_scene",set_parent:"set_parent",get_parent:"get_parent",set_fixed_rate:"set_fixed_rate",get_fixed_rate:"get_fixed_rate",get_components:"get_components"}
});
var luxe_Camera = function(options) {
	this._connected = false;
	this.minimum_shake = 0.1;
	this.shaking = false;
	this._size_factor = new phoenix_Vector();
	this._rotation_radian = new phoenix_Vector();
	this._rotation_cache = new phoenix_Quaternion();
	this.set_size_mode(luxe_SizeMode.fit);
	var _name = "untitled camera";
	if(options != null) {
		if(options.name != null) _name = options.name;
	} else options = { no_scene : false};
	if(options.view == null) this.view = new phoenix_Camera(options); else this.view = options.view;
	luxe_Entity.call(this,{ name : _name, no_scene : options.no_scene},{ fileName : "Camera.hx", lineNumber : 91, className : "luxe.Camera", methodName : "new"});
	this._final_pos = this.view.get_pos();
};
luxe_Camera.__name__ = true;
luxe_Camera.__super__ = luxe_Entity;
luxe_Camera.prototype = $extend(luxe_Entity.prototype,{
	get_viewport: function() {
		return this.view.get_viewport();
	}
	,set_viewport: function(_v) {
		return this.view.set_viewport(_v);
	}
	,get_center: function() {
		return this.view.get_center();
	}
	,set_center: function(_c) {
		this.set_pos(new phoenix_Vector(_c.x - this.get_viewport().w / 2,_c.y - this.get_viewport().h / 2));
		return this.view.set_center(_c);
	}
	,get_minimum_zoom: function() {
		return this.view.minimum_zoom;
	}
	,set_minimum_zoom: function(_m) {
		return this.view.minimum_zoom = _m;
	}
	,get_zoom: function() {
		return this.view.zoom;
	}
	,set_zoom: function(_z) {
		this.view.set_zoom(_z);
		if(this.get_size() != null) {
			var _g = this.view.get_scale();
			_g.set_x(_g.x * (1 / this._size_factor.x));
			var _g1 = this.view.get_scale();
			_g1.set_y(_g1.y * (1 / this._size_factor.y));
		}
		return this.view.zoom;
	}
	,get_size: function() {
		return this.size;
	}
	,get_size_mode: function() {
		return this.size_mode;
	}
	,set_size_mode: function(_m) {
		if(this.get_size_mode() != null) {
			this.size_mode = _m;
			if(this.get_size() != null) this.set_size(this.get_size());
		}
		return this.size_mode = _m;
	}
	,_onwindowsized: function(_event) {
		if(this.get_size() != null) {
			this.set_viewport(new phoenix_Rectangle(this.get_viewport().x,this.get_viewport().y,_event.event.x,_event.event.y));
			this.set_size(this.get_size());
		}
	}
	,set_size: function(_size) {
		if(_size == null) {
			this.set_center(new phoenix_Vector(this.get_viewport().w / 2,this.get_viewport().h / 2));
			this.size = _size;
			this._size_factor.set_x(this._size_factor.set_y(1));
			this.set_zoom(this.get_zoom());
			this._connected = false;
			Luxe.off(29,$bind(this,this._onwindowsized));
			return this.get_size();
		}
		if(!this._connected) {
			Luxe.on(29,$bind(this,this._onwindowsized));
			this._connected = true;
		}
		var _ratio_x = this.get_viewport().w / _size.x;
		var _ratio_y = this.get_viewport().h / _size.y;
		var _shortest = Math.max(_ratio_x,_ratio_y);
		var _longest = Math.min(_ratio_x,_ratio_y);
		var _g = this.get_size_mode();
		switch(_g[1]) {
		case 0:
			_ratio_x = _ratio_y = _longest;
			break;
		case 1:
			_ratio_x = _ratio_y = _shortest;
			break;
		case 2:
			break;
		}
		this._size_factor.set_x(_ratio_x);
		this._size_factor.set_y(_ratio_y);
		this.view.get_scale().set_x(1 / (this._size_factor.x * this.get_zoom()));
		this.view.get_scale().set_y(1 / (this._size_factor.y * this.get_zoom()));
		this.set_center(new phoenix_Vector(_size.x / 2,_size.y / 2));
		return this.size = new phoenix_Vector(_size.x,_size.y,_size.z,_size.w);
	}
	,focus: function(_p,_t,oncomplete) {
		if(_t == null) _t = 0.6;
		var _g = this;
		luxe_tween_Actuate.tween(this.view.get_center(),_t,{ x : _p.x, y : _p.y},true).onComplete(oncomplete).ease(luxe_tween_easing_Quad.get_easeInOut()).onUpdate(function() {
			_g.get_transform().get_pos().set_xy(_g.view.get_pos().x,_g.view.get_pos().y);
		});
	}
	,screen_point_to_world: function(_vector) {
		return this.view.screen_point_to_world(_vector);
	}
	,world_point_to_screen: function(_vector,_viewport) {
		return this.view.world_point_to_screen(_vector,_viewport);
	}
	,set_pos_from_transform: function(_pos) {
		var vw = this.view.get_viewport().w;
		var vh = this.view.get_viewport().h;
		var hvw = vw / 2;
		var hvh = vh / 2;
		var _px = _pos.x;
		var _py = _pos.y;
		if(this.bounds != null) {
			if(_px < this.bounds.x) _px = this.bounds.x;
			if(_py < this.bounds.y) _py = this.bounds.y;
			if(_px + hvw > this.bounds.w - vw) _px = this.bounds.w - vw - hvw;
			if(_py + hvh > this.bounds.h - vh) _py = this.bounds.h - vh - hvh;
		}
		var prev = _pos.ignore_listeners;
		_pos.ignore_listeners = true;
		_pos.set_xy(_px,_py);
		_pos.ignore_listeners = prev;
		luxe_Entity.prototype.set_pos_from_transform.call(this,_pos);
		this.update_view_pos = _pos;
	}
	,set_rotation_from_transform: function(_rotation) {
		luxe_Entity.prototype.set_rotation_from_transform.call(this,_rotation);
		if(this.view != null) this.view.set_rotation(_rotation);
	}
	,set_scale_from_transform: function(_scale) {
		luxe_Entity.prototype.set_scale_from_transform.call(this,_scale);
		if(this.view != null) this.view.set_scale(_scale);
	}
	,shake: function(amount) {
		this.shake_amount = amount;
		this.shaking = true;
	}
	,update: function(dt) {
		if(this.shaking) {
			this._final_pos.set_xyz(this.get_transform().get_pos().x,this.get_transform().get_pos().y,this.get_transform().get_pos().z);
			this.shake_vector = Luxe.utils.geometry.random_point_in_unit_circle();
			var _g = this.shake_vector;
			_g.set_x(_g.x * this.shake_amount);
			var _g1 = this.shake_vector;
			_g1.set_y(_g1.y * this.shake_amount);
			var _g2 = this.shake_vector;
			_g2.set_z(_g2.z * this.shake_amount);
			this.shake_amount *= 0.9;
			if(this.shake_amount <= this.minimum_shake) {
				this.shake_amount = 0;
				this.shaking = false;
			}
			this._final_pos.set_xyz(this._final_pos.x + this.shake_vector.x,this._final_pos.y + this.shake_vector.y,this._final_pos.z + this.shake_vector.z);
			this.update_view_pos = this._final_pos;
		}
		if(this.update_view_pos != null && this.view != null) {
			this.view.set_pos(this.update_view_pos.clone());
			this.update_view_pos = null;
		}
	}
	,init: function() {
	}
	,ondestroy: function() {
		luxe_Entity.prototype.ondestroy.call(this);
	}
	,__class__: luxe_Camera
	,__properties__: $extend(luxe_Entity.prototype.__properties__,{set_size_mode:"set_size_mode",get_size_mode:"get_size_mode",set_size:"set_size",get_size:"get_size",set_minimum_zoom:"set_minimum_zoom",get_minimum_zoom:"get_minimum_zoom",set_zoom:"set_zoom",get_zoom:"get_zoom",set_center:"set_center",get_center:"get_center",set_viewport:"set_viewport",get_viewport:"get_viewport"})
});
var luxe_ID = function(_name,_id) {
	if(_id == null) _id = "";
	if(_name == null) _name = "";
	this.name = "";
	this.name = _name;
	if(_id == "") this.id = Luxe.utils.uniqueid(); else this.id = _id;
};
luxe_ID.__name__ = true;
luxe_ID.prototype = {
	__class__: luxe_ID
};
var luxe_Component = function(_options) {
	var _name = "";
	if(_options != null) {
		if(_options.name != null) _name = _options.name;
	}
	luxe_ID.call(this,_name == ""?Luxe.utils.uniqueid():_name);
};
luxe_Component.__name__ = true;
luxe_Component.__super__ = luxe_ID;
luxe_Component.prototype = $extend(luxe_ID.prototype,{
	init: function() {
	}
	,update: function(dt) {
	}
	,onadded: function() {
	}
	,onremoved: function() {
	}
	,onfixedupdate: function(rate) {
	}
	,onreset: function() {
	}
	,ondestroy: function() {
	}
	,onkeyup: function(event) {
	}
	,onkeydown: function(event) {
	}
	,ontextinput: function(event) {
	}
	,oninputdown: function(event) {
	}
	,oninputup: function(event) {
	}
	,onmousedown: function(event) {
	}
	,onmouseup: function(event) {
	}
	,onmousemove: function(event) {
	}
	,onmousewheel: function(event) {
	}
	,ontouchdown: function(event) {
	}
	,ontouchup: function(event) {
	}
	,ontouchmove: function(event) {
	}
	,ongamepadup: function(event) {
	}
	,ongamepaddown: function(event) {
	}
	,ongamepadaxis: function(event) {
	}
	,ongamepaddevice: function(event) {
	}
	,onwindowmoved: function(event) {
	}
	,onwindowresized: function(event) {
	}
	,onwindowsized: function(event) {
	}
	,onwindowminimized: function(event) {
	}
	,onwindowrestored: function(event) {
	}
	,add: function(component) {
		return this.get_entity().add(component);
	}
	,remove: function(_name) {
		return this.get_entity().remove(_name);
	}
	,get: function(_name,in_children) {
		if(in_children == null) in_children = false;
		return this.get_entity().get(_name,in_children);
	}
	,get_any: function(_name,in_children,first_only) {
		if(first_only == null) first_only = true;
		if(in_children == null) in_children = false;
		return this.get_entity().get_any(_name,in_children,first_only);
	}
	,has: function(_name) {
		return this.get_entity().has(_name);
	}
	,_detach_entity: function() {
		if(this.get_entity() != null) {
		}
	}
	,_attach_entity: function() {
		if(this.get_entity() != null) {
		}
	}
	,set_entity: function(_entity) {
		this._detach_entity();
		this.entity = _entity;
		this._attach_entity();
		return this.get_entity();
	}
	,get_entity: function() {
		return this.entity;
	}
	,set_pos: function(_p) {
		return this.get_entity().get_transform().set_pos(_p);
	}
	,get_pos: function() {
		return this.get_entity().get_transform().get_pos();
	}
	,set_rotation: function(_r) {
		return this.get_entity().get_transform().set_rotation(_r);
	}
	,get_rotation: function() {
		return this.get_entity().get_transform().get_rotation();
	}
	,set_scale: function(_s) {
		return this.get_entity().get_transform().set_scale(_s);
	}
	,get_scale: function() {
		return this.get_entity().get_transform().get_scale();
	}
	,set_origin: function(_o) {
		return this.get_entity().get_transform().set_origin(_o);
	}
	,get_origin: function() {
		return this.get_entity().get_transform().get_origin();
	}
	,set_transform: function(_o) {
		return this.get_entity().set_transform(_o);
	}
	,get_transform: function() {
		return this.get_entity().get_transform();
	}
	,entity_pos_change: function(_pos) {
	}
	,entity_scale_change: function(_scale) {
	}
	,entity_rotation_change: function(_rotation) {
	}
	,entity_origin_change: function(_origin) {
	}
	,entity_parent_change: function(_parent) {
	}
	,__class__: luxe_Component
	,__properties__: {set_origin:"set_origin",get_origin:"get_origin",set_scale:"set_scale",get_scale:"get_scale",set_rotation:"set_rotation",get_rotation:"get_rotation",set_pos:"set_pos",get_pos:"get_pos",set_entity:"set_entity",get_entity:"get_entity"}
});
var snow_App = function() {
	this.next_render = 0;
	this.next_tick = 0;
	this.alpha = 1.0;
	this.cur_frame_start = 0.0;
	this.current_time = 0;
	this.last_frame_start = 0.0;
	this.delta_sim = 0.016666666666666666;
	this.delta_time = 0.016666666666666666;
	this.max_frame_time = 0.25;
	this.update_rate = 0;
	this.render_rate = 0.016666666666666666;
	this.fixed_delta = 0;
	this.timescale = 1;
};
snow_App.__name__ = true;
snow_App.prototype = {
	config: function(config) {
		return config;
	}
	,ready: function() {
	}
	,update: function(dt) {
	}
	,ondestroy: function() {
	}
	,onevent: function(event) {
	}
	,onkeydown: function(keycode,scancode,repeat,mod,timestamp,window_id) {
	}
	,onkeyup: function(keycode,scancode,repeat,mod,timestamp,window_id) {
	}
	,ontextinput: function(text,start,length,type,timestamp,window_id) {
	}
	,onmousedown: function(x,y,button,timestamp,window_id) {
	}
	,onmouseup: function(x,y,button,timestamp,window_id) {
	}
	,onmousewheel: function(x,y,timestamp,window_id) {
	}
	,onmousemove: function(x,y,xrel,yrel,timestamp,window_id) {
	}
	,ontouchdown: function(x,y,touch_id,timestamp) {
	}
	,ontouchup: function(x,y,touch_id,timestamp) {
	}
	,ontouchmove: function(x,y,dx,dy,touch_id,timestamp) {
	}
	,ongamepadaxis: function(gamepad,axis,value,timestamp) {
	}
	,ongamepaddown: function(gamepad,button,value,timestamp) {
	}
	,ongamepadup: function(gamepad,button,value,timestamp) {
	}
	,ongamepaddevice: function(gamepad,type,timestamp) {
	}
	,on_internal_init: function() {
		this.cur_frame_start = snow_Snow.core.timestamp();
		this.last_frame_start = this.cur_frame_start;
		this.current_time = 0;
		this.delta_time = 0.016;
	}
	,on_internal_update: function() {
		if(this.update_rate != 0) {
			if(this.next_tick < snow_Snow.core.timestamp()) this.next_tick = snow_Snow.core.timestamp() + this.update_rate; else return;
		}
		this.cur_frame_start = snow_Snow.core.timestamp();
		this.delta_time = this.cur_frame_start - this.last_frame_start;
		this.last_frame_start = this.cur_frame_start;
		if(this.delta_time > this.max_frame_time) this.delta_time = this.max_frame_time;
		var used_delta;
		if(this.fixed_delta == 0) used_delta = this.delta_time; else used_delta = this.fixed_delta;
		used_delta *= this.timescale;
		this.delta_sim = used_delta;
		this.current_time += used_delta;
		this.app.do_internal_update(used_delta);
	}
	,on_internal_render: function() {
		if(this.render_rate != 0) {
			if(this.next_render < snow_Snow.core.timestamp()) {
				this.app.render();
				this.next_render += this.render_rate;
			}
		}
	}
	,__class__: snow_App
};
var luxe_Core = function(_game,_config) {
	this.inited = false;
	this.has_shutdown = false;
	this.shutting_down = false;
	this.headless = false;
	this.console_visible = false;
	snow_App.call(this);
	this.appconfig = _config;
	this.game = _game;
	this.game.app = this;
	this.emitter = new luxe_Emitter();
	Luxe.core = this;
	Luxe.utils = new luxe_utils_Utils(this);
};
luxe_Core.__name__ = true;
luxe_Core.__super__ = snow_App;
luxe_Core.prototype = $extend(snow_App.prototype,{
	ready: function() {
		Luxe.version = haxe_Resource.getString("version");
		Luxe.build = Luxe.version + haxe_Resource.getString("build");
		haxe_Log.trace("     i / luxe / " + ("version " + Luxe.build),{ fileName : "Core.hx", lineNumber : 104, className : "luxe.Core", methodName : "ready"});
		this.init();
		this.game.ready();
		if(!this.shutting_down) {
			this.emitter.emit(2,null,{ fileName : "Core.hx", lineNumber : 121, className : "luxe.Core", methodName : "ready"});
			this.inited = true;
			this.physics.reset();
			if(!this.app.snow_config.has_loop) this.shutdown();
		}
	}
	,ondestroy: function() {
		this.shutting_down = true;
		haxe_Log.trace("     i / luxe / " + "shutting down...",{ fileName : "Core.hx", lineNumber : 141, className : "luxe.Core", methodName : "ondestroy"});
		this.game.ondestroy();
		this.emitter.emit(6,null,{ fileName : "Core.hx", lineNumber : 147, className : "luxe.Core", methodName : "ondestroy"});
		if(this.renderer != null) this.renderer.destroy();
		this.physics.destroy();
		this.input.destroy();
		this.audio.destroy();
		this.timer.destroy();
		this.events.destroy();
		this.debug.destroy();
		this.emitter = null;
		this.input = null;
		this.audio = null;
		this.events = null;
		this.timer = null;
		this.debug = null;
		Luxe.utils = null;
		this.has_shutdown = true;
		haxe_Log.trace("     i / luxe / " + "goodbye.",{ fileName : "Core.hx", lineNumber : 173, className : "luxe.Core", methodName : "ondestroy"});
	}
	,init: function() {
		Luxe.debug = this.debug = new luxe_Debug(this);
		Luxe.io = this.io = new luxe_IO(this);
		this.draw = new luxe_Draw(this);
		this.timer = new luxe_Timer(this);
		this.events = new luxe_Events();
		this.audio = new luxe_Audio(this);
		this.input = new luxe_Input(this);
		this.physics = new luxe_Physics(this);
		this.resources = new luxe_resource_Resources();
		Luxe.resources = this.resources;
		this.headless = this.app.window == null;
		if(!this.headless) {
			this.app.window.onevent = $bind(this,this.window_event);
			this.renderer = new phoenix_Renderer(this);
			Luxe.renderer = this.renderer;
		}
		var _window_w = 0;
		var _window_h = 0;
		if(this.app.window != null) {
			_window_w = this.app.window.width;
			_window_h = this.app.window.height;
		}
		this.screen = new luxe_Screen(this,_window_w,_window_h);
		this.debug.init();
		this.io.init();
		this.timer.init();
		this.audio.init();
		this.input.init();
		if(!this.headless) this.renderer.init();
		this.physics.init();
		Luxe.audio = this.audio;
		Luxe.draw = this.draw;
		Luxe.events = this.events;
		Luxe.timer = this.timer;
		Luxe.input = this.input;
		if(!this.headless) Luxe.camera = new luxe_Camera({ name : "default camera", view : this.renderer.camera});
		Luxe.physics = this.physics;
		this.scene = new luxe_Scene("default scene");
		Luxe.scene = this.scene;
		if(!this.headless) {
			this.scene.add(Luxe.camera,{ fileName : "Core.hx", lineNumber : 254, className : "luxe.Core", methodName : "init"});
			this.debug.create_debug_console();
		}
		if(this.app.window != null && !this.headless) {
			this.app.window.onrender = $bind(this,this.render);
			this.debug.start(luxe_Tag.update,50);
			this.debug.start(luxe_Tag.renderdt,50);
		}
	}
	,shutdown: function() {
		this.shutting_down = true;
		snow_Snow.next(($_=this.app,$bind($_,$_.shutdown)));
	}
	,on: function(event,handler) {
		this.emitter.on(event,handler,{ fileName : "Core.hx", lineNumber : 283, className : "luxe.Core", methodName : "on"});
	}
	,off: function(event,handler) {
		return this.emitter.off(event,handler,{ fileName : "Core.hx", lineNumber : 287, className : "luxe.Core", methodName : "off"});
	}
	,emit: function(event,data) {
		this.emitter.emit(event,data,{ fileName : "Core.hx", lineNumber : 291, className : "luxe.Core", methodName : "emit"});
		return;
	}
	,onevent: function(event) {
		this.game.onevent(event);
	}
	,update: function(dt) {
		if(this.has_shutdown) return;
		this.debug.end(luxe_Tag.update);
		this.debug.start(luxe_Tag.update);
		this.timer.process();
		this.input.process();
		this.audio.process();
		this.events.process();
		this.physics.process();
		this.debug.start(luxe_Tag.updates);
		this.emitter.emit(4,dt,{ fileName : "Core.hx", lineNumber : 337, className : "luxe.Core", methodName : "update"});
		this.debug.end(luxe_Tag.updates);
		this.debug.start(luxe_Tag.game_update);
		this.game.update(dt);
		this.debug.end(luxe_Tag.game_update);
		this.debug.process();
	}
	,window_event: function(_event) {
		if(this.shutting_down) return;
		this.emitter.emit(26,_event,{ fileName : "Core.hx", lineNumber : 358, className : "luxe.Core", methodName : "window_event"});
		var _g = _event.type;
		if(_g != null) switch(_g) {
		case 5:
			this.emitter.emit(27,_event,{ fileName : "Core.hx", lineNumber : 363, className : "luxe.Core", methodName : "window_event"});
			this.game.onwindowmoved(_event);
			break;
		case 6:
			this.screen.internal_resized(_event.event.x,_event.event.y);
			this.renderer.internal_resized(_event.event.x,_event.event.y);
			this.emitter.emit(28,_event,{ fileName : "Core.hx", lineNumber : 370, className : "luxe.Core", methodName : "window_event"});
			this.game.onwindowresized(_event);
			break;
		case 7:
			this.screen.internal_resized(_event.event.x,_event.event.y);
			this.renderer.internal_resized(_event.event.x,_event.event.y);
			this.emitter.emit(29,_event,{ fileName : "Core.hx", lineNumber : 377, className : "luxe.Core", methodName : "window_event"});
			this.game.onwindowsized(_event);
			break;
		case 8:
			this.emitter.emit(30,_event,{ fileName : "Core.hx", lineNumber : 382, className : "luxe.Core", methodName : "window_event"});
			this.game.onwindowminimized(_event);
			break;
		case 10:
			this.emitter.emit(31,_event,{ fileName : "Core.hx", lineNumber : 387, className : "luxe.Core", methodName : "window_event"});
			this.game.onwindowrestored(_event);
			break;
		default:
		} else {
		}
	}
	,render: function(window) {
		if(this.shutting_down) return;
		this.debug.end(luxe_Tag.renderdt);
		this.debug.start(luxe_Tag.renderdt);
		if(!this.headless) {
			this.debug.start(luxe_Tag.render);
			this.emitter.emit(7,null,{ fileName : "Core.hx", lineNumber : 410, className : "luxe.Core", methodName : "render"});
			this.game.onprerender();
			this.emitter.emit(8,null,{ fileName : "Core.hx", lineNumber : 413, className : "luxe.Core", methodName : "render"});
			this.game.onrender();
			this.renderer.process();
			this.emitter.emit(9,null,{ fileName : "Core.hx", lineNumber : 417, className : "luxe.Core", methodName : "render"});
			this.game.onpostrender();
			this.debug.end(luxe_Tag.render);
		}
	}
	,show_console: function(_show) {
		if(_show == null) _show = true;
		this.console_visible = _show;
		this.debug.show_console(this.console_visible);
	}
	,onkeydown: function(keycode,scancode,repeat,mod,timestamp,window_id) {
		var event = { scancode : scancode, keycode : keycode, state : luxe_InteractState.down, mod : mod, repeat : repeat, timestamp : timestamp, window_id : window_id};
		if(!this.shutting_down) {
			this.input.check_named_keys(event,true);
			this.emitter.emit(10,event,{ fileName : "Core.hx", lineNumber : 451, className : "luxe.Core", methodName : "onkeydown"});
			this.game.onkeydown(event);
			if(scancode == snow_input_Scancodes.grave) this.show_console(!this.console_visible);
		}
	}
	,onkeyup: function(keycode,scancode,repeat,mod,timestamp,window_id) {
		var event = { scancode : scancode, keycode : keycode, state : luxe_InteractState.up, mod : mod, repeat : repeat, timestamp : timestamp, window_id : window_id};
		if(!this.shutting_down) {
			this.input.check_named_keys(event);
			this.emitter.emit(11,event,{ fileName : "Core.hx", lineNumber : 479, className : "luxe.Core", methodName : "onkeyup"});
			this.game.onkeyup(event);
		}
	}
	,ontextinput: function(text,start,length,type,timestamp,window_id) {
		var _type = luxe_TextEventType.unknown;
		switch(type) {
		case 1:
			_type = luxe_TextEventType.edit;
			break;
		case 2:
			_type = luxe_TextEventType.input;
			break;
		default:
			return;
		}
		var event = { text : text, start : start, length : length, type : _type, timestamp : timestamp, window_id : window_id};
		if(!this.shutting_down) {
			this.emitter.emit(12,event,{ fileName : "Core.hx", lineNumber : 510, className : "luxe.Core", methodName : "ontextinput"});
			this.game.ontextinput(event);
		}
	}
	,oninputdown: function(name,event) {
		if(!this.shutting_down) {
			this.emitter.emit(13,{ name : name, event : event},{ fileName : "Core.hx", lineNumber : 524, className : "luxe.Core", methodName : "oninputdown"});
			this.game.oninputdown(name,event);
		}
	}
	,oninputup: function(name,event) {
		if(!this.shutting_down) {
			this.emitter.emit(14,{ name : name, event : event},{ fileName : "Core.hx", lineNumber : 536, className : "luxe.Core", methodName : "oninputup"});
			this.game.oninputup(name,event);
		}
	}
	,onmousedown: function(x,y,button,timestamp,window_id) {
		this.screen.cursor.set_internal(new phoenix_Vector(x,y));
		var event = { timestamp : timestamp, window_id : window_id, state : luxe_InteractState.down, button : button, x : x, y : y, xrel : x, yrel : y, pos : this.screen.cursor.get_pos()};
		if(!this.shutting_down) {
			this.input.check_named_mouse(event,true);
			this.emitter.emit(15,event,{ fileName : "Core.hx", lineNumber : 566, className : "luxe.Core", methodName : "onmousedown"});
			this.game.onmousedown(event);
		}
	}
	,onmouseup: function(x,y,button,timestamp,window_id) {
		this.screen.cursor.set_internal(new phoenix_Vector(x,y));
		var event = { timestamp : timestamp, window_id : window_id, state : luxe_InteractState.up, button : button, x : x, y : y, xrel : x, yrel : y, pos : this.screen.cursor.get_pos()};
		if(!this.shutting_down) {
			this.input.check_named_mouse(event);
			this.emitter.emit(16,event,{ fileName : "Core.hx", lineNumber : 593, className : "luxe.Core", methodName : "onmouseup"});
			this.game.onmouseup(event);
		}
	}
	,onmousemove: function(x,y,xrel,yrel,timestamp,window_id) {
		this.screen.cursor.set_internal(new phoenix_Vector(x,y));
		var event = { timestamp : timestamp, window_id : window_id, state : luxe_InteractState.move, button : 0, x : x, y : y, xrel : xrel, yrel : yrel, pos : this.screen.cursor.get_pos()};
		if(!this.shutting_down) {
			this.emitter.emit(17,event,{ fileName : "Core.hx", lineNumber : 619, className : "luxe.Core", methodName : "onmousemove"});
			this.game.onmousemove(event);
		}
	}
	,onmousewheel: function(x,y,timestamp,window_id) {
		var event = { timestamp : timestamp, window_id : window_id, state : luxe_InteractState.wheel, button : 0, x : x, y : y, xrel : x, yrel : y, pos : this.screen.cursor.get_pos()};
		if(!this.shutting_down) {
			this.input.check_named_mouse(event,false);
			this.emitter.emit(18,event,{ fileName : "Core.hx", lineNumber : 643, className : "luxe.Core", methodName : "onmousewheel"});
			this.game.onmousewheel(event);
		}
	}
	,ontouchdown: function(x,y,touch_id,timestamp) {
		this._touch_pos = new phoenix_Vector(x,y);
		var event = { state : luxe_InteractState.down, timestamp : timestamp, touch_id : touch_id, x : x, y : y, dx : x, dy : y, pos : this._touch_pos};
		if(!this.shutting_down) {
			this.emitter.emit(19,event,{ fileName : "Core.hx", lineNumber : 671, className : "luxe.Core", methodName : "ontouchdown"});
			this.game.ontouchdown(event);
			if(this.app.input.touch_count == 3) {
				if(this.console_visible) this.debug.switch_view();
			}
			if(this.app.input.touch_count == 4) this.show_console(!this.console_visible);
		}
	}
	,ontouchup: function(x,y,touch_id,timestamp) {
		this._touch_pos = new phoenix_Vector(x,y);
		var event = { state : luxe_InteractState.up, timestamp : timestamp, touch_id : touch_id, x : x, y : y, dx : x, dy : y, pos : this._touch_pos};
		if(!this.shutting_down) {
			this.emitter.emit(20,event,{ fileName : "Core.hx", lineNumber : 712, className : "luxe.Core", methodName : "ontouchup"});
			this.game.ontouchup(event);
		}
	}
	,ontouchmove: function(x,y,dx,dy,touch_id,timestamp) {
		this._touch_pos = new phoenix_Vector(x,y);
		var event = { state : luxe_InteractState.move, timestamp : timestamp, touch_id : touch_id, x : x, y : y, dx : dx, dy : dy, pos : this._touch_pos};
		if(!this.shutting_down) {
			this.emitter.emit(21,event,{ fileName : "Core.hx", lineNumber : 736, className : "luxe.Core", methodName : "ontouchmove"});
			this.game.ontouchmove(event);
		}
	}
	,ongamepadaxis: function(gamepad,axis,value,timestamp) {
		var event = { timestamp : timestamp, type : luxe_GamepadEventType.axis, state : luxe_InteractState.axis, gamepad : gamepad, button : -1, axis : axis, value : value};
		if(!this.shutting_down) {
			this.emitter.emit(22,event,{ fileName : "Core.hx", lineNumber : 759, className : "luxe.Core", methodName : "ongamepadaxis"});
			this.game.ongamepadaxis(event);
		}
	}
	,ongamepaddown: function(gamepad,button,value,timestamp) {
		var event = { timestamp : timestamp, type : luxe_GamepadEventType.button, state : luxe_InteractState.down, gamepad : gamepad, button : button, axis : -1, value : value};
		if(!this.shutting_down) {
			this.input.check_named_gamepad_buttons(event,true);
			this.emitter.emit(23,event,{ fileName : "Core.hx", lineNumber : 781, className : "luxe.Core", methodName : "ongamepaddown"});
			this.game.ongamepaddown(event);
		}
	}
	,ongamepadup: function(gamepad,button,value,timestamp) {
		var event = { timestamp : timestamp, type : luxe_GamepadEventType.button, state : luxe_InteractState.up, gamepad : gamepad, button : button, axis : -1, value : value};
		if(!this.shutting_down) {
			this.input.check_named_gamepad_buttons(event,false);
			this.emitter.emit(24,event,{ fileName : "Core.hx", lineNumber : 803, className : "luxe.Core", methodName : "ongamepadup"});
			this.game.ongamepadup(event);
		}
	}
	,ongamepaddevice: function(gamepad,type,timestamp) {
		var _event_type = luxe_GamepadEventType.unknown;
		switch(type) {
		case 1:
			_event_type = luxe_GamepadEventType.device_added;
			break;
		case 2:
			_event_type = luxe_GamepadEventType.device_removed;
			break;
		case 3:
			_event_type = luxe_GamepadEventType.device_remapped;
			break;
		default:
		}
		var event = { timestamp : timestamp, type : _event_type, state : luxe_InteractState.none, gamepad : gamepad, button : -1, axis : -1, value : 0};
		if(!this.shutting_down) this.game.ongamepaddevice(event);
	}
	,config: function(config) {
		config.window.width = this.appconfig.window.width;
		config.window.height = this.appconfig.window.height;
		config.window.fullscreen = this.appconfig.window.fullscreen;
		config.window.borderless = this.appconfig.window.borderless;
		config.window.resizable = this.appconfig.window.resizable;
		config.window.title = this.appconfig.window.title;
		return this.game.config(config);
	}
	,__class__: luxe_Core
});
var luxe_Tag = function() { };
luxe_Tag.__name__ = true;
var luxe_Debug = function(_core) {
	this.last_cursor_grab = false;
	this.last_cursor_shown = true;
	this.profiling = false;
	this.profile_path = "profile.txt";
	this.started = false;
	this.last_view_index = 0;
	this.current_view_index = 0;
	this.dt_average_count = 0;
	this.dt_average_span = 60;
	this.dt_average_accum = 0;
	this.dt_average = 0;
	this.visible = false;
	this.core = _core;
};
luxe_Debug.__name__ = true;
luxe_Debug.internal_trace = function(v,inf) {
	var _line = StringTools.rpad(inf.lineNumber == null?"null":"" + inf.lineNumber," ",4);
	console.log("" + inf.fileName + "::" + _line + " " + Std.string(v));
	if(luxe_Debug.shut_down) return;
	var $it0 = luxe_Debug.trace_callbacks.iterator();
	while( $it0.hasNext() ) {
		var _callback = $it0.next();
		_callback(v,inf);
	}
};
luxe_Debug.prototype = {
	init: function() {
		luxe_Debug.trace_callbacks = new haxe_ds_StringMap();
		luxe_Debug.views = [new luxe_debug_TraceDebugView(),new luxe_debug_StatsDebugView(),new luxe_debug_ProfilerDebugView()];
		this.current_view = luxe_Debug.views[0];
		haxe_Log.trace = luxe_Debug.internal_trace;
		null;
	}
	,start: function(_name,_max) {
		if(_max == null) _max = 0.0;
		if(!this.core.headless) luxe_debug_ProfilerDebugView.start(_name,_max);
	}
	,end: function(_name) {
		if(!this.core.headless) luxe_debug_ProfilerDebugView.end(_name);
	}
	,remove_trace_listener: function(_name) {
		luxe_Debug.trace_callbacks.remove(_name);
	}
	,add_trace_listener: function(_name,_callback) {
		luxe_Debug.trace_callbacks.set(_name,_callback);
	}
	,create_debug_console: function() {
		var _g = this;
		this.core.on(11,$bind(this,this.keyup));
		this.core.on(10,$bind(this,this.keydown));
		this.core.on(16,$bind(this,this.mouseup));
		this.core.on(15,$bind(this,this.mousedown));
		this.core.on(17,$bind(this,this.mousemove));
		this.core.on(18,$bind(this,this.mousewheel));
		this.batcher = new phoenix_Batcher(Luxe.renderer,"debug_batcher");
		this.view = new phoenix_Camera();
		this.batcher.view = this.view;
		this.batcher.set_layer(999);
		Luxe.renderer.add_batch(this.batcher);
		this.overlay = new phoenix_geometry_QuadGeometry({ x : 0, y : 0, w : Luxe.core.screen.w, h : Luxe.core.screen.h, color : new phoenix_Color(0,0,0,0.8), depth : 999, group : 999, visible : false, batcher : this.batcher});
		this.padding = new phoenix_Vector(Luxe.core.screen.w * 0.05,Luxe.core.screen.h * 0.05);
		this.debug_inspector = new luxe_debug_Inspector({ title : "luxe debug", pos : new phoenix_Vector(this.padding.x,this.padding.y), size : new phoenix_Vector(Luxe.core.screen.w - this.padding.x * 2,Luxe.core.screen.h - this.padding.y * 2), batcher : this.batcher});
		this.debug_inspector.onrefresh = $bind(this,this.refresh);
		this.core.on(29,function(_event) {
			var _w = _event.event.x;
			var _h = _event.event.y;
			var _v = new phoenix_Vector(_w,_h);
			_g.padding.set_xy(_w * 0.05,_h * 0.05);
			_g.overlay.resize(_v);
			_g.view.set_viewport(new phoenix_Rectangle(0,0,_w,_h));
			_g.debug_inspector.set_size(new phoenix_Vector(_w - _g.padding.x * 2,_h - _g.padding.y * 2));
			_g.debug_inspector.set_pos(new phoenix_Vector(_g.padding.x,_g.padding.y));
			var _g1 = 0;
			var _g2 = luxe_Debug.views;
			while(_g1 < _g2.length) {
				var view = _g2[_g1];
				++_g1;
				view.onwindowsized(_event);
			}
		});
		this.batcher.enabled = false;
		var _g3 = 0;
		var _g11 = luxe_Debug.views;
		while(_g3 < _g11.length) {
			var view1 = _g11[_g3];
			++_g3;
			view1.create();
		}
	}
	,mouseup: function(e) {
		if(this.visible) {
			var _g = 0;
			var _g1 = luxe_Debug.views;
			while(_g < _g1.length) {
				var view = _g1[_g];
				++_g;
				view.onmouseup(e);
			}
		}
	}
	,mousedown: function(e) {
		if(this.visible) {
			var _g = 0;
			var _g1 = luxe_Debug.views;
			while(_g < _g1.length) {
				var view = _g1[_g];
				++_g;
				view.onmousedown(e);
			}
		}
	}
	,mousewheel: function(e) {
		if(this.visible) {
			var _g = 0;
			var _g1 = luxe_Debug.views;
			while(_g < _g1.length) {
				var view = _g1[_g];
				++_g;
				view.onmousewheel(e);
			}
		}
	}
	,mousemove: function(e) {
		if(this.visible) {
			var _g = 0;
			var _g1 = luxe_Debug.views;
			while(_g < _g1.length) {
				var view = _g1[_g];
				++_g;
				view.onmousemove(e);
			}
		}
	}
	,keyup: function(e) {
		if(this.visible) {
			var _g = 0;
			var _g1 = luxe_Debug.views;
			while(_g < _g1.length) {
				var view = _g1[_g];
				++_g;
				view.onkeyup(e);
			}
		}
	}
	,keydown: function(e) {
		if(this.visible) {
			if(e.keycode == snow_input_Keycodes.key_1 && this.core.console_visible) this.switch_view();
			var _g = 0;
			var _g1 = luxe_Debug.views;
			while(_g < _g1.length) {
				var view = _g1[_g];
				++_g;
				view.onkeydown(e);
			}
		}
	}
	,refresh: function() {
		this.current_view.refresh();
	}
	,switch_view: function() {
		this.last_view_index = this.current_view_index;
		this.current_view_index++;
		if(this.current_view_index > luxe_Debug.views.length - 1) this.current_view_index = 0;
		luxe_Debug.views[this.last_view_index].hide();
		this.current_view = luxe_Debug.views[this.current_view_index];
		this.current_view.show();
	}
	,show_console: function(_show) {
		if(_show == null) _show = true;
		if(_show) {
			this.last_cursor_shown = Luxe.core.screen.cursor.get_visible();
			this.last_cursor_grab = Luxe.core.screen.cursor.get_grab();
			Luxe.core.screen.cursor.set_visible(true);
			Luxe.core.screen.cursor.set_grab(false);
		} else {
			if(this.last_cursor_shown != true) Luxe.core.screen.cursor.set_visible(this.last_cursor_shown);
			if(this.last_cursor_grab != false) Luxe.core.screen.cursor.set_grab(this.last_cursor_grab);
		}
		this.visible = _show;
		this.batcher.enabled = _show;
		if(_show) {
			this.current_view.show();
			this.overlay.set_visible(true);
			this.debug_inspector.show();
		} else {
			this.current_view.hide();
			this.debug_inspector.hide();
			this.overlay.set_visible(false);
		}
	}
	,destroy: function() {
		this.core.off(11,$bind(this,this.keyup));
		this.core.off(10,$bind(this,this.keydown));
		this.core.off(16,$bind(this,this.mouseup));
		this.core.off(15,$bind(this,this.mousedown));
		this.core.off(17,$bind(this,this.mousemove));
		this.core.off(18,$bind(this,this.mousewheel));
		luxe_Debug.shut_down = true;
	}
	,process: function() {
		this.dt_average_accum += Luxe.core.delta_time;
		this.dt_average_count++;
		if(this.dt_average_count == this.dt_average_span - 1) {
			this.dt_average = this.dt_average_accum / this.dt_average_span;
			this.dt_average_accum = this.dt_average;
			this.dt_average_count = 0;
		}
		if(!this.visible) return;
		this.debug_inspector._title_text.set_text("[ " + this.current_view.name + " ] " + luxe_utils_Maths.fixed(Luxe.core.delta_time,5) + " / " + luxe_utils_Maths.fixed(this.dt_average,5));
		var _g = 0;
		var _g1 = luxe_Debug.views;
		while(_g < _g1.length) {
			var view = _g1[_g];
			++_g;
			view.process();
		}
	}
	,__class__: luxe_Debug
};
var luxe_Draw = function(_core) {
	this.core = _core;
};
luxe_Draw.__name__ = true;
luxe_Draw.prototype = {
	line: function(options) {
		if(options.p0 == null) throw new js__$Boot_HaxeError("draw.line requires p0:Vector, and p1:Vector");
		if(options.p1 == null) throw new js__$Boot_HaxeError("draw.line requires p0:Vector, and p1:Vector");
		if(options.id == null) options.id = "line.geometry";
		if(options.batcher == null) options.batcher = Luxe.renderer.batcher;
		return new phoenix_geometry_LineGeometry(options);
	}
	,rectangle: function(options) {
		if(options.id == null) options.id = "rectangle.geometry";
		if(options.batcher == null) options.batcher = Luxe.renderer.batcher;
		return new phoenix_geometry_RectangleGeometry(options);
	}
	,box: function(options) {
		if(options.id == null) options.id = "quad.geometry";
		if(options.batcher == null) options.batcher = Luxe.renderer.batcher;
		return new phoenix_geometry_QuadGeometry(options);
	}
	,ring: function(options) {
		if(options.id == null) options.id = "ring.geometry";
		if(options.batcher == null) options.batcher = Luxe.renderer.batcher;
		return new phoenix_geometry_RingGeometry(options);
	}
	,circle: function(options) {
		if(options.id == null) options.id = "circle.geometry";
		if(options.batcher == null) options.batcher = Luxe.renderer.batcher;
		return new phoenix_geometry_CircleGeometry(options);
	}
	,arc: function(options) {
		if(options.id == null) options.id = "arc.geometry";
		if(options.batcher == null) options.batcher = Luxe.renderer.batcher;
		return new phoenix_geometry_ArcGeometry(options);
	}
	,ngon: function(options) {
		if(options.id == null) options.id = "ngon.geometry";
		if(options.batcher == null) options.batcher = Luxe.renderer.batcher;
		var _sides = 3;
		var _radius = 64;
		var _solid = false;
		var _x = 0;
		var _y = 0;
		var _angle = 0;
		if(options.sides != null) _sides = options.sides;
		if(options.r != null) _radius = options.r;
		if(options.x != null) _x = options.x;
		if(options.y != null) _y = options.y;
		if(options.angle != null) _angle = options.angle;
		if(options.solid != null) _solid = options.solid;
		var _geometry = new phoenix_geometry_Geometry(options);
		if(!_solid) _geometry.set_primitive_type(1); else _geometry.set_primitive_type(6);
		var _two_pi = 2 * Math.PI;
		var _sides_over_pi = Math.PI / _sides;
		var _sides_over_twopi = _two_pi / _sides;
		var _angle_rad = _angle * 0.017453292519943278;
		if(_solid) _geometry.add(new phoenix_geometry_Vertex(new phoenix_Vector(_x,_y),options.color));
		var _count;
		if(_solid == false) _count = _sides; else _count = _sides + 1;
		var _points = [];
		var _g = 0;
		while(_g < _count) {
			var i = _g++;
			var __x = _radius * Math.sin(_angle_rad + _sides_over_pi + i * _sides_over_twopi);
			var __y = _radius * Math.cos(_angle_rad + _sides_over_pi + i * _sides_over_twopi);
			var __pos = new phoenix_Vector(_x + __x,_y + __y,0);
			_geometry.add(new phoenix_geometry_Vertex(__pos,options.color));
			if(!_solid) {
				if(i > 0) {
					var _last = _points[i - 1];
					_geometry.add(new phoenix_geometry_Vertex(__pos,options.color));
				}
			}
			_points.push(__pos);
		}
		if(!_solid) _geometry.add(new phoenix_geometry_Vertex(_points[0],options.color));
		return _geometry;
	}
	,texture: function(options) {
		if(options.id == null) options.id = "texture.geometry";
		if(options.batcher == null) options.batcher = Luxe.renderer.batcher;
		var _x = 0;
		var _y = 0;
		var _w = 0;
		var _h = 0;
		var _tw = 64;
		var _th = 64;
		if(options.texture != null) {
			_tw = options.texture.width;
			_th = options.texture.height;
			if(options.size == null) {
				_w = _tw;
				_h = _th;
			}
		}
		if(options.pos != null) {
			_x = options.pos.x;
			_y = options.pos.y;
		}
		if(options.size != null) {
			_w = options.size.x;
			_h = options.size.y;
		}
		if(options.x == null) options.x = _x;
		if(options.y == null) options.y = _y;
		if(options.w == null) options.w = _w;
		if(options.h == null) options.h = _h;
		var _quad = new phoenix_geometry_QuadGeometry(options);
		var _ux = 0;
		var _uy = 0;
		var _uw = _tw;
		var _uh = _th;
		if(options.uv != null) {
			_ux = options.uv.x;
			_uy = options.uv.y;
			_uw = options.uv.w;
			_uh = options.uv.h;
		}
		_quad.uv(new phoenix_Rectangle(_ux,_uy,_uw,_uh));
		return _quad;
	}
	,text: function(options) {
		if(options.batcher == null) options.batcher = Luxe.renderer.batcher;
		return new phoenix_geometry_TextGeometry(options);
	}
	,plane: function(options) {
		if(options.id == null) options.id = "plane.geometry";
		if(options.batcher == null) options.batcher = Luxe.renderer.batcher;
		return new phoenix_geometry_PlaneGeometry(options);
	}
	,__class__: luxe_Draw
};
var luxe_Events = function() {
	this.event_connections = new haxe_ds_StringMap();
	this.event_slots = new haxe_ds_StringMap();
	this.event_filters = new haxe_ds_StringMap();
	this.event_queue = new haxe_ds_StringMap();
	this.event_schedules = new haxe_ds_StringMap();
};
luxe_Events.__name__ = true;
luxe_Events.prototype = {
	destroy: function() {
		this.clear();
	}
	,clear: function() {
		var $it0 = this.event_schedules.iterator();
		while( $it0.hasNext() ) {
			var schedule = $it0.next();
			schedule.stop();
			schedule = null;
		}
		var $it1 = this.event_connections.keys();
		while( $it1.hasNext() ) {
			var connection = $it1.next();
			this.event_connections.remove(connection);
		}
		var $it2 = this.event_filters.keys();
		while( $it2.hasNext() ) {
			var filter = $it2.next();
			this.event_filters.remove(filter);
		}
		var $it3 = this.event_slots.keys();
		while( $it3.hasNext() ) {
			var slot = $it3.next();
			this.event_slots.remove(slot);
		}
		var $it4 = this.event_queue.keys();
		while( $it4.hasNext() ) {
			var event = $it4.next();
			this.event_queue.remove(event);
		}
	}
	,does_filter_event: function(_filter,_event) {
		var _replace_stars = new EReg("\\*","gi");
		var _final_filter = _replace_stars.replace(_filter,".*?");
		var _final_search = new EReg(_final_filter,"gi");
		return _final_search.match(_event);
	}
	,listen: function(_event_name,_listener) {
		var id = Luxe.utils.uniqueid();
		var connection = new luxe__$Events_EventConnection(id,_event_name,_listener);
		this.event_connections.set(id,connection);
		var _has_stars = new EReg("\\*","gi");
		if(_has_stars.match(_event_name)) {
			if(!this.event_filters.exists(_event_name)) {
				var value = [];
				this.event_filters.set(_event_name,value);
			}
			this.event_filters.get(_event_name).push(connection);
		} else {
			if(!this.event_slots.exists(_event_name)) {
				var value1 = [];
				this.event_slots.set(_event_name,value1);
			}
			this.event_slots.get(_event_name).push(connection);
		}
		return id;
	}
	,disconnect: function(event_id) {
		if(this.event_connections.exists(event_id)) {
			var connection = this.event_connections.get(event_id);
			var event_slot = this.event_slots.get(connection.event_name);
			if(event_slot != null) {
				HxOverrides.remove(event_slot,connection);
				return true;
			} else {
				var event_filter = this.event_filters.get(connection.event_name);
				if(event_filter != null) {
					HxOverrides.remove(event_filter,connection);
					return true;
				} else return false;
			}
			return true;
		} else return false;
	}
	,queue: function(event_name,properties) {
		var id = Luxe.utils.uniqueid();
		var event = new luxe__$Events_EventObject(id,event_name,properties);
		this.event_queue.set(id,event);
		return id;
	}
	,dequeue: function(event_id) {
		if(this.event_queue.exists(event_id)) {
			var event = this.event_queue.get(event_id);
			event = null;
			this.event_queue.remove(event_id);
			return true;
		}
		return false;
	}
	,process: function() {
		var $it0 = this.event_queue.iterator();
		while( $it0.hasNext() ) {
			var event = $it0.next();
			this.fire(event.name,event.properties);
		}
		if(this.event_queue.keys().hasNext()) {
			this.event_queue = null;
			this.event_queue = new haxe_ds_StringMap();
		}
	}
	,fire: function(_event_name,_properties) {
		var $it0 = this.event_filters.iterator();
		while( $it0.hasNext() ) {
			var _filter = $it0.next();
			if(_filter.length > 0) {
				var _filter_name = _filter[0].event_name;
				if(this.does_filter_event(_filter_name,_event_name)) {
					_properties = this.tag_properties(_properties,_event_name,_filter.length);
					var _g = 0;
					while(_g < _filter.length) {
						var _connection = _filter[_g];
						++_g;
						_connection.listener(_properties);
					}
				}
			}
		}
		if(this.event_slots.exists(_event_name)) {
			var connections = this.event_slots.get(_event_name);
			var _g1 = 0;
			while(_g1 < connections.length) {
				var connection = connections[_g1];
				++_g1;
				connection.listener(_properties);
			}
		} else return false;
		return false;
	}
	,schedule: function(time,event_name,properties) {
		var _g = this;
		var id = Luxe.utils.uniqueid();
		var _timer = Luxe.timer.schedule(time,function() {
			_g.fire(event_name,properties);
		});
		this.event_schedules.set(id,_timer);
		return id;
	}
	,unschedule: function(schedule_id) {
		if(this.event_schedules.exists(schedule_id)) {
			var timer = this.event_schedules.get(schedule_id);
			timer.stop();
			this.event_schedules.remove(schedule_id);
			return true;
		}
		return false;
	}
	,tag_properties: function(_properties,_name,_count) {
		if(_properties == null) _properties = { };
		_properties._event_name_ = _name;
		_properties._event_connection_count_ = _count;
		return _properties;
	}
	,__class__: luxe_Events
};
var luxe__$Events_EventConnection = function(_id,_event_name,_listener) {
	this.id = _id;
	this.listener = _listener;
	this.event_name = _event_name;
};
luxe__$Events_EventConnection.__name__ = true;
luxe__$Events_EventConnection.prototype = {
	__class__: luxe__$Events_EventConnection
};
var luxe__$Events_EventObject = function(_id,_event_name,_event_properties) {
	this.id = _id;
	this.name = _event_name;
	this.properties = _event_properties;
};
luxe__$Events_EventObject.__name__ = true;
luxe__$Events_EventObject.prototype = {
	__class__: luxe__$Events_EventObject
};
var luxe_IO = function(_core) {
	this.core = _core;
};
luxe_IO.__name__ = true;
luxe_IO.prototype = {
	url_open: function(_url) {
		this.core.app.io.url_open(_url);
	}
	,get_app_path: function() {
		return this.core.app.io.app_path();
	}
	,get_app_path_prefs: function() {
		return this.core.app.io.app_path_prefs();
	}
	,init: function() {
	}
	,__class__: luxe_IO
	,__properties__: {get_app_path_prefs:"get_app_path_prefs",get_app_path:"get_app_path"}
};
var luxe_InteractState = { __ename__ : true, __constructs__ : ["unknown","none","down","up","move","wheel","axis"] };
luxe_InteractState.unknown = ["unknown",0];
luxe_InteractState.unknown.toString = $estr;
luxe_InteractState.unknown.__enum__ = luxe_InteractState;
luxe_InteractState.none = ["none",1];
luxe_InteractState.none.toString = $estr;
luxe_InteractState.none.__enum__ = luxe_InteractState;
luxe_InteractState.down = ["down",2];
luxe_InteractState.down.toString = $estr;
luxe_InteractState.down.__enum__ = luxe_InteractState;
luxe_InteractState.up = ["up",3];
luxe_InteractState.up.toString = $estr;
luxe_InteractState.up.__enum__ = luxe_InteractState;
luxe_InteractState.move = ["move",4];
luxe_InteractState.move.toString = $estr;
luxe_InteractState.move.__enum__ = luxe_InteractState;
luxe_InteractState.wheel = ["wheel",5];
luxe_InteractState.wheel.toString = $estr;
luxe_InteractState.wheel.__enum__ = luxe_InteractState;
luxe_InteractState.axis = ["axis",6];
luxe_InteractState.axis.toString = $estr;
luxe_InteractState.axis.__enum__ = luxe_InteractState;
var luxe_TextEventType = { __ename__ : true, __constructs__ : ["unknown","edit","input"] };
luxe_TextEventType.unknown = ["unknown",0];
luxe_TextEventType.unknown.toString = $estr;
luxe_TextEventType.unknown.__enum__ = luxe_TextEventType;
luxe_TextEventType.edit = ["edit",1];
luxe_TextEventType.edit.toString = $estr;
luxe_TextEventType.edit.__enum__ = luxe_TextEventType;
luxe_TextEventType.input = ["input",2];
luxe_TextEventType.input.toString = $estr;
luxe_TextEventType.input.__enum__ = luxe_TextEventType;
var luxe_GamepadEventType = { __ename__ : true, __constructs__ : ["unknown","axis","button","device_added","device_removed","device_remapped"] };
luxe_GamepadEventType.unknown = ["unknown",0];
luxe_GamepadEventType.unknown.toString = $estr;
luxe_GamepadEventType.unknown.__enum__ = luxe_GamepadEventType;
luxe_GamepadEventType.axis = ["axis",1];
luxe_GamepadEventType.axis.toString = $estr;
luxe_GamepadEventType.axis.__enum__ = luxe_GamepadEventType;
luxe_GamepadEventType.button = ["button",2];
luxe_GamepadEventType.button.toString = $estr;
luxe_GamepadEventType.button.__enum__ = luxe_GamepadEventType;
luxe_GamepadEventType.device_added = ["device_added",3];
luxe_GamepadEventType.device_added.toString = $estr;
luxe_GamepadEventType.device_added.__enum__ = luxe_GamepadEventType;
luxe_GamepadEventType.device_removed = ["device_removed",4];
luxe_GamepadEventType.device_removed.toString = $estr;
luxe_GamepadEventType.device_removed.__enum__ = luxe_GamepadEventType;
luxe_GamepadEventType.device_remapped = ["device_remapped",5];
luxe_GamepadEventType.device_remapped.toString = $estr;
luxe_GamepadEventType.device_remapped.__enum__ = luxe_GamepadEventType;
var luxe_InputType = { __ename__ : true, __constructs__ : ["mouse","touch","keys","gamepad"] };
luxe_InputType.mouse = ["mouse",0];
luxe_InputType.mouse.toString = $estr;
luxe_InputType.mouse.__enum__ = luxe_InputType;
luxe_InputType.touch = ["touch",1];
luxe_InputType.touch.toString = $estr;
luxe_InputType.touch.__enum__ = luxe_InputType;
luxe_InputType.keys = ["keys",2];
luxe_InputType.keys.toString = $estr;
luxe_InputType.keys.__enum__ = luxe_InputType;
luxe_InputType.gamepad = ["gamepad",3];
luxe_InputType.gamepad.toString = $estr;
luxe_InputType.gamepad.__enum__ = luxe_InputType;
var luxe_Input = function(_core) {
	this.core = _core;
};
luxe_Input.__name__ = true;
luxe_Input.prototype = {
	init: function() {
		this.key_bindings = new haxe_ds_StringMap();
		this.mouse_bindings = new haxe_ds_StringMap();
		this.gamepad_bindings = new haxe_ds_StringMap();
		this._named_input_down = new haxe_ds_StringMap();
		this._named_input_pressed = new haxe_ds_StringMap();
		this._named_input_released = new haxe_ds_StringMap();
		null;
	}
	,destroy: function() {
		null;
	}
	,process: function() {
		var $it0 = this._named_input_pressed.keys();
		while( $it0.hasNext() ) {
			var _event = $it0.next();
			if(this._named_input_pressed.get(_event)) this._named_input_pressed.remove(_event); else this._named_input_pressed.set(_event,true);
		}
		var $it1 = this._named_input_released.keys();
		while( $it1.hasNext() ) {
			var _event1 = $it1.next();
			if(this._named_input_released.get(_event1)) this._named_input_released.remove(_event1); else this._named_input_released.set(_event1,true);
		}
	}
	,inputpressed: function(_event) {
		return this._named_input_pressed.exists(_event);
	}
	,inputreleased: function(_event) {
		return this._named_input_released.exists(_event);
	}
	,inputdown: function(_event) {
		return this._named_input_down.exists(_event);
	}
	,keypressed: function(_code) {
		return this.core.app.input.keypressed(_code);
	}
	,keyreleased: function(_code) {
		return this.core.app.input.keyreleased(_code);
	}
	,keydown: function(_code) {
		return this.core.app.input.keydown(_code);
	}
	,scanpressed: function(_code) {
		return this.core.app.input.scanpressed(_code);
	}
	,scanreleased: function(_code) {
		return this.core.app.input.scanreleased(_code);
	}
	,scandown: function(_code) {
		return this.core.app.input.scandown(_code);
	}
	,mousepressed: function(_button) {
		return this.core.app.input.mousepressed(_button);
	}
	,mousereleased: function(_button) {
		return this.core.app.input.mousereleased(_button);
	}
	,mousedown: function(_button) {
		return this.core.app.input.mousedown(_button);
	}
	,gamepadpressed: function(_gamepad,_button) {
		return this.core.app.input.gamepadpressed(_gamepad,_button);
	}
	,gamepadreleased: function(_gamepad,_button) {
		return this.core.app.input.gamepadreleased(_gamepad,_button);
	}
	,gamepaddown: function(_gamepad,_button) {
		return this.core.app.input.gamepaddown(_gamepad,_button);
	}
	,gamepadaxis: function(_gamepad,_axis) {
		return this.core.app.input.gamepadaxis(_gamepad,_axis);
	}
	,bind_key: function(_name,_key) {
		if(!this.key_bindings.exists(_name)) {
			var value = new haxe_ds_IntMap();
			this.key_bindings.set(_name,value);
		}
		var kb = this.key_bindings.get(_name);
		kb.h[_key] = true;
	}
	,bind_mouse: function(_name,_button) {
		if(!this.mouse_bindings.exists(_name)) {
			var value = new haxe_ds_IntMap();
			this.mouse_bindings.set(_name,value);
		}
		var mb = this.mouse_bindings.get(_name);
		mb.h[_button] = true;
	}
	,bind_gamepad: function(_name,_gamepad_button,_gamepad_id) {
		if(!this.gamepad_bindings.exists(_name)) {
			var value = new haxe_ds_IntMap();
			this.gamepad_bindings.set(_name,value);
		}
		var gp = this.gamepad_bindings.get(_name);
		gp.h[_gamepad_button] = _gamepad_id;
	}
	,check_named_keys: function(e,_down) {
		if(_down == null) _down = false;
		var _fired = [];
		var $it0 = this.key_bindings.keys();
		while( $it0.hasNext() ) {
			var _name = $it0.next();
			var _b = this.key_bindings.get(_name);
			var _is_down_repeat = _down && e.repeat;
			if(_b.h.hasOwnProperty(e.keycode) && !_is_down_repeat) {
				if(!Lambda.has(_fired,_name)) _fired.push(_name);
			}
		}
		var _g = 0;
		while(_g < _fired.length) {
			var _f = _fired[_g];
			++_g;
			if(_down) {
				this._named_input_pressed.set(_f,false);
				this._named_input_down.set(_f,true);
				this.core.oninputdown(_f,{ name : _f, type : luxe_InputType.keys, state : luxe_InteractState.down, key_event : e});
			} else {
				this._named_input_released.set(_f,false);
				this._named_input_down.remove(_f);
				this.core.oninputup(_f,{ name : _f, type : luxe_InputType.keys, state : luxe_InteractState.up, key_event : e});
			}
		}
	}
	,check_named_mouse: function(e,_down) {
		if(_down == null) _down = false;
		var _fired = [];
		var $it0 = this.mouse_bindings.keys();
		while( $it0.hasNext() ) {
			var _name = $it0.next();
			var _b = this.mouse_bindings.get(_name);
			if(_b.h.hasOwnProperty(e.button)) {
				if(!Lambda.has(_fired,_name)) _fired.push(_name);
			}
		}
		var _g = 0;
		while(_g < _fired.length) {
			var _f = _fired[_g];
			++_g;
			if(_down) {
				this._named_input_pressed.set(_f,false);
				this._named_input_down.set(_f,true);
				this.core.oninputdown(_f,{ name : _f, type : luxe_InputType.mouse, state : luxe_InteractState.down, mouse_event : e});
			} else {
				this._named_input_released.set(_f,false);
				this._named_input_down.remove(_f);
				this.core.oninputup(_f,{ name : _f, type : luxe_InputType.mouse, state : luxe_InteractState.up, mouse_event : e});
			}
		}
	}
	,check_named_gamepad_buttons: function(e,_down) {
		if(_down == null) _down = false;
		var _fired = [];
		var $it0 = this.gamepad_bindings.keys();
		while( $it0.hasNext() ) {
			var _name = $it0.next();
			var _b = this.gamepad_bindings.get(_name);
			if(_b.h.hasOwnProperty(e.button)) {
				var _kb = _b.h[e.button];
				var _accepted_gamepad = _kb == null || _kb == e.gamepad;
				if(!Lambda.has(_fired,_name) && _accepted_gamepad) _fired.push(_name);
			}
		}
		var _g = 0;
		while(_g < _fired.length) {
			var _f = _fired[_g];
			++_g;
			if(_down) {
				this._named_input_pressed.set(_f,false);
				this._named_input_down.set(_f,true);
				this.core.oninputdown(_f,{ name : _f, type : luxe_InputType.gamepad, state : luxe_InteractState.down, gamepad_event : e});
			} else {
				this._named_input_released.set(_f,false);
				this._named_input_down.remove(_f);
				this.core.oninputup(_f,{ name : _f, type : luxe_InputType.gamepad, state : luxe_InteractState.up, gamepad_event : e});
			}
		}
	}
	,__class__: luxe_Input
};
var luxe_Log = function() { };
luxe_Log.__name__ = true;
luxe_Log._get_spacing = function(_file) {
	var _spaces = "";
	var _trace_length = _file.length + 4;
	var _diff = luxe_Log._log_width - _trace_length;
	if(_diff > 0) {
		var _g = 0;
		while(_g < _diff) {
			var i = _g++;
			_spaces += " ";
		}
	}
	return _spaces;
};
var luxe_Visual = function(_options,_pos_info) {
	this.ignore_texture_on_geometry_change = false;
	this._creating_geometry = false;
	this._has_custom_origin = false;
	this.radians = 0.0;
	this.group = 0;
	this.depth = 0.0;
	this.visible = true;
	this.locked = false;
	var _g = this;
	if(_options == null) throw new js__$Boot_HaxeError("Visual needs not-null options at the moment");
	this._rotation_euler = new phoenix_Vector();
	this._rotation_quat = new phoenix_Quaternion();
	luxe_Entity.call(this,_options,_pos_info);
	this.set_color(new phoenix_Color());
	this.set_size(new phoenix_Vector());
	if(this.options.texture != null) this.set_texture(this.options.texture);
	if(this.options.shader != null) this.set_shader(this.options.shader);
	if(this.options.color != null) this.set_color(this.options.color);
	if(this.options.depth != null) this.set_depth(this.options.depth);
	if(this.options.group != null) this.set_group(this.options.group);
	if(this.options.visible != null) this.set_visible(this.options.visible);
	if(this.options.size != null) {
		this.set_size(this.options.size);
		this._create_geometry();
	} else if(this.texture != null) {
		if(this.texture.loaded) {
			this.set_size(new phoenix_Vector(this.texture.width,this.texture.height));
			this._create_geometry();
		} else this.texture.set_onload(function(_texture) {
			_g.set_size(new phoenix_Vector(_texture.width,_texture.height));
			_g._create_geometry();
		});
	} else {
		this.set_size(new phoenix_Vector(64,64));
		this._create_geometry();
	}
};
luxe_Visual.__name__ = true;
luxe_Visual.__super__ = luxe_Entity;
luxe_Visual.prototype = $extend(luxe_Entity.prototype,{
	_create_geometry: function() {
		if(this.options.geometry == null) {
			if(this.options.no_geometry == null || this.options.no_geometry == false) {
				this._creating_geometry = true;
				var _batcher = null;
				if(this.options.no_batcher_add == null || this.options.no_batcher_add == false) {
					if(this.options.batcher != null) _batcher = this.options.batcher; else _batcher = Luxe.renderer.batcher;
				}
				this.set_geometry(new phoenix_geometry_QuadGeometry({ id : this.name + ".visual", x : 0, y : 0, w : this.size.x, h : this.size.y, scale : new phoenix_Vector(1,1,1), texture : this.texture, color : this.color, shader : this.shader, batcher : _batcher, depth : this.options.depth == null?0:this.options.depth, group : this.options.group == null?0:this.options.group, visible : this.options.visible == null?this.visible:this.options.visible}));
				this._creating_geometry = false;
				this.on_geometry_created();
			}
		} else this.set_geometry(this.options.geometry);
		if(this.geometry != null) {
			this.geometry.id = this.name + ".visual";
			this.geometry.transform.id = this.name + ".visual.transform";
		}
		if(this.options.origin != null) {
			this._has_custom_origin = true;
			this.set_origin(this.options.origin);
		}
		if(this.options.rotation_z != null) this.set_rotation_z(this.options.rotation_z);
	}
	,ondestroy: function() {
		if(this.geometry != null && this.geometry.added) this.geometry.drop(true);
		this.set_geometry(null);
		this.set_texture(null);
	}
	,on_geometry_created: function() {
	}
	,set_visible: function(_v) {
		this.visible = _v;
		if(this.geometry != null) this.geometry.set_visible(this.visible);
		return this.visible;
	}
	,set_depth: function(_v) {
		if(this.geometry != null) this.geometry.set_depth(_v);
		return this.depth = _v;
	}
	,set_group: function(_v) {
		if(this.geometry != null) this.geometry.set_group(_v);
		return this.group = _v;
	}
	,set_color: function(_c) {
		if(this.color != null && this.geometry != null) this.geometry.set_color(_c);
		return this.color = _c;
	}
	,set_texture: function(_t) {
		if(this.geometry != null && this.geometry.get_texture() != _t) this.geometry.set_texture(_t);
		return this.texture = _t;
	}
	,set_shader: function(_s) {
		if(this.geometry != null && this.geometry.get_shader() != _s) this.geometry.set_shader(_s);
		return this.shader = _s;
	}
	,set_geometry: function(_g) {
		if(this.geometry == _g) return this.geometry;
		if(this.geometry != null) this.geometry.drop();
		this.geometry = _g;
		if(this.geometry != null) {
			this.geometry.transform.set_parent(this.get_transform());
			if(this._creating_geometry == false) {
				this.geometry.set_color(this.color);
				this.geometry.set_group(this.group);
				this.geometry.set_depth(this.depth);
				this.geometry.set_visible(this.visible);
				if(!this.ignore_texture_on_geometry_change) {
				}
			}
		}
		return this.geometry;
	}
	,set_parent_from_transform: function(_parent) {
		luxe_Entity.prototype.set_parent_from_transform.call(this,_parent);
		if(this.geometry != null) this.geometry.transform.set_parent(this.get_transform());
	}
	,set_rotation_from_transform: function(_rotation) {
		luxe_Entity.prototype.set_rotation_from_transform.call(this,_rotation);
		this._rotation_euler.setEulerFromQuaternion(_rotation,null);
		this._rotation_quat.copy(_rotation);
	}
	,set_size: function(_v) {
		this.size = _v;
		if(this.size != null) phoenix_Vector.Listen(this.size,$bind(this,this._size_change));
		return this.size;
	}
	,get_rotation_z: function() {
		return luxe_utils_Maths.degrees(this.get_radians());
	}
	,set_rotation_z: function(_degrees) {
		this.set_radians(_degrees * 0.017453292519943278);
		return _degrees;
	}
	,set_radians: function(_r) {
		this._rotation_euler.set_z(_r);
		this._rotation_quat.setFromEuler(this._rotation_euler);
		this.set_rotation(this._rotation_quat.clone());
		return this.radians = _r;
	}
	,get_radians: function() {
		return this.radians;
	}
	,set_locked: function(_l) {
		if(this.geometry != null) this.geometry.set_locked(_l);
		return this.locked = _l;
	}
	,set_clip_rect: function(_val) {
		if(this.geometry != null) this.geometry.set_clip_rect(_val);
		return this.clip_rect = _val;
	}
	,_size_change: function(_v) {
		this.set_size(this.size);
	}
	,init: function() {
	}
	,__class__: luxe_Visual
	,__properties__: $extend(luxe_Entity.prototype.__properties__,{set_rotation_z:"set_rotation_z",get_rotation_z:"get_rotation_z",set_radians:"set_radians",get_radians:"get_radians",set_clip_rect:"set_clip_rect",set_group:"set_group",set_depth:"set_depth",set_visible:"set_visible",set_color:"set_color",set_shader:"set_shader",set_texture:"set_texture",set_locked:"set_locked",set_geometry:"set_geometry",set_size:"set_size"})
});
var luxe_NineSlice = function(_options) {
	this.added = false;
	this.midheight = 0.0;
	this.midwidth = 0.0;
	this.is_set = false;
	this.source_h = 0.0;
	this.source_w = 0.0;
	this.source_y = 0.0;
	this.source_x = 0.0;
	this.height = 0.0;
	this.bottom = 32;
	this.width = 0.0;
	this.right = 32;
	this.left = 32;
	this.top = 32;
	this.slices = [];
	if(_options == null) _options = { no_geometry : true, no_scene : true}; else {
		_options.no_geometry = true;
		_options.no_scene = true;
	}
	this.nineslice_options = _options;
	if(_options.batcher != null) this._batcher = _options.batcher; else this._batcher = Luxe.renderer.batcher;
	luxe_Visual.call(this,_options,{ fileName : "NineSlice.hx", lineNumber : 77, className : "luxe.NineSlice", methodName : "new"});
	if(_options.top != null) this.top = _options.top;
	if(_options.left != null) this.left = _options.left;
	if(_options.right != null) this.right = _options.right;
	if(_options.bottom != null) this.bottom = _options.bottom;
	if(_options.source_x != null) this.source_x = _options.source_x;
	if(_options.source_y != null) this.source_y = _options.source_y;
	if(_options.source_w != null) this.source_w = _options.source_w; else this.source_w = this.texture.width;
	if(_options.source_h != null) this.source_h = _options.source_h; else this.source_h = this.texture.height;
	this.set_geometry(null);
};
luxe_NineSlice.__name__ = true;
luxe_NineSlice.__super__ = luxe_Visual;
luxe_NineSlice.prototype = $extend(luxe_Visual.prototype,{
	lock: function() {
		if(this.is_set && this._geometry != null) this._geometry.set_locked(true);
	}
	,dirty: function() {
		if(this.is_set && this._geometry != null) this._geometry.set_dirty(true);
	}
	,update_size: function(_width,_height) {
		this.width = _width;
		this.height = _height;
		this.midwidth = Math.abs(this.width - this.left - this.right);
		this.midheight = Math.abs(this.height - this.top - this.bottom);
		this.slices[0].source_width = this.left;
		this.slices[0].source_height = this.top;
		this.slices[0].source_x = this.source_x;
		this.slices[0].source_y = this.source_y;
		this.slices[0].pos.set_xy(0,0);
		this.slices[0].width = this.left;
		this.slices[0].height = this.top;
		this.slices[1].source_width = this.source_w - this.left - this.right;
		this.slices[1].source_height = this.top;
		this.slices[1].source_x = this.source_x + this.left;
		this.slices[1].source_y = this.source_y;
		this.slices[1].pos.set_xy(this.left,0);
		this.slices[1].width = this.width - this.left - this.right;
		this.slices[1].height = this.top;
		this.slices[2].source_width = this.right;
		this.slices[2].source_height = this.top;
		this.slices[2].source_x = this.source_x + (this.source_w - this.right);
		this.slices[2].source_y = this.source_y;
		this.slices[2].pos.set_xy(this.left + this.midwidth,0);
		this.slices[2].width = this.right;
		this.slices[2].height = this.top;
		this.slices[3].source_width = this.left;
		this.slices[3].source_height = this.source_h - this.top - this.bottom;
		this.slices[3].source_x = this.source_x;
		this.slices[3].source_y = this.source_y + this.top;
		this.slices[3].pos.set_xy(0,this.top);
		this.slices[3].width = this.left;
		this.slices[3].height = this.height - this.top - this.bottom;
		this.slices[4].source_width = this.source_w - this.left - this.right;
		this.slices[4].source_height = this.source_h - this.top - this.bottom;
		this.slices[4].source_x = this.source_x + this.left;
		this.slices[4].source_y = this.source_y + this.top;
		this.slices[4].pos.set_xy(this.left,this.top);
		this.slices[4].width = this.width - this.left - this.right;
		this.slices[4].height = this.height - this.top - this.bottom;
		this.slices[5].source_width = this.right;
		this.slices[5].source_height = this.source_h - this.top - this.bottom;
		this.slices[5].source_x = this.source_x + (this.source_w - this.right);
		this.slices[5].source_y = this.source_y + this.top;
		this.slices[5].pos.set_xy(this.left + this.midwidth,this.top);
		this.slices[5].width = this.right;
		this.slices[5].height = this.height - this.top - this.bottom;
		this.slices[6].source_width = this.left;
		this.slices[6].source_height = this.bottom;
		this.slices[6].source_x = this.source_x;
		this.slices[6].source_y = this.source_y + (this.source_h - this.bottom);
		this.slices[6].pos.set_xy(0,this.top + this.midheight);
		this.slices[6].width = this.left;
		this.slices[6].height = this.bottom;
		this.slices[7].source_width = this.source_w - this.left - this.right;
		this.slices[7].source_height = this.bottom;
		this.slices[7].source_x = this.source_x + this.left;
		this.slices[7].source_y = this.source_y + (this.source_h - this.bottom);
		this.slices[7].pos.set_xy(this.left,this.top + this.midheight);
		this.slices[7].width = this.width - this.left - this.right;
		this.slices[7].height = this.bottom;
		this.slices[8].source_width = this.right;
		this.slices[8].source_height = this.bottom;
		this.slices[8].source_x = this.source_x + (this.source_w - this.right);
		this.slices[8].source_y = this.source_y + (this.source_h - this.bottom);
		this.slices[8].pos.set_xy(this.left + this.midwidth,this.top + this.midheight);
		this.slices[8].width = this.right;
		this.slices[8].height = this.bottom;
	}
	,set: function(_width,_height) {
		if(this.added) {
			this._geometry.drop();
			this.added = false;
		}
		this.slices.splice(0,this.slices.length);
		this.width = _width;
		this.height = _height;
		this.midwidth = Math.abs(this.width - this.left - this.right);
		this.midheight = Math.abs(this.height - this.top - this.bottom);
		this.slices.push({ source_width : this.left, source_height : this.top, source_x : this.source_x, source_y : this.source_y, pos : new phoenix_Vector(0,0), width : this.left, height : this.top, geometry_id : 0});
		this.slices.push({ source_width : this.source_w - this.left - this.right, source_height : this.top, source_x : this.source_x + this.left, source_y : this.source_y, pos : new phoenix_Vector(this.left,0), width : this.width - this.left - this.right, height : this.top, geometry_id : 0});
		this.slices.push({ source_width : this.right, source_height : this.top, source_x : this.source_x + (this.source_w - this.right), source_y : this.source_y, pos : new phoenix_Vector(this.left + this.midwidth,0), width : this.right, height : this.top, geometry_id : 0});
		this.slices.push({ source_width : this.left, source_height : this.source_h - this.top - this.bottom, source_x : this.source_x, source_y : this.source_y + this.top, pos : new phoenix_Vector(0,this.top), width : this.left, height : this.height - this.top - this.bottom, geometry_id : 0});
		this.slices.push({ source_width : this.source_w - this.left - this.right, source_height : this.source_h - this.top - this.bottom, source_x : this.source_x + this.left, source_y : this.source_y + this.top, pos : new phoenix_Vector(this.left,this.top), width : this.width - this.left - this.right, height : this.height - this.top - this.bottom, geometry_id : 0});
		this.slices.push({ source_width : this.right, source_height : this.source_h - this.top - this.bottom, source_x : this.source_x + (this.source_w - this.right), source_y : this.source_y + this.top, pos : new phoenix_Vector(this.left + this.midwidth,this.top), width : this.right, height : this.height - this.top - this.bottom, geometry_id : 0});
		this.slices.push({ source_width : this.left, source_height : this.bottom, source_x : this.source_x, source_y : this.source_y + (this.source_h - this.bottom), pos : new phoenix_Vector(0,this.top + this.midheight), width : this.left, height : this.bottom, geometry_id : 0});
		this.slices.push({ source_width : this.source_w - this.left - this.right, source_height : this.bottom, source_x : this.source_x + this.left, source_y : this.source_y + (this.source_h - this.bottom), pos : new phoenix_Vector(this.left,this.top + this.midheight), width : this.width - this.left - this.right, height : this.bottom, geometry_id : 0});
		this.slices.push({ source_width : this.right, source_height : this.bottom, source_x : this.source_x + (this.source_w - this.right), source_y : this.source_y + (this.source_h - this.bottom), pos : new phoenix_Vector(this.left + this.midwidth,this.top + this.midheight), width : this.right, height : this.bottom, geometry_id : 0});
		this.is_set = true;
	}
	,set_size: function(_v) {
		if(!this.is_set) return _v;
		this.update_size(_v.x,_v.y);
		var _g = 0;
		var _g1 = this.slices;
		while(_g < _g1.length) {
			var slice = _g1[_g];
			++_g;
			if(this._geometry != null) this._geometry.quad_resize(slice.geometry_id,new phoenix_Rectangle(slice.pos.x,slice.pos.y,slice.width,slice.height));
		}
		return _v;
	}
	,_create: function(_pos,_w,_h,_reset) {
		if(_reset == null) _reset = false;
		if(!this.is_set || _reset) this.set(_w,_h);
		var _color = new phoenix_Color();
		this._geometry = new phoenix_geometry_QuadPackGeometry({ texture : this.texture, color : _color, depth : this.nineslice_options.depth, group : this.nineslice_options.group, visible : this.nineslice_options.visible, batcher : this._batcher});
		var _g = 0;
		var _g1 = this.slices;
		while(_g < _g1.length) {
			var slice = _g1[_g];
			++_g;
			slice.geometry_id = this._geometry.quad_add({ x : slice.pos.x, y : slice.pos.y, w : slice.width, h : slice.height, color : this.nineslice_options.color, uv : new phoenix_Rectangle(slice.source_x,slice.source_y,slice.source_width,slice.source_height)});
		}
		this._geometry.id = "NineSlice" + this._geometry.id;
		this.set_geometry(this._geometry);
		this.set_pos(_pos);
		this.added = true;
		this.is_set = true;
	}
	,create: function(_pos,_w,_h,_reset) {
		if(_reset == null) _reset = false;
		var _g = this;
		if(!this.texture.loaded) this.texture.set_onload(function(texture) {
			_g._create(_pos,_w,_h,_reset);
		}); else this._create(_pos,_w,_h,_reset);
	}
	,init: function() {
	}
	,ondestroy: function() {
		luxe_Visual.prototype.ondestroy.call(this);
	}
	,__class__: luxe_NineSlice
});
var luxe_Physics = function(_core) {
	this.step_delta = 0.016666666666666666;
	this.step_rate = 0.016666666666666666;
	this.core = _core;
};
luxe_Physics.__name__ = true;
luxe_Physics.prototype = {
	init: function() {
		this.engines = [];
	}
	,reset: function() {
		if(this.timer != null) {
			this.timer.stop();
			this.timer = null;
		}
		if(this.step_rate != 0) this.timer = Luxe.timer.schedule(this.step_rate,$bind(this,this.fixed_update),true);
	}
	,fixed_update: function() {
		Luxe.debug.start(luxe_Physics.tag_physics);
		this.update();
		Luxe.debug.end(luxe_Physics.tag_physics);
	}
	,add_engine: function(type,_data) {
		var _engine_instance = Type.createInstance(type,[_data]);
		var _physics_engine = _engine_instance;
		_physics_engine.init();
		this.engines.push(_physics_engine);
		return _engine_instance;
	}
	,update: function() {
		var _g = 0;
		var _g1 = this.engines;
		while(_g < _g1.length) {
			var engine = _g1[_g];
			++_g;
			engine.update();
		}
	}
	,process: function() {
		var _g = 0;
		var _g1 = this.engines;
		while(_g < _g1.length) {
			var engine = _g1[_g];
			++_g;
			engine.process();
		}
	}
	,render: function() {
		var _g = 0;
		var _g1 = this.engines;
		while(_g < _g1.length) {
			var engine = _g1[_g];
			++_g;
			engine.render();
		}
	}
	,destroy: function() {
		if(this.timer != null) this.timer.stop();
		this.timer = null;
		var _g = 0;
		var _g1 = this.engines;
		while(_g < _g1.length) {
			var engine = _g1[_g];
			++_g;
			engine.destroy();
		}
	}
	,set_step_rate: function(_rate) {
		this.step_rate = _rate;
		this.step_delta = this.step_rate;
		this.reset();
		return this.step_rate;
	}
	,__class__: luxe_Physics
	,__properties__: {set_step_rate:"set_step_rate"}
};
var luxe_PhysicsEngine = function() {
	this.draw = true;
	this.paused = false;
	this.name = "engine";
	this.set_gravity(new phoenix_Vector(0,-9.8,0));
	Luxe.on(8,$bind(this,this._render));
};
luxe_PhysicsEngine.__name__ = true;
luxe_PhysicsEngine.prototype = {
	init: function() {
	}
	,_render: function(_) {
		this.render();
	}
	,process: function() {
	}
	,update: function() {
	}
	,render: function() {
	}
	,get_paused: function() {
		return this.paused;
	}
	,set_paused: function(_pause) {
		return this.paused = _pause;
	}
	,get_draw: function() {
		return this.draw;
	}
	,set_draw: function(_draw) {
		return this.draw = _draw;
	}
	,get_gravity: function() {
		return this.gravity;
	}
	,set_gravity: function(_gravity) {
		return this.gravity = _gravity;
	}
	,destroy: function() {
	}
	,__class__: luxe_PhysicsEngine
	,__properties__: {set_draw:"set_draw",get_draw:"get_draw",set_gravity:"set_gravity",get_gravity:"get_gravity",set_paused:"set_paused",get_paused:"get_paused"}
};
var luxe_Scene = function(_name) {
	if(_name == null) _name = "untitled scene";
	this.entity_count = 0;
	this.length = 0;
	this.started = false;
	this.inited = false;
	luxe_Objects.call(this,_name);
	this.entities = new haxe_ds_StringMap();
	this._delayed_init_entities = [];
	this._delayed_reset_entities = [];
	Luxe.core.on(2,$bind(this,this.init));
	Luxe.core.on(6,$bind(this,this._destroy));
	Luxe.core.on(4,$bind(this,this.update));
	Luxe.core.on(7,$bind(this,this.prerender));
	Luxe.core.on(9,$bind(this,this.postrender));
	Luxe.core.on(8,$bind(this,this.render));
	Luxe.core.on(10,$bind(this,this.keydown));
	Luxe.core.on(11,$bind(this,this.keyup));
	Luxe.core.on(12,$bind(this,this.textinput));
	Luxe.core.on(14,$bind(this,this.inputup));
	Luxe.core.on(13,$bind(this,this.inputdown));
	Luxe.core.on(16,$bind(this,this.mouseup));
	Luxe.core.on(15,$bind(this,this.mousedown));
	Luxe.core.on(17,$bind(this,this.mousemove));
	Luxe.core.on(18,$bind(this,this.mousewheel));
	Luxe.core.on(20,$bind(this,this.touchup));
	Luxe.core.on(19,$bind(this,this.touchdown));
	Luxe.core.on(21,$bind(this,this.touchmove));
	Luxe.core.on(24,$bind(this,this.gamepadup));
	Luxe.core.on(23,$bind(this,this.gamepaddown));
	Luxe.core.on(22,$bind(this,this.gamepadaxis));
	Luxe.core.on(25,$bind(this,this.gamepaddevice));
	Luxe.core.on(27,$bind(this,this.windowmoved));
	Luxe.core.on(28,$bind(this,this.windowresized));
	Luxe.core.on(29,$bind(this,this.windowsized));
	Luxe.core.on(30,$bind(this,this.windowminimized));
	Luxe.core.on(31,$bind(this,this.windowrestored));
	if(Luxe.core.inited) this.init(null);
};
luxe_Scene.__name__ = true;
luxe_Scene.__super__ = luxe_Objects;
luxe_Scene.prototype = $extend(luxe_Objects.prototype,{
	add: function(entity,pos) {
		if(entity == null) throw new js__$Boot_HaxeError("can't put entity in a scene if the entity is null.");
		if(this.entities.exists(entity.name)) haxe_Log.trace("    i / scene / " + ("" + this.name + " / adding a second entity named " + entity.name + "! " + Luxe.utils.pos_info(pos) + "\r\n                This will replace the existing one, possibly leaving the previous one in limbo.\r\n                Use EntityOptions name_unique flag to automatically handle this for similar named entities."),{ fileName : "Scene.hx", lineNumber : 86, className : "luxe.Scene", methodName : "add"});
		entity.set_scene(this);
		this.entities.set(entity.name,entity);
		this.entity_count++;
		if(this.inited) this._delayed_init_entities.push(entity);
		if(this.started) this._delayed_reset_entities.push(entity);
	}
	,remove: function(entity) {
		if(entity == null) throw new js__$Boot_HaxeError("can't remove entity from a scene if the entity is null.");
		if(entity.get_scene() == this) {
			entity.set_scene(null);
			this.entity_count--;
			return this.entities.remove(entity.name);
		} else {
			haxe_Log.trace("    i / scene / " + "can't remove the entity from this scene, it is not mine (entity.scene != this)",{ fileName : "Scene.hx", lineNumber : 123, className : "luxe.Scene", methodName : "remove"});
			return false;
		}
		return false;
	}
	,empty: function() {
		if(this.entity_count > 0) {
			var $it0 = this.entities.iterator();
			while( $it0.hasNext() ) {
				var entity = $it0.next();
				if(entity != null) {
					this.remove(entity);
					entity.destroy();
					entity = null;
				}
			}
		}
	}
	,get_named_like: function(_name,into) {
		if(this.entity_count > 0) {
			var _filter = new EReg("^((?:" + _name + ")[.]{1})","g");
			var $it0 = this.entities.iterator();
			while( $it0.hasNext() ) {
				var _entity = $it0.next();
				if(_filter.match(_entity.name)) into.push(_entity);
			}
		}
		return into;
	}
	,render: function(_) {
		this.emit(8,null,{ fileName : "Scene.hx", lineNumber : 178, className : "luxe.Scene", methodName : "render"});
	}
	,prerender: function(_) {
		this.emit(7,null,{ fileName : "Scene.hx", lineNumber : 184, className : "luxe.Scene", methodName : "prerender"});
	}
	,postrender: function(_) {
		this.emit(9,null,{ fileName : "Scene.hx", lineNumber : 190, className : "luxe.Scene", methodName : "postrender"});
	}
	,keydown: function(e) {
		this.emit(10,e,{ fileName : "Scene.hx", lineNumber : 200, className : "luxe.Scene", methodName : "keydown"});
	}
	,keyup: function(e) {
		this.emit(11,e,{ fileName : "Scene.hx", lineNumber : 208, className : "luxe.Scene", methodName : "keyup"});
	}
	,textinput: function(e) {
		this.emit(12,e,{ fileName : "Scene.hx", lineNumber : 216, className : "luxe.Scene", methodName : "textinput"});
	}
	,mousedown: function(e) {
		this.emit(15,e,{ fileName : "Scene.hx", lineNumber : 226, className : "luxe.Scene", methodName : "mousedown"});
	}
	,mousewheel: function(e) {
		this.emit(18,e,{ fileName : "Scene.hx", lineNumber : 234, className : "luxe.Scene", methodName : "mousewheel"});
	}
	,mouseup: function(e) {
		this.emit(16,e,{ fileName : "Scene.hx", lineNumber : 242, className : "luxe.Scene", methodName : "mouseup"});
	}
	,mousemove: function(e) {
		this.emit(17,e,{ fileName : "Scene.hx", lineNumber : 250, className : "luxe.Scene", methodName : "mousemove"});
	}
	,touchdown: function(event) {
		this.emit(19,event,{ fileName : "Scene.hx", lineNumber : 258, className : "luxe.Scene", methodName : "touchdown"});
	}
	,touchup: function(event) {
		this.emit(20,event,{ fileName : "Scene.hx", lineNumber : 264, className : "luxe.Scene", methodName : "touchup"});
	}
	,touchmove: function(event) {
		this.emit(21,event,{ fileName : "Scene.hx", lineNumber : 270, className : "luxe.Scene", methodName : "touchmove"});
	}
	,gamepadaxis: function(event) {
		this.emit(22,event,{ fileName : "Scene.hx", lineNumber : 278, className : "luxe.Scene", methodName : "gamepadaxis"});
	}
	,gamepadup: function(event) {
		this.emit(24,event,{ fileName : "Scene.hx", lineNumber : 284, className : "luxe.Scene", methodName : "gamepadup"});
	}
	,gamepaddown: function(event) {
		this.emit(23,event,{ fileName : "Scene.hx", lineNumber : 290, className : "luxe.Scene", methodName : "gamepaddown"});
	}
	,gamepaddevice: function(event) {
		this.emit(25,event,{ fileName : "Scene.hx", lineNumber : 296, className : "luxe.Scene", methodName : "gamepaddevice"});
	}
	,windowmoved: function(event) {
		this.emit(27,event,{ fileName : "Scene.hx", lineNumber : 305, className : "luxe.Scene", methodName : "windowmoved"});
	}
	,windowresized: function(event) {
		this.emit(28,event,{ fileName : "Scene.hx", lineNumber : 311, className : "luxe.Scene", methodName : "windowresized"});
	}
	,windowsized: function(event) {
		this.emit(29,event,{ fileName : "Scene.hx", lineNumber : 317, className : "luxe.Scene", methodName : "windowsized"});
	}
	,windowminimized: function(event) {
		this.emit(30,event,{ fileName : "Scene.hx", lineNumber : 323, className : "luxe.Scene", methodName : "windowminimized"});
	}
	,windowrestored: function(event) {
		this.emit(31,event,{ fileName : "Scene.hx", lineNumber : 329, className : "luxe.Scene", methodName : "windowrestored"});
	}
	,inputdown: function(event) {
		this.emit(13,event,{ fileName : "Scene.hx", lineNumber : 337, className : "luxe.Scene", methodName : "inputdown"});
	}
	,inputup: function(event) {
		this.emit(14,event,{ fileName : "Scene.hx", lineNumber : 343, className : "luxe.Scene", methodName : "inputup"});
	}
	,_destroy: function(_) {
		this.destroy();
	}
	,destroy: function() {
		Luxe.core.off(2,$bind(this,this.init));
		Luxe.core.off(6,$bind(this,this._destroy));
		Luxe.core.off(4,$bind(this,this.update));
		Luxe.core.off(7,$bind(this,this.prerender));
		Luxe.core.off(9,$bind(this,this.postrender));
		Luxe.core.off(8,$bind(this,this.render));
		Luxe.core.off(10,$bind(this,this.keydown));
		Luxe.core.off(11,$bind(this,this.keyup));
		Luxe.core.off(12,$bind(this,this.textinput));
		Luxe.core.off(14,$bind(this,this.inputup));
		Luxe.core.off(13,$bind(this,this.inputdown));
		Luxe.core.off(16,$bind(this,this.mouseup));
		Luxe.core.off(15,$bind(this,this.mousedown));
		Luxe.core.off(17,$bind(this,this.mousemove));
		Luxe.core.off(18,$bind(this,this.mousewheel));
		Luxe.core.off(20,$bind(this,this.touchup));
		Luxe.core.off(19,$bind(this,this.touchdown));
		Luxe.core.off(21,$bind(this,this.touchmove));
		Luxe.core.off(24,$bind(this,this.gamepadup));
		Luxe.core.off(23,$bind(this,this.gamepaddown));
		Luxe.core.off(22,$bind(this,this.gamepadaxis));
		Luxe.core.off(25,$bind(this,this.gamepaddevice));
		Luxe.core.off(27,$bind(this,this.windowmoved));
		Luxe.core.off(28,$bind(this,this.windowresized));
		Luxe.core.off(29,$bind(this,this.windowsized));
		Luxe.core.off(30,$bind(this,this.windowminimized));
		Luxe.core.off(31,$bind(this,this.windowrestored));
		this.emit(6,null,{ fileName : "Scene.hx", lineNumber : 392, className : "luxe.Scene", methodName : "destroy"});
	}
	,_do_init: function() {
		var _before_count = this.get_length();
		if(this.entity_count > 0) {
			var $it0 = this.entities.iterator();
			while( $it0.hasNext() ) {
				var entity = $it0.next();
				if(entity != null) {
					if(!entity.inited) entity._init();
				}
			}
		}
		var _after_count = this.get_length();
		return _before_count != _after_count;
	}
	,init: function(_) {
		var keep_going = true;
		while(keep_going) keep_going = this._do_init();
		this.inited = true;
		this.emit(2,null,{ fileName : "Scene.hx", lineNumber : 428, className : "luxe.Scene", methodName : "init"});
		this.reset();
	}
	,reset: function() {
		this.started = false;
		this.emit(3,null,{ fileName : "Scene.hx", lineNumber : 439, className : "luxe.Scene", methodName : "reset"});
		this.started = true;
	}
	,update: function(dt) {
		Luxe.core.debug.start("scene." + this.name);
		this.handle_delayed_additions();
		this.emit(4,dt,{ fileName : "Scene.hx", lineNumber : 452, className : "luxe.Scene", methodName : "update"});
		if(this.entity_count > 0) {
			var $it0 = this.entities.iterator();
			while( $it0.hasNext() ) {
				var entity = $it0.next();
				if(entity != null) entity._update(dt);
			}
		}
		Luxe.core.debug.end("scene." + this.name);
	}
	,handle_delayed_additions: function() {
		if(this._delayed_init_entities.length != 0 || this._delayed_reset_entities.length != 0) null;
		if(this._delayed_init_entities.length > 0) {
			var _g = 0;
			var _g1 = this._delayed_init_entities;
			while(_g < _g1.length) {
				var entity = _g1[_g];
				++_g;
				entity._init();
			}
			this._delayed_init_entities.splice(0,this._delayed_init_entities.length);
		}
		if(this._delayed_reset_entities.length > 0) {
			var _g2 = 0;
			var _g11 = this._delayed_reset_entities;
			while(_g2 < _g11.length) {
				var entity1 = _g11[_g2];
				++_g2;
				entity1._reset(null);
			}
			this._delayed_reset_entities.splice(0,this._delayed_reset_entities.length);
		}
	}
	,get_length: function() {
		return Lambda.count(this.entities);
	}
	,toString: function() {
		return "luxe Scene: " + this.name + " / " + this.get_length() + " entities / id: " + this.id;
	}
	,__class__: luxe_Scene
	,__properties__: {get_length:"get_length"}
});
var luxe_Screen = function(_core,_w,_h) {
	this.internal = false;
	this.core = _core;
	this.cursor = new luxe_Cursor(this);
	this.w = _w;
	this.h = _h;
	this.mid = new phoenix_Vector(Math.round(this.w / 2),Math.round(this.h / 2));
	this.size = new phoenix_Vector(this.w,this.h);
};
luxe_Screen.__name__ = true;
luxe_Screen.prototype = {
	toString: function() {
		return "luxe.Screen({ w:" + this.w + ", h:" + this.h + " })";
	}
	,point_inside: function(_p) {
		if(_p.x < 0) return false;
		if(_p.y < 0) return false;
		if(_p.x > this.w) return false;
		if(_p.y > this.h) return false;
		return true;
	}
	,point_inside_xy: function(_x,_y) {
		if(_x < 0) return false;
		if(_y < 0) return false;
		if(_x > this.w) return false;
		if(_y > this.h) return false;
		return true;
	}
	,internal_resized: function(_w,_h) {
		this.w = _w;
		this.h = _h;
		this.internal = true;
		this.get_size().set_x(_w);
		this.get_size().set_y(_h);
		this.get_mid().set_x(_w / 2);
		this.get_mid().set_y(_h / 2);
		this.internal = false;
	}
	,get_mid: function() {
		if(this.internal) return this.mid;
		return this.mid.clone();
	}
	,get_size: function() {
		if(this.internal) return this.size;
		return this.size.clone();
	}
	,__class__: luxe_Screen
	,__properties__: {get_size:"get_size",get_mid:"get_mid"}
};
var luxe_Cursor = function(_screen) {
	this.ignore = false;
	this.lock = false;
	this.grab = false;
	this.visible = true;
	this.screen = _screen;
	this.set_pos(new phoenix_Vector());
};
luxe_Cursor.__name__ = true;
luxe_Cursor.prototype = {
	set_internal: function(_pos) {
		this.ignore = true;
		this.set_pos(_pos);
		this.ignore = false;
	}
	,get_visible: function() {
		return this.visible;
	}
	,set_visible: function(_visible) {
		this.screen.core.app.windowing.enable_cursor(_visible);
		return this.visible = _visible;
	}
	,get_grab: function() {
		return this.grab;
	}
	,get_lock: function() {
		return this.lock;
	}
	,set_grab: function(_grab) {
		this.screen.core.app.window.set_grab(_grab);
		return this.grab = _grab;
	}
	,set_lock: function(_lock) {
		this.screen.core.app.windowing.enable_cursor_lock(_lock);
		return this.lock = _lock;
	}
	,get_pos: function() {
		return this.pos;
	}
	,set_pos: function(_p) {
		if(this.get_pos() != null && _p != null && !this.ignore) this.screen.core.app.window.set_cursor_position(_p.x | 0,_p.y | 0);
		return this.pos = _p;
	}
	,__class__: luxe_Cursor
	,__properties__: {set_pos:"set_pos",get_pos:"get_pos",set_lock:"set_lock",get_lock:"get_lock",set_grab:"set_grab",get_grab:"get_grab",set_visible:"set_visible",get_visible:"get_visible"}
};
var luxe_Sprite = function(options) {
	this.flipy = false;
	this.flipx = false;
	this.centered = true;
	this.set_uv(new phoenix_Rectangle());
	if(options == null) throw new js__$Boot_HaxeError("Sprite needs not-null options at the moment");
	if(options.centered != null) this.set_centered(options.centered);
	if(options.flipx != null) this.set_flipx(options.flipx);
	if(options.flipy != null) this.set_flipy(options.flipy);
	luxe_Visual.call(this,options,{ fileName : "Sprite.hx", lineNumber : 48, className : "luxe.Sprite", methodName : "new"});
};
luxe_Sprite.__name__ = true;
luxe_Sprite.__super__ = luxe_Visual;
luxe_Sprite.prototype = $extend(luxe_Visual.prototype,{
	on_geometry_created: function() {
		var _g = this;
		luxe_Visual.prototype.on_geometry_created.call(this);
		if(this.texture != null) this.texture.set_onload(function(t) {
			if(_g.options.uv == null) _g.set_uv(new phoenix_Rectangle(0,0,_g.texture.width,_g.texture.height)); else _g.set_uv(_g.options.uv);
			if(_g.texture.type == 6) _g.set_flipy(true);
		});
		this.set_centered(!(!this.centered));
		this.set_flipx(!(!this.flipx));
		this.set_flipy(!(!this.flipy));
	}
	,set_geometry: function(_g) {
		this.geometry_quad = _g;
		return luxe_Visual.prototype.set_geometry.call(this,_g);
	}
	,point_inside: function(_p) {
		if(this.geometry == null) return false;
		return Luxe.utils.geometry.point_in_geometry(_p,this.geometry);
	}
	,point_inside_AABB: function(_p) {
		if(this.get_pos() == null) return false;
		if(this.size == null) return false;
		var _s_x = this.size.x * this.get_scale().x;
		var _s_y = this.size.y * this.get_scale().y;
		if(this.centered) {
			var _hx = _s_x / 2;
			var _hy = _s_y / 2;
			if(_p.x < this.get_pos().x - _hx) return false;
			if(_p.y < this.get_pos().y - _hy) return false;
			if(_p.x > this.get_pos().x + _s_x - _hx) return false;
			if(_p.y > this.get_pos().y + _s_y - _hy) return false;
		} else {
			if(_p.x < this.get_pos().x) return false;
			if(_p.y < this.get_pos().y) return false;
			if(_p.x > this.get_pos().x + _s_x) return false;
			if(_p.y > this.get_pos().y + _s_y) return false;
		}
		return true;
	}
	,set_uv: function(_uv) {
		if(this.geometry_quad != null) this.geometry_quad.uv(_uv);
		this.uv = _uv;
		phoenix_Rectangle.listen(this.uv,$bind(this,this._uv_change));
		return this.uv;
	}
	,set_flipy: function(_v) {
		if(_v == this.flipy) return this.flipy;
		if(this.geometry_quad != null) this.geometry_quad.set_flipy(_v);
		return this.flipy = _v;
	}
	,set_flipx: function(_v) {
		if(_v == this.flipx) return this.flipx;
		if(this.geometry_quad != null) this.geometry_quad.set_flipx(_v);
		return this.flipx = _v;
	}
	,set_size: function(_v) {
		if(this.geometry_quad != null) {
			this.geometry_quad.resize(new phoenix_Vector(_v.x,_v.y));
			if(!this._has_custom_origin) {
				if(this.centered) this.set_origin(new phoenix_Vector(_v.x,_v.y,_v.z,_v.w).divideScalar(2));
			}
		}
		return luxe_Visual.prototype.set_size.call(this,_v);
	}
	,set_centered: function(_c) {
		if(this.size != null) {
			if(_c) this.set_origin(new phoenix_Vector(this.size.x / 2,this.size.y / 2)); else this.set_origin(new phoenix_Vector());
		}
		return this.centered = _c;
	}
	,_uv_change: function(_v) {
		this.set_uv(this.uv);
	}
	,init: function() {
	}
	,ondestroy: function() {
		luxe_Visual.prototype.ondestroy.call(this);
	}
	,__class__: luxe_Sprite
	,__properties__: $extend(luxe_Visual.prototype.__properties__,{set_uv:"set_uv",set_flipy:"set_flipy",set_flipx:"set_flipx",set_centered:"set_centered"})
});
var luxe_Text = function(_options,_pos_info) {
	this.text_options = _options;
	this.text_bounds = new phoenix_Rectangle();
	var _batcher = null;
	if(_options.no_batcher_add == null || _options.no_batcher_add == false) {
		if(_options.batcher != null) _batcher = _options.batcher; else _batcher = Luxe.renderer.batcher;
	}
	this.geom = new phoenix_geometry_TextGeometry({ batcher : _batcher, depth : _options.depth, group : _options.group, visible : _options.visible, immediate : _options.immediate, color : _options.color, shader : _options.shader, texture : _options.texture, text : _options.text, font : _options.font, point_size : _options.point_size, line_spacing : _options.line_spacing, letter_spacing : _options.letter_spacing, bounds : _options.bounds, bounds_wrap : _options.bounds_wrap, align : _options.align, align_vertical : _options.align_vertical, sdf : _options.sdf, smoothness : _options.smoothness, thickness : _options.thickness, outline : _options.outline, outline_color : _options.outline_color, glow_threshold : _options.glow_threshold, glow_amount : _options.glow_amount, glow_color : _options.glow_color});
	this.geom.emitter.on(1,$bind(this,this.on_geom_text_update),{ fileName : "Text.hx", lineNumber : 141, className : "luxe.Text", methodName : "new"});
	_options.geometry = this.geom;
	_options.shader = this.geom.get_shader();
	luxe_Visual.call(this,_options,_pos_info);
	this._update_bounds();
};
luxe_Text.__name__ = true;
luxe_Text.__super__ = luxe_Visual;
luxe_Text.prototype = $extend(luxe_Visual.prototype,{
	get_text: function() {
		return this.geom.text;
	}
	,set_text: function(_s) {
		return this.geom.set_text(_s);
	}
	,get_font: function() {
		return this.geom.font;
	}
	,set_font: function(_f) {
		return this.geom.font = _f;
	}
	,get_point_size: function() {
		return this.geom.point_size;
	}
	,set_point_size: function(_s) {
		return this.geom.set_point_size(_s);
	}
	,get_letter_spacing: function() {
		return this.geom.letter_spacing;
	}
	,set_letter_spacing: function(_s) {
		return this.geom.set_letter_spacing(_s);
	}
	,get_line_spacing: function() {
		return this.geom.line_spacing;
	}
	,set_line_spacing: function(_s) {
		return this.geom.set_line_spacing(_s);
	}
	,get_bounds: function() {
		return this.geom.bounds;
	}
	,set_bounds: function(_b) {
		return this.geom.set_bounds(_b);
	}
	,get_bounds_wrap: function() {
		return this.geom.bounds_wrap;
	}
	,set_bounds_wrap: function(_b) {
		return this.geom.set_bounds_wrap(_b);
	}
	,get_align: function() {
		return this.geom.align;
	}
	,set_align: function(_a) {
		return this.geom.set_align(_a);
	}
	,get_align_vertical: function() {
		return this.geom.align_vertical;
	}
	,set_align_vertical: function(_a) {
		return this.geom.set_align_vertical(_a);
	}
	,get_sdf: function() {
		return this.geom.sdf;
	}
	,set_sdf: function(_s) {
		return this.geom.sdf = _s;
	}
	,get_smoothness: function() {
		return this.geom.smoothness;
	}
	,set_smoothness: function(_s) {
		return this.geom.set_smoothness(_s);
	}
	,get_thickness: function() {
		return this.geom.thickness;
	}
	,set_thickness: function(_t) {
		return this.geom.set_thickness(_t);
	}
	,get_outline: function() {
		return this.geom.outline;
	}
	,set_outline: function(_o) {
		return this.geom.set_outline(_o);
	}
	,get_outline_color: function() {
		return this.geom.outline_color;
	}
	,set_outline_color: function(_c) {
		return this.geom.set_outline_color(_c);
	}
	,get_glow_threshold: function() {
		return this.geom.glow_threshold;
	}
	,set_glow_threshold: function(_s) {
		return this.geom.set_glow_threshold(_s);
	}
	,get_glow_amount: function() {
		return this.geom.glow_amount;
	}
	,set_glow_amount: function(_e) {
		return this.geom.set_glow_amount(_e);
	}
	,get_glow_color: function() {
		return this.geom.glow_color;
	}
	,set_glow_color: function(_c) {
		return this.geom.set_glow_color(_c);
	}
	,point_inside: function(p) {
		this._update_bounds();
		return this.text_bounds.point_inside(p);
	}
	,set_pos_from_transform: function(_p) {
		luxe_Visual.prototype.set_pos_from_transform.call(this,_p);
		this._update_bounds();
		this.text_options.pos = this.get_pos();
	}
	,on_geom_text_update: function(_) {
		this._update_bounds();
	}
	,_update_bounds: function() {
		var _x = this.get_pos().x;
		var _y = this.get_pos().y;
		var _tw = this.geom.text_width;
		var _th = this.geom.text_height;
		var _bw = this.geom.text_width;
		var _bh = this.geom.text_height;
		if(this.get_bounds() != null) {
			_bh = this.get_bounds().h;
			_bw = this.get_bounds().w;
			_x = this.get_bounds().x;
			_y = this.get_bounds().y;
			var _g = this.get_align();
			switch(_g) {
			case 2:
				_x += _tw / 2;
				break;
			case 1:
				_x += _tw;
				break;
			default:
				_x += 0.0;
			}
			var _g1 = this.get_align_vertical();
			switch(_g1) {
			case 2:
				_y += _bh / 2 - _th / 2;
				break;
			case 4:
				_y += _bh - _th;
				break;
			default:
				_y += 0.0;
			}
		} else {
			var _g2 = this.get_align();
			switch(_g2) {
			case 2:
				_x -= _tw / 2;
				break;
			case 1:
				_x -= _tw;
				break;
			default:
				_x -= 0.0;
			}
			var _g3 = this.get_align_vertical();
			switch(_g3) {
			case 2:
				_y -= _th / 2;
				break;
			case 4:
				_y -= _th;
				break;
			default:
				_y -= 0.0;
			}
		}
		this.text_bounds.set(_x,_y,_tw,_th);
	}
	,init: function() {
	}
	,ondestroy: function() {
		luxe_Visual.prototype.ondestroy.call(this);
	}
	,__class__: luxe_Text
	,__properties__: $extend(luxe_Visual.prototype.__properties__,{set_glow_color:"set_glow_color",get_glow_color:"get_glow_color",set_glow_amount:"set_glow_amount",get_glow_amount:"get_glow_amount",set_glow_threshold:"set_glow_threshold",get_glow_threshold:"get_glow_threshold",set_outline_color:"set_outline_color",get_outline_color:"get_outline_color",set_outline:"set_outline",get_outline:"get_outline",set_thickness:"set_thickness",get_thickness:"get_thickness",set_smoothness:"set_smoothness",get_smoothness:"get_smoothness",set_sdf:"set_sdf",get_sdf:"get_sdf",set_align_vertical:"set_align_vertical",get_align_vertical:"get_align_vertical",set_align:"set_align",get_align:"get_align",set_bounds_wrap:"set_bounds_wrap",get_bounds_wrap:"get_bounds_wrap",set_bounds:"set_bounds",get_bounds:"get_bounds",set_line_spacing:"set_line_spacing",get_line_spacing:"get_line_spacing",set_letter_spacing:"set_letter_spacing",get_letter_spacing:"get_letter_spacing",set_point_size:"set_point_size",get_point_size:"get_point_size",set_font:"set_font",get_font:"get_font",set_text:"set_text",get_text:"get_text"})
});
var luxe_Timer = function(_core) {
	this.core = _core;
	this.timers = [];
};
luxe_Timer.__name__ = true;
luxe_Timer.prototype = {
	init: function() {
		null;
	}
	,destroy: function() {
		this.reset();
		null;
	}
	,process: function() {
	}
	,reset: function() {
		var _g = 0;
		var _g1 = this.timers;
		while(_g < _g1.length) {
			var t = _g1[_g];
			++_g;
			t.stop();
			t = null;
		}
		this.timers = null;
		this.timers = [];
	}
	,schedule: function(_time_in_seconds,_on_time,repeat) {
		if(repeat == null) repeat = false;
		var _g = this;
		var t = new snow_utils_Timer(_time_in_seconds);
		t.run = function() {
			if(!repeat) {
				t.stop();
				HxOverrides.remove(_g.timers,t);
			}
			_on_time();
		};
		this.timers.push(t);
		return t;
	}
	,__class__: luxe_Timer
};
var luxe_components_Components = function(_entity) {
	var _map = new haxe_ds_StringMap();
	this.components = new luxe_structural_OrderedMap(_map);
	this.entity = _entity;
};
luxe_components_Components.__name__ = true;
luxe_components_Components.prototype = {
	add: function(_component) {
		if(_component == null) {
			haxe_Log.trace("attempt to add null component to " + this.entity.name,{ fileName : "Components.hx", lineNumber : 28, className : "luxe.components.Components", methodName : "add"});
			return _component;
		}
		_component.set_entity(this.entity);
		this.components.set(_component.name,_component);
		_component.onadded();
		if(this.entity.inited) _component.init();
		if(this.entity.started) _component.onreset();
		return _component;
	}
	,remove: function(_name) {
		if(!this.components.map.exists(_name)) {
			haxe_Log.trace("attempt to remove " + _name + " from " + this.entity.name + " failed because that component was not attached to this entity",{ fileName : "Components.hx", lineNumber : 61, className : "luxe.components.Components", methodName : "remove"});
			return false;
		}
		var _component = this.components.map.get(_name);
		_component.onremoved();
		_component.set_entity(null);
		return this.components.remove(_name);
	}
	,get: function(_name,in_children) {
		if(in_children == null) in_children = false;
		if(!in_children) return this.components.map.get(_name); else {
			var in_this_entity = this.components.map.get(_name);
			if(in_this_entity != null) return in_this_entity;
			var _g = 0;
			var _g1 = this.entity.children;
			while(_g < _g1.length) {
				var _child = _g1[_g];
				++_g;
				var found = _child._components.get(_name,true);
				if(found != null) return found;
			}
			return null;
		}
		return null;
	}
	,get_any: function(_name,in_children,first_only) {
		if(first_only == null) first_only = true;
		if(in_children == null) in_children = false;
		var results = [];
		if(!in_children) return [this.components.map.get(_name)]; else {
			var in_this_entity = this.components.map.get(_name);
			if(in_this_entity != null) {
				if(first_only) return [in_this_entity]; else results.push(in_this_entity);
			}
			var _g = 0;
			var _g1 = this.entity.children;
			while(_g < _g1.length) {
				var _child = _g1[_g];
				++_g;
				var found = _child._components.get_any(_name,true,first_only);
				if(found != null) {
					if(first_only && found.length > 0) return [found[0]]; else results.concat(found);
				}
			}
		}
		return results;
	}
	,has: function(_name) {
		return this.components.map.exists(_name);
	}
	,__class__: luxe_components_Components
};
var luxe_debug_DebugView = function() {
	this.visible = false;
	luxe_Objects.call(this);
};
luxe_debug_DebugView.__name__ = true;
luxe_debug_DebugView.__super__ = luxe_Objects;
luxe_debug_DebugView.prototype = $extend(luxe_Objects.prototype,{
	refresh: function() {
	}
	,process: function() {
	}
	,onmousedown: function(e) {
	}
	,onmousewheel: function(e) {
	}
	,onmouseup: function(e) {
	}
	,onmousemove: function(e) {
	}
	,onkeydown: function(e) {
	}
	,onkeyup: function(e) {
	}
	,onwindowsized: function(e) {
	}
	,create: function() {
	}
	,show: function() {
		this.visible = true;
	}
	,hide: function() {
		this.visible = false;
	}
	,__class__: luxe_debug_DebugView
});
var luxe_debug_BatcherDebugView = function() {
	this.as_immediate = false;
	this.dragging = false;
	luxe_debug_DebugView.call(this);
	this.name = "Batcher Debug";
};
luxe_debug_BatcherDebugView.__name__ = true;
luxe_debug_BatcherDebugView.__super__ = luxe_debug_DebugView;
luxe_debug_BatcherDebugView.prototype = $extend(luxe_debug_DebugView.prototype,{
	create: function() {
		this.batcher = Luxe.renderer.create_batcher({ name : "debug_batcher_view", camera : new phoenix_Camera({ camera_name : "batcher_debug_view"}), layer : 1000});
	}
	,refresh: function() {
		this.clear_batcher_tree();
		this.draw_batcher_tree();
	}
	,onmousedown: function(e) {
		this.dragmstart = e.pos.clone();
		this.dragstart = this.batcher.view.get_pos().clone();
		this.dragging = true;
	}
	,onmouseup: function(e) {
		this.dragging = false;
	}
	,onmousemove: function(e) {
		if(this.dragging) {
			var diff = phoenix_Vector.Subtract(e.pos,this.dragmstart);
			this.batcher.view.set_pos(phoenix_Vector.Subtract(this.dragstart,diff));
		}
	}
	,onmousewheel: function(e) {
		if(e.y < 0) {
			var _g = this.batcher.view;
			_g.set_zoom(_g.zoom - 0.1);
		} else {
			var _g1 = this.batcher.view;
			_g1.set_zoom(_g1.zoom + 0.1);
		}
	}
	,clear_batcher_tree: function() {
		if(this._tree_geom != null) {
			this._tree_geom.drop();
			this._tree_geom = null;
		}
	}
	,keystr: function(key,key2) {
		return "ts: " + key.timestamp + "\n" + "seq: " + key.sequence + "\n" + "primitive_type: " + key.primitive_type + " " + key.primitive_type + "\n" + "texture: " + (key.texture == null?"null":Std.string(key.texture.texture)) + "\n" + "texture id: " + (key.texture == null?"null":key.texture.id) + "\n" + "shader: " + (key.shader == null?"null":key.shader.id) + "\n" + "group: " + key.group + "\n" + "depth: " + key.depth + "\n" + "clip: " + (key.clip == null?"null":"" + key.clip);
	}
	,draw_geom_node: function(l,_leaf,_p,_bbw) {
		if(_bbw == null) _bbw = 20;
		var _bw = 128;
		var _bwhalf = _bw / 2;
		var _bh = 128;
		var _g = _leaf.value;
		var c = new phoenix_Color(1,1,1,0.4).rgb(16777215);
		if(_g.dropped) c = new phoenix_Color(1,1,1,1).rgb(13369344);
		this._tree_geom.add_geometry(Luxe.draw.rectangle({ immediate : this.as_immediate, x : _p.x - _bwhalf, y : _p.y, w : _bw, h : _bh, color : c, batcher : this.batcher, depth : 999.4}));
		this._tree_geom.add_geometry(Luxe.draw.text({ immediate : this.as_immediate, bounds : new phoenix_Rectangle(_p.x - _bwhalf,_p.y,_bw,_bh), point_size : 13, color : c, batcher : this.batcher, depth : 999.4, text : this.keystr(_leaf.key,_g.key), align : 2, align_vertical : 2}));
		var t = new phoenix_Vector(_p.x,_p.y,_p.z,_p.w).set_xy(_p.x,_p.y - 16);
		var t2 = new phoenix_Vector(_p.x,_p.y,_p.z,_p.w).set_xy(_p.x,_p.y + _bw + 2);
		var talign = 2;
		this._tree_geom.add_geometry(Luxe.draw.text({ immediate : this.as_immediate, pos : t, point_size : 13, color : c, batcher : this.batcher, depth : 999.4, text : _g.id, align : talign}));
		var c2 = new phoenix_Color(1,1,1,0.4).rgb(16750916);
		var notes_l = "none";
		var notes_r = "none";
		if(_leaf.left != null) {
			notes_l = "node";
			var compare = Luxe.renderer.batcher.compare_rule(_leaf.key,_leaf.left.key);
			notes_l = Luxe.renderer.batcher.compare_rule_to_string(compare);
		}
		if(_leaf.right != null) {
			notes_r = "node";
			var compare1 = Luxe.renderer.batcher.compare_rule(_leaf.key,_leaf.right.key);
			notes_r = Luxe.renderer.batcher.compare_rule_to_string(compare1);
		}
		this._tree_geom.add_geometry(Luxe.draw.text({ immediate : this.as_immediate, pos : t2, point_size : 13, color : c2, batcher : this.batcher, depth : 999.4, text : notes_l + " / " + notes_r, align : talign}));
	}
	,draw_geom_leaf: function(L,_leaf,_p) {
		if(_leaf == null) return;
		var _bw = _leaf.nodecount / 20;
		var _bwb = _leaf.nodecount * 25;
		var _bh = 128;
		var _bh2 = 148;
		var _bwhalf = _bw / 2;
		var c = new phoenix_Color(1,1,1,0.4).rgb(16777215);
		if(_leaf != null) {
			this.draw_geom_node(L,_leaf,_p,_bw);
			if(_leaf.left != null) {
				if(Luxe.renderer.batcher.geometry_compare(_leaf.left.key,_leaf.key) < 0) c = new phoenix_Color(1,1,1,1).rgb(52224); else c = new phoenix_Color(1,1,1,1).rgb(13369344);
				this._tree_geom.add_geometry(Luxe.draw.line({ immediate : this.as_immediate, p0 : new phoenix_Vector(_p.x - _bwhalf,_p.y + _bh), p1 : new phoenix_Vector(_p.x - _bwb,_p.y + _bh2), color : c, batcher : this.batcher, depth : 999.4}));
				this.draw_geom_leaf(true,_leaf.left,new phoenix_Vector(_p.x - _bwb,_p.y + _bh2));
			}
			if(_leaf.right != null) {
				if(Luxe.renderer.batcher.geometry_compare(_leaf.right.key,_leaf.key) > 0) c = new phoenix_Color(1,1,1,1).rgb(52224); else c = new phoenix_Color(1,1,1,1).rgb(13369344);
				this._tree_geom.add_geometry(Luxe.draw.line({ immediate : this.as_immediate, p0 : new phoenix_Vector(_p.x + _bwhalf,_p.y + _bh), p1 : new phoenix_Vector(_p.x + _bwb,_p.y + _bh2), color : c, batcher : this.batcher, depth : 999.4}));
				this.draw_geom_leaf(false,_leaf.right,new phoenix_Vector(_p.x + _bwb,_p.y + _bh2));
			}
		}
	}
	,draw_batcher_tree: function() {
		this._tree_geom = null;
		this._tree_geom = new phoenix_geometry_CompositeGeometry({ batcher : this.batcher, immediate : this.as_immediate, depth : 999.4});
		var _p = new phoenix_Vector(Luxe.core.screen.w / 2,Luxe.debug.padding.y * 2 + 10);
		var _node = Luxe.renderer.batcher.geometry.root;
		this.draw_geom_leaf(true,_node,_p);
	}
	,process: function() {
		if(this.visible) {
			if(Luxe.renderer.batcher.tree_changed) this.refresh();
		}
	}
	,show: function() {
		luxe_debug_DebugView.prototype.show.call(this);
		this.refresh();
	}
	,hide: function() {
		luxe_debug_DebugView.prototype.hide.call(this);
		this.clear_batcher_tree();
	}
	,__class__: luxe_debug_BatcherDebugView
});
var luxe_debug_Inspector = function(_options) {
	this.title = "Inspector";
	this.font = Luxe.renderer.font;
	this.set_size(new phoenix_Vector(Luxe.core.screen.w * 0.2 | 0,Luxe.core.screen.h * 0.6 | 0));
	this.set_pos(new phoenix_Vector(Luxe.core.screen.w / 2 - this.size.x / 2,Luxe.core.screen.h / 2 - this.size.y / 2));
	this.uitexture = phoenix_Texture.load_from_resource("tiny.ui.png");
	this.uibutton = phoenix_Texture.load_from_resource("tiny.button.png");
	this._batcher = Luxe.renderer.batcher;
	if(_options != null) {
		if(_options.title != null) this.title = _options.title;
		if(_options.font != null) this.font = _options.font;
		if(_options.pos != null) this.set_pos(_options.pos);
		if(_options.size != null) this.set_size(_options.size);
		if(_options.batcher != null) this._batcher = _options.batcher;
	}
};
luxe_debug_Inspector.__name__ = true;
luxe_debug_Inspector.prototype = {
	refresh: function() {
		if(this._window == null) this._create_window();
		if(this.onrefresh != null) this.onrefresh();
	}
	,show: function() {
		this.refresh();
		this._window.set_visible(true);
		this._title_text.set_visible(true);
		this._version_text.set_visible(true);
	}
	,hide: function() {
		this._window.set_visible(false);
		this._title_text.set_visible(false);
		this._version_text.set_visible(false);
	}
	,set_size: function(_size) {
		if(this.size != null && this._window != null) this._window.set_size(_size);
		if(this._version_text != null) this._version_text.set_pos(new phoenix_Vector(this.pos.x + (_size.x - 14),this.pos.y + 6));
		return this.size = _size;
	}
	,set_pos: function(_pos) {
		if(this.pos != null && this._window != null) this._window.set_pos(_pos);
		if(this._title_text != null) this._title_text.set_pos(new phoenix_Vector(_pos.x + 14,_pos.y + 6));
		if(this._version_text != null) this._version_text.set_pos(new phoenix_Vector(_pos.x + (this.size.x - 14),_pos.y + 6));
		return this.pos = _pos;
	}
	,_create_window: function() {
		if(this._window != null) this._window.destroy();
		this._window = new luxe_NineSlice({ depth : 999.1, texture : this.uitexture, batcher : this._batcher});
		this._window.create(this.pos,this.size.x,this.size.y);
		this._window._geometry.id = "debug.Inspector";
		this._window.lock();
		this._title_text = new luxe_Text({ name : "debug.title", batcher : this._batcher, no_scene : true, depth : 999.2, color : new phoenix_Color().rgb(16121979), pos : new phoenix_Vector(this.pos.x + 14,this.pos.y + 6), align : 0, font : this.font, text : this.title, point_size : 15, visible : false},{ fileName : "Inspector.hx", lineNumber : 133, className : "luxe.debug.Inspector", methodName : "_create_window"});
		this._version_text = new luxe_Text({ name : "debug.version", batcher : this._batcher, no_scene : true, depth : 999.2, color : new phoenix_Color().rgb(3355443), pos : new phoenix_Vector(this.pos.x + (this.size.x - 14),this.pos.y + 6), align : 1, font : this.font, text : "" + Luxe.build, point_size : 16, visible : false},{ fileName : "Inspector.hx", lineNumber : 147, className : "luxe.debug.Inspector", methodName : "_create_window"});
		if(this._title_text.geometry != null) this._title_text.geometry.id = "debug.title.text";
		if(this._version_text.geometry != null) this._version_text.geometry.id = "debug.version.text";
	}
	,__class__: luxe_debug_Inspector
	,__properties__: {set_size:"set_size",set_pos:"set_pos"}
};
var luxe_debug_ProfilerDebugView = function() {
	this._setup = false;
	luxe_debug_DebugView.call(this);
	this.name = "Profiler";
	luxe_debug_ProfilerDebugView.lists = new haxe_ds_StringMap();
};
luxe_debug_ProfilerDebugView.__name__ = true;
luxe_debug_ProfilerDebugView.add_offset = function(_id,_offset) {
	var _item = luxe_debug_ProfilerDebugView.lists.get(_id);
	var _offsetitem = luxe_debug_ProfilerDebugView.lists.get(_offset);
	if(_item != null && _offsetitem != null) _item.offsets.push(_offsetitem); else {
		haxe_Log.trace("not found for " + _id + " or " + _offset,{ fileName : "ProfilerDebugView.hx", lineNumber : 32, className : "luxe.debug.ProfilerDebugView", methodName : "add_offset"});
		haxe_Log.trace(Std.string(_item) + " / " + Std.string(_offsetitem),{ fileName : "ProfilerDebugView.hx", lineNumber : 33, className : "luxe.debug.ProfilerDebugView", methodName : "add_offset"});
	}
};
luxe_debug_ProfilerDebugView.hide_item = function(_id) {
	var _item = luxe_debug_ProfilerDebugView.lists.get(_id);
	if(_item != null) {
		_item.hidden = true;
		_item.bar.hide();
	}
};
luxe_debug_ProfilerDebugView.show_item = function(_id) {
	var _item = luxe_debug_ProfilerDebugView.lists.get(_id);
	if(_item != null) {
		_item.hidden = false;
		_item.bar.show();
	}
};
luxe_debug_ProfilerDebugView.start = function(_id,_max) {
	if(_max == null) _max = 0.0;
	var _item = luxe_debug_ProfilerDebugView.lists.get(_id);
	if(_item == null) {
		_item = new luxe_debug__$ProfilerDebugView_ProfilerValue(_id,new luxe_debug__$ProfilerDebugView_ProfilerBar(_id,_max,new phoenix_Color().rgb(16121979)));
		_item.bar.set_pos(new phoenix_Vector(Luxe.debug.padding.x * 2,Luxe.debug.padding.y * 3 + Lambda.count(luxe_debug_ProfilerDebugView.lists) * 20));
		luxe_debug_ProfilerDebugView.lists.set(_id,_item);
	}
	_item.start = snow_Snow.core.timestamp();
};
luxe_debug_ProfilerDebugView.end = function(_id) {
	var _item = luxe_debug_ProfilerDebugView.lists.get(_id);
	if(_item != null) _item.set(); else throw new js__$Boot_HaxeError("Profile end called for " + _id + " but no start called");
};
luxe_debug_ProfilerDebugView.__super__ = luxe_debug_DebugView;
luxe_debug_ProfilerDebugView.prototype = $extend(luxe_debug_DebugView.prototype,{
	show: function() {
		var $it0 = luxe_debug_ProfilerDebugView.lists.iterator();
		while( $it0.hasNext() ) {
			var _item = $it0.next();
			if(!_item.hidden) _item.bar.show();
		}
		if(!this._setup) {
			luxe_debug_ProfilerDebugView.add_offset("core.render","batch.debug_batcher");
			this._setup = true;
		}
	}
	,hide: function() {
		var $it0 = luxe_debug_ProfilerDebugView.lists.iterator();
		while( $it0.hasNext() ) {
			var _item = $it0.next();
			_item.bar.hide();
		}
	}
	,__class__: luxe_debug_ProfilerDebugView
});
var luxe_debug__$ProfilerDebugView_ProfilerValue = function(_name,_bar) {
	this.accum = 0;
	this.count = 0;
	this.hidden = false;
	this.avg = 10;
	this.start = 0.0;
	this.name = _name;
	this.bar = _bar;
	this.history = [];
	this.offsets = [];
};
luxe_debug__$ProfilerDebugView_ProfilerValue.__name__ = true;
luxe_debug__$ProfilerDebugView_ProfilerValue.prototype = {
	set: function() {
		var _t = snow_Snow.core.timestamp() - this.start;
		var _g = 0;
		var _g1 = this.offsets;
		while(_g < _g1.length) {
			var _offset = _g1[_g];
			++_g;
			_t -= _offset.history[_offset.history.length - 1];
		}
		this.history.push(_t);
		if(this.history.length > this.avg) this.history.shift();
		this.count++;
		if(this.count == this.avg) {
			var __t = this.accum / this.avg;
			this.bar.set_value(__t);
			this.bar.set_ping(__t);
			this.accum = 0;
			this.count = 0;
		}
		this.accum += _t;
		if(this.bar.visible) this.bar.set_text(Std.string(luxe_utils_Maths.fixed(_t * 1000,4)));
	}
	,__class__: luxe_debug__$ProfilerDebugView_ProfilerValue
};
var luxe_debug__$ProfilerDebugView_ProfilerBar = function(_name,_max,_color) {
	if(_max == null) _max = 0.0;
	this.visible = false;
	this.history = 33;
	this.max = 16.6;
	this.height2 = 8;
	this.height = 8;
	this.width = 128;
	this.color_red = new phoenix_Color().rgb(13369344);
	this.color_green = new phoenix_Color().rgb(2263108);
	this.color_normal = new phoenix_Color().rgb(15790320);
	if(_max == 0.0) this.max = 16.666666666666668; else this.max = _max;
	this.max = luxe_utils_Maths.fixed(this.max,1);
	this.name = _name;
	this.segment = this.width / this.history;
	this.height2 = this.height * 2;
	this.text_item = new luxe_Text({ no_scene : true, name : "profiler.text." + _name, pos : new phoenix_Vector(0,0), color : _color, point_size : this.height * 1.8, depth : 999.3, text : "", batcher : Luxe.debug.batcher},{ fileName : "ProfilerDebugView.hx", lineNumber : 189, className : "luxe.debug._ProfilerDebugView.ProfilerBar", methodName : "new"});
	this.bg_geometry = Luxe.draw.box({ color : new phoenix_Color().rgb(592137), depth : 999.3, batcher : Luxe.debug.batcher, x : 0, y : 0, w : this.width, h : this.height});
	this.graphbg_geometry = Luxe.draw.box({ color : new phoenix_Color().rgb(2236962), depth : 999.3, batcher : Luxe.debug.batcher, x : 0, y : 0, w : this.width - this.segment, h : this.height * 2});
	this.bar_geometry = Luxe.draw.box({ color : _color, depth : 999.33, batcher : Luxe.debug.batcher, x : 1, y : 1, w : this.width - 2, h : this.height - 2});
	this.graph_geometry = new phoenix_geometry_Geometry({ color : _color, depth : 999.33, batcher : Luxe.debug.batcher});
	var _g1 = 0;
	var _g = this.history;
	while(_g1 < _g) {
		var i = _g1++;
		var _b = new phoenix_geometry_Vertex(new phoenix_Vector(this.segment * i,0),_color);
		this.graph_geometry.add(_b);
	}
	this.graph_geometry.set_primitive_type(3);
	this.hide();
};
luxe_debug__$ProfilerDebugView_ProfilerBar.__name__ = true;
luxe_debug__$ProfilerDebugView_ProfilerBar.prototype = {
	hide: function() {
		this.visible = false;
		this.bar_geometry.set_visible(false);
		this.bg_geometry.set_visible(false);
		this.graph_geometry.set_visible(false);
		this.graphbg_geometry.set_visible(false);
		this.text_item.set_visible(false);
	}
	,show: function() {
		this.visible = true;
		this.bar_geometry.set_visible(true);
		this.bg_geometry.set_visible(true);
		this.graph_geometry.set_visible(true);
		this.graphbg_geometry.set_visible(true);
		this.text_item.set_visible(true);
	}
	,set_ping: function(_v) {
		var _vv = luxe_utils_Maths.fixed(_v * 1000,4);
		var _p = _vv / this.max;
		var _g1 = 0;
		var _g = this.history;
		while(_g1 < _g) {
			var i = _g1++;
			var v = this.graph_geometry.vertices[i];
			if(i < this.history - 1) {
				var v1 = this.graph_geometry.vertices[i + 1];
				if(v1 != null) {
					v.pos.set_y(Math.floor(v1.pos.y));
					v.color = v1.color;
				}
			}
		}
		if(_p > 1) {
			_p = 1;
			this.graph_geometry.vertices[this.history - 1].color = this.color_red;
		} else if(_p < 0.2) this.graph_geometry.vertices[this.history - 1].color = this.color_green; else this.graph_geometry.vertices[this.history - 1].color = this.color_normal;
		if(_p < 0.001) _p = 0.001;
		this.graph_geometry.vertices[this.history - 1].pos.set_y(Math.floor(this.height2 * (1.0 - _p)));
		return this.ping = _v;
	}
	,set_value: function(_v) {
		var _vv = luxe_utils_Maths.fixed(_v * 1000,4);
		var _p = _vv / this.max;
		if(_p > 1) {
			_p = 1;
			this.bar_geometry.set_color(this.color_red);
		} else if(_p < 0.15) this.bar_geometry.set_color(this.color_green); else this.bar_geometry.set_color(this.color_normal);
		if(_p < 0.005) _p = 0.005;
		var nx = (this.width - 2) * _p;
		this.bar_geometry.resize(new phoenix_Vector(nx,this.height - 2));
		return this.value = _v;
	}
	,set_pos: function(_p) {
		this.bg_geometry.transform.local.set_pos(_p);
		this.bar_geometry.transform.set_pos(new phoenix_Vector(_p.x + 1,_p.y + 1));
		this.text_item.set_pos(new phoenix_Vector(_p.x + this.width * 2 + 10,_p.y - 6));
		this.graphbg_geometry.transform.set_pos(new phoenix_Vector(_p.x + this.width + 2,_p.y - 4));
		this.graph_geometry.transform.local.set_pos(this.graphbg_geometry.transform.local.pos);
		return this.pos = _p;
	}
	,set_text: function(_t) {
		this.text_item.set_text("" + this.name + " (" + this.max + "ms) | " + _t + "ms");
		return this.text = _t;
	}
	,__class__: luxe_debug__$ProfilerDebugView_ProfilerBar
	,__properties__: {set_ping:"set_ping",set_value:"set_value",set_pos:"set_pos",set_text:"set_text"}
};
var luxe_debug_StatsDebugView = function() {
	this.hide_debug = true;
	this.font_size = 15;
	this.debug_geometry_count = 13;
	this.debug_draw_call_count = 3;
	luxe_debug_DebugView.call(this);
	this.name = "Statistics";
	this._last_render_stats = { batchers : 0, geometry_count : 0, dynamic_batched_count : 0, static_batched_count : 0, visible_count : 0, draw_calls : 0, vert_count : 0, group_count : 0};
	this._render_stats = { batchers : 0, geometry_count : 0, dynamic_batched_count : 0, static_batched_count : 0, visible_count : 0, draw_calls : 0, vert_count : 0, group_count : 0};
};
luxe_debug_StatsDebugView.__name__ = true;
luxe_debug_StatsDebugView.__super__ = luxe_debug_DebugView;
luxe_debug_StatsDebugView.prototype = $extend(luxe_debug_DebugView.prototype,{
	get_resource_stats_string: function() {
		return Std.string(Luxe.resources.stats);
	}
	,get_render_stats_string: function() {
		return "Renderer Statistics\n" + "\tbatcher count : " + this._render_stats.batchers + "\n" + "\ttotal geometry : " + this._render_stats.geometry_count + "\n" + "\tvisible geometry : " + this._render_stats.visible_count + "\n" + "\tdynamic batch count : " + this._render_stats.dynamic_batched_count + "\n" + "\tstatic batch count : " + this._render_stats.static_batched_count + "\n" + "\ttotal draw calls : " + this._render_stats.draw_calls + "\n" + "\ttotal vert count : " + this._render_stats.vert_count;
	}
	,create: function() {
		var debug = Luxe.debug;
		this.render_stats_text = new luxe_Text({ depth : 999.3, no_scene : true, color : new phoenix_Color(0,0,0,1).rgb(16121979), pos : new phoenix_Vector(debug.padding.x * 2,debug.padding.y * 3), font : Luxe.renderer.font, text : this.get_render_stats_string(), point_size : this.font_size, batcher : debug.batcher, visible : false},{ fileName : "StatsDebugView.hx", lineNumber : 82, className : "luxe.debug.StatsDebugView", methodName : "create"});
		this.resource_stats_text = new luxe_Text({ depth : 999.3, no_scene : true, color : new phoenix_Color(0,0,0,1).rgb(16121979), pos : new phoenix_Vector(debug.padding.x * 2,debug.padding.y * 7.5), font : Luxe.renderer.font, text : this.get_resource_stats_string(), point_size : this.font_size, batcher : debug.batcher, visible : false},{ fileName : "StatsDebugView.hx", lineNumber : 94, className : "luxe.debug.StatsDebugView", methodName : "create"});
		this.resource_list_text = new luxe_Text({ depth : 999.3, no_scene : true, color : new phoenix_Color(0,0,0,1).rgb(16121979), pos : new phoenix_Vector(debug.padding.x * 7,debug.padding.y * 3), font : Luxe.renderer.font, text : "", point_size : this.font_size * 0.8, batcher : debug.batcher, visible : false},{ fileName : "StatsDebugView.hx", lineNumber : 106, className : "luxe.debug.StatsDebugView", methodName : "create"});
		this.resource_list_text.set_locked(true);
		this.resource_stats_text.set_locked(true);
	}
	,onwindowsized: function(e) {
		var debug = Luxe.debug;
		if(this.resource_list_text != null) {
			this.resource_list_text.set_pos(new phoenix_Vector(debug.padding.x * 7,debug.padding.y * 3));
			this.resource_list_text.geometry.set_dirty(true);
		}
		if(this.resource_stats_text != null) {
			this.resource_stats_text.set_pos(new phoenix_Vector(debug.padding.x * 2,debug.padding.y * 7.5));
			this.resource_stats_text.geometry.set_dirty(true);
		}
		if(this.render_stats_text != null) {
			this.render_stats_text.set_pos(new phoenix_Vector(debug.padding.x * 2,debug.padding.y * 3));
			this.render_stats_text.geometry.set_dirty(true);
		}
	}
	,refresh: function() {
		var texture_lists = "";
		var shader_lists = "";
		var font_lists = "";
		var _g = 0;
		var _g1 = Luxe.resources.resourcelist;
		while(_g < _g1.length) {
			var res = _g1[_g];
			++_g;
			var _g2 = res.type;
			switch(_g2) {
			case 4:
				var t = res;
				texture_lists += "\t" + t.id + "    (" + t.width_actual + "x" + t.height_actual + "  " + t.estimated_memory() + " )\n";
				break;
			case 7:
				font_lists += "\t" + res.id + "\n";
				break;
			case 8:
				shader_lists += "\t" + res.id + "\n";
				break;
			default:
			}
		}
		var lists = "Fonts\n";
		lists += font_lists;
		lists += "Shader\n";
		lists += shader_lists;
		lists += "Textures\n";
		lists += texture_lists;
		this.resource_list_text.set_text(lists);
		if(this.resource_list_text.geometry != null) this.resource_list_text.geometry.set_dirty(true);
	}
	,process: function() {
		if(!this.visible) return;
		var dirty = false;
		this.update_render_stats();
		if(this._last_render_stats.batchers != this._render_stats.batchers) {
			dirty = true;
			this._last_render_stats.batchers = this._render_stats.batchers;
		}
		if(this._last_render_stats.geometry_count != this._render_stats.geometry_count) {
			dirty = true;
			this._last_render_stats.geometry_count = this._render_stats.geometry_count;
		}
		if(this._last_render_stats.dynamic_batched_count != this._render_stats.dynamic_batched_count) {
			dirty = true;
			this._last_render_stats.dynamic_batched_count = this._render_stats.dynamic_batched_count;
		}
		if(this._last_render_stats.static_batched_count != this._render_stats.static_batched_count) {
			dirty = true;
			this._last_render_stats.static_batched_count = this._render_stats.static_batched_count;
		}
		if(this._last_render_stats.visible_count != this._render_stats.visible_count) {
			dirty = true;
			this._last_render_stats.visible_count = this._render_stats.visible_count;
		}
		if(this._last_render_stats.draw_calls != this._render_stats.draw_calls) {
			dirty = true;
			this._last_render_stats.draw_calls = this._render_stats.draw_calls;
		}
		if(this._last_render_stats.group_count != this._render_stats.group_count) {
			dirty = true;
			this._last_render_stats.group_count = this._render_stats.group_count;
		}
		if(this._last_render_stats.vert_count != this._render_stats.vert_count) {
			dirty = true;
			this._last_render_stats.vert_count = this._render_stats.vert_count;
		}
		if(dirty) this.refresh_render_stats();
	}
	,onkeydown: function(e) {
		if(e.keycode == snow_input_Keycodes.key_2 && this.visible) this.toggle_debug_stats();
	}
	,show: function() {
		luxe_debug_DebugView.prototype.show.call(this);
		this.refresh();
		this.render_stats_text.set_visible(true);
		this.resource_stats_text.set_visible(true);
		this.resource_list_text.set_visible(true);
	}
	,hide: function() {
		luxe_debug_DebugView.prototype.hide.call(this);
		this.render_stats_text.set_visible(false);
		this.resource_stats_text.set_visible(false);
		this.resource_list_text.set_visible(false);
	}
	,refresh_render_stats: function() {
		if(!this.visible) return;
		this.render_stats_text.set_text(this.get_render_stats_string());
		this.resource_stats_text.set_text(this.get_resource_stats_string());
		this.resource_stats_text.set_locked(true);
		this.render_stats_text.set_locked(true);
		if(this.render_stats_text.geometry != null) {
			this.resource_stats_text.geometry.set_dirty(true);
			this.render_stats_text.geometry.set_dirty(true);
		}
	}
	,toggle_debug_stats: function() {
		this.hide_debug = !this.hide_debug;
	}
	,update_render_stats: function() {
		this.debug_geometry_count = Luxe.debug.batcher.geometry.size();
		this.debug_draw_call_count = Luxe.debug.batcher.draw_calls;
		this._render_stats.batchers = Luxe.renderer.stats.batchers;
		this._render_stats.geometry_count = Luxe.renderer.stats.geometry_count;
		this._render_stats.visible_count = Luxe.renderer.stats.visible_count;
		this._render_stats.dynamic_batched_count = Luxe.renderer.stats.dynamic_batched_count;
		this._render_stats.static_batched_count = Luxe.renderer.stats.static_batched_count;
		this._render_stats.draw_calls = Luxe.renderer.stats.draw_calls;
		this._render_stats.vert_count = Luxe.renderer.stats.vert_count;
		if(this.hide_debug) {
			this._render_stats.batchers = this._render_stats.batchers - 1;
			this._render_stats.geometry_count = this._render_stats.geometry_count - this.debug_geometry_count;
			this._render_stats.visible_count = this._render_stats.visible_count - Luxe.debug.batcher.visible_count;
			this._render_stats.dynamic_batched_count = this._render_stats.dynamic_batched_count - Luxe.debug.batcher.dynamic_batched_count;
			this._render_stats.static_batched_count = this._render_stats.static_batched_count - Luxe.debug.batcher.static_batched_count;
			this._render_stats.draw_calls -= this.debug_draw_call_count;
			this._render_stats.vert_count -= Luxe.debug.batcher.vert_count;
		}
	}
	,__class__: luxe_debug_StatsDebugView
});
var luxe_debug_TraceDebugView = function() {
	this._last_logged_length = 0;
	this.max_lines = 35;
	luxe_debug_DebugView.call(this);
	this.name = "Log";
	Luxe.debug.add_trace_listener("TraceDebugView",$bind(this,this.on_trace));
	this.logged = [];
	this.add_line("luxe version " + Luxe.build + " Debug Log");
};
luxe_debug_TraceDebugView.__name__ = true;
luxe_debug_TraceDebugView.__super__ = luxe_debug_DebugView;
luxe_debug_TraceDebugView.prototype = $extend(luxe_debug_DebugView.prototype,{
	on_trace: function(v,inf) {
		this.add_line(inf.fileName + ":" + inf.lineNumber + " " + Std.string(v));
	}
	,create: function() {
		var debug = Luxe.debug;
		var text_bounds = new phoenix_Rectangle(debug.padding.x + 20,debug.padding.y + 40,Luxe.core.screen.w - debug.padding.x * 2 - 20,Luxe.core.screen.h - debug.padding.y * 2 - 40);
		this.lines = new luxe_Text({ name : "debug.log.text", no_scene : true, depth : 999.3, color : new phoenix_Color().rgb(8947848), bounds : text_bounds, bounds_wrap : true, font : Luxe.renderer.font, text : "", align_vertical : 4, point_size : 12, batcher : debug.batcher, visible : false},{ fileName : "TraceDebugView.hx", lineNumber : 35, className : "luxe.debug.TraceDebugView", methodName : "create"});
		if(this.lines.geometry != null) {
			this.lines.geometry.set_clip_rect(text_bounds);
			this.lines.geometry.set_locked(true);
		}
	}
	,onwindowsized: function(e) {
		var debug = Luxe.debug;
		var text_bounds = new phoenix_Rectangle(debug.padding.x + 20,debug.padding.y + 40,Luxe.core.screen.w - debug.padding.x * 2 - 20,Luxe.core.screen.h - debug.padding.y * 2 - 40);
		this.lines.set_bounds(text_bounds);
		this.lines.set_clip_rect(text_bounds);
		if(this.lines.geometry != null) {
			this.lines.geometry.set_locked(true);
			this.lines.geometry.set_dirty(true);
		}
	}
	,add_line: function(_t) {
		if(this.logged == null) return;
		this.logged.push(_t);
		if(!this.visible) return;
		this.refresh_lines();
	}
	,refresh_lines: function() {
		if(this._last_logged_length == this.logged.length) return;
		var _final = "";
		if(this.logged.length <= this.max_lines) {
			var _g = 0;
			var _g1 = this.logged;
			while(_g < _g1.length) {
				var _line = _g1[_g];
				++_g;
				_final += _line + "\n";
			}
		} else {
			var _start = this.logged.length - this.max_lines;
			var _total = this.logged.length;
			var _g11 = _start;
			var _g2 = this.logged.length;
			while(_g11 < _g2) {
				var i = _g11++;
				var _line1 = this.logged[i];
				_final += _line1 + "\n";
			}
		}
		this.lines.set_text(_final);
		if(this.lines.geometry != null) {
			this.lines.geometry.set_locked(true);
			this.lines.geometry.set_dirty(true);
		}
		this._last_logged_length = this.logged.length;
	}
	,refresh: function() {
	}
	,process: function() {
	}
	,show: function() {
		luxe_debug_DebugView.prototype.show.call(this);
		this.refresh_lines();
		this.lines.set_visible(true);
	}
	,hide: function() {
		luxe_debug_DebugView.prototype.hide.call(this);
		this.lines.set_visible(false);
	}
	,__class__: luxe_debug_TraceDebugView
});
var luxe_macros_BuildVersion = function() { };
luxe_macros_BuildVersion.__name__ = true;
luxe_macros_BuildVersion.try_git = function(root) {
	return "";
};
var luxe_options__$DrawOptions_DrawOptions = function() { };
luxe_options__$DrawOptions_DrawOptions.__name__ = true;
var luxe_resource_Resource = function(_manager,_type,_load_time) {
	this.dropped = false;
	this.time_created = 0;
	this.time_to_load = 0;
	this.persistent = false;
	if(_manager == null) this.manager = Luxe.resources; else this.manager = _manager;
	this.type = _type;
	this.time_to_load = _load_time;
	this.time_created = snow_Snow.core.timestamp();
	this.manager.add(this);
};
luxe_resource_Resource.__name__ = true;
luxe_resource_Resource.prototype = {
	drop: function() {
		if(!this.dropped) {
			this.dropped = true;
			this.manager.remove(this);
		}
	}
	,__class__: luxe_resource_Resource
};
var luxe_resource_TextResource = function(_id,_text,_manager) {
	this.id = _id;
	luxe_resource_Resource.call(this,_manager,1);
	this.text = _text;
};
luxe_resource_TextResource.__name__ = true;
luxe_resource_TextResource.__super__ = luxe_resource_Resource;
luxe_resource_TextResource.prototype = $extend(luxe_resource_Resource.prototype,{
	__class__: luxe_resource_TextResource
});
var luxe_resource_JSONResource = function(_id,_json,_manager) {
	this.id = _id;
	luxe_resource_Resource.call(this,_manager,2);
	this.json = _json;
};
luxe_resource_JSONResource.__name__ = true;
luxe_resource_JSONResource.__super__ = luxe_resource_Resource;
luxe_resource_JSONResource.prototype = $extend(luxe_resource_Resource.prototype,{
	__class__: luxe_resource_JSONResource
});
var luxe_resource_DataResource = function(_id,_data,_manager) {
	this.id = _id;
	luxe_resource_Resource.call(this,_manager,3);
	this.data = _data;
};
luxe_resource_DataResource.__name__ = true;
luxe_resource_DataResource.__super__ = luxe_resource_Resource;
luxe_resource_DataResource.prototype = $extend(luxe_resource_Resource.prototype,{
	__class__: luxe_resource_DataResource
});
var luxe_resource_SoundResource = function(_id,_name,_manager) {
	this.id = _id;
	luxe_resource_Resource.call(this,_manager,5);
	this.name = _name;
};
luxe_resource_SoundResource.__name__ = true;
luxe_resource_SoundResource.__super__ = luxe_resource_Resource;
luxe_resource_SoundResource.prototype = $extend(luxe_resource_Resource.prototype,{
	__class__: luxe_resource_SoundResource
});
var luxe_resource_Resources = function() {
	this.resourcelist = [];
	this.textures = new haxe_ds_StringMap();
	this.render_textures = new haxe_ds_StringMap();
	this.fonts = new haxe_ds_StringMap();
	this.shaders = new haxe_ds_StringMap();
	this.sounds = new haxe_ds_StringMap();
	this.data = new haxe_ds_StringMap();
	this.text = new haxe_ds_StringMap();
	this.json = new haxe_ds_StringMap();
	this.stats = new luxe_resource_ResourceStats();
};
luxe_resource_Resources.__name__ = true;
luxe_resource_Resources.prototype = {
	add: function(res) {
		this.resourcelist.push(res);
		var _g = res.type;
		switch(_g) {
		case 4:
			this.stats.textures++;
			break;
		case 6:
			this.stats.render_textures++;
			break;
		case 7:
			this.stats.fonts++;
			break;
		case 8:
			this.stats.shaders++;
			break;
		case 5:
			this.stats.sounds++;
			break;
		case 1:
			this.stats.texts++;
			break;
		case 2:
			this.stats.jsons++;
			break;
		case 3:
			this.stats.datas++;
			break;
		case 0:
			this.stats.unknown++;
			break;
		}
		this.stats.resources++;
	}
	,remove: function(res) {
		HxOverrides.remove(this.resourcelist,res);
		this.uncache(res);
		var _g = res.type;
		switch(_g) {
		case 4:
			this.stats.textures--;
			break;
		case 6:
			this.stats.render_textures--;
			break;
		case 7:
			this.stats.fonts--;
			break;
		case 8:
			this.stats.shaders--;
			break;
		case 5:
			this.stats.sounds--;
			break;
		case 1:
			this.stats.texts--;
			break;
		case 2:
			this.stats.jsons--;
			break;
		case 3:
			this.stats.datas--;
			break;
		case 0:
			this.stats.unknown--;
			break;
		}
		this.stats.resources--;
	}
	,uncache: function(res) {
		var _g = res.type;
		switch(_g) {
		case 4:
			this.textures.remove(res.id);
			break;
		case 6:
			this.render_textures.remove(res.id);
			break;
		case 7:
			this.fonts.remove(res.id);
			break;
		case 8:
			this.shaders.remove(res.id);
			break;
		case 5:
			this.sounds.remove(res.id);
			break;
		case 3:
			this.data.remove(res.id);
			break;
		case 1:
			this.text.remove(res.id);
			break;
		case 2:
			this.json.remove(res.id);
			break;
		case 0:
			break;
		}
	}
	,cache: function(res) {
		var _g = res.type;
		switch(_g) {
		case 4:
			this.textures.set(res.id,res);
			break;
		case 6:
			this.render_textures.set(res.id,res);
			break;
		case 7:
			this.fonts.set(res.id,res);
			break;
		case 8:
			this.shaders.set(res.id,res);
			break;
		case 5:
			this.sounds.set(res.id,res);
			break;
		case 1:
			this.text.set(res.id,res);
			break;
		case 2:
			this.json.set(res.id,res);
			break;
		case 3:
			this.data.set(res.id,res);
			break;
		case 0:
			break;
		}
	}
	,find_render_texture: function(_name) {
		return this.render_textures.get(_name);
	}
	,find_texture: function(_name) {
		return this.textures.get(_name);
	}
	,find_shader: function(_name) {
		return this.shaders.get(_name);
	}
	,find_font: function(_name) {
		return this.fonts.get(_name);
	}
	,find_sound: function(_name) {
		return this.sounds.get(_name);
	}
	,find_text: function(_name) {
		return this.text.get(_name);
	}
	,find_json: function(_name) {
		return this.json.get(_name);
	}
	,find_data: function(_name) {
		return this.data.get(_name);
	}
	,clear: function(and_persistent) {
		if(and_persistent == null) and_persistent = false;
		var keep = [];
		var _g = 0;
		var _g1 = this.resourcelist;
		while(_g < _g1.length) {
			var res = _g1[_g];
			++_g;
			if(!res.persistent || and_persistent) res.drop(); else keep.push(res);
		}
		this.resourcelist.splice(0,this.resourcelist.length);
		this.resourcelist = [];
		this.stats.reset();
		var _g2 = 0;
		while(_g2 < keep.length) {
			var res1 = keep[_g2];
			++_g2;
			this.add(res1);
		}
		keep = null;
	}
	,find: function(id) {
		var _g = 0;
		var _g1 = this.resourcelist;
		while(_g < _g1.length) {
			var resource = _g1[_g];
			++_g;
			if(resource.id == id) return resource;
		}
		return null;
	}
	,__class__: luxe_resource_Resources
};
var luxe_resource_ResourceStats = function() {
	this.unknown = 0;
	this.sounds = 0;
	this.datas = 0;
	this.jsons = 0;
	this.texts = 0;
	this.shaders = 0;
	this.render_textures = 0;
	this.textures = 0;
	this.fonts = 0;
	this.resources = 0;
};
luxe_resource_ResourceStats.__name__ = true;
luxe_resource_ResourceStats.prototype = {
	toString: function() {
		return "Resource Statistics\n" + "\ttotal resources : " + this.resources + "\n" + "\ttextures : " + this.textures + " \n" + "" + "\trender textures : " + this.render_textures + " \n" + "\tfonts : " + this.fonts + "\n" + "\tshaders : " + this.shaders + "\n" + "\tsounds : " + this.sounds + "\n" + "\ttext : " + this.texts + "\n" + "\tjson : " + this.jsons + "\n" + "\tdata : " + this.datas + "\n" + "\tunknown : " + this.unknown;
	}
	,reset: function() {
		this.resources = 0;
		this.fonts = 0;
		this.textures = 0;
		this.render_textures = 0;
		this.shaders = 0;
		this.texts = 0;
		this.jsons = 0;
		this.datas = 0;
		this.sounds = 0;
		this.unknown = 0;
	}
	,__class__: luxe_resource_ResourceStats
};
var luxe_structural_BalancedBST = function(compare_function) {
	this.compare = compare_function;
	this._array = [];
};
luxe_structural_BalancedBST.__name__ = true;
luxe_structural_BalancedBST.prototype = {
	size: function() {
		return this.node_count(this.root);
	}
	,depth: function() {
		return this.node_depth(this.root);
	}
	,insert: function(_key,_value) {
		this.root = this.node_insert(this.root,_key,_value);
		this.root.color = false;
		this._array = null;
		this._array = this.toArray();
	}
	,contains: function(_key) {
		return this.find(_key) != null;
	}
	,find: function(_key) {
		return this.node_find(this.root,_key);
	}
	,rank: function(_key) {
		return this.node_rank(_key,this.root);
	}
	,select: function(_rank) {
		var _node = this.node_select(this.root,_rank);
		if(_node != null) return _node.key; else return null;
	}
	,smallest: function() {
		var _node = this.node_smallest(this.root);
		if(_node != null) return _node.key; else return null;
	}
	,largest: function() {
		var _node = this.node_largest(this.root);
		if(_node != null) return _node.key; else return null;
	}
	,remove: function(_key) {
		if(!this.is_red(this.root.left) && !this.is_red(this.root.right)) this.root.color = true;
		if(!this.contains(_key)) return false;
		this.root = this.node_remove(this.root,_key);
		if(this.root != null) this.root.color = false;
		this._array = null;
		this._array = this.toArray();
		return true;
	}
	,remove_smallest: function() {
		if(!this.is_red(this.root.left) && !this.is_red(this.root.right)) this.root.color = true;
		this.root = this.node_remove_smallest(this.root);
		if(this.root != null) this.root.color = false;
		this._array = null;
		this._array = this.toArray();
		return true;
	}
	,remove_largest: function() {
		if(!this.is_red(this.root.left) && !this.is_red(this.root.right)) this.root.color = true;
		this.root = this.node_remove_largest(this.root);
		if(this.root != null) this.root.color = false;
		this._array = null;
		this._array = this.toArray();
		return true;
	}
	,floor: function(_key) {
		var _node = this.node_floor(this.root,_key);
		if(_node == null) return null;
		return _node.key;
	}
	,ceil: function(_key) {
		var _node = this.node_ceil(this.root,_key);
		if(_node == null) return null;
		return _node.key;
	}
	,toArray: function() {
		var a = [];
		this.traverse_node(this.root,luxe_structural_BalancedBSTTraverseMethod.order_retain,function(_node) {
			a.push(_node.value);
		});
		return a;
	}
	,keys: function() {
		var a = [];
		this.traverse_node(this.root,luxe_structural_BalancedBSTTraverseMethod.order_retain,function(_node) {
			a.push(_node.key);
		});
		return a;
	}
	,iterator: function() {
		return HxOverrides.iter(this._array);
	}
	,traverse_node: function(_node,_method,_on_traverse) {
		if(_node != null) switch(_method[1]) {
		case 0:
			_on_traverse(_node);
			this.traverse_node(_node.left,_method,_on_traverse);
			this.traverse_node(_node.right,_method,_on_traverse);
			break;
		case 1:
			this.traverse_node(_node.left,_method,_on_traverse);
			_on_traverse(_node);
			this.traverse_node(_node.right,_method,_on_traverse);
			break;
		case 2:
			this.traverse_node(_node.left,_method,_on_traverse);
			this.traverse_node(_node.right,_method,_on_traverse);
			_on_traverse(_node);
			break;
		}
	}
	,get_empty: function() {
		return this.root == null;
	}
	,node_depth: function(_node) {
		if(_node == null) return 0;
		var _n_depth = Math.max(this.node_depth(_node.left),this.node_depth(_node.right));
		return 1 + (_n_depth | 0);
	}
	,node_count: function(_node) {
		if(_node == null) return 0; else return _node.nodecount;
	}
	,node_insert: function(_node,_key,_value) {
		if(_node == null) return new luxe_structural_BalancedBSTNode(_key,_value,1,true);
		var comparison = this.compare(_key,_node.key);
		if(comparison < 0) _node.left = this.node_insert(_node.left,_key,_value); else if(comparison > 0) _node.right = this.node_insert(_node.right,_key,_value); else _node.value = _value;
		if(this.is_red(_node.right) && !this.is_red(_node.left)) _node = this.rotate_left(_node);
		if(this.is_red(_node.left) && this.is_red(_node.left.left)) _node = this.rotate_right(_node);
		if(this.is_red(_node.left) && this.is_red(_node.right)) this.swap_color(_node);
		this.node_update_count(_node);
		return _node;
	}
	,node_update_count: function(_node) {
		_node.nodecount = this.node_count(_node.left) + this.node_count(_node.right) + 1;
		return _node;
	}
	,node_find: function(_node,_key) {
		if(_node == null) return null;
		var comparison = this.compare(_key,_node.key);
		if(comparison < 0) return this.node_find(_node.left,_key); else if(comparison > 0) return this.node_find(_node.right,_key); else return _node.value;
	}
	,node_rank: function(_key,_node) {
		if(_node == null) return 0;
		var comparison = this.compare(_key,_node.key);
		if(comparison < 0) return this.node_rank(_key,_node.left); else if(comparison > 0) return 1 + this.node_count(_node.left) + this.node_rank(_key,_node.right); else return this.node_count(_node.left);
	}
	,node_select: function(_node,_rank) {
		if(_node == null) return null;
		var _r = this.node_count(_node.left);
		if(_r > _rank) return this.node_select(_node.left,_rank); else if(_r < _rank) return this.node_select(_node.right,_rank - _r - 1); else return _node;
	}
	,node_smallest: function(_node) {
		if(_node.left == null) return _node;
		return this.node_smallest(_node.left);
	}
	,node_largest: function(_node) {
		if(_node.right == null) return _node; else return this.node_largest(_node.right);
	}
	,node_floor: function(_node,_key) {
		if(_node == null) return null;
		var comparison = this.compare(_key,_node.key);
		if(comparison == 0) return _node; else if(comparison < 0) return this.node_floor(_node.left,_key);
		var _n = this.node_floor(_node.right,_key);
		if(_n != null) return _n; else return _node;
	}
	,node_ceil: function(_node,_key) {
		if(_node == null) return null;
		var comparison = this.compare(_key,_node.key);
		if(comparison == 0) return _node; else if(comparison < 0) {
			var _n = this.node_ceil(_node.left,_key);
			if(_n != null) return _n; else return _node;
		}
		return this.node_ceil(_node.right,_key);
	}
	,node_remove_smallest: function(_node) {
		if(_node.left == null) return null;
		if(!this.is_red(_node.left) && !this.is_red(_node.left.left)) _node = this.move_red_left(_node);
		_node.left = this.node_remove_smallest(_node.left);
		this.node_update_count(_node);
		return this.balance(_node);
	}
	,node_remove_largest: function(_node) {
		if(this.is_red(_node.left)) _node = this.rotate_right(_node);
		if(_node.right == null) return null;
		if(!this.is_red(_node.right) && !this.is_red(_node.right.left)) _node = this.move_red_right(_node);
		_node.right = this.node_remove_largest(_node.right);
		this.node_update_count(_node);
		return this.balance(_node);
	}
	,node_remove: function(_node,_key) {
		var comparison = this.compare(_key,_node.key);
		if(comparison < 0) {
			if(!this.is_red(_node.left) && !this.is_red(_node.left.left)) _node = this.move_red_left(_node);
			_node.left = this.node_remove(_node.left,_key);
		} else {
			if(this.is_red(_node.left)) _node = this.rotate_right(_node);
			var comparison1 = this.compare(_key,_node.key);
			if(comparison1 == 0 && _node.right == null) return null;
			if(!this.is_red(_node.right) && !this.is_red(_node.right.left)) _node = this.move_red_right(_node);
			var comparison2 = this.compare(_key,_node.key);
			if(comparison2 == 0) {
				var _n = this.node_smallest(_node.right);
				_node.key = _n.key;
				_node.value = _n.value;
				_node.right = this.node_remove_smallest(_node.right);
			} else _node.right = this.node_remove(_node.right,_key);
		}
		return this.balance(_node);
	}
	,is_red: function(_node) {
		if(_node == null) return false;
		return _node.color == true;
	}
	,rotate_left: function(_node) {
		var _n = _node.right;
		_n.color = _node.color;
		_node.color = true;
		_node.right = _n.left;
		_n.left = _node;
		_n.nodecount = _node.nodecount;
		this.node_update_count(_node);
		return _n;
	}
	,rotate_right: function(_node) {
		var _n = _node.left;
		_n.color = _node.color;
		_node.color = true;
		_node.left = _n.right;
		_n.right = _node;
		_n.nodecount = _node.nodecount;
		this.node_update_count(_node);
		return _n;
	}
	,swap_color: function(_node) {
		_node.color = !_node.color;
		_node.left.color = !_node.left.color;
		_node.right.color = !_node.right.color;
	}
	,move_red_left: function(_node) {
		this.swap_color(_node);
		if(this.is_red(_node.right.left)) {
			_node.right = this.rotate_right(_node.right);
			_node = this.rotate_left(_node);
		}
		return _node;
	}
	,move_red_right: function(_node) {
		this.swap_color(_node);
		if(this.is_red(_node.left.left)) _node = this.rotate_right(_node);
		return _node;
	}
	,balance: function(_node) {
		if(this.is_red(_node.right)) _node = this.rotate_left(_node);
		if(this.is_red(_node.left) && this.is_red(_node.left.left)) _node = this.rotate_right(_node);
		if(this.is_red(_node.left) && this.is_red(_node.right)) this.swap_color(_node);
		this.node_update_count(_node);
		return _node;
	}
	,__class__: luxe_structural_BalancedBST
	,__properties__: {get_empty:"get_empty"}
};
var luxe_structural__$BalancedBST_NodeColor = function() { };
luxe_structural__$BalancedBST_NodeColor.__name__ = true;
var luxe_structural_BalancedBSTNode = function(_key,_value,_node_count,_color) {
	this.left = null;
	this.right = null;
	this.key = _key;
	this.value = _value;
	this.nodecount = _node_count;
	this.color = _color;
};
luxe_structural_BalancedBSTNode.__name__ = true;
luxe_structural_BalancedBSTNode.prototype = {
	__class__: luxe_structural_BalancedBSTNode
};
var luxe_structural_BalancedBSTTraverseMethod = { __ename__ : true, __constructs__ : ["order_pre","order_retain","order_post"] };
luxe_structural_BalancedBSTTraverseMethod.order_pre = ["order_pre",0];
luxe_structural_BalancedBSTTraverseMethod.order_pre.toString = $estr;
luxe_structural_BalancedBSTTraverseMethod.order_pre.__enum__ = luxe_structural_BalancedBSTTraverseMethod;
luxe_structural_BalancedBSTTraverseMethod.order_retain = ["order_retain",1];
luxe_structural_BalancedBSTTraverseMethod.order_retain.toString = $estr;
luxe_structural_BalancedBSTTraverseMethod.order_retain.__enum__ = luxe_structural_BalancedBSTTraverseMethod;
luxe_structural_BalancedBSTTraverseMethod.order_post = ["order_post",2];
luxe_structural_BalancedBSTTraverseMethod.order_post.toString = $estr;
luxe_structural_BalancedBSTTraverseMethod.order_post.__enum__ = luxe_structural_BalancedBSTTraverseMethod;
var luxe_structural_BalancedBSTNode_$phoenix_$geometry_$GeometryKey_$phoenix_$geometry_$Geometry = function(_key,_value,_node_count,_color) {
	this.left = null;
	this.right = null;
	this.key = _key;
	this.value = _value;
	this.nodecount = _node_count;
	this.color = _color;
};
luxe_structural_BalancedBSTNode_$phoenix_$geometry_$GeometryKey_$phoenix_$geometry_$Geometry.__name__ = true;
luxe_structural_BalancedBSTNode_$phoenix_$geometry_$GeometryKey_$phoenix_$geometry_$Geometry.prototype = {
	__class__: luxe_structural_BalancedBSTNode_$phoenix_$geometry_$GeometryKey_$phoenix_$geometry_$Geometry
};
var luxe_structural_BalancedBST_$phoenix_$geometry_$GeometryKey_$phoenix_$geometry_$Geometry = function(compare_function) {
	this.compare = compare_function;
	this._array = [];
};
luxe_structural_BalancedBST_$phoenix_$geometry_$GeometryKey_$phoenix_$geometry_$Geometry.__name__ = true;
luxe_structural_BalancedBST_$phoenix_$geometry_$GeometryKey_$phoenix_$geometry_$Geometry.prototype = {
	size: function() {
		return this.node_count(this.root);
	}
	,depth: function() {
		return this.node_depth(this.root);
	}
	,insert: function(_key,_value) {
		this.root = this.node_insert(this.root,_key,_value);
		this.root.color = false;
		this._array = null;
		this._array = this.toArray();
	}
	,contains: function(_key) {
		return this.find(_key) != null;
	}
	,find: function(_key) {
		return this.node_find(this.root,_key);
	}
	,rank: function(_key) {
		return this.node_rank(_key,this.root);
	}
	,select: function(_rank) {
		var _node = this.node_select(this.root,_rank);
		if(_node != null) return _node.key; else return null;
	}
	,smallest: function() {
		var _node = this.node_smallest(this.root);
		if(_node != null) return _node.key; else return null;
	}
	,largest: function() {
		var _node = this.node_largest(this.root);
		if(_node != null) return _node.key; else return null;
	}
	,remove: function(_key) {
		if(!this.is_red(this.root.left) && !this.is_red(this.root.right)) this.root.color = true;
		if(!this.contains(_key)) return false;
		this.root = this.node_remove(this.root,_key);
		if(this.root != null) this.root.color = false;
		this._array = null;
		this._array = this.toArray();
		return true;
	}
	,remove_smallest: function() {
		if(!this.is_red(this.root.left) && !this.is_red(this.root.right)) this.root.color = true;
		this.root = this.node_remove_smallest(this.root);
		if(this.root != null) this.root.color = false;
		this._array = null;
		this._array = this.toArray();
		return true;
	}
	,remove_largest: function() {
		if(!this.is_red(this.root.left) && !this.is_red(this.root.right)) this.root.color = true;
		this.root = this.node_remove_largest(this.root);
		if(this.root != null) this.root.color = false;
		this._array = null;
		this._array = this.toArray();
		return true;
	}
	,floor: function(_key) {
		var _node = this.node_floor(this.root,_key);
		if(_node == null) return null;
		return _node.key;
	}
	,ceil: function(_key) {
		var _node = this.node_ceil(this.root,_key);
		if(_node == null) return null;
		return _node.key;
	}
	,toArray: function() {
		var a = [];
		this.traverse_node(this.root,luxe_structural_BalancedBSTTraverseMethod.order_retain,function(_node) {
			a.push(_node.value);
		});
		return a;
	}
	,keys: function() {
		var a = [];
		this.traverse_node(this.root,luxe_structural_BalancedBSTTraverseMethod.order_retain,function(_node) {
			a.push(_node.key);
		});
		return a;
	}
	,iterator: function() {
		return HxOverrides.iter(this._array);
	}
	,traverse_node: function(_node,_method,_on_traverse) {
		if(_node != null) switch(_method[1]) {
		case 0:
			_on_traverse(_node);
			this.traverse_node(_node.left,_method,_on_traverse);
			this.traverse_node(_node.right,_method,_on_traverse);
			break;
		case 1:
			this.traverse_node(_node.left,_method,_on_traverse);
			_on_traverse(_node);
			this.traverse_node(_node.right,_method,_on_traverse);
			break;
		case 2:
			this.traverse_node(_node.left,_method,_on_traverse);
			this.traverse_node(_node.right,_method,_on_traverse);
			_on_traverse(_node);
			break;
		}
	}
	,get_empty: function() {
		return this.root == null;
	}
	,node_depth: function(_node) {
		if(_node == null) return 0;
		var _n_depth = Math.max(this.node_depth(_node.left),this.node_depth(_node.right));
		return 1 + (_n_depth | 0);
	}
	,node_count: function(_node) {
		if(_node == null) return 0; else return _node.nodecount;
	}
	,node_insert: function(_node,_key,_value) {
		if(_node == null) return new luxe_structural_BalancedBSTNode_$phoenix_$geometry_$GeometryKey_$phoenix_$geometry_$Geometry(_key,_value,1,true);
		var comparison = this.compare(_key,_node.key);
		if(comparison < 0) _node.left = this.node_insert(_node.left,_key,_value); else if(comparison > 0) _node.right = this.node_insert(_node.right,_key,_value); else _node.value = _value;
		if(this.is_red(_node.right) && !this.is_red(_node.left)) _node = this.rotate_left(_node);
		if(this.is_red(_node.left) && this.is_red(_node.left.left)) _node = this.rotate_right(_node);
		if(this.is_red(_node.left) && this.is_red(_node.right)) this.swap_color(_node);
		this.node_update_count(_node);
		return _node;
	}
	,node_update_count: function(_node) {
		_node.nodecount = this.node_count(_node.left) + this.node_count(_node.right) + 1;
		return _node;
	}
	,node_find: function(_node,_key) {
		if(_node == null) return null;
		var comparison = this.compare(_key,_node.key);
		if(comparison < 0) return this.node_find(_node.left,_key); else if(comparison > 0) return this.node_find(_node.right,_key); else return _node.value;
	}
	,node_rank: function(_key,_node) {
		if(_node == null) return 0;
		var comparison = this.compare(_key,_node.key);
		if(comparison < 0) return this.node_rank(_key,_node.left); else if(comparison > 0) return 1 + this.node_count(_node.left) + this.node_rank(_key,_node.right); else return this.node_count(_node.left);
	}
	,node_select: function(_node,_rank) {
		if(_node == null) return null;
		var _r = this.node_count(_node.left);
		if(_r > _rank) return this.node_select(_node.left,_rank); else if(_r < _rank) return this.node_select(_node.right,_rank - _r - 1); else return _node;
	}
	,node_smallest: function(_node) {
		if(_node.left == null) return _node;
		return this.node_smallest(_node.left);
	}
	,node_largest: function(_node) {
		if(_node.right == null) return _node; else return this.node_largest(_node.right);
	}
	,node_floor: function(_node,_key) {
		if(_node == null) return null;
		var comparison = this.compare(_key,_node.key);
		if(comparison == 0) return _node; else if(comparison < 0) return this.node_floor(_node.left,_key);
		var _n = this.node_floor(_node.right,_key);
		if(_n != null) return _n; else return _node;
	}
	,node_ceil: function(_node,_key) {
		if(_node == null) return null;
		var comparison = this.compare(_key,_node.key);
		if(comparison == 0) return _node; else if(comparison < 0) {
			var _n = this.node_ceil(_node.left,_key);
			if(_n != null) return _n; else return _node;
		}
		return this.node_ceil(_node.right,_key);
	}
	,node_remove_smallest: function(_node) {
		if(_node.left == null) return null;
		if(!this.is_red(_node.left) && !this.is_red(_node.left.left)) _node = this.move_red_left(_node);
		_node.left = this.node_remove_smallest(_node.left);
		this.node_update_count(_node);
		return this.balance(_node);
	}
	,node_remove_largest: function(_node) {
		if(this.is_red(_node.left)) _node = this.rotate_right(_node);
		if(_node.right == null) return null;
		if(!this.is_red(_node.right) && !this.is_red(_node.right.left)) _node = this.move_red_right(_node);
		_node.right = this.node_remove_largest(_node.right);
		this.node_update_count(_node);
		return this.balance(_node);
	}
	,node_remove: function(_node,_key) {
		var comparison = this.compare(_key,_node.key);
		if(comparison < 0) {
			if(!this.is_red(_node.left) && !this.is_red(_node.left.left)) _node = this.move_red_left(_node);
			_node.left = this.node_remove(_node.left,_key);
		} else {
			if(this.is_red(_node.left)) _node = this.rotate_right(_node);
			var comparison1 = this.compare(_key,_node.key);
			if(comparison1 == 0 && _node.right == null) return null;
			if(!this.is_red(_node.right) && !this.is_red(_node.right.left)) _node = this.move_red_right(_node);
			var comparison2 = this.compare(_key,_node.key);
			if(comparison2 == 0) {
				var _n = this.node_smallest(_node.right);
				_node.key = _n.key;
				_node.value = _n.value;
				_node.right = this.node_remove_smallest(_node.right);
			} else _node.right = this.node_remove(_node.right,_key);
		}
		return this.balance(_node);
	}
	,is_red: function(_node) {
		if(_node == null) return false;
		return _node.color == true;
	}
	,rotate_left: function(_node) {
		var _n = _node.right;
		_n.color = _node.color;
		_node.color = true;
		_node.right = _n.left;
		_n.left = _node;
		_n.nodecount = _node.nodecount;
		this.node_update_count(_node);
		return _n;
	}
	,rotate_right: function(_node) {
		var _n = _node.left;
		_n.color = _node.color;
		_node.color = true;
		_node.left = _n.right;
		_n.right = _node;
		_n.nodecount = _node.nodecount;
		this.node_update_count(_node);
		return _n;
	}
	,swap_color: function(_node) {
		_node.color = !_node.color;
		_node.left.color = !_node.left.color;
		_node.right.color = !_node.right.color;
	}
	,move_red_left: function(_node) {
		this.swap_color(_node);
		if(this.is_red(_node.right.left)) {
			_node.right = this.rotate_right(_node.right);
			_node = this.rotate_left(_node);
		}
		return _node;
	}
	,move_red_right: function(_node) {
		this.swap_color(_node);
		if(this.is_red(_node.left.left)) _node = this.rotate_right(_node);
		return _node;
	}
	,balance: function(_node) {
		if(this.is_red(_node.right)) _node = this.rotate_left(_node);
		if(this.is_red(_node.left) && this.is_red(_node.left.left)) _node = this.rotate_right(_node);
		if(this.is_red(_node.left) && this.is_red(_node.right)) this.swap_color(_node);
		this.node_update_count(_node);
		return _node;
	}
	,__class__: luxe_structural_BalancedBST_$phoenix_$geometry_$GeometryKey_$phoenix_$geometry_$Geometry
	,__properties__: {get_empty:"get_empty"}
};
var luxe_structural_OrderedMapIterator = function(omap) {
	this.index = 0;
	this.map = omap;
};
luxe_structural_OrderedMapIterator.__name__ = true;
luxe_structural_OrderedMapIterator.prototype = {
	hasNext: function() {
		return this.index < this.map._keys.length;
	}
	,next: function() {
		return this.map.get(this.map._keys[this.index++]);
	}
	,__class__: luxe_structural_OrderedMapIterator
};
var luxe_structural_OrderedMap = function(_map) {
	this.idx = 0;
	this._keys = [];
	this.map = _map;
};
luxe_structural_OrderedMap.__name__ = true;
luxe_structural_OrderedMap.__interfaces__ = [haxe_IMap];
luxe_structural_OrderedMap.prototype = {
	set: function(key,value) {
		if(!this.map.exists(key)) this._keys.push(key);
		{
			this.map.set(key,value);
			value;
		}
	}
	,toString: function() {
		var _ret = "";
		var _cnt = 0;
		var _len = this._keys.length;
		var _g = 0;
		var _g1 = this._keys;
		while(_g < _g1.length) {
			var k = _g1[_g];
			++_g;
			_ret += "" + Std.string(k) + " => " + Std.string(this.map.get(k)) + (_cnt++ < _len - 1?", ":"");
		}
		return "{" + _ret + "}";
	}
	,iterator: function() {
		return new luxe_structural_OrderedMapIterator(this);
	}
	,remove: function(key) {
		return this.map.remove(key) && HxOverrides.remove(this._keys,key);
	}
	,exists: function(key) {
		return this.map.exists(key);
	}
	,get: function(key) {
		return this.map.get(key);
	}
	,keys: function() {
		return HxOverrides.iter(this._keys);
	}
	,__class__: luxe_structural_OrderedMap
};
var luxe_tween_actuators_IGenericActuator = function() { };
luxe_tween_actuators_IGenericActuator.__name__ = true;
luxe_tween_actuators_IGenericActuator.prototype = {
	__class__: luxe_tween_actuators_IGenericActuator
};
var luxe_tween_actuators_GenericActuator = function(target,duration,properties) {
	this.timescaled = false;
	this._autoVisible = true;
	this._delay = 0;
	this._reflect = false;
	this._repeat = 0;
	this._reverse = false;
	this._smartRotation = false;
	this._snapping = false;
	this.special = false;
	this.target = target;
	this.properties = properties;
	this.duration = duration;
	this._ease = luxe_tween_Actuate.defaultEase;
};
luxe_tween_actuators_GenericActuator.__name__ = true;
luxe_tween_actuators_GenericActuator.__interfaces__ = [luxe_tween_actuators_IGenericActuator];
luxe_tween_actuators_GenericActuator.prototype = {
	apply: function() {
		var _g = 0;
		var _g1 = Reflect.fields(this.properties);
		while(_g < _g1.length) {
			var i = _g1[_g];
			++_g;
			if(Object.prototype.hasOwnProperty.call(this.target,i)) Reflect.setField(this.target,i,Reflect.field(this.properties,i)); else Reflect.setProperty(this.target,i,Reflect.field(this.properties,i));
		}
	}
	,autoVisible: function(value) {
		if(value == null) value = true;
		this._autoVisible = value;
		return this;
	}
	,callMethod: function(method,params) {
		if(params == null) params = [];
		return Reflect.callMethod(method,method,params);
	}
	,change: function() {
		if(this._onUpdate != null) this.callMethod(this._onUpdate,this._onUpdateParams);
	}
	,complete: function(sendEvent) {
		if(sendEvent == null) sendEvent = true;
		if(sendEvent) {
			this.change();
			if(this._onComplete != null) this.callMethod(this._onComplete,this._onCompleteParams);
		}
		luxe_tween_Actuate.unload(this);
	}
	,delay: function(duration) {
		this._delay = duration;
		return this;
	}
	,ease: function(easing) {
		this._ease = easing;
		return this;
	}
	,move: function() {
	}
	,timescale: function(_value) {
		if(_value == null) _value = true;
		this.timescaled = _value;
		return this;
	}
	,onComplete: function(handler,parameters) {
		this._onComplete = handler;
		if(parameters == null) this._onCompleteParams = []; else this._onCompleteParams = parameters;
		if(this.duration == 0) this.complete();
		return this;
	}
	,onRepeat: function(handler,parameters) {
		this._onRepeat = handler;
		if(parameters == null) this._onRepeatParams = []; else this._onRepeatParams = parameters;
		return this;
	}
	,onUpdate: function(handler,parameters) {
		this._onUpdate = handler;
		if(parameters == null) this._onUpdateParams = []; else this._onUpdateParams = parameters;
		return this;
	}
	,pause: function() {
	}
	,reflect: function(value) {
		if(value == null) value = true;
		this._reflect = value;
		this.special = true;
		return this;
	}
	,repeat: function(times) {
		if(times == null) times = -1;
		this._repeat = times;
		return this;
	}
	,resume: function() {
	}
	,reverse: function(value) {
		if(value == null) value = true;
		this._reverse = value;
		this.special = true;
		return this;
	}
	,smartRotation: function(value) {
		if(value == null) value = true;
		this._smartRotation = value;
		this.special = true;
		return this;
	}
	,snapping: function(value) {
		if(value == null) value = true;
		this._snapping = value;
		this.special = true;
		return this;
	}
	,stop: function(properties,complete,sendEvent) {
	}
	,__class__: luxe_tween_actuators_GenericActuator
};
var luxe_tween_actuators_SimpleActuator = function(target,duration,properties) {
	this.has_timescaled_starttime = false;
	this.active = true;
	this.propertyDetails = [];
	this.sendChange = false;
	this.paused = false;
	this.cacheVisible = false;
	this.initialized = false;
	this.setVisible = false;
	this.toggleVisible = false;
	this.startTime = snow_Snow.core.timestamp();
	luxe_tween_actuators_GenericActuator.call(this,target,duration,properties);
	if(!luxe_tween_actuators_SimpleActuator.addedEvent) {
		luxe_tween_actuators_SimpleActuator.addedEvent = true;
		Luxe.on(4,luxe_tween_actuators_SimpleActuator.on_internal_update);
	}
};
luxe_tween_actuators_SimpleActuator.__name__ = true;
luxe_tween_actuators_SimpleActuator.on_internal_update = function(dt) {
	luxe_tween_actuators_SimpleActuator.update_timer += dt;
	luxe_tween_actuators_SimpleActuator.current_time = snow_Snow.core.timestamp();
	var currentTime = luxe_tween_actuators_SimpleActuator.current_time;
	var actuator;
	var j = 0;
	var cleanup = false;
	var _g1 = 0;
	var _g = luxe_tween_actuators_SimpleActuator.actuatorsLength;
	while(_g1 < _g) {
		var i = _g1++;
		actuator = luxe_tween_actuators_SimpleActuator.actuators[j];
		if(actuator != null && actuator.active) {
			if(actuator.timescaled) currentTime = luxe_tween_actuators_SimpleActuator.update_timer; else currentTime = luxe_tween_actuators_SimpleActuator.current_time;
			if(actuator.timescaled && !actuator.has_timescaled_starttime) {
				actuator.has_timescaled_starttime = true;
				actuator.startTime = luxe_tween_actuators_SimpleActuator.update_timer;
				actuator.timeOffset = actuator.startTime;
			}
			if(currentTime > actuator.timeOffset) actuator.update(currentTime);
			j++;
		} else {
			luxe_tween_actuators_SimpleActuator.actuators.splice(j,1);
			--luxe_tween_actuators_SimpleActuator.actuatorsLength;
		}
	}
};
luxe_tween_actuators_SimpleActuator.__super__ = luxe_tween_actuators_GenericActuator;
luxe_tween_actuators_SimpleActuator.prototype = $extend(luxe_tween_actuators_GenericActuator.prototype,{
	autoVisible: function(value) {
		if(value == null) value = true;
		this._autoVisible = value;
		if(!value) {
			this.toggleVisible = false;
			if(this.setVisible) this.setField(this.target,"visible",this.cacheVisible);
		}
		return this;
	}
	,delay: function(duration) {
		this._delay = duration;
		this.timeOffset = this.startTime + duration;
		return this;
	}
	,getField: function(target,propertyName) {
		var value = null;
		if(Object.prototype.hasOwnProperty.call(target,propertyName)) value = Reflect.field(target,propertyName); else value = Reflect.getProperty(target,propertyName);
		return value;
	}
	,initialize: function() {
		var details;
		var start;
		var _g = 0;
		var _g1 = Reflect.fields(this.properties);
		while(_g < _g1.length) {
			var i = _g1[_g];
			++_g;
			var isField = true;
			if(Object.prototype.hasOwnProperty.call(this.target,i) && (!this.target.__properties__ || !this.target.__properties__["set_" + i])) start = Reflect.field(this.target,i); else {
				isField = false;
				start = Reflect.getProperty(this.target,i);
			}
			if(typeof(start) == "number") {
				details = new luxe_tween_actuators_PropertyDetails(this.target,i,start,this.getField(this.properties,i) - start,isField);
				this.propertyDetails.push(details);
			}
		}
		this.detailsLength = this.propertyDetails.length;
		this.initialized = true;
	}
	,move: function() {
		this.toggleVisible = Object.prototype.hasOwnProperty.call(this.properties,"alpha") && Object.prototype.hasOwnProperty.call(this.properties,"visible");
		if(this.toggleVisible && this.properties.alpha != 0 && !this.getField(this.target,"visible")) {
			this.setVisible = true;
			this.cacheVisible = this.getField(this.target,"visible");
			this.setField(this.target,"visible",true);
		}
		this.timeOffset = this.startTime;
		luxe_tween_actuators_SimpleActuator.actuators.push(this);
		++luxe_tween_actuators_SimpleActuator.actuatorsLength;
	}
	,onUpdate: function(handler,parameters) {
		this._onUpdate = handler;
		if(parameters == null) this._onUpdateParams = []; else this._onUpdateParams = parameters;
		this.sendChange = true;
		return this;
	}
	,pause: function() {
		this.paused = true;
		if(this.timescaled) this.pauseTime = luxe_tween_actuators_SimpleActuator.update_timer; else this.pauseTime = luxe_tween_actuators_SimpleActuator.current_time;
	}
	,resume: function() {
		if(this.paused) {
			this.paused = false;
			this.timeOffset += ((this.timescaled?luxe_tween_actuators_SimpleActuator.update_timer:luxe_tween_actuators_SimpleActuator.current_time) - this.pauseTime) / 1000;
		}
	}
	,setField: function(target,propertyName,value) {
		if(Object.prototype.hasOwnProperty.call(target,propertyName)) target[propertyName] = value; else Reflect.setProperty(target,propertyName,value);
	}
	,setProperty: function(details,value) {
		if(details.isField) Reflect.setProperty(details.target,details.propertyName,value); else Reflect.setProperty(details.target,details.propertyName,value);
	}
	,stop: function(properties,complete,sendEvent) {
		if(this.active) {
			if(properties == null) {
				this.active = false;
				if(complete) this.apply();
				this.complete(sendEvent);
				return;
			}
			var _g = 0;
			var _g1 = Reflect.fields(properties);
			while(_g < _g1.length) {
				var i = _g1[_g];
				++_g;
				if(Object.prototype.hasOwnProperty.call(this.properties,i)) {
					this.active = false;
					if(complete) this.apply();
					this.complete(sendEvent);
					return;
				}
			}
		}
	}
	,update: function(currentTime) {
		if(!this.paused) {
			var details;
			var easing;
			var i;
			var tweenPosition = (currentTime - this.timeOffset) / this.duration;
			if(tweenPosition > 1) tweenPosition = 1;
			if(!this.initialized) this.initialize();
			if(!this.special) {
				easing = this._ease.calculate(tweenPosition);
				var _g1 = 0;
				var _g = this.detailsLength;
				while(_g1 < _g) {
					var i1 = _g1++;
					details = this.propertyDetails[i1];
					this.setProperty(details,details.start + details.change * easing);
				}
			} else {
				if(!this._reverse) easing = this._ease.calculate(tweenPosition); else easing = this._ease.calculate(1 - tweenPosition);
				var endValue;
				var _g11 = 0;
				var _g2 = this.detailsLength;
				while(_g11 < _g2) {
					var i2 = _g11++;
					details = this.propertyDetails[i2];
					if(this._smartRotation && (details.propertyName == "rotation" || details.propertyName == "rotationX" || details.propertyName == "rotationY" || details.propertyName == "rotationZ")) {
						var rotation = details.change % 360;
						if(rotation > 180) rotation -= 360; else if(rotation < -180) rotation += 360;
						endValue = details.start + rotation * easing;
					} else endValue = details.start + details.change * easing;
					if(!this._snapping) {
						if(details.isField) Reflect.setProperty(details.target,details.propertyName,endValue); else Reflect.setProperty(details.target,details.propertyName,endValue);
					} else this.setProperty(details,Math.round(endValue));
				}
			}
			if(tweenPosition == 1) {
				if(this._repeat == 0) {
					this.active = false;
					if(this.toggleVisible && this.getField(this.target,"alpha") == 0) this.setField(this.target,"visible",false);
					this.complete(true);
					return;
				} else {
					if(this._onRepeat != null) this.callMethod(this._onRepeat,this._onRepeatParams);
					if(this._reflect) this._reverse = !this._reverse;
					this.startTime = currentTime;
					this.timeOffset = this.startTime + this._delay;
					if(this._repeat > 0) this._repeat--;
				}
			}
			if(this.sendChange) this.change();
		}
	}
	,__class__: luxe_tween_actuators_SimpleActuator
});
var luxe_tween_easing_Quad = function() { };
luxe_tween_easing_Quad.__name__ = true;
luxe_tween_easing_Quad.__properties__ = {get_easeOut:"get_easeOut",get_easeInOut:"get_easeInOut",get_easeIn:"get_easeIn"}
luxe_tween_easing_Quad.get_easeIn = function() {
	return new luxe_tween_easing_QuadEaseIn();
};
luxe_tween_easing_Quad.get_easeInOut = function() {
	return new luxe_tween_easing_QuadEaseInOut();
};
luxe_tween_easing_Quad.get_easeOut = function() {
	return new luxe_tween_easing_QuadEaseOut();
};
var luxe_tween_easing_IEasing = function() { };
luxe_tween_easing_IEasing.__name__ = true;
luxe_tween_easing_IEasing.prototype = {
	__class__: luxe_tween_easing_IEasing
};
var luxe_tween_easing_QuadEaseOut = function() {
};
luxe_tween_easing_QuadEaseOut.__name__ = true;
luxe_tween_easing_QuadEaseOut.__interfaces__ = [luxe_tween_easing_IEasing];
luxe_tween_easing_QuadEaseOut.prototype = {
	calculate: function(k) {
		return -k * (k - 2);
	}
	,ease: function(t,b,c,d) {
		return -c * (t /= d) * (t - 2) + b;
	}
	,__class__: luxe_tween_easing_QuadEaseOut
};
var luxe_tween_Actuate = function() { };
luxe_tween_Actuate.__name__ = true;
luxe_tween_Actuate.apply = function(target,properties,customActuator) {
	luxe_tween_Actuate.stop(target,properties);
	if(customActuator == null) customActuator = luxe_tween_Actuate.defaultActuator;
	var actuator = Type.createInstance(customActuator,[target,0,properties]);
	actuator.apply();
	return actuator;
};
luxe_tween_Actuate.getLibrary = function(target,allowCreation) {
	if(allowCreation == null) allowCreation = true;
	if(!luxe_tween_Actuate.targetLibraries.exists(target) && allowCreation) luxe_tween_Actuate.targetLibraries.set(target,[]);
	return luxe_tween_Actuate.targetLibraries.get(target);
};
luxe_tween_Actuate.motionPath = function(target,duration,properties,overwrite) {
	if(overwrite == null) overwrite = true;
	return luxe_tween_Actuate.tween(target,duration,properties,overwrite,luxe_tween_actuators_MotionPathActuator);
};
luxe_tween_Actuate.pause = function(target) {
	if(js_Boot.__instanceof(target,luxe_tween_actuators_GenericActuator)) (js_Boot.__cast(target , luxe_tween_actuators_GenericActuator)).pause(); else {
		var library = luxe_tween_Actuate.getLibrary(target,false);
		if(library != null) {
			var _g = 0;
			while(_g < library.length) {
				var actuator = library[_g];
				++_g;
				actuator.pause();
			}
		}
	}
};
luxe_tween_Actuate.pauseAll = function() {
	var $it0 = luxe_tween_Actuate.targetLibraries.iterator();
	while( $it0.hasNext() ) {
		var library = $it0.next();
		var _g = 0;
		while(_g < library.length) {
			var actuator = library[_g];
			++_g;
			actuator.pause();
		}
	}
};
luxe_tween_Actuate.reset = function() {
	var $it0 = luxe_tween_Actuate.targetLibraries.iterator();
	while( $it0.hasNext() ) {
		var library = $it0.next();
		var i = library.length - 1;
		while(i >= 0) {
			library[i].stop(null,false,false);
			i--;
		}
	}
	luxe_tween_Actuate.targetLibraries = new haxe_ds_ObjectMap();
};
luxe_tween_Actuate.resume = function(target) {
	if(js_Boot.__instanceof(target,luxe_tween_actuators_GenericActuator)) (js_Boot.__cast(target , luxe_tween_actuators_GenericActuator)).resume(); else {
		var library = luxe_tween_Actuate.getLibrary(target,false);
		if(library != null) {
			var _g = 0;
			while(_g < library.length) {
				var actuator = library[_g];
				++_g;
				actuator.resume();
			}
		}
	}
};
luxe_tween_Actuate.resumeAll = function() {
	var $it0 = luxe_tween_Actuate.targetLibraries.iterator();
	while( $it0.hasNext() ) {
		var library = $it0.next();
		var _g = 0;
		while(_g < library.length) {
			var actuator = library[_g];
			++_g;
			actuator.resume();
		}
	}
};
luxe_tween_Actuate.stop = function(target,properties,complete,sendEvent) {
	if(sendEvent == null) sendEvent = true;
	if(complete == null) complete = false;
	if(target != null) {
		if(js_Boot.__instanceof(target,luxe_tween_actuators_GenericActuator)) (js_Boot.__cast(target , luxe_tween_actuators_GenericActuator)).stop(null,complete,sendEvent); else {
			var library = luxe_tween_Actuate.getLibrary(target,false);
			if(library != null) {
				if(typeof(properties) == "string") {
					var temp = { };
					Reflect.setField(temp,properties,null);
					properties = temp;
				} else if((properties instanceof Array) && properties.__enum__ == null) {
					var temp1 = { };
					var _g = 0;
					var _g1;
					_g1 = js_Boot.__cast(properties , Array);
					while(_g < _g1.length) {
						var property = _g1[_g];
						++_g;
						Reflect.setField(temp1,property,null);
					}
					properties = temp1;
				}
				var i = library.length - 1;
				while(i >= 0) {
					library[i].stop(properties,complete,sendEvent);
					i--;
				}
			}
		}
	}
};
luxe_tween_Actuate.timer = function(duration,customActuator) {
	return luxe_tween_Actuate.tween(new luxe_tween__$Actuate_TweenTimer(0),duration,new luxe_tween__$Actuate_TweenTimer(1),false,customActuator);
};
luxe_tween_Actuate.tween = function(target,duration,properties,overwrite,customActuator) {
	if(overwrite == null) overwrite = true;
	if(target != null) {
		if(duration > 0) {
			if(customActuator == null) customActuator = luxe_tween_Actuate.defaultActuator;
			var actuator = Type.createInstance(customActuator,[target,duration,properties]);
			var library = luxe_tween_Actuate.getLibrary(actuator.target);
			if(overwrite) {
				var i = library.length - 1;
				while(i >= 0) {
					library[i].stop(actuator.properties,false,false);
					i--;
				}
				library = luxe_tween_Actuate.getLibrary(actuator.target);
			}
			library.push(actuator);
			actuator.move();
			return actuator;
		} else return luxe_tween_Actuate.apply(target,properties,customActuator);
	}
	return null;
};
luxe_tween_Actuate.unload = function(actuator) {
	var target = actuator.target;
	if(luxe_tween_Actuate.targetLibraries.h.__keys__[target.__id__] != null) {
		HxOverrides.remove(luxe_tween_Actuate.targetLibraries.h[target.__id__],actuator);
		if(luxe_tween_Actuate.targetLibraries.h[target.__id__].length == 0) luxe_tween_Actuate.targetLibraries.remove(target);
	}
};
luxe_tween_Actuate.update = function(target,duration,start,end,overwrite) {
	if(overwrite == null) overwrite = true;
	var properties = { start : start, end : end};
	return luxe_tween_Actuate.tween(target,duration,properties,overwrite,luxe_tween_actuators_MethodActuator);
};
var luxe_tween__$Actuate_TweenTimer = function(progress) {
	this.progress = progress;
};
luxe_tween__$Actuate_TweenTimer.__name__ = true;
luxe_tween__$Actuate_TweenTimer.prototype = {
	__class__: luxe_tween__$Actuate_TweenTimer
};
var luxe_tween_MotionPath = function() {
	this._x = new luxe_tween_ComponentPath();
	this._y = new luxe_tween_ComponentPath();
	this._rotation = null;
};
luxe_tween_MotionPath.__name__ = true;
luxe_tween_MotionPath.prototype = {
	bezier: function(x,y,controlX,controlY,strength) {
		if(strength == null) strength = 1;
		this._x.addPath(new luxe_tween_BezierPath(x,controlX,strength));
		this._y.addPath(new luxe_tween_BezierPath(y,controlY,strength));
		return this;
	}
	,line: function(x,y,strength) {
		if(strength == null) strength = 1;
		this._x.addPath(new luxe_tween_LinearPath(x,strength));
		this._y.addPath(new luxe_tween_LinearPath(y,strength));
		return this;
	}
	,get_rotation: function() {
		if(this._rotation == null) this._rotation = new luxe_tween_RotationPath(this._x,this._y);
		return this._rotation;
	}
	,get_x: function() {
		return this._x;
	}
	,get_y: function() {
		return this._y;
	}
	,__class__: luxe_tween_MotionPath
	,__properties__: {get_y:"get_y",get_x:"get_x",get_rotation:"get_rotation"}
};
var luxe_tween_IComponentPath = function() { };
luxe_tween_IComponentPath.__name__ = true;
luxe_tween_IComponentPath.prototype = {
	__class__: luxe_tween_IComponentPath
	,__properties__: {get_end:"get_end"}
};
var luxe_tween_ComponentPath = function() {
	this.paths = [];
	this.start = 0;
	this.totalStrength = 0;
};
luxe_tween_ComponentPath.__name__ = true;
luxe_tween_ComponentPath.__interfaces__ = [luxe_tween_IComponentPath];
luxe_tween_ComponentPath.prototype = {
	addPath: function(path) {
		this.paths.push(path);
		this.totalStrength += path.strength;
	}
	,calculate: function(k) {
		if(this.paths.length == 1) return this.paths[0].calculate(this.start,k); else {
			var ratio = k * this.totalStrength;
			var lastEnd = this.start;
			var _g = 0;
			var _g1 = this.paths;
			while(_g < _g1.length) {
				var path = _g1[_g];
				++_g;
				if(ratio > path.strength) {
					ratio -= path.strength;
					lastEnd = path.end;
				} else return path.calculate(lastEnd,ratio / path.strength);
			}
		}
		return 0;
	}
	,get_end: function() {
		if(this.paths.length > 0) {
			var path = this.paths[this.paths.length - 1];
			return path.end;
		} else return this.start;
	}
	,__class__: luxe_tween_ComponentPath
	,__properties__: {get_end:"get_end"}
};
var luxe_tween_BezierPath = function(end,control,strength) {
	this.end = end;
	this.control = control;
	this.strength = strength;
};
luxe_tween_BezierPath.__name__ = true;
luxe_tween_BezierPath.prototype = {
	calculate: function(start,k) {
		return (1 - k) * (1 - k) * start + 2 * (1 - k) * k * this.control + k * k * this.end;
	}
	,__class__: luxe_tween_BezierPath
};
var luxe_tween_LinearPath = function(end,strength) {
	luxe_tween_BezierPath.call(this,end,0,strength);
};
luxe_tween_LinearPath.__name__ = true;
luxe_tween_LinearPath.__super__ = luxe_tween_BezierPath;
luxe_tween_LinearPath.prototype = $extend(luxe_tween_BezierPath.prototype,{
	calculate: function(start,k) {
		return start + k * (this.end - start);
	}
	,__class__: luxe_tween_LinearPath
});
var luxe_tween_RotationPath = function(x,y) {
	this.step = 0.01;
	this._x = x;
	this._y = y;
	this.offset = 0;
	this.start = this.calculate(0.0);
};
luxe_tween_RotationPath.__name__ = true;
luxe_tween_RotationPath.__interfaces__ = [luxe_tween_IComponentPath];
luxe_tween_RotationPath.prototype = {
	calculate: function(k) {
		var dX = this._x.calculate(k) - this._x.calculate(k + this.step);
		var dY = this._y.calculate(k) - this._y.calculate(k + this.step);
		var angle = Math.atan2(dY,dX) * (180 / Math.PI);
		angle = (angle + this.offset) % 360;
		return angle;
	}
	,get_end: function() {
		return this.calculate(1.0);
	}
	,__class__: luxe_tween_RotationPath
	,__properties__: {get_end:"get_end"}
};
var luxe_tween_actuators_MethodActuator = function(target,duration,properties) {
	this.currentParameters = [];
	this.tweenProperties = { };
	luxe_tween_actuators_SimpleActuator.call(this,target,duration,properties);
	if(!Object.prototype.hasOwnProperty.call(properties,"start")) this.properties.start = [];
	if(!Object.prototype.hasOwnProperty.call(properties,"end")) this.properties.end = this.properties.start;
	var _g1 = 0;
	var _g = this.properties.start.length;
	while(_g1 < _g) {
		var i = _g1++;
		this.currentParameters.push(null);
	}
};
luxe_tween_actuators_MethodActuator.__name__ = true;
luxe_tween_actuators_MethodActuator.__super__ = luxe_tween_actuators_SimpleActuator;
luxe_tween_actuators_MethodActuator.prototype = $extend(luxe_tween_actuators_SimpleActuator.prototype,{
	apply: function() {
		this.callMethod(this.target,this.properties.end);
	}
	,complete: function(sendEvent) {
		if(sendEvent == null) sendEvent = true;
		var _g1 = 0;
		var _g = this.properties.start.length;
		while(_g1 < _g) {
			var i = _g1++;
			this.currentParameters[i] = Reflect.field(this.tweenProperties,"param" + i);
		}
		this.callMethod(this.target,this.currentParameters);
		luxe_tween_actuators_SimpleActuator.prototype.complete.call(this,sendEvent);
	}
	,initialize: function() {
		var details;
		var propertyName;
		var start;
		var _g1 = 0;
		var _g = this.properties.start.length;
		while(_g1 < _g) {
			var i = _g1++;
			propertyName = "param" + i;
			start = this.properties.start[i];
			this.tweenProperties[propertyName] = start;
			if(typeof(start) == "number" || ((start | 0) === start)) {
				details = new luxe_tween_actuators_PropertyDetails(this.tweenProperties,propertyName,start,this.properties.end[i] - start);
				this.propertyDetails.push(details);
			}
		}
		this.detailsLength = this.propertyDetails.length;
		this.initialized = true;
	}
	,update: function(currentTime) {
		luxe_tween_actuators_SimpleActuator.prototype.update.call(this,currentTime);
		if(this.active) {
			var _g1 = 0;
			var _g = this.properties.start.length;
			while(_g1 < _g) {
				var i = _g1++;
				this.currentParameters[i] = Reflect.field(this.tweenProperties,"param" + i);
			}
			this.callMethod(this.target,this.currentParameters);
		}
	}
	,__class__: luxe_tween_actuators_MethodActuator
});
var luxe_tween_actuators_MotionPathActuator = function(target,duration,properties) {
	luxe_tween_actuators_SimpleActuator.call(this,target,duration,properties);
};
luxe_tween_actuators_MotionPathActuator.__name__ = true;
luxe_tween_actuators_MotionPathActuator.__super__ = luxe_tween_actuators_SimpleActuator;
luxe_tween_actuators_MotionPathActuator.prototype = $extend(luxe_tween_actuators_SimpleActuator.prototype,{
	apply: function() {
		var _g = 0;
		var _g1 = Reflect.fields(this.properties);
		while(_g < _g1.length) {
			var propertyName = _g1[_g];
			++_g;
			if(Object.prototype.hasOwnProperty.call(this.target,propertyName)) Reflect.setField(this.target,propertyName,(js_Boot.__cast(Reflect.field(this.properties,propertyName) , luxe_tween_IComponentPath)).get_end()); else Reflect.setProperty(this.target,propertyName,(js_Boot.__cast(Reflect.field(this.properties,propertyName) , luxe_tween_IComponentPath)).get_end());
		}
	}
	,initialize: function() {
		var details;
		var path;
		var _g = 0;
		var _g1 = Reflect.fields(this.properties);
		while(_g < _g1.length) {
			var propertyName = _g1[_g];
			++_g;
			path = js_Boot.__cast(Reflect.field(this.properties,propertyName) , luxe_tween_IComponentPath);
			if(path != null) {
				var isField = true;
				if(Object.prototype.hasOwnProperty.call(this.target,propertyName)) path.start = Reflect.field(this.target,propertyName); else {
					isField = false;
					path.start = Reflect.getProperty(this.target,propertyName);
				}
				details = new luxe_tween_actuators_PropertyPathDetails(this.target,propertyName,path,isField);
				this.propertyDetails.push(details);
			}
		}
		this.detailsLength = this.propertyDetails.length;
		this.initialized = true;
	}
	,update: function(currentTime) {
		if(!this.paused) {
			var details;
			var easing;
			var tweenPosition = (currentTime - this.timeOffset) / this.duration;
			if(tweenPosition > 1) tweenPosition = 1;
			if(!this.initialized) this.initialize();
			if(!this.special) {
				easing = this._ease.calculate(tweenPosition);
				var _g = 0;
				var _g1 = this.propertyDetails;
				while(_g < _g1.length) {
					var details1 = _g1[_g];
					++_g;
					if(details1.isField) Reflect.setField(details1.target,details1.propertyName,(js_Boot.__cast(details1 , luxe_tween_actuators_PropertyPathDetails)).path.calculate(easing)); else Reflect.setProperty(details1.target,details1.propertyName,(js_Boot.__cast(details1 , luxe_tween_actuators_PropertyPathDetails)).path.calculate(easing));
				}
			} else {
				if(!this._reverse) easing = this._ease.calculate(tweenPosition); else easing = this._ease.calculate(1 - tweenPosition);
				var endValue;
				var _g2 = 0;
				var _g11 = this.propertyDetails;
				while(_g2 < _g11.length) {
					var details2 = _g11[_g2];
					++_g2;
					if(!this._snapping) {
						if(details2.isField) Reflect.setField(details2.target,details2.propertyName,(js_Boot.__cast(details2 , luxe_tween_actuators_PropertyPathDetails)).path.calculate(easing)); else Reflect.setProperty(details2.target,details2.propertyName,(js_Boot.__cast(details2 , luxe_tween_actuators_PropertyPathDetails)).path.calculate(easing));
					} else if(details2.isField) Reflect.setField(details2.target,details2.propertyName,Math.round((js_Boot.__cast(details2 , luxe_tween_actuators_PropertyPathDetails)).path.calculate(easing))); else Reflect.setProperty(details2.target,details2.propertyName,Math.round((js_Boot.__cast(details2 , luxe_tween_actuators_PropertyPathDetails)).path.calculate(easing)));
				}
			}
			if(tweenPosition == 1) {
				if(this._repeat == 0) {
					this.active = false;
					if(this.toggleVisible && this.getField(this.target,"alpha") == 0) this.setField(this.target,"visible",false);
					this.complete(true);
					return;
				} else {
					if(this._reflect) this._reverse = !this._reverse;
					this.startTime = currentTime;
					this.timeOffset = this.startTime + this._delay;
					if(this._repeat > 0) this._repeat--;
				}
			}
			if(this.sendChange) this.change();
		}
	}
	,__class__: luxe_tween_actuators_MotionPathActuator
});
var luxe_tween_actuators_PropertyDetails = function(target,propertyName,start,change,isField) {
	if(isField == null) isField = true;
	this.target = target;
	this.propertyName = propertyName;
	this.start = start;
	this.change = change;
	this.isField = isField;
};
luxe_tween_actuators_PropertyDetails.__name__ = true;
luxe_tween_actuators_PropertyDetails.prototype = {
	__class__: luxe_tween_actuators_PropertyDetails
};
var luxe_tween_actuators_PropertyPathDetails = function(target,propertyName,path,isField) {
	if(isField == null) isField = true;
	luxe_tween_actuators_PropertyDetails.call(this,target,propertyName,0,0,isField);
	this.path = path;
};
luxe_tween_actuators_PropertyPathDetails.__name__ = true;
luxe_tween_actuators_PropertyPathDetails.__super__ = luxe_tween_actuators_PropertyDetails;
luxe_tween_actuators_PropertyPathDetails.prototype = $extend(luxe_tween_actuators_PropertyDetails.prototype,{
	__class__: luxe_tween_actuators_PropertyPathDetails
});
var luxe_tween_easing_QuadEaseIn = function() {
};
luxe_tween_easing_QuadEaseIn.__name__ = true;
luxe_tween_easing_QuadEaseIn.__interfaces__ = [luxe_tween_easing_IEasing];
luxe_tween_easing_QuadEaseIn.prototype = {
	calculate: function(k) {
		return k * k;
	}
	,ease: function(t,b,c,d) {
		return c * (t /= d) * t + b;
	}
	,__class__: luxe_tween_easing_QuadEaseIn
};
var luxe_tween_easing_QuadEaseInOut = function() {
};
luxe_tween_easing_QuadEaseInOut.__name__ = true;
luxe_tween_easing_QuadEaseInOut.__interfaces__ = [luxe_tween_easing_IEasing];
luxe_tween_easing_QuadEaseInOut.prototype = {
	calculate: function(k) {
		if((k *= 2) < 1) return 0.5 * k * k;
		return -0.5 * ((k - 1) * (k - 3) - 1);
	}
	,ease: function(t,b,c,d) {
		if((t /= d / 2) < 1) return c / 2 * t * t + b;
		return -c / 2 * ((t - 1) * (t - 3) - 1) + b;
	}
	,__class__: luxe_tween_easing_QuadEaseInOut
};
var luxe_utils_GeometryUtils = function() {
};
luxe_utils_GeometryUtils.__name__ = true;
luxe_utils_GeometryUtils.prototype = {
	segments_for_smooth_circle: function(_radius,_smooth) {
		if(_smooth == null) _smooth = 6;
		return Std["int"](_smooth * Math.sqrt(_radius));
	}
	,random_point_in_unit_circle: function() {
		var _r = Math.sqrt(Math.random());
		var _t = (-1 + 2 * Math.random()) * 6.283185307179586;
		return new phoenix_Vector(_r * Math.cos(_t),_r * Math.sin(_t));
	}
	,point_in_polygon: function(_point,_offset,_verts) {
		if(_offset == null) _offset = new phoenix_Vector();
		var c = false;
		var nvert = _verts.length;
		var j = nvert - 1;
		var _g = 0;
		while(_g < nvert) {
			var i = _g++;
			if(_verts[i].y + _offset.y > _point.y != _verts[j].y + _offset.y > _point.y && _point.x < (_verts[j].x + _offset.x - (_verts[i].x + _offset.x)) * (_point.y - (_verts[i].y + _offset.y)) / (_verts[j].y + _offset.y - (_verts[i].y + _offset.y)) + (_verts[i].x + _offset.x)) c = !c;
			j = i;
		}
		return c;
	}
	,point_in_geometry: function(_point,_geometry) {
		var c = false;
		var nvert = _geometry.vertices.length;
		var j = nvert - 1;
		var _g = 0;
		while(_g < nvert) {
			var i = _g++;
			var _vert_i_pos = _geometry.vertices[i].pos.clone().transform(_geometry.transform.get_world().get_matrix());
			var _vert_j_pos = _geometry.vertices[j].pos.clone().transform(_geometry.transform.get_world().get_matrix());
			if(_vert_i_pos.y > _point.y != _vert_j_pos.y > _point.y && _point.x < (_vert_j_pos.x - _vert_i_pos.x) * (_point.y - _vert_i_pos.y) / (_vert_j_pos.y - _vert_i_pos.y) + _vert_i_pos.x) c = !c;
			j = i;
		}
		return c;
	}
	,intersect_ray_plane: function(_ray_start,_ray_dir,_plane_normal,_plane_point) {
		var part1 = _plane_normal.dot(new phoenix_Vector(_plane_point.x - _ray_start.x,_plane_point.y - _ray_start.y,_plane_point.z - _ray_start.z));
		var part2 = _plane_normal.x * _ray_dir.x + _plane_normal.y * _ray_dir.y + _plane_normal.z * _ray_dir.z;
		var T = part1 / part2;
		return phoenix_Vector.Add(_ray_start,phoenix_Vector.Multiply(_ray_dir,T));
	}
	,__class__: luxe_utils_GeometryUtils
};
var luxe_utils_Maths = function() {
};
luxe_utils_Maths.__name__ = true;
luxe_utils_Maths.fixed = function(value,precision) {
	var n = Math.pow(10,precision);
	return (value * n | 0) / n;
};
luxe_utils_Maths.lerp = function(value,target,t) {
	if(t < 0) t = 0; else if(t > 1) t = 1; else t = t;
	return value + t * (target - value);
};
luxe_utils_Maths.weighted_avg = function(value,target,slowness) {
	if(slowness == 0) slowness = 0.00000001;
	return (value * (slowness - 1) + target) / slowness;
};
luxe_utils_Maths.clamp = function(value,a,b) {
	if(value < a) return a; else if(value > b) return b; else return value;
};
luxe_utils_Maths.clamp_bottom = function(value,a) {
	if(value < a) return a; else return value;
};
luxe_utils_Maths.within_range = function(value,start_range,end_range) {
	return value >= start_range && value <= end_range;
};
luxe_utils_Maths.wrap_angle = function(degrees,lower,upper) {
	var _radians = degrees * 0.017453292519943278;
	var _distance = upper - lower;
	var _times = Math.floor((degrees - lower) / _distance);
	return degrees - _times * _distance;
};
luxe_utils_Maths.nearest_power_of_two = function(_value) {
	_value--;
	_value |= _value >> 1;
	_value |= _value >> 2;
	_value |= _value >> 4;
	_value |= _value >> 8;
	_value |= _value >> 16;
	_value++;
	return _value;
};
luxe_utils_Maths.map_linear = function(value,a1,a2,b1,b2) {
	return b1 + (value - a1) * (b2 - b1) / (a2 - a1);
};
luxe_utils_Maths.smoothstep = function(x,min,max) {
	if(x <= min) return 0;
	if(x >= max) return 1;
	x = (x - min) / (max - min);
	return x * x * (3 - 2 * x);
};
luxe_utils_Maths.smootherstep = function(x,min,max) {
	if(x <= min) return 0;
	if(x >= max) return 1;
	x = (x - min) / (max - min);
	return x * x * x * (x * (x * 6 - 15) + 10);
};
luxe_utils_Maths.random16 = function() {
	return (65280 * Math.random() + 255 * Math.random()) / 65535;
};
luxe_utils_Maths.random_int = function(low,high) {
	return low + Math.floor(Math.random() * (high - low + 1));
};
luxe_utils_Maths.random_float = function(low,high) {
	return low + Math.random() * (high - low);
};
luxe_utils_Maths.random_float_spread = function(range) {
	return range * (0.5 - Math.random());
};
luxe_utils_Maths.sign = function(x) {
	if(x < 0) return -1; else if(x > 0) return 1; else return 0;
};
luxe_utils_Maths.radians = function(degrees) {
	return degrees * 0.017453292519943278;
};
luxe_utils_Maths.degrees = function(radians) {
	return radians * 57.29577951308238;
};
luxe_utils_Maths.prototype = {
	__class__: luxe_utils_Maths
};
var luxe_utils_Random = function(_initial_seed) {
	this.initial = this.seed = _initial_seed;
	this.seed = this.initial;
};
luxe_utils_Random.__name__ = true;
luxe_utils_Random.prototype = {
	get: function() {
		return (function($this) {
			var $r;
			var a = $this.seed = Std["int"](_$UInt_UInt_$Impl_$.toFloat($this.seed * 16807) % _$UInt_UInt_$Impl_$.toFloat(2147483647));
			$r = _$UInt_UInt_$Impl_$.toFloat(a) / _$UInt_UInt_$Impl_$.toFloat(2147483647);
			return $r;
		}(this)) + 0.000000000233;
	}
	,'float': function(min,max) {
		if(max == null) {
			max = min;
			min = 0;
		}
		return this.get() * (max - min) + min;
	}
	,'int': function(min,max) {
		if(max == null) {
			max = min;
			min = 0;
		}
		return Math.floor(this["float"](min,max));
	}
	,bool: function(chance) {
		if(chance == null) chance = 0.5;
		return this.get() < chance;
	}
	,sign: function(chance) {
		if(chance == null) chance = 0.5;
		if(this.get() < chance) return 1; else return -1;
	}
	,bit: function(chance) {
		if(chance == null) chance = 0.5;
		if(this.get() < chance) return 1; else return 0;
	}
	,reset: function() {
		var s = this.seed;
		this.initial = this.seed = s;
		this.initial;
	}
	,set_initial: function(_initial) {
		this.initial = this.seed = _initial;
		return this.initial;
	}
	,__class__: luxe_utils_Random
	,__properties__: {set_initial:"set_initial"}
};
var luxe_utils_Utils = function(_luxe) {
	this.core = _luxe;
	this.geometry = new luxe_utils_GeometryUtils();
	this.random = new luxe_utils_Random(Std["int"](Math.random() * 1073741823));
	this._byte_levels = ["bytes","Kb","MB","GB","TB"];
};
luxe_utils_Utils.__name__ = true;
luxe_utils_Utils.prototype = {
	pos_info: function(pos) {
		return "" + pos.fileName + ":" + pos.lineNumber + ":(" + pos.className + ":" + pos.methodName + ")";
	}
	,uniqueid: function(val) {
		if(val == null) val = Std.random(2147483647);
		var to_char = function(value) {
			if(value > 9) {
				var ascii = 65 + (value - 10);
				if(ascii > 90) ascii += 6;
				return String.fromCharCode(ascii);
			} else return (value == null?"null":"" + value).charAt(0);
		};
		var r = val % 62 | 0;
		var q = val / 62 | 0;
		if(q > 0) return this.uniqueid(q) + to_char(r); else return Std.string(to_char(r));
	}
	,uniquehash: function() {
		return this.hash(this.uniqueid());
	}
	,hash: function(string) {
		return this.hashdjb2(string);
	}
	,hashdjb2: function(string) {
		var _hash = 5381;
		var _g1 = 0;
		var _g = string.length;
		while(_g1 < _g) {
			var i = _g1++;
			_hash = (_hash << 5) + _hash + HxOverrides.cca(string,i);
		}
		return _hash;
	}
	,uniqueid2: function() {
		return haxe_crypto_Md5.encode(Std.string(snow_Snow.core.timestamp() * Math.random()));
	}
	,stacktrace: function(_depth) {
		if(_depth == null) _depth = 100;
		var result = "\n";
		var stack = haxe_CallStack.callStack();
		stack.shift();
		stack.reverse();
		var total = Std["int"](Math.min(stack.length,_depth));
		var _g = 0;
		while(_g < total) {
			var i = _g++;
			var stackitem = stack[i];
			{
				var _g1 = stack[i];
				switch(_g1[1]) {
				case 2:
					var line = _g1[4];
					var file = _g1[3];
					var s = _g1[2];
					if(s != null) switch(s[1]) {
					case 3:
						var method = s[3];
						var classname = s[2];
						result += "   at " + file + ":" + line + ": " + classname + "." + method;
						break;
					default:
					} else {
					}
					break;
				default:
				}
			}
			if(i != total - 1) result += "\n";
		}
		return result;
	}
	,path_is_relative: function(_path) {
		return _path.charAt(0) != "#" && _path.charAt(0) != "/" && _path.indexOf(":\\") == -1 && _path.indexOf(":/") == -1 && (_path.indexOf("//") == -1 || _path.indexOf("//") > _path.indexOf("#") || _path.indexOf("//") > _path.indexOf("?"));
	}
	,find_assets_image_sequence: function(_name,_ext,_start) {
		if(_start == null) _start = "1";
		if(_ext == null) _ext = ".png";
		var _final = [];
		var _sequence_type = "";
		var _pattern_regex = null;
		var _type0 = _name + _start + _ext;
		var _type0_re = new EReg("(" + _name + ")(\\d\\b)","gi");
		var _type1 = _name + "_" + _start + _ext;
		var _type1_re = new EReg("(" + _name + ")(_\\d\\b)","gi");
		var _type2 = _name + "-" + _start + _ext;
		var _type2_re = new EReg("(" + _name + ")(-\\d\\b)","gi");
		if(this.core.app.assets.listed(_type0)) {
			_sequence_type = _type0;
			_pattern_regex = _type0_re;
		} else if(this.core.app.assets.listed(_type1)) {
			_sequence_type = _type1;
			_pattern_regex = _type1_re;
		} else if(this.core.app.assets.listed(_type2)) {
			_sequence_type = _type2;
			_pattern_regex = _type2_re;
		} else haxe_Log.trace("Sequence requested from " + _name + " but no assets found like `" + _type0 + "` or `" + _type1 + "` or `" + _type2 + "`",{ fileName : "Utils.hx", lineNumber : 168, className : "luxe.utils.Utils", methodName : "find_assets_image_sequence"});
		if(_sequence_type != "") {
			var $it0 = this.core.app.assets.list.iterator();
			while( $it0.hasNext() ) {
				var _asset = $it0.next();
				if(_pattern_regex.match(_asset.id)) _final.push(_asset.id);
			}
			_final.sort(function(a,b) {
				if(a == b) return 0;
				if(a < b) return -1;
				return 1;
			});
		}
		return _final;
	}
	,text_wrap_column_knuth_plass: function(_string,_column) {
		if(_column == null) _column = 80;
		var result = [];
		var words = [];
		var lengths = [];
		var badness;
		var _g = new haxe_ds_IntMap();
		_g.h[0] = 0;
		badness = _g;
		var extra = new haxe_ds_IntMap();
		var s = _string;
		var rgx = new EReg("(\\b[^\\s]+\\b)","gm");
		while(rgx.match(s)) {
			words.push(rgx.matched(1));
			s = rgx.matchedRight();
		}
		if(words.length == 0) words.push(_string);
		words;
		words.map(function(w) {
			lengths.push(w.length);
		});
		var n = words.length;
		var _g2 = 1;
		var _g1 = n + 1;
		while(_g2 < _g1) {
			var i = _g2++;
			var sums = new haxe_ds_IntMap();
			var k = i;
			while((function($this) {
				var $r;
				var total = 0;
				{
					var _g3 = k - 1;
					while(_g3 < i) {
						var i1 = _g3++;
						total += lengths[i1];
					}
				}
				$r = total + (i - k + 1);
				return $r;
			}(this)) <= _column && k > 0) {
				var a;
				a = _column - (function($this) {
					var $r;
					var total1 = 0;
					{
						var _g4 = k - 1;
						while(_g4 < i) {
							var i2 = _g4++;
							total1 += lengths[i2];
						}
					}
					$r = total1 + (i - k + 1);
					return $r;
				}(this));
				var k1 = Std["int"](Math.pow(a,3) + badness.h[k - 1]);
				sums.h[k1] = k;
				k;
				k -= 1;
			}
			var mn;
			var min = 1073741823;
			var $it0 = sums.keys();
			while( $it0.hasNext() ) {
				var item = $it0.next();
				if(item < min) min = item;
			}
			mn = min;
			{
				badness.h[i] = mn;
				mn;
			}
			var v = sums.h[mn];
			extra.h[i] = v;
			v;
		}
		var line = 1;
		while(n > 1) {
			result.unshift(words.slice(extra.h[n] - 1,n).join(" "));
			n = extra.h[n] - 1;
			line += 1;
		}
		if(result.length == 0) result.push(_string);
		return result;
	}
	,text_wrap_column: function(_text,_brk,_column) {
		if(_column == null) _column = 80;
		if(_brk == null) _brk = "\n";
		var result = new EReg("(.{1," + _column + "})(?: +|$)\n?|(.{" + _column + "})","gimu").replace(_text,"$1$2" + _brk);
		return StringTools.rtrim(result);
	}
	,bytes_to_string: function(bytes,precision) {
		if(precision == null) precision = 3;
		var index = Math.floor(Math.log(bytes) / Math.log(1024));
		var _byte_value = bytes / Math.pow(1024,index);
		_byte_value = luxe_utils_Maths.fixed(_byte_value,precision);
		return _byte_value + " " + this._byte_levels[index];
	}
	,array_to_bytes: function(array) {
		if(array == null) return null;
		var bytes = haxe_io_Bytes.alloc(array.length);
		var _g1 = 0;
		var _g = bytes.length;
		while(_g1 < _g) {
			var n = _g1++;
			bytes.b[n] = array[n] & 255;
		}
		return bytes;
	}
	,__class__: luxe_utils_Utils
};
var luxe_utils_unifill__$CodePoint_CodePoint_$Impl_$ = {};
luxe_utils_unifill__$CodePoint_CodePoint_$Impl_$.__name__ = true;
luxe_utils_unifill__$CodePoint_CodePoint_$Impl_$.cons = function(a,b) {
	return luxe_utils_unifill_Utf16.fromCodePoint(a).toString() + b;
};
luxe_utils_unifill__$CodePoint_CodePoint_$Impl_$.snoc = function(a,b) {
	return a + luxe_utils_unifill_Utf16.fromCodePoint(b).toString();
};
luxe_utils_unifill__$CodePoint_CodePoint_$Impl_$.addInt = function(a,b) {
	return a + b;
};
luxe_utils_unifill__$CodePoint_CodePoint_$Impl_$.sub = function(a,b) {
	return a - b;
};
luxe_utils_unifill__$CodePoint_CodePoint_$Impl_$.subInt = function(a,b) {
	return a - b;
};
luxe_utils_unifill__$CodePoint_CodePoint_$Impl_$._new = function(code) {
	var this1;
	if(!(0 <= code && code <= 1114111 && !(55296 <= code && code <= 56319) && !(56320 <= code && code <= 57343))) throw new js__$Boot_HaxeError(luxe_utils_unifill_Exception.InvalidCodePoint(code));
	this1 = code;
	return this1;
};
luxe_utils_unifill__$CodePoint_CodePoint_$Impl_$.toString = function(this1) {
	return luxe_utils_unifill_Utf16.fromCodePoint(this1).toString();
};
luxe_utils_unifill__$CodePoint_CodePoint_$Impl_$.toInt = function(this1) {
	return this1;
};
var luxe_utils_unifill_CodePointIter = function(s) {
	this.s = s;
	this.itr = new luxe_utils_unifill_InternalEncodingIter(s,0,s.length);
};
luxe_utils_unifill_CodePointIter.__name__ = true;
luxe_utils_unifill_CodePointIter.prototype = {
	hasNext: function() {
		return this.itr.hasNext();
	}
	,next: function() {
		return luxe_utils_unifill_InternalEncoding.codePointAt(this.s,this.itr.next());
	}
	,__class__: luxe_utils_unifill_CodePointIter
};
var luxe_utils_unifill_Exception = { __ename__ : true, __constructs__ : ["InvalidCodePoint","InvalidCodeUnitSequence"] };
luxe_utils_unifill_Exception.InvalidCodePoint = function(code) { var $x = ["InvalidCodePoint",0,code]; $x.__enum__ = luxe_utils_unifill_Exception; $x.toString = $estr; return $x; };
luxe_utils_unifill_Exception.InvalidCodeUnitSequence = function(index) { var $x = ["InvalidCodeUnitSequence",1,index]; $x.__enum__ = luxe_utils_unifill_Exception; $x.toString = $estr; return $x; };
var luxe_utils_unifill_InternalEncoding = function() { };
luxe_utils_unifill_InternalEncoding.__name__ = true;
luxe_utils_unifill_InternalEncoding.__properties__ = {get_internalEncoding:"get_internalEncoding"}
luxe_utils_unifill_InternalEncoding.get_internalEncoding = function() {
	return "UTF-16";
};
luxe_utils_unifill_InternalEncoding.codeUnitAt = function(s,index) {
	var u_str = s;
	return u_str.charCodeAt(index);
};
luxe_utils_unifill_InternalEncoding.codePointAt = function(s,index) {
	var u = new luxe_utils_unifill_Utf16(s);
	return u.codePointAt(index);
};
luxe_utils_unifill_InternalEncoding.charAt = function(s,index) {
	var u = new luxe_utils_unifill_Utf16(s);
	return u.charAt(index).toString();
};
luxe_utils_unifill_InternalEncoding.codePointCount = function(s,beginIndex,endIndex) {
	var u = new luxe_utils_unifill_Utf16(s);
	return u.codePointCount(beginIndex,endIndex);
};
luxe_utils_unifill_InternalEncoding.codePointWidthAt = function(s,index) {
	var u = new luxe_utils_unifill_Utf16(s);
	return u.codePointWidthAt(index);
};
luxe_utils_unifill_InternalEncoding.codePointWidthBefore = function(s,index) {
	var u = new luxe_utils_unifill_Utf16(s);
	return luxe_utils_unifill__$Utf16_Utf16Impl.find_prev_code_point($bind(u,u.codeUnitAt),index);
};
luxe_utils_unifill_InternalEncoding.offsetByCodePoints = function(s,index,codePointOffset) {
	var u = new luxe_utils_unifill_Utf16(s);
	if(codePointOffset >= 0) return u.forward_offset_by_code_points(index,codePointOffset); else return u.backward_offset_by_code_points(index,-codePointOffset);
};
luxe_utils_unifill_InternalEncoding.backwardOffsetByCodePoints = function(s,index,codePointOffset) {
	var u = new luxe_utils_unifill_Utf16(s);
	return u.offsetByCodePoints(index,-codePointOffset);
};
luxe_utils_unifill_InternalEncoding.fromCodePoint = function(codePoint) {
	return luxe_utils_unifill_Utf16.fromCodePoint(codePoint).toString();
};
luxe_utils_unifill_InternalEncoding.fromCodePoints = function(codePoints) {
	return luxe_utils_unifill_Utf16.fromCodePoints(codePoints).toString();
};
luxe_utils_unifill_InternalEncoding.validate = function(s) {
	var u = new luxe_utils_unifill_Utf16(s);
	u.validate();
};
luxe_utils_unifill_InternalEncoding.isValidString = function(s) {
	try {
		luxe_utils_unifill_InternalEncoding.validate(s);
		return true;
	} catch( e ) {
		if (e instanceof js__$Boot_HaxeError) e = e.val;
		if( js_Boot.__instanceof(e,luxe_utils_unifill_Exception) ) {
			switch(e[1]) {
			case 1:
				var index = e[2];
				return false;
			default:
				throw new js__$Boot_HaxeError(e);
			}
		} else throw(e);
	}
};
var luxe_utils_unifill_InternalEncodingIter = function(s,beginIndex,endIndex) {
	this.string = s;
	this.index = beginIndex;
	this.endIndex = endIndex;
};
luxe_utils_unifill_InternalEncodingIter.__name__ = true;
luxe_utils_unifill_InternalEncodingIter.prototype = {
	hasNext: function() {
		return this.index < this.endIndex;
	}
	,next: function() {
		var i = this.index;
		this.index += luxe_utils_unifill_InternalEncoding.codePointWidthAt(this.string,this.index);
		return i;
	}
	,__class__: luxe_utils_unifill_InternalEncodingIter
};
var luxe_utils_unifill_Unicode = function() { };
luxe_utils_unifill_Unicode.__name__ = true;
luxe_utils_unifill_Unicode.decodeSurrogate = function(hi,lo) {
	return hi - 55232 << 10 | lo & 1023;
};
luxe_utils_unifill_Unicode.encodeHighSurrogate = function(c) {
	return (c >> 10) + 55232;
};
luxe_utils_unifill_Unicode.encodeLowSurrogate = function(c) {
	return c & 1023 | 56320;
};
luxe_utils_unifill_Unicode.isScalar = function(code) {
	return 0 <= code && code <= 1114111 && !(55296 <= code && code <= 56319) && !(56320 <= code && code <= 57343);
};
luxe_utils_unifill_Unicode.isHighSurrogate = function(code) {
	return 55296 <= code && code <= 56319;
};
luxe_utils_unifill_Unicode.isLowSurrogate = function(code) {
	return 56320 <= code && code <= 57343;
};
var luxe_utils_unifill_Unifill = function() { };
luxe_utils_unifill_Unifill.__name__ = true;
luxe_utils_unifill_Unifill.uLength = function(s) {
	return luxe_utils_unifill_InternalEncoding.codePointCount(s,0,s.length);
};
luxe_utils_unifill_Unifill.uCharAt = function(s,index) {
	var i = luxe_utils_unifill_InternalEncoding.offsetByCodePoints(s,0,index);
	return luxe_utils_unifill_InternalEncoding.charAt(s,i);
};
luxe_utils_unifill_Unifill.uCharCodeAt = function(s,index) {
	var i = luxe_utils_unifill_InternalEncoding.offsetByCodePoints(s,0,index);
	return luxe_utils_unifill_InternalEncoding.codePointAt(s,i);
};
luxe_utils_unifill_Unifill.uCodePointAt = function(s,index) {
	return luxe_utils_unifill_Unifill.uCharCodeAt(s,index);
};
luxe_utils_unifill_Unifill.uIndexOf = function(s,value,startIndex) {
	if(startIndex == null) startIndex = 0;
	var index = s.indexOf(value,luxe_utils_unifill_InternalEncoding.offsetByCodePoints(s,0,startIndex));
	if(index >= 0) return luxe_utils_unifill_InternalEncoding.codePointCount(s,0,index); else return -1;
};
luxe_utils_unifill_Unifill.uLastIndexOf = function(s,value,startIndex) {
	if(startIndex == null) startIndex = s.length - 1;
	var index = s.lastIndexOf(value,luxe_utils_unifill_InternalEncoding.offsetByCodePoints(s,0,startIndex));
	if(index >= 0) return luxe_utils_unifill_InternalEncoding.codePointCount(s,0,index); else return -1;
};
luxe_utils_unifill_Unifill.uSplit = function(s,delimiter) {
	if(delimiter.length == 0) {
		var _g = [];
		var _g1 = new luxe_utils_unifill_InternalEncodingIter(s,0,s.length);
		while(_g1.index < _g1.endIndex) {
			var i = _g1.next();
			_g.push(luxe_utils_unifill_InternalEncoding.charAt(s,i));
		}
		return _g;
	} else return s.split(delimiter);
};
luxe_utils_unifill_Unifill.uSubstr = function(s,startIndex,length) {
	var si = luxe_utils_unifill_InternalEncoding.offsetByCodePoints(s,startIndex >= 0?0:s.length,startIndex);
	var ei;
	if(length == null) ei = s.length; else if(length < 0) ei = si; else ei = luxe_utils_unifill_InternalEncoding.offsetByCodePoints(s,si,length);
	return s.substring(si,ei);
};
luxe_utils_unifill_Unifill.uSubstring = function(s,startIndex,endIndex) {
	var si;
	if(startIndex < 0) si = 0; else si = luxe_utils_unifill_InternalEncoding.offsetByCodePoints(s,0,startIndex);
	var ei;
	if(endIndex == null) ei = s.length; else if(endIndex < 0) ei = 0; else ei = luxe_utils_unifill_InternalEncoding.offsetByCodePoints(s,0,endIndex);
	return s.substring(si,ei);
};
luxe_utils_unifill_Unifill.uIterator = function(s) {
	return new luxe_utils_unifill_CodePointIter(s);
};
luxe_utils_unifill_Unifill.uCompare = function(a,b) {
	var aiter = new luxe_utils_unifill_InternalEncodingIter(a,0,a.length);
	var biter = new luxe_utils_unifill_InternalEncodingIter(b,0,b.length);
	while(aiter.index < aiter.endIndex && biter.index < biter.endIndex) {
		var acode = luxe_utils_unifill_InternalEncoding.codePointAt(a,aiter.next());
		var bcode = luxe_utils_unifill_InternalEncoding.codePointAt(b,biter.next());
		if(acode < bcode) return -1;
		if(acode > bcode) return 1;
	}
	if(biter.index < biter.endIndex) return -1;
	if(aiter.index < aiter.endIndex) return 1;
	return 0;
};
luxe_utils_unifill_Unifill.uToString = function(codePoints) {
	return luxe_utils_unifill_Utf16.fromCodePoints(codePoints).toString();
};
var luxe_utils_unifill_Utf = function() { };
luxe_utils_unifill_Utf.__name__ = true;
luxe_utils_unifill_Utf.prototype = {
	__class__: luxe_utils_unifill_Utf
	,__properties__: {get_length:"get_length"}
};
var luxe_utils_unifill_Utf16 = function(s) {
	this.str = s;
};
luxe_utils_unifill_Utf16.__name__ = true;
luxe_utils_unifill_Utf16.__interfaces__ = [luxe_utils_unifill_Utf];
luxe_utils_unifill_Utf16.fromCodePoint = function(codePoint) {
	var buf = new StringBuf();
	luxe_utils_unifill__$Utf16_Utf16Impl.encode_code_point(function(x) {
		buf.b += String.fromCharCode(x);
	},codePoint);
	return new luxe_utils_unifill_Utf16(buf.b);
};
luxe_utils_unifill_Utf16.fromCodePoints = function(codePoints) {
	var buf = new StringBuf();
	var $it0 = $iterator(codePoints)();
	while( $it0.hasNext() ) {
		var c = $it0.next();
		luxe_utils_unifill__$Utf16_Utf16Impl.encode_code_point(function(x) {
			buf.b += String.fromCharCode(x);
		},c);
	}
	return new luxe_utils_unifill_Utf16(buf.b);
};
luxe_utils_unifill_Utf16.fromString = function(s) {
	return new luxe_utils_unifill_Utf16(s);
};
luxe_utils_unifill_Utf16.fromArray = function(a) {
	return new luxe_utils_unifill_Utf16((function($this) {
		var $r;
		var buf_b = "";
		{
			var _g = 0;
			while(_g < a.length) {
				var x = a[_g];
				++_g;
				buf_b += String.fromCharCode(x);
			}
		}
		$r = buf_b;
		return $r;
	}(this)));
};
luxe_utils_unifill_Utf16.prototype = {
	codeUnitAt: function(index) {
		return this.str.charCodeAt(index);
	}
	,codePointAt: function(index) {
		return luxe_utils_unifill__$Utf16_Utf16Impl.decode_code_point(this.str.length,$bind(this,this.codeUnitAt),index);
	}
	,charAt: function(index) {
		return new luxe_utils_unifill_Utf16((function($this) {
			var $r;
			var len = $this.codePointWidthAt(index);
			$r = (function($this) {
				var $r;
				var s = HxOverrides.substr($this.str,index,len);
				$r = s;
				return $r;
			}($this));
			return $r;
		}(this)));
	}
	,codePointCount: function(beginIndex,endIndex) {
		var index = beginIndex;
		var i = 0;
		while(index < endIndex) {
			index += this.codePointWidthAt(index);
			++i;
		}
		return i;
	}
	,codePointWidthAt: function(index) {
		var c = this.str.charCodeAt(index);
		if(!(55296 <= c && c <= 56319)) return 1; else return 2;
	}
	,codePointWidthBefore: function(index) {
		return luxe_utils_unifill__$Utf16_Utf16Impl.find_prev_code_point($bind(this,this.codeUnitAt),index);
	}
	,offsetByCodePoints: function(index,codePointOffset) {
		if(codePointOffset >= 0) return this.forward_offset_by_code_points(index,codePointOffset); else return this.backward_offset_by_code_points(index,-codePointOffset);
	}
	,substr: function(index,len) {
		return new luxe_utils_unifill_Utf16((function($this) {
			var $r;
			var s = HxOverrides.substr($this.str,index,len);
			$r = s;
			return $r;
		}(this)));
	}
	,validate: function() {
		var len = this.str.length;
		var accessor = $bind(this,this.codeUnitAt);
		var i = 0;
		while(i < len) {
			luxe_utils_unifill__$Utf16_Utf16Impl.decode_code_point(len,accessor,i);
			i += this.codePointWidthAt(i);
		}
	}
	,toString: function() {
		return this.str;
	}
	,toArray: function() {
		var this1 = this.str;
		var i = 0;
		var len = this1.length;
		var _g = [];
		while(i < len) _g.push(StringTools.fastCodeAt(this1,i++));
		return _g;
	}
	,get_length: function() {
		return this.str.length;
	}
	,forward_offset_by_code_points: function(index,codePointOffset) {
		var len = this.str.length;
		var i = 0;
		while(i < codePointOffset && index < len) {
			index += this.codePointWidthAt(index);
			++i;
		}
		return index;
	}
	,backward_offset_by_code_points: function(index,codePointOffset) {
		var count = 0;
		while(count < codePointOffset && 0 < index) {
			index -= luxe_utils_unifill__$Utf16_Utf16Impl.find_prev_code_point($bind(this,this.codeUnitAt),index);
			++count;
		}
		return index;
	}
	,__class__: luxe_utils_unifill_Utf16
	,__properties__: {get_length:"get_length"}
};
var luxe_utils_unifill__$Utf16_Utf16Impl = function() { };
luxe_utils_unifill__$Utf16_Utf16Impl.__name__ = true;
luxe_utils_unifill__$Utf16_Utf16Impl.code_point_width = function(c) {
	if(!(55296 <= c && c <= 56319)) return 1; else return 2;
};
luxe_utils_unifill__$Utf16_Utf16Impl.find_prev_code_point = function(accessor,index) {
	var c = accessor(index - 1);
	if(!(56320 <= c && c <= 57343)) return 1; else return 2;
};
luxe_utils_unifill__$Utf16_Utf16Impl.encode_code_point = function(addUnit,codePoint) {
	if(codePoint <= 65535) addUnit(codePoint); else {
		addUnit((codePoint >> 10) + 55232);
		addUnit(codePoint & 1023 | 56320);
	}
};
luxe_utils_unifill__$Utf16_Utf16Impl.decode_code_point = function(len,accessor,index) {
	if(index < 0 || len <= index) throw new js__$Boot_HaxeError(luxe_utils_unifill_Exception.InvalidCodeUnitSequence(index));
	var hi = accessor(index);
	if(55296 <= hi && hi <= 56319) {
		if(index + 1 < 0 || len <= index + 1) throw new js__$Boot_HaxeError(luxe_utils_unifill_Exception.InvalidCodeUnitSequence(index));
		var lo = accessor(index + 1);
		if(56320 <= lo && lo <= 57343) return hi - 55232 << 10 | lo & 1023; else throw new js__$Boot_HaxeError(luxe_utils_unifill_Exception.InvalidCodeUnitSequence(index));
	} else if(56320 <= hi && hi <= 57343) throw new js__$Boot_HaxeError(luxe_utils_unifill_Exception.InvalidCodeUnitSequence(index)); else return hi;
};
var luxe_utils_unifill__$Utf16_StringU16Buffer_$Impl_$ = {};
luxe_utils_unifill__$Utf16_StringU16Buffer_$Impl_$.__name__ = true;
luxe_utils_unifill__$Utf16_StringU16Buffer_$Impl_$._new = function() {
	return new StringBuf();
};
luxe_utils_unifill__$Utf16_StringU16Buffer_$Impl_$.addUnit = function(this1,unit) {
	this1.b += String.fromCharCode(unit);
};
luxe_utils_unifill__$Utf16_StringU16Buffer_$Impl_$.getStringU16 = function(this1) {
	return this1.b;
};
var luxe_utils_unifill__$Utf16_StringU16_$Impl_$ = {};
luxe_utils_unifill__$Utf16_StringU16_$Impl_$.__name__ = true;
luxe_utils_unifill__$Utf16_StringU16_$Impl_$.__properties__ = {get_length:"get_length"}
luxe_utils_unifill__$Utf16_StringU16_$Impl_$.fromString = function(s) {
	return s;
};
luxe_utils_unifill__$Utf16_StringU16_$Impl_$.ofArray = function(a) {
	var buf_b = "";
	var _g = 0;
	while(_g < a.length) {
		var x = a[_g];
		++_g;
		buf_b += String.fromCharCode(x);
	}
	return buf_b;
};
luxe_utils_unifill__$Utf16_StringU16_$Impl_$.fromArray = function(a) {
	var buf_b = "";
	var _g = 0;
	while(_g < a.length) {
		var x = a[_g];
		++_g;
		buf_b += String.fromCharCode(x);
	}
	return buf_b;
};
luxe_utils_unifill__$Utf16_StringU16_$Impl_$.codeUnitAt = function(this1,index) {
	return this1.charCodeAt(index);
};
luxe_utils_unifill__$Utf16_StringU16_$Impl_$.substr = function(this1,index,len) {
	var s = HxOverrides.substr(this1,index,len);
	return s;
};
luxe_utils_unifill__$Utf16_StringU16_$Impl_$.toString = function(this1) {
	return this1;
};
luxe_utils_unifill__$Utf16_StringU16_$Impl_$.toArray = function(this1) {
	var i = 0;
	var len = this1.length;
	var _g = [];
	while(i < len) _g.push(StringTools.fastCodeAt(this1,i++));
	return _g;
};
luxe_utils_unifill__$Utf16_StringU16_$Impl_$._new = function(s) {
	return s;
};
luxe_utils_unifill__$Utf16_StringU16_$Impl_$.get_length = function(this1) {
	return this1.length;
};
var phoenix_BatchState = function(_r) {
	this.log = false;
	this.last_group = -1;
	this.batcher = _r;
	this.geom_state = new phoenix_geometry_GeometryState();
	this.last_geom_state = new phoenix_geometry_GeometryState();
};
phoenix_BatchState.__name__ = true;
phoenix_BatchState.prototype = {
	active_shader: function() {
		if(this.geom_state.shader != null) return this.geom_state.shader; else if(this.geom_state.texture != null) return this.batcher.renderer.shaders.textured.shader; else return this.batcher.renderer.shaders.plain.shader;
	}
	,activate: function(batcher) {
		if(this.geom_state.dirty) {
			if(this.geom_state.texture != null) {
				if(this.last_texture_id == null) {
				}
				if(this.last_texture_id != this.geom_state.texture.id) {
					this.last_texture_id = this.geom_state.texture.id;
					if(this.geom_state.texture.loaded) {
						this.geom_state.texture.bind();
						this.geom_state.texture.activate(batcher.tex0_attribute);
					}
				}
			} else {
				Luxe.renderer.state.bindTexture2D(null);
				this.last_texture_id = null;
			}
			if(this.geom_state.shader != null) {
				if(this.last_shader_id != this.geom_state.shader.program) {
					batcher.shader_activate(this.geom_state.shader);
					this.last_shader_id = this.geom_state.shader.program;
				}
			} else if(this.geom_state.texture != null) {
				batcher.shader_activate(batcher.renderer.shaders.textured.shader);
				this.last_shader_id = batcher.renderer.shaders.textured.shader.program;
			} else {
				batcher.shader_activate(batcher.renderer.shaders.plain.shader);
				this.last_shader_id = batcher.renderer.shaders.plain.shader.program;
			}
			if(this.geom_state.group != this.last_group) {
				var previous = batcher.groups.h[this.last_group];
				if(previous != null) {
					var _g = 0;
					while(_g < previous.length) {
						var _batch_group = previous[_g];
						++_g;
						if(_batch_group.post_render != null) _batch_group.post_render(batcher);
					}
				}
				var current = batcher.groups.h[this.geom_state.group];
				if(current != null) {
					var _g1 = 0;
					while(_g1 < current.length) {
						var _batch_group1 = current[_g1];
						++_g1;
						if(_batch_group1.pre_render != null) _batch_group1.pre_render(batcher);
					}
				}
				this.last_group = this.geom_state.group;
			}
		}
		if(this.geom_state.clip) {
			if(!this.is_clipping) {
				snow_platform_web_render_opengl_GL.enable(3089);
				this.is_clipping = true;
			}
			if(this.clip_rect != null) {
				if(!this.clip_rect.equal(this.last_clip_rect)) {
					var _y = batcher.view.get_viewport().h - (this.clip_rect.y + this.clip_rect.h);
					snow_platform_web_render_opengl_GL.scissor(this.clip_rect.x | 0,_y | 0,this.clip_rect.w | 0,this.clip_rect.h | 0);
				}
			}
		} else if(this.is_clipping) {
			snow_platform_web_render_opengl_GL.disable(3089);
			this.is_clipping = false;
		}
		this.geom_state.clean();
	}
	,deactivate: function(batcher) {
		if(this.last_texture_id != null) Luxe.renderer.state.bindTexture2D(null);
		Luxe.renderer.state.useProgram(null);
		var previous = batcher.groups.h[this.last_group];
		if(previous != null) {
			var _g = 0;
			while(_g < previous.length) {
				var _batch_group = previous[_g];
				++_g;
				if(_batch_group.post_render != null) _batch_group.post_render(batcher);
			}
		}
		if(this.is_clipping) snow_platform_web_render_opengl_GL.disable(3089);
	}
	,update: function(geom) {
		this.geom_state.clone_onto(this.last_geom_state);
		this.geom_state.update(geom.state);
		if(this.geom_state.clip) {
			this.last_clip_rect = this.clip_rect;
			this.clip_rect = geom.get_clip_rect();
		}
		return this.geom_state.dirty || this.last_clip_rect != this.clip_rect;
	}
	,str: function() {
		if(!this.log) return;
		haxe_Log.trace("\t+ BATCHSTATE LAST ",{ fileName : "BatchState.hx", lineNumber : 200, className : "phoenix.BatchState", methodName : "str"});
		haxe_Log.trace("\t\tdepth - " + this.last_geom_state.depth,{ fileName : "BatchState.hx", lineNumber : 201, className : "phoenix.BatchState", methodName : "str"});
		haxe_Log.trace("\t\tgroup - " + this.last_geom_state.group,{ fileName : "BatchState.hx", lineNumber : 202, className : "phoenix.BatchState", methodName : "str"});
		haxe_Log.trace("\t\ttexture - " + (this.last_geom_state.texture == null?"null":this.last_geom_state.texture.id),{ fileName : "BatchState.hx", lineNumber : 203, className : "phoenix.BatchState", methodName : "str"});
		if(this.last_geom_state.texture != null) haxe_Log.trace("\t\t\t " + Std.string(this.last_geom_state.texture.texture),{ fileName : "BatchState.hx", lineNumber : 205, className : "phoenix.BatchState", methodName : "str"});
		haxe_Log.trace("\t\tshader - " + (this.last_geom_state.shader == null?"null":this.last_geom_state.shader.id),{ fileName : "BatchState.hx", lineNumber : 207, className : "phoenix.BatchState", methodName : "str"});
		haxe_Log.trace("\t\tprimitive_type - " + this.last_geom_state.primitive_type,{ fileName : "BatchState.hx", lineNumber : 208, className : "phoenix.BatchState", methodName : "str"});
		haxe_Log.trace("\t\tclip - " + Std.string(this.last_geom_state.clip),{ fileName : "BatchState.hx", lineNumber : 209, className : "phoenix.BatchState", methodName : "str"});
		haxe_Log.trace("\t- BATCHSTATE LAST",{ fileName : "BatchState.hx", lineNumber : 210, className : "phoenix.BatchState", methodName : "str"});
		haxe_Log.trace("\t+ BATCHSTATE STATE",{ fileName : "BatchState.hx", lineNumber : 212, className : "phoenix.BatchState", methodName : "str"});
		haxe_Log.trace("\t\tdepth - " + this.geom_state.depth,{ fileName : "BatchState.hx", lineNumber : 213, className : "phoenix.BatchState", methodName : "str"});
		haxe_Log.trace("\t\tgroup - " + this.geom_state.group,{ fileName : "BatchState.hx", lineNumber : 214, className : "phoenix.BatchState", methodName : "str"});
		haxe_Log.trace("\t\ttexture - " + (this.geom_state.texture == null?"null":this.geom_state.texture.id),{ fileName : "BatchState.hx", lineNumber : 215, className : "phoenix.BatchState", methodName : "str"});
		if(this.geom_state.texture != null) haxe_Log.trace("\t\t\t " + Std.string(this.geom_state.texture.texture),{ fileName : "BatchState.hx", lineNumber : 217, className : "phoenix.BatchState", methodName : "str"});
		haxe_Log.trace("\t\tshader - " + (this.geom_state.shader == null?"null":this.geom_state.shader.id),{ fileName : "BatchState.hx", lineNumber : 219, className : "phoenix.BatchState", methodName : "str"});
		haxe_Log.trace("\t\tprimitive_type - " + this.geom_state.primitive_type,{ fileName : "BatchState.hx", lineNumber : 220, className : "phoenix.BatchState", methodName : "str"});
		haxe_Log.trace("\t\tclip - " + Std.string(this.geom_state.clip),{ fileName : "BatchState.hx", lineNumber : 221, className : "phoenix.BatchState", methodName : "str"});
		haxe_Log.trace("\t- BATCHSTATE STATE",{ fileName : "BatchState.hx", lineNumber : 222, className : "phoenix.BatchState", methodName : "str"});
	}
	,__class__: phoenix_BatchState
};
var phoenix_BatchGroup = function(_pre,_post) {
	this.pre_render = _pre;
	this.post_render = _post;
};
phoenix_BatchGroup.__name__ = true;
phoenix_BatchGroup.prototype = {
	__class__: phoenix_BatchGroup
};
var phoenix_Batcher = function(_r,_name) {
	if(_name == null) _name = "";
	this.sequence = -1;
	this.name = "";
	this.log = false;
	this.visible_count = 0;
	this.static_batched_count = 0;
	this.dynamic_batched_count = 0;
	this.draw_calls = 0;
	this.color_attribute = 2;
	this.tcoord_attribute = 1;
	this.vert_attribute = 0;
	this.vert_count = 0;
	this.max_floats = 0;
	this.max_verts = 0;
	this.buffer_index = 0;
	this.buffer_count = 2;
	this.static_normal_floats = 0;
	this.static_color_floats = 0;
	this.static_tcoord_floats = 0;
	this.static_vert_floats = 0;
	this.normal_floats = 0;
	this.color_floats = 0;
	this.tcoord_floats = 0;
	this.vert_floats = 0;
	this.tree_changed = false;
	this.enabled = true;
	this.layer = 0;
	this.id = Luxe.utils.uniqueid();
	this.renderer = _r;
	this.sequence = ++phoenix_Batcher._sequence_key;
	this.geometry = new luxe_structural_BalancedBST_$phoenix_$geometry_$GeometryKey_$phoenix_$geometry_$Geometry($bind(this,this.geometry_compare));
	this.groups = new haxe_ds_IntMap();
	this.max_verts = Std["int"](Math.pow(2,15));
	this.max_floats = this.max_verts * 4;
	var elements = this.max_floats;
	var len = null;
	var this1;
	if(elements != null) this1 = new Float32Array(elements); else this1 = null;
	this.vertlist = this1;
	var elements1 = this.max_floats;
	var len1 = null;
	var this2;
	if(elements1 != null) this2 = new Float32Array(elements1); else this2 = null;
	this.tcoordlist = this2;
	var elements2 = this.max_floats;
	var len2 = null;
	var this3;
	if(elements2 != null) this3 = new Float32Array(elements2); else this3 = null;
	this.colorlist = this3;
	var elements3 = this.max_floats;
	var len3 = null;
	var this4;
	if(elements3 != null) this4 = new Float32Array(elements3); else this4 = null;
	this.static_vertlist = this4;
	var elements4 = this.max_floats;
	var len4 = null;
	var this5;
	if(elements4 != null) this5 = new Float32Array(elements4); else this5 = null;
	this.static_tcoordlist = this5;
	var elements5 = this.max_floats;
	var len5 = null;
	var this6;
	if(elements5 != null) this6 = new Float32Array(elements5); else this6 = null;
	this.static_colorlist = this6;
	this.view = this.renderer.camera;
	this.vertexBuffers = [];
	this.tcoordBuffers = [];
	this.vcolorBuffers = [];
	var _g1 = 0;
	var _g = this.buffer_count;
	while(_g1 < _g) {
		var i = _g1++;
		var _vb = snow_platform_web_render_opengl_GL.createBuffer();
		var _tb = snow_platform_web_render_opengl_GL.createBuffer();
		var _cb = snow_platform_web_render_opengl_GL.createBuffer();
		var _nb = snow_platform_web_render_opengl_GL.createBuffer();
		snow_platform_web_render_opengl_GL.bindBuffer(34962,_vb);
		snow_platform_web_render_opengl_GL.bufferData(34962,this.vertlist,35044);
		snow_platform_web_render_opengl_GL.bindBuffer(34962,_tb);
		snow_platform_web_render_opengl_GL.bufferData(34962,this.tcoordlist,35044);
		snow_platform_web_render_opengl_GL.bindBuffer(34962,_cb);
		snow_platform_web_render_opengl_GL.bufferData(34962,this.colorlist,35044);
		this.vertexBuffers.push(_vb);
		this.tcoordBuffers.push(_tb);
		this.vcolorBuffers.push(_cb);
	}
	snow_platform_web_render_opengl_GL.enableVertexAttribArray(this.vert_attribute);
	snow_platform_web_render_opengl_GL.enableVertexAttribArray(this.tcoord_attribute);
	snow_platform_web_render_opengl_GL.enableVertexAttribArray(this.color_attribute);
	if(_name.length == 0) this.name = Luxe.utils.uniqueid(); else this.name = _name;
};
phoenix_Batcher.__name__ = true;
phoenix_Batcher.prototype = {
	set_layer: function(_layer) {
		this.layer = _layer;
		this.renderer.batchers.sort(($_=this.renderer,$bind($_,$_.sort_batchers)));
		return this.layer;
	}
	,toString: function() {
		return "Batcher(" + this.name + ")";
	}
	,compare: function(other) {
		if(this.layer == other.layer) return 0;
		if(this.layer < other.layer) return -1;
		return 1;
	}
	,add_group: function(_group,_pre_render,_post_render) {
		if(!this.groups.h.hasOwnProperty(_group)) {
			var value = [];
			this.groups.h[_group] = value;
		}
		this.groups.h[_group].push(new phoenix_BatchGroup(_pre_render,_post_render));
	}
	,compare_rule_to_string: function(r) {
		switch(r) {
		case 0:
			return "same";
		case 1:
			return "depth <";
		case 2:
			return "depth >";
		case 3:
			return "shader <";
		case 4:
			return "shader >";
		case 5:
			return "shader s._ >";
		case 6:
			return "shader _.s <";
		case 7:
			return "texture <";
		case 8:
			return "texture >";
		case 9:
			return "texture t._ >";
		case 10:
			return "texture _.t <";
		case 11:
			return "primitive <";
		case 12:
			return "primitive >";
		case 13:
			return "unclipped";
		case 14:
			return "clipped";
		case 15:
			return "timestamp <";
		case 16:
			return "timestamp >";
		case 17:
			return "timestamp ==";
		case 18:
			return "sequence <";
		case 19:
			return "sequence >";
		case 20:
			return "fallback";
		}
		return "unknown";
	}
	,compare_rule: function(a,b) {
		if(a.uuid == b.uuid) return 0;
		if(a.depth < b.depth) return 1;
		if(a.depth > b.depth) return 2;
		if(a.shader != null && b.shader != null) {
			if(a.shader.id < b.shader.id) return 3;
			if(a.shader.id > b.shader.id) return 4;
		} else if(a.shader != null && b.shader == null) return 5; else if(a.shader == null && b.shader != null) return 6;
		if(a.texture != null && b.texture != null) {
			if(a.texture.id < b.texture.id) return 7;
			if(a.texture.id > b.texture.id) return 8;
		} else if(a.texture != null && b.texture == null) return 9; else if(a.texture == null && b.texture != null) return 10;
		var a_primitive_index = a.primitive_type;
		var b_primitive_index = b.primitive_type;
		if(a_primitive_index < b_primitive_index) return 11;
		if(a_primitive_index > b_primitive_index) return 12;
		if(a.clip != b.clip) {
			if(a.clip == false && b.clip == true) return 13; else if(a.clip == true && b.clip == false) return 14;
		}
		if(a.timestamp < b.timestamp) return 15;
		if(a.timestamp > b.timestamp) return 16;
		if(a.timestamp == b.timestamp) return 17;
		if(a.sequence < b.sequence) return 18;
		if(a.sequence > b.sequence) return 19;
		return 20;
	}
	,geometry_compare: function(a,b) {
		if(a.uuid == b.uuid) return 0;
		if(a.depth < b.depth) return -1;
		if(a.depth > b.depth) return 1;
		if(a.shader != null && b.shader != null) {
			if(a.shader.id < b.shader.id) return -1;
			if(a.shader.id > b.shader.id) return 1;
		} else if(a.shader != null && b.shader == null) return 1; else if(a.shader == null && b.shader != null) return -1;
		if(a.texture != null && b.texture != null) {
			if(a.texture.id < b.texture.id) return -1;
			if(a.texture.id > b.texture.id) return 1;
		} else if(a.texture != null && b.texture == null) return 1; else if(a.texture == null && b.texture != null) return -1;
		var a_primitive_index = a.primitive_type;
		var b_primitive_index = b.primitive_type;
		if(a_primitive_index < b_primitive_index) return -1;
		if(a_primitive_index > b_primitive_index) return 1;
		if(a.clip != b.clip) {
			if(a.clip == false && b.clip == true) return 1; else if(a.clip == true && b.clip == false) return -1;
		}
		if(a.timestamp < b.timestamp) return -1;
		if(a.timestamp >= b.timestamp) return 1;
		if(a.sequence < b.sequence) return -1;
		if(a.sequence > b.sequence) return 1;
		return 1;
	}
	,list_geometry: function() {
		var $it0 = this.geometry.iterator();
		while( $it0.hasNext() ) {
			var geom = $it0.next();
			null;
		}
	}
	,add: function(_geom,_force_add) {
		if(_force_add == null) _force_add = false;
		if(this.geometry.find(_geom.key) == null || _force_add) {
			if(!Lambda.has(_geom.batchers,this)) _geom.batchers.push(this);
			this.geometry.insert(_geom.key,_geom);
			_geom.added = true;
			this.tree_changed = true;
		} else {
		}
	}
	,empty: function(_drop) {
		if(_drop == null) _drop = true;
		if(_drop) {
			var $it0 = this.geometry.iterator();
			while( $it0.hasNext() ) {
				var geom = $it0.next();
				geom.drop(true);
				geom = null;
			}
		} else {
			var $it1 = this.geometry.iterator();
			while( $it1.hasNext() ) {
				var geom1 = $it1.next();
				this.geometry.remove(geom1.key);
			}
		}
	}
	,remove: function(_geom,_remove_batcher_from_geometry) {
		if(_remove_batcher_from_geometry == null) _remove_batcher_from_geometry = true;
		if(_remove_batcher_from_geometry) {
			HxOverrides.remove(_geom.batchers,this);
			if(_geom.batchers.length == 0) _geom.added = false;
		}
		var countbefore = this.geometry.size();
		this.geometry.remove(_geom.key);
		var countafter = this.geometry.size();
		if(countbefore == countafter) {
		}
		this.tree_changed = true;
	}
	,shader_activate: function(_shader) {
		_shader.activate();
		this.projectionmatrix_attribute = _shader.projectionmatrix_attribute;
		this.modelviewmatrix_attribute = _shader.modelviewmatrix_attribute;
		this.tex0_attribute = _shader.tex0_attribute;
		this.tex1_attribute = _shader.tex1_attribute;
		this.tex2_attribute = _shader.tex2_attribute;
		this.tex3_attribute = _shader.tex3_attribute;
		this.tex4_attribute = _shader.tex4_attribute;
		this.tex5_attribute = _shader.tex5_attribute;
		this.tex6_attribute = _shader.tex6_attribute;
		this.tex7_attribute = _shader.tex7_attribute;
		_shader.apply_uniforms();
		Luxe.renderer.state.activeTexture(33984);
	}
	,batch: function(persist_immediate) {
		if(persist_immediate == null) persist_immediate = false;
		this.dynamic_batched_count = 0;
		this.static_batched_count = 0;
		this.visible_count = 0;
		this.vert_floats = 0;
		this.tcoord_floats = 0;
		this.color_floats = 0;
		this.normal_floats = 0;
		this.state = new phoenix_BatchState(this);
		var geom = null;
		var $it0 = this.geometry.iterator();
		while( $it0.hasNext() ) {
			var _geom = $it0.next();
			geom = _geom;
			if(geom != null && !geom.dropped) {
				if(this.state.update(geom)) {
					if(this.vert_floats > 0) this.submit_current_vertex_list(this.state.last_geom_state.primitive_type);
				}
				this.state.activate(this);
				if(geom.visible) {
					this.visible_count++;
					if(geom.get_locked()) {
						this.submit_static_geometry(geom);
						this.vert_count += geom.vertices.length;
					} else if(geom.get_primitive_type() == 3 || geom.get_primitive_type() == 2 || geom.get_primitive_type() == 5 || geom.get_primitive_type() == 6) {
						this.geometry_batch(geom);
						this.submit_current_vertex_list(geom.get_primitive_type());
						this.vert_count += geom.vertices.length;
					} else {
						this.geometry_batch(geom);
						this.dynamic_batched_count++;
						this.vert_count += geom.vertices.length;
					}
					if(!persist_immediate && geom.immediate) geom.drop();
				}
			} else {
			}
		}
		if(this.vert_floats > 0 && geom != null) {
			this.state.update(geom);
			this.state.activate(this);
			this.submit_current_vertex_list(this.state.last_geom_state.primitive_type);
		}
		this.state.deactivate(this);
		this.state = null;
	}
	,draw: function(persist_immediate) {
		if(persist_immediate == null) persist_immediate = false;
		this.draw_calls = 0;
		this.vert_count = 0;
		this.view.process();
		this.renderer.state.viewport(this.view.get_viewport().x,this.view.get_viewport().y,this.view.get_viewport().w,this.view.get_viewport().h);
		this.batch(persist_immediate);
	}
	,submit_static_geometry: function(geom) {
		if(geom.vertices.length == 0) return;
		this.static_vert_floats = 0;
		this.static_tcoord_floats = 0;
		this.static_color_floats = 0;
		if(!geom.submitted || geom.get_dirty()) this.geometry_batch_static(geom); else {
			this.static_vert_floats = geom.vertices.length * 4;
			this.static_tcoord_floats = geom.vertices.length * 4;
			this.static_color_floats = geom.vertices.length * 4;
		}
		if(geom.static_vertex_buffer == null) {
			geom.static_vertex_buffer = snow_platform_web_render_opengl_GL.createBuffer();
			geom.static_tcoord_buffer = snow_platform_web_render_opengl_GL.createBuffer();
			geom.static_vcolor_buffer = snow_platform_web_render_opengl_GL.createBuffer();
		}
		this._enable_attributes();
		snow_platform_web_render_opengl_GL.bindBuffer(34962,geom.static_vertex_buffer);
		snow_platform_web_render_opengl_GL.vertexAttribPointer(this.vert_attribute,4,5126,false,0,0);
		if(!geom.submitted || geom.get_dirty()) snow_platform_web_render_opengl_GL.bufferData(34962,this.static_vertlist,35044);
		snow_platform_web_render_opengl_GL.bindBuffer(34962,geom.static_tcoord_buffer);
		snow_platform_web_render_opengl_GL.vertexAttribPointer(this.tcoord_attribute,4,5126,false,0,0);
		if(!geom.submitted || geom.get_dirty()) snow_platform_web_render_opengl_GL.bufferData(34962,this.static_tcoordlist,35044);
		snow_platform_web_render_opengl_GL.bindBuffer(34962,geom.static_vcolor_buffer);
		snow_platform_web_render_opengl_GL.vertexAttribPointer(this.color_attribute,4,5126,false,0,0);
		if(!geom.submitted || geom.get_dirty()) snow_platform_web_render_opengl_GL.bufferData(34962,this.static_colorlist,35044);
		snow_platform_web_render_opengl_GL.drawArrays(geom.get_primitive_type(),0,phoenix_utils_Rendering.get_elements_for_type(geom.get_primitive_type(),this.static_vert_floats));
		this._disable_attributes();
		this.draw_calls++;
		this.static_batched_count++;
		this.static_vert_floats = 0;
		this.static_tcoord_floats = 0;
		this.static_color_floats = 0;
		geom.set_dirty(false);
		geom.submitted = true;
	}
	,submit_current_vertex_list: function(type) {
		if(this.vert_floats == 0) return;
		if(this.vert_floats > this.max_floats) throw new js__$Boot_HaxeError("uh oh, somehow too many floats are being submitted (max:$max_floats, attempt:$vert_floats).");
		this._enable_attributes();
		snow_platform_web_render_opengl_GL.bindBuffer(34962,this.vertexBuffers[this.buffer_index]);
		snow_platform_web_render_opengl_GL.vertexAttribPointer(0,4,5126,false,0,0);
		snow_platform_web_render_opengl_GL.bufferSubData(34962,0,(function($this) {
			var $r;
			var buffer = $this.vertlist.buffer;
			var len = $this.vert_floats;
			var this1;
			if(buffer != null) {
				if(len == null) {
					len = undefined;
				} else len = len;
				this1 = new Float32Array(buffer,0,len);
			} else this1 = null;
			$r = this1;
			return $r;
		}(this)));
		snow_platform_web_render_opengl_GL.bindBuffer(34962,this.tcoordBuffers[this.buffer_index]);
		snow_platform_web_render_opengl_GL.vertexAttribPointer(1,4,5126,false,0,0);
		snow_platform_web_render_opengl_GL.bufferSubData(34962,0,(function($this) {
			var $r;
			var buffer1 = $this.tcoordlist.buffer;
			var len1 = $this.tcoord_floats;
			var this2;
			if(buffer1 != null) {
				if(len1 == null) {
					len1 = undefined;
				} else len1 = len1;
				this2 = new Float32Array(buffer1,0,len1);
			} else this2 = null;
			$r = this2;
			return $r;
		}(this)));
		snow_platform_web_render_opengl_GL.bindBuffer(34962,this.vcolorBuffers[this.buffer_index]);
		snow_platform_web_render_opengl_GL.vertexAttribPointer(2,4,5126,false,0,0);
		snow_platform_web_render_opengl_GL.bufferSubData(34962,0,(function($this) {
			var $r;
			var buffer2 = $this.colorlist.buffer;
			var len2 = $this.color_floats;
			var this3;
			if(buffer2 != null) {
				if(len2 == null) {
					len2 = undefined;
				} else len2 = len2;
				this3 = new Float32Array(buffer2,0,len2);
			} else this3 = null;
			$r = this3;
			return $r;
		}(this)));
		snow_platform_web_render_opengl_GL.drawArrays(type,0,phoenix_utils_Rendering.get_elements_for_type(type,this.vert_floats));
		this._disable_attributes();
		this.buffer_index++;
		if(this.buffer_index >= this.buffer_count) this.buffer_index = 0;
		this.vert_floats = 0;
		this.tcoord_floats = 0;
		this.color_floats = 0;
		this.normal_floats = 0;
		this.draw_calls++;
	}
	,geometry_batch: function(geom) {
		var _count_after = geom.vertices.length + this.vert_floats / 4;
		if(_count_after > this.max_verts) this.submit_current_vertex_list(geom.get_primitive_type());
		geom.batch(this.vert_floats,this.tcoord_floats,this.color_floats,this.normal_floats,this.vertlist,this.tcoordlist,this.colorlist,this.normallist);
		this.vert_floats += geom.vertices.length * 4;
		this.tcoord_floats += geom.vertices.length * 4;
		this.color_floats += geom.vertices.length * 4;
	}
	,geometry_batch_static: function(geom) {
		geom.batch(this.static_vert_floats,this.static_tcoord_floats,this.static_color_floats,this.static_normal_floats,this.static_vertlist,this.static_tcoordlist,this.static_colorlist,this.static_normallist);
		this.static_vert_floats += geom.vertices.length * 4;
		this.static_tcoord_floats += geom.vertices.length * 4;
		this.static_color_floats += geom.vertices.length * 4;
	}
	,_enable_attributes: function() {
		snow_platform_web_render_opengl_GL.uniformMatrix4fv(this.projectionmatrix_attribute,false,this.view.projection_float32array);
		snow_platform_web_render_opengl_GL.uniformMatrix4fv(this.modelviewmatrix_attribute,false,this.view.view_inverse_float32array);
	}
	,_disable_attributes: function() {
	}
	,__class__: phoenix_Batcher
	,__properties__: {set_layer:"set_layer"}
};
var phoenix_BitmapFont = function(_options) {
	this.items_total = 0;
	this.items_loaded = 0;
	this.loaded = false;
	if(_options == null) this.options = { id : "font." + Luxe.utils.uniqueid()}; else this.options = _options;
	this.id = this.options.id;
	this.default_options();
	luxe_resource_Resource.call(this,this.options.resources,7);
	this.pages = new haxe_ds_IntMap();
};
phoenix_BitmapFont.__name__ = true;
phoenix_BitmapFont.load = function(_options) {
	if(_options == null || _options.id == null) throw new js__$Boot_HaxeError("BitmapFont: `load` cannot work without a file id to load from.");
	if(_options.silent == null) _options.silent = false;
	var font = new phoenix_BitmapFont(_options);
	Luxe.loadText(font.id,function(font_data) {
		font.from_string(font_data.text,font.options.onload,null,font.options.silent);
		font.options.resources.cache(font);
	});
	return font;
};
phoenix_BitmapFont.__super__ = luxe_resource_Resource;
phoenix_BitmapFont.prototype = $extend(luxe_resource_Resource.prototype,{
	from_string: function(_bitmapfont_data,_onload,_custom_pages,_silent) {
		if(_silent == null) _silent = false;
		if(_onload != null) this.onload = _onload;
		this.info = phoenix__$BitmapFont_Parser.parse(_bitmapfont_data);
		if(this.info.char_count == 0 || this.info.pages.length == 0 && _custom_pages.length == 0) {
			haxe_Log.trace("i / bitmapfont / " + ("error / " + this.id + " / invalid font data specified for this font, cannot load. This font will not be valid."),{ fileName : "BitmapFont.hx", lineNumber : 116, className : "phoenix.BitmapFont", methodName : "from_string"});
			this.do_onload(false);
			return;
		}
		this.space_char = this.info.chars.h[32];
		this.load_pages(_custom_pages);
		if(HxOverrides.indexOf(phoenix_BitmapFont.generic_names,this.id,0) != -1) {
			var _warning = "warning / font loaded with a generic or no name as \"" + this.id + "\". ";
			_warning += "This could lead to bugs or confusion, or not being able to retrieve the font ";
			_warning += "later from the resources.";
			haxe_Log.trace("i / bitmapfont / " + _warning,{ fileName : "BitmapFont.hx", lineNumber : 130, className : "phoenix.BitmapFont", methodName : "from_string"});
		}
	}
	,kerning: function(_first,_second) {
		var _map = this.info.kernings.h[_first];
		if(_map != null && _map.h.hasOwnProperty(_second)) return _map.h[_second];
		return 0;
	}
	,wrap_string_to_bounds: function(_string,_bounds,_point_size,_letter_spc) {
		if(_letter_spc == null) _letter_spc = 0.0;
		if(_point_size == null) _point_size = 1.0;
		var _g = this;
		if(_bounds == null) return _string;
		var _cur_x = 0.0;
		var _idx = 0;
		var _final_str = "";
		var _spacew = _g.width_of(" ",_point_size,_letter_spc,null);
		var _strings = _string.split(" ");
		var _count = _strings.length;
		var _g1 = 0;
		while(_g1 < _strings.length) {
			var _str = _strings[_g1];
			++_g1;
			if(luxe_utils_unifill_Unifill.uIndexOf(_str,"\n",null) == -1) {
				if(_str == "") _str = " ";
				var _w = _g.width_of(_str,_point_size,_letter_spc,null);
				if(_cur_x + _w > _bounds.w) {
					_cur_x = 0;
					_final_str += "\n";
				}
				_cur_x += _w;
				_final_str += _str;
			} else {
				var _widx = 0;
				var _words = _str.split("\n");
				var _g11 = 0;
				while(_g11 < _words.length) {
					var _word = _words[_g11];
					++_g11;
					if(_word != "") {
						var _w1 = _g.width_of(_word,_point_size,_letter_spc,null);
						if(_cur_x + _w1 > _bounds.w) {
							_cur_x = 0;
							_final_str += "\n";
						}
						_cur_x += _w1;
						_final_str += _word;
					} else _cur_x = 0;
					if(_widx < _words.length - 1) {
						_final_str += "\n";
						_cur_x = 0;
					}
					_widx++;
				}
			}
			if(_idx < _count - 1) {
				_final_str += " ";
				_cur_x += _spacew + _letter_spc;
			}
			_idx++;
		}
		return _final_str;
	}
	,width_of_line: function(_string,_point_size,_letter_spc) {
		if(_letter_spc == null) _letter_spc = 0.0;
		if(_point_size == null) _point_size = 1.0;
		var _cur_x = 0.0;
		var _cur_w = 0.0;
		var _ratio = _point_size / this.info.point_size;
		var i = 0;
		var _len = luxe_utils_unifill_InternalEncoding.codePointCount(_string,0,_string.length);
		var $it0 = new luxe_utils_unifill_CodePointIter(_string);
		while( $it0.hasNext() ) {
			var _uglyph = $it0.next();
			var _index = _uglyph;
			var _char = this.info.chars.h[_index];
			if(_char == null) _char = this.space_char;
			var _cw = (_char.xoffset + Math.max(_char.width,_char.xadvance)) * _ratio;
			var _cx = _cur_x + _char.xoffset * _ratio;
			var _spacing = _char.xadvance;
			if(i < _len - 1) {
				var _next_index = luxe_utils_unifill_Unifill.uCharCodeAt(_string,i + 1);
				_spacing += this.kerning(_index,_next_index);
				if(_next_index >= 32) _spacing += _letter_spc;
			}
			_cur_x += _spacing * _ratio;
			_cur_w = Math.max(_cur_w,_cx + _cw);
			++i;
		}
		return _cur_w;
	}
	,width_of: function(_string,_point_size,_letter_spc,_line_widths) {
		if(_letter_spc == null) _letter_spc = 0.0;
		if(_point_size == null) _point_size = 1.0;
		var _max_w = 0.0;
		var _push_widths = _line_widths != null;
		var _lines = luxe_utils_unifill_Unifill.uSplit(_string,"\n");
		var _g = 0;
		while(_g < _lines.length) {
			var _line = _lines[_g];
			++_g;
			var _cur_w = this.width_of_line(_line,_point_size,_letter_spc);
			_max_w = Math.max(_max_w,_cur_w);
			if(_push_widths) _line_widths.push(_cur_w);
		}
		return _max_w;
	}
	,height_of: function(_string,_point_size,_line_spc) {
		if(_line_spc == null) _line_spc = 0.0;
		return this.height_of_lines(_string.split("\n"),_point_size,_line_spc);
	}
	,dimensions_of: function(_string,_point_size,_into,_letter_spc,_line_spc) {
		if(_line_spc == null) _line_spc = 0.0;
		if(_letter_spc == null) _letter_spc = 0.0;
		var _width = this.width_of(_string,_point_size,_letter_spc,null);
		var _height = this.height_of_lines(_string.split("\n"),_point_size,_line_spc);
		return _into.set_xy(_width,_height);
	}
	,height_of_lines: function(_lines,_point_size,_line_spc) {
		if(_line_spc == null) _line_spc = 0.0;
		var _ratio = _point_size / this.info.point_size;
		return _lines.length * ((this.info.line_height + _line_spc) * _ratio);
	}
	,default_options: function() {
		if(this.options.id == null) this.options.id = this.id;
		if(this.options.resources == null) this.options.resources = Luxe.resources;
		if(this.options.mipmaps == null) this.options.mipmaps = false;
		if(this.options.filter == null) this.options.filter = phoenix_FilterType.linear;
		if(this.options.filter_min == null) this.options.filter_min = phoenix_FilterType.linear;
		if(this.options.filter_mag == null) this.options.filter_mag = phoenix_FilterType.linear;
	}
	,do_onload: function(success) {
		if(success == null) success = true;
		this.loaded = success;
		if(this.onload != null) this.onload(this);
	}
	,page_loaded: function(t) {
		this.items_loaded++;
		if(this.items_loaded == this.items_total) this.do_onload();
	}
	,load_pages: function(_custom_pages) {
		var _g2 = this;
		var _path;
		if(this.options.texture_path == null) _path = haxe_io_Path.directory(this.id); else _path = this.options.texture_path;
		if(_custom_pages == null) {
			this.items_total = Lambda.count(this.info.pages);
			var _g = 0;
			var _g1 = this.info.pages;
			while(_g < _g1.length) {
				var _page = [_g1[_g]];
				++_g;
				var _page_path = haxe_io_Path.join([_path,_page[0].file]);
				var _t = [Luxe.loadTexture(_page_path,null,this.options.silent)];
				if(_t[0] != null) _t[0].set_onload((function(_t,_page) {
					return function(_) {
						_g2.pages.h[_page[0].id] = _t[0];
						_t[0].slot = _page[0].id;
						_t[0].set_filter(_g2.options.filter);
						_t[0].set_filter_min(_g2.options.filter_min);
						_t[0].set_filter_mag(_g2.options.filter_mag);
						if(_g2.options.mipmaps) _t[0].generate_mipmaps();
						_g2.page_loaded(_t[0]);
					};
				})(_t,_page)); else throw new js__$Boot_HaxeError("BitmapFont: \"" + this.id + " (" + this.info.face + ")\" specified a page \"" + _page[0].file + "\" with a missing texture at " + _page_path);
			}
		} else {
			this.items_total = _custom_pages.length;
			var _id = 0;
			var _g3 = 0;
			while(_g3 < _custom_pages.length) {
				var _page1 = _custom_pages[_g3];
				++_g3;
				_page1.slot = _id;
				this.pages.h[_id] = _page1;
				++_id;
			}
			this.do_onload();
		}
	}
	,draw_text: function(opt) {
		if(opt.batcher == null) opt.batcher = Luxe.renderer.batcher;
		opt.font = this;
		return new phoenix_geometry_TextGeometry(opt);
	}
	,toString: function() {
		return "BitmapFont(" + this.id + ")";
	}
	,__class__: phoenix_BitmapFont
});
var phoenix__$BitmapFont_Parser = function() { };
phoenix__$BitmapFont_Parser.__name__ = true;
phoenix__$BitmapFont_Parser.parse = function(_font_data) {
	if(_font_data.length == 0) throw new js__$Boot_HaxeError("BitmapFont:Parser: _font_data is 0 length");
	var _info = { face : null, chars : new haxe_ds_IntMap(), point_size : 0, base_size : 0, char_count : 0, line_height : 0, pages : [], kernings : new haxe_ds_IntMap()};
	var _lines = _font_data.split("\n");
	if(_lines.length == 0) throw new js__$Boot_HaxeError("BitmapFont; invalid font data specified for parser.");
	var _first = _lines[0];
	if((function($this) {
		var $r;
		var _this = StringTools.ltrim(_first);
		$r = HxOverrides.substr(_this,0,4);
		return $r;
	}(this)) != "info") throw new js__$Boot_HaxeError("BitmapFont; invalid font data specified for parser. Format should be plain ascii text .fnt file only currently.");
	var _g = 0;
	while(_g < _lines.length) {
		var _line = _lines[_g];
		++_g;
		var _tokens = _line.split(" ");
		var _g1 = 0;
		while(_g1 < _tokens.length) {
			var _current = _tokens[_g1];
			++_g1;
			phoenix__$BitmapFont_Parser.parse_token(_current,_tokens,_info);
		}
	}
	return _info;
};
phoenix__$BitmapFont_Parser.parse_token = function(_token,_tokens,_info) {
	_tokens.shift();
	var _items = phoenix__$BitmapFont_Parser.tokenize_line(_tokens);
	switch(_token) {
	case "info":
		_info.face = phoenix__$BitmapFont_Parser.unquote(__map_reserved.face != null?_items.getReserved("face"):_items.h["face"]);
		_info.point_size = Std.parseFloat(__map_reserved.size != null?_items.getReserved("size"):_items.h["size"]);
		break;
	case "common":
		_info.line_height = Std.parseFloat(__map_reserved.lineHeight != null?_items.getReserved("lineHeight"):_items.h["lineHeight"]);
		_info.base_size = Std.parseFloat(__map_reserved.base != null?_items.getReserved("base"):_items.h["base"]);
		break;
	case "page":
		_info.pages.push({ id : Std.parseInt(__map_reserved.id != null?_items.getReserved("id"):_items.h["id"]), file : phoenix__$BitmapFont_Parser.trim(phoenix__$BitmapFont_Parser.unquote(__map_reserved.file != null?_items.getReserved("file"):_items.h["file"]))});
		break;
	case "chars":
		_info.char_count = Std.parseInt(__map_reserved.count != null?_items.getReserved("count"):_items.h["count"]);
		break;
	case "char":
		var _char = { id : Std.parseInt(__map_reserved.id != null?_items.getReserved("id"):_items.h["id"]), x : Std.parseFloat(__map_reserved.x != null?_items.getReserved("x"):_items.h["x"]), y : Std.parseFloat(__map_reserved.y != null?_items.getReserved("y"):_items.h["y"]), width : Std.parseFloat(__map_reserved.width != null?_items.getReserved("width"):_items.h["width"]), height : Std.parseFloat(__map_reserved.height != null?_items.getReserved("height"):_items.h["height"]), xoffset : Std.parseFloat(__map_reserved.xoffset != null?_items.getReserved("xoffset"):_items.h["xoffset"]), yoffset : Std.parseFloat(__map_reserved.yoffset != null?_items.getReserved("yoffset"):_items.h["yoffset"]), xadvance : Std.parseFloat(__map_reserved.xadvance != null?_items.getReserved("xadvance"):_items.h["xadvance"]), page : Std.parseInt(__map_reserved.page != null?_items.getReserved("page"):_items.h["page"])};
		_info.chars.h[_char.id] = _char;
		break;
	case "kerning":
		var _first = Std.parseInt(__map_reserved.first != null?_items.getReserved("first"):_items.h["first"]);
		var _second = Std.parseInt(__map_reserved.second != null?_items.getReserved("second"):_items.h["second"]);
		var _amount = Std.parseFloat(__map_reserved.amount != null?_items.getReserved("amount"):_items.h["amount"]);
		var _map = _info.kernings.h[_first];
		if(_map == null) {
			_map = new haxe_ds_IntMap();
			_info.kernings.h[_first] = _map;
		}
		_map.h[_second] = _amount;
		break;
	default:
	}
};
phoenix__$BitmapFont_Parser.tokenize_line = function(_tokens) {
	var _item_map = new haxe_ds_StringMap();
	var _g = 0;
	while(_g < _tokens.length) {
		var _token = _tokens[_g];
		++_g;
		var _items = _token.split("=");
		_item_map.set(_items[0],_items[1]);
	}
	return _item_map;
};
phoenix__$BitmapFont_Parser.trim = function(_s) {
	return StringTools.trim(_s);
};
phoenix__$BitmapFont_Parser.unquote = function(_s) {
	if(_s.indexOf("\"") != -1) _s = StringTools.replace(_s,"\"","");
	return _s;
};
var phoenix_ProjectionType = { __ename__ : true, __constructs__ : ["ortho","perspective","custom"] };
phoenix_ProjectionType.ortho = ["ortho",0];
phoenix_ProjectionType.ortho.toString = $estr;
phoenix_ProjectionType.ortho.__enum__ = phoenix_ProjectionType;
phoenix_ProjectionType.perspective = ["perspective",1];
phoenix_ProjectionType.perspective.toString = $estr;
phoenix_ProjectionType.perspective.__enum__ = phoenix_ProjectionType;
phoenix_ProjectionType.custom = ["custom",2];
phoenix_ProjectionType.custom.toString = $estr;
phoenix_ProjectionType.custom.__enum__ = phoenix_ProjectionType;
var phoenix_Camera = function(_options) {
	this._refresh_pos = false;
	this._setup = true;
	this.look_at_dirty = true;
	this.projection_dirty = true;
	this.transform_dirty = true;
	this.minimum_zoom = 0.01;
	this.aspect = 1.5;
	this.fov_type = phoenix_FOVType.horizontal;
	this.fov = 60;
	this.far = -1000;
	this.near = 1000;
	this.zoom = 1.0;
	this.name = "camera";
	this.transform = new phoenix_Transform();
	this.options = _options;
	if(this.options == null) this.options = this.default_camera_options();
	if(this.options.camera_name != null) this.name = this.options.camera_name;
	if(this.options.projection != null) this.projection = this.options.projection; else this.projection = phoenix_ProjectionType.ortho;
	this.set_center(new phoenix_Vector(Luxe.core.screen.w / 2,Luxe.core.screen.h / 2));
	this.set_pos(new phoenix_Vector());
	if(this.options.viewport != null) this.set_viewport(this.options.viewport); else this.set_viewport(new phoenix_Rectangle(0,0,Luxe.core.screen.w,Luxe.core.screen.h));
	this.up = new phoenix_Vector(0,1,0);
	this.projection_matrix = new phoenix_Matrix();
	this.view_matrix = new phoenix_Matrix();
	this.view_matrix_inverse = new phoenix_Matrix();
	this.look_at_matrix = new phoenix_Matrix();
	this.transform.listen($bind(this,this.on_transform_cleaned));
	this.apply_default_camera_options();
	var _g = this.projection;
	switch(_g[1]) {
	case 0:
		this.set_ortho(this.options);
		break;
	case 1:
		this.set_perspective(this.options);
		break;
	case 2:
		break;
	}
	this._setup = false;
};
phoenix_Camera.__name__ = true;
phoenix_Camera.prototype = {
	set_ortho: function(_options) {
		this.projection = phoenix_ProjectionType.ortho;
		this._merge_options(_options);
	}
	,set_perspective: function(_options) {
		this.projection = phoenix_ProjectionType.perspective;
		this._merge_options(_options);
		this.transform.origin.set_xyz(0,0,0);
	}
	,project: function(_vector) {
		this.update_view_matrix();
		var _transform = new phoenix_Matrix().multiplyMatrices(this.projection_matrix,this.view_matrix_inverse);
		return new phoenix_Vector(_vector.x,_vector.y,_vector.z,_vector.w).applyProjection(_transform);
	}
	,unproject: function(_vector) {
		this.update_view_matrix();
		var _inverted = new phoenix_Matrix().multiplyMatrices(this.projection_matrix,this.view_matrix_inverse);
		return new phoenix_Vector(_vector.x,_vector.y,_vector.z,_vector.w).applyProjection(_inverted.getInverse(_inverted));
	}
	,screen_point_to_ray: function(_vector) {
		return new phoenix_Ray(_vector,this);
	}
	,screen_point_to_world: function(_vector) {
		if(this.projection == phoenix_ProjectionType.ortho) return this.ortho_screen_to_world(_vector); else if(this.projection == phoenix_ProjectionType.perspective) return this.screen_point_to_ray(_vector).end;
		return this.ortho_screen_to_world(_vector);
	}
	,world_point_to_screen: function(_vector,_viewport) {
		if(this.projection == phoenix_ProjectionType.ortho) return this.ortho_world_to_screen(_vector); else if(this.projection == phoenix_ProjectionType.perspective) return this.persepective_world_to_screen(_vector,_viewport);
		return this.ortho_world_to_screen(_vector);
	}
	,process: function() {
		if(this.target != null) this.update_look_at();
		this.update_projection_matrix();
		this.update_view_matrix();
		this.apply_state(2884,this.options.cull_backfaces);
		this.apply_state(2929,this.options.depth_test);
	}
	,on_transform_cleaned: function(t) {
		this.transform_dirty = true;
	}
	,update_look_at: function() {
		if(this.look_at_dirty && this.target != null) {
			this.look_at_matrix.lookAt(this.target,this.get_pos(),this.up);
			this.get_rotation().setFromRotationMatrix(this.look_at_matrix);
		}
	}
	,update_view_matrix: function() {
		this.view_matrix = this.transform.get_world().get_matrix();
		if(!this.transform_dirty) return;
		this.view_matrix_inverse = this.view_matrix.inverse();
		this.view_inverse_float32array = this.view_matrix_inverse.float32array();
		this.transform_dirty = false;
	}
	,update_projection_matrix: function() {
		if(!this.projection_dirty) return;
		var _g = this.projection;
		switch(_g[1]) {
		case 1:
			this.projection_matrix.makePerspective(this.fov_y,this.aspect,this.near,this.far);
			break;
		case 0:
			this.projection_matrix.makeOrthographic(0,this.get_viewport().w,0,this.get_viewport().h,this.near,this.far);
			break;
		case 2:
			break;
		}
		this.projection_float32array = this.projection_matrix.float32array();
		this.projection_dirty = false;
	}
	,apply_state: function(state,value) {
		if(value) Luxe.renderer.state.enable(state); else Luxe.renderer.state.disable(state);
	}
	,apply_default_camera_options: function() {
		var _g = this.projection;
		switch(_g[1]) {
		case 0:
			this.options.cull_backfaces = false;
			this.options.depth_test = false;
			break;
		case 1:
			this.options.cull_backfaces = true;
			this.options.depth_test = true;
			break;
		case 2:
			break;
		}
	}
	,default_camera_options: function() {
		return { projection : phoenix_ProjectionType.ortho, depth_test : false, cull_backfaces : false, near : 1000, far : -1000};
	}
	,ortho_screen_to_world: function(_vector) {
		this.update_view_matrix();
		return new phoenix_Vector(_vector.x,_vector.y,_vector.z,_vector.w).transform(this.view_matrix);
	}
	,ortho_world_to_screen: function(_vector) {
		this.update_view_matrix();
		return new phoenix_Vector(_vector.x,_vector.y,_vector.z,_vector.w).transform(this.view_matrix_inverse);
	}
	,persepective_world_to_screen: function(_vector,_viewport) {
		if(_viewport == null) _viewport = this.get_viewport();
		var _projected = this.project(_vector);
		var width_half = _viewport.w / 2;
		var height_half = _viewport.h / 2;
		return new phoenix_Vector(_projected.x * width_half + width_half,-(_projected.y * height_half) + height_half);
	}
	,set_target: function(_target) {
		if(_target != null) this.look_at_dirty = true;
		return this.target = _target;
	}
	,set_fov: function(_fov) {
		this.projection_dirty = true;
		this.options.fov = _fov;
		if(this.fov_type == phoenix_FOVType.horizontal) this.fov_y = 180 / Math.PI * (2 * Math.atan(Math.tan(_fov * (Math.PI / 180) / 2) * (1 / this.aspect))); else this.fov_y = _fov;
		return this.fov = _fov;
	}
	,set_fov_type: function(_fov_type) {
		this.options.fov_type = _fov_type;
		this.fov_type = _fov_type;
		this.set_fov(this.fov);
		return this.fov_type;
	}
	,set_aspect: function(_aspect) {
		this.projection_dirty = true;
		this.options.aspect = _aspect;
		return this.aspect = _aspect;
	}
	,set_near: function(_near) {
		this.projection_dirty = true;
		this.options.near = _near;
		return this.near = _near;
	}
	,set_far: function(_far) {
		this.projection_dirty = true;
		this.options.far = _far;
		return this.far = _far;
	}
	,set_zoom: function(_z) {
		var _new_zoom = _z;
		if(_new_zoom < this.minimum_zoom) _new_zoom = this.minimum_zoom;
		var _g = this.projection;
		switch(_g[1]) {
		case 0:
			this.transform.local.scale.set_x(1 / _new_zoom);
			this.transform.local.scale.set_y(1 / _new_zoom);
			this.transform.local.scale.set_z(1 / _new_zoom);
			break;
		case 1:
			break;
		case 2:
			break;
		}
		return this.zoom = _new_zoom;
	}
	,set_center: function(_p) {
		this.center = _p;
		var _g = this.projection;
		switch(_g[1]) {
		case 0:
			if(!this._refresh_pos && !this._setup) {
				this.get_pos().ignore_listeners = true;
				this.get_pos().set_x(_p.x - this.get_viewport().w / 2);
				this.get_pos().set_y(_p.y - this.get_viewport().h / 2);
				this.get_pos().ignore_listeners = false;
			}
			break;
		case 1:
			break;
		case 2:
			break;
		}
		phoenix_Vector.Listen(this.get_center(),$bind(this,this._center_changed));
		return this.get_center();
	}
	,get_center: function() {
		return this.center;
	}
	,get_pos: function() {
		return this.pos;
	}
	,get_rotation: function() {
		return this.transform.local.rotation;
	}
	,get_scale: function() {
		return this.transform.local.scale;
	}
	,get_viewport: function() {
		return this.viewport;
	}
	,set_viewport: function(_r) {
		this.projection_dirty = true;
		this.viewport = _r;
		var _g = this.projection;
		switch(_g[1]) {
		case 0:
			this.transform.set_origin(new phoenix_Vector(_r.w / 2,_r.h / 2));
			this.set_pos(this.get_pos());
			break;
		case 1:
			break;
		case 2:
			break;
		}
		return this.get_viewport();
	}
	,set_rotation: function(_q) {
		return this.transform.local.set_rotation(_q);
	}
	,set_scale: function(_s) {
		return this.transform.local.set_scale(_s);
	}
	,set_pos: function(_p) {
		this.pos = _p;
		var _g = this.projection;
		switch(_g[1]) {
		case 0:
			var _cx = this.get_center().x;
			var _cy = this.get_center().y;
			if(this.get_viewport() != null) {
				_cx = _p.x + this.get_viewport().w / 2;
				_cy = _p.y + this.get_viewport().h / 2;
			}
			this._refresh_pos = true;
			this.get_center().ignore_listeners = true;
			this.get_center().set_x(_cx);
			this.get_center().set_y(_cy);
			this.get_center().ignore_listeners = false;
			this._refresh_pos = false;
			this.transform.local.pos.set_x(_cx);
			this.transform.local.pos.set_y(_cy);
			break;
		case 1:
			this.transform.set_pos(this.get_pos());
			break;
		case 2:
			break;
		}
		phoenix_Vector.Listen(this.get_pos(),$bind(this,this._pos_changed));
		return this.get_pos();
	}
	,_merge_options: function(_options) {
		if(_options.aspect != null) {
			this.options.aspect = _options.aspect;
			this.set_aspect(this.options.aspect);
		}
		if(_options.far != null) {
			this.options.far = _options.far;
			this.set_far(this.options.far);
		}
		if(_options.fov != null) {
			this.options.fov = _options.fov;
			this.set_fov(this.options.fov);
		}
		if(_options.fov_type != null) {
			this.options.fov_type = _options.fov_type;
			this.set_fov_type(_options.fov_type);
		} else {
			this.options.fov_type = phoenix_FOVType.horizontal;
			this.set_fov_type(phoenix_FOVType.horizontal);
		}
		if(_options.near != null) {
			this.options.near = _options.near;
			this.set_near(this.options.near);
		}
		if(_options.viewport != null) {
			this.options.viewport = _options.viewport;
			this.set_viewport(this.options.viewport);
		}
		this.apply_default_camera_options();
		if(_options.cull_backfaces != null) this.options.cull_backfaces = _options.cull_backfaces;
		if(_options.depth_test != null) this.options.depth_test = _options.depth_test;
	}
	,_pos_changed: function(v) {
		this.set_pos(this.get_pos());
	}
	,_center_changed: function(v) {
		this.set_center(this.get_center());
	}
	,__class__: phoenix_Camera
	,__properties__: {set_rotation:"set_rotation",get_rotation:"get_rotation",set_scale:"set_scale",get_scale:"get_scale",set_pos:"set_pos",get_pos:"get_pos",set_target:"set_target",set_aspect:"set_aspect",set_fov_type:"set_fov_type",set_fov:"set_fov",set_far:"set_far",set_near:"set_near",set_zoom:"set_zoom",set_center:"set_center",get_center:"get_center",set_viewport:"set_viewport",get_viewport:"get_viewport"}
};
var phoenix_FOVType = { __ename__ : true, __constructs__ : ["vertical","horizontal"] };
phoenix_FOVType.vertical = ["vertical",0];
phoenix_FOVType.vertical.toString = $estr;
phoenix_FOVType.vertical.__enum__ = phoenix_FOVType;
phoenix_FOVType.horizontal = ["horizontal",1];
phoenix_FOVType.horizontal.toString = $estr;
phoenix_FOVType.horizontal.__enum__ = phoenix_FOVType;
var phoenix_Circle = function(_x,_y,_r) {
	if(_r == null) _r = 0;
	if(_y == null) _y = 0;
	if(_x == null) _x = 0;
	this.x = _x;
	this.y = _y;
	this.r = _r;
};
phoenix_Circle.__name__ = true;
phoenix_Circle.prototype = {
	toString: function() {
		return "{ x:" + this.x + ", y:" + this.y + ", r:" + this.r + " }";
	}
	,point_inside: function(_p) {
		var diff = new phoenix_Vector(_p.x - this.x,_p.y - this.y);
		return Math.sqrt(diff.x * diff.x + diff.y * diff.y + diff.z * diff.z) <= this.r;
	}
	,clone: function() {
		return new phoenix_Circle(this.x,this.y,this.r);
	}
	,set: function(_x,_y,_r) {
		var _setx = this.x;
		var _sety = this.y;
		var _setr = this.r;
		if(_x != null) _setx = _x;
		if(_y != null) _sety = _y;
		if(_r != null) _setr = _r;
		this.x = _setx;
		this.y = _sety;
		this.r = _setr;
		return this;
	}
	,__class__: phoenix_Circle
};
var phoenix_Color = function(_r,_g,_b,_a) {
	if(_a == null) _a = 1.0;
	if(_b == null) _b = 1.0;
	if(_g == null) _g = 1.0;
	if(_r == null) _r = 1.0;
	this.refreshing = false;
	this.is_hsv = false;
	this.is_hsl = false;
	this.a = 1.0;
	this.b = 1.0;
	this.g = 1.0;
	this.r = 1.0;
	this.set_r(_r);
	this.set_g(_g);
	this.set_b(_b);
	this.a = _a;
};
phoenix_Color.__name__ = true;
phoenix_Color.random = function(_include_alpha) {
	if(_include_alpha == null) _include_alpha = false;
	return new phoenix_Color(Math.random(),Math.random(),Math.random(),_include_alpha?Math.random():1.0);
};
phoenix_Color.prototype = {
	set_r: function(_r) {
		this.r = _r;
		if(!this.refreshing) {
			if(this.is_hsl) {
				var colorhsl = this;
				colorhsl.fromColor(this);
			} else if(this.is_hsv) {
				var colorhsv = this;
				colorhsv.fromColor(this);
			}
		}
		return this.r;
	}
	,set_g: function(_g) {
		this.g = _g;
		if(!this.refreshing) {
			if(this.is_hsl) {
				var colorhsl = this;
				colorhsl.fromColor(this);
			} else if(this.is_hsv) {
				var colorhsv = this;
				colorhsv.fromColor(this);
			}
		}
		return this.g;
	}
	,set_b: function(_b) {
		this.b = _b;
		if(!this.refreshing) {
			if(this.is_hsl) {
				var colorhsl = this;
				colorhsl.fromColor(this);
			} else if(this.is_hsv) {
				var colorhsv = this;
				colorhsv.fromColor(this);
			}
		}
		return this.b;
	}
	,set: function(_r,_g,_b,_a) {
		var _setr = this.r;
		var _setg = this.g;
		var _setb = this.b;
		var _seta = this.a;
		if(_r != null) _setr = _r;
		if(_g != null) _setg = _g;
		if(_b != null) _setb = _b;
		if(_a != null) _seta = _a;
		this.set_r(_setr);
		this.set_g(_setg);
		this.set_b(_setb);
		this.a = _seta;
		return this;
	}
	,maxRGB: function() {
		return Math.max(this.r,Math.max(this.g,this.b));
	}
	,minRGB: function() {
		return Math.min(this.r,Math.min(this.g,this.b));
	}
	,tween: function(_time_in_seconds,_properties_to_tween,_override) {
		if(_override == null) _override = true;
		if(_time_in_seconds == null) _time_in_seconds = 0.5;
		if(_properties_to_tween != null) {
			var _dest_r = this.r;
			var _dest_g = this.g;
			var _dest_b = this.b;
			var _dest_a = this.a;
			var _change_r = false;
			var _change_g = false;
			var _change_b = false;
			var _change_a = false;
			if(js_Boot.__instanceof(_properties_to_tween,phoenix_Color)) {
				_dest_r = _properties_to_tween.r;
				_dest_g = _properties_to_tween.g;
				_dest_b = _properties_to_tween.b;
				_dest_a = _properties_to_tween.a;
				_change_r = true;
				_change_g = true;
				_change_b = true;
				_change_a = true;
			} else {
				if(_properties_to_tween.r != null) {
					_dest_r = _properties_to_tween.r;
					_change_r = true;
				}
				if(_properties_to_tween.g != null) {
					_dest_g = _properties_to_tween.g;
					_change_g = true;
				}
				if(_properties_to_tween.b != null) {
					_dest_b = _properties_to_tween.b;
					_change_b = true;
				}
				if(_properties_to_tween.a != null) {
					_dest_a = _properties_to_tween.a;
					_change_a = true;
				}
			}
			var _properties = { };
			if(_change_r) _properties.r = _dest_r;
			if(_change_g) _properties.g = _dest_g;
			if(_change_b) _properties.b = _dest_b;
			if(_change_a) _properties.a = _dest_a;
			return luxe_tween_Actuate.tween(this,_time_in_seconds,_properties,_override);
		} else throw new js__$Boot_HaxeError(" Warning: Color.tween passed a null destination ");
	}
	,clone: function() {
		return new phoenix_Color(this.r,this.g,this.b,this.a);
	}
	,rgb: function(_rgb) {
		if(_rgb == null) _rgb = 16777215;
		this.from_int(_rgb);
		return this;
	}
	,toColorHSL: function() {
		return new phoenix_ColorHSL().fromColor(this);
	}
	,toColorHSV: function() {
		return new phoenix_ColorHSV().fromColor(this);
	}
	,fromColorHSV: function(_color_hsv) {
		var d = _color_hsv.h % 360 / 60;
		if(d < 0) d += 6;
		var hf = Math.floor(d);
		var hi = hf % 6;
		var f = d - hf;
		var v = _color_hsv.v;
		var p = _color_hsv.v * (1 - _color_hsv.s);
		var q = _color_hsv.v * (1 - f * _color_hsv.s);
		var t = _color_hsv.v * (1 - (1 - f) * _color_hsv.s);
		switch(hi) {
		case 0:
			this.set_r(v);
			this.set_g(t);
			this.set_b(p);
			break;
		case 1:
			this.set_r(q);
			this.set_g(v);
			this.set_b(p);
			break;
		case 2:
			this.set_r(p);
			this.set_g(v);
			this.set_b(t);
			break;
		case 3:
			this.set_r(p);
			this.set_g(q);
			this.set_b(v);
			break;
		case 4:
			this.set_r(t);
			this.set_g(p);
			this.set_b(v);
			break;
		case 5:
			this.set_r(v);
			this.set_g(p);
			this.set_b(q);
			break;
		}
		this.a = _color_hsv.a;
	}
	,fromColorHSL: function(_color_hsl) {
		var q = 1;
		if(_color_hsl.l < 0.5) q = _color_hsl.l * (1 + _color_hsl.s); else q = _color_hsl.l + _color_hsl.s - _color_hsl.l * _color_hsl.s;
		var p = 2 * _color_hsl.l - q;
		var hk = _color_hsl.h % 360 / 360;
		var tr = hk + 0.33333333333333331;
		var tg = hk;
		var tb = hk - 0.33333333333333331;
		var tc = [tr,tg,tb];
		var _g1 = 0;
		var _g = tc.length;
		while(_g1 < _g) {
			var n = _g1++;
			var t = tc[n];
			if(t < 0) t += 1;
			if(t > 1) t -= 1;
			if(t < 0.16666666666666666) tc[n] = p + (q - p) * 6 * t; else if(t < 0.5) tc[n] = q; else if(t < 0.66666666666666663) tc[n] = p + (q - p) * 6 * (0.66666666666666663 - t); else tc[n] = p;
		}
		this.set_r(tc[0]);
		this.set_g(tc[1]);
		this.set_b(tc[2]);
		this.a = _color_hsl.a;
		return this;
	}
	,toString: function() {
		return "{ r:" + this.r + " , g:" + this.g + " , b:" + this.b + " , a:" + this.a + " }";
	}
	,from_int: function(_i) {
		var _r = _i >> 16;
		var _g = _i >> 8 & 255;
		var _b = _i & 255;
		this.set_r(_r / 255);
		this.set_g(_g / 255);
		this.set_b(_b / 255);
	}
	,__class__: phoenix_Color
	,__properties__: {set_b:"set_b",set_g:"set_g",set_r:"set_r"}
};
var phoenix_ColorHSL = function(_h,_s,_l,_a) {
	if(_a == null) _a = 1.0;
	if(_l == null) _l = 1.0;
	if(_s == null) _s = 1.0;
	if(_h == null) _h = 0.0;
	this.l = 1.0;
	this.s = 1.0;
	this.h = 0.0;
	phoenix_Color.call(this);
	this.is_hsl = true;
	this.set_h(_h);
	this.set_s(_s);
	this.set_l(_l);
	this.a = _a;
	this._refresh();
};
phoenix_ColorHSL.__name__ = true;
phoenix_ColorHSL.__super__ = phoenix_Color;
phoenix_ColorHSL.prototype = $extend(phoenix_Color.prototype,{
	set_h: function(_h) {
		this.h = _h;
		this._refresh();
		return _h;
	}
	,set_s: function(_s) {
		this.s = _s;
		this._refresh();
		return _s;
	}
	,set_l: function(_l) {
		this.l = _l;
		this._refresh();
		return _l;
	}
	,set: function(_h,_s,_l,_a) {
		var _seth = this.h;
		var _sets = this.s;
		var _setl = this.l;
		var _seta = this.a;
		if(_h != null) _seth = _h;
		if(_s != null) _sets = _s;
		if(_l != null) _setl = _l;
		if(_a != null) _seta = _a;
		this.set_h(_seth);
		this.set_s(_sets);
		this.set_l(_setl);
		this.a = _seta;
		this._refresh();
		return this;
	}
	,tween: function(_time_in_seconds,_dest,_override) {
		if(_override == null) _override = true;
		if(_time_in_seconds == null) _time_in_seconds = 0.5;
		phoenix_Color.prototype.tween.call(this,_time_in_seconds,_dest,_override);
		if(_dest != null) {
			var _dest_h = this.h;
			var _dest_s = this.s;
			var _dest_l = this.l;
			var _dest_a = this.a;
			var _change_h = false;
			var _change_s = false;
			var _change_l = false;
			var _change_a = false;
			if(js_Boot.__instanceof(_dest,phoenix_ColorHSL)) {
				_dest_h = _dest.h;
				_dest_s = _dest.s;
				_dest_l = _dest.l;
				_dest_a = _dest.a;
				_change_h = true;
				_change_s = true;
				_change_l = true;
				_change_a = true;
			} else {
				if(_dest.h != null) {
					_dest_h = _dest.h;
					_change_h = true;
				}
				if(_dest.s != null) {
					_dest_s = _dest.s;
					_change_s = true;
				}
				if(_dest.l != null) {
					_dest_l = _dest.l;
					_change_l = true;
				}
				if(_dest.a != null) {
					_dest_a = _dest.a;
					_change_a = true;
				}
			}
			var _properties = { };
			if(_change_h) _properties.h = _dest_h;
			if(_change_s) _properties.s = _dest_s;
			if(_change_l) _properties.l = _dest_l;
			if(_change_a) _properties.a = _dest_a;
			return luxe_tween_Actuate.tween(this,_time_in_seconds,_properties,_override);
		} else throw new js__$Boot_HaxeError(" Warning: Color.tween passed a null destination ");
	}
	,_refresh: function() {
		this.refreshing = true;
		phoenix_Color.prototype.fromColorHSL.call(this,this);
		this.refreshing = false;
		return this;
	}
	,clone: function() {
		return new phoenix_ColorHSL(this.h,this.s,this.l,this.a);
	}
	,toColor: function() {
		return this._refresh();
	}
	,fromColor: function(_color) {
		var max = _color.maxRGB();
		var min = _color.minRGB();
		var add = max + min;
		var sub = max - min;
		var _h = 0;
		if(max == min) _h = 0; else if(max == _color.r) _h = (60 * (_color.g - _color.b) / sub + 360) % 360; else if(max == _color.g) _h = 60 * (_color.b - _color.r) / sub + 120; else if(max == _color.b) _h = 60 * (_color.r - _color.g) / sub + 240;
		var _l = add / 2;
		var _s;
		if(max == min) _s = 0; else if(this.l <= 0.5) _s = sub / add; else _s = sub / (2 - add);
		this.set_h(_h);
		this.set_s(_s);
		this.set_l(_l);
		this.a = _color.a;
		return this;
	}
	,toString: function() {
		return "{ h:" + this.h + " , s:" + this.s + " , l:" + this.l + " , a:" + this.a + " }";
	}
	,__class__: phoenix_ColorHSL
	,__properties__: $extend(phoenix_Color.prototype.__properties__,{set_l:"set_l",set_s:"set_s",set_h:"set_h"})
});
var phoenix_ColorHSV = function(_h,_s,_v,_a) {
	if(_a == null) _a = 1.0;
	if(_v == null) _v = 1.0;
	if(_s == null) _s = 0.0;
	if(_h == null) _h = 0.0;
	this.v = 1.0;
	this.s = 0.0;
	this.h = 0.0;
	phoenix_Color.call(this);
	this.is_hsv = true;
	this.set_h(_h);
	this.set_s(_s);
	this.set_v(_v);
	this.a = _a;
	this._refresh();
};
phoenix_ColorHSV.__name__ = true;
phoenix_ColorHSV.__super__ = phoenix_Color;
phoenix_ColorHSV.prototype = $extend(phoenix_Color.prototype,{
	set_h: function(_h) {
		this.h = _h;
		this._refresh();
		return _h;
	}
	,set_s: function(_s) {
		this.s = _s;
		this._refresh();
		return this.s;
	}
	,set_v: function(_v) {
		this.v = _v;
		this._refresh();
		return this.v;
	}
	,set: function(_h,_s,_v,_a) {
		var _seth = this.h;
		var _sets = this.s;
		var _setv = this.v;
		var _seta = this.a;
		if(_h != null) _seth = _h;
		if(_s != null) _sets = _s;
		if(_v != null) _setv = _v;
		if(_a != null) _seta = _a;
		this.set_h(_seth);
		this.set_s(_sets);
		this.set_v(_setv);
		this.a = _seta;
		this._refresh();
		return this;
	}
	,tween: function(_time_in_seconds,_dest,_override) {
		if(_override == null) _override = true;
		if(_time_in_seconds == null) _time_in_seconds = 0.5;
		phoenix_Color.prototype.tween.call(this,_time_in_seconds,_dest,_override);
		if(_dest != null) {
			var _dest_h = this.h;
			var _dest_s = this.s;
			var _dest_v = this.v;
			var _dest_a = this.a;
			var _change_h = false;
			var _change_s = false;
			var _change_v = false;
			var _change_a = false;
			if(js_Boot.__instanceof(_dest,phoenix_ColorHSV)) {
				_dest_h = _dest.h;
				_dest_s = _dest.s;
				_dest_v = _dest.v;
				_dest_a = _dest.a;
				_change_h = true;
				_change_s = true;
				_change_v = true;
				_change_a = true;
			} else {
				if(_dest.h != null) {
					_dest_h = _dest.h;
					_change_h = true;
				}
				if(_dest.s != null) {
					_dest_s = _dest.s;
					_change_s = true;
				}
				if(_dest.v != null) {
					_dest_v = _dest.v;
					_change_v = true;
				}
				if(_dest.a != null) {
					_dest_a = _dest.a;
					_change_a = true;
				}
			}
			var _properties = { };
			if(_change_h) _properties.h = _dest_h;
			if(_change_s) _properties.s = _dest_s;
			if(_change_v) _properties.v = _dest_v;
			if(_change_a) _properties.a = _dest_a;
			return luxe_tween_Actuate.tween(this,_time_in_seconds,_properties,_override);
		} else throw new js__$Boot_HaxeError(" Warning: Color.tween passed a null destination ");
	}
	,_refresh: function() {
		this.refreshing = true;
		phoenix_Color.prototype.fromColorHSV.call(this,this);
		this.refreshing = false;
		return this;
	}
	,clone: function() {
		return new phoenix_ColorHSV(this.h,this.s,this.v,this.a);
	}
	,toColor: function() {
		return this._refresh();
	}
	,toColorHSL: function() {
		this._refresh();
		return phoenix_Color.prototype.toColorHSL.call(this);
	}
	,fromColorHSL: function(_color_hsl) {
		_color_hsl._refresh();
		return this.fromColor(_color_hsl);
	}
	,fromColor: function(_color) {
		var max = _color.maxRGB();
		var min = _color.minRGB();
		var add = max + min;
		var sub = max - min;
		var _h = 0;
		if(max == min) _h = 0; else if(max == _color.r) _h = (60 * (_color.g - _color.b) / sub + 360) % 360; else if(max == _color.g) _h = 60 * (_color.b - _color.r) / sub + 120; else if(max == _color.b) _h = 60 * (_color.r - _color.g) / sub + 240;
		var _s;
		if(max == 0) _s = 0; else _s = 1 - min / max;
		this.set_h(_h);
		this.set_s(_s);
		this.set_v(max);
		this.a = _color.a;
		return this;
	}
	,toString: function() {
		return "{ h:" + this.h + " , s:" + this.s + " , v:" + this.v + " , a:" + this.a + " }";
	}
	,__class__: phoenix_ColorHSV
	,__properties__: $extend(phoenix_Color.prototype.__properties__,{set_v:"set_v",set_s:"set_s",set_h:"set_h"})
});
var phoenix_MatrixTransform = function(p,r,s) {
	this.pos = p;
	this.rotation = r;
	this.scale = s;
};
phoenix_MatrixTransform.__name__ = true;
phoenix_MatrixTransform.prototype = {
	destroy: function() {
		this.pos = null;
		this.rotation = null;
		this.scale = null;
	}
	,__class__: phoenix_MatrixTransform
};
var phoenix_Matrix = function(n11,n12,n13,n14,n21,n22,n23,n24,n31,n32,n33,n34,n41,n42,n43,n44) {
	if(n44 == null) n44 = 1;
	if(n43 == null) n43 = 0;
	if(n42 == null) n42 = 0;
	if(n41 == null) n41 = 0;
	if(n34 == null) n34 = 0;
	if(n33 == null) n33 = 1;
	if(n32 == null) n32 = 0;
	if(n31 == null) n31 = 0;
	if(n24 == null) n24 = 0;
	if(n23 == null) n23 = 0;
	if(n22 == null) n22 = 1;
	if(n21 == null) n21 = 0;
	if(n14 == null) n14 = 0;
	if(n13 == null) n13 = 0;
	if(n12 == null) n12 = 0;
	if(n11 == null) n11 = 1;
	this.M44 = 1;
	this.M34 = 0;
	this.M24 = 0;
	this.M14 = 0;
	this.M43 = 0;
	this.M33 = 1;
	this.M23 = 0;
	this.M13 = 0;
	this.M42 = 0;
	this.M32 = 0;
	this.M22 = 1;
	this.M12 = 0;
	this.M41 = 0;
	this.M31 = 0;
	this.M21 = 0;
	this.M11 = 1;
	this.elements = [];
	var i = 0;
	while(i++ < 16) this.elements.push(0.0);
	this.set(n11,n12,n13,n14,n21,n22,n23,n24,n31,n32,n33,n34,n41,n42,n43,n44);
	var array = this.elements;
	var len = null;
	var this1;
	if(array != null) this1 = new Float32Array(array); else this1 = null;
	this._float32array = this1;
};
phoenix_Matrix.__name__ = true;
phoenix_Matrix.prototype = {
	set: function(n11,n12,n13,n14,n21,n22,n23,n24,n31,n32,n33,n34,n41,n42,n43,n44) {
		var e = this.elements;
		e[0] = n11;
		e[4] = n12;
		e[8] = n13;
		e[12] = n14;
		e[1] = n21;
		e[5] = n22;
		e[9] = n23;
		e[13] = n24;
		e[2] = n31;
		e[6] = n32;
		e[10] = n33;
		e[14] = n34;
		e[3] = n41;
		e[7] = n42;
		e[11] = n43;
		e[15] = n44;
		return this;
	}
	,toString: function() {
		var e = this.elements;
		var str = "{ 11:" + luxe_utils_Maths.fixed(e[0],3) + ", 12:" + luxe_utils_Maths.fixed(e[4],3) + ", 13:" + luxe_utils_Maths.fixed(e[8],3) + ", 14:" + luxe_utils_Maths.fixed(e[12],3) + " }, " + "{ 21:" + luxe_utils_Maths.fixed(e[1],3) + ", 22:" + luxe_utils_Maths.fixed(e[5],3) + ", 23:" + luxe_utils_Maths.fixed(e[9],3) + ", 24:" + luxe_utils_Maths.fixed(e[13],3) + " }, " + "{ 31:" + luxe_utils_Maths.fixed(e[2],3) + ", 32:" + luxe_utils_Maths.fixed(e[6],3) + ", 33:" + luxe_utils_Maths.fixed(e[10],3) + ", 34:" + luxe_utils_Maths.fixed(e[14],3) + " }, " + "{ 41:" + luxe_utils_Maths.fixed(e[3],3) + ", 42:" + luxe_utils_Maths.fixed(e[7],3) + ", 43:" + luxe_utils_Maths.fixed(e[11],3) + ", 44:" + luxe_utils_Maths.fixed(e[15],3) + " }";
		return str;
	}
	,get_M11: function() {
		return this.elements[0];
	}
	,get_M12: function() {
		return this.elements[1];
	}
	,get_M13: function() {
		return this.elements[2];
	}
	,get_M14: function() {
		return this.elements[3];
	}
	,get_M21: function() {
		return this.elements[4];
	}
	,get_M22: function() {
		return this.elements[5];
	}
	,get_M23: function() {
		return this.elements[6];
	}
	,get_M24: function() {
		return this.elements[7];
	}
	,get_M31: function() {
		return this.elements[8];
	}
	,get_M32: function() {
		return this.elements[9];
	}
	,get_M33: function() {
		return this.elements[10];
	}
	,get_M34: function() {
		return this.elements[11];
	}
	,get_M41: function() {
		return this.elements[12];
	}
	,get_M42: function() {
		return this.elements[13];
	}
	,get_M43: function() {
		return this.elements[14];
	}
	,get_M44: function() {
		return this.elements[15];
	}
	,set_M11: function(_value) {
		this.elements[0] = _value;
		return _value;
	}
	,set_M12: function(_value) {
		this.elements[1] = _value;
		return _value;
	}
	,set_M13: function(_value) {
		this.elements[2] = _value;
		return _value;
	}
	,set_M14: function(_value) {
		this.elements[3] = _value;
		return _value;
	}
	,set_M21: function(_value) {
		this.elements[4] = _value;
		return _value;
	}
	,set_M22: function(_value) {
		this.elements[5] = _value;
		return _value;
	}
	,set_M23: function(_value) {
		this.elements[6] = _value;
		return _value;
	}
	,set_M24: function(_value) {
		this.elements[7] = _value;
		return _value;
	}
	,set_M31: function(_value) {
		this.elements[8] = _value;
		return _value;
	}
	,set_M32: function(_value) {
		this.elements[9] = _value;
		return _value;
	}
	,set_M33: function(_value) {
		this.elements[10] = _value;
		return _value;
	}
	,set_M34: function(_value) {
		this.elements[11] = _value;
		return _value;
	}
	,set_M41: function(_value) {
		this.elements[12] = _value;
		return _value;
	}
	,set_M42: function(_value) {
		this.elements[13] = _value;
		return _value;
	}
	,set_M43: function(_value) {
		this.elements[14] = _value;
		return _value;
	}
	,set_M44: function(_value) {
		this.elements[15] = _value;
		return _value;
	}
	,float32array: function() {
		var array = this.elements;
		var len = null;
		var this1;
		if(array != null) this1 = new Float32Array(array); else this1 = null;
		return this1;
	}
	,identity: function() {
		this.set(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1);
		return this;
	}
	,copy: function(m) {
		var me = m.elements;
		this.set(me[0],me[4],me[8],me[12],me[1],me[5],me[9],me[13],me[2],me[6],me[10],me[14],me[3],me[7],me[11],me[15]);
		return this;
	}
	,make2D: function(_x,_y,_scale,_rotation) {
		if(_rotation == null) _rotation = 0;
		if(_scale == null) _scale = 1;
		var theta = _rotation * 0.017453292519943278;
		var c = Math.cos(theta);
		var s = Math.sin(theta);
		this.set(c * _scale,s * _scale,0,_x,-s * _scale,c * _scale,0,_y,0,0,1,0,0,0,0,1);
		return this;
	}
	,copyPosition: function(m) {
		this.elements[12] = m.elements[12];
		this.elements[13] = m.elements[13];
		this.elements[14] = m.elements[14];
		return this;
	}
	,getPosition: function() {
		return new phoenix_Vector(this.elements[12],this.elements[13],this.elements[14],1);
	}
	,extractRotation: function(m) {
		var _temp = new phoenix_Vector();
		var me = m.elements;
		var _scale_x = 1 / _temp.set_xyz(me[0],me[1],me[2]).get_length();
		var _scale_y = 1 / _temp.set_xyz(me[4],me[5],me[6]).get_length();
		var _scale_z = 1 / _temp.set_xyz(me[8],me[9],me[10]).get_length();
		this.elements[0] = me[0] * _scale_x;
		this.elements[1] = me[1] * _scale_x;
		this.elements[2] = me[2] * _scale_x;
		this.elements[4] = me[4] * _scale_y;
		this.elements[5] = me[5] * _scale_y;
		this.elements[6] = me[6] * _scale_y;
		this.elements[8] = me[8] * _scale_z;
		this.elements[9] = me[9] * _scale_z;
		this.elements[10] = me[10] * _scale_z;
		return this;
	}
	,makeRotationFromEuler: function(_v,_order) {
		if(_order == null) _order = 0;
		var te = this.elements;
		var x = _v.x;
		var y = _v.y;
		var z = _v.z;
		var a = Math.cos(x);
		var b = Math.sin(x);
		var c = Math.cos(y);
		var d = Math.sin(y);
		var e = Math.cos(z);
		var f = Math.sin(z);
		if(_order == 0) {
			var ae = a * e;
			var af = a * f;
			var be = b * e;
			var bf = b * f;
			te[0] = c * e;
			te[4] = -c * f;
			te[8] = d;
			te[1] = af + be * d;
			te[5] = ae - bf * d;
			te[9] = -b * c;
			te[2] = bf - ae * d;
			te[6] = be + af * d;
			te[10] = a * c;
		} else if(_order == 1) {
			var ce = c * e;
			var cf = c * f;
			var de = d * e;
			var df = d * f;
			te[0] = ce + df * b;
			te[4] = de * b - cf;
			te[8] = a * d;
			te[1] = a * f;
			te[5] = a * e;
			te[9] = -b;
			te[2] = cf * b - de;
			te[6] = df + ce * b;
			te[10] = a * c;
		} else if(_order == 2) {
			var ce1 = c * e;
			var cf1 = c * f;
			var de1 = d * e;
			var df1 = d * f;
			te[0] = ce1 - df1 * b;
			te[4] = -a * f;
			te[8] = de1 + cf1 * b;
			te[1] = cf1 + de1 * b;
			te[5] = a * e;
			te[9] = df1 - ce1 * b;
			te[2] = -a * d;
			te[6] = b;
			te[10] = a * c;
		} else if(_order == 3) {
			var ae1 = a * e;
			var af1 = a * f;
			var be1 = b * e;
			var bf1 = b * f;
			te[0] = c * e;
			te[4] = be1 * d - af1;
			te[8] = ae1 * d + bf1;
			te[1] = c * f;
			te[5] = bf1 * d + ae1;
			te[9] = af1 * d - be1;
			te[2] = -d;
			te[6] = b * c;
			te[10] = a * c;
		} else if(_order == 4) {
			var ac = a * c;
			var ad = a * d;
			var bc = b * c;
			var bd = b * d;
			te[0] = c * e;
			te[4] = bd - ac * f;
			te[8] = bc * f + ad;
			te[1] = f;
			te[5] = a * e;
			te[9] = -b * e;
			te[2] = -d * e;
			te[6] = ad * f + bc;
			te[10] = ac - bd * f;
		} else if(_order == 5) {
			var ac1 = a * c;
			var ad1 = a * d;
			var bc1 = b * c;
			var bd1 = b * d;
			te[0] = c * e;
			te[4] = -f;
			te[8] = d * e;
			te[1] = ac1 * f + bd1;
			te[5] = a * e;
			te[9] = ad1 * f - bc1;
			te[2] = bc1 * f - ad1;
			te[6] = b * e;
			te[10] = bd1 * f + ac1;
		}
		te[3] = 0;
		te[7] = 0;
		te[11] = 0;
		te[12] = 0;
		te[13] = 0;
		te[14] = 0;
		te[15] = 1;
		return this;
	}
	,makeRotationFromQuaternion: function(q) {
		var te = this.elements;
		var x2 = q.x + q.x;
		var y2 = q.y + q.y;
		var z2 = q.z + q.z;
		var xx = q.x * x2;
		var xy = q.x * y2;
		var xz = q.x * z2;
		var yy = q.y * y2;
		var yz = q.y * z2;
		var zz = q.z * z2;
		var wx = q.w * x2;
		var wy = q.w * y2;
		var wz = q.w * z2;
		te[0] = 1 - (yy + zz);
		te[4] = xy - wz;
		te[8] = xz + wy;
		te[1] = xy + wz;
		te[5] = 1 - (xx + zz);
		te[9] = yz - wx;
		te[2] = xz - wy;
		te[6] = yz + wx;
		te[10] = 1 - (xx + yy);
		te[3] = 0;
		te[7] = 0;
		te[11] = 0;
		te[12] = 0;
		te[13] = 0;
		te[14] = 0;
		te[15] = 1;
		return this;
	}
	,lookAt: function(_eye,_target,_up) {
		var _x = new phoenix_Vector();
		var _y = new phoenix_Vector();
		var _z = new phoenix_Vector();
		var te = this.elements;
		_z = new phoenix_Vector(_target.x - _eye.x,_target.y - _eye.y,_target.z - _eye.z).get_normalized();
		if(Math.sqrt(_z.x * _z.x + _z.y * _z.y + _z.z * _z.z) == 0) {
			_z.z = 1;
			if(_z._construct) _z.z; else {
				if(_z.listen_z != null && !_z.ignore_listeners) _z.listen_z(1);
				_z.z;
			}
		}
		_x = new phoenix_Vector(_up.y * _z.z - _up.z * _z.y,_up.z * _z.x - _up.x * _z.z,_up.x * _z.y - _up.y * _z.x).get_normalized();
		if(Math.sqrt(_x.x * _x.x + _x.y * _x.y + _x.z * _x.z) == 0) {
			var _g = _z;
			_g.set_x(_g.x + 0.0001);
			_x = new phoenix_Vector(_up.y * _z.z - _up.z * _z.y,_up.z * _z.x - _up.x * _z.z,_up.x * _z.y - _up.y * _z.x).get_normalized();
		}
		_y = new phoenix_Vector(_z.y * _x.z - _z.z * _x.y,_z.z * _x.x - _z.x * _x.z,_z.x * _x.y - _z.y * _x.x);
		te[0] = _x.x;
		te[4] = _y.x;
		te[8] = _z.x;
		te[1] = _x.y;
		te[5] = _y.y;
		te[9] = _z.y;
		te[2] = _x.z;
		te[6] = _y.z;
		te[10] = _z.z;
		return this;
	}
	,multiply: function(_m) {
		return this.multiplyMatrices(this,_m);
	}
	,multiplyMatrices: function(_a,_b) {
		var ae = _a.elements;
		var be = _b.elements;
		var te = this.elements;
		var a11 = ae[0];
		var a12 = ae[4];
		var a13 = ae[8];
		var a14 = ae[12];
		var a21 = ae[1];
		var a22 = ae[5];
		var a23 = ae[9];
		var a24 = ae[13];
		var a31 = ae[2];
		var a32 = ae[6];
		var a33 = ae[10];
		var a34 = ae[14];
		var a41 = ae[3];
		var a42 = ae[7];
		var a43 = ae[11];
		var a44 = ae[15];
		var b11 = be[0];
		var b12 = be[4];
		var b13 = be[8];
		var b14 = be[12];
		var b21 = be[1];
		var b22 = be[5];
		var b23 = be[9];
		var b24 = be[13];
		var b31 = be[2];
		var b32 = be[6];
		var b33 = be[10];
		var b34 = be[14];
		var b41 = be[3];
		var b42 = be[7];
		var b43 = be[11];
		var b44 = be[15];
		te[0] = a11 * b11 + a12 * b21 + a13 * b31 + a14 * b41;
		te[4] = a11 * b12 + a12 * b22 + a13 * b32 + a14 * b42;
		te[8] = a11 * b13 + a12 * b23 + a13 * b33 + a14 * b43;
		te[12] = a11 * b14 + a12 * b24 + a13 * b34 + a14 * b44;
		te[1] = a21 * b11 + a22 * b21 + a23 * b31 + a24 * b41;
		te[5] = a21 * b12 + a22 * b22 + a23 * b32 + a24 * b42;
		te[9] = a21 * b13 + a22 * b23 + a23 * b33 + a24 * b43;
		te[13] = a21 * b14 + a22 * b24 + a23 * b34 + a24 * b44;
		te[2] = a31 * b11 + a32 * b21 + a33 * b31 + a34 * b41;
		te[6] = a31 * b12 + a32 * b22 + a33 * b32 + a34 * b42;
		te[10] = a31 * b13 + a32 * b23 + a33 * b33 + a34 * b43;
		te[14] = a31 * b14 + a32 * b24 + a33 * b34 + a34 * b44;
		te[3] = a41 * b11 + a42 * b21 + a43 * b31 + a44 * b41;
		te[7] = a41 * b12 + a42 * b22 + a43 * b32 + a44 * b42;
		te[11] = a41 * b13 + a42 * b23 + a43 * b33 + a44 * b43;
		te[15] = a41 * b14 + a42 * b24 + a43 * b34 + a44 * b44;
		return this;
	}
	,multiplyToArray: function(_a,_b,_r) {
		var te = this.elements;
		this.multiplyMatrices(_a,_b);
		_r[0] = te[0];
		_r[1] = te[1];
		_r[2] = te[2];
		_r[3] = te[3];
		_r[4] = te[4];
		_r[5] = te[5];
		_r[6] = te[6];
		_r[7] = te[7];
		_r[8] = te[8];
		_r[9] = te[9];
		_r[10] = te[10];
		_r[11] = te[11];
		_r[12] = te[12];
		_r[13] = te[13];
		_r[14] = te[14];
		_r[15] = te[15];
		return this;
	}
	,multiplyScalar: function(_s) {
		var te = this.elements;
		te[0] *= _s;
		te[4] *= _s;
		te[8] *= _s;
		te[12] *= _s;
		te[1] *= _s;
		te[5] *= _s;
		te[9] *= _s;
		te[13] *= _s;
		te[2] *= _s;
		te[6] *= _s;
		te[10] *= _s;
		te[14] *= _s;
		te[3] *= _s;
		te[7] *= _s;
		te[11] *= _s;
		te[15] *= _s;
		return this;
	}
	,multiplyVector3Array: function(_a) {
		var v1 = new phoenix_Vector();
		var i = 0;
		var il = _a.length;
		while(i < il) {
			v1.set_x(_a[i]);
			v1.set_y(_a[i + 1]);
			v1.set_z(_a[i + 2]);
			v1.applyProjection(this);
			_a[i] = v1.x;
			_a[i + 1] = v1.y;
			_a[i + 2] = v1.z;
			i += 3;
		}
		return _a;
	}
	,determinant: function() {
		var te = this.elements;
		var n11 = te[0];
		var n12 = te[4];
		var n13 = te[8];
		var n14 = te[12];
		var n21 = te[1];
		var n22 = te[5];
		var n23 = te[9];
		var n24 = te[13];
		var n31 = te[2];
		var n32 = te[6];
		var n33 = te[10];
		var n34 = te[14];
		var n41 = te[3];
		var n42 = te[7];
		var n43 = te[11];
		var n44 = te[15];
		return n41 * (n14 * n23 * n32 - n13 * n24 * n32 - n14 * n22 * n33 + n12 * n24 * n33 + n13 * n22 * n34 - n12 * n23 * n34) + n42 * (n11 * n23 * n34 - n11 * n24 * n33 + n14 * n21 * n33 - n13 * n21 * n34 + n13 * n24 * n31 - n14 * n23 * n31) + n43 * (n11 * n24 * n32 - n11 * n22 * n34 - n14 * n21 * n32 + n12 * n21 * n34 + n14 * n22 * n31 - n12 * n24 * n31) + n44 * (-n13 * n22 * n31 - n11 * n23 * n32 + n11 * n22 * n33 + n13 * n21 * n32 - n12 * n21 * n33 + n12 * n23 * n31);
	}
	,transpose: function() {
		var te = this.elements;
		var tmp;
		tmp = te[1];
		te[1] = te[4];
		te[4] = tmp;
		tmp = te[2];
		te[2] = te[8];
		te[8] = tmp;
		tmp = te[6];
		te[6] = te[9];
		te[9] = tmp;
		tmp = te[3];
		te[3] = te[12];
		te[12] = tmp;
		tmp = te[7];
		te[7] = te[13];
		te[13] = tmp;
		tmp = te[11];
		te[11] = te[14];
		te[14] = tmp;
		return this;
	}
	,flattenToArray: function(_flat) {
		if(_flat == null) {
			_flat = [];
			var _g = 0;
			while(_g < 16) {
				var i = _g++;
				_flat.push(0.0);
			}
		}
		var te = this.elements;
		_flat[0] = te[0];
		_flat[1] = te[1];
		_flat[2] = te[2];
		_flat[3] = te[3];
		_flat[4] = te[4];
		_flat[5] = te[5];
		_flat[6] = te[6];
		_flat[7] = te[7];
		_flat[8] = te[8];
		_flat[9] = te[9];
		_flat[10] = te[10];
		_flat[11] = te[11];
		_flat[12] = te[12];
		_flat[13] = te[13];
		_flat[14] = te[14];
		_flat[15] = te[15];
		return _flat;
	}
	,flattenToArrayOffset: function(_flat,_offset) {
		var te = this.elements;
		_flat[_offset] = te[0];
		_flat[_offset + 1] = te[1];
		_flat[_offset + 2] = te[2];
		_flat[_offset + 3] = te[3];
		_flat[_offset + 4] = te[4];
		_flat[_offset + 5] = te[5];
		_flat[_offset + 6] = te[6];
		_flat[_offset + 7] = te[7];
		_flat[_offset + 8] = te[8];
		_flat[_offset + 9] = te[9];
		_flat[_offset + 10] = te[10];
		_flat[_offset + 11] = te[11];
		_flat[_offset + 12] = te[12];
		_flat[_offset + 13] = te[13];
		_flat[_offset + 14] = te[14];
		_flat[_offset + 15] = te[15];
		return _flat;
	}
	,setPosition: function(_v) {
		var te = this.elements;
		te[12] = _v.x;
		te[13] = _v.y;
		te[14] = _v.z;
		return this;
	}
	,inverse: function() {
		return this.clone().getInverse(this);
	}
	,getInverse: function(_m) {
		var te = this.elements;
		var me = _m.elements;
		var n11 = me[0];
		var n12 = me[4];
		var n13 = me[8];
		var n14 = me[12];
		var n21 = me[1];
		var n22 = me[5];
		var n23 = me[9];
		var n24 = me[13];
		var n31 = me[2];
		var n32 = me[6];
		var n33 = me[10];
		var n34 = me[14];
		var n41 = me[3];
		var n42 = me[7];
		var n43 = me[11];
		var n44 = me[15];
		te[0] = n23 * n34 * n42 - n24 * n33 * n42 + n24 * n32 * n43 - n22 * n34 * n43 - n23 * n32 * n44 + n22 * n33 * n44;
		te[4] = n14 * n33 * n42 - n13 * n34 * n42 - n14 * n32 * n43 + n12 * n34 * n43 + n13 * n32 * n44 - n12 * n33 * n44;
		te[8] = n13 * n24 * n42 - n14 * n23 * n42 + n14 * n22 * n43 - n12 * n24 * n43 - n13 * n22 * n44 + n12 * n23 * n44;
		te[12] = n14 * n23 * n32 - n13 * n24 * n32 - n14 * n22 * n33 + n12 * n24 * n33 + n13 * n22 * n34 - n12 * n23 * n34;
		te[1] = n24 * n33 * n41 - n23 * n34 * n41 - n24 * n31 * n43 + n21 * n34 * n43 + n23 * n31 * n44 - n21 * n33 * n44;
		te[5] = n13 * n34 * n41 - n14 * n33 * n41 + n14 * n31 * n43 - n11 * n34 * n43 - n13 * n31 * n44 + n11 * n33 * n44;
		te[9] = n14 * n23 * n41 - n13 * n24 * n41 - n14 * n21 * n43 + n11 * n24 * n43 + n13 * n21 * n44 - n11 * n23 * n44;
		te[13] = n13 * n24 * n31 - n14 * n23 * n31 + n14 * n21 * n33 - n11 * n24 * n33 - n13 * n21 * n34 + n11 * n23 * n34;
		te[2] = n22 * n34 * n41 - n24 * n32 * n41 + n24 * n31 * n42 - n21 * n34 * n42 - n22 * n31 * n44 + n21 * n32 * n44;
		te[6] = n14 * n32 * n41 - n12 * n34 * n41 - n14 * n31 * n42 + n11 * n34 * n42 + n12 * n31 * n44 - n11 * n32 * n44;
		te[10] = n12 * n24 * n41 - n14 * n22 * n41 + n14 * n21 * n42 - n11 * n24 * n42 - n12 * n21 * n44 + n11 * n22 * n44;
		te[14] = n14 * n22 * n31 - n12 * n24 * n31 - n14 * n21 * n32 + n11 * n24 * n32 + n12 * n21 * n34 - n11 * n22 * n34;
		te[3] = n23 * n32 * n41 - n22 * n33 * n41 - n23 * n31 * n42 + n21 * n33 * n42 + n22 * n31 * n43 - n21 * n32 * n43;
		te[7] = n12 * n33 * n41 - n13 * n32 * n41 + n13 * n31 * n42 - n11 * n33 * n42 - n12 * n31 * n43 + n11 * n32 * n43;
		te[11] = n13 * n22 * n41 - n12 * n23 * n41 - n13 * n21 * n42 + n11 * n23 * n42 + n12 * n21 * n43 - n11 * n22 * n43;
		te[15] = n12 * n23 * n31 - n13 * n22 * n31 + n13 * n21 * n32 - n11 * n23 * n32 - n12 * n21 * n33 + n11 * n22 * n33;
		var det = me[0] * te[0] + me[1] * te[4] + me[2] * te[8] + me[3] * te[12];
		if(det == 0) {
			haxe_Log.trace("Matrix.getInverse: cant invert matrix, determinant is 0",{ fileName : "Matrix.hx", lineNumber : 689, className : "phoenix.Matrix", methodName : "getInverse"});
			this.set(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1);
			this;
			return this;
		}
		this.multiplyScalar(1 / det);
		return this;
	}
	,scale: function(_v) {
		var te = this.elements;
		var _x = _v.x;
		var _y = _v.y;
		var _z = _v.z;
		te[0] *= _x;
		te[4] *= _y;
		te[8] *= _z;
		te[1] *= _x;
		te[5] *= _y;
		te[9] *= _z;
		te[2] *= _x;
		te[6] *= _y;
		te[10] *= _z;
		te[3] *= _x;
		te[7] *= _y;
		te[11] *= _z;
		return this;
	}
	,getMaxScaleOnAxis: function() {
		var te = this.elements;
		var _scaleXSq = te[0] * te[0] + te[1] * te[1] + te[2] * te[2];
		var _scaleYSq = te[4] * te[4] + te[5] * te[5] + te[6] * te[6];
		var _scaleZSq = te[8] * te[8] + te[9] * te[9] + te[10] * te[10];
		return Math.sqrt(Math.max(_scaleXSq,Math.max(_scaleYSq,_scaleZSq)));
	}
	,makeTranslation: function(_x,_y,_z) {
		this.set(1,0,0,_x,0,1,0,_y,0,0,1,_z,0,0,0,1);
		return this;
	}
	,makeRotationX: function(_theta) {
		var _c = Math.cos(_theta);
		var _s = Math.sin(_theta);
		this.set(1,0,0,0,0,_c,-_s,0,0,_s,_c,0,0,0,0,1);
		return this;
	}
	,makeRotationY: function(_theta) {
		var _c = Math.cos(_theta);
		var _s = Math.sin(_theta);
		this.set(_c,0,_s,0,0,1,0,0,-_s,0,_c,0,0,0,0,1);
		return this;
	}
	,makeRotationZ: function(_theta) {
		var _c = Math.cos(_theta);
		var _s = Math.sin(_theta);
		this.set(_c,-_s,0,0,_s,_c,0,0,0,0,1,0,0,0,0,1);
		return this;
	}
	,makeRotationAxis: function(_axis,_angle) {
		var _c = Math.cos(_angle);
		var _s = Math.sin(_angle);
		var _t = 1 - _c;
		var _ax = _axis.x;
		var _ay = _axis.y;
		var _az = _axis.z;
		var _tx = _t * _ax;
		var _ty = _t * _ay;
		this.set(_tx * _ax + _c,_tx * _ay - _s * _az,_tx * _az + _s * _ay,0,_tx * _ay + _s * _az,_ty * _ay + _c,_ty * _az - _s * _ax,0,_tx * _az - _s * _ay,_ty * _az + _s * _ax,_t * _az * _az + _c,0,0,0,0,1);
		return this;
	}
	,makeScale: function(_x,_y,_z) {
		this.set(_x,0,0,0,0,_y,0,0,0,0,_z,0,0,0,0,1);
		return this;
	}
	,compose_with_origin: function(_position,_origin,_quaternion,_scale) {
		this.set(1,0,0,_origin.x,0,1,0,_origin.y,0,0,1,_origin.z,0,0,0,1);
		this;
		this.scale(_scale);
		this.multiply(new phoenix_Matrix().makeRotationFromQuaternion(_quaternion));
		this.multiply(new phoenix_Matrix().makeTranslation(-_origin.x,-_origin.y,-_origin.z));
		this.multiply(new phoenix_Matrix().makeTranslation(_position.x,_position.y,_position.z));
		return this;
	}
	,compose: function(_position,_quaternion,_scale) {
		this.makeRotationFromQuaternion(_quaternion);
		this.scale(_scale);
		this.setPosition(_position);
		return this;
	}
	,decompose: function(_position,_quaternion,_scale) {
		var te = this.elements;
		var matrix = new phoenix_Matrix();
		var _ax_x = te[0];
		var _ax_y = te[1];
		var _ax_z = te[2];
		var _ay_x = te[4];
		var _ay_y = te[5];
		var _ay_z = te[6];
		var _az_x = te[8];
		var _az_y = te[9];
		var _az_z = te[10];
		var _ax_length = Math.sqrt(_ax_x * _ax_x + _ax_y * _ax_y + _ax_z * _ax_z);
		var _ay_length = Math.sqrt(_ay_x * _ay_x + _ay_y * _ay_y + _ay_z * _ay_z);
		var _az_length = Math.sqrt(_az_x * _az_x + _az_y * _az_y + _az_z * _az_z);
		if(_quaternion == null) _quaternion = new phoenix_Quaternion();
		if(_position == null) _position = new phoenix_Vector(te[12],te[13],te[14]); else {
			_position.set_x(te[12]);
			_position.set_y(te[13]);
			_position.set_z(te[14]);
		}
		if(_scale == null) _scale = new phoenix_Vector(_ax_length,_ay_length,_az_length); else {
			_scale.x = _ax_length;
			if(_scale._construct) _scale.x; else {
				if(_scale.listen_x != null && !_scale.ignore_listeners) _scale.listen_x(_ax_length);
				_scale.x;
			}
			_scale.y = _ay_length;
			if(_scale._construct) _scale.y; else {
				if(_scale.listen_y != null && !_scale.ignore_listeners) _scale.listen_y(_ay_length);
				_scale.y;
			}
			_scale.z = _az_length;
			if(_scale._construct) _scale.z; else {
				if(_scale.listen_z != null && !_scale.ignore_listeners) _scale.listen_z(_az_length);
				_scale.z;
			}
		}
		matrix.elements = this.elements.concat([]);
		var me = matrix.elements;
		me[0] /= _ax_length;
		me[1] /= _ax_length;
		me[2] /= _ax_length;
		me[4] /= _ay_length;
		me[5] /= _ay_length;
		me[6] /= _ay_length;
		me[8] /= _az_length;
		me[9] /= _az_length;
		me[10] /= _az_length;
		_quaternion.setFromRotationMatrix(matrix);
		if(this._transform == null) this._transform = new phoenix_MatrixTransform(_position,_quaternion,_scale); else {
			this._transform.pos = _position;
			this._transform.rotation = _quaternion;
			this._transform.scale = _scale;
		}
		return this._transform;
	}
	,makeFrustum: function(_left,_right,_bottom,_top,_near,_far) {
		var te = this.elements;
		var tx = 2 * _near / (_right - _left);
		var ty = 2 * _near / (_top - _bottom);
		var a = (_right + _left) / (_right - _left);
		var b = (_top + _bottom) / (_top - _bottom);
		var c = -(_far + _near) / (_far - _near);
		var d = -2 * _far * _near / (_far - _near);
		te[0] = tx;
		te[4] = 0;
		te[8] = a;
		te[12] = 0;
		te[1] = 0;
		te[5] = ty;
		te[9] = b;
		te[13] = 0;
		te[2] = 0;
		te[6] = 0;
		te[10] = c;
		te[14] = d;
		te[3] = 0;
		te[7] = 0;
		te[11] = -1;
		te[15] = 0;
		return this;
	}
	,makePerspective: function(_fov,_aspect,_near,_far) {
		var ymax = _near * Math.tan(_fov * 0.5 * 0.017453292519943278);
		var ymin = -ymax;
		var xmin = ymin * _aspect;
		var xmax = ymax * _aspect;
		return this.makeFrustum(xmin,xmax,ymin,ymax,_near,_far);
	}
	,makeOrthographic: function(_left,_right,_top,_bottom,_near,_far) {
		var te = this.elements;
		var w = _right - _left;
		var h = _top - _bottom;
		var p = _far - _near;
		var tx = (_right + _left) / w;
		var ty = (_top + _bottom) / h;
		var tz = (_far + _near) / p;
		te[0] = 2 / w;
		te[4] = 0;
		te[8] = 0;
		te[12] = -tx;
		te[1] = 0;
		te[5] = 2 / h;
		te[9] = 0;
		te[13] = -ty;
		te[2] = 0;
		te[6] = 0;
		te[10] = -2 / p;
		te[14] = -tz;
		te[3] = 0;
		te[7] = 0;
		te[11] = 0;
		te[15] = 1;
		return this;
	}
	,fromArray: function(_from) {
		this.elements = _from.concat([]);
	}
	,toArray: function() {
		var te = this.elements;
		return [te[0],te[1],te[2],te[3],te[4],te[5],te[6],te[7],te[8],te[9],te[10],te[11],te[12],te[13],te[14],te[15]];
	}
	,clone: function() {
		var te = this.elements;
		return new phoenix_Matrix(te[0],te[4],te[8],te[12],te[1],te[5],te[9],te[13],te[2],te[6],te[10],te[14],te[3],te[7],te[11],te[15]);
	}
	,up: function() {
		return new phoenix_Vector(this.elements[4],this.elements[5],this.elements[10]);
	}
	,down: function() {
		return new phoenix_Vector(this.elements[4],this.elements[5],this.elements[10]).get_inverted();
	}
	,left: function() {
		return new phoenix_Vector(this.elements[0],this.elements[1],this.elements[2]).get_inverted();
	}
	,right: function() {
		return new phoenix_Vector(this.elements[0],this.elements[1],this.elements[2]);
	}
	,backward: function() {
		return new phoenix_Vector(this.elements[8],this.elements[9],this.elements[10]);
	}
	,forward: function() {
		return new phoenix_Vector(this.elements[8],this.elements[9],this.elements[10]).get_inverted();
	}
	,__class__: phoenix_Matrix
	,__properties__: {set_M44:"set_M44",get_M44:"get_M44",set_M34:"set_M34",get_M34:"get_M34",set_M24:"set_M24",get_M24:"get_M24",set_M14:"set_M14",get_M14:"get_M14",set_M43:"set_M43",get_M43:"get_M43",set_M33:"set_M33",get_M33:"get_M33",set_M23:"set_M23",get_M23:"get_M23",set_M13:"set_M13",get_M13:"get_M13",set_M42:"set_M42",get_M42:"get_M42",set_M32:"set_M32",get_M32:"get_M32",set_M22:"set_M22",get_M22:"get_M22",set_M12:"set_M12",get_M12:"get_M12",set_M41:"set_M41",get_M41:"get_M41",set_M31:"set_M31",get_M31:"get_M31",set_M21:"set_M21",get_M21:"get_M21",set_M11:"set_M11",get_M11:"get_M11"}
};
var phoenix_Quaternion = function(_x,_y,_z,_w) {
	if(_w == null) _w = 1;
	if(_z == null) _z = 0;
	if(_y == null) _y = 0;
	if(_x == null) _x = 0;
	this.ignore_euler = false;
	this._construct = false;
	this.ignore_listeners = false;
	this.w = 0.0;
	this.z = 0.0;
	this.y = 0.0;
	this.x = 0.0;
	this._construct = true;
	this.x = _x;
	if(this._construct) this.x; else {
		if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
		if(this.listen_x != null && !this.ignore_listeners) this.listen_x(this.x);
		this.x;
	}
	this.y = _y;
	if(this._construct) this.y; else {
		if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
		if(this.listen_y != null && !this.ignore_listeners) this.listen_y(this.y);
		this.y;
	}
	this.z = _z;
	if(this._construct) this.z; else {
		if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
		if(this.listen_z != null && !this.ignore_listeners) this.listen_z(this.z);
		this.z;
	}
	this.w = _w;
	if(this._construct) this.w; else {
		if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
		if(this.listen_w != null && !this.ignore_listeners) this.listen_w(this.w);
		this.w;
	}
	this.euler = new phoenix_Vector();
	this._construct = false;
};
phoenix_Quaternion.__name__ = true;
phoenix_Quaternion.Add = function(_a,_b) {
	return _a.clone().add(_b);
};
phoenix_Quaternion.Multiply = function(_a,_b) {
	return _a.clone().multiply(_b);
};
phoenix_Quaternion.MultiplyScalar = function(_quaternion,_scalar) {
	return _quaternion.clone().multiplyScalar(_scalar);
};
phoenix_Quaternion.Slerp = function(_qa,_qb,_qm,_t) {
	return _qm.copy(_qa).slerp(_qb,_t);
};
phoenix_Quaternion.Dot = function(_a,_b) {
	return new phoenix_Quaternion(_a.x,_a.y,_a.z,_a.w).dot(_b);
};
phoenix_Quaternion.Listen = function(_q,listener) {
	_q.listen_x = listener;
	_q.listen_y = listener;
	_q.listen_z = listener;
	_q.listen_w = listener;
};
phoenix_Quaternion.prototype = {
	toString: function() {
		return "{ x:" + this.x + ", y:" + this.y + ", z:" + this.z + ", w:" + this.w + " }";
	}
	,set: function(_x,_y,_z,_w) {
		this.ignore_euler = true;
		this.x = _x;
		if(this._construct) this.x; else {
			if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
			if(this.listen_x != null && !this.ignore_listeners) this.listen_x(this.x);
			this.x;
		}
		this.y = _y;
		if(this._construct) this.y; else {
			if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
			if(this.listen_y != null && !this.ignore_listeners) this.listen_y(this.y);
			this.y;
		}
		this.z = _z;
		if(this._construct) this.z; else {
			if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
			if(this.listen_z != null && !this.ignore_listeners) this.listen_z(this.z);
			this.z;
		}
		this.w = _w;
		if(this._construct) this.w; else {
			if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
			if(this.listen_w != null && !this.ignore_listeners) this.listen_w(this.w);
			this.w;
		}
		this.ignore_euler = false;
		if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
		if(this.listen_x != null && !this.ignore_listeners) this.listen_x(this.x);
		if(this.listen_y != null && !this.ignore_listeners) this.listen_y(this.y);
		if(this.listen_z != null && !this.ignore_listeners) this.listen_z(this.z);
		if(this.listen_w != null && !this.ignore_listeners) this.listen_w(this.w);
		return this;
	}
	,copy: function(_quaternion) {
		this.ignore_euler = true;
		this.x = _quaternion.x;
		if(this._construct) this.x; else {
			if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
			if(this.listen_x != null && !this.ignore_listeners) this.listen_x(this.x);
			this.x;
		}
		this.y = _quaternion.y;
		if(this._construct) this.y; else {
			if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
			if(this.listen_y != null && !this.ignore_listeners) this.listen_y(this.y);
			this.y;
		}
		this.z = _quaternion.z;
		if(this._construct) this.z; else {
			if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
			if(this.listen_z != null && !this.ignore_listeners) this.listen_z(this.z);
			this.z;
		}
		this.w = _quaternion.w;
		if(this._construct) this.w; else {
			if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
			if(this.listen_w != null && !this.ignore_listeners) this.listen_w(this.w);
			this.w;
		}
		this.ignore_euler = false;
		if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
		if(this.listen_x != null && !this.ignore_listeners) this.listen_x(this.x);
		if(this.listen_y != null && !this.ignore_listeners) this.listen_y(this.y);
		if(this.listen_z != null && !this.ignore_listeners) this.listen_z(this.z);
		if(this.listen_w != null && !this.ignore_listeners) this.listen_w(this.w);
		return this;
	}
	,dot: function(_other) {
		return this.x * _other.x + this.y * _other.y + this.z * _other.z + this.w * _other.w;
	}
	,setFromEuler: function(_euler,_order) {
		if(_order == null) _order = 0;
		var _x = this.x;
		var _y = this.y;
		var _z = this.z;
		var _w = this.w;
		var c1 = Math.cos(_euler.x / 2);
		var c2 = Math.cos(_euler.y / 2);
		var c3 = Math.cos(_euler.z / 2);
		var s1 = Math.sin(_euler.x / 2);
		var s2 = Math.sin(_euler.y / 2);
		var s3 = Math.sin(_euler.z / 2);
		if(_order == 0) {
			_x = s1 * c2 * c3 + c1 * s2 * s3;
			_y = c1 * s2 * c3 - s1 * c2 * s3;
			_z = c1 * c2 * s3 + s1 * s2 * c3;
			_w = c1 * c2 * c3 - s1 * s2 * s3;
		} else if(_order == 1) {
			_x = s1 * c2 * c3 + c1 * s2 * s3;
			_y = c1 * s2 * c3 - s1 * c2 * s3;
			_z = c1 * c2 * s3 - s1 * s2 * c3;
			_w = c1 * c2 * c3 + s1 * s2 * s3;
		} else if(_order == 2) {
			_x = s1 * c2 * c3 - c1 * s2 * s3;
			_y = c1 * s2 * c3 + s1 * c2 * s3;
			_z = c1 * c2 * s3 + s1 * s2 * c3;
			_w = c1 * c2 * c3 - s1 * s2 * s3;
		} else if(_order == 3) {
			_x = s1 * c2 * c3 - c1 * s2 * s3;
			_y = c1 * s2 * c3 + s1 * c2 * s3;
			_z = c1 * c2 * s3 - s1 * s2 * c3;
			_w = c1 * c2 * c3 + s1 * s2 * s3;
		} else if(_order == 4) {
			_x = s1 * c2 * c3 + c1 * s2 * s3;
			_y = c1 * s2 * c3 + s1 * c2 * s3;
			_z = c1 * c2 * s3 - s1 * s2 * c3;
			_w = c1 * c2 * c3 - s1 * s2 * s3;
		} else if(_order == 5) {
			_x = s1 * c2 * c3 - c1 * s2 * s3;
			_y = c1 * s2 * c3 - s1 * c2 * s3;
			_z = c1 * c2 * s3 + s1 * s2 * c3;
			_w = c1 * c2 * c3 + s1 * s2 * s3;
		}
		this.ignore_euler = true;
		this.x = _x;
		if(this._construct) this.x; else {
			if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
			if(this.listen_x != null && !this.ignore_listeners) this.listen_x(this.x);
			this.x;
		}
		this.y = _y;
		if(this._construct) this.y; else {
			if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
			if(this.listen_y != null && !this.ignore_listeners) this.listen_y(this.y);
			this.y;
		}
		this.z = _z;
		if(this._construct) this.z; else {
			if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
			if(this.listen_z != null && !this.ignore_listeners) this.listen_z(this.z);
			this.z;
		}
		this.w = _w;
		if(this._construct) this.w; else {
			if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
			if(this.listen_w != null && !this.ignore_listeners) this.listen_w(this.w);
			this.w;
		}
		this.ignore_euler = false;
		if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
		if(this.listen_x != null && !this.ignore_listeners) this.listen_x(this.x);
		if(this.listen_y != null && !this.ignore_listeners) this.listen_y(this.y);
		if(this.listen_z != null && !this.ignore_listeners) this.listen_z(this.z);
		if(this.listen_w != null && !this.ignore_listeners) this.listen_w(this.w);
		return this;
	}
	,setFromAxisAngle: function(_axis,_angle) {
		var _halfAngle = _angle / 2;
		var _s = Math.sin(_halfAngle);
		this.set_xyzw(_axis.x * _s,_axis.y * _s,_axis.z * _s,Math.cos(_halfAngle));
		return this;
	}
	,setFromRotationMatrix: function(_m) {
		var te = _m.elements;
		var m11 = te[0];
		var m12 = te[4];
		var m13 = te[8];
		var m21 = te[1];
		var m22 = te[5];
		var m23 = te[9];
		var m31 = te[2];
		var m32 = te[6];
		var m33 = te[10];
		var _x = this.x;
		var _y = this.y;
		var _z = this.z;
		var _w = this.w;
		var tr = m11 + m22 + m33;
		var s;
		if(tr > 0) {
			s = 0.5 / Math.sqrt(tr + 1.0);
			_w = 0.25 / s;
			_x = (m32 - m23) * s;
			_y = (m13 - m31) * s;
			_z = (m21 - m12) * s;
		} else if(m11 > m22 && m11 > m33) {
			s = 2.0 * Math.sqrt(1.0 + m11 - m22 - m33);
			_w = (m32 - m23) / s;
			_x = 0.25 * s;
			_y = (m12 + m21) / s;
			_z = (m13 + m31) / s;
		} else if(m22 > m33) {
			s = 2.0 * Math.sqrt(1.0 + m22 - m11 - m33);
			_w = (m13 - m31) / s;
			_x = (m12 + m21) / s;
			_y = 0.25 * s;
			_z = (m23 + m32) / s;
		} else {
			s = 2.0 * Math.sqrt(1.0 + m33 - m11 - m22);
			_w = (m21 - m12) / s;
			_x = (m13 + m31) / s;
			_y = (m23 + m32) / s;
			_z = 0.25 * s;
		}
		this.ignore_euler = true;
		this.x = _x;
		if(this._construct) this.x; else {
			if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
			if(this.listen_x != null && !this.ignore_listeners) this.listen_x(this.x);
			this.x;
		}
		this.y = _y;
		if(this._construct) this.y; else {
			if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
			if(this.listen_y != null && !this.ignore_listeners) this.listen_y(this.y);
			this.y;
		}
		this.z = _z;
		if(this._construct) this.z; else {
			if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
			if(this.listen_z != null && !this.ignore_listeners) this.listen_z(this.z);
			this.z;
		}
		this.w = _w;
		if(this._construct) this.w; else {
			if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
			if(this.listen_w != null && !this.ignore_listeners) this.listen_w(this.w);
			this.w;
		}
		this.ignore_euler = false;
		if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
		if(this.listen_x != null && !this.ignore_listeners) this.listen_x(this.x);
		if(this.listen_y != null && !this.ignore_listeners) this.listen_y(this.y);
		if(this.listen_z != null && !this.ignore_listeners) this.listen_z(this.z);
		if(this.listen_w != null && !this.ignore_listeners) this.listen_w(this.w);
		return this;
	}
	,inverse: function() {
		return this.conjugate().normalize();
	}
	,conjugate: function() {
		this.ignore_euler = true;
		this.x = this.x * -1;
		if(this._construct) this.x; else {
			if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
			if(this.listen_x != null && !this.ignore_listeners) this.listen_x(this.x);
			this.x;
		}
		this.y = this.y * -1;
		if(this._construct) this.y; else {
			if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
			if(this.listen_y != null && !this.ignore_listeners) this.listen_y(this.y);
			this.y;
		}
		this.z = this.z * -1;
		if(this._construct) this.z; else {
			if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
			if(this.listen_z != null && !this.ignore_listeners) this.listen_z(this.z);
			this.z;
		}
		this.ignore_euler = false;
		if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
		if(this.listen_x != null && !this.ignore_listeners) this.listen_x(this.x);
		if(this.listen_y != null && !this.ignore_listeners) this.listen_y(this.y);
		if(this.listen_z != null && !this.ignore_listeners) this.listen_z(this.z);
		return this;
	}
	,lengthSq: function() {
		return this.x * this.x + this.y * this.y + this.z * this.z + this.w * this.w;
	}
	,length: function() {
		return Math.sqrt(this.x * this.x + this.y * this.y + this.z * this.z + this.w * this.w);
	}
	,normalize: function() {
		var l = this.length();
		if(l == 0) {
			this.ignore_euler = true;
			this.x = 0;
			if(this._construct) this.x; else {
				if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
				if(this.listen_x != null && !this.ignore_listeners) this.listen_x(this.x);
				this.x;
			}
			this.y = 0;
			if(this._construct) this.y; else {
				if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
				if(this.listen_y != null && !this.ignore_listeners) this.listen_y(this.y);
				this.y;
			}
			this.z = 0;
			if(this._construct) this.z; else {
				if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
				if(this.listen_z != null && !this.ignore_listeners) this.listen_z(this.z);
				this.z;
			}
			this.w = 1;
			if(this._construct) this.w; else {
				if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
				if(this.listen_w != null && !this.ignore_listeners) this.listen_w(this.w);
				this.w;
			}
			this.ignore_euler = false;
			if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
			if(this.listen_x != null && !this.ignore_listeners) this.listen_x(this.x);
			if(this.listen_y != null && !this.ignore_listeners) this.listen_y(this.y);
			if(this.listen_z != null && !this.ignore_listeners) this.listen_z(this.z);
			if(this.listen_w != null && !this.ignore_listeners) this.listen_w(this.w);
		} else {
			l = 1 / l;
			this.ignore_euler = true;
			this.x = this.x * l;
			if(this._construct) this.x; else {
				if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
				if(this.listen_x != null && !this.ignore_listeners) this.listen_x(this.x);
				this.x;
			}
			this.y = this.y * l;
			if(this._construct) this.y; else {
				if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
				if(this.listen_y != null && !this.ignore_listeners) this.listen_y(this.y);
				this.y;
			}
			this.z = this.z * l;
			if(this._construct) this.z; else {
				if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
				if(this.listen_z != null && !this.ignore_listeners) this.listen_z(this.z);
				this.z;
			}
			this.w = this.w * l;
			if(this._construct) this.w; else {
				if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
				if(this.listen_w != null && !this.ignore_listeners) this.listen_w(this.w);
				this.w;
			}
			this.ignore_euler = false;
			if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
			if(this.listen_x != null && !this.ignore_listeners) this.listen_x(this.x);
			if(this.listen_y != null && !this.ignore_listeners) this.listen_y(this.y);
			if(this.listen_z != null && !this.ignore_listeners) this.listen_z(this.z);
			if(this.listen_w != null && !this.ignore_listeners) this.listen_w(this.w);
		}
		return this;
	}
	,multiply: function(_quaternion) {
		return this.multiplyQuaternions(this,_quaternion);
	}
	,add: function(_quaternion) {
		return this.addQuaternions(this,_quaternion);
	}
	,addQuaternions: function(_a,_b) {
		this.x = _a.x + _b.x;
		if(this._construct) this.x; else {
			if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
			if(this.listen_x != null && !this.ignore_listeners) this.listen_x(this.x);
			this.x;
		}
		this.y = _a.y + _b.y;
		if(this._construct) this.y; else {
			if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
			if(this.listen_y != null && !this.ignore_listeners) this.listen_y(this.y);
			this.y;
		}
		this.z = _a.z + _b.z;
		if(this._construct) this.z; else {
			if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
			if(this.listen_z != null && !this.ignore_listeners) this.listen_z(this.z);
			this.z;
		}
		this.w = _a.w + _b.w;
		if(this._construct) this.w; else {
			if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
			if(this.listen_w != null && !this.ignore_listeners) this.listen_w(this.w);
			this.w;
		}
		return this;
	}
	,multiplyScalar: function(_scalar) {
		var _g = this;
		_g.x = _g.x * _scalar;
		if(_g._construct) _g.x; else {
			if(_g.euler == null || _g.ignore_euler || _g._construct) null; else _g.euler.setEulerFromQuaternion(_g,null);
			if(_g.listen_x != null && !_g.ignore_listeners) _g.listen_x(_g.x);
			_g.x;
		}
		var _g1 = this;
		_g1.y = _g1.y * _scalar;
		if(_g1._construct) _g1.y; else {
			if(_g1.euler == null || _g1.ignore_euler || _g1._construct) null; else _g1.euler.setEulerFromQuaternion(_g1,null);
			if(_g1.listen_y != null && !_g1.ignore_listeners) _g1.listen_y(_g1.y);
			_g1.y;
		}
		var _g2 = this;
		_g2.z = _g2.z * _scalar;
		if(_g2._construct) _g2.z; else {
			if(_g2.euler == null || _g2.ignore_euler || _g2._construct) null; else _g2.euler.setEulerFromQuaternion(_g2,null);
			if(_g2.listen_z != null && !_g2.ignore_listeners) _g2.listen_z(_g2.z);
			_g2.z;
		}
		var _g3 = this;
		_g3.w = _g3.w * _scalar;
		if(_g3._construct) _g3.w; else {
			if(_g3.euler == null || _g3.ignore_euler || _g3._construct) null; else _g3.euler.setEulerFromQuaternion(_g3,null);
			if(_g3.listen_w != null && !_g3.ignore_listeners) _g3.listen_w(_g3.w);
			_g3.w;
		}
		return this;
	}
	,multiplyQuaternions: function(_a,_b) {
		var qax = _a.x;
		var qay = _a.y;
		var qaz = _a.z;
		var qaw = _a.w;
		var qbx = _b.x;
		var qby = _b.y;
		var qbz = _b.z;
		var qbw = _b.w;
		this.ignore_euler = true;
		this.x = qax * qbw + qaw * qbx + qay * qbz - qaz * qby;
		if(this._construct) this.x; else {
			if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
			if(this.listen_x != null && !this.ignore_listeners) this.listen_x(this.x);
			this.x;
		}
		this.y = qay * qbw + qaw * qby + qaz * qbx - qax * qbz;
		if(this._construct) this.y; else {
			if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
			if(this.listen_y != null && !this.ignore_listeners) this.listen_y(this.y);
			this.y;
		}
		this.z = qaz * qbw + qaw * qbz + qax * qby - qay * qbx;
		if(this._construct) this.z; else {
			if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
			if(this.listen_z != null && !this.ignore_listeners) this.listen_z(this.z);
			this.z;
		}
		this.w = qaw * qbw - qax * qbx - qay * qby - qaz * qbz;
		if(this._construct) this.w; else {
			if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
			if(this.listen_w != null && !this.ignore_listeners) this.listen_w(this.w);
			this.w;
		}
		this.ignore_euler = false;
		if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
		if(this.listen_x != null && !this.ignore_listeners) this.listen_x(this.x);
		if(this.listen_y != null && !this.ignore_listeners) this.listen_y(this.y);
		if(this.listen_z != null && !this.ignore_listeners) this.listen_z(this.z);
		if(this.listen_w != null && !this.ignore_listeners) this.listen_w(this.w);
		return this;
	}
	,slerp: function(_qb,_t) {
		var _x = this.x;
		var _y = this.y;
		var _z = this.z;
		var _w = this.w;
		var cosHalfTheta = _w * _qb.w + _x * _qb.x + _y * _qb.y + _z * _qb.z;
		if(cosHalfTheta < 0) {
			this.w = -_qb.w;
			if(this._construct) this.w; else {
				if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
				if(this.listen_w != null && !this.ignore_listeners) this.listen_w(this.w);
				this.w;
			}
			this.x = -_qb.x;
			if(this._construct) this.x; else {
				if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
				if(this.listen_x != null && !this.ignore_listeners) this.listen_x(this.x);
				this.x;
			}
			this.y = -_qb.y;
			if(this._construct) this.y; else {
				if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
				if(this.listen_y != null && !this.ignore_listeners) this.listen_y(this.y);
				this.y;
			}
			this.z = -_qb.z;
			if(this._construct) this.z; else {
				if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
				if(this.listen_z != null && !this.ignore_listeners) this.listen_z(this.z);
				this.z;
			}
			cosHalfTheta = -cosHalfTheta;
		} else this.copy(_qb);
		if(cosHalfTheta >= 1.0) {
			this.ignore_euler = true;
			this.x = _x;
			if(this._construct) this.x; else {
				if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
				if(this.listen_x != null && !this.ignore_listeners) this.listen_x(this.x);
				this.x;
			}
			this.y = _y;
			if(this._construct) this.y; else {
				if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
				if(this.listen_y != null && !this.ignore_listeners) this.listen_y(this.y);
				this.y;
			}
			this.z = _z;
			if(this._construct) this.z; else {
				if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
				if(this.listen_z != null && !this.ignore_listeners) this.listen_z(this.z);
				this.z;
			}
			this.w = _w;
			if(this._construct) this.w; else {
				if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
				if(this.listen_w != null && !this.ignore_listeners) this.listen_w(this.w);
				this.w;
			}
			this.ignore_euler = false;
			if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
			if(this.listen_x != null && !this.ignore_listeners) this.listen_x(this.x);
			if(this.listen_y != null && !this.ignore_listeners) this.listen_y(this.y);
			if(this.listen_z != null && !this.ignore_listeners) this.listen_z(this.z);
			if(this.listen_w != null && !this.ignore_listeners) this.listen_w(this.w);
			return this;
		}
		var halfTheta = Math.acos(cosHalfTheta);
		var sinHalfTheta = Math.sqrt(1.0 - cosHalfTheta * cosHalfTheta);
		if(Math.abs(sinHalfTheta) < 0.001) {
			this.ignore_euler = true;
			this.x = 0.5 * (_w + this.w);
			if(this._construct) this.x; else {
				if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
				if(this.listen_x != null && !this.ignore_listeners) this.listen_x(this.x);
				this.x;
			}
			this.y = 0.5 * (_x + this.x);
			if(this._construct) this.y; else {
				if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
				if(this.listen_y != null && !this.ignore_listeners) this.listen_y(this.y);
				this.y;
			}
			this.z = 0.5 * (_y + this.y);
			if(this._construct) this.z; else {
				if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
				if(this.listen_z != null && !this.ignore_listeners) this.listen_z(this.z);
				this.z;
			}
			this.w = 0.5 * (_z + this.z);
			if(this._construct) this.w; else {
				if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
				if(this.listen_w != null && !this.ignore_listeners) this.listen_w(this.w);
				this.w;
			}
			this.ignore_euler = false;
			if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
			if(this.listen_x != null && !this.ignore_listeners) this.listen_x(this.x);
			if(this.listen_y != null && !this.ignore_listeners) this.listen_y(this.y);
			if(this.listen_z != null && !this.ignore_listeners) this.listen_z(this.z);
			if(this.listen_w != null && !this.ignore_listeners) this.listen_w(this.w);
			return this;
		}
		var ratioA = Math.sin((1 - _t) * halfTheta) / sinHalfTheta;
		var ratioB = Math.sin(_t * halfTheta) / sinHalfTheta;
		this.ignore_euler = true;
		this.x = _w * ratioA + this.w * ratioB;
		if(this._construct) this.x; else {
			if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
			if(this.listen_x != null && !this.ignore_listeners) this.listen_x(this.x);
			this.x;
		}
		this.y = _x * ratioA + this.x * ratioB;
		if(this._construct) this.y; else {
			if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
			if(this.listen_y != null && !this.ignore_listeners) this.listen_y(this.y);
			this.y;
		}
		this.z = _y * ratioA + this.y * ratioB;
		if(this._construct) this.z; else {
			if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
			if(this.listen_z != null && !this.ignore_listeners) this.listen_z(this.z);
			this.z;
		}
		this.w = _z * ratioA + this.z * ratioB;
		if(this._construct) this.w; else {
			if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
			if(this.listen_w != null && !this.ignore_listeners) this.listen_w(this.w);
			this.w;
		}
		this.ignore_euler = false;
		if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
		if(this.listen_x != null && !this.ignore_listeners) this.listen_x(this.x);
		if(this.listen_y != null && !this.ignore_listeners) this.listen_y(this.y);
		if(this.listen_z != null && !this.ignore_listeners) this.listen_z(this.z);
		if(this.listen_w != null && !this.ignore_listeners) this.listen_w(this.w);
		return this;
	}
	,equals: function(_q) {
		return _q.x == this.x && _q.y == this.y && _q.z == this.z && _q.w == this.w;
	}
	,fromArray: function(_a) {
		this.ignore_euler = true;
		this.x = _a[0];
		if(this._construct) this.x; else {
			if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
			if(this.listen_x != null && !this.ignore_listeners) this.listen_x(this.x);
			this.x;
		}
		this.y = _a[1];
		if(this._construct) this.y; else {
			if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
			if(this.listen_y != null && !this.ignore_listeners) this.listen_y(this.y);
			this.y;
		}
		this.z = _a[2];
		if(this._construct) this.z; else {
			if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
			if(this.listen_z != null && !this.ignore_listeners) this.listen_z(this.z);
			this.z;
		}
		this.w = _a[3];
		if(this._construct) this.w; else {
			if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
			if(this.listen_w != null && !this.ignore_listeners) this.listen_w(this.w);
			this.w;
		}
		this.ignore_euler = false;
		if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
		if(this.listen_x != null && !this.ignore_listeners) this.listen_x(this.x);
		if(this.listen_y != null && !this.ignore_listeners) this.listen_y(this.y);
		if(this.listen_z != null && !this.ignore_listeners) this.listen_z(this.z);
		if(this.listen_w != null && !this.ignore_listeners) this.listen_w(this.w);
		return this;
	}
	,toArray: function() {
		return [this.x,this.y,this.z,this.w];
	}
	,clone: function() {
		return new phoenix_Quaternion(this.x,this.y,this.z,this.w);
	}
	,toeuler: function() {
		return new phoenix_Vector().setEulerFromQuaternion(this,null).degrees();
	}
	,update_euler: function() {
		if(this.euler == null || this.ignore_euler || this._construct) return;
		this.euler.setEulerFromQuaternion(this,null);
	}
	,set_xyzw: function(_x,_y,_z,_w) {
		this.ignore_euler = true;
		this.x = _x;
		if(this._construct) this.x; else {
			if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
			if(this.listen_x != null && !this.ignore_listeners) this.listen_x(this.x);
			this.x;
		}
		this.y = _y;
		if(this._construct) this.y; else {
			if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
			if(this.listen_y != null && !this.ignore_listeners) this.listen_y(this.y);
			this.y;
		}
		this.z = _z;
		if(this._construct) this.z; else {
			if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
			if(this.listen_z != null && !this.ignore_listeners) this.listen_z(this.z);
			this.z;
		}
		this.w = _w;
		if(this._construct) this.w; else {
			if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
			if(this.listen_w != null && !this.ignore_listeners) this.listen_w(this.w);
			this.w;
		}
		this.ignore_euler = false;
		if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
		if(this.listen_x != null && !this.ignore_listeners) this.listen_x(this.x);
		if(this.listen_y != null && !this.ignore_listeners) this.listen_y(this.y);
		if(this.listen_z != null && !this.ignore_listeners) this.listen_z(this.z);
		if(this.listen_w != null && !this.ignore_listeners) this.listen_w(this.w);
	}
	,set_xyz: function(_x,_y,_z) {
		this.ignore_euler = true;
		this.x = _x;
		if(this._construct) this.x; else {
			if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
			if(this.listen_x != null && !this.ignore_listeners) this.listen_x(this.x);
			this.x;
		}
		this.y = _y;
		if(this._construct) this.y; else {
			if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
			if(this.listen_y != null && !this.ignore_listeners) this.listen_y(this.y);
			this.y;
		}
		this.z = _z;
		if(this._construct) this.z; else {
			if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
			if(this.listen_z != null && !this.ignore_listeners) this.listen_z(this.z);
			this.z;
		}
		this.ignore_euler = false;
		if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
		if(this.listen_x != null && !this.ignore_listeners) this.listen_x(this.x);
		if(this.listen_y != null && !this.ignore_listeners) this.listen_y(this.y);
		if(this.listen_z != null && !this.ignore_listeners) this.listen_z(this.z);
	}
	,set_x: function(_v) {
		this.x = _v;
		if(this._construct) return this.x;
		if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
		if(this.listen_x != null && !this.ignore_listeners) this.listen_x(this.x);
		return this.x;
	}
	,set_y: function(_v) {
		this.y = _v;
		if(this._construct) return this.y;
		if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
		if(this.listen_y != null && !this.ignore_listeners) this.listen_y(this.y);
		return this.y;
	}
	,set_z: function(_v) {
		this.z = _v;
		if(this._construct) return this.z;
		if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
		if(this.listen_z != null && !this.ignore_listeners) this.listen_z(this.z);
		return this.z;
	}
	,set_w: function(_v) {
		this.w = _v;
		if(this._construct) return this.w;
		if(this.euler == null || this.ignore_euler || this._construct) null; else this.euler.setEulerFromQuaternion(this,null);
		if(this.listen_w != null && !this.ignore_listeners) this.listen_w(this.w);
		return this.w;
	}
	,__class__: phoenix_Quaternion
	,__properties__: {set_w:"set_w",set_z:"set_z",set_y:"set_y",set_x:"set_x"}
};
var phoenix_Ray = function(_screen_pos,_camera,_viewport) {
	if(_viewport == null) _viewport = new phoenix_Rectangle(0,0,Luxe.core.screen.w,Luxe.core.screen.h);
	if(_camera == null) throw new js__$Boot_HaxeError("Camera required for a ray!");
	this.camera = _camera;
	this.viewport = _viewport;
	this.refresh(_screen_pos);
};
phoenix_Ray.__name__ = true;
phoenix_Ray.prototype = {
	refresh: function(_screen_pos) {
		var ndc_x = (_screen_pos.x / this.viewport.w - 0.5) * 2.0;
		var ndc_y = ((this.viewport.h - _screen_pos.y) / this.viewport.h - 0.5) * 2.0;
		var start_ndc = new phoenix_Vector(ndc_x,ndc_y,0.0,1.0);
		var end_ndc = new phoenix_Vector(ndc_x,ndc_y,1.0,1.0);
		this.origin = this.camera.unproject(start_ndc);
		this.end = this.camera.unproject(end_ndc);
		this.dir = phoenix_Vector.Subtract(this.end,this.origin);
	}
	,__class__: phoenix_Ray
};
var phoenix_Rectangle = function(_x,_y,_w,_h) {
	if(_h == null) _h = 0;
	if(_w == null) _w = 0;
	if(_y == null) _y = 0;
	if(_x == null) _x = 0;
	this.ignore_listeners = false;
	this.h = 0;
	this.w = 0;
	this.y = 0;
	this.x = 0;
	this.set_x(_x);
	this.set_y(_y);
	this.set_w(_w);
	this.set_h(_h);
};
phoenix_Rectangle.__name__ = true;
phoenix_Rectangle.listen = function(_r,listener) {
	_r.listen_x = listener;
	_r.listen_y = listener;
	_r.listen_w = listener;
	_r.listen_h = listener;
};
phoenix_Rectangle.prototype = {
	toString: function() {
		return "{ x:" + this.x + ", y:" + this.y + ", w:" + this.w + ", h:" + this.h + " }";
	}
	,point_inside: function(_p) {
		if(_p.x < this.x) return false;
		if(_p.y < this.y) return false;
		if(_p.x > this.x + this.w) return false;
		if(_p.y > this.y + this.h) return false;
		return true;
	}
	,overlaps: function(_other) {
		if(_other == null) return false;
		if(this.x < _other.x + _other.w && this.y < _other.y + _other.h && this.x + this.w > _other.x && this.y + this.h > _other.y) return true;
		return false;
	}
	,clone: function() {
		return new phoenix_Rectangle(this.x,this.y,this.w,this.h);
	}
	,equal: function(_other) {
		if(_other == null) return false;
		return this.x == _other.x && this.y == _other.y && this.w == _other.w && this.h == _other.h;
	}
	,copy_from: function(_rect) {
		this.set_x(_rect.x);
		this.set_y(_rect.y);
		this.set_w(_rect.w);
		this.set_h(_rect.h);
	}
	,set: function(_x,_y,_w,_h) {
		var _setx = this.x;
		var _sety = this.y;
		var _setw = this.w;
		var _seth = this.h;
		if(_x != null) _setx = _x;
		if(_y != null) _sety = _y;
		if(_w != null) _setw = _w;
		if(_h != null) _seth = _h;
		this.set_x(_setx);
		this.set_y(_sety);
		this.set_w(_setw);
		this.set_h(_seth);
		return this;
	}
	,set_x: function(_x) {
		this.x = _x;
		if(this.listen_x != null && !this.ignore_listeners) this.listen_x(_x);
		return this.x;
	}
	,set_y: function(_y) {
		this.y = _y;
		if(this.listen_y != null && !this.ignore_listeners) this.listen_y(_y);
		return this.y;
	}
	,set_w: function(_w) {
		this.w = _w;
		if(this.listen_w != null && !this.ignore_listeners) this.listen_w(_w);
		return this.w;
	}
	,set_h: function(_h) {
		this.h = _h;
		if(this.listen_h != null && !this.ignore_listeners) this.listen_h(_h);
		return this.h;
	}
	,__class__: phoenix_Rectangle
	,__properties__: {set_h:"set_h",set_w:"set_w",set_y:"set_y",set_x:"set_x"}
};
var phoenix_RenderPath = function(_renderer) {
	this.renderer = _renderer;
};
phoenix_RenderPath.__name__ = true;
phoenix_RenderPath.prototype = {
	render: function(_batchers,_stats) {
		var _g = 0;
		while(_g < _batchers.length) {
			var batch = _batchers[_g];
			++_g;
			if(batch.enabled) {
				Luxe.debug.start("batch." + batch.name);
				batch.draw();
				_stats.geometry_count += batch.geometry.size();
				_stats.dynamic_batched_count += batch.dynamic_batched_count;
				_stats.static_batched_count += batch.static_batched_count;
				_stats.visible_count += batch.visible_count;
				_stats.draw_calls += batch.draw_calls;
				_stats.vert_count += batch.vert_count;
				Luxe.debug.end("batch." + batch.name);
			}
		}
	}
	,__class__: phoenix_RenderPath
};
var phoenix_RenderState = function(_renderer) {
	this._last_depth_mask = true;
	this._last_line_width = 1;
	this._bound_texture_2D = null;
	this._active_texture = -1;
	this._used_program = null;
	this._current_rbo = null;
	this._current_fbo = null;
	this.depth_func = -1;
	this.depth_mask = true;
	this.depth_test = false;
	this.cull_face = false;
	this.renderer = _renderer;
	this._viewport = new phoenix_Rectangle(0,0,0,0);
};
phoenix_RenderState.__name__ = true;
phoenix_RenderState.prototype = {
	enable: function(what) {
		switch(what) {
		case 2884:
			if(!this.cull_face) {
				this.cull_face = true;
				snow_platform_web_render_opengl_GL.enable(2884);
			}
			break;
		case 2929:
			if(Luxe.core.app.config.render.depth) {
				if(!this.depth_test) {
					this.depth_test = true;
					snow_platform_web_render_opengl_GL.enable(2929);
				}
			}
			break;
		}
	}
	,disable: function(what) {
		switch(what) {
		case 2884:
			if(this.cull_face) {
				this.cull_face = false;
				snow_platform_web_render_opengl_GL.disable(2884);
			}
			break;
		case 2929:
			if(Luxe.core.app.config.render.depth) {
				if(this.depth_test) {
					this.depth_test = false;
					snow_platform_web_render_opengl_GL.disable(2929);
				}
			}
			break;
		}
	}
	,depth_function: function(what) {
		if(this.depth_func != this.depth_func) {
			snow_platform_web_render_opengl_GL.depthFunc(what);
			this.depth_func = what;
		}
	}
	,viewport: function(x,y,w,h) {
		if(this._viewport.x != x || this._viewport.y != y || this._viewport.w != w || this._viewport.h != h) {
			this._viewport.set_x(x);
			this._viewport.set_y(y);
			this._viewport.set_w(w);
			this._viewport.set_h(h);
			var _y = this.renderer.target_size.y - (y + h);
			snow_platform_web_render_opengl_GL.viewport(x | 0,_y | 0,w | 0,h | 0);
		}
	}
	,bindFramebuffer: function(buffer) {
		if(this._current_fbo != buffer) {
			if(buffer == null) buffer = this.renderer.default_fbo;
			snow_platform_web_render_opengl_GL.bindFramebuffer(36160,buffer);
			this._current_fbo = buffer;
		}
	}
	,bindRenderbuffer: function(buffer) {
		if(this._current_rbo != buffer) {
			if(buffer == null) buffer = this.renderer.default_rbo;
			snow_platform_web_render_opengl_GL.bindRenderbuffer(36161,buffer);
			this._current_rbo = buffer;
		}
	}
	,useProgram: function(program) {
		if(this._used_program != program) {
			this._used_program = program;
			snow_platform_web_render_opengl_GL.useProgram(program);
		}
	}
	,activeTexture: function(val) {
		if(this._active_texture != val) {
			snow_platform_web_render_opengl_GL.activeTexture(val);
			this._active_texture = val;
		}
	}
	,bindTexture2D: function(tex) {
		if(this._bound_texture_2D != tex) {
			this._bound_texture_2D = tex;
			snow_platform_web_render_opengl_GL.bindTexture(3553,tex);
		}
	}
	,lineWidth: function(_width) {
		if(this._last_line_width != _width) {
			this._last_line_width = _width;
			snow_platform_web_render_opengl_GL.lineWidth(_width);
		}
	}
	,depthMask: function(_enable) {
		if(this._last_depth_mask != _enable) {
			this._last_depth_mask = _enable;
			snow_platform_web_render_opengl_GL.depthMask(_enable);
		}
	}
	,__class__: phoenix_RenderState
};
var phoenix_Texture = function(_manager,_type) {
	this.slot = 0;
	this.loaded = false;
	this.height = -1;
	this.width = -1;
	this.height_actual = -1;
	this.width_actual = -1;
	if(_type == null) _type = 4;
	luxe_resource_Resource.call(this,_manager,_type);
	this._onload_handlers = [];
	this.id = Luxe.utils.uniqueid();
	this.set_filter(phoenix_FilterType.linear);
	this.set_clamp(phoenix_ClampType.edge);
};
phoenix_Texture.__name__ = true;
phoenix_Texture.load = function(_id,_onloaded,_silent) {
	if(_silent == null) _silent = false;
	var resources = Luxe.resources;
	var _exists = resources.find_texture(_id);
	if(_exists != null) {
		if(_onloaded != null) _onloaded(_exists);
		return _exists;
	}
	var texture = new phoenix_Texture(resources);
	if(_onloaded != null) texture.set_onload(_onloaded);
	var _asset = Luxe.core.app.assets.image(_id,{ onload : function(asset) {
		if(asset != null && asset.image != null) {
			texture.from_asset(asset);
			texture.reset();
			texture.do_onload();
			if(!_silent) haxe_Log.trace("  i / texture / " + ("loaded " + texture.id + " (" + texture.width + "x" + texture.height + ") real size (" + texture.width_actual + "x" + texture.height_actual + ")"),{ fileName : "Texture.hx", lineNumber : 150, className : "phoenix.Texture", methodName : "load"});
		} else if(!_silent) haxe_Log.trace("  i / texture / " + ("failed to load! " + _id),{ fileName : "Texture.hx", lineNumber : 155, className : "phoenix.Texture", methodName : "load"});
	}});
	if(_asset != null) {
		texture.id = _id;
		resources.cache(texture);
		return texture;
	}
	return null;
};
phoenix_Texture.load_from_resource = function(_name,_cache) {
	if(_cache == null) _cache = true;
	var texture_bytes = haxe_Resource.getBytes(_name);
	if(texture_bytes != null) {
		var texture = phoenix_Texture.load_from_bytes(_name,snow_io_typedarray__$Uint8Array_Uint8Array_$Impl_$.fromBytes(texture_bytes),_cache);
		texture_bytes = null;
		return texture;
	}
	return null;
};
phoenix_Texture.load_from_bytes = function(_name,_bytes,_cache) {
	if(_cache == null) _cache = true;
	if(_bytes != null) {
		var resources = Luxe.resources;
		var texture = new phoenix_Texture(resources);
		var _asset = Luxe.core.app.assets.image(_name,{ bytes : _bytes});
		if(_asset != null) {
			texture.from_asset(_asset);
			texture.reset();
			texture.do_onload();
			if(_cache) resources.cache(texture);
			return texture;
		}
	}
	return null;
};
phoenix_Texture.load_from_pixels = function(_id,_width,_height,_pixels,_cache) {
	if(_cache == null) _cache = true;
	if(_pixels == null) return null;
	var resources = Luxe.resources;
	var texture = new phoenix_Texture(resources);
	var _asset_info = Luxe.core.app.assets.info_from_id(_id,"image");
	var _asset = new snow_assets_AssetImage(Luxe.core.app.assets,_asset_info);
	_asset.load_from_pixels(_id,_width,_height,_pixels);
	texture.from_asset(_asset);
	texture.reset();
	texture.do_onload();
	if(_cache) resources.cache(texture);
	return texture;
};
phoenix_Texture.__super__ = luxe_resource_Resource;
phoenix_Texture.prototype = $extend(luxe_resource_Resource.prototype,{
	set_onload: function(f) {
		if(this.loaded) {
			f(this);
			return f;
		} else this._onload_handlers.push(f);
		return f;
	}
	,do_onload: function() {
		this.loaded = true;
		var _g = 0;
		var _g1 = this._onload_handlers;
		while(_g < _g1.length) {
			var f = _g1[_g];
			++_g;
			if(f != null) f(this);
		}
		this._onload_handlers.splice(0,this._onload_handlers.length);
	}
	,toString: function() {
		return "Texture (" + Std.string(this.texture) + ") (" + this.width + "x" + this.height + ") real size(" + this.width_actual + "x" + this.height_actual + ") " + Std.string(this.filter) + " filtering. " + Std.string(this.clamp) + " clamp. id: " + this.id;
	}
	,estimated_memory: function() {
		var _bytes = this.width_actual * this.height_actual * 4;
		return Luxe.utils.bytes_to_string(_bytes);
	}
	,check_size: function() {
		var max_size = snow_platform_web_render_opengl_GL.getParameter(3379);
		if(this.asset.image.width_actual > max_size) throw new js__$Boot_HaxeError("texture bigger than MAX_TEXTURE_SIZE (" + max_size + ") " + this.asset.id);
		if(this.asset.image.height_actual > max_size) throw new js__$Boot_HaxeError("texture bigger than MAX_TEXTURE_SIZE (" + max_size + ") " + this.asset.id);
	}
	,reset: function() {
		this.texture = snow_platform_web_render_opengl_GL.createTexture();
		this.bind();
		snow_platform_web_render_opengl_GL.texImage2D(3553,0,6408,this.width_actual,this.height_actual,0,6408,5121,this.asset.image.data);
		this._set_filter(this.filter);
		this._set_clamp(this.clamp);
	}
	,from_asset: function(_asset) {
		if(_asset == null) throw new js__$Boot_HaxeError("null asset passed to Texture.from_asset");
		this.asset = _asset;
		this.check_size();
		this.id = this.asset.id;
		this.width = this.asset.image.width;
		this.height = this.asset.image.height;
		this.width_actual = this.asset.image.width_actual;
		this.height_actual = this.asset.image.height_actual;
	}
	,generate_mipmaps: function() {
		var _g = this;
		this.set_onload(function(t) {
			_g.bind();
			snow_platform_web_render_opengl_GL.generateMipmap(3553);
		});
	}
	,bind: function() {
		Luxe.renderer.state.activeTexture(33984 + this.slot);
		Luxe.renderer.state.bindTexture2D(this.texture);
	}
	,get_pixel: function(_pos) {
		if(this.asset.image.data == null) return null;
		var x = _pos.x | 0;
		var y = _pos.y | 0;
		return { r : _$UInt_UInt_$Impl_$.toFloat(this.asset.image.data[(y * this.width + x) * 4]) / 255.0, g : _$UInt_UInt_$Impl_$.toFloat(this.asset.image.data[(y * this.width + x) * 4 + 1]) / 255.0, b : _$UInt_UInt_$Impl_$.toFloat(this.asset.image.data[(y * this.width + x) * 4 + 2]) / 255.0, a : _$UInt_UInt_$Impl_$.toFloat(this.asset.image.data[(y * this.width + x) * 4 + 3]) / 255.0};
	}
	,set_pixel: function(_pos,_color) {
		if(this.asset.image.data == null) return;
		var x = _pos.x | 0;
		var y = _pos.y | 0;
		this.asset.image.data[(y * this.width + x) * 4] = _color.r * 255 | 0;
		this.asset.image.data[(y * this.width + x) * 4 + 1] = _color.g * 255 | 0;
		this.asset.image.data[(y * this.width + x) * 4 + 2] = _color.b * 255 | 0;
		this.asset.image.data[(y * this.width + x) * 4 + 3] = _color.a * 255 | 0;
	}
	,lock: function() {
		return true;
	}
	,unlock: function() {
		if(this.asset.image.data != null) {
			Luxe.renderer.state.bindTexture2D(this.texture);
			snow_platform_web_render_opengl_GL.texImage2D(3553,0,6408,this.width,this.height,0,6408,5121,this.asset.image.data);
			this.asset.image.data = null;
		}
	}
	,drop: function() {
		luxe_resource_Resource.prototype.drop.call(this);
		this.destroy();
	}
	,activate: function(att) {
	}
	,destroy: function() {
		snow_platform_web_render_opengl_GL.deleteTexture(this.texture);
	}
	,_set_clamp: function(_clamp) {
		switch(_clamp[1]) {
		case 0:
			snow_platform_web_render_opengl_GL.texParameteri(3553,10242,33071);
			snow_platform_web_render_opengl_GL.texParameteri(3553,10243,33071);
			break;
		case 1:
			snow_platform_web_render_opengl_GL.texParameteri(3553,10242,10497);
			snow_platform_web_render_opengl_GL.texParameteri(3553,10243,10497);
			break;
		case 2:
			snow_platform_web_render_opengl_GL.texParameteri(3553,10242,33648);
			snow_platform_web_render_opengl_GL.texParameteri(3553,10243,33648);
			break;
		}
	}
	,set_clamp: function(_clamp) {
		var _g = this;
		if(this.clamp == null) return this.clamp = _clamp;
		if(this.loaded == false) this.set_onload(function(t) {
			_g.bind();
			_g._set_clamp(_clamp);
		}); else {
			this.bind();
			this._set_clamp(_clamp);
		}
		return _clamp;
	}
	,_set_filter: function(_filter) {
		switch(_filter[1]) {
		case 1:
			snow_platform_web_render_opengl_GL.texParameteri(3553,10241,9729);
			snow_platform_web_render_opengl_GL.texParameteri(3553,10240,9729);
			break;
		case 0:
			snow_platform_web_render_opengl_GL.texParameteri(3553,10241,9728);
			snow_platform_web_render_opengl_GL.texParameteri(3553,10240,9728);
			break;
		case 2:
			snow_platform_web_render_opengl_GL.texParameteri(3553,10241,9984);
			snow_platform_web_render_opengl_GL.texParameteri(3553,10240,9984);
			break;
		case 3:
			snow_platform_web_render_opengl_GL.texParameteri(3553,10241,9985);
			snow_platform_web_render_opengl_GL.texParameteri(3553,10240,9985);
			break;
		case 4:
			snow_platform_web_render_opengl_GL.texParameteri(3553,10241,9986);
			snow_platform_web_render_opengl_GL.texParameteri(3553,10240,9986);
			break;
		case 5:
			snow_platform_web_render_opengl_GL.texParameteri(3553,10241,9987);
			snow_platform_web_render_opengl_GL.texParameteri(3553,10240,9987);
			break;
		}
	}
	,_set_filter_min: function(_filter) {
		switch(_filter[1]) {
		case 1:
			snow_platform_web_render_opengl_GL.texParameteri(3553,10241,9729);
			break;
		case 0:
			snow_platform_web_render_opengl_GL.texParameteri(3553,10241,9728);
			break;
		case 2:
			snow_platform_web_render_opengl_GL.texParameteri(3553,10241,9984);
			break;
		case 3:
			snow_platform_web_render_opengl_GL.texParameteri(3553,10241,9985);
			break;
		case 4:
			snow_platform_web_render_opengl_GL.texParameteri(3553,10241,9986);
			break;
		case 5:
			snow_platform_web_render_opengl_GL.texParameteri(3553,10241,9987);
			break;
		}
	}
	,_set_filter_mag: function(_filter) {
		switch(_filter[1]) {
		case 1:
			snow_platform_web_render_opengl_GL.texParameteri(3553,10240,9729);
			break;
		case 0:
			snow_platform_web_render_opengl_GL.texParameteri(3553,10240,9728);
			break;
		case 2:
			snow_platform_web_render_opengl_GL.texParameteri(3553,10240,9984);
			break;
		case 3:
			snow_platform_web_render_opengl_GL.texParameteri(3553,10240,9985);
			break;
		case 4:
			snow_platform_web_render_opengl_GL.texParameteri(3553,10240,9986);
			break;
		case 5:
			snow_platform_web_render_opengl_GL.texParameteri(3553,10240,9987);
			break;
		}
	}
	,set_filter: function(_filter) {
		var _g = this;
		if(this.filter == null) return this.filter = _filter;
		if(this.loaded == false) this.set_onload(function(t) {
			_g.bind();
			_g._set_filter(_filter);
		}); else {
			this.bind();
			this._set_filter(_filter);
		}
		return this.filter = _filter;
	}
	,set_filter_min: function(_filter) {
		var _g = this;
		if(this.loaded == false) this.set_onload(function(t) {
			_g.bind();
			_g._set_filter_min(_filter);
		}); else {
			this.bind();
			this._set_filter_min(_filter);
		}
		return this.filter_min = _filter;
	}
	,set_filter_mag: function(_filter) {
		var _g = this;
		if(this.loaded == false) this.set_onload(function(t) {
			_g.bind();
			_g._set_filter_mag(_filter);
		}); else {
			this.bind();
			this._set_filter_mag(_filter);
		}
		return this.filter_mag = _filter;
	}
	,__class__: phoenix_Texture
	,__properties__: {set_clamp:"set_clamp",set_filter_mag:"set_filter_mag",set_filter_min:"set_filter_min",set_filter:"set_filter",set_onload:"set_onload"}
});
var phoenix_RenderTexture = function(_manager,_size) {
	phoenix_Texture.call(this,_manager,6);
	if(_size == null) new phoenix_Vector(Luxe.core.screen.w,Luxe.core.screen.h); else _size;
	this.width = this.width_actual = _size.x | 0;
	this.height = this.height_actual = _size.y | 0;
	this.texture = snow_platform_web_render_opengl_GL.createTexture();
	this.bind();
	snow_platform_web_render_opengl_GL.texImage2D(3553,0,6408,this.width,this.height,0,6408,5121,null);
	this._set_filter(phoenix_FilterType.linear);
	this._set_clamp(phoenix_ClampType.edge);
	this.fbo = snow_platform_web_render_opengl_GL.createFramebuffer();
	this.bindBuffer();
	this.renderbuffer = snow_platform_web_render_opengl_GL.createRenderbuffer();
	this.bindRenderBuffer();
	snow_platform_web_render_opengl_GL.renderbufferStorage(36161,33189,this.width,this.height);
	snow_platform_web_render_opengl_GL.framebufferTexture2D(36160,36064,3553,this.texture,0);
	snow_platform_web_render_opengl_GL.framebufferRenderbuffer(36160,36096,36161,this.renderbuffer);
	var status = snow_platform_web_render_opengl_GL.checkFramebufferStatus(36160);
	switch(status) {
	case 36053:
		break;
	case 36054:
		throw new js__$Boot_HaxeError("Incomplete framebuffer: FRAMEBUFFER_INCOMPLETE_ATTACHMENT");
		break;
	case 36055:
		throw new js__$Boot_HaxeError("Incomplete framebuffer: FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT");
		break;
	case 36057:
		throw new js__$Boot_HaxeError("Incomplete framebuffer: FRAMEBUFFER_INCOMPLETE_DIMENSIONS");
		break;
	case 36061:
		throw new js__$Boot_HaxeError("Incomplete framebuffer: FRAMEBUFFER_UNSUPPORTED");
		break;
	default:
		throw new js__$Boot_HaxeError("Incomplete framebuffer: " + status);
	}
	this.unbindBuffer();
	this.unbindRenderBuffer();
	this.loaded = true;
};
phoenix_RenderTexture.__name__ = true;
phoenix_RenderTexture.__super__ = phoenix_Texture;
phoenix_RenderTexture.prototype = $extend(phoenix_Texture.prototype,{
	destroy: function() {
		snow_platform_web_render_opengl_GL.deleteFramebuffer(this.fbo);
		snow_platform_web_render_opengl_GL.deleteRenderbuffer(this.renderbuffer);
		phoenix_Texture.prototype.destroy.call(this);
	}
	,bindBuffer: function() {
		Luxe.renderer.state.bindFramebuffer(this.fbo);
	}
	,unbindBuffer: function(_other) {
		Luxe.renderer.state.bindFramebuffer(_other);
	}
	,bindRenderBuffer: function() {
		Luxe.renderer.state.bindRenderbuffer(this.renderbuffer);
	}
	,unbindRenderBuffer: function(_other) {
		Luxe.renderer.state.bindRenderbuffer(_other);
	}
	,__class__: phoenix_RenderTexture
});
var phoenix_Renderer = function(_core) {
	this.stop_count = 0;
	this.stop = false;
	this.should_clear = true;
	this.core = _core;
	this.default_fbo = snow_platform_web_render_opengl_GL.getParameter(36006);
	this.default_rbo = snow_platform_web_render_opengl_GL.getParameter(36007);
	null;
};
phoenix_Renderer.__name__ = true;
phoenix_Renderer.prototype = {
	init: function() {
		this.state = new phoenix_RenderState(this);
		this.clear_color = new phoenix_Color().rgb(1710618);
		this.stats = new phoenix_RendererStats();
		this.batchers = [];
		this.target_size = new phoenix_Vector(Luxe.core.screen.w,Luxe.core.screen.h);
		this.camera = new phoenix_Camera();
		this.default_render_path = new phoenix_RenderPath(this);
		this.render_path = this.default_render_path;
		this.create_default_shaders();
		this.batcher = new phoenix_Batcher(this,"default batcher");
		this.batcher.set_layer(1);
		this.add_batch(this.batcher);
		this.create_default_font();
		if(Luxe.core.app.config.render.depth) {
			this.state.enable(2929);
			this.state.depth_function(515);
			snow_platform_web_render_opengl_GL.clearDepth(1.0);
		}
		snow_platform_web_render_opengl_GL.enable(3042);
		snow_platform_web_render_opengl_GL.blendFunc(770,771);
		snow_platform_web_render_opengl_GL.pixelStorei(37441,0);
	}
	,destroy: function() {
		this.clear(new phoenix_Color().rgb(16729099));
	}
	,sort_batchers: function(a,b) {
		if(a.layer < b.layer) return -1;
		if(a.layer > b.layer) return 1;
		if(a.sequence < b.sequence) return -1;
		if(a.sequence > b.sequence) return 1;
		return 1;
	}
	,add_batch: function(batch) {
		this.batchers.push(batch);
		this.batchers.sort($bind(this,this.sort_batchers));
	}
	,remove_batch: function(batch) {
		HxOverrides.remove(this.batchers,batch);
	}
	,create_batcher: function(options) {
		var _new_batcher_layer = 2;
		if(options != null) {
			if(options.name == null) options.name = "batcher";
			if(options.layer == null) options.layer = _new_batcher_layer;
			if(options.camera == null) options.camera = new phoenix_Camera();
		} else options = { name : "batcher", camera : new phoenix_Camera(), layer : _new_batcher_layer};
		var _batcher = new phoenix_Batcher(this,options.name);
		_batcher.view = options.camera;
		_batcher.set_layer(options.layer);
		if(options.no_add == null || options.no_add == false) this.add_batch(_batcher);
		return _batcher;
	}
	,clear: function(_color) {
		if(_color == null) _color = this.clear_color;
		snow_platform_web_render_opengl_GL.clearColor(_color.r,_color.g,_color.b,_color.a);
		if(Luxe.core.app.config.render.depth) {
			snow_platform_web_render_opengl_GL.clear(16640);
			snow_platform_web_render_opengl_GL.clearDepth(1.0);
		} else snow_platform_web_render_opengl_GL.clear(16384);
	}
	,blend_mode: function(_src_mode,_dst_mode) {
		if(_dst_mode == null) _dst_mode = 771;
		if(_src_mode == null) _src_mode = 770;
		snow_platform_web_render_opengl_GL.blendFunc(_src_mode,_dst_mode);
	}
	,blend_equation: function(_equation) {
		if(_equation == null) _equation = 32774;
		snow_platform_web_render_opengl_GL.blendEquation(_equation);
	}
	,internal_resized: function(_w,_h) {
		if(this.get_target() == null) this.target_size.set_xy(_w,_h);
	}
	,process: function() {
		if(this.stop) return;
		if(this.should_clear) this.clear(this.clear_color);
		this.stats.batchers = this.batchers.length;
		this.stats.reset();
		this.render_path.render(this.batchers,this.stats);
	}
	,onresize: function(e) {
	}
	,set_vsync: function(_vsync) {
		Luxe.core.app.windowing.enable_vsync(_vsync);
		return this.vsync = _vsync;
	}
	,get_vsync: function() {
		return this.vsync;
	}
	,get_target: function() {
		return this.target;
	}
	,set_target: function(_target) {
		if(_target != null) {
			this.target_size.set_x(_target.width);
			this.target_size.set_y(_target.height);
			this.state.bindFramebuffer(_target.fbo);
		} else {
			this.target_size.set_x(Luxe.core.screen.w);
			this.target_size.set_y(Luxe.core.screen.h);
			this.state.bindFramebuffer();
		}
		return this.target = _target;
	}
	,create_default_shaders: function() {
		var vert = haxe_Resource.getString("default.vert.glsl");
		var frag = haxe_Resource.getString("default.frag.glsl");
		var frag_textured = haxe_Resource.getString("default.frag.textured.glsl");
		var frag_bitmapfont = haxe_Resource.getString("default.frag.bitmapfont.glsl");
		var ext = snow_platform_web_render_opengl_GL.current_context.getExtension("OES_standard_derivatives");
		frag = "precision mediump float;\n" + frag;
		frag_textured = "precision mediump float;\n" + frag_textured;
		frag_bitmapfont = "#extension GL_OES_standard_derivatives : enable\n#extension OES_standard_derivatives : enable\nprecision mediump float;\n" + frag_bitmapfont;
		var _plain = new phoenix_Shader(this.core.resources);
		var _textured = new phoenix_Shader(this.core.resources);
		var _font = new phoenix_Shader(this.core.resources);
		var _dvs = "default vertex shader";
		_plain.id = "default_shader";
		_textured.id = "default_shader_textured";
		_font.id = "default_shader_bitmapfont";
		_plain.from_string(vert,frag,_dvs,"default fragment shader",false);
		_textured.from_string(vert,frag_textured,_dvs,"default textured shader",false);
		_font.from_string(vert,frag_bitmapfont,_dvs,"default bitmapfont shader",false);
		this.shaders = { plain : { shader : _plain, source : { vert : vert, frag : frag}}, textured : { shader : _textured, source : { vert : vert, frag : frag_textured}}, bitmapfont : { shader : _font, source : { vert : vert, frag : frag_bitmapfont}}};
		null;
	}
	,create_default_font: function() {
		this.font = new phoenix_BitmapFont({ id : "default", resources : this.core.resources});
		var _font_texture = phoenix_Texture.load_from_resource("default.png");
		_font_texture.set_filter_min(phoenix_FilterType.linear);
		this.font.from_string(haxe_Resource.getString("default.fnt"),null,[_font_texture]);
		null;
	}
	,__class__: phoenix_Renderer
	,__properties__: {set_target:"set_target",get_target:"get_target",set_vsync:"set_vsync",get_vsync:"get_vsync"}
};
var phoenix_RendererStats = function() {
	this.vert_count = 0;
	this.group_count = 0;
	this.draw_calls = 0;
	this.visible_count = 0;
	this.static_batched_count = 0;
	this.dynamic_batched_count = 0;
	this.geometry_count = 0;
	this.batchers = 0;
};
phoenix_RendererStats.__name__ = true;
phoenix_RendererStats.prototype = {
	reset: function() {
		this.geometry_count = 0;
		this.dynamic_batched_count = 0;
		this.static_batched_count = 0;
		this.visible_count = 0;
		this.group_count = 0;
		this.draw_calls = 0;
		this.vert_count = 0;
	}
	,toString: function() {
		return "Renderer Statistics\n" + "\tbatcher count : " + this.batchers + "\n" + "\ttotal geometry : " + this.geometry_count + "\n" + "\tvisible geometry : " + this.visible_count + "\n" + "\tdynamic batched geometry : " + this.dynamic_batched_count + "\n" + "\tstatic batched geometry : " + this.static_batched_count + "\n" + "\ttotal draw calls : " + this.draw_calls + "\n" + "\ttotal vertices : " + this.vert_count;
	}
	,__class__: phoenix_RendererStats
};
var phoenix_Shader = function(_manager) {
	this.normal_attribute = 3;
	this.color_attribute = 2;
	this.tcoord_attribute = 1;
	this.vert_attribute = 0;
	this.frag_source_name = "";
	this.vertex_source_name = "";
	this.frag_source = "";
	this.vertex_source = "";
	this.log = "";
	this.errors = "";
	luxe_resource_Resource.call(this,_manager,8);
	this.uniforms = new haxe_ds_StringMap();
	this.uniform_textures = new haxe_ds_StringMap();
};
phoenix_Shader.__name__ = true;
phoenix_Shader.load = function(_psid,_vsid,_onload,_silent) {
	if(_silent == null) _silent = false;
	var _shader = new phoenix_Shader(Luxe.resources);
	var _frag_shader = "";
	var _vert_shader = "";
	if(_vsid == "default" || _vsid == "") {
		_vert_shader = Luxe.renderer.shaders.plain.source.vert;
		null;
	}
	if(_psid == "default" || _psid == "") {
		_frag_shader = Luxe.renderer.shaders.plain.source.frag;
		null;
	} else if(_psid == "textured") {
		_frag_shader = Luxe.renderer.shaders.textured.source.frag;
		null;
	}
	if(_vert_shader.length == 0) Luxe.loadText(_vsid,function(_vert_asset) {
		_vert_shader = _vert_asset.text;
		if(_vert_shader.length == 0) null; else if(_frag_shader.length == 0) null; else {
			_shader.from_string(_vert_shader,_frag_shader,_vsid,_psid,false);
			Luxe.resources.cache(_shader);
			if(_onload != null) _onload(_shader);
			if(!_silent) null;
		}
	});
	if(_frag_shader.length == 0) Luxe.loadText(_psid,function(_frag_asset) {
		var prefixes = "precision mediump float;\n";
		_frag_shader = prefixes + _frag_asset.text;
		if(_vert_shader.length == 0) null; else if(_frag_shader.length == 0) null; else {
			_shader.from_string(_vert_shader,_frag_shader,_vsid,_psid,false);
			Luxe.resources.cache(_shader);
			if(_onload != null) _onload(_shader);
			if(!_silent) null;
		}
	});
	_shader.id = _psid + "|" + _vsid;
	return _shader;
};
phoenix_Shader.__super__ = luxe_resource_Resource;
phoenix_Shader.prototype = $extend(luxe_resource_Resource.prototype,{
	activate: function() {
		if(this.program != null) Luxe.renderer.state.useProgram(this.program);
	}
	,deactivate: function() {
		Luxe.renderer.state.useProgram(null);
	}
	,clone: function() {
		var _clone = new phoenix_Shader(this.manager);
		_clone.id = this.id + ".clone." + Luxe.utils.uniqueid();
		_clone.from_string(this.vertex_source,this.frag_source,this.vertex_source_name,this.frag_source_name,false);
		return _clone;
	}
	,set_int: function(_name,_value) {
		if(this.uniforms.exists(_name)) {
			var _uniform = this.uniforms.get(_name);
			_uniform.value = _value;
		} else {
			var _uniform1 = { name : _name, value : _value, type : 1, location : snow_platform_web_render_opengl_GL.getUniformLocation(this.program,_name)};
			this.uniforms.set(_name,_uniform1);
		}
	}
	,set_float: function(_name,_value) {
		if(this.uniforms.exists(_name)) {
			var _uniform = this.uniforms.get(_name);
			_uniform.value = _value;
		} else {
			var _uniform1 = { name : _name, value : _value, type : 2, location : snow_platform_web_render_opengl_GL.getUniformLocation(this.program,_name)};
			this.uniforms.set(_name,_uniform1);
		}
	}
	,set_vector2: function(_name,_value) {
		if(this.uniforms.exists(_name)) {
			var _uniform = this.uniforms.get(_name);
			_uniform.value = _value;
		} else {
			var _uniform1 = { name : _name, value : _value, type : 3, location : snow_platform_web_render_opengl_GL.getUniformLocation(this.program,_name)};
			this.uniforms.set(_name,_uniform1);
		}
	}
	,set_vector3: function(_name,_value) {
		if(this.uniforms.exists(_name)) {
			var _uniform = this.uniforms.get(_name);
			_uniform.value = _value;
		} else {
			var _uniform1 = { name : _name, value : _value, type : 4, location : snow_platform_web_render_opengl_GL.getUniformLocation(this.program,_name)};
			this.uniforms.set(_name,_uniform1);
		}
	}
	,set_vector4: function(_name,_value) {
		if(this.uniforms.exists(_name)) {
			var _uniform = this.uniforms.get(_name);
			_uniform.value = _value;
		} else {
			var _uniform1 = { name : _name, value : _value, type : 5, location : snow_platform_web_render_opengl_GL.getUniformLocation(this.program,_name)};
			this.uniforms.set(_name,_uniform1);
		}
	}
	,set_color: function(_name,_value) {
		if(this.uniforms.exists(_name)) {
			var _uniform = this.uniforms.get(_name);
			_uniform.value = _value;
		} else {
			var _uniform1 = { name : _name, value : _value, type : 6, location : snow_platform_web_render_opengl_GL.getUniformLocation(this.program,_name)};
			this.uniforms.set(_name,_uniform1);
		}
	}
	,set_texture: function(_name,_value) {
		if(this.uniforms.exists(_name)) {
			var _uniform = this.uniforms.get(_name);
			_uniform.value = _value;
			this.uniform_textures.set(_name,_value);
		} else {
			var _uniform1 = { name : _name, value : _value, type : 7, location : snow_platform_web_render_opengl_GL.getUniformLocation(this.program,_name)};
			this.uniforms.set(_name,_uniform1);
			this.uniform_textures.set(_name,_value);
		}
	}
	,compile: function(_type,_source,_verbose) {
		if(_verbose == null) _verbose = false;
		var _shader = snow_platform_web_render_opengl_GL.createShader(_type);
		snow_platform_web_render_opengl_GL.shaderSource(_shader,_source);
		snow_platform_web_render_opengl_GL.compileShader(_shader);
		var shader_log = "";
		if(_verbose) {
			shader_log = snow_platform_web_render_opengl_GL.getShaderInfoLog(_shader);
			if(shader_log.length > 0) {
				this.log += "\n\t :: start -- (" + (_type == 35632?"fragment":"vertex") + ") Shader compile log -- " + this.id + "\n";
				this.log += "\t\t" + shader_log + "\n";
				this.log += "\t :: end -- (" + (_type == 35632?"fragment":"vertex") + ") Shader compile log -- " + this.id;
			}
		}
		if(snow_platform_web_render_opengl_GL.getShaderParameter(_shader,35713) == 0) {
			var _info;
			if(_type == 35632) _info = "fragment"; else _info = "vertex";
			if(_type == 35632) _info += "(" + this.frag_source_name + ")"; else _info += "(" + this.vertex_source_name + ")";
			this.errors += "\tFailed to compile shader (" + _info + ") : \n";
			if(!_verbose) shader_log = snow_platform_web_render_opengl_GL.getShaderInfoLog(_shader);
			this.errors += "\t\t" + shader_log;
			snow_platform_web_render_opengl_GL.deleteShader(_shader);
			_shader = null;
			return null;
		}
		return _shader;
	}
	,link: function() {
		this.program = snow_platform_web_render_opengl_GL.createProgram();
		snow_platform_web_render_opengl_GL.attachShader(this.program,this.vert_shader);
		snow_platform_web_render_opengl_GL.attachShader(this.program,this.frag_shader);
		snow_platform_web_render_opengl_GL.bindAttribLocation(this.program,this.vert_attribute,"vertexPosition");
		snow_platform_web_render_opengl_GL.bindAttribLocation(this.program,this.tcoord_attribute,"vertexTCoord");
		snow_platform_web_render_opengl_GL.bindAttribLocation(this.program,this.color_attribute,"vertexColor");
		snow_platform_web_render_opengl_GL.bindAttribLocation(this.program,this.normal_attribute,"vertexNormal");
		snow_platform_web_render_opengl_GL.linkProgram(this.program);
		if(snow_platform_web_render_opengl_GL.getProgramParameter(this.program,35714) == 0) {
			this.errors += "\tFailed to link shader program:";
			this.add_error("\t\t" + snow_platform_web_render_opengl_GL.getProgramInfoLog(this.program));
			snow_platform_web_render_opengl_GL.deleteProgram(this.program);
			this.program = null;
			return;
		}
		this.activate();
		this.projectionmatrix_attribute = snow_platform_web_render_opengl_GL.getUniformLocation(this.program,"projectionMatrix");
		this.modelviewmatrix_attribute = snow_platform_web_render_opengl_GL.getUniformLocation(this.program,"modelViewMatrix");
		this.tex0_attribute = snow_platform_web_render_opengl_GL.getUniformLocation(this.program,"tex0");
		this.tex1_attribute = snow_platform_web_render_opengl_GL.getUniformLocation(this.program,"tex1");
		this.tex2_attribute = snow_platform_web_render_opengl_GL.getUniformLocation(this.program,"tex2");
		this.tex3_attribute = snow_platform_web_render_opengl_GL.getUniformLocation(this.program,"tex3");
		this.tex4_attribute = snow_platform_web_render_opengl_GL.getUniformLocation(this.program,"tex4");
		this.tex5_attribute = snow_platform_web_render_opengl_GL.getUniformLocation(this.program,"tex5");
		this.tex6_attribute = snow_platform_web_render_opengl_GL.getUniformLocation(this.program,"tex6");
		this.tex7_attribute = snow_platform_web_render_opengl_GL.getUniformLocation(this.program,"tex7");
	}
	,drop: function() {
		luxe_resource_Resource.prototype.drop.call(this);
		this.destroy();
	}
	,destroy: function() {
		if(this.vert_shader != null) snow_platform_web_render_opengl_GL.deleteShader(this.vert_shader);
		if(this.frag_shader != null) snow_platform_web_render_opengl_GL.deleteShader(this.frag_shader);
		if(this.program != null) snow_platform_web_render_opengl_GL.deleteProgram(this.program);
	}
	,from_string: function(_vertex_source,_fragment_source,_vertex_name,_frag_name,_verbose) {
		if(_verbose == null) _verbose = false;
		if(_frag_name == null) _frag_name = "";
		if(_vertex_name == null) _vertex_name = "";
		var _g = this;
		this.destroy();
		this.frag_source = _fragment_source;
		this.vertex_source = _vertex_source;
		this.frag_source_name = _frag_name;
		this.vertex_source_name = _vertex_name;
		this.vert_shader = this.compile(35633,this.vertex_source,_verbose);
		this.frag_shader = this.compile(35632,this.frag_source,_verbose);
		if(this.vert_shader == null || this.frag_shader == null) {
			haxe_Log.trace("   i / shader / " + ("failed to create shader : " + _g.id + "\n\n" + _g.log + "\n" + _g.errors),{ fileName : "Shader.hx", lineNumber : 419, className : "phoenix.Shader", methodName : "from_string"});
			throw new js__$Boot_HaxeError(":( shader errors ");
		}
		this.link();
		if(this.program == null) {
			haxe_Log.trace("   i / shader / " + ("failed to create shader : " + _g.id + "\n\n" + _g.log + "\n" + _g.errors),{ fileName : "Shader.hx", lineNumber : 419, className : "phoenix.Shader", methodName : "from_string"});
			throw new js__$Boot_HaxeError(":( shader errors ");
		} else if(_verbose && this.log.length > 0) haxe_Log.trace("   i / shader / " + this.log,{ fileName : "Shader.hx", lineNumber : 436, className : "phoenix.Shader", methodName : "from_string"});
		if(this.program == null) return false;
		return true;
	}
	,toString: function() {
		return "Shader(" + this.id + ") vert:" + this.vertex_source_name + " / frag: " + this.frag_source_name;
	}
	,apply_uniforms: function() {
		snow_platform_web_render_opengl_GL.uniform1i(this.tex0_attribute,0);
		snow_platform_web_render_opengl_GL.uniform1i(this.tex1_attribute,1);
		snow_platform_web_render_opengl_GL.uniform1i(this.tex2_attribute,2);
		snow_platform_web_render_opengl_GL.uniform1i(this.tex3_attribute,3);
		snow_platform_web_render_opengl_GL.uniform1i(this.tex4_attribute,4);
		snow_platform_web_render_opengl_GL.uniform1i(this.tex5_attribute,5);
		snow_platform_web_render_opengl_GL.uniform1i(this.tex6_attribute,6);
		snow_platform_web_render_opengl_GL.uniform1i(this.tex7_attribute,7);
		var $it0 = this.uniforms.iterator();
		while( $it0.hasNext() ) {
			var uniform = $it0.next();
			var _g = uniform.type;
			switch(_g) {
			case 1:
				this.apply_int(uniform.location,uniform.value);
				break;
			case 2:
				this.apply_float(uniform.location,uniform.value);
				break;
			case 3:
				this.apply_vec2(uniform.location,uniform.value);
				break;
			case 4:
				this.apply_vec3(uniform.location,uniform.value);
				break;
			case 5:
				this.apply_vec4(uniform.location,uniform.value);
				break;
			case 6:
				this.apply_color(uniform.location,uniform.value);
				break;
			case 7:
				this.apply_texture(uniform.location,uniform.value);
				break;
			case 0:
				break;
			}
		}
	}
	,location: function(_name) {
		return snow_platform_web_render_opengl_GL.getUniformLocation(this.program,_name);
	}
	,apply_int: function(_location,_int) {
		snow_platform_web_render_opengl_GL.uniform1i(_location,_int);
	}
	,apply_float: function(_location,_float) {
		snow_platform_web_render_opengl_GL.uniform1f(_location,_float);
	}
	,apply_vec2: function(_location,_vec) {
		snow_platform_web_render_opengl_GL.uniform2f(_location,_vec.x,_vec.y);
	}
	,apply_vec3: function(_location,_vec) {
		snow_platform_web_render_opengl_GL.uniform3f(_location,_vec.x,_vec.y,_vec.z);
	}
	,apply_vec4: function(_location,_vec) {
		snow_platform_web_render_opengl_GL.uniform4f(_location,_vec.x,_vec.y,_vec.z,_vec.w);
	}
	,apply_color: function(_location,_color) {
		snow_platform_web_render_opengl_GL.uniform4f(_location,_color.r,_color.g,_color.b,_color.a);
	}
	,apply_texture: function(_location,_tex) {
		snow_platform_web_render_opengl_GL.uniform1i(_location,_tex.slot);
		_tex.bind();
	}
	,add_log: function(_log) {
		this.log += _log;
	}
	,add_error: function(_error) {
		this.errors += _error;
	}
	,__class__: phoenix_Shader
});
var phoenix_FilterType = { __ename__ : true, __constructs__ : ["nearest","linear","mip_nearest_nearest","mip_linear_nearest","mip_nearest_linear","mip_linear_linear"] };
phoenix_FilterType.nearest = ["nearest",0];
phoenix_FilterType.nearest.toString = $estr;
phoenix_FilterType.nearest.__enum__ = phoenix_FilterType;
phoenix_FilterType.linear = ["linear",1];
phoenix_FilterType.linear.toString = $estr;
phoenix_FilterType.linear.__enum__ = phoenix_FilterType;
phoenix_FilterType.mip_nearest_nearest = ["mip_nearest_nearest",2];
phoenix_FilterType.mip_nearest_nearest.toString = $estr;
phoenix_FilterType.mip_nearest_nearest.__enum__ = phoenix_FilterType;
phoenix_FilterType.mip_linear_nearest = ["mip_linear_nearest",3];
phoenix_FilterType.mip_linear_nearest.toString = $estr;
phoenix_FilterType.mip_linear_nearest.__enum__ = phoenix_FilterType;
phoenix_FilterType.mip_nearest_linear = ["mip_nearest_linear",4];
phoenix_FilterType.mip_nearest_linear.toString = $estr;
phoenix_FilterType.mip_nearest_linear.__enum__ = phoenix_FilterType;
phoenix_FilterType.mip_linear_linear = ["mip_linear_linear",5];
phoenix_FilterType.mip_linear_linear.toString = $estr;
phoenix_FilterType.mip_linear_linear.__enum__ = phoenix_FilterType;
var phoenix_ClampType = { __ename__ : true, __constructs__ : ["edge","repeat","mirror"] };
phoenix_ClampType.edge = ["edge",0];
phoenix_ClampType.edge.toString = $estr;
phoenix_ClampType.edge.__enum__ = phoenix_ClampType;
phoenix_ClampType.repeat = ["repeat",1];
phoenix_ClampType.repeat.toString = $estr;
phoenix_ClampType.repeat.__enum__ = phoenix_ClampType;
phoenix_ClampType.mirror = ["mirror",2];
phoenix_ClampType.mirror.toString = $estr;
phoenix_ClampType.mirror.__enum__ = phoenix_ClampType;
var phoenix_Transform = function() {
	this._destroying = false;
	this._cleaning = false;
	this._setup = true;
	this.dirty = true;
	luxe_ID.call(this,"transform");
	this.set_local(new phoenix_Spatial());
	this.set_world(new phoenix_Spatial());
	this._origin_undo_matrix = new phoenix_Matrix();
	this._pos_matrix = new phoenix_Matrix();
	this._rotation_matrix = new phoenix_Matrix();
	this.set_origin(new phoenix_Vector());
	this.local.pos_changed = $bind(this,this.on_local_pos_change);
	this.local.rotation_changed = $bind(this,this.on_local_rotation_change);
	this.local.scale_changed = $bind(this,this.on_local_scale_change);
	this._setup = false;
};
phoenix_Transform.__name__ = true;
phoenix_Transform.__super__ = luxe_ID;
phoenix_Transform.prototype = $extend(luxe_ID.prototype,{
	destroy: function() {
		this._destroying = true;
		if(this.parent != null) this.parent.unlisten($bind(this,this.on_parent_cleaned));
		this._clean_handlers = null;
		this._dirty_handlers = null;
		this._pos_handlers = null;
		this._rotation_handlers = null;
		this._scale_handlers = null;
		this._origin_handlers = null;
		this._parent_handlers = null;
		this.local.destroy();
		((function($this) {
			var $r;
			if(!$this._destroying) {
				if($this.parent != null) {
					if($this.parent.dirty) $this.parent.clean();
				}
				if($this.dirty && !$this._cleaning) {
					if(!$this.dirty) null; else {
						$this._cleaning = true;
						$this._pos_matrix.makeTranslation($this.local.pos.x,$this.local.pos.y,$this.local.pos.z);
						$this._rotation_matrix.makeRotationFromQuaternion($this.local.rotation);
						$this._origin_undo_matrix.makeTranslation(-$this.origin.x,-$this.origin.y,-$this.origin.z);
						$this.local.matrix.makeTranslation($this.origin.x,$this.origin.y,$this.origin.z);
						$this.local.matrix.scale($this.local.scale);
						$this.local.matrix.multiply($this._rotation_matrix);
						$this.local.matrix.setPosition($this.local.pos);
						$this.local.matrix.multiply($this._origin_undo_matrix);
						if($this.parent != null) $this.get_world().set_matrix($this.get_world().get_matrix().multiplyMatrices($this.parent.get_world().get_matrix(),$this.local.matrix)); else $this.get_world().set_matrix($this.local.matrix.clone());
						$this.get_world().decompose(false);
						$this.dirty = false;
						if($this.dirty && !$this._setup && $this._dirty_handlers != null && $this._dirty_handlers.length > 0) $this.propagate_dirty();
						$this.dirty;
						$this._cleaning = false;
						if($this._clean_handlers != null && $this._clean_handlers.length > 0) $this.propagate_clean();
					}
				}
			}
			$r = $this.world;
			return $r;
		}(this))).destroy();
		this.local = null;
		this.world = null;
		this.dirty = true;
		if(this.dirty && !this._setup && this._dirty_handlers != null && this._dirty_handlers.length > 0) this.propagate_dirty();
		this.dirty;
		this.origin = null;
		if(this._origin_handlers != null && this._origin_handlers.length > 0) this.propagate_origin(this.origin);
		this.origin;
		this._origin_undo_matrix = null;
		this._pos_matrix = null;
		this._rotation_matrix = null;
	}
	,set_dirty: function(_dirty) {
		this.dirty = _dirty;
		if(this.dirty && !this._setup && this._dirty_handlers != null && this._dirty_handlers.length > 0) this.propagate_dirty();
		return this.dirty;
	}
	,on_local_pos_change: function(v) {
		this.dirty = true;
		if(this.dirty && !this._setup && this._dirty_handlers != null && this._dirty_handlers.length > 0) this.propagate_dirty();
		this.dirty;
		if(this._pos_handlers != null && this._pos_handlers.length > 0) this.propagate_pos(v);
	}
	,on_local_rotation_change: function(r) {
		this.dirty = true;
		if(this.dirty && !this._setup && this._dirty_handlers != null && this._dirty_handlers.length > 0) this.propagate_dirty();
		this.dirty;
		if(this._rotation_handlers != null && this._rotation_handlers.length > 0) this.propagate_rotation(r);
	}
	,on_local_scale_change: function(s) {
		this.dirty = true;
		if(this.dirty && !this._setup && this._dirty_handlers != null && this._dirty_handlers.length > 0) this.propagate_dirty();
		this.dirty;
		if(this._scale_handlers != null && this._scale_handlers.length > 0) this.propagate_scale(s);
	}
	,on_parent_cleaned: function(p) {
		this.dirty = true;
		if(this.dirty && !this._setup && this._dirty_handlers != null && this._dirty_handlers.length > 0) this.propagate_dirty();
		this.dirty;
	}
	,get_local: function() {
		return this.local;
	}
	,set_local: function(l) {
		if(l != null) {
			this.dirty = true;
			if(this.dirty && !this._setup && this._dirty_handlers != null && this._dirty_handlers.length > 0) this.propagate_dirty();
			this.dirty;
			l.pos_changed = $bind(this,this.on_local_pos_change);
			l.rotation_changed = $bind(this,this.on_local_rotation_change);
			l.scale_changed = $bind(this,this.on_local_scale_change);
		}
		return this.local = l;
	}
	,get_world: function() {
		if(!this._destroying) {
			if(this.parent != null) {
				if(this.parent.dirty) this.parent.clean();
			}
			if(this.dirty && !this._cleaning) {
				if(!this.dirty) null; else {
					this._cleaning = true;
					this._pos_matrix.makeTranslation(this.local.pos.x,this.local.pos.y,this.local.pos.z);
					this._rotation_matrix.makeRotationFromQuaternion(this.local.rotation);
					this._origin_undo_matrix.makeTranslation(-this.origin.x,-this.origin.y,-this.origin.z);
					this.local.matrix.makeTranslation(this.origin.x,this.origin.y,this.origin.z);
					this.local.matrix.scale(this.local.scale);
					this.local.matrix.multiply(this._rotation_matrix);
					this.local.matrix.setPosition(this.local.pos);
					this.local.matrix.multiply(this._origin_undo_matrix);
					if(this.parent != null) this.get_world().set_matrix(this.get_world().get_matrix().multiplyMatrices(this.parent.get_world().get_matrix(),this.local.matrix)); else this.get_world().set_matrix(this.local.matrix.clone());
					this.get_world().decompose(false);
					this.dirty = false;
					if(this.dirty && !this._setup && this._dirty_handlers != null && this._dirty_handlers.length > 0) this.propagate_dirty();
					this.dirty;
					this._cleaning = false;
					if(this._clean_handlers != null && this._clean_handlers.length > 0) this.propagate_clean();
				}
			}
		}
		return this.world;
	}
	,clean_check: function() {
		if(this.parent != null) {
			if(this.parent.dirty) this.parent.clean();
		}
		if(this.dirty && !this._cleaning) {
			if(!this.dirty) null; else {
				this._cleaning = true;
				this._pos_matrix.makeTranslation(this.local.pos.x,this.local.pos.y,this.local.pos.z);
				this._rotation_matrix.makeRotationFromQuaternion(this.local.rotation);
				this._origin_undo_matrix.makeTranslation(-this.origin.x,-this.origin.y,-this.origin.z);
				this.local.matrix.makeTranslation(this.origin.x,this.origin.y,this.origin.z);
				this.local.matrix.scale(this.local.scale);
				this.local.matrix.multiply(this._rotation_matrix);
				this.local.matrix.setPosition(this.local.pos);
				this.local.matrix.multiply(this._origin_undo_matrix);
				if(this.parent != null) this.get_world().set_matrix(this.get_world().get_matrix().multiplyMatrices(this.parent.get_world().get_matrix(),this.local.matrix)); else this.get_world().set_matrix(this.local.matrix.clone());
				this.get_world().decompose(false);
				this.dirty = false;
				if(this.dirty && !this._setup && this._dirty_handlers != null && this._dirty_handlers.length > 0) this.propagate_dirty();
				this.dirty;
				this._cleaning = false;
				if(this._clean_handlers != null && this._clean_handlers.length > 0) this.propagate_clean();
			}
		}
	}
	,clean: function() {
		if(!this.dirty) return;
		this._cleaning = true;
		this._pos_matrix.makeTranslation(this.local.pos.x,this.local.pos.y,this.local.pos.z);
		this._rotation_matrix.makeRotationFromQuaternion(this.local.rotation);
		this._origin_undo_matrix.makeTranslation(-this.origin.x,-this.origin.y,-this.origin.z);
		this.local.matrix.makeTranslation(this.origin.x,this.origin.y,this.origin.z);
		this.local.matrix.scale(this.local.scale);
		this.local.matrix.multiply(this._rotation_matrix);
		this.local.matrix.setPosition(this.local.pos);
		this.local.matrix.multiply(this._origin_undo_matrix);
		if(this.parent != null) this.get_world().set_matrix(this.get_world().get_matrix().multiplyMatrices(this.parent.get_world().get_matrix(),this.local.matrix)); else this.get_world().set_matrix(this.local.matrix.clone());
		this.get_world().decompose(false);
		this.dirty = false;
		if(this.dirty && !this._setup && this._dirty_handlers != null && this._dirty_handlers.length > 0) this.propagate_dirty();
		this.dirty;
		this._cleaning = false;
		if(this._clean_handlers != null && this._clean_handlers.length > 0) this.propagate_clean();
	}
	,toString: function() {
		return "Transform (" + this.id + ")";
	}
	,get_origin: function() {
		return this.origin;
	}
	,set_origin: function(o) {
		this.dirty = true;
		if(this.dirty && !this._setup && this._dirty_handlers != null && this._dirty_handlers.length > 0) this.propagate_dirty();
		this.dirty;
		this.origin = o;
		if(this._origin_handlers != null && this._origin_handlers.length > 0) this.propagate_origin(this.origin);
		return this.origin;
	}
	,set_world: function(w) {
		if(w == null) return this.world = w;
		this.dirty = true;
		if(this.dirty && !this._setup && this._dirty_handlers != null && this._dirty_handlers.length > 0) this.propagate_dirty();
		this.dirty;
		return this.world = w;
	}
	,get_parent: function() {
		return this.parent;
	}
	,set_parent: function(_p) {
		this.dirty = true;
		if(this.dirty && !this._setup && this._dirty_handlers != null && this._dirty_handlers.length > 0) this.propagate_dirty();
		this.dirty;
		if(this.parent != null) this.parent.unlisten($bind(this,this.on_parent_cleaned));
		this.parent = _p;
		if(this._parent_handlers != null && this._parent_handlers.length > 0) this.propagate_parent(this.parent);
		if(this.parent != null) this.parent.listen($bind(this,this.on_parent_cleaned));
		return this.parent;
	}
	,get_pos: function() {
		return this.local.pos;
	}
	,get_rotation: function() {
		return this.local.rotation;
	}
	,get_scale: function() {
		return this.local.scale;
	}
	,set_pos: function(value) {
		return this.local.set_pos(value);
	}
	,set_rotation: function(value) {
		return this.local.set_rotation(value);
	}
	,set_scale: function(value) {
		return this.local.set_scale(value);
	}
	,propagate_clean: function() {
		var _g = 0;
		var _g1 = this._clean_handlers;
		while(_g < _g1.length) {
			var _handler = _g1[_g];
			++_g;
			if(_handler != null) _handler(this);
		}
	}
	,propagate_dirty: function() {
		var _g = 0;
		var _g1 = this._dirty_handlers;
		while(_g < _g1.length) {
			var _handler = _g1[_g];
			++_g;
			if(_handler != null) _handler(this);
		}
	}
	,propagate_pos: function(_pos) {
		var _g = 0;
		var _g1 = this._pos_handlers;
		while(_g < _g1.length) {
			var _handler = _g1[_g];
			++_g;
			if(_handler != null) _handler(_pos);
		}
	}
	,propagate_rotation: function(_rotation) {
		var _g = 0;
		var _g1 = this._rotation_handlers;
		while(_g < _g1.length) {
			var _handler = _g1[_g];
			++_g;
			if(_handler != null) _handler(_rotation);
		}
	}
	,propagate_scale: function(_scale) {
		var _g = 0;
		var _g1 = this._scale_handlers;
		while(_g < _g1.length) {
			var _handler = _g1[_g];
			++_g;
			if(_handler != null) _handler(_scale);
		}
	}
	,propagate_origin: function(_origin) {
		var _g = 0;
		var _g1 = this._origin_handlers;
		while(_g < _g1.length) {
			var _handler = _g1[_g];
			++_g;
			if(_handler != null) _handler(_origin);
		}
	}
	,propagate_parent: function(_parent) {
		var _g = 0;
		var _g1 = this._parent_handlers;
		while(_g < _g1.length) {
			var _handler = _g1[_g];
			++_g;
			if(_handler != null) _handler(_parent);
		}
	}
	,listen: function(_handler) {
		if(this._clean_handlers == null) this._clean_handlers = [];
		this._clean_handlers.push(_handler);
	}
	,unlisten: function(_handler) {
		if(this._clean_handlers == null) return false;
		return HxOverrides.remove(this._clean_handlers,_handler);
	}
	,listen_dirty: function(_handler) {
		if(this._dirty_handlers == null) this._dirty_handlers = [];
		this._dirty_handlers.push(_handler);
	}
	,unlisten_dirty: function(_handler) {
		if(this._dirty_handlers == null) return false;
		return HxOverrides.remove(this._dirty_handlers,_handler);
	}
	,listen_pos: function(_handler) {
		if(this._pos_handlers == null) this._pos_handlers = [];
		this._pos_handlers.push(_handler);
	}
	,unlisten_pos: function(_handler) {
		if(this._pos_handlers == null) return false;
		return HxOverrides.remove(this._pos_handlers,_handler);
	}
	,listen_scale: function(_handler) {
		if(this._scale_handlers == null) this._scale_handlers = [];
		this._scale_handlers.push(_handler);
	}
	,unlisten_scale: function(_handler) {
		if(this._scale_handlers == null) return false;
		return HxOverrides.remove(this._scale_handlers,_handler);
	}
	,listen_rotation: function(_handler) {
		if(this._rotation_handlers == null) this._rotation_handlers = [];
		this._rotation_handlers.push(_handler);
	}
	,unlisten_rotation: function(_handler) {
		if(this._rotation_handlers == null) return false;
		return HxOverrides.remove(this._rotation_handlers,_handler);
	}
	,listen_origin: function(_handler) {
		if(this._origin_handlers == null) this._origin_handlers = [];
		this._origin_handlers.push(_handler);
	}
	,unlisten_origin: function(_handler) {
		if(this._origin_handlers == null) return false;
		return HxOverrides.remove(this._origin_handlers,_handler);
	}
	,listen_parent: function(_handler) {
		if(this._parent_handlers == null) this._parent_handlers = [];
		this._parent_handlers.push(_handler);
	}
	,unlisten_parent: function(_handler) {
		if(this._parent_handlers == null) return false;
		return HxOverrides.remove(this._parent_handlers,_handler);
	}
	,__class__: phoenix_Transform
	,__properties__: {set_scale:"set_scale",get_scale:"get_scale",set_rotation:"set_rotation",get_rotation:"get_rotation",set_pos:"set_pos",get_pos:"get_pos",set_dirty:"set_dirty",set_origin:"set_origin",get_origin:"get_origin",set_world:"set_world",get_world:"get_world",set_local:"set_local",get_local:"get_local",set_parent:"set_parent",get_parent:"get_parent"}
});
var phoenix_Spatial = function() {
	this._setup = true;
	this.auto_decompose = false;
	this.ignore_listeners = false;
	this.set_matrix(new phoenix_Matrix());
	this.floats = this.matrix.float32array();
	this.set_pos(new phoenix_Vector());
	this.set_rotation(new phoenix_Quaternion());
	this.set_scale(new phoenix_Vector(1,1,1));
	this._setup = false;
};
phoenix_Spatial.__name__ = true;
phoenix_Spatial.prototype = {
	destroy: function() {
		this.matrix = null;
		this.matrix;
		this.floats = null;
		this.pos = null;
		this.pos;
		this.rotation = null;
		this.rotation;
		this.scale = null;
		this.scale;
	}
	,decompose: function(_force) {
		if(_force == null) _force = true;
		if(this.auto_decompose || _force) {
			var _transform = this.matrix.decompose(null,null,null);
			this.set_pos(_transform.pos);
			this.set_rotation(_transform.rotation);
			this.set_scale(_transform.scale);
		}
		return this;
	}
	,get_matrix: function() {
		return this.matrix;
	}
	,set_matrix: function(_m) {
		this.matrix = _m;
		if(_m != null) this.floats = this.matrix.float32array();
		return this.matrix;
	}
	,propagate_pos: function(_p) {
		if(this.pos_changed != null && !this.ignore_listeners) this.pos_changed(_p);
	}
	,propagate_rotation: function(_r) {
		if(this.rotation_changed != null && !this.ignore_listeners) this.rotation_changed(_r);
	}
	,propagate_scale: function(_s) {
		if(this.scale_changed != null && !this.ignore_listeners) this.scale_changed(_s);
	}
	,set_pos: function(_p) {
		this.pos = _p;
		if(_p != null) {
			phoenix_Vector.Listen(this.pos,$bind(this,this._pos_change));
			if(this.pos_changed != null && !this.ignore_listeners) this.pos_changed(this.pos);
		}
		return this.pos;
	}
	,set_rotation: function(_r) {
		this.rotation = _r;
		if(_r != null) {
			phoenix_Quaternion.Listen(this.rotation,$bind(this,this._rotation_change));
			if(this.rotation_changed != null && !this.ignore_listeners) this.rotation_changed(this.rotation);
		}
		return this.rotation;
	}
	,set_scale: function(_s) {
		this.scale = _s;
		if(_s != null) {
			phoenix_Vector.Listen(this.scale,$bind(this,this._scale_change));
			if(this.scale_changed != null && !this.ignore_listeners) this.scale_changed(this.scale);
		}
		return this.scale;
	}
	,_pos_change: function(_v) {
		this.set_pos(this.pos);
	}
	,_scale_change: function(_v) {
		this.set_scale(this.scale);
	}
	,_rotation_change: function(_v) {
		this.set_rotation(this.rotation);
	}
	,__class__: phoenix_Spatial
	,__properties__: {set_matrix:"set_matrix",get_matrix:"get_matrix",set_scale:"set_scale",set_rotation:"set_rotation",set_pos:"set_pos"}
};
var phoenix_Vector = function(_x,_y,_z,_w) {
	if(_w == null) _w = 0;
	if(_z == null) _z = 0;
	if(_y == null) _y = 0;
	if(_x == null) _x = 0;
	this._construct = false;
	this.ignore_listeners = false;
	this.w = 0;
	this.z = 0;
	this.y = 0;
	this.x = 0;
	this._construct = true;
	this.x = _x;
	if(this._construct) this.x; else {
		if(this.listen_x != null && !this.ignore_listeners) this.listen_x(_x);
		this.x;
	}
	this.y = _y;
	if(this._construct) this.y; else {
		if(this.listen_y != null && !this.ignore_listeners) this.listen_y(_y);
		this.y;
	}
	this.z = _z;
	if(this._construct) this.z; else {
		if(this.listen_z != null && !this.ignore_listeners) this.listen_z(_z);
		this.z;
	}
	this.w = _w;
	this._construct = false;
};
phoenix_Vector.__name__ = true;
phoenix_Vector.Add = function(a,b) {
	return new phoenix_Vector(a.x + b.x,a.y + b.y,a.z + b.z);
};
phoenix_Vector.Subtract = function(a,b) {
	return new phoenix_Vector(a.x - b.x,a.y - b.y,a.z - b.z);
};
phoenix_Vector.MultiplyVector = function(a,b) {
	return new phoenix_Vector(a.x * b.x,a.y * b.y,a.z * b.z);
};
phoenix_Vector.DivideVector = function(a,b) {
	return new phoenix_Vector(a.x / b.x,a.y / b.y,a.z / b.z);
};
phoenix_Vector.Multiply = function(a,b) {
	return new phoenix_Vector(a.x * b,a.y * b,a.z * b);
};
phoenix_Vector.Divide = function(a,b) {
	return new phoenix_Vector(a.x / b,a.y / b,a.z / b);
};
phoenix_Vector.AddScalar = function(a,b) {
	return new phoenix_Vector(a.x + b,a.y + b,a.z + b);
};
phoenix_Vector.SubtractScalar = function(a,b) {
	return new phoenix_Vector(a.x - b,a.y - b,a.z - b);
};
phoenix_Vector.Cross = function(a,b) {
	return new phoenix_Vector(a.y * b.z - a.z * b.y,a.z * b.x - a.x * b.z,a.x * b.y - a.y * b.x);
};
phoenix_Vector.RotationTo = function(a,b) {
	return a.rotationTo(b);
};
phoenix_Vector.Listen = function(_v,listener) {
	_v.listen_x = listener;
	_v.listen_y = listener;
	_v.listen_z = listener;
};
phoenix_Vector.Degrees = function(_radian_vector) {
	return new phoenix_Vector(_radian_vector.x,_radian_vector.y,_radian_vector.z,_radian_vector.w).degrees();
};
phoenix_Vector.Radians = function(_degree_vector) {
	return new phoenix_Vector(_degree_vector.x,_degree_vector.y,_degree_vector.z,_degree_vector.w).radians();
};
phoenix_Vector.prototype = {
	copy_from: function(_other) {
		this.set(_other.x,_other.y,_other.z,_other.w);
		return this;
	}
	,set: function(_x,_y,_z,_w) {
		var prev = this.ignore_listeners;
		this.ignore_listeners = true;
		this.x = _x;
		if(this._construct) this.x; else {
			if(this.listen_x != null && !this.ignore_listeners) this.listen_x(_x);
			this.x;
		}
		this.y = _y;
		if(this._construct) this.y; else {
			if(this.listen_y != null && !this.ignore_listeners) this.listen_y(_y);
			this.y;
		}
		this.z = _z;
		if(this._construct) this.z; else {
			if(this.listen_z != null && !this.ignore_listeners) this.listen_z(_z);
			this.z;
		}
		this.w = _w;
		this.ignore_listeners = prev;
		if(this.listen_x != null && !this.ignore_listeners) this.listen_x(this.x);
		if(this.listen_y != null && !this.ignore_listeners) this.listen_y(this.y);
		if(this.listen_z != null && !this.ignore_listeners) this.listen_z(this.z);
		return this;
	}
	,set_xy: function(_x,_y) {
		var prev = this.ignore_listeners;
		this.ignore_listeners = true;
		this.x = _x;
		if(this._construct) this.x; else {
			if(this.listen_x != null && !this.ignore_listeners) this.listen_x(_x);
			this.x;
		}
		this.y = _y;
		if(this._construct) this.y; else {
			if(this.listen_y != null && !this.ignore_listeners) this.listen_y(_y);
			this.y;
		}
		this.ignore_listeners = prev;
		if(this.listen_x != null && !this.ignore_listeners) this.listen_x(this.x);
		if(this.listen_y != null && !this.ignore_listeners) this.listen_y(this.y);
		return this;
	}
	,set_xyz: function(_x,_y,_z) {
		var prev = this.ignore_listeners;
		this.ignore_listeners = true;
		this.x = _x;
		if(this._construct) this.x; else {
			if(this.listen_x != null && !this.ignore_listeners) this.listen_x(_x);
			this.x;
		}
		this.y = _y;
		if(this._construct) this.y; else {
			if(this.listen_y != null && !this.ignore_listeners) this.listen_y(_y);
			this.y;
		}
		this.z = _z;
		if(this._construct) this.z; else {
			if(this.listen_z != null && !this.ignore_listeners) this.listen_z(_z);
			this.z;
		}
		this.ignore_listeners = prev;
		if(this.listen_x != null && !this.ignore_listeners) this.listen_x(this.x);
		if(this.listen_y != null && !this.ignore_listeners) this.listen_y(this.y);
		if(this.listen_z != null && !this.ignore_listeners) this.listen_z(this.z);
		return this;
	}
	,lerp_xy: function(_dest_x,_dest_y,_t) {
		this.set_xy(luxe_utils_Maths.lerp(this.x,_dest_x,_t),luxe_utils_Maths.lerp(this.y,_dest_y,_t));
		return this;
	}
	,lerp_xyz: function(_dest_x,_dest_y,_dest_z,_t) {
		this.set_xyz(luxe_utils_Maths.lerp(this.x,_dest_x,_t),luxe_utils_Maths.lerp(this.y,_dest_y,_t),luxe_utils_Maths.lerp(this.z,_dest_z,_t));
		return this;
	}
	,weighted_average_xy: function(_dest_x,_dest_y,_slowness) {
		this.set_xy(luxe_utils_Maths.weighted_avg(this.x,_dest_x,_slowness),luxe_utils_Maths.weighted_avg(this.y,_dest_y,_slowness));
		return this;
	}
	,weighted_average_xyz: function(_dest_x,_dest_y,_dest_z,_slowness) {
		this.set_xyz(luxe_utils_Maths.weighted_avg(this.x,_dest_x,_slowness),luxe_utils_Maths.weighted_avg(this.y,_dest_y,_slowness),luxe_utils_Maths.weighted_avg(this.z,_dest_z,_slowness));
		return this;
	}
	,'int': function() {
		this.set_xyz(Math.round(this.x),Math.round(this.y),Math.round(this.z));
		return this;
	}
	,int_x: function() {
		this.set_x(Math.round(this.x));
		return this;
	}
	,int_y: function() {
		this.set_y(Math.round(this.y));
		return this;
	}
	,int_z: function() {
		this.set_z(Math.round(this.z));
		return this;
	}
	,toString: function() {
		return "{ x:" + this.x + ", y:" + this.y + ", z:" + this.z + " }";
	}
	,equals: function(other) {
		return this.x == other.x && this.y == other.y && this.z == other.z && this.w == other.w;
	}
	,clone: function() {
		return new phoenix_Vector(this.x,this.y,this.z,this.w);
	}
	,normalize: function() {
		return this.divideScalar(Math.sqrt(this.x * this.x + this.y * this.y + this.z * this.z));
	}
	,dot: function(other) {
		return this.x * other.x + this.y * other.y + this.z * other.z;
	}
	,cross: function(a,b) {
		this.set_xyz(a.y * b.z - a.z * b.y,a.z * b.x - a.x * b.z,a.x * b.y - a.y * b.x);
		return this;
	}
	,invert: function() {
		this.set_xyz(-this.x,-this.y,-this.z);
		return this;
	}
	,add: function(other) {
		if(other == null) throw new js__$Boot_HaxeError("vector.add other was handed in as null");
		this.set_xyz(this.x + other.x,this.y + other.y,this.z + other.z);
		return this;
	}
	,add_xyz: function(_x,_y,_z) {
		if(_z == null) _z = 0;
		if(_y == null) _y = 0;
		if(_x == null) _x = 0;
		this.set_xyz(this.x + _x,this.y + _y,this.z + _z);
		return this;
	}
	,subtract: function(other) {
		if(other == null) throw new js__$Boot_HaxeError("vector.subtract other was handed in as null");
		this.set_xyz(this.x - other.x,this.y - other.y,this.z - other.z);
		return this;
	}
	,subtract_xyz: function(_x,_y,_z) {
		if(_z == null) _z = 0;
		if(_y == null) _y = 0;
		if(_x == null) _x = 0;
		this.set_xyz(this.x - _x,this.y - _y,this.z - _z);
		return this;
	}
	,multiply: function(other) {
		if(other == null) throw new js__$Boot_HaxeError("vector.multiply other was handed in as null");
		this.set_xyz(this.x * other.x,this.y * other.y,this.z * other.z);
		return this;
	}
	,multiply_xyz: function(_x,_y,_z) {
		if(_z == null) _z = 1;
		if(_y == null) _y = 1;
		if(_x == null) _x = 1;
		this.set_xyz(this.x * _x,this.y * _y,this.z * _z);
		return this;
	}
	,divide: function(other) {
		if(other == null) throw new js__$Boot_HaxeError("vector.divide other was handed in as null");
		this.set_xyz(this.x / other.x,this.y / other.y,this.z / other.z);
		return this;
	}
	,divide_xyz: function(_x,_y,_z) {
		if(_z == null) _z = 1;
		if(_y == null) _y = 1;
		if(_x == null) _x = 1;
		this.set_xyz(this.x / _x,this.y / _y,this.z / _z);
		return this;
	}
	,addScalar: function(v) {
		this.set_xyz(this.x + v,this.y + v,this.z + v);
		return this;
	}
	,subtractScalar: function(v) {
		this.set_xyz(this.x - v,this.y - v,this.z - v);
		return this;
	}
	,multiplyScalar: function(v) {
		this.set_xyz(this.x * v,this.y * v,this.z * v);
		return this;
	}
	,divideScalar: function(v) {
		if(v != 0) this.set_xyz(this.x / v,this.y / v,this.z / v); else this.set_xyz(0,0,0);
		return this;
	}
	,set_length: function(value) {
		this.divideScalar(Math.sqrt(this.x * this.x + this.y * this.y + this.z * this.z)).multiplyScalar(value);
		return value;
	}
	,get_length: function() {
		return Math.sqrt(this.x * this.x + this.y * this.y + this.z * this.z);
	}
	,get_lengthsq: function() {
		return this.x * this.x + this.y * this.y + this.z * this.z;
	}
	,get_normalized: function() {
		return phoenix_Vector.Divide(this,Math.sqrt(this.x * this.x + this.y * this.y + this.z * this.z));
	}
	,set_x: function(_x) {
		this.x = _x;
		if(this._construct) return this.x;
		if(this.listen_x != null && !this.ignore_listeners) this.listen_x(_x);
		return this.x;
	}
	,set_y: function(_y) {
		this.y = _y;
		if(this._construct) return this.y;
		if(this.listen_y != null && !this.ignore_listeners) this.listen_y(_y);
		return this.y;
	}
	,set_z: function(_z) {
		this.z = _z;
		if(this._construct) return this.z;
		if(this.listen_z != null && !this.ignore_listeners) this.listen_z(_z);
		return this.z;
	}
	,get_inverted: function() {
		return new phoenix_Vector(-this.x,-this.y,-this.z);
	}
	,set_angle2D: function(value) {
		var len = Math.sqrt(this.x * this.x + this.y * this.y + this.z * this.z);
		this.set_xy(Math.cos(value) * len,Math.sin(value) * len);
		return value;
	}
	,get_angle2D: function() {
		return Math.atan2(this.y,this.x);
	}
	,truncate: function(max) {
		this.set_length(Math.min(max,Math.sqrt(this.x * this.x + this.y * this.y + this.z * this.z)));
		return this;
	}
	,rotationTo: function(other) {
		var theta = Math.atan2(other.x - this.x,other.y - this.y);
		var r = -(180.0 + theta * 180.0 / Math.PI);
		return r;
	}
	,applyQuaternion: function(q) {
		var qx = q.x;
		var qy = q.y;
		var qz = q.z;
		var qw = q.w;
		var ix = qw * this.x + qy * this.z - qz * this.y;
		var iy = qw * this.y + qz * this.x - qx * this.z;
		var iz = qw * this.z + qx * this.y - qy * this.x;
		var iw = -qx * this.x - qy * this.y - qz * this.z;
		this.set_xyz(ix * qw + iw * -qx + iy * -qz - iz * -qy,iy * qw + iw * -qy + iz * -qx - ix * -qz,iz * qw + iw * -qz + ix * -qy - iy * -qx);
		return this;
	}
	,applyProjection: function(m) {
		var e = m.elements;
		var x = this.x;
		var y = this.y;
		var z = this.z;
		var d = 1 / (e[3] * x + e[7] * y + e[11] * z + e[15]);
		this.set_xyz((e[0] * x + e[4] * y + e[8] * z + e[12]) * d,(e[1] * x + e[5] * y + e[9] * z + e[13]) * d,(e[2] * x + e[6] * y + e[10] * z + e[14]) * d);
		return this;
	}
	,transform: function(_m) {
		var _x = this.x;
		var _y = this.y;
		var _z = this.z;
		var e = _m.elements;
		this.set_xyz(e[0] * _x + e[4] * _y + e[8] * _z + e[12],e[1] * _x + e[5] * _y + e[9] * _z + e[13],e[2] * _x + e[6] * _y + e[10] * _z + e[14]);
		return this;
	}
	,transformDirection: function(m) {
		var e = m.elements;
		var x = this.x;
		var y = this.y;
		var z = this.z;
		this.set_xyz(e[0] * x + e[4] * y + e[8] * z,e[1] * x + e[5] * y + e[9] * z,e[2] * x + e[6] * y + e[10] * z);
		this.divideScalar(Math.sqrt(this.x * this.x + this.y * this.y + this.z * this.z));
		return this;
	}
	,setEulerFromRotationMatrix: function(m,order) {
		if(order == null) order = 0;
		var te = m.elements;
		var m11 = te[0];
		var m12 = te[4];
		var m13 = te[8];
		var m21 = te[1];
		var m22 = te[5];
		var m23 = te[9];
		var m31 = te[2];
		var m32 = te[6];
		var m33 = te[10];
		var _x = this.x;
		var _y = this.y;
		var _z = this.z;
		if(order == 0) {
			_y = Math.asin(m13 < -1?-1:m13 > 1?1:m13);
			if(Math.abs(m13) < 0.99999) {
				_x = Math.atan2(-m23,m33);
				_z = Math.atan2(-m12,m11);
			} else {
				_x = Math.atan2(m32,m22);
				_z = 0;
			}
		} else if(order == 1) {
			_x = Math.asin(-(m23 < -1?-1:m23 > 1?1:m23));
			if(Math.abs(m23) < 0.99999) {
				_y = Math.atan2(m13,m33);
				_z = Math.atan2(m21,m22);
			} else {
				_y = Math.atan2(-m31,m11);
				_z = 0;
			}
		} else if(order == 2) {
			_x = Math.asin(m32 < -1?-1:m32 > 1?1:m32);
			if(Math.abs(m32) < 0.99999) {
				_y = Math.atan2(-m31,m33);
				_z = Math.atan2(-m12,m22);
			} else {
				_y = 0;
				_z = Math.atan2(m21,m11);
			}
		} else if(order == 3) {
			_y = Math.asin(-(m31 < -1?-1:m31 > 1?1:m31));
			if(Math.abs(m31) < 0.99999) {
				_x = Math.atan2(m32,m33);
				_z = Math.atan2(m21,m11);
			} else {
				_x = 0;
				_z = Math.atan2(-m12,m22);
			}
		} else if(order == 4) {
			_z = Math.asin(m21 < -1?-1:m21 > 1?1:m21);
			if(Math.abs(m21) < 0.99999) {
				_x = Math.atan2(-m23,m22);
				_y = Math.atan2(-m31,m11);
			} else {
				_x = 0;
				_y = Math.atan2(m13,m33);
			}
		} else if(order == 5) {
			_z = Math.asin(-(m12 < -1?-1:m12 > 1?1:m12));
			if(Math.abs(m12) < 0.99999) {
				_x = Math.atan2(m32,m22);
				_y = Math.atan2(m13,m11);
			} else {
				_x = Math.atan2(-m23,m33);
				_y = 0;
			}
		}
		this.set_xyz(_x,_y,_z);
		return this;
	}
	,setEulerFromQuaternion: function(q,order) {
		if(order == null) order = 0;
		var sqx = q.x * q.x;
		var sqy = q.y * q.y;
		var sqz = q.z * q.z;
		var sqw = q.w * q.w;
		var _x = this.x;
		var _y = this.y;
		var _z = this.z;
		if(order == 0) {
			_x = Math.atan2(2 * (q.x * q.w - q.y * q.z),sqw - sqx - sqy + sqz);
			_y = Math.asin(luxe_utils_Maths.clamp(2 * (q.x * q.z + q.y * q.w),-1,1));
			_z = Math.atan2(2 * (q.z * q.w - q.x * q.y),sqw + sqx - sqy - sqz);
		} else if(order == 1) {
			_x = Math.asin(luxe_utils_Maths.clamp(2 * (q.x * q.w - q.y * q.z),-1,1));
			_y = Math.atan2(2 * (q.x * q.z + q.y * q.w),sqw - sqx - sqy + sqz);
			_z = Math.atan2(2 * (q.x * q.y + q.z * q.w),sqw - sqx + sqy - sqz);
		} else if(order == 2) {
			_x = Math.asin(luxe_utils_Maths.clamp(2 * (q.x * q.w + q.y * q.z),-1,1));
			_y = Math.atan2(2 * (q.y * q.w - q.z * q.x),sqw - sqx - sqy + sqz);
			_z = Math.atan2(2 * (q.z * q.w - q.x * q.y),sqw - sqx + sqy - sqz);
		} else if(order == 3) {
			_x = Math.atan2(2 * (q.x * q.w + q.z * q.y),sqw - sqx - sqy + sqz);
			_y = Math.asin(luxe_utils_Maths.clamp(2 * (q.y * q.w - q.x * q.z),-1,1));
			_z = Math.atan2(2 * (q.x * q.y + q.z * q.w),sqw + sqx - sqy - sqz);
		} else if(order == 4) {
			_x = Math.atan2(2 * (q.x * q.w - q.z * q.y),sqw - sqx + sqy - sqz);
			_y = Math.atan2(2 * (q.y * q.w - q.x * q.z),sqw + sqx - sqy - sqz);
			_z = Math.asin(luxe_utils_Maths.clamp(2 * (q.x * q.y + q.z * q.w),-1,1));
		} else if(order == 5) {
			_x = Math.atan2(2 * (q.x * q.w + q.y * q.z),sqw - sqx + sqy - sqz);
			_y = Math.atan2(2 * (q.x * q.z + q.y * q.w),sqw + sqx - sqy - sqz);
			_z = Math.asin(luxe_utils_Maths.clamp(2 * (q.z * q.w - q.x * q.y),-1,1));
		}
		this.set_xyz(_x,_y,_z);
		return this;
	}
	,degrees: function() {
		this.set_xyz(this.x * 57.29577951308238,this.y * 57.29577951308238,this.z * 57.29577951308238);
		return this;
	}
	,radians: function() {
		this.set_xyz(this.x * 0.017453292519943278,this.y * 0.017453292519943278,this.z * 0.017453292519943278);
		return this;
	}
	,__class__: phoenix_Vector
	,__properties__: {get_inverted:"get_inverted",get_normalized:"get_normalized",set_angle2D:"set_angle2D",get_angle2D:"get_angle2D",get_lengthsq:"get_lengthsq",set_length:"set_length",get_length:"get_length",set_z:"set_z",set_y:"set_y",set_x:"set_x"}
};
var phoenix__$Vector_Vec_$Impl_$ = {};
phoenix__$Vector_Vec_$Impl_$.__name__ = true;
phoenix__$Vector_Vec_$Impl_$._new = function(_x,_y,_z,_w) {
	return new phoenix_Vector(_x,_y,_z,_w);
};
phoenix__$Vector_Vec_$Impl_$._multiply = function(lhs,rhs) {
	return new phoenix_Vector(lhs.x * rhs.x,lhs.y * rhs.y,lhs.z * rhs.z);
};
phoenix__$Vector_Vec_$Impl_$._multiply_scalar = function(lhs,rhs) {
	return phoenix_Vector.Multiply(lhs,rhs);
};
phoenix__$Vector_Vec_$Impl_$._multiply_scalar_int = function(lhs,rhs) {
	return phoenix_Vector.Multiply(lhs,rhs);
};
phoenix__$Vector_Vec_$Impl_$._divide = function(lhs,rhs) {
	return new phoenix_Vector(lhs.x / rhs.x,lhs.y / rhs.y,lhs.z / rhs.z);
};
phoenix__$Vector_Vec_$Impl_$._divide_scalar = function(lhs,rhs) {
	return new phoenix_Vector(lhs.x / rhs,lhs.y / rhs,lhs.z / rhs);
};
phoenix__$Vector_Vec_$Impl_$._divide_scalar_int = function(lhs,rhs) {
	return new phoenix_Vector(lhs.x / rhs,lhs.y / rhs,lhs.z / rhs);
};
phoenix__$Vector_Vec_$Impl_$._add = function(lhs,rhs) {
	return new phoenix_Vector(lhs.x + rhs.x,lhs.y + rhs.y,lhs.z + rhs.z);
};
phoenix__$Vector_Vec_$Impl_$._add_scalar = function(lhs,rhs) {
	return new phoenix_Vector(lhs.x + rhs,lhs.y + rhs,lhs.z + rhs);
};
phoenix__$Vector_Vec_$Impl_$._add_scalar_int = function(lhs,rhs) {
	return new phoenix_Vector(lhs.x + rhs,lhs.y + rhs,lhs.z + rhs);
};
phoenix__$Vector_Vec_$Impl_$._subtract = function(lhs,rhs) {
	return new phoenix_Vector(lhs.x - rhs.x,lhs.y - rhs.y,lhs.z - rhs.z);
};
phoenix__$Vector_Vec_$Impl_$._subtract_scalar = function(lhs,rhs) {
	return new phoenix_Vector(lhs.x - rhs,lhs.y - rhs,lhs.z - rhs);
};
phoenix__$Vector_Vec_$Impl_$._subtract_scalar_int = function(lhs,rhs) {
	return new phoenix_Vector(lhs.x - rhs,lhs.y - rhs,lhs.z - rhs);
};
var phoenix_geometry_Geometry = function(options) {
	this.dirty = false;
	this.locked = false;
	this.immediate = false;
	this.visible = true;
	this.dirty_clip = false;
	this.dirty_depth = false;
	this.dirty_group = false;
	this.dirty_shader = false;
	this.dirty_texture = false;
	this.dirty_primitive_type = false;
	this.shadow_clip = false;
	this.shadow_depth = 0.0;
	this.shadow_group = 0;
	this.id = "";
	this.uuid = "";
	this.dropped = false;
	this.added = false;
	this.submitted = false;
	this.uuid = Luxe.utils.uniqueid();
	this.id = this.uuid;
	this.vertices = [];
	this.state = new phoenix_geometry_GeometryState();
	this.batchers = [];
	this.transform = new phoenix_Transform();
	this._final_vert_position = new phoenix_Vector();
	this.set_clip_rect(null);
	this.set_clip(false);
	var _do_add = true;
	if(options != null) {
		this.state.set_depth(options.depth == null?this.state.depth:options.depth);
		this.state.set_group(options.group == null?this.state.group:options.group);
		this.state.set_texture(options.texture == null?this.state.texture:options.texture);
		this.state.set_clip_rect(options.clip_rect == null?this.state.clip_rect:options.clip_rect);
		this.state.set_primitive_type(options.primitive_type == null?this.state.primitive_type:options.primitive_type);
		this.state.set_shader(options.shader == null?this.state.shader:options.shader);
		if(options.id == null) this.id = this.uuid; else this.id = options.id;
		this.transform.local.set_pos(options.pos == null?this.transform.local.pos:options.pos);
		this.transform.local.set_rotation(options.rotation == null?this.transform.local.rotation:options.rotation);
		this.transform.local.set_scale(options.scale == null?this.transform.local.scale:options.scale);
		this.transform.set_origin(options.origin == null?this.transform.origin:options.origin);
		if(options.immediate == null) this.immediate = false; else this.immediate = options.immediate;
		this.set_visible(options.visible == null?true:options.visible);
		this.set_color(options.color == null?new phoenix_Color():options.color);
		if(options.no_batcher_add == null) _do_add = true; else _do_add = options.no_batcher_add;
	} else this.set_color(new phoenix_Color());
	phoenix_geometry_Geometry._sequence_key++;
	this.key = new phoenix_geometry_GeometryKey();
	this.key.uuid = this.uuid;
	this.key.timestamp = snow_Snow.core.timestamp();
	this.key.sequence = phoenix_geometry_Geometry._sequence_key;
	this.key.primitive_type = this.state.primitive_type;
	this.key.texture = this.state.texture;
	this.key.shader = this.state.shader;
	this.key.group = this.state.group;
	this.key.depth = this.state.depth;
	this.key.clip = this.state.clip;
	this.transform.id = this.uuid;
	this.transform.name = this.id;
	if(options != null && options.batcher != null && _do_add) options.batcher.add(this);
};
phoenix_geometry_Geometry.__name__ = true;
phoenix_geometry_Geometry.prototype = {
	key_string: function() {
		return "ts: " + this.key.timestamp + "\n" + "sequence: " + this.key.sequence + "\n" + "primitive_type: " + this.key.primitive_type + "\n" + "texture: " + (this.key.texture == null?"null":this.key.texture.id) + "\n" + "shader: " + (this.key.shader == null?"null":this.key.shader.id) + "\n" + "group: " + this.key.group + "\n" + "depth: " + this.key.depth + "\n" + "clip: " + Std.string(this.key.clip);
	}
	,refresh_key: function() {
		this.key.uuid = this.uuid;
		this.key.timestamp = snow_Snow.core.timestamp();
		this.key.sequence = phoenix_geometry_Geometry._sequence_key;
		this.key.primitive_type = this.state.primitive_type;
		this.key.texture = this.state.texture;
		this.key.shader = this.state.shader;
		this.key.group = this.state.group;
		this.key.depth = this.state.depth;
		this.key.clip = this.state.clip;
	}
	,str: function() {
		if(!this.state.log) return;
		haxe_Log.trace("\t\tgeometry ; " + this.id,{ fileName : "Geometry.hx", lineNumber : 210, className : "phoenix.geometry.Geometry", methodName : "str"});
		this.state.log = true;
		this.state.str();
		this.state.log = false;
	}
	,drop: function(remove) {
		if(remove == null) remove = true;
		if(remove && this.added) {
			var _g = 0;
			var _g1 = this.batchers;
			while(_g < _g1.length) {
				var b = _g1[_g];
				++_g;
				b.remove(this,true);
			}
		}
		if(this.transform != null) {
			this.transform.destroy();
			this.transform = null;
		}
		this.dropped = true;
	}
	,add: function(v) {
		this.vertices.push(v);
		if(this.vertices.length > Luxe.renderer.batcher.max_verts) throw new js__$Boot_HaxeError("" + this.id + " / Currently a single geometry cannot exceed the maximum vert count of " + Luxe.renderer.batcher.max_verts);
	}
	,remove: function(v) {
		HxOverrides.remove(this.vertices,v);
	}
	,batch: function(vert_index,tcoord_index,color_index,normal_index,vertlist,tcoordlist,colorlist,normallist) {
		var _g = 0;
		var _g1 = this.vertices;
		while(_g < _g1.length) {
			var v = _g1[_g];
			++_g;
			this._final_vert_position.set(v.pos.x,v.pos.y,v.pos.z,v.pos.w);
			this._final_vert_position.transform(this.transform.get_world().get_matrix());
			vertlist[vert_index] = this._final_vert_position.x;
			vertlist[vert_index + 1] = this._final_vert_position.y;
			vertlist[vert_index + 2] = this._final_vert_position.z;
			vertlist[vert_index + 3] = this._final_vert_position.w;
			vert_index += 4;
			tcoordlist[tcoord_index] = v.uv.uv0.u;
			tcoordlist[tcoord_index + 1] = v.uv.uv0.v;
			tcoordlist[tcoord_index + 2] = v.uv.uv0.w;
			tcoordlist[tcoord_index + 3] = v.uv.uv0.t;
			tcoord_index += 4;
			colorlist[color_index] = v.color.r;
			colorlist[color_index + 1] = v.color.g;
			colorlist[color_index + 2] = v.color.b;
			colorlist[color_index + 3] = v.color.a;
			color_index += 4;
		}
	}
	,batch_into_arrays: function(vertlist,tcoordlist,colorlist,normallist) {
		var _g = 0;
		var _g1 = this.vertices;
		while(_g < _g1.length) {
			var v = _g1[_g];
			++_g;
			this._final_vert_position.set(v.pos.x,v.pos.y,v.pos.z,v.pos.w);
			this._final_vert_position.transform(this.transform.get_world().get_matrix());
			vertlist.push(this._final_vert_position.x);
			vertlist.push(this._final_vert_position.y);
			vertlist.push(this._final_vert_position.z);
			vertlist.push(this._final_vert_position.w);
			tcoordlist.push(v.uv.uv0.u);
			tcoordlist.push(v.uv.uv0.v);
			tcoordlist.push(v.uv.uv0.w);
			tcoordlist.push(v.uv.uv0.t);
			colorlist.push(v.color.r);
			colorlist.push(v.color.g);
			colorlist.push(v.color.b);
			colorlist.push(v.color.a);
			normallist.push(v.normal.x);
			normallist.push(v.normal.y);
			normallist.push(v.normal.z);
			normallist.push(v.normal.w);
		}
	}
	,translate: function(_offset) {
		this.transform.local.pos.set_xyz(this.transform.local.pos.x + _offset.x,this.transform.local.pos.y + _offset.y,this.transform.local.pos.x + _offset.z);
	}
	,set_locked: function(_locked) {
		return this.locked = _locked;
	}
	,get_locked: function() {
		return this.locked;
	}
	,set_dirty: function(_dirty) {
		return this.dirty = _dirty;
	}
	,get_dirty: function() {
		return this.dirty;
	}
	,refresh: function() {
		var _g = 0;
		var _g1 = this.batchers;
		while(_g < _g1.length) {
			var b = _g1[_g];
			++_g;
			b.remove(this,false);
		}
		if(this.dirty_primitive_type) {
			this.dirty_primitive_type = false;
			this.state.set_primitive_type(this.shadow_primitive_type);
		}
		if(this.dirty_texture) {
			this.dirty_texture = false;
			this.state.set_texture(this.shadow_texture);
		}
		if(this.dirty_shader) {
			this.dirty_shader = false;
			this.state.set_shader(this.shadow_shader);
		}
		if(this.dirty_group) {
			this.dirty_group = false;
			this.state.set_group(this.shadow_group);
		}
		if(this.dirty_depth) {
			this.dirty_depth = false;
			this.state.set_depth(this.shadow_depth);
		}
		if(this.dirty_clip) {
			this.dirty_clip = false;
			this.state.set_clip(this.shadow_clip);
		}
		this.refresh_key();
		var _g2 = 0;
		var _g11 = this.batchers;
		while(_g2 < _g11.length) {
			var b1 = _g11[_g2];
			++_g2;
			b1.add(this,false);
		}
	}
	,get_primitive_type: function() {
		return this.state.primitive_type;
	}
	,set_primitive_type: function(val) {
		if(this.state.primitive_type != val) {
			this.shadow_primitive_type = val;
			this.dirty_primitive_type = true;
			this.refresh();
		}
		return this.primitive_type = val;
	}
	,get_texture: function() {
		return this.state.texture;
	}
	,set_texture: function(val) {
		if(this.state.texture != val) {
			this.shadow_texture = val;
			this.dirty_texture = true;
			this.refresh();
		}
		return this.texture = val;
	}
	,set_visible: function(val) {
		return this.visible = val;
	}
	,set_color: function(val) {
		var _g = 0;
		var _g1 = this.vertices;
		while(_g < _g1.length) {
			var v = _g1[_g];
			++_g;
			v.color = val;
		}
		return this.color = val;
	}
	,get_shader: function() {
		return this.state.shader;
	}
	,set_shader: function(val) {
		if(this.state.shader != val) {
			this.shadow_shader = val;
			this.dirty_shader = true;
			this.refresh();
		}
		return this.shader = val;
	}
	,get_depth: function() {
		return this.state.depth;
	}
	,set_depth: function(val) {
		if(this.state.depth != val) {
			this.shadow_depth = val;
			this.dirty_depth = true;
			this.refresh();
		}
		return this.depth = val;
	}
	,get_group: function() {
		return this.state.group;
	}
	,set_group: function(val) {
		if(this.state.group != val) {
			this.shadow_group = val;
			this.dirty_group = true;
			this.refresh();
		}
		return this.group = val;
	}
	,get_clip: function() {
		return this.state.clip;
	}
	,set_clip: function(val) {
		if(this.state.clip != val) {
			this.shadow_clip = val;
			this.dirty_clip = true;
			this.refresh();
		}
		return this.clip = val;
	}
	,get_clip_rect: function() {
		return this.state.clip_rect;
	}
	,set_clip_rect: function(val) {
		if(val == null) this.set_clip(false); else this.set_clip(true);
		return this.state.set_clip_rect(val);
	}
	,__class__: phoenix_geometry_Geometry
	,__properties__: {set_clip:"set_clip",get_clip:"get_clip",set_color:"set_color",set_dirty:"set_dirty",get_dirty:"get_dirty",set_locked:"set_locked",get_locked:"get_locked",set_visible:"set_visible",set_clip_rect:"set_clip_rect",get_clip_rect:"get_clip_rect",set_group:"set_group",get_group:"get_group",set_depth:"set_depth",get_depth:"get_depth",set_shader:"set_shader",get_shader:"get_shader",set_texture:"set_texture",get_texture:"get_texture",set_primitive_type:"set_primitive_type",get_primitive_type:"get_primitive_type"}
};
var phoenix_geometry_CircleGeometry = function(options) {
	phoenix_geometry_Geometry.call(this,options);
	if(options == null) return;
	var _radius_x = 32;
	var _radius_y = 32;
	if(options.end_angle == null) options.end_angle = 360;
	if(options.start_angle == null) options.start_angle = 0;
	if(options.r != null) {
		_radius_x = options.r;
		_radius_y = options.r;
	}
	if(options.rx != null) _radius_x = options.rx;
	if(options.ry != null) _radius_y = options.ry;
	if(options.steps == null) {
		if(options.smooth == null) {
			var _max = Math.max(_radius_x,_radius_y);
			options.steps = Luxe.utils.geometry.segments_for_smooth_circle(_max);
		} else {
			var _smooth = options.smooth;
			var _max1 = Math.max(_radius_x,_radius_y);
			options.steps = Luxe.utils.geometry.segments_for_smooth_circle(_max1,_smooth);
		}
	}
	this.set(options.x,options.y,_radius_x,_radius_y,options.steps,options.start_angle,options.end_angle);
	if(options.visible != null) this.set_visible(options.visible);
};
phoenix_geometry_CircleGeometry.__name__ = true;
phoenix_geometry_CircleGeometry.__super__ = phoenix_geometry_Geometry;
phoenix_geometry_CircleGeometry.prototype = $extend(phoenix_geometry_Geometry.prototype,{
	set: function(_x,_y,_rx,_ry,_steps,_start_angle,_end_angle) {
		if(_end_angle == null) _end_angle = 360;
		if(_start_angle == null) _start_angle = 0;
		this.set_primitive_type(4);
		var half_pi = Math.PI / 2;
		var _start_angle_rad = _start_angle * 0.017453292519943278 - half_pi;
		var _end_angle_rad = _end_angle * 0.017453292519943278 - half_pi;
		var _range = _end_angle_rad - _start_angle_rad;
		_steps = Math.ceil(Math.abs(_range) / (Math.PI * 2) * _steps);
		var theta = _range / _steps;
		var tangential_factor = Math.tan(theta);
		var radial_factor = Math.cos(theta);
		var x = _rx * Math.cos(_start_angle_rad);
		var y = _rx * Math.sin(_start_angle_rad);
		var radial_ratio = _rx / _ry;
		if(radial_ratio == 0) radial_ratio = 0.000000001;
		var _index = 0;
		var _segment_pos = [];
		var _g1 = 0;
		var _g = _steps + 1;
		while(_g1 < _g) {
			var i = _g1++;
			var __x = x;
			var __y = y / radial_ratio;
			var _seg = new phoenix_Vector(__x,__y);
			_segment_pos.push(_seg);
			if(_index > 0) this.add(new phoenix_geometry_Vertex(_seg,this.color));
			this.add(new phoenix_geometry_Vertex(new phoenix_Vector(0,0),this.color));
			this.add(new phoenix_geometry_Vertex(_seg,this.color));
			var tx = -y;
			var ty = x;
			x += tx * tangential_factor;
			y += ty * tangential_factor;
			x *= radial_factor;
			y *= radial_factor;
			_index++;
		}
		this.add(new phoenix_geometry_Vertex(_segment_pos[_steps],this.color));
		this.transform.set_pos(new phoenix_Vector(_x,_y));
	}
	,__class__: phoenix_geometry_CircleGeometry
});
var phoenix_geometry_RingGeometry = function(options) {
	phoenix_geometry_CircleGeometry.call(this,options);
	this.set_primitive_type(1);
};
phoenix_geometry_RingGeometry.__name__ = true;
phoenix_geometry_RingGeometry.__super__ = phoenix_geometry_CircleGeometry;
phoenix_geometry_RingGeometry.prototype = $extend(phoenix_geometry_CircleGeometry.prototype,{
	set: function(_x,_y,_rx,_ry,_steps,_start_angle_degrees,_end_angle_degrees) {
		if(_end_angle_degrees == null) _end_angle_degrees = 360;
		if(_start_angle_degrees == null) _start_angle_degrees = 0;
		this.set_primitive_type(4);
		var _start_angle_rad = _start_angle_degrees * 0.017453292519943278;
		var _end_angle_rad = _end_angle_degrees * 0.017453292519943278;
		var _range = _end_angle_rad - _start_angle_rad;
		var theta = _range / _steps;
		var tangential_factor = Math.tan(theta);
		var radial_factor = Math.cos(theta);
		var x = _rx * Math.cos(_start_angle_rad);
		var y = _rx * Math.sin(_start_angle_rad);
		var radial_ratio = _rx / _ry;
		if(radial_ratio == 0) radial_ratio = 0.000000001;
		var _index = 0;
		var _segment_pos = [];
		var _g = 0;
		while(_g < _steps) {
			var i = _g++;
			var __x = x;
			var __y = y / radial_ratio;
			var _seg = new phoenix_Vector(__x,__y);
			_segment_pos.push(_seg);
			this.add(new phoenix_geometry_Vertex(_seg,this.color));
			if(_index > 0) {
				var prevvert = _segment_pos[_index];
				this.add(new phoenix_geometry_Vertex(new phoenix_Vector(prevvert.x,prevvert.y,prevvert.z,prevvert.w),this.color));
			}
			var tx = -y;
			var ty = x;
			x += tx * tangential_factor;
			y += ty * tangential_factor;
			x *= radial_factor;
			y *= radial_factor;
			_index++;
		}
		this.add(new phoenix_geometry_Vertex(_segment_pos[0],this.color));
		this.transform.set_pos(new phoenix_Vector(_x,_y));
	}
	,__class__: phoenix_geometry_RingGeometry
});
var phoenix_geometry_ArcGeometry = function(options) {
	phoenix_geometry_RingGeometry.call(this,options);
	this.vertices.pop();
	this.vertices.pop();
	this.set_primitive_type(1);
};
phoenix_geometry_ArcGeometry.__name__ = true;
phoenix_geometry_ArcGeometry.__super__ = phoenix_geometry_RingGeometry;
phoenix_geometry_ArcGeometry.prototype = $extend(phoenix_geometry_RingGeometry.prototype,{
	__class__: phoenix_geometry_ArcGeometry
});
var phoenix_geometry_CompositeGeometry = function(_options) {
	phoenix_geometry_Geometry.call(this,_options);
	this.geometry = [];
};
phoenix_geometry_CompositeGeometry.__name__ = true;
phoenix_geometry_CompositeGeometry.__super__ = phoenix_geometry_Geometry;
phoenix_geometry_CompositeGeometry.prototype = $extend(phoenix_geometry_Geometry.prototype,{
	toString: function() {
		return "CompositeGeometry " + Std.string(this.geometry) + " : " + Std.string(this.geometry);
	}
	,clear: function() {
		var _g = 0;
		var _g1 = this.geometry;
		while(_g < _g1.length) {
			var geom = _g1[_g];
			++_g;
			geom.transform.set_parent(null);
		}
		this.geometry.splice(0,this.geometry.length);
	}
	,replace: function(_geometry) {
		this.clear();
		this.geometry = _geometry;
		var _g = 0;
		var _g1 = this.geometry;
		while(_g < _g1.length) {
			var geom = _g1[_g];
			++_g;
			geom.transform.set_parent(this.transform);
		}
	}
	,has_geometry: function(geom) {
		return Lambda.has(this.geometry,geom);
	}
	,add_geometry: function(geom) {
		if(geom != null) {
			geom.transform.set_parent(this.transform);
			this.geometry.push(geom);
		}
	}
	,remove_geometry: function(g) {
		if(HxOverrides.remove(this.geometry,g)) g.transform.set_parent(null);
	}
	,add_to_batcher: function(_batcher) {
		var _g = 0;
		var _g1 = this.geometry;
		while(_g < _g1.length) {
			var geom = _g1[_g];
			++_g;
			_batcher.add(geom);
		}
	}
	,drop: function(remove) {
		if(remove == null) remove = true;
		phoenix_geometry_Geometry.prototype.drop.call(this,remove);
		var _g = 0;
		var _g1 = this.geometry;
		while(_g < _g1.length) {
			var geom = _g1[_g];
			++_g;
			geom.drop(remove);
			geom = null;
		}
		this.geometry = null;
		this.geometry = [];
	}
	,translate: function(_offset) {
		if(this.geometry != null) {
			var _g = 0;
			var _g1 = this.geometry;
			while(_g < _g1.length) {
				var geom = _g1[_g];
				++_g;
				geom.translate(_offset);
			}
		}
	}
	,set_color: function(_color) {
		if(this.geometry != null) {
			var _g = 0;
			var _g1 = this.geometry;
			while(_g < _g1.length) {
				var geom = _g1[_g];
				++_g;
				geom.set_color(_color);
			}
		}
		return this.color = _color;
	}
	,set_primitive_type: function(val) {
		if(this.geometry != null) {
			var _g = 0;
			var _g1 = this.geometry;
			while(_g < _g1.length) {
				var geom = _g1[_g];
				++_g;
				geom.set_primitive_type(val);
			}
		}
		return this.primitive_type = val;
	}
	,set_shader: function(val) {
		if(this.geometry != null) {
			var _g = 0;
			var _g1 = this.geometry;
			while(_g < _g1.length) {
				var geom = _g1[_g];
				++_g;
				geom.set_shader(val);
			}
		}
		return this.shader = val;
	}
	,set_texture: function(val) {
		if(this.geometry != null) {
			var _g = 0;
			var _g1 = this.geometry;
			while(_g < _g1.length) {
				var geom = _g1[_g];
				++_g;
				geom.set_texture(val);
			}
		}
		return this.texture = val;
	}
	,set_depth: function(val) {
		if(this.geometry != null) {
			var _g = 0;
			var _g1 = this.geometry;
			while(_g < _g1.length) {
				var geom = _g1[_g];
				++_g;
				geom.set_depth(val);
			}
		}
		return this.depth = val;
	}
	,set_group: function(val) {
		if(this.geometry != null) {
			var _g = 0;
			var _g1 = this.geometry;
			while(_g < _g1.length) {
				var geom = _g1[_g];
				++_g;
				geom.set_group(val);
			}
		}
		return this.group = val;
	}
	,set_locked: function(val) {
		if(this.geometry != null) {
			var _g = 0;
			var _g1 = this.geometry;
			while(_g < _g1.length) {
				var geom = _g1[_g];
				++_g;
				geom.set_locked(val);
			}
		}
		return this.locked = val;
	}
	,set_dirty: function(val) {
		if(this.geometry != null) {
			var _g = 0;
			var _g1 = this.geometry;
			while(_g < _g1.length) {
				var geom = _g1[_g];
				++_g;
				geom.set_dirty(val);
			}
		}
		return this.dirty = val;
	}
	,set_clip_rect: function(val) {
		if(this.geometry != null) {
			var _g = 0;
			var _g1 = this.geometry;
			while(_g < _g1.length) {
				var geom = _g1[_g];
				++_g;
				geom.set_clip_rect(val);
			}
		}
		return this.clip_rect = val;
	}
	,set_visible: function(val) {
		if(this.geometry != null) {
			var _g = 0;
			var _g1 = this.geometry;
			while(_g < _g1.length) {
				var geom = _g1[_g];
				++_g;
				geom.set_visible(val);
			}
		}
		return this.visible = val;
	}
	,__class__: phoenix_geometry_CompositeGeometry
});
var phoenix_geometry_GeometryKey = function() {
	this.clip = false;
	this.depth = 0;
	this.group = 0;
	this.uuid = "";
	this.sequence = 0;
	this.timestamp = 0;
};
phoenix_geometry_GeometryKey.__name__ = true;
phoenix_geometry_GeometryKey.prototype = {
	__class__: phoenix_geometry_GeometryKey
};
var phoenix_geometry_GeometryState = function() {
	this.log = false;
	this.set_clip(false);
	this.set_clip_rect(new phoenix_Rectangle());
	this.set_texture(null);
	this.set_shader(null);
	this.set_group(0);
	this.set_depth(0.0);
	this.set_primitive_type(0);
	this.dirty = false;
};
phoenix_geometry_GeometryState.__name__ = true;
phoenix_geometry_GeometryState.prototype = {
	clone_onto: function(_other) {
		_other.dirty = this.dirty;
		_other.set_texture(this.texture);
		_other.set_shader(this.shader);
		_other.set_group(this.group);
		_other.set_depth(this.depth);
		_other.set_primitive_type(this.primitive_type);
		_other.set_clip(this.clip);
		_other.clip_rect.copy_from(this.clip_rect);
	}
	,str: function() {
		if(!this.log) return;
		haxe_Log.trace("\t+ GEOMETRYSTATE " + Std.string(this.dirty),{ fileName : "GeometryState.hx", lineNumber : 53, className : "phoenix.geometry.GeometryState", methodName : "str"});
		haxe_Log.trace("\t\tdepth - " + this.depth,{ fileName : "GeometryState.hx", lineNumber : 54, className : "phoenix.geometry.GeometryState", methodName : "str"});
		haxe_Log.trace("\t\tgroup - " + this.group,{ fileName : "GeometryState.hx", lineNumber : 55, className : "phoenix.geometry.GeometryState", methodName : "str"});
		haxe_Log.trace("\t\ttexture - " + (this.texture == null?"null":this.texture.id),{ fileName : "GeometryState.hx", lineNumber : 56, className : "phoenix.geometry.GeometryState", methodName : "str"});
		if(this.texture != null) haxe_Log.trace("\t\t\t " + Std.string(this.texture.texture),{ fileName : "GeometryState.hx", lineNumber : 58, className : "phoenix.geometry.GeometryState", methodName : "str"});
		haxe_Log.trace("\t\tshader - " + (this.shader == null?"null":this.shader.id),{ fileName : "GeometryState.hx", lineNumber : 60, className : "phoenix.geometry.GeometryState", methodName : "str"});
		haxe_Log.trace("\t\tprimitive_type - " + this.primitive_type,{ fileName : "GeometryState.hx", lineNumber : 61, className : "phoenix.geometry.GeometryState", methodName : "str"});
		haxe_Log.trace("\t\tclip - " + Std.string(this.clip),{ fileName : "GeometryState.hx", lineNumber : 62, className : "phoenix.geometry.GeometryState", methodName : "str"});
		haxe_Log.trace("\t\tclip rect - " + Std.string(this.clip_rect),{ fileName : "GeometryState.hx", lineNumber : 63, className : "phoenix.geometry.GeometryState", methodName : "str"});
		haxe_Log.trace("\t- GEOMETRYSTATE",{ fileName : "GeometryState.hx", lineNumber : 64, className : "phoenix.geometry.GeometryState", methodName : "str"});
	}
	,clean: function() {
		this.dirty = false;
	}
	,update: function(other) {
		if(this.depth != other.depth) this.set_depth(other.depth);
		if(this.group != other.group) this.set_group(other.group);
		if(this.texture != other.texture) this.set_texture(other.texture);
		if(this.shader != other.shader) this.set_shader(other.shader);
		if(this.primitive_type != other.primitive_type) this.set_primitive_type(other.primitive_type);
		if(this.clip != other.clip) this.set_clip(other.clip);
		if(this.clip_rect != null) {
			if(other.clip_rect != null && !this.clip_rect.equal(other.clip_rect)) this.clip_rect.set(other.clip_rect.x,other.clip_rect.y,other.clip_rect.w,other.clip_rect.h);
		}
	}
	,set_primitive_type: function(val) {
		this.dirty = true;
		return this.primitive_type = val;
	}
	,set_texture: function(val) {
		this.dirty = true;
		return this.texture = val;
	}
	,set_shader: function(val) {
		this.dirty = true;
		return this.shader = val;
	}
	,set_depth: function(val) {
		return this.depth = val;
	}
	,set_group: function(val) {
		this.dirty = true;
		return this.group = val;
	}
	,set_clip: function(val) {
		this.dirty = true;
		return this.clip = val;
	}
	,set_clip_rect: function(val) {
		this.dirty = true;
		return this.clip_rect = val;
	}
	,__class__: phoenix_geometry_GeometryState
	,__properties__: {set_clip_rect:"set_clip_rect",set_clip:"set_clip",set_group:"set_group",set_depth:"set_depth",set_texture:"set_texture",set_shader:"set_shader",set_primitive_type:"set_primitive_type"}
};
var phoenix_geometry_LineGeometry = function(options) {
	phoenix_geometry_Geometry.call(this,options);
	if(options == null) return;
	if(options.color == null) options.color = new phoenix_Color();
	if(options.color0 == null) options.color0 = options.color;
	if(options.color1 == null) options.color1 = options.color;
	if(options.p0 != null) this.set_p0(options.p0); else this.set_p0(new phoenix_Vector());
	if(options.p1 != null) this.set_p1(options.p1); else this.set_p1(new phoenix_Vector());
	this.set(options);
};
phoenix_geometry_LineGeometry.__name__ = true;
phoenix_geometry_LineGeometry.__super__ = phoenix_geometry_Geometry;
phoenix_geometry_LineGeometry.prototype = $extend(phoenix_geometry_Geometry.prototype,{
	set_p0: function(_p) {
		if(this.vertices.length == 0) return this.p0 = _p;
		this.vertices[0].pos.set_x(_p.x);
		this.vertices[0].pos.set_y(_p.y);
		this.vertices[0].pos.set_z(_p.z);
		return this.p0 = _p;
	}
	,set_p1: function(_p) {
		if(this.vertices.length == 0) return this.p1 = _p;
		this.vertices[1].pos.set_x(_p.x);
		this.vertices[1].pos.set_y(_p.y);
		this.vertices[1].pos.set_z(_p.z);
		return this.p1 = _p;
	}
	,set: function(options) {
		this.vertices.splice(0,this.vertices.length);
		var vert0 = new phoenix_geometry_Vertex(new phoenix_Vector(options.p0.x,options.p0.y,options.p0.z),options.color0);
		vert0.uv.uv0.set_uv(0,0);
		var vert1 = new phoenix_geometry_Vertex(new phoenix_Vector(options.p1.x,options.p1.y,options.p1.z),options.color1);
		vert1.uv.uv0.set_uv(1,0);
		this.add(vert0);
		this.add(vert1);
		this.set_primitive_type(1);
		this.immediate = options.immediate;
	}
	,__class__: phoenix_geometry_LineGeometry
	,__properties__: $extend(phoenix_geometry_Geometry.prototype.__properties__,{set_p1:"set_p1",set_p0:"set_p0"})
});
var phoenix_geometry_PlaneGeometry = function(options) {
	this.is_set = false;
	this.flipy = false;
	this.flipx = false;
	phoenix_geometry_Geometry.call(this,options);
	if(options == null) return;
	if(options.flipx != null) this.set_flipx(options.flipx);
	if(options.flipy != null) this.set_flipy(options.flipy);
	this._uv_cache = new phoenix_Rectangle(0,0,1,1);
	this.set(new phoenix_Rectangle(options.x,options.z,options.w,options.h),options.y);
	if(options.visible != null) this.set_visible(options.visible);
	if(options.immediate != null) this.immediate = options.immediate;
};
phoenix_geometry_PlaneGeometry.__name__ = true;
phoenix_geometry_PlaneGeometry.__super__ = phoenix_geometry_Geometry;
phoenix_geometry_PlaneGeometry.prototype = $extend(phoenix_geometry_Geometry.prototype,{
	uv: function(_rect) {
		if(this.get_texture() == null) {
			haxe_Log.trace("Warning : calling UV on a geometry with null texture.",{ fileName : "PlaneGeometry.hx", lineNumber : 45, className : "phoenix.geometry.PlaneGeometry", methodName : "uv"});
			return;
		}
		var tlx = _rect.x / this.get_texture().width_actual;
		var tly = _rect.y / this.get_texture().height_actual;
		var szx = _rect.w / this.get_texture().width_actual;
		var szy = _rect.h / this.get_texture().height_actual;
		this.uv_space(new phoenix_Rectangle(tlx,tly,szx,szy));
	}
	,uv_space: function(_rect) {
		var sz_x = _rect.w;
		var sz_y = _rect.h;
		var tl_x = _rect.x;
		var tl_y = _rect.y;
		this._uv_cache.set(tl_x,tl_y,sz_x,sz_y);
		var tr_x = tl_x + sz_x;
		var tr_y = tl_y;
		var br_x = tl_x + sz_x;
		var br_y = tl_y + sz_y;
		var bl_x = tl_x;
		var bl_y = tl_y + sz_y;
		var tmp_x = 0.0;
		var tmp_y = 0.0;
		if(this.flipy) {
			tmp_y = bl_y;
			bl_y = tl_y;
			tl_y = tmp_y;
			tmp_y = br_y;
			br_y = tr_y;
			tr_y = tmp_y;
		}
		if(this.flipx) {
			tmp_x = tr_x;
			tr_x = tl_x;
			tl_x = tmp_x;
			tmp_x = br_x;
			br_x = bl_x;
			bl_x = tmp_x;
		}
		this.vertices[0].uv.uv0.set_uv(tl_x,tl_y);
		this.vertices[1].uv.uv0.set_uv(tr_x,tr_y);
		this.vertices[2].uv.uv0.set_uv(br_x,br_y);
		this.vertices[3].uv.uv0.set_uv(bl_x,bl_y);
		this.vertices[4].uv.uv0.set_uv(tl_x,tl_y);
		this.vertices[5].uv.uv0.set_uv(br_x,br_y);
		this.set_dirty(true);
	}
	,set: function(quad,y) {
		this.vertices.splice(0,this.vertices.length);
		var vert0 = new phoenix_geometry_Vertex(new phoenix_Vector(0,0,0),this.color);
		var vert1 = new phoenix_geometry_Vertex(new phoenix_Vector(quad.w,0,0),this.color);
		var vert2 = new phoenix_geometry_Vertex(new phoenix_Vector(quad.w,0,quad.h),this.color);
		var vert3 = new phoenix_geometry_Vertex(new phoenix_Vector(0,0,quad.h),this.color);
		var vert4 = new phoenix_geometry_Vertex(new phoenix_Vector(0,0,0),this.color);
		var vert5 = new phoenix_geometry_Vertex(new phoenix_Vector(quad.w,0,quad.h),this.color);
		this.add(vert5);
		this.add(vert4);
		this.add(vert3);
		this.add(vert2);
		this.add(vert1);
		this.add(vert0);
		this.set_primitive_type(4);
		this.immediate = false;
		this.transform.set_pos(new phoenix_Vector(quad.x,y,quad.y));
		this.is_set = true;
		this.uv_space(new phoenix_Rectangle(0,0,1,1));
	}
	,set_flipx: function(_val) {
		this.flipx = _val;
		if(this.is_set) this.uv_space(this._uv_cache);
		return this.flipx;
	}
	,set_flipy: function(_val) {
		this.flipy = _val;
		if(this.is_set) this.uv_space(this._uv_cache);
		return this.flipy;
	}
	,__class__: phoenix_geometry_PlaneGeometry
	,__properties__: $extend(phoenix_geometry_Geometry.prototype.__properties__,{set_flipy:"set_flipy",set_flipx:"set_flipx"})
});
var phoenix_geometry_QuadGeometry = function(options) {
	this.is_set = false;
	this.flipy = false;
	this.flipx = false;
	phoenix_geometry_Geometry.call(this,options);
	if(options == null) return;
	if(options.flipx != null) this.set_flipx(options.flipx);
	if(options.flipy != null) this.set_flipy(options.flipy);
	var _x = options.x;
	var _y = options.y;
	var _w = options.w;
	var _h = options.h;
	if(options.rect != null) {
		_x = options.rect.x;
		_y = options.rect.y;
		_w = options.rect.w;
		_h = options.rect.h;
	}
	this._uv_cache = new phoenix_Rectangle(0,0,1,1);
	this.set(new phoenix_Rectangle(_x,_y,_w,_h));
	if(options.visible != null) this.set_visible(options.visible);
	if(options.immediate != null) this.immediate = options.immediate;
};
phoenix_geometry_QuadGeometry.__name__ = true;
phoenix_geometry_QuadGeometry.__super__ = phoenix_geometry_Geometry;
phoenix_geometry_QuadGeometry.prototype = $extend(phoenix_geometry_Geometry.prototype,{
	uv: function(_rect) {
		if(this.get_texture() == null) {
			haxe_Log.trace("Warning : calling UV on a geometry with null texture.",{ fileName : "QuadGeometry.hx", lineNumber : 56, className : "phoenix.geometry.QuadGeometry", methodName : "uv"});
			return;
		}
		var tlx = _rect.x / this.get_texture().width_actual;
		var tly = _rect.y / this.get_texture().height_actual;
		var szx = _rect.w / this.get_texture().width_actual;
		var szy = _rect.h / this.get_texture().height_actual;
		this.uv_space(new phoenix_Rectangle(tlx,tly,szx,szy));
	}
	,uv_space: function(_rect) {
		var sz_x = _rect.w;
		var sz_y = _rect.h;
		var tl_x = _rect.x;
		var tl_y = _rect.y;
		this._uv_cache.set(tl_x,tl_y,sz_x,sz_y);
		var tr_x = tl_x + sz_x;
		var tr_y = tl_y;
		var br_x = tl_x + sz_x;
		var br_y = tl_y + sz_y;
		var bl_x = tl_x;
		var bl_y = tl_y + sz_y;
		var tmp_x = 0.0;
		var tmp_y = 0.0;
		if(this.flipy) {
			tmp_y = bl_y;
			bl_y = tl_y;
			tl_y = tmp_y;
			tmp_y = br_y;
			br_y = tr_y;
			tr_y = tmp_y;
		}
		if(this.flipx) {
			tmp_x = tr_x;
			tr_x = tl_x;
			tl_x = tmp_x;
			tmp_x = br_x;
			br_x = bl_x;
			bl_x = tmp_x;
		}
		this.vertices[0].uv.uv0.set_uv(tl_x,tl_y);
		this.vertices[1].uv.uv0.set_uv(tr_x,tr_y);
		this.vertices[2].uv.uv0.set_uv(br_x,br_y);
		this.vertices[3].uv.uv0.set_uv(bl_x,bl_y);
		this.vertices[4].uv.uv0.set_uv(tl_x,tl_y);
		this.vertices[5].uv.uv0.set_uv(br_x,br_y);
		this.set_dirty(true);
	}
	,resize: function(quad) {
		this.vertices[0].pos.set_xy(0,0);
		this.vertices[1].pos.set_xy(quad.x,0);
		this.vertices[2].pos.set_xy(quad.x,quad.y);
		this.vertices[3].pos.set_xy(0,quad.y);
		this.vertices[4].pos.set_xy(0,0);
		this.vertices[5].pos.set_xy(quad.x,quad.y);
	}
	,set: function(quad) {
		this.vertices.splice(0,this.vertices.length);
		var vert0 = new phoenix_geometry_Vertex(new phoenix_Vector(0,0),this.color);
		var vert1 = new phoenix_geometry_Vertex(new phoenix_Vector(quad.w,0),this.color);
		var vert2 = new phoenix_geometry_Vertex(new phoenix_Vector(quad.w,quad.h),this.color);
		var vert3 = new phoenix_geometry_Vertex(new phoenix_Vector(0,quad.h),this.color);
		var vert4 = new phoenix_geometry_Vertex(new phoenix_Vector(0,0),this.color);
		var vert5 = new phoenix_geometry_Vertex(new phoenix_Vector(quad.w,quad.h),this.color);
		this.add(vert0);
		this.add(vert1);
		this.add(vert2);
		this.add(vert3);
		this.add(vert4);
		this.add(vert5);
		this.set_primitive_type(4);
		this.immediate = false;
		this.transform.set_pos(new phoenix_Vector(quad.x,quad.y));
		this.is_set = true;
		this.uv_space(new phoenix_Rectangle(0,0,1,1));
	}
	,set_flipx: function(_val) {
		this.flipx = _val;
		if(this.is_set) this.uv_space(this._uv_cache);
		return this.flipx;
	}
	,set_flipy: function(_val) {
		this.flipy = _val;
		if(this.is_set) this.uv_space(this._uv_cache);
		return this.flipy;
	}
	,__class__: phoenix_geometry_QuadGeometry
	,__properties__: $extend(phoenix_geometry_Geometry.prototype.__properties__,{set_flipy:"set_flipy",set_flipx:"set_flipx"})
});
var phoenix_geometry_QuadPackGeometry = function(_options) {
	phoenix_geometry_Geometry.call(this,_options);
	this.set_primitive_type(4);
	this.quads = new haxe_ds_IntMap();
};
phoenix_geometry_QuadPackGeometry.__name__ = true;
phoenix_geometry_QuadPackGeometry.__super__ = phoenix_geometry_Geometry;
phoenix_geometry_QuadPackGeometry.prototype = $extend(phoenix_geometry_Geometry.prototype,{
	clear: function() {
		var $it0 = this.quads.keys();
		while( $it0.hasNext() ) {
			var q = $it0.next();
			this.quad_remove(q);
		}
	}
	,quad_add: function(_options) {
		if(_options.visible == null) _options.visible = true;
		if(_options.flipx == null) _options.flipx = false;
		if(_options.flipy == null) _options.flipy = false;
		var _uid = Luxe.utils.uniquehash();
		var vert0 = new phoenix_geometry_Vertex(new phoenix_Vector(_options.x,_options.y),_options.color);
		var vert1 = new phoenix_geometry_Vertex(new phoenix_Vector(_options.x + _options.w,_options.y),_options.color);
		var vert2 = new phoenix_geometry_Vertex(new phoenix_Vector(_options.x + _options.w,_options.y + _options.h),_options.color);
		var vert3 = new phoenix_geometry_Vertex(new phoenix_Vector(_options.x,_options.y + _options.h),_options.color);
		var vert4 = new phoenix_geometry_Vertex(new phoenix_Vector(_options.x,_options.y),_options.color);
		var vert5 = new phoenix_geometry_Vertex(new phoenix_Vector(_options.x + _options.w,_options.y + _options.h),_options.color);
		this.add(vert0);
		this.add(vert1);
		this.add(vert2);
		this.add(vert3);
		this.add(vert4);
		this.add(vert5);
		var _quad = { uid : _uid, verts : [], flipx : _options.flipx, flipy : _options.flipx, visible : _options.visible, _uv_cache : new phoenix_Rectangle(0,0,1,1)};
		_quad.verts.push(vert0);
		_quad.verts.push(vert1);
		_quad.verts.push(vert2);
		_quad.verts.push(vert3);
		_quad.verts.push(vert4);
		_quad.verts.push(vert5);
		this.quads.h[_uid] = _quad;
		if(_options.uv != null) this.quad_uv(_uid,_options.uv);
		this.set_dirty(true);
		return _uid;
	}
	,quad_remove: function(_quad_id) {
		var _quad = this.quads.h[_quad_id];
		if(_quad != null) {
			this.remove(_quad.verts[0]);
			this.remove(_quad.verts[1]);
			this.remove(_quad.verts[2]);
			this.remove(_quad.verts[3]);
			this.remove(_quad.verts[4]);
			this.remove(_quad.verts[5]);
			this.quads.remove(_quad_id);
			this.set_dirty(true);
		}
	}
	,quad_visible: function(_quad_id,visible) {
		var _quad = this.quads.h[_quad_id];
		if(_quad != null) {
			if(visible && !_quad.visible) {
				_quad.visible = false;
				this.add(_quad.verts[0]);
				this.add(_quad.verts[1]);
				this.add(_quad.verts[2]);
				this.add(_quad.verts[3]);
				this.add(_quad.verts[4]);
				this.add(_quad.verts[5]);
			} else if(!visible && _quad.visible) {
				_quad.visible = false;
				this.remove(_quad.verts[0]);
				this.remove(_quad.verts[1]);
				this.remove(_quad.verts[2]);
				this.remove(_quad.verts[3]);
				this.remove(_quad.verts[4]);
				this.remove(_quad.verts[5]);
			}
			this.set_dirty(true);
		}
	}
	,quad_resize: function(_quad_id,_size) {
		var _quad = this.quads.h[_quad_id];
		if(_quad != null) {
			_quad.verts[0].pos = new phoenix_Vector(_size.x,_size.y);
			_quad.verts[1].pos = new phoenix_Vector(_size.x + _size.w,_size.y);
			_quad.verts[2].pos = new phoenix_Vector(_size.x + _size.w,_size.y + _size.h);
			_quad.verts[3].pos = new phoenix_Vector(_size.x,_size.y + _size.h);
			_quad.verts[4].pos = new phoenix_Vector(_size.x,_size.y);
			_quad.verts[5].pos = new phoenix_Vector(_size.x + _size.w,_size.y + _size.h);
			this.set_dirty(true);
		}
	}
	,quad_pos: function(_quad_id,_p) {
		var _quad = this.quads.h[_quad_id];
		if(_quad != null) {
			var _diffx = _p.x - _quad.verts[0].pos.x;
			var _diffy = _p.y - _quad.verts[0].pos.y;
			var _g = _quad.verts[0].pos;
			_g.set_x(_g.x + _diffx);
			var _g1 = _quad.verts[0].pos;
			_g1.set_y(_g1.y + _diffy);
			var _g2 = _quad.verts[1].pos;
			_g2.set_x(_g2.x + _diffx);
			var _g3 = _quad.verts[1].pos;
			_g3.set_y(_g3.y + _diffy);
			var _g4 = _quad.verts[2].pos;
			_g4.set_x(_g4.x + _diffx);
			var _g5 = _quad.verts[2].pos;
			_g5.set_y(_g5.y + _diffy);
			var _g6 = _quad.verts[3].pos;
			_g6.set_x(_g6.x + _diffx);
			var _g7 = _quad.verts[3].pos;
			_g7.set_y(_g7.y + _diffy);
			var _g8 = _quad.verts[4].pos;
			_g8.set_x(_g8.x + _diffx);
			var _g9 = _quad.verts[4].pos;
			_g9.set_y(_g9.y + _diffy);
			var _g10 = _quad.verts[5].pos;
			_g10.set_x(_g10.x + _diffx);
			var _g11 = _quad.verts[5].pos;
			_g11.set_y(_g11.y + _diffy);
			this.set_dirty(true);
		}
	}
	,quad_color: function(_quad_id,_c) {
		var _quad = this.quads.h[_quad_id];
		if(_quad != null) {
			_quad.verts[0].color = _c;
			_quad.verts[1].color = _c;
			_quad.verts[2].color = _c;
			_quad.verts[3].color = _c;
			_quad.verts[4].color = _c;
			_quad.verts[5].color = _c;
		}
	}
	,quad_alpha: function(_quad_id,_a) {
		var _quad = this.quads.h[_quad_id];
		if(_quad != null) {
			_quad.verts[0].color.a = _a;
			_quad.verts[1].color.a = _a;
			_quad.verts[2].color.a = _a;
			_quad.verts[3].color.a = _a;
			_quad.verts[4].color.a = _a;
			_quad.verts[5].color.a = _a;
		}
	}
	,quad_uv_space: function(_quad_id,_uv) {
		var _quad = this.quads.h[_quad_id];
		if(_quad != null) {
			var flipx = _quad.flipx;
			var flipy = _quad.flipy;
			var sz_x = _uv.w;
			var sz_y = _uv.h;
			var tl_x = _uv.x;
			var tl_y = _uv.y;
			_quad._uv_cache.set(tl_x,tl_y,sz_x,sz_y);
			var tr_x = tl_x + sz_x;
			var tr_y = tl_y;
			var br_x = tl_x + sz_x;
			var br_y = tl_y + sz_y;
			var bl_x = tl_x;
			var bl_y = tl_y + sz_y;
			var tmp_x = 0.0;
			var tmp_y = 0.0;
			if(flipy) {
				tmp_y = bl_y;
				bl_y = tl_y;
				tl_y = tmp_y;
				tmp_y = br_y;
				br_y = tr_y;
				tr_y = tmp_y;
			}
			if(flipx) {
				tmp_x = tr_x;
				tr_x = tl_x;
				tl_x = tmp_x;
				tmp_x = br_x;
				br_x = bl_x;
				bl_x = tmp_x;
			}
			_quad.verts[0].uv.uv0.set_uv(tl_x,tl_y);
			_quad.verts[1].uv.uv0.set_uv(tr_x,tr_y);
			_quad.verts[2].uv.uv0.set_uv(br_x,br_y);
			_quad.verts[3].uv.uv0.set_uv(bl_x,bl_y);
			_quad.verts[4].uv.uv0.set_uv(tl_x,tl_y);
			_quad.verts[5].uv.uv0.set_uv(br_x,br_y);
			this.set_dirty(true);
		}
	}
	,quad_uv: function(_quad_id,_uv) {
		if(this.get_texture() == null) {
			haxe_Log.trace("Warning : calling UV on a PackedQuad Geometry with null texture.",{ fileName : "QuadPackGeometry.hx", lineNumber : 350, className : "phoenix.geometry.QuadPackGeometry", methodName : "quad_uv"});
			return;
		}
		var tlx = _uv.x / this.get_texture().width_actual;
		var tly = _uv.y / this.get_texture().height_actual;
		var szx = _uv.w / this.get_texture().width_actual;
		var szy = _uv.h / this.get_texture().height_actual;
		this.quad_uv_space(_quad_id,new phoenix_Rectangle(tlx,tly,szx,szy));
	}
	,quad_flipx: function(_quad_id,_flip) {
		var _quad = this.quads.h[_quad_id];
		if(_quad != null) {
			_quad.flipx = _flip;
			this.quad_uv_space(_quad_id,_quad._uv_cache);
		}
	}
	,quad_flipy: function(_quad_id,_flip) {
		var _quad = this.quads.h[_quad_id];
		if(_quad != null) {
			_quad.flipy = _flip;
			this.quad_uv_space(_quad_id,_quad._uv_cache);
		}
	}
	,__class__: phoenix_geometry_QuadPackGeometry
});
var phoenix_geometry_RectangleGeometry = function(options) {
	phoenix_geometry_Geometry.call(this,options);
	if(options == null) return;
	this.set(options);
};
phoenix_geometry_RectangleGeometry.__name__ = true;
phoenix_geometry_RectangleGeometry.__super__ = phoenix_geometry_Geometry;
phoenix_geometry_RectangleGeometry.prototype = $extend(phoenix_geometry_Geometry.prototype,{
	set: function(options) {
		this.vertices.splice(0,this.vertices.length);
		var _x = options.x;
		var _y = options.y;
		var _w = options.w;
		var _h = options.h;
		if(options.rect != null) {
			_x = options.rect.x;
			_y = options.rect.y;
			_w = options.rect.w;
			_h = options.rect.h;
		}
		var vert0 = new phoenix_geometry_Vertex(new phoenix_Vector(0,0));
		vert0.uv.uv0.set_uv(0,0);
		var vert1 = new phoenix_geometry_Vertex(new phoenix_Vector(_w,0));
		vert1.uv.uv0.set_uv(1,0);
		var vert2 = new phoenix_geometry_Vertex(new phoenix_Vector(_w,0));
		vert2.uv.uv0.set_uv(1,0);
		var vert3 = new phoenix_geometry_Vertex(new phoenix_Vector(_w,_h));
		vert3.uv.uv0.set_uv(1,1);
		var vert4 = new phoenix_geometry_Vertex(new phoenix_Vector(_w,_h));
		vert4.uv.uv0.set_uv(1,1);
		var vert5 = new phoenix_geometry_Vertex(new phoenix_Vector(0,_h));
		vert5.uv.uv0.set_uv(0,1);
		var vert6 = new phoenix_geometry_Vertex(new phoenix_Vector(0,_h));
		vert6.uv.uv0.set_uv(0,1);
		var vert7 = new phoenix_geometry_Vertex(new phoenix_Vector(0,0));
		vert7.uv.uv0.set_uv(0,0);
		this.add(vert0);
		this.add(vert1);
		this.add(vert2);
		this.add(vert3);
		this.add(vert4);
		this.add(vert5);
		this.add(vert6);
		this.add(vert7);
		this.set_primitive_type(1);
		if(options.immediate == null) this.immediate = false; else this.immediate = options.immediate;
		this.set_visible(options.visible == null?true:options.visible);
		this.set_color(options.color == null?new phoenix_Color():options.color);
		this.transform.set_pos(new phoenix_Vector(_x,_y));
	}
	,__class__: phoenix_geometry_RectangleGeometry
});
var phoenix_geometry_TextGeometry = function(_options) {
	this.dirty_align = true;
	this.dirty_sizing = true;
	this.point_ratio = 1;
	this.text_h_h = 0;
	this.text_h_w = 0;
	this.text_height = 0;
	this.text_width = 0;
	this.glow_amount = 0;
	this.glow_threshold = 0;
	this.outline = 0;
	this.thickness = 0.5;
	this.smoothness = 0.75;
	this.unique = false;
	this.sdf = false;
	this.bounds_wrap = false;
	this.letter_spacing = 0.0;
	this.line_spacing = 0.0;
	this.point_size = 32.0;
	this.text = "";
	this.options = _options;
	this.emitter = new luxe_Emitter();
	if(this.options == null) throw new js__$Boot_HaxeError("TextGeometry: requires non-null options at the moment");
	if(this.options.sdf != null) this.sdf = this.options.sdf;
	if(this.options.font == null) this.font = Luxe.renderer.font; else this.font = this.options.font;
	if(this.font == Luxe.renderer.font) this.sdf = true;
	if(this.options.shader == null) {
		if(this.sdf) this.options.shader = Luxe.renderer.shaders.bitmapfont.shader; else this.options.shader = Luxe.renderer.shaders.textured.shader;
	} else if(this.options.shader != Luxe.renderer.shaders.bitmapfont.shader) this.unique = true;
	phoenix_geometry_Geometry.call(this,this.options);
	this.set_primitive_type(4);
	this.cache = [];
	this.line_widths = [];
	this.line_offsets = [[],[]];
	this.lines = [];
	this.set_outline_color(new phoenix_Color());
	this.set_glow_color(new phoenix_Color());
	this.default_options();
};
phoenix_geometry_TextGeometry.__name__ = true;
phoenix_geometry_TextGeometry.__super__ = phoenix_geometry_Geometry;
phoenix_geometry_TextGeometry.prototype = $extend(phoenix_geometry_Geometry.prototype,{
	tidy: function() {
		var _vertidx = Math.floor(this.vertices.length / 6);
		var _diff = this.cache.length - _vertidx;
		if(_diff > 0) {
			var extra = this.cache.splice(_vertidx,_diff);
			var c = extra.length;
			while(c > 0) {
				c--;
				var vert = extra.pop();
				vert = null;
			}
		}
	}
	,default_options: function() {
		this.set_texture(this.font.pages.h[0]);
		if(this.options.letter_spacing != null) this.set_letter_spacing(this.options.letter_spacing);
		if(this.options.line_spacing != null) this.set_line_spacing(this.options.line_spacing);
		if(this.options.point_size != null) this.set_point_size(this.options.point_size);
		if(this.options.bounds != null) this.set_bounds(this.options.bounds);
		if(this.options.bounds_wrap != null) this.set_bounds_wrap(this.options.bounds_wrap);
		if(this.options.align == null) this.options.align = 0;
		if(this.options.align_vertical == null) this.options.align_vertical = 0;
		this.set_align(this.options.align);
		this.set_align_vertical(this.options.align_vertical);
		if(this.options.thickness != null) this.set_thickness(this.options.thickness);
		if(this.options.smoothness != null) this.set_smoothness(this.options.smoothness);
		if(this.options.outline != null) this.set_outline(this.options.outline);
		if(this.options.outline_color != null) this.set_outline_color(this.options.outline_color);
		if(this.options.glow_threshold != null) this.set_glow_threshold(this.options.glow_threshold);
		if(this.options.glow_amount != null) this.set_glow_amount(this.options.glow_amount);
		if(this.options.glow_color != null) this.set_glow_color(this.options.glow_color);
		if(this.sdf) this.flush_uniforms();
		if(this.options.text != null) this.set_text(this.options.text);
	}
	,set_text: function(_text) {
		if(_text == null) {
			haxe_Log.trace("i / textgeometry / " + "null text passed into TextGeometry!",{ fileName : "TextGeometry.hx", lineNumber : 239, className : "phoenix.geometry.TextGeometry", methodName : "set_text"});
			_text = "";
		}
		if(this.text != _text) {
			this.text = _text;
			if(this.text != "") {
				this.set_dirty_sizing(true);
				this.update_text();
			} else this.vertices.splice(0,this.vertices.length);
		}
		return this.text;
	}
	,stats: function() {
		return "letters:" + this.vertices.length / 6 + " / cache:" + this.cache.length;
	}
	,update_sizes: function() {
		if(!this.dirty_sizing) return false;
		var drawn_text = phoenix_geometry_TextGeometry.tab_regex.replace(this.text,"    ");
		if(this.bounds_wrap && this.bounds != null) drawn_text = this.font.wrap_string_to_bounds(drawn_text,this.bounds,this.point_size,this.letter_spacing);
		this.lines.splice(0,this.lines.length);
		this.lines = drawn_text.split("\n");
		this.line_widths.splice(0,this.line_widths.length);
		this.text_width = this.font.width_of(drawn_text,this.point_size,this.letter_spacing,this.line_widths);
		this.text_height = this.font.height_of_lines(this.lines,this.point_size,this.line_spacing);
		this.text_h_w = this.text_width / 2;
		this.text_h_h = this.text_height / 2;
		this.point_ratio = this.point_size / this.font.info.point_size;
		this.set_dirty_sizing(false);
		return true;
	}
	,update_text: function() {
		var _g = this;
		var _pos_x = 0.0;
		var _pos_y = 0.0;
		var _bounds_based = this.bounds != null;
		if(_bounds_based) {
			this.transform.local.pos.set_x(_pos_x = this.bounds.x);
			this.transform.local.pos.set_y(_pos_y = this.bounds.y);
		}
		var _cur_x = 0.0;
		var _cur_y = 0.0;
		var _line_idx = 0;
		var _total_idx = 0;
		var _is_char = true;
		var _was_dirty = this.update_sizes();
		var _g1 = 0;
		var _g11 = this.lines;
		while(_g1 < _g11.length) {
			var _line = _g11[_g1];
			++_g1;
			var _line_x_offset = 0.0;
			var _line_y_offset = 0.0;
			if(this.dirty_align) {
				if(!_bounds_based) {
					var _g2 = this.align;
					switch(_g2) {
					case 2:
						_line_x_offset = -(this.line_widths[_line_idx] / 2.0);
						break;
					case 1:
						_line_x_offset = -this.line_widths[_line_idx];
						break;
					default:
						_line_x_offset = 0.0;
					}
					var _g21 = this.align_vertical;
					switch(_g21) {
					case 2:
						_line_y_offset = -this.text_h_h;
						break;
					case 4:
						_line_y_offset = -this.text_height;
						break;
					default:
						_line_y_offset = 0.0;
					}
				} else {
					var _g22 = this.align;
					switch(_g22) {
					case 2:
						_line_x_offset = -(this.line_widths[_line_idx] / 2.0) + this.bounds.w / 2;
						break;
					case 1:
						_line_x_offset = -this.line_widths[_line_idx] + this.bounds.w;
						break;
					default:
						_line_x_offset = 0.0;
					}
					var _g23 = this.align_vertical;
					switch(_g23) {
					case 2:
						_line_y_offset = this.bounds.h / 2 - this.text_h_h;
						break;
					case 4:
						_line_y_offset = this.bounds.h - this.text_height;
						break;
					default:
						_line_y_offset = 0.0;
					}
				}
				this.line_offsets[0][_line_idx] = _line_x_offset;
				this.line_offsets[1][_line_idx] = _line_y_offset;
			} else {
				_line_x_offset = this.line_offsets[0][_line_idx];
				_line_y_offset = this.line_offsets[1][_line_idx];
			}
			if(_line_idx != 0) {
				_cur_y += (_g.font.info.line_height + _g.line_spacing) * _g.point_ratio;
				_cur_x = 0;
			}
			var _idx = 0;
			var $it0 = new luxe_utils_unifill_CodePointIter(_line);
			while( $it0.hasNext() ) {
				var _uglyph = $it0.next();
				var _index = _uglyph;
				var _char = this.font.info.chars.h[_index];
				_is_char = _char != null && _index > 32;
				if(!_is_char) _char = this.font.space_char;
				if(_is_char) {
					var _quad_x = _line_x_offset + _cur_x + _char.xoffset * this.point_ratio;
					var _quad_y = _line_y_offset + _cur_y + _char.yoffset * this.point_ratio;
					var _page = this.font.pages.h[_char.page];
					var _u1 = _char.x / _page.width_actual;
					var _v1 = _char.y / _page.height_actual;
					var _u2 = (_char.x + _char.width) / _page.width_actual;
					var _v2 = (_char.y + _char.height) / _page.height_actual;
					this.update_char(_total_idx,_quad_x,_quad_y,_char.width * this.point_ratio,_char.height * this.point_ratio,_u1,_v1,_u2,_v2,this.color);
					_total_idx++;
				}
				var _x_inc = _char.xadvance;
				if(_idx < _line.length - 1) {
					_x_inc += this.font.kerning(_index,luxe_utils_unifill_Unifill.uCharCodeAt(_line,_idx + 1));
					if(_index >= 32) _x_inc += this.letter_spacing;
				}
				_x_inc *= this.point_ratio;
				_cur_x += _x_inc;
				_idx++;
			}
			_line_idx++;
		}
		var _vertidx = this.vertices.length / 6 | 0;
		var _diff = _vertidx - _total_idx;
		if(_diff > 0) this.vertices.splice(_total_idx * 6,_diff * 6);
		this.dirty_align = false;
		this.emitter.emit(1,null,{ fileName : "TextGeometry.hx", lineNumber : 453, className : "phoenix.geometry.TextGeometry", methodName : "update_text"});
	}
	,update_char: function(_letteridx,_x,_y,_w,_h,_u,_v,_u2,_v2,_color) {
		var vert0;
		var vert1;
		var vert2;
		var vert3;
		var vert4;
		var vert5;
		var quad = this.cache[_letteridx];
		if(quad == null) {
			vert0 = new phoenix_geometry_Vertex(new phoenix_Vector(_x,_y),_color);
			vert1 = new phoenix_geometry_Vertex(new phoenix_Vector(_x + _w,_y),_color);
			vert2 = new phoenix_geometry_Vertex(new phoenix_Vector(_x + _w,_y + _h),_color);
			vert3 = new phoenix_geometry_Vertex(new phoenix_Vector(_x,_y + _h),_color);
			vert4 = new phoenix_geometry_Vertex(new phoenix_Vector(_x,_y),_color);
			vert5 = new phoenix_geometry_Vertex(new phoenix_Vector(_x + _w,_y + _h),_color);
			quad = [vert0,vert1,vert2,vert3,vert4,vert5];
			this.cache[_letteridx] = quad;
		} else {
			vert0 = quad[0];
			vert1 = quad[1];
			vert2 = quad[2];
			vert3 = quad[3];
			vert4 = quad[4];
			vert5 = quad[5];
			vert0.pos.set_xy(_x,_y);
			vert1.pos.set_xy(_x + _w,_y);
			vert2.pos.set_xy(_x + _w,_y + _h);
			vert3.pos.set_xy(_x,_y + _h);
			vert4.pos.set_xy(_x,_y);
			vert5.pos.set_xy(_x + _w,_y + _h);
		}
		vert0.uv.uv0.set_uv(_u,_v);
		vert1.uv.uv0.set_uv(_u2,_v);
		vert2.uv.uv0.set_uv(_u2,_v2);
		vert3.uv.uv0.set_uv(_u,_v2);
		vert4.uv.uv0.set_uv(_u,_v);
		vert5.uv.uv0.set_uv(_u2,_v2);
		var _vertidx = Math.floor(this.vertices.length / 6);
		if(_vertidx <= _letteridx) {
			this.add(vert0);
			this.add(vert1);
			this.add(vert2);
			this.add(vert3);
			this.add(vert4);
			this.add(vert5);
		}
	}
	,set_dirty_sizing: function(_b) {
		this.dirty_align = true;
		return this.dirty_sizing = _b;
	}
	,set_bounds: function(_bounds) {
		this.bounds = _bounds;
		this.set_dirty_sizing(true);
		this.update_text();
		return this.bounds;
	}
	,set_bounds_wrap: function(_wrap) {
		this.bounds_wrap = _wrap;
		this.set_dirty_sizing(true);
		this.update_text();
		return this.bounds_wrap;
	}
	,set_line_spacing: function(_line_spacing) {
		this.line_spacing = _line_spacing;
		this.set_dirty_sizing(true);
		this.update_text();
		return this.line_spacing;
	}
	,set_letter_spacing: function(_letter_spacing) {
		this.letter_spacing = _letter_spacing;
		this.set_dirty_sizing(true);
		this.update_text();
		return this.letter_spacing;
	}
	,set_align: function(_align) {
		this.align = _align;
		this.dirty_align = true;
		this.update_text();
		return this.align;
	}
	,set_align_vertical: function(_align_vertical) {
		this.align_vertical = _align_vertical;
		this.dirty_align = true;
		this.update_text();
		return this.align_vertical;
	}
	,set_point_size: function(s) {
		if(s < 0) s = 0;
		this.point_size = s;
		this.set_dirty_sizing(true);
		this.update_text();
		return this.point_size;
	}
	,set_smoothness: function(s) {
		if(s < 0) s = 0;
		if(this.get_shader() != null && this.sdf && this.unique) this.get_shader().set_float("smoothness",s);
		return this.smoothness = s;
	}
	,set_thickness: function(s) {
		if(s < 0) s = 0;
		if(this.get_shader() != null && this.sdf && this.unique) this.get_shader().set_float("thickness",s);
		return this.thickness = s;
	}
	,set_outline: function(s) {
		if(s < 0.0) s = 0.0; else if(s > 1.0) s = 1.0; else s = s;
		if(this.get_shader() != null && this.sdf && this.unique) this.get_shader().set_float("outline",s);
		return this.outline = s;
	}
	,set_glow_threshold: function(s) {
		if(s < 0) s = 0;
		if(this.get_shader() != null && this.sdf && this.unique) this.get_shader().set_float("glow_threshold",s);
		return this.glow_threshold = s;
	}
	,set_glow_amount: function(s) {
		if(s < 0) s = 0;
		if(this.get_shader() != null && this.sdf && this.unique) this.get_shader().set_float("glow_amount",s);
		return this.glow_amount = s;
	}
	,set_outline_color: function(c) {
		if(this.get_shader() != null && this.sdf && this.unique) this.get_shader().set_color("outline_color",c);
		return this.outline_color = c;
	}
	,set_glow_color: function(c) {
		if(this.get_shader() != null && this.sdf && this.unique) this.get_shader().set_color("glow_color",c);
		return this.glow_color = c;
	}
	,flush_uniforms: function() {
		if(this.get_shader() != null && this.sdf) {
			this.get_shader().set_float("smoothness",this.smoothness);
			this.get_shader().set_float("thickness",this.thickness);
			this.get_shader().set_float("outline",this.outline);
			this.get_shader().set_float("glow_threshold",this.glow_threshold);
			this.get_shader().set_float("glow_amount",this.glow_amount);
			this.get_shader().set_color("outline_color",this.outline_color);
			this.get_shader().set_color("glow_color",this.glow_color);
		}
	}
	,__class__: phoenix_geometry_TextGeometry
	,__properties__: $extend(phoenix_geometry_Geometry.prototype.__properties__,{set_dirty_sizing:"set_dirty_sizing",set_glow_color:"set_glow_color",set_glow_amount:"set_glow_amount",set_glow_threshold:"set_glow_threshold",set_outline_color:"set_outline_color",set_outline:"set_outline",set_thickness:"set_thickness",set_smoothness:"set_smoothness",set_align_vertical:"set_align_vertical",set_align:"set_align",set_bounds_wrap:"set_bounds_wrap",set_bounds:"set_bounds",set_letter_spacing:"set_letter_spacing",set_line_spacing:"set_line_spacing",set_point_size:"set_point_size",set_text:"set_text"})
});
var phoenix_geometry_TextureCoordSet = function() {
	this.uv0 = new phoenix_geometry_TextureCoord();
	this.uv1 = new phoenix_geometry_TextureCoord();
	this.uv2 = new phoenix_geometry_TextureCoord();
	this.uv3 = new phoenix_geometry_TextureCoord();
	this.uv4 = new phoenix_geometry_TextureCoord();
	this.uv5 = new phoenix_geometry_TextureCoord();
	this.uv6 = new phoenix_geometry_TextureCoord();
	this.uv7 = new phoenix_geometry_TextureCoord();
};
phoenix_geometry_TextureCoordSet.__name__ = true;
phoenix_geometry_TextureCoordSet.prototype = {
	clone: function() {
		var _set = new phoenix_geometry_TextureCoordSet();
		_set.uv0.set(this.uv0.u,this.uv0.v,this.uv0.w,this.uv0.t);
		_set.uv1.set(this.uv1.u,this.uv1.v,this.uv1.w,this.uv1.t);
		_set.uv2.set(this.uv2.u,this.uv2.v,this.uv2.w,this.uv2.t);
		_set.uv3.set(this.uv3.u,this.uv3.v,this.uv3.w,this.uv3.t);
		_set.uv4.set(this.uv4.u,this.uv4.v,this.uv4.w,this.uv4.t);
		_set.uv5.set(this.uv5.u,this.uv5.v,this.uv5.w,this.uv5.t);
		_set.uv6.set(this.uv6.u,this.uv6.v,this.uv6.w,this.uv6.t);
		_set.uv7.set(this.uv7.u,this.uv7.v,this.uv7.w,this.uv7.t);
		return _set;
	}
	,__class__: phoenix_geometry_TextureCoordSet
};
var phoenix_geometry_TextureCoord = function(_u,_v,_w,_t) {
	if(_t == null) _t = 0.0;
	if(_w == null) _w = 0.0;
	if(_v == null) _v = 0.0;
	if(_u == null) _u = 0.0;
	this.t = 0.0;
	this.w = 0.0;
	this.v = 0.0;
	this.u = 0.0;
	this.u = _u;
	this.v = _v;
	this.w = _w;
	this.t = _t;
};
phoenix_geometry_TextureCoord.__name__ = true;
phoenix_geometry_TextureCoord.prototype = {
	clone: function() {
		return new phoenix_geometry_TextureCoord(this.u,this.v,this.w,this.t);
	}
	,set: function(_u,_v,_w,_t) {
		this.u = _u;
		this.v = _v;
		this.w = _w;
		this.t = _t;
		return this;
	}
	,set_uv: function(_u,_v) {
		this.u = _u;
		this.v = _v;
		return this;
	}
	,toString: function() {
		return "{ u:" + this.v + ", v:" + this.v + " }";
	}
	,__class__: phoenix_geometry_TextureCoord
};
var phoenix_geometry_Vertex = function(_pos,_color,_normal) {
	this.uv = new phoenix_geometry_TextureCoordSet();
	this.pos = _pos;
	if(_color == null) this.color = new phoenix_Color(); else this.color = _color;
	if(_normal == null) this.normal = new phoenix_Vector(); else this.normal = _normal;
};
phoenix_geometry_Vertex.__name__ = true;
phoenix_geometry_Vertex.prototype = {
	clone: function() {
		var _new = new phoenix_geometry_Vertex(this.pos.clone(),this.color.clone(),this.normal.clone());
		_new.uv = this.uv.clone();
		return _new;
	}
	,__class__: phoenix_geometry_Vertex
};
var phoenix_utils_Rendering = function() { };
phoenix_utils_Rendering.__name__ = true;
phoenix_utils_Rendering.gl_blend_mode_from_BlendMode = function(_b) {
	switch(_b) {
	case 0:
		return 0;
	case 1:
		return 1;
	case 768:
		return 768;
	case 769:
		return 769;
	case 770:
		return 770;
	case 771:
		return 771;
	case 772:
		return 772;
	case 773:
		return 773;
	case 774:
		return 774;
	case 775:
		return 775;
	case 776:
		return 776;
	}
};
phoenix_utils_Rendering.get_elements_for_type = function(type,length) {
	switch(type) {
	case 0:
		return length / 4 | 0;
	case 1:
		return length / 4 | 0;
	case 3:
		return length / 4 | 0;
	case 2:
		return length / 4 | 0;
	case 5:
		return length / 4 | 0;
	case 6:
		return length / 4 | 0;
	default:
		return length / 4 | 0;
	}
};
phoenix_utils_Rendering.fovx_to_y = function(fovx,aspect) {
	return 180 / Math.PI * (2 * Math.atan(Math.tan(fovx * (Math.PI / 180) / 2) * (1 / aspect)));
};
var snow_AppFixedTimestep = function() {
	this.overflow = 0.0;
	this.frame_time = 0.0167;
	snow_App.call(this);
};
snow_AppFixedTimestep.__name__ = true;
snow_AppFixedTimestep.__super__ = snow_App;
snow_AppFixedTimestep.prototype = $extend(snow_App.prototype,{
	on_internal_init: function() {
		snow_App.prototype.on_internal_init.call(this);
		this.frame_time = 0.016666666666666666;
		this.last_frame_start = snow_Snow.core.timestamp();
	}
	,on_internal_update: function() {
		this.cur_frame_start = snow_Snow.core.timestamp();
		this.delta_time = this.cur_frame_start - this.last_frame_start;
		this.delta_sim = this.delta_time * this.timescale;
		if(this.delta_sim > this.max_frame_time) this.delta_sim = this.max_frame_time;
		this.last_frame_start = this.cur_frame_start;
		this.overflow += this.delta_sim;
		while(this.overflow >= this.frame_time) {
			this.app.do_internal_update(this.frame_time * this.timescale);
			this.current_time += this.frame_time * this.timescale;
			this.overflow -= this.frame_time * this.timescale;
		}
		this.alpha = this.overflow / this.frame_time;
	}
	,__class__: snow_AppFixedTimestep
});
var snow_utils_AbstractClass = function() { };
snow_utils_AbstractClass.__name__ = true;
var snow_CoreBinding = function() { };
snow_CoreBinding.__name__ = true;
snow_CoreBinding.__interfaces__ = [snow_utils_AbstractClass];
snow_CoreBinding.prototype = {
	init: function(_event_handler) {
		throw new js__$Boot_HaxeError("abstract method, must override");
	}
	,shutdown: function() {
		throw new js__$Boot_HaxeError("abstract method, must override");
	}
	,timestamp: function() {
		throw new js__$Boot_HaxeError("abstract method, must override");
	}
	,app_path: function() {
		throw new js__$Boot_HaxeError("abstract method, must override");
	}
	,app_path_prefs: function() {
		throw new js__$Boot_HaxeError("abstract method, must override");
	}
	,__class__: snow_CoreBinding
};
var snow__$Log_LogError = { __ename__ : true, __constructs__ : ["RequireString"] };
snow__$Log_LogError.RequireString = function(detail) { var $x = ["RequireString",0,detail]; $x.__enum__ = snow__$Log_LogError; $x.toString = $estr; return $x; };
var snow_Log = function() { };
snow_Log.__name__ = true;
snow_Log._get_spacing = function(_file) {
	var _spaces = "";
	var _trace_length = _file.length + 4;
	var _diff = snow_Log._log_width - _trace_length;
	if(_diff > 0) {
		var _g = 0;
		while(_g < _diff) {
			var i = _g++;
			_spaces += " ";
		}
	}
	return _spaces;
};
var snow_Snow = function() {
	this.is_ready = false;
	this.was_ready = false;
	this.has_shutdown = false;
	this.shutting_down = false;
	this.freeze = false;
	snow_Snow.core = new snow_platform_web_Core(this);
	snow_Snow.next_list = [];
};
snow_Snow.__name__ = true;
snow_Snow.load = function(library,method,args) {
	if(args == null) args = 0;
	return snow_utils_Libs.load(library,method,args);
};
snow_Snow.next = function(func) {
	if(func != null) snow_Snow.next_list.push(func);
};
snow_Snow.prototype = {
	init: function(_snow_config,_host) {
		this.snow_config = _snow_config;
		if(this.snow_config.app_package == null) this.snow_config.app_package = "org.snowkit.snowdefault";
		this.config = { has_window : true, runtime : { }, window : null, render : null, assets : [], web : { no_context_menu : true, prevent_default_keys : [snow_input_Keycodes.left,snow_input_Keycodes.right,snow_input_Keycodes.up,snow_input_Keycodes.down,snow_input_Keycodes.backspace,snow_input_Keycodes.tab,snow_input_Keycodes["delete"]], prevent_default_mouse_wheel : true, true_fullscreen : false}, 'native' : { audio_buffer_length : 176400, audio_buffer_count : 4}};
		this.host = _host;
		this.host.app = this;
		snow_Snow.core.init($bind(this,this.on_event));
	}
	,shutdown: function() {
		this.shutting_down = true;
		this.host.ondestroy();
		this.io.destroy();
		this.audio.destroy();
		this.input.destroy();
		this.windowing.destroy();
		snow_Snow.core.shutdown();
		this.has_shutdown = true;
	}
	,get_time: function() {
		return snow_Snow.core.timestamp();
	}
	,on_snow_init: function() {
		this.host.on_internal_init();
	}
	,on_snow_ready: function() {
		var _g = this;
		if(this.was_ready) throw new js__$Boot_HaxeError(snow_types_Error.error("firing ready event more than once is invalid usage"));
		this.io = new snow_io_IO(this);
		this.input = new snow_input_Input(this);
		this.audio = new snow_audio_Audio(this);
		this.assets = new snow_assets_Assets(this);
		this.windowing = new snow_window_Windowing(this);
		this.was_ready = true;
		this.setup_default_assets().then(function(_) {
			_g.setup_configs().then(function(_1) {
				_g.setup_default_window();
				_g.is_ready = true;
				_g.host.ready();
			});
		}).error(function(e) {
			throw new js__$Boot_HaxeError(snow_types_Error.init("snow / cannot recover from error: " + e));
		});
	}
	,do_internal_update: function(dt) {
		this.io.update();
		this.input.update();
		this.audio.update();
		this.host.update(dt);
	}
	,render: function() {
		this.windowing.update();
	}
	,on_snow_update: function() {
		if(this.freeze) return;
		snow_utils_Timer.update();
		snow_utils_Promises.step();
		this.handle_next_list();
		if(!this.is_ready) return;
		this.host.on_internal_update();
		this.host.on_internal_render();
	}
	,dispatch_system_event: function(_event) {
		this.on_event(_event);
	}
	,on_event: function(_event) {
		if(_event.type != 3 && _event.type != 0 && _event.type != 5 && _event.type != 6) null;
		if(_event.type != 3) null;
		if(this.is_ready) {
			this.io.on_event(_event);
			this.audio.on_event(_event);
			this.windowing.on_event(_event);
			this.input.on_event(_event);
			this.host.onevent(_event);
		}
		var _g = _event.type;
		if(_g != null) switch(_g) {
		case 1:
			this.on_snow_init();
			break;
		case 2:
			this.on_snow_ready();
			break;
		case 3:
			this.on_snow_update();
			break;
		case 7:case 8:
			this.shutdown();
			break;
		case 4:
			haxe_Log.trace("     i / snow / " + "Goodbye.",{ fileName : "Snow.hx", lineNumber : 311, className : "snow.Snow", methodName : "on_event"});
			break;
		default:
		} else {
		}
	}
	,set_freeze: function(_freeze) {
		this.freeze = _freeze;
		if(_freeze) this.audio.suspend(); else this.audio.resume();
		return this.freeze;
	}
	,setup_default_assets: function() {
		var _g = this;
		return new snow_utils_Promise(function(resolve,reject) {
			if(!_g.snow_config.config_custom_assets) {
				_g.assets.manifest_path = _g.snow_config.config_assets_path;
				_g.default_asset_list().then(function(list) {
					_g.config.assets = list;
					_g.assets.add(_g.config.assets);
					resolve();
				}).error(function(e) {
					_g.config.assets = [];
					resolve();
				});
			}
		});
	}
	,setup_configs: function() {
		var _g = this;
		this.config.window = this.default_window_config();
		this.config.render = this.default_render_config();
		return new snow_utils_Promise(function(resolve,reject) {
			if(!_g.snow_config.config_custom_runtime) _g.default_runtime_config().then(function(_runtime_conf) {
				_g.config.runtime = _runtime_conf;
				_g.setup_host_config();
				resolve();
			}); else {
				_g.setup_host_config();
				resolve();
			}
		});
	}
	,setup_host_config: function() {
		this.config = this.host.config(this.config);
	}
	,setup_default_window: function() {
		if(this.config.has_window == true) {
			this.window = this.windowing.create(this.config.window);
			if(this.window.handle == null) throw new js__$Boot_HaxeError(snow_types_Error.windowing("requested default window cannot be created. cannot continue"));
		}
	}
	,default_runtime_config: function() {
		var _g = this;
		return new snow_utils_Promise(function(resolve,reject) {
			var json = null;
			var onload = function(asset) {
				if(asset.text != null) {
					try {
						json = JSON.parse(asset.text);
						null;
					} catch( e ) {
						if (e instanceof js__$Boot_HaxeError) e = e.val;
						haxe_Log.trace("     i / snow / " + "config / json parse error ",{ fileName : "Snow.hx", lineNumber : 458, className : "snow.Snow", methodName : "default_runtime_config"});
						throw new js__$Boot_HaxeError(snow_types_Error.init("config / failed / default runtime config failed to parse as JSON. cannot recover. " + Std.string(e)));
					}
					resolve(json);
				}
			};
			var found = _g.assets.text(_g.snow_config.config_runtime_path,{ silent : true, onload : onload});
			if(found == null) resolve({ });
		});
	}
	,default_asset_list: function() {
		var _g = this;
		return new snow_utils_Promise(function(resolve,reject) {
			var list_path = _g.assets.assets_root + _g.assets.manifest_path;
			var load = _g.io.data_load(list_path,{ binary : false});
			load.then(function(_data) {
				var _filedata = snow_io_typedarray__$Uint8Array_Uint8Array_$Impl_$.toBytes(_data).toString();
				if(_filedata != null && _filedata.length != 0) {
					var _list = JSON.parse(_filedata.toString());
					var asset_list = [];
					var _g1 = 0;
					while(_g1 < _list.length) {
						var asset = _list[_g1];
						++_g1;
						asset_list.push({ id : asset, path : haxe_io_Path.join([_g.assets.assets_root,asset]), type : haxe_io_Path.extension(asset), ext : haxe_io_Path.extension(asset)});
					}
					resolve(asset_list);
				} else {
					haxe_Log.trace("     i / snow / " + "assets / info / default asset manifest is empty?",{ fileName : "Snow.hx", lineNumber : 507, className : "snow.Snow", methodName : "default_asset_list"});
					reject("default asset manifest is empty");
				}
			}).error(function(e) {
				haxe_Log.trace("     i / snow / " + ("assets / info / default asset manifest not found at " + list_path),{ fileName : "Snow.hx", lineNumber : 514, className : "snow.Snow", methodName : "default_asset_list"});
				reject("default asset manifest error: " + Std.string(e));
			});
		});
	}
	,default_render_config: function() {
		return { depth : false, stencil : false, antialiasing : 0, red_bits : 8, green_bits : 8, blue_bits : 8, alpha_bits : 8, depth_bits : 0, stencil_bits : 0, opengl : { minor : 0, major : 0, profile : 0}};
	}
	,default_window_config: function() {
		var conf = { fullscreen_desktop : true, fullscreen : false, borderless : false, resizable : true, x : 536805376, y : 536805376, width : 960, height : 640, title : "snow app"};
		return conf;
	}
	,get_uniqueid: function() {
		return this._uniqueid(null);
	}
	,_uniqueid: function(val) {
		if(val == null) val = Std.random(2147483647);
		var to_char = function(value) {
			if(value > 9) {
				var ascii = 65 + (value - 10);
				if(ascii > 90) ascii += 6;
				return String.fromCharCode(ascii);
			} else return (value == null?"null":"" + value).charAt(0);
		};
		var r = val % 62 | 0;
		var q = val / 62 | 0;
		if(q > 0) return this._uniqueid(q) + to_char(r); else return Std.string(to_char(r));
	}
	,handle_next_list: function() {
		if(snow_Snow.next_list.length > 0) {
			var _pre_next_length = snow_Snow.next_list.length;
			var _g1 = 0;
			var _g = snow_Snow.next_list.length;
			while(_g1 < _g) {
				var i = _g1++;
				snow_Snow.next_list[i]();
			}
			snow_Snow.next_list.splice(0,_pre_next_length);
		}
	}
	,__class__: snow_Snow
	,__properties__: {set_freeze:"set_freeze",get_uniqueid:"get_uniqueid",get_time:"get_time"}
};
var snow_assets_Asset = function(_assets,_info) {
	this.loaded = false;
	this.assets = _assets;
	this.info = _info;
	this.id = this.info.id;
};
snow_assets_Asset.__name__ = true;
snow_assets_Asset.prototype = {
	__class__: snow_assets_Asset
};
var snow_assets_AssetAudio = function(_assets,_info,_format,_load) {
	if(_load == null) _load = true;
	this.load_full = true;
	snow_assets_Asset.call(this,_assets,_info);
	this.type = 3;
	this.format = _format;
	this.load_full = _load;
};
snow_assets_AssetAudio.__name__ = true;
snow_assets_AssetAudio.__super__ = snow_assets_Asset;
snow_assets_AssetAudio.prototype = $extend(snow_assets_Asset.prototype,{
	load: function(onload) {
		var _g = this;
		this.loaded = false;
		this.audio = null;
		this.assets.platform.audio_load_info(this.info.path,this.format,this.load_full,function(_audio) {
			_g.audio = _audio;
			_g.loaded = true;
			if(onload != null) snow_Snow.next(function() {
				onload(_g);
			});
		});
	}
	,load_from_bytes: function(bytes,format,onload) {
		this.loaded = false;
		this.audio = null;
		this.audio = this.assets.platform.audio_info_from_bytes(this.info.path,bytes,format);
		if(onload != null) onload(this);
		this.loaded = true;
	}
	,__class__: snow_assets_AssetAudio
});
var snow_assets_AssetBytes = function(_assets,_info,_async) {
	if(_async == null) _async = false;
	this.async = false;
	snow_assets_Asset.call(this,_assets,_info);
	this.type = 0;
	this.async = _async;
};
snow_assets_AssetBytes.__name__ = true;
snow_assets_AssetBytes.__super__ = snow_assets_Asset;
snow_assets_AssetBytes.prototype = $extend(snow_assets_Asset.prototype,{
	load: function(onload) {
		var _g = this;
		this.loaded = false;
		this.bytes = null;
		var p = this.assets.lib.io.data_load(this.info.path,{ binary : true});
		p.then(function(data) {
			_g.load_from_bytes(data,onload);
		});
	}
	,load_from_bytes: function(_bytes,onload) {
		this.loaded = false;
		this.bytes = _bytes;
		this.loaded = true;
		if(onload != null) onload(this);
	}
	,__class__: snow_assets_AssetBytes
});
var snow_assets_AssetImage = function(_assets,_info,_components) {
	if(_components == null) _components = 4;
	this.components = 4;
	snow_assets_Asset.call(this,_assets,_info);
	this.type = 2;
	this.components = _components;
};
snow_assets_AssetImage.__name__ = true;
snow_assets_AssetImage.__super__ = snow_assets_Asset;
snow_assets_AssetImage.prototype = $extend(snow_assets_Asset.prototype,{
	load: function(onload) {
		var _g = this;
		this.loaded = false;
		this.image = null;
		this.assets.platform.image_load_info(this.info.path,this.components,function(_image) {
			if(_image != null) {
				_g.image = _image;
				_g.loaded = true;
			}
			if(onload != null) snow_Snow.next(function() {
				onload(_g);
			});
		});
	}
	,load_from_bytes: function(bytes,onload) {
		this.loaded = false;
		this.image = null;
		this.image = this.assets.platform.image_info_from_bytes(this.info.path,bytes,this.components);
		if(onload != null) onload(this);
		this.loaded = true;
	}
	,load_from_pixels: function(_id,_width,_height,_pixels,onload) {
		this.loaded = false;
		this.image = null;
		this.image = { id : _id, width : _width, width_actual : _width, height : _height, height_actual : _height, bpp : 4, bpp_source : 4, data : _pixels};
		if(onload != null) onload(this);
		this.loaded = true;
	}
	,__class__: snow_assets_AssetImage
});
var snow_assets_AssetSystemBinding = function() { };
snow_assets_AssetSystemBinding.__name__ = true;
snow_assets_AssetSystemBinding.__interfaces__ = [snow_utils_AbstractClass];
snow_assets_AssetSystemBinding.prototype = {
	exists: function(_id,_strict) {
		if(_strict == null) _strict = true;
		throw new js__$Boot_HaxeError("abstract method, must override");
	}
	,image_load_info: function(_path,_components,_onload) {
		if(_components == null) _components = 4;
		throw new js__$Boot_HaxeError("abstract method, must override");
	}
	,image_info_from_bytes: function(_path,_bytes,_components) {
		if(_components == null) _components = 4;
		throw new js__$Boot_HaxeError("abstract method, must override");
	}
	,audio_load_info: function(_path,_format,_load,_onload) {
		if(_load == null) _load = true;
		throw new js__$Boot_HaxeError("abstract method, must override");
	}
	,audio_info_from_bytes: function(_path,_bytes,_format) {
		throw new js__$Boot_HaxeError("abstract method, must override");
	}
	,__class__: snow_assets_AssetSystemBinding
};
var snow_assets_AssetText = function(_assets,_info,_async) {
	if(_async == null) _async = false;
	this.async = false;
	snow_assets_Asset.call(this,_assets,_info);
	this.type = 1;
	this.async = _async;
};
snow_assets_AssetText.__name__ = true;
snow_assets_AssetText.__super__ = snow_assets_Asset;
snow_assets_AssetText.prototype = $extend(snow_assets_Asset.prototype,{
	load: function(onload) {
		var _g = this;
		this.loaded = false;
		this.text = null;
		var p = this.assets.lib.io.data_load(this.info.path,{ binary : false});
		p.then(function(data) {
			_g.load_from_string(snow_io_typedarray__$Uint8Array_Uint8Array_$Impl_$.toBytes(data).toString(),onload);
		});
	}
	,load_from_string: function(_string,onload) {
		this.loaded = false;
		this.text = _string;
		this.loaded = true;
		if(onload != null) onload(this);
	}
	,__class__: snow_assets_AssetText
});
var snow_assets_Assets = function(_lib) {
	this.strict = true;
	this.manifest_path = "manifest";
	this.assets_root = "";
	this.lib = _lib;
	this.list = new haxe_ds_StringMap();
	this.platform = new snow_platform_web_assets_AssetSystem(this);
};
snow_assets_Assets.__name__ = true;
snow_assets_Assets.prototype = {
	add: function(_list) {
		var _g = 0;
		while(_g < _list.length) {
			var _asset = _list[_g];
			++_g;
			var images = ["psd","bmp","tga","gif","jpg","png"];
			var sounds = ["pcm","ogg","wav"];
			if(Lambda.has(images,_asset.ext)) _asset.type = "image"; else if(Lambda.has(sounds,_asset.ext)) _asset.type = "sound";
			this.list.set(_asset.id,_asset);
		}
	}
	,get: function(_id) {
		return this.list.get(_id);
	}
	,listed: function(_id) {
		return this.list.exists(_id);
	}
	,exists: function(_id,_strict) {
		if(_strict == null) _strict = true;
		return this.platform.exists(_id,_strict);
	}
	,path: function(_id) {
		if(this.listed(_id)) return this.get(_id).path;
		return this.assets_root + _id;
	}
	,bytes: function(_id,options) {
		var _strict = this.strict;
		var _silent = false;
		if(options != null) {
			if(options.strict != null) _strict = options.strict;
			if(options.silent != null) _silent = options.silent;
		}
		if(this.exists(_id,_strict)) {
			var info = this.get(_id);
			if(info == null) info = this.info_from_id(_id,"bytes");
			var asset = new snow_assets_AssetBytes(this,info,options != null?options.async:null);
			asset.load(options != null?options.onload:null);
			return asset;
		} else this.exists_error(_id,_silent);
		return null;
	}
	,text: function(_id,options) {
		var _strict = this.strict;
		var _silent = false;
		if(options != null) {
			if(options.strict != null) _strict = options.strict;
			if(options.silent != null) _silent = options.silent;
		}
		if(this.exists(_id,_strict)) {
			var info = this.get(_id);
			if(info == null) info = this.info_from_id(_id,"text");
			var asset = new snow_assets_AssetText(this,info,options != null?options.async:null);
			asset.load(options != null?options.onload:null);
			return asset;
		} else this.exists_error(_id,_silent);
		return null;
	}
	,image: function(_id,options) {
		var _strict = this.strict;
		var _silent = false;
		var _from_bytes = false;
		if(options != null) {
			if(options.strict != null) _strict = options.strict;
			if(options.silent != null) _silent = options.silent;
			_from_bytes = options.bytes != null;
		}
		if(this.exists(_id,_strict) || _from_bytes) {
			if(options == null) options = { components : 4};
			var info = this.get(_id);
			if(info == null) info = this.info_from_id(_id,"image");
			var comp;
			if(options.components == null) comp = 4; else comp = options.components;
			var asset = new snow_assets_AssetImage(this,info,comp);
			if(!_from_bytes) asset.load(options.onload); else asset.load_from_bytes(options.bytes,options.onload);
			return asset;
		} else this.exists_error(_id,_silent);
		return null;
	}
	,audio: function(_id,options) {
		var _strict = this.strict;
		var _silent = false;
		var _from_bytes = false;
		if(options != null) {
			if(options.strict != null) _strict = options.strict;
			if(options.silent != null) _silent = options.silent;
			_from_bytes = options.bytes != null;
		}
		if(this.exists(_id,_strict) || _from_bytes) {
			var info = this.get(_id);
			if(info == null) info = this.info_from_id(_id,"audio");
			if(options == null) options = { type : info.ext, load : true}; else if(options.type == null || options.type == "") options.type = info.ext;
			var _type = 0;
			var _g = options.type;
			if(_g != null) switch(_g) {
			case "wav":
				_type = 2;
				break;
			case "ogg":
				_type = 1;
				break;
			case "pcm":
				_type = 3;
				break;
			default:
				this.load_error(_id,"unrecognized audio format");
				return null;
			} else {
				this.load_error(_id,"unrecognized audio format");
				return null;
			}
			var asset = new snow_assets_AssetAudio(this,info,_type,options.load);
			if(!_from_bytes) asset.load(options != null?options.onload:null); else asset.load_from_bytes(options.bytes,_type,options.onload);
			return asset;
		} else this.exists_error(_id,_silent);
		return null;
	}
	,info_from_id: function(_id,_type) {
		return { id : _id, path : _id, ext : haxe_io_Path.extension(_id), type : _type};
	}
	,exists_error: function(_id,_silent) {
		if(_silent == null) _silent = false;
		if(!_silent) haxe_Log.trace("   i / assets / " + ("not found \"" + _id + "\""),{ fileName : "Assets.hx", lineNumber : 311, className : "snow.assets.Assets", methodName : "exists_error"});
	}
	,load_error: function(_id,reason,_silent) {
		if(_silent == null) _silent = false;
		if(reason == null) reason = "unknown";
		if(!_silent) haxe_Log.trace("   i / assets / " + ("found \"" + _id + "\" but it failed to load (" + reason + ")"),{ fileName : "Assets.hx", lineNumber : 315, className : "snow.assets.Assets", methodName : "load_error"});
	}
	,__class__: snow_assets_Assets
};
var snow_audio_Audio = function(_lib) {
	this.active = false;
	this.lib = _lib;
	this.platform = new snow_platform_web_audio_howlerjs_AudioSystem(this,this.lib);
	this.platform.init();
	this.sound_list = new haxe_ds_StringMap();
	this.stream_list = new haxe_ds_StringMap();
	this.handles = new haxe_ds_ObjectMap();
	this.active = true;
};
snow_audio_Audio.__name__ = true;
snow_audio_Audio.prototype = {
	create: function(_id,_name,streaming) {
		if(streaming == null) streaming = false;
		if(_name == null) _name = "";
		var _g = this;
		if(_name == "") _name = this.lib.get_uniqueid();
		var sound = null;
		var _asset = this.lib.assets.audio(_id,{ load : !streaming, onload : function(asset) {
			if(asset != null && sound != null) {
				_g.handles.set(asset.audio.handle,sound);
				sound.set_info(asset.audio);
			}
		}});
		if(!streaming) sound = new snow_platform_web_audio_howlerjs_Sound(this,_name); else {
			var sound_stream = new snow_platform_web_audio_howlerjs_SoundStream(this,_name);
			this.stream_list.set(_name,sound_stream);
			sound = sound_stream;
		}
		this.sound_list.set(_name,sound);
		return sound;
	}
	,create_from_bytes: function(_id,_name,bytes) {
		if(_name == null) _name = "";
		var _g = this;
		if(_name == "") _name = this.lib.get_uniqueid();
		var sound = new snow_platform_web_audio_howlerjs_Sound(this,_name);
		this.sound_list.set(_name,sound);
		var _asset = this.lib.assets.audio(_id,{ load : true, bytes : bytes, onload : function(asset) {
			if(asset != null && sound != null) {
				_g.handles.set(asset.audio.handle,sound);
				sound.set_info(asset.audio);
			}
		}});
		return sound;
	}
	,uncreate: function(_name) {
		var _sound = this.sound_list.get(_name);
		if(_sound == null) haxe_Log.trace("    i / audio / " + ("can't find sound, unable to uncreate, use create first: " + _name),{ fileName : "Audio.hx", lineNumber : 145, className : "snow.audio.Audio", methodName : "uncreate"});
		_sound.destroy();
	}
	,on: function(_name,_event,_handler) {
		var sound = this.get(_name);
		if(sound != null) sound.on(_event,_handler);
	}
	,off: function(_name,_event,_handler) {
		var sound = this.get(_name);
		if(sound != null) sound.off(_event,_handler);
	}
	,get: function(_name) {
		var _sound = this.sound_list.get(_name);
		if(_sound == null) haxe_Log.trace("    i / audio / " + ("sound not found, use create first: " + _name),{ fileName : "Audio.hx", lineNumber : 175, className : "snow.audio.Audio", methodName : "get"});
		return _sound;
	}
	,volume: function(_name,_volume) {
		var sound = this.get(_name);
		if(sound != null) {
			if(_volume != null) return sound.set_volume(_volume); else return sound.get_volume();
		}
		return 0;
	}
	,pan: function(_name,_pan) {
		var sound = this.get(_name);
		if(sound != null) {
			if(_pan != null) return sound.set_pan(_pan); else return sound.get_pan();
		}
		return 0;
	}
	,pitch: function(_name,_pitch) {
		var sound = this.get(_name);
		if(sound != null) {
			if(_pitch != null) return sound.set_pitch(_pitch); else return sound.get_pitch();
		}
		return 0;
	}
	,position: function(_name,_position) {
		var sound = this.get(_name);
		if(sound != null) {
			if(_position != null) return sound.set_position(_position); else return sound.get_position();
		}
		return 0;
	}
	,duration: function(_name) {
		var sound = this.get(_name);
		if(sound != null) return sound.get_duration();
		return 0;
	}
	,play: function(_name) {
		if(!this.active) return;
		var sound = this.get(_name);
		if(sound != null) sound.play();
	}
	,loop: function(_name) {
		if(!this.active) return;
		var sound = this.get(_name);
		if(sound != null) sound.loop();
	}
	,pause: function(_name) {
		if(!this.active) return;
		var sound = this.get(_name);
		if(sound != null) sound.pause();
	}
	,stop: function(_name) {
		if(!this.active) return;
		var sound = this.get(_name);
		if(sound != null) sound.stop();
	}
	,toggle: function(_name) {
		if(!this.active) return;
		var sound = this.get(_name);
		if(sound != null) sound.toggle();
	}
	,kill: function(_sound) {
		if(_sound == null) return;
		if(_sound.get_info() != null) {
			var key = _sound.get_info().handle;
			this.handles.remove(key);
		}
		this.sound_list.remove(_sound.name);
		this.stream_list.remove(_sound.name);
	}
	,suspend: function() {
		if(!this.active) return;
		haxe_Log.trace("    i / audio / " + "suspending sound context",{ fileName : "Audio.hx", lineNumber : 336, className : "snow.audio.Audio", methodName : "suspend"});
		this.active = false;
		var $it0 = this.stream_list.iterator();
		while( $it0.hasNext() ) {
			var sound = $it0.next();
			sound.internal_pause();
		}
		this.platform.suspend();
	}
	,resume: function() {
		if(this.active) return;
		haxe_Log.trace("    i / audio / " + "resuming sound context",{ fileName : "Audio.hx", lineNumber : 354, className : "snow.audio.Audio", methodName : "resume"});
		this.active = true;
		this.platform.resume();
		var $it0 = this.stream_list.iterator();
		while( $it0.hasNext() ) {
			var sound = $it0.next();
			sound.internal_play();
		}
	}
	,on_event: function(_event) {
		if(_event.type == 10) this.suspend(); else if(_event.type == 12) this.resume();
	}
	,destroy: function() {
		this.active = false;
		var $it0 = this.sound_list.iterator();
		while( $it0.hasNext() ) {
			var sound = $it0.next();
			sound.destroy();
		}
		this.platform.destroy();
	}
	,update: function() {
		if(!this.active) return;
		var $it0 = this.sound_list.iterator();
		while( $it0.hasNext() ) {
			var _sound = $it0.next();
			if(_sound.playing) _sound.internal_update();
		}
		this.platform.process();
	}
	,__class__: snow_audio_Audio
};
var snow_audio_AudioSystemBinding = function() { };
snow_audio_AudioSystemBinding.__name__ = true;
snow_audio_AudioSystemBinding.__interfaces__ = [snow_utils_AbstractClass];
snow_audio_AudioSystemBinding.prototype = {
	init: function() {
		throw new js__$Boot_HaxeError("abstract method, must override");
	}
	,process: function() {
		throw new js__$Boot_HaxeError("abstract method, must override");
	}
	,destroy: function() {
		throw new js__$Boot_HaxeError("abstract method, must override");
	}
	,suspend: function() {
		throw new js__$Boot_HaxeError("abstract method, must override");
	}
	,resume: function() {
		throw new js__$Boot_HaxeError("abstract method, must override");
	}
	,__class__: snow_audio_AudioSystemBinding
};
var snow_audio_SoundBinding = function(_manager,_name) {
	this.duration = 0.0;
	this.position = 0.0;
	this.looping = false;
	this.pan = 0.0;
	this.volume = 1.0;
	this.pitch = 1.0;
	this.is_stream = false;
	this.loaded = false;
	this.paused = false;
	this.playing = false;
	this.name = "";
	this.name = _name;
	this.manager = _manager;
	this.onload_list = [];
	this.onend_list = [];
};
snow_audio_SoundBinding.__name__ = true;
snow_audio_SoundBinding.prototype = {
	emit: function(_event) {
		switch(_event) {
		case "end":
			this.do_onend();
			break;
		case "load":
			this.do_onload();
			break;
		default:
			haxe_Log.trace("    i / sound / " + ("no event {" + _event + "}"),{ fileName : "Sound.hx", lineNumber : 80, className : "snow.audio.SoundBinding", methodName : "emit"});
		}
	}
	,on: function(_event,_handler) {
		switch(_event) {
		case "end":
			this.onend_list.push(_handler);
			break;
		case "load":
			this.add_onload(_handler);
			break;
		default:
			haxe_Log.trace("    i / sound / " + ("no event {" + _event + "}"),{ fileName : "Sound.hx", lineNumber : 91, className : "snow.audio.SoundBinding", methodName : "on"});
		}
	}
	,off: function(_event,_handler) {
		switch(_event) {
		case "end":
			HxOverrides.remove(this.onend_list,_handler);
			break;
		case "load":
			HxOverrides.remove(this.onload_list,_handler);
			break;
		default:
			haxe_Log.trace("    i / sound / " + ("no event {" + _event + "}"),{ fileName : "Sound.hx", lineNumber : 102, className : "snow.audio.SoundBinding", methodName : "off"});
		}
	}
	,play: function() {
	}
	,loop: function() {
	}
	,stop: function() {
	}
	,pause: function() {
	}
	,destroy: function() {
	}
	,internal_update: function() {
	}
	,internal_play: function() {
	}
	,internal_loop: function() {
	}
	,internal_stop: function() {
	}
	,internal_pause: function() {
	}
	,toggle: function() {
		this.playing = !this.playing;
		if(this.playing) {
			if(this.get_looping()) this.loop(); else this.play();
		} else this.pause();
	}
	,get_info: function() {
		return this.info;
	}
	,set_info: function(_info) {
		return this.info = _info;
	}
	,get_pan: function() {
		return this.pan;
	}
	,get_pitch: function() {
		return this.pitch;
	}
	,get_volume: function() {
		return this.volume;
	}
	,get_looping: function() {
		return this.looping;
	}
	,get_position: function() {
		return this.position;
	}
	,get_duration: function() {
		return 0;
	}
	,set_pan: function(_pan) {
		return this.pan = _pan;
	}
	,set_pitch: function(_pitch) {
		return this.pitch = _pitch;
	}
	,set_volume: function(_volume) {
		return this.volume = _volume;
	}
	,set_position: function(_position) {
		return this.position = _position;
	}
	,set_looping: function(_looping) {
		return this.looping = _looping;
	}
	,do_onload: function() {
		var _g = 0;
		var _g1 = this.onload_list;
		while(_g < _g1.length) {
			var _f = _g1[_g];
			++_g;
			_f(this);
		}
		this.onload_list = null;
		this.onload_list = [];
	}
	,do_onend: function() {
		var _g = 0;
		var _g1 = this.onend_list;
		while(_g < _g1.length) {
			var _f = _g1[_g];
			++_g;
			_f(this);
		}
	}
	,add_onload: function(_onload) {
		if(this.loaded) _onload(this); else this.onload_list.push(_onload);
		return _onload;
	}
	,__class__: snow_audio_SoundBinding
	,__properties__: {get_duration:"get_duration",set_position:"set_position",get_position:"get_position",set_looping:"set_looping",get_looping:"get_looping",set_pan:"set_pan",get_pan:"get_pan",set_volume:"set_volume",get_volume:"get_volume",set_pitch:"set_pitch",get_pitch:"get_pitch",set_info:"set_info",get_info:"get_info"}
};
var snow_input_Input = function(_lib) {
	this.touch_count = 0;
	this.lib = _lib;
	this.platform = new snow_platform_web_input_InputSystem(this,this.lib);
	this.platform.init();
	this.key_code_pressed = new haxe_ds_IntMap();
	this.key_code_down = new haxe_ds_IntMap();
	this.key_code_released = new haxe_ds_IntMap();
	this.scan_code_pressed = new haxe_ds_IntMap();
	this.scan_code_down = new haxe_ds_IntMap();
	this.scan_code_released = new haxe_ds_IntMap();
	this.mouse_button_pressed = new haxe_ds_IntMap();
	this.mouse_button_down = new haxe_ds_IntMap();
	this.mouse_button_released = new haxe_ds_IntMap();
	this.gamepad_button_pressed = new haxe_ds_IntMap();
	this.gamepad_button_down = new haxe_ds_IntMap();
	this.gamepad_button_released = new haxe_ds_IntMap();
	this.gamepad_axis_values = new haxe_ds_IntMap();
	this.touches_down = new haxe_ds_IntMap();
};
snow_input_Input.__name__ = true;
snow_input_Input.prototype = {
	keypressed: function(_code) {
		return this.key_code_pressed.h.hasOwnProperty(_code);
	}
	,keyreleased: function(_code) {
		return this.key_code_released.h.hasOwnProperty(_code);
	}
	,keydown: function(_code) {
		return this.key_code_down.h.hasOwnProperty(_code);
	}
	,scanpressed: function(_code) {
		return this.scan_code_pressed.h.hasOwnProperty(_code);
	}
	,scanreleased: function(_code) {
		return this.scan_code_released.h.hasOwnProperty(_code);
	}
	,scandown: function(_code) {
		return this.scan_code_down.h.hasOwnProperty(_code);
	}
	,mousepressed: function(_button) {
		return this.mouse_button_pressed.h.hasOwnProperty(_button);
	}
	,mousereleased: function(_button) {
		return this.mouse_button_released.h.hasOwnProperty(_button);
	}
	,mousedown: function(_button) {
		return this.mouse_button_down.h.hasOwnProperty(_button);
	}
	,gamepadpressed: function(_gamepad,_button) {
		var _gamepad_state = this.gamepad_button_pressed.h[_gamepad];
		if(_gamepad_state != null) return _gamepad_state.h.hasOwnProperty(_button); else return false;
	}
	,gamepadreleased: function(_gamepad,_button) {
		var _gamepad_state = this.gamepad_button_released.h[_gamepad];
		if(_gamepad_state != null) return _gamepad_state.h.hasOwnProperty(_button); else return false;
	}
	,gamepaddown: function(_gamepad,_button) {
		var _gamepad_state = this.gamepad_button_down.h[_gamepad];
		if(_gamepad_state != null) return _gamepad_state.h.hasOwnProperty(_button); else return false;
	}
	,gamepadaxis: function(_gamepad,_axis) {
		var _gamepad_state = this.gamepad_axis_values.h[_gamepad];
		if(_gamepad_state != null) {
			if(_gamepad_state.h.hasOwnProperty(_axis)) return _gamepad_state.h[_axis];
		}
		return 0;
	}
	,dispatch_key_down_event: function(keycode,scancode,repeat,mod,timestamp,window_id) {
		if(!repeat) {
			this.key_code_pressed.h[keycode] = false;
			this.key_code_down.h[keycode] = true;
			this.scan_code_pressed.h[scancode] = false;
			this.scan_code_down.h[scancode] = true;
		}
		this.lib.host.onkeydown(keycode,scancode,repeat,mod,timestamp,window_id);
	}
	,dispatch_key_up_event: function(keycode,scancode,repeat,mod,timestamp,window_id) {
		this.key_code_released.h[keycode] = false;
		this.key_code_down.remove(keycode);
		this.scan_code_released.h[scancode] = false;
		this.scan_code_down.remove(scancode);
		this.lib.host.onkeyup(keycode,scancode,repeat,mod,timestamp,window_id);
	}
	,dispatch_text_event: function(text,start,length,type,timestamp,window_id) {
		this.lib.host.ontextinput(text,start,length,type,timestamp,window_id);
	}
	,dispatch_mouse_move_event: function(x,y,xrel,yrel,timestamp,window_id) {
		this.lib.host.onmousemove(x,y,xrel,yrel,timestamp,window_id);
	}
	,dispatch_mouse_down_event: function(x,y,button,timestamp,window_id) {
		this.mouse_button_pressed.h[button] = false;
		this.mouse_button_down.h[button] = true;
		this.lib.host.onmousedown(x,y,button,timestamp,window_id);
	}
	,dispatch_mouse_up_event: function(x,y,button,timestamp,window_id) {
		this.mouse_button_released.h[button] = false;
		this.mouse_button_down.remove(button);
		this.lib.host.onmouseup(x,y,button,timestamp,window_id);
	}
	,dispatch_mouse_wheel_event: function(x,y,timestamp,window_id) {
		this.lib.host.onmousewheel(x,y,timestamp,window_id);
	}
	,dispatch_touch_down_event: function(x,y,touch_id,timestamp) {
		if(!this.touches_down.h.hasOwnProperty(touch_id)) {
			this.touch_count++;
			this.touches_down.h[touch_id] = true;
		}
		this.lib.host.ontouchdown(x,y,touch_id,timestamp);
	}
	,dispatch_touch_up_event: function(x,y,touch_id,timestamp) {
		this.lib.host.ontouchup(x,y,touch_id,timestamp);
		if(this.touches_down.remove(touch_id)) this.touch_count--;
	}
	,dispatch_touch_move_event: function(x,y,dx,dy,touch_id,timestamp) {
		this.lib.host.ontouchmove(x,y,dx,dy,touch_id,timestamp);
	}
	,dispatch_gamepad_axis_event: function(gamepad,axis,value,timestamp) {
		if(!this.gamepad_axis_values.h.hasOwnProperty(gamepad)) {
			var value1 = new haxe_ds_IntMap();
			this.gamepad_axis_values.h[gamepad] = value1;
		}
		var this1 = this.gamepad_axis_values.h[gamepad];
		this1.set(axis,value);
		this.lib.host.ongamepadaxis(gamepad,axis,value,timestamp);
	}
	,dispatch_gamepad_button_down_event: function(gamepad,button,value,timestamp) {
		if(!this.gamepad_button_pressed.h.hasOwnProperty(gamepad)) {
			var value1 = new haxe_ds_IntMap();
			this.gamepad_button_pressed.h[gamepad] = value1;
		}
		if(!this.gamepad_button_down.h.hasOwnProperty(gamepad)) {
			var value2 = new haxe_ds_IntMap();
			this.gamepad_button_down.h[gamepad] = value2;
		}
		var this1 = this.gamepad_button_pressed.h[gamepad];
		this1.set(button,false);
		var this2 = this.gamepad_button_down.h[gamepad];
		this2.set(button,true);
		this.lib.host.ongamepaddown(gamepad,button,value,timestamp);
	}
	,dispatch_gamepad_button_up_event: function(gamepad,button,value,timestamp) {
		if(!this.gamepad_button_released.h.hasOwnProperty(gamepad)) {
			var value1 = new haxe_ds_IntMap();
			this.gamepad_button_released.h[gamepad] = value1;
		}
		if(!this.gamepad_button_down.h.hasOwnProperty(gamepad)) {
			var value2 = new haxe_ds_IntMap();
			this.gamepad_button_down.h[gamepad] = value2;
		}
		var this1 = this.gamepad_button_released.h[gamepad];
		this1.set(button,false);
		var this2 = this.gamepad_button_down.h[gamepad];
		this2.remove(button);
		this.lib.host.ongamepadup(gamepad,button,value,timestamp);
	}
	,dispatch_gamepad_device_event: function(gamepad,type,timestamp) {
		this.lib.host.ongamepaddevice(gamepad,type,timestamp);
	}
	,listen: function(_window) {
		this.platform.listen(_window);
	}
	,unlisten: function(_window) {
		this.platform.unlisten(_window);
	}
	,on_event: function(_event) {
		if(_event.type == 6) this.platform.on_event(_event.input);
	}
	,on_gamepad_added: function(_event) {
		this.platform.gamepad_add(_event.which);
	}
	,on_gamepad_removed: function(_event) {
		this.platform.gamepad_remove(_event.which);
	}
	,update: function() {
		this.platform.process();
		this._update_keystate();
		this._update_gamepadstate();
		this._update_mousestate();
	}
	,destroy: function() {
		this.platform.destroy();
	}
	,_update_mousestate: function() {
		var $it0 = this.mouse_button_pressed.keys();
		while( $it0.hasNext() ) {
			var _code = $it0.next();
			if(this.mouse_button_pressed.h[_code]) this.mouse_button_pressed.remove(_code); else this.mouse_button_pressed.h[_code] = true;
		}
		var $it1 = this.mouse_button_released.keys();
		while( $it1.hasNext() ) {
			var _code1 = $it1.next();
			if(this.mouse_button_released.h[_code1]) this.mouse_button_released.remove(_code1); else this.mouse_button_released.h[_code1] = true;
		}
	}
	,_update_gamepadstate: function() {
		var $it0 = this.gamepad_button_pressed.iterator();
		while( $it0.hasNext() ) {
			var _gamepad_pressed = $it0.next();
			var $it1 = _gamepad_pressed.keys();
			while( $it1.hasNext() ) {
				var _button = $it1.next();
				if(_gamepad_pressed.h[_button]) _gamepad_pressed.remove(_button); else _gamepad_pressed.h[_button] = true;
			}
		}
		var $it2 = this.gamepad_button_released.iterator();
		while( $it2.hasNext() ) {
			var _gamepad_released = $it2.next();
			var $it3 = _gamepad_released.keys();
			while( $it3.hasNext() ) {
				var _button1 = $it3.next();
				if(_gamepad_released.h[_button1]) _gamepad_released.remove(_button1); else _gamepad_released.h[_button1] = true;
			}
		}
	}
	,_update_keystate: function() {
		var $it0 = this.key_code_pressed.keys();
		while( $it0.hasNext() ) {
			var _code = $it0.next();
			if(this.key_code_pressed.h[_code]) this.key_code_pressed.remove(_code); else this.key_code_pressed.h[_code] = true;
		}
		var $it1 = this.key_code_released.keys();
		while( $it1.hasNext() ) {
			var _code1 = $it1.next();
			if(this.key_code_released.h[_code1]) this.key_code_released.remove(_code1); else this.key_code_released.h[_code1] = true;
		}
		var $it2 = this.scan_code_pressed.keys();
		while( $it2.hasNext() ) {
			var _code2 = $it2.next();
			if(this.scan_code_pressed.h[_code2]) this.scan_code_pressed.remove(_code2); else this.scan_code_pressed.h[_code2] = true;
		}
		var $it3 = this.scan_code_released.keys();
		while( $it3.hasNext() ) {
			var _code3 = $it3.next();
			if(this.scan_code_released.h[_code3]) this.scan_code_released.remove(_code3); else this.scan_code_released.h[_code3] = true;
		}
	}
	,__class__: snow_input_Input
};
var snow_input_InputSystemBinding = function() { };
snow_input_InputSystemBinding.__name__ = true;
snow_input_InputSystemBinding.__interfaces__ = [snow_utils_AbstractClass];
snow_input_InputSystemBinding.prototype = {
	init: function() {
		throw new js__$Boot_HaxeError("abstract method, must override");
	}
	,process: function() {
		throw new js__$Boot_HaxeError("abstract method, must override");
	}
	,destroy: function() {
		throw new js__$Boot_HaxeError("abstract method, must override");
	}
	,on_event: function(_event) {
		throw new js__$Boot_HaxeError("abstract method, must override");
	}
	,text_input_start: function() {
		throw new js__$Boot_HaxeError("abstract method, must override");
	}
	,text_input_stop: function() {
		throw new js__$Boot_HaxeError("abstract method, must override");
	}
	,text_input_rect: function(x,y,w,h) {
		throw new js__$Boot_HaxeError("abstract method, must override");
	}
	,gamepad_add: function(id) {
		throw new js__$Boot_HaxeError("abstract method, must override");
	}
	,gamepad_remove: function(id) {
		throw new js__$Boot_HaxeError("abstract method, must override");
	}
	,listen: function(window) {
		throw new js__$Boot_HaxeError("abstract method, must override");
	}
	,unlisten: function(window) {
		throw new js__$Boot_HaxeError("abstract method, must override");
	}
	,__class__: snow_input_InputSystemBinding
};
var snow_input_Scancodes = function() { };
snow_input_Scancodes.__name__ = true;
snow_input_Scancodes.$name = function(scancode) {
	var res = null;
	if(scancode >= 0 && scancode < snow_input_Scancodes.scancode_names.length) res = snow_input_Scancodes.scancode_names[scancode];
	if(res != null) return res; else return "";
};
var snow_input_Keycodes = function() { };
snow_input_Keycodes.__name__ = true;
snow_input_Keycodes.from_scan = function(scancode) {
	return scancode | snow_input_Scancodes.MASK;
};
snow_input_Keycodes.to_scan = function(keycode) {
	if((keycode & snow_input_Scancodes.MASK) != 0) return keycode & ~snow_input_Scancodes.MASK;
	switch(keycode) {
	case snow_input_Keycodes.enter:
		return snow_input_Scancodes.enter;
	case snow_input_Keycodes.escape:
		return snow_input_Scancodes.escape;
	case snow_input_Keycodes.backspace:
		return snow_input_Scancodes.backspace;
	case snow_input_Keycodes.tab:
		return snow_input_Scancodes.tab;
	case snow_input_Keycodes.space:
		return snow_input_Scancodes.space;
	case snow_input_Keycodes.slash:
		return snow_input_Scancodes.slash;
	case snow_input_Keycodes.key_0:
		return snow_input_Scancodes.key_0;
	case snow_input_Keycodes.key_1:
		return snow_input_Scancodes.key_1;
	case snow_input_Keycodes.key_2:
		return snow_input_Scancodes.key_2;
	case snow_input_Keycodes.key_3:
		return snow_input_Scancodes.key_3;
	case snow_input_Keycodes.key_4:
		return snow_input_Scancodes.key_4;
	case snow_input_Keycodes.key_5:
		return snow_input_Scancodes.key_5;
	case snow_input_Keycodes.key_6:
		return snow_input_Scancodes.key_6;
	case snow_input_Keycodes.key_7:
		return snow_input_Scancodes.key_7;
	case snow_input_Keycodes.key_8:
		return snow_input_Scancodes.key_8;
	case snow_input_Keycodes.key_9:
		return snow_input_Scancodes.key_9;
	case snow_input_Keycodes.semicolon:
		return snow_input_Scancodes.semicolon;
	case snow_input_Keycodes.equals:
		return snow_input_Scancodes.equals;
	case snow_input_Keycodes.leftbracket:
		return snow_input_Scancodes.leftbracket;
	case snow_input_Keycodes.backslash:
		return snow_input_Scancodes.backslash;
	case snow_input_Keycodes.rightbracket:
		return snow_input_Scancodes.rightbracket;
	case snow_input_Keycodes.backquote:
		return snow_input_Scancodes.grave;
	case snow_input_Keycodes.key_a:
		return snow_input_Scancodes.key_a;
	case snow_input_Keycodes.key_b:
		return snow_input_Scancodes.key_b;
	case snow_input_Keycodes.key_c:
		return snow_input_Scancodes.key_c;
	case snow_input_Keycodes.key_d:
		return snow_input_Scancodes.key_d;
	case snow_input_Keycodes.key_e:
		return snow_input_Scancodes.key_e;
	case snow_input_Keycodes.key_f:
		return snow_input_Scancodes.key_f;
	case snow_input_Keycodes.key_g:
		return snow_input_Scancodes.key_g;
	case snow_input_Keycodes.key_h:
		return snow_input_Scancodes.key_h;
	case snow_input_Keycodes.key_i:
		return snow_input_Scancodes.key_i;
	case snow_input_Keycodes.key_j:
		return snow_input_Scancodes.key_j;
	case snow_input_Keycodes.key_k:
		return snow_input_Scancodes.key_k;
	case snow_input_Keycodes.key_l:
		return snow_input_Scancodes.key_l;
	case snow_input_Keycodes.key_m:
		return snow_input_Scancodes.key_m;
	case snow_input_Keycodes.key_n:
		return snow_input_Scancodes.key_n;
	case snow_input_Keycodes.key_o:
		return snow_input_Scancodes.key_o;
	case snow_input_Keycodes.key_p:
		return snow_input_Scancodes.key_p;
	case snow_input_Keycodes.key_q:
		return snow_input_Scancodes.key_q;
	case snow_input_Keycodes.key_r:
		return snow_input_Scancodes.key_r;
	case snow_input_Keycodes.key_s:
		return snow_input_Scancodes.key_s;
	case snow_input_Keycodes.key_t:
		return snow_input_Scancodes.key_t;
	case snow_input_Keycodes.key_u:
		return snow_input_Scancodes.key_u;
	case snow_input_Keycodes.key_v:
		return snow_input_Scancodes.key_v;
	case snow_input_Keycodes.key_w:
		return snow_input_Scancodes.key_w;
	case snow_input_Keycodes.key_x:
		return snow_input_Scancodes.key_x;
	case snow_input_Keycodes.key_y:
		return snow_input_Scancodes.key_y;
	case snow_input_Keycodes.key_z:
		return snow_input_Scancodes.key_z;
	}
	return snow_input_Scancodes.unknown;
};
snow_input_Keycodes.$name = function(keycode) {
	if((keycode & snow_input_Scancodes.MASK) != 0) return snow_input_Scancodes.$name(keycode & ~snow_input_Scancodes.MASK);
	switch(keycode) {
	case snow_input_Keycodes.enter:
		return snow_input_Scancodes.$name(snow_input_Scancodes.enter);
	case snow_input_Keycodes.escape:
		return snow_input_Scancodes.$name(snow_input_Scancodes.escape);
	case snow_input_Keycodes.backspace:
		return snow_input_Scancodes.$name(snow_input_Scancodes.backspace);
	case snow_input_Keycodes.tab:
		return snow_input_Scancodes.$name(snow_input_Scancodes.tab);
	case snow_input_Keycodes.space:
		return snow_input_Scancodes.$name(snow_input_Scancodes.space);
	case snow_input_Keycodes["delete"]:
		return snow_input_Scancodes.$name(snow_input_Scancodes["delete"]);
	default:
		var decoder = new haxe_Utf8();
		decoder.__b += String.fromCharCode(keycode);
		return decoder.__b;
	}
};
var snow_io_IO = function(_lib) {
	this.lib = _lib;
	this.platform = new snow_platform_web_io_IOSystem(this,this.lib);
	this.platform.init();
};
snow_io_IO.__name__ = true;
snow_io_IO.prototype = {
	url_open: function(_url) {
		this.platform.url_open(_url);
	}
	,data_load: function(_path,_options) {
		return this.platform.data_load(_path,_options);
	}
	,data_save: function(_path,_data,_options) {
		return this.platform.data_save(_path,_data,_options);
	}
	,app_path: function() {
		return snow_Snow.core.app_path();
	}
	,app_path_prefs: function() {
		return snow_Snow.core.app_path_prefs();
	}
	,on_event: function(_event) {
		this.platform.on_event(_event);
	}
	,update: function() {
		this.platform.process();
	}
	,destroy: function() {
		this.platform.destroy();
	}
	,__class__: snow_io_IO
};
var snow_io_IOSystemBinding = function() { };
snow_io_IOSystemBinding.__name__ = true;
snow_io_IOSystemBinding.__interfaces__ = [snow_utils_AbstractClass];
snow_io_IOSystemBinding.prototype = {
	init: function() {
		throw new js__$Boot_HaxeError("abstract method, must override");
	}
	,process: function() {
		throw new js__$Boot_HaxeError("abstract method, must override");
	}
	,destroy: function() {
		throw new js__$Boot_HaxeError("abstract method, must override");
	}
	,on_event: function(_event) {
		throw new js__$Boot_HaxeError("abstract method, must override");
	}
	,url_open: function(_url) {
		throw new js__$Boot_HaxeError("abstract method, must override");
	}
	,data_load: function(_path,_options) {
		throw new js__$Boot_HaxeError("abstract method, must override");
	}
	,data_save: function(_path,_data,_options) {
		throw new js__$Boot_HaxeError("abstract method, must override");
	}
	,__class__: snow_io_IOSystemBinding
};
var snow_io_typedarray__$Float32Array_Float32Array_$Impl_$ = {};
snow_io_typedarray__$Float32Array_Float32Array_$Impl_$.__name__ = true;
snow_io_typedarray__$Float32Array_Float32Array_$Impl_$.__set = function(this1,idx,val) {
	return this1[idx] = val;
};
snow_io_typedarray__$Float32Array_Float32Array_$Impl_$.__get = function(this1,idx) {
	return this1[idx];
};
snow_io_typedarray__$Float32Array_Float32Array_$Impl_$.fromBytes = function(bytes,byteOffset,len) {
	if(byteOffset == null) byteOffset = 0;
	return new Float32Array(bytes.b.buffer,byteOffset,len);
};
snow_io_typedarray__$Float32Array_Float32Array_$Impl_$.toBytes = function(this1) {
	return new haxe_io_Bytes(new Uint8Array(this1.buffer));
};
var snow_io_typedarray__$Int32Array_Int32Array_$Impl_$ = {};
snow_io_typedarray__$Int32Array_Int32Array_$Impl_$.__name__ = true;
snow_io_typedarray__$Int32Array_Int32Array_$Impl_$.__set = function(this1,idx,val) {
	return this1[idx] = val;
};
snow_io_typedarray__$Int32Array_Int32Array_$Impl_$.__get = function(this1,idx) {
	return this1[idx];
};
snow_io_typedarray__$Int32Array_Int32Array_$Impl_$.fromBytes = function(bytes,byteOffset,len) {
	if(byteOffset == null) byteOffset = 0;
	return new Int32Array(bytes.b.buffer,byteOffset,len);
};
snow_io_typedarray__$Int32Array_Int32Array_$Impl_$.toBytes = function(this1) {
	return new haxe_io_Bytes(new Uint8Array(this1.buffer));
};
var snow_io_typedarray__$Uint8Array_Uint8Array_$Impl_$ = {};
snow_io_typedarray__$Uint8Array_Uint8Array_$Impl_$.__name__ = true;
snow_io_typedarray__$Uint8Array_Uint8Array_$Impl_$.__set = function(this1,idx,val) {
	return this1[idx] = val;
};
snow_io_typedarray__$Uint8Array_Uint8Array_$Impl_$.__get = function(this1,idx) {
	return this1[idx];
};
snow_io_typedarray__$Uint8Array_Uint8Array_$Impl_$.fromBytes = function(bytes,byteOffset,len) {
	if(byteOffset == null) byteOffset = 0;
	return new Uint8Array(bytes.b.buffer,byteOffset,len);
};
snow_io_typedarray__$Uint8Array_Uint8Array_$Impl_$.toBytes = function(this1) {
	return new haxe_io_Bytes(new Uint8Array(this1.buffer));
};
var snow_platform_web_Core = function(_app) {
	this._time_now = 0.0;
	this._lf_timestamp = 0.016;
	this.start_timestamp = 0.0;
	this.app = _app;
	this.start_timestamp = this.timestamp();
};
snow_platform_web_Core.__name__ = true;
snow_platform_web_Core.__super__ = snow_CoreBinding;
snow_platform_web_Core.prototype = $extend(snow_CoreBinding.prototype,{
	init: function(_event_handler) {
		this.app.dispatch_system_event({ type : 1});
		this.app.dispatch_system_event({ type : 2});
		if(this.app.snow_config.has_loop) this.request_update();
	}
	,shutdown: function() {
	}
	,timestamp: function() {
		var now;
		if(window.performance != null) now = window.performance.now() / 1000.0; else now = haxe_Timer.stamp();
		return now - this.start_timestamp;
	}
	,app_path: function() {
		return haxe_io_Path.directory(window.location.href) + "/";
	}
	,app_path_prefs: function() {
		return "./";
	}
	,request_update: function() {
		var _g = this;
		if(($_=window,$bind($_,$_.requestAnimationFrame)) != null) window.requestAnimationFrame($bind(this,this.snow_core_loop)); else {
			haxe_Log.trace("     i / core / " + ("warning : requestAnimationFrame not found, falling back to render_rate! render_rate:" + this.app.host.render_rate),{ fileName : "Core.hx", lineNumber : 97, className : "snow.platform.web.Core", methodName : "request_update"});
			window.setTimeout(function() {
				var _now = _g.timestamp();
				_g._time_now += _now - _g._lf_timestamp;
				_g.snow_core_loop(_g._time_now * 1000.0);
				_g._lf_timestamp = _now;
			},this.app.host.render_rate * 1000.0 | 0);
		}
	}
	,snow_core_loop: function(_t) {
		if(_t == null) _t = 0.016;
		this.update();
		this.app.dispatch_system_event({ type : 3});
		this.request_update();
		return true;
	}
	,update: function() {
	}
	,__class__: snow_platform_web_Core
});
var snow_platform_web_assets_AssetSystem = function(_manager) {
	this.manager = _manager;
};
snow_platform_web_assets_AssetSystem.__name__ = true;
snow_platform_web_assets_AssetSystem.__super__ = snow_assets_AssetSystemBinding;
snow_platform_web_assets_AssetSystem.prototype = $extend(snow_assets_AssetSystemBinding.prototype,{
	exists: function(_id,_strict) {
		if(_strict == null) _strict = true;
		if(_strict) return this.manager.listed(_id);
		return true;
	}
	,nearest_power_of_two: function(_value) {
		_value--;
		_value |= _value >> 1;
		_value |= _value >> 2;
		_value |= _value >> 4;
		_value |= _value >> 8;
		_value |= _value >> 16;
		_value++;
		return _value;
	}
	,image_load_info: function(_path,_components,_onload) {
		if(_components == null) _components = 4;
		var ext = haxe_io_Path.extension(_path);
		switch(ext) {
		case "tga":
			return this.image_load_info_tga(_path,_components,_onload);
		case "psd":
			return this.image_load_info_psd(_path,_components,_onload);
		default:
			return this.image_load_info_generic(_path,_components,_onload);
		}
		return null;
	}
	,image_load_info_generic: function(_path,_components,_onload) {
		if(_components == null) _components = 4;
		var _g = this;
		var image;
		var _this = window.document;
		image = _this.createElement("img");
		var info = null;
		image.onload = function(a) {
			var width_pot = _g.nearest_power_of_two(image.width);
			var height_pot = _g.nearest_power_of_two(image.height);
			var image_bytes = _g.POT_Uint8Array_from_image(image.width,image.height,width_pot,height_pot,image);
			info = { id : _path, bpp : 4, width : image.width, height : image.height, width_actual : width_pot, height_actual : height_pot, bpp_source : 4, data : image_bytes};
			image_bytes = null;
			if(_onload != null) _onload(info);
		};
		image.src = _path;
		return info;
	}
	,image_load_info_tga: function(_path,_components,_onload) {
		if(_components == null) _components = 4;
		var _g = this;
		var info = null;
		var load = this.manager.lib.io.data_load(_path,{ binary : false});
		load.then(function(uint) {
			var image = new window.TGA();
			image.load(uint);
			var width_pot = _g.nearest_power_of_two(image.header.width);
			var height_pot = _g.nearest_power_of_two(image.header.height);
			var image_bytes = _g.POT_Uint8Array_from_image(image.header.width,image.header.height,width_pot,height_pot,image.getCanvas());
			info = { id : _path, bpp : 4, width : image.header.width, height : image.header.height, width_actual : width_pot, height_actual : height_pot, bpp_source : 4, data : image_bytes};
			image_bytes = null;
			if(_onload != null) _onload(info);
		}).error(function(e) {
			if(_onload != null) _onload(info);
		});
		return info;
	}
	,POT_Uint8Array_from_image: function(_width,_height,_width_pot,_height_pot,_source) {
		var tmp_canvas;
		var _this = window.document;
		tmp_canvas = _this.createElement("canvas");
		tmp_canvas.width = _width_pot;
		tmp_canvas.height = _height_pot;
		var tmp_context = tmp_canvas.getContext("2d",null);
		tmp_context.clearRect(0,0,tmp_canvas.width,tmp_canvas.height);
		tmp_context.drawImage(_source,0,0,_width,_height);
		var image_bytes = null;
		try {
			image_bytes = tmp_context.getImageData(0,0,tmp_canvas.width,tmp_canvas.height);
		} catch( e ) {
			if (e instanceof js__$Boot_HaxeError) e = e.val;
			var tips = "- textures served from file:/// throw security errors\n";
			tips += "- textures served over http:// work for cross origin byte requests";
			haxe_Log.trace("i / assets / " + tips,{ fileName : "AssetSystem.hx", lineNumber : 188, className : "snow.platform.web.assets.AssetSystem", methodName : "POT_Uint8Array_from_image"});
			throw new js__$Boot_HaxeError(e);
		}
		tmp_canvas = null;
		tmp_context = null;
		var view = image_bytes.data;
		var len = null;
		var this1;
		if(view != null) this1 = new Uint8Array(view); else this1 = null;
		return this1;
	}
	,image_load_info_psd: function(_path,_components,_onload) {
		if(_components == null) _components = 4;
		var _g = this;
		var info = null;
		var image = new snow_platform_web_assets_psd_PSD();
		image.open(_path,function(psdimage) {
			var png_then = function(png_image) {
				var width_pot = _g.nearest_power_of_two(psdimage.header.width);
				var height_pot = _g.nearest_power_of_two(psdimage.header.height);
				var image_bytes = _g.POT_Uint8Array_from_image(psdimage.header.width,psdimage.header.height,width_pot,height_pot,png_image);
				info = { id : _path, bpp : 4, width : psdimage.header.width, height : psdimage.header.height, width_actual : width_pot, height_actual : height_pot, bpp_source : 4, data : image_bytes};
				image_bytes = null;
				if(_onload != null) _onload(info);
			};
			psdimage.image.toPng().then(png_then);
		});
		return info;
	}
	,image_info_from_bytes: function(_path,_bytes,_components) {
		if(_components == null) _components = 4;
		if(_bytes == null) {
			haxe_Log.trace("i / assets / " + ("invalid bytes passed to image_info_from_bytes " + _path),{ fileName : "AssetSystem.hx", lineNumber : 248, className : "snow.platform.web.assets.AssetSystem", methodName : "image_info_from_bytes"});
			return null;
		}
		var _raw_bytes = snow_io_typedarray__$Uint8Array_Uint8Array_$Impl_$.toBytes(_bytes);
		var byte_input = new haxe_io_BytesInput(_raw_bytes,0,_raw_bytes.length);
		var png_reader = new snow_utils_format_png_Reader(byte_input);
		png_reader.checkCRC = false;
		var png_data = png_reader.read();
		var png_bytes = snow_utils_format_png_Tools.extract32(png_data);
		var png_header = snow_utils_format_png_Tools.getHeader(png_data);
		return { id : _path, bpp : _components, width : png_header.width, height : png_header.height, width_actual : png_header.width, height_actual : png_header.height, bpp_source : png_header.colbits, data : (function($this) {
			var $r;
			var elements = png_bytes.b.buffer;
			var len = null;
			var this1;
			if(elements != null) this1 = new Uint8Array(elements); else this1 = null;
			$r = this1;
			return $r;
		}(this))};
	}
	,audio_load_info: function(_path,_format,_load,_onload) {
		if(_load == null) _load = true;
		var _g = this;
		var info = { format : _format, id : _path, handle : null, data : null};
		info.handle = new window.Howl({ urls : [_path], onend : function() {
			_g.manager.lib.audio.platform._on_end(info.handle);
		}, onload : function() {
			if(_onload != null) _onload(info);
		}});
		return info;
	}
	,audio_info_from_bytes: function(_path,_bytes,_format) {
		throw new js__$Boot_HaxeError("unimplemented");
	}
	,__class__: snow_platform_web_assets_AssetSystem
});
var snow_platform_web_assets_psd_PSD = function() {
	this._PSD = window.require("psd");
};
snow_platform_web_assets_psd_PSD.__name__ = true;
snow_platform_web_assets_psd_PSD.prototype = {
	open: function(_url,_psd_onload) {
		this._PSD.fromURL(_url).then(function(psd) {
			if(_psd_onload) _psd_onload(psd);
		});
	}
	,__class__: snow_platform_web_assets_psd_PSD
};
var snow_platform_web_audio_AudioSystem = function(_manager,_lib) {
	this.manager = _manager;
	this.lib = _lib;
};
snow_platform_web_audio_AudioSystem.__name__ = true;
snow_platform_web_audio_AudioSystem.__super__ = snow_audio_AudioSystemBinding;
snow_platform_web_audio_AudioSystem.prototype = $extend(snow_audio_AudioSystemBinding.prototype,{
	init: function() {
	}
	,process: function() {
	}
	,destroy: function() {
	}
	,suspend: function() {
	}
	,resume: function() {
	}
	,__class__: snow_platform_web_audio_AudioSystem
});
var snow_platform_web_audio_Sound = function(_manager,_name) {
	snow_audio_SoundBinding.call(this,_manager,_name);
};
snow_platform_web_audio_Sound.__name__ = true;
snow_platform_web_audio_Sound.__super__ = snow_audio_SoundBinding;
snow_platform_web_audio_Sound.prototype = $extend(snow_audio_SoundBinding.prototype,{
	__class__: snow_platform_web_audio_Sound
});
var snow_platform_web_audio_howlerjs_Sound = function(_manager,_name) {
	this.volume_dirty = false;
	this.pan_dirty = false;
	snow_platform_web_audio_Sound.call(this,_manager,_name);
};
snow_platform_web_audio_howlerjs_Sound.__name__ = true;
snow_platform_web_audio_howlerjs_Sound.__super__ = snow_platform_web_audio_Sound;
snow_platform_web_audio_howlerjs_Sound.prototype = $extend(snow_platform_web_audio_Sound.prototype,{
	set_info: function(_info) {
		if(this.get_info() != null) this.destroy();
		this.info = null;
		if(_info == null) {
			haxe_Log.trace("    i / sound / " + "not creating sound, info was null",{ fileName : "Sound.hx", lineNumber : 33, className : "snow.platform.web.audio.howlerjs.Sound", methodName : "set_info"});
			return this.get_info();
		}
		this.info = _info;
		this.loaded = true;
		this.emit("load");
		return this.get_info();
	}
	,set_pan: function(_pan) {
		this.pan_dirty = true;
		return this.pan = _pan;
	}
	,set_volume: function(_volume) {
		this.volume_dirty = true;
		return this.volume = _volume;
	}
	,set_pitch: function(_pitch) {
		this.get_info().handle._rate = _pitch;
		return this.pitch = _pitch;
	}
	,set_position: function(_position) {
		if(this.get_info() != null && this.get_info().handle != null) this.get_info().handle.pos(_position);
		return this.position = _position;
	}
	,get_position: function() {
		if(this.get_info() != null && this.get_info().handle != null) return this.get_info().handle.pos();
		return this.position;
	}
	,get_duration: function() {
		if(this.get_info() != null && this.get_info().handle != null) return this.get_info().handle._duration;
		return 0;
	}
	,play: function() {
		if(this.get_info() != null && this.get_info().handle != null) {
			this.playing = true;
			this.set_looping(false);
			this.get_info().handle.loop(false);
			this.get_info().handle.play();
			if(this.pan_dirty) this.get_info().handle.pos3d(this.get_pan());
			if(this.volume_dirty) this.get_info().handle.volume(this.get_volume());
		}
	}
	,loop: function() {
		if(this.get_info() != null && this.get_info().handle != null) {
			this.playing = true;
			this.set_looping(true);
			this.get_info().handle.loop(true);
			this.get_info().handle.play();
			if(this.pan_dirty) this.get_info().handle.pos3d(this.get_pan());
			if(this.volume_dirty) this.get_info().handle.volume(this.get_volume());
		}
	}
	,stop: function() {
		this.playing = false;
		if(this.get_info() != null && this.get_info().handle != null) this.get_info().handle.stop();
	}
	,pause: function() {
		if(this.get_info() != null && this.get_info().handle != null) this.get_info().handle.pause();
	}
	,destroy: function() {
		if(this.get_info() != null && this.get_info().handle != null) this.get_info().handle.unload();
		this.manager.kill(this);
	}
	,__class__: snow_platform_web_audio_howlerjs_Sound
});
var snow_platform_web_audio_SoundStream = function(_manager,_name) {
	snow_platform_web_audio_howlerjs_Sound.call(this,_manager,_name);
};
snow_platform_web_audio_SoundStream.__name__ = true;
snow_platform_web_audio_SoundStream.__super__ = snow_platform_web_audio_howlerjs_Sound;
snow_platform_web_audio_SoundStream.prototype = $extend(snow_platform_web_audio_howlerjs_Sound.prototype,{
	__class__: snow_platform_web_audio_SoundStream
});
var snow_platform_web_audio_howlerjs_AudioSystem = function(_manager,_lib) {
	snow_platform_web_audio_AudioSystem.call(this,_manager,_lib);
};
snow_platform_web_audio_howlerjs_AudioSystem.__name__ = true;
snow_platform_web_audio_howlerjs_AudioSystem.__super__ = snow_platform_web_audio_AudioSystem;
snow_platform_web_audio_howlerjs_AudioSystem.prototype = $extend(snow_platform_web_audio_AudioSystem.prototype,{
	init: function() {
		this.suspended_sounds = [];
	}
	,process: function() {
	}
	,destroy: function() {
	}
	,suspend: function() {
		var $it0 = this.manager.handles.iterator();
		while( $it0.hasNext() ) {
			var sound = $it0.next();
			if(sound.playing) {
				sound.toggle();
				this.suspended_sounds.push(sound);
			}
		}
	}
	,resume: function() {
		while(this.suspended_sounds.length > 0) {
			var sound = this.suspended_sounds.pop();
			sound.toggle();
		}
	}
	,_on_end: function(handle) {
		var sound = this.manager.handles.h[handle.__id__];
		if(sound != null) sound.emit("end");
	}
	,__class__: snow_platform_web_audio_howlerjs_AudioSystem
});
var snow_platform_web_audio_howlerjs_SoundStream = function(_manager,_name) {
	snow_platform_web_audio_SoundStream.call(this,_manager,_name);
};
snow_platform_web_audio_howlerjs_SoundStream.__name__ = true;
snow_platform_web_audio_howlerjs_SoundStream.__super__ = snow_platform_web_audio_SoundStream;
snow_platform_web_audio_howlerjs_SoundStream.prototype = $extend(snow_platform_web_audio_SoundStream.prototype,{
	__class__: snow_platform_web_audio_howlerjs_SoundStream
});
var snow_platform_web_input_DOMKeys = function() { };
snow_platform_web_input_DOMKeys.__name__ = true;
snow_platform_web_input_DOMKeys.dom_key_to_keycode = function(_keycode) {
	switch(_keycode) {
	case 16:
		return snow_input_Keycodes.lshift;
	case 17:
		return snow_input_Keycodes.lctrl;
	case 18:
		return snow_input_Keycodes.lalt;
	case 20:
		return snow_input_Keycodes.capslock;
	case 33:
		return snow_input_Keycodes.pageup;
	case 34:
		return snow_input_Keycodes.pagedown;
	case 35:
		return snow_input_Keycodes.end;
	case 36:
		return snow_input_Keycodes.home;
	case 37:
		return snow_input_Keycodes.left;
	case 38:
		return snow_input_Keycodes.up;
	case 39:
		return snow_input_Keycodes.right;
	case 40:
		return snow_input_Keycodes.down;
	case 44:
		return snow_input_Keycodes.printscreen;
	case 45:
		return snow_input_Keycodes.insert;
	case 46:
		return snow_input_Keycodes["delete"];
	case 91:
		return snow_input_Keycodes.lmeta;
	case 93:
		return snow_input_Keycodes.rmeta;
	case 224:
		return snow_input_Keycodes.lmeta;
	case 96:
		return snow_input_Keycodes.kp_0;
	case 97:
		return snow_input_Keycodes.kp_1;
	case 98:
		return snow_input_Keycodes.kp_2;
	case 99:
		return snow_input_Keycodes.kp_3;
	case 100:
		return snow_input_Keycodes.kp_4;
	case 101:
		return snow_input_Keycodes.kp_5;
	case 102:
		return snow_input_Keycodes.kp_6;
	case 103:
		return snow_input_Keycodes.kp_7;
	case 104:
		return snow_input_Keycodes.kp_8;
	case 105:
		return snow_input_Keycodes.kp_9;
	case 106:
		return snow_input_Keycodes.kp_multiply;
	case 107:
		return snow_input_Keycodes.kp_plus;
	case 109:
		return snow_input_Keycodes.kp_minus;
	case 110:
		return snow_input_Keycodes.kp_decimal;
	case 111:
		return snow_input_Keycodes.kp_divide;
	case 144:
		return snow_input_Keycodes.numlockclear;
	case 112:
		return snow_input_Keycodes.f1;
	case 113:
		return snow_input_Keycodes.f2;
	case 114:
		return snow_input_Keycodes.f3;
	case 115:
		return snow_input_Keycodes.f4;
	case 116:
		return snow_input_Keycodes.f5;
	case 117:
		return snow_input_Keycodes.f6;
	case 118:
		return snow_input_Keycodes.f7;
	case 119:
		return snow_input_Keycodes.f8;
	case 120:
		return snow_input_Keycodes.f9;
	case 121:
		return snow_input_Keycodes.f10;
	case 122:
		return snow_input_Keycodes.f11;
	case 123:
		return snow_input_Keycodes.f12;
	case 124:
		return snow_input_Keycodes.f13;
	case 125:
		return snow_input_Keycodes.f14;
	case 126:
		return snow_input_Keycodes.f15;
	case 127:
		return snow_input_Keycodes.f16;
	case 128:
		return snow_input_Keycodes.f17;
	case 129:
		return snow_input_Keycodes.f18;
	case 130:
		return snow_input_Keycodes.f19;
	case 131:
		return snow_input_Keycodes.f20;
	case 132:
		return snow_input_Keycodes.f21;
	case 133:
		return snow_input_Keycodes.f22;
	case 134:
		return snow_input_Keycodes.f23;
	case 135:
		return snow_input_Keycodes.f24;
	case 160:
		return snow_input_Keycodes.caret;
	case 161:
		return snow_input_Keycodes.exclaim;
	case 162:
		return snow_input_Keycodes.quotedbl;
	case 163:
		return snow_input_Keycodes.hash;
	case 164:
		return snow_input_Keycodes.dollar;
	case 165:
		return snow_input_Keycodes.percent;
	case 166:
		return snow_input_Keycodes.ampersand;
	case 167:
		return snow_input_Keycodes.underscore;
	case 168:
		return snow_input_Keycodes.leftparen;
	case 169:
		return snow_input_Keycodes.rightparen;
	case 170:
		return snow_input_Keycodes.asterisk;
	case 171:
		return snow_input_Keycodes.plus;
	case 172:
		return snow_input_Keycodes.backslash;
	case 173:
		return snow_input_Keycodes.minus;
	case 174:
		return snow_input_Keycodes.leftbracket;
	case 175:
		return snow_input_Keycodes.rightbracket;
	case 176:
		return snow_input_Keycodes.backquote;
	case 181:
		return snow_input_Keycodes.audiomute;
	case 182:
		return snow_input_Keycodes.volumedown;
	case 183:
		return snow_input_Keycodes.volumeup;
	case 188:
		return snow_input_Keycodes.comma;
	case 190:
		return snow_input_Keycodes.period;
	case 191:
		return snow_input_Keycodes.slash;
	case 192:
		return snow_input_Keycodes.backquote;
	case 219:
		return snow_input_Keycodes.leftbracket;
	case 221:
		return snow_input_Keycodes.rightbracket;
	case 220:
		return snow_input_Keycodes.backslash;
	case 222:
		return snow_input_Keycodes.quote;
	}
	return _keycode;
};
var snow_platform_web_input_InputSystem = function(_manager,_lib) {
	this.gamepads_supported = false;
	this.manager = _manager;
	this.lib = _lib;
};
snow_platform_web_input_InputSystem.__name__ = true;
snow_platform_web_input_InputSystem.__super__ = snow_input_InputSystemBinding;
snow_platform_web_input_InputSystem.prototype = $extend(snow_input_InputSystemBinding.prototype,{
	init: function() {
		window.document.addEventListener("keypress",$bind(this,this.on_keypress));
		window.document.addEventListener("keydown",$bind(this,this.on_keydown));
		window.document.addEventListener("keyup",$bind(this,this.on_keyup));
		this.active_gamepads = new haxe_ds_IntMap();
		this.gamepads_supported = this.get_gamepad_list() != null;
		haxe_Log.trace("i / input / " + ("Gamepads supported: " + Std.string(this.gamepads_supported)),{ fileName : "InputSystem.hx", lineNumber : 57, className : "snow.platform.web.input.InputSystem", methodName : "init"});
	}
	,process: function() {
		if(this.gamepads_supported) this.poll_gamepads();
	}
	,destroy: function() {
	}
	,listen: function(window) {
		window.handle.addEventListener("contextmenu",$bind(this,this.on_contextmenu));
		window.handle.addEventListener("mousedown",$bind(this,this.on_mousedown));
		window.handle.addEventListener("mouseup",$bind(this,this.on_mouseup));
		window.handle.addEventListener("mousemove",$bind(this,this.on_mousemove));
		window.handle.addEventListener("mousewheel",$bind(this,this.on_mousewheel));
		window.handle.addEventListener("wheel",$bind(this,this.on_mousewheel));
		window.handle.addEventListener("touchstart",$bind(this,this.on_touchdown));
		window.handle.addEventListener("touchend",$bind(this,this.on_touchup));
		window.handle.addEventListener("touchmove",$bind(this,this.on_touchmove));
	}
	,unlisten: function(window) {
	}
	,on_event: function(_event) {
	}
	,text_input_start: function() {
	}
	,text_input_stop: function() {
	}
	,text_input_rect: function(x,y,w,h) {
	}
	,gamepad_add: function(id) {
	}
	,gamepad_remove: function(id) {
	}
	,poll_gamepads: function() {
		if(!this.gamepads_supported) return;
		var list = this.get_gamepad_list();
		if(list != null) {
			var _g1 = 0;
			var _g = list.length;
			while(_g1 < _g) {
				var i = _g1++;
				if(list[i] != null) this.handle_gamepad(list[i]); else {
					var _gamepad = this.active_gamepads.h[i];
					if(_gamepad != null) this.manager.dispatch_gamepad_device_event(_gamepad.index,2,snow_Snow.core.timestamp());
					this.active_gamepads.remove(i);
				}
			}
		}
	}
	,handle_gamepad: function(_gamepad) {
		if(_gamepad == null) return;
		if(!(function($this) {
			var $r;
			var key = _gamepad.index;
			$r = $this.active_gamepads.h.hasOwnProperty(key);
			return $r;
		}(this))) {
			var _new_gamepad = { id : _gamepad.id, index : _gamepad.index, axes : [], buttons : [], timestamp : snow_Snow.core.timestamp()};
			var axes = _gamepad.axes;
			var _g = 0;
			while(_g < axes.length) {
				var value = axes[_g];
				++_g;
				_new_gamepad.axes.push(value);
			}
			var _button_list = _gamepad.buttons;
			var _g1 = 0;
			while(_g1 < _button_list.length) {
				var _button = _button_list[_g1];
				++_g1;
				_new_gamepad.buttons.push({ pressed : false, value : 0});
			}
			this.active_gamepads.h[_new_gamepad.index] = _new_gamepad;
			this.manager.dispatch_gamepad_device_event(_new_gamepad.index,1,_new_gamepad.timestamp);
		} else {
			var gamepad;
			var key1 = _gamepad.index;
			gamepad = this.active_gamepads.h[key1];
			if(gamepad.id != _gamepad.id) gamepad.id = _gamepad.id;
			var axes_changed = [];
			var buttons_changed = [];
			var last_axes = gamepad.axes;
			var last_buttons = gamepad.buttons;
			var new_axes = _gamepad.axes;
			var new_buttons = _gamepad.buttons;
			var axis_index = 0;
			var _g2 = 0;
			while(_g2 < new_axes.length) {
				var axis = new_axes[_g2];
				++_g2;
				if(axis != last_axes[axis_index]) {
					axes_changed.push(axis_index);
					gamepad.axes[axis_index] = axis;
				}
				axis_index++;
			}
			var button_index = 0;
			var _g3 = 0;
			while(_g3 < new_buttons.length) {
				var button = new_buttons[_g3];
				++_g3;
				if(button.value != last_buttons[button_index].value) {
					buttons_changed.push(button_index);
					gamepad.buttons[button_index].pressed = button.pressed;
					gamepad.buttons[button_index].value = button.value;
				}
				button_index++;
			}
			var _g4 = 0;
			while(_g4 < axes_changed.length) {
				var index = axes_changed[_g4];
				++_g4;
				this.manager.dispatch_gamepad_axis_event(gamepad.index,index,new_axes[index],gamepad.timestamp);
			}
			var _g5 = 0;
			while(_g5 < buttons_changed.length) {
				var index1 = buttons_changed[_g5];
				++_g5;
				if(new_buttons[index1].pressed == true) this.manager.dispatch_gamepad_button_down_event(gamepad.index,index1,new_buttons[index1].value,gamepad.timestamp); else this.manager.dispatch_gamepad_button_up_event(gamepad.index,index1,new_buttons[index1].value,gamepad.timestamp);
			}
		}
	}
	,fail_gamepads: function() {
		this.gamepads_supported = false;
		haxe_Log.trace("i / input / " + "Gamepads are not supported in this browser :(",{ fileName : "InputSystem.hx", lineNumber : 288, className : "snow.platform.web.input.InputSystem", methodName : "fail_gamepads"});
	}
	,get_gamepad_list: function() {
		var modernizr = window.Modernizr;
		if(modernizr != null) {
			if(modernizr.gamepads == true) {
				if(($_=window.navigator,$bind($_,$_.getGamepads)) != null) return window.navigator.getGamepads();
				if(window.navigator.webkitGetGamepads != null) return window.navigator.webkitGetGamepads();
				this.fail_gamepads();
			} else this.fail_gamepads();
		}
		return null;
	}
	,on_mousedown: function(_mouse_event) {
		var _window = this.lib.windowing.window_from_handle(_mouse_event.target);
		this.manager.dispatch_mouse_down_event(_mouse_event.pageX - window.pageXOffset - _window.x,_mouse_event.pageY - window.pageYOffset - _window.y,_mouse_event.button + 1,_mouse_event.timeStamp,_window.id);
	}
	,on_mouseup: function(_mouse_event) {
		var _window = this.lib.windowing.window_from_handle(_mouse_event.target);
		this.manager.dispatch_mouse_up_event(_mouse_event.pageX - window.pageXOffset - _window.x,_mouse_event.pageY - window.pageYOffset - _window.y,_mouse_event.button + 1,_mouse_event.timeStamp,_window.id);
	}
	,on_mousemove: function(_mouse_event) {
		var _window = this.lib.windowing.window_from_handle(_mouse_event.target);
		var _movement_x = _mouse_event.movementX;
		var _movement_y = _mouse_event.movementY;
		if(_mouse_event.webkitMovementX != null) {
			_movement_x = _mouse_event.webkitMovementX;
			_movement_y = _mouse_event.webkitMovementY;
		} else if(_mouse_event.mozMovementX != null) {
			_movement_x = _mouse_event.mozMovementX;
			_movement_y = _mouse_event.mozMovementY;
		}
		this.manager.dispatch_mouse_move_event(_mouse_event.pageX - window.pageXOffset - _window.x,_mouse_event.pageY - window.pageYOffset - _window.y,_movement_x,_movement_y,_mouse_event.timeStamp,_window.id);
	}
	,on_mousewheel: function(_wheel_event) {
		if(this.lib.config.web.prevent_default_mouse_wheel) _wheel_event.preventDefault();
		var _window = this.lib.windowing.window_from_handle(_wheel_event.target);
		var _x = 0;
		var _y = 0;
		if(_wheel_event.deltaY != null) _y = _wheel_event.deltaY; else if(_wheel_event.wheelDeltaY != null) _y = -_wheel_event.wheelDeltaY / 3 | 0;
		if(_wheel_event.deltaX != null) _x = _wheel_event.deltaX; else if(_wheel_event.wheelDeltaX != null) _x = -_wheel_event.wheelDeltaX / 3 | 0;
		this.manager.dispatch_mouse_wheel_event(Math.round(_x / 16),Math.round(_y / 16),_wheel_event.timeStamp,_window.id);
	}
	,on_contextmenu: function(_event) {
		if(this.lib.config.web.no_context_menu) _event.preventDefault();
	}
	,on_keypress: function(_key_event) {
		if(_key_event.which != 0 && HxOverrides.indexOf(snow_platform_web_input_InputSystem._keypress_blacklist,_key_event.keyCode,0) == -1) {
			var _text = String.fromCharCode(_key_event.charCode);
			this.manager.dispatch_text_event(_text,0,_text.length,2,_key_event.timeStamp,1);
		}
	}
	,on_keydown: function(_key_event) {
		var _keycode = this.convert_keycode(_key_event.keyCode);
		var _scancode = snow_input_Keycodes.to_scan(_keycode);
		var _mod_state = this.mod_state_from_event(_key_event);
		if(HxOverrides.indexOf(this.lib.config.web.prevent_default_keys,_keycode,0) != -1) _key_event.preventDefault();
		this.manager.dispatch_key_down_event(_keycode,_scancode,_key_event.repeat,_mod_state,_key_event.timeStamp,1);
	}
	,on_keyup: function(_key_event) {
		var _keycode = this.convert_keycode(_key_event.keyCode);
		var _scancode = snow_input_Keycodes.to_scan(_keycode);
		var _mod_state = this.mod_state_from_event(_key_event);
		if(HxOverrides.indexOf(this.lib.config.web.prevent_default_keys,_keycode,0) != -1) _key_event.preventDefault();
		this.manager.dispatch_key_up_event(_keycode,_scancode,_key_event.repeat,_mod_state,_key_event.timeStamp,1);
	}
	,mod_state_from_event: function(_key_event) {
		var _none = !_key_event.altKey && !_key_event.ctrlKey && !_key_event.metaKey && !_key_event.shiftKey;
		return { none : _none, lshift : _key_event.shiftKey, rshift : _key_event.shiftKey, lctrl : _key_event.ctrlKey, rctrl : _key_event.ctrlKey, lalt : _key_event.altKey, ralt : _key_event.altKey, lmeta : _key_event.metaKey, rmeta : _key_event.metaKey, num : false, caps : false, mode : false, ctrl : _key_event.ctrlKey, shift : _key_event.shiftKey, alt : _key_event.altKey, meta : _key_event.metaKey};
	}
	,convert_keycode: function(dom_keycode) {
		if(dom_keycode >= 65 && dom_keycode <= 90) return dom_keycode + 32;
		return snow_platform_web_input_DOMKeys.dom_key_to_keycode(dom_keycode);
	}
	,on_touchdown: function(_touch_event) {
		var _window = this.lib.windowing.window_from_handle(_touch_event.target);
		var _g = 0;
		var _g1 = _touch_event.changedTouches;
		while(_g < _g1.length) {
			var touch = _g1[_g];
			++_g;
			var _x = touch.pageX - window.pageXOffset - _window.x;
			var _y = touch.pageY - window.pageYOffset - _window.y;
			_x = _x / _window.width;
			_y = _y / _window.height;
			this.manager.dispatch_touch_down_event(_x,_y,touch.identifier,snow_Snow.core.timestamp());
		}
	}
	,on_touchup: function(_touch_event) {
		var _window = this.lib.windowing.window_from_handle(_touch_event.target);
		var _g = 0;
		var _g1 = _touch_event.changedTouches;
		while(_g < _g1.length) {
			var touch = _g1[_g];
			++_g;
			var _x = touch.pageX - window.pageXOffset - _window.x;
			var _y = touch.pageY - window.pageYOffset - _window.y;
			_x = _x / _window.width;
			_y = _y / _window.height;
			this.manager.dispatch_touch_up_event(_x,_y,touch.identifier,snow_Snow.core.timestamp());
		}
	}
	,on_touchmove: function(_touch_event) {
		var _window = this.lib.windowing.window_from_handle(_touch_event.target);
		var _g = 0;
		var _g1 = _touch_event.changedTouches;
		while(_g < _g1.length) {
			var touch = _g1[_g];
			++_g;
			var _x = touch.pageX - window.pageXOffset - _window.x;
			var _y = touch.pageY - window.pageYOffset - _window.y;
			_x = _x / _window.width;
			_y = _y / _window.height;
			this.manager.dispatch_touch_move_event(_x,_y,0,0,touch.identifier,snow_Snow.core.timestamp());
		}
	}
	,__class__: snow_platform_web_input_InputSystem
});
var snow_platform_web_io_IOSystem = function(_manager,_lib) {
	this.manager = _manager;
	this.lib = _lib;
};
snow_platform_web_io_IOSystem.__name__ = true;
snow_platform_web_io_IOSystem.__super__ = snow_io_IOSystemBinding;
snow_platform_web_io_IOSystem.prototype = $extend(snow_io_IOSystemBinding.prototype,{
	url_open: function(_url) {
		if(_url != null && _url.length > 0) window.open(_url,"_blank");
	}
	,data_load: function(_path,_options) {
		return new snow_utils_Promise(function(resolve,reject) {
			var _async = true;
			var _binary = true;
			if(_options != null) {
				if(_options.binary != null) _binary = _options.binary;
			}
			var request = new XMLHttpRequest();
			request.open("GET",_path,_async);
			if(_binary) request.overrideMimeType("text/plain; charset=x-user-defined"); else request.overrideMimeType("text/plain; charset=UTF-8");
			if(_async) request.responseType = "arraybuffer";
			request.onload = function(data) {
				if(request.status == 200) resolve((function($this) {
					var $r;
					var elements = request.response;
					var len = null;
					var this1;
					if(elements != null) this1 = new Uint8Array(elements); else this1 = null;
					$r = this1;
					return $r;
				}(this))); else reject("request status was " + request.status + " / " + request.statusText);
			};
			request.send();
		});
	}
	,data_save: function(_path,_data,_options) {
		return false;
	}
	,init: function() {
	}
	,process: function() {
	}
	,destroy: function() {
	}
	,on_event: function(_event) {
	}
	,__class__: snow_platform_web_io_IOSystem
});
var snow_platform_web_render_opengl_GL = function() { };
snow_platform_web_render_opengl_GL.__name__ = true;
snow_platform_web_render_opengl_GL.__properties__ = {get_version:"get_version"}
snow_platform_web_render_opengl_GL.versionString = function() {
	var ver = snow_platform_web_render_opengl_GL.current_context.getParameter(7938);
	var slver = snow_platform_web_render_opengl_GL.current_context.getParameter(35724);
	var ren = snow_platform_web_render_opengl_GL.current_context.getParameter(7937);
	var ven = snow_platform_web_render_opengl_GL.current_context.getParameter(7936);
	return "/ " + ver + " / " + slver + " / " + ren + " / " + ven + " /";
};
snow_platform_web_render_opengl_GL.activeTexture = function(texture) {
	snow_platform_web_render_opengl_GL.current_context.activeTexture(texture);
};
snow_platform_web_render_opengl_GL.attachShader = function(program,shader) {
	snow_platform_web_render_opengl_GL.current_context.attachShader(program,shader);
};
snow_platform_web_render_opengl_GL.bindAttribLocation = function(program,index,name) {
	snow_platform_web_render_opengl_GL.current_context.bindAttribLocation(program,index,name);
};
snow_platform_web_render_opengl_GL.bindBuffer = function(target,buffer) {
	snow_platform_web_render_opengl_GL.current_context.bindBuffer(target,buffer);
};
snow_platform_web_render_opengl_GL.bindFramebuffer = function(target,framebuffer) {
	snow_platform_web_render_opengl_GL.current_context.bindFramebuffer(target,framebuffer);
};
snow_platform_web_render_opengl_GL.bindRenderbuffer = function(target,renderbuffer) {
	snow_platform_web_render_opengl_GL.current_context.bindRenderbuffer(target,renderbuffer);
};
snow_platform_web_render_opengl_GL.bindTexture = function(target,texture) {
	snow_platform_web_render_opengl_GL.current_context.bindTexture(target,texture);
};
snow_platform_web_render_opengl_GL.blendColor = function(red,green,blue,alpha) {
	snow_platform_web_render_opengl_GL.current_context.blendColor(red,green,blue,alpha);
};
snow_platform_web_render_opengl_GL.blendEquation = function(mode) {
	snow_platform_web_render_opengl_GL.current_context.blendEquation(mode);
};
snow_platform_web_render_opengl_GL.blendEquationSeparate = function(modeRGB,modeAlpha) {
	snow_platform_web_render_opengl_GL.current_context.blendEquationSeparate(modeRGB,modeAlpha);
};
snow_platform_web_render_opengl_GL.blendFunc = function(sfactor,dfactor) {
	snow_platform_web_render_opengl_GL.current_context.blendFunc(sfactor,dfactor);
};
snow_platform_web_render_opengl_GL.blendFuncSeparate = function(srcRGB,dstRGB,srcAlpha,dstAlpha) {
	snow_platform_web_render_opengl_GL.current_context.blendFuncSeparate(srcRGB,dstRGB,srcAlpha,dstAlpha);
};
snow_platform_web_render_opengl_GL.bufferData = function(target,data,usage) {
	snow_platform_web_render_opengl_GL.current_context.bufferData(target,data,usage);
};
snow_platform_web_render_opengl_GL.bufferSubData = function(target,offset,data) {
	snow_platform_web_render_opengl_GL.current_context.bufferSubData(target,offset,data);
};
snow_platform_web_render_opengl_GL.checkFramebufferStatus = function(target) {
	return snow_platform_web_render_opengl_GL.current_context.checkFramebufferStatus(target);
};
snow_platform_web_render_opengl_GL.clear = function(mask) {
	snow_platform_web_render_opengl_GL.current_context.clear(mask);
};
snow_platform_web_render_opengl_GL.clearColor = function(red,green,blue,alpha) {
	snow_platform_web_render_opengl_GL.current_context.clearColor(red,green,blue,alpha);
};
snow_platform_web_render_opengl_GL.clearDepth = function(depth) {
	snow_platform_web_render_opengl_GL.current_context.clearDepth(depth);
};
snow_platform_web_render_opengl_GL.clearStencil = function(s) {
	snow_platform_web_render_opengl_GL.current_context.clearStencil(s);
};
snow_platform_web_render_opengl_GL.colorMask = function(red,green,blue,alpha) {
	snow_platform_web_render_opengl_GL.current_context.colorMask(red,green,blue,alpha);
};
snow_platform_web_render_opengl_GL.compileShader = function(shader) {
	snow_platform_web_render_opengl_GL.current_context.compileShader(shader);
};
snow_platform_web_render_opengl_GL.compressedTexImage2D = function(target,level,internalformat,width,height,border,data) {
	snow_platform_web_render_opengl_GL.current_context.compressedTexImage2D(target,level,internalformat,width,height,border,data);
};
snow_platform_web_render_opengl_GL.compressedTexSubImage2D = function(target,level,xoffset,yoffset,width,height,format,data) {
	snow_platform_web_render_opengl_GL.current_context.compressedTexSubImage2D(target,level,xoffset,yoffset,width,height,format,data);
};
snow_platform_web_render_opengl_GL.copyTexImage2D = function(target,level,internalformat,x,y,width,height,border) {
	snow_platform_web_render_opengl_GL.current_context.copyTexImage2D(target,level,internalformat,x,y,width,height,border);
};
snow_platform_web_render_opengl_GL.copyTexSubImage2D = function(target,level,xoffset,yoffset,x,y,width,height) {
	snow_platform_web_render_opengl_GL.current_context.copyTexSubImage2D(target,level,xoffset,yoffset,x,y,width,height);
};
snow_platform_web_render_opengl_GL.createBuffer = function() {
	return snow_platform_web_render_opengl_GL.current_context.createBuffer();
};
snow_platform_web_render_opengl_GL.createFramebuffer = function() {
	return snow_platform_web_render_opengl_GL.current_context.createFramebuffer();
};
snow_platform_web_render_opengl_GL.createProgram = function() {
	return snow_platform_web_render_opengl_GL.current_context.createProgram();
};
snow_platform_web_render_opengl_GL.createRenderbuffer = function() {
	return snow_platform_web_render_opengl_GL.current_context.createRenderbuffer();
};
snow_platform_web_render_opengl_GL.createShader = function(type) {
	return snow_platform_web_render_opengl_GL.current_context.createShader(type);
};
snow_platform_web_render_opengl_GL.createTexture = function() {
	return snow_platform_web_render_opengl_GL.current_context.createTexture();
};
snow_platform_web_render_opengl_GL.cullFace = function(mode) {
	snow_platform_web_render_opengl_GL.current_context.cullFace(mode);
};
snow_platform_web_render_opengl_GL.deleteBuffer = function(buffer) {
	snow_platform_web_render_opengl_GL.current_context.deleteBuffer(buffer);
};
snow_platform_web_render_opengl_GL.deleteFramebuffer = function(framebuffer) {
	snow_platform_web_render_opengl_GL.current_context.deleteFramebuffer(framebuffer);
};
snow_platform_web_render_opengl_GL.deleteProgram = function(program) {
	snow_platform_web_render_opengl_GL.current_context.deleteProgram(program);
};
snow_platform_web_render_opengl_GL.deleteRenderbuffer = function(renderbuffer) {
	snow_platform_web_render_opengl_GL.current_context.deleteRenderbuffer(renderbuffer);
};
snow_platform_web_render_opengl_GL.deleteShader = function(shader) {
	snow_platform_web_render_opengl_GL.current_context.deleteShader(shader);
};
snow_platform_web_render_opengl_GL.deleteTexture = function(texture) {
	snow_platform_web_render_opengl_GL.current_context.deleteTexture(texture);
};
snow_platform_web_render_opengl_GL.depthFunc = function(func) {
	snow_platform_web_render_opengl_GL.current_context.depthFunc(func);
};
snow_platform_web_render_opengl_GL.depthMask = function(flag) {
	snow_platform_web_render_opengl_GL.current_context.depthMask(flag);
};
snow_platform_web_render_opengl_GL.depthRange = function(zNear,zFar) {
	snow_platform_web_render_opengl_GL.current_context.depthRange(zNear,zFar);
};
snow_platform_web_render_opengl_GL.detachShader = function(program,shader) {
	snow_platform_web_render_opengl_GL.current_context.detachShader(program,shader);
};
snow_platform_web_render_opengl_GL.disable = function(cap) {
	snow_platform_web_render_opengl_GL.current_context.disable(cap);
};
snow_platform_web_render_opengl_GL.disableVertexAttribArray = function(index) {
	snow_platform_web_render_opengl_GL.current_context.disableVertexAttribArray(index);
};
snow_platform_web_render_opengl_GL.drawArrays = function(mode,first,count) {
	snow_platform_web_render_opengl_GL.current_context.drawArrays(mode,first,count);
};
snow_platform_web_render_opengl_GL.drawElements = function(mode,count,type,offset) {
	snow_platform_web_render_opengl_GL.current_context.drawElements(mode,count,type,offset);
};
snow_platform_web_render_opengl_GL.enable = function(cap) {
	snow_platform_web_render_opengl_GL.current_context.enable(cap);
};
snow_platform_web_render_opengl_GL.enableVertexAttribArray = function(index) {
	snow_platform_web_render_opengl_GL.current_context.enableVertexAttribArray(index);
};
snow_platform_web_render_opengl_GL.finish = function() {
	snow_platform_web_render_opengl_GL.current_context.finish();
};
snow_platform_web_render_opengl_GL.flush = function() {
	snow_platform_web_render_opengl_GL.current_context.flush();
};
snow_platform_web_render_opengl_GL.framebufferRenderbuffer = function(target,attachment,renderbuffertarget,renderbuffer) {
	snow_platform_web_render_opengl_GL.current_context.framebufferRenderbuffer(target,attachment,renderbuffertarget,renderbuffer);
};
snow_platform_web_render_opengl_GL.framebufferTexture2D = function(target,attachment,textarget,texture,level) {
	snow_platform_web_render_opengl_GL.current_context.framebufferTexture2D(target,attachment,textarget,texture,level);
};
snow_platform_web_render_opengl_GL.frontFace = function(mode) {
	snow_platform_web_render_opengl_GL.current_context.frontFace(mode);
};
snow_platform_web_render_opengl_GL.generateMipmap = function(target) {
	snow_platform_web_render_opengl_GL.current_context.generateMipmap(target);
};
snow_platform_web_render_opengl_GL.getActiveAttrib = function(program,index) {
	return snow_platform_web_render_opengl_GL.current_context.getActiveAttrib(program,index);
};
snow_platform_web_render_opengl_GL.getActiveUniform = function(program,index) {
	return snow_platform_web_render_opengl_GL.current_context.getActiveUniform(program,index);
};
snow_platform_web_render_opengl_GL.getAttachedShaders = function(program) {
	return snow_platform_web_render_opengl_GL.current_context.getAttachedShaders(program);
};
snow_platform_web_render_opengl_GL.getAttribLocation = function(program,name) {
	return snow_platform_web_render_opengl_GL.current_context.getAttribLocation(program,name);
};
snow_platform_web_render_opengl_GL.getBufferParameter = function(target,pname) {
	return snow_platform_web_render_opengl_GL.current_context.getBufferParameter(target,pname);
};
snow_platform_web_render_opengl_GL.getContextAttributes = function() {
	return snow_platform_web_render_opengl_GL.current_context.getContextAttributes();
};
snow_platform_web_render_opengl_GL.getError = function() {
	return snow_platform_web_render_opengl_GL.current_context.getError();
};
snow_platform_web_render_opengl_GL.getExtension = function(name) {
	return snow_platform_web_render_opengl_GL.current_context.getExtension(name);
};
snow_platform_web_render_opengl_GL.getFramebufferAttachmentParameter = function(target,attachment,pname) {
	return snow_platform_web_render_opengl_GL.current_context.getFramebufferAttachmentParameter(target,attachment,pname);
};
snow_platform_web_render_opengl_GL.getParameter = function(pname) {
	return snow_platform_web_render_opengl_GL.current_context.getParameter(pname);
};
snow_platform_web_render_opengl_GL.getProgramInfoLog = function(program) {
	return snow_platform_web_render_opengl_GL.current_context.getProgramInfoLog(program);
};
snow_platform_web_render_opengl_GL.getProgramParameter = function(program,pname) {
	return snow_platform_web_render_opengl_GL.current_context.getProgramParameter(program,pname);
};
snow_platform_web_render_opengl_GL.getRenderbufferParameter = function(target,pname) {
	return snow_platform_web_render_opengl_GL.current_context.getRenderbufferParameter(target,pname);
};
snow_platform_web_render_opengl_GL.getShaderInfoLog = function(shader) {
	return snow_platform_web_render_opengl_GL.current_context.getShaderInfoLog(shader);
};
snow_platform_web_render_opengl_GL.getShaderParameter = function(shader,pname) {
	return snow_platform_web_render_opengl_GL.current_context.getShaderParameter(shader,pname);
};
snow_platform_web_render_opengl_GL.getShaderPrecisionFormat = function(shadertype,precisiontype) {
	return snow_platform_web_render_opengl_GL.current_context.getShaderPrecisionFormat(shadertype,precisiontype);
};
snow_platform_web_render_opengl_GL.getShaderSource = function(shader) {
	return snow_platform_web_render_opengl_GL.current_context.getShaderSource(shader);
};
snow_platform_web_render_opengl_GL.getSupportedExtensions = function() {
	return snow_platform_web_render_opengl_GL.current_context.getSupportedExtensions();
};
snow_platform_web_render_opengl_GL.getTexParameter = function(target,pname) {
	return snow_platform_web_render_opengl_GL.current_context.getTexParameter(target,pname);
};
snow_platform_web_render_opengl_GL.getUniform = function(program,location) {
	return snow_platform_web_render_opengl_GL.current_context.getUniform(program,location);
};
snow_platform_web_render_opengl_GL.getUniformLocation = function(program,name) {
	return snow_platform_web_render_opengl_GL.current_context.getUniformLocation(program,name);
};
snow_platform_web_render_opengl_GL.getVertexAttrib = function(index,pname) {
	return snow_platform_web_render_opengl_GL.current_context.getVertexAttrib(index,pname);
};
snow_platform_web_render_opengl_GL.getVertexAttribOffset = function(index,pname) {
	return snow_platform_web_render_opengl_GL.current_context.getVertexAttribOffset(index,pname);
};
snow_platform_web_render_opengl_GL.hint = function(target,mode) {
	snow_platform_web_render_opengl_GL.current_context.hint(target,mode);
};
snow_platform_web_render_opengl_GL.isBuffer = function(buffer) {
	return snow_platform_web_render_opengl_GL.current_context.isBuffer(buffer);
};
snow_platform_web_render_opengl_GL.isEnabled = function(cap) {
	return snow_platform_web_render_opengl_GL.current_context.isEnabled(cap);
};
snow_platform_web_render_opengl_GL.isFramebuffer = function(framebuffer) {
	return snow_platform_web_render_opengl_GL.current_context.isFramebuffer(framebuffer);
};
snow_platform_web_render_opengl_GL.isProgram = function(program) {
	return snow_platform_web_render_opengl_GL.current_context.isProgram(program);
};
snow_platform_web_render_opengl_GL.isRenderbuffer = function(renderbuffer) {
	return snow_platform_web_render_opengl_GL.current_context.isRenderbuffer(renderbuffer);
};
snow_platform_web_render_opengl_GL.isShader = function(shader) {
	return snow_platform_web_render_opengl_GL.current_context.isShader(shader);
};
snow_platform_web_render_opengl_GL.isTexture = function(texture) {
	return snow_platform_web_render_opengl_GL.current_context.isTexture(texture);
};
snow_platform_web_render_opengl_GL.lineWidth = function(width) {
	snow_platform_web_render_opengl_GL.current_context.lineWidth(width);
};
snow_platform_web_render_opengl_GL.linkProgram = function(program) {
	snow_platform_web_render_opengl_GL.current_context.linkProgram(program);
};
snow_platform_web_render_opengl_GL.pixelStorei = function(pname,param) {
	snow_platform_web_render_opengl_GL.current_context.pixelStorei(pname,param);
};
snow_platform_web_render_opengl_GL.polygonOffset = function(factor,units) {
	snow_platform_web_render_opengl_GL.current_context.polygonOffset(factor,units);
};
snow_platform_web_render_opengl_GL.readPixels = function(x,y,width,height,format,type,data) {
	snow_platform_web_render_opengl_GL.current_context.readPixels(x,y,width,height,format,type,data);
};
snow_platform_web_render_opengl_GL.renderbufferStorage = function(target,internalformat,width,height) {
	snow_platform_web_render_opengl_GL.current_context.renderbufferStorage(target,internalformat,width,height);
};
snow_platform_web_render_opengl_GL.sampleCoverage = function(value,invert) {
	snow_platform_web_render_opengl_GL.current_context.sampleCoverage(value,invert);
};
snow_platform_web_render_opengl_GL.scissor = function(x,y,width,height) {
	snow_platform_web_render_opengl_GL.current_context.scissor(x,y,width,height);
};
snow_platform_web_render_opengl_GL.shaderSource = function(shader,source) {
	snow_platform_web_render_opengl_GL.current_context.shaderSource(shader,source);
};
snow_platform_web_render_opengl_GL.stencilFunc = function(func,ref,mask) {
	snow_platform_web_render_opengl_GL.current_context.stencilFunc(func,ref,mask);
};
snow_platform_web_render_opengl_GL.stencilFuncSeparate = function(face,func,ref,mask) {
	snow_platform_web_render_opengl_GL.current_context.stencilFuncSeparate(face,func,ref,mask);
};
snow_platform_web_render_opengl_GL.stencilMask = function(mask) {
	snow_platform_web_render_opengl_GL.current_context.stencilMask(mask);
};
snow_platform_web_render_opengl_GL.stencilMaskSeparate = function(face,mask) {
	snow_platform_web_render_opengl_GL.current_context.stencilMaskSeparate(face,mask);
};
snow_platform_web_render_opengl_GL.stencilOp = function(fail,zfail,zpass) {
	snow_platform_web_render_opengl_GL.current_context.stencilOp(fail,zfail,zpass);
};
snow_platform_web_render_opengl_GL.stencilOpSeparate = function(face,fail,zfail,zpass) {
	snow_platform_web_render_opengl_GL.current_context.stencilOpSeparate(face,fail,zfail,zpass);
};
snow_platform_web_render_opengl_GL.texImage2D = function(target,level,internalformat,width,height,border,format,type,data) {
	snow_platform_web_render_opengl_GL.current_context.texImage2D(target,level,internalformat,width,height,border,format,type,data);
};
snow_platform_web_render_opengl_GL.texParameterf = function(target,pname,param) {
	snow_platform_web_render_opengl_GL.current_context.texParameterf(target,pname,param);
};
snow_platform_web_render_opengl_GL.texParameteri = function(target,pname,param) {
	snow_platform_web_render_opengl_GL.current_context.texParameteri(target,pname,param);
};
snow_platform_web_render_opengl_GL.texSubImage2D = function(target,level,xoffset,yoffset,width,height,format,type,data) {
	snow_platform_web_render_opengl_GL.current_context.texSubImage2D(target,level,xoffset,yoffset,width,height,format,type,data);
};
snow_platform_web_render_opengl_GL.uniform1f = function(location,x) {
	snow_platform_web_render_opengl_GL.current_context.uniform1f(location,x);
};
snow_platform_web_render_opengl_GL.uniform1fv = function(location,data) {
	snow_platform_web_render_opengl_GL.current_context.uniform1fv(location,data);
};
snow_platform_web_render_opengl_GL.uniform1i = function(location,x) {
	snow_platform_web_render_opengl_GL.current_context.uniform1i(location,x);
};
snow_platform_web_render_opengl_GL.uniform1iv = function(location,data) {
	snow_platform_web_render_opengl_GL.current_context.uniform1iv(location,data);
};
snow_platform_web_render_opengl_GL.uniform2f = function(location,x,y) {
	snow_platform_web_render_opengl_GL.current_context.uniform2f(location,x,y);
};
snow_platform_web_render_opengl_GL.uniform2fv = function(location,data) {
	snow_platform_web_render_opengl_GL.current_context.uniform2fv(location,data);
};
snow_platform_web_render_opengl_GL.uniform2i = function(location,x,y) {
	snow_platform_web_render_opengl_GL.current_context.uniform2i(location,x,y);
};
snow_platform_web_render_opengl_GL.uniform2iv = function(location,data) {
	snow_platform_web_render_opengl_GL.current_context.uniform2iv(location,data);
};
snow_platform_web_render_opengl_GL.uniform3f = function(location,x,y,z) {
	snow_platform_web_render_opengl_GL.current_context.uniform3f(location,x,y,z);
};
snow_platform_web_render_opengl_GL.uniform3fv = function(location,data) {
	snow_platform_web_render_opengl_GL.current_context.uniform3fv(location,data);
};
snow_platform_web_render_opengl_GL.uniform3i = function(location,x,y,z) {
	snow_platform_web_render_opengl_GL.current_context.uniform3i(location,x,y,z);
};
snow_platform_web_render_opengl_GL.uniform3iv = function(location,data) {
	snow_platform_web_render_opengl_GL.current_context.uniform3iv(location,data);
};
snow_platform_web_render_opengl_GL.uniform4f = function(location,x,y,z,w) {
	snow_platform_web_render_opengl_GL.current_context.uniform4f(location,x,y,z,w);
};
snow_platform_web_render_opengl_GL.uniform4fv = function(location,data) {
	snow_platform_web_render_opengl_GL.current_context.uniform4fv(location,data);
};
snow_platform_web_render_opengl_GL.uniform4i = function(location,x,y,z,w) {
	snow_platform_web_render_opengl_GL.current_context.uniform4i(location,x,y,z,w);
};
snow_platform_web_render_opengl_GL.uniform4iv = function(location,data) {
	snow_platform_web_render_opengl_GL.current_context.uniform4iv(location,data);
};
snow_platform_web_render_opengl_GL.uniformMatrix2fv = function(location,transpose,data) {
	snow_platform_web_render_opengl_GL.current_context.uniformMatrix2fv(location,transpose,data);
};
snow_platform_web_render_opengl_GL.uniformMatrix3fv = function(location,transpose,data) {
	snow_platform_web_render_opengl_GL.current_context.uniformMatrix3fv(location,transpose,data);
};
snow_platform_web_render_opengl_GL.uniformMatrix4fv = function(location,transpose,data) {
	snow_platform_web_render_opengl_GL.current_context.uniformMatrix4fv(location,transpose,data);
};
snow_platform_web_render_opengl_GL.useProgram = function(program) {
	snow_platform_web_render_opengl_GL.current_context.useProgram(program);
};
snow_platform_web_render_opengl_GL.validateProgram = function(program) {
	snow_platform_web_render_opengl_GL.current_context.validateProgram(program);
};
snow_platform_web_render_opengl_GL.vertexAttrib1f = function(indx,x) {
	snow_platform_web_render_opengl_GL.current_context.vertexAttrib1f(indx,x);
};
snow_platform_web_render_opengl_GL.vertexAttrib1fv = function(indx,data) {
	snow_platform_web_render_opengl_GL.current_context.vertexAttrib1fv(indx,data);
};
snow_platform_web_render_opengl_GL.vertexAttrib2f = function(indx,x,y) {
	snow_platform_web_render_opengl_GL.current_context.vertexAttrib2f(indx,x,y);
};
snow_platform_web_render_opengl_GL.vertexAttrib2fv = function(indx,data) {
	snow_platform_web_render_opengl_GL.current_context.vertexAttrib2fv(indx,data);
};
snow_platform_web_render_opengl_GL.vertexAttrib3f = function(indx,x,y,z) {
	snow_platform_web_render_opengl_GL.current_context.vertexAttrib3f(indx,x,y,z);
};
snow_platform_web_render_opengl_GL.vertexAttrib3fv = function(indx,data) {
	snow_platform_web_render_opengl_GL.current_context.vertexAttrib3fv(indx,data);
};
snow_platform_web_render_opengl_GL.vertexAttrib4f = function(indx,x,y,z,w) {
	snow_platform_web_render_opengl_GL.current_context.vertexAttrib4f(indx,x,y,z,w);
};
snow_platform_web_render_opengl_GL.vertexAttrib4fv = function(indx,data) {
	snow_platform_web_render_opengl_GL.current_context.vertexAttrib4fv(indx,data);
};
snow_platform_web_render_opengl_GL.vertexAttribPointer = function(indx,size,type,normalized,stride,offset) {
	snow_platform_web_render_opengl_GL.current_context.vertexAttribPointer(indx,size,type,normalized,stride,offset);
};
snow_platform_web_render_opengl_GL.viewport = function(x,y,width,height) {
	snow_platform_web_render_opengl_GL.current_context.viewport(x,y,width,height);
};
snow_platform_web_render_opengl_GL.get_version = function() {
	return 7938;
};
var snow_window_WindowSystemBinding = function() { };
snow_window_WindowSystemBinding.__name__ = true;
snow_window_WindowSystemBinding.__interfaces__ = [snow_utils_AbstractClass];
snow_window_WindowSystemBinding.prototype = {
	init: function() {
		throw new js__$Boot_HaxeError("abstract method, must override");
	}
	,process: function() {
		throw new js__$Boot_HaxeError("abstract method, must override");
	}
	,destroy: function() {
		throw new js__$Boot_HaxeError("abstract method, must override");
	}
	,listen: function(window) {
		throw new js__$Boot_HaxeError("abstract method, must override");
	}
	,unlisten: function(window) {
		throw new js__$Boot_HaxeError("abstract method, must override");
	}
	,create: function(render_config,config,on_created) {
		throw new js__$Boot_HaxeError("abstract method, must override");
	}
	,close: function(window) {
		throw new js__$Boot_HaxeError("abstract method, must override");
	}
	,show: function(window) {
		throw new js__$Boot_HaxeError("abstract method, must override");
	}
	,destroy_window: function(window) {
		throw new js__$Boot_HaxeError("abstract method, must override");
	}
	,update: function(window) {
		throw new js__$Boot_HaxeError("abstract method, must override");
	}
	,render: function(window) {
		throw new js__$Boot_HaxeError("abstract method, must override");
	}
	,swap: function(window) {
		throw new js__$Boot_HaxeError("abstract method, must override");
	}
	,simple_message: function(window,message,title) {
		if(title == null) title = "";
		throw new js__$Boot_HaxeError("abstract method, must override");
	}
	,set_size: function(window,w,h) {
		throw new js__$Boot_HaxeError("abstract method, must override");
	}
	,set_position: function(window,x,y) {
		throw new js__$Boot_HaxeError("abstract method, must override");
	}
	,set_title: function(window,title) {
		throw new js__$Boot_HaxeError("abstract method, must override");
	}
	,set_max_size: function(window,w,h) {
		throw new js__$Boot_HaxeError("abstract method, must override");
	}
	,set_min_size: function(window,w,h) {
		throw new js__$Boot_HaxeError("abstract method, must override");
	}
	,fullscreen: function(window,fullscreen) {
		throw new js__$Boot_HaxeError("abstract method, must override");
	}
	,bordered: function(window,bordered) {
		throw new js__$Boot_HaxeError("abstract method, must override");
	}
	,grab: function(window,grabbed) {
		throw new js__$Boot_HaxeError("abstract method, must override");
	}
	,set_cursor_position: function(window,x,y) {
		throw new js__$Boot_HaxeError("abstract method, must override");
	}
	,system_enable_cursor: function(enable) {
		throw new js__$Boot_HaxeError("abstract method, must override");
	}
	,system_lock_cursor: function(enable) {
		throw new js__$Boot_HaxeError("abstract method, must override");
	}
	,system_enable_vsync: function(enable) {
		throw new js__$Boot_HaxeError("abstract method, must override");
	}
	,display_count: function() {
		throw new js__$Boot_HaxeError("abstract method, must override");
	}
	,display_mode_count: function(display) {
		throw new js__$Boot_HaxeError("abstract method, must override");
	}
	,display_native_mode: function(display) {
		throw new js__$Boot_HaxeError("abstract method, must override");
	}
	,display_current_mode: function(display) {
		throw new js__$Boot_HaxeError("abstract method, must override");
	}
	,display_mode: function(display,mode_index) {
		throw new js__$Boot_HaxeError("abstract method, must override");
	}
	,display_bounds: function(display) {
		throw new js__$Boot_HaxeError("abstract method, must override");
	}
	,display_name: function(display) {
		throw new js__$Boot_HaxeError("abstract method, must override");
	}
	,__class__: snow_window_WindowSystemBinding
};
var snow_platform_web_window_WindowSystem = function(_manager,_lib) {
	this._hidden_event_name = "";
	this._hidden_name = "";
	this._cursor_visible = true;
	this._pre_fs_body_margin = "0";
	this._pre_fs_body_overflow = "0";
	this._pre_fs_height = 0;
	this._pre_fs_width = 0;
	this._pre_fs_s_height = "";
	this._pre_fs_s_width = "";
	this._pre_fs_margin = "0";
	this._pre_fs_padding = "0";
	this.seq_window = 1;
	this.manager = _manager;
	this.lib = _lib;
	this.fs_windows = [];
	this.gl_contexts = new haxe_ds_IntMap();
};
snow_platform_web_window_WindowSystem.__name__ = true;
snow_platform_web_window_WindowSystem.__super__ = snow_window_WindowSystemBinding;
snow_platform_web_window_WindowSystem.prototype = $extend(snow_window_WindowSystemBinding.prototype,{
	init: function() {
		this.listen_for_visibility();
		this.listen_for_resize();
	}
	,process: function() {
	}
	,destroy: function() {
	}
	,_copy_config: function(_config) {
		return { borderless : _config.borderless, fullscreen : _config.fullscreen, fullscreen_desktop : _config.fullscreen_desktop, height : _config.height, no_input : _config.no_input, resizable : _config.resizable, title : _config.title, width : _config.width, x : _config.x, y : _config.y};
	}
	,create: function(render_config,_config,on_created) {
		var _window_id = this.seq_window;
		var _handle;
		var _this = window.document;
		_handle = _this.createElement("canvas");
		var config = this._copy_config(_config);
		_handle.width = config.width;
		_handle.height = config.height;
		if(config.fullscreen) {
			this.internal_fullscreen(_handle,config.fullscreen);
			config.width = _handle.width;
			config.height = _handle.height;
		}
		_handle.style.display = "block";
		_handle.style.position = "relative";
		_handle.style.background = "#000";
		window.document.body.appendChild(_handle);
		var _gl_context = js_html__$CanvasElement_CanvasUtil.getContextWebGL(_handle,{ alpha : false, premultipliedAlpha : false, antialias : render_config.antialiasing > 0});
		if(_gl_context == null) {
			var msg = "WebGL is required to run this!<br/><br/>";
			msg += "visit http://get.webgl.org/ for help <br/>";
			msg += "and contact the developer of the application";
			this.internal_fallback(msg);
			throw new js__$Boot_HaxeError(msg);
		}
		if(snow_platform_web_render_opengl_GL.current_context == null) snow_platform_web_render_opengl_GL.current_context = _gl_context;
		this.gl_contexts.h[_window_id] = _gl_context;
		var _window_pos = this.get_real_window_position(_handle);
		config.x = _window_pos.x;
		config.y = _window_pos.y;
		if(config.title != null && config.title != "") window.document.title = config.title;
		on_created(_handle,_window_id,{ config : config, render_config : render_config});
		_handle.setAttribute("id","window" + _window_id);
		this.seq_window++;
	}
	,destroy_window: function(_window) {
		window.document.body.removeChild(_window.handle);
	}
	,close: function(_window) {
		_window.handle.style.display = "none";
	}
	,show: function(_window) {
		_window.handle.style.display = null;
	}
	,internal_resize: function(_window,_w,_h) {
		this.lib.dispatch_system_event({ type : 5, window : { type : 7, timestamp : snow_Snow.core.timestamp(), window_id : _window.id, event : { x : _w, y : _h}}});
		this.lib.dispatch_system_event({ type : 5, window : { type : 6, timestamp : snow_Snow.core.timestamp(), window_id : _window.id, event : { x : _w, y : _h}}});
	}
	,update: function(_window) {
		var _rect = _window.handle.getBoundingClientRect();
		if(_rect.left != _window.x || _rect.top != _window.y) this.lib.dispatch_system_event({ type : 5, window : { type : 5, timestamp : snow_Snow.core.timestamp(), window_id : _window.id, event : { x : _rect.left, y : _rect.top}}});
		if(_rect.width != _window.width || _rect.height != _window.height) this.internal_resize(_window,_rect.width,_rect.height);
		_rect = null;
	}
	,render: function(_window) {
		var _window_gl_context = this.gl_contexts.h[_window.id];
		if(snow_platform_web_render_opengl_GL.current_context != _window_gl_context) snow_platform_web_render_opengl_GL.current_context = _window_gl_context;
	}
	,swap: function(_window) {
	}
	,simple_message: function(_window,message,title) {
		if(title == null) title = "";
		window.alert(message);
	}
	,set_size: function(_window,w,h) {
		_window.handle.width = w;
		_window.handle.height = h;
		_window.handle.style.width = "" + w + "px";
		_window.handle.style.height = "" + h + "px";
		this.internal_resize(_window,w,h);
	}
	,set_position: function(_window,x,y) {
		_window.handle.style.left = "" + x + "px";
		_window.handle.style.top = "" + y + "px";
	}
	,get_real_window_position: function(handle) {
		var curleft = 0;
		var curtop = 0;
		var _obj = handle;
		var _has_parent = true;
		var _max_count = 0;
		while(_has_parent == true) {
			_max_count++;
			if(_max_count > 100) {
				_has_parent = false;
				break;
			}
			if(_obj.offsetParent != null) {
				curleft += _obj.offsetLeft;
				curtop += _obj.offsetTop;
				_obj = _obj.offsetParent;
			} else _has_parent = false;
		}
		return { x : curleft, y : curtop};
	}
	,set_title: function(_window,title) {
		window.document.title = title;
	}
	,set_max_size: function(_window,w,h) {
		_window.handle.style.maxWidth = "" + w + "px";
		_window.handle.style.maxHeight = "" + h + "px";
	}
	,set_min_size: function(_window,w,h) {
		_window.handle.style.minWidth = "" + w + "px";
		_window.handle.style.minHeight = "" + h + "px";
	}
	,internal_fullscreen: function(_handle,fullscreen) {
		var true_fullscreen = this.lib.config.web.true_fullscreen;
		if(fullscreen) {
			if(true_fullscreen) {
				if($bind(_handle,_handle.requestFullscreen) == null) {
					if(_handle.requestFullScreen == null) {
						if(_handle.webkitRequestFullscreen == null) {
							if(_handle.mozRequestFullScreen == null) {
							} else _handle.mozRequestFullScreen();
						} else _handle.webkitRequestFullscreen();
					} else _handle.requestFullScreen(null);
				} else _handle.requestFullscreen();
			} else {
				this._pre_fs_padding = _handle.style.padding;
				this._pre_fs_margin = _handle.style.margin;
				this._pre_fs_s_width = _handle.style.width;
				this._pre_fs_s_height = _handle.style.height;
				this._pre_fs_width = _handle.width;
				this._pre_fs_height = _handle.height;
				this._pre_fs_body_margin = window.document.body.style.margin;
				this._pre_fs_body_overflow = window.document.body.style.overflow;
				_handle.style.margin = "0";
				_handle.style.padding = "0";
				_handle.style.width = window.innerWidth + "px";
				_handle.style.height = window.innerHeight + "px";
				_handle.width = window.innerWidth;
				_handle.height = window.innerHeight;
				window.document.body.style.margin = "0";
				window.document.body.style.overflow = "hidden";
			}
		} else if(true_fullscreen) {
		} else {
			_handle.style.padding = this._pre_fs_padding;
			_handle.style.margin = this._pre_fs_margin;
			_handle.style.width = this._pre_fs_s_width;
			_handle.style.height = this._pre_fs_s_height;
			_handle.width = this._pre_fs_width;
			_handle.height = this._pre_fs_height;
			window.document.body.style.margin = this._pre_fs_body_margin;
			window.document.body.style.overflow = this._pre_fs_body_overflow;
		}
	}
	,fullscreen: function(_window,fullscreen) {
		if(fullscreen) {
			if(HxOverrides.indexOf(this.fs_windows,_window,0) == -1) this.fs_windows.push(_window);
		} else HxOverrides.remove(this.fs_windows,_window);
		this.internal_fullscreen(_window.handle,fullscreen);
	}
	,bordered: function(_window,bordered) {
	}
	,grab: function(_window,grabbed) {
		if(grabbed) {
			if(($_=_window.handle,$bind($_,$_.requestPointerLock)) == null) {
				if(_window.handle.webkitRequestPointerLock == null) {
					if(_window.handle.mozRequestPointerLock == null) {
					} else _window.handle.mozRequestPointerLock();
				} else _window.handle.webkitRequestPointerLock();
			} else _window.handle.requestPointerLock();
		} else {
		}
	}
	,set_cursor_position: function(_window,x,y) {
	}
	,system_enable_cursor: function(enable) {
		if(this.cursor_style == null) {
			var _this = window.document;
			this.cursor_style = _this.createElement("style");
			this.cursor_style.innerHTML = "* { cursor:none; }";
		}
		if(enable && !this._cursor_visible) {
			this._cursor_visible = true;
			window.document.body.removeChild(this.cursor_style);
		} else if(!enable && this._cursor_visible) {
			this._cursor_visible = false;
			window.document.body.appendChild(this.cursor_style);
		}
	}
	,system_lock_cursor: function(enable) {
		if(this.lib.window != null) this.grab(this.lib.window,enable);
	}
	,system_enable_vsync: function(enable) {
		return -1;
	}
	,display_count: function() {
		return 1;
	}
	,display_mode_count: function(display) {
		return 1;
	}
	,display_native_mode: function(display) {
		return { format : 0, refresh_rate : 0, width : window.screen.width, height : window.screen.height};
	}
	,display_current_mode: function(display) {
		return this.display_native_mode(display);
	}
	,display_mode: function(display,mode_index) {
		return this.display_native_mode(display);
	}
	,display_bounds: function(display) {
		return { x : 0, y : 0, width : window.innerWidth, height : window.innerHeight};
	}
	,display_name: function(display) {
		return window.navigator.vendor;
	}
	,listen: function(_window) {
		_window.handle.addEventListener("mouseleave",$bind(this,this.on_internal_leave));
		_window.handle.addEventListener("mouseenter",$bind(this,this.on_internal_enter));
	}
	,unlisten: function(_window) {
		_window.handle.removeEventListener("mouseleave",$bind(this,this.on_internal_leave));
		_window.handle.removeEventListener("mouseenter",$bind(this,this.on_internal_enter));
	}
	,on_internal_leave: function(_mouse_event) {
		var _window = this.lib.windowing.window_from_handle(_mouse_event.target);
		this.lib.dispatch_system_event({ type : 5, window : { type : 12, timestamp : _mouse_event.timeStamp, window_id : _window.id, event : _mouse_event}});
	}
	,on_internal_enter: function(_mouse_event) {
		var _window = this.lib.windowing.window_from_handle(_mouse_event.target);
		this.lib.dispatch_system_event({ type : 5, window : { type : 11, timestamp : _mouse_event.timeStamp, window_id : _window.id, event : _mouse_event}});
	}
	,listen_for_resize: function() {
		var _g = this;
		window.onresize = function(e) {
			if(!_g.lib.config.web.true_fullscreen) {
				var _g1 = 0;
				var _g2 = _g.fs_windows;
				while(_g1 < _g2.length) {
					var $window = _g2[_g1];
					++_g1;
					$window.set_size(window.innerWidth,window.innerHeight);
					_g.internal_resize($window,$window.width,$window.height);
				}
			}
		};
	}
	,listen_for_visibility: function() {
		if(typeof document.hidden !== undefined) {
			this._hidden_name = "hidden";
			this._hidden_event_name = "visibilitychange";
		} else if(typeof document.mozHidden !== undefined ) {
			this._hidden_name = "mozHidden";
			this._hidden_name = "mozvisibilitychange";
		} else if(typeof document.msHidden !== "undefined") {
			this._hidden_name = "msHidden";
			this._hidden_event_name = "msvisibilitychange";
		} else if(typeof document.webkitHidden !== "undefined") {
			this._hidden_name = "webkitHidden";
			this._hidden_event_name = "webkitvisibilitychange";
		}
		if(this._hidden_name != "" && this._hidden_event_name != "") window.document.addEventListener(this._hidden_event_name,$bind(this,this.on_visibility_change));
	}
	,on_visibility_change: function(jsevent) {
		var _event = { type : 5, window : { type : 2, timestamp : snow_Snow.core.timestamp(), window_id : 1, event : jsevent}};
		if(document[this._hidden_name]) {
			_event.window.type = 3;
			this.lib.dispatch_system_event(_event);
			_event.window.type = 8;
			this.lib.dispatch_system_event(_event);
			_event.window.type = 14;
			this.lib.dispatch_system_event(_event);
		} else {
			_event.window.type = 2;
			this.lib.dispatch_system_event(_event);
			_event.window.type = 10;
			this.lib.dispatch_system_event(_event);
			_event.window.type = 13;
			this.lib.dispatch_system_event(_event);
		}
	}
	,internal_fallback: function(message) {
		var text_el;
		var overlay_el;
		var _this = window.document;
		text_el = _this.createElement("div");
		var _this1 = window.document;
		overlay_el = _this1.createElement("div");
		text_el.style.marginLeft = "auto";
		text_el.style.marginRight = "auto";
		text_el.style.color = "#d3d3d3";
		text_el.style.marginTop = "5em";
		text_el.style.fontSize = "1.4em";
		text_el.style.fontFamily = "helvetica,sans-serif";
		text_el.innerHTML = message;
		overlay_el.style.top = "0";
		overlay_el.style.left = "0";
		overlay_el.style.width = "100%";
		overlay_el.style.height = "100%";
		overlay_el.style.display = "block";
		overlay_el.style.minWidth = "100%";
		overlay_el.style.minHeight = "100%";
		overlay_el.style.textAlign = "center";
		overlay_el.style.position = "absolute";
		overlay_el.style.background = "rgba(1,1,1,0.90)";
		overlay_el.appendChild(text_el);
		window.document.body.appendChild(overlay_el);
	}
	,__class__: snow_platform_web_window_WindowSystem
});
var snow_types_Error = { __ename__ : true, __constructs__ : ["error","init","windowing"] };
snow_types_Error.error = function(value) { var $x = ["error",0,value]; $x.__enum__ = snow_types_Error; $x.toString = $estr; return $x; };
snow_types_Error.init = function(value) { var $x = ["init",1,value]; $x.__enum__ = snow_types_Error; $x.toString = $estr; return $x; };
snow_types_Error.windowing = function(value) { var $x = ["windowing",2,value]; $x.__enum__ = snow_types_Error; $x.toString = $estr; return $x; };
var snow_utils_AbstractClassBuilder = function() { };
snow_utils_AbstractClassBuilder.__name__ = true;
var snow_utils_Libs = function() { };
snow_utils_Libs.__name__ = true;
snow_utils_Libs.tryLoad = function(name,library,func,args) {
	return null;
};
snow_utils_Libs.findHaxeLib = function(library) {
	try {
	} catch( e ) {
		if (e instanceof js__$Boot_HaxeError) e = e.val;
	}
	return "";
};
snow_utils_Libs.get_system_name = function() {
	return window.navigator.userAgent;
	return "unknown";
};
snow_utils_Libs.web_add_lib = function(library,root) {
	if(snow_utils_Libs._web_libs == null) snow_utils_Libs._web_libs = new haxe_ds_StringMap();
	var value = root;
	snow_utils_Libs._web_libs.set(library,value);
	return true;
};
snow_utils_Libs.web_lib_load = function(library,method) {
	if(snow_utils_Libs._web_libs == null) snow_utils_Libs._web_libs = new haxe_ds_StringMap();
	var _root = snow_utils_Libs._web_libs.get(library);
	if(_root != null) return Reflect.field(_root,method);
	return null;
};
snow_utils_Libs.load = function(library,method,args) {
	if(args == null) args = 0;
	var found_in_web_libs = snow_utils_Libs.web_lib_load(library,method);
	if(found_in_web_libs) return found_in_web_libs;
	if(snow_utils_Libs.__moduleNames == null) snow_utils_Libs.__moduleNames = new haxe_ds_StringMap();
	if(snow_utils_Libs.__moduleNames.exists(library)) {
	}
	snow_utils_Libs.__moduleNames.set(library,library);
	var result = snow_utils_Libs.tryLoad("./" + library,library,method,args);
	if(result == null) result = snow_utils_Libs.tryLoad(".\\" + library,library,method,args);
	if(result == null) result = snow_utils_Libs.tryLoad(library,library,method,args);
	if(result == null) {
		var slash;
		if(((function($this) {
			var $r;
			var _this = snow_utils_Libs.get_system_name();
			$r = HxOverrides.substr(_this,7,null);
			return $r;
		}(this))).toLowerCase() == "windows") slash = "\\"; else slash = "/";
		var haxelib = snow_utils_Libs.findHaxeLib("snow");
		if(haxelib != "") {
			result = snow_utils_Libs.tryLoad(haxelib + slash + "ndll" + slash + snow_utils_Libs.get_system_name() + slash + library,library,method,args);
			if(result == null) result = snow_utils_Libs.tryLoad(haxelib + slash + "ndll" + slash + snow_utils_Libs.get_system_name() + "64" + slash + library,library,method,args);
		}
	}
	snow_utils_Libs.loaderTrace("Result : " + Std.string(result));
	return result;
};
snow_utils_Libs.loaderTrace = function(message) {
};
var snow_utils_Promise = function(func) {
	this.was_caught = false;
	var _g = this;
	this.state = 0;
	this.reject_reactions = [];
	this.fulfill_reactions = [];
	this.settle_reactions = [];
	snow_utils_Promises.queue(function() {
		func($bind(_g,_g.onfulfill),$bind(_g,_g.onreject));
		snow_utils_Promises.defer(snow_utils_Promises.next);
	});
};
snow_utils_Promise.__name__ = true;
snow_utils_Promise.all = function(_tag,list) {
	if(_tag == null) _tag = "all";
	return new snow_utils_Promise(function(ok,no) {
		var current = 0;
		var total = list.length;
		var fulfill_result = [];
		var reject_result = null;
		var all_state = 0;
		var single_ok = function(val) {
			if(all_state != 0) return;
			current++;
			fulfill_result.push(val);
			if(total == current) {
				all_state = 1;
				ok(fulfill_result);
			}
		};
		var single_err = function(val1) {
			if(all_state != 0) return;
			all_state = 2;
			reject_result = val1;
			no(reject_result);
		};
		var _g = 0;
		while(_g < list.length) {
			var promise = list[_g];
			++_g;
			promise.then(single_ok).error(single_err);
		}
	});
};
snow_utils_Promise.race = function(list) {
	return new snow_utils_Promise(function(ok,no) {
		var settled = false;
		var single_ok = function(val) {
			if(settled) return;
			settled = true;
			ok(val);
		};
		var single_err = function(val1) {
			if(settled) return;
			settled = true;
			no(val1);
		};
		var _g = 0;
		while(_g < list.length) {
			var promise = list[_g];
			++_g;
			promise.then(single_ok).error(single_err);
		}
	});
};
snow_utils_Promise.reject = function(reason) {
	return new snow_utils_Promise(function(ok,no) {
		no(reason);
	});
};
snow_utils_Promise.resolve = function(val) {
	return new snow_utils_Promise(function(ok,no) {
		ok(val);
	});
};
snow_utils_Promise.prototype = {
	then: function(on_fulfilled,on_rejected) {
		var _g = this.state;
		switch(_g) {
		case 0:
			this.add_fulfill(on_fulfilled);
			this.add_reject(on_rejected);
			return this.new_linked_promise();
		case 1:
			snow_utils_Promises.defer(on_fulfilled,this.result);
			return snow_utils_Promise.resolve(this.result);
		case 2:
			snow_utils_Promises.defer(on_rejected,this.result);
			return snow_utils_Promise.reject(this.result);
		}
	}
	,error: function(on_rejected) {
		var _g = this.state;
		switch(_g) {
		case 0:
			this.add_reject(on_rejected);
			return this.new_linked_resolve_empty();
		case 1:
			return snow_utils_Promise.resolve(this.result);
		case 2:
			snow_utils_Promises.defer(on_rejected,this.result);
			return snow_utils_Promise.reject(this.result);
		}
	}
	,toString: function() {
		return "Promise { state:" + this.state_string() + ", result:" + Std.string(this.result) + " }";
	}
	,add_settle: function(f) {
		if(this.state == 0) this.settle_reactions.push(f); else snow_utils_Promises.defer(f,this.result);
	}
	,new_linked_promise: function() {
		var _g = this;
		return new snow_utils_Promise(function(f,r) {
			_g.add_settle(function(_) {
				if(_g.state == 1) f(_g.result); else r(_g.result);
			});
		});
	}
	,new_linked_resolve: function() {
		var _g = this;
		return new snow_utils_Promise(function(f,r) {
			_g.add_settle(function(val) {
				f(val);
			});
		});
	}
	,new_linked_reject: function() {
		var _g = this;
		return new snow_utils_Promise(function(f,r) {
			_g.add_settle(function(val) {
				r(val);
			});
		});
	}
	,new_linked_resolve_empty: function() {
		var _g = this;
		return new snow_utils_Promise(function(f,r) {
			_g.add_settle(function(_) {
				f();
			});
		});
	}
	,new_linked_reject_empty: function() {
		var _g = this;
		return new snow_utils_Promise(function(f,r) {
			_g.add_settle(function(_) {
				r();
			});
		});
	}
	,add_fulfill: function(f) {
		if(f != null) this.fulfill_reactions.push(f);
	}
	,add_reject: function(f) {
		if(f != null) {
			this.was_caught = true;
			this.reject_reactions.push(f);
		}
	}
	,onfulfill: function(val) {
		this.state = 1;
		this.result = val;
		while(this.fulfill_reactions.length > 0) {
			var fn = this.fulfill_reactions.shift();
			fn(this.result);
		}
		this.onsettle();
	}
	,onreject: function(reason) {
		this.state = 2;
		this.result = reason;
		while(this.reject_reactions.length > 0) {
			var fn = this.reject_reactions.shift();
			fn(this.result);
		}
		this.onsettle();
	}
	,onsettle: function() {
		while(this.settle_reactions.length > 0) {
			var fn = this.settle_reactions.shift();
			fn(this.result);
		}
	}
	,onexception: function(err) {
		var _g = this;
		this.add_settle(function(_) {
			if(!_g.was_caught) {
				if(_g.state == 2) {
					throw new js__$Boot_HaxeError(snow_utils_PromiseError.UnhandledPromiseRejection(_g.toString()));
					return;
				}
			}
		});
		if(this.state == 0) this.onreject(err);
	}
	,state_string: function() {
		var _g = this.state;
		switch(_g) {
		case 0:
			return "pending";
		case 1:
			return "fulfilled";
		case 2:
			return "rejected";
		}
	}
	,__class__: snow_utils_Promise
};
var snow_utils_Promises = function() { };
snow_utils_Promises.__name__ = true;
snow_utils_Promises.step = function() {
	snow_utils_Promises.next();
	while(snow_utils_Promises.defers.length > 0) {
		var defer = snow_utils_Promises.defers.shift();
		defer.f(defer.a);
	}
};
snow_utils_Promises.next = function() {
	if(snow_utils_Promises.calls.length > 0) (snow_utils_Promises.calls.shift())();
};
snow_utils_Promises.defer = function(f,a) {
	if(f == null) return;
	snow_utils_Promises.defers.push({ f : f, a : a});
};
snow_utils_Promises.queue = function(f) {
	if(f == null) return;
	snow_utils_Promises.calls.push(f);
};
var snow_utils_PromiseError = { __ename__ : true, __constructs__ : ["UnhandledPromiseRejection"] };
snow_utils_PromiseError.UnhandledPromiseRejection = function(err) { var $x = ["UnhandledPromiseRejection",0,err]; $x.__enum__ = snow_utils_PromiseError; $x.toString = $estr; return $x; };
var snow_utils_Timer = function(_time) {
	this.time = _time;
	snow_utils_Timer.running_timers.push(this);
	this.fire_at = snow_utils_Timer.stamp() + this.time;
	this.running = true;
};
snow_utils_Timer.__name__ = true;
snow_utils_Timer.measure = function(f,pos) {
	var t0 = snow_utils_Timer.stamp();
	var r = f();
	haxe_Log.trace(snow_utils_Timer.stamp() - t0 + "s",pos);
	return r;
};
snow_utils_Timer.update = function() {
	var now = snow_utils_Timer.stamp();
	var _g = 0;
	var _g1 = snow_utils_Timer.running_timers;
	while(_g < _g1.length) {
		var timer = _g1[_g];
		++_g;
		if(timer.running) {
			if(timer.fire_at < now) {
				timer.fire_at += timer.time;
				timer.run();
			}
		}
	}
};
snow_utils_Timer.delay = function(_time,_f) {
	var t = new snow_utils_Timer(_time);
	t.run = function() {
		t.stop();
		_f();
	};
	return t;
};
snow_utils_Timer.stamp = function() {
	return snow_Snow.core.timestamp();
};
snow_utils_Timer.prototype = {
	run: function() {
	}
	,stop: function() {
		if(this.running) {
			this.running = false;
			HxOverrides.remove(snow_utils_Timer.running_timers,this);
		}
	}
	,__class__: snow_utils_Timer
};
var snow_utils_format_png_Color = { __ename__ : true, __constructs__ : ["ColGrey","ColTrue","ColIndexed"] };
snow_utils_format_png_Color.ColGrey = function(alpha) { var $x = ["ColGrey",0,alpha]; $x.__enum__ = snow_utils_format_png_Color; $x.toString = $estr; return $x; };
snow_utils_format_png_Color.ColTrue = function(alpha) { var $x = ["ColTrue",1,alpha]; $x.__enum__ = snow_utils_format_png_Color; $x.toString = $estr; return $x; };
snow_utils_format_png_Color.ColIndexed = ["ColIndexed",2];
snow_utils_format_png_Color.ColIndexed.toString = $estr;
snow_utils_format_png_Color.ColIndexed.__enum__ = snow_utils_format_png_Color;
var snow_utils_format_png_Chunk = { __ename__ : true, __constructs__ : ["CEnd","CHeader","CData","CPalette","CUnknown"] };
snow_utils_format_png_Chunk.CEnd = ["CEnd",0];
snow_utils_format_png_Chunk.CEnd.toString = $estr;
snow_utils_format_png_Chunk.CEnd.__enum__ = snow_utils_format_png_Chunk;
snow_utils_format_png_Chunk.CHeader = function(h) { var $x = ["CHeader",1,h]; $x.__enum__ = snow_utils_format_png_Chunk; $x.toString = $estr; return $x; };
snow_utils_format_png_Chunk.CData = function(b) { var $x = ["CData",2,b]; $x.__enum__ = snow_utils_format_png_Chunk; $x.toString = $estr; return $x; };
snow_utils_format_png_Chunk.CPalette = function(b) { var $x = ["CPalette",3,b]; $x.__enum__ = snow_utils_format_png_Chunk; $x.toString = $estr; return $x; };
snow_utils_format_png_Chunk.CUnknown = function(id,data) { var $x = ["CUnknown",4,id,data]; $x.__enum__ = snow_utils_format_png_Chunk; $x.toString = $estr; return $x; };
var snow_utils_format_png_Reader = function(i) {
	this.i = i;
	i.set_bigEndian(true);
	this.checkCRC = true;
};
snow_utils_format_png_Reader.__name__ = true;
snow_utils_format_png_Reader.prototype = {
	read: function() {
		var _g = 0;
		var _g1 = [137,80,78,71,13,10,26,10];
		while(_g < _g1.length) {
			var b = _g1[_g];
			++_g;
			if(this.i.readByte() != b) throw new js__$Boot_HaxeError("Invalid header");
		}
		var l = new List();
		while(true) {
			var c = this.readChunk();
			l.add(c);
			if(c == snow_utils_format_png_Chunk.CEnd) break;
		}
		return l;
	}
	,readHeader: function(i) {
		i.set_bigEndian(true);
		var width = i.readInt32();
		var height = i.readInt32();
		var colbits = i.readByte();
		var color = i.readByte();
		var color1;
		switch(color) {
		case 0:
			color1 = snow_utils_format_png_Color.ColGrey(false);
			break;
		case 2:
			color1 = snow_utils_format_png_Color.ColTrue(false);
			break;
		case 3:
			color1 = snow_utils_format_png_Color.ColIndexed;
			break;
		case 4:
			color1 = snow_utils_format_png_Color.ColGrey(true);
			break;
		case 6:
			color1 = snow_utils_format_png_Color.ColTrue(true);
			break;
		default:
			throw new js__$Boot_HaxeError("Unknown color model " + color + ":" + colbits);
		}
		var compress = i.readByte();
		var filter = i.readByte();
		if(compress != 0 || filter != 0) throw new js__$Boot_HaxeError("Invalid header");
		var interlace = i.readByte();
		if(interlace != 0 && interlace != 1) throw new js__$Boot_HaxeError("Invalid header");
		return { width : width, height : height, colbits : colbits, color : color1, interlaced : interlace == 1};
	}
	,readChunk: function() {
		var dataLen = this.i.readInt32();
		var id = this.i.readString(4);
		var data = this.i.read(dataLen);
		var crc = this.i.readInt32();
		if(this.checkCRC) {
			var c = new haxe_crypto_Crc32();
			var _g = 0;
			while(_g < 4) {
				var i = _g++;
				c["byte"](HxOverrides.cca(id,i));
			}
			c.update(data,0,data.length);
			if(c.get() != crc) throw new js__$Boot_HaxeError("CRC check failure");
		}
		switch(id) {
		case "IEND":
			return snow_utils_format_png_Chunk.CEnd;
		case "IHDR":
			return snow_utils_format_png_Chunk.CHeader(this.readHeader(new haxe_io_BytesInput(data)));
		case "IDAT":
			return snow_utils_format_png_Chunk.CData(data);
		case "PLTE":
			return snow_utils_format_png_Chunk.CPalette(data);
		default:
			return snow_utils_format_png_Chunk.CUnknown(id,data);
		}
	}
	,__class__: snow_utils_format_png_Reader
};
var snow_utils_format_png_Tools = function() { };
snow_utils_format_png_Tools.__name__ = true;
snow_utils_format_png_Tools.getHeader = function(d) {
	var _g_head = d.h;
	var _g_val = null;
	while(_g_head != null) {
		var c;
		c = (function($this) {
			var $r;
			_g_val = _g_head[0];
			_g_head = _g_head[1];
			$r = _g_val;
			return $r;
		}(this));
		switch(c[1]) {
		case 1:
			var h = c[2];
			return h;
		default:
		}
	}
	throw new js__$Boot_HaxeError("Header not found");
};
snow_utils_format_png_Tools.getPalette = function(d) {
	var _g_head = d.h;
	var _g_val = null;
	while(_g_head != null) {
		var c;
		c = (function($this) {
			var $r;
			_g_val = _g_head[0];
			_g_head = _g_head[1];
			$r = _g_val;
			return $r;
		}(this));
		switch(c[1]) {
		case 3:
			var b = c[2];
			return b;
		default:
		}
	}
	return null;
};
snow_utils_format_png_Tools.filter = function(data,x,y,stride,prev,p,numChannels) {
	if(numChannels == null) numChannels = 4;
	var b;
	if(y == 0) b = 0; else b = data.b[p - stride];
	var c;
	if(x == 0 || y == 0) c = 0; else c = data.b[p - stride - numChannels];
	var k = prev + b - c;
	var pa = k - prev;
	if(pa < 0) pa = -pa;
	var pb = k - b;
	if(pb < 0) pb = -pb;
	var pc = k - c;
	if(pc < 0) pc = -pc;
	if(pa <= pb && pa <= pc) return prev; else if(pb <= pc) return b; else return c;
};
snow_utils_format_png_Tools.reverseBytes = function(b) {
	var p = 0;
	var _g1 = 0;
	var _g = b.length >> 2;
	while(_g1 < _g) {
		var i = _g1++;
		var b1 = b.b[p];
		var g = b.b[p + 1];
		var r = b.b[p + 2];
		var a = b.b[p + 3];
		var p1 = p++;
		b.b[p1] = a & 255;
		var p2 = p++;
		b.b[p2] = r & 255;
		var p3 = p++;
		b.b[p3] = g & 255;
		var p4 = p++;
		b.b[p4] = b1 & 255;
	}
};
snow_utils_format_png_Tools.extractGrey = function(d) {
	var h = snow_utils_format_png_Tools.getHeader(d);
	var grey = haxe_io_Bytes.alloc(h.width * h.height);
	var data = null;
	var fullData = null;
	var _g_head = d.h;
	var _g_val = null;
	while(_g_head != null) {
		var c;
		c = (function($this) {
			var $r;
			_g_val = _g_head[0];
			_g_head = _g_head[1];
			$r = _g_val;
			return $r;
		}(this));
		switch(c[1]) {
		case 2:
			var b = c[2];
			if(fullData != null) fullData.add(b); else if(data == null) data = b; else {
				fullData = new haxe_io_BytesBuffer();
				fullData.add(data);
				fullData.add(b);
				data = null;
			}
			break;
		default:
		}
	}
	if(fullData != null) data = fullData.getBytes();
	if(data == null) throw new js__$Boot_HaxeError("Data not found");
	data = snow_utils_format_tools_Inflate.run(data);
	var r = 0;
	var w = 0;
	{
		var _g = h.color;
		switch(_g[1]) {
		case 0:
			var alpha = _g[2];
			if(h.colbits != 8) throw new js__$Boot_HaxeError("Unsupported color mode");
			var width = h.width;
			var stride;
			stride = (alpha?2:1) * width + 1;
			if(data.length < h.height * stride) throw new js__$Boot_HaxeError("Not enough data");
			var rinc;
			if(alpha) rinc = 2; else rinc = 1;
			var _g2 = 0;
			var _g1 = h.height;
			while(_g2 < _g1) {
				var y = _g2++;
				var f = data.get(r++);
				switch(f) {
				case 0:
					var _g3 = 0;
					while(_g3 < width) {
						var x = _g3++;
						var v = data.b[r];
						r += rinc;
						grey.set(w++,v);
					}
					break;
				case 1:
					var cv = 0;
					var _g31 = 0;
					while(_g31 < width) {
						var x1 = _g31++;
						cv += data.b[r];
						r += rinc;
						grey.set(w++,cv);
					}
					break;
				case 2:
					var stride1;
					if(y == 0) stride1 = 0; else stride1 = width;
					var _g32 = 0;
					while(_g32 < width) {
						var x2 = _g32++;
						var v1 = data.b[r] + grey.b[w - stride1];
						r += rinc;
						grey.set(w++,v1);
					}
					break;
				case 3:
					var cv1 = 0;
					var stride2;
					if(y == 0) stride2 = 0; else stride2 = width;
					var _g33 = 0;
					while(_g33 < width) {
						var x3 = _g33++;
						cv1 = data.b[r] + (cv1 + grey.b[w - stride2] >> 1) & 255;
						r += rinc;
						grey.set(w++,cv1);
					}
					break;
				case 4:
					var stride3 = width;
					var cv2 = 0;
					var _g34 = 0;
					while(_g34 < width) {
						var x4 = _g34++;
						cv2 = snow_utils_format_png_Tools.filter(grey,x4,y,stride3,cv2,w,1) + data.b[r] & 255;
						r += rinc;
						grey.set(w++,cv2);
					}
					break;
				default:
					throw new js__$Boot_HaxeError("Invalid filter " + f);
				}
			}
			break;
		default:
			throw new js__$Boot_HaxeError("Unsupported color mode");
		}
	}
	return grey;
};
snow_utils_format_png_Tools.extract32 = function(d,bytes) {
	var h = snow_utils_format_png_Tools.getHeader(d);
	var bgra;
	if(bytes == null) bgra = haxe_io_Bytes.alloc(h.width * h.height * 4); else bgra = bytes;
	var data = null;
	var fullData = null;
	var _g_head = d.h;
	var _g_val = null;
	while(_g_head != null) {
		var c;
		c = (function($this) {
			var $r;
			_g_val = _g_head[0];
			_g_head = _g_head[1];
			$r = _g_val;
			return $r;
		}(this));
		switch(c[1]) {
		case 2:
			var b = c[2];
			if(fullData != null) fullData.add(b); else if(data == null) data = b; else {
				fullData = new haxe_io_BytesBuffer();
				fullData.add(data);
				fullData.add(b);
				data = null;
			}
			break;
		default:
		}
	}
	if(fullData != null) data = fullData.getBytes();
	if(data == null) throw new js__$Boot_HaxeError("Data not found");
	data = snow_utils_format_tools_Inflate.run(data);
	var r = 0;
	var w = 0;
	{
		var _g = h.color;
		switch(_g[1]) {
		case 2:
			var pal = snow_utils_format_png_Tools.getPalette(d);
			if(pal == null) throw new js__$Boot_HaxeError("PNG Palette is missing");
			var alpha = null;
			var _g1_head = d.h;
			var _g1_val = null;
			try {
				while(_g1_head != null) {
					var t;
					t = (function($this) {
						var $r;
						_g1_val = _g1_head[0];
						_g1_head = _g1_head[1];
						$r = _g1_val;
						return $r;
					}(this));
					switch(t[1]) {
					case 4:
						switch(t[2]) {
						case "tRNS":
							var data1 = t[3];
							alpha = data1;
							throw "__break__";
							break;
						default:
						}
						break;
					default:
					}
				}
			} catch( e ) { if( e != "__break__" ) throw e; }
			var width = h.width;
			var stride = width + 1;
			if(data.length < h.height * stride) throw new js__$Boot_HaxeError("Not enough data");
			var vr;
			var vg;
			var vb;
			var va = 255;
			var _g2 = 0;
			var _g1 = h.height;
			while(_g2 < _g1) {
				var y = _g2++;
				var f = data.get(r++);
				switch(f) {
				case 0:
					var _g3 = 0;
					while(_g3 < width) {
						var x = _g3++;
						var c1 = data.get(r++);
						vr = pal.b[c1 * 3];
						vg = pal.b[c1 * 3 + 1];
						vb = pal.b[c1 * 3 + 2];
						if(alpha != null) va = alpha.b[c1];
						bgra.set(w++,vb);
						bgra.set(w++,vg);
						bgra.set(w++,vr);
						bgra.set(w++,va);
					}
					break;
				case 1:
					var cr = 0;
					var cg = 0;
					var cb = 0;
					var ca = 0;
					var _g31 = 0;
					while(_g31 < width) {
						var x1 = _g31++;
						var c2 = data.get(r++);
						vr = pal.b[c2 * 3];
						vg = pal.b[c2 * 3 + 1];
						vb = pal.b[c2 * 3 + 2];
						if(alpha != null) va = alpha.b[c2];
						cb += vb;
						bgra.set(w++,cb);
						cg += vg;
						bgra.set(w++,cg);
						cr += vr;
						bgra.set(w++,cr);
						ca += va;
						bgra.set(w++,ca);
						bgra.set(w++,va);
					}
					break;
				case 2:
					var stride1;
					if(y == 0) stride1 = 0; else stride1 = width * 4;
					var _g32 = 0;
					while(_g32 < width) {
						var x2 = _g32++;
						var c3 = data.get(r++);
						vr = pal.b[c3 * 3];
						vg = pal.b[c3 * 3 + 1];
						vb = pal.b[c3 * 3 + 2];
						if(alpha != null) va = alpha.b[c3];
						bgra.b[w] = vb + bgra.b[w - stride1] & 255;
						w++;
						bgra.b[w] = vg + bgra.b[w - stride1] & 255;
						w++;
						bgra.b[w] = vr + bgra.b[w - stride1] & 255;
						w++;
						bgra.b[w] = va + bgra.b[w - stride1] & 255;
						w++;
					}
					break;
				case 3:
					var cr1 = 0;
					var cg1 = 0;
					var cb1 = 0;
					var ca1 = 0;
					var stride2;
					if(y == 0) stride2 = 0; else stride2 = width * 4;
					var _g33 = 0;
					while(_g33 < width) {
						var x3 = _g33++;
						var c4 = data.get(r++);
						vr = pal.b[c4 * 3];
						vg = pal.b[c4 * 3 + 1];
						vb = pal.b[c4 * 3 + 2];
						if(alpha != null) va = alpha.b[c4];
						cb1 = vb + (cb1 + bgra.b[w - stride2] >> 1) & 255;
						bgra.set(w++,cb1);
						cg1 = vg + (cg1 + bgra.b[w - stride2] >> 1) & 255;
						bgra.set(w++,cg1);
						cr1 = vr + (cr1 + bgra.b[w - stride2] >> 1) & 255;
						bgra.set(w++,cr1);
						cr1 = va + (ca1 + bgra.b[w - stride2] >> 1) & 255;
						bgra.set(w++,ca1);
					}
					break;
				case 4:
					var stride3 = width * 4;
					var cr2 = 0;
					var cg2 = 0;
					var cb2 = 0;
					var ca2 = 0;
					var _g34 = 0;
					while(_g34 < width) {
						var x4 = _g34++;
						var c5 = data.get(r++);
						vr = pal.b[c5 * 3];
						vg = pal.b[c5 * 3 + 1];
						vb = pal.b[c5 * 3 + 2];
						if(alpha != null) va = alpha.b[c5];
						cb2 = snow_utils_format_png_Tools.filter(bgra,x4,y,stride3,cb2,w,null) + vb & 255;
						bgra.set(w++,cb2);
						cg2 = snow_utils_format_png_Tools.filter(bgra,x4,y,stride3,cg2,w,null) + vg & 255;
						bgra.set(w++,cg2);
						cr2 = snow_utils_format_png_Tools.filter(bgra,x4,y,stride3,cr2,w,null) + vr & 255;
						bgra.set(w++,cr2);
						ca2 = snow_utils_format_png_Tools.filter(bgra,x4,y,stride3,ca2,w,null) + va & 255;
						bgra.set(w++,ca2);
					}
					break;
				default:
					throw new js__$Boot_HaxeError("Invalid filter " + f);
				}
			}
			break;
		case 0:
			var alpha1 = _g[2];
			if(h.colbits != 8) throw new js__$Boot_HaxeError("Unsupported color mode");
			var width1 = h.width;
			var stride4;
			stride4 = (alpha1?2:1) * width1 + 1;
			if(data.length < h.height * stride4) throw new js__$Boot_HaxeError("Not enough data");
			var _g21 = 0;
			var _g11 = h.height;
			while(_g21 < _g11) {
				var y1 = _g21++;
				var f1 = data.get(r++);
				switch(f1) {
				case 0:
					if(alpha1) {
						var _g35 = 0;
						while(_g35 < width1) {
							var x5 = _g35++;
							var v = data.get(r++);
							bgra.set(w++,v);
							bgra.set(w++,v);
							bgra.set(w++,v);
							bgra.set(w++,data.get(r++));
						}
					} else {
						var _g36 = 0;
						while(_g36 < width1) {
							var x6 = _g36++;
							var v1 = data.get(r++);
							bgra.set(w++,v1);
							bgra.set(w++,v1);
							bgra.set(w++,v1);
							bgra.set(w++,255);
						}
					}
					break;
				case 1:
					var cv = 0;
					var ca3 = 0;
					if(alpha1) {
						var _g37 = 0;
						while(_g37 < width1) {
							var x7 = _g37++;
							cv += data.get(r++);
							bgra.set(w++,cv);
							bgra.set(w++,cv);
							bgra.set(w++,cv);
							ca3 += data.get(r++);
							bgra.set(w++,ca3);
						}
					} else {
						var _g38 = 0;
						while(_g38 < width1) {
							var x8 = _g38++;
							cv += data.get(r++);
							bgra.set(w++,cv);
							bgra.set(w++,cv);
							bgra.set(w++,cv);
							bgra.set(w++,255);
						}
					}
					break;
				case 2:
					var stride5;
					if(y1 == 0) stride5 = 0; else stride5 = width1 * 4;
					if(alpha1) {
						var _g39 = 0;
						while(_g39 < width1) {
							var x9 = _g39++;
							var v2 = data.get(r++) + bgra.b[w - stride5];
							bgra.set(w++,v2);
							bgra.set(w++,v2);
							bgra.set(w++,v2);
							bgra.set(w++,data.get(r++) + bgra.b[w - stride5]);
						}
					} else {
						var _g310 = 0;
						while(_g310 < width1) {
							var x10 = _g310++;
							var v3 = data.get(r++) + bgra.b[w - stride5];
							bgra.set(w++,v3);
							bgra.set(w++,v3);
							bgra.set(w++,v3);
							bgra.set(w++,255);
						}
					}
					break;
				case 3:
					var cv1 = 0;
					var ca4 = 0;
					var stride6;
					if(y1 == 0) stride6 = 0; else stride6 = width1 * 4;
					if(alpha1) {
						var _g311 = 0;
						while(_g311 < width1) {
							var x11 = _g311++;
							cv1 = data.get(r++) + (cv1 + bgra.b[w - stride6] >> 1) & 255;
							bgra.set(w++,cv1);
							bgra.set(w++,cv1);
							bgra.set(w++,cv1);
							ca4 = data.get(r++) + (ca4 + bgra.b[w - stride6] >> 1) & 255;
							bgra.set(w++,ca4);
						}
					} else {
						var _g312 = 0;
						while(_g312 < width1) {
							var x12 = _g312++;
							cv1 = data.get(r++) + (cv1 + bgra.b[w - stride6] >> 1) & 255;
							bgra.set(w++,cv1);
							bgra.set(w++,cv1);
							bgra.set(w++,cv1);
							bgra.set(w++,255);
						}
					}
					break;
				case 4:
					var stride7 = width1 * 4;
					var cv2 = 0;
					var ca5 = 0;
					if(alpha1) {
						var _g313 = 0;
						while(_g313 < width1) {
							var x13 = _g313++;
							cv2 = snow_utils_format_png_Tools.filter(bgra,x13,y1,stride7,cv2,w,null) + data.get(r++) & 255;
							bgra.set(w++,cv2);
							bgra.set(w++,cv2);
							bgra.set(w++,cv2);
							ca5 = snow_utils_format_png_Tools.filter(bgra,x13,y1,stride7,ca5,w,null) + data.get(r++) & 255;
							bgra.set(w++,ca5);
						}
					} else {
						var _g314 = 0;
						while(_g314 < width1) {
							var x14 = _g314++;
							cv2 = snow_utils_format_png_Tools.filter(bgra,x14,y1,stride7,cv2,w,null) + data.get(r++) & 255;
							bgra.set(w++,cv2);
							bgra.set(w++,cv2);
							bgra.set(w++,cv2);
							bgra.set(w++,255);
						}
					}
					break;
				default:
					throw new js__$Boot_HaxeError("Invalid filter " + f1);
				}
			}
			break;
		case 1:
			var alpha2 = _g[2];
			if(h.colbits != 8) throw new js__$Boot_HaxeError("Unsupported color mode");
			var width2 = h.width;
			var stride8;
			stride8 = (alpha2?4:3) * width2 + 1;
			if(data.length < h.height * stride8) throw new js__$Boot_HaxeError("Not enough data");
			var _g22 = 0;
			var _g12 = h.height;
			while(_g22 < _g12) {
				var y2 = _g22++;
				var f2 = data.get(r++);
				switch(f2) {
				case 0:
					if(alpha2) {
						var _g315 = 0;
						while(_g315 < width2) {
							var x15 = _g315++;
							bgra.set(w++,data.b[r + 2]);
							bgra.set(w++,data.b[r + 1]);
							bgra.set(w++,data.b[r]);
							bgra.set(w++,data.b[r + 3]);
							r += 4;
						}
					} else {
						var _g316 = 0;
						while(_g316 < width2) {
							var x16 = _g316++;
							bgra.set(w++,data.b[r + 2]);
							bgra.set(w++,data.b[r + 1]);
							bgra.set(w++,data.b[r]);
							bgra.set(w++,255);
							r += 3;
						}
					}
					break;
				case 1:
					var cr3 = 0;
					var cg3 = 0;
					var cb3 = 0;
					var ca6 = 0;
					if(alpha2) {
						var _g317 = 0;
						while(_g317 < width2) {
							var x17 = _g317++;
							cb3 += data.b[r + 2];
							bgra.set(w++,cb3);
							cg3 += data.b[r + 1];
							bgra.set(w++,cg3);
							cr3 += data.b[r];
							bgra.set(w++,cr3);
							ca6 += data.b[r + 3];
							bgra.set(w++,ca6);
							r += 4;
						}
					} else {
						var _g318 = 0;
						while(_g318 < width2) {
							var x18 = _g318++;
							cb3 += data.b[r + 2];
							bgra.set(w++,cb3);
							cg3 += data.b[r + 1];
							bgra.set(w++,cg3);
							cr3 += data.b[r];
							bgra.set(w++,cr3);
							bgra.set(w++,255);
							r += 3;
						}
					}
					break;
				case 2:
					var stride9;
					if(y2 == 0) stride9 = 0; else stride9 = width2 * 4;
					if(alpha2) {
						var _g319 = 0;
						while(_g319 < width2) {
							var x19 = _g319++;
							bgra.b[w] = data.b[r + 2] + bgra.b[w - stride9] & 255;
							w++;
							bgra.b[w] = data.b[r + 1] + bgra.b[w - stride9] & 255;
							w++;
							bgra.b[w] = data.b[r] + bgra.b[w - stride9] & 255;
							w++;
							bgra.b[w] = data.b[r + 3] + bgra.b[w - stride9] & 255;
							w++;
							r += 4;
						}
					} else {
						var _g320 = 0;
						while(_g320 < width2) {
							var x20 = _g320++;
							bgra.b[w] = data.b[r + 2] + bgra.b[w - stride9] & 255;
							w++;
							bgra.b[w] = data.b[r + 1] + bgra.b[w - stride9] & 255;
							w++;
							bgra.b[w] = data.b[r] + bgra.b[w - stride9] & 255;
							w++;
							bgra.set(w++,255);
							r += 3;
						}
					}
					break;
				case 3:
					var cr4 = 0;
					var cg4 = 0;
					var cb4 = 0;
					var ca7 = 0;
					var stride10;
					if(y2 == 0) stride10 = 0; else stride10 = width2 * 4;
					if(alpha2) {
						var _g321 = 0;
						while(_g321 < width2) {
							var x21 = _g321++;
							cb4 = data.b[r + 2] + (cb4 + bgra.b[w - stride10] >> 1) & 255;
							bgra.set(w++,cb4);
							cg4 = data.b[r + 1] + (cg4 + bgra.b[w - stride10] >> 1) & 255;
							bgra.set(w++,cg4);
							cr4 = data.b[r] + (cr4 + bgra.b[w - stride10] >> 1) & 255;
							bgra.set(w++,cr4);
							ca7 = data.b[r + 3] + (ca7 + bgra.b[w - stride10] >> 1) & 255;
							bgra.set(w++,ca7);
							r += 4;
						}
					} else {
						var _g322 = 0;
						while(_g322 < width2) {
							var x22 = _g322++;
							cb4 = data.b[r + 2] + (cb4 + bgra.b[w - stride10] >> 1) & 255;
							bgra.set(w++,cb4);
							cg4 = data.b[r + 1] + (cg4 + bgra.b[w - stride10] >> 1) & 255;
							bgra.set(w++,cg4);
							cr4 = data.b[r] + (cr4 + bgra.b[w - stride10] >> 1) & 255;
							bgra.set(w++,cr4);
							bgra.set(w++,255);
							r += 3;
						}
					}
					break;
				case 4:
					var stride11 = width2 * 4;
					var cr5 = 0;
					var cg5 = 0;
					var cb5 = 0;
					var ca8 = 0;
					if(alpha2) {
						var _g323 = 0;
						while(_g323 < width2) {
							var x23 = _g323++;
							cb5 = snow_utils_format_png_Tools.filter(bgra,x23,y2,stride11,cb5,w,null) + data.b[r + 2] & 255;
							bgra.set(w++,cb5);
							cg5 = snow_utils_format_png_Tools.filter(bgra,x23,y2,stride11,cg5,w,null) + data.b[r + 1] & 255;
							bgra.set(w++,cg5);
							cr5 = snow_utils_format_png_Tools.filter(bgra,x23,y2,stride11,cr5,w,null) + data.b[r] & 255;
							bgra.set(w++,cr5);
							ca8 = snow_utils_format_png_Tools.filter(bgra,x23,y2,stride11,ca8,w,null) + data.b[r + 3] & 255;
							bgra.set(w++,ca8);
							r += 4;
						}
					} else {
						var _g324 = 0;
						while(_g324 < width2) {
							var x24 = _g324++;
							cb5 = snow_utils_format_png_Tools.filter(bgra,x24,y2,stride11,cb5,w,null) + data.b[r + 2] & 255;
							bgra.set(w++,cb5);
							cg5 = snow_utils_format_png_Tools.filter(bgra,x24,y2,stride11,cg5,w,null) + data.b[r + 1] & 255;
							bgra.set(w++,cg5);
							cr5 = snow_utils_format_png_Tools.filter(bgra,x24,y2,stride11,cr5,w,null) + data.b[r] & 255;
							bgra.set(w++,cr5);
							bgra.set(w++,255);
							r += 3;
						}
					}
					break;
				default:
					throw new js__$Boot_HaxeError("Invalid filter " + f2);
				}
			}
			break;
		}
	}
	return bgra;
};
snow_utils_format_png_Tools.buildGrey = function(width,height,data) {
	var rgb = haxe_io_Bytes.alloc(width * height + height);
	var w = 0;
	var r = 0;
	var _g = 0;
	while(_g < height) {
		var y = _g++;
		rgb.set(w++,0);
		var _g1 = 0;
		while(_g1 < width) {
			var x = _g1++;
			rgb.set(w++,data.get(r++));
		}
	}
	var l = new List();
	l.add(snow_utils_format_png_Chunk.CHeader({ width : width, height : height, colbits : 8, color : snow_utils_format_png_Color.ColGrey(false), interlaced : false}));
	l.add(snow_utils_format_png_Chunk.CData(snow_utils_format_tools_Deflate.run(rgb)));
	l.add(snow_utils_format_png_Chunk.CEnd);
	return l;
};
snow_utils_format_png_Tools.buildRGB = function(width,height,data) {
	var rgb = haxe_io_Bytes.alloc(width * height * 3 + height);
	var w = 0;
	var r = 0;
	var _g = 0;
	while(_g < height) {
		var y = _g++;
		rgb.set(w++,0);
		var _g1 = 0;
		while(_g1 < width) {
			var x = _g1++;
			rgb.set(w++,data.b[r + 2]);
			rgb.set(w++,data.b[r + 1]);
			rgb.set(w++,data.b[r]);
			r += 3;
		}
	}
	var l = new List();
	l.add(snow_utils_format_png_Chunk.CHeader({ width : width, height : height, colbits : 8, color : snow_utils_format_png_Color.ColTrue(false), interlaced : false}));
	l.add(snow_utils_format_png_Chunk.CData(snow_utils_format_tools_Deflate.run(rgb)));
	l.add(snow_utils_format_png_Chunk.CEnd);
	return l;
};
snow_utils_format_png_Tools.build32ARGB = function(width,height,data) {
	var rgba = haxe_io_Bytes.alloc(width * height * 4 + height);
	var w = 0;
	var r = 0;
	var _g = 0;
	while(_g < height) {
		var y = _g++;
		rgba.set(w++,0);
		var _g1 = 0;
		while(_g1 < width) {
			var x = _g1++;
			rgba.set(w++,data.b[r + 1]);
			rgba.set(w++,data.b[r + 2]);
			rgba.set(w++,data.b[r + 3]);
			rgba.set(w++,data.b[r]);
			r += 4;
		}
	}
	var l = new List();
	l.add(snow_utils_format_png_Chunk.CHeader({ width : width, height : height, colbits : 8, color : snow_utils_format_png_Color.ColTrue(true), interlaced : false}));
	l.add(snow_utils_format_png_Chunk.CData(snow_utils_format_tools_Deflate.run(rgba)));
	l.add(snow_utils_format_png_Chunk.CEnd);
	return l;
};
snow_utils_format_png_Tools.build32BGRA = function(width,height,data) {
	var rgba = haxe_io_Bytes.alloc(width * height * 4 + height);
	var w = 0;
	var r = 0;
	var _g = 0;
	while(_g < height) {
		var y = _g++;
		rgba.set(w++,0);
		var _g1 = 0;
		while(_g1 < width) {
			var x = _g1++;
			rgba.set(w++,data.b[r + 2]);
			rgba.set(w++,data.b[r + 1]);
			rgba.set(w++,data.b[r]);
			rgba.set(w++,data.b[r + 3]);
			r += 4;
		}
	}
	var l = new List();
	l.add(snow_utils_format_png_Chunk.CHeader({ width : width, height : height, colbits : 8, color : snow_utils_format_png_Color.ColTrue(true), interlaced : false}));
	l.add(snow_utils_format_png_Chunk.CData(snow_utils_format_tools_Deflate.run(rgba)));
	l.add(snow_utils_format_png_Chunk.CEnd);
	return l;
};
var snow_utils_format_tools_Adler32 = function() {
	this.a1 = 1;
	this.a2 = 0;
};
snow_utils_format_tools_Adler32.__name__ = true;
snow_utils_format_tools_Adler32.read = function(i) {
	var a = new snow_utils_format_tools_Adler32();
	var a2a = i.readByte();
	var a2b = i.readByte();
	var a1a = i.readByte();
	var a1b = i.readByte();
	a.a1 = a1a << 8 | a1b;
	a.a2 = a2a << 8 | a2b;
	return a;
};
snow_utils_format_tools_Adler32.prototype = {
	update: function(b,pos,len) {
		var a1 = this.a1;
		var a2 = this.a2;
		var _g1 = pos;
		var _g = pos + len;
		while(_g1 < _g) {
			var p = _g1++;
			var c = b.b[p];
			a1 = (a1 + c) % 65521;
			a2 = (a2 + a1) % 65521;
		}
		this.a1 = a1;
		this.a2 = a2;
	}
	,equals: function(a) {
		return a.a1 == this.a1 && a.a2 == this.a2;
	}
	,__class__: snow_utils_format_tools_Adler32
};
var snow_utils_format_tools_Deflate = function() { };
snow_utils_format_tools_Deflate.__name__ = true;
snow_utils_format_tools_Deflate.run = function(b) {
	throw new js__$Boot_HaxeError("Deflate is not supported on this platform");
	return null;
};
var snow_utils_format_tools_Huffman = { __ename__ : true, __constructs__ : ["Found","NeedBit","NeedBits"] };
snow_utils_format_tools_Huffman.Found = function(i) { var $x = ["Found",0,i]; $x.__enum__ = snow_utils_format_tools_Huffman; $x.toString = $estr; return $x; };
snow_utils_format_tools_Huffman.NeedBit = function(left,right) { var $x = ["NeedBit",1,left,right]; $x.__enum__ = snow_utils_format_tools_Huffman; $x.toString = $estr; return $x; };
snow_utils_format_tools_Huffman.NeedBits = function(n,table) { var $x = ["NeedBits",2,n,table]; $x.__enum__ = snow_utils_format_tools_Huffman; $x.toString = $estr; return $x; };
var snow_utils_format_tools_HuffTools = function() {
};
snow_utils_format_tools_HuffTools.__name__ = true;
snow_utils_format_tools_HuffTools.prototype = {
	treeDepth: function(t) {
		switch(t[1]) {
		case 0:
			return 0;
		case 2:
			throw new js__$Boot_HaxeError("assert");
			break;
		case 1:
			var b = t[3];
			var a = t[2];
			var da = this.treeDepth(a);
			var db = this.treeDepth(b);
			return 1 + (da < db?da:db);
		}
	}
	,treeCompress: function(t) {
		var d = this.treeDepth(t);
		if(d == 0) return t;
		if(d == 1) switch(t[1]) {
		case 1:
			var b = t[3];
			var a = t[2];
			return snow_utils_format_tools_Huffman.NeedBit(this.treeCompress(a),this.treeCompress(b));
		default:
			throw new js__$Boot_HaxeError("assert");
		}
		var size = 1 << d;
		var table = [];
		var _g = 0;
		while(_g < size) {
			var i = _g++;
			table.push(snow_utils_format_tools_Huffman.Found(-1));
		}
		this.treeWalk(table,0,0,d,t);
		return snow_utils_format_tools_Huffman.NeedBits(d,table);
	}
	,treeWalk: function(table,p,cd,d,t) {
		switch(t[1]) {
		case 1:
			var b = t[3];
			var a = t[2];
			if(d > 0) {
				this.treeWalk(table,p,cd + 1,d - 1,a);
				this.treeWalk(table,p | 1 << cd,cd + 1,d - 1,b);
			} else table[p] = this.treeCompress(t);
			break;
		default:
			table[p] = this.treeCompress(t);
		}
	}
	,treeMake: function(bits,maxbits,v,len) {
		if(len > maxbits) throw new js__$Boot_HaxeError("Invalid huffman");
		var idx = v << 5 | len;
		if(bits.h.hasOwnProperty(idx)) return snow_utils_format_tools_Huffman.Found(bits.h[idx]);
		v <<= 1;
		len += 1;
		return snow_utils_format_tools_Huffman.NeedBit(this.treeMake(bits,maxbits,v,len),this.treeMake(bits,maxbits,v | 1,len));
	}
	,make: function(lengths,pos,nlengths,maxbits) {
		var counts = [];
		var tmp = [];
		if(maxbits > 32) throw new js__$Boot_HaxeError("Invalid huffman");
		var _g = 0;
		while(_g < maxbits) {
			var i = _g++;
			counts.push(0);
			tmp.push(0);
		}
		var _g1 = 0;
		while(_g1 < nlengths) {
			var i1 = _g1++;
			var p = lengths[i1 + pos];
			if(p >= maxbits) throw new js__$Boot_HaxeError("Invalid huffman");
			counts[p]++;
		}
		var code = 0;
		var _g11 = 1;
		var _g2 = maxbits - 1;
		while(_g11 < _g2) {
			var i2 = _g11++;
			code = code + counts[i2] << 1;
			tmp[i2] = code;
		}
		var bits = new haxe_ds_IntMap();
		var _g3 = 0;
		while(_g3 < nlengths) {
			var i3 = _g3++;
			var l = lengths[i3 + pos];
			if(l != 0) {
				var n = tmp[l - 1];
				tmp[l - 1] = n + 1;
				bits.h[n << 5 | l] = i3;
			}
		}
		return this.treeCompress(snow_utils_format_tools_Huffman.NeedBit(this.treeMake(bits,maxbits,0,1),this.treeMake(bits,maxbits,1,1)));
	}
	,__class__: snow_utils_format_tools_HuffTools
};
var snow_utils_format_tools_Inflate = function() { };
snow_utils_format_tools_Inflate.__name__ = true;
snow_utils_format_tools_Inflate.run = function(bytes) {
	return snow_utils_format_tools_InflateImpl.run(new haxe_io_BytesInput(bytes));
};
var snow_utils_format_tools__$InflateImpl_Window = function(hasCrc) {
	this.buffer = haxe_io_Bytes.alloc(65536);
	this.pos = 0;
	if(hasCrc) this.crc = new snow_utils_format_tools_Adler32();
};
snow_utils_format_tools__$InflateImpl_Window.__name__ = true;
snow_utils_format_tools__$InflateImpl_Window.prototype = {
	slide: function() {
		if(this.crc != null) this.crc.update(this.buffer,0,32768);
		var b = haxe_io_Bytes.alloc(65536);
		this.pos -= 32768;
		b.blit(0,this.buffer,32768,this.pos);
		this.buffer = b;
	}
	,addBytes: function(b,p,len) {
		if(this.pos + len > 65536) this.slide();
		this.buffer.blit(this.pos,b,p,len);
		this.pos += len;
	}
	,addByte: function(c) {
		if(this.pos == 65536) this.slide();
		this.buffer.b[this.pos] = c & 255;
		this.pos++;
	}
	,getLastChar: function() {
		return this.buffer.b[this.pos - 1];
	}
	,available: function() {
		return this.pos;
	}
	,checksum: function() {
		if(this.crc != null) this.crc.update(this.buffer,0,this.pos);
		return this.crc;
	}
	,__class__: snow_utils_format_tools__$InflateImpl_Window
};
var snow_utils_format_tools__$InflateImpl_State = { __ename__ : true, __constructs__ : ["Head","Block","CData","Flat","Crc","Dist","DistOne","Done"] };
snow_utils_format_tools__$InflateImpl_State.Head = ["Head",0];
snow_utils_format_tools__$InflateImpl_State.Head.toString = $estr;
snow_utils_format_tools__$InflateImpl_State.Head.__enum__ = snow_utils_format_tools__$InflateImpl_State;
snow_utils_format_tools__$InflateImpl_State.Block = ["Block",1];
snow_utils_format_tools__$InflateImpl_State.Block.toString = $estr;
snow_utils_format_tools__$InflateImpl_State.Block.__enum__ = snow_utils_format_tools__$InflateImpl_State;
snow_utils_format_tools__$InflateImpl_State.CData = ["CData",2];
snow_utils_format_tools__$InflateImpl_State.CData.toString = $estr;
snow_utils_format_tools__$InflateImpl_State.CData.__enum__ = snow_utils_format_tools__$InflateImpl_State;
snow_utils_format_tools__$InflateImpl_State.Flat = ["Flat",3];
snow_utils_format_tools__$InflateImpl_State.Flat.toString = $estr;
snow_utils_format_tools__$InflateImpl_State.Flat.__enum__ = snow_utils_format_tools__$InflateImpl_State;
snow_utils_format_tools__$InflateImpl_State.Crc = ["Crc",4];
snow_utils_format_tools__$InflateImpl_State.Crc.toString = $estr;
snow_utils_format_tools__$InflateImpl_State.Crc.__enum__ = snow_utils_format_tools__$InflateImpl_State;
snow_utils_format_tools__$InflateImpl_State.Dist = ["Dist",5];
snow_utils_format_tools__$InflateImpl_State.Dist.toString = $estr;
snow_utils_format_tools__$InflateImpl_State.Dist.__enum__ = snow_utils_format_tools__$InflateImpl_State;
snow_utils_format_tools__$InflateImpl_State.DistOne = ["DistOne",6];
snow_utils_format_tools__$InflateImpl_State.DistOne.toString = $estr;
snow_utils_format_tools__$InflateImpl_State.DistOne.__enum__ = snow_utils_format_tools__$InflateImpl_State;
snow_utils_format_tools__$InflateImpl_State.Done = ["Done",7];
snow_utils_format_tools__$InflateImpl_State.Done.toString = $estr;
snow_utils_format_tools__$InflateImpl_State.Done.__enum__ = snow_utils_format_tools__$InflateImpl_State;
var snow_utils_format_tools_InflateImpl = function(i,header,crc) {
	if(crc == null) crc = true;
	if(header == null) header = true;
	this["final"] = false;
	this.htools = new snow_utils_format_tools_HuffTools();
	this.huffman = this.buildFixedHuffman();
	this.huffdist = null;
	this.len = 0;
	this.dist = 0;
	if(header) this.state = snow_utils_format_tools__$InflateImpl_State.Head; else this.state = snow_utils_format_tools__$InflateImpl_State.Block;
	this.input = i;
	this.bits = 0;
	this.nbits = 0;
	this.needed = 0;
	this.output = null;
	this.outpos = 0;
	this.lengths = [];
	var _g = 0;
	while(_g < 19) {
		var i1 = _g++;
		this.lengths.push(-1);
	}
	this.window = new snow_utils_format_tools__$InflateImpl_Window(crc);
};
snow_utils_format_tools_InflateImpl.__name__ = true;
snow_utils_format_tools_InflateImpl.run = function(i,bufsize) {
	if(bufsize == null) bufsize = 65536;
	var buf = haxe_io_Bytes.alloc(bufsize);
	var output = new haxe_io_BytesBuffer();
	var inflate = new snow_utils_format_tools_InflateImpl(i);
	while(true) {
		var len = inflate.readBytes(buf,0,bufsize);
		output.addBytes(buf,0,len);
		if(len < bufsize) break;
	}
	return output.getBytes();
};
snow_utils_format_tools_InflateImpl.prototype = {
	buildFixedHuffman: function() {
		if(snow_utils_format_tools_InflateImpl.FIXED_HUFFMAN != null) return snow_utils_format_tools_InflateImpl.FIXED_HUFFMAN;
		var a = [];
		var _g = 0;
		while(_g < 288) {
			var n = _g++;
			a.push(n <= 143?8:n <= 255?9:n <= 279?7:8);
		}
		snow_utils_format_tools_InflateImpl.FIXED_HUFFMAN = this.htools.make(a,0,288,10);
		return snow_utils_format_tools_InflateImpl.FIXED_HUFFMAN;
	}
	,readBytes: function(b,pos,len) {
		this.needed = len;
		this.outpos = pos;
		this.output = b;
		if(len > 0) while(this.inflateLoop()) {
		}
		return len - this.needed;
	}
	,getBits: function(n) {
		while(this.nbits < n) {
			this.bits |= this.input.readByte() << this.nbits;
			this.nbits += 8;
		}
		var b = this.bits & (1 << n) - 1;
		this.nbits -= n;
		this.bits >>= n;
		return b;
	}
	,getBit: function() {
		if(this.nbits == 0) {
			this.nbits = 8;
			this.bits = this.input.readByte();
		}
		var b = (this.bits & 1) == 1;
		this.nbits--;
		this.bits >>= 1;
		return b;
	}
	,getRevBits: function(n) {
		if(n == 0) return 0; else if(this.getBit()) return 1 << n - 1 | this.getRevBits(n - 1); else return this.getRevBits(n - 1);
	}
	,resetBits: function() {
		this.bits = 0;
		this.nbits = 0;
	}
	,addBytes: function(b,p,len) {
		this.window.addBytes(b,p,len);
		this.output.blit(this.outpos,b,p,len);
		this.needed -= len;
		this.outpos += len;
	}
	,addByte: function(b) {
		this.window.addByte(b);
		this.output.b[this.outpos] = b & 255;
		this.needed--;
		this.outpos++;
	}
	,addDistOne: function(n) {
		var c = this.window.getLastChar();
		var _g = 0;
		while(_g < n) {
			var i = _g++;
			this.addByte(c);
		}
	}
	,addDist: function(d,len) {
		this.addBytes(this.window.buffer,this.window.pos - d,len);
	}
	,applyHuffman: function(h) {
		switch(h[1]) {
		case 0:
			var n = h[2];
			return n;
		case 1:
			var b = h[3];
			var a = h[2];
			return this.applyHuffman(this.getBit()?b:a);
		case 2:
			var tbl = h[3];
			var n1 = h[2];
			return this.applyHuffman(tbl[this.getBits(n1)]);
		}
	}
	,inflateLengths: function(a,max) {
		var i = 0;
		var prev = 0;
		while(i < max) {
			var n = this.applyHuffman(this.huffman);
			switch(n) {
			case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:case 9:case 10:case 11:case 12:case 13:case 14:case 15:
				prev = n;
				a[i] = n;
				i++;
				break;
			case 16:
				var end = i + 3 + this.getBits(2);
				if(end > max) throw new js__$Boot_HaxeError("Invalid data");
				while(i < end) {
					a[i] = prev;
					i++;
				}
				break;
			case 17:
				i += 3 + this.getBits(3);
				if(i > max) throw new js__$Boot_HaxeError("Invalid data");
				break;
			case 18:
				i += 11 + this.getBits(7);
				if(i > max) throw new js__$Boot_HaxeError("Invalid data");
				break;
			default:
				throw new js__$Boot_HaxeError("Invalid data");
			}
		}
	}
	,inflateLoop: function() {
		var _g = this.state;
		switch(_g[1]) {
		case 0:
			var cmf = this.input.readByte();
			var cm = cmf & 15;
			var cinfo = cmf >> 4;
			if(cm != 8 || cinfo != 7) throw new js__$Boot_HaxeError("Invalid data");
			var flg = this.input.readByte();
			var fdict = (flg & 32) != 0;
			if(((cmf << 8) + flg) % 31 != 0) throw new js__$Boot_HaxeError("Invalid data");
			if(fdict) throw new js__$Boot_HaxeError("Unsupported dictionary");
			this.state = snow_utils_format_tools__$InflateImpl_State.Block;
			return true;
		case 4:
			var calc = this.window.checksum();
			if(calc == null) {
				this.state = snow_utils_format_tools__$InflateImpl_State.Done;
				return true;
			}
			var crc = snow_utils_format_tools_Adler32.read(this.input);
			if(!calc.equals(crc)) throw new js__$Boot_HaxeError("Invalid CRC");
			this.state = snow_utils_format_tools__$InflateImpl_State.Done;
			return true;
		case 7:
			return false;
		case 1:
			this["final"] = this.getBit();
			var _g1 = this.getBits(2);
			switch(_g1) {
			case 0:
				this.len = this.input.readUInt16();
				var nlen = this.input.readUInt16();
				if(nlen != 65535 - this.len) throw new js__$Boot_HaxeError("Invalid data");
				this.state = snow_utils_format_tools__$InflateImpl_State.Flat;
				var r = this.inflateLoop();
				this.resetBits();
				return r;
			case 1:
				this.huffman = this.buildFixedHuffman();
				this.huffdist = null;
				this.state = snow_utils_format_tools__$InflateImpl_State.CData;
				return true;
			case 2:
				var hlit = this.getBits(5) + 257;
				var hdist = this.getBits(5) + 1;
				var hclen = this.getBits(4) + 4;
				var _g2 = 0;
				while(_g2 < hclen) {
					var i = _g2++;
					this.lengths[snow_utils_format_tools_InflateImpl.CODE_LENGTHS_POS[i]] = this.getBits(3);
				}
				var _g21 = hclen;
				while(_g21 < 19) {
					var i1 = _g21++;
					this.lengths[snow_utils_format_tools_InflateImpl.CODE_LENGTHS_POS[i1]] = 0;
				}
				this.huffman = this.htools.make(this.lengths,0,19,8);
				var lengths = [];
				var _g3 = 0;
				var _g22 = hlit + hdist;
				while(_g3 < _g22) {
					var i2 = _g3++;
					lengths.push(0);
				}
				this.inflateLengths(lengths,hlit + hdist);
				this.huffdist = this.htools.make(lengths,hlit,hdist,16);
				this.huffman = this.htools.make(lengths,0,hlit,16);
				this.state = snow_utils_format_tools__$InflateImpl_State.CData;
				return true;
			default:
				throw new js__$Boot_HaxeError("Invalid data");
			}
			break;
		case 3:
			var rlen;
			if(this.len < this.needed) rlen = this.len; else rlen = this.needed;
			var bytes = this.input.read(rlen);
			this.len -= rlen;
			this.addBytes(bytes,0,rlen);
			if(this.len == 0) if(this["final"]) this.state = snow_utils_format_tools__$InflateImpl_State.Crc; else this.state = snow_utils_format_tools__$InflateImpl_State.Block;
			return this.needed > 0;
		case 6:
			var rlen1;
			if(this.len < this.needed) rlen1 = this.len; else rlen1 = this.needed;
			this.addDistOne(rlen1);
			this.len -= rlen1;
			if(this.len == 0) this.state = snow_utils_format_tools__$InflateImpl_State.CData;
			return this.needed > 0;
		case 5:
			while(this.len > 0 && this.needed > 0) {
				var rdist;
				if(this.len < this.dist) rdist = this.len; else rdist = this.dist;
				var rlen2;
				if(this.needed < rdist) rlen2 = this.needed; else rlen2 = rdist;
				this.addDist(this.dist,rlen2);
				this.len -= rlen2;
			}
			if(this.len == 0) this.state = snow_utils_format_tools__$InflateImpl_State.CData;
			return this.needed > 0;
		case 2:
			var n = this.applyHuffman(this.huffman);
			if(n < 256) {
				this.addByte(n);
				return this.needed > 0;
			} else if(n == 256) {
				if(this["final"]) this.state = snow_utils_format_tools__$InflateImpl_State.Crc; else this.state = snow_utils_format_tools__$InflateImpl_State.Block;
				return true;
			} else {
				n -= 257;
				var extra_bits = snow_utils_format_tools_InflateImpl.LEN_EXTRA_BITS_TBL[n];
				if(extra_bits == -1) throw new js__$Boot_HaxeError("Invalid data");
				this.len = snow_utils_format_tools_InflateImpl.LEN_BASE_VAL_TBL[n] + this.getBits(extra_bits);
				var dist_code;
				if(this.huffdist == null) dist_code = this.getRevBits(5); else dist_code = this.applyHuffman(this.huffdist);
				extra_bits = snow_utils_format_tools_InflateImpl.DIST_EXTRA_BITS_TBL[dist_code];
				if(extra_bits == -1) throw new js__$Boot_HaxeError("Invalid data");
				this.dist = snow_utils_format_tools_InflateImpl.DIST_BASE_VAL_TBL[dist_code] + this.getBits(extra_bits);
				if(this.dist > this.window.available()) throw new js__$Boot_HaxeError("Invalid data");
				if(this.dist == 1) this.state = snow_utils_format_tools__$InflateImpl_State.DistOne; else this.state = snow_utils_format_tools__$InflateImpl_State.Dist;
				return true;
			}
			break;
		}
	}
	,__class__: snow_utils_format_tools_InflateImpl
};
var snow_window_Window = function(_manager,_config) {
	this.internal_resize = false;
	this.internal_position = false;
	this.minimized = false;
	this.closed = true;
	this.auto_render = true;
	this.auto_swap = true;
	this.height = 0;
	this.width = 0;
	this.y = 0;
	this.x = 0;
	this.fullscreen = false;
	this.grab = false;
	this.bordered = true;
	this.title = "snow window";
	this.set_max_size({ x : 0, y : 0});
	this.set_min_size({ x : 0, y : 0});
	this.manager = _manager;
	this.asked_config = _config;
	this.config = _config;
	if(this.config.x == null) this.config.x = 536805376;
	if(this.config.y == null) this.config.y = 536805376;
	this.manager.platform.create(_manager.lib.config.render,_config,$bind(this,this.on_window_created));
};
snow_window_Window.__name__ = true;
snow_window_Window.prototype = {
	on_window_created: function(_handle,_id,_configs) {
		this.id = _id;
		this.handle = _handle;
		if(this.handle == null) {
			haxe_Log.trace("   i / window / " + "failed to create window",{ fileName : "Window.hx", lineNumber : 94, className : "snow.window.Window", methodName : "on_window_created"});
			return;
		}
		this.closed = false;
		this.config = _configs.config;
		this.manager.lib.config.render = _configs.render_config;
		this.internal_position = true;
		this.set_x(this.config.x);
		this.set_y(this.config.y);
		this.internal_position = false;
		this.internal_resize = true;
		this.set_width(this.config.width);
		this.set_height(this.config.height);
		this.internal_resize = false;
		this.on_event({ type : 1, window_id : _id, timestamp : snow_Snow.core.timestamp(), event : { }});
		null;
	}
	,on_event: function(_event) {
		var _g = _event.type;
		if(_g != null) switch(_g) {
		case 5:
			this.internal_position = true;
			this.set_position(_event.event.x,_event.event.y);
			this.internal_position = false;
			break;
		case 6:
			this.internal_resize = true;
			this.set_size(_event.event.x,_event.event.y);
			this.internal_resize = false;
			break;
		case 7:
			this.internal_resize = true;
			this.set_size(_event.event.x,_event.event.y);
			this.internal_resize = false;
			break;
		case 8:
			this.minimized = true;
			break;
		case 10:
			this.minimized = false;
			break;
		default:
		} else {
		}
		if(this.onevent != null) this.onevent(_event);
	}
	,update: function() {
		if(this.handle != null && !this.closed) this.manager.platform.update(this);
	}
	,render: function() {
		if(this.minimized || this.closed) return;
		if(this.handle == null) return;
		this.manager.platform.render(this);
		if(this.onrender != null) {
			this.onrender(this);
			if(this.auto_swap) this.swap();
			return;
		}
		snow_platform_web_render_opengl_GL.clearColor(0.8,0.12,0.12,1.0);
		snow_platform_web_render_opengl_GL.clear(16384);
		if(this.auto_swap) this.swap();
	}
	,swap: function() {
		if(this.handle == null || this.closed || this.minimized) return;
		this.manager.platform.swap(this);
	}
	,destroy: function() {
		this.closed = true;
		if(this.handle == null) return;
		this.manager.remove(this);
		this.manager.platform.destroy_window(this);
		this.handle = null;
	}
	,close: function() {
		this.closed = true;
		if(this.handle == null) return;
		this.manager.platform.close(this);
	}
	,show: function() {
		if(this.handle == null) return;
		this.closed = false;
		this.manager.platform.show(this);
	}
	,simple_message: function(message,title) {
		if(title == null) title = "";
		if(this.handle == null) return;
		this.manager.platform.simple_message(this,message,title);
	}
	,get_fullscreen: function() {
		return this.fullscreen;
	}
	,set_fullscreen: function(_enable) {
		if(this.handle != null) this.manager.platform.fullscreen(this,_enable);
		return this.fullscreen = _enable;
	}
	,get_bordered: function() {
		return this.bordered;
	}
	,get_grab: function() {
		return this.grab;
	}
	,get_max_size: function() {
		return this.max_size;
	}
	,get_min_size: function() {
		return this.min_size;
	}
	,get_title: function() {
		return this.title;
	}
	,set_title: function(_title) {
		if(this.handle != null) this.manager.platform.set_title(this,_title);
		return this.title = _title;
	}
	,set_x: function(_x) {
		this.x = _x;
		if(this.handle != null && !this.internal_position) this.manager.platform.set_position(this,this.x,this.y);
		return this.x;
	}
	,set_y: function(_y) {
		this.y = _y;
		if(this.handle != null && !this.internal_position) this.manager.platform.set_position(this,this.x,this.y);
		return this.y;
	}
	,set_width: function(_width) {
		this.width = _width;
		if(this.handle != null && !this.internal_resize) this.manager.platform.set_size(this,this.width,this.height);
		return this.width;
	}
	,set_height: function(_height) {
		this.height = _height;
		if(this.handle != null && !this.internal_resize) this.manager.platform.set_size(this,this.width,this.height);
		return this.height;
	}
	,set_cursor_position: function(_x,_y) {
		if(this.handle != null && !this.closed) this.manager.platform.set_cursor_position(this,_x,_y);
	}
	,set_position: function(_x,_y) {
		var last_internal_position_flag = this.internal_position;
		this.internal_position = true;
		this.set_x(_x);
		this.set_y(_y);
		this.internal_position = last_internal_position_flag;
		if(this.handle != null && !this.internal_position) this.manager.platform.set_position(this,this.x,this.y);
	}
	,set_size: function(_width,_height) {
		var last_internal_resize_flag = this.internal_resize;
		this.internal_resize = true;
		this.set_width(_width);
		this.set_height(_height);
		this.internal_resize = last_internal_resize_flag;
		if(this.handle != null && !this.internal_resize) this.manager.platform.set_size(this,_width,_height);
	}
	,set_max_size: function(_size) {
		if(this.get_max_size() != null && this.handle != null) this.manager.platform.set_max_size(this,_size.x,_size.y);
		return this.max_size = _size;
	}
	,set_min_size: function(_size) {
		if(this.get_min_size() != null && this.handle != null) this.manager.platform.set_min_size(this,_size.x,_size.y);
		return this.min_size = _size;
	}
	,set_bordered: function(_bordered) {
		if(this.handle != null) this.manager.platform.bordered(this,_bordered);
		return this.bordered = _bordered;
	}
	,set_grab: function(_grab) {
		if(this.handle != null) this.manager.platform.grab(this,_grab);
		return this.grab = _grab;
	}
	,__class__: snow_window_Window
	,__properties__: {set_min_size:"set_min_size",get_min_size:"get_min_size",set_max_size:"set_max_size",get_max_size:"get_max_size",set_height:"set_height",set_width:"set_width",set_y:"set_y",set_x:"set_x",set_fullscreen:"set_fullscreen",get_fullscreen:"get_fullscreen",set_grab:"set_grab",get_grab:"get_grab",set_bordered:"set_bordered",get_bordered:"get_bordered",set_title:"set_title",get_title:"get_title"}
};
var snow_window_Windowing = function(_lib) {
	this.window_count = 0;
	this.lib = _lib;
	this.window_list = new haxe_ds_IntMap();
	this.window_handles = new haxe_ds_ObjectMap();
	this.platform = new snow_platform_web_window_WindowSystem(this,this.lib);
	this.platform.init();
};
snow_window_Windowing.__name__ = true;
snow_window_Windowing.prototype = {
	create: function(_config) {
		var _window = new snow_window_Window(this,_config);
		this.window_list.h[_window.id] = _window;
		this.window_handles.set(_window.handle,_window.id);
		this.window_count++;
		this.platform.listen(_window);
		if(_config.no_input == null || _config.no_input == false) this.lib.input.listen(_window);
		return _window;
	}
	,remove: function(_window) {
		this.window_list.remove(_window.id);
		this.window_handles.remove(_window.handle);
		this.window_count--;
		this.platform.unlisten(_window);
		if(_window.config.no_input == null || _window.config.no_input == false) this.lib.input.unlisten(_window);
	}
	,window_from_handle: function(_handle) {
		if(this.window_handles.h.__keys__[_handle.__id__] != null) {
			var _id = this.window_handles.h[_handle.__id__];
			return this.window_list.h[_id];
		}
		return null;
	}
	,window_from_id: function(_id) {
		return this.window_list.h[_id];
	}
	,enable_vsync: function(_enable) {
		return this.platform.system_enable_vsync(_enable);
	}
	,enable_cursor: function(_enable) {
		this.platform.system_enable_cursor(_enable);
	}
	,enable_cursor_lock: function(_enable) {
		this.platform.system_lock_cursor(_enable);
	}
	,display_count: function() {
		return this.platform.display_count();
	}
	,display_mode_count: function(display) {
		return this.platform.display_mode_count(display);
	}
	,display_native_mode: function(display) {
		return this.platform.display_native_mode(display);
	}
	,display_current_mode: function(display) {
		return this.platform.display_current_mode(display);
	}
	,display_mode: function(display,mode_index) {
		return this.platform.display_mode(display,mode_index);
	}
	,display_bounds: function(display) {
		return this.platform.display_bounds(display);
	}
	,display_name: function(display) {
		return this.platform.display_name(display);
	}
	,on_event: function(_event) {
		if(_event.type == 5) {
			var _window_event = _event.window;
			var _window = this.window_list.h[_window_event.window_id];
			if(_window != null) _window.on_event(_window_event);
		}
	}
	,update: function() {
		this.platform.process();
		var $it0 = this.window_list.iterator();
		while( $it0.hasNext() ) {
			var $window = $it0.next();
			$window.update();
		}
		var $it1 = this.window_list.iterator();
		while( $it1.hasNext() ) {
			var window1 = $it1.next();
			if(window1.auto_render) window1.render();
		}
	}
	,destroy: function() {
		this.platform.destroy();
	}
	,__class__: snow_window_Windowing
};
function $iterator(o) { if( o instanceof Array ) return function() { return HxOverrides.iter(o); }; return typeof(o.iterator) == 'function' ? $bind(o,o.iterator) : o.iterator; }
var $_, $fid = 0;
function $bind(o,m) { if( m == null ) return null; if( m.__id__ == null ) m.__id__ = $fid++; var f; if( o.hx__closures__ == null ) o.hx__closures__ = {}; else f = o.hx__closures__[m.__id__]; if( f == null ) { f = function(){ return f.method.apply(f.scope, arguments); }; f.scope = o; f.method = m; o.hx__closures__[m.__id__] = f; } return f; }
if(Array.prototype.indexOf) HxOverrides.indexOf = function(a,o,i) {
	return Array.prototype.indexOf.call(a,o,i);
};
String.prototype.__class__ = String;
String.__name__ = true;
Array.__name__ = true;
Date.prototype.__class__ = Date;
Date.__name__ = ["Date"];
var Int = { __name__ : ["Int"]};
var Dynamic = { __name__ : ["Dynamic"]};
var Float = Number;
Float.__name__ = ["Float"];
var Bool = Boolean;
Bool.__ename__ = ["Bool"];
var Class = { __name__ : ["Class"]};
var Enum = { };
if(Array.prototype.map == null) Array.prototype.map = function(f) {
	var a = [];
	var _g1 = 0;
	var _g = this.length;
	while(_g1 < _g) {
		var i = _g1++;
		a[i] = f(this[i]);
	}
	return a;
};
if(Array.prototype.filter == null) Array.prototype.filter = function(f1) {
	var a1 = [];
	var _g11 = 0;
	var _g2 = this.length;
	while(_g11 < _g2) {
		var i1 = _g11++;
		var e = this[i1];
		if(f1(e)) a1.push(e);
	}
	return a1;
};
var __map_reserved = {}
var ArrayBuffer = typeof(window) != "undefined" && window.ArrayBuffer || typeof(global) != "undefined" && global.ArrayBuffer || js_html_compat_ArrayBuffer;
if(ArrayBuffer.prototype.slice == null) ArrayBuffer.prototype.slice = js_html_compat_ArrayBuffer.sliceImpl;
var DataView = typeof(window) != "undefined" && window.DataView || typeof(global) != "undefined" && global.DataView || js_html_compat_DataView;
var Uint8Array = typeof(window) != "undefined" && window.Uint8Array || typeof(global) != "undefined" && global.Uint8Array || js_html_compat_Uint8Array._new;
Luxe.version = "dev";
Luxe.build = "+8db7c1203c";
haxe_crypto_Base64.CHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
haxe_crypto_Base64.BYTES = haxe_io_Bytes.ofString(haxe_crypto_Base64.CHARS);
haxe_ds_ObjectMap.count = 0;
haxe_io_FPHelper.i64tmp = (function($this) {
	var $r;
	var x = new haxe__$Int64__$_$_$Int64(0,0);
	$r = x;
	return $r;
}(this));
hxDaedalus_ai_EntityAI.NUM_SEGMENTS = 6;
hxDaedalus_data_Constants.EPSILON = 0.01;
hxDaedalus_data_Constants.EPSILON_SQUARED = 0.0001;
hxDaedalus_data_ConstraintSegment.INC = 0;
hxDaedalus_data_ConstraintShape.INC = 0;
hxDaedalus_data_Edge.INC = 0;
hxDaedalus_data_Face.INC = 0;
hxDaedalus_data_Mesh.INC = 0;
hxDaedalus_data_Object.INC = 0;
hxDaedalus_data_Vertex.INC = 0;
hxDaedalus_data_math_Geom2D.__samples = [];
hxDaedalus_data_math_Geom2D.__circumcenter = new hxDaedalus_data_math_Point2D();
js_Boot.__toStr = {}.toString;
js_html_compat_Uint8Array.BYTES_PER_ELEMENT = 1;
luxe_Tag.update = "real dt";
luxe_Tag.renderdt = "render dt";
luxe_Tag.game_update = "game.update";
luxe_Tag.render = "core.render";
luxe_Tag.debug = "core.debug";
luxe_Tag.updates = "core.updates";
luxe_Tag.events = "core.events";
luxe_Tag.audio = "core.audio";
luxe_Tag.input = "core.input";
luxe_Tag.timer = "core.timer";
luxe_Tag.scene = "core.scene";
luxe_Debug.shut_down = false;
luxe_Log._level = 1;
luxe_Log._log_width = 16;
luxe_Physics.tag_physics = "physics";
luxe_macros_BuildVersion._save = false;
luxe_structural__$BalancedBST_NodeColor.red = true;
luxe_structural__$BalancedBST_NodeColor.black = false;
luxe_tween_actuators_SimpleActuator.actuators = [];
luxe_tween_actuators_SimpleActuator.actuatorsLength = 0;
luxe_tween_actuators_SimpleActuator.addedEvent = false;
luxe_tween_actuators_SimpleActuator.update_timer = 0;
luxe_tween_actuators_SimpleActuator.current_time = 0;
luxe_tween_Actuate.defaultActuator = luxe_tween_actuators_SimpleActuator;
luxe_tween_Actuate.defaultEase = luxe_tween_easing_Quad.get_easeOut();
luxe_tween_Actuate.targetLibraries = new haxe_ds_ObjectMap();
luxe_utils_GeometryUtils.two_pi = 6.283185307179586;
luxe_utils_Maths._PI_OVER_180 = 0.017453292519943278;
luxe_utils_Maths._180_OVER_PI = 57.29577951308238;
luxe_utils_unifill_Unicode.minCodePoint = 0;
luxe_utils_unifill_Unicode.maxCodePoint = 1114111;
luxe_utils_unifill_Unicode.minHighSurrogate = 55296;
luxe_utils_unifill_Unicode.maxHighSurrogate = 56319;
luxe_utils_unifill_Unicode.minLowSurrogate = 56320;
luxe_utils_unifill_Unicode.maxLowSurrogate = 57343;
phoenix_Batcher._sequence_key = -1;
phoenix_BitmapFont.generic_names = ["font",""," "];
phoenix_geometry_Geometry._sequence_key = -1;
phoenix_geometry_TextGeometry.tab_regex = new EReg("\t","gim");
snow_Log._level = 1;
snow_Log._log_width = 16;
snow_input_Scancodes.MASK = 1073741824;
snow_input_Scancodes.unknown = 0;
snow_input_Scancodes.key_a = 4;
snow_input_Scancodes.key_b = 5;
snow_input_Scancodes.key_c = 6;
snow_input_Scancodes.key_d = 7;
snow_input_Scancodes.key_e = 8;
snow_input_Scancodes.key_f = 9;
snow_input_Scancodes.key_g = 10;
snow_input_Scancodes.key_h = 11;
snow_input_Scancodes.key_i = 12;
snow_input_Scancodes.key_j = 13;
snow_input_Scancodes.key_k = 14;
snow_input_Scancodes.key_l = 15;
snow_input_Scancodes.key_m = 16;
snow_input_Scancodes.key_n = 17;
snow_input_Scancodes.key_o = 18;
snow_input_Scancodes.key_p = 19;
snow_input_Scancodes.key_q = 20;
snow_input_Scancodes.key_r = 21;
snow_input_Scancodes.key_s = 22;
snow_input_Scancodes.key_t = 23;
snow_input_Scancodes.key_u = 24;
snow_input_Scancodes.key_v = 25;
snow_input_Scancodes.key_w = 26;
snow_input_Scancodes.key_x = 27;
snow_input_Scancodes.key_y = 28;
snow_input_Scancodes.key_z = 29;
snow_input_Scancodes.key_1 = 30;
snow_input_Scancodes.key_2 = 31;
snow_input_Scancodes.key_3 = 32;
snow_input_Scancodes.key_4 = 33;
snow_input_Scancodes.key_5 = 34;
snow_input_Scancodes.key_6 = 35;
snow_input_Scancodes.key_7 = 36;
snow_input_Scancodes.key_8 = 37;
snow_input_Scancodes.key_9 = 38;
snow_input_Scancodes.key_0 = 39;
snow_input_Scancodes.enter = 40;
snow_input_Scancodes.escape = 41;
snow_input_Scancodes.backspace = 42;
snow_input_Scancodes.tab = 43;
snow_input_Scancodes.space = 44;
snow_input_Scancodes.minus = 45;
snow_input_Scancodes.equals = 46;
snow_input_Scancodes.leftbracket = 47;
snow_input_Scancodes.rightbracket = 48;
snow_input_Scancodes.backslash = 49;
snow_input_Scancodes.nonushash = 50;
snow_input_Scancodes.semicolon = 51;
snow_input_Scancodes.apostrophe = 52;
snow_input_Scancodes.grave = 53;
snow_input_Scancodes.comma = 54;
snow_input_Scancodes.period = 55;
snow_input_Scancodes.slash = 56;
snow_input_Scancodes.capslock = 57;
snow_input_Scancodes.f1 = 58;
snow_input_Scancodes.f2 = 59;
snow_input_Scancodes.f3 = 60;
snow_input_Scancodes.f4 = 61;
snow_input_Scancodes.f5 = 62;
snow_input_Scancodes.f6 = 63;
snow_input_Scancodes.f7 = 64;
snow_input_Scancodes.f8 = 65;
snow_input_Scancodes.f9 = 66;
snow_input_Scancodes.f10 = 67;
snow_input_Scancodes.f11 = 68;
snow_input_Scancodes.f12 = 69;
snow_input_Scancodes.printscreen = 70;
snow_input_Scancodes.scrolllock = 71;
snow_input_Scancodes.pause = 72;
snow_input_Scancodes.insert = 73;
snow_input_Scancodes.home = 74;
snow_input_Scancodes.pageup = 75;
snow_input_Scancodes["delete"] = 76;
snow_input_Scancodes.end = 77;
snow_input_Scancodes.pagedown = 78;
snow_input_Scancodes.right = 79;
snow_input_Scancodes.left = 80;
snow_input_Scancodes.down = 81;
snow_input_Scancodes.up = 82;
snow_input_Scancodes.numlockclear = 83;
snow_input_Scancodes.kp_divide = 84;
snow_input_Scancodes.kp_multiply = 85;
snow_input_Scancodes.kp_minus = 86;
snow_input_Scancodes.kp_plus = 87;
snow_input_Scancodes.kp_enter = 88;
snow_input_Scancodes.kp_1 = 89;
snow_input_Scancodes.kp_2 = 90;
snow_input_Scancodes.kp_3 = 91;
snow_input_Scancodes.kp_4 = 92;
snow_input_Scancodes.kp_5 = 93;
snow_input_Scancodes.kp_6 = 94;
snow_input_Scancodes.kp_7 = 95;
snow_input_Scancodes.kp_8 = 96;
snow_input_Scancodes.kp_9 = 97;
snow_input_Scancodes.kp_0 = 98;
snow_input_Scancodes.kp_period = 99;
snow_input_Scancodes.nonusbackslash = 100;
snow_input_Scancodes.application = 101;
snow_input_Scancodes.power = 102;
snow_input_Scancodes.kp_equals = 103;
snow_input_Scancodes.f13 = 104;
snow_input_Scancodes.f14 = 105;
snow_input_Scancodes.f15 = 106;
snow_input_Scancodes.f16 = 107;
snow_input_Scancodes.f17 = 108;
snow_input_Scancodes.f18 = 109;
snow_input_Scancodes.f19 = 110;
snow_input_Scancodes.f20 = 111;
snow_input_Scancodes.f21 = 112;
snow_input_Scancodes.f22 = 113;
snow_input_Scancodes.f23 = 114;
snow_input_Scancodes.f24 = 115;
snow_input_Scancodes.execute = 116;
snow_input_Scancodes.help = 117;
snow_input_Scancodes.menu = 118;
snow_input_Scancodes.select = 119;
snow_input_Scancodes.stop = 120;
snow_input_Scancodes.again = 121;
snow_input_Scancodes.undo = 122;
snow_input_Scancodes.cut = 123;
snow_input_Scancodes.copy = 124;
snow_input_Scancodes.paste = 125;
snow_input_Scancodes.find = 126;
snow_input_Scancodes.mute = 127;
snow_input_Scancodes.volumeup = 128;
snow_input_Scancodes.volumedown = 129;
snow_input_Scancodes.kp_comma = 133;
snow_input_Scancodes.kp_equalsas400 = 134;
snow_input_Scancodes.international1 = 135;
snow_input_Scancodes.international2 = 136;
snow_input_Scancodes.international3 = 137;
snow_input_Scancodes.international4 = 138;
snow_input_Scancodes.international5 = 139;
snow_input_Scancodes.international6 = 140;
snow_input_Scancodes.international7 = 141;
snow_input_Scancodes.international8 = 142;
snow_input_Scancodes.international9 = 143;
snow_input_Scancodes.lang1 = 144;
snow_input_Scancodes.lang2 = 145;
snow_input_Scancodes.lang3 = 146;
snow_input_Scancodes.lang4 = 147;
snow_input_Scancodes.lang5 = 148;
snow_input_Scancodes.lang6 = 149;
snow_input_Scancodes.lang7 = 150;
snow_input_Scancodes.lang8 = 151;
snow_input_Scancodes.lang9 = 152;
snow_input_Scancodes.alterase = 153;
snow_input_Scancodes.sysreq = 154;
snow_input_Scancodes.cancel = 155;
snow_input_Scancodes.clear = 156;
snow_input_Scancodes.prior = 157;
snow_input_Scancodes.return2 = 158;
snow_input_Scancodes.separator = 159;
snow_input_Scancodes.out = 160;
snow_input_Scancodes.oper = 161;
snow_input_Scancodes.clearagain = 162;
snow_input_Scancodes.crsel = 163;
snow_input_Scancodes.exsel = 164;
snow_input_Scancodes.kp_00 = 176;
snow_input_Scancodes.kp_000 = 177;
snow_input_Scancodes.thousandsseparator = 178;
snow_input_Scancodes.decimalseparator = 179;
snow_input_Scancodes.currencyunit = 180;
snow_input_Scancodes.currencysubunit = 181;
snow_input_Scancodes.kp_leftparen = 182;
snow_input_Scancodes.kp_rightparen = 183;
snow_input_Scancodes.kp_leftbrace = 184;
snow_input_Scancodes.kp_rightbrace = 185;
snow_input_Scancodes.kp_tab = 186;
snow_input_Scancodes.kp_backspace = 187;
snow_input_Scancodes.kp_a = 188;
snow_input_Scancodes.kp_b = 189;
snow_input_Scancodes.kp_c = 190;
snow_input_Scancodes.kp_d = 191;
snow_input_Scancodes.kp_e = 192;
snow_input_Scancodes.kp_f = 193;
snow_input_Scancodes.kp_xor = 194;
snow_input_Scancodes.kp_power = 195;
snow_input_Scancodes.kp_percent = 196;
snow_input_Scancodes.kp_less = 197;
snow_input_Scancodes.kp_greater = 198;
snow_input_Scancodes.kp_ampersand = 199;
snow_input_Scancodes.kp_dblampersand = 200;
snow_input_Scancodes.kp_verticalbar = 201;
snow_input_Scancodes.kp_dblverticalbar = 202;
snow_input_Scancodes.kp_colon = 203;
snow_input_Scancodes.kp_hash = 204;
snow_input_Scancodes.kp_space = 205;
snow_input_Scancodes.kp_at = 206;
snow_input_Scancodes.kp_exclam = 207;
snow_input_Scancodes.kp_memstore = 208;
snow_input_Scancodes.kp_memrecall = 209;
snow_input_Scancodes.kp_memclear = 210;
snow_input_Scancodes.kp_memadd = 211;
snow_input_Scancodes.kp_memsubtract = 212;
snow_input_Scancodes.kp_memmultiply = 213;
snow_input_Scancodes.kp_memdivide = 214;
snow_input_Scancodes.kp_plusminus = 215;
snow_input_Scancodes.kp_clear = 216;
snow_input_Scancodes.kp_clearentry = 217;
snow_input_Scancodes.kp_binary = 218;
snow_input_Scancodes.kp_octal = 219;
snow_input_Scancodes.kp_decimal = 220;
snow_input_Scancodes.kp_hexadecimal = 221;
snow_input_Scancodes.lctrl = 224;
snow_input_Scancodes.lshift = 225;
snow_input_Scancodes.lalt = 226;
snow_input_Scancodes.lmeta = 227;
snow_input_Scancodes.rctrl = 228;
snow_input_Scancodes.rshift = 229;
snow_input_Scancodes.ralt = 230;
snow_input_Scancodes.rmeta = 231;
snow_input_Scancodes.mode = 257;
snow_input_Scancodes.audionext = 258;
snow_input_Scancodes.audioprev = 259;
snow_input_Scancodes.audiostop = 260;
snow_input_Scancodes.audioplay = 261;
snow_input_Scancodes.audiomute = 262;
snow_input_Scancodes.mediaselect = 263;
snow_input_Scancodes.www = 264;
snow_input_Scancodes.mail = 265;
snow_input_Scancodes.calculator = 266;
snow_input_Scancodes.computer = 267;
snow_input_Scancodes.ac_search = 268;
snow_input_Scancodes.ac_home = 269;
snow_input_Scancodes.ac_back = 270;
snow_input_Scancodes.ac_forward = 271;
snow_input_Scancodes.ac_stop = 272;
snow_input_Scancodes.ac_refresh = 273;
snow_input_Scancodes.ac_bookmarks = 274;
snow_input_Scancodes.brightnessdown = 275;
snow_input_Scancodes.brightnessup = 276;
snow_input_Scancodes.displayswitch = 277;
snow_input_Scancodes.kbdillumtoggle = 278;
snow_input_Scancodes.kbdillumdown = 279;
snow_input_Scancodes.kbdillumup = 280;
snow_input_Scancodes.eject = 281;
snow_input_Scancodes.sleep = 282;
snow_input_Scancodes.app1 = 283;
snow_input_Scancodes.app2 = 284;
snow_input_Scancodes.scancode_names = [null,null,null,null,"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z","1","2","3","4","5","6","7","8","9","0","Enter","Escape","Backspace","Tab","Space","-","=","[","]","\\","#",";","'","`",",",".","/","CapsLock","F1","F2","F3","F4","F5","F6","F7","F8","F9","F10","F11","F12","PrintScreen","ScrollLock","Pause","Insert","Home","PageUp","Delete","End","PageDown","Right","Left","Down","Up","Numlock","Keypad /","Keypad *","Keypad -","Keypad +","Keypad Enter","Keypad 1","Keypad 2","Keypad 3","Keypad 4","Keypad 5","Keypad 6","Keypad 7","Keypad 8","Keypad 9","Keypad 0","Keypad .",null,"Application","Power","Keypad =","F13","F14","F15","F16","F17","F18","F19","F20","F21","F22","F23","F24","Execute","Help","Menu","Select","Stop","Again","Undo","Cut","Copy","Paste","Find","Mute","VolumeUp","VolumeDown",null,null,null,"Keypad ,","Keypad = (AS400)",null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,"AltErase","SysReq","Cancel","Clear","Prior","Enter","Separator","Out","Oper","Clear / Again","CrSel","ExSel",null,null,null,null,null,null,null,null,null,null,null,"Keypad 00","Keypad 000","ThousandsSeparator","DecimalSeparator","CurrencyUnit","CurrencySubUnit","Keypad (","Keypad )","Keypad {","Keypad }","Keypad Tab","Keypad Backspace","Keypad A","Keypad B","Keypad C","Keypad D","Keypad E","Keypad F","Keypad XOR","Keypad ^","Keypad %","Keypad <","Keypad >","Keypad &","Keypad &&","Keypad |","Keypad ||","Keypad :","Keypad #","Keypad Space","Keypad @","Keypad !","Keypad MemStore","Keypad MemRecall","Keypad MemClear","Keypad MemAdd","Keypad MemSubtract","Keypad MemMultiply","Keypad MemDivide","Keypad +/-","Keypad Clear","Keypad ClearEntry","Keypad Binary","Keypad Octal","Keypad Decimal","Keypad Hexadecimal",null,null,"Left Ctrl","Left Shift","Left Alt","Left Meta","Right Ctrl","Right Shift","Right Alt","Right Meta",null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,"ModeSwitch","AudioNext","AudioPrev","AudioStop","AudioPlay","AudioMute","MediaSelect","WWW","Mail","Calculator","Computer","AC Search","AC Home","AC Back","AC Forward","AC Stop","AC Refresh","AC Bookmarks","BrightnessDown","BrightnessUp","DisplaySwitch","KBDIllumToggle","KBDIllumDown","KBDIllumUp","Eject","Sleep"];
snow_input_Keycodes.unknown = 0;
snow_input_Keycodes.enter = 13;
snow_input_Keycodes.escape = 27;
snow_input_Keycodes.backspace = 8;
snow_input_Keycodes.tab = 9;
snow_input_Keycodes.space = 32;
snow_input_Keycodes.exclaim = 33;
snow_input_Keycodes.quotedbl = 34;
snow_input_Keycodes.hash = 35;
snow_input_Keycodes.percent = 37;
snow_input_Keycodes.dollar = 36;
snow_input_Keycodes.ampersand = 38;
snow_input_Keycodes.quote = 39;
snow_input_Keycodes.leftparen = 40;
snow_input_Keycodes.rightparen = 41;
snow_input_Keycodes.asterisk = 42;
snow_input_Keycodes.plus = 43;
snow_input_Keycodes.comma = 44;
snow_input_Keycodes.minus = 45;
snow_input_Keycodes.period = 46;
snow_input_Keycodes.slash = 47;
snow_input_Keycodes.key_0 = 48;
snow_input_Keycodes.key_1 = 49;
snow_input_Keycodes.key_2 = 50;
snow_input_Keycodes.key_3 = 51;
snow_input_Keycodes.key_4 = 52;
snow_input_Keycodes.key_5 = 53;
snow_input_Keycodes.key_6 = 54;
snow_input_Keycodes.key_7 = 55;
snow_input_Keycodes.key_8 = 56;
snow_input_Keycodes.key_9 = 57;
snow_input_Keycodes.colon = 58;
snow_input_Keycodes.semicolon = 59;
snow_input_Keycodes.less = 60;
snow_input_Keycodes.equals = 61;
snow_input_Keycodes.greater = 62;
snow_input_Keycodes.question = 63;
snow_input_Keycodes.at = 64;
snow_input_Keycodes.leftbracket = 91;
snow_input_Keycodes.backslash = 92;
snow_input_Keycodes.rightbracket = 93;
snow_input_Keycodes.caret = 94;
snow_input_Keycodes.underscore = 95;
snow_input_Keycodes.backquote = 96;
snow_input_Keycodes.key_a = 97;
snow_input_Keycodes.key_b = 98;
snow_input_Keycodes.key_c = 99;
snow_input_Keycodes.key_d = 100;
snow_input_Keycodes.key_e = 101;
snow_input_Keycodes.key_f = 102;
snow_input_Keycodes.key_g = 103;
snow_input_Keycodes.key_h = 104;
snow_input_Keycodes.key_i = 105;
snow_input_Keycodes.key_j = 106;
snow_input_Keycodes.key_k = 107;
snow_input_Keycodes.key_l = 108;
snow_input_Keycodes.key_m = 109;
snow_input_Keycodes.key_n = 110;
snow_input_Keycodes.key_o = 111;
snow_input_Keycodes.key_p = 112;
snow_input_Keycodes.key_q = 113;
snow_input_Keycodes.key_r = 114;
snow_input_Keycodes.key_s = 115;
snow_input_Keycodes.key_t = 116;
snow_input_Keycodes.key_u = 117;
snow_input_Keycodes.key_v = 118;
snow_input_Keycodes.key_w = 119;
snow_input_Keycodes.key_x = 120;
snow_input_Keycodes.key_y = 121;
snow_input_Keycodes.key_z = 122;
snow_input_Keycodes.capslock = snow_input_Keycodes.from_scan(snow_input_Scancodes.capslock);
snow_input_Keycodes.f1 = snow_input_Keycodes.from_scan(snow_input_Scancodes.f1);
snow_input_Keycodes.f2 = snow_input_Keycodes.from_scan(snow_input_Scancodes.f2);
snow_input_Keycodes.f3 = snow_input_Keycodes.from_scan(snow_input_Scancodes.f3);
snow_input_Keycodes.f4 = snow_input_Keycodes.from_scan(snow_input_Scancodes.f4);
snow_input_Keycodes.f5 = snow_input_Keycodes.from_scan(snow_input_Scancodes.f5);
snow_input_Keycodes.f6 = snow_input_Keycodes.from_scan(snow_input_Scancodes.f6);
snow_input_Keycodes.f7 = snow_input_Keycodes.from_scan(snow_input_Scancodes.f7);
snow_input_Keycodes.f8 = snow_input_Keycodes.from_scan(snow_input_Scancodes.f8);
snow_input_Keycodes.f9 = snow_input_Keycodes.from_scan(snow_input_Scancodes.f9);
snow_input_Keycodes.f10 = snow_input_Keycodes.from_scan(snow_input_Scancodes.f10);
snow_input_Keycodes.f11 = snow_input_Keycodes.from_scan(snow_input_Scancodes.f11);
snow_input_Keycodes.f12 = snow_input_Keycodes.from_scan(snow_input_Scancodes.f12);
snow_input_Keycodes.printscreen = snow_input_Keycodes.from_scan(snow_input_Scancodes.printscreen);
snow_input_Keycodes.scrolllock = snow_input_Keycodes.from_scan(snow_input_Scancodes.scrolllock);
snow_input_Keycodes.pause = snow_input_Keycodes.from_scan(snow_input_Scancodes.pause);
snow_input_Keycodes.insert = snow_input_Keycodes.from_scan(snow_input_Scancodes.insert);
snow_input_Keycodes.home = snow_input_Keycodes.from_scan(snow_input_Scancodes.home);
snow_input_Keycodes.pageup = snow_input_Keycodes.from_scan(snow_input_Scancodes.pageup);
snow_input_Keycodes["delete"] = 127;
snow_input_Keycodes.end = snow_input_Keycodes.from_scan(snow_input_Scancodes.end);
snow_input_Keycodes.pagedown = snow_input_Keycodes.from_scan(snow_input_Scancodes.pagedown);
snow_input_Keycodes.right = snow_input_Keycodes.from_scan(snow_input_Scancodes.right);
snow_input_Keycodes.left = snow_input_Keycodes.from_scan(snow_input_Scancodes.left);
snow_input_Keycodes.down = snow_input_Keycodes.from_scan(snow_input_Scancodes.down);
snow_input_Keycodes.up = snow_input_Keycodes.from_scan(snow_input_Scancodes.up);
snow_input_Keycodes.numlockclear = snow_input_Keycodes.from_scan(snow_input_Scancodes.numlockclear);
snow_input_Keycodes.kp_divide = snow_input_Keycodes.from_scan(snow_input_Scancodes.kp_divide);
snow_input_Keycodes.kp_multiply = snow_input_Keycodes.from_scan(snow_input_Scancodes.kp_multiply);
snow_input_Keycodes.kp_minus = snow_input_Keycodes.from_scan(snow_input_Scancodes.kp_minus);
snow_input_Keycodes.kp_plus = snow_input_Keycodes.from_scan(snow_input_Scancodes.kp_plus);
snow_input_Keycodes.kp_enter = snow_input_Keycodes.from_scan(snow_input_Scancodes.kp_enter);
snow_input_Keycodes.kp_1 = snow_input_Keycodes.from_scan(snow_input_Scancodes.kp_1);
snow_input_Keycodes.kp_2 = snow_input_Keycodes.from_scan(snow_input_Scancodes.kp_2);
snow_input_Keycodes.kp_3 = snow_input_Keycodes.from_scan(snow_input_Scancodes.kp_3);
snow_input_Keycodes.kp_4 = snow_input_Keycodes.from_scan(snow_input_Scancodes.kp_4);
snow_input_Keycodes.kp_5 = snow_input_Keycodes.from_scan(snow_input_Scancodes.kp_5);
snow_input_Keycodes.kp_6 = snow_input_Keycodes.from_scan(snow_input_Scancodes.kp_6);
snow_input_Keycodes.kp_7 = snow_input_Keycodes.from_scan(snow_input_Scancodes.kp_7);
snow_input_Keycodes.kp_8 = snow_input_Keycodes.from_scan(snow_input_Scancodes.kp_8);
snow_input_Keycodes.kp_9 = snow_input_Keycodes.from_scan(snow_input_Scancodes.kp_9);
snow_input_Keycodes.kp_0 = snow_input_Keycodes.from_scan(snow_input_Scancodes.kp_0);
snow_input_Keycodes.kp_period = snow_input_Keycodes.from_scan(snow_input_Scancodes.kp_period);
snow_input_Keycodes.application = snow_input_Keycodes.from_scan(snow_input_Scancodes.application);
snow_input_Keycodes.power = snow_input_Keycodes.from_scan(snow_input_Scancodes.power);
snow_input_Keycodes.kp_equals = snow_input_Keycodes.from_scan(snow_input_Scancodes.kp_equals);
snow_input_Keycodes.f13 = snow_input_Keycodes.from_scan(snow_input_Scancodes.f13);
snow_input_Keycodes.f14 = snow_input_Keycodes.from_scan(snow_input_Scancodes.f14);
snow_input_Keycodes.f15 = snow_input_Keycodes.from_scan(snow_input_Scancodes.f15);
snow_input_Keycodes.f16 = snow_input_Keycodes.from_scan(snow_input_Scancodes.f16);
snow_input_Keycodes.f17 = snow_input_Keycodes.from_scan(snow_input_Scancodes.f17);
snow_input_Keycodes.f18 = snow_input_Keycodes.from_scan(snow_input_Scancodes.f18);
snow_input_Keycodes.f19 = snow_input_Keycodes.from_scan(snow_input_Scancodes.f19);
snow_input_Keycodes.f20 = snow_input_Keycodes.from_scan(snow_input_Scancodes.f20);
snow_input_Keycodes.f21 = snow_input_Keycodes.from_scan(snow_input_Scancodes.f21);
snow_input_Keycodes.f22 = snow_input_Keycodes.from_scan(snow_input_Scancodes.f22);
snow_input_Keycodes.f23 = snow_input_Keycodes.from_scan(snow_input_Scancodes.f23);
snow_input_Keycodes.f24 = snow_input_Keycodes.from_scan(snow_input_Scancodes.f24);
snow_input_Keycodes.execute = snow_input_Keycodes.from_scan(snow_input_Scancodes.execute);
snow_input_Keycodes.help = snow_input_Keycodes.from_scan(snow_input_Scancodes.help);
snow_input_Keycodes.menu = snow_input_Keycodes.from_scan(snow_input_Scancodes.menu);
snow_input_Keycodes.select = snow_input_Keycodes.from_scan(snow_input_Scancodes.select);
snow_input_Keycodes.stop = snow_input_Keycodes.from_scan(snow_input_Scancodes.stop);
snow_input_Keycodes.again = snow_input_Keycodes.from_scan(snow_input_Scancodes.again);
snow_input_Keycodes.undo = snow_input_Keycodes.from_scan(snow_input_Scancodes.undo);
snow_input_Keycodes.cut = snow_input_Keycodes.from_scan(snow_input_Scancodes.cut);
snow_input_Keycodes.copy = snow_input_Keycodes.from_scan(snow_input_Scancodes.copy);
snow_input_Keycodes.paste = snow_input_Keycodes.from_scan(snow_input_Scancodes.paste);
snow_input_Keycodes.find = snow_input_Keycodes.from_scan(snow_input_Scancodes.find);
snow_input_Keycodes.mute = snow_input_Keycodes.from_scan(snow_input_Scancodes.mute);
snow_input_Keycodes.volumeup = snow_input_Keycodes.from_scan(snow_input_Scancodes.volumeup);
snow_input_Keycodes.volumedown = snow_input_Keycodes.from_scan(snow_input_Scancodes.volumedown);
snow_input_Keycodes.kp_comma = snow_input_Keycodes.from_scan(snow_input_Scancodes.kp_comma);
snow_input_Keycodes.kp_equalsas400 = snow_input_Keycodes.from_scan(snow_input_Scancodes.kp_equalsas400);
snow_input_Keycodes.alterase = snow_input_Keycodes.from_scan(snow_input_Scancodes.alterase);
snow_input_Keycodes.sysreq = snow_input_Keycodes.from_scan(snow_input_Scancodes.sysreq);
snow_input_Keycodes.cancel = snow_input_Keycodes.from_scan(snow_input_Scancodes.cancel);
snow_input_Keycodes.clear = snow_input_Keycodes.from_scan(snow_input_Scancodes.clear);
snow_input_Keycodes.prior = snow_input_Keycodes.from_scan(snow_input_Scancodes.prior);
snow_input_Keycodes.return2 = snow_input_Keycodes.from_scan(snow_input_Scancodes.return2);
snow_input_Keycodes.separator = snow_input_Keycodes.from_scan(snow_input_Scancodes.separator);
snow_input_Keycodes.out = snow_input_Keycodes.from_scan(snow_input_Scancodes.out);
snow_input_Keycodes.oper = snow_input_Keycodes.from_scan(snow_input_Scancodes.oper);
snow_input_Keycodes.clearagain = snow_input_Keycodes.from_scan(snow_input_Scancodes.clearagain);
snow_input_Keycodes.crsel = snow_input_Keycodes.from_scan(snow_input_Scancodes.crsel);
snow_input_Keycodes.exsel = snow_input_Keycodes.from_scan(snow_input_Scancodes.exsel);
snow_input_Keycodes.kp_00 = snow_input_Keycodes.from_scan(snow_input_Scancodes.kp_00);
snow_input_Keycodes.kp_000 = snow_input_Keycodes.from_scan(snow_input_Scancodes.kp_000);
snow_input_Keycodes.thousandsseparator = snow_input_Keycodes.from_scan(snow_input_Scancodes.thousandsseparator);
snow_input_Keycodes.decimalseparator = snow_input_Keycodes.from_scan(snow_input_Scancodes.decimalseparator);
snow_input_Keycodes.currencyunit = snow_input_Keycodes.from_scan(snow_input_Scancodes.currencyunit);
snow_input_Keycodes.currencysubunit = snow_input_Keycodes.from_scan(snow_input_Scancodes.currencysubunit);
snow_input_Keycodes.kp_leftparen = snow_input_Keycodes.from_scan(snow_input_Scancodes.kp_leftparen);
snow_input_Keycodes.kp_rightparen = snow_input_Keycodes.from_scan(snow_input_Scancodes.kp_rightparen);
snow_input_Keycodes.kp_leftbrace = snow_input_Keycodes.from_scan(snow_input_Scancodes.kp_leftbrace);
snow_input_Keycodes.kp_rightbrace = snow_input_Keycodes.from_scan(snow_input_Scancodes.kp_rightbrace);
snow_input_Keycodes.kp_tab = snow_input_Keycodes.from_scan(snow_input_Scancodes.kp_tab);
snow_input_Keycodes.kp_backspace = snow_input_Keycodes.from_scan(snow_input_Scancodes.kp_backspace);
snow_input_Keycodes.kp_a = snow_input_Keycodes.from_scan(snow_input_Scancodes.kp_a);
snow_input_Keycodes.kp_b = snow_input_Keycodes.from_scan(snow_input_Scancodes.kp_b);
snow_input_Keycodes.kp_c = snow_input_Keycodes.from_scan(snow_input_Scancodes.kp_c);
snow_input_Keycodes.kp_d = snow_input_Keycodes.from_scan(snow_input_Scancodes.kp_d);
snow_input_Keycodes.kp_e = snow_input_Keycodes.from_scan(snow_input_Scancodes.kp_e);
snow_input_Keycodes.kp_f = snow_input_Keycodes.from_scan(snow_input_Scancodes.kp_f);
snow_input_Keycodes.kp_xor = snow_input_Keycodes.from_scan(snow_input_Scancodes.kp_xor);
snow_input_Keycodes.kp_power = snow_input_Keycodes.from_scan(snow_input_Scancodes.kp_power);
snow_input_Keycodes.kp_percent = snow_input_Keycodes.from_scan(snow_input_Scancodes.kp_percent);
snow_input_Keycodes.kp_less = snow_input_Keycodes.from_scan(snow_input_Scancodes.kp_less);
snow_input_Keycodes.kp_greater = snow_input_Keycodes.from_scan(snow_input_Scancodes.kp_greater);
snow_input_Keycodes.kp_ampersand = snow_input_Keycodes.from_scan(snow_input_Scancodes.kp_ampersand);
snow_input_Keycodes.kp_dblampersand = snow_input_Keycodes.from_scan(snow_input_Scancodes.kp_dblampersand);
snow_input_Keycodes.kp_verticalbar = snow_input_Keycodes.from_scan(snow_input_Scancodes.kp_verticalbar);
snow_input_Keycodes.kp_dblverticalbar = snow_input_Keycodes.from_scan(snow_input_Scancodes.kp_dblverticalbar);
snow_input_Keycodes.kp_colon = snow_input_Keycodes.from_scan(snow_input_Scancodes.kp_colon);
snow_input_Keycodes.kp_hash = snow_input_Keycodes.from_scan(snow_input_Scancodes.kp_hash);
snow_input_Keycodes.kp_space = snow_input_Keycodes.from_scan(snow_input_Scancodes.kp_space);
snow_input_Keycodes.kp_at = snow_input_Keycodes.from_scan(snow_input_Scancodes.kp_at);
snow_input_Keycodes.kp_exclam = snow_input_Keycodes.from_scan(snow_input_Scancodes.kp_exclam);
snow_input_Keycodes.kp_memstore = snow_input_Keycodes.from_scan(snow_input_Scancodes.kp_memstore);
snow_input_Keycodes.kp_memrecall = snow_input_Keycodes.from_scan(snow_input_Scancodes.kp_memrecall);
snow_input_Keycodes.kp_memclear = snow_input_Keycodes.from_scan(snow_input_Scancodes.kp_memclear);
snow_input_Keycodes.kp_memadd = snow_input_Keycodes.from_scan(snow_input_Scancodes.kp_memadd);
snow_input_Keycodes.kp_memsubtract = snow_input_Keycodes.from_scan(snow_input_Scancodes.kp_memsubtract);
snow_input_Keycodes.kp_memmultiply = snow_input_Keycodes.from_scan(snow_input_Scancodes.kp_memmultiply);
snow_input_Keycodes.kp_memdivide = snow_input_Keycodes.from_scan(snow_input_Scancodes.kp_memdivide);
snow_input_Keycodes.kp_plusminus = snow_input_Keycodes.from_scan(snow_input_Scancodes.kp_plusminus);
snow_input_Keycodes.kp_clear = snow_input_Keycodes.from_scan(snow_input_Scancodes.kp_clear);
snow_input_Keycodes.kp_clearentry = snow_input_Keycodes.from_scan(snow_input_Scancodes.kp_clearentry);
snow_input_Keycodes.kp_binary = snow_input_Keycodes.from_scan(snow_input_Scancodes.kp_binary);
snow_input_Keycodes.kp_octal = snow_input_Keycodes.from_scan(snow_input_Scancodes.kp_octal);
snow_input_Keycodes.kp_decimal = snow_input_Keycodes.from_scan(snow_input_Scancodes.kp_decimal);
snow_input_Keycodes.kp_hexadecimal = snow_input_Keycodes.from_scan(snow_input_Scancodes.kp_hexadecimal);
snow_input_Keycodes.lctrl = snow_input_Keycodes.from_scan(snow_input_Scancodes.lctrl);
snow_input_Keycodes.lshift = snow_input_Keycodes.from_scan(snow_input_Scancodes.lshift);
snow_input_Keycodes.lalt = snow_input_Keycodes.from_scan(snow_input_Scancodes.lalt);
snow_input_Keycodes.lmeta = snow_input_Keycodes.from_scan(snow_input_Scancodes.lmeta);
snow_input_Keycodes.rctrl = snow_input_Keycodes.from_scan(snow_input_Scancodes.rctrl);
snow_input_Keycodes.rshift = snow_input_Keycodes.from_scan(snow_input_Scancodes.rshift);
snow_input_Keycodes.ralt = snow_input_Keycodes.from_scan(snow_input_Scancodes.ralt);
snow_input_Keycodes.rmeta = snow_input_Keycodes.from_scan(snow_input_Scancodes.rmeta);
snow_input_Keycodes.mode = snow_input_Keycodes.from_scan(snow_input_Scancodes.mode);
snow_input_Keycodes.audionext = snow_input_Keycodes.from_scan(snow_input_Scancodes.audionext);
snow_input_Keycodes.audioprev = snow_input_Keycodes.from_scan(snow_input_Scancodes.audioprev);
snow_input_Keycodes.audiostop = snow_input_Keycodes.from_scan(snow_input_Scancodes.audiostop);
snow_input_Keycodes.audioplay = snow_input_Keycodes.from_scan(snow_input_Scancodes.audioplay);
snow_input_Keycodes.audiomute = snow_input_Keycodes.from_scan(snow_input_Scancodes.audiomute);
snow_input_Keycodes.mediaselect = snow_input_Keycodes.from_scan(snow_input_Scancodes.mediaselect);
snow_input_Keycodes.www = snow_input_Keycodes.from_scan(snow_input_Scancodes.www);
snow_input_Keycodes.mail = snow_input_Keycodes.from_scan(snow_input_Scancodes.mail);
snow_input_Keycodes.calculator = snow_input_Keycodes.from_scan(snow_input_Scancodes.calculator);
snow_input_Keycodes.computer = snow_input_Keycodes.from_scan(snow_input_Scancodes.computer);
snow_input_Keycodes.ac_search = snow_input_Keycodes.from_scan(snow_input_Scancodes.ac_search);
snow_input_Keycodes.ac_home = snow_input_Keycodes.from_scan(snow_input_Scancodes.ac_home);
snow_input_Keycodes.ac_back = snow_input_Keycodes.from_scan(snow_input_Scancodes.ac_back);
snow_input_Keycodes.ac_forward = snow_input_Keycodes.from_scan(snow_input_Scancodes.ac_forward);
snow_input_Keycodes.ac_stop = snow_input_Keycodes.from_scan(snow_input_Scancodes.ac_stop);
snow_input_Keycodes.ac_refresh = snow_input_Keycodes.from_scan(snow_input_Scancodes.ac_refresh);
snow_input_Keycodes.ac_bookmarks = snow_input_Keycodes.from_scan(snow_input_Scancodes.ac_bookmarks);
snow_input_Keycodes.brightnessdown = snow_input_Keycodes.from_scan(snow_input_Scancodes.brightnessdown);
snow_input_Keycodes.brightnessup = snow_input_Keycodes.from_scan(snow_input_Scancodes.brightnessup);
snow_input_Keycodes.displayswitch = snow_input_Keycodes.from_scan(snow_input_Scancodes.displayswitch);
snow_input_Keycodes.kbdillumtoggle = snow_input_Keycodes.from_scan(snow_input_Scancodes.kbdillumtoggle);
snow_input_Keycodes.kbdillumdown = snow_input_Keycodes.from_scan(snow_input_Scancodes.kbdillumdown);
snow_input_Keycodes.kbdillumup = snow_input_Keycodes.from_scan(snow_input_Scancodes.kbdillumup);
snow_input_Keycodes.eject = snow_input_Keycodes.from_scan(snow_input_Scancodes.eject);
snow_input_Keycodes.sleep = snow_input_Keycodes.from_scan(snow_input_Scancodes.sleep);
snow_platform_web_input_DOMKeys.dom_shift = 16;
snow_platform_web_input_DOMKeys.dom_ctrl = 17;
snow_platform_web_input_DOMKeys.dom_alt = 18;
snow_platform_web_input_DOMKeys.dom_capslock = 20;
snow_platform_web_input_DOMKeys.dom_pageup = 33;
snow_platform_web_input_DOMKeys.dom_pagedown = 34;
snow_platform_web_input_DOMKeys.dom_end = 35;
snow_platform_web_input_DOMKeys.dom_home = 36;
snow_platform_web_input_DOMKeys.dom_left = 37;
snow_platform_web_input_DOMKeys.dom_up = 38;
snow_platform_web_input_DOMKeys.dom_right = 39;
snow_platform_web_input_DOMKeys.dom_down = 40;
snow_platform_web_input_DOMKeys.dom_printscr = 44;
snow_platform_web_input_DOMKeys.dom_insert = 45;
snow_platform_web_input_DOMKeys.dom_delete = 46;
snow_platform_web_input_DOMKeys.dom_lmeta = 91;
snow_platform_web_input_DOMKeys.dom_rmeta = 93;
snow_platform_web_input_DOMKeys.dom_kp_0 = 96;
snow_platform_web_input_DOMKeys.dom_kp_1 = 97;
snow_platform_web_input_DOMKeys.dom_kp_2 = 98;
snow_platform_web_input_DOMKeys.dom_kp_3 = 99;
snow_platform_web_input_DOMKeys.dom_kp_4 = 100;
snow_platform_web_input_DOMKeys.dom_kp_5 = 101;
snow_platform_web_input_DOMKeys.dom_kp_6 = 102;
snow_platform_web_input_DOMKeys.dom_kp_7 = 103;
snow_platform_web_input_DOMKeys.dom_kp_8 = 104;
snow_platform_web_input_DOMKeys.dom_kp_9 = 105;
snow_platform_web_input_DOMKeys.dom_kp_multiply = 106;
snow_platform_web_input_DOMKeys.dom_kp_plus = 107;
snow_platform_web_input_DOMKeys.dom_kp_minus = 109;
snow_platform_web_input_DOMKeys.dom_kp_decimal = 110;
snow_platform_web_input_DOMKeys.dom_kp_divide = 111;
snow_platform_web_input_DOMKeys.dom_kp_numlock = 144;
snow_platform_web_input_DOMKeys.dom_f1 = 112;
snow_platform_web_input_DOMKeys.dom_f2 = 113;
snow_platform_web_input_DOMKeys.dom_f3 = 114;
snow_platform_web_input_DOMKeys.dom_f4 = 115;
snow_platform_web_input_DOMKeys.dom_f5 = 116;
snow_platform_web_input_DOMKeys.dom_f6 = 117;
snow_platform_web_input_DOMKeys.dom_f7 = 118;
snow_platform_web_input_DOMKeys.dom_f8 = 119;
snow_platform_web_input_DOMKeys.dom_f9 = 120;
snow_platform_web_input_DOMKeys.dom_f10 = 121;
snow_platform_web_input_DOMKeys.dom_f11 = 122;
snow_platform_web_input_DOMKeys.dom_f12 = 123;
snow_platform_web_input_DOMKeys.dom_f13 = 124;
snow_platform_web_input_DOMKeys.dom_f14 = 125;
snow_platform_web_input_DOMKeys.dom_f15 = 126;
snow_platform_web_input_DOMKeys.dom_f16 = 127;
snow_platform_web_input_DOMKeys.dom_f17 = 128;
snow_platform_web_input_DOMKeys.dom_f18 = 129;
snow_platform_web_input_DOMKeys.dom_f19 = 130;
snow_platform_web_input_DOMKeys.dom_f20 = 131;
snow_platform_web_input_DOMKeys.dom_f21 = 132;
snow_platform_web_input_DOMKeys.dom_f22 = 133;
snow_platform_web_input_DOMKeys.dom_f23 = 134;
snow_platform_web_input_DOMKeys.dom_f24 = 135;
snow_platform_web_input_DOMKeys.dom_caret = 160;
snow_platform_web_input_DOMKeys.dom_exclaim = 161;
snow_platform_web_input_DOMKeys.dom_quotedbl = 162;
snow_platform_web_input_DOMKeys.dom_hash = 163;
snow_platform_web_input_DOMKeys.dom_dollar = 164;
snow_platform_web_input_DOMKeys.dom_percent = 165;
snow_platform_web_input_DOMKeys.dom_ampersand = 166;
snow_platform_web_input_DOMKeys.dom_underscore = 167;
snow_platform_web_input_DOMKeys.dom_leftparen = 168;
snow_platform_web_input_DOMKeys.dom_rightparen = 169;
snow_platform_web_input_DOMKeys.dom_asterisk = 170;
snow_platform_web_input_DOMKeys.dom_plus = 171;
snow_platform_web_input_DOMKeys.dom_pipe = 172;
snow_platform_web_input_DOMKeys.dom_minus = 173;
snow_platform_web_input_DOMKeys.dom_leftbrace = 174;
snow_platform_web_input_DOMKeys.dom_rightbrace = 175;
snow_platform_web_input_DOMKeys.dom_tilde = 176;
snow_platform_web_input_DOMKeys.dom_audiomute = 181;
snow_platform_web_input_DOMKeys.dom_volumedown = 182;
snow_platform_web_input_DOMKeys.dom_volumeup = 183;
snow_platform_web_input_DOMKeys.dom_comma = 188;
snow_platform_web_input_DOMKeys.dom_period = 190;
snow_platform_web_input_DOMKeys.dom_slash = 191;
snow_platform_web_input_DOMKeys.dom_backquote = 192;
snow_platform_web_input_DOMKeys.dom_leftbracket = 219;
snow_platform_web_input_DOMKeys.dom_rightbracket = 221;
snow_platform_web_input_DOMKeys.dom_backslash = 220;
snow_platform_web_input_DOMKeys.dom_quote = 222;
snow_platform_web_input_DOMKeys.dom_meta = 224;
snow_platform_web_input_InputSystem._keypress_blacklist = [snow_input_Keycodes.backspace,snow_input_Keycodes.enter];
snow_platform_web_render_opengl_GL.DEPTH_BUFFER_BIT = 256;
snow_platform_web_render_opengl_GL.STENCIL_BUFFER_BIT = 1024;
snow_platform_web_render_opengl_GL.COLOR_BUFFER_BIT = 16384;
snow_platform_web_render_opengl_GL.POINTS = 0;
snow_platform_web_render_opengl_GL.LINES = 1;
snow_platform_web_render_opengl_GL.LINE_LOOP = 2;
snow_platform_web_render_opengl_GL.LINE_STRIP = 3;
snow_platform_web_render_opengl_GL.TRIANGLES = 4;
snow_platform_web_render_opengl_GL.TRIANGLE_STRIP = 5;
snow_platform_web_render_opengl_GL.TRIANGLE_FAN = 6;
snow_platform_web_render_opengl_GL.ZERO = 0;
snow_platform_web_render_opengl_GL.ONE = 1;
snow_platform_web_render_opengl_GL.SRC_COLOR = 768;
snow_platform_web_render_opengl_GL.ONE_MINUS_SRC_COLOR = 769;
snow_platform_web_render_opengl_GL.SRC_ALPHA = 770;
snow_platform_web_render_opengl_GL.ONE_MINUS_SRC_ALPHA = 771;
snow_platform_web_render_opengl_GL.DST_ALPHA = 772;
snow_platform_web_render_opengl_GL.ONE_MINUS_DST_ALPHA = 773;
snow_platform_web_render_opengl_GL.DST_COLOR = 774;
snow_platform_web_render_opengl_GL.ONE_MINUS_DST_COLOR = 775;
snow_platform_web_render_opengl_GL.SRC_ALPHA_SATURATE = 776;
snow_platform_web_render_opengl_GL.FUNC_ADD = 32774;
snow_platform_web_render_opengl_GL.BLEND_EQUATION = 32777;
snow_platform_web_render_opengl_GL.BLEND_EQUATION_RGB = 32777;
snow_platform_web_render_opengl_GL.BLEND_EQUATION_ALPHA = 34877;
snow_platform_web_render_opengl_GL.FUNC_SUBTRACT = 32778;
snow_platform_web_render_opengl_GL.FUNC_REVERSE_SUBTRACT = 32779;
snow_platform_web_render_opengl_GL.BLEND_DST_RGB = 32968;
snow_platform_web_render_opengl_GL.BLEND_SRC_RGB = 32969;
snow_platform_web_render_opengl_GL.BLEND_DST_ALPHA = 32970;
snow_platform_web_render_opengl_GL.BLEND_SRC_ALPHA = 32971;
snow_platform_web_render_opengl_GL.CONSTANT_COLOR = 32769;
snow_platform_web_render_opengl_GL.ONE_MINUS_CONSTANT_COLOR = 32770;
snow_platform_web_render_opengl_GL.CONSTANT_ALPHA = 32771;
snow_platform_web_render_opengl_GL.ONE_MINUS_CONSTANT_ALPHA = 32772;
snow_platform_web_render_opengl_GL.BLEND_COLOR = 32773;
snow_platform_web_render_opengl_GL.ARRAY_BUFFER = 34962;
snow_platform_web_render_opengl_GL.ELEMENT_ARRAY_BUFFER = 34963;
snow_platform_web_render_opengl_GL.ARRAY_BUFFER_BINDING = 34964;
snow_platform_web_render_opengl_GL.ELEMENT_ARRAY_BUFFER_BINDING = 34965;
snow_platform_web_render_opengl_GL.STREAM_DRAW = 35040;
snow_platform_web_render_opengl_GL.STATIC_DRAW = 35044;
snow_platform_web_render_opengl_GL.DYNAMIC_DRAW = 35048;
snow_platform_web_render_opengl_GL.BUFFER_SIZE = 34660;
snow_platform_web_render_opengl_GL.BUFFER_USAGE = 34661;
snow_platform_web_render_opengl_GL.CURRENT_VERTEX_ATTRIB = 34342;
snow_platform_web_render_opengl_GL.FRONT = 1028;
snow_platform_web_render_opengl_GL.BACK = 1029;
snow_platform_web_render_opengl_GL.FRONT_AND_BACK = 1032;
snow_platform_web_render_opengl_GL.CULL_FACE = 2884;
snow_platform_web_render_opengl_GL.BLEND = 3042;
snow_platform_web_render_opengl_GL.DITHER = 3024;
snow_platform_web_render_opengl_GL.STENCIL_TEST = 2960;
snow_platform_web_render_opengl_GL.DEPTH_TEST = 2929;
snow_platform_web_render_opengl_GL.SCISSOR_TEST = 3089;
snow_platform_web_render_opengl_GL.POLYGON_OFFSET_FILL = 32823;
snow_platform_web_render_opengl_GL.SAMPLE_ALPHA_TO_COVERAGE = 32926;
snow_platform_web_render_opengl_GL.SAMPLE_COVERAGE = 32928;
snow_platform_web_render_opengl_GL.NO_ERROR = 0;
snow_platform_web_render_opengl_GL.INVALID_ENUM = 1280;
snow_platform_web_render_opengl_GL.INVALID_VALUE = 1281;
snow_platform_web_render_opengl_GL.INVALID_OPERATION = 1282;
snow_platform_web_render_opengl_GL.OUT_OF_MEMORY = 1285;
snow_platform_web_render_opengl_GL.CW = 2304;
snow_platform_web_render_opengl_GL.CCW = 2305;
snow_platform_web_render_opengl_GL.LINE_WIDTH = 2849;
snow_platform_web_render_opengl_GL.ALIASED_POINT_SIZE_RANGE = 33901;
snow_platform_web_render_opengl_GL.ALIASED_LINE_WIDTH_RANGE = 33902;
snow_platform_web_render_opengl_GL.CULL_FACE_MODE = 2885;
snow_platform_web_render_opengl_GL.FRONT_FACE = 2886;
snow_platform_web_render_opengl_GL.DEPTH_RANGE = 2928;
snow_platform_web_render_opengl_GL.DEPTH_WRITEMASK = 2930;
snow_platform_web_render_opengl_GL.DEPTH_CLEAR_VALUE = 2931;
snow_platform_web_render_opengl_GL.DEPTH_FUNC = 2932;
snow_platform_web_render_opengl_GL.STENCIL_CLEAR_VALUE = 2961;
snow_platform_web_render_opengl_GL.STENCIL_FUNC = 2962;
snow_platform_web_render_opengl_GL.STENCIL_FAIL = 2964;
snow_platform_web_render_opengl_GL.STENCIL_PASS_DEPTH_FAIL = 2965;
snow_platform_web_render_opengl_GL.STENCIL_PASS_DEPTH_PASS = 2966;
snow_platform_web_render_opengl_GL.STENCIL_REF = 2967;
snow_platform_web_render_opengl_GL.STENCIL_VALUE_MASK = 2963;
snow_platform_web_render_opengl_GL.STENCIL_WRITEMASK = 2968;
snow_platform_web_render_opengl_GL.STENCIL_BACK_FUNC = 34816;
snow_platform_web_render_opengl_GL.STENCIL_BACK_FAIL = 34817;
snow_platform_web_render_opengl_GL.STENCIL_BACK_PASS_DEPTH_FAIL = 34818;
snow_platform_web_render_opengl_GL.STENCIL_BACK_PASS_DEPTH_PASS = 34819;
snow_platform_web_render_opengl_GL.STENCIL_BACK_REF = 36003;
snow_platform_web_render_opengl_GL.STENCIL_BACK_VALUE_MASK = 36004;
snow_platform_web_render_opengl_GL.STENCIL_BACK_WRITEMASK = 36005;
snow_platform_web_render_opengl_GL.VIEWPORT = 2978;
snow_platform_web_render_opengl_GL.SCISSOR_BOX = 3088;
snow_platform_web_render_opengl_GL.COLOR_CLEAR_VALUE = 3106;
snow_platform_web_render_opengl_GL.COLOR_WRITEMASK = 3107;
snow_platform_web_render_opengl_GL.UNPACK_ALIGNMENT = 3317;
snow_platform_web_render_opengl_GL.PACK_ALIGNMENT = 3333;
snow_platform_web_render_opengl_GL.MAX_TEXTURE_SIZE = 3379;
snow_platform_web_render_opengl_GL.MAX_VIEWPORT_DIMS = 3386;
snow_platform_web_render_opengl_GL.SUBPIXEL_BITS = 3408;
snow_platform_web_render_opengl_GL.RED_BITS = 3410;
snow_platform_web_render_opengl_GL.GREEN_BITS = 3411;
snow_platform_web_render_opengl_GL.BLUE_BITS = 3412;
snow_platform_web_render_opengl_GL.ALPHA_BITS = 3413;
snow_platform_web_render_opengl_GL.DEPTH_BITS = 3414;
snow_platform_web_render_opengl_GL.STENCIL_BITS = 3415;
snow_platform_web_render_opengl_GL.POLYGON_OFFSET_UNITS = 10752;
snow_platform_web_render_opengl_GL.POLYGON_OFFSET_FACTOR = 32824;
snow_platform_web_render_opengl_GL.TEXTURE_BINDING_2D = 32873;
snow_platform_web_render_opengl_GL.SAMPLE_BUFFERS = 32936;
snow_platform_web_render_opengl_GL.SAMPLES = 32937;
snow_platform_web_render_opengl_GL.SAMPLE_COVERAGE_VALUE = 32938;
snow_platform_web_render_opengl_GL.SAMPLE_COVERAGE_INVERT = 32939;
snow_platform_web_render_opengl_GL.COMPRESSED_TEXTURE_FORMATS = 34467;
snow_platform_web_render_opengl_GL.DONT_CARE = 4352;
snow_platform_web_render_opengl_GL.FASTEST = 4353;
snow_platform_web_render_opengl_GL.NICEST = 4354;
snow_platform_web_render_opengl_GL.GENERATE_MIPMAP_HINT = 33170;
snow_platform_web_render_opengl_GL.BYTE = 5120;
snow_platform_web_render_opengl_GL.UNSIGNED_BYTE = 5121;
snow_platform_web_render_opengl_GL.SHORT = 5122;
snow_platform_web_render_opengl_GL.UNSIGNED_SHORT = 5123;
snow_platform_web_render_opengl_GL.INT = 5124;
snow_platform_web_render_opengl_GL.UNSIGNED_INT = 5125;
snow_platform_web_render_opengl_GL.FLOAT = 5126;
snow_platform_web_render_opengl_GL.DEPTH_COMPONENT = 6402;
snow_platform_web_render_opengl_GL.ALPHA = 6406;
snow_platform_web_render_opengl_GL.RGB = 6407;
snow_platform_web_render_opengl_GL.RGBA = 6408;
snow_platform_web_render_opengl_GL.LUMINANCE = 6409;
snow_platform_web_render_opengl_GL.LUMINANCE_ALPHA = 6410;
snow_platform_web_render_opengl_GL.UNSIGNED_SHORT_4_4_4_4 = 32819;
snow_platform_web_render_opengl_GL.UNSIGNED_SHORT_5_5_5_1 = 32820;
snow_platform_web_render_opengl_GL.UNSIGNED_SHORT_5_6_5 = 33635;
snow_platform_web_render_opengl_GL.FRAGMENT_SHADER = 35632;
snow_platform_web_render_opengl_GL.VERTEX_SHADER = 35633;
snow_platform_web_render_opengl_GL.MAX_VERTEX_ATTRIBS = 34921;
snow_platform_web_render_opengl_GL.MAX_VERTEX_UNIFORM_VECTORS = 36347;
snow_platform_web_render_opengl_GL.MAX_VARYING_VECTORS = 36348;
snow_platform_web_render_opengl_GL.MAX_COMBINED_TEXTURE_IMAGE_UNITS = 35661;
snow_platform_web_render_opengl_GL.MAX_VERTEX_TEXTURE_IMAGE_UNITS = 35660;
snow_platform_web_render_opengl_GL.MAX_TEXTURE_IMAGE_UNITS = 34930;
snow_platform_web_render_opengl_GL.MAX_FRAGMENT_UNIFORM_VECTORS = 36349;
snow_platform_web_render_opengl_GL.SHADER_TYPE = 35663;
snow_platform_web_render_opengl_GL.DELETE_STATUS = 35712;
snow_platform_web_render_opengl_GL.LINK_STATUS = 35714;
snow_platform_web_render_opengl_GL.VALIDATE_STATUS = 35715;
snow_platform_web_render_opengl_GL.ATTACHED_SHADERS = 35717;
snow_platform_web_render_opengl_GL.ACTIVE_UNIFORMS = 35718;
snow_platform_web_render_opengl_GL.ACTIVE_ATTRIBUTES = 35721;
snow_platform_web_render_opengl_GL.SHADING_LANGUAGE_VERSION = 35724;
snow_platform_web_render_opengl_GL.CURRENT_PROGRAM = 35725;
snow_platform_web_render_opengl_GL.NEVER = 512;
snow_platform_web_render_opengl_GL.LESS = 513;
snow_platform_web_render_opengl_GL.EQUAL = 514;
snow_platform_web_render_opengl_GL.LEQUAL = 515;
snow_platform_web_render_opengl_GL.GREATER = 516;
snow_platform_web_render_opengl_GL.NOTEQUAL = 517;
snow_platform_web_render_opengl_GL.GEQUAL = 518;
snow_platform_web_render_opengl_GL.ALWAYS = 519;
snow_platform_web_render_opengl_GL.KEEP = 7680;
snow_platform_web_render_opengl_GL.REPLACE = 7681;
snow_platform_web_render_opengl_GL.INCR = 7682;
snow_platform_web_render_opengl_GL.DECR = 7683;
snow_platform_web_render_opengl_GL.INVERT = 5386;
snow_platform_web_render_opengl_GL.INCR_WRAP = 34055;
snow_platform_web_render_opengl_GL.DECR_WRAP = 34056;
snow_platform_web_render_opengl_GL.VENDOR = 7936;
snow_platform_web_render_opengl_GL.RENDERER = 7937;
snow_platform_web_render_opengl_GL.VERSION = 7938;
snow_platform_web_render_opengl_GL.NEAREST = 9728;
snow_platform_web_render_opengl_GL.LINEAR = 9729;
snow_platform_web_render_opengl_GL.NEAREST_MIPMAP_NEAREST = 9984;
snow_platform_web_render_opengl_GL.LINEAR_MIPMAP_NEAREST = 9985;
snow_platform_web_render_opengl_GL.NEAREST_MIPMAP_LINEAR = 9986;
snow_platform_web_render_opengl_GL.LINEAR_MIPMAP_LINEAR = 9987;
snow_platform_web_render_opengl_GL.TEXTURE_MAG_FILTER = 10240;
snow_platform_web_render_opengl_GL.TEXTURE_MIN_FILTER = 10241;
snow_platform_web_render_opengl_GL.TEXTURE_WRAP_S = 10242;
snow_platform_web_render_opengl_GL.TEXTURE_WRAP_T = 10243;
snow_platform_web_render_opengl_GL.TEXTURE_2D = 3553;
snow_platform_web_render_opengl_GL.TEXTURE = 5890;
snow_platform_web_render_opengl_GL.TEXTURE_CUBE_MAP = 34067;
snow_platform_web_render_opengl_GL.TEXTURE_BINDING_CUBE_MAP = 34068;
snow_platform_web_render_opengl_GL.TEXTURE_CUBE_MAP_POSITIVE_X = 34069;
snow_platform_web_render_opengl_GL.TEXTURE_CUBE_MAP_NEGATIVE_X = 34070;
snow_platform_web_render_opengl_GL.TEXTURE_CUBE_MAP_POSITIVE_Y = 34071;
snow_platform_web_render_opengl_GL.TEXTURE_CUBE_MAP_NEGATIVE_Y = 34072;
snow_platform_web_render_opengl_GL.TEXTURE_CUBE_MAP_POSITIVE_Z = 34073;
snow_platform_web_render_opengl_GL.TEXTURE_CUBE_MAP_NEGATIVE_Z = 34074;
snow_platform_web_render_opengl_GL.MAX_CUBE_MAP_TEXTURE_SIZE = 34076;
snow_platform_web_render_opengl_GL.TEXTURE0 = 33984;
snow_platform_web_render_opengl_GL.TEXTURE1 = 33985;
snow_platform_web_render_opengl_GL.TEXTURE2 = 33986;
snow_platform_web_render_opengl_GL.TEXTURE3 = 33987;
snow_platform_web_render_opengl_GL.TEXTURE4 = 33988;
snow_platform_web_render_opengl_GL.TEXTURE5 = 33989;
snow_platform_web_render_opengl_GL.TEXTURE6 = 33990;
snow_platform_web_render_opengl_GL.TEXTURE7 = 33991;
snow_platform_web_render_opengl_GL.TEXTURE8 = 33992;
snow_platform_web_render_opengl_GL.TEXTURE9 = 33993;
snow_platform_web_render_opengl_GL.TEXTURE10 = 33994;
snow_platform_web_render_opengl_GL.TEXTURE11 = 33995;
snow_platform_web_render_opengl_GL.TEXTURE12 = 33996;
snow_platform_web_render_opengl_GL.TEXTURE13 = 33997;
snow_platform_web_render_opengl_GL.TEXTURE14 = 33998;
snow_platform_web_render_opengl_GL.TEXTURE15 = 33999;
snow_platform_web_render_opengl_GL.TEXTURE16 = 34000;
snow_platform_web_render_opengl_GL.TEXTURE17 = 34001;
snow_platform_web_render_opengl_GL.TEXTURE18 = 34002;
snow_platform_web_render_opengl_GL.TEXTURE19 = 34003;
snow_platform_web_render_opengl_GL.TEXTURE20 = 34004;
snow_platform_web_render_opengl_GL.TEXTURE21 = 34005;
snow_platform_web_render_opengl_GL.TEXTURE22 = 34006;
snow_platform_web_render_opengl_GL.TEXTURE23 = 34007;
snow_platform_web_render_opengl_GL.TEXTURE24 = 34008;
snow_platform_web_render_opengl_GL.TEXTURE25 = 34009;
snow_platform_web_render_opengl_GL.TEXTURE26 = 34010;
snow_platform_web_render_opengl_GL.TEXTURE27 = 34011;
snow_platform_web_render_opengl_GL.TEXTURE28 = 34012;
snow_platform_web_render_opengl_GL.TEXTURE29 = 34013;
snow_platform_web_render_opengl_GL.TEXTURE30 = 34014;
snow_platform_web_render_opengl_GL.TEXTURE31 = 34015;
snow_platform_web_render_opengl_GL.ACTIVE_TEXTURE = 34016;
snow_platform_web_render_opengl_GL.REPEAT = 10497;
snow_platform_web_render_opengl_GL.CLAMP_TO_EDGE = 33071;
snow_platform_web_render_opengl_GL.MIRRORED_REPEAT = 33648;
snow_platform_web_render_opengl_GL.FLOAT_VEC2 = 35664;
snow_platform_web_render_opengl_GL.FLOAT_VEC3 = 35665;
snow_platform_web_render_opengl_GL.FLOAT_VEC4 = 35666;
snow_platform_web_render_opengl_GL.INT_VEC2 = 35667;
snow_platform_web_render_opengl_GL.INT_VEC3 = 35668;
snow_platform_web_render_opengl_GL.INT_VEC4 = 35669;
snow_platform_web_render_opengl_GL.BOOL = 35670;
snow_platform_web_render_opengl_GL.BOOL_VEC2 = 35671;
snow_platform_web_render_opengl_GL.BOOL_VEC3 = 35672;
snow_platform_web_render_opengl_GL.BOOL_VEC4 = 35673;
snow_platform_web_render_opengl_GL.FLOAT_MAT2 = 35674;
snow_platform_web_render_opengl_GL.FLOAT_MAT3 = 35675;
snow_platform_web_render_opengl_GL.FLOAT_MAT4 = 35676;
snow_platform_web_render_opengl_GL.SAMPLER_2D = 35678;
snow_platform_web_render_opengl_GL.SAMPLER_CUBE = 35680;
snow_platform_web_render_opengl_GL.VERTEX_ATTRIB_ARRAY_ENABLED = 34338;
snow_platform_web_render_opengl_GL.VERTEX_ATTRIB_ARRAY_SIZE = 34339;
snow_platform_web_render_opengl_GL.VERTEX_ATTRIB_ARRAY_STRIDE = 34340;
snow_platform_web_render_opengl_GL.VERTEX_ATTRIB_ARRAY_TYPE = 34341;
snow_platform_web_render_opengl_GL.VERTEX_ATTRIB_ARRAY_NORMALIZED = 34922;
snow_platform_web_render_opengl_GL.VERTEX_ATTRIB_ARRAY_POINTER = 34373;
snow_platform_web_render_opengl_GL.VERTEX_ATTRIB_ARRAY_BUFFER_BINDING = 34975;
snow_platform_web_render_opengl_GL.VERTEX_PROGRAM_POINT_SIZE = 34370;
snow_platform_web_render_opengl_GL.POINT_SPRITE = 34913;
snow_platform_web_render_opengl_GL.COMPILE_STATUS = 35713;
snow_platform_web_render_opengl_GL.LOW_FLOAT = 36336;
snow_platform_web_render_opengl_GL.MEDIUM_FLOAT = 36337;
snow_platform_web_render_opengl_GL.HIGH_FLOAT = 36338;
snow_platform_web_render_opengl_GL.LOW_INT = 36339;
snow_platform_web_render_opengl_GL.MEDIUM_INT = 36340;
snow_platform_web_render_opengl_GL.HIGH_INT = 36341;
snow_platform_web_render_opengl_GL.FRAMEBUFFER = 36160;
snow_platform_web_render_opengl_GL.RENDERBUFFER = 36161;
snow_platform_web_render_opengl_GL.RGBA4 = 32854;
snow_platform_web_render_opengl_GL.RGB5_A1 = 32855;
snow_platform_web_render_opengl_GL.RGB565 = 36194;
snow_platform_web_render_opengl_GL.DEPTH_COMPONENT16 = 33189;
snow_platform_web_render_opengl_GL.STENCIL_INDEX = 6401;
snow_platform_web_render_opengl_GL.STENCIL_INDEX8 = 36168;
snow_platform_web_render_opengl_GL.DEPTH_STENCIL = 34041;
snow_platform_web_render_opengl_GL.RENDERBUFFER_WIDTH = 36162;
snow_platform_web_render_opengl_GL.RENDERBUFFER_HEIGHT = 36163;
snow_platform_web_render_opengl_GL.RENDERBUFFER_INTERNAL_FORMAT = 36164;
snow_platform_web_render_opengl_GL.RENDERBUFFER_RED_SIZE = 36176;
snow_platform_web_render_opengl_GL.RENDERBUFFER_GREEN_SIZE = 36177;
snow_platform_web_render_opengl_GL.RENDERBUFFER_BLUE_SIZE = 36178;
snow_platform_web_render_opengl_GL.RENDERBUFFER_ALPHA_SIZE = 36179;
snow_platform_web_render_opengl_GL.RENDERBUFFER_DEPTH_SIZE = 36180;
snow_platform_web_render_opengl_GL.RENDERBUFFER_STENCIL_SIZE = 36181;
snow_platform_web_render_opengl_GL.FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE = 36048;
snow_platform_web_render_opengl_GL.FRAMEBUFFER_ATTACHMENT_OBJECT_NAME = 36049;
snow_platform_web_render_opengl_GL.FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL = 36050;
snow_platform_web_render_opengl_GL.FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE = 36051;
snow_platform_web_render_opengl_GL.COLOR_ATTACHMENT0 = 36064;
snow_platform_web_render_opengl_GL.DEPTH_ATTACHMENT = 36096;
snow_platform_web_render_opengl_GL.STENCIL_ATTACHMENT = 36128;
snow_platform_web_render_opengl_GL.DEPTH_STENCIL_ATTACHMENT = 33306;
snow_platform_web_render_opengl_GL.NONE = 0;
snow_platform_web_render_opengl_GL.FRAMEBUFFER_COMPLETE = 36053;
snow_platform_web_render_opengl_GL.FRAMEBUFFER_INCOMPLETE_ATTACHMENT = 36054;
snow_platform_web_render_opengl_GL.FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT = 36055;
snow_platform_web_render_opengl_GL.FRAMEBUFFER_INCOMPLETE_DIMENSIONS = 36057;
snow_platform_web_render_opengl_GL.FRAMEBUFFER_UNSUPPORTED = 36061;
snow_platform_web_render_opengl_GL.FRAMEBUFFER_BINDING = 36006;
snow_platform_web_render_opengl_GL.RENDERBUFFER_BINDING = 36007;
snow_platform_web_render_opengl_GL.MAX_RENDERBUFFER_SIZE = 34024;
snow_platform_web_render_opengl_GL.INVALID_FRAMEBUFFER_OPERATION = 1286;
snow_platform_web_render_opengl_GL.UNPACK_FLIP_Y_WEBGL = 37440;
snow_platform_web_render_opengl_GL.UNPACK_PREMULTIPLY_ALPHA_WEBGL = 37441;
snow_platform_web_render_opengl_GL.CONTEXT_LOST_WEBGL = 37442;
snow_platform_web_render_opengl_GL.UNPACK_COLORSPACE_CONVERSION_WEBGL = 37443;
snow_platform_web_render_opengl_GL.BROWSER_DEFAULT_WEBGL = 37444;
snow_utils_Promises.calls = [];
snow_utils_Promises.defers = [];
snow_utils_Timer.running_timers = [];
snow_utils_format_tools__$InflateImpl_Window.SIZE = 32768;
snow_utils_format_tools__$InflateImpl_Window.BUFSIZE = 65536;
snow_utils_format_tools_InflateImpl.LEN_EXTRA_BITS_TBL = [0,0,0,0,0,0,0,0,1,1,1,1,2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,0,-1,-1];
snow_utils_format_tools_InflateImpl.LEN_BASE_VAL_TBL = [3,4,5,6,7,8,9,10,11,13,15,17,19,23,27,31,35,43,51,59,67,83,99,115,131,163,195,227,258];
snow_utils_format_tools_InflateImpl.DIST_EXTRA_BITS_TBL = [0,0,0,0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10,11,11,12,12,13,13,-1,-1];
snow_utils_format_tools_InflateImpl.DIST_BASE_VAL_TBL = [1,2,3,4,5,7,9,13,17,25,33,49,65,97,129,193,257,385,513,769,1025,1537,2049,3073,4097,6145,8193,12289,16385,24577];
snow_utils_format_tools_InflateImpl.CODE_LENGTHS_POS = [16,17,18,0,8,7,9,6,10,5,11,4,12,3,13,2,14,1,15];
LuxeApp.main();
})(typeof console != "undefined" ? console : {log:function(){}});