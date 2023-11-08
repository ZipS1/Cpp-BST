#pragma once

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
*/

enum class Color { Red, Black };

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
	Node* node;
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
	void outputSymmetricWalk();
	void outputWalkInWidth();
	float getAverage();
	int distanceToValue(int value);
	~BinarySearchTree();
private:
	Node* root;

	/// <summary>
	/// Finds a place for value in tree. Recursive function
	/// </summary>
	/// <param name="node">- starting point to find place</param>
	/// <param name="value">to find place for</param>
	/// <returns>
	/// Search result with parent of node place and found node place.
	///	Both nullptrs if value is already in tree.
	/// </returns>
	SearchResult findEmptyPlaceFrom(Node* node, int value);
	
	/// <summary>
	/// Checks if BST is balanced and balance if it is not
	/// </summary>
	/// <returns>
	/// True if BST was already balanced. 
	/// False otherwise. 
	/// </returns>
	bool ensureBalanced(Node* newNode);

	/// <summary>
	/// Checks if new node is a root, then do balancing
	/// </summary>
	/// <param name="newNode">that was inserted</param>
	/// <returns>True if case matched, false otherwise</returns>
	bool balanceIfCaseFirst(Node* newNode);

	/// <summary>
	/// Checks if parent is black, then tree is balanced.
	/// </summary>
	/// <param name="newNode">that was inserted</param>
	/// <returns>True if case matched, false otherwise</returns>
	bool balanceIfCaseSecond(Node* newNode);

	/// <summary>
	/// Checks if both parent and uncle are red, then do balancing.
	/// </summary>
	/// <param name="newNode">that was inserted</param>
	/// <returns>True if case matched, false otherwise</returns>
	bool balanceIfCaseThird(Node* newNode);

	/// <summary>
	/// Checks if parent is red, uncle are black and node and his parent form a zig.
	/// Transforms tree to Case 5.
	/// </summary>
	/// <param name="newNode">that was inserted</param>
	/// <returns>Always false to check case 5</returns>
	bool balanceIfCaseFourth(Node* newNode);

	/// <summary>
	/// Checks if parent is red, uncle is black and node, parent, grandparent form a line to the right or left.
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
	/// Returns grandparent of node. Grandparent is parent of parent of node
	/// </summary>
	/// <param name="node">of which to get grandparent</param>
	/// <returns>Grandparent of node OR  nullptr if grandparent does not exist</returns>
	Node* getGrandparent(Node* node);

	/// <summary>
	/// Returns uncle of node. Uncle is child of grandparent which is not parent of node
	/// </summary>
	/// <param name="node">of which to get uncle</param>
	/// <returns>Uncle of node OR nullptr if uncle does not exist</returns>
	Node* getUncle(Node* node);
};