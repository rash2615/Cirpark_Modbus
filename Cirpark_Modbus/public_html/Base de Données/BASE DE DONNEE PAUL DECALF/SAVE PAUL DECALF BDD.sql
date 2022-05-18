/*
 Navicat MySQL Data Transfer

 Source Server         : aaa
 Source Server Type    : MySQL
 Source Server Version : 100422
 Source Host           : localhost:3306
 Source Schema         : test

 Target Server Type    : MySQL
 Target Server Version : 100422
 File Encoding         : 65001

 Date: 12/05/2022 17:29:34
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for capteur
-- ----------------------------
DROP TABLE IF EXISTS `capteur`;
CREATE TABLE `capteur`  (
  `id_capteur` int NOT NULL AUTO_INCREMENT,
  `nom_capteur` varchar(30) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL,
  `annee` int NOT NULL,
  `etat` tinyint(1) NOT NULL,
  `reference` varchar(45) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL,
  PRIMARY KEY (`id_capteur`) USING BTREE
) ENGINE = MyISAM AUTO_INCREMENT = 3 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of capteur
-- ----------------------------
INSERT INTO `capteur` VALUES (1, 'SP157b', 2018, 0, '157b');
INSERT INTO `capteur` VALUES (2, 'SP1c27', 2018, 0, '1c27');

-- ----------------------------
-- Table structure for gerant
-- ----------------------------
DROP TABLE IF EXISTS `gerant`;
CREATE TABLE `gerant`  (
  `id_gerant` int NOT NULL AUTO_INCREMENT,
  `id_niveau` int NOT NULL,
  `nom` varchar(50) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL,
  `prenom` varchar(50) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL,
  `localite_parking` int NOT NULL,
  PRIMARY KEY (`id_gerant`) USING BTREE,
  UNIQUE INDEX `id_parking`(`id_niveau`) USING BTREE,
  UNIQUE INDEX `id_gerant`(`id_gerant`) USING BTREE
) ENGINE = MyISAM AUTO_INCREMENT = 1 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of gerant
-- ----------------------------

-- ----------------------------
-- Table structure for historique
-- ----------------------------
DROP TABLE IF EXISTS `historique`;
CREATE TABLE `historique`  (
  `id_histo` int NOT NULL AUTO_INCREMENT,
  `id_utilisateur` int NOT NULL,
  `niveau` int NOT NULL,
  `id_place` int NOT NULL,
  `id_paiement` int NOT NULL,
  `mode_paiement` varchar(50) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL,
  `montant` float NOT NULL,
  `id_reservation` int NULL DEFAULT NULL,
  PRIMARY KEY (`id_histo`) USING BTREE,
  UNIQUE INDEX `id_abonne`(`id_utilisateur`) USING BTREE,
  UNIQUE INDEX `id_place`(`id_place`) USING BTREE,
  UNIQUE INDEX `id_paiement`(`id_paiement`) USING BTREE,
  UNIQUE INDEX `id_histo`(`id_histo`) USING BTREE
) ENGINE = MyISAM AUTO_INCREMENT = 2 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of historique
-- ----------------------------
INSERT INTO `historique` VALUES (1, 4, 1, 1, 1, 'CB', 5, 1);

-- ----------------------------
-- Table structure for niveau
-- ----------------------------
DROP TABLE IF EXISTS `niveau`;
CREATE TABLE `niveau`  (
  `id_niveau` int NOT NULL AUTO_INCREMENT,
  `niveau` int NOT NULL,
  `nb_place` int NOT NULL,
  PRIMARY KEY (`id_niveau`) USING BTREE,
  UNIQUE INDEX `id_parking`(`id_niveau`) USING BTREE
) ENGINE = MyISAM AUTO_INCREMENT = 4 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Fixed;

-- ----------------------------
-- Records of niveau
-- ----------------------------
INSERT INTO `niveau` VALUES (1, 1, 0);
INSERT INTO `niveau` VALUES (2, 2, 0);
INSERT INTO `niveau` VALUES (3, 3, 0);

-- ----------------------------
-- Table structure for paiement
-- ----------------------------
DROP TABLE IF EXISTS `paiement`;
CREATE TABLE `paiement`  (
  `id_paiement` int NOT NULL AUTO_INCREMENT,
  `id_utilisateur` int NOT NULL,
  `mode_paiement` varchar(20) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL,
  `montant` float NOT NULL,
  `id_reservation` varchar(45) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL,
  PRIMARY KEY (`id_paiement`) USING BTREE,
  UNIQUE INDEX `id_paiement`(`id_paiement`) USING BTREE,
  INDEX `fk_paiement_reservation1_idx`(`id_reservation`) USING BTREE
) ENGINE = MyISAM AUTO_INCREMENT = 2 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of paiement
-- ----------------------------
INSERT INTO `paiement` VALUES (1, 4, 'CB', 5, '1');

-- ----------------------------
-- Table structure for place
-- ----------------------------
DROP TABLE IF EXISTS `place`;
CREATE TABLE `place`  (
  `id_place` int NOT NULL AUTO_INCREMENT,
  `id_capteur` int NOT NULL,
  `numero_place` varchar(45) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL COMMENT 'Exemple : A1 pour la place 1 de l\'allée A',
  `id_niveau` int NOT NULL,
  PRIMARY KEY (`id_place`) USING BTREE,
  INDEX `fk_place_capteur1_idx`(`id_capteur`) USING BTREE,
  INDEX `fk_place_niveau1_idx`(`id_niveau`) USING BTREE
) ENGINE = MyISAM AUTO_INCREMENT = 3 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of place
-- ----------------------------
INSERT INTO `place` VALUES (1, 1, 'A1', 1);
INSERT INTO `place` VALUES (2, 2, 'B1', 1);

-- ----------------------------
-- Table structure for reservation
-- ----------------------------
DROP TABLE IF EXISTS `reservation`;
CREATE TABLE `reservation`  (
  `id_reservation` int NOT NULL AUTO_INCREMENT,
  `id_utilisateur` int NOT NULL,
  `date_debut` timestamp NULL DEFAULT NULL,
  `date_fin` timestamp NULL DEFAULT NULL,
  `id_place` int NULL DEFAULT NULL,
  PRIMARY KEY (`id_reservation`) USING BTREE,
  UNIQUE INDEX `id_compte`(`id_utilisateur`) USING BTREE,
  UNIQUE INDEX `id_reservation`(`id_reservation`) USING BTREE,
  UNIQUE INDEX `id_place_UNIQUE`(`id_place`) USING BTREE,
  INDEX `fk_reservation_place1_idx`(`id_place`) USING BTREE
) ENGINE = MyISAM AUTO_INCREMENT = 2 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Fixed;

-- ----------------------------
-- Records of reservation
-- ----------------------------
INSERT INTO `reservation` VALUES (1, 4, '2022-04-01 13:12:17', '2022-04-01 15:12:17', 1);

-- ----------------------------
-- Table structure for utilisateur
-- ----------------------------
DROP TABLE IF EXISTS `utilisateur`;
CREATE TABLE `utilisateur`  (
  `id_utilisateur` int NOT NULL AUTO_INCREMENT,
  `role` varchar(50) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `nom` varchar(45) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `prenom` varchar(45) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `mail` text CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL,
  `mdp` varchar(45) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  PRIMARY KEY (`id_utilisateur`) USING BTREE,
  UNIQUE INDEX `id_compte`(`id_utilisateur`) USING BTREE
) ENGINE = MyISAM AUTO_INCREMENT = 21 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of utilisateur
-- ----------------------------
INSERT INTO `utilisateur` VALUES (1, 'admin', 'bhavsar', 'aakash', 'abhavsar@cirpark.com', 'acirpark');
INSERT INTO `utilisateur` VALUES (2, 'admin', 'patel', 'rashmi', 'rpatel@cirpark.com', 'rcirpark');
INSERT INTO `utilisateur` VALUES (3, 'admin', 'caillard', 'yoan', 'ycaillard@cirpark.com', 'ycirpark');
INSERT INTO `utilisateur` VALUES (4, 'admin', 'karunanayake', 'dilshan', 'dkarunanayake@cirpark.com', 'kcirpark');
INSERT INTO `utilisateur` VALUES (5, 'client', 'cirpark', 'modbus', 'mcirpark@cirpark.com', 'mcirpark');

SET FOREIGN_KEY_CHECKS = 1;
