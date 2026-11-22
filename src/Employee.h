#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;

struct Employee {
    string id, name, email, phone, department;
    double salary = 0;
    bool paid = false;
    string payrollMonth = "";
    char attendance[31];

    Employee() {
        for (int i = 1; i <= 30; i++) attendance[i] = '-';
    }
};
#endif
