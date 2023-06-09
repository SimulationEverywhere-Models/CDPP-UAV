/*******************************************************************
*
*  DESCRIPTION: Atomic Model Track
*
*  AUTHOR: Rami Youssef
*
*  EMAIL: ryoussef@drdc-rddc.gc.ca
*         
*
*  DATE: 19/10/2003
*
*******************************************************************/

#ifndef __FUELMONITOR_H
#define __FUELMONITOR_H
//test
#include <list>
#include "atomic.h"     // class Atomic
class Fuelmonitor : public Atomic
{
public:
	Fuelmonitor( const string &name = "Fuelmonitor" );					//Default constructor

	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &in;
	const Port &stop;
	const Port &outoffuel;
	Time fuelCapacity;
	typedef list<Value> ElementList ;
	ElementList elements ;

	Time timeLeft;

};	// class Track

// ** inline ** // 
inline
string Fuelmonitor::className() const
{
	return "Fuelmonitor" ;
}

#endif   //__TRACK_H
