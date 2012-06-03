#include "logger.h"
#include <iostream>

using namespace std;

Logger* Logger::m_pInstance = 0;

Logger::Logger() : output(&cout), lvl(0) {}

void Logger::set(int level, ostream* out)
{
    Logger *l = Instance();
    l->lvl = level;
	l->output = out;
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

int logColor(int p)
{
	if(p < 11) { // VERBOSE
		return 37; // BLANC
	} else if(p < 21) { // DEBUG
		return 32; // VERT
	} else if(p<31) { // INFORMATION
		return 34; // BLEU
	} else if(p<41) { // Warning
		return 33; // JAUNE
	} else { // Error
		return 35; // ROUGE
	}
}

#define textcolor(param) cout << "\033[" << param << "m"

void Logger::log(int priority, const QString& tag, const QString& msg)
{
    Logger *l = Instance();
    if (priority > l->lvl)
	{
		int color = logColor(priority);
		textcolor( color );
                *(l->output) << "[" << priority << "] " << tag.toStdString() << " : " << msg.toStdString() << endl;
		textcolor( 37 );
	}
}

void Logger::v(const QString& tag, const QString& msg) // Verbose
{
    log(10, tag, msg);
}

void Logger::d(const QString& tag, const QString& msg) // Debug
{
    log(20, tag, msg);
}

void Logger::i(const QString& tag, const QString& msg) // Information
{
    log(30, tag, msg);
}

void Logger::w(const QString& tag, const QString& msg) // Warning
{
    log(40, tag, msg);
}

void Logger::e(const QString& tag, const QString& msg) // Error
{
    log(50, tag, msg);
}
