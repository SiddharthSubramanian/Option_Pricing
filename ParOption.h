#ifndef ParOption_h
#define ParOption_h

#include "BinModel.h"
#include "PathInfo.h"
#include "AllPaths.h"
#include "PathDependentOption.h"

class ParOption : public PathDependentOption {
    double StrikePrice;
public:
    ParOption(BinModel Model, int N, AllPaths Paths, double StrikePrice_) :
            PathDependentOption(Model, N, Paths),
            StrikePrice(StrikePrice_) {}

    double GetPayoffByPathInfo(PathInfo PathInfo);
//    {
//     ParOption: standard Parisian option: the payoff of a standard Parisian option is
//     dependent on the maximum amount of time the underlying asset value has spent consecutively above or below a strike price.

//        return 0.0;
//    }
};

#endif
