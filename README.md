# Cpp-Hashtable

**A C++ open-addressing hash table implementation for educational purposes.**

## Project Description  
Cpp-Hashtable implements a templated hash table with string keys using quadratic probing for collision resolution. It supports insertion, removal, lookup, iteration, automatic resizing, and throws exceptions on missing keys or full tables.

## Getting Started

### Prerequisites  
- A C++17-compatible compiler (e.g., GCC, Clang, MSVC)  
- Git  

### Building and Running on Windows  
1. Clone the repository:  
   ```bash
   git clone https://github.com/ZipS1/Cpp-Hashtable.git
   cd Cpp-Hashtable
   ```
2. Open **hashtable.sln** in Visual Studio.  
3. Build the **HashTable** and **demo** projects.  
4. Run the console demo:  
   ```bash
   demo\Debug\demo.exe
   ```
5. To run tests, build and execute **HashTableTests** in Visual Studio.

## Technology Stack

| Component       | Details                                                        |
|-----------------|----------------------------------------------------------------|
| Language        | C++17                                                          |
| Build (Windows) | MSBuild via Visual Studio solution (`hashtable.sln`)           |
| Testing         | Microsoft Unit Testing Framework (`HashTableTests`)            |
| CI/CD           | GitHub Actions (`.github/workflows/tests.yml`)                 |
