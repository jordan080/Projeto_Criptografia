//standard libraries
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//other libraries 
#include "libraries.h"

int main() {
	
	int exit, escolha, p, q , e;

	do {
	
		escolha = request_menu();

		exit = select_menu(escolha, &p, &q, &e);
        printf("%d%d\n", escolha, exit);
	}while(exit);

	system("exit");

	return 0;
}