/*! File Name: OrderBook.h 
 *  Description: This header file contians the structre of OrderBook  
 *               OrderBook.cpp 
 *
 *  Creation Date: 02-07-2016 
 *  Author: Ashwin
 */
 
#ifndef STOCK_MKT_ORDER_BOOK_H
#define STOCK_MKT_ORDER_BOOK_H

/******************************************************************************/
/*                   H.E.A.D.E.R  F.I.L.E.S                                   */
/******************************************************************************/
/* Standard C++ includes */
#include<stdio.h>
#include <string.h>

#include <DBConnection.h>

/******************************************************************************/
/*                              M.A.C.R.O.S                                   */
/******************************************************************************/

/******************************************************************************/
/*                C.L.A.S.S  D.E.F.I.N.I.T.I.O.N                              */
/******************************************************************************/

class OrderBook {

   public:
   int iUserID;
   int iTokenNmbr;
   int iVol;
   int iPrice;
   char caSymbol[10];
   char caSerise[2];
   short shBuySellIndc;
   short shActivePassiveIndc;
   short shIOCBitIndc;
   short shDayBitIndc;
   short shMktBitIndc;
   double dOrdrNmbr;
   long lLadtModTimeStmp;
   
   
   public:
   OrderBook(void);
   
   ~OrderBook(void);
   
   int InsertOrderBook(DBConnection*);
   
   int SelectOrderBook(DBConnection*, OrderBook*);
   
   int UpdateOrderBook(DBConnection*, OrderBook*);
   
};


/******************************************************************************/
/*                F.U.N.C.T.I.O.N  D.E.F.I.N.I.T.I.O.N                        */
/******************************************************************************/


#endif //STOCK_MKT_ORDER_BOOK_H

