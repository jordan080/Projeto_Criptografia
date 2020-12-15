//standard libraries
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
//other libraries 
#include "matematica_discreta.h"
#include "gerar_chave.h"
#include "encriptar.h"
#include "desencriptar.h"

int main() {
	
	int exit, escolha;
	long p, q , e;

	do {
		escolha = request_menu();
		exit = select_menu(escolha, &p, &q, &e);
	}while(exit);

	system("exit");

	return 0;
}