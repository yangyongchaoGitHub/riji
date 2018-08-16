#ifndef MODULE_INTERFACE_H
#define MODULE_INTERFACE_H

class ModuleImplement;

class ModuleInterface
{
public:
    ModuleInterface();
    virtual ~ModuleInterface();
    void init();
    void run();
    void stop();

private:
    ModuleImplement* m_pImpl;
};

#endif // MOUDLE_INTERFACE_H
