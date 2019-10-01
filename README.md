# hifive1_fe310_devbrd
Play and learn with the SiFive HiFive1 board featuring a FE310-G000 SoC integrating SiFive's E31 RISC-V core.  
This guide is for the HiFive1 revision A board, not the revision B with onboard Segger J-Link and ESP32 modules.

## Getting Started
First and foremost the Freedom-E-SDK (or just SDK in short) is required. The SDK contains the complete toolchain required to build a program binary for the Freedom-E platform (which includes the HiFive1 dev board).  

You can install the SDK on your system by using the install script  
```
$> ./install_sifive_toolchain.sh
```  
To test that the basics work, the hello example can be build by  
```
$> cd ./freedom-e-sdk
$> make software PROGRAM=hello BOARD=sifive-hifive1
```
The program is uploaded to the HiFive1 by  
```
$> cd freedom-e-sdk
$> make upload PROGRAM=hello BOARD=sifive-hifive1
```

Alternatively you can pull the docker container from dockerhub  
```
$> docker pull andrsmllr/freedom-e-sdk:latest
```
The recommended way to use the docker container is by invoking the run scripts in ./freedom-e-sdk-docker.  
To test that the basics work, the hello example can be build by  
```
$> ./freedom-e-sdk-docker/run_exec.sh software PROGRAM=hello BOARD=sifive-hifive1
```
The program is uploaded to the HiFive1 by  
```
$> ./freedom-e-sdk-docker/run_exec.sh upload PROGRAM=hello BOARD=sifive-hifive1
```

To see the output of the hello example program you need to connect to the HiFive1 over the built-in USB-UART.

## Serial Connection
Connect the micro-USB port of the SiFive HiFive1 dev board to your machine, Linux should detect an FTDI device like this  
```
$> lsusb  
Bus 001 Device 002: ID 0403:6010 Future Technology Devices International, Ltd FT2232C Dual USB-UART/FIFO IC  
```
You should also see a USB serial devices in the /dev folder  
```
$> ls /dev/ttyUSB*  
/dev/ttyUSB1  
```
Use your favorite terminal emulator to connect to the serial device, 115200 Baud, 8 data bits, 1 stop bit, 0 parity bits.  

If building and uploading the hello example was successful you should see the classic "Hello World!" message after uploading the program file as explained in the [Getting Started section](#getting-started) above. Every time you reset the HiFive board (red button) the "Hello World!" message should be printed again.  

## References:  
[HiFive1 Product Page](https://www.sifive.com/boards/hifive1)  
[HiFive1 Schematic](https://sifive.cdn.prismic.io/sifive%2F080cdef9-4631-4c9b-b8f5-7937fbdec8a4_hifive1-a01-schematics.pdf)  
[SiFive FE310-G000 Datasheet](https://sifive.cdn.prismic.io/sifive%2Ffeb6f967-ff96-418f-9af4-a7f3b7fd1dfc_fe310-g000-ds.pdf)  
[SiFive HiFive1 Getting Started Guide](https://sifive.cdn.prismic.io/sifive%2F9c57065b-6d28-465b-b67d-f416894123a9_hifive1-getting-started-v1.0.2.pdf)  
[SiFive FE310-G000 Manual](https://sifive.cdn.prismic.io/sifive%2F500a69f8-af3a-4fd9-927f-10ca77077532_fe310-g000.pdf)  
[SiFive E31 Manual](https://sifive.cdn.prismic.io/sifive%2F2df24239-b9bf-42cd-b287-2d57030e91fa_e31-core-complex-manual-v19.05.pdf)
