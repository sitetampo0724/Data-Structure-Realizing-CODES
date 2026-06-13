#pragma once

#include "graph.h"

template <class TypeOfVer, class TypeOfEdge>
class adjMatrixGraph : public graph<TypeOfVer, TypeOfEdge>
{
public:
	adjMatrixGraph(int vSize, const TypeOfEdge d[], const TypeOfEdge& noEdgeFlag);
	void insert(TypeOfVer X, TypeOfVer y, TypeOfEdge W);
	void remove(TypeOfVer X, TypeOfVer y);
	bool exist(TypeOfVer X, TypeOfVer y) const;
	~adjMatrixGraph();

private:
	TypeOfEdge** edge;
	TypeOfVer* ver;
	TypeOfEdge noEdge;
	int find(TypeOfEdge v)const
	{
		for (int i = 0; i < this->Vers; i++)
			if (ver[i] == v)
				return i;
	}
};


template <class TypeOfVer, class TypeOfEdge>
adjMatrixGraph<TypeOfVer, TypeOfEdge>::adjMatrixGraph(int vSize, const TypeOfEdge d[], const TypeOfEdge& noEdgeFlag)
{
	int i, j;

	vers = vSize;
	edges = 0;
	noEdge = noEdgeFlag;

	ver = new TypeOfVer[vers];
	for (i = 0; i < vers; i++)
		ver[i] = d[i];

	edge = new TypeOfEdge*[vers];
	for (i = 0; i < vers; i++)
	{
		edge[i] = new TypeOfEdge[vers];
		for (j = 0; j < vers; j++)
			edge[i][j] = noEdge;
	}
}


template <class TypeOfVer, class TypeOfEdge>
adjMatrixGraph<TypeOfVer, TypeOfEdge>::~adjMatrixGraph()
{
	delete[]ver;
	for (int i = 0;i < vers;i++)
		delete[]edge[i];
	delete[]edge;
}

template <class TypeOfVer, class TypeOfEdge>
void adjMatrixGraph<TypeOfVer, TypeOfEdge>::insert(TypeOfVer X, TypeOfVer y, TypeOfEdge W)
{
	int u = find(x);
	int v = find(y);
	edge[u][v] = w;
	++edges;//no mistake checker
}

template <class TypeOfVer, class TypeOfEdge>
void adjMatrixGraph<TypeOfVer, TypeOfEdge>::remove(TypeOfVer X, TypeOfVer y)
{
	int u = find(x);
	int v = find(y);
	edge[u][v] = noEdge;
	--edges;//no mistake checker
}


template <class TypeOfVer, class TypeOfEdge>
bool exist(TypeOfVer X, TypeOfVer y)
{
	int u = find(x);
	int v = find(y);
	return edge[u][v] != noEdge;
}