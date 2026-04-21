#ifndef ROSNODE_H
#define ROSNODE_H

#include <QThread>
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/int32.hpp>
#include <std_msgs/msg/string.hpp>
#include <geometry_msgs/msg/twist.hpp>

class RosNode : public QThread, public rclcpp::Node
{
    Q_OBJECT
public:
    RosNode();
    ~RosNode();

    void publish_servo(int angle);
    void move_robot(double linear, double angular);

protected:
    void run() override;

private:
    rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr servo_pub_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_pub_;
};

#endif // ROSNODE_H