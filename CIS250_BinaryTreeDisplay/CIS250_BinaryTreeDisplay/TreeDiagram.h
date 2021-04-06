#pragma once
#include "iostream"
#include "string"
#include <stdio.h>
#include "TreeNode.h"
#include "fstream"

using namespace std;
class TreeDiagram
{
	private:
		
	public:
		static const int maxGridSize = 27;
		TreeDiagram();
		TreeDiagram(string fname);
		~TreeDiagram();
		int listInOrder(TreeNode *node, int row, int col);
		void showNode(TreeNode *node, int row, int col);
		void showGrid(string fname);
		void prtDashes();
		void addNode(int id, string name);
		TreeNode *root = nullptr;
		int grid[maxGridSize][maxGridSize];

};

