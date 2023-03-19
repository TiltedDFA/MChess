cmake_minimum_required(VERSION 3.21)
project(MChess LANGUAGES CXX)
set(BUILD_SHARED_LIBS OFF)
include_directories(src/headers)
include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)
file(GLOB MY_SOURCES "src/*.cpp")
add_executable(MChess ${MY_SOURCES})
set_target_properties(MChess PROPERTIES
    COMPILE_OPTIONS "-save-temps"
)
target_link_libraries(MChess PRIVATE sfml-graphics)
target_compile_features(MChess PRIVATE cxx_std_20)
if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET MChess POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:MChess> $<TARGET_FILE_DIR:MChess> COMMAND_EXPAND_LISTS)
endif()

install(TARGETS MChess)