#ifndef THREAD_H
#define THREAD_H

#include <string>

#include "ThreadInterface.h"
#include "MutexWindows.h"

namespace GIF{

    class Thread
    {

        private:

            Mutex m__runMutex;

        public:

            Thread();
            virtual ~Thread();

    };

}

#endif
