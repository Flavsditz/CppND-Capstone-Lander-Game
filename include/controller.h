#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "lander.hpp"

class Controller {
public:
    void HandleInput(bool &running, Lander &lander) const;

};

#endif