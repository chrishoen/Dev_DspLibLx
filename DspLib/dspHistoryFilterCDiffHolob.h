#pragma once

/*==============================================================================
Signal history linear operator: Filter - Pavel Holoborodko central difference
algorithms for smoothing, first and second derivates.
==============================================================================*/

//******************************************************************************
//******************************************************************************
//******************************************************************************

#include "risCmdLineExec.h"

#include "dspHistoryFilterParms.h"
#include "dspHistoryFilterCDiffBase.h"

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
// This class provides a linear operator on the set of signal histories.
// It implements the central difference algorithms of Pavel Holobordko to 
// calculate smoothing, first and second derivatives. The central differece
// calculations for smoothing, first and second derivatives are the same but
// with different coefficients.
 
class HistoryFilterCDiffHolob : public HistoryFilterCDiffBase
{
public:
   typedef HistoryFilterCDiffBase BaseClass;

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Members.

   // If true then add backward terms, else subtract.
   // Central difference filters are symmetric or asymetric. The coefficients
   // for forward time and backward time are the same. Forward terms are added
   // to the accumulator. Backward terms are either added or subtracted,
   // depending on the type. Smoothers add the backward terms, first
   // derivatives subtract, and second derivatives add.
   bool mBackAddFlag;

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Methods.

   // Constructor.
   HistoryFilterCDiffHolob(HistoryFilterParms& aParms);
   void show();

   // Apply the linear operator from the input to the output. F:X->Y.
   // This applies the central difference filter using the coefficients 
   // calculated below.
   void operate(History& aX, History& aY) override;

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Methods.

   // Calculate the central difference filter coefficents, based on the parms.
   // This coefficients are used to calculate the smoothed output.
   void calculateCoefficientsSmoother();

   // Calculate the central difference filter coefficents, based on the parms.
   // This coefficients are used to calculate the first derivative.
   void calculateCoefficientsFirstDerivative();

   // Calculate the central difference filter coefficents, based on the parms.
   // This coefficients are used to calculate the second derivative.
   void calculateCoefficientsSecondDerivative();
};

//******************************************************************************
//******************************************************************************
//******************************************************************************
}//namespace


