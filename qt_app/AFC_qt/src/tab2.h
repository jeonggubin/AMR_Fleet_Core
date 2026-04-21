#ifndef TAB2_H
#define TAB2_H

#include <QWidget>

namespace Ui {
class Tab2;
}

class Tab2 : public QWidget
{
    Q_OBJECT

public:
    explicit Tab2(QWidget *parent = nullptr);
    ~Tab2();

private:
    Ui::Tab2 *ui;
};

#endif // TAB2_H
