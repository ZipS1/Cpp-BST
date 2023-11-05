#include "BinarySearchTree.h"

bool BinarySearchTree::insert(int value)
{
	SearchResult result = findPlaceFrom(root, value);
	if (result.node == nullptr)
		return false;

	result.node = new Node(result.parent, value);
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

SearchResult BinarySearchTree::findPlaceFrom(Node* node, int value)
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
		findPlaceFrom(node->left, value);
	else
		findPlaceFrom(node->right, value);
}

bool BinarySearchTree::ensureBalanced()
{
	return false;
}
