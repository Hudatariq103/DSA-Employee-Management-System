#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Employee.h"
#include <iostream>
#include <functional>
using namespace std;

class LinkedList {
private:
    struct Node {
        Employee data;
        Node* next;
        Node(Employee e) { data = e; next = nullptr; }
    };
    Node* head;
public:
    LinkedList() { head = nullptr; }
    ~LinkedList() { clear(); }
    void clear() {
        while (head != nullptr) { Node* temp = head; head = head->next; delete temp; }
    }
    bool add(Employee e) {
        if (search(e.id) != nullptr) return false;
        Node* n = new Node(e);
        if (head == nullptr) head = n;
        else { Node* p = head; while (p->next != nullptr) p = p->next; p->next = n; }
        return true;
    }
    Employee* search(string id) {
        Node* p = head;
        while (p != nullptr) { if (p->data.id == id) return &p->data; p = p->next; }
        return nullptr;
    }
    bool remove(string id) {
        Node* p = head; Node* previous = nullptr;
        while (p != nullptr && p->data.id != id) { previous = p; p = p->next; }
        if (p == nullptr) return false;
        if (previous == nullptr) head = p->next; else previous->next = p->next;
        delete p; return true;
    }
    int count() const { int n=0; Node* p=head; while(p){n++;p=p->next;} return n; }
    template <typename Function> void forEach(Function action) { Node* p=head; while(p){ action(p->data); p=p->next; } }
    void display() const {
        if (!head) { cout << "No employees found.\n"; return; }
        cout << "\nID\tName\t\tDepartment\tSalary\tPayroll\n";
        Node* p=head;
        while(p) { cout << p->data.id << "\t" << p->data.name << "\t\t" << p->data.department << "\t\t" << p->data.salary << "\t" << (p->data.paid ? "Paid":"Unpaid") << "\n"; p=p->next; }
    }
};
#endif
