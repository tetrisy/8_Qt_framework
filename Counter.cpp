#include "Counter.h"

int Counter::Increment() {
    m_count++;
    emit counterIncremented();
    return m_count;
}

int Counter::Decrement() {
    m_count--;
    emit counterDecremented();
    return m_count;
}

void Counter::incrementCounter() {
    m_count++;
}

void Counter::decrementCounter() {
    m_count--;
}