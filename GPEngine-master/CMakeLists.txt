cmake_minimum_required(VERSION 2.6)


project(HARUENGINE)

include_directories(
source
contrib
)

if(MSVC)
  include_directories(
    contrib/msvc-2017-windows-x86/glew/include
    contrib/msvc-2017-windows-x86/SDL2/include
    contrib/msvc-2017-windows-x86/openal-soft/include
    contrib/msvc-2017-windows-x86/ogg/include
    contrib/msvc-2017-windows-x86/vorbis/include
  )

  link_directories(
    ${CMAKE_SOURCE_DIR}/contrib/msvc-2017-windows-x86/SDL2/lib
    ${CMAKE_SOURCE_DIR}/contrib/msvc-2017-windows-x86/glew/lib
    ${CMAKE_SOURCE_DIR}/contrib/msvc-2017-windows-x86/openal-soft/lib
    ${CMAKE_SOURCE_DIR}/contrib/msvc-2017-windows-x86/ogg/lib
    ${CMAKE_SOURCE_DIR}/contrib/msvc-2017-windows-x86/vorbis/lib
  )
else()
  include_directories(
    /usr/X11R6/include
    /usr/local/include
  )

  link_directories(
    /usr/X11R6/lib
    /usr/local/lib
  )
endif()

if(MSVC)
  add_definitions(-DSDL_MAIN_HANDLED)
endif()

add_executable(game
  
source/game/main.cpp
)



add_library(haruengine
source/haruengine/Object.cpp

source/haruengine/Object.h

source/haruengine/Root.cpp

source/haruengine/Root.h
source/haruengine/Segment.cpp

source/haruengine/Segment.h
source/haruengine/Domain.cpp

source/haruengine/Domain.h
source/haruengine/Keyboard.cpp

source/haruengine/Keyboard.h
source/haruengine/MeshRenderer.cpp
source/haruengine/MeshRenderer.h
source/haruengine/ShaderProgram.cpp
source/haruengine/ShaderProgram.h
source/haruengine/VertexBuffer.cpp
source/haruengine/VertexBuffer.h
source/haruengine/VertexArray.cpp
source/haruengine/VertexArray.h

)

  target_link_libraries(game haruengine)


if(MSVC)
  target_link_libraries(haruengine
    SDL2 glew32 opengl32 OpenAL32 ogg vorbis vorbisfile
  )
else()
  target_link_libraries(haruengine
    SDL2 GLU GLEW GL AL ogg vorbis vorbisfile
  )
endif()

if(MSVC)
  add_custom_command(TARGET game POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      "${CMAKE_SOURCE_DIR}/contrib/msvc-2017-windows-x86/SDL2/bin/SDL2.dll"
      "$<TARGET_FILE_DIR:game>"
  )

  add_custom_command(TARGET game POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      "${CMAKE_SOURCE_DIR}/contrib/msvc-2017-windows-x86/glew/bin/glew32.dll"
      "$<TARGET_FILE_DIR:game>"
  )

  add_custom_command(TARGET game POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      "${CMAKE_SOURCE_DIR}/contrib/msvc-2017-windows-x86/openal-soft/bin/OpenAL32.dll"
      "$<TARGET_FILE_DIR:game>"
  )
endif()