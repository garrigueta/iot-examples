from machine import UART

uart = UART(1, baudrate=9600, tx=33, rx=32)
uart.write('hello')
uart.read(5)