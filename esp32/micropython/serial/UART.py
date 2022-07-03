from mpython import *                            # import all mPython object

uart=UART(20,baudrate=9600,tx=Pin.P15,rx=Pin.P16) # construct UART object，set Baud Rate at 9600，the TX、RX pins are P15、P16 respectively.