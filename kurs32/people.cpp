#include "people.h"
#include "input.h"

void student::newStudent() {
    cout << "Данные нового студента: \n";
    cout << "Фамилия: ";
    cin >> surname;
    cout << "Имя: ";
    cin >> name;
    cout << "Отчество: ";
    cin >> middleName;
    cout << "Дата рождения: ";
    cin >> birthday;
    cout << "Год начала обучения: ";
    startYear = numCheck(cin);
    cout << "Факультет: ";
    cin >> faculty;
    cout << "Кафедра: ";
    cin >> cathedra;
    cout << "Группа: ";
    cin >> group;
    cout << "Номер зачетной книжки: ";
    cin >> studID;
    cout << "Пол: ";
    cin >> sex;}