# EasySocket
EasySocket is a simple library to deal with sockets, simplifying the process of building a functional socket application in C.
<br>
### EasySocketClose - ()
Attempts to close the descriptor of a EasySocket
### EasySocketInitDescriptor - (Family,Type)
Attempts to initialize a descriptor of a EasySocket
### EasySocketInitAddr - (IP,Port,Family)
Attempts to initialize the "addr" Structure inside of a EasySocket
### EasySocketInitBuffer - (BufferSize)
Attempts to allocate a char buffer inside a EasySocket
### EasySocketFreeBuffer - ()
Attempts to deallocate a char buffer inside a EasySocket
### EasySocketClearBuffer - ()
Attempts to initialize all the bytes of a buffer, inside a EasySocket, with '\0'
### EasySocketBind - ()
Attempts to bind a EasySocket to a previously defined port
### EasySocketListen - (MaxQueueLength)
Attemps to make a EasySocket Listen to a previously bound port
### EasySocketAccept - (Server,Client)
Attempts to make a "Server" EasySocket accept to a connection, and transfer control to a "Client" EasySocket
