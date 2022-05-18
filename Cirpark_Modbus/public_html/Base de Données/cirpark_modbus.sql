-- phpMyAdmin SQL Dump
-- version 4.7.4
-- https://www.phpmyadmin.net/
--
-- Hôte : 127.0.0.1:3306
-- Généré le :  lun. 31 jan. 2022 à 09:41
-- Version du serveur :  5.7.19
-- Version de PHP :  5.6.31

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données :  `cirpark_modbus`
--

-- --------------------------------------------------------

--
-- Structure de la table `capteur`
--

DROP TABLE IF EXISTS `capteur`;
CREATE TABLE IF NOT EXISTS `capteur` (
  `id_capteur` int(11) NOT NULL AUTO_INCREMENT,
  `id_place` int(11) NOT NULL,
  `modele` varchar(30) NOT NULL,
  `niveau` int(11) NOT NULL,
  `annee` int(11) NOT NULL,
  `etat` tinyint(1) NOT NULL,
  PRIMARY KEY (`id_capteur`),
  UNIQUE KEY `id_place` (`id_place`),
  UNIQUE KEY `id_capteur` (`id_capteur`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `client`
--

DROP TABLE IF EXISTS `client`;
CREATE TABLE IF NOT EXISTS `client` (
  `id_client` int(11) NOT NULL AUTO_INCREMENT,
  `gestion_mdp` varchar(15) DEFAULT NULL,
  `parametre` varchar(50) DEFAULT NULL,
  `nom` varchar(45) DEFAULT NULL,
  `prenom` varchar(45) DEFAULT NULL,
  `mail` varchar(100) DEFAULT NULL,
  `mdp` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`id_client`),
  UNIQUE KEY `id_compte` (`id_client`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `gerant`
--

DROP TABLE IF EXISTS `gerant`;
CREATE TABLE IF NOT EXISTS `gerant` (
  `id_gerant` int(11) NOT NULL AUTO_INCREMENT,
  `id_niveau` int(11) NOT NULL,
  `nom` varchar(50) NOT NULL,
  `prenom` varchar(50) NOT NULL,
  `localite_parking` int(11) NOT NULL,
  PRIMARY KEY (`id_gerant`),
  UNIQUE KEY `id_parking` (`id_niveau`),
  UNIQUE KEY `id_gerant` (`id_gerant`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `historique`
--

DROP TABLE IF EXISTS `historique`;
CREATE TABLE IF NOT EXISTS `historique` (
  `id_histo` int(11) NOT NULL AUTO_INCREMENT,
  `id_client` int(11) NOT NULL,
  `nom` varchar(50) NOT NULL,
  `prenom` varchar(50) NOT NULL,
  `niveau` int(11) NOT NULL,
  `id_place` int(11) NOT NULL,
  `id_paiement` int(11) NOT NULL,
  `mode_paiement` varchar(50) NOT NULL,
  `montant` float NOT NULL,
  `id_capteur` int(11) NOT NULL,
  `modele` varchar(50) NOT NULL,
  `id_reservation` int(11) DEFAULT NULL,
  PRIMARY KEY (`id_histo`),
  UNIQUE KEY `id_abonne` (`id_client`),
  UNIQUE KEY `id_place` (`id_place`),
  UNIQUE KEY `id_paiement` (`id_paiement`),
  UNIQUE KEY `id_capteur` (`id_capteur`),
  UNIQUE KEY `id_histo` (`id_histo`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `niveau`
--

DROP TABLE IF EXISTS `niveau`;
CREATE TABLE IF NOT EXISTS `niveau` (
  `id_niveau` int(11) NOT NULL,
  `id_place` int(11) NOT NULL,
  `etat` varchar(50) NOT NULL,
  `niveau` int(11) NOT NULL,
  `id_gerant` int(11) NOT NULL,
  PRIMARY KEY (`id_gerant`),
  UNIQUE KEY `id_place` (`id_place`),
  UNIQUE KEY `id_parking` (`id_niveau`),
  KEY `fk_niveau_gerant1_idx` (`id_gerant`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `paiement`
--

DROP TABLE IF EXISTS `paiement`;
CREATE TABLE IF NOT EXISTS `paiement` (
  `id_paiement` int(11) NOT NULL AUTO_INCREMENT,
  `id_client` int(11) NOT NULL,
  `mode_paiement` varchar(20) NOT NULL,
  `montant` float NOT NULL,
  `id_reservation` varchar(45) NOT NULL,
  PRIMARY KEY (`id_paiement`),
  UNIQUE KEY `id_paiement` (`id_paiement`),
  KEY `fk_paiement_reservation1_idx` (`id_reservation`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `place`
--

DROP TABLE IF EXISTS `place`;
CREATE TABLE IF NOT EXISTS `place` (
  `id_place` int(11) NOT NULL AUTO_INCREMENT,
  `etat` varchar(50) NOT NULL,
  `capteur_id_capteur` int(11) NOT NULL,
  PRIMARY KEY (`id_place`,`capteur_id_capteur`),
  KEY `fk_place_capteur1_idx` (`capteur_id_capteur`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `reservation`
--

DROP TABLE IF EXISTS `reservation`;
CREATE TABLE IF NOT EXISTS `reservation` (
  `id_reservation` int(11) NOT NULL AUTO_INCREMENT,
  `id_client` int(11) NOT NULL,
  `date_debut` timestamp NULL DEFAULT NULL,
  `date_fin` timestamp NULL DEFAULT NULL,
  `id_place` int(11) DEFAULT NULL,
  PRIMARY KEY (`id_reservation`),
  UNIQUE KEY `id_compte` (`id_client`),
  UNIQUE KEY `id_reservation` (`id_reservation`),
  UNIQUE KEY `id_place_UNIQUE` (`id_place`),
  KEY `fk_reservation_place1_idx` (`id_place`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
