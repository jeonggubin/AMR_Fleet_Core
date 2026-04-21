#ifndef TAB1_H
#define TAB1_H

#include <QWidget>
#include "rosnode.h"

namespace Ui {
class Tab1;
}

class Tab1 : public QWidget
{
    Q_OBJECT

public:
    explicit Tab1(QWidget *parent = nullptr);
    ~Tab1();

    void setRosNode(RosNode* node);

private slots:
    void sendVelocityCommand();

    void on_pPBServo0_clicked();

    void on_pPBServo30_clicked();

    void on_pPBForward_clicked();

    void on_pPBBackward_clicked();

    void on_pPBLeft_clicked();

    void on_pPBRight_clicked();

    void on_pPBStop_clicked();

    void on_btnStart_clicked();

    void updateBatteryStatus(int percentage, double voltage);

    void on_cbDest_currentTextChanged(const QString &text);


private:
    Ui::Tab1 *ui;
    RosNode *pRosNode;

    QTimer *cmdTimer;     // 10Hz 발행용 타이머
    double currentLinear;  // 현재 목표 선속도
    double currentAngular; // 현재 목표 각속도
};

#endif // TAB1_H
