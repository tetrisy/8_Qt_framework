#pragma once

#include <QObject>

class Counter : public QObject {
    Q_OBJECT
private:
    int m_count;
public:
    explicit Counter(int startValue, QObject* parent = nullptr) : QObject(parent), m_count(startValue) {}

    int Increment();
    int Decrement();

    int getCount() const noexcept {
        return m_count;
    }

public slots:
    void incrementCounter();
    void decrementCounter();

signals:
    void counterIncremented();
    void counterDecremented();
};
