.section .text
.align 2
.global setPwm

.include "fe310_memory_map.inc"

.equ NOERROR,   0
.equ ERRPWMBLK, 1
.equ ERRPWMCH,  2


# a0 : PWM block
# a1 : PWM channel
# a2 : PWM compare value
setPwm:
    addi sp, sp, -20
    sw ra, 16(sp)

# t0 : PWM block base address
_selPwmBaddr:
    li t0, PWM0_BADDR                # Select PWM base address
    beqz a0, _selPwmCmpOaddr
    li t0, PWM1_BADDR
    addi a0, a0, -1
    beqz a0, _selPwmCmpOaddr
    li t0, PWM2_BADDR
    addi a0, a0, -1
    beqz a0, _selPwmCmpOaddr
    li a0, ERRPWMBLK                 # Error, invalid PWM block
    j _exit

# t1 : PWM channel compare register offset address
_selPwmCmpOaddr:
    li t1, PWM_PWMCMP0_OADDR
    beqz a1, _setPwm
    addi a1, a1, -1
    li t1, PWM_PWMCMP1_OADDR
    beqz a1, _setPwm
    addi a1, a1, -1
    li t1, PWM_PWMCMP2_OADDR
    beqz a1, _setPwm
    addi a1, a1, -1
    li t1, PWM_PWMCMP3_OADDR
    beqz a1, _setPwm
    addi a1, a1, -1
    li a0, ERRPWMCH                  # Error, invalid PWM channel
    j _exit

_setPwm:
    add t1, t1, t0
    sw a2, (t1)
    li a0, NOERROR

_exit:
    lw ra, 16(sp)
    addi sp, sp, 20
    ret
