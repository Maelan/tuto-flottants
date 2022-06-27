#ifndef INCLUDE_CMPFLOATS_H
#define INCLUDE_CMPFLOATS_H


#include <stdint.h>
#include <math.h>   /* pour les macros de test des nombres
                       flottants ( isnan() et isinf() ) */


/* représentation entière du nombre en virgule flottante */
#define  INTREPOFFLOAT(f)   ( *(int32_t*)&(f) )
#define  INTREPOFDOUBLE(d)  ( *(int64_t*)&(d) )

/* marge maximale séparant deux nombres flottants considérés comme égaux,
   en termes d'ULP (« Unit of Least Precision ») */
#define  MAXULPSFLOAT   5
#define  MAXULPSDOUBLE  5


/* renvoie vrai (1) si les 2 nombres sont égaux, faux (0) sinon */
int floatsAreEqual(float a, float b);
int doublesAreEqual(double a, double b);


/* renvoie  -1 si a>b,  0 si a==b,  1 si a<b,  ou -2 si a ou b est NaN */
int cmpFloats(float a, float b);
int cmpDoubles(double a, double b);

/* macros booléennes (à utiliser dans des tests simples) */
#define  CMPFLOATS_EQUAL(a,b)     (cmpFloats((a),(b))==0)      // =>  a==b
#define  CMPFLOATS_UNEQUAL(a,b)   (cmpFloats((a),(b))!=0)      // =>  a!=b
#define  CMPFLOATS_GT(a,b)        (cmpFloats((a),(b))==-1)     // =>  a>b
#define  CMPFLOATS_LT(a,b)        (cmpFloats((a),(b))==1)      // =>  a<b
//#define  CMPFLOATS_GTEQUAL(a,b)   (cmpFloats((a),(b))!=1)      // =>  a>=b
//#define  CMPFLOATS_LTEQUAL(a,b)   (cmpFloats((a),(b))!=-1)     // =>  a<=b
#define  CMPFLOATS_GTEQUAL(a,b)   ((cmpFloats((a),(b))-1)&2)   // =>  a>=b
#define  CMPFLOATS_LTEQUAL(a,b)   (cmpFloats((a),(b))>=0)      // =>  a<=b
#define  CMPFLOATS_NAN(a,b)       (cmpFloats((a),(b))==-2)     // =>  a==NaN || b==NaN

#define  CMPDOUBLES_EQUAL(a,b)     (cmpDoubles((a),(b))==0)    // =>  a==b
#define  CMPDOUBLES_UNEQUAL(a,b)   (cmpDoubles((a),(b))!=0)    // =>  a!=b
#define  CMPDOUBLES_GT(a,b)        (cmpDoubles((a),(b))==-1)   // =>  a>b
#define  CMPDOUBLES_LT(a,b)        (cmpDoubles((a),(b))==1)    // =>  a<b
//#define  CMPDOUBLES_GTEQUAL(a,b)   (cmpDoubles((a),(b))!=1)    // =>  a>=b
//#define  CMPDOUBLES_LTEQUAL(a,b)   (cmpDoubles((a),(b))!=-1)   // =>  a<=b
#define  CMPDOUBLES_GTEQUAL(a,b)   ((cmpDoubles((a),(b))-1)&2) // =>  a>=b
#define  CMPDOUBLES_LTEQUAL(a,b)   (cmpDoubles((a),(b))>=0)    // =>  a<=b
#define  CMPDOUBLES_NAN(a,b)       (cmpDoubles((a),(b))==-2)   // =>  a==NaN || b==NaN


#endif  //INCLUDE_CMPFLOATS_H