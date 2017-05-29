#include "ThreadUnix.h"

#include <iostream>
#include <thread>

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

    this_thread::sleep_for(std::chrono::milliseconds(framerate - elapsedTime));

}
