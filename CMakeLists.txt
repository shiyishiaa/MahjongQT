cmake_minimum_required(VERSION 3.16)
project(MahjongQT)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_PREFIX_PATH D:/Qt/Qt5.14.2/5.14.2/mingw73_64) #这里需要填入自己安装的路径

find_package(Qt5Widgets)
find_package(Qt5Core)
find_package(Qt5Gui)

set(UI_FILES Judge.ui MahjongQT.ui)
set(RC_FILES)
set(QRC_FILES MahjongQT.qrc)
set(SOURCE_FILES main.cpp Judge.h Judge.cpp Mahjong.h Mahjong.cpp Tiles.h Tiles.cpp MahjongQT.cpp MahjongQT.h)

# Add the source in project root directory
aux_source_directory(. DIRSRCS)
# Add header file include directories
include_directories(./ ./x64)
# Add block directories
add_subdirectory(x64)

add_executable(MahjongQT ${RC_FILES} ${SOURCE_FILES} ${UI_FILES} ${QRC_FILES} ${uic})
target_link_libraries(MahjongQT uic)

target_link_libraries(MahjongQT Qt5::Widgets)

qt5_use_modules(MahjongQT Core Widgets Gui)