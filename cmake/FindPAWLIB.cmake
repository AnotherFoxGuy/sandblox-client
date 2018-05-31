find_path(PAWLIB_INCLUDE_DIR pawlib 
  PATHS ${PROJECT_SOURCE_DIR}/..
  ${PROJECT_SOURCE_DIR}/../pawlib
  ${PROJECT_SOURCE_DIR}/../pawlib/pawlib-source
  ${PROJECT_SOURCE_DIR}/../lib
)

message(${PAWLIB_INCLUDE_DIR})

find_library(PAWLIB_LIBRARY libpawlib.a 
	PATHS ${PROJECT_SOURCE_DIR}/..
	${PROJECT_SOURCE_DIR}/../pawlib
	${PROJECT_SOURCE_DIR}/../pawlib/lib
	${PROJECT_SOURCE_DIR}/../lib
	${PROJECT_SOURCE_DIR}/.. /pawlib/pawlib-source/lib
)

message(${PAWLIB_LIBRARY})

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(PAWLIB DEFAULT_MSG PAWLIB_LIBRARY PAWLIB_INCLUDE_DIR)

mark_as_advanced(PAWLIB_INCLUDE_DIR PAWLIB_LIBRARY)

