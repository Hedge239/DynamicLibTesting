#ifndef _PLUGININTERFACE_H_
#define _PLUGININTERFACE_H_

#include <string>

class PluginInterface {
    public:
    virtual ~PluginInterface() {}
    virtual const std::string& GetPluginName() const = 0;
    virtual const std::string& GetPluginVersion() const = 0;
    virtual const std::string& GetPluginRepo() const = 0; // Disabled by default for security reasons (In actual project)

    // Functions
    virtual void DoSomething() const = 0;
    virtual void DoSomethingElse() const = 0;
};

// Instance Creation & Destruction
extern "C" PluginInterface* CreatePluginInstance();
extern "C" void DestroyPluginInstance(PluginInterface*);

#endif /*_PLUGININTERFACE_H_*/