#include "BinarySearchTree.h"

bool BinarySearchTree::insert(int value)
{
	SearchResult result = findEmptyPlaceFrom(root, Side::Root, value);
	if (result.parent == nullptr && result.side != Side::Root)
		return false;

	switch (result.side)
	{
	case Side::Left:
		result.parent->left = new Node(result.parent, value);
		ensureBalanced(result.parent->left);
		break;
	case Side::Right:
		result.parent->right = new Node(result.parent, value);
		ensureBalanced(result.parent->right);
		break;
	case Side::Root:
		root = new Node(nullptr, value);
		ensureBalanced(root);
		break;
	}
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

SearchResult BinarySearchTree::findEmptyPlaceFrom(Node* node, Side side,  int value)
{
	static Node* parent = nullptr;
	SearchResult result;

	if (node == nullptr)
	{
		result = { parent, side};
		parent = nullptr;
		return result;
	}

	if (value == node->data)
	{
		parent = nullptr;
		return { nullptr,  Side::Left };
	}

	parent = node;
	if (value < node->data)
		result = findEmptyPlaceFrom(node->left, Side::Left, value);
	else
		result = findEmptyPlaceFrom(node->right, Side::Right, value);
	return result;
}

bool BinarySearchTree::ensureBalanced(Node* newNode)
{
	bool isBalanceRequired = true;

	if (balanceIfCaseFirst(newNode)) {}
	else if (balanceIfCaseSecond(newNode)) {}
	else if (balanceIfCaseThird(newNode)) {}
	else if (balanceIfCaseFourth(newNode)) {}
	else if (balanceIfCaseFifth(newNode)) {}
	else
		isBalanceRequired = false;

	return isBalanceRequired == false;		
}

#pragma region BalancingCases
bool BinarySearchTree::balanceIfCaseFirst(Node* newNode)
{
	if (newNode != root)
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
