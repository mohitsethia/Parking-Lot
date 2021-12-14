cmake_minimum_required (VERSION 3.16)
project (ParkingLot)

set(CMAKE_CXX_STANDARD 17)

set(ParkingLotSource
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ParkingLot.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ParkingSpot.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Vehicle.cpp
)

add_library(parking_lib ${ParkingLotSource})

add_executable (ParkingLot src/main.cpp)

target_link_libraries(ParkingLot parking_lib)