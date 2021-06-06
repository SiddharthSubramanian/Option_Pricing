
#include "AllPaths.h"
#include "PathInfo.h"
#include "PathDependentOption.h"
#include "GrowOption.h"
#include <iostream>
#include <vector>
#include <cmath>


using namespace std;

double GrowOption::GetPayoffByPathInfo(PathInfo PathInfo) {
    
//    cout << "Start of Growth Option :" << endl;
    int N = Model.GetN();
    double S0, U, D, R;
    S0 = Model.GetS0();
    U = Model.GetU();
    D = Model.GetD();
    R = Model.GetR();

    std::vector<double> Prices;
    Prices = PathInfo.GetPrices();
    Prices.insert(Prices.begin(), S0);


    int diff = 0 ;
    int count = 0;
    int result = 0;
    
//    Calculating the maximum sequence of periods where Price is consecutively increasing
    for(int i = N; i > 0; i--){
        diff = Prices[i] - Prices[i-1];
        if(diff >0){
            count +=1;
        }
        else{
            count = 0;
        }
        result = max(result,count);

    }
    return result;
      
}
        
