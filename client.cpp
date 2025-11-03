#include <cstring>
#include <bits/stdc++.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

using namespace std;

int main()
{

    int clientSocket = socket(AF_INET,SOCK_STREAM,0);
    if(clientSocket<0){
        cerr<<"Socket creation failed!"<<endl;
        return 1;
    }
    else{
        cout<<"Socket created successfully. "<<endl;
    }
    
    sockaddr_in serverAddress{};
    serverAddress.sin_family =  AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    
    int connectingServer = connect(clientSocket, (struct sockaddr*)&serverAddress,sizeof(serverAddress));
    
    if(connectingServer<0){
        cerr<<"Connection to server failed!"<<endl;
        return 1;
    }
    else{
        cout<<"Connected to server successfully."<<endl;
    }
    
    
    string msg = "Hello server bhai!";
    ssize_t byteSent = send(clientSocket,msg.c_str(),msg.size(),0);
    if(byteSent<0){
        cerr<<"Failed to send message!"<<endl;
    }
    else{
        cout<<"Message sent: "<<msg<<endl;
    }
    
    close(clientSocket);
    return 0;
    

}
