#ifndef WINGUFILE_CLIENT_INIT_WINGUFILE_DIALOG_H
#define WINGUFILE_CLIENT_INIT_WINGUFILE_DIALOG_H

#include <QDialog>
#include "ui_init-wingufile-dialog.h"

class InitSeafileDialog : public QDialog,
                          public Ui::InitSeafileDialog
{
    Q_OBJECT

public:
    InitSeafileDialog(QWidget *parent=0);
};

#endif
