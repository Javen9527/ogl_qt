#pragma once

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class OglWindow; }
QT_END_NAMESPACE

class OglWindow : public QDialog
{
    Q_OBJECT

public:
    OglWindow(QWidget *parent = nullptr);
    ~OglWindow();

private:
    Ui::OglWindow *ui;
};

