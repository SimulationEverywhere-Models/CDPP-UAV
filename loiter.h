/*******************************************************************
*
*  DESCRIPTION: Atomic Model Loiter
*
*  AUTHOR: Rami Youssef
*
*  EMAIL: ryoussef@drdc-rddc.gc.ca
*         
*
*  DATE: 19/10/2003
*
*******************************************************************/

#ifndef __LOITER_H
#define __LOITER_H

#include <list>
#include "atomic.h"     // class Atomic

class loiter : public Atomic
{
public:
	loiter( const string &name = "loiter" );					//Default constructor

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
	Time LoiterTime;
	//typedef list<Value> ElementList ;
	//ElementList elements ;

	Time timeLeft;

};	// class Loiter

// ** inline ** // 
inline
string loiter::className() const
{
	return "Loiter" ;
}

#endif   //__LOITER_H
