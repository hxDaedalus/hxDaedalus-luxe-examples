package lime;


import lime.utils.Assets;


class AssetData {

	private static var initialized:Bool = false;
	
	public static var library = new #if haxe3 Map <String, #else Hash <#end LibraryType> ();
	public static var path = new #if haxe3 Map <String, #else Hash <#end String> ();
	public static var type = new #if haxe3 Map <String, #else Hash <#end AssetType> ();	
	
	public static function initialize():Void {
		
		if (!initialized) {
			
			path.set ("img/galapagosBW.png", "img/galapagosBW.png");
			type.set ("img/galapagosBW.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("img/galapagosColor.png", "img/galapagosColor.png");
			type.set ("img/galapagosColor.png", Reflect.field (AssetType, "image".toUpperCase ()));
			
			
			initialized = true;
			
		} //!initialized
		
	} //initialize
	
	
} //AssetData
