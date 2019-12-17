.section .text
.align 2
.global initPwm

.include "fe310_memory_map.inc"

.equ GPIO_ALL_LEDS,   0x00680000
.equ GPIO_RED_LED,    0x00400000
.equ GPIO_BLUE_LED,   0x00200000
.equ GPIO_GREEN_LED,  0x00080000

initPwm:
    addi sp, sp, -16
    sw ra, 12(sp)
_initGpio:
    li t0, GPIO_BADDR
    li t1, GPIO_ALL_LEDS
    sw t1, GPIO_OUTPUT_EN_OADDR(t0)
    sw t1, GPIO_IOFEN_OADDR(t0)
    sw t1, GPIO_IOFSEL_OADDR(t0)
    ;sw t1, GPIO_OUT_XOR_OADDR(t0)
_initPwm:
    li t0, PWM1_BADDR
    lw t1, PWM_PWMCFG_OADDR(t0)
    li t2, 0x0000FFFF
    sw t2, PWM_PWMCMP0_OADDR(t0)
    sw t2, PWM_PWMCMP1_OADDR(t0)
    sw t2, PWM_PWMCMP2_OADDR(t0)
    sw t2, PWM_PWMCMP3_OADDR(t0)
    li t2, PWM_PWMENALWAYS
    li t3, 2
    or t2, t2, t3
    sw t2, PWM_PWMCFG_OADDR(t0)
    lw ra, 12(sp)
    addi sp, sp, 16
    ret
