/* ============================================================================================================================ *//**
 * @file       asm.cpp
 * @author     Krzysztof Pierczyk (krzysztof.pierczyk@gmail.com)
 * @maintainer Krzysztof Pierczyk (krzysztof.pierczyk@gmail.com)
 * @date       Tuesday, 18th June 2024 1:06:13 pm
 * @modified   Tuesday, 18th June 2024 1:08:42 pm by Krzysztof Pierczyk (k.pierczyk@wb.com.pl)
 * @project    Developer Interviews
 * @brief      Inline GASM for ARMv7-M architecture
 * 
 * 
 * @copyright Krzysztof Pierczyk © 2024
 */// ============================================================================================================================= */

[[noreturn]] void hard_fault_handler(std::uint32_t* hardfault_args);

[[noreturn]]
[[gnu::naked]]
[[gnu::weak]]
void hard_fault(void) {

	asm volatile(

        ".syntax unified \n"

	    "mov r0, %[return_stack_bit_mask] \n"
	    "mov r1, lr                       \n"
	    "tst r0, r1                       \n"
	    "beq _MSP                         \n"

	"_PSP:                                \n"
	    "mrs r0, psp                      \n"
	    "bx %[handler]                    \n"

	"_MSP:                                \n"
	    "mrs r0, msp                      \n"
	    "bx %[handler]                    \n"

        ".syntax divided \n"

    :
    : [return_stack_bit_mask] "i" (0b100),
      [handler]               "r" (hard_fault_handler)
    );
    
}