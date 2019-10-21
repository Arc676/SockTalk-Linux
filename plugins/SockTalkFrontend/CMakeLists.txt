set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
set(CMAKE_CXX_STANDARD 11)
set(PLUGIN "SockTalkFrontend")

set(
    SRC
    plugin.cpp
    socktalkfrontend.cpp
    client.cpp
)

set(CMAKE_AUTOMOC ON)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/plugins/SockTalkFrontend/lib)
link_directories(${CMAKE_SOURCE_DIR}/plugins/SockTalkFrontend/lib)

add_library(${PLUGIN} MODULE ${SRC})
target_link_libraries(${PLUGIN} ${CMAKE_SOURCE_DIR}/plugins/SockTalkFrontend/lib/libsocktalk.a ${CMAKE_THREAD_LIBS_INIT})
set_target_properties(${PLUGIN} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${PLUGIN})
qt5_use_modules(${PLUGIN} Qml Quick DBus)

execute_process(
    COMMAND dpkg-architecture -qDEB_HOST_MULTIARCH
    OUTPUT_VARIABLE ARCH_TRIPLET
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

set(QT_IMPORTS_DIR "/lib/${ARCH_TRIPLET}")

install(TARGETS ${PLUGIN} DESTINATION ${QT_IMPORTS_DIR}/${PLUGIN}/)
install(FILES qmldir DESTINATION ${QT_IMPORTS_DIR}/${PLUGIN}/)
