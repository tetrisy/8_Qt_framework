#include <iostream>
#include "Counter.h"

static void printCounters(const Counter& c1, const Counter& c2) {
    std::cout << "Counter 1: " << c1.getCount() << " | " << "Counter 2: " << c2.getCount() << '\n';
}

int main()
{

    Counter c1(5);
    Counter c2(12);

    QObject::connect(&c1, &Counter::counterIncremented, &c2, &Counter::incrementCounter);
    QObject::connect(&c2, &Counter::counterIncremented, &c1, &Counter::incrementCounter);
    QObject::connect(&c1, &Counter::counterDecremented, &c2, &Counter::decrementCounter);
    QObject::connect(&c2, &Counter::counterDecremented, &c1, &Counter::decrementCounter);

    c1.Increment();
    printCounters(c1, c2);
    c2.Increment();
    printCounters(c1, c2);
    c1.Decrement();
    printCounters(c1, c2);
    c2.Decrement();
    printCounters(c1, c2);

    return 0;
}
