#ifndef SUB_MODULES_H
#define SUB_MODULES_H

class SubModuleA
{
public:
    SubModuleA();
    virtual ~SubModuleA();
    void init();
    void run();
    void stop();
};

class SubModuleB
{
public:
    SubModuleB();
    virtual ~SubModuleB();
    void init();
    void run();
    void stop();
};

class SubModuleC
{
public:
    SubModuleC();
    virtual ~SubModuleC();
    void init();
    void run();
    void stop();
};


#endif // SUB_MODULES_H
