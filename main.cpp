#include <stdio.h>
#include "sort.h"

int main() {
	FILE *file;
	file = fopen("entrada.dat", "a+");

	sortFile(file);

	fclose(file);
    return 0;
}
