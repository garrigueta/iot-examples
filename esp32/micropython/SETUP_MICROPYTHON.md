# Set-UP Micropython Tools

## Introduction

Using MicroPython is a great way to get the most of your ESP32 board. And vice versa, the ESP32 chip is a great platform for using MicroPython. This tutorial will guide you through setting up MicroPython, getting a prompt, using WebREPL, connecting to the network and communicating with the Internet, using the hardware peripherals, and controlling some external components.

### Windows Environment

As minimum requirement you need to have installed python, for Windows you just need the installer.

[Download the latest version for Windows](https://www.python.org/downloads/)

You need Git installed locally to checkout the source code of this tool, you can clone the repo or just download it locally.

1 Download the required Micropython tools:

```console
git clone https://github.com/micropython/micropython.git
```

You can download the last release too from GitHub without using git CLI:

[GitHub | Micropython Releases](https://github.com/micropython/micropython/releases)

2 Install the Python package

To be using the python CLI tools for the ESP32 board you need to install the right package, use the follwing command:

```console
pip install esptool
```

2 Prepare the device

To have all ready and to check every thing we can erase the board content using the follwoing command:

```console
esptool.py --port COM11 erase_flash
```

If you are not sure which port you have assigned to your board, you can check quickly running the follwing command:

```console
PS C:\> mode

Estado para dispositivo COM20:
------------------------------
    Baudios:             115200
    Paridad:             None
    Bits de datos:       8
    Bits de paro:        1
    Tiempo de espera:    OFF
    XON / XOFF:          OFF
    Protocolo CTS:       OFF
    Protocolo DSR:       OFF
    Sensibilidad de DSR: OFF
    Circuito DTR:        OFF
    Circuito RTS:        OFF

Estado para dispositivo CON:
----------------------------
    Líneas:              30
    Columnas:            120
    Ritmo del teclado:   31
    Retardo del teclado: 1
    Página de códigos:    850
```

Then, running the "esptool.py" command you should see somehting like the following output:

```console
PS C:\> esptool.py --port COM20 erase_flash
esptool.py v4.1
Serial port COM20
Connecting....
Detecting chip type... Unsupported detection protocol, switching and trying again...
Connecting.....
Detecting chip type... ESP32
Chip is ESP32-D0WD (revision 1)
Features: WiFi, BT, Dual Core, 240MHz, VRef calibration in efuse, Coding Scheme None
Crystal is 40MHz
MAC: e8:31:cd:14:41:3c
Uploading stub...
Running stub...
Stub running...
Erasing flash (this may take a while)...
Chip erase completed successfully in 16.4s
Hard resetting via RTS pin...
```

## Tutorials

[docs.micropython.org | MicroPython tutorial for ESP8266](https://docs.micropython.org/)
