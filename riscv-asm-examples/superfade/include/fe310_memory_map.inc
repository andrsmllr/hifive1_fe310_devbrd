# FE310 memory map, ref. SiFive FE310-G000 Manual v3p1.
.equ DEBUG_BADDR,                    0x00000100
.equ MASK_ROM_BADDR,                 0x00001000
.equ OTP_MEM_BADDR,                  0x00020000
.equ CLINT_BADDR,                    0x02000000
.equ PLIC_BADDR,                     0x0C000000
.equ AON_BADDR,                      0x10000000
.equ PRCI_BADDR,                     0x10008000
.equ OTP_CTL_BADDR,                  0x10010000
.equ GPIO_BADDR,                     0x10012000
.equ UART0_BADDR,                    0x10013000
.equ QSPI0_CTL_BADDR,                0x10014000
.equ PWM0_BADDR,                     0x10015000
.equ UART1_BADDR,                    0x10023000
.equ QSPI1_BADDR,                    0x10024000
.equ PWM1_BADDR,                     0x10025000
.equ QSPI2_BADDR,                    0x10034000
.equ PWM2_BADDR,                     0x10035000
.equ QPSI0_FLASH_BADDR,              0x20000000
.equ DTIM_BADDR,                     0x80000000

# PRCI Registers
.equ PRCI_HFROSCCFG_OADDR,           0x00000000
.equ PRCI_HFROSCCFG_HFROSCDIV,       0x0000003F
.equ PRCI_HFROSCCFG_HFROSCTRIM,      0x001F0000
.equ PRCI_HFROSCCFG_HFROSCEN,        0x40000000
.equ PRCI_HFROSCCFG_HFROSCRDY,       0x80000000
.equ PRCI_HFXOSCCFG_OADDR,           0x00000004
.equ PRCI_HFXOSCCFG_HFXOSCEN,        0x40000000
.equ PRCI_HFXOSCCFG_HFXOSCRDY,       0x80000000
.equ PRCI_PLLCFG_OADDR,              0x00000008
.equ PRCI_PLLCFG_PLLR,               0x00000007
.equ PRCI_PLLCFG_PLLF,               0x000001F0
.equ PRCI_PLLCFG_PLLQ,               0x00000600
.equ PRCI_PLLCFG_PLLSEL,             0x00010000
.equ PRCI_PLLCFG_PLLREFSEL,          0x00020000
.equ PRCI_PLLCFG_PLLBYPASS,          0x00040000
.equ PRCI_PLLCFG_PLLLOCK,            0x80000000
.equ PRCI_PLLOUTDIV_OADDR,           0x0000000C
.equ PRCI_PLLOUTDIV_OADDR,           0x0000003F
.equ PRCI_PLLOUTDIV_OADDR,           0x00003F00
.equ PRCI_LFROSC_OADDR,              0x00000070
.equ PRCI_LFROSC_LFROSCDIV,          0x0000003F
.equ PRCI_LFROSC_LFROSCTRIM,         0x001F0000
.equ PRCI_LFROSC_LFROSCEN,           0x40000000
.equ PRCI_LFROSC_LFROSCRDY,          0x80000000
                                     
# Core-Local Interruptor             
.equ CLINT_MSIP0_OADDR,              0x00000000
.equ CLINT_MTIMECMP0_OADDR,          0x00004000
.equ CLINT_MTIME_OADDR,              0x0000BFF8

# Platform-Level Interrupt Control   ler
.equ PLIC_SOURCE1_PRIO_OADDR,        0x00000004
.equ PLIC_SOURCE1_PRIO,              0x00000003
.equ PLIC_SOURCE51_PRIO_OADDR,       0x000000CC
.equ PLIC_START_PENDING_OADDR,       0x00001000
.equ PLIC_PENDING1,                  0xFFFFFFFF
.equ PLIC_LAST_PENDING_OADDR,        0x00001004
.equ PLIC_PENDING2,                  0x000FFFFF
.equ PLIC_HART0_START_MIE_OADDR,     0x00002000
.equ PLIC_HART0_MIE1,                0xFFFFFFFF
.equ PLIC_HART0_END_MIE_OADDR,       0x00002004
.equ PLIC_HART0_MIE2,                0x000FFFFF
.equ PLIC_HART0_MPT_OADDR,           0x00200000
.equ PLIC_HART0_threshold,           0x00000003
.equ PLIC_HART0_MC_OADDR,            0x00200004
.equ PLIC_HART0_CLAIM,               0xFFFFFFFF
                                     
