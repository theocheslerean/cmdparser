## CommandLineParser

### A C++ lightweight header only library for main arguments parsing

#### Installation

```
mkdir build
cd build
cmake ..
make
(sudo) make install
```
It should install in /usr/local/

For another installation location use:
```
cmake .. -DCMAKE_INSTALL_PREFIX:PATH=/path/where/to/install
```
#### Usage
In CMakeLists.txt add:
```
include_directories(
    ${COMMANDLINEPARSER_INCLUDE_DIR}
)
target_include_directories(... PUBLIC CommandLineParser)
```
For cmake
```
-DCOMMANDLINEPARSER_INCLUDE_DIR=/path/to/install/folder
```
For C++ Code
```
#include <cmdparser.h>
```

CMake file written following instructions from: http://dominikberner.ch/cmake-interface-lib/

Some code snippets taken from: https://github.com/jarro2783/cxxopts
