#include<iostream>
#include"module_implement.h"

using namespace std;
ModuleImplement::ModuleImplement()
{
    m_pSubModuleA = new SubModuleA;
    m_pSubModuleB = new SubModuleB;
    m_pSubModuleC = new SubModuleC;
}

ModuleImplement::~ModuleImplement()
{
    if(m_pSubModuleA)
        delete m_pSubModuleA;
    if(m_pSubModuleB)
        delete m_pSubModuleB;
    if(m_pSubModuleC)
        delete m_pSubModuleC;
}

void ModuleImplement::init()
{
    std::cout << "+module init!" << std::endl;
    allSubMoudleInit();
}
void ModuleImplement::allSubMoudleInit()
{
    m_pSubModuleA->init();
    m_pSubModuleB->init();
    m_pSubModuleC->init();
}
void ModuleImplement::run()
{
    std::cout << "+module run!" << std::endl;
    allSubMoudleRun();
}
void ModuleImplement::allSubMoudleRun()
{
    m_pSubModuleA->run();
    m_pSubModuleB->run();
    m_pSubModuleC->run();
}
void ModuleImplement::stop()
{
    std::cout << "+module stop!" << std::endl;
    allSubMoudleStop();
}

void ModuleImplement::allSubMoudleStop()
{
    m_pSubModuleA->stop();
    m_pSubModuleB->stop();
    m_pSubModuleC->stop();
}
