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
#include "fuelmonitor.h"      // class Queue
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )
#include "queue.h" 
/** public functions **/

/*******************************************************************
* Function Name: Track
* Description: 
********************************************************************/
Fuelmonitor::Fuelmonitor( const string &name )
: Atomic( name )
, in( addInputPort( "in" ) )
, stop( addInputPort( "stop" ) )
, outoffuel( addOutputPort( "outoffuel" ) )
, fuelCapacity( 0, 0, 35, 0 )
{
	string time( MainSimulator::Instance().getParameter( description(), "preparation" ) ) ;

	if( time != "" )
		fuelCapacity = time ;
}

/*******************************************************************
* Function Name: initFunction
* Description: Resetea la lista
* Precondition: El tiempo del proximo evento interno es Infinito
********************************************************************/
Model &Fuelmonitor::initFunction()
{
	elements.erase( elements.begin(), elements.end() ) ;
	//this->passivate();
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description: 
********************************************************************/
Model &Fuelmonitor::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == in )
	{	
		if(!elements.empty())
		{}
		else 
		{
		elements.push_back(1) ;
		holdIn( active, fuelCapacity);
		}

	}

	

	else if( msg.port() == stop )
		{
		
		if( elements.empty() || elements.size() ==2 )
		{}
		else
		{
		if( state() == active )
				{
				passivate();
				}
		}
	}
	return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description: 
********************************************************************/
Model &Fuelmonitor::internalFunction( const InternalMessage & )
{
	passivate();
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
* Description: 
********************************************************************/
Model &Fuelmonitor::outputFunction( const InternalMessage &msg )
{
	if (elements.size()==1)
	{
	sendOutput( msg.time(), outoffuel,1) ;
	}

	return *this ;

}
