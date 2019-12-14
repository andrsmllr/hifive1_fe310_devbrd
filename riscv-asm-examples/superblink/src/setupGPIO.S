.section .text
.align 2
.global setupGPIO

.include "memory_map.inc"
.include "gpio.inc"

setupGPIO:
	addi sp, sp, -16 # Setup stack pointer
	sw ra, 12(sp)    # Save return address to stack

	li t0, GPIO_CTRL_ADDR               # Load the base address of GPIO
	li t1, GPIO_RGB_PINS                # Load the bitmask for all RGB pins
	sw t1, GPIO_OUTPUT_EN(t0)           # Enable output mode on all RGB pins
	sw t1, GPIO_XOR_INVERT(t0)          # Set xor_invert to make all RGB pins active high
	sw x0, GPIO_OUTPUT_VAL(t0)          # Set all RGB pins to 0 to turn off the LEDs

	lw ra, 12(sp)                       # Restore return address
	addi sp, sp, 16                     # Deallocate stack frame
	ret
