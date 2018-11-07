# SystemC tutorial

To do:
- Keywords and concepts introduced to C++
- Make small examples

## Whats is SystemC

SystemC is a set of classes and libraries that provide event driven simulation for a system modeling language called SystemC. SystemC is based on C++, which gives it speed and flexibility.

Being based on C++, SystemC doesnt require any special EDA tool in order to use it. All you need is a C++ compiler that you can link your installation to.

Knowledge of C++ is required in order to understand this.

## Installation

Dependencies:

- For Debian/Ubuntu and Ubuntu based distros
```
sudo apt install build-essential make wget
```

- For Arch, Manjaro and other Arch based distros
```
sudo pacman -S gcc make wget
```

SystemC can be downloaded, free of charge, from Accellera's website.

Steps:
1. Open terminal and type
```
wget http://www.accellera.org/images/downloads/standards/systemc/systemc-2.3.2.tar.gz
```
This downloads the SystemC tarball

2. Unpacking the package and making directories
```
tar -xzf systemc-2.3.2.tar.gz
sudo mkdir /usr/local/systemc-2.3.2
cd systemc-2.3.2 && mkdir objdir && cd objdir
```

3. Final installation
```
sudo ../configure --prefix=/usr/local/systemc-2.3.2/
sudo make
sudo make install
```


## Compile the program

First clone this repo

```
git clone https://github.com/AleksandarKostovic/SystemC-tutorial.git
```

Then run the command to compile SystemC into exacutable called hello

```
g++ -I. -I /usr/local/systemc-2.3.2/include -L. -L/usr/local/systemc-2.3.2/lib-linux64 -Wl,-rpath=/usr/local/systemc-2.3.2/lib-linux64 -lsystemc -lm -o hello hello.cpp
```

(In examples i will provide makefiles so you dont have to type long commands)


Now, type `./hello` to run the exectutable and you should get this:

```

        SystemC 2.3.2-Accellera --- Oct 30 2018 15:06:05
        Copyright (c) 1996-2017 by all Contributors,
        ALL RIGHTS RESERVED
Hello World!

```

## Keywords introduced and some building concepts

## sc_main
`sc_main` is the master function. When building a system based on SystemC, `sc_main` is going the whole system's main function. You can build multiple functions, but `sc_main` must be present. Like in hello world example:

```c++
#include <systemc.h>

SC_MODULE (hello) {  // module named hello
  SC_CTOR (hello) {  //constructor phase, which is empty in this case
  }

  void say_hello() {
    std::cout << "Hello World!" << std::endl;
  }
};

int sc_main(int argc, char* argv[]) {
  hello h("hello");
  h.say_hello();
  return 0;
}
```
