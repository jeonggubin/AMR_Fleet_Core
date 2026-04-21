#include "tab1.h"
#include "ui_tab1.h"
#include <QDebug>
#include <QTimer>

Tab1::Tab1(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Tab1)
    , currentLinear(0.0)
    , currentAngular(0.0)
{
    ui->setupUi(this);

    connect(ui->cbDest, &QComboBox::currentTextChanged, this, &Tab1::on_cbDest_currentTextChanged);

    cmdTimer = new QTimer(this);
    connect(cmdTimer, &QTimer::timeout, this, &Tab1::sendVelocityCommand);
    cmdTimer->start(100);
}

Tab1::~Tab1() { delete ui; }

void Tab1::setRosNode(RosNode* node) { pRosNode = node; }

// 타이머에 의해 0.1초마다 반복 호출됨
void Tab1::sendVelocityCommand()
{
    if (!pRosNode) return;

    // UI의 수동조작 체크박스가 체크되어 있을 때만 명령 전송
    if (ui->checkBox->isChecked()) {
        pRosNode->move_robot(currentLinear, currentAngular);
    } else {
        // 체크 해제 시 안전을 위해 속도 초기화 및 정지 명령 1회 전송
        if (currentLinear != 0.0 || currentAngular != 0.0) {
            currentLinear = 0.0;
            currentAngular = 0.0;
            pRosNode->move_robot(0.0, 0.0);
        }
    }
}

// 방향 버튼들은 "목표 속도"만 설정함
void Tab1::on_pPBForward_clicked() {
    currentLinear = 0.15; currentAngular = 0.0;
}

void Tab1::on_pPBBackward_clicked() {
    currentLinear = -0.15; currentAngular = 0.0;
}

void Tab1::on_pPBLeft_clicked() {
    currentLinear = 0.0; currentAngular = 0.5;
}

void Tab1::on_pPBRight_clicked() {
    currentLinear = 0.0; currentAngular = -0.5;
}

void Tab1::on_pPBStop_clicked() {
    currentLinear = 0.0; currentAngular = 0.0;
}

void Tab1::on_pPBServo0_clicked() {
    if(pRosNode) pRosNode->publish_servo(0);
}

void Tab1::on_pPBServo30_clicked() {
    if(pRosNode) pRosNode->publish_servo(30);
}

void Tab1::updateBatteryStatus(int percentage, double voltage) {
    ui->barBattery->setValue(percentage);
    ui->lblVoltageValue->setText(QString::number(voltage, 'f', 1) + " V");
}


void Tab1::on_btnStart_clicked()
{
    QString robot = ui->cbRobot->currentText();
    QString goal = ui->cbDest->currentText();
    QString item = ui->cbItem->currentText();
    QString count = ui->cbCount->currentText();

    // 잘 가져왔는지 디버그 출력으로 확인 (터미널에 뜸)
    qDebug() << "명령 수신: " << robot << " 가 " << goal << " 로 이동합니다.";
    bool isNoItemLocation = (goal == "상차장" || goal == "충전소 A" || goal == "충전소 B");

    if (!isNoItemLocation) {
        qDebug() << "운반 물품: " << item << " 개수: " << count;
    }
}
    // 3. 여기서 이제 ROS 노드에게 명령을 전달하는 코드를 작성하게 됩니다.
    // 예: pRosNode->sendGoal(goal);


// 2. 목적지에 따른 물품/개수창 제어 로직 구현
void Tab1::on_cbDest_currentTextChanged(const QString &text)
{
    // "상차장"이 선택되었을 때
    if (text == "상차장") {
        // 물품과 개수를 자동으로 "N/A" 또는 "0"으로 세팅 (이미 리스트에 있어야 함)
        // 만약 리스트에 없다면 addItem으로 추가하거나 빈 칸으로 만듭니다.
        ui->cbItem->setCurrentText("-");
        ui->cbCount->setCurrentText("0");

        // 입력 불가능하게 비활성화
        ui->cbItem->setEnabled(false);
        ui->cbCount->setEnabled(false);

        // 시각적으로 구분하게
        ui->cbItem->setStyleSheet("background-color: #2d2d2d; color: #777777;");
        ui->cbCount->setStyleSheet("background-color: #2d2d2d; color: #777777;");
    }
    // 하역장 등 다른 목적지일 때 다시 활성화
    else {
        ui->cbItem->setEnabled(true);
        ui->cbCount->setEnabled(true);

        // 스타일 시트 초기화 및 텍스트 초기화
        ui->cbItem->setStyleSheet("");
        ui->cbCount->setStyleSheet("");
    }
}

