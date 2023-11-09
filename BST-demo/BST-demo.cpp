#include "../BinarySearchTree/BinarySearchTree.h"
#include "../ConsoleMenu/console-menu.h"
#include <vector>

#pragma region FuncDeclarations
void insert(BinarySearchTree&);
void symmetricWalk(BinarySearchTree&);
void walkInWidth(BinarySearchTree&);
void average(BinarySearchTree&);
void distanceToValue(BinarySearchTree&);
void getSize(BinarySearchTree&);
#pragma endregion

int main()
{
    std::vector<std::string> menuItems{ "Insert...", "Symmetric walk", "Walk in width", "Average", "Distance to value...", "Size"};
    std::vector<void (*)(BinarySearchTree&)> functions{ &insert, &symmetricWalk, &walkInWidth, &average, &distanceToValue, &getSize };
  
    BinarySearchTree tree;
    ConsoleMenu::ConsoleMenu<BinarySearchTree&> menu(menuItems, functions);
    menu.run(tree);
}

void insert(BinarySearchTree& tree)
{
    std::cout << "Enter a value to insert: ";
    int value;
    std::cin >> value;
    bool isOk = tree.insert(value);
    
    if (isOk)
        std::cout << "Success!" << std::endl;
    else
        std::cout << "Value already in tree!" << std::endl;
}

void symmetricWalk(BinarySearchTree& tree)
{
    std::cout << "--- Symmetric walk ---" << std::endl;
    tree.outputSymmetricWalk();
    std::cout << std::endl;
}

void walkInWidth(BinarySearchTree& tree)
{
    std::cout << "--- Walk in width ---" << std::endl;
    tree.outputWalkInWidth();
    std::cout << std::endl;
}

void average(BinarySearchTree& tree)
{
    bool isOk;
    float average = tree.getAverage(&isOk);
    if (isOk)
        std::cout << "Average: " << average << std::endl;
    else
        std::cout << "Tree is empty!" << std::endl;
}

void distanceToValue(BinarySearchTree& tree)
{
    std::cout << "Enter value to calculate distance for: ";
    int value;
    std::cin >> value;
    
    int distance = tree.distanceToValue(value);
    if (distance < 0)
        std::cout << "No such value in tree!" << std::endl;
    else
        std::cout << "Distance to value " << value << ": " << distance << std::endl;
}

void getSize(BinarySearchTree& tree)
{
    std::cout << "Tree size: " << tree.getSize() << std::endl;
}