#include "Timer.h"



int CTimer::UpdateTimer()
{
    //경과 시간을 리턴한다.
    QueryPerformanceCounter(&m_nNow);
    float ElapsedTime =  ((float)(m_nNow.QuadPart - m_nLast.QuadPart )) / ((float)m_nFrequency.QuadPart);
    QueryPerformanceCounter(&m_nLast);
    //ms 단위.
    float fret = (ElapsedTime * 1000.0f);
    return (int)(fret);

}

void CTimer::FixStartPoint()
{
    QueryPerformanceCounter(&m_nLast);
}

void CTimer::FixEndPoint()
{
    QueryPerformanceCounter(&m_nNow);

}

int CTimer::GetTimeWithStartAndEnd()
{
    float ElapsedTime = ((float)(m_nNow.QuadPart - m_nLast.QuadPart)) / ((float)m_nFrequency.QuadPart);
    float fret = (ElapsedTime * 1000.0f);
    return (int)(fret);

    return 0;
}



CTimer::CTimer()
{
    ZeroMemory(&m_nLast, sizeof(m_nLast));
    ZeroMemory(&m_nNow, sizeof(m_nNow));
    ZeroMemory(&m_nFrequency, sizeof(m_nFrequency));
    QueryPerformanceFrequency(&m_nFrequency);
    QueryPerformanceCounter(&m_nLast);
    QueryPerformanceCounter(&m_nNow);

}


CTimer::~CTimer()
{
}
