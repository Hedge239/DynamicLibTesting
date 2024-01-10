#include "PluginManager.h"

#include <iostream>


int main()
{
    std::cout << "[APP] Loading Plugins for testing" << std::endl;
    app::Pluginmanager::LoadPlugins();
}