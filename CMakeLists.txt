cmake_minimum_required(VERSION 3.16.0)

project(voxTools)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")
include_directories(${PROJECT_SOURCE_DIR}/include/)
file(GLOB SRCS 
		"${PROJECT_SOURCE_DIR}/src/*.cpp"
		"${PROJECT_SOURCE_DIR}/include/vox2D/gl/*.cpp"
		"${PROJECT_SOURCE_DIR}/include/vox2D/glfw/*.cpp"
	)

add_link_options(-lglfw)
add_link_options(-lSDL2_image)
add_link_options(-lGL)
add_executable(app ${SRCS})
