aux_source_directory(. DIR_X64_SRCS)
include_directories(./ ./Debug)
add_subdirectory(Debug)
add_library(x64 ${DIR_X64_SRCS})