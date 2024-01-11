#include <plugins/PluginManager.h>
#include <plugins/PluginLoader.h>

#include <iostream>
#include <filesystem>
#include <fstream>
#include <vector>
#include <string>

#ifdef _WIN32
    const bool IsWindows = true;
#elif __linux__
    const bool IsWindows = false;
#endif


void app::plugins::manager::LoadPluginsFromFile()
{
    // Validate that plugin.ini exist
    std::cout << "[PLUGIN MANAGER] Searching For Plugin.ini" << std::endl;

    if(!std::filesystem::exists("plugins/plugin.ini"))
    {
        std::ofstream c_pluginlist;
        std::filesystem::create_directory("plugins");
        c_pluginlist.open("plugins/plugin.ini");
        c_pluginlist.close();

        std::cout << "[PLUGIN MANAGER] Faild to locate plugin.ini, creating" << std::endl;
        return;
    }

    // Read from plugin.ini
    std::ifstream pluginListFile;
    std::vector<std::string> pluginList;

    pluginListFile.open("plugins/plugin.ini");
    std::cout << "[PLUGIN MANAGER] Reading Plugin.ini" << std::endl;

    if(pluginListFile.is_open())
    {
        std::string line;
        
        while(std::getline(pluginListFile, line))
        {
            if(line.empty())
            {
                break;
            }

            // This is yet another horrible function, makeing this another problem for future me
            if(IsWindows)
            {
                line = "plugins/" + line + ".dll";
            }else
            {
                line = "plugins/" + line + ".so";
            };

            std::cout << "[PLUGIN MANAGER] Found: " + line << std::endl;
            pluginList.push_back(line);
        }
    }else
    {
        std::cout << "[PLUGIN MANAGER] Faild to load plugin.ini, aborting" << std::endl;
        return;
    }

    // Load Plugins
    app::plugins::loader::LoadPlugins(pluginList);
}

void app::plugins::manager::UnloadLoadedPlugins()
{
    app::plugins::loader::UnloadPlugins();
}

void TestCallBackReturn(const std::string& message)
{
    std::cout << "[Plugin Log] " << message << std::endl;
}

// Plugin Functions

void app::plugins::manager::pmDoSomething()
{
    const auto& loadedPlugins = app::plugins::loader::GetLoadedPlugins();

    for (const auto& plugin : loadedPlugins) {
        //std::cout << "Plugin name: " << plugin->GetPluginName() << std::endl;
        //std::cout << "Plugin Version: " << plugin->GetPluginVersion() << std::endl;
        //std::cout << "Plugin Repo: " << plugin->etPluginVersion() << std::endl;
        plugin->DoSomething();
    }
}

void app::plugins::manager::pmDoSomethingElse()
{
    const auto& loadedPlugins = app::plugins::loader::GetLoadedPlugins();

    for (const auto& plugin : loadedPlugins) {
        //std::cout << "Plugin name: " << plugin->GetPluginName() << std::endl;
        //std::cout << "Plugin Version: " << plugin->GetPluginVersion() << std::endl;
        //std::cout << "Plugin Repo: " << plugin->etPluginVersion() << std::endl;
        plugin->DoSomethingElse();
    }
}

void app::plugins::manager::pmSetCallBack()
{
    const auto& loadedPlugins = app::plugins::loader::GetLoadedPlugins();

    for (const auto& plugin : loadedPlugins) {
        plugin->SetTestCallback(TestCallBackReturn);
    }
}


