#include "sort.h"
int maxNumberRecords = MAXMEM/sizeof(Record);
int runSize = maxNumberRecords;
vector<FileAttributes> files;





void externalSort() {
    Record record;
    vector<Record> records;

    
    for (vector<FileAttributes>::iterator i = files.begin() + files.size() / 2 + 1; i != files.end(); ++i) {
        //Carrega o primeiro registro dos Arquivos A*.dat no vector records;
        for (vector<FileAttributes>::iterator m = files.begin(); m != files.begin() + files.size() / 2; ++i) {
            records.push_back(consultRecord(*m)); 
        }

        for (int j = 0; j < runSize * files.size() / 2; j++) { //enquanto as runs tiverem registros
            sort(records.begin(), records.end(), compareByKey);
            record = records[0];
            records.erase(records.begin());
            insertRecord(record, *i);
            vector<FileAttributes>::iterator k;
            for (k = files.begin(); k != files.end(); ++k) {
                FileAttributes fa = *k;
                if (fa.fileName == record.file) {
                    records.push_back(consultRecord(*k));
                }
            }

        } 
        
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
            record.file = fa.fileName; 
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
