#include "cmpfloats.h"




/* valeur absolue d'un entier de 32 ou 64 bits */
uint32_t abs32(int32_t x) {   return x<0? -x : x;   }
uint64_t abs64(int64_t x) {   return x<0? -x : x;   }




int floatsAreEqual(float a, float b) {
   
   /* vérification pour NaN : si l'un des deux nombres est NaN, alors on
      retourne toujours faux */
   if(isnan(a) || isnan(b))
      return 0;
   
   /* vérification pour les infinis : si l'un des deux nombres est infini,
      alors on ne retourne vrai que si les deux nombres sont strictement
      égaux (tous les deux +inf ou -inf) */
   if(isinf(a) || isinf(b))
      return a==b;
   
   int32_t aInt= INTREPOFFLOAT(a);
   int32_t bInt= INTREPOFFLOAT(b);
   if(aInt<0)   aInt= 0x80000000 - aInt;
   if(bInt<0)   bInt= 0x80000000 - bInt;
   return abs32( aInt - bInt )  <=  MAXULPSFLOAT;
}

int doublesAreEqual(double a, double b) {
   if(isnan(a) || isnan(b))
      return 0;
   
   if(isinf(a) || isinf(b))
      return a==b;
   
   int64_t aInt= INTREPOFDOUBLE(a);
   int64_t bInt= INTREPOFDOUBLE(b);
   if(aInt<0)   aInt= 0x8000000000000000LL - aInt;
   if(bInt<0)   bInt= 0x8000000000000000LL - bInt;
   return abs64( aInt - bInt )  <=  MAXULPSDOUBLE;
}




int cmpFloats(float a, float b) {
   if(isnan(a) || isnan(b))
      return -2;   // -2 si on a au moins un NaN
   
   if(isinf(a) || isinf(b))
      return (a<b)? -1 : (a>b)? 1 : 0;   // gestion des infinis similaire à ci-dessous
   
   int32_t aInt= INTREPOFFLOAT(a);
   int32_t bInt= INTREPOFFLOAT(b);
   if(aInt<0)   aInt= 0x80000000 - aInt;
   if(bInt<0)   bInt= 0x80000000 - bInt;
   return (abs32(aInt-bInt) <= MAXULPSFLOAT)?  0   // 0 si les nombres sont égaux
                               : (aInt<bInt)?  1   // 1 si a<b
                               :              -1;  // -1 si a>b
}

int cmpDoubles(double a, double b) {
   if(isnan(a) || isnan(b))
      return -2;
   
   if(isinf(a) || isinf(b))
      return (a<b)? -1 : (a>b)? 1 : 0;
   
   int64_t aInt= INTREPOFDOUBLE(a);
   int64_t bInt= INTREPOFDOUBLE(b);
   if(aInt<0)   aInt= 0x8000000000000000LL - aInt;
   if(bInt<0)   bInt= 0x8000000000000000LL - bInt;
   return (abs64(aInt-bInt) <= MAXULPSDOUBLE)?  0
                                : (aInt<bInt)?  1
                                :              -1;
}
