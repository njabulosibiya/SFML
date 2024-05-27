cmake_minimum_required(VERSION 3.20)

# Set project name
set(BINARY_NAME "SFML")

add_subdirectory(src)

project(${BINARY_NAME}
	VERSION 0.0.1
	LANGUAGES CXX
)

include_directories(include)
