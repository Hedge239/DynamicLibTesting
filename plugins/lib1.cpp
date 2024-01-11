#include "interface/PluginInterface.h"

#include <iostream>

class lib1 : public PluginInterface
{
    public:
        // Plugin Info
        const std::string& GetPluginName() const override
        {
            static const std::string name = "Lib1";
            return name;
        }
        const std::string& GetPluginVersion() const override
        {
            static const std::string version = "0.0.1";
            return version;
        }
        const std::string& GetPluginRepo() const override
        {
            static const std::string repository = "This is a link";
            return repository;
        }

        // Functions
        void DoSomething() const override 
        {
            std::cout << "[Lib1] There's a way" << std::endl;
        }

        void DoSomethingElse() const override
        {
            std::cout << "[Lib1] *Wip noises*" << std::endl;
        }
};

extern "C" PluginInterface* CreatePluginInstance()
{
    return new lib1();
}

extern "C" void DestroyPluginInstance(PluginInterface* plugin)
{
    delete plugin;
}