/*==============================================================================
Description:
==============================================================================*/

//******************************************************************************
//******************************************************************************
//******************************************************************************

#include "stdafx.h"

#include "dsp_math.h"
#include "dspStatistics.h"
#include "dspHistoryGenSinWave.h"

namespace Dsp
{

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Constructor

HistoryGenSinWave::HistoryGenSinWave(HistoryGenParms& aParms)
{
   mParms = aParms;
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Show

void HistoryGenSinWave::show()
{
   BaseClass::show();
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Generate the signal history according to the parameters.

void HistoryGenSinWave::generateHistoryType1(History& aHistory)
{
   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Initialize.

   // Initialize base class variables according to the parameters and 
   // initialize the history for the correct sample size with a zero value
   // array and a lineary increasing time array.
   BaseClass::initializeHistoryType1(aHistory);

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Generate sin wave add it to the history value array.

   for (int k = 0; k < mParms.mMaxSamples; k++)
   {
      double tTime = aHistory.mTime[k];
      double tValue = mParms.mA*sin(DSP_2PI*mParms.mFc*tTime + mParms.mPhi);

      tValue += mParms.mEX;
      aHistory.mValue[k] = tValue;
   }

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Add gaussian noise to the history sample array.

    BaseClass::addNoise(aHistory);

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Normalize the history to get the desired expectation and uncertainty.

// BaseClass::normalizeHistory(aHistory);
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Generate the signal history according to the parameters.

void HistoryGenSinWave::generateHistoryType2(History& aHistory)
{
   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Initialize the history with Type2 sample timing. Random intersample
   // arrival times, zero values.

   BaseClass::initializeHistoryType2(aHistory);

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Generate sin wave add it to the history value array.

   for (int k = 0; k < mParms.mMaxSamples; k++)
   {
      double tTime = aHistory.mTime[k];
      double tValue = mParms.mA*sin(DSP_2PI*mParms.mFc*tTime + mParms.mPhi);
      aHistory.mValue[k] = tValue;
   }

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Add gaussian noise to the history sample array.

    BaseClass::addNoise(aHistory);

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Normalize the history to get the desired expectation and uncertainty.

// BaseClass::normalizeHistory(aHistory);
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
}//namespace