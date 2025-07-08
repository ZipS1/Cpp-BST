# BalancedBinarySearchTree

## Project Overview  
BalancedBinarySearchTree is an educational C++ implementation of a Red-Black Tree, showcasing self-balancing binary search tree algorithms. It provides insertion, deletion, and search operations with guaranteed *O(log n)* performance, along with a console-based demonstration.

## Prerequisites  
- A C++17-compatible compiler (e.g., MSVC in Visual Studio 2019/2022 or GCC/Clang)  
- Windows SDK (if building with Visual Studio)  

## Building and Running

### Using Visual Studio  
1. Clone the repository:  
   ```bash
   git clone https://github.com/ZipS1/Cpp-BST.git
   cd Cpp-BST
   ```
2. Open `BinarySearchTree.sln` in Visual Studio.  
3. Set `BST-demo` as the startup project.  
4. Build and run (F5) to launch the console demo.

## Technology Stack  

| Component                 | Technology                           |
|---------------------------|--------------------------------------|
| Language                  | C++ (C++17)                          |
| Build System              | Microsoft Visual Studio solution     |
| Console Interface Library | Custom header-only `ConsoleMenu`     |
| Version Control           | Git / GitHub                         |

## Repository Structure  
```
Cpp-BST/
├── BST-demo/                – Console demo project
├── BinarySearchTree/        – Core tree implementation
├── ConsoleMenu/             – Header-only menu interface
├── .gitignore
├── BinarySearchTree.sln     – Visual Studio solution
└── README.md                – Project documentation
```
