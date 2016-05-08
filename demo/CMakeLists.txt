project( CuteDogHouseDemos )

add_executable( cwdWatch cwdWatch.cpp )
target_link_libraries( cwdWatch ${QT_LIBRARIES} CuteWatchDog )

add_executable( cwdHouse cwdHouse.cpp )
target_link_libraries( cwdHouse ${QT_LIBRARIES} CuteWatchDog )
