#include<iostream>
#include"Graph.h"
using namespace std;
void main() {
	Graph g;
	g.InsertNode(1);
	g.InsertNode(2);
	g.InsertNode(3);
	g.InsertNode(4);
	g.InsertNode(5);

	g.InsertEdge(1, 2, 7);
	g.InsertEdge(1, 3, 55);
	g.InsertEdge(2, 4, 9);
	g.InsertEdge(4, 5, 2);
	g.InsertDoubleEdge(5, 3, 11);
	g.InsertEdge(3, 1, 77);
	//g.EveryEdgeDouble(); //Radi
	//g.DeleteNode(2); //Radi

	g.PrintGraph();
	cout << endl;
	//cout << "Moves: " << g.BFSTime() << endl;
	//g.BFS();
	g.SingeVsMultipleMoves();
	system("pause");
}