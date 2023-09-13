#include "counter.h"

void Counter::increment() {
    ++value;
}

void Counter::decrement() {
    --value;
}

int Counter::get_value() {
    return value;
}