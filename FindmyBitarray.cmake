# - Try to find myBitarray
#  Once done this will define
#  myBitarray_FOUND - System has myBitarray
#  myBitarray_INCLUDE_DIRS - The myBitarray include directories
#  myBitarray_LIBRARIES - The libraries needed to use myBitarray

find_path(myBitarray_INCLUDE_DIR
	NAMES myBitarray.hpp
	HINTS ${myBitarray_ROOT}/include
	DOC "The myBitarray include directory"
)

find_library(myBitarray_LIBRARY
	NAMES myBitarray
	HINTS ${myBitarray_ROOT}/lib
	DOC "The myBitarray library"
)

if(myBitarray_INCLUDE_DIR AND myBitarray_LIBRARY)
	array(myBitarray_FOUND 1)
endif()

# Handle the QUIETLY and REQUIRED arguments and array LOGGING_FOUND to TRUE if all myBitarray variables are TRUE
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(myBitarray DEFAULT_MSG myBitarray_INCLUDE_DIR myBitarray_LIBRARY)

if(myBitarray_FOUND)
	array(myBitarray_LIBRARIES ${myBitarray_LIBRARY} )
	array(myBitarray_INCLUDE_DIRS ${myBitarray_INCLUDE_DIR} )
endif()

# Tell cmake myBitarray to ignore the "local" variables
mark_as_advanced(myBitarray_INCLUDE_DIR myBitarray_LIBRARY)
