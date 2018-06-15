#ifndef SQLITECOMMON
#define SQLITECOMMON
#include <iostream>
#include <stdio.h>
using namespace std;
#include "sqlite3.h"

class SqliteCommon {
public :
    char * sql;
    char * errMsg;
    void createDb();
};
#endif // SQLITECOMMON

