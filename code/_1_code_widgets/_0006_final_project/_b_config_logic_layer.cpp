/*
    Copyright (C) 2025  Giang Trinh

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/


/* ==========================================================================
 * list object
 *  - label_ic_back
 *  - btn_back
 *
 *  - combox_list_avail
 *
 *  - btn_add_wishlist
 *  - label_ic_add_wishlist
 *
 *  - label_stat_select
 *
 *  - combox_list_order
 *
 *  - label_logic_if_log
 *
 *  - btn_start_cf_ic
 *  - btn_start_cf
========================================================================== */



/* ==========================================================================
 * Definition
========================================================================== */


#include "_b_config_logic_layer.h"
#include "ui__b_config_logic_layer.h"

#define ICON_SVG_BACK ":/icon/rsrc/Icon/feather/arrow-left.svg"
#define ICON_SVG_ADD_WISH ":/icon/rsrc/Icon/feather/thumbs-up.svg"
#define ICON_SVG_START_CF ":/icon/rsrc/Icon/feather/tool.svg"



/* ==========================================================================
 * Class
========================================================================== */
_b_config_logic_layer::_b_config_logic_layer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::_b_config_logic_layer)
    , reconn_count(0)
{
    ui->setupUi(this);
    this->setWindowTitle("Setup logic blocks to board");

    //==========================Inform Config ================
    // set frame functions list ( see example combinations F1)
    ui->frame_cf_lgb->setFrameShape(QFrame::Box);
    ui->frame_cf_lgb->setFrameShadow(QFrame::Sunken);
    ui->frame_cf_lgb->setLineWidth(1);//ptx
    ui->frame_cf_lgb->setMidLineWidth(3);

    // button and label
    // set button/ label back
    {
        QSize btn_back_size = ui->btn_back->size();
        btn_back_size.setWidth(btn_back_size.height()); // square

        ui->btn_back->setStyleSheet(BTN_STYLE_DESIGN);

        ui->label_ic_back->setPixmap(renderSvgToPixmap(ICON_SVG_BACK
                                                       ,btn_back_size));

    }

    // btn_add_wishlist
    // label_ic_add_wishlist
    {
        QSize btn_wishlist_size = ui->btn_add_wishlist->size();
        btn_wishlist_size.setWidth(btn_wishlist_size.height()); // square

        ui->btn_add_wishlist->setStyleSheet(BTN_STYLE_DESIGN);

        ui->label_ic_add_wishlist->setPixmap(renderSvgToPixmap(ICON_SVG_ADD_WISH
                                                               ,btn_wishlist_size));
    }

    // btn_start_cf_ic
    // - btn_start_cf
    {
        QSize btn_start_size = ui->btn_start_cf->size();
        btn_start_size.setWidth(btn_start_size.height()); // square

        ui->btn_start_cf->setStyleSheet(BTN_STYLE_DESIGN);

        ui->btn_start_cf_ic->setPixmap(renderSvgToPixmap(ICON_SVG_START_CF
                                                               ,btn_start_size));
    }

    // groupbox
    ui->groupBox_select->setStyleSheet(GROUPBOX_OUTLINE_DESIGN);
    ui->groupBox_added->setStyleSheet(GROUPBOX_OUTLINE_DESIGN);

    // combox
    ui->combox_list_avail->clear();
    ui->combox_list_order->clear();


    // ==============================http client=================================
    // net work setup
    http_manager = new QNetworkAccessManager(this);

    // start check connection to dev board
    try_connect_to_dev_board();


    qDebug()<<this<<"- created window config logic layer";
}


// destructor
_b_config_logic_layer::~_b_config_logic_layer()
{
    delete ui;

    qDebug()<<this<<"- deleted window config logic layer";
}


// back to menu
void _b_config_logic_layer::on_btn_back_clicked()
{
    // hide this window
    this->hide(); // no continue click, smooth when switch window

    // return menu page

    qDebug() << this << "Returning menu page";

    _1_menuconfig * menu_page = new(std::nothrow) _1_menuconfig(nullptr); // nothow -> return nullptr if fail

    if(menu_page)
    {
        menu_page->show();
        qDebug() << this << "Created menu page";
    }
    else
    {
        qDebug() << this << "Failed when allocate menu_page";
        qDebug() << this << "Force quit app!!!";
        QApplication::quit();
    }

    // safe close by add delete command to last of queue exec loop
    this->deleteLater();
}



// add to wishlist
void _b_config_logic_layer::on_btn_add_wishlist_clicked()
{
    int index = ui->combox_list_avail->currentIndex();

    if(index < 0 || index >= output_list.size())
    {
        ui->label_stat_select->setText("Invalid selection.");
        return;
    }

    lg_info_t selected_block = output_list[index];

    QString full_info = ui->label_stat_select->text(); // backup info board

    if(!check_board_available_before_add_block_to_wishlish())
    {
        // OK -> add to wish list
        wish_list.append(selected_block);
        ui->label_logic_if_log->setText(QString("%1\nAdded [%2] to wishlist")
                                            .arg(full_info,selected_block.lg_desc));
        ui->combox_list_order->addItem(selected_block.lg_desc);
    }
}



