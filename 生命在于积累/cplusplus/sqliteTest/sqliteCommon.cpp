#include <sqliteCommon.h>

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
    int i;
    for(i=0; i<argc; i++){
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

void SqliteCommon::createDb() {
    sqlite3 *db;
    int rc = sqlite3_open("tst.db",&db);
    if(rc) {
        cout << "open db error!!!" << endl;
        exit(0);
    } else {
        cout << "open .db ok" << endl;
    }

    sql = "create table test(" \
          "id int primary key, " \
          "name char(20)" \
          ");";

    rc = sqlite3_exec(db, sql, callback, 0, &errMsg);

    if (rc != SQLITE_OK) {
        cout << "create error " << errMsg << endl;
    } else {
        cout << "create table successful " << endl;
    }
    sqlite3_close(db);
}
