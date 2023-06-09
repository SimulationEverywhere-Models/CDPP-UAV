/*******************************************************************
*
*  DESCRIPTION: Atomic Model GoToWaypoint
*
*  AUTHOR: Rami Youssef
*
*  EMAIL: R.Youssef@drdc-rddc.gc.ca
*         
*
*  DATE: 19/10/2003
*
*******************************************************************/

/** include files **/
#include "gotowaypoint.h"      // class Queue
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: GoToWaypoint
* Description: 
********************************************************************/
gotowaypoint::gotowaypoint( const string &name )
: Atomic( name )
, in( addInputPort( "in" ) )
, stop( addInputPort( "stop" ) )
, done( addOutputPort( "done" ) )
, estimatedArrivalTime( 0, 0, 25, 0 )
{
	string time( MainSimulator::Instance().getParameter( description(), "preparation" ) ) ;

	//cout << " Hii! ";
	if( time != "" )
		estimatedArrivalTime = time ;
}

/*******************************************************************
* Function Name: initFunction
* Description: Resetea la lista
* Precondition: El tiempo del proximo evento interno es Infinito
********************************************************************/
Model &gotowaypoint::initFunction()
{
	//elements.erase( elements.begin(), elements.end() ) ;
	this->passivate();
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description: 
********************************************************************/
Model &gotowaypoint::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == in )
	{
		//elements.push_back( msg.value() ) ;
		//if( elements.size() == 1 )
			holdIn( active, estimatedArrivalTime );
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
Model &gotowaypoint::internalFunction( const InternalMessage & )
{
	passivate();
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
* Description: 
********************************************************************/
Model &gotowaypoint::outputFunction( const InternalMessage &msg )
{
	sendOutput( msg.time(), done,1) ;
	return *this ;
}
