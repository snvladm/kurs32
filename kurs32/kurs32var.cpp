#include "FileReading.h"
#include "list.h"
#include "input.h"
#include "people.h"
#include <iostream>
#include <time.h>
#include <vector>
#include <stdlib.h>
#include <locale.h>
#include <fstream>
#include <sstream>
#include <windows.h>
int compChoise;
vector <int> semsNums;

bool compaire(const student& stud1, const student& stud2) {
    if (compChoise == 1) {
        int semNum = semsNums[0] - 1;
        int c1 = 0;
        int c2 = 0;
        for (auto mark = stud1.marks[semNum].begin(); mark != stud1.marks[semNum].end(); mark++) {
            if (mark->mark == 3) c1++;
        }
        for (auto mark = stud2.marks[semNum].begin(); mark != stud2.marks[semNum].end(); mark++) {
            if (mark->mark == 3) c2++;
        }
        return float (c1) / stud1.marks[semNum].size() > float (c2) / stud2.marks[semNum].size();
    }
    if (compChoise == 2) {
        int c1 = 0;
        int c2 = 0;
        int m1 = 0;
        int m2 = 0;

        for (int i = 0; i < 9; i++) {
            int present = 0;
            for (auto sem = semsNums.begin(); sem != semsNums.end(); sem++) {
                if (*sem-1 == i) present = 1;
            }
            if (present == 0) continue;
            m1 += stud1.marks[i].size();
            m2 += stud2.marks[i].size();
            for (auto mark = stud1.marks[i].begin(); mark != stud1.marks[i].end(); mark++) {
                if (mark->mark == 3) c1++;
            }
            for (auto mark = stud2.marks[i].begin(); mark != stud2.marks[i].end(); mark++) {
                if (mark->mark == 3) c2++;
            }
        }
        return float(c1) / m1 > float(c2) / m2;
    }
    if (compChoise == 3) {
        int c1 = 0;
        int c2 = 0;
        int m1 = 0;
        int m2 = 0;

        for (int i = 0; i < 9; i++) {
            m1 += stud1.marks[i].size();
            m2 += stud2.marks[i].size();
            for (auto mark = stud1.marks[i].begin(); mark != stud1.marks[i].end(); mark++) {
                if (mark->mark == 3) c1++;
            }
            for (auto mark = stud2.marks[i].begin(); mark != stud2.marks[i].end(); mark++) {
                if (mark->mark == 3) c2++;
            }
        }
        return float(c1) / m1 > float(c2) / m2;

    }
    return 1;
};

