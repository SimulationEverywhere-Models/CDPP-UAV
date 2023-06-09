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

#ifndef __TRACK_H
#define __TRACk_H

#include <list>
#include "atomic.h"     // class Atomic

class Track : public Atomic
{
public:
	Track( const string &name = "Track" );					//Default constructor

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
	Time TrackTime;
	//typedef list<Value> ElementList ;
	//ElementList elements ;

	Time timeLeft;

};	// class Track

// ** inline ** // 
inline
string Track::className() const
{
	return "Track" ;
}

#endif   //__TRACK_H
