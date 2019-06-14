#include <iostream>
using namespace std;
const int MAXNARQS = 100;
const int MAXMEM = 512000;

/**
 * The Record
 */
typedef struct record {
	char key[21];
	char content[51];
} Record;

/**
 * Inserts a record into the file
 * @param char[21] Record
 *
 */
void insertRecord(Record record);

/**
 * Retrieves a record from the file
 * @return Record
 *
 */
Record consultRecord(FILE* file);

/**
 * Sorts the file
 *
 */
void sortFile(FILE* input);

/**
 * Splits a string by given delimiter
 * @param string line
 * @param char character
 * @return Record
 *
 */
Record explode(string line, char character);

/**
 * Concatenetes two strings by given delimiter
 * @param Record record
 * @return string
 *
 */
string implode(Record record);