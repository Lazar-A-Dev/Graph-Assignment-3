#pragma once
#include<iostream>
using namespace std;
class LinkedNode;
class Edge {
public:
	Edge* link;
	LinkedNode* dest;
	int weight;

	Edge() {
		link = NULL;
		dest = NULL;
		weight = 0;
	}

	Edge(Edge* link, LinkedNode* dest, int weight) {
		this->link = link;
		this->dest = dest;
		this->weight = weight;
	}

	~Edge() {}
};