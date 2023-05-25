#ifndef DATABASESERVER_H
#define DATABASESERVER_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QString>


class DatabaseServer
{
public:
    DatabaseServer(const QString &server,
                   const QString &driver,
                   const QString &user,
                   const QString &password,
                   const QString &databasename,
                   bool TrueConnection = true);
    bool openDataBase(QString *error = nullptr);
private:
    QSqlDatabase mDatabase;
    QString mServer;
    QString mDriver;
    QString mUser;
    QString mPassword;
    QString mDatabasename;
    bool mTrueConnection;
};

#endif // DATABASESERVER_H
