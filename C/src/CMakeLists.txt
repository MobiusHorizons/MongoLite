include_directories("${CMAKE_CURRENT_LIST_DIR}")


add_library(mongolite sync.c init.c client.c collection.c)
target_link_libraries(mongolite LINK_PUBLIC ${BSON_LIBRARIES})
