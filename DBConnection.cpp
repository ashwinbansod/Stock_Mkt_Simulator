/*! File Name: DBConnection.cpp 
 *  Description: This header file includes the declerations for function  
 *               defined in OrderBook.h
 *
 *  Creation Date: 02-07-2016 
 *  Author: Ashwin
 */
 

/******************************************************************************/
/*                   H.E.A.D.E.R  F.I.L.E.S                                   */
/******************************************************************************/
#include <DBConnection.h>

/******************************************************************************/
/*                              M.A.C.R.O.S                                   */
/******************************************************************************/

#define DB_USERNAME                         "root"
#define DB_PASSWORD                         "root"
#define DB_CONN_STR                         "tcp://127.0.0.1:3306"
#define DB_NAME                             "StockMktSimulator"


/******************************************************************************/
/*                C.L.A.S.S  D.E.F.I.N.I.T.I.O.N                              */
/******************************************************************************/

/******************************************************************************/
/*                F.U.N.C.T.I.O.N  D.E.C.L.A.R.A.T.I.O.N                      */
/******************************************************************************/

DBConnection::DBConnection(void)
{  
   /* Create a connection */
	this->psDriver = NULL;
	this->psConn = NULL;
	this->psStmt = NULL;
	this->psRes = NULL;
}

DBConnection:: ~DBConnection(void)
{  
   /* Delete connection variables  */
   if (this->psConn != NULL)
      delete psConn;
   
   if (this->psStmt != NULL)
      delete psStmt;
   
	if (this->psRes != NULL)
	   delete psRes;
}

int DBConnection::InitDB(void)
{
   int iRetVal = 0;
   
   /* Create a connection */
	psDriver = get_driver_instance();
	psConn = psDriver->connect(DB_CONN_STR, DB_USERNAME, DB_PASSWORD);
	
	/* Connect to the MySQL test database */
	psConn->setSchema(DB_NAME);

	psStmt = psConn->createStatement();

   return iRetVal;
}

int DBConnection::DisconnectDB(void)
{
   int iRetVal = 0;
   
   /* Execute destructor of the class  */
	this->~DBConnection();

   return iRetVal;
}

sql::ResultSet* DBConnection::ExecuteQuery(std::string sQuery)
{
   int iRetVal = 0;
   
   /* Execute the given query and return result set  */
	psRes = psStmt->executeQuery(sQuery);

   return psRes;
}


