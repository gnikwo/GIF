//Exemple de code (sale) compatible Windows et Linux
//A compiler avec "gcc -o exemple -std=c++11 -pthread exemple_multi_os.cpp"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include <chrono>
#include <thread>

#ifdef _WIN32

	#include <windows.h>

	#include <conio.h>
	#include <process.h>

#elif __linux__

    #include <pthread.h>
    #include <unistd.h>

#elif __APPLE


#else
#   error "Unknown compiler"
#endif

#define MAX_THREADS  1024

int main( void );                    // Thread 1: main
void* test( void * MyID );
void psleep(int ms);

int ThreadNr;                    // Number of threads started

#if _win32

    //Mutex Windows
    HANDLE  hRunMutex;                   // "Keep Running" mutex

#elif __linux__

    pthread_mutex_t mutex;

    //Thread Linux
    pthread_t thread;

#endif

int main() // Thread One
{

	ThreadNr = 0;
	ThreadNr++;

#if _win32

    //Mutex Windows
    hRunMutex = CreateMutex( NULL, TRUE, NULL );      // Set

    WaitForSingleObject( hRunMutex, INFINITE ); //WaitForSingleObject( hRunMutex, 75L ) == WAIT_TIMEOUT;

    //Thread Windows
    _beginthread( test, 0, &ThreadNr);

#elif __linux__

    //Mutex Linux
    pthread_mutex_init(&mutex, NULL);

    pthread_mutex_lock(&mutex);

    //Thread Linux
    pthread_create(&thread, NULL, test, &ThreadNr);

#endif


    while(1)
	{
		printf("test1\n");
		psleep(100);
	}


#if _win32

    //Mutex Windows
	ReleaseMutex( hRunMutex );

    CloseHandle( hRunMutex );

#elif __linux__

    //Mutex Linux
    pthread_mutex_lock(&mutex);

    pthread_mutex_destroy(&mutex);

    //Thread Linux
    pthread_exit(NULL);

#endif

}

void* test( void *pMyID )
{
    while(1)
	{
		printf("test2\n");
		psleep(100);
	}

#if _win32


#elif __linux__

    //Thread Linux
    pthread_exit(NULL);

#endif

}


void psleep(int ms)
{

#if _win32

    Sleep(ms);

#elif __linux__

    sleep(ms/1000.0);

#endif

}