int main() {
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");
    string fileName;
    int menu;
    int sexChoise;
    int i;
    student student;
    int Edit;
    int menuEdit;
    int delStud;
    int semester;
    int semNum;
    int semsNum;
    string Finder;
    cout << "Введите название файла:  ";
    cin >> fileName;
    myList people = fileOpen(fileName);

    do {
        cout << "Ваш список: " << fileName << endl;
        cout << "МЕНЮ\n";
        cout << "1. Добавить студента\n";
        cout << "2. Редактировать информацию\n";
        cout << "3. Удалить запись\n";
        cout << "4. Найти\n";
        cout << "5. Показать все\n";
        cout << "6. Задание\n";
        cout << "7. Выход\n";
        menu = numCheck(cin);
        system("cls");
        switch (menu) {
        case 1: student.newStudent();
            people.push_back(student);
            break;
        case 2: if (people.size() == 0) {
            cout << "Пустой файл. Возврат в главное меню...\n";
            break;
        }
              i = 1;
              for (auto write = people.begin(); write != people.end(); write++, i++) {
                  cout << i << ". ";
                  write->write(cout);
              };
              cout << "Введите номер записи: ";
              Edit = numCheck(cin);
              i = 1;
              for (auto write = people.begin(); write != people.end(); write++, i++) {
                  if (i == Edit) {
                      cout << "Что вы хотите отредактировать?\n";
                      cout << "1. Фамилия студента \n";
                      cout << "2. Имя студента \n";
                      cout << "3. Отчество студента \n";
                      cout << "4. Дата рождения студента \n";
                      cout << "5. Год начала обучения \n";
                      cout << "6. Факультет \n";
                      cout << "7. Кафедра \n";
                      cout << "8. Группа \n";
                      cout << "9. Номер зачетной книжки \n";
                      cout << "10.Пол \n";
                      cout << "11.Оценки \n";
                      cout << "12.Добавить оценки нового для нового семестра\n";
                      menuEdit = numCheck(cin);
                      switch (menuEdit) {
                      case 1: cout << "Введите новую информацию >> ";
                          cin >> write->surname;
                          break;
                      case 2: cout << "Введите новую информацию >> ";
                          cin >> write->name;
                          break;
                      case 3: cout << "Введите новую информацию >> ";
                          cin >> write->middleName;
                          break;
                      case 4: cout << "Введите новую информацию >> ";
                          cin >> write->birthday;
                          break;
                      case 5: cout << "Введите новую информацию >> ";
                          write->startYear = numCheck(cin);
                          break;
                      case 6: cout << "Введите новую информацию >> ";
                          cin >> write->faculty;
                          break;
                      case 7: cout << "Введите новую информацию >> ";
                          cin >> write->cathedra;
                          break;
                      case 8: cout << "Введите новую информацию >> ";
                          cin >> write->group;
                          break;
                      case 9: cout << "Введите новую информацию >> ";
                          cin >> write->studID;
                          break;
                      case 10: cout << "Введите новую информацию >> ";
                          cin >> write->sex;
                          break;
                      case 11: cout << "Выберите семестр: \n";
                          semester = numCheck(cin);
                          cout << "Выберите номер предмета: \n";
                          i = 1;
                          for (auto mark = write->marks[semester - 1].begin(); mark != write->marks[semester - 1].end(); mark++, i++)
                              cout << i << ". " << mark->name << " " << mark->mark << endl;
                          menuEdit = numCheck(cin);
                          i = 1;
                          for (auto mark = write->marks[semester - 1].begin(); mark != write->marks[semester - 1].end(); mark++, i++)
                              if (i == menuEdit) {
                                  cout << "Введите новую оценку: \n";
                                  mark->mark = numCheck(cin);
                                  break;
                              };
                          break;
                      case 12:
                          lessons lesName;
                          for (i = 0; i < 9; i++)
                              if (write->marks[i].size() == 0)
                                  break;
                          if (i == 9) {
                              cout << "Свободных семестров нет!";
                              break;
                          }
                          cout << "|      Ввод новых оценок...Чтобы выйти введите 0     |\n";
                          while (1) {
                              cout << "Введите название предмета: \n";
                              cin >> lesName.name;
                              if (lesName.name == "0")
                                  break;
                              cout << "Введите оценку:  \n";
                              lesName.mark = numCheck(cin);
                              write->marks[i].push_back(lesName);
                          }
                          break;
                      }
                      break;
                  }
              }
              break;
        case 3:if (people.size() == 0) {
            cout << "Список студентов пуст. Возврат в главное меню...\n";
            break;
        }
              i = 1;
              for (auto write = people.begin(); write != people.end(); write++, i++) {
                  cout << i << ". ";
                  write->write(cout);
              };
              cout << "Выбери номер записи для удаления: ";
              delStud = numCheck(cin);
              i = 1;
              for (auto write = people.begin(); write != people.end(); write++, i++) {
                  if (i == delStud) { people.erase(write); break; }
              }
              break;
        case 4:if (people.size() == 0) {
            cout << "Список студентов пуст. Возврат в главное меню...\n";
            break;
        }
              cout << "Введите номер зачетной книжки или фамилию для поиска студента: ";
              cin >> Finder;
              for (auto write = people.begin(); write != people.end(); write++) {
                  if (Finder == write->studID) {
                      write->write(cout);
                      break;
                  };
                  if (Finder == write->surname) {
                      write->write(cout);
                  };
              }
              break;
        case 5: if (people.size() == 0) {
            cout << "Список студентов пуст. Возврат в главное меню...\n";
            break;
        }
              i = 1;
              for (auto write = people.begin(); write != people.end(); write++, i++) {
                  cout << i << ". ";
                  write->write(cout);
              }
              break;
        case 6:
            int semNum;
            if (people.size() == 0) {
                cout << "Список студентов пуст. Возврат в главное меню...\n";
                break;
            }
            cout << "Выберите пол студента:\n";
            cout << "1. Мужчины\n";
            cout << "2. Женщины\n";
            sexChoise = numCheck(cin);
            cout << "Выберите вариант сортировки:\n";
            cout << "1. Один семестр\n";
            cout << "2. Несколько семестров\n";
            cout << "3. Все семестры\n";
            compChoise = numCheck(cin);
            if (compChoise == 1) {
                cout << "Выберете номер семестра\n";
                semsNums.clear();               
                semNum = numCheck(cin);
                semsNums.push_back(semNum);
            }
            if (compChoise == 2) {
                cout << "Сколько семестров вам нужно отсортировать?\n";
                semsNum = numCheck(cin);
                cout << "Введите номера семестров:\n";
                semsNums.clear();
                for (i = 0; i < semsNum; i++) {
                    semNum = numCheck(cin);
                    semsNums.push_back(semNum);
                }
            }
            myList Select;
            for (auto write = people.begin(); write != people.end(); write++) {
                int isFem = write->sex == "М" && sexChoise == 1 || write->sex == "Ж" && sexChoise == 2;
                
                if (isFem == 1)
                    Select.push_back(*write);
            }
            Select.sort(compaire);
            i = 1;
            for (auto write = Select.begin(); write != Select.end(); write++, i++) {
                cout << i << ". ";
                write->write(cout);
            }
            break;
        };
    } while (menu != 7);
    ofstream fileWrite;
    fileWrite.open(fileName, ios_base::binary);
    ostringstream inFlow;
    for (auto write = people.begin(); write != people.end(); write++)
        write->write(fileWrite);
    return 0;
};

