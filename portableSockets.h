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
    closesocket(addr);
    return 0;
}

#endif

#ifdef _LINUX
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int portableSetup(){
    return 0;
}

int portableClose(int addr){
    close(addr);
    return 0;
}

#endif