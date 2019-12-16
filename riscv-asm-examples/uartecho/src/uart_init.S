.section .text
.align 2
.global uart_init

.include "fe310_memory_map.inc"

.equ GPIO_UART0_TX, (1 << 17)
.equ GPIO_UART0_RX, (1 << 16)

uart_init:
init_uart0_gpios:
    li  t0, GPIO_BADDR
    lw  t1, GPIO_OUTPUT_EN_OADDR(t0)
    li  t2, GPIO_UART0_RX
    or  t1, t1, t2
    li  t2, GPIO_UART0_TX
    or  t1, t1, t2
    sw  t1, GPIO_OUTPUT_EN_OADDR(t0)
init_uart0_regs:
    li  t0, UART0_BADDR
    sw  x0, UART_IE_OADDR(t0)         # Disable UART0 interrupts
    #li t1,                           # Use default Baud rate 115200 for now
    #sw t1, UART_DIV_OADDR(t0)
    lw  t1, UART_TXCTRL_OADDR(t0)     # Enable UART0 TX
    ori t1, t1, UART_TXCTRL_TXEN
    sw  t1, UART_TXCTRL_OADDR(t0)
    lw  t1, UART_RXCTRL_OADDR(t0)     # Enable UART0 RX    
    ori t1, t1, UART_RXCTRL_RXEN
    sw  t1, UART_RXCTRL_OADDR(t0)
    ret
