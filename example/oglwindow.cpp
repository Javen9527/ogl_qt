#include "oglwindow.h"
#include "ui_oglwindow.h"

OglWindow::OglWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::OglWindow)
{
    ui->setupUi(this);
}

OglWindow::~OglWindow()
{
    delete ui;
}

