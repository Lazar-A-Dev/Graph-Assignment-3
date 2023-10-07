#pragma once
#include<iostream>
using namespace std;
class Edge;
class LinkedNode {
public:
	LinkedNode* next;
	Edge* adj;
	int info;
	int status;

	LinkedNode() {
		next = NULL;
		adj = NULL;
		info = status = 0;
	}

	LinkedNode(LinkedNode* next, Edge* adj, int info, int status) {
		this->next = next;
		this->adj = adj;
		this->info = info;
		this->status = status;
	}

	void ChangeStatus(int s) {
		this->status = s;
	}

	~LinkedNode() {}
};
