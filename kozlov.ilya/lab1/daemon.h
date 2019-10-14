//
// Created by ilya on 10/10/19.
//

#ifndef LAB1__DAEMON_H_
#define LAB1__DAEMON_H_

#include <string>

class Daemon
{
private:
  static const std::string DELIM;
  static const std::string INTERVAL_KEY;
  static const std::string PID_FILE_KEY;
  static const std::string DIR1_KEY;
  static const std::string DIR2_KEY;
  static const std::string NAME;

  static std::string pid_file_;
  static std::string dir1_;
  static std::string dir2_;
  static std::string hist_log_;
  static char* config_file_;
  static int time_interval_;

public:
  static bool Init(char* config_file);
  static void Start();

private:
  static void Clear();
  static void Terminate();
  static bool LoadConfig();
  static void CheckPidFile();
  static void SetPidFile();
  static void SetSignals();
  static void StartWork();
  static void DoWork();
  static void SignalHandler(int sig_num);
  static std::string GetFullPath(std::string& path);
  static void ListDirRec(std::ofstream& hist_log, std::string& path, int indent);
};

#endif //LAB1__DAEMON_H_
