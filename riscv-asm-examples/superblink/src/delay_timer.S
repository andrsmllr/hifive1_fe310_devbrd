.section .text
.align 2
.global delay_timer

.include "memory_map.inc"

.equ MTIME, 0x0200BFF8
.equ MTIME_FREQ, 33

# Arguments
# a0 : delay in milliseconds
delay_timer:
    addi sp, sp, -16
    sw ra, 12(sp)

    li t0, MTIME
    lw t1, 0(t0)        # Get current time
    li t2, MTIME_FREQ
    mul t2, t2, a0
    add t2, t1, t2
1:  lw t1, 0(t0)
    ble t1, t2, 1b

    lw ra, 12(sp)
    addi sp, sp, 16
    ret
