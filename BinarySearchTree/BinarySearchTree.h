#pragma once

/* --- УСТРОЙСТВО ДЕРЕВА ---
* Источник: https://www.youtube.com/watch?v=0BUX_PotA4c
* 
* Красно-черное дерево состоит из красных и черных узлов.
* Правила КЧ дерева:
* 1. Листом в КЧ дереве является несуществующий узел (nullptr)
* 2. Корень и лист черного цвета
* 3. У красного узла оба ребенка - черные
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
* 4. Черная высота должна быть одинакова для левой/правой стороны,
*		тогда дерево называется сбалансированным.
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
	/// <returns>True if value inserted. 
	///				False if value already in tree.
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
	SearchResult findPlaceFrom(Node* node, int value);
	
	/// <summary>
	/// Checks if BST is balanced and balance if it is not
	/// </summary>
	/// <returns>
	/// True if BST was already balanced. 
	/// False otherwise. 
	/// </returns>
	bool ensureBalanced();
};