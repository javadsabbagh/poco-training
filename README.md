# poco-training

A set of poco samples. Each sample is in the corresponding category, e.g Networking, Process, etc.

## Projects Layout
Regarding each category we have a separate project, i.e subproject, which is based on CMake. There should be src directory for every project that contains all source files, and another include directory that houses project header files.

## Compile and use POCO in CMake

Please refere to the following stackoverflow question:
https://stackoverflow.com/questions/30114662/clion-cmake-and-poco


```sh
You can get the latest CMake release from: http://www.cmake.org/download/

For Linux, it's this archive: http://www.cmake.org/files/v3.2/cmake-3.2.2.tar.gz

An easy way to use it is to put the extracted files in /opt/cmake/cmake-3.2 then create the following aliases (e.g. in ~/.bash_aliases:

alias ccmake3='/opt/cmake/cmake-3.2/bin/ccmake'
alias cmake3='/opt/cmake/cmake-3.2/bin/cmake'
alias cmake3-gui='/opt/cmake/cmake-3.2/bin/cmake-gui'
alias cpack3='/opt/cmake/cmake-3.2/bin/cpack'
alias ctest3='/opt/cmake/cmake-3.2/bin/ctest'
Then, make sure that you have properly built and installed POCO. The Getting Started page has all the information you need for doing that. But, basically, you should get the sources from here and extract them somehwere:

wget http://pocoproject.org/releases/poco-1.6.0/poco-1.6.0.tar.gz
tar xvfz poco-1.6.0.tar.gz
cd poco-1.6.0
mkdir -p cmake_build cmake_install/debug cmake_install/release
cd cmake_build
cmake3-gui ..
In the CMake 3 GUI, press Configure. In the new window, keep the default option Unix Makefiles and click on Finish. An error message should appear (which is fine), click Ok.

To build the Debug version, set the following:

CMAKE_BUILD_TYPE     : Debug
CMAKE_INSTALL_PREFIX : the absolute path to "cmake_install/debug"
To get you started quickly with POCO, unckeck all the options, except for the following, they have to be enabled:

ENABLE_JSON
ENABLE_NET
ENABLE_UTIL
ENABLE_XML
POCO_STATIC
(You can consider the other options later if you need to...)

Quit the GUI, then build/install POCO:

make clean
make -j8
make install
Now, POCO should be installed in cmake_install/debug. To build/install the other versions, just do the same procedure, but replace Debug in CMAKE_BUILD_TYPE with Release, RelWithDebInfo or MinSizeRel (cf. CMake's doc) (also, you'll have to change the install directories)

Finally, you can use POCO in you C++ projects.

For instance, your CMakeLists.txt should look like this:

cmake_minimum_required(VERSION 3.0)

project(Email_Reader)

# define the project
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Email_Reader ${SOURCE_FILES}) 

# set the POCO paths and libs
set(POCO_PREFIX      "/path/to/cmake_install/debug") # the directory containing "include" and "lib"
set(POCO_INCLUDE_DIR "${POCO_PREFIX}/include")
set(POCO_LIB_DIR     "${POCO_PREFIX}/lib")
set(POCO_LIBS        "${POCO_LIB_DIR}/libPocoNetd.a"
                     "${POCO_LIB_DIR}/libPocoUtild.a"
                     "${POCO_LIB_DIR}/libPocoJSONd.a"
                     "${POCO_LIB_DIR}/libPocoXMLd.a"
                     "${POCO_LIB_DIR}/libPocoFoundationd.a"
                     "pthread")

# set the include path for the app
target_include_directories(Email_Reader PRIVATE "${POCO_INCLUDE_DIR}")
# link the app against POCO
target_link_libraries(Email_Reader "${POCO_LIBS}")

``
