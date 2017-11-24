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
#include <bits/stdc++.h>
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
    bool Send(char * data, int size)
    {
        while( send(sock , data , size , 0) < 0)
        {
            cout << "Send failed : " << data << endl;
//            return false;
        }
        return true;
    }
    string receive(long & size)
    {
        string reply;
        char buffer[15000];
        recv(sock,buffer,8,0);
        memcpy((void*)&size,buffer+4,4);
        while(recv(sock , buffer , size, 0) < 0)// sizeof(buffer)
        {
            cout << "receive failed!" << endl;
        }
        reply += buffer;
        //        buffer[size]='\0';
        return reply;
    }
    string read(int &size)
    {
        char buffer[1] = {};
        string reply;
        while (recv(sock , buffer , sizeof(buffer) , 0) > 0) {
            reply += buffer[0];
        }
        return reply;
    }

    void closeCon()
    {
        close(sock);
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
void print(const char * data, int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << data[i];
    }
}

void login(std::string name, TCPClient tcp)
{
    char buffer[256];
    std::string msg = "{\n\"name\": \""+name+"\"\n}";
//    std::cout << msg << std::endl;
    long cmd = 1;
    long size = msg.size();

    memcpy(buffer, (void*)&cmd, 4);
    memcpy(buffer+4, (void*)&size, 4);
    memcpy(buffer+8, msg.c_str(), msg.size());
    buffer[size+8] = 0;
    tcp.Send(buffer,8+size);
    auto ans = tcp.receive(size);
    std::cout << ans << std::endl;
}

void getmap(int layer, TCPClient tcp)
{
    char buffer[256];
    std::string msg = "{\"layer\": "+ std::to_string(layer)+" }";
    std::cout << msg << std::endl;
    long cmd = 0x0A;
    long size = msg.size();
    std::cout << size << std::endl;
    memcpy(buffer, (void*)&cmd, 4);
    memcpy(buffer+4, (void*)&size, 4);
    memcpy(buffer+8, msg.c_str(), msg.size());
    buffer[size+8] = 0;

    tcp.Send(buffer,8+size);
    auto ans = tcp.receive(size);
    std::cout << ans << std::endl;
}

void move(int train_id,int speed, int line_id,TCPClient tcp)
{
    char buffer[256];
    std::string msg = "{\n \"line_idx\": 1, \n\
        \n\"speed\": 1, \n\
        \n\"train_idx\": 0 \n}";
    std::cout << msg << std::endl;
    long cmd = 3;
    long size = msg.size();
    std::cout << size << std::endl;
    memcpy(buffer, (void*)&cmd, 4);
    memcpy(buffer+4, (void*)&size, 4);
    memcpy(buffer+8, msg.c_str(), msg.size());
    buffer[size+8] = 0;

    tcp.Send(buffer,8+size);
    auto ans = tcp.receive(size);
    std::cout << ans << std::endl;
}

void turn(TCPClient tcp)
{
    char buffer[256];
    std::string msg="";
    std::cout << msg << std::endl;
    long cmd = 5;
    long size = msg.size();
    std::cout << size << std::endl;
    memcpy(buffer, (void*)&cmd, 4);
    memcpy(buffer+4, (void*)&size, 4);
    memcpy(buffer+8, msg.c_str(), msg.size());
    buffer[size+8] = 0;

    tcp.Send(buffer,8+size);
}

int main(int argc, char ** argv)
{
    TCPClient tcp;
    tcp.setup(ser_ip,potr);
    login("rrr",tcp);
//    sleep(5);
//    tcp.closeCon();
    //        sleep(10);
    getmap(0,tcp);
    getmap(1,tcp);
    move(1,1,1,tcp);

    getmap(1,tcp);
    getmap(1,tcp);
    getmap(1,tcp);
    turn(tcp);
    turn(tcp);
    getmap(1,tcp);
    getmap(1,tcp);


}

