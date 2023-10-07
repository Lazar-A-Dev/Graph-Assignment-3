#include "Graph.h"
Graph::Graph() {
	start = NULL;
	size = 0;
}

Graph::~Graph() {

}

void Graph::InsertNode(int info) {
	LinkedNode* tmp = new LinkedNode(start, NULL, info, 0);
	start = tmp;
	size++;
}

void Graph::InsertEdge(int a, int b, int w) {
	LinkedNode* p1 = FindNode(a);
	LinkedNode* p2 = FindNode(b);
	if (p1 != NULL && p2 != NULL) {
		Edge* ed = new Edge(p1->adj, p2, w);
		p1->adj = ed;
	}
}

void Graph::InsertDoubleEdge(int a, int b, int w) {
	LinkedNode* p1 = FindNode(a);
	LinkedNode* p2 = FindNode(b);

	Edge* ed = new Edge(p1->adj, p2, w);
	p1->adj = ed;

	ed = new Edge(p2->adj, p1, w);
	p2->adj = ed;
}

void Graph::EveryEdgeDouble() {
	LinkedNode* tmp = start;
	while (tmp != NULL) {
		Edge* ed = tmp->adj;
		while (ed != NULL) {
			if (EdgeExists(tmp->info, ed->dest->info) && !EdgeExists(ed->dest->info, tmp->info))
				InsertEdge(ed->dest->info, tmp->info, ed->weight);

			ed = ed->link;
		}
		tmp = tmp->next;
	}
}

LinkedNode* Graph::FindNode(int info) {
	LinkedNode* tmp = start;
	while (tmp != NULL && tmp->info != info)
		tmp = tmp->next;

	return tmp;
}

Edge* Graph::FindEdge(int a, int b) {
	LinkedNode* p1 = FindNode(a);
	LinkedNode* p2 = FindNode(b);

	if (p1 != NULL && p2 != NULL) {
		Edge* ed = p1->adj;
		while (ed != NULL && ed->dest != p2)
			ed = ed->link;

		return ed;
	}
	else return NULL;
}

bool Graph::EdgeExists(int a, int b) {
	if (FindEdge(a, b))
		return true;
	return false;
}

void Graph::DeleteNode(int info) {
	LinkedNode* p1 = FindNode(info);
	LinkedNode* tmp = start;

	while (tmp != NULL) {//Svaki ulazni poteg
		if (EdgeExists(tmp->info, p1->info))
			DeleteEdge(tmp->info, p1->info);
		else if (EdgeExists(p1->info, tmp->info))
			DeleteEdge(p1->info, tmp->info);
		tmp = tmp->next;
	}


	tmp = start;
	while (tmp->next != p1)
		tmp = tmp->next;
	
	tmp->next = p1->next;
	p1 = NULL;
	delete p1;
}

bool Graph::DeleteEdge(int a, int b) {
	Edge* pot = FindEdge(a, b);
	if (pot == NULL)
		return false;

	LinkedNode* pa = FindNode(a);
	if (pot == pa->adj) {
		pa->adj = pot->link;
		delete pot;
		return true;
	}

	Edge* tpot = pa->adj;
	while (tpot->link != pot)
		tpot = tpot->link;
	tpot->link = pot->link;
	delete pot;
	return true;
}

void Graph::BFS() {
	LinkedNode** stack = new LinkedNode * [size];
	int i = 0;
	int position = 1;
	LinkedNode* tmp = start;
	tmp->ChangeStatus(1);
	stack[i++] = tmp;
	while (tmp != NULL && i<size) {
		Edge* ed = tmp->adj;
		while (ed != NULL) {
			if (ed->dest->status == 0) {
				ed->dest->ChangeStatus(1);
				stack[i++] = ed->dest;
			}

			ed = ed->link;
		}

		tmp = stack[position++];
	}

	LinkedNode* p = start;
	while (p != NULL) {
		p->ChangeStatus(0);//vraca svim cvorovima status na 0
		p = p->next;
	}

	cout << "Stack: " << endl;
	for (int j = 0; j < i; j++) {
		cout << "[" << stack[j]->info << "] ";
	}

}

int Graph::BFSTime() {
	LinkedNode** stack = new LinkedNode * [size];
	int i = 0;
	int position = 1;
	int time = 1;
	LinkedNode* tmp = start;
	tmp->ChangeStatus(1);
	stack[i++] = tmp;
	while (tmp != NULL && i < size) {
		Edge* ed = tmp->adj;
		while (ed != NULL) {

			if (ed->dest->status == 0) {
				ed->dest->ChangeStatus(1);
				stack[i++] = ed->dest;
			}

			ed = ed->link;
		}
		time++;
		tmp = stack[position++];
	}
	
	LinkedNode* p = start;
	while (p != NULL) {
		p->ChangeStatus(0);
		p = p->next;
	}
	return time;
}

void Graph::ShortestPath(int a, int b) {

}

void Graph::CheapestPath(int a, int b) {

}

void Graph::SingeVsMultipleMoves() {
	int single = BFSTime();
	cout << "Broj poteza odredjenog grafa: " << single << endl;
	EveryEdgeDouble();
	int multiple = BFSTime();
	cout << "Broj poteza neodredjenog grafa: " << multiple << endl;

	if (single < multiple)
		cout << "Odredjeni graf obuhvata sve cvorove za " << multiple - single << " broj koraka brze " << endl;
	else
		cout << "Neodredjeni graf obuhvata sve cvorove za " << single - multiple << " broj koraka brze " << endl;
}

void Graph::PrintGraph() {
	LinkedNode* p1 = start;
	while (p1 != NULL) {
		cout << "[" << p1->info << "] ";
		Edge* ed = p1->adj;
		while (ed != NULL) {
			if(EdgeExists(p1->info, ed->dest->info) && EdgeExists(ed->dest->info, p1->info))
				cout << "<-" << ed->weight << "-> [" << ed->dest->info << "] ";
			else 
				cout << "-" << ed->weight << "-> [" << ed->dest->info << "] ";
			ed = ed->link;
		}
		p1 = p1->next;
		cout << endl;
	}
}