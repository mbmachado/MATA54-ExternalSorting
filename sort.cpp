#include "sort.h"

void insertRecord(Record record, ofstream &file) {
    string r = implode(record, ',');

    file << r;
    file.close();
}

Record consultRecord(FILE* file) {

}

void sortFile(FILE* input) {

}

Record explode(string line, char character) {
    int i = 0, j = 0;
    Record record;

    while(line[i] != character ) {
        record.key[i] = line[i];
        i++;
    }

    i++;
    while(line[i] != '\0') {
        record.content[j] = line[i];
        i++, j++;
    }

    return record;
}

string implode(Record record, char character) {
    string line = record.key;
    line += character;
    line += record.content;

    return line;
}
