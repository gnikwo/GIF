#ifndef THREAD_H
#define THREAD_H

#include <string>

#include "ThreadInterface.h"

namespace LO43{

    class Thread: public ThreadInterface
    {

        public:

            Thread();
            virtual ~Thread();

    };

}

#endif
