find_program(MAKE_COMMAND NAMES gmake nmake make)
find_program(GIT_COMMAND NAMES git)

set(DEPS_DIR ${CMAKE_BINARY_DIR}/_deps)

if (NOT EXISTS ${DEPS_DIR}/libdeps)
    message(STATUS "Building pawlib deps")
    execute_process(COMMAND ${GIT_COMMAND} clone https://github.com/mousepawmedia/libdeps.git libdeps
            WORKING_DIRECTORY ${DEPS_DIR})
    execute_process(COMMAND ${GIT_COMMAND} checkout tags/v1.0.0
            WORKING_DIRECTORY ${DEPS_DIR}/libdeps)
    execute_process(COMMAND ${MAKE_COMMAND} cpgf
            WORKING_DIRECTORY ${DEPS_DIR}/libdeps)
    message(STATUS "Done building pawlib deps")
endif ()

if (NOT EXISTS ${DEPS_DIR}/pawlib)
    message(STATUS "Building pawlib")
    execute_process(COMMAND ${GIT_COMMAND} clone https://github.com/mousepawmedia/pawlib.git pawlib
            WORKING_DIRECTORY ${DEPS_DIR})
    execute_process(COMMAND ${GIT_COMMAND} checkout tags/v1.0.0
            WORKING_DIRECTORY ${DEPS_DIR}/pawlib)
    execute_process(COMMAND ${MAKE_COMMAND} ready
            WORKING_DIRECTORY ${DEPS_DIR}/pawlib)
    message(STATUS "Done building pawlib")
endif ()


find_path(CPGF_INCLUDE_DIR cpgf
        PATHS ${DEPS_DIR}/libdeps/cpgf/include
        )
message("Set cpgf include path to: ${CPGF_INCLUDE_DIR}")

find_library(CPGF_LIBRARY libcpgf.a
        PATHS ${DEPS_DIR}/libdeps/cpgf/lib
        )

message("Set cpgf lib path to: ${CPGF_LIBRARY}")


find_path(PAWLIB_INCLUDE_DIR pawlib
        PATHS ${DEPS_DIR}/pawlib/pawlib/include
        )
message("Set pawlib include path to: ${PAWLIB_INCLUDE_DIR}")

find_library(PAWLIB_LIBRARY libpawlib.a
        PATHS ${DEPS_DIR}/pawlib/pawlib/lib
        )
message("Set pawlib lib path to: ${PAWLIB_LIBRARY}")


