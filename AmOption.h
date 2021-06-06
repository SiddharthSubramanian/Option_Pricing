#ifndef AmOption_h
#define AmOption_h

#include "Option.h"
#include "BinModel.h"

class AmOption : public Option {
public:
    AmOption(BinModel Model_, int N_) : Option(Model_, N_) {
    }

    double GetPrice() {
        return 0.0;
    }
// this class is intentionally left totally empty as it is not a matter of interest in this project
};

#endif
