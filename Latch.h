#pragma once
#include "Headers.h"



class CLatch
{
public :
    LPCRITICAL_SECTION m_pCriticalSection = nullptr;


public:


    explicit operator bool()
    {
        return true;
    }
   
    CLatch(LPCRITICAL_SECTION sc) : m_pCriticalSection(sc)
    {
        
        EnterCriticalSection(m_pCriticalSection);
    }
    explicit CLatch()
    {
        
    }
    virtual ~CLatch()
    {
        if (m_pCriticalSection != nullptr)
            LeaveCriticalSection(m_pCriticalSection);
    }
};

#define LOCKNOW(CS) if( CLatch latch = CS ) 


