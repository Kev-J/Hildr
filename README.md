Hildr
=====

Dependencies
------------

- sfml (=2.1)
- sfgui (=0.2.0)
- opengl

Install (for debian like)
------------

- Install SFML
$ apt-get libsfml-dev

- Install OpenGL
$ apt-get install freeglut3

- Install SFGUI
Download the package from SFGUI website
unzip the package

$ cd SFGUI-0.2.0

$ mkdir build

$ cd build

$ cmake ..

If at this point, SFML is not found, please try:

$ cmake .. -DCMAKE_MODULE_PATH:PATH=/usr/share/SFML/cmake/Modules

# make install

