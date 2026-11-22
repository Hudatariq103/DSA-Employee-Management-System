#ifndef STACK_H
#define STACK_H
#include <string>
using namespace std;
struct AttendanceChange { string employeeID; int day; char oldValue; };
class Stack {
private:
    AttendanceChange items[500];
    int top;
public:
    Stack(){top=-1;}
    bool empty() const{return top==-1;}
    void push(AttendanceChange x){if(top<499) items[++top]=x;}
    AttendanceChange pop(){return items[top--];}
};
#endif
