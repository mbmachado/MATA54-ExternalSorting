#include "sort.h"
#include <sstream>

void sortFile(ifstream &file) {
    int maxNumberRegisters = MAXMEM/sizeof(Record);
    Record record;
    string line;

    if (file.is_open() && file.good()) {
        getline(file, line);

        while(!file.fail()) {
            if (line.length() != 0) {
                insertRecord(explode(line, ','), "saida.dat");
            }
            getline(file, line);
        }
    
    }

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
    string key, content;
    Record record;

    getline(iss, key, delimiter);
    getline(iss, content, delimiter);
    strncpy(record.key, key.c_str(), 21);
    strncpy(record.content, content.c_str(), 51);

    return record;
}

string implode(Record record, char delimiter) {
    string line; 

    line = record.key;
    line += delimiter;
    line += record.content;

    return line;
}
