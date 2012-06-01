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

void Logger::log(int priority, string tag, string msg)
{
    Logger *l = Instance();
    if (priority > l->lvl)
	{
		int color = logColor(priority);
		textcolor( color );
		*(l->output) << "[" << priority << "] " << tag << " : " << msg << endl;
		textcolor( 37 );
	}
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
