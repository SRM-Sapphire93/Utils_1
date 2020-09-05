#pragma once
#include "SafeQueue.h"
#include "Latch.h"
#include "LogPrinter.h"

#define DEFAULTPOOLSIZE 25

#define CASEMEMORYPUSHTOPOOL(TYPE , p) case TYPE : {CMemoryPool<CLASS_##TYPE>::Push( (CLASS_##TYPE*)p ); return; }  
#define POOLINITIALIZE(TYPE)  case TYPE: { CMemoryPool<CLASS_##TYPE>::GetInstance(); break;}

using namespace std;
template <typename T>
class CMemoryPool
{
private : 
     
     static CMemoryPool<T>* m_pInstance;

     CRITICAL_SECTION m_CS;
     T m_Stocks[DEFAULTPOOLSIZE];
     CSafeQueue<T*> m_Queue;


public:

    static CMemoryPool<T>* GetInstance();
    static T* Pop();
    static void Push(T* p);
    void Initialize();
    T* _Pop();
    void _Push(T* p);
    CMemoryPool();
    ~CMemoryPool();
};




template<typename T>
inline CMemoryPool<T>* CMemoryPool<T>::GetInstance()
{
    if (m_pInstance == nullptr)
    {
        m_pInstance = new CMemoryPool<T>;
        m_pInstance->Initialize();
    }

    return m_pInstance;
}

template<typename T>
inline T * CMemoryPool<T>::Pop()
{
    //CLogPrinter::LeaveLogOnConsole(L"%s", __FUNCTIONW__);
    return m_pInstance->_Pop();
}

template<typename T>
inline void CMemoryPool<T>::Push(T * p)
{
    //CLogPrinter::LeaveLogOnConsole(L"%s", __FUNCTIONW__);
    m_pInstance->_Push(p);
    return;
}

template<typename T>
inline void CMemoryPool<T>::Initialize()
{
    InitializeCriticalSection(&m_CS);

    for (int i = 0; i < DEFAULTPOOLSIZE; ++i)
    {
        m_Queue.Push( &(m_Stocks[i]) );
    }

}

template<typename T>
inline T* CMemoryPool<T>::_Pop()
{
    T* ret = nullptr;
    LOCKNOW(&m_CS)
    {
       
        m_Queue.Pop(&ret);
        
    }
    return ret;
}

template<typename T>
inline void CMemoryPool<T>::_Push(T * p)
{
    
    m_Queue.Push(p);
    //CLogPrinter::LeaveLogOnConsole(L"%s ť�뷮 : %d", __FUNCTIONW__, m_Queue.GetUsage());
    return;
}

template<typename T>
inline CMemoryPool<T>::CMemoryPool()
{
    
    

}

template<typename T>
inline CMemoryPool<T>::~CMemoryPool()
{
}


void MemoryPool_StreamPush(void* p);
void MemoryPool_PacketPush(int TYPE, void* p  );


void PacketPoolInitialize();




