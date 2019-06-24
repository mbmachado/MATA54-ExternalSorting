#include <algorithm>
#include <sstream>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
using namespace std;
const int MAXNARQS = 4;
const int MAXMEM = 1000; //Bytes

/**
 * The Record
 */
typedef struct record {
	char key[21];
	char content[51];
} Record;

/**
 * The FileAttributes Record
 */
typedef struct fileAttributes {
	string fileName;
	long currentLine = 0;
	short hasContent = 0;
} FileAttributes;

/**
 * Inserts a record into the file
 * @param Record record
 * @param string fileName
 *
 */
void insertRecord(Record record, FileAttributes fa);

/**
 * Retrieves a record from the file
 * @param string fileName
 * @return Record
 *
 */
Record consultRecord(FileAttributes fa);

/**
 * Comparison function used during sorting
 * @param Record &i
 * @param Record &j
 *
 */
bool compareByKey(Record &i, Record &j);

/**
 * Sorts the file
 *
 */
void externalSort();

/**
 * Initialize A*.dat files with runs
 *
 */
void initializeFiles();

/**
 * Splits a string by given delimiter
 * @param string line
 * @param char delimiter
 * @return Record
 *
 */
Record explode(string line, char delimiter);

/**
 * Concatenetes two strings by given delimiter
 * @param Record record
 * @param char delimiter
 * @return string
 *
 */
string implode(Record record, char delimiter);
