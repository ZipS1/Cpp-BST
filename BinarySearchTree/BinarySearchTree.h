#pragma once

/*
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
* ������ ������ ����� ����� 2
* -------------------------------------------------------------------------
* 4. ������ ������ ������ ���� ��������� ��� �����/������ �������.
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