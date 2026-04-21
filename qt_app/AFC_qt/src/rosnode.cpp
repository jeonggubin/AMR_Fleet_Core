#include "rosnode.h"

RosNode::RosNode() : rclcpp::Node("qt_ros_node")
{
    // 1. QoS 설정: 서보모터는 신뢰성(Reliable), 속도 명령은 일반적인 설정 사용
    auto qos_reliable = rclcpp::QoS(rclcpp::KeepLast(10)).reliable();
    auto qos_vel = rclcpp::QoS(10);

    // 2. Publisher 생성: 토픽명 앞에 '/'를 붙여 전역 네임스페이스 지정
    servo_pub_ = this->create_publisher<std_msgs::msg::Int32>("/servo_angle", qos_reliable);
    cmd_vel_pub_ = this->create_publisher<geometry_msgs::msg::Twist>("/cmd_vel", qos_vel);
}

RosNode::~RosNode()
{
    // 소멸 시 별도 처리가 필요하다면 여기에 작성
}

void RosNode::run()
{
    // ROS 2가 정상 상태일 때만 스피닝 수행
    if (rclcpp::ok()) {
        rclcpp::spin(this->get_node_base_interface());
    }
}

void RosNode::publish_servo(int angle)
{
    if (!rclcpp::ok()) return;

    std_msgs::msg::Int32 msg;
    msg.data = angle;
    servo_pub_->publish(msg);

    // 서보 명령은 드문드문 발생하므로 로그를 남기는 것이 디버깅에 유리함
    RCLCPP_INFO(this->get_logger(), "Servo Command Sent: %d degrees", angle);
}

void RosNode::move_robot(double linear, double angular)
{
    if (!rclcpp::ok()) return;

    geometry_msgs::msg::Twist msg;
    msg.linear.x = linear;   // 전진/후진
    msg.angular.z = angular; // 좌우 회전

    cmd_vel_pub_->publish(msg);

    // [중요] Tab1에서 타이머(10Hz)로 이 함수를 호출할 경우,
    // RCLCPP_INFO가 있으면 터미널이 로그로 도배되어 성능이 저하될 수 있습니다.
    // 확인이 끝났다면 아래 로그는 주석 처리하는 것을 추천합니다.
    // RCLCPP_INFO(this->get_logger(), "Robot Move: Linear=%.2f, Angular=%.2f", linear, angular);
}