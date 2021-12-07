#include <string>
#include <iostream>
#include <list>
#pragma once
using namespace std;
struct lessons {
    lessons(string les, int marc) {
        name = les;
        mark = marc;}
    lessons() {
        mark = 0;}
    string name;
    int mark;};
class student {
public:
    string surname;
    string name;
    string middleName;
    string birthday;
    int startYear;
    string faculty;
    string cathedra;
    string group;
    string studID;
    string sex;
    list<lessons> marks[9];
    void read(istream& file) {
        string sem;
        string les;
        int mark;
        int i = 0;
        file >> surname >> name >> middleName >> birthday >> startYear >> faculty >> cathedra >> group >> studID >> sex;
        file >> sem;
        file >> les;
        while (!(file.eof()) && i < 9) {
            while (les != "//" && !file.eof() && les != "") {
                file >> mark;
                marks[i].push_back(lessons(les, mark));
                file >> les;}
            file >> les;
            i++;}}
    void newStudent();
    void write(ostream& file) {
        int notEmpty;
        for (notEmpty = 8; notEmpty >= 0; notEmpty--) {
            if (marks[notEmpty].size() != 0)
                break;}
        file << surname << " " << name << " " << middleName << " " << birthday << " " << startYear << " " << faculty << " " << cathedra << " " << group << " " << studID << " " << sex << " " << "//";
        for (int i = 0; i <= notEmpty; i++) {
            for (auto write = marks[i].begin(); write != marks[i].end(); write++)
                file << " " << write->name << " " << write->mark;
            file << " //";}
        file << endl;}};
