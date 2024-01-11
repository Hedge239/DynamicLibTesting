
add_library(1 SHARED "lib1.cpp")
set_target_properties(1 PROPERTIES RUNTIME_OUTPUT_DIRECTORY "../../application/plugins/lib1")
target_include_directories(1 PUBLIC "include")

add_library(2 SHARED "lib2.cpp")
set_target_properties(2 PROPERTIES RUNTIME_OUTPUT_DIRECTORY "../../application/plugins/lib2")
target_include_directories(2 PUBLIC "include")
