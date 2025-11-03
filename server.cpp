#include<iostream>
#include<cstring>
#include<netinet/in.h>
#include<sys/socket.h>
#include<unistd.h>
#include<arpa/inet.h>

using namespace std;

int main(){
    int serverSocket = socket(AF_INET,SOCK_STREAM,0);
    
    if(serverSocket<0){
        cerr<<"Socket creation failed!"<<endl;
        return 1;
    }
    else{
        cout<<"Socket created successfully"<<endl;
    }
    
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    
    int bindValue = bind(serverSocket,(const struct sockaddr*) &serverAddress, sizeof(serverAddress) );
    
    if(bindValue<0){
        cerr<<"Binding failed!."<<endl;
        close(serverSocket);
        return 1;
    }
    else{
        cout<<"Bind successful."<<endl;
    }
    
    int listening = listen(serverSocket,5);
    if(listening<0){
        cerr<<"Listen failed!"<<endl;
        close(serverSocket);
        return 1;
    }
    else{
        cout<<"Server is  listening on port 8080..."<<endl;
    }
    
    int clientSocket = accept(serverSocket,nullptr,nullptr);
    if(clientSocket<0){
        cerr<<"Accept failed!"<<endl;
        close(serverSocket);
        return 1;
        
    }
    else{
        cout<<"Connection accepted."<<endl;
    }
    
    char buffer[1024] = {0};
    int byteReceived  = recv(clientSocket,buffer,sizeof(buffer),0);
    if(byteReceived<0){
        cerr<<"Receive failed!"<<endl;
    }
    else{
        cout<<"Message from client:"<<buffer<<endl;
    }
    
    close(clientSocket);
    close(serverSocket);
    cout<<"Socket closed,Server Exiting."<<endl;
    
    return 0;
    
}
