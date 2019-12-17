.section .text
.align 2
.global delay_timer

.include "fe310_memory_map.inc"

.equ MTIME_FREQ, 33

# Arguments
# a0 : delay in milliseconds
delay_timer:
    addi sp, sp, -16                 # Allocate stack frame
    sw ra, 12(sp)                    # Save return address

    li t0, CLINT_BADDR
    li t1, CLINT_MTIME_OADDR
    add t0, t0, t1
    lw t1, 0(t0)                     # Get current time
    li t2, MTIME_FREQ
    mul t2, t2, a0
    add t2, t1, t2
1:  lw t1, 0(t0)
    ble t1, t2, 1b

    lw ra, 12(sp)                    # Restore return address  
    addi sp, sp, 16                  # Deallocate stack frame   
    ret
