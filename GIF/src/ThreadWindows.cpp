#include "ThreadWindows.h"

#include <iostream>

#include <windows.h>

#include <conio.h>
#include <process.h>

using namespace std;
using namespace GIF;

Thread::Thread()
{



}


Thread::~Thread()
{



}

void Thread::sleep(int ms)
{

    Sleep(ms);

}
