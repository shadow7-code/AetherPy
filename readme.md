# Aether Py

Aether Py is a Python compiler written entirely in C++. It takes Python code as input, converts it to C code using Cython, compiles it with g++, and executes it, providing the output in the terminal.

## Features
- Fully functional Python compiler built in C++
- Converts Python code to C using Cython
- Compiles and runs the C code using g++
- Supports all Python data types and arithmetic operations
- REPL mode for interactive execution

## Installation
To use Aether Py, ensure you have the following dependencies installed:
- **C++ compiler (g++)**
- **Cython**
- **Python 3.x**

Clone the repository and navigate to the project folder:
```sh
git clone https://github.com/your-repository/AetherPy.git
cd AetherPy
```

## Usage
1. Compile the project:
   ```sh
   g++ -o AetherPy src/*.cpp
   ```
2. Run Aether Py:
   ```sh
   ./AetherPy
   ```
3. Enter Python code when prompted and view the output.

## Test Files
Test cases are available in the  directory on the GitHub repository. These test files (`test1.py`, `test2.py`, `test3.py`) cover various Python code scenarios to validate the compiler's functionality. Run them using:
```sh
./AetherPy < tests/test1.py
./AetherPy < tests/test2.py
./AetherPy < tests/test3.py
```

## Contributing
Feel free to contribute by submitting pull requests or reporting issues on the GitHub repository.

---
**GitHub Repository:** [Aether Py on GitHub](https://github.com/shadow7-code/AetherPy)

