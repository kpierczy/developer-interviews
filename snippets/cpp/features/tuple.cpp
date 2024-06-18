/* ============================================================================================================================ *//**
 * @file       tuple.cpp
 * @author     Krzysztof Pierczyk (krzysztof.pierczyk@gmail.com)
 * @maintainer Krzysztof Pierczyk (krzysztof.pierczyk@gmail.com)
 * @date       Tuesday, 18th June 2024 1:06:13 pm
 * @modified   Tuesday, 18th June 2024 1:14:21 pm by Krzysztof Pierczyk (k.pierczyk@wb.com.pl)
 * @project    Developer Interviews
 * @brief      Tuple basics
 * 
 * 
 * @copyright Krzysztof Pierczyk © 2024
 */// ============================================================================================================================= */

#include <tuple>

/* ================================================================================================================================ */

template<typename... Ts>
void print_tuple(const std::tuple<Ts...>& t);

/* ================================================================================================================================ */

int main() {
    std::tuple<int, double, const char*> t { 1, 2.0, "three" };
    print_tuple(t);    
}

/* ================================================================================================================================ */
