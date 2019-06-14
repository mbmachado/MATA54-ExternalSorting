#include <iostream>
#include <string.h>
#include "sort.h"
using namespace std;

void insertRecord(Record record) {

}

Record consultRecord(FILE* file) {

}

void sortFile(FILE* input) {

}

void clear(Record* record) {
    memset(record->key, 0, sizeof record->key);
    memset(record->content, 0, sizeof record->content);
}

Record explode(string line, char character) {
    int i = 0, j = 0;
    Record record;
    clear(&record);

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

string implode(Record record) {

}
