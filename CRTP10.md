# Compte-rendu TP10

[a] Code de la porte : *1234*

[b] Pour arrêter la simulation, il faut entrer *-*

[c] Oui!

```c
void simule_automate() {
int etat_courant, etat_suivant, entree ;
	entree = 0 ;
	etat_courant = etat_initial() ;
	while (entree != -1) {
		entree = lire_entree() ;
		switch (etat_courant) {
			case Q0 : switch (entree) {
					case 1 : etat_suivant = Q1 ;
						 break ;
					default : etat_suivant = Q0 ;
						  break ;
				  }
				  break ;
			case Q1 : switch (entree) {
					case 1 : etat_suivant = Q1 ;
						 break ;
					case 2 : etat_suivant = Q2 ;
						 break ;
					default : etat_suivant = Q0 ;
						 break ;
				  }
				  break ;
			case Q2 : switch (entree) {
					case 1 : etat_suivant = Q1 ;
						 break ;
					case 3 : etat_suivant = Q3 ;
						 break ;
					default : etat_suivant = Q0 ;
						 break ;
				  }
				  break ;
			case Q3 : switch (entree) {
					case 1 : etat_suivant = Q1 ;
						 break ;
					case 4 : etat_suivant = Q4 ;
						 break ;
					default : etat_suivant = Q0 ;
						 break ;
				  }
				  break ;
			case Q4 : switch (entree) {
					case 1 : etat_suivant = Q1 ;
						 break ;
					default : etat_suivant = Q0 ;
						 break ;
				  }
				  break ;
			default : break ;
		}
		/* test */
		printf("%d - %d -> %d\n", etat_courant, entree, etat_suivant) ;
		/* fin test */
		etat_courant = etat_suivant ;

		if (est_final(etat_courant)) {
			printf("clic\n");
			exit(0);
		}
	}
}
```c

[d] cf Fonction_transition.pdf

[e] printf("clic\n"); 
pour afficher un message lorsque la porte s'ouvre 

```c
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
```c

[f] Oui!
