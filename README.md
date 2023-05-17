# EasySocket
EasySocket is a simple library to deal with sockets, simplifying the process of building a functional socket application in C.<br>
```ws2_32```Library is needed to be compiled in windows.
<br>
### EasySocketClose - (EasySocket)
Attempts to close the descriptor of a EasySocket
### EasySocketInitDescriptor - (EasySocket,Family,Type)
Attempts to initialize a descriptor of a EasySocket<br>
|Value|Family|True Family|
|-|-|-|
|0|IPV4|AF_INET|
|1|IPV6|AF_INET6|


|Value|Type|True Type|
|-|-|-|
|0|UDP|SOCK_DGRAM|
|1|TCP|SOCK_STREAM|
### EasySocketInitAddr - (EasySocket,IP,Port,Family)
Attempts to initialize the "addr" Structure inside of a EasySocket<br>
|Value|Family|True Family|
|-|-|-|
|0|IPV4|AF_INET|
|1|IPV6|AF_INET6|<br>
|Value|Type|True Type|
### EasySocketInitBuffer - (EasySocket,BufferSize)
Attempts to allocate a char buffer inside a EasySocket
### EasySocketFreeBuffer - (EasySocket)
Attempts to deallocate a char buffer inside a EasySocket
### EasySocketClearBuffer - (EasySocket)
Attempts to initialize all the bytes of a buffer, inside a EasySocket, with '\0'
### EasySocketBind - (EasySocketServer)
Attempts to bind a EasySocketServer to a previously defined port
### EasySocketListen - (EasySocketServer,MaxQueueLength)
Attemps to make a EasySocketServer Listen to a previously bound port
### EasySocketAccept - (EasySocketServer,EasySocketClient)
Attempts to make a EasySocketServer accept to a connection, and transfer control to a EasySocketClient
### EasySocketConnect - (EasySocketClient)
Attempts to connect a EasySocketClient to a previously listening EasySocketServer
### EasySocketSend - (EasySocket,Message)
Attempts to send the current buffer as a message from a EasySocket, to another previously connected EasySocket<br>
If the message parameter is not NULL,the buffer will be overwritten.
### EasySocketSendUnconnected - (EasySocket,Message)
Attempts to send a message from a EasySocket to another unconnected EasySocket (UDP)
### EasySocketRecive - (EasySocket)
Attempts to make a EasySocket recive a message from another previously connected EasySocket<br>
The message will be stored inside the reciver's buffer
