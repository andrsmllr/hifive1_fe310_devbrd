.section .text
.align 2
.global setLED

.include "memory_map.inc"
.include "gpio.inc"

.equ NOERROR,   0x00
.equ ERROR,     0x01
.equ LEDON,     0x01

# Arguments:
#   a0: color
#   a1: state
setLED:
    addi sp, sp, -16            # Allocate stack frame
    sw ra, 12(sp)               # Store return address

    li t0, GPIO_CTRL_ADDR
    lw t1, GPIO_OUTPUT_VAL(t0)  # Get current value of the GPIO pins

    beqz a1, ledOff
    li t2, LEDON

    beq a1, t2, ledOn

    li a0, ERROR                # Invalid state, return error
    j exit

ledOff:
    xor a0, a0, 0xFFFFFFFF      # Set requested pin to 0, others 1
    and t1, t1, a0
    sw t1, GPIO_OUTPUT_VAL(t0)
    li a0, NOERROR
    j exit

ledOn:
    xor t1, t1, a0              # Set requested pin to 1, others 0
    sw t1, GPIO_OUTPUT_VAL(t0)
    li a0, NOERROR
    j exit

exit:
    lw ra, 12(sp)               # Deallocate stack frame
    addi sp, sp, 16
    ret
