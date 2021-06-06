
#ifndef GrowOption_h
#define GrowOption_h

#include "AllPaths.h"
#include "PathInfo.h"
#include "PathDependentOption.h"

class GrowOption : public PathDependentOption {
public:
    GrowOption(BinModel Model, int N, AllPaths Paths) : PathDependentOption(Model, N, Paths) {

    }

    double GetPayoffByPathInfo(PathInfo PathInfo);
//    {
        //GrowOption: an option that pays an amount equal to the duration
        // of the longest period of consecutive growth of the underlying asset.
//        return 0.0;
//    }
//    double GetPrice();
    
};


#endif
