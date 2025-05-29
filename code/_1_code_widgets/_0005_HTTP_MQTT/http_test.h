#ifndef HTTP_TEST_H
#define HTTP_TEST_H

#include <QMainWindow>

namespace Ui {
class http_test;
}

class http_test : public QMainWindow
{
    Q_OBJECT

public:
    explicit http_test(QWidget *parent = nullptr);
    ~http_test();

private:
    Ui::http_test *ui;
};

#endif // HTTP_TEST_H
