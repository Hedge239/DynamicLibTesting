#include <PluginManager.h>

#include <iostream>
#include <filesystem>
#include <fstream>
#include <vector>
#include <string>

#ifdef _WIN32
    #include "windows.h"
    const bool IsWindows = true;
#elif __linux__
else
    // Continue adding for other display services
#endif


void app::Pluginmanager::LoadPlugins()
{
    // Validate that plugin.ini exist
    std::cout << "[PLUGIN MANAGER] Searching For Plugin.ini" << std::endl;

    if(!std::filesystem::exists("plugins\\plugin.ini"))
    {
        std::ofstream c_pluginlist;
        std::filesystem::create_directory("plugins");
        c_pluginlist.open("plugins\\plugin.ini");
        c_pluginlist.close();

        std::cout << "[PLUGIN MANAGER] Faild to locate plugin.ini, creating" << std::endl;
        return;
    }

    // Read from plugin.ini
    std::ifstream pluginListFile;
    std::vector<std::string> pluginList;

    pluginListFile.open("plugins\\plugin.ini");
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
                line = line + ".dll";
            }else
            {
                line = line + ".so";
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
}