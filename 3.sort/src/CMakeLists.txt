add_library(src_lib ${SOURCES})
target_include_directories(src_lib PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_include_directories(app PRIVATE ${PROJECT_SOURCE_DIR}/include)