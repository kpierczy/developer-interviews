/* ============================================================================================================================ *//**
 * @file       async.cpp
 * @author     Krzysztof Pierczyk (krzysztof.pierczyk@gmail.com)
 * @maintainer Krzysztof Pierczyk (krzysztof.pierczyk@gmail.com)
 * @date       Wednesday, 19th June 2024 10:49:07 am
 * @modified   Wednesday, 19th June 2024 11:07:30 am by Krzysztof Pierczyk (krzysztof.pierczyk@gmail.com)
 * @project    Developer Interviews
 * @brief      Async implementation review 
 * 
 * 
 * @copyright Krzysztof Pierczyk © 2024
 */// ============================================================================================================================= */

#include <thread>

/* ======================================================= some_async_module ====================================================== */

class some_async :
    public std::thread
{
private:
    
    volatile int result;

public:

    some_async() :
        std::thread{ &some_async::run, this },
        result{ -1 }
    { }

    ~some_async() {
        this->join();
    }

    void run() {
        
        result = 0;
        
        for(int i = 0; i < 1000000; ++i) {
            result += i;
        }
        
    }

    int get_result() {
        return result;
    }

};

/* ================================================================================================================================ */
