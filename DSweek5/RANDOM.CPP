#include"RANDOM.H"
#include <limits.h>
#include<iostream>
using namespace std;
const int max_int = INT_MAX;
#include <math.h>
#include <time.h>
 
Random::Random(bool pseudo)
/* 
 
Post: The values of seed, add_on, and multiplier 
are initialized.  The seed is initialized randomly only if
pseudo == false.
 
*/
{
   if (pseudo) seed = 1;
   else seed = time(NULL) % max_int;
   multiplier = 2743;
   add_on = 5923;
}
 
double Random::random_real()
/* 
 
Post: A random real number between 0 and 1 is returned.
 
*/
{
   double max = max_int + 1.0;
   double temp = reseed();
   if (temp < 0) temp = temp + max;
   return temp / max;
}
 
int Random::random_integer(int low, int high)
/* 
 
Post: A random integer between low and high (inclusive)
is returned.
 
*/
{

   if (low > high) return random_integer(high, low);
   else return ((int) ((high - low + 1) * random_real())) + low;
}
 
int Random::poisson(double mean)
/* 
 
Post:
A random integer, reflecting a Poisson distribution
with parameter mean, is returned.
 
*/
{
   double limit = exp(-mean);
   double product = random_real();
   int count = 0;
   while (product > limit) {
      count++;
      product *= random_real();
   }
   return count;
}
 
int Random::reseed()
/* 
 
Post:
The seed is replaced by a psuedorandom successor.
 
*/
{
   seed = seed * multiplier + add_on;
   return seed;
}
