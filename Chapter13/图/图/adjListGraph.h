#pragma once

#include "graph.h"
#include <iostream>
#include <queue>

using namespace std;

template <class TypeOfVer, class TypeOfEdge>
class adjListGraph : public graph<TypeOfVer, TypeOfEdge>
{
public:
	adjListGraph(int vSize, const TypeOfEdge d[]);
	void insert(TypeOfVer X, TypeOfVer y, TypeOfEdge W);
	void remove(TypeOfVer X, TypeOfVer y);
	bool exist(TypeOfVer X, TypeOfVer y) const;
	~adjListGraph();

	void dfs() const;
	void bfs() const;

private:
	void dfs(int v, bool visited[]) const;

	struct edgeNode
	{
		int end;
		TypeOfEdge weight;
		edgeNode* next;

		edgeNode(int e, TypeOfVer w, edgeNode* n = nullptr)
			:end(e), weight(w), next(n) {
		}
	};

	struct verNode
	{
		TypeOfVer ver;
		edgeNode* head;

		verNode(edgeNode* h = nullptr) :head(h) {}
	};

	verNode* verList;

	int find(TypeOfEdge v)const
	{
		for (int i = 0; i < this->Vers; i++)
			if (ver[i] == v)
				return i;
	}
};


template <class TypeOfVer, class TypeOfEdge>
adjListGraph<TypeOfVer, TypeOfEdge>::adjListGraph(int vSize, const TypeOfEdge d[])
{
	int i, j;

	vers = vSize;
	edges = 0;

	verList = new verNode[vers];
	for (i = 0; i < vers; i++)
		verList[i].ver = d[i];
}

template <class TypeOfVer, class TypeOfEdge>
adjListGraph<TypeOfVer, TypeOfEdge>::~adjListGraph()
{
	int i;
	edgeNode* p;

	for (int i = 0;i < vers;i++)
	{
		p = verList[i].head;
		while (p != nullptr)
		{
			verList = p->next;
			delete p;
		}
	}

	delete[]verList;
}

template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::insert(TypeOfVer X, TypeOfVer y, TypeOfEdge W)
{
	int u = find(X);
	int v = find(y);

	typeList[u].head = new edgeNode(v, w,typeList[u].head);

	++edges;
}

template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::remove(TypeOfVer X, TypeOfVer y)
{
	int u = find(X);
	int v = find(y);

	edgeNode* p = typeList[u].head,*q = nullptr;
	
	if (p == nullptr) return;

	if (p->end == v) {
		verlist[u].head = p->next;
		delete p;
		--edges;
	}

	while (p->next != nullptr && p->next->end != v) p = p->next;

	if (p->next != nullptr)
	{
		q = p->next;
		p->next = q->next;	
		delete q;
		--edges;
	}
}


template <class TypeOfVer, class TypeOfEdge>
bool adjListGraph<TypeOfVer, TypeOfEdge>::exist(TypeOfVer X, TypeOfVer y) const
{
	int u = find(X);
	int v = find(y);

	edgeNode* p = verList[u].head;

	while (p != nullptr && p->end != v)
		p = p->next;

	return (p != nullptr);
}

template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::dfs() const
{
	bool* visited = new bool[vers];
	for (int i = 0; i < vers; i++)
		visited[i] = false;

	for (int i = 0; i < vers; i++) {
		if (visited[i]) continue;
	    dfs(i, visited);
		cout << endl;
	}
		
	delete[] visited;
}


template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::dfs(int v, bool visited[]) const
{
	visited[v] = true;
	cout<<verList[v].ver<<" ";

	edgeNode* p = verList[v].head;
	while (p != nullptr)
	{
		if (!visited[p->end])
			dfs(p->end, visited);
		p = p->next;
	}
}


template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::bfs() const
{
	bool* visited = new bool[vers];
	int currentNode;
	queue<int> q;
	edgeNode* p;

	for (int i = 0;i < vers;i++)
		visited[i] = false;

	for (int i = 0;i < vers;i++)
	{
		if (visited[i]) continue;
		q.push(i);
		while (!q.empty()) {
			currentNode = q.front();
			q.pop();

			if (visited[currentNode]) continue;
			cout << verList[currentNode].ver << '\t';

			visited[currentNode] = true;
			p = verList[currentNode].head;
			while (p != nullptr) {
				if(!visited[p->end])
					q.push(p->end);
				p = p->next;
			}
		}
		cout << endl;
	}

}