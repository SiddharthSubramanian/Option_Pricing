
#include "AllPaths.h"
#include "PathInfo.h"
#include "PathDependentOption.h"
#include "AsianCallPayoffOption.h"
#include <iostream>
#include <vector>
#include <cmath>



using namespace std;


double AsianCallPayoffOption::GetPayoffByPathInfo(PathInfo PathInfo) {
    
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
    double avgPrice;
    double sum =0.0;
    
    for(int i = 0; i< N; i++){
     
        sum += Prices[i];
    }
    avgPrice = sum/N;
//
//    cout << "Prices: "<< endl;
//    for(int i = 0; i< N; i++){
//        cout<< Prices[i] << " ";
//    }
//    cout << endl;
//    cout << "Average Price: "<< avgPrice << endl;
    
    double AsianPrice;
    AsianPrice = max(avgPrice - K , 0.0);
//    cout << "Asian Price: " <<AsianPrice << endl;

    return AsianPrice;
      
}
        
