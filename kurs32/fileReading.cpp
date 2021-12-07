#include "fileReading.h"
#include "people.h"
#include "List.h"
#include <fstream>
#include <sstream>

myList fileOpen(string fileName) {
    string line;
    myList people;
    ifstream file;
    file.open(fileName, ios_base::binary);
    if (!file.good()) {
        cout << "¬веденный файл не найден! Ѕудет создан новый список.\n";
        return(people);}
    string str;
    while (!(file.eof())) {
        student student;
        getline(file, line);
        istringstream studLine(line);
        student.read(studLine);
        if (!(file.eof()))
            people.push_back(student);}
    file.close();
    return(people);}

