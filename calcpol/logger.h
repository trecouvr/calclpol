#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <iostream>

using namespace std;

class Logger
{
public:
    ostream& output;
    int lvl;
    static Logger* Instance();
    void static set(int level, ostream& out);
    void static log(int priority, string tag, string msg);
    void static v(string tag, string msg); // Verbose
    void static d(string tag, string msg); // Debug
    void static i(string tag, string msg); // Information
    void static w(string tag, string msg); // Warning
    void static e(string tag, string msg); // Error
private:
    Logger();
    static Logger* m_pInstance;

};

#endif // LOGGER_H
