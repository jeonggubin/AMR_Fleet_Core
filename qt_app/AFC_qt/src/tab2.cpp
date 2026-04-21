#include "tab2.h"
#include "ui_tab2.h"

Tab2::Tab2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tab2)
{
    ui->setupUi(this);
}

Tab2::~Tab2()
{
    delete ui;
}
