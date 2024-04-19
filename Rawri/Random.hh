#ifndef __RAWRI__RANDOM__HH__
#define __RAWRI__RANDOM__HH__

#include <chrono>
#include <random>

namespace Rawri 
{
    namespace Random
    {
        static std::random_device g_RandomDevice;
        static bool				  g_IsDeviceInitialized = false;
        static std::mt19937		  g_Generator;

        inline int32_t Gen(int32_t min, int32_t max)
        {
            if (!g_IsDeviceInitialized)
            {
                std::mt19937::result_type seed =
                    g_RandomDevice() ^ ((std::mt19937::result_type)std::chrono::duration_cast<std::chrono::seconds>(
                                std::chrono::system_clock::now().time_since_epoch())
                                .count() +
                            (std::mt19937::result_type)std::chrono::duration_cast<std::chrono::microseconds>(
                                std::chrono::high_resolution_clock::now().time_since_epoch())
                                .count());

                g_Generator.seed(seed);
                g_IsDeviceInitialized = true;
            }

            std::uniform_int_distribution<int32_t> distrib(min, max);
            return distrib(g_Generator);
        }

        inline bool Gen(double chanceOfTrue) 
        {
            int random = Gen(0, 100);
            return random < chanceOfTrue;
        }
    }
}

#endif	// __RAWRI__RANDOM__HH__