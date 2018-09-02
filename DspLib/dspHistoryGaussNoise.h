#pragma once
/*==============================================================================
Gaussian noise generator.
==============================================================================*/

//******************************************************************************
//******************************************************************************
//******************************************************************************

#include <random>
#include "dspHistoryGenBase.h"

namespace Dsp
{

//******************************************************************************
//******************************************************************************
//******************************************************************************
// This is a class that provides a gaussian noise generator.

class HistoryGaussNoise
{
public:
   //******************************************************************************
   //******************************************************************************
   //******************************************************************************
   // Input parameters.

   double  mNoiseSigma;   // Random noise generator sigma

   //******************************************************************************
   //******************************************************************************
   //******************************************************************************
   // Gaussian noise variables.

   bool mNoiseFlag;
   std::mt19937 mRandomGenerator;
   std::normal_distribution<double> mRandomDistribution;

   //******************************************************************************
   //******************************************************************************
   //******************************************************************************
   // Constructor and initialization.

   HistoryGaussNoise();
   HistoryGaussNoise(double aSigma);

   //******************************************************************************
   //******************************************************************************
   //******************************************************************************
   // Gaussian noise methods.

   // Initialize random distribution.
   void initialize(double aSigma);

   // Get noise from random distribution.
   double getNoise();
};

//******************************************************************************
}//namespace


