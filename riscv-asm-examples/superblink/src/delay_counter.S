.section .text
.align 2
.global delay_counter

.equ F_CPU,         320000000L
.equ CYCLES_PER_MS, (F_CPU / (1000 * 2))

# Arguments:
# a0: milliseconds
delay_counter:
    addi sp, sp, -16    # Allocate stack frame
    sw ra, 12(sp)

    mv t0, a0
1:  beqz t0, exit
    addi t0, t0, -1
    j wait_ms

wait_ms:
    li t1, CYCLES_PER_MS
2:  addi t1, t1, -1
    bnez t1, 2b
    j 1b

exit:
    lw ra, 12(sp)       # Deallocate stack frame
    addi sp, sp, 16
    ret
