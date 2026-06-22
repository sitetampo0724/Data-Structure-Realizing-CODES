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
	void EulerCircuit(TypeOfVer start) const;
	verNode* clone() const;
	void EulerCircuit(int v, EulerNode*& beg, EulerNode*& end) const;
	void topSort()const;
	void criticalPath()const;

private:
	void dfs(int v, bool visited[]) const;

	struct EulerNode
	{
		int NodeNum;
		EulerNode* next;
		EulerNode(int ver)
		{
			NodeNum = ver;
			next = nullptr;
		}
	};

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
adjListGraph<TypeOfVer, TypeOfEdge>::adjListGraph(int vSize, const TypeOfVer d[])
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
			verList[i].head = p->next;
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

	verList[u].head = new edgeNode(v, w, verList[u].head);

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
	int currentNode;
	queue<int> q;
	edgeNode* p;

	bool* visited = new bool[vers];
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


template <class TypeOfVer,class TypeOfEdge>
void  adjListGraph<TypeOfVer, TypeOfEdge>::EulerCircuit(TypeOfVer start) const
{
	if (Edges == 0)
		return;

	for (int i = 0;i < vers;i++)
	{
		int degree = 0;
		edgeNode* p = verList[i].head;
		while (p != NULL)
		{
			degree++;
			p = p->next;
		}
		if (degree % 2 != 0)
			return;
	}

	int i = find(start);

	VerNode* temp = clone();

	EulerNode* beg, * end, * tb, * te, * p, * q;
	EulerCircuit(i, beg, end);

	while (true) {
		p = beg;
		while (p->next != nullptr)
		{
			if (verlist[p->next.Nodenum].head != nullptr)
				break;
			p = p->next;
		}
		
		if (p->next == nullptr) break;

		q = p->next;
		EulerCircuit(q->NodeNum, tb, te);

		p->next = tb;
		te->next = q->next;
		
		delete q;
	}

	delete[]verList;
	verList = temp;

	while (begin != nullptr)
	{
		cout << verList[begin->NodeNum].ver << '\t';
		EulerNode* temp = begin;
		begin = begin->next;
		delete temp;
	}
}


template <class TypeOfVer, class TypeOfEdge>
adjListGraph<TypeOfVer, TypeOfEdge>::verNode* adjListGraph<TypeOfVer, TypeOfEdge>::clone() const
{
	verNode* temp = new verNode[vers];

	for (int i = 0;i < vers;i++)
	{
		temp[i].ver = verList[i].ver;

		edgeNode* p = verList[i].head;
		while (p != nullptr)
		{
			temp[i].head = new edgeNode(p->end, p->weight, temp[i].head);
			p = p->next;
		}
	}

	return temp;
}

template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::EulerCircuit(int v, EulerNode*& beg, EulerNode*& end) const
{
	
	begin = end = new EulerNode(v);

	while (verList[v].head != nullptr)
	{
		int nextNode = verList[v].head->end;
		remove(v, nextNode);
		remove(nextNode, v);
		v = nextNode;
		end->next = new EulerNode(v);
		end = end->next;
	}
}


template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::topSort()const
{
	linkQueue<int> q;
	
	int* inDegree = new int[Vers];
	for (int i = 0;i < vers;i++) inDegree[i] = 0;
	for (int i = 0;i < vers;i++)
	{
		edgeNode* p = verList[i].head;
		while (p != nullptr)
		{
			inDegree[p->end]++;
			p = p->next;
		}
	}

	for (int i = 0;i < vers;i++)
		if (inDegree[i] == 0) q.enqueue(i);

	while (!q.empty())
	{
		int current = q.dequeue();
		cout << verList[current].ver << '\t';
		p = verList[current].head;
		while (p != nullptr)
		{
			inDegree[p->end]--;
			if (inDegree[p->end] == 0)
				q.enqueue(p->end);
			p = p->next;
		}
	}
    
	cout << endl;
}


template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::criticalPath()const
{
	TypeOfEdge* ee = new TypeOfEdge[vers];
	TypeOfEdge* le = new TypeOfEdge[vers];
	int* top = new int[vers];
	int* inDegree = new int[vers];
	linkQueue<int> q;
	edgeNode* p

	for (int i = 0;i < vers;i++) inDegree[i] = 0;
	for (int i = 0;i < vers;i++)
	{
		p = verList[i].head;
		while (p != nullptr)
		{
			inDegree[p->end]++;
			p = p->next;
		}
	}

	int i = 0;
	while (!q.empty())
	{
		int current = q.dequeue();
		top[i++] = current;
		p = verList[current].head;
		while (p != nullptr)
		{
			inDegree[p->end]--;
			if (inDegree[p->end] == 0)
				q.enqueue(p->end);
			p = p->next;
		}
	}

	for (int i = 0;i < vers;i++) ee[i] = 0;
	for (int i = 0;i < vers;i++) {
		for(p=verList[top[i]].head;p!=nullptr;p=p->next)
			if(ee[p->end]<ee[i]+p->weight)
				ee[p->end] = ee[i] + p->weight;
	}

	for (int i = 0;i < vers;i++) le[i] = ee[top[vers - 1]];
	for(int i=vers-1;i>=0;i--)
	{
		for(p=verList[top[i]].head;p!=nullptr;p=p->next)
			if(le[p->end]>le[i]-p->weight)
				le[p->end] = le[i] - p->weight;
	}

	for (int i = 0;i < vers;i++)
	    if(le[top[i]]==ee[top[i]])
	        cout << verList[top[i]].ver << '\t';

	cout << endl;

}