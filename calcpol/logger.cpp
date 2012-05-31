#include "logger.h"
#include <iostream>

using namespace std;

Logger::Logger(int level, ostream& out) : output(out), lvl(level) {}

void Logger::log(int priority, string tag, string msg)
{
    if (priority > lvl)
        output << "[" << priority << "] " << tag << " : " << msg << endl;
}

void Logger::v(string tag, string msg) // Verbose
{
    log(10, tag, msg);
}

void Logger::d(string tag, string msg) // Debug
{
    log(20, tag, msg);
}

void Logger::i(string tag, string msg) // Information
{
    log(30, tag, msg);
}

void Logger::w(string tag, string msg) // Warning
{
    log(40, tag, msg);
}

void Logger::e(string tag, string msg) // Error
{
    log(50, tag, msg);
}
