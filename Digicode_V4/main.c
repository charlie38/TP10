#include <stdio.h>
#include "automate.h"

int main(int argc, char * argv[]) {
	if (argc!=2){
		printf("USAGE: ./main nom_fichier\n");
	}else{
		int res=init_automate(argv[1]);
		if (res==0) {
			simule_automate() ;
		}else{
			printf("échec initialisation");
		}
	}
	return 0 ;
}

