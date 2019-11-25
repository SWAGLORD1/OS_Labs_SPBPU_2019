#ifndef GOAT_H
#define GOAT_H

#include <conn.h>
#include <csignal>
#include <semaphore.h>
#include <memory.h>

class Goat
{
public:
  static Goat& GetInstance(int host_pid);
  void Start();
  bool OpenConnection();
  Goat(Goat&) = delete;
private:
  Conn connection;
  sem_t* semaphore_host;
  sem_t* semaphore_client;
  int host_pid;

  explicit Goat(int host_pid);
  void Terminate(int signum);
  bool CheckIfSelfMessage(Message& msg);
  static int GetRand(int right);
  static void SignalHandler(int signum);
};


#endif //GOAT_GOAT_H