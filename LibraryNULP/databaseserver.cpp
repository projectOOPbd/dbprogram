#include "databaseserver.h"

DatabaseServer::DatabaseServer(const QString &server,const QString &driver,const QString &user,const QString &password,const QString &databasename,bool TrueConnection)
{
    mDatabase = QSqlDatabase::addDatabase("QODBC");
    mServer = server;
    mDriver = driver;
    mUser = user;
    mPassword = password;
    mDatabasename = databasename;
    mTrueConnection = TrueConnection;
}

bool DatabaseServer::openDataBase(QString *error)
{
    mDatabase.setDatabaseName(QString("DRIVER={%1};SERVER=%2;DATABASE=%3;UID=%4;PWD=%5;Trusted_Connection=%6")
                              .arg(mDriver)
                              .arg(mServer)
                              .arg(mDatabasename)
                              .arg(mUser)
                              .arg(mPassword)
                              .arg(mTrueConnection ? "Yes":"No"));
    if(!mDatabase.open())
    {
        if(error != nullptr)
        {
            *error = mDatabase.lastError().text();
        }
        return false;
    }
    return true;
}