// commbox input list index changed
void _b_config_logic_layer::on_combox_list_avail_currentIndexChanged(int index)
{
    if (index < 0 || index >= output_list.size())
        return;

    const auto &block = output_list[index];

    QString info = QString("Board code: [%1]\nInfo: [%2]\n\nSelected logic block:\n- Code: %3\n- Desc: %4\n- Require: %5")
                       .arg(board_info.b_code,
                            board_info.b_desc,
                            block.lg_code,
                            block.lg_desc,
                            block.h_require);

    ui->label_stat_select->setText(info);
}


// commbix order list index changed
void _b_config_logic_layer::on_combox_list_order_currentIndexChanged(int index)
{
    if (index < 0 || index >= wish_list.size())
    {
        ui->label_logic_if_log->setText("No logic block selected.");
        return;
    }

    const auto &block = wish_list[index];

    QString info = QString("Wishlist logic block:\n- Code: %1\n- Desc: %2\n- Require: %3")
                       .arg(block.lg_code,
                            block.lg_desc,
                            block.h_require);

    ui->label_logic_if_log->setText(info);
}






// reconnect to devboard by default ip
void _b_config_logic_layer::try_connect_to_dev_board()
{
    // log
    // ui->label_stat_select->setText("Try connecting ...");
    // qDebug()<<"Try connecting ...";


    // create url to path get board type
    QString url = QString(HTTP_PATH_DEFAULT_DEV_BOARD_URL)
        + HTTP_PATH_GET_DEV_BOARD_TYPE;


    // create request
    QNetworkRequest request{QUrl(url)};
    request.setHeader(QNetworkRequest::ContentTypeHeader,
                      HTTP_MEDIA_TYPE_PLAIN_TEXT); // JSON

    // Create reply
    QNetworkReply *reply = nullptr;

    // GET request
    reply = http_manager->get(request);

    // emit after done
    // Note: in case page delete before emit we should
    //      + reply(this) <- set this is parent
    reply->setParent(this);

    connect(reply, &QNetworkReply::finished, this, [=]()
    {
        // delete reply after use
        reply->deleteLater();

        if (reply->error() != QNetworkReply::NoError) {
            reconn_count++;
            ui->label_stat_select->setText(QString("Connect failed, Retry...[%1]").arg(this->reconn_count));

            QTimer::singleShot(2000,this,SLOT(try_connect_to_dev_board())); // retry each 2 second

            return;
        }

        // update board code
        this->board_info.b_code = reply->readAll();

        // update new data logic block code available for board to combox

    });

}




