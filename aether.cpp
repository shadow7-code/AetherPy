#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <chrono>
#include <iomanip>

//only supports linux

using namespace std;
using namespace chrono;

void calculateRuntime(const string& pythonFile) {
    string baseName = pythonFile.substr(0, pythonFile.find_last_of("."));
    string exeFile = "./" + baseName;

    cout << "Output..." << endl;
    cout << string(50, '~') << endl;

    auto startPy = high_resolution_clock::now();
    string runPyCmd = "python3 " + pythonFile + " 2> /dev/null";
    system(runPyCmd.c_str());
    auto endPy = high_resolution_clock::now();
    duration<double> pythonTime = endPy - startPy;
    
    auto startCpp = high_resolution_clock::now();
    string runCppCmd = exeFile;
    system(runCppCmd.c_str());
    auto endCpp = high_resolution_clock::now();
    duration<double> cppTime = (endCpp - startCpp);

    cout << string(50, '~') << endl;
    
    cout << "\nCalculating actual runtime..." << endl;
    cout << "\nPython Execution Time: " << pythonTime.count() << " seconds";
    cout << "\nAether Execution Time: " << cppTime.count() << " seconds";
    cout << "\nSpeed-up Factor: " << (pythonTime.count() / cppTime.count()) << "x\n";
}

void compileAndRun(const string& pythonFile) {
    string baseName = pythonFile.substr(0, pythonFile.find_last_of("."));
    string cFile = baseName + ".c";
    string exeFile = baseName;
    
    string cythonCmd = "cython --embed -3 -o " + cFile + " " + pythonFile;
    if (system(cythonCmd.c_str()) != 0) {
        cerr << "Error: Failed to generate C code." << endl;
        return;
    }

    cout << "Compiling code...\n";
    string compileCmd = "g++ -o " + exeFile + " " + cFile +" $(python3-config --includes) " +
                        " $(python3-config --ldflags) -lpython3.10";
    if (system(compileCmd.c_str()) != 0) {
        cerr << "Error: Compilation failed." << endl;
        return;
    }
    
    calculateRuntime(pythonFile);
}

void writePythonToFile(const string& filename) {
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error creating file." << endl;
        return;
    }
    
    cout << "Enter your Python code (end with an empty line):\n";
    string line;
    cin.ignore();
    while (true) {
        getline(cin, line);
        if (line.empty()) break;
        outFile << line << "\n";
    }
    outFile.close();
}

void printHeader() {
    cout << string(50, '*') << endl;
    cout << string(17, ' ') << "AetherPy" << endl;
    cout << string(10, ' ') << "Python Compiler in C++" << endl;
    cout << string(50, '*') << endl << endl;
}

int main() {
    while (true) {
        printHeader();

        cout << "MAIN MENU:" << endl;
        cout << "1. Start Compiler" << endl;
        cout << "2. Exit" << endl;
        cout << "\nChoose an option: ";
        
        int choice;
        cin >> choice;
        
        if (choice == 2) {
            cout << "Exiting..." << endl;
            break;
        } else if (choice == 1) {
            cout << "\nCOMPILER OPTIONS:" << endl;
            cout << "1. Write Python Code in Terminal" << endl;
            cout << "2. Provide Python File Name" << endl;
            cout << "\nChoose an option: ";
            
            int subChoice;
            cin >> subChoice;
            
            string pythonFile;
            if (subChoice == 1) {
                cout << "Enter a filename to save your Python code: ";
                cin >> pythonFile;
                writePythonToFile(pythonFile);
            } else if (subChoice == 2) {
                cout << "Enter Python file name (with .py extension): ";
                cin >> pythonFile;
            } else {
                cout << "Invalid choice. Returning to main menu." << endl;
                continue;
            }
            
            compileAndRun(pythonFile);
            
            cout << "\n" << string(50, '-') << endl;
            cout << "Press Enter to continue...";
            cin.ignore();
            cin.get();
        } else {
            cout << "Invalid choice. Try again." << endl;
            break;
        }
    }
    return 0;
}
