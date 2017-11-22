#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netdb.h>
#include <vector>

using namespace std;

class TCPClient
{
private:
    int sock;
    std::string address;
    int port;
    struct sockaddr_in server;

public:
    TCPClient()
    {
        sock = -1;
        port = 0;
        address = "";
    }
    bool setup(string address, int port)
    {
        if(sock == -1)
        {
            sock = socket(AF_INET , SOCK_STREAM , 0);
            if (sock == -1)
            {
                cout << "Could not create socket" << endl;
            }
        }
        if(inet_addr(address.c_str()) == -1)
        {
            struct hostent *he;
            struct in_addr **addr_list;
            if ( (he = gethostbyname( address.c_str() ) ) == NULL)
            {
                herror("gethostbyname");
                cout<<"Failed to resolve hostname\n";
                return false;
            }
            addr_list = (struct in_addr **) he->h_addr_list;
            for(int i = 0; addr_list[i] != NULL; i++)
            {
                server.sin_addr = *addr_list[i];
                break;
            }
        }
        else
        {
            server.sin_addr.s_addr = inet_addr( address.c_str() );
        }
        server.sin_family = AF_INET;
        server.sin_port = htons( port );
        if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
        {
            perror("connect failed. Error");
            return 1;
        }
        return true;
    }
    bool Send(string data)
    {
        if( send(sock , data.c_str() , strlen( data.c_str() ) , 0) < 0)
        {
            cout << "Send failed : " << data << endl;
            return false;
        }
        return true;
    }
    string receive(int size = 4096)
    {
        char buffer[size];
        string reply;
        if( recv(sock , buffer , size, 0) < 0)// sizeof(buffer)
        {
            cout << "receive failed!" << endl;
        }
        buffer[size]='\0';
        reply = buffer;
        return reply;
    }
    string read()
    {
        char buffer[1] = {};
        string reply;
        while (buffer[0] != '\n') {
            if( recv(sock , buffer , sizeof(buffer) , 0) < 0)
            {
                cout << "receive failed!" << endl;
                break;
            }
            reply += buffer[0];
        }
        return reply;
    }
};


std::string utl = "wgforge-srv.wargaming.net";
int potr        = 443;

std::string ser_ip = "92.223.2.79";

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char ** argv)
{
    char ze= 0;
    char on= 1;
    char sev= 17;
    std::cout << ze << on << std::endl;
    TCPClient tcp;
    tcp.setup(ser_ip,potr);
    while (true)
    {
        std::string tmp = "11111111";
        tmp[0] = on;
        tmp[1] = ze;
        tmp[2] = ze;
        tmp[3] = ze;

        tmp[4] = sev;
        tmp[5] = ze;
        tmp[6] = ze;
        tmp[7] = ze;
        std::string msg = "Hex: |01 00 00 00|17 00 00 00|\"{\n \"name\": \"Boris\"\n}\"";

        tcp.Send(msg);
        std::string rec = tcp.receive();
        std::cout << rec << std::endl;
        sleep(5);
    }

}

