#include <stdio.h>
#include <string.h>
#include "automate.h"
#include <stdlib.h>


#define NB_ETATS 5
#define NB_ENTREES 10
#define LG_MAX_SORTIE 128

#define Q0 0
#define Q1 1
#define Q2 2
#define Q3 3
#define Q4 4

char essai[]="/*" /* un essai : " */;
typedef int etat ;

etat etat_initial() {
	return Q0 ;
}

int est_final(etat Q) {
	return Q == Q4 ;
	}

int lire_entree() {
char c ;
	scanf("\n%c", &c) ;
	while (((c < '0') || (c > '9')) && (c != '-')) {
		printf("entree invalide ! un chiffre entre 0 et 9 (- pour finir) ?\n") ;
		scanf("\n%c", &c) ;
		}
	if (c == '-') {
		return -1 ;
	}
	else {
		return c-'0' ;
	}
}

void init_par_defaut() { /* initialise toutes les cases du tableau transition à 0 */
	int transition[NB_ETATS][NB_ENTREES] ;
	for (int i=0 ; i<NB_ETATS ; i++) {
		for (int j=0 ; i<NB_ENTREES ; j++) {
			transition[i][j]=0;
		}	
	}

int init_automate(char *nom_fich) {
	FILE * fich = fopen(nom_fich,"r") ;
	if (file==NULL) {
		return 1
	}else{
		/* initialise l'automate par défaut */
	}
}

void simule_automate() {
int etat_courant, etat_suivant, entree ;
	entree = 0 ;
	etat_courant = etat_initial() ;

	/*-- question d --*/
	int transition[NB_ETATS][NB_ENTREES] ;
	for (int i=0 ; i<NB_ETATS ; i++){
		for (int j=0 ; j<NB_ENTREES ; j++) {
			if (j==1) {
				transition[i][j]=1 ; /* on remplit la colonne 1 */
			}else{
				transition[i][j]=0 ; /* initialise le reste à zéro */
			}
		}
	}	
	/* on complète le tableau */
	transition[1][2]=2 ;
	transition[2][3]=3 ;
	transition[3][4]=4 ;
	/*-- question d --*/


	while (entree != -1) {
		entree = lire_entree() ;
		etat_suivant=transition[etat_courant][entree] ;
		
		printf("courant:%d - entree:%d -> suivant:%d\n", etat_courant, entree, etat_suivant) ; /* pour tester */
		
		etat_courant = etat_suivant ;
		
		/* question e */
		if (est_final(etat_courant)) {
			printf("clic\n");
			exit(0);
		}
	}
}
