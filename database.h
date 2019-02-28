#ifndef DATABASE_H
#define DATABASE_H

/*****************************************************************************
                                INCLUDES
******************************************************************************/
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QDebug>
//#include <sqlite3.h>

/**
 * \class CDatabase "database.h"
 * \brief The DataBase class is used to commnunicate the SQLITE Database file.
 *
 * This class is used to execute queries and give the results.
 *
 */
class CDatabase
{

public:
    /**
     * \fn bool createDefaultTables()
     * \brief It creates the tables which is not exist in the database.
     * \return It gives the result true,If all tables are created successfully
     * otherwise return false .
     */
    bool createDefaultTables();
    /**
     * A constructor.
     * \brief Constructs a CDatabase class.add the database driver.
     */
    CDatabase();
    /**
     * A destructor.
     * \brief Destroys the CDatabase class and remove the database driver.
     */
    ~CDatabase();
    /**
     * \fn bool openConnections()
     * \brief open the database connectivity.
     * \return Whether the connection is opened successfully or not.
     */
//    bool openConnections();  //for license

    bool openConnections(QString DB_name);
    /**
     * \fn bool executeCommand(const QString &query)
     * \brief Execute the query command such as CREATE,DELETE,UPDATE,..etc.,
     * \param[in] query string must use syntax appropriate for the SQL database
     * being queried (for example, standard SQL).
     * \return Whether the query is executed successfully or not.
     */
    bool executeCommand(const QString &query);
    /**
     * \fn bool selectQuery(const QString &query)
     * \brief it execute and give the result for the given query.
     * \param[in] query string must use syntax appropriate for the SQL database
     * being queried (for example, standard SQL).
     * \param[out] resQuery if the query was executed successful,it returns the
     * queryresult value for read the data.
     * \return Whether the query is executed successfully or not.
     */
    bool selectQuery(const QString &query, QSqlQuery &resQuery);
    /**
     * \fn int size(QSqlQuery query)
     * \brief It gives the number of records in the givent query result.
     * \param[in] query it gives the executed query result).
     * \return It retutns  the number of records.
     */
    int size(QSqlQuery query);
    /**
     * \fn executeQuery(QSqlQuery &sqlQuery)
     * \brief It execute the query and give the result.
     * \param[in/out] sqlQuery it execute the query).
     * \return Whether the query is executed successfully or not.
     */
    bool executeQuery(QSqlQuery &sqlQuery);
    /**
     * \fn bool closeConnection()
     * \brief close the database connectivity.
     */
    void closeConnection();

    /**
     * \var QSqlDatabase con
     * \brief Database connectivity object.
     */
    QSqlDatabase con;
};

#endif // DATABASE_H
