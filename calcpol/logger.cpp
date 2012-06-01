#include "logger.h"
#include <iostream>

using namespace std;

Logger* Logger::m_pInstance = NULL;

Logger::Logger() : output(&cout), lvl(0) {}

void Logger::set(int level, ostream* out)
{
    Logger *l = Instance();
    l->lvl = level;
	l->output = out; /*<<-- marche pas je sais pas pourquoi TODO ! */
}

/*
 Le logger par défaut est très verbeux, et il ecrit sur STDOUT.
 Il faut appeler la méthode Logger::set pour modifier les paramétres.
*/
Logger* Logger::Instance()
{
   if (!m_pInstance)
       m_pInstance = new Logger;
   return m_pInstance;
}


void Logger::log(int priority, string tag, string msg)
{
    Logger *l = Instance();
    if (priority > l->lvl)
		*(l->output) << "[" << priority << "] " << tag << " : " << msg << endl;
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
