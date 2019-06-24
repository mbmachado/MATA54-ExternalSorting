#include <algorithm>
#include <sstream>
#include <vector>
#include "sort.h"

void sortFile(ifstream &file) {
    int maxNumberRecords = MAXMEM/sizeof(Record);
    vector<FileAttributes> files;
    vector<Record> records;
    string line;

    for (int i = 1; i <= MAXNARQS/2 * 2; i++) {
        FileAttributes fa;
        fa.fileName = 'A' + to_string(i) + ".dat";
        files.push_back(fa);
    }

    for (vector<FileAttributes>::iterator i = files.begin(); i != files.begin() + files.size() / 2; ++i) {
        for (int j = 0; j < maxNumberRecords && getline(file, line); j++) {
           records.push_back(explode(line, ','));
        }
        sort(records.begin(), records.end(), compareByKey);
        for (vector<record>::iterator j = records.begin(); j != records.end(); ++j) {
            insertRecord(*j, *i);
        }
        records.clear();
    }

    cout << maxNumberRecords << endl;
}

Record consultRecord(FileAttributes fa) {
    ifstream file;
}

void insertRecord(Record record, FileAttributes fa) {
    string line;
    ofstream file;

    file.open(fa.fileName, ios::app);
    line = implode(record, ',');
    file << line << endl;
    file.close();
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

bool compareByKey(Record &i, Record &j) {
    if(strcmp(i.key, j.key) >= 0) {
        return false;
    }

    return true;
}
