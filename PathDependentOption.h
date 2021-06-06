#ifndef PathDependentOption_h
#define PathDependentOption_h

#include <cmath>
#include "Option.h"
#include "BinModel.h"

class PathDependentOption : public Option {
    AllPaths Paths;
public:
    PathDependentOption(BinModel Model_, int N_, AllPaths Paths_) : Option(Model_, N_), Paths(Paths_) {

    }

    double GetPrice() {
        double R = Model.GetR();
        int n = Paths.GetPathsNumber();
        double s = 0;
        for (int i = 0; i < n; ++i) {
            PathInfo curPathInfo = Paths.GetPathInfoByNumber(i);
            double payoff = GetPayoffByPathInfo(Paths.GetPathInfoByNumber(i));
            double probability = Paths.GetPathInfoByNumber(i).GetProbability();
            s += payoff * probability;
        }
        s = s / std::pow(1 + R, N);
        return s;
    }

    virtual double GetPayoffByPathInfo(PathInfo pathInfo) = 0;
};


#endif
