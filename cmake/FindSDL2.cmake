find_path(
	SDL2_INCLUDE_DIR SDL.h
	PATHS ${PROJECT_SOURCE_DIR}/../SDL2-2.0.8/include
	)
	
message(${SDL2_INCLUDE_DIR})

find_library(
	SDL2_LIBRARY
	NAMES libSDL2-static.a
	PATHS ${PROJECT_SOURCE_DIR}/../SDL2-2.0.8/build/
	)
	
message(${SDL2_LIBRARY})

include(FindPackageHandleStandardArgs)

find_package_handle_standard_args(SDL2 DEFAULT_MSG SDL2_LIBRARY SDL2_INCLUDE_DIR)

mark_as_advanced(SDL2_INCLUDE_DIR SDL2_LIBRARY)
