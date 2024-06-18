/* ============================================================================================================================ *//**
 * @file       meta.cpp
 * @author     Krzysztof Pierczyk (krzysztof.pierczyk@gmail.com)
 * @maintainer Krzysztof Pierczyk (krzysztof.pierczyk@gmail.com)
 * @date       Tuesday, 18th June 2024 1:06:13 pm
 * @modified   Tuesday, 18th June 2024 1:13:58 pm by Krzysztof Pierczyk (k.pierczyk@wb.com.pl)
 * @project    Developer Interviews
 * @brief      Metaprogramming basics
 * 
 * 
 * @copyright Krzysztof Pierczyk © 2024
 */// ============================================================================================================================= */

#include <iostream>
#include <type_traits>

/* ================================================================================================================================ */

template<typename T>
struct always_false :
    std::false_type
{ };

template<typename T>
constexpr bool always_false_v = always_false<T>::value;

/* ================================================================================================================================ */

template<typename T>
void foo(const T& t) {
    if constexpr(std::is_invocable_r_v<double, T, int>) {
        std::cout << "Result of T: " << t(1) << std::endl;
    } else {
        static_assert(false);
    }
}

/* ================================================================================================================================ */

int main() {

    auto l = [](int i) { return 2 * i; };
    l(1);
    
    foo([](float i) { return 2.0 * i; });
    
    return 0;
}

/* ================================================================================================================================ */
