# add_library(bigodemo BigODemo.cpp)
add_library(bigodemo ${SOURCES})
target_include_directories(bigodemo PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_include_directories(app PRIVATE ${PROJECT_SOURCE_DIR}/include)