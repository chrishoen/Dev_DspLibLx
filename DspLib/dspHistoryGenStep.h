#pragma once

/*==============================================================================
Signal history generator with a step function.
==============================================================================*/

//******************************************************************************
//******************************************************************************
//******************************************************************************

#include "risCmdLineExec.h"

#include "dspHistoryGenParms.h"
#include "dspHistoryGenBase.h"

//******************************************************************************
//******************************************************************************
//******************************************************************************

namespace Dsp
{

//******************************************************************************
//******************************************************************************
//******************************************************************************
// This class provides a generator for a signal history that evolves according
// to a step function.
 
class HistoryGenStep : public HistoryGenBase
{
public:
   typedef HistoryGenBase BaseClass;

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Members.

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Methods.

   // Constructor.
   HistoryGenStep(HistoryGenParms& aParms);
   void show();

   // Generate the signal history according to the parameters.
   // Type1 is  periodic, with   regular intersample arrival times.
   // Type2 is aperiodic, with irregular intersample arrival times.
   void generateHistoryType1(History& aHistory) override;
   void generateHistoryType2(History& aHistory) override;
};

//******************************************************************************
//******************************************************************************
//******************************************************************************
}//namespace


