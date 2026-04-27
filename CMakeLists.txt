cmake_minimum_required(VERSION 3.28)

project(fluidsim)

add_executable(fluidsim)
target_sources(fluidsim
	PRIVATE
	src/main.cpp
)
