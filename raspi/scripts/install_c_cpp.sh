#! /bin/bash

sudo apt install cmake clang clang-format cppcheck global build-essential gdb git ninja-build -y
# Wringpi is now obsolete
# Install Wiringpi alternative
cd /tmp
wget https://github.com/WiringPi/WiringPi/releases/download/2.61-1/wiringpi-2.61-1-arm64.deb
sudo dpkg -i wiringpi-2.61-1-arm64.deb