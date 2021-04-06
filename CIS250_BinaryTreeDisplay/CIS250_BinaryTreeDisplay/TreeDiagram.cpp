#include "stdafx.h"
#include "TreeDiagram.h"


TreeDiagram::TreeDiagram()
{
}
TreeDiagram::TreeDiagram(string fname)
{
	ifstream inputFile;
	string fileName = fname;
	string lineOfText;
	int commaPos;
	char delim = ',';
	int id; 
	string name;

	inputFile.open(fileName);
	if (inputFile)
	{
		while (getline(inputFile, lineOfText))
		{
			commaPos = lineOfText.find(delim);
			id = stoi(lineOfText.substr(0, commaPos));
			lineOfText = lineOfText.substr(commaPos + 1);

			name = lineOfText;

			addNode(id, name);
		}
	}
	else
	{
		cout << "Error Reading File" << endl;
	}
	inputFile.close();
}

TreeDiagram::~TreeDiagram()
{
}

int TreeDiagram::listInOrder(TreeNode *node, int row, int col)
{
	if (node == nullptr)
	{
		return col;
	}
	
	row++;

	col = listInOrder(node->leftChild, row, col);

	grid[row][col] = node->id;
	grid[row][0]++;
	showNode(node, row, col);
	col++;
	col = listInOrder(node->rightChild, row, col);

	return col;
}
void TreeDiagram::showNode(TreeNode *node, int row, int col)
{
	if (node->leftChild == nullptr && node->rightChild == nullptr)
	{
		printf("%2d %-7s %2d leaf", node->id, node->name.c_str(), row);
		//cout << node->id << "  " << node->name << "  " << row << "  Leaf";
	}
	else
	{
		printf("%2d %-7s %2d     ", node->id, node->name.c_str(), row);
		//cout << node->id << "  " << node->name << "  " << row;
	}

	cout << endl;
}
void TreeDiagram::showGrid(string fname)
{
	int row = 0;
	int col;

	prtDashes();
	cout << fname << endl;
	cout << "Lvl Count" << endl;

	while (grid[row][0] != 0)
	{
		printf("%2d %3d :  ", row, grid[row][0]);
		//cout << row << grid[row][0];
		for (col = 1; col < maxGridSize; col++)
		{
			if (grid[row][col] == 0)
			{
				cout << "   ";
			}
			else
			{
				printf("%3d", grid[row][col]);
				//cout << grid[row][col];
			}
		}
		cout << endl << endl;
		row++;
	}
	prtDashes();
}
void TreeDiagram::prtDashes()
{
	for (int i = 0; i < 90; i++)
	{
		cout << "-";
	}
	cout << endl;
}
void TreeDiagram::addNode(int id, string name)
{
	TreeNode *parent;
	TreeNode *curr;
	TreeNode *newNode = new TreeNode(id, name);

	if (root == nullptr)
	{
		root = newNode;
	}
	else
	{
		curr = root;

		while (true)
		{
			parent = curr;
			if (id < curr->id)
			{
				curr = curr->leftChild;
				if (curr == nullptr)
				{
					parent->leftChild = newNode;
					return;
				}
			}
			else
			{
				curr = curr->rightChild;
				if (curr == nullptr)
				{
					parent->rightChild = newNode;
					return;
				}
			}
		}
	}
}
