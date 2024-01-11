#include "interface/PluginInterface.h"

#include <iostream>

class lib2 : public PluginInterface
{
    public:
        // Plugin Info
        const std::string& GetPluginName() const override
        {
            static const std::string name = "Lib2";
            return name;
        }
        const std::string& GetPluginVersion() const override
        {
            static const std::string version = "0.2.1";
            return version;
        }
        const std::string& GetPluginRepo() const override
        {
            static const std::string repository = "This is a link again";
            return repository;
        }

        // Functions
        void DoSomething() const override 
        {
            std::cout << "[Lib2] Theres a way" << std::endl;
        }

        void DoSomethingElse() const override
        {
            std::cout << "[Lib2] *more wip noises*" << std::endl;
        }
};

extern "C" PluginInterface* CreatePluginInstance()
{
    return new lib2();
}

extern "C" void DestroyPluginInstance(PluginInterface* plugin)
{
    delete plugin;
}