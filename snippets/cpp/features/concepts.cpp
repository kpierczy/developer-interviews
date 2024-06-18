/* ============================================================================================================================ *//**
 * @file       concepts.cpp
 * @author     Krzysztof Pierczyk (krzysztof.pierczyk@gmail.com)
 * @maintainer Krzysztof Pierczyk (krzysztof.pierczyk@gmail.com)
 * @date       Tuesday, 18th June 2024 1:06:13 pm
 * @modified   Tuesday, 18th June 2024 1:10:42 pm by Krzysztof Pierczyk (k.pierczyk@wb.com.pl)
 * @project    Developer Interviews
 * @brief      Concepts basics
 * 
 * 
 * @copyright Krzysztof Pierczyk © 2024
 */// ============================================================================================================================= */

template <typename T>
concept Clock = requires(T c) { 
    
    typename T::time_point;
    typename T::duration;
    
    { c.now()         } -> typename T::time_point;
    { c.to_time_t()   } -> time_t;
    { c.from_time_t() } -> typename T::time_point;
    
};

template <typename ClockT>
    requires Clock<T>
auto measure_time_since(
    const typename ClockT::time_point& start
) {
    return ClockT::now() - start;
}

/* ================================================================================================================================ */

struct my_clock {
    
    using time_point = int;
    using duration = int;
    
    static auto now()         { return 0; }
    static auto to_time_t()   { return 0; }
    static auto from_time_t() { return 0; }
    
    static constexpr bool is_steady = true;
};

/* ================================================================================================================================ */

int main() {
    auto start = my_clock::now();
    auto duration = measure_time_since<my_clock>(start);
    return 0;
}

/* ================================================================================================================================ */
