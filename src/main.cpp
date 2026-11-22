
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <cctype>
#include <limits>

using namespace std;

// Heading background colors
const string RESET = "\033[0m";
const string BG_TEAL = "\033[48;2;22;68;91m";
const string WHITE_BOLD = "\033[97;1m";

// ================= EMPLOYEE STRUCTURE =================

struct Employee {
    string id;
    string name;
    string email;
    string phone;
    string department;
    double salary;
    bool paid;
    string payrollMonth;
    char attendance[31];

    Employee() {
        salary = 0;
        paid = false;
        payrollMonth = "";

        for (int i = 0; i <= 30; i++) {
            attendance[i] = '-';
        }
    }
};

// ================= LINKED LIST =================

class LinkedList {
public:
    struct Node {
        Employee data;
        Node* next;

        Node(Employee e) {
            data = e;
            next = NULL;
        }
    };

    Node* head;

    LinkedList() {
        head = NULL;
    }

    void add(Employee e) {
        Node* newNode = new Node(e);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    Employee* search(string id) {
        Node* temp = head;

        while (temp != NULL) {
            if (temp->data.id == id) {
                return &temp->data;
            }

            temp = temp->next;
        }

        return NULL;
    }

    bool remove(string id) {
        if (head == NULL) {
            return false;
        }

        if (head->data.id == id) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return true;
        }

        Node* temp = head;

        while (temp->next != NULL) {
            if (temp->next->data.id == id) {
                Node* del = temp->next;
                temp->next = del->next;
                delete del;
                return true;
            }

            temp = temp->next;
        }

        return false;
    }

    int count() {
        int total = 0;
        Node* temp = head;

        while (temp != NULL) {
            total++;
            temp = temp->next;
        }

        return total;
    }

    void display() {
        if (head == NULL) {
            cout << "No employees found.\n";
            return;
        }

        Node* temp = head;

        cout << "\n========== EMPLOYEE RECORDS ==========\n";

        while (temp != NULL) {
            Employee e = temp->data;

            cout << "\nID: " << e.id;
            cout << "\nName: " << e.name;
            cout << "\nEmail: " << e.email;
            cout << "\nPhone: " << e.phone;
            cout << "\nDepartment: " << e.department;
            cout << "\nSalary: " << e.salary;
            cout << "\nPayroll: ";

            if (e.paid) {
                cout << "Paid";
            }
            else {
                cout << "Unpaid";
            }

            cout << "\n-----------------------------\n";

            temp = temp->next;
        }
    }
};

// ================= BINARY SEARCH TREE =================

class BST {
private:
    struct Node {
        string id;
        Node* left;
        Node* right;

        Node(string value) {
            id = value;
            left = NULL;
            right = NULL;
        }
    };

    Node* root;

    Node* insertNode(Node* root, string id) {
        if (root == NULL) {
            return new Node(id);
        }

        if (id < root->id) {
            root->left = insertNode(root->left, id);
        }
        else if (id > root->id) {
            root->right = insertNode(root->right, id);
        }

        return root;
    }

    bool searchNode(Node* root, string id) {
        if (root == NULL) {
            return false;
        }

        if (root->id == id) {
            return true;
        }

        if (id < root->id) {
            return searchNode(root->left, id);
        }

        return searchNode(root->right, id);
    }

    void displayInOrder(Node* root) {
        if (root == NULL) {
            return;
        }

        displayInOrder(root->left);
        cout << root->id << endl;
        displayInOrder(root->right);
    }

    void clearTree(Node* root) {
        if (root == NULL) {
            return;
        }

        clearTree(root->left);
        clearTree(root->right);
        delete root;
    }

public:
    BST() {
        root = NULL;
    }

    void insert(string id) {
        root = insertNode(root, id);
    }

    bool search(string id) {
        return searchNode(root, id);
    }

    void displaySorted() {
        if (root == NULL) {
            cout << "No employee IDs found.\n";
            return;
        }

        cout << "\nEmployee IDs in sorted order:\n";
        displayInOrder(root);
    }

    void clear() {
        clearTree(root);
        root = NULL;
    }
};

// ================= STACK =================

struct AttendanceChange {
    string employeeID;
    int day;
    char oldValue;
};

class Stack {
private:
    struct Node {
        AttendanceChange data;
        Node* next;

        Node(AttendanceChange value) {
            data = value;
            next = NULL;
        }
    };

    Node* topNode;

public:
    Stack() {
        topNode = NULL;
    }

    void push(AttendanceChange value) {
        Node* newNode = new Node(value);
        newNode->next = topNode;
        topNode = newNode;
    }

    AttendanceChange pop() {
        AttendanceChange value = topNode->data;

        Node* temp = topNode;
        topNode = topNode->next;

        delete temp;

        return value;
    }

    bool empty() {
        return topNode == NULL;
    }
};

// ================= QUEUE =================

class Queue {
private:
    struct Node {
        string id;
        Node* next;

        Node(string value) {
            id = value;
            next = NULL;
        }
    };

    Node* frontNode;
    Node* rearNode;
    int total;

public:
    Queue() {
        frontNode = NULL;
        rearNode = NULL;
        total = 0;
    }

    void push(string id) {
        Node* newNode = new Node(id);

        if (rearNode == NULL) {
            frontNode = rearNode = newNode;
        }
        else {
            rearNode->next = newNode;
            rearNode = newNode;
        }

        total++;
    }

    string pop() {
        if (frontNode == NULL) {
            return "";
        }

        Node* temp = frontNode;
        string id = temp->id;

        frontNode = frontNode->next;

        if (frontNode == NULL) {
            rearNode = NULL;
        }

        delete temp;
        total--;

        return id;
    }

    bool empty() {
        return frontNode == NULL;
    }

    int size() {
        return total;
    }

    void clear() {
        while (!empty()) {
            pop();
        }
    }
};

// ================= GLOBAL OBJECTS =================

LinkedList employees;
BST employeeTree;
Stack undoStack;
Queue payrollQueue;

// ================= INPUT VALIDATION =================

bool isDigits(string value) {
    if (value.empty()) {
        return false;
    }

    for (int i = 0; i < value.length(); i++) {
        if (!isdigit(static_cast<unsigned char>(value[i]))) {
            return false;
        }
    }

    return true;
}

// ================= DATE FUNCTIONS =================

string currentMonth() {
    time_t now = time(0);
    tm* t = localtime(&now);

    stringstream ss;

    ss << t->tm_year + 1900 << "-";
    ss << setw(2) << setfill('0') << t->tm_mon + 1;

    return ss.str();
}

int currentDay() {
    time_t now = time(0);
    tm* t = localtime(&now);

    return t->tm_mday;
}

// ================= SAVE DATA =================

void saveData() {
    ofstream out("data/employees.txt");

    LinkedList::Node* temp = employees.head;

    while (temp != NULL) {
        Employee e = temp->data;

        out << e.id << '|'
            << e.name << '|'
            << e.email << '|'
            << e.phone << '|'
            << e.department << '|'
            << e.salary << '|'
            << (e.paid ? 1 : 0) << '|'
            << e.payrollMonth << '|';

        for (int d = 1; d <= 30; d++) {
            out << e.attendance[d];
        }

        out << "\n";

        temp = temp->next;
    }

    out.close();
}

// ================= LOAD DATA =================

void loadData() {
    ifstream in("data/employees.txt");

    if (!in.is_open()) {
        return;
    }

    string line;

    while (getline(in, line)) {
        stringstream ss(line);

        Employee e;

        string salary;
        string paid;
        string attendance;

        getline(ss, e.id, '|');
        getline(ss, e.name, '|');
        getline(ss, e.email, '|');
        getline(ss, e.phone, '|');
        getline(ss, e.department, '|');
        getline(ss, salary, '|');
        getline(ss, paid, '|');
        getline(ss, e.payrollMonth, '|');
        getline(ss, attendance);

        if (e.id.empty()) {
            continue;
        }

        e.salary = atof(salary.c_str());
        e.paid = (paid == "1");

        for (int d = 1; d <= 30 && d - 1 < (int)attendance.length(); d++) {
            e.attendance[d] = attendance[d - 1];
        }

        employees.add(e);
        employeeTree.insert(e.id);
    }

    in.close();
}

// ================= LOGIN =================

void login() {
    string username;
    string password;

    cout << "\n========== ADMIN LOGIN ==========\n";

    cout << "Username: ";
    cin >> username;

    cout << "Password: ";
    cin >> password;

    if (username != "admin" || password != "admin123") {
        cout << "\nIncorrect login. Program closing.\n";
        exit(0);
    }

    cout << "\nLogin successful!\n";
}

