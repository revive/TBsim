project(TBsim)
cmake_minimum_required(VERSION 2.6)
find_package(Qt4 REQUIRED)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

set(TBsim_SRCS TBsim.cpp main.cpp)
qt4_automoc(${TBsim_SRCS})
add_executable(TBsim ${TBsim_SRCS})
add_executable(vectest vectest.cpp vector3.cpp massobj.cpp)
target_link_libraries(vectest m)
target_link_libraries(TBsim ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY})
