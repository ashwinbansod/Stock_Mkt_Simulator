/*! File Name: OrderBook.cpp 
 *  Description: This header file includes the declerations for function  
 *               defined in OrderBook.h
 *
 *  Creation Date: 02-07-2016 
 *  Author: Ashwin
 */
 

/******************************************************************************/
/*                   H.E.A.D.E.R  F.I.L.E.S                                   */
/******************************************************************************/
#include <OrderBook.h>
using namespace std;

/******************************************************************************/
/*                              M.A.C.R.O.S                                   */
/******************************************************************************/

#define DB_USERNAME                         "root"
#define DB_PASSWORD                         "root"
#define DB_CONN_STR                         "tcp://127.0.0.1:3306"
#define DB_NAME                             "test"


/******************************************************************************/
/*                C.L.A.S.S  D.E.F.I.N.I.T.I.O.N                              */
/******************************************************************************/

/******************************************************************************/
/*                F.U.N.C.T.I.O.N  D.E.C.L.A.R.A.T.I.O.N                      */
/******************************************************************************/

OrderBook::OrderBook(void)
{  
   /* Create a connection */
   this->iUserID        = 0;
   this->iTokenNmbr     = 0;
   this->iVol           = 0;
   this->iPrice         = 0;
   memset(this->caSymbol, '\0', 10);
   memset(this->caSerise, '\0', 2);
   this->shBuySellIndc  = 0;
   this->shActivePassiveIndc  = 0;
   this->shIOCBitIndc   = 0;
   this->shDayBitIndc   = 0;
   this->shMktBitIndc   = 0;
   this->dOrdrNmbr      = 0;
   this->lLadtModTimeStmp  = 0;
	
}

OrderBook:: ~OrderBook(void)
{  
   /* Destructor for OrderBook  */
}

int OrderBook::InsertOrderBook(DBConnection *psDBConn)
{
   int iRetVal = 0;
   char sQuery[512];
   sql::ResultSet *psRes = NULL;
   
   memset(sQuery, '\0', sizeof(sQuery));
   
   /* Create a Insert Query */
	sprintf(sQuery,
	        "%s %d %s %d %s %d %s %d %s %s %s %s %s %hd %s %hd %s %hd %s %hd %s %hd %s %lf %s %ld %s",
	        "Insert into OrderBook Values (\'",
	        this->iUserID,
	        "\', \'",
	        this->iTokenNmbr,
	        "\', \'",
	        this->iVol,
	        "\', \'",
	        this->iPrice,
	        "\', \'",
	        this->caSymbol,
	        "\', \'",
	        this->caSerise,
	        "\', \'",
	        this->shBuySellIndc,
	        "\', \'",
	        this->shActivePassiveIndc,
	        "\', \'",
	        this->shIOCBitIndc,
	        "\', \'",
	        this->shDayBitIndc,
	        "\', \'",
	        this->shMktBitIndc,
	        "\', \'",
	        this->dOrdrNmbr,
	        "\', \'",
	        this->lLadtModTimeStmp,
	        "\') ");
	        
	
	/* Execute the above query */
	psRes = psDBConn->ExecuteQuery(sQuery);

	
   return iRetVal;
}

int OrderBook::SelectOrderBook(DBConnection *psDBConn, OrderBook *psOrderBook)
{
   int iRetVal = 0;
   
   /* Execute destructor of the class  */
	

   return iRetVal;
}

int OrderBook::UpdateOrderBook(DBConnection *psDBConn, OrderBook *psOrderBook)
{
   int iRetVal = 0;
   
   /* Execute the given query and return result set  */

   return iRetVal;
}


