#pragma once
#include <iostream>
#include <queue>

/* --- УСТРОЙСТВО ДЕРЕВА ---
* Источник: https://www.youtube.com/watch?v=0BUX_PotA4c
* Балансировка дерева: https://clck.ru/36Trxy
* 
* Красно-черное дерево состоит из красных и черных узлов.
* Правила КЧ дерева:
* 1. Листом в КЧ дереве является несуществующий узел (nullptr)
* 2. Корень и лист черного цвета
* 3. У красного узла оба ребенка - черные
* 
* -------------------------------------------------------------------------
* Черная высота - количество черных узлов от исходного до null включительно.
* Исходный узел при этом не считается. Т.е. в дереве формата:
* 
*                          Ч
*                         / \
*                        К   К
*                       /     \
*                    null(Ч) null(Ч)
* 
* Черная высота корня равна 1
* -------------------------------------------------------------------------
* 
* 4. Черная высота должна быть одинакова для левой/правой стороны.
* 
* -------------------------------------------------------------------------
* Дерево называется сбалансированным при выполнении правил 1-4.
* Для балансировки дерева применяются перекрашивания цветов
* и левые/правые повороты на узлах.
* -------------------------------------------------------------------------
* 
* --- Код для проверки всех случаев балансировки ---
BinarySearchTree tree;
tree.insert(1); // Trigger Case 1
tree.insert(0); // Trigger Case 2
tree.insert(3); // Trigger Case 2
tree.insert(2); // Trigger Case 3
tree.insert(8); // Trigger Case 2
tree.insert(11); // Trigger Case 3
tree.insert(7); // Trigger Case 2
tree.insert(9); // Trigger Case 3 + Case 5 on Node 8
tree.insert(10); // Trigger Case 4
*/

enum class Color { Red, Black };

enum class Side { Left, Right, Root };

/// <summary>
/// Structure that represents unit of data in BST
/// </summary>
struct Node
{
	Color color = Color::Red;
	int data;
	Node* parent;
	Node* right = nullptr;
	Node* left = nullptr;

	Node(Node* parent, int data) 
	{
		this->parent = parent;
		this->data = data;
	}
};

struct SearchResult 
{
	Node* parent;
	Side side;
};

class BinarySearchTree
{
public:
	/// <summary>
	/// Inserts value into BST
	/// </summary>
	/// <param name="value"></param>
	/// <returns>
	/// True if value inserted. 
	///	False if value already in tree.
	/// </returns>
	bool insert(int value);

	/// <summary>
	/// Output data in format Left Child -> Parent -> Right Child,
	/// starting from the least (bottom-left) node. 
	/// </summary>
	void outputSymmetricWalk();

	/// <summary>
	/// Output data in format Root -> Root Left Child -> Root Right Child and so on 
	/// left to right down to the bottom of the tree.
	/// </summary>
	void outputWalkInWidth();

	/// <summary>
	/// Calculate average of values in tree.
	/// </summary>
	/// <param name="isOk">false if tree is empty</param>
	/// <returns>average of values in tree</returns>
	float getAverage(bool* isOk);

	/// <summary>
	/// Return distance to value in tree
	/// </summary>
	/// <param name="value">to calculate distance for</param>
	/// <returns>ditance to value OR negative number if no such value exists in tree</returns>
	int distanceToValue(int value);
	~BinarySearchTree();

	int getSize() { return size; }
private:
	Node* root = nullptr;
	int size = 0;

	/// <summary>
	/// Recursive function to perform symmetric walk
	/// </summary>
	/// <param name="node">to output</param>
	void outputNodeSymmetric(Node* node);

	/// <summary>
	/// Recursive function to find sum
	/// </summary>
	/// <param name="node">to find sum</param>
	/// <returns>Sum</returns>
	int handleNodeSum(Node* node);

	/// <summary>
	/// Find a place for value in tree. Recursive function
	/// </summary>
	/// <param name="node">- starting point to find place</param>
	/// <param name="value">to find place for</param>
	/// <returns>
	/// Search result with parent of node place and found node place.
	///	Both nullptrs if value is already in tree.
	/// </returns>
	SearchResult findEmptyPlaceFrom(Node* node, Side side, int value);
	
	/// <summary>
	/// Recursive function to get distance to value
	/// </summary>
	/// <param name="start">Node to calculate distance from</param>
	/// <param name="value">Value to find</param>
	/// <returns></returns>
	int stepsToValue(Node* start, int value);

	/// <summary>
	/// Check if BST is balanced and balance if it is not
	/// </summary>
	/// <returns>
	/// True if BST was already balanced. 
	/// False otherwise. 
	/// </returns>
	bool ensureBalanced(Node* newNode);

	/// <summary>
	/// Check if new node is a root, then do balancing
	/// </summary>
	/// <param name="newNode">that was inserted</param>
	/// <returns>True if case matched, false otherwise</returns>
	bool balanceIfCaseFirst(Node* newNode);

	/// <summary>
	/// Check if parent is black, then tree is balanced.
	/// </summary>
	/// <param name="newNode">that was inserted</param>
	/// <returns>True if case matched, false otherwise</returns>
	bool balanceIfCaseSecond(Node* newNode);

	/// <summary>
	/// Check if both parent and uncle are red, then do balancing.
	/// </summary>
	/// <param name="newNode">that was inserted</param>
	/// <returns>True if case matched, false otherwise</returns>
	bool balanceIfCaseThird(Node* newNode);

	/// <summary>
	/// Check if parent is red, uncle are black and node and his parent form a zig.
	/// Transforms tree to Case 5 and resolve using Case 5 algorithm.
	/// </summary>
	/// <param name="newNode">that was inserted</param>
	/// <returns>True if case matched, false otherwise</returns>
	bool balanceIfCaseFourth(Node* newNode);

	/// <summary>
	/// Check if parent is red, uncle is black and node, parent, grandparent form a line to the right or left.
	/// </summary>
	/// <param name="newNode">that was inserted</param>
	/// <returns>True if case matched, false otherwise</returns>
	bool balanceIfCaseFifth(Node* newNode);

	/// <summary>
	/// Perform left rotation on node.
	/// </summary>
	/// <param name="node">to perform rotation on</param>
	void rotateLeft(Node* node);

	/// <summary>
	/// Perform right rotation on node.
	/// </summary>
	/// <param name="node">to perform rotation on</param>
	void rotateRight(Node* node);
	
	/// <summary>
	/// Return grandparent of node. Grandparent is parent of parent of node
	/// </summary>
	/// <param name="node">of which to get grandparent</param>
	/// <returns>Grandparent of node OR  nullptr if grandparent does not exist</returns>
	Node* getGrandparent(Node* node);

	/// <summary>
	/// Return uncle of node. Uncle is child of grandparent which is not parent of node
	/// </summary>
	/// <param name="node">of which to get uncle</param>
	/// <returns>Uncle of node OR nullptr if uncle does not exist</returns>
	Node* getUncle(Node* node);
};