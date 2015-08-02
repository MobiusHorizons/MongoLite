

# Test connections to databases.
add_executable(connect connect.c)
target_link_libraries( connect LINK_PUBLIC mongolite )
add_test(NAME "Can_Connect_to_DB" WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/tests COMMAND connect)
