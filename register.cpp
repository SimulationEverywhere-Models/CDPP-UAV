/*******************************************************************
*
*  DESCRIPTION: Simulator::registerNewAtomics()
*
*  AUTHOR: Amir Barylko & Jorge Beyoglonian 
*
*  EMAIL: mailto://amir@dc.uba.ar
*         mailto://jbeyoglo@dc.uba.ar
*
*  DATE: 27/6/1998
*
*******************************************************************/

#include "modeladm.h" 
#include "mainsimu.h"
#include "queue.h"      // class Queue
#include "generat.h"    // class Generator
#include "cpu.h"        // class CPU
#include "transduc.h"   // class Transducer
#include "trafico.h"    // class Trafico
#include "track.h"
#include "loiter.h"
#include "search.h"
#include "gotowaypoint.h"
#include "missionscript.h"
#include "Fuelmonitor.h"

void MainSimulator::registerNewAtomics()
{
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Fuelmonitor>() , "Fuelmonitor" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Track>() , "Track" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Queue>() , "Queue" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Generator>() , "Generator" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<CPU>() , "CPU" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Transducer>() , "Transducer" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Trafico>() , "Trafico" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<search>() , "search" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<gotowaypoint>() , "gotowaypoint" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<loiter>() , "loiter" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Missionscript>() , "Missionscript" ) ;
}