# OTP                                
.equ OTP_CTL_LOCK_OADDR,             0x00000000
.equ OTP_CTL_CK_OADDR,               0x00000004
.equ OTP_CTL_OE_OADDR,               0x00000008
.equ OTP_CTL_SEL_OADDR,              0x0000000C
.equ OTP_CTL_WE_OADDR,               0x00000010
.equ OTP_CTL_MR_OADDR,               0x00000014
.equ OTP_CTL_MRR_OADDR,              0x00000018
.equ OTP_CTL_MPP_OADDR,              0x0000001C
.equ OTP_CTL_VRREN_OADDR,            0x00000020
.equ OTP_CTL_VPPEN_OADDR,            0x00000024
.equ OTP_CTL_A_OADDR,                0x00000028
.equ OTP_CTL_D_OADDR,                0x0000002C
.equ OTP_CTL_Q_OADDR,                0x00000030
.equ OTP_CTL_RSCTRL_OADDR,           0x00000034
.equ OTP_CTL_RSCTRL_SCALE,           0x00000007
.equ OTP_CTL_RSCTRL_TAS,             0x00000008
.equ OTP_CTL_RSCTRL_TRP,             0x00000010
.equ OTP_CTL_RSCTRL_TACC,            0x00000020

# AON
.equ AON_WDOGCFG_OADDR,              0x00000000
.equ AON_WDOGCFG_SCALE,              0x0000000F
.equ AON_WDOGCFG_RSTEN,              0x00000100
.equ AON_WDOGCFG_ZEROCMP,            0x00000200
.equ AON_WDOGCFG_ENALWAYS,           0x00001000
.equ AON_WDOGCFG_COREAWAKE,          0x00002000
.equ AON_WDOGCFG_IP0,                0x10000000
.equ AON_WDOGCOUNT_OADDR,            0x00000008
.equ AON_WDOS_OADDR,                 0x00000010
.equ AON_WDOGFEED_OADDR,             0x00000018
.equ AON_WDOGKEY_OADDR,              0x0000001C
.equ AON_WDOGCMP0_OADDR,             0x00000020
.equ AON_WDOGCMP0,                   0x0000FFFF
.equ AON_RTCCFG_OADDR,               0x00000040
.equ AON_RTCCOUNTLO_OADDR,           0x00000048
.equ AON_RTCCOUNTHI_OADDR,           0x0000004C
.equ AON_RTCS_OADDR,                 0x00000050
.equ AON_RTCCMP0_OADDR,              0x00000060
.equ AON_LFROSCCFG_OADDR,            0x00000070
.equ AON_BACKUP0_OADDR,              0x00000080
.equ AON_BACKUP1_OADDR,              0x00000084
.equ AON_BACKUP2_OADDR,              0x00000088
.equ AON_BACKUP3_OADDR,              0x0000008C
.equ AON_BACKUP4_OADDR,              0x00000090
.equ AON_BACKUP5_OADDR,              0x00000094
.equ AON_BACKUP6_OADDR,              0x00000098
.equ AON_BACKUP7_OADDR,              0x0000009C
.equ AON_BACKUP8_OADDR,              0x000000A0
.equ AON_BACKUP9_OADDR,              0x000000A4
.equ AON_BACKUP10_OADDR,             0x000000A8
.equ AON_BACKUP11_OADDR,             0x000000AC
.equ AON_BACKUP12_OADDR,             0x000000B0
.equ AON_BACKUP13_OADDR,             0x000000B4
.equ AON_BACKUP14_OADDR,             0x000000B8
.equ AON_BACKUP15_OADDR,             0x000000BC
.equ AON_PMUWAKEUPI0_OADDR,          0x00000100
.equ AON_PMUWAKEUPI1_OADDR,          0x00000104
.equ AON_PMUWAKEUPI2_OADDR,          0x00000108
.equ AON_PMUWAKEUPI3_OADDR,          0x0000010C
.equ AON_PMUWAKEUPI4_OADDR,          0x00000110
.equ AON_PMUWAKEUPI5_OADDR,          0x00000114
.equ AON_PMUWAKEUPI6_OADDR,          0x00000118
.equ AON_PMUWAKEUPI7_OADDR,          0x0000011C
                                     
.equ AON_PMUSLEEPI0_OADDR,           0x00000120
.equ AON_PMUSLEEPI1_OADDR,           0x00000124
.equ AON_PMUSLEEPI2_OADDR,           0x00000128
.equ AON_PMUSLEEPI3_OADDR,           0x0000012C
.equ AON_PMUSLEEPI4_OADDR,           0x00000130
.equ AON_PMUSLEEPI5_OADDR,           0x00000134
.equ AON_PMUSLEEPI6_OADDR,           0x00000138
.equ AON_PMUSLEEPI7_OADDR,           0x0000013C
                                     
