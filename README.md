# OFCTBot

## How to compile and run
Make sure you have [git](https://git-scm.com), [CMake](https://cmake.org), OpenSSL([windows](https://slproweb.com/products/Win32OpenSSL.html), [linux](https://www.openssl.org/source/)) and some c++ compiler installed in your computer. The instruction below is known to work with:
* Microsoft Visual C++ 14.24
* g++ 7.4.0

1. Open the terminal or command prompt and enter `git clone https://github.com/A-BCDe/OFCTBot.git`
2. `cd OFCTBot`
3. `git clone https://github.com/taocpp/PEGTL.git`
4. `git clone https://github.com/yourWaifu/sleepy-discord.git`
5. `mkdir build`
6. `cd build`
7. `cmake ..`
8. If you are using Visual Studio, `start OFCTBot_ver2.sln`, then set project `OFCTBot_ver2` as a startup project, and compile and run.
  If you are using g++ with make, `make`, then `./OFCTBot_ver2`.
