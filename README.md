# EasySocket
EasySocket is a simple library to deal with sockets, simplifying the process of building a functional socket application in C.
<br>
|Function|Parameters|Description|
|-|-|-|
|EasySocketClose|EasySocket*|Attempts to close the descriptor of a EasySocket Structure|
|EasySocketInitDescriptor|EasySocket*,Family(0-1),Type(0-1)|Attempts to initialize a descriptor of a EasySocket Structure|
|EasySocketInitAddr|EasySocket*,IP,Port,Family|Attempts to initialize the "addr" Structure inside of a EasySocket Structure|
