#include "handle_ssm.h"

handle_ssm::handle_ssm(QObject *parent)
    : QObject{parent}
    , ssm(nullptr)
{

    qDebug() << "[Constructed] handle ssm";
}

handle_ssm::~handle_ssm()
{
    // delete ssm
    if(this->ssm)
    {
        qDebug() << "[Deleting] ssm dialog";
        delete ssm;
        ssm = nullptr;
    }

    qDebug() << "[Destructed] handle ssm";
}

int handle_ssm::start_ssm_dialog()
{
    if(!this->ssm)
    {
        this->ssm = new ssm_dialog;

        if(!(this->ssm))
        {
            qDebug() << "[Init failed] ssm dialog - alloc failed";
            return 1;
        }
    }

    // parse scxml to init elements
    if(! (this->ssm->init()) )
    {
        qDebug() << "[Init failed] ssm dialog - init failed";
        return 1;
    }

    // reset to initial state
    this->ssm->start();
    qDebug() << "[Done] ssm dialog - started";


    // connect state to method
    this->connect_state_to_method();

    // start state machine

    return 0;
}

void handle_ssm::connect_state_to_method()
{
    // in/out dialog, dialog_2
    // + if true  -> active state -> init dialog
    // + if false -> inactive     -> ignore
    this->ssm->connectToState("init_dialog", this, SLOT(init_dialog(bool)));
    this->ssm->connectToState("init_dialog_2", this, SLOT(init_dialog_2(bool)));
}

void handle_ssm::init_dialog(bool active)
{
    if(active == false)
    {
        qDebug()<<"[Note] "<< __FUNCTION__ <<" ignore inactive state";
        return;
    }

    // init dialog and pass this pointer
    Dialog* dialog = new Dialog;
    if(! dialog)
    {
        qDebug() << "[ERROR] Dialog create failed";
        emit error_catch();
        return;
    }

    // connect signal of child with this->next state:
    QObject::connect(dialog, SIGNAL(go_to_dialog_2()),this, SLOT(dialog_next_state()));

    // show
    dialog->show();

    // child has to auto call deleteLater()
    // Do not delete child here because if
    // any child event existing in event loop app will be cashed

    // Beleve that child has to auto delete, don't delete it here :)
}

void handle_ssm::dialog_next_state()
{
    // next state is dialog_2
    qDebug() << "[Creating] dialog_2";
    this->ssm->submitEvent("init_dialog_2");
}


void handle_ssm::init_dialog_2(bool active)
{
    if(active == false)
    {
        qDebug()<<"[Note] "<< __FUNCTION__ <<" ignore inactive state";
        return;
    }

    // init dialog and pass this pointer
    Dialog_2* dialog_2 = new Dialog_2;
    if(! dialog_2)
    {
        qDebug() << "[ERROR] Dialog_2 create failed";
        emit error_catch();
        return;
    }

    // connect signal of child with this->next state:
    QObject::connect(dialog_2, SIGNAL(go_to_dialog()),this, SLOT(dialog_2_next_state()));

    // show
    dialog_2->show();

    // child has to auto call deleteLater()
    // Do not delete child here because if
    // any child event existing in event loop app will be cashed
}

void handle_ssm::dialog_2_next_state()
{
    // next state is dialog
    qDebug() << "[Creating] dialog";
    this->ssm->submitEvent("init_dialog");
}

