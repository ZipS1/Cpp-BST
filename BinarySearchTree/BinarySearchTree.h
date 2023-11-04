#pragma once

/*
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
*                        Ч   Ч
*                       /     \
*                    null(Ч) null(Ч)
* 
* Черная высота корня равна 2
* -------------------------------------------------------------------------
* 4. Черная высота должна быть одинакова для левой/правой стороны.
*/

enum class Color { Red, Black };

struct Node
{
	Color color;
	int data;
	Node* right;
	Node* left;
};

class BinarySearchTree
{
public:
	bool insert(int value);
	void outputSymmetricWalk();
	void outputWalkInWidth();
	float getAverage();
	int distanceToValue(int value);
	~BinarySearchTree();
private:
	Node* root;
};