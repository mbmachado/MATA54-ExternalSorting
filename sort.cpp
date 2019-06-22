#include "sort.h"
#include <sstream>

void sortFile(ifstream &file) {
    int maxNumberRegisters = MAXMEM/sizeof(Record);
    Record record;
    string line;

    if (file.is_open() && file.good()) {

        while(getline(file, line)) {
            insertRecord(explode(line, ','), "saida.dat");
        }
    
    }

    cout << maxNumberRegisters << endl;
}

void insertRecord(Record record, string fileName) {
    string line;
    ofstream file;

    file.open(fileName, ios::app);
    line = implode(record, ',');
    file << line << endl;
    file.close();
}

Record consultRecord(FILE* file) {

}

Record explode(string line, char delimiter) {
    istringstream iss(line);
    Record record;

    iss.getline(record.key, 21, delimiter);
    iss.getline(record.content, 51, delimiter);

    return record;
}

string implode(Record record, char delimiter) {
    string line; 

    line = record.key;
    line += delimiter;
    line += record.content;

    return line;
}
