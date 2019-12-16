.section .text
.align 2
.global uart_echo

.include "fe310_memory_map.inc"

uart_echo:
    addi sp, sp, -16    # Allocate stack frame
    sw ra, 12(sp)       # Save return address

    jal uart_rx
    jal uart_tx

    lw ra, 12(sp)       # Restore return address
    addi sp, sp, 16     # Deallocate stack frame
    ret

# Receive a byte on UART0 (blocking)
# a0 : receive byte
uart_rx:
    li t0, UART0_BADDR
    li t1, UART_RXDATA_EMPTY
1:  lw a0, UART_RXDATA_OADDR(t0)
    and t2, a0, t1
    bnez t2, 1b
    ret

# Transmit a byte (blocking)
# a0 : transmit byte
uart_tx:
    li t0, UART0_BADDR
    li t1, UART_TXDATA_FULL
1:  lw t2, UART_TXDATA_OADDR(t0)
    and t3, t2, t1
    bnez t3, 1b
    andi a0, a0, UART_TXDATA_DATA
    sw a0, UART_TXDATA_OADDR(t0)
    ret
