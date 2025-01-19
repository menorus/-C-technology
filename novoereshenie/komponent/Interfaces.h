#pragma once
#include <objbase.h>

//////////////////////////////////////////////////////////////////////////
// “ип объекта

enum ObjectType
{
	// целый
	otInt,

	// вещественный
	otDouble,

	// массив
	otArray
};

//////////////////////////////////////////////////////////////////////////
// ќбъект - значение произвольного типа (предварительное объ€вление)

struct Object;

//////////////////////////////////////////////////////////////////////////
// ObjectArray - ћассив значений Object

struct ObjectArray
{
	// элементы массива
	Object *Data;

	// количество элементов массива
	unsigned Count;
};

//////////////////////////////////////////////////////////////////////////
// ќбъект - значение произвольного типа

struct Object
{
	// тип объекта
	ObjectType Type;

	union
	{
		// значение целого типа
		int Int;

		// значение вещественного типа
		double Double;

		// значение типа "массив"
		ObjectArray *Array;
	} Value;
};

//////////////////////////////////////////////////////////////////////////
// »нтерфейс коллекции
// {37F7727A-0174-4F2B-ADE9-271B949AA229}

// {7E60250C-49C1-448B-A87E-145BB366B76B}
static const GUID IID_IColletion =
{ 0x7e60250c, 0x49c1, 0x448b, { 0xa8, 0x7e, 0x14, 0x5b, 0xb3, 0x66, 0xb7, 0x6b } };

interface ICollection : public IUnknown
{
	// добавить элемент в коллекцию
	virtual HRESULT __stdcall Add(Object obj) = 0;

	// удалить элемент из коллекции
	virtual HRESULT __stdcall Remove(Object obj) = 0;

	// получить количество элементов коллекции
	virtual HRESULT __stdcall GetCount(unsigned *count) = 0;

	// преобразовать коллекцию в массив
	virtual HRESULT __stdcall ToArray(ObjectArray **arr) = 0;
};


//////////////////////////////////////////////////////////////////////////
// »нтерфейс перечислител€
// {7BAAB13D-AC13-484C-A1A0-132B28136425}

static const GUID IID_IEnumerator = 
{ 0xdc7a0692, 0xd98d, 0x42a1, { 0xb2, 0x5c, 0xd3, 0x51, 0xc, 0x0, 0x17, 0xcc } };


interface IEnumerator : public IUnknown
{
	// возврат в исходное состо€ние
	virtual HRESULT __stdcall Reset() = 0;

	// переход к следующему элементу
	virtual HRESULT __stdcall MoveNext(int *result) = 0;

	// получить текущий элемент
	virtual HRESULT __stdcall GetCurrent(Object *obj) = 0;
};


//////////////////////////////////////////////////////////////////////////
// “ип функции создани€ экземпл€ра компонента

typedef IUnknown* (*CREATEINSTANCEPROC)();


//////////////////////////////////////////////////////////////////////////
// Ёкспортируема€ функци€ создани€ экземпл€ра компонента

extern "C" __declspec(dllexport) IUnknown* CreateInstance();
