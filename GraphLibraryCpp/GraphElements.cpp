#include  "GraphElements.h"

int CGraphPrimitive::ms_UniqueSerialNumberCounter = 0;

CGraphPrimitive::CGraphPrimitive(GRAPH_ELEMENT_TYPE type, CGraph* owner)
{
	m_algorithmOutput = new map<void*, void*>();
	m_eType = type;
	m_owner = owner;
	m_SerialNumber = ms_UniqueSerialNumberCounter++;
}


GRAPH_ELEMENT_TYPE CGraphPrimitive::M_e_type()
{
	return m_eType;
}

int CGraphPrimitive::M_serial_number() const
{
	return m_SerialNumber;
}

string CGraphPrimitive::M_label() const
{
	return m_Label;
}

void* CGraphPrimitive::operator[](void* index) const
{
	const map<void*, void*>::iterator it = m_algorithmOutput->find(index);
	if (it != m_algorithmOutput->end()) {
		return (*m_algorithmOutput)[index];
	}
	return NULL;
}