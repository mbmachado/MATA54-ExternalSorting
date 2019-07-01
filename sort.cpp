#include "sort.h"
int maxNumberRecords = MAXMEM/sizeof(Record);
int runSize = maxNumberRecords;
vector<FileAttributes> files;

void externalSort() {
    Record record;
    vector<Record> records;
    string line;
    
    for (vector<FileAttributes>::iterator i = files.begin(); i != files.begin() + files.size() / 2; ++i) {
        FileAttributes fa = *i;
        ifstream file;

        file.open(fa.fileName);
        while(getline(file, line)) {
            records.push_back(explode(line, ','));
        }
        file.close();
        
    }

    sort(records.begin(), records.end(), compareByKey);
    
    for (vector<Record>::iterator j = records.begin(); j != records.end(); ++j) {
        ofstream file;
        file.open("saida.dat", ios::app);
        line = implode(*j, ',');
        file << line << endl;
        file.close();
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

    file.open(fa.fileName);

    getline(file, line);
        
    file.close();
    
    record = explode(line, ',');
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
    int comp = strcmp(i.key, j.key);

    if(comp == 0) {
        if (strcmp(i.content, j.content) >= 0) {
            return false;
        }
    } else if(comp > 0) {
        return false;
    }

    return true;
}