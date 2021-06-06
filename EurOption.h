#ifndef EurOption_h
#define EurOption_h

#include "Option.h"
#include "BinModel.h"

class EurOption : public Option {
public:
    EurOption(BinModel Model_, int N_) : Option(Model_, N_) {
    }

    double GetPrice() {
        return 0.0;
    }
// this class is intentionally left totally empty as it is not a matter of interest in this project
};

#endif
