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

#ifndef __MISSIONSCRIPT_H
#define __MISSIONSCRIPT_H

#include <list>
#include "atomic.h"     // class Atomic

class Missionscript: public Atomic
{
public:
	Missionscript( const string &name = "Missionscript" );					//Default constructor

	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &in;
	const Port &stop;
	const Port &out;
	const Port &stopexecution;
	
	Time preparationTime;
	
	typedef list<Value> ElementList ;
	ElementList elements ;

	Time timeLeft;
	//Time searchTime;
};	// class Queue

// ** inline ** // 
inline
string Missionscript::className() const
{
	return "Missionscript" ;
}

#endif   //__QUEUE_H
