#pragma once
#include<iostream>
using namespace std;
#include"Edge.h"
#include"LinkedNode.h"
class Graph
{
public:

	LinkedNode* start;
	int size;

public:

	Graph();
	~Graph();
	void InsertNode(int info);
	void InsertEdge(int a, int b, int w);
	void InsertDoubleEdge(int a, int b, int w);
	void EveryEdgeDouble();//Graf postaje neodredjen
	LinkedNode* FindNode(int info);
	Edge* FindEdge(int a, int b);
	bool EdgeExists(int a, int b);
	void DeleteNode(int info);
	bool DeleteEdge(int a, int b);
	void BFS();
	int BFSTime();
	void ShortestPath(int a, int b);//by nodes
	void CheapestPath(int a, int b);//by weigth
	void SingeVsMultipleMoves();
	void PrintGraph();
};