/*
 * query then feedback in top input QStringList&
 * + clean if list not empty
 * + query table 'link_lcb_with_dev_board'
*/
void _b_config_logic_layer::try_get_list_logic_block_available()
{
    int ret = 0;

    // open database
    if(connectToSQLiteDB(DEV_BOARD_DESIGNED_DB_RSRC_PATH,DEV_BOARD_DESIGNED_DB_LOCAL_PATH,
            DEV_BOARD_DESIGNED_UNIQUE_CONNECT))
    {
        qDebug()<<this<< "Can't connect to database";
        ret = 1;
        qDebug()<<this<<"PAGE WILL DELETE WITH ERROR ["<< ret <<"]";

        this->deleteLater();
        return;
    }



    // get a query to table
    QSqlQuery query(QSqlDatabase::database(DEV_BOARD_DESIGNED_UNIQUE_CONNECT));




    // ====================================== Find board info


    // try find board inform
    query.prepare(QString(
        "SELECT * "
        "FROM \"%1\" "
        "WHERE [code_board] = :code")
                      .arg(DEV_BOARD_DESIGNED_TABLE_DEV_BOARD));

    query.bindValue(":code", this->board_info.b_code);

    if (!query.exec())
    {
        qDebug() << "Query error:" << query.lastError().text();

        // disconnect link to database
        disconnectFromSQLiteDB(DEV_BOARD_DESIGNED_UNIQUE_CONNECT);

        ret = 2;
        qDebug()<<this<<"PAGE WILL DELETE WITH ERROR ["<< ret <<"]";

        this->deleteLater();
        return;
    }
    else
    {
        if (query.next()) // go to query executed, false return if nothing
        {
            QString board_limit_hardware = query.value("hardware_limit").toString();

            // save board info
            this->board_info.b_desc = query.value("descript").toString();
            this->board_info.h_limit= board_limit_hardware;


            // parse JSON to get limit
            QJsonParseError err;
            QJsonDocument doc = QJsonDocument::fromJson(board_limit_hardware.toUtf8(), &err);

            if (!err.error && doc.isObject())
            {
                QJsonObject rootObj = doc.object();
                QStringList limits_str_list;

                for (auto it = rootObj.begin(); it != rootObj.end(); it++) {
                    QString type = it.key();
                    QJsonObject range = it.value().toObject();

                    int s_id = range["s_id"].toInt();
                    int e_id = range["e_id"].toInt();
                    int capacity = e_id - s_id + 1;

                    limits_str_list.append(QString("%1: %2").arg(type, QString::number(capacity)));
                }

                QString full_info = QString("Board code: [%1]\nInfo: [%2]\nRemain:\n%3")
                                        .arg(this->board_info.b_code,
                                             this->board_info.b_desc,
                                             limits_str_list.join(", "));

                ui->label_stat_select->setText(full_info);
            }
            else
            {
                ui->label_stat_select->setText(QString("Board code: [%1]\nInfo: [%2]\nRemain: [JSON parse failed]")
                                                   .arg(this->board_info.b_code, this->board_info.b_desc));
            }
        }
        else // table type not found
        {
            ui->label_stat_select->setText(QString("Board code: [%1]\n"
                                                   "Info: No information found")
                                               .arg(this->board_info.b_code));
        }
    }


    // ====================================== Find logicblock available
    query.clear();

    query.prepare(QString(R"(
query.prepare(R("SELECT "T3".code_logic,"T3".hardware_require,"T3".descript
FROM "designed_dev_board" AS "T1"
INNER JOIN "link_lcb_with_dev_board" AS "T2"
INNER JOIN "logic_code_block" AS "T3"
ON ("T1".[code_board] = "T2".[code_board]) AND ("T2".[code_logic]="T3".[code_logic])
WHERE "T1".[code_board] = 'B0'"));)"));

    if (!query.exec())
    {
        qDebug() << "Query error:" << query.lastError().text();

        // disconnect link to database
        disconnectFromSQLiteDB(DEV_BOARD_DESIGNED_UNIQUE_CONNECT);

        ret = 3;
        qDebug()<<this<<"PAGE WILL DELETE WITH ERROR ["<< ret <<"]";

        this->deleteLater();
        return;
    }

    else
    {
        // clean output list
        output_list.clear();
        qDebug()<<"Lg list clean before append";

        // add query to list
        while(query.next()) // go to query executed, false return if nothing
        {
            // append
            output_list.append({query.value("code_logic").toString(),
                                query.value("descript").toString(),
                                query.value("hardware_require").toString()});
        }

        // update to combox
        int ol_size = output_list.size();

        ui->combox_list_avail->clear();

        for (int i = 0; i < ol_size; i++)
        {
            // add to combox
            ui->combox_list_avail->addItem(output_list[i].lg_desc);
        }

    }

    // disconnect link to database
    disconnectFromSQLiteDB(NET_SERVICE_INFORM_UNIQUE_CONNECT_A_LOGIN_PAGE);
}




/*
 * Check board available before add new logic block
 * - parse JSON of logic block requirement hardware
 * - parse JSON of dev board limit hardware
 * - handle:
 *  + foreach requirement in logicblock, find it exist in devboard
 *      + if not exist -> return -1, logic block unavailabe -> print require hardware name unvailable, print remain hardware
 *      + if exist requirement hardware then check enough slot:
 *          - check slot by child key "s_id" and "e_id" of limit hardware, and child key "n_order" of require hardware:
 *              + remain_slot = e_id - s_id + 1
 *              + check enough:
 *                  + if: remain_after = remain_slot - require <0 -> run out of slots
 *                      + print require hardware number order and [remain_hardware]
 *                  + else:
 *                      + update JSON limit of devboard by: s_id = s_id + require
 *                      + print success add to wishlist, print before, require, remain after
 */
int _b_config_logic_layer::check_board_available_before_add_block_to_wishlish()
{
    // Parse JSON from string
    QJsonParseError err;
    QJsonDocument dev_doc = QJsonDocument::fromJson(board_info.h_limit.toUtf8(), &err);
    if(err.error)
    {
        qDebug()<<"board document init fail";
        return -1;
    }

    QJsonDocument lg_doc = QJsonDocument::fromJson(output_list[ui->combox_list_avail->currentIndex()].h_require.toUtf8(), &err);
    if(err.error)
    {
        qDebug()<<"logic block document init fail";
        return -1;
    }

    QJsonObject dev_obj = dev_doc.object();
    QJsonObject lg_obj = lg_doc.object();

    // Browse all hardware logic block required
    for(auto it = lg_obj.begin(); it != lg_obj.end(); ++it) {
        QString type = it.key();

        if(!dev_obj.contains(type)) {
            qDebug() << "Board missing hardware: " << type;
            return -1;
        }

        int require = it.value().toObject().value("n_order").toInt();
        QJsonObject dev_hw = dev_obj[type].toObject();

        int s_id = dev_hw["s_id"].toInt();
        int e_id = dev_hw["e_id"].toInt();
        int remain = e_id - s_id + 1;

        if(remain < require) {
            qDebug() << "Not enough resourse: " << type << ", need: " << require << ", remain: " << remain;
            return -1;
        }

        // Else update
        dev_hw["s_id"] = s_id + require;
        dev_obj[type] = dev_hw;
    }

    // save new board_info.h_limit
    QJsonDocument new_dev_doc(dev_obj);
    board_info.h_limit = QString::fromUtf8(new_dev_doc.toJson(QJsonDocument::Compact));


    return 0;
}




