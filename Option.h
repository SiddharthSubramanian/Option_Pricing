#ifndef Option_h
#define Option_h

#include "BinModel.h"

class Option {
protected:
    BinModel Model;
    int N;
public:
    Option(BinModel Model_, int N_) {
        Model = Model_;
        N = N_;
    }

    int GetN() { return N; }

    virtual double GetPrice() = 0;
};

#endif
