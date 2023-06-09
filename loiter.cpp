/*******************************************************************
*
*  DESCRIPTION: Atomic Model Loiter
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
#include "loiter.h"      // class Queue
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: Loiter
* Description: 
********************************************************************/
loiter::loiter( const string &name )
: Atomic( name )
, in( addInputPort( "in" ) )
, stop( addInputPort( "stop" ) )
, done( addOutputPort( "done" ) )
, LoiterTime( 0, 0, 24, 0 )
{
	string time( MainSimulator::Instance().getParameter( description(), "preparation" ) ) ;

	//cout << " Hii! ";
	if( time != "" )
		LoiterTime = time ;
}

/*******************************************************************
* Function Name: initFunction
* Description: Resetea la lista
* Precondition: El tiempo del proximo evento interno es Infinito
********************************************************************/
Model &loiter::initFunction()
{
	//elements.erase( elements.begin(), elements.end() ) ;
	this->passivate();
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description: 
********************************************************************/
Model &loiter::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == in )
	{
		//elements.push_back( msg.value() ) ;
		//if( elements.size() == 1 )
			holdIn( active, LoiterTime );
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
Model &loiter::internalFunction( const InternalMessage & )
{
	passivate();
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
* Description: 
********************************************************************/
Model &loiter::outputFunction( const InternalMessage &msg )
{
	//sendOutput( msg.time(), done, elements.front() ) ;
	sendOutput( msg.time(), done,1) ;
	return *this ;
}
