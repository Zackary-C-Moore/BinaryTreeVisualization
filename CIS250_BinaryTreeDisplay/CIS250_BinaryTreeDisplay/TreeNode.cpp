#include "stdafx.h"
#include "TreeNode.h"


TreeNode::TreeNode()
{
}

TreeNode::TreeNode(int i, string n)
{
	id         = i;
	name       = n;
	leftChild  = nullptr;
	rightChild = nullptr;
}


TreeNode::~TreeNode()
{
}
