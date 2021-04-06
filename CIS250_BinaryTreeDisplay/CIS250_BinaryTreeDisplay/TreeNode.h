#pragma once
#include "iostream"
#include "string"

using namespace std;
class TreeNode
{
	public:
		TreeNode();
		TreeNode(int i, string n);
		~TreeNode();
		int id;
		string name;
		TreeNode *leftChild;
		TreeNode *rightChild;
};

