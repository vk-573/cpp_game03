project(game)
cmake_minimum_required(VERSION 3.0)
add_definitions("-fPIC")

# include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
# conan_basic_setup()

set(SRC
	src/main.cpp
	src/Display.cpp
	src/Manager.cpp
	src/Game.cpp
	src/MainMenu.cpp
	src/GameConfigScene.cpp
	src/MenuConfig.cpp
	src/Scene.cpp
	src/PluginManager.cpp
)

set(HEADER
	include/Display.hpp
	include/IDisplay.hpp
	include/IPlayer.hpp
	include/IWeapon.hpp
	include/IMap.hpp
	include/IMenuScene.hpp
	include/Game.hpp
	include/PluginManager.hpp
	include/Manager.hpp
	include/MainMenu.hpp
	include/GameConfigScene.hpp
	include/MenuConfig.hpp
	include/Scene.hpp
)

add_executable(game ${SRC} ${HEADER})
target_include_directories(game PUBLIC ${CMAKE_SOURCE_DIR}/include/)
target_link_libraries(game ${SFML_LIBRARIES} ${SFML_DEPENDENCIES} sfml-graphics sfml-audio sfml-window sfml-system pthread dl)