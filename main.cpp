#include "sort.h"

int main() {
	ifstream file;
  	file.open("entrada.dat");

  	sortFile(file);

  	file.close();
    return 0;
}
