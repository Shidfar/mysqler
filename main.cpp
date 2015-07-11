#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>
#include <time.h>
using namespace std;
int main()
{
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;

    char *server = "localhost";
    char *user = "root";
    char *password = "1234";
    char *database = "gateway";

    conn = mysql_init(NULL);

//    cout<<"REALLY DONE"<<endl;
    if(!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
    {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }
    char * comm = "show tables";
    if (mysql_query(conn, comm)) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }
    res = mysql_use_result(conn);
    /* output table name */
    printf("MySQL Tables in mysql database:\n");
    while ((row = mysql_fetch_row(res)) != NULL)
        printf("%s \n", row[0]);
    /* close connection */
    mysql_free_result(res);
    mysql_close(conn);

    return 0;
}

//#include <stdlib.h>
//#include <iostream>
//
//#include <mysql_connection.h>
//
//#include <cppconn/driver.h>
//#include <cppconn/exception.h>
//#include <cppconn/resultset.h>
//#include <cppconn/statement.h>
//
//using namespace std;
//
//int main(void)
//{
////    cout << endl;
////    cout << "Running 'SELECT 'Hello World!' AS _message ..." << endl;
//
//    try {
//        sql::Driver *driver;
//        sql::Connection *con;
//        sql::Statement *stmt;
//        sql::ResultSet *res;
//
//        /* Create a connection */
//        driver = get_driver_instance();
//        con = driver->connect("localhost", "root", "1234");
//
//
//        /* Connect to the MySQL test database */
//        con->setSchema("gateway");
//
//        stmt = con->createStatement();
//        res = stmt->executeQuery("INSERT INTO DEVICE (`id`) VALUES (6)"); // replace with your statement
////        while (res->next()) {
////            cout << "\t... MySQL replies: ";
////            /* Access column data by alias or column name */
////            cout << res->getString("_message") << endl;
////            cout << "\t... MySQL says it again: ";
////            /* Access column fata by numeric offset, 1 is the first column */
////            cout << res->getString(1) << endl;
////        }
////        delete res;
////        delete stmt;
////        delete con;
//
//    } catch (sql::SQLException &e) {
//        cout << "# ERR: SQLException in " << __FILE__;
//        cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
//        cout << "# ERR: " << e.what();
//        cout << " (MySQL error code: " << e.getErrorCode();
//        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
//    }
//
//    cout << endl;
//
//    return EXIT_SUCCESS;
//}