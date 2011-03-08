#ifndef logger_h
#define logger_h
#include <sys/time.h>
#include "types.h"

class Logger {
private:
  std::ofstream file;
  Event         tic;
  Event         timer;
  Event         memory;

  double get_time() {                                           // Timer function
    struct timeval tv;                                          // Time value
    gettimeofday(&tv, NULL);                                    // Get time of day in seconds and microseconds
    return double(tv.tv_sec+tv.tv_usec*1e-6);                   // Combine seconds and microseconds and return
  }

public:
  bool printNow;

  Logger() {
    file.open("time");
    printNow = false;
  }
  ~Logger() {
    file.close();
  }

  void startTimer(std::string event) {
    tic[event] = get_time();
  }

  void stopTimer(std::string event, bool print=false) {
    double toc = get_time();
    timer[event] += toc - tic[event];
    if(print) std::cout << event << " : " << timer[event] << std::endl;
  }

  void eraseTimer(std::string event) {
    timer.erase(event);
  }

  void resetTimer() {
    for( E_iter E=timer.begin(); E!=timer.end(); ++E ) {
      E->second = 0;
    }
  }

  void allocMemory(std::string event, double bytes) {
    memory[event] += bytes;
  }

  void freeMemory(std::string event, double bytes) {
    memory[event] -= bytes;
  }

  void printTime(std::string event) {
    std::cout << event << " : " << timer[event] << std::endl;
  }

  void printMemory(std::string event) {
    std::cout << event << " : " << memory[event] << std::endl;
  }

  void printAllTime() {
    for( E_iter E=timer.begin(); E!=timer.end(); ++E ) {
      std::cout << E->first << " : " << E->second << std::endl;
    }
  }

  void writeTime() {
    for( E_iter E=timer.begin(); E!=timer.end(); ++E ) {
      file <<  E->first << " " << E->second << std::endl;
    }
  }

};

#endif
