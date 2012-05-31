#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <iostream>

using namespace std;

class Logger
{
    ostream& output;
    int lvl;
public:
    Logger(int level, ostream& out);
    void log(int priority, string tag, string msg);
    void v(string tag, string msg); // Verbose
    void d(string tag, string msg); // Debug
    void i(string tag, string msg); // Information
    void w(string tag, string msg); // Warning
    void e(string tag, string msg); // Error
private:
};

#endif // LOGGER_H
