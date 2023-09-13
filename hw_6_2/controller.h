#pragma once

#include <iostream>
#include "counter.h"

class Controller {
public:
    void set_counter(Counter* counter);
    void clear_counter();
    bool process_command(char command);

private:
    Counter* counter;
};