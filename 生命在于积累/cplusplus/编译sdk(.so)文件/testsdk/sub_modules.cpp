#include<iostream>
#include"sub_modules.h"

using namespace std;

SubModuleA::SubModuleA()
{
    ;
}
SubModuleB::SubModuleB()
{
    ;
}
SubModuleC::SubModuleC()
{
    ;
}

SubModuleA::~SubModuleA()
{
    ;
}

SubModuleB::~SubModuleB()
{
    ;
}
SubModuleC::~SubModuleC()
{
    ;
}
void SubModuleA::init()
{
    std::cout<< "	-sub module A init!"<< std::endl;
}
void SubModuleB::init()
{
    std::cout<< "	-sub module B init!"<< std::endl;
}
void SubModuleC::init()
{
    std::cout<< "	-sub module C init!"<< std::endl;
}

void SubModuleA::run()
{
    std::cout<< "	-sub module A run!"<< std::endl;
}
void SubModuleB::run()
{
    std::cout<< "	-sub module B run!"<< std::endl;
}
void SubModuleC::run()
{
    std::cout<< "	-sub module C run!"<< std::endl;
}
void SubModuleA::stop()
{
    std::cout<< "	-sub module A stop!"<< std::endl;
}
void SubModuleB::stop()
{
    std::cout<< "	-sub module B stop!"<< std::endl;
}
void SubModuleC::stop()
{
    std::cout<< "	-sub module C stop!"<< std::endl;
}
