#ifndef __AUTOMATE__
#define __AUTOMATE__

void simule_automate() ;

typedef int etat ;

etat transition(etat Q, int e) ; /* retourne l'état atteint à partir de l'état Q avec l'entrée e */

#endif
