# Install script for directory: C:/Users/FUJITSU/Downloads/Compressed/SFML-2.5.1-sources_2/SFML-2.5.1/src/SFML

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "E:/SFML/SFML")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "C:/MinGW/bin/objdump.exe")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("E:/SFML/SFML_Build/src/SFML/System/cmake_install.cmake")
  include("E:/SFML/SFML_Build/src/SFML/Main/cmake_install.cmake")
  include("E:/SFML/SFML_Build/src/SFML/Window/cmake_install.cmake")
  include("E:/SFML/SFML_Build/src/SFML/Network/cmake_install.cmake")
  include("E:/SFML/SFML_Build/src/SFML/Graphics/cmake_install.cmake")
  include("E:/SFML/SFML_Build/src/SFML/Audio/cmake_install.cmake")

endif()

