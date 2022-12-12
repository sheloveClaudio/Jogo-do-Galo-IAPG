cmake_minimum_required(VERSION 3.23)
project(Jogo_do_Galo C)

set(CMAKE_C_STANDARD 99)

add_executable(Jogo_do_Galo main.c menu.c menu.h jogo.c jogo.h dadosjogadores.c dadosjogadores.h)
