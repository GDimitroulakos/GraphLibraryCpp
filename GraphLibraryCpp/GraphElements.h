#ifndef GRAPH_ELEMENTS_
#define GRAPH_ELEMENTS_
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <list>
#include <map>
using namespace std;
class CGraphEdge;
class CGraphNode;
class CGraph;

typedef enum GraphElementType {
	ET_NODE,
	ET_EDGE,
	ET_GRAPH
} GRAPH_ELEMENT_TYPE;

class CGraphPrimitive {
private:
	CGraphPrimitive* m_owner;
	GRAPH_ELEMENT_TYPE m_eType;
	static int ms_UniqueSerialNumberCounter;
	int m_SerialNumber;
	string m_Label;
	map<void*, void*>* m_algorithmOutput;

public:
	CGraphPrimitive(GRAPH_ELEMENT_TYPE type, CGraph* owner = NULL);


public:
	GRAPH_ELEMENT_TYPE M_e_type();

	int M_serial_number() const;

	string M_label() const;

	void* operator[] (void* index) const;

	virtual string ToString() = 0;
	virtual void SetLabel(string label) = 0;
};

class CGraphNode : public CGraphPrimitive {
private:
	list <CGraphEdge> m_OutgoingEdges;
	list <CGraphEdge> m_IngoingEdges;
	list <CGraphEdge> m_Successors;
	list <CGraphEdge> m_Predecessors;

public:
	CGraphNode(CGraph ownerGraph);
};

class CGraphEdge : public CGraphPrimitive {

};

class CGraph : public CGraphPrimitive {
public:
	virtual string ToString() const;
	virtual void setLabel()  const;
protected:
	CGraph();
};

#endif