/*******************************************************************
*
*  DESCRIPTION: Atomic Model Track
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
#include "track.h"      // class Queue
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: Track
* Description: 
********************************************************************/
Track::Track( const string &name )
: Atomic( name )
, in( addInputPort( "in" ) )
, stop( addInputPort( "stop" ) )
, done( addOutputPort( "done" ) )
, TrackTime( 0, 0, 20, 0 )
{
	string time( MainSimulator::Instance().getParameter( description(), "preparation" ) ) ;

	//cout << " Hii! ";
	if( time != "" )
		TrackTime = time ;
}

/*******************************************************************
* Function Name: initFunction
* Description: Resetea la lista
* Precondition: El tiempo del proximo evento interno es Infinito
********************************************************************/
Model &Track::initFunction()
{
	//elements.erase( elements.begin(), elements.end() ) ;
	//this->passivate();
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description: 
********************************************************************/
Model &Track::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == in )
	{
		holdIn( active, TrackTime );
	}

	

	else if( msg.port() == stop )
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
Model &Track::internalFunction( const InternalMessage & )
{
	passivate();
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
* Description: 
********************************************************************/
Model &Track::outputFunction( const InternalMessage &msg )
{
	sendOutput( msg.time(), done,1) ;
	return *this ;
}
