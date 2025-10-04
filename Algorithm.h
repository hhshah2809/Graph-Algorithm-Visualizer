#pragma once
#include "Graph.h"

class Algorithm {
public:
    virtual void run() = 0;
    virtual void displayResult() = 0;
    virtual ~Algorithm() {}
};
