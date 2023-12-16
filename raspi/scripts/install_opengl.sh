#! /bin/bash

sudo apt-get install mesa-utils freeglut3-dev libglew2.1 libglew-dev -y

glxinfo | grep "OpenGL version"

apt-get install g++ freeglut3-dev glew1.5-dev libmagick++-dev libassimp-dev libglfw-dev