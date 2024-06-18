/* ============================================================================================================================ *//**
 * @file       crc.cpp
 * @author     Krzysztof Pierczyk (krzysztof.pierczyk@gmail.com)
 * @maintainer Krzysztof Pierczyk (krzysztof.pierczyk@gmail.com)
 * @date       Tuesday, 18th June 2024 1:45:24 pm
 * @modified   Tuesday, 18th June 2024 2:03:53 pm by Krzysztof Pierczyk (k.pierczyk@wb.com.pl)
 * @project    Developer Interviews
 * @brief      Tunable runtime CRC calculation library API design
 * 
 * 
 * @copyright Krzysztof Pierczyk © 2024
 */// ============================================================================================================================= */

#include <array>
#include <tuple>
#include <algorithm>
#include <cstddef>

/* ================================================================================================================================ */

namespace crc {

    template<typename Config>
    class calculator { /* ... */ };

    template<typename...>
    struct config;

    template<typename>
    struct representation;

    template<auto>
    struct polynomial;
    
    template<auto>
    struct initial_value;
    
    template<auto>
    struct final_xor_value;
    
    template<auto>
    struct lookup_width;
    
    template<auto>
    struct unroll_size;

} // End namespace crc

template<
    typename LookupWidth,
    typename UnrollSize
> struct ethernet :
    public crc::calculator<
        crc::config<
            crc::representation<std::uint32_t>,
            crc::mode::shift_right_simple,
            crc::polynomial     <0xEDB88320>,
            crc::initial_value  <0xffffffff>,
            crc::final_xor_value<0xffffffff>,
            LookupWidth,
            UnrollSize
        >
    >
{ };

/* ================================================================================================================================ */

int main() {

    std::tuple data {
        0x08, 0x0F, 0x1A, 0x01, 0x00, 0x7F,
        0xFF, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x01, 0x02, 0x03
    };

    auto data_bytes = std::apply(
        [](auto... bytes) {
            return std::array{ static_cast<std::byte>(bytes)... };
        }
    , data);

    auto result = ethernet<
        crc::lookup_width<8>,
        crc::unroll_size<8>
    >::calculate(data_bytes);
    
    return 0;
}

/* ================================================================================================================================ */
