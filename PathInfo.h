#ifndef PathInfo_h
#define PathInfo_h

#include <vector>
#include "BinModel.h"

class PathInfo {
private:
    int PathNumber;
    std::vector<int> Path;
    std::vector<double> Prices;
    double Probability;
public:
    PathInfo(int PathNumber_, std::vector<int> Path_, std::vector<double> Prices_, double Probability_) :
            PathNumber(PathNumber_), Path(Path_), Prices(Prices_), Probability(Probability_) {};

    int GetPathNumber() {
        return PathNumber;
    }

    double GetProbability() {
        return Probability;
    }

    std::vector<int> GetPath() {
        return Path;
    }

    std::vector<double> GetPrices() {
        return Prices;
    }
};

#endif
