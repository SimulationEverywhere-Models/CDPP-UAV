/*******************************************************************
*
*  DESCRIPTION: Atomic Model Queue
*
*  AUTHOR: Amir Barylko & Jorge Beyoglonian 
*
*  EMAIL: mailto://amir@dc.uba.ar
*         mailto://jbeyoglo@dc.uba.ar
*
*  DATE: 27/6/1998
*
*******************************************************************/

/** include files **/
#include "missionscript.h"      // class Queue
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )
#include "queue.h" 

/** public functions **/

/*******************************************************************
* Function Name: MissionScript
* Description: 
********************************************************************/
Missionscript::Missionscript( const string &name )
: Atomic( name )
, in( addInputPort( "in" ) )
, stop( addInputPort( "stop" ) )
, out( addOutputPort( "out" ) )
, stopexecution( addOutputPort( "stopexecution" ) )
, preparationTime( 0, 0, 2, 0 )

{
	string time( MainSimulator::Instance().getParameter( description(), "preparation" ) ) ;

	if( time != "" )
		preparationTime = time ;
	}

/*******************************************************************
* Function Name: initFunction
* Description: Resetea la lista
* Precondition: El tiempo del proximo evento interno es Infinito
********************************************************************/
Model &Missionscript::initFunction()
{
	elements.erase( elements.begin(), elements.end() ) ;
	//passivate();
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description: 
********************************************************************/
Model &Missionscript::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == in )
	{		
			if( !elements.empty() )
			{}
			else
			{
			elements.push_back(1) ;
			holdIn( active, preparationTime );
			}
	}

		if( msg.port() == stop )
	{
		if( elements.empty() || elements.size() ==2 )
			{}	
		
		else{
			elements.push_back(0) ;
			holdIn( active, preparationTime );
			}
	}

/*	if( msg.port() == done )
	{
	holdIn( active, preparationTime );
	}

	//if( msg.port() == stop )
		if( state() == active && msg.value() )
		{
			//timeLeft = msg.time() - lastChange();
			passivate();
		} else
			//if( state() == passive && !msg.value() )
				holdIn( active, timeLeft );
*/

	return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description: 
********************************************************************/
Model &Missionscript::internalFunction( const InternalMessage & )
{
	passivate();
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
* Description: 
********************************************************************/
Model &Missionscript::outputFunction( const InternalMessage &msg )
{
	 //elements.pop_front();
	if (elements.size()==1)
	{
		sendOutput( msg.time(), out, elements.front() ) ;
		//elements.pop_front();
	}
	
	else if (elements.size()==2)
	{
		sendOutput( msg.time(), stopexecution, elements.front() ) ;
	//elements.pop_front();
	}

	return *this ;
}
