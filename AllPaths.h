#ifndef AllPaths_h
#define AllPaths_h

#include <vector>
#include "BinModel.h"
#include "PathInfo.h"

class AllPaths {
private:
    std::vector<PathInfo> AllPathInfo;
public:
    AllPaths(std::vector<PathInfo> AllPathInfo_) : AllPathInfo(AllPathInfo_) {};

    PathInfo GetPathInfoByNumber(int number) {
        return AllPathInfo[number];
    }

    int GetPathsNumber() {
        return AllPathInfo.size();
    }
};


#endif
