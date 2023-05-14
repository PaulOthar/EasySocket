#include "EasySocket.h"

int main(int argc, char **argv)
{
    if (argc < 4)
    {
        printf("EasyServer CLOSE_WORD PROTOCOL(udp/tcp) PORT IP(Optional)\n");
        return 0;
    }

    if (strcmp(argv[2], "udp") == 0)
    {
        printf("UDP not yet supported\n");
        return 0;
    }
    else if (strcmp(argv[2], "tcp") == 0)
    {
        portableSetup();

        EasySocket server;
        EasySocket client;

        EasySocketInitDescriptor(&server, 0, 1);
        if (argc == 4)
        { // No IP
            EasySocketInitAddr(&server, NULL, atoi(argv[3]), 0);
        }
        else
        {
            EasySocketInitAddr(&server, argv[4], atoi(argv[3]), 0);
        }

        EasySocketInitBuffer(&client, 255);

        EasySocketBind(&server);
        EasySocketListen(&server, 1);

        EasySocketAccept(&server, &client);

        EasySocketSend(&client, "Connected to Server.\n");

        while (strcmp(client.buffer, argv[1]))
        {
            EasySocketRecive(&client);
            EasySocketSend(&client, NULL);
        }

        EasySocketSend(&client, "Closing Server.\n");

        EasySocketClose(&client);
        EasySocketFreeBuffer(&client);

        EasySocketClose(&server);
    }
    else
    {
        printf("Invalid Protocol \"%s\"\n", argv[2]);
        return 0;
    }
    return 0;
}