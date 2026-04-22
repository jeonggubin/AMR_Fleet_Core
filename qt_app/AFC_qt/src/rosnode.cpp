#include "rosnode.h"

// ======= [생성자] =======
RosNode::RosNode() : rclcpp::Node("qt_ros_node")
{
    auto qos_reliable = rclcpp::QoS(rclcpp::KeepLast(10)).reliable();
    auto qos_vel      = rclcpp::QoS(10);

    // ======= [Publisher 초기화] =======
    // 터틀봇A
    cmd_vel_pub_a_ = create_publisher<geometry_msgs::msg::Twist>("/tb3_a/cmd_vel", qos_vel);
    servo_pub_a_   = create_publisher<std_msgs::msg::Int32>("/tb3_a/servo_angle", qos_reliable);

    // 터틀봇B
    cmd_vel_pub_b_ = create_publisher<geometry_msgs::msg::Twist>("/tb3_b/cmd_vel", qos_vel);
    servo_pub_b_   = create_publisher<std_msgs::msg::Int32>("/tb3_b/servo_angle", qos_reliable);

    // ======= [Subscriber 초기화] =======
    // 터틀봇A 배터리 상태 구독 → batteryUpdated 시그널 emit
    battery_sub_a_ = create_subscription<sensor_msgs::msg::BatteryState>(
        "/tb3_a/battery_state", 10,
        [this](const sensor_msgs::msg::BatteryState::SharedPtr msg) {
            int percentage = (int)(msg->percentage * 100);
            emit batteryUpdated(percentage, msg->voltage);
        });
}

// ======= [소멸자] =======
RosNode::~RosNode() {}

// ======= [ROS2 스핀 스레드] =======
void RosNode::run() {
    if (rclcpp::ok())
        rclcpp::spin(this->get_node_base_interface());
}

// ======= [이동 명령] =======
void RosNode::move_robot_a(double linear, double angular) {
    if (!rclcpp::ok()) return;
    geometry_msgs::msg::Twist msg;
    msg.linear.x  = linear;
    msg.angular.z = angular;
    cmd_vel_pub_a_->publish(msg);
}

void RosNode::move_robot_b(double linear, double angular) {
    if (!rclcpp::ok()) return;
    geometry_msgs::msg::Twist msg;
    msg.linear.x  = linear;
    msg.angular.z = angular;
    cmd_vel_pub_b_->publish(msg);
}

// ======= [서보 명령] =======
void RosNode::publish_servo_a(int angle) {
    if (!rclcpp::ok()) return;
    std_msgs::msg::Int32 msg;
    msg.data = angle;
    servo_pub_a_->publish(msg);
    RCLCPP_INFO(this->get_logger(), "Servo A Command Sent: %d degrees", angle);
}

void RosNode::publish_servo_b(int angle) {
    if (!rclcpp::ok()) return;
    std_msgs::msg::Int32 msg;
    msg.data = angle;
    servo_pub_b_->publish(msg);
    RCLCPP_INFO(this->get_logger(), "Servo B Command Sent: %d degrees", angle);
}