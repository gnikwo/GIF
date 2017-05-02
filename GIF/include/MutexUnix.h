#ifndef MUTEX_H
#define MUTEX_H

#include <string>

#include <pthread.h>

#include "MutexInterface.h"

namespace GIF{

    class Mutex: public MutexInterface
    {

        private:

            pthread_mutex_t m__mutex;


        public:

            Mutex();
            virtual ~Mutex();

    };

}

#endif
