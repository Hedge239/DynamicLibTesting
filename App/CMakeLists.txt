set(PLUGIN_SRC
    "src/PluginManager.cpp"
    "src/PluginLoader.cpp"
)

add_executable(application "src/app.cpp" ${PLUGIN_SRC})
set_target_properties(application PROPERTIES RUNTIME_OUTPUT_DIRECTORY "../../application")

target_include_directories(application PUBLIC "include")