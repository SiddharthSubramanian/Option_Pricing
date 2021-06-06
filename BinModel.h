#ifndef BinModel_h
#define BinModel_h
#include <tuple>

class BinModel
{
   private:
      double S0;
      double U;
      double D;
      double R;
    double K;
    int N;

   public:
      //computing risk-neutral probability
      double RiskNeutProb();

      //computing the stock price at node n,i
      double S(int n, int i);

      //inputting, displaying and checking model data
     double GetInputData();

    double GetR();
    double GetS0();
    double GetD();
    double GetU();
    double GetN();
    double GetK();
      
};

#endif
