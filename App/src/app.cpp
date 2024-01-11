#include <plugins/PluginManager.h>

#include <iostream>

int main()
{
    app::plugins::manager::LoadPluginsFromFile();

    std::cout << "[App] Where there a wip," << std::endl;

    app::plugins::manager::pmSetCallBack();
    app::plugins::manager::pmDoSomething();
    app::plugins::manager::pmDoSomethingElse();

    std::string userInput;
    std::getline(std::cin, userInput);
    
    app::plugins::manager::UnloadLoadedPlugins();
}