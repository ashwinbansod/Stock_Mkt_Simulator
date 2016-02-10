/*! File Name: Main file.
 *  Description: This file contains the main function
 *
 *  Creation Date: 02-07-2016 
 *  Author: Ashwin 
 */

#include <main.h>

using namespace std;

int main ()
{
   int iRetVal = 0;
   DBConnection *oDBConn = new DBConnection();
   
   oDBConn->InitDB();
   
   //Sample DB Connection test
   sql::ResultSet *psRes;
   string saQuery = "SELECT 'Hello World!' AS _message";
   
   psRes = oDBConn->ExecuteQuery(saQuery);
   
   while (psRes->next()) {
   cout << "\t... MySQL replies: ";
   /* Access column data by alias or column name */
   cout << psRes->getString("_message") << endl;
   cout << "\t... MySQL says it again: ";
   /* Access column fata by numeric offset, 1 is the first column */
   cout << psRes->getString(1) << endl;
   } 
   
   OrderBook sOrderBook;
   
   sOrderBook.iUserID        = 1000;
   sOrderBook.iTokenNmbr     = 1234;
   sOrderBook.iVol           = 100;
   sOrderBook.iPrice         = 15000;
   memcpy(sOrderBook.caSymbol, "APPLE     ", 10);
   memcpy(sOrderBook.caSerise, "EQ", 2);
   sOrderBook.shBuySellIndc  = 2;
   sOrderBook.shActivePassiveIndc  = 1;
   sOrderBook.shIOCBitIndc   = 0;
   sOrderBook.shDayBitIndc   = 1;
   sOrderBook.shMktBitIndc   = 0;
   sOrderBook.dOrdrNmbr      = 2016090200000002;
   sOrderBook.lLadtModTimeStmp  = 12345456;
   
   iRetVal = sOrderBook.InsertOrderBook(oDBConn);
   if (iRetVal != SUCCESS)
   {
      iRetVal = 3;
   }
   
   oDBConn->DisconnectDB();
   
   return iRetVal;
}
