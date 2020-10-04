 class Random {
public:
   Random(bool pseudo = true);
//    Declare random-number generation methods here.
 
   int random_integer(int low, int high);
   double random_real();
   int poisson(double mean);
 
private:
   int reseed(); //  Re-randomize the seed.
   int seed,
       multiplier, add_on; //  constants for use in arithmetic operations
};
