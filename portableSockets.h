#ifndef PORTABLE_SOCKETS
#define PORTABLE_SOCKETS

int portableSetup();
int portableClose(int addr);

#endif

#ifdef _WIN32
#include <winsock2.h>

int portableSetup(){
    WSADATA wsa;
    WSAStartup(MAKEWORD(2,0),&wsa);
    return 0;
}

int portableClose(int addr){
    return closesocket(addr);
}

#else
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>

int portableSetup(){
    return 0;
}

int portableClose(int addr){
    return close(addr);
}

#endif