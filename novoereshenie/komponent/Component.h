#pragma once
#include <iostream>
#include "Interfaces.h"
#include <list>

//////////////////////////////////////////////////////////////////////////
// ����� ������
class CList : public ICollection, public IEnumerator
{
	// ������� ������
	ULONG m_cRef;
	std::list <Object> perem;
	// ��������� ������ ���������� ������ ����� ��������� ��
	// ��������������� ����������, ������� � ���������� ����� ���� ���������!

	////////////////////////////
	// ������ IUnknown
	HRESULT __stdcall QueryInterface(REFIID iid, void** ppv);
	ULONG __stdcall AddRef();
	ULONG __stdcall Release();
	
	////////////////////////////
	// ������ ICollection
	HRESULT __stdcall Add(Object obj);
	HRESULT __stdcall Remove(Object obj);
	HRESULT __stdcall GetCount(unsigned *count);
	HRESULT __stdcall ToArray(ObjectArray **arr);

	////////////////////////////
	// ������ IEnumerator
	HRESULT __stdcall Reset();
	HRESULT __stdcall MoveNext(int *result);
	HRESULT __stdcall GetCurrent(Object *obj);

public:

	// �����������
	CList() : m_cRef(0) {}

	// ����������
	~CList() { std::cout << __FUNCTION__ << std::endl; }
};