// ================= ADD EMPLOYEE =================

void addEmployee() {
    Employee e;
    string input;

    cout << "\n========== ADD NEW EMPLOYEE ==========\n";
    cout << "Enter 0 at any step to cancel.\n";

    // Employee ID
    while (true) {
        cout << "\nEmployee ID (6 digits): ";
        cin >> input;

        if (input == "0") {
            cout << "Employee addition cancelled.\n";
            return;
        }

        if (input.length() != 6 || !isDigits(input)) {
            cout << "\nInvalid Employee ID! It must contain exactly 6 digits.\n";
            cout << "Please enter again.\n";
            continue;
        }

        if (employeeTree.search(input)) {
            cout << "\nThis Employee ID already exists.\n";
            cout << "Please enter another ID.\n";
            continue;
        }

        e.id = input;
        break;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Employee Name
    while (true) {
        cout << "\nFull Name: ";
        getline(cin, input);

        if (input == "0") {
            cout << "Employee addition cancelled.\n";
            return;
        }

        e.name = input;
        break;
    }

    // Email
    while (true) {
        cout << "\nEmail Address: ";
        getline(cin, input);

        if (input == "0") {
            cout << "Employee addition cancelled.\n";
            return;
        }

        if (input.find('@') == string::npos) {
            cout << "\nInvalid Email! Email must contain @.\n";
            cout << "Please enter again.\n";
            continue;
        }

        e.email = input;
        break;
    }

    // Phone Number
    while (true) {
        cout << "\nPhone Number (7 digits): ";
        cin >> input;

        if (input == "0") {
            cout << "Employee addition cancelled.\n";
            return;
        }

        if (input.length() != 7 || !isDigits(input)) {
            cout << "\nInvalid Phone Number! It must contain exactly 7 digits.\n";
            cout << "Please enter again.\n";
            continue;
        }

        e.phone = input;
        break;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Department
    while (true) {
        cout << "\nDepartment: ";
        getline(cin, input);

        if (input == "0") {
            cout << "Employee addition cancelled.\n";
            return;
        }

        e.department = input;
        break;
    }

    // Monthly Salary
    while (true) {
        cout << "\nMonthly Salary: ";
        cin >> input;

        if (input == "0") {
            cout << "Employee addition cancelled.\n";
            return;
        }

        if (!isDigits(input)) {
            cout << "\nInvalid Salary! Salary must contain digits only.\n";
            cout << "Please enter again.\n";
            continue;
        }

        e.salary = atof(input.c_str());
        break;
    }

    // Save Employee
    employees.add(e);
    employeeTree.insert(e.id);

    saveData();

    cout << "\n====================================\n";
    cout << "Employee added successfully!\n";
    cout << "Employee ID: " << e.id << endl;
    cout << "Name: " << e.name << endl;
    cout << "====================================\n";
}

// ================= EDIT EMPLOYEE =================

void editEmployee() {
    string id, input;

    cout << "\nEnter Employee ID: ";
    cin >> id;

    Employee* e = employees.search(id);

    if (e == NULL) {
        cout << "Employee not found.\n";
        return;
    }

    Employee updated = *e;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\nEditing Employee: " << updated.id << endl;
    cout << "Employee ID cannot be changed.\n";
    cout << "Enter 0 at any step to cancel.\n";

    cout << "\nNew Name: ";
    getline(cin, input);
    if (input == "0") {
        cout << "Editing cancelled. No changes saved.\n";
        return;
    }
    updated.name = input;

    while (true) {
        cout << "New Email: ";
        getline(cin, input);

        if (input == "0") {
            cout << "Editing cancelled. No changes saved.\n";
            return;
        }
        if (input.find('@') == string::npos) {
            cout << "Invalid Email! Email must contain @. Please try again.\n";
            continue;
        }
        updated.email = input;
        break;
    }

    while (true) {
        cout << "New Phone Number (7 digits): ";
        getline(cin, input);

        if (input == "0") {
            cout << "Editing cancelled. No changes saved.\n";
            return;
        }
        if (input.length() != 7 || !isDigits(input)) {
            cout << "Invalid Phone Number! It must contain exactly 7 digits.\n";
            continue;
        }
        updated.phone = input;
        break;
    }

    cout << "New Department: ";
    getline(cin, input);
    if (input == "0") {
        cout << "Editing cancelled. No changes saved.\n";
        return;
    }
    updated.department = input;

    while (true) {
        cout << "New Monthly Salary: ";
        getline(cin, input);

        if (input == "0") {
            cout << "Editing cancelled. No changes saved.\n";
            return;
        }
        if (!isDigits(input)) {
            cout << "Invalid Salary! Enter digits only. Please try again.\n";
            continue;
        }
        updated.salary = atof(input.c_str());
        break;
    }

    *e = updated;
    saveData();
    cout << "\nEmployee updated successfully.\n";
}
// ================= DELETE EMPLOYEE =================

void deleteEmployee() {
    string id;

    cout << "\nEnter Employee ID: ";
    cin >> id;

    if (!employees.remove(id)) {
        cout << "Employee not found.\n";
        return;
    }

    employeeTree.clear();

    LinkedList::Node* temp = employees.head;

    while (temp != NULL) {
        employeeTree.insert(temp->data.id);
        temp = temp->next;
    }

    saveData();

    cout << "Employee deleted successfully.\n";
}

// ================= SEARCH EMPLOYEE =================

void searchEmployee() {
    string id;

    cout << "\nEnter Employee ID: ";
    cin >> id;

    if (!employeeTree.search(id)) {
        cout << "Employee not found in BST.\n";
        return;
    }

    Employee* e = employees.search(id);

    if (e != NULL) {
        cout << "\nEmployee Found!\n";
        cout << "ID: " << e->id << endl;
        cout << "Name: " << e->name << endl;
        cout << "Department: " << e->department << endl;
        cout << "Salary: " << e->salary << endl;
    }
}

// ================= ATTENDANCE MENU =================

void attendanceMenu() {
    int choice;

    cout << "\n========== ATTENDANCE ==========\n";
    cout << "1. Mark Attendance\n";
    cout << "2. View Attendance\n";
    cout << "3. Undo Latest Change\n";
    cout << "0. Back\n";
    cout << "Choice: ";

    cin >> choice;

    if (choice == 1) {
        string id;
        int day;
        char value;

        cout << "Employee ID: ";
        cin >> id;

        Employee* e = employees.search(id);

        if (e == NULL) {
            cout << "Employee not found.\n";
            return;
        }

        cout << "Day (1-30): ";
        cin >> day;

        if (day < 1 || day > 30) {
            cout << "Invalid day.\n";
            return;
        }

        cout << "P = Present, A = Absent: ";
        cin >> value;

        value = toupper(static_cast<unsigned char>(value));

        if (value != 'P' && value != 'A') {
            cout << "Invalid attendance status.\n";
            return;
        }

        AttendanceChange change;

        change.employeeID = id;
        change.day = day;
        change.oldValue = e->attendance[day];

        undoStack.push(change);

        e->attendance[day] = value;

        saveData();

        cout << "Attendance marked successfully.\n";
    }

    else if (choice == 2) {
        string id;

        cout << "Employee ID: ";
        cin >> id;

        Employee* e = employees.search(id);

        if (e == NULL) {
            cout << "Employee not found.\n";
            return;
        }

        int present = 0;
        int absent = 0;

        cout << "\n========== ATTENDANCE RECORD ==========\n";

        for (int d = 1; d <= 30; d++) {
            cout << "Day " << d << ": ";

            if (e->attendance[d] == 'P') {
                cout << "Present";
                present++;
            }
            else if (e->attendance[d] == 'A') {
                cout << "Absent";
                absent++;
            }
            else {
                cout << "Not marked";
            }

            cout << endl;
        }

        cout << "\nPresent: " << present;
        cout << "\nAbsent: " << absent << endl;
    }

    else if (choice == 3) {
        if (undoStack.empty()) {
            cout << "Nothing to undo.\n";
            return;
        }

        AttendanceChange change = undoStack.pop();

        Employee* e = employees.search(change.employeeID);

        if (e != NULL) {
            e->attendance[change.day] = change.oldValue;

            saveData();

            cout << "Last attendance change undone.\n";
        }
    }
}

// ================= PAYROLL MENU =================

void payrollMenu() {
    int choice;

    cout << "\n========== PAYROLL MANAGEMENT ==========\n";
    cout << "1. View Employees and Payroll\n";
    cout << "2. Build Payroll Queue\n";
    cout << "3. Process Payroll\n";
    cout << "0. Back\n";
    cout << "Choice: ";

    cin >> choice;

    if (choice == 1) {
        employees.display();
    }

    else if (choice == 2) {
        payrollQueue.clear();

        LinkedList::Node* temp = employees.head;

        while (temp != NULL) {
            Employee e = temp->data;

            if (!(e.paid && e.payrollMonth == currentMonth())) {
                payrollQueue.push(e.id);
            }

            temp = temp->next;
        }

        cout << "Payroll queue created.\n";
        cout << "Employees waiting: " << payrollQueue.size() << endl;
    }

    else if (choice == 3) {
        if (payrollQueue.empty()) {
            LinkedList::Node* temp = employees.head;

            while (temp != NULL) {
                Employee e = temp->data;

                if (!(e.paid && e.payrollMonth == currentMonth())) {
                    payrollQueue.push(e.id);
                }

                temp = temp->next;
            }
        }

        if (payrollQueue.empty()) {
            cout << "No unpaid employees.\n";
            return;
        }

        while (!payrollQueue.empty()) {
            string id = payrollQueue.pop();

            Employee* e = employees.search(id);

            if (e != NULL && !(e->paid && e->payrollMonth == currentMonth())) {
                e->paid = true;
                e->payrollMonth = currentMonth();

                cout << "Paid: " << e->id << " - " << e->name << endl;
            }
        }

        saveData();

        cout << "\nPayroll processing completed.\n";
    }
}

// ================= DASHBOARD =================

void dashboard() {
    int present = 0;
    int absent = 0;
    int paid = 0;
    int unpaid = 0;

    int day = currentDay();

    if (day > 30) {
        day = 30;
    }

    LinkedList::Node* temp = employees.head;

    while (temp != NULL) {
        Employee e = temp->data;

        if (e.attendance[day] == 'P') {
            present++;
        }

        if (e.attendance[day] == 'A') {
            absent++;
        }

        if (e.paid && e.payrollMonth == currentMonth()) {
            paid++;
        }
        else {
            unpaid++;
        }

        temp = temp->next;
    }

    cout << "\n========== EMPLOYEE DASHBOARD ==========\n";

    cout << "Total Employees: " << employees.count() << endl;
    cout << "Present Today: " << present << endl;
    cout << "Absent Today: " << absent << endl;
    cout << "Paid This Month: " << paid << endl;
    cout << "Unpaid This Month: " << unpaid << endl;
}

// ================= MAIN FUNCTION =================

int main() {

    system("if not exist data mkdir data");

    loadData();

    login();

    int choice;

    do {
        const int bannerWidth = 52;
        const string title = "EMPLOYEE MANAGEMENT SYSTEM";
        const int leftSpace = (bannerWidth - static_cast<int>(title.length())) / 2;
        const int rightSpace = bannerWidth - static_cast<int>(title.length()) - leftSpace;

        cout << "\n";
        cout << "\033[48;2;8;126;139m" << string(8, ' ')
             << "\033[48;2;22;138;173m" << string(9, ' ')
             << "\033[48;2;67;97;168m" << string(9, ' ')
             << "\033[48;2;118;86;168m" << string(9, ' ')
             << "\033[48;2;176;74;133m" << string(9, ' ')
             << "\033[48;2;209;107;74m" << string(8, ' ') << RESET << "\n";

        cout << BG_TEAL << WHITE_BOLD
             << string(leftSpace, ' ') << title << string(rightSpace, ' ')
             << RESET << "\n";


        cout << "1. Dashboard\n";
        cout << "2. Add Employee\n";
        cout << "3. View Employees\n";
        cout << "4. Edit Employee\n";
        cout << "5. Delete Employee\n";
        cout << "6. Search Employee (BST)\n";
        cout << "7. Attendance Management\n";
        cout << "8. Payroll Management\n";
        cout << "9. Display Sorted Employee IDs (BST)\n";
        cout << "0. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                dashboard();
                break;

            case 2:
                addEmployee();
                break;

            case 3:
                employees.display();
                break;

            case 4:
                editEmployee();
                break;

            case 5:
                deleteEmployee();
                break;

            case 6:
                searchEmployee();
                break;

            case 7:
                attendanceMenu();
                break;

            case 8:
                payrollMenu();
                break;

            case 9:
                employeeTree.displaySorted();
                break;

            case 0:
                saveData();
                cout << "\nData saved. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
