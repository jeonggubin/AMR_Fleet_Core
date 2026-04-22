#include "tab1.h"
#include "ui_tab1.h"
#include <QDebug>

Tab1::Tab1(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Tab1)
    , currentLinear(0.0)
    , currentAngular(0.0)
{
    ui->setupUi(this);
    cmdTimer = new QTimer(this);
    connect(cmdTimer, &QTimer::timeout, this, &Tab1::sendVelocityCommand);
    cmdTimer->start(100);

    // 터틀봇 초기 설정
    robot_a_.id = 1; robot_a_.priority = 1; robot_a_.currentPos = {7, 4};
    robot_b_.id = 2; robot_b_.priority = 2; robot_b_.currentPos = {7, 6};
}

Tab1::~Tab1() { delete ui; }

void Tab1::setRosNode(RosNode* node) {
    pRosNode = node;
}

void Tab1::updateBatteryStatus(int percentage, double voltage) {
    ui->barBattery->setValue(percentage);
    ui->lblVoltageValue->setText(QString("VOLTAGE: %1V").arg(voltage, 0, 'f', 2));
}

void Tab1::stopRobot() {
    if (!pRosNode) return;
    if (selectedRobot_ == 1) pRosNode->move_robot_a(0.0, 0.0);
    else if (selectedRobot_ == 2) pRosNode->move_robot_b(0.0, 0.0);
}

void Tab1::startMove(bool reverse) {
    reverse_   = reverse;
    moveTick_  = 0;
    gridState_ = GridState::MOVING;
    qDebug() << "[이동 시작]" << (reverse ? "후진" : "전진");
}

void Tab1::startTurn(int dir) {
    turnDir_   = dir;
    turnTick_  = 0;
    gridState_ = GridState::TURNING;
    qDebug() << "[회전 시작]" << (dir == 1 ? "좌회전" : "우회전");
}

void Tab1::sendVelocityCommand() {
    if (gridState_ == GridState::MOVING) {
        moveTick_++;
        if (moveTick_ >= MOVE_TICKS) {
            stopRobot();
            gridState_ = GridState::IDLE;
            moveTick_  = 0;
            qDebug() << "[이동 완료]";

            if (isAutoRunning_) {
                Robot& r = (selectedRobot_ == 1) ? robot_a_ : robot_b_;
                r.pathIndex++;
                r.currentPos = r.path[r.pathIndex];

                vector<Robot> robots = {robot_a_, robot_b_};
                simulateStep(robots);
                robot_a_ = robots[0];
                robot_b_ = robots[1];
                // isSlave 처리
                Robot& other = (selectedRobot_ == 1) ? robot_b_ : robot_a_;
                if (r.blockedCnt >= 3 && other.blockedCnt >= 3 && other.priority < r.priority) {
                    qDebug() << "[Slave] Robot" << r.id << "→ 대피소 이동";
                    vector<Point> shelterPath = findValidShelterPath(r.currentPos, shelters, world_map);
                    if (!shelterPath.empty()) {
                        r.path       = shelterPath;
                        r.pathIndex  = 0;
                        r.isWaiting  = true;
                        r.blockedCnt = 0;
                    }
                }
                nextStep(r);
            }
        } else {
            if (pRosNode) {
                if (selectedRobot_ == 1)
                    pRosNode->move_robot_a(reverse_ ? -0.05 : 0.05, 0.0);
                else if (selectedRobot_ == 2)
                    pRosNode->move_robot_b(reverse_ ? -0.05 : 0.05, 0.0);
            }
        }
        return;
    }

    if (gridState_ == GridState::TURNING) {
        turnTick_++;
        int targetTicks = (turnDir_ == 1) ? TURN_TICKS_LEFT : TURN_TICKS_RIGHT;

        if (turnTick_ >= targetTicks) {
            stopRobot();
            gridState_ = GridState::IDLE;
            turnTick_  = 0;

            if (turnDir_ == 1) {
                switch (currentDir_) {
                case Direction::EAST:  currentDir_ = Direction::NORTH; break;
                case Direction::NORTH: currentDir_ = Direction::WEST;  break;
                case Direction::WEST:  currentDir_ = Direction::SOUTH; break;
                case Direction::SOUTH: currentDir_ = Direction::EAST;  break;
                }
            } else {
                switch (currentDir_) {
                case Direction::EAST:  currentDir_ = Direction::SOUTH; break;
                case Direction::SOUTH: currentDir_ = Direction::WEST;  break;
                case Direction::WEST:  currentDir_ = Direction::NORTH; break;
                case Direction::NORTH: currentDir_ = Direction::EAST;  break;
                }
            }
            qDebug() << "[회전 완료] 현재 방향:"
                     << QString::fromStdString(directionToString(currentDir_));

            if (isAutoRunning_) startMove(false);
        } else {
            if (pRosNode) {
                if (selectedRobot_ == 1)
                    pRosNode->move_robot_a(0.0, turnDir_ * 0.3);
                else if (selectedRobot_ == 2)
                    pRosNode->move_robot_b(0.0, turnDir_ * 0.3);
            }
        }
        return;
    }

    // 수동 조작
    if (!pRosNode) return;
    if (ui->checkBox->isChecked()) {
        if (selectedRobot_ == 1)      pRosNode->move_robot_a(currentLinear, currentAngular);
        else if (selectedRobot_ == 2) pRosNode->move_robot_b(currentLinear, currentAngular);
    } else {
        if (currentLinear != 0.0 || currentAngular != 0.0) {
            currentLinear  = 0.0;
            currentAngular = 0.0;
            stopRobot();
        }
    }
}

