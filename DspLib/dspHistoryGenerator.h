#pragma once

/*==============================================================================
Signal history general generator.
==============================================================================*/

//******************************************************************************
//******************************************************************************
//******************************************************************************

#include "dspHistoryGenParms.h"
#include "dspHistory.h"

//******************************************************************************
//******************************************************************************
//******************************************************************************

namespace Dsp
{

//******************************************************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
// This class provides a generator for a signal history that evolves according
// parameters specified in the parms file. Based on the generator type
// parameter, it instantiates one of the concrete generators and used it to
// generate a history.
 
class HistoryGenerator
{
public:

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Members.

   HistoryGenParms mParms;

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Methods.

   // Constructor.
   HistoryGenerator(HistoryGenParms& aParms);
   void show();

   // Generate the signal history according to the parameters. This is a jump 
   // table that selects one of the concrete history generators according to
   // the generator type parameter and uses it to generate a history.
   void generateHistory(History& aHistory);   
};

//******************************************************************************
}//namespace

