#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <QVBoxLayout>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);

    // 1. ROS 2 스레드 생성 및 시작
    m_rosNode = new RosNode();
    m_rosNode->start();

    // 2. Tab1 객체 생성 및 ROS 노드 주입
    m_tab1 = new Tab1(this);
    m_tab1->setRosNode(m_rosNode);

    // 3. Qt Designer에서 만든 빈 pTab1 영역에 m_tab1 위젯을 꽉 차게 삽입
    QVBoxLayout *tab1Layout = new QVBoxLayout(ui->pTab1);
    tab1Layout->addWidget(m_tab1);
    ui->pTab1->setLayout(tab1Layout);
}

MainWidget::~MainWidget()
{
    // 앱 종료 시 ROS 2 스레드 안전하게 종료
    if (m_rosNode) {
        rclcpp::shutdown();
        m_rosNode->quit();
        m_rosNode->wait();
        delete m_rosNode;
    }
    delete ui;
}