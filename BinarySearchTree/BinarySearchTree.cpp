#include "BinarySearchTree.h"

bool BinarySearchTree::insert(int value)
{
	SearchResult result = findEmptyPlaceFrom(root, value);
	if (result.node == nullptr)
		return false;

	result.node = new Node(result.parent, value);
	ensureBalanced(result.node);
}

void BinarySearchTree::outputSymmetricWalk()
{
}

void BinarySearchTree::outputWalkInWidth()
{
}

float BinarySearchTree::getAverage()
{
	return 0.0f;
}

int BinarySearchTree::distanceToValue(int value)
{
	return 0;
}

BinarySearchTree::~BinarySearchTree()
{
}

SearchResult BinarySearchTree::findEmptyPlaceFrom(Node* node, int value)
{
	static Node* parent = nullptr;

	if (node == nullptr)
	{
		SearchResult result{ parent, node };
		parent = nullptr;
		return result;
	}

	if (value == node->data)
	{
		parent = nullptr;
		return { nullptr,  nullptr };
	}

	parent = node;
	if (value < node->data)
		findEmptyPlaceFrom(node->left, value);
	else
		findEmptyPlaceFrom(node->right, value);
}

bool BinarySearchTree::ensureBalanced(Node* newNode)
{
	bool isBalanceRequired = false;

	if (balanceIfCaseFirst(newNode))
		isBalanceRequired = true;
	else if (balanceIfCaseSecond(newNode))
		isBalanceRequired = true;
	else if (balanceIfCaseThird(newNode))
		isBalanceRequired = true;
	else if (balanceIfCaseFourth(newNode))
		isBalanceRequired = true;
	else if (balanceIfCaseFifth(newNode))
		isBalanceRequired = true;

	return isBalanceRequired == false;		
}

#pragma region BalancingCases
bool BinarySearchTree::balanceIfCaseFirst(Node* newNode)
{
	if (newNode->parent != nullptr)
		return false;

	newNode->color = Color::Black;
	return true;
}

bool BinarySearchTree::balanceIfCaseSecond(Node* newNode)
{
	return newNode->parent->color == Color::Black;
}

bool BinarySearchTree::balanceIfCaseThird(Node* newNode)
{
	Node* uncle = getUncle(newNode);
	if (uncle != nullptr && uncle->color == Color::Red)
	{
		newNode->parent->color = Color::Black;
		uncle->color = Color::Black;
		Node* grandparent = getGrandparent(newNode);
		grandparent->color = Color::Red;
		ensureBalanced(grandparent);
		return true;
	}
	return false;
}

bool BinarySearchTree::balanceIfCaseFourth(Node* newNode)
{
	Node* grandparent = getGrandparent(newNode);
	bool isLeftRightZig = newNode == newNode->parent->right && newNode->parent == grandparent->left;
	bool isRightLeftZig = newNode == newNode->parent->left && newNode->parent == grandparent->right;
	if (isLeftRightZig)
		rotateLeft(newNode->parent);
	else if (isRightLeftZig)
		rotateRight(newNode->parent);

	return false;
}

bool BinarySearchTree::balanceIfCaseFifth(Node* newNode)
{
	Node* grandparent = getGrandparent(newNode);
	newNode->parent->color = Color::Black;
	grandparent->color = Color::Red;
	bool isLineToLeft = newNode == newNode->parent->left && newNode->parent == grandparent->left;
	bool isLineToRight = newNode == newNode->parent->right && newNode->parent == grandparent->right;
	if (isLineToLeft == false && isLineToRight == false)
		return false;

	isLineToLeft ? rotateRight(grandparent) : rotateLeft(grandparent);
	return true;
}
#pragma endregion

void BinarySearchTree::rotateLeft(Node* node)
{
	Node* rightNode = node->right;
	node->right = rightNode->left;
	rightNode->left = node;
	rightNode->parent = node->parent;
	node->parent = rightNode;

	if (root == node)
		root = rightNode;
}

void BinarySearchTree::rotateRight(Node* node)
{
	Node* leftNode = node->left;
	node->left = leftNode->right;
	leftNode->right = node;
	leftNode->parent = node->parent;
	node->parent = leftNode;

	if (root == node)
		root = leftNode;
}

Node* BinarySearchTree::getGrandparent(Node* node)
{
	if (node != nullptr && node->parent != nullptr)
		return node->parent->parent;
	else 
		return nullptr;
}

Node* BinarySearchTree::getUncle(Node* node)
{
	Node* grandparent = getGrandparent(node);
	if (grandparent == nullptr)
		return nullptr;

	return grandparent->right == node->parent ? 
		grandparent->left : grandparent->right;
}		
