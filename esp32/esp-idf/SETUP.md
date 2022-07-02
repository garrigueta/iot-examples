# Set-UP ESP-IDF Tools

## Introduction

ESP-IDF requires some prerequisite tools to be installed so you can build firmware for supported chips. The prerequisite tools include Python, Git, cross-compilers, CMake and Ninja build tools.

For this Getting Started we’re going to use the Command Prompt, but after ESP-IDF is installed you can use Eclipse or another graphical IDE with CMake support instead.

### Windows Environment

to be completed...

### Linux Environment

 1 Install the required tools:

 ```console

sudo apt-get install git wget flex bison gperf python3 python3-venv cmake ninja-build ccache libffi-dev libssl-dev dfu-util libusb-1.0-0
 
 ```

 2 Get ESP-IDF Code from the GitHub repository

```console

mkdir -p ~/esp
cd ~/esp
git clone --recursive https://github.com/espressif/esp-idf.git

 ```

 Note: If you don't have CMake >= 3.16 installed you can run the follwing command:

```console

python3 ~/esp/esp-idf/tools/idf_tools.py install cmake
 
```

 3 Install ESP-IDF Toolchain

To set-up ESP-IDF once the clonning process is completed you can isntall all required tools using the followign command:

```console

cd ~/esp/esp-idf
./install.sh esp32
 
```

 4 Set-Up the environment

ESP-IDF provides a script to set-up all required environment varaibles, run the following command:

```console

. $HOME/esp/esp-idf/export.sh
 
```

This command is required to be run every time you want to run ESP-IDF tools, you can add an alias using the following command:

```console

echo "alias get_idf='. $HOME/esp/esp-idf/export.sh'" >> ~/.profile
 
```

After loading again your session you just need to type the command "*get_idf*" to set-up the ESP_IDF environment
