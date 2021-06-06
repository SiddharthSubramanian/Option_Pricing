#include <cmath>
#include <iostream>
#include <vector>
#include <chrono>
#include "BinModel.h"
#include "PricePathGenerator.h"
#include "PathDependentOption.h"
#include "AmOption.h"
#include "EurOption.h"
#include "GrowOption.h"
#include "LookbackOption.h"
#include "ParOption.h"
#include "AsianCallPayoffOption.h"

using namespace std::chrono;




//Pricing is done under a binomial model (implemented in class BinModel).
//We have class for path generator (implemented in class PricePathGenerator).
//The most general class is the class of options (Option).
//It has child classes: AmOption, EurOption (with dummy implementation as we are not interested in those)
//  and PathDependentOption.
//PathDependentOption has several subclasses:
//1)    LookbackBack option: a lookback option is a path dependent option where the option owner has the right to buy (sell) the underlying instrument at its lowest (highest) price over some preceding period.
//2)    An AsianCall option with arithmetic average
//3)    ParOption: standard Parisian option: the payoff of a standard Parisian option is
//          dependent on the maximum amount of time the underlying asset value has spent consecutively above or below a strike price.
//4)    GrowOption: an option that pays an amount equal to the duration of the longest period of growth of the underlying asset.



// we need to have something that stores information about AllPathInfo 2^N of paths, we call this class PathsGenerator
// we also want to have a class PathInfo that stores the information about a single path with number x
// The Path/Price/Probability are generated in PathGenerator which gives each vector of path/price/probability by the path number
// later in the path dependent options we will retrieve vector of prices/a path/probability and calculate
// a payoff along a given path and perhaps multiply this payoff by the probability to find an
// average payoff along paths. Which then is discounted and the option price is obtained from PathDependentOption


int main() {

//    auto start = high_resolution_clock::now();
    std::cout << "Welcome to Option Pricing Engine "<< std::endl;
    std::cout << std::endl;
    BinModel Model;
    if (Model.GetInputData() == 1) return 1;
    auto start = high_resolution_clock::now();
    int N = Model.GetN(); // read from input

    // Generate All Paths
    
    PathsGenerator MyPathGen(Model, N);
    
    AllPaths paths = MyPathGen.GenAllPaths();

    // create different flavours of options
    EurOption eurOption(Model, N);
    AmOption amOption(Model, N);
    AsianCallPayoffOption asianOption(Model, N, paths);
    ParOption parOption(Model, N, paths, 10);
    GrowOption growOption(Model, N, paths);
    LookbackOption lookbackOption(Model, N, paths);
    

    // count prices
    std::cout << "Eur Option Price: " << eurOption.GetPrice() << std::endl;
    std::cout << "Am Option Price: " << amOption.GetPrice() << std::endl;
    std::cout << "Asian Option Price: " << asianOption.GetPrice() << std::endl;
    std::cout << "Par Option Price: " << parOption.GetPrice() << std::endl;
    std::cout << "Grow Option Price: " << growOption.GetPrice() << std::endl;
    std::cout << "Lookback Option Price: " << lookbackOption.GetPrice() << std::endl;
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << std::endl;
    std::cout <<  "Total time taken: " << duration.count() << "microseconds"<< std::endl;
    return 0;
}

