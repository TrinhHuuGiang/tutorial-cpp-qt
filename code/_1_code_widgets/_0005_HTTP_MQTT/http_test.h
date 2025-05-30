#ifndef HTTP_TEST_H
#define HTTP_TEST_H

#include <QMainWindow>

#include <QStringList>

#include <QObject>
#include <QString>
#include <QList>
#include <QDateTime>


#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>

namespace Ui {
class http_test;
}

class http_test : public QMainWindow
{
    Q_OBJECT
private:
    QNetworkAccessManager *manager;

public:
    explicit http_test(QWidget *parent = nullptr);
    ~http_test();

private:
    void log_to_text_edit(const QString &log);

private slots:


    void on_clean_btn_clicked();

    void on_send_btn_clicked();

private:
    Ui::http_test *ui;
};

#endif // HTTP_TEST_H
