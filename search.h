/*******************************************************************
*
*  DESCRIPTION: Atomic Model Search
*
*  AUTHOR: Rami Youssef
*
*  EMAIL: ryoussef@drdc-rddc.gc.ca
*         
*
*  DATE: 19/10/2003
*
*******************************************************************/

#ifndef __SEARCH_H
#define __SEARCH_H

#include <list>
#include "atomic.h"     // class Atomic

class search : public Atomic
{
public:
	search( const string &name = "search" );					//Default constructor

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
	Time searchTime;
	//typedef list<Value> ElementList ;
	//ElementList elements ;

	Time timeLeft;

};	// class Search

// ** inline ** // 
inline
string search::className() const
{
	return "search" ;
}

#endif   //__QUEUE_H
