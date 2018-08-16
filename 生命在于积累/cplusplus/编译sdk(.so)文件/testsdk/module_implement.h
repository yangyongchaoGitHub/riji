#ifndef MODULE_IMPLEMENT_H
#define MODULE_IMPLEMENT_H

#include"sub_modules.h"

class ModuleImplement
{
public:
    ModuleImplement();
    ~ModuleImplement();
    void init();
    void run();
    void stop();
private:
    SubModuleA* m_pSubModuleA;
    SubModuleB* m_pSubModuleB;
    SubModuleC* m_pSubModuleC;
    void allSubMoudleInit();
    void allSubMoudleRun();
    void allSubMoudleStop();
};

#endif // MODULE_IMPLEMENT_H
