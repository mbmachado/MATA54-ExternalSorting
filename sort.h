#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
using namespace std;
const int MAXNARQS = 100;
const int MAXMEM = 512000000; //Bytes

/**
 * The Record
 */
typedef struct record {
	char key[21];
	char content[51];
} Record;

/**
 * Inserts a record into the file
 * @param Record record
 * @param string fileName
 *
 */
void insertRecord(Record record, string fileName);

/**
 * Retrieves a record from the file
 * @param string fileName
 * @return Record
 *
 */
Record consultRecord(string fileName);

/**
 * Sorts the file
 * @param ifstream &file
 *
 */
void sortFile(ifstream &file);

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
