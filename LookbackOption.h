

#ifndef LookbackOption_h
#define LookbackOption_h

#include "AllPaths.h"
#include "PathInfo.h"
#include "PathDependentOption.h"

class LookbackOption : public PathDependentOption {
public:
    LookbackOption(BinModel Model, int N, AllPaths Paths) : PathDependentOption(Model, N, Paths) {

    }

    double GetPayoffByPathInfo(PathInfo PathInfo);

        //LookbackOption: an option that pays an amount equal to the difference of the latest price with the minimum price along the path
    
};


#endif

