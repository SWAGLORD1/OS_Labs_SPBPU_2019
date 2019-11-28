//
// Created by misha on 24.11.2019.
//

#ifndef LAB_2_SEVER__CLIENTHANDLER_H
#define LAB_2_SEVER__CLIENTHANDLER_H

#include <string>
//#include <bits/types/siginfo_t.h>
#include <semaphore.h>
#include "client_info.h"
#include "../interfaces/Conn.h"
#include "../interfaces/message.h"
#include "Server_conn.h"


class ClientHandler {
public:
    static ClientHandler* GetInstance();
    bool OpenConnection();
    void SetClient(int client_pid);
    void Start();
    Conn GetPipe();
    void SetServerConnection(Server_conn serv_conn_);

private:
    sem_t* semaphore_host;
    sem_t* semaphore;
    sem_t* semaphore_client;

    std::string semaphore_name;
    std::string sem_client_name;
    std::string sem_host_name;
    Conn connection;
    Server_conn serv_con;
    ClientInfo client_info;
    ClientHandler();
    //ClientHandler(ClientHandler&);
    bool GetTask(Message& mes);
    void KillClient();
    void Terminate(int signum);
    static void SignalHandler(int signum);
};


#endif //LAB_2_SEVER__CLIENTHANDLER_H
