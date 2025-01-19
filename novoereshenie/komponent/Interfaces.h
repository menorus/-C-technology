#pragma once
#include <objbase.h>

//////////////////////////////////////////////////////////////////////////
// ��� �������

enum ObjectType
{
	// �����
	otInt,

	// ������������
	otDouble,

	// ������
	otArray
};

//////////////////////////////////////////////////////////////////////////
// ������ - �������� ������������� ���� (��������������� ����������)

struct Object;

//////////////////////////////////////////////////////////////////////////
// ObjectArray - ������ �������� Object

struct ObjectArray
{
	// �������� �������
	Object *Data;

	// ���������� ��������� �������
	unsigned Count;
};

//////////////////////////////////////////////////////////////////////////
// ������ - �������� ������������� ����

struct Object
{
	// ��� �������
	ObjectType Type;

	union
	{
		// �������� ������ ����
		int Int;

		// �������� ������������� ����
		double Double;

		// �������� ���� "������"
		ObjectArray *Array;
	} Value;
};

//////////////////////////////////////////////////////////////////////////
// ��������� ���������
// {37F7727A-0174-4F2B-ADE9-271B949AA229}

// {7E60250C-49C1-448B-A87E-145BB366B76B}
static const GUID IID_IColletion =
{ 0x7e60250c, 0x49c1, 0x448b, { 0xa8, 0x7e, 0x14, 0x5b, 0xb3, 0x66, 0xb7, 0x6b } };

interface ICollection : public IUnknown
{
	// �������� ������� � ���������
	virtual HRESULT __stdcall Add(Object obj) = 0;

	// ������� ������� �� ���������
	virtual HRESULT __stdcall Remove(Object obj) = 0;

	// �������� ���������� ��������� ���������
	virtual HRESULT __stdcall GetCount(unsigned *count) = 0;

	// ������������� ��������� � ������
	virtual HRESULT __stdcall ToArray(ObjectArray **arr) = 0;
};


//////////////////////////////////////////////////////////////////////////
// ��������� �������������
// {7BAAB13D-AC13-484C-A1A0-132B28136425}

static const GUID IID_IEnumerator = 
{ 0xdc7a0692, 0xd98d, 0x42a1, { 0xb2, 0x5c, 0xd3, 0x51, 0xc, 0x0, 0x17, 0xcc } };


interface IEnumerator : public IUnknown
{
	// ������� � �������� ���������
	virtual HRESULT __stdcall Reset() = 0;

	// ������� � ���������� ��������
	virtual HRESULT __stdcall MoveNext(int *result) = 0;

	// �������� ������� �������
	virtual HRESULT __stdcall GetCurrent(Object *obj) = 0;
};


//////////////////////////////////////////////////////////////////////////
// ��� ������� �������� ���������� ����������

typedef IUnknown* (*CREATEINSTANCEPROC)();


//////////////////////////////////////////////////////////////////////////
// �������������� ������� �������� ���������� ����������

extern "C" __declspec(dllexport) IUnknown* CreateInstance();
