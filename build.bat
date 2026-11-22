@echo off
cd /d "%~dp0"
g++ -std=c++17 src/main.cpp -o EmployeeManagementSystem.exe
if errorlevel 1 (
  echo Build failed. Check the compiler errors above.
  pause
  exit /b 1
)
EmployeeManagementSystem.exe
pause
