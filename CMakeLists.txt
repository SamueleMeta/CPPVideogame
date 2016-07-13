cmake_minimum_required(VERSION 3.5)
project(ProjectVideogame)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(test)

set(EXECUTABLE_NAME "MyGame")
set(SOURCE_FILES Armor.h Character.cpp Character.h Hero.cpp Hero.h MeleeWeapon.h Weapon.h Mob.cpp Mob.h NPC.cpp NPC.h Potion.cpp Potion.h RangedWeapon.h Scroll.h TileMap.cpp TileMap.h)
add_executable(${EXECUTABLE_NAME} main.cpp)

add_library(core ${SOURCE_FILES})
target_link_libraries(MyGame core)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()



