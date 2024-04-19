#ifndef __RAWRI__LOGGER__HH__
#define __RAWRI__LOGGER__HH__

#include <iostream>
#include <format>

namespace Rawri 
{
    namespace Log
    {
        template <typename... Args>
        static void Info(const std::string& format, Args&&... args) 
        {
            std::cout << "[I]: " << std::vformat(format, std::make_format_args(args...)) << "\n";
        }	

        template <typename... Args>
        static void Debug(const std::string& format, Args&&... args) 
        {
            std::cout << "[D]: " << std::vformat(format, std::make_format_args(args...)) << "\n";
        }
    }
}

#endif	// __RAWRI__LOGGER__HH__