# Use this version because it adds some options that we use.
cmake_minimum_required(VERSION 3.0.2 FATAL_ERROR)

project(sandblox-client)

# This is necessary when we need to debug CMake.
set(CMAKE_VERBOSE_MAKEFILE ON)

# Set the directory for CMake modules dedicated to finding dependencies.
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})

if (CMAKE_BUILD_TYPE STREQUAL "")
  set(CMAKE_BUILD_TYPE "Release")
endif()

# Establish fundamental compiler rules.

option(32BIT "Build 32-bit on either 32-bit or 64-bit systems" OFF)
option(64BIT "Build 64-bit on only 64-bit systems" OFF)

set(WARNINGS "-Wall -Wextra")

if (${CMAKE_CXX_COMPILER_ID} STREQUAL MSVC)
  message(FATAL_ERROR "MSVC is not supported.\n For more information as to why, see https://phab.qub3d.org/V8")
endif()

# Global compiler flags.
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} ${WARNINGS} -std=c++17")
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} ${WARNINGS} -std=c11")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} ${WARNINGS} -O0 -std=c++17")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} ${WARNINGS} -O0 -std=c11")

# Establish settings for Clang and GCC.
if (${CMAKE_CXX_COMPILER_ID} STREQUAL Clang)
  if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS "2.0")
    message(FATAL_ERROR "You need Clang to be newer than 2.0. Halting.")
  endif()
  if (LLVM)
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -stdlib=libc++")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -stdlib=libc++")
  endif()
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL GNU)
  if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS "5")
    message(FATAL_ERROR "You need GCC to be newer than 5.x. Halting.")
  endif()
  set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -s")
  set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -s")
endif()

# Detect a CPU architecture to target in order to make unrecognizable executables a thing.
if (${32BIT} STREQUAL ON)
  set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -m32")
  set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -m32")
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -m32")
  set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -m32")
elseif (${64BIT} STREQUAL ON)
  set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -m64")
  set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -m64")
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -m64")
  set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -m64")
endif()

# Set include, library, and source directories.

set(source_dir ${PROJECT_SOURCE_DIR}/source/src)

set(client_sources
	${source_dir}/gameStateManager.cpp
	${source_dir}/globalVars.cpp
	${source_dir}/main.cpp
	${source_dir}/SandBlox.cpp
	${source_dir}/states/mainGame.cpp
	${source_dir}/states/mainMenu.cpp
	${source_dir}/states/stateMap.cpp
	${source_dir}/gui/gui.cpp)
	
find_package(SDL2)

set(include_dirs
	${PROJECT_SOURCE_DIR}/../cegui-0.8.4/cegui/include
	${PROJECT_SOURCE_DIR}/../cpgf-1.5.6/include
	${PROJECT_SOURCE_DIR}/../glew-2.1.0/include
	${PROJECT_SOURCE_DIR}/../pawlib/pawlib-source/include
	${PROJECT_SOURCE_DIR}/../glm-0.9.9-a2
	${SDL2_INCLUDE_DIR}
	${source_dir}/../include)

message(${include_dirs})

if (UNIX AND NOT APPLE)
	find_package(X11 REQUIRED)
	find_package(Threads REQUIRED)
	set(library_dirs
		${CMAKE_DL_LIBS}
		${CMAKE_THREAD_LIBS_INIT}
		${PROJECT_SOURCE_DIR}/../glew-2.1.0/lib/libglew32.a
		${SDL2_LIBRARY}
		${X11_LIBRARIES}
		${X11_Xcursor_LIB}
		${X11_Xinerama_LIB}
		${X11_Xrandr_LIB}
		${X11_Xxf86vm_LIB}
		${PROJECT_SOURCE_DIR}/../cpgf-1.5.6/lib/libcpgf.a
	)
else()
	set(library_dirs
		${PROJECT_SOURCE_DIR}/../glew-2.1.0/build/lib/libglew32.a
		${PROJECT_SOURCE_DIR}/../lib/libpawlib.a
		${SDL2_LIBRARY}
		${PROJECT_SOURCE_DIR}/../cpgf-1.5.6/lib/libcpgf.a)
endif()# UNIX AND NOT APPLE

#add the CEGUI libraries
set(library_dirs
	${library_dirs}
	${PROJECT_SOURCE_DIR}/../cegui-0.8.4/lib/libCEGUIBase-0.dll.a
	${PROJECT_SOURCE_DIR}/../cegui-0.8.4/lib/libCEGUICommonDialogs-0.dll.a
	${PROJECT_SOURCE_DIR}/../cegui-0.8.4/lib/libCEGUICoreWindowRendererSet.dll.a
	${PROJECT_SOURCE_DIR}/../cegui-0.8.4/lib/libCEGUIExpatParser.dll.a
	${PROJECT_SOURCE_DIR}/../cegui-0.8.4/lib/libCEGUIOpenGLRenderer-0.dll.a
	${PROJECT_SOURCE_DIR}/../cegui-0.8.4/lib/libCEGUISILLYImageCodec.dll.a
	)


#SDL2 needs these libs if on Windows
if(WIN32)
	set(library_dirs 
		${library_dirs}
		imm32.lib
		ole32.lib
		oleaut32.lib
		opengl32.lib
		version.lib
		winmm.lib)
endif()# WIN32

# Link the "SandBlox" binary.

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(POSITION_INDEPENDENT_CODE True)
add_executable(sandblox-client ${client_sources})
include_directories(${include_dirs})
target_link_libraries(sandblox-client ${library_dirs})

# Install it system-wide. (Invoked by `sudo make install`)

if (UNIX)
  install(
    TARGETS sandblox-client
    RUNTIME DESTINATION /usr/bin
  )
endif()
