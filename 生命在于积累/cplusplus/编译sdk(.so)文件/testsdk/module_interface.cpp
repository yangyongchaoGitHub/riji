#include <iostream>
#include "module_interface.h"
#include "module_implement.h"

using namespace std;

ModuleInterface::ModuleInterface()
{
    m_pImpl = new ModuleImplement;
}
ModuleInterface::~ModuleInterface()
{
    if(m_pImpl)
        delete m_pImpl;
}

void ModuleInterface::init()
{
    m_pImpl->init();
}

void ModuleInterface::run()
{
    m_pImpl->run();
}

void ModuleInterface::stop()
{
    m_pImpl->stop();
}
