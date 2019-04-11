# vw_use_demo
A demo of how to consume VW as a direct dependency using CMake

For dependencies / environment set up, see https://github.com/VowpalWabbit/vowpal_wabbit/wiki/Dependencies

    git checkout https://github.com/lokitoth/vw_use_demo
    cd vw_use_demo
    git submodule update --init
    mkdir build
    cd build
    cmake ..
    make

Build has been tested on Ubuntu 16.04
