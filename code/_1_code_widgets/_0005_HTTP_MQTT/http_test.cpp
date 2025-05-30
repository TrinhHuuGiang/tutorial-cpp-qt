#include "http_test.h"
#include "ui_http_test.h"

http_test::http_test(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::http_test)
{
    // ui setup
    ui->setupUi(this);

    this->log_to_text_edit("Init http test");

    // other ui
    // button: send_btn, clean_btn
    // lineedit: rq_url, rq_content

    QStringList method_list = {"GET","POST","PATCH","PUT","DELETE"};
    ui->comboBox->addItems(method_list);

    ui->rq_url->setText("http://httpbin.org/get");

    // net work setup
    manager = new QNetworkAccessManager(this);



}

http_test::~http_test()
{
    delete ui;
}

void http_test::log_to_text_edit(const QString &log)
{
    ui->textEdit->moveCursor(QTextCursor::End);
    QString timestamp = QDateTime::currentDateTime().toString("hh:mm:ss");

    ui->textEdit->append(QString("==========")+timestamp+"==========");

    ui->textEdit->append(log);
}

void http_test::on_clean_btn_clicked()
{
    ui->textEdit->setText("");
}


void http_test::on_send_btn_clicked()
{
    QString url = ui->rq_url->text().trimmed();
    QString method = ui->comboBox->currentText();
    QString content = ui->rq_content->text();

    if (url.isEmpty()) {
        log_to_text_edit("URL is empty!");
        return;
    }

    QNetworkRequest request{QUrl(url)};
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json"); // giả sử dùng JSON

    QNetworkReply *reply = nullptr;

    if (method == "GET") {
        reply = manager->get(request);
    } else if (method == "POST") {
        reply = manager->post(request, content.toUtf8());
    } else if (method == "PUT") {
        reply = manager->put(request, content.toUtf8());
    } else if (method == "PATCH") {
        // patch is not exist on Qt, use sendCustomRequest
        reply = manager->sendCustomRequest(request, "PATCH", content.toUtf8());
    } else if (method == "DELETE") {
        // delete is not exist on Qt, use sendCustomRequest
        reply = manager->sendCustomRequest(request, "DELETE", content.toUtf8());
    } else {
        log_to_text_edit("Unsupported HTTP method");
        return;
    }

    if (!reply) {
        log_to_text_edit("Failed to create network request");

        int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        log_to_text_edit("HTTP Status: " + QString::number(statusCode));

        return;
    }

    // emit after done
    connect(reply, &QNetworkReply::finished, this, [=]() {
        reply->deleteLater();

        if (reply->error() != QNetworkReply::NoError) {
            log_to_text_edit("Error: " + reply->errorString());
            return;
        }

        QByteArray response_data = reply->readAll();
        log_to_text_edit("Response (" + reply->url().toString() + "):\n" + QString(response_data));
    });

    log_to_text_edit(method + " request sent to " + url);
}

