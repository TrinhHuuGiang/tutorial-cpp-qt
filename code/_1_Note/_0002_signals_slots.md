## **Creating Signals and Slots**
In Qt, **signals** are emitted by objects when an event occurs, and **slots** are functions that respond to those signals.

## **Example: Defining a Signal and Slot**
```cpp
#include <QObject>
#include <QDebug>

class MyClass : public QObject {
    Q_OBJECT
public:
    explicit MyClass(QObject *parent = nullptr) : QObject(parent) {}

signals:
    void mySignal(); // Define a signal

public slots:
    void mySlot() { // Define a slot
        qDebug() << "Slot executed!";
    }
};
```

---

## **Connecting Signals and Slots**
To use signals and slots, you need to connect them using `QObject::connect()`.

```cpp
int main() {
    MyClass obj;
    QObject::connect(&obj, &MyClass::mySignal, &obj, &MyClass::mySlot);

    emit obj.mySignal(); // Emitting signal calls the slot
}
```

