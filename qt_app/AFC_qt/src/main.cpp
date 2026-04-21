#include "mainwidget.h"
#include <QApplication>
#include <rclcpp/rclcpp.hpp>

int main(int argc, char *argv[])
{
    // ROS 2 초기화
    rclcpp::init(argc, argv);

    QApplication a(argc, argv);
    MainWidget w;
    w.show();

    int result = a.exec();

    // ROS 2 종료
    rclcpp::shutdown();

    return result;
}