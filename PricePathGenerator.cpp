
#include <vector>
#include "BinModel.h"
#include "PathInfo.h"
#include "AllPaths.h"
#include "PricePathGenerator.h"
#include <iostream>
#include <cmath>
using namespace std;

    
std::vector<int> PathsGenerator::GenPathByNumber(int x)
{
    //This function takes the number x and converts it into binary.
    //It then stores the individual binary digits as consecutive elements in the array Path.
    //If every x from 0 to (2^N)-1 is input into this function in turn, it will
    //return every possible array with different combinations of 0s and 1s of length N.
    
    
    int* temp_Path;
    temp_Path = new int[N]{0};
    
    for(int i=0; x>0; i++) {
        temp_Path[i] = x%2;
        x=x/2;
    }

    std::vector<int> Path;
    for(int i = 0; i <N; i++){
        Path.push_back(temp_Path[i]);
    }
    
    delete [] temp_Path;
    return Path;
}




std::vector<double> PathsGenerator::GenPricesByPath(std::vector<int> Path) {
    //So 0 in the path corresponds to a growth of the underlying asset and 1
    //in the path corresponds to the underlying asset falling.
//    GenPricesByPath(Path);
    double temp_Prices[N];
    double S0;
    double U;
    double D;
    double R;
    S0 = Model.GetS0();
    U = Model.GetU();
    D = Model.GetD();
    R = Model.GetR();
    for(int i=0; i<N; i++) {
        int number = Path[i]; //selecting the element of the array path
        if (i == 0) { //the section of code in this if statement is only executed
        //for the 0th element of the array path
            if (number == 0){
                temp_Prices[i] = S0*(1+U); //setting the 0th element of the array Prices as S0*(1+U)
        //if the 0th element of the array Path is 0, as 0 in the path indicates a growth
        //in the underlying asset.
                continue;
            }
            else {
                temp_Prices[i] = S0*(1+D); //setting the 0th element of the array Prices as S0*(1+D)
        //if the 0th element of the array Path is 1, as 1 in the path indicates a fall
        //in the underlying asset.
                continue;
            }
        }
        //calculating the prices corresponding to the remaining N-1 elements in the path:
        if (number == 0){
            temp_Prices[i] = temp_Prices[i-1]*(1+U);
            continue;
        }
        else {
            temp_Prices[i] = temp_Prices[i-1]*(1+D);
            continue;
        }
    }
    
    std::vector<double> Prices;
    for(int i = 0; i<N; i++){
        Prices.push_back(temp_Prices[i]);
    }
    
//    GenPricesByPath(Path) = Prices;
//    delete temp_Prices;
    return Prices;
}



double PathsGenerator::GenProbabilityByPath(std::vector<int> Path) {
    int zeronum = 0;
//    GenProbabilityByPath(Path);
    for (int i=0; i<N; i++) { //for loop to count the number of 0s in the array Path
        int num = Path[i];
        if (num == 0) zeronum = zeronum+1;
        else continue; //if an entry in the path equals 1 then the for loop continues
        //onto the next iteration
    }
    int onenum = N-zeronum; //the number of 1s in the path is the length of the path (N) minus the
    //number of 0s in the path
    double R;
    double U;
    double D;
    R = Model.GetR();
    D = Model.GetD();
    U = Model.GetU();
    double q = (R-D)/(U-D); //Sets the risk neutral probability as q. The
    //risk neutral probability is calculated in the function RiskNeutProb which is defined in
    //BinModel.cpp
//    GenProbabilityByPath(Path) = pow(q, zeronum)*pow(1-q, onenum);
    return pow(q, zeronum)*pow(1-q, onenum);
}


