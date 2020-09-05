#pragma once
#include "Headers.h"
#define TIME_FORMAT L"[%hd년%hd월%hd일 %hd시%hd분 %hd.%hd초]:: "
#define TIME_FORMATA "[%hd년%hd월%hd일 %hd시%hd분 %hd.%hd초]:: "

class CLogPrinter
{
public : 
    static void LeaveLogOnConsole(const wchar_t* format , ...)
    {
        va_list ap;
        va_start(ap, format);
        wchar_t buf[256];
        wvsprintf(buf, format, ap);
        va_end(ap);

        SYSTEMTIME STT;
        GetLocalTime(&STT);
        WCHAR BUF[128];
        ZeroMemory(BUF, 128 * sizeof(WCHAR));
        wsprintf(BUF, TIME_FORMAT,
            STT.wYear,
            STT.wMonth,
            STT.wDay,
            STT.wHour,
            STT.wMinute,
            STT.wSecond,
            STT.wMilliseconds
        );
        wprintf(BUF);
        wprintf(L"%s\n", buf);

    }
    static void LeaveLogOnConsole(const char* format, ...)
    {
        va_list ap;
        va_start(ap, format);
        char buf[256];
        vsprintf_s(buf, format, ap);
        va_end(ap);



        SYSTEMTIME STT;
        GetLocalTime(&STT);
        CHAR BUF[128];
        ZeroMemory(BUF, 128 * sizeof(CHAR));
        sprintf_s(BUF, TIME_FORMATA,
            STT.wYear,
            STT.wMonth,
            STT.wDay,
            STT.wHour,
            STT.wMinute,
            STT.wSecond,
            STT.wMilliseconds
        );
        printf(BUF);
        printf("%s\n", buf);

    }



    CLogPrinter() { }
    virtual ~CLogPrinter() { }

};


