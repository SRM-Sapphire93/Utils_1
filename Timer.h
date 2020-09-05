#pragma once
#include "Headers.h"
class CTimer
{
    LARGE_INTEGER m_nLast;
    LARGE_INTEGER m_nNow;
    LARGE_INTEGER m_nFrequency;




public:

    int UpdateTimer();
    void FixStartPoint();
    void FixEndPoint();
    int GetTimeWithStartAndEnd();


    CTimer();
    virtual ~CTimer();
};

