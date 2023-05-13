#include <stdio.h>
#include "EasySocket.h"

int main(int argc,char** argv){
    portableSetup();

    EasySocket client;

    EasySocketInitBuffer(&client,150);
    EasySocketInitDescriptor(&client,0,1);
    EasySocketInitAddr(&client,"192.168.0.25",5000,0);

    EasySocketConnect(&client);

    EasySocketRecive(&client);
    EasySocketSend(&client,"Oh hello! what is up my friend? i am the client.");
    EasySocketRecive(&client);

    EasySocketClose(&client);
    EasySocketFreeBuffer(&client);

    return 0;
}