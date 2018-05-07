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
```

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
```

[f] Oui!

[g] 

[h] 

[i] Format choisi : un chiffre par ligne!

```c
int init_automate(char *nom_fich) {
	FILE * fich = fopen(nom_fich,"r") ;
	if (fich==NULL) {
		return 1;
	}else{
		/* initialise l'automate par défaut */
		init_par_defaut();

		/* lire le code */
		int e_1,e_2,e_3,e_4=0;
		fscanf(fich,"%d\n",&e_1);
		fscanf(fich,"%d\n",&e_2);
		fscanf(fich,"%d\n",&e_3);
		fscanf(fich,"%d\n",&e_4);

		/* printf("%d;%d;%d;%d\n",e_1,e_2,e_3,e_4); */
		
		transition[Q0][e_1]=e_1;
		transition[Q1][e_1]=e_1;
		transition[Q2][e_1]=e_1;
		transition[Q3][e_1]=e_1;
		transition[Q4][e_1]=e_1;

		transition[Q1][e_2]=e_2 ;
		transition[Q2][e_3]=e_3 ;
		transition[Q3][e_4]=e_4 ;
					
	}
	fclose(fich);
	return 0;
}

```

