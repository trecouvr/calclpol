#ifndef LOGGER_H
#define LOGGER_H

#include <QString>
#include <iostream>

using namespace std;

class Logger
{
public:
    static Logger* Instance();
	void static set(int level, ostream* out);
    void static log(int priority, const QString& tag, const QString& msg);
    void static v(const QString& tag, const QString& msg); // Verbose
    void static d(const QString& tag, const QString& msg); // Debug
    void static i(const QString& tag, const QString& msg); // Information
    void static w(const QString& tag, const QString& msg); // Warning
    void static e(const QString& tag, const QString& msg); // Error
private:
    Logger();
    static Logger* m_pInstance;
	ostream* output;
	int lvl;

};

#endif // LOGGER_H