.equ AON_PMUIE_OADDR,                0x00000140
.equ AON_PMUIE,                      0x0000000F
.equ AON_PMUCAUSE_OADDR,             0x00000144
.equ AON_PMUCAUSE,                   0xFFFFFFFF
.equ AON_PMUSLEEP_OADDR,             0x00000148
.equ AON_PMUKEY_OADDR,               0x0000014C

# GPIO
.equ GPIO_INPUT_VAL_OADDR,           0x00000000
.equ GPIO_INPUT_EN_OADDR,            0x00000004
.equ GPIO_OUTPUT_EN_OADDR,           0x00000008
.equ GPIO_OUTPUT_VAL_OADDR,          0x0000000C
.equ GPIO_PUE_OADDR,                 0x00000010
.equ GPIO_DS_OADDR,                  0x00000014
.equ GPIO_RISE_IE_OADDR,             0x00000018
.equ GPIO_RISE_IP_OADDR,             0x0000001C
.equ GPIO_FALL_IE_OADDR,             0x00000020
.equ GPIO_FALL_IP_OADDR,             0x00000024
.equ GPIO_HIGH_IE_OADDR,             0x00000028
.equ GPIO_HIGH_IP_OADDR,             0x0000002C
.equ GPIO_LOW_IE_OADDR,              0x00000030
.equ GPIO_LOW_IP_OADDR,              0x00000034
.equ GPIO_IOFEN_OADDR,               0x00000038
.equ GPIO_IOFSEL_OADDR,              0x0000003C
.equ GPIO_OUT_XOR_OADDR,             0x00000040

# UART
.equ UART_TXDATA_OADDR,              0x00000000
.equ UART_TXDATA_DATA,               0x000000FF
.equ UART_TXDATA_FULL,               0x80000000
.equ UART_RXDATA_OADDR,              0x00000004
.equ UART_RXDATA_DATA,               0x000000FF
.equ UART_RXDATA_EMPTY,              0x80000000
.equ UART_TXCTRL_OADDR,              0x00000008
.equ UART_TXCTRL_TXEN,               0x00000001
.equ UART_TXCTRL_NSTOP,              0x00000002
.equ UART_TXCTRL_TXCNT,              0x00070000
.equ UART_RXCTRL_OADDR,              0x0000000C
.equ UART_RXCTRL_RXEN,               0x00000001
.equ UART_RXCTRL_RXCNT,              0x00070000
.equ UART_IE_OADDR,                  0x00000010
.equ UART_IE_TXWM,                   0x00000001
.equ UART_IE_RXWM,                   0x00000002
.equ UART_IP_OADDR,                  0x00000014
.equ UART_IP_TXWM,                   0x00000001
.equ UART_IP_RXWM,                   0x00000002
.equ UART_DIV_OADDR,                 0x00000018
.equ UART_DIV,                       0x0000FFFF

# SPI

# PWM
.equ PWM_PWMCFG_OADDR,    0x00000000
.equ PWM_PWMSCALE,        0x0000000F
.equ PWM_PWMSTICKY,       0x00000100
.equ PWM_PWMZEROCMP,      0x00000200
.equ PWM_PWMDEGLITCH,     0x00000400
.equ PWM_PWMENALWAYS,     0x00001000
.equ PWM_PWMENONESHOT,    0x00002000
.equ PWM_PWMCMP0CENTER,   0x00010000
.equ PWM_PWMCMP1CENTER,   0x00020000
.equ PWM_PWMCMP2CENTER,   0x00040000
.equ PWM_PWMCMP3CENTER,   0x00080000
.equ PWM_PWMCMP0GANG,     0x01000000
.equ PWM_PWMCMP1GANG,     0x02000000
.equ PWM_PWMCMP2GANG,     0x04000000
.equ PWM_PWMCMP3GANG,     0x08000000
.equ PWM_PWMCMP0IP,       0x10000000
.equ PWM_PWMCMP1IP,       0x20000000
.equ PWM_PWMCMP2IP,       0x40000000
.equ PWM_PWMCMP3IP,       0x80000000
.equ PWM_PWMCOUNT_OADDR,  0x00000008
.equ PWM_PWMS_OADDR,      0x00000010
.equ PWM_PWMS,            0x0000FFFF
.equ PWM_PWMCMP0_OADDR,   0x00000020
.equ PWM_PWMCMP0,         0x0000FFFF
.equ PWM_PWMCMP1_OADDR,   0x00000024
.equ PWM_PWMCMP1,         0x0000FFFF
.equ PWM_PWMCMP2_OADDR,   0x00000028
.equ PWM_PWMCMP2,         0x0000FFFF
.equ PWM_PWMCMP3_OADDR,   0x0000002C
.equ PWM_PWMCMP3,         0x0000FFFF

# DEBUG
