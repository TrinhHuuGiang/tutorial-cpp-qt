#ifndef HANDLE_SSM_H
#define HANDLE_SSM_H

#include <QObject>
#include <QDebug>

#include <stdint.h>

// state machine
#include "ssm_dialog.h"

// dialog
#include "dialog.h"
#include "dialog_2.h"


class handle_ssm : public QObject
{
    Q_OBJECT
private:
    ssm_dialog* ssm;

public:
    explicit handle_ssm(QObject *parent = nullptr);
    virtual ~handle_ssm();
    int start_ssm_dialog();

private:
    void connect_state_to_method();

signals:
    void error_catch(); // link emit with main exec.quit()

private slots:
    void init_dialog(bool active);
    void dialog_next_state();
    void init_dialog_2(bool active);
    void dialog_2_next_state();
};

#endif // HANDLE_SSM_H