void Tab1::nextStep(Robot& r) {
    if (r.pathIndex + 1 >= (int)r.path.size()) {
        isAutoRunning_ = false;
        stopRobot();
        qDebug() << "[자율주행 완료] 최종 셀:" << r.currentPos.x << r.currentPos.y;
        return;
    }

    Point from = r.path[r.pathIndex];
    Point to   = r.path[r.pathIndex + 1];

    Direction targetDir = getDirectionTo(from, to);
    int turn = getTurnAction(currentDir_, targetDir);

    qDebug() << "[nextStep] 현재 셀:" << from.x << from.y
             << "→ 다음 셀:" << to.x << to.y;
    qDebug() << "[nextStep] 현재 방향:"
             << QString::fromStdString(directionToString(currentDir_))
             << "→ 목표 방향:"
             << QString::fromStdString(directionToString(targetDir));

    if      (turn ==  0) { qDebug() << "직진";   startMove(false); }
    else if (turn ==  1) { qDebug() << "좌회전"; startTurn(1);     }
    else if (turn == -1) { qDebug() << "우회전"; startTurn(-1);    }
    else                 { qDebug() << "180도";  startTurn(1);     }
}

Point Tab1::getGoalFromDest(const QString& dest) {
    if (dest == "하역장X") return {3, 0};
    if (dest == "하역장Y") return {5, 0};
    if (dest == "하역장Z") return {7, 0};
    if (dest == "상차장")  return {0, 6};
    if (dest == "충전소A") return {7, 4};
    if (dest == "충전소B") return {7, 6};
    return {0, 0};
}

void Tab1::startAutoNav(Point goal) {
    Robot& r = (selectedRobot_ == 1) ? robot_a_ : robot_b_;
    r.finalGoal = goal;
    r.path      = findPath(r.currentPos, goal, world_map);
    r.pathIndex = 0;

    qDebug() << "[자율주행] 시작:" << r.currentPos.x << r.currentPos.y;
    qDebug() << "[자율주행] 목표:" << goal.x << goal.y;
    qDebug() << "[자율주행] 경로 길이:" << r.path.size();

    if (r.path.empty()) {
        qDebug() << "[자율주행] 경로 없음";
        return;
    }

    isAutoRunning_ = true;
    nextStep(r);
}

void Tab1::on_btnStart_clicked() {
    // 로봇 선택
    QString robot = ui->cbRobot->currentText();
    selectedRobot_ = (robot == "터틀봇A") ? 1 : 2;

    // 시작 방향 설정
    currentDir_ = Direction::WEST;

    // 목적지 가져오기
    QString dest = ui->cbDest->currentText();
    Point goal = getGoalFromDest(dest);

    qDebug() << "[START]" << robot << "→" << dest;
    startAutoNav(goal);
}

void Tab1::on_cbDest_currentTextChanged(const QString &text) {
    qDebug() << "[목적지 변경]" << text;
}

// 수동 버튼
void Tab1::on_pPBForward_clicked()  { isAutoRunning_ = false; startMove(false); }
void Tab1::on_pPBBackward_clicked() { isAutoRunning_ = false; startMove(true);  }
void Tab1::on_pPBLeft_clicked()     { isAutoRunning_ = false; startTurn(1);     }
void Tab1::on_pPBRight_clicked()    { isAutoRunning_ = false; startTurn(-1);    }
void Tab1::on_pPBStop_clicked() {
    isAutoRunning_ = false;
    gridState_     = GridState::IDLE;
    stopRobot();
}

void Tab1::on_pPBServo0_clicked()  { if (pRosNode) pRosNode->publish_servo_a(0);  }
void Tab1::on_pPBServo30_clicked() { if (pRosNode) pRosNode->publish_servo_a(30); }