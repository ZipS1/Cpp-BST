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
	
	size++;
	return true;
}

void BinarySearchTree::outputSymmetricWalk()
{
	outputNodeSymmetric(root);
	std::cout << std::endl;
}

void BinarySearchTree::outputWalkInWidth()
{
	if (root == nullptr)
		return;

	std::queue<Node*> q;
	q.push(root);
	
	int elementsAtLevel, i;
	while (q.size() != 0)
	{
		elementsAtLevel = q.size();
		for (i = 0; i < elementsAtLevel; i++)
		{
			Node* front = q.front();
			std::cout << " " << front->data;
			q.pop();

			if (front->left != nullptr)
				q.push(front->left);

			if (front->right != nullptr)
				q.push(front->right);
		}
	}
}

float BinarySearchTree::getAverage(bool* isOk)
{
	if (root = nullptr)
	{
		*isOk = false;
		return 0.0f;
	}

	int sum = handleNodeSum(root);
	return (float)sum / size;
		
}

int BinarySearchTree::distanceToValue(int value)
{
	return stepsToValue(root, value);
}

BinarySearchTree::~BinarySearchTree()
{
}

void BinarySearchTree::outputNodeSymmetric(Node* node)
{
	if (node == nullptr)
		return;

	outputNodeSymmetric(node->left);
	std::cout << " " << node->data;
	outputNodeSymmetric(node->right);

}

int BinarySearchTree::handleNodeSum(Node* node)
{
	if (node == nullptr)
		return 0;

	return node->data + handleNodeSum(node->left) + handleNodeSum(node->right);
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

int BinarySearchTree::stepsToValue(Node* start, int value)
{
	if (start == nullptr)
		return INT_MIN;

	if (start->data == value)
		return 0;

	return start->data > value ?
		stepsToValue(start->right, value) + 1 :
		stepsToValue(start->left, value) + 1;
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
	if (isLeftRightZig == false && isRightLeftZig == false)
		return false;

	if (isLeftRightZig)
		rotateLeft(newNode->parent);
	else if (isRightLeftZig)
		rotateRight(newNode->parent);

	Node* newNodeChild = newNode->left == nullptr ? newNode->right : newNode->left;
	balanceIfCaseFifth(newNodeChild);
	return true;
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
	if (node->right != nullptr)
		node->right->parent = node;

	if (node->parent != nullptr)
		node == node->parent->left ?
		node->parent->left = rightNode :
		node->parent->right = rightNode;

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
	if (node->left != nullptr)
		node->left->parent = node;

	if (node->parent != nullptr)
		node == node->parent->left ?
		node->parent->left = leftNode :
		node->parent->right = leftNode;

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
