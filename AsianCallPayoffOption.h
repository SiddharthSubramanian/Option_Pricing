
#ifndef AsianCallPayoffOption_h
#define AsianCallPayoffOption_h

#include <stdio.h>
#include "AllPaths.h"
#include "PathInfo.h"
#include "PathDependentOption.h"

class AsianCallPayoffOption : public PathDependentOption {
public:
    AsianCallPayoffOption(BinModel Model, int N, AllPaths Paths) : PathDependentOption(Model, N, Paths) {

    }

    double GetPayoffByPathInfo(PathInfo PathInfo);

        //AsianCallPayoffOption: an option that pays an amount equal to the average value of the prices along the path
    
};


#endif /* AsianCallPayoffOption_h */
