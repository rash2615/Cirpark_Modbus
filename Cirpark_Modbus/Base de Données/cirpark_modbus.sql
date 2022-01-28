-- phpMyAdmin SQL Dump
-- version 4.7.4
-- https://www.phpmyadmin.net/
--
-- Hôte : 127.0.0.1:3306
-- Généré le :  ven. 28 jan. 2022 à 13:08
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
-- Structure de la table `abonne`
--

DROP TABLE IF EXISTS `abonne`;
CREATE TABLE IF NOT EXISTS `abonne` (
  `id_abonne` int(11) NOT NULL AUTO_INCREMENT,
  `nom` varchar(50) NOT NULL,
  `prenom` varchar(50) NOT NULL,
  `mail` varchar(100) NOT NULL,
  `mdp` varchar(15) NOT NULL,
  PRIMARY KEY (`id_abonne`),
  UNIQUE KEY `id_abonne` (`id_abonne`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

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
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `compte`
--

DROP TABLE IF EXISTS `compte`;
CREATE TABLE IF NOT EXISTS `compte` (
  `id_compte` int(11) NOT NULL AUTO_INCREMENT,
  `id_abonne` int(11) DEFAULT NULL,
  `gestion_mdp` varchar(15) NOT NULL,
  `parametre` varchar(50) NOT NULL,
  PRIMARY KEY (`id_compte`),
  UNIQUE KEY `id_compte` (`id_compte`),
  UNIQUE KEY `id_abonne` (`id_abonne`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `duree`
--

DROP TABLE IF EXISTS `duree`;
CREATE TABLE IF NOT EXISTS `duree` (
  `id_duree` int(11) NOT NULL AUTO_INCREMENT,
  `heure_debut` int(3) NOT NULL,
  `minute_debut` int(3) NOT NULL,
  `seconde_debut` int(3) NOT NULL,
  `heure_fin` int(3) NOT NULL,
  `minute_fin` int(3) NOT NULL,
  `seconde_fin` int(3) NOT NULL,
  `date` date NOT NULL,
  PRIMARY KEY (`id_duree`),
  UNIQUE KEY `id_duree` (`id_duree`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `gerant`
--

DROP TABLE IF EXISTS `gerant`;
CREATE TABLE IF NOT EXISTS `gerant` (
  `id_gerant` int(11) NOT NULL AUTO_INCREMENT,
  `id_parking` int(11) NOT NULL,
  `nom` varchar(50) NOT NULL,
  `prenom` varchar(50) NOT NULL,
  `localite_parking` int(11) NOT NULL,
  PRIMARY KEY (`id_gerant`),
  UNIQUE KEY `id_parking` (`id_parking`),
  UNIQUE KEY `id_gerant` (`id_gerant`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `historique`
--

DROP TABLE IF EXISTS `historique`;
CREATE TABLE IF NOT EXISTS `historique` (
  `id_histo` int(11) NOT NULL AUTO_INCREMENT,
  `id_abonne` int(11) NOT NULL,
  `nom` varchar(50) NOT NULL,
  `prenom` varchar(50) NOT NULL,
  `date` date NOT NULL,
  `id_compte` int(11) NOT NULL,
  `niveau` int(11) NOT NULL,
  `id_parking` int(11) NOT NULL,
  `id_duree` int(11) NOT NULL,
  `id_place` int(11) NOT NULL,
  `id_tarif` int(11) NOT NULL,
  `id_paiement` int(11) NOT NULL,
  `mode_paiement` varchar(50) NOT NULL,
  `montantHT` float NOT NULL,
  `montantTTC` float NOT NULL,
  `id_capteur` int(11) NOT NULL,
  `modele` varchar(50) NOT NULL,
  PRIMARY KEY (`id_histo`),
  UNIQUE KEY `id_abonne` (`id_abonne`),
  UNIQUE KEY `id_compte` (`id_compte`),
  UNIQUE KEY `id_parking` (`id_parking`),
  UNIQUE KEY `id_duree` (`id_duree`),
  UNIQUE KEY `id_place` (`id_place`),
  UNIQUE KEY `id_tarif` (`id_tarif`),
  UNIQUE KEY `id_paiement` (`id_paiement`),
  UNIQUE KEY `id_capteur` (`id_capteur`),
  UNIQUE KEY `id_histo` (`id_histo`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `paiement`
--

DROP TABLE IF EXISTS `paiement`;
CREATE TABLE IF NOT EXISTS `paiement` (
  `id_paiement` int(11) NOT NULL AUTO_INCREMENT,
  `id_compte` int(11) NOT NULL,
  `id_tarif` int(11) NOT NULL,
  `mode_paiement` varchar(20) NOT NULL,
  `montantHT` float NOT NULL,
  `montantTTC` float NOT NULL,
  PRIMARY KEY (`id_paiement`),
  UNIQUE KEY `id_compte` (`id_compte`),
  UNIQUE KEY `id_tarif` (`id_tarif`),
  UNIQUE KEY `id_paiement` (`id_paiement`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `parking`
--

DROP TABLE IF EXISTS `parking`;
CREATE TABLE IF NOT EXISTS `parking` (
  `id_parking` int(11) NOT NULL AUTO_INCREMENT,
  `id_place` int(11) NOT NULL,
  `etat` varchar(50) NOT NULL,
  `niveau` int(11) NOT NULL,
  PRIMARY KEY (`id_parking`),
  UNIQUE KEY `id_place` (`id_place`),
  UNIQUE KEY `id_parking` (`id_parking`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `place`
--

DROP TABLE IF EXISTS `place`;
CREATE TABLE IF NOT EXISTS `place` (
  `id_place` int(11) NOT NULL AUTO_INCREMENT,
  `id_reservation` int(11) NOT NULL,
  `id_abonne` int(11) NOT NULL,
  `place_dispo` tinyint(1) NOT NULL,
  `place_prive` tinyint(1) NOT NULL,
  `etat` varchar(50) NOT NULL,
  `id_duree` int(11) NOT NULL,
  PRIMARY KEY (`id_place`),
  UNIQUE KEY `id_reservation` (`id_reservation`),
  UNIQUE KEY `id_abonne` (`id_abonne`),
  UNIQUE KEY `id_duree` (`id_duree`),
  UNIQUE KEY `id_place` (`id_place`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `repetition`
--

DROP TABLE IF EXISTS `repetition`;
CREATE TABLE IF NOT EXISTS `repetition` (
  `id_rep` int(11) NOT NULL AUTO_INCREMENT,
  `id_duree` int(11) NOT NULL,
  `id_compte` int(11) NOT NULL,
  `journalier` tinyint(1) NOT NULL,
  `hebdomadaire` tinyint(1) NOT NULL,
  `mensuel` tinyint(1) NOT NULL,
  `annuel` tinyint(1) NOT NULL,
  PRIMARY KEY (`id_rep`),
  UNIQUE KEY `id_duree` (`id_duree`),
  UNIQUE KEY `id_compte` (`id_compte`),
  UNIQUE KEY `id_rep` (`id_rep`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `reservation`
--

DROP TABLE IF EXISTS `reservation`;
CREATE TABLE IF NOT EXISTS `reservation` (
  `id_reservation` int(11) NOT NULL AUTO_INCREMENT,
  `id_compte` int(11) NOT NULL,
  `id_duree` int(11) NOT NULL,
  `id_rep` int(11) NOT NULL,
  `date` date NOT NULL,
  PRIMARY KEY (`id_reservation`),
  UNIQUE KEY `id_compte` (`id_compte`),
  UNIQUE KEY `id_duree` (`id_duree`),
  UNIQUE KEY `id_rep` (`id_rep`),
  UNIQUE KEY `id_reservation` (`id_reservation`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `tarif`
--

DROP TABLE IF EXISTS `tarif`;
CREATE TABLE IF NOT EXISTS `tarif` (
  `id_tarif` int(11) NOT NULL AUTO_INCREMENT,
  `id_compte` int(11) NOT NULL,
  `id_place` int(11) NOT NULL,
  `id_reservation` int(11) NOT NULL,
  `id_duree` int(11) NOT NULL,
  `prix` float NOT NULL,
  PRIMARY KEY (`id_tarif`),
  UNIQUE KEY `id_compte` (`id_compte`),
  UNIQUE KEY `id_place` (`id_place`),
  UNIQUE KEY `id_reservation` (`id_reservation`),
  UNIQUE KEY `id_duree` (`id_duree`),
  UNIQUE KEY `id_tarif` (`id_tarif`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
