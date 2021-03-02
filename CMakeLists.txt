cmake_minimum_required(VERSION 3.19)

project(GetSteamIDtest VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(Steamworks_API_Directory "A:\\Coding\\Libraries\\steamworks sdk\\151\\sdk" CACHE PATH "Filepath to the steamworks api directory. Should point to the \"sdk\" folder.")

# TODO: Other os
add_executable(GSIt "src/main.cpp")
target_include_directories(GSIt PUBLIC "${Steamworks_API_Directory}\\public")
target_link_libraries(GSIt "${Steamworks_API_Directory}\\redistributable_bin\\win64\\steam_api64.lib")

# Removes the /Debug on MSVC
set_target_properties(GSIt PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_BINARY_DIR})
configure_file("src/steam_appid.txt" "${CMAKE_CURRENT_BINARY_DIR}/steam_appid.txt" COPYONLY)
configure_file("${Steamworks_API_Directory}\\redistributable_bin\\win64\\steam_api64.dll" "${CMAKE_CURRENT_BINARY_DIR}/steam_api64.dll" COPYONLY)