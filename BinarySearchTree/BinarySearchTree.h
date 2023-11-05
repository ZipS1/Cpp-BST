#pragma once

/* --- ���������� ������ ---
* ��������: https://www.youtube.com/watch?v=0BUX_PotA4c
* 
* ������-������ ������ ������� �� ������� � ������ �����.
* ������� �� ������:
* 1. ������ � �� ������ �������� �������������� ���� (nullptr)
* 2. ������ � ���� ������� �����
* 3. � �������� ���� ��� ������� - ������
* -------------------------------------------------------------------------
* ������ ������ - ���������� ������ ����� �� ��������� �� null ������������.
* �������� ���� ��� ���� �� ���������. �.�. � ������ �������:
* 
*                          �
*                         / \
*                        �   �
*                       /     \
*                    null(�) null(�)
* 
* ������ ������ ����� ����� 1
* -------------------------------------------------------------------------
* 4. ������ ������ ������ ���� ��������� ��� �����/������ �������,
*		����� ������ ���������� ����������������.
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