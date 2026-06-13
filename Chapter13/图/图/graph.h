#pragma once

template <class TypeOfVer,class TypeOfEdge>
class graph {
public: 
	virtual void insert(TypeOfVer X,TypeOfVer y, TypeOfEdge W) = 0;
	virtual void remove(TypeOfVer X, TypeOfVer y) = 0;
	virtual bool exist(TypeOfVer X, TypeOfVer y) const = 0;
	int numOfVer() const { return vers; }
	int numOfEdge() const { return edges; }
protected:
	int vers, edges;
};














// TODO: Reference additional headers your program requires here.
