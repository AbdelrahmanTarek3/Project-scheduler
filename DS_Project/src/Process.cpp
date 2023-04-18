#include"../include/Process.h"

Process::Process(int at, int pid, int ct, int nio)
{
    setPID(pid);
    setAT(at);
    setCT(ct);
    setIO_number(nio);
}

void Process::setPID(int i)
{
    PID=i;
}

int Process::getPID()
{
    return PID;
}

void Process::setAT(int a)
{
    AT = a;
}

int Process::getAT()
{
    return AT;
}

void Process::setRT(int r)
{
    RT = r;
}

int Process::getRT()
{
    return RT;
}

void Process::setCT(int c)
{
    CT = c;
}

int Process::getCT()
{
    return CT;
}

void Process::setTT(int t)
{
    TT = t;
}

int Process::getTT()
{
    return TT;
}

void Process::setTRT(int tr)
{
    TRT = tr;
}

int Process::getTRT()
{
    return TRT;
}

void Process::setWT(int w)
{
    WT = w;
}

int Process::getWT()
{
    return WT;
}

void Process::setIO_number(int io)
{
    IO_number = io;
}

int Process::getIO_number()
{
    return IO_number;
}

void Process::setremaining_time(int rt)
{
    remaining_time = rt;
}

int Process::getremaining_time(int time)
{
    // return RT + CT - time;
    return remaining_time;
}