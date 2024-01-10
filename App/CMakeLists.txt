
add_executable(application "src/app.cpp" "src/PluginManager.cpp" "src/global.cpp")
set_target_properties(application PROPERTIES RUNTIME_OUTPUT_DIRECTORY "../../application")
target_include_directories(application PUBLIC "include")