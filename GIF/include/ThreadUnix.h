#ifndef THREAD_H
#define THREAD_H

#include <string>

#include <pthread.h>
#include <unistd.h>

#include "ThreadInterface.h"
#include "MutexUnix.h"

namespace GIF{

    class Thread: public ThreadInterface
    {

        private:

            Mutex m__runMutex;

            //Thread Linux
            pthread_t m__thread;

        public:

            Thread();
            virtual ~Thread();

    };

}

#endif
