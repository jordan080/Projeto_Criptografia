//standard libraries
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
//other libraries 
#include "menu.h"
#include "aritmetica.h"
#include "gerar_chave.h"
#include "encriptar.h"
#include "desencriptar.h"

int main() {
	
	int exit;
	do {
		request_menu();
		exit = select_menu();
	}while(exit);

	system("exit");
	return 0;
}