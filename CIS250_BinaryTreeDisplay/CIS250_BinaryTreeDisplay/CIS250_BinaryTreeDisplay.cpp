// CIS250_BinaryTreeDisplay.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "string"
#include "TreeDiagram.h"
#include "TreeNode.h"

using namespace std;

void buildDispTree(string fname);


int main()
{
	buildDispTree("stuBalanced.txt");
	buildDispTree("stuRandom.txt");
	buildDispTree("stuOrdered.txt");



	system("pause");
    return 0;
}


void buildDispTree(string fname)
{
	TreeDiagram *myTree = new TreeDiagram(fname);
	//int grid[27][27];

	cout << fname << endl;
	cout << "ID Name    Lvl" << endl;
	myTree->listInOrder(myTree->root, -1, 1);
	//cout << grid[0][0] << "---------++++++" << endl;
	myTree->showGrid(fname);
}
