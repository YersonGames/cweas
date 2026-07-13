cmake_minimum_required(VERSION 3.23)

project(test
        LANGUAGES C)

add_executable(main)

target_sources(main
  PRIVATE
    main.c
)