# Employee Management System (Simple DSA C++)

This is a beginner-friendly, menu-driven C++ version of the CS214 Employee Management System. The proposal's page 4 and 5 interface examples are terminal-style screens, so this version keeps the interface simple and focuses on explaining the DSA code. It is not a Windows desktop GUI.

## DSA concepts
- **Array:** `Employee::attendance[31]` stores attendance for days 1-30.
- **Singly linked list:** stores employee records and supports add, search, delete and traversal.
- **Stack:** stores previous attendance values so the latest change can be undone (LIFO).
- **Queue:** stores unpaid employee IDs for payroll processing (FIFO).
- **Binary search tree:** indexes employee IDs and prints them in sorted order using inorder traversal.

## Files
- `src/Employee.h` - employee structure
- `src/LinkedList.h` - linked list of employees
- `src/BST.h` - binary search tree index
- `src/Stack.h` - attendance undo stack
- `src/Queue.h` - payroll queue
- `src/main.cpp` - menus and program logic
- `data/employees.txt` - created automatically for saved records

## Compile (MinGW g++)
Open PowerShell in this folder and run:

```powershell
g++ -std=c++17 src/main.cpp -o EmployeeManagementSystem.exe
.\EmployeeManagementSystem.exe
```

Default login: `admin` / `admin123`.

The program stores records locally in `data/employees.txt`. Attendance undo history is kept during the current run only. This is an academic demonstration, not a production payroll system.
