#ifndef _DSP_MATH_H_
#define _DSP_MATH_H_

/*==============================================================================
Description:
Extends math.h
==============================================================================*/

#include <math.h>

//******************************************************************************
//******************************************************************************
//******************************************************************************

#define DSP_C   299,792,458 

#define DSP_PI    3.14159265358979323846264338327950288419716939937510
#define DSP_2PI   2.0*DSP_PI

#define DSP_RAD   DSP_PI/180.0
#define DSP_DEG   180.0/DSP_PI

static constexpr double cDsp_C     = 299792458.0;
static constexpr double cDsp_Pi    = 3.14159265358979323846264338327950288419716939937510;
static constexpr double cDsp_TwoPi = 2.0*cDsp_Pi;

static constexpr double cDsp_Rad   = cDsp_Pi/180.0;
static constexpr double cDsp_Deg   = 180.0/cDsp_Pi;

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Convert radians to degrees, degrees to radians

   inline double dsp_rad(double x) {return x*DSP_RAD;}
   inline double dsp_deg(double x) {return x*DSP_DEG;}

   inline double rad(double x) {return x*DSP_RAD;}
   inline double deg(double x) {return x*DSP_DEG;}


//******************************************************************************
//******************************************************************************
//******************************************************************************
// Format an angle for -pi .. pi or 0 .. 2pi

   inline void dsp_format_pi (double* x)
   { 
      if (*x >=  DSP_PI) *x -= DSP_2PI;
      if (*x <  -DSP_PI) *x += DSP_2PI;
   }

   inline void dsp_format_two_pi (double* x)
   { 
      if (*x >=  DSP_2PI) *x -= DSP_2PI;
      if (*x <       0.0) *x += DSP_2PI;
   }

   
#endif

