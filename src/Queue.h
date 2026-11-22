#ifndef QUEUE_H
#define QUEUE_H
#include <string>
using namespace std;
class Queue {
private:
    string items[500]; int front, rear, total;
public:
    Queue(){front=0;rear=-1;total=0;}
    bool empty() const{return total==0;}
    void clear(){front=0;rear=-1;total=0;}
    void push(string id){if(total<500){rear=(rear+1)%500;items[rear]=id;total++;}}
    string pop(){if(empty()) return "";string x=items[front];front=(front+1)%500;total--;return x;}
    int size() const{return total;}
};
#endif
