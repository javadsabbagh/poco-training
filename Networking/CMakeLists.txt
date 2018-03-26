cmake_minimum_required(VERSION 3.0)

project(Networking)

# Add C++11 support
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Define source, include and target build directories
set(PROJECT_SOURCE_DIR src)
include_directories(
  "include"
)
set(PROJECT_BINARY_DIR build)

set(SOURCE_FILES src/main.cpp)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# set the POCO paths and libs
set(POCO_PREFIX "/home/javad/Development/Libraries/poco-1.8.1/install") # the directory containing "incl
set(POCO_INCLUDE_DIR "${POCO_PREFIX}/include")
set(POCO_LIB_DIR "${POCO_PREFIX}/lib")
set(POCO_LIBS "${POCO_LIB_DIR}/libPocoNet.a"
              "${POCO_LIB_DIR}/libPocoUtil.a"
              "${POCO_LIB_DIR}/libPocoJSON.a"
              "${POCO_LIB_DIR}/libPocoXML.a"
              "${POCO_LIB_DIR}/libPocoFoundation.a"
              "pthread")

# set the include path for the app
target_include_directories(${PROJECT_NAME}  PRIVATE "${POCO_INCLUDE_DIR}")

# link the app against POCO
target_link_libraries(${PROJECT_NAME}  "${POCO_LIBS}")
