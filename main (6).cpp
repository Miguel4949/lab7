////
// Name: Miguel Angel Puga
// Date: October 4, 2026
// Class: CSCI 1470.0X
// Semester: Fall 2026
// CSCI 1470 Instructor: Dr. Jonatan Reyes
//
// Program Description: Spell checker (Part 1) 
//////

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;

const bool debug = true;

void initializeArray(string dict[], int size);
bool populateArray(string dict[], int size, int &loadedCount, const string &filename);
int countWords(const string dict[], int size);
void printArray(const string dict[], int loadedCount);

int main() 
{
    
    const int DICT_SIZE = 24500;
    string dictionary[DICT_SIZE];
    int loadedCount = 0;

    if (debug) {
        cout << "*****************************************************" << endl;
        cout << "*** Welcome to the spell checker! [UNDER CONSTRUCTION] ***" << endl;
        cout << "*****************************************************" << endl;
    } else {
        cout << "*****************************************************" << endl;
        cout << "******** UNDER CONSTRUCTION: Spell checker **********" << endl;
        cout << "*****************************************************" << endl;
    }

    auto start = high_resolution_clock::now();
    initializeArray(dictionary, DICT_SIZE);
    auto end = high_resolution_clock::now();
    if (debug) {
        auto duration = duration_cast<microseconds>(end - start).count();
        cout << "DEBUG: Initialization took " << duration << " microseconds." << endl;
    }

    start = high_resolution_clock::now();
    if (!populateArray(dictionary, DICT_SIZE, loadedCount, "dictionary.txt")) {
        cout << "Error: Could not open dictionary file!" << endl;
        return 1;
    }
    end = high_resolution_clock::now();
    if (debug) {
        auto duration = duration_cast<microseconds>(end - start).count();
        cout << "DEBUG: Loading took " << duration << " microseconds." << endl;
    }

    if (debug) {
        start = high_resolution_clock::now();
        printArray(dictionary, loadedCount);
        end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start).count();
        cout << "DEBUGGING: Printing took " << duration << " microseconds." << endl;
    }

    start = high_resolution_clock::now();
    int validWords = countWords(dictionary, DICT_SIZE);
    end = high_resolution_clock::now();

    cout << "Loaded " << validWords << " words from dictionary." << endl;

    if (debug) {
        auto duration = duration_cast<microseconds>(end - start).count();
        cout << "DEBUGGING: Word count took " << duration << " microseconds." << endl;
    }

    return 0;
}


void initializeArray(string dict[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        dict[i] = "";
    }
}

bool populateArray(string dict[], int size, int &loadedCount, const string &filename) 
{
    ifstream infile(filename);
    if (!infile.is_open()) 
    {
        return false;     }
    
    loadedCount = 0;
    while (loadedCount < size && infile >> dict[loadedCount]) 
    {
        loadedCount++;
    }
    
    infile.close();
    return true;
}

int countWords(const string dict[], int size) 
{
    int count = 0;
    for (int i = 0; i < size; i++) 
    {
        if (!dict[i].empty()) 
        {
            count++;
        }
    }
    return count;
}

void printArray(const string dict[], int loadedCount) 
{
    for (int i = 0; i < loadedCount; i++) 
    {
        cout << i + 1 << " " << dict[i] << endl;
    }
}



