/*******************************************************************
*
*  DESCRIPTION: Atomic Model GoToWaypoint
*
*  AUTHOR: Rami Youssef
*
*  EMAIL: ryoussef@drdc-rddc.gc.ca
*         
*
*  DATE: 19/10/2003
*
*******************************************************************/

#ifndef __GOTOWAYPOINT_H
#define __GOTOWAYPOINT_H

#include <list>
#include "atomic.h"     // class Atomic

class gotowaypoint : public Atomic
{
public:
	gotowaypoint( const string &name = "gotowaypoint" );					//Default constructor

	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &in;
	const Port &stop;
	const Port &done;
	Time estimatedArrivalTime;
	//typedef list<Value> ElementList ;
	//ElementList elements ;

	Time timeLeft;

};	// class GoToWaypoint

// ** inline ** // 
inline
string gotowaypoint::className() const
{
	return "gotowaypoint" ;
}

#endif   //__GOTOWAYPOINT_H
