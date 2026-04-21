-- --------------------------------------------------------
-- 호스트:                          10.10.16.76
-- 서버 버전:                        11.8.6-MariaDB-0+deb13u1 from Debian - -- Please help get to 10k stars at https://github.com/MariaDB/Server
-- 서버 OS:                        debian-linux-gnu
-- HeidiSQL 버전:                  12.16.0.7229
-- --------------------------------------------------------

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!50503 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;


-- amr_turtle_db 데이터베이스 구조 내보내기
CREATE DATABASE IF NOT EXISTS `amr_turtle_db` /*!40100 DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_uca1400_ai_ci */;
USE `amr_turtle_db`;

-- 테이블 amr_turtle_db.amr_working_logs 구조 내보내기
CREATE TABLE IF NOT EXISTS `amr_working_logs` (
  `id` char(36) NOT NULL,
  `turtlebot_uuid` char(36) NOT NULL,
  `section` char(1) NOT NULL,
  `command_id` char(36) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_uca1400_ai_ci;

-- 테이블 데이터 amr_turtle_db.amr_working_logs:~0 rows (대략적) 내보내기

-- 테이블 amr_turtle_db.command_msg 구조 내보내기
CREATE TABLE IF NOT EXISTS `command_msg` (
  `id` char(36) NOT NULL,
  `turtlebot_uuid` char(36) NOT NULL,
  `section` char(1) NOT NULL,
  `action` enum('charging','pick_up','put_down','waiting') NOT NULL,
  `act_status` enum('success','error') NOT NULL,
  `item_uuid` char(36) DEFAULT NULL,
  `item_count` int(11) DEFAULT NULL,
  `created_at` datetime DEFAULT current_timestamp(),
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_uca1400_ai_ci;

-- 테이블 데이터 amr_turtle_db.command_msg:~4 rows (대략적) 내보내기
INSERT INTO `command_msg` (`id`, `turtlebot_uuid`, `section`, `action`, `act_status`, `item_uuid`, `item_count`, `created_at`) VALUES
	('0ec619b7-3cb2-11f1-987d-f39a29fe8188', 'c5ec79f8-3c8c-11f1-987d-f39a29fe8188', 'Z', 'pick_up', 'success', 'b63020ca-3c8d-11f1-987d-f39a29fe8188', 1, '2026-04-20 21:11:34'),
	('0ec6bfc0-3cb2-11f1-987d-f39a29fe8188', 'c6be1ccd-3c8c-11f1-987d-f39a29fe8188', 'X', 'pick_up', 'success', 'b630be08-3c8d-11f1-987d-f39a29fe8188', 1, '2026-04-20 21:11:34'),
	('0ec7c3d6-3cb2-11f1-987d-f39a29fe8188', 'c5ec79f8-3c8c-11f1-987d-f39a29fe8188', 'D', 'waiting', 'success', NULL, 0, '2026-04-20 21:11:34'),
	('105165b1-3cb2-11f1-987d-f39a29fe8188', 'c6be1ccd-3c8c-11f1-987d-f39a29fe8188', 'S', 'charging', 'error', NULL, 0, '2026-04-20 21:11:37');

-- 테이블 amr_turtle_db.product_inventory 구조 내보내기
CREATE TABLE IF NOT EXISTS `product_inventory` (
  `id` char(36) NOT NULL,
  `item_name` varchar(50) NOT NULL,
  `item_type` varchar(20) DEFAULT NULL,
  `stock` int(11) DEFAULT 0,
  `location_x` int(11) NOT NULL DEFAULT 0,
  `location_y` int(11) NOT NULL DEFAULT 0,
  `unit` varchar(10) DEFAULT 'EA',
  `updated_at` timestamp NULL DEFAULT current_timestamp() ON UPDATE current_timestamp(),
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_uca1400_ai_ci;

-- 테이블 데이터 amr_turtle_db.product_inventory:~3 rows (대략적) 내보내기
INSERT INTO `product_inventory` (`id`, `item_name`, `item_type`, `stock`, `location_x`, `location_y`, `unit`, `updated_at`) VALUES
	('b63020ca-3c8e-11f1-987d-f39a29fe8188', 'item_a', 'RAW', 100, 1, 1, 'EA', '2026-04-20 12:36:03'),
	('b630be08-3c8e-11f1-987d-f39a29fe8188', 'item_b', 'RAW', 50, 2, 2, 'EA', '2026-04-20 12:36:03'),
	('b6742d63-3c8e-11f1-987d-f39a29fe8188', 'item_c', 'PROD', 10, 5, 10, 'EA', '2026-04-20 12:47:17');

-- 테이블 amr_turtle_db.turtlebot_info 구조 내보내기
CREATE TABLE IF NOT EXISTS `turtlebot_info` (
  `uuid` char(36) NOT NULL,
  `turtlebot_name` varchar(20) NOT NULL,
  `status` varchar(20) DEFAULT '정상',
  PRIMARY KEY (`uuid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_uca1400_ai_ci;

-- 테이블 데이터 amr_turtle_db.turtlebot_info:~2 rows (대략적) 내보내기
INSERT INTO `turtlebot_info` (`uuid`, `turtlebot_name`, `status`) VALUES
	('c5ec79f8-3c8c-11f1-987d-f39a29fe8188', '터틀봇_A', '정상'),
	('c6be1ccd-3c8c-11f1-987d-f39a29fe8188', '터틀봇_B', '정상');

/*!40103 SET TIME_ZONE=IFNULL(@OLD_TIME_ZONE, 'system') */;
/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IFNULL(@OLD_FOREIGN_KEY_CHECKS, 1) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40111 SET SQL_NOTES=IFNULL(@OLD_SQL_NOTES, 1) */;
