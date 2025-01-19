#include "Component.h"

HRESULT __stdcall CList::QueryInterface(REFIID iid, void** ppv)
{
  //  interface IX : IUnknown {};
  //  interface IY : IUnknown {};
  //  class CA:public IX, public IY{};
  ////  HRESULT _stdcall CA::QueryInterface()
    if (iid == IID_IUnknown) {
        *ppv = static_cast<ICollection*>(this);
    }
    else if (iid == IID_IColletion) {
        *ppv = static_cast<ICollection*>(this);
    }
    else if (iid == IID_IEnumerator) {
        *ppv = static_cast<IEnumerator*>(this);
    }
    else {
        *ppv = NULL;
        return E_NOINTERFACE;
    }
    AddRef();
    return S_OK;
}

ULONG __stdcall CList::AddRef()
{

    return ++m_cRef;
}

ULONG __stdcall CList::Release()
{
    if (--m_cRef == 0) {
        delete this;
        return 0;
    }
    return m_cRef;
}

HRESULT __stdcall CList::Add(Object obj)
{
    perem.push_back(obj);
    return E_NOTIMPL;
}

HRESULT __stdcall CList::Remove(Object obj)
{
    perem.remove(obj);
    return E_NOTIMPL;
}

HRESULT __stdcall CList::GetCount(unsigned* count)
{
    return E_NOTIMPL;
}

HRESULT __stdcall CList::ToArray(ObjectArray** arr)
{
    return E_NOTIMPL;
}

bool operator==(Object &obj, Object &obj) {

    return 0;
}