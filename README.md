hxDaedalus-Luxe-Examples
==============================

This is the [Luxe](http://www.luxeengine.com/) examples repository for the Haxe version of the as3 Daedalus-lib.

https://github.com/hxDaedalus/hxDaedalus-Examples

These examples require the current haxe hxDaedalus library, which can be found here:

https://github.com/hxDaedalus/hxDaedalus

You can view some of the examples:

 - 01-Basics: [web](http://hxdaedalus.github.io/hxDaedalus-luxe-examples/hxDaedalus-Luxe-Examples/01-Basics/bin/web/index.html)
 - 02-FromBitmap: [web](http://hxdaedalus.github.io/hxDaedalus-luxe-examples/hxDaedalus-Luxe-Examples/02-FromBitmap/bin/web/index.html)
 - 03-Pathfinding: [web](http://hxdaedalus.github.io/hxDaedalus-luxe-examples/hxDaedalus-Luxe-Examples/03-Pathfinding/bin/web/index.html)
 - 04-BitmapPathfinding: [web](http://hxdaedalus.github.io/hxDaedalus-luxe-examples/hxDaedalus-Luxe-Examples/04-BitmapPathfinding/bin/web/index.html)
 - 05-GridMaze: [web](http://hxdaedalus.github.io/hxDaedalus-luxe-examples/hxDaedalus-Luxe-Examples/05-GridMaze/bin/web/index.html)
 - 07-MeshExtractionFromBitmap: [web](http://hxdaedalus.github.io/hxDaedalus-luxe-examples/hxDaedalus-Luxe-Examples/07-MeshExtractionFromBitmap/bin/web/index.html)
 
License is MIT.

Setup of Snowkit and hxDaedalus
=================================

1) Install haxe if you don't have latest
http://haxe.org/download/

2) Install git if you don't have git
https://git-scm.com/downloads

2) setup haxelib eg:

haxelib setup
   Please enter haxelib repository path with write access
   Hit enter for default (/usr/lib/haxe/lib)
Path :
   <hit Enter>
   haxelib repository is now /usr/lib/haxe/lib/

3) Install hxcpp

haxelib install hxcpp

4) Install git version of snowkit you can get these in any order.
haxelib git luxe https://github.com/underscorediscovery/luxe.git
haxelib git flow https://github.com/underscorediscovery/flow.git
haxelib git snow https://github.com/underscorediscovery/snow.git

5) Rebuild Snow for required platforms
go into the snow haxelib on mac it would be...

cd /usr/lib/haxeLibrary/snow/git/project

then rebuild for mac ( or windows for windows ).

haxelib run flow run mac

6) Install hxDaedalus from git you need the additional parameters since it's in an src folder.

haxelib git hxDaedalus https://github.com/hxDaedalus/hxDaedalus.git master src

7) Then you can clone this repository to try the examples.

git clone https://github.com/hxDaedalus/hxDaedalus-luxe-examples.git

8) Then you can go into each of the example and try them so on a mac you may want to try the mac and web versions eg: 

cd 04-BitmapPathfinding

haxe flowMac.hxml  

or 

haxe flowWeb.hxml

