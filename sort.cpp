#include "sort.h"
int maxNumberRecords = MAXMEM/sizeof(Record);
int runSize = maxNumberRecords;
vector<FileAttributes> files;

void externalSort() { 
    vector<Record> records;

    //Carrega o primeiro registro dos Arquivos A*.dat no vector records;
    for (vector<FileAttributes>::iterator i = files.begin(); i != files.begin() + files.size() / 2; ++i) {
        records.push_back(consultRecord(*i)); 
    }

}

void initializeFiles() {
    vector<Record> records;
    ifstream file;
    string line;

    for (int i = 1; i <= MAXNARQS/2 * 2; i++) {
        FileAttributes fa;
        fa.fileName = 'A' + to_string(i) + ".dat";
        files.push_back(fa);
    }

    file.open("entrada.dat");

    while(!file.fail()) {
        for (vector<FileAttributes>::iterator i = files.begin(); i != files.begin() + files.size() / 2; ++i) {
            for (int j = 0; j < maxNumberRecords && getline(file, line); j++) {
               records.push_back(explode(line, ','));
            }
            sort(records.begin(), records.end(), compareByKey);
            for (vector<Record>::iterator j = records.begin(); j != records.end(); ++j) {
                insertRecord(*j, *i);
            }
            records.clear();
        }
    }

    file.close();
}

Record consultRecord(FileAttributes fa) {
    Record record;
    string line;
    ifstream file;
    int i;

    file.open(fa.fileName);

    for (i = 0; getline(file, line); i++) {
        if (fa.currentLine == i) {
            record = explode(line, ',');    
            break;
        }
    }
    fa.currentLine = i;

    file.close();
    return record;
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

void deleteFiles(int n) {
    for(int i = 1; i <=n; i++) {
        string fileName = 'A' + to_string(i) + ".dat";
        remove(fileName.c_str());
    }
}
