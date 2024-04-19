#ifndef __RAWRI__THREAD__HH__
#define __RAWRI__THREAD__HH__

#include <thread>
#include <chrono>

namespace Rawri 
{
    namespace Thread
    {
        template <class _Rep, class _Period>
        inline void Sleep(const std::chrono::duration<_Rep, _Period>& _Rel_time)
        {
            std::this_thread::sleep_for(_Rel_time);
        }
    }
}

#endif // __RAWRI__THREAD__HH__