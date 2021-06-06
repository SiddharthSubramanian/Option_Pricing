
#include "AllPaths.h"
#include "PathInfo.h"
#include "PathDependentOption.h"
#include "ParOption.h"
#include <iostream>
#include <vector>
#include<cmath>


using namespace std;

double ParOption::GetPayoffByPathInfo(PathInfo PathInfo) {
    
    
//    cout << "Start of Parisian Option :" << endl;
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

    int count = 0;
    int result = 0;
    
//    Calculating the maximum sequence of periods where Price is consecutively increasing
    for(int i = N; i > -1; i--){
        if(Prices[i] > K){
            count +=1;
        }
        else{
            count = 0;
        }
        result = max(result,count);
//        cout << "0. count value : "<< result << endl;
    }
    return result;
      
}
        
