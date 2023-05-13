#ifndef EASY_SOCKET
#define EASY_SOCKET

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <winsock2.h>
#include "portableSockets.h"

#define IPV4 AF_INET
#define IPV6 AF_INET6

#define TCP SOCK_STREAM
#define UDP SOCK_DGRAM

typedef struct /*EasySocket*/{
    int descriptor;
    struct sockaddr_in addr;

    char* buffer;
    int bufferSize;

    int port;
    int isCompromised;
}EasySocket;

/*  
    Family:
        0 = IPV4
        1 = IPV6
    Type:
        0 = UDP
        1 = TCP
*/

void EasySocketInitDescriptor(EasySocket* es,int family,int type){
    if(es==NULL){
        perror("[!]EasySocket Is Null on Descriptor Initialization!");
        exit(1);
    }
    if(family > 0){
        if(type > 0){
            es->descriptor = socket(AF_INET6,SOCK_STREAM,0);
        }
        else{
            es->descriptor = socket(AF_INET6,SOCK_DGRAM,0);
        }
    }
    else{
        if(type > 0){
            es->descriptor = socket(AF_INET,SOCK_STREAM,0);
        }
        else{
            es->descriptor = socket(AF_INET,SOCK_DGRAM,0);
        }
    }

    char* message[4] = {"IPV4","IPV6","UDP","TCP"};

    if(es->descriptor == -1){
        perror("[!]Error on socket descriptor");
        exit(1);
    }
    printf("[+]EasySocket (%s/%s) Descriptor Initialized!\n",message[family],message[type+2]);
}

void EasySocketInitAddr(EasySocket* es,char* ip,int port,int family){
    if(es==NULL){
        perror("[!]EasySocket Is Null on Addr Initialization!");
        exit(1);
    }
    memset(&(es->addr.sin_zero),'\0',sizeof(es->addr.sin_zero));

    if(family > 0){
        es->addr.sin_family = AF_INET6;
    }
    else{
        es->addr.sin_family = AF_INET;
    }

    es->addr.sin_port = htons(port);

    es->addr.sin_addr.s_addr = inet_addr(ip);

    es->port = port;
    es->isCompromised = 0;

    char* message[2] = {"IPV4","IPV6"};

    printf("[+]EasySocket Addr{IP:%s ,PORT:%d ,FAMILY:%s} Initialized!\n",ip,port,message[family]);
}

void EasySocketInitBuffer(EasySocket* es,int bufferSize){
    if(es==NULL){
        perror("[!]EasySocket Is Null on Buffer Initialization!");
        exit(1);
    }

    es->buffer = (char*)malloc(sizeof(char)*bufferSize);
    if(es->buffer == NULL){
        perror("[!]Could not allocate a buffer for the EasySocket");
        exit(1);
    }
    else{
        es->bufferSize = bufferSize;
        printf("[+]EasySocket Buffer[%d] Initialized!\n",bufferSize);
    }
}

void EasySocketFreeBuffer(EasySocket* es){
    if(es==NULL){
        perror("[!]EasySocket Is Null on Free Buffer");
        exit(1);
    }
    if(es->buffer != NULL){
        free(es->buffer);
    }
}

void EasySocketClearBuffer(EasySocket* es){
    if(es==NULL){
        perror("[!]EasySocket Is Null on Clear Buffer");
        exit(1);
    }
    int i = 0;
    for(i = 0;i<es->bufferSize;i++){
        es->buffer[i] = '\0';
    }
}

void EasySocketClose(EasySocket* es){
    if(es==NULL){
        perror("[!]EasySocket Is Null on Close!");
        exit(1);
    }

    portableClose(es->descriptor);
    printf("[+]EasySocket Sucessifully closed.\n");
}

void EasySocketBind(EasySocket* server){
    if(server==NULL){
        perror("[!]EasySocket Is Null on Bind!\n");
        exit(1);
    }

    int message = bind(server->descriptor,(struct sockaddr*)&(server->addr),sizeof(server->addr));
    if(message == -1){
        EasySocketClose(server);
        perror("[!]Error on bind");
        exit(1);
    }
    printf("[+]EasySocket sucessifully bound to port:%d\n",server->port);
    server->isCompromised = 1;
}

void EasySocketListen(EasySocket* server,int maxQueueLength){
    if(server==NULL){
        perror("[!]EasySocket Is Null on Listen!\n");
        exit(1);
    }

    listen(server->descriptor,maxQueueLength);
    printf("[+]EasySocket is now Listening up to %d connections\n",maxQueueLength);
}

void EasySocketAccept(EasySocket* server,EasySocket* client){
    if(server==NULL){
        perror("[!]EasySocket<server> Is Null on Accept!");
        exit(1);
    }
    if(client==NULL){
        perror("[!]EasySocket<client> Is Null on Accept!");
        exit(1);
    }

    int addrSize = sizeof(client->addr);
    client->descriptor = accept(server->descriptor,(struct sockaddr*)&(client->addr),&addrSize);

    if(client->descriptor == -1){
        perror("[!]Error on accept");
        exit(1);
    }
    printf("[+]EasySocket Client accepted!\n");
}

void EasySocketConnect(EasySocket* client){
    if(client==NULL){
        perror("[!]EasySocket Is Null on Connect!");
        exit(1);
    }

    int message = connect(client->descriptor,(struct sockaddr*)&(client->addr),sizeof(client->addr));
    if(message == -1){
        EasySocketClose(client);
        perror("[!]Error on connect");
        exit(1);
    }
    printf("[+]EasySocket sucessifully connected!\n");
    client->isCompromised = 1;
}

void EasySocketSend(EasySocket* es,char* message){
    if(es==NULL){
        perror("[!]EasySocket Is Null on Send!");
        exit(1);
    }

    if(message != NULL){
        //EasySocketClearBuffer(es);
        strcpy(es->buffer,message);
    }

    int check = send(es->descriptor,es->buffer,strlen(es->buffer)+1,0);

    if(check == -1){
        perror("[!]EasySocket is unable to send message");
        exit(1);
    }

    printf("[+]EasySocket Sent:\"%s\"\n",es->buffer);
}

void EasySocketRecive(EasySocket* es){
    if(es==NULL){
        perror("[!]EasySocket Is Null on Send!");
        exit(1);
    }
    //bzero(es->buffer,es->bufferSize);
    //EasySocketClearBuffer(es);

    int check = recv(es->descriptor,es->buffer,es->bufferSize,0);

    if(check == -1){
        perror("[!]EasySocket is unable to recive message");
        exit(1);
    }

    printf("[+]EasySocket Recieved:\"%s\"\n",es->buffer);
}

#endif