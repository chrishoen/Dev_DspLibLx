#pragma once
/*==============================================================================
Vectors and matrices on R3.
==============================================================================*/

//******************************************************************************
//******************************************************************************
//******************************************************************************

namespace Dsp
{
//******************************************************************************
//******************************************************************************
//******************************************************************************

class ThreeAxisAngle
{
public:
   // Vector components
   double mAxisX;
   double mAxisY;
   double mAxisZ;
   double mAngle;

   // Constructor
   ThreeAxisAngle();
   ThreeAxisAngle(double aAxisX,double aAxisY,double aAxisZ,double aAngle);

   // Assign values
   void set(double aAxisX,double aAxisY,double aAxisZ,double aAngle);
   void setToZero();
   void setIdentity();

   //show
   void show(char* aLabel);
};

//******************************************************************************
//******************************************************************************
//******************************************************************************

}//namespace


