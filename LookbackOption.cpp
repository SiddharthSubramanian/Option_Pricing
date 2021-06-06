
#include "AllPaths.h"
#include "PathInfo.h"
#include "PathDependentOption.h"
#include "LookbackOption.h"
#include <iostream>
#include <vector>
#include <cmath>


using namespace std;

double LookbackOption::GetPayoffByPathInfo(PathInfo PathInfo) {
    
//    int N = PathInfo.GetPathNumber();
//    double payoff = GetPrice();
    
//    cout << "Lookback Option Start: "<< endl;
    int N = Model.GetN();
    double S0, U, D, R, K;
    S0 = Model.GetS0();
    U = Model.GetU();
    D = Model.GetD();
    R = Model.GetR();
    K = Model.GetK();

    std::vector<double> Prices;
    Prices = PathInfo.GetPrices();
    Prices.insert(Prices.begin(), S0);     //Inserting S0 at the start of every Price vector
    
//    Find the minimum Price(S(t)) and find its difference from most recent Price
    double min_price = *min_element(Prices.begin(), Prices.end());
//    cout << "Minimum Price: "<< min_price << endl;
    
    double LookbackPrice;
    LookbackPrice = max(Prices[N] - min_price , 0.0);
    

    return LookbackPrice;
      
}
        
