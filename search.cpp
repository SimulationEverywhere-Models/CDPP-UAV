/*******************************************************************
*
*  DESCRIPTION: Atomic Model Search
*
*  AUTHOR: Rami Youssef
*
*  EMAIL: Rami.Youssef@drdc-rddc.gc.ca
*         
*
*  DATE: 19/10/2003
*
*******************************************************************/

/** include files **/
#include "search.h"      // class Queue
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )
#include <string>
/** public functions **/

/*******************************************************************
* Function Name: Search
* Description: 
********************************************************************/
search::search( const string &name )
: Atomic( name )
, in( addInputPort( "in" ) )
, stop( addInputPort( "stop" ) )
, done( addOutputPort( "done" ) )
, searchTime( 0, 0, 3, 0 )
{
	string time( MainSimulator::Instance().getParameter( description(), "preparation" ) ) ;

	//cout << " Hiiu! ";
	if( time != "" )
		searchTime = time ;
}

/*******************************************************************
* Function Name: initFunction
* Description: Resetea la lista
* Precondition: El tiempo del proximo evento interno es Infinito
********************************************************************/
Model &search::initFunction()
{
	//elements.erase( elements.begin(), elements.end() ) ;
	this->passivate();
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description: 
********************************************************************/
Model &search::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == in )
	{
	
			holdIn( active, searchTime );
	}


	if( msg.port() == stop )
		{
			if( state() == active )
				{
				passivate();
				}
		}	
	return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description: 
********************************************************************/
Model &search::internalFunction( const InternalMessage & )
{
	passivate();
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
* Description: 
********************************************************************/
Model &search::outputFunction( const InternalMessage &msg )
{
	 //sendOutput( msg.time(), out,1 ) ;
	 sendOutput( msg.time(), done,1) ;
	return *this ;
}
