#ifndef _PLUGININTERFACE_H_
#define _PLUGININTERFACE_H_

#include <string>
#include <functional>

class PluginInterface
{
    public:
    virtual ~PluginInterface() {}
    virtual const std::string& GetPluginName() const = 0;
    virtual const std::string& GetPluginVersion() const = 0;
    virtual const std::string& etPluginVersion() const = 0;

    // Functions
    virtual void DoSomething() const {}
    virtual void DoSomethingElse() const {}

    // Call Back
    virtual void SetTestCallback(std::function<void(const std::string&)> TestCallback) {}
};

// Instance Creation & Destruction
extern "C" PluginInterface* CreatePluginInstance();
extern "C" void DestroyPluginInstance(PluginInterface*);

// Define Function Pointers
using CreatePlugin = PluginInterface* (*)();
using DestroyPlugin = void (*)(PluginInterface*);

#endif /*_PLUGININTERFACE_H_*/