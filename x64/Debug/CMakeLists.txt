aux_source_directory(. DIR_DEBUG_SRCS)
include_directories(./ ./uic)
add_subdirectory(uic)
add_library(Debug ${DIR_DEBUG_SRCS})