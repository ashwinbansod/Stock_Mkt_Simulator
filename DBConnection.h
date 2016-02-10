/*! File Name: DBConnection.h 
 *  Description: This header file includes the headers required for 
 *               DBConnection.cpp 
 *
 *  Creation Date: 02-07-2016 
 *  Author: Ashwin
 */
 
#ifndef STOCK_MKT_DBCONNECTION_H
#define STOCK_MKT_DBCONNECTION_H

/******************************************************************************/
/*                   H.E.A.D.E.R  F.I.L.E.S                                   */
/******************************************************************************/
/* Standard C++ includes */

/* MYSQL rerlated header files */
#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

/******************************************************************************/
/*                              M.A.C.R.O.S                                   */
/******************************************************************************/

/******************************************************************************/
/*                C.L.A.S.S  D.E.F.I.N.I.T.I.O.N                              */
/******************************************************************************/

class DBConnection {

   private:
   sql::Driver *psDriver;
   sql::Connection *psConn;
   sql::Statement *psStmt;
   
   public:
   sql::ResultSet *psRes;

   public:
   DBConnection();
   
   ~DBConnection();
   
   int InitDB();
   
   int DisconnectDB();
   
   sql::ResultSet* ExecuteQuery(std::string sQuery);

};


/******************************************************************************/
/*                F.U.N.C.T.I.O.N  D.E.F.I.N.I.T.I.O.N                        */
/******************************************************************************/


#endif //STOCK_MKT_DBCONNECTION_H

