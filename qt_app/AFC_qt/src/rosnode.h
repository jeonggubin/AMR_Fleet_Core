#ifndef ROSNODE_H
#define ROSNODE_H

#include <QThread>
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/int32.hpp>
#include <std_msgs/msg/string.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <sensor_msgs/msg/battery_state.hpp>

class RosNode : public QThread, public rclcpp::Node
{
    Q_OBJECT

public:
    RosNode();
    ~RosNode();

    // ======= [이동 명령] =======
    void move_robot_a(double linear, double angular);  // 터틀봇A 이동
    void move_robot_b(double linear, double angular);  // 터틀봇B 이동

    // ======= [서보 명령] =======
    void publish_servo_a(int angle);  // 터틀봇A 서보
    void publish_servo_b(int angle);  // 터틀봇B 서보

signals:
    // ======= [시그널] =======
    void batteryUpdated(int percentage, double voltage);  // 배터리 상태 업데이트

protected:
    void run() override;  // ROS2 스핀 스레드

private:
    // ======= [Publisher] =======
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_pub_a_;  // 터틀봇A 속도
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_pub_b_;  // 터틀봇B 속도
    rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr      servo_pub_a_;    // 터틀봇A 서보
    rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr      servo_pub_b_;    // 터틀봇B 서보

    // ======= [Subscriber] =======
    rclcpp::Subscription<sensor_msgs::msg::BatteryState>::SharedPtr battery_sub_a_;  // 터틀봇A 배터리
};

#endif // ROSNODE_H