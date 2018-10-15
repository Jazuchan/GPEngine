cmake_minimum_required(VERSION 2.6)


project(GPENGINE)


if(MSVC)
  include_directories(
    contrib/msvc-windows-x86/glew/include
    contrib/msvc-windows-x86/SDL2/include
  )

  link_directories(
    ${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/SDL2/lib
    ${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/glew/lib
  )
endif()

if(MSVC)
  add_definitions(-DSDL_MAIN_HANDLED)
endif()

include_directories(
source
)

add_executable(game
  
source/game/main.cpp
source/game/FragmentShader.txt
source/game/VertexShader.txt
source/game/ShaderProgram.txt
)



add_library(GPEngine
source/game/Object.cpp

source/game/Object.h

source/game/Root.cpp

source/game/Root.h
source/game/Segment.cpp

source/game/Segment.h
source/game/Domain.cpp

source/game/Domain.h
source/game/Keyboard.cpp

source/game/Keyboard.h
source/game/ces.cpp

source/game/ces.h




)

  target_link_libraries(game   
GPEngine
)

if(MSVC)
  target_link_libraries(game
    SDL2 glew32 opengl32
  )
else()
  target_link_libraries(game
    SDL2 GLU GLEW GL
  )
endif()

if(MSVC)
  add_custom_command(TARGET game POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      "${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/SDL2/bin/SDL2.dll"
      "$<TARGET_FILE_DIR:game>"
  )

  add_custom_command(TARGET game POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      "${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/glew/bin/glew32.dll"
      "$<TARGET_FILE_DIR:game>"
  )
endif()