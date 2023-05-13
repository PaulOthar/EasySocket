#include "EasySocket.h"

int main(int argc,char** argv){
    if(argc<4){
        printf("EasyClient IP PORT PROTOCOL(udp/tcp) UDP_MESSAGE\n");
        return 0;
    }

    portableSetup();

    if(strncmp(argv[3],"udp",3) == 0){
        if(argc<5){
            printf("No Message Inputted\n");
            return 0;
        }
        EasySocket client;

        EasySocketInitDescriptor(&client,0,0);
        EasySocketInitAddr(&client,argv[1],atoi(argv[2]),0);

        EasySocketSendUnconnected(&client,argv[4]);

        EasySocketClose(&client);
    }
    else if(strncmp(argv[3],"tcp",3) == 0){
        EasySocket client;
        EasySocketInitBuffer(&client,255);
        EasySocketInitDescriptor(&client,0,1);
        EasySocketInitAddr(&client,argv[1],atoi(argv[2]),0);
        EasySocketConnect(&client);

        char command[200];
        while((strcmp(command,"close\n") != 0)){
            if((strcmp(command,"send\n") == 0)){
                fgets(client.buffer,200,stdin);
                client.buffer[strlen(client.buffer)-1] = '\0';
                printf("\n");
                EasySocketSend(&client,NULL);
            }
            else if((strcmp(command,"recive\n") == 0)){
                printf("\n");
                EasySocketRecive(&client);
            }
            printf("\n\"send\" : sends a message to the server\n\"recive\" : recives a message from the server\n\"close\" : closes the socket\n\n");
            fgets(command,200,stdin);
        }

        EasySocketClose(&client);
        EasySocketFreeBuffer(&client);
    }
    else{
        printf("Invalid Protocol \"%s\"\n",argv[3]);
        return 0;
    }

    return 0;
}