#pragma once

class Counter {
public:
    Counter() {};
    Counter(int init_value) :value(init_value) {};

    void increment();
    void decrement();
    int get_value();

private:
    int value = 1;
};