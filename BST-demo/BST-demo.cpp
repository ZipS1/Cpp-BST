#include "../BinarySearchTree/BinarySearchTree.h"
#include "../ConsoleMenu/console-menu.h"

int main()
{
    BinarySearchTree tree;
    tree.insert(1); // Trigger Case 1
    tree.insert(0); // Trigger Case 2
    tree.insert(3); // Trigger Case 2
    tree.insert(2); // Trigger Case 3
    tree.insert(8); // Trigger Case 2
    tree.insert(11); // Trigger Case 3
    tree.insert(7); // Trigger Case 2
    tree.insert(9); // Trigger Case 3 + Case 5 (8)
    tree.insert(10); // Trigger Case 4
}