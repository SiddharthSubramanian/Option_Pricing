
#ifndef PricePathGenerator_h
#define PricePathGenerator_h
#pragma once
#include <vector>
#include "BinModel.h"
#include "PathInfo.h"
#include "AllPaths.h"


class PathsGenerator {
private:
    int N;
    BinModel Model;
public:
    PathsGenerator(BinModel Model_, int N_) : Model(Model_), N(N_) {
        // set N paths

    }
    
//    Following were private functions but since we need to access the results in different cpp files, hence converted them to public
    
    std::vector<int> GenPathByNumber(int i);

    std::vector<double> GenPricesByPath(std::vector<int> Path);

    double GenProbabilityByPath(std::vector<int> Path);

    PathInfo GenPathInfoByNumber(int i) {
        std::vector<int> Path = GenPathByNumber(i);
        std::vector<double> Prices = GenPricesByPath(Path);
        double Probability = GenProbabilityByPath(Path);
        return PathInfo(i, Path, Prices, Probability);
            };
    
    
    AllPaths GenAllPaths() {
        std::vector<PathInfo> allPaths;
        // generate AllPathInfo prices;
        int numPaths = 1 << N; // 2 ^ 0 = 1 (0001), 2 ^ 1 = 2 (0010), 2 ^ 2 = 4 (0100)
        for (int i = 0; i < numPaths; ++i) {
            allPaths.push_back(GenPathInfoByNumber(i));
        }
        return AllPaths(allPaths);
    }
};

#endif
