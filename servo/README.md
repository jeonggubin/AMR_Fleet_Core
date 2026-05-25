# TurtleBot3 Servo Motor Control

## 📂 파일 구조

```
servo/
├── arduino/
│   └── turtlebot3.cpp
├── raspberry_pi/
│   ├── turtlebot3.hpp
│   ├── turtlebot3.cpp
│   └── CMakeLists.txt
├── image.png
└── README.md
```

---

## 🔧 하드웨어 연결

| 서보 선 | 연결 위치 |
|---|---|
| 노란선 (신호) | OpenCR D9 |
| 빨간선 (VCC) | OpenCR 5V |
| 검정선 (GND) | OpenCR GND |

---

## ⚙️ 환경 설정

### 1. Arduino IDE 설치

[Arduino IDE 공식 사이트](https://www.arduino.cc/en/software)에서 다운로드 후 설치

### 2. OpenCR 보드 설치

Arduino IDE 실행 후:

```
파일 → 기본 설정 → 추가 보드 매니저 URLs에 아래 주소 입력
```

```
https://raw.githubusercontent.com/ROBOTIS-GIT/OpenCR/master/arduino/opencr_release/package_opencr_index.json
```

```
툴 → 보드 → 보드 매니저 → OpenCR 검색 → 설치
```

### 3. Dynamixel2Arduino 라이브러리 설정

`Documents\Arduino\libraries\` 경로에 `Dynamixel2Arduino` 폴더가 있으면 이름을 변경해야 합니다.

```
Dynamixel2Arduino → Dynamixel2Arduino_backup
```

> OpenCR 내장 라이브러리와 충돌하여 `CONTROL_ITEM_MAX` 가 64로 제한되기 때문입니다.

### 4. 아두이노 파일 적용

아래 경로의 파일을 이 저장소의 `arduino/turtlebot3.cpp` 로 교체합니다.

```
C:\Users\{Windows 계정}\AppData\Local\Arduino15\packages\OpenCR\hardware\OpenCR\1.5.3\libraries\turtlebot3_ros2\src\turtlebot3\turtlebot3.cpp
```

### 5. 아두이노 업로드

```
툴 → 보드 → OpenCR Board 선택
툴 → 포트 → OpenCR COM 포트 선택
Ctrl+U → 업로드
업로드 완료 후 멜로디 소리 확인
```

---

## 🛠 라즈베리파이4 파일 적용 및 빌드

아래 경로의 파일들을 이 저장소의 `raspberry_pi/` 파일로 교체합니다.

```
~/turtlebot3_ws/src/turtlebot3/turtlebot3_node/include/turtlebot3_node/turtlebot3.hpp
~/turtlebot3_ws/src/turtlebot3/turtlebot3_node/src/turtlebot3.cpp
~/turtlebot3_ws/src/turtlebot3/turtlebot3_node/CMakeLists.txt
```

빌드:

```bash
cd ~/turtlebot3_ws
colcon build --packages-select turtlebot3_node
source install/local_setup.bash
```

---

## 🚀 실행

### 1. 브링업 (라즈베리파이4)

```bash
export LDS_MODEL=LDS-02        # LDS-01 사용 시 LDS-01 으로 변경
sudo chmod 666 /dev/ttyACM0
ROS_DOMAIN_ID=4 ros2 launch turtlebot3_bringup robot.launch.py namespace:=tb3_a
```

> 포트가 `ttyACM1` 로 잡힐 경우:
> ```bash
> sudo chmod 666 /dev/ttyACM1
> ROS_DOMAIN_ID=4 ros2 launch turtlebot3_bringup robot.launch.py namespace:=tb3_a usb_port:=/dev/ttyACM1
> ```

### 2. 서보 제어 (우분투 PC)

```bash
# 0도
ROS_DOMAIN_ID=4 ros2 topic pub /tb3_a/servo_angle std_msgs/msg/Int32 "data: 0" --once

# 90도
ROS_DOMAIN_ID=4 ros2 topic pub /tb3_a/servo_angle std_msgs/msg/Int32 "data: 90" --once

# 180도
ROS_DOMAIN_ID=4 ros2 topic pub /tb3_a/servo_angle std_msgs/msg/Int32 "data: 180" --once
```

---

## 🖼 동작 확인

<p align="center">
  <img width="90%" alt="브링업으로 서보모터 가동 성공!" src="https://github.com/user-attachments/assets/6a6163a6-241e-4a4a-bae2-6590fcceaf64" />
  <br><i>[브링업 및 서보 제어 동작 확인]</i>
</p>
