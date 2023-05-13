#include <stdio.h>
#include "EasySocket.h"

int main(int argc,char** argv){
    portableSetup();

    EasySocket server;
    EasySocket client;

    //EasySocketInitBuffer(&server,150);
    EasySocketInitDescriptor(&server,0,1);
    EasySocketInitAddr(&server,"192.168.0.25",5000,0);

    EasySocketInitBuffer(&client,150);

    EasySocketBind(&server);
    EasySocketListen(&server,1);

    EasySocketAccept(&server,&client);

    EasySocketSend(&client,"Hello!");
    EasySocketRecive(&client);
    EasySocketSend(&client,"Im good, im the server, by the way!");

    EasySocketClose(&client);
    EasySocketFreeBuffer(&client);

    EasySocketClose(&server);
    //EasySocketFreeBuffer(&server);

    return 0;
}
