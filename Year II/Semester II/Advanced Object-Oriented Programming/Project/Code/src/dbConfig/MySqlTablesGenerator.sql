CREATE TABLE `buyers_utilities` (
                                    `idUtility` int NOT NULL,
                                    `idService` int NOT NULL,
                                    `idBuyer` int NOT NULL,
                                    `type` varchar(45) NOT NULL,
                                    `serviceAddedDate` date DEFAULT NULL,
                                    `feedback` varchar(300) DEFAULT NULL,
                                    PRIMARY KEY (`idUtility`,`idService`,`idBuyer`),
                                    KEY `idService_idx` (`idService`),
                                    KEY `idBuyer_idx` (`idBuyer`),
                                    KEY `idServiceInBuyerUtility_idx` (`idService`),
                                    KEY `idBuyerInBuyerUtility_idx` (`idBuyer`),
                                    CONSTRAINT `idBuyerInBuyerUtility` FOREIGN KEY (`idBuyer`) REFERENCES `users` (`idUser`) ON DELETE CASCADE ON UPDATE CASCADE,
                                    CONSTRAINT `idServiceInBuyerUtility` FOREIGN KEY (`idService`) REFERENCES `services` (`idService`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci

CREATE TABLE `cities` (
                          `idCity` int NOT NULL AUTO_INCREMENT,
                          `name` varchar(45) NOT NULL,
                          PRIMARY KEY (`idCity`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci

CREATE TABLE `jobs` (
                        `idJob` int NOT NULL AUTO_INCREMENT,
                        `name` varchar(45) NOT NULL,
                        PRIMARY KEY (`idJob`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci

CREATE TABLE `services` (
                            `idService` int NOT NULL AUTO_INCREMENT,
                            `idSeller` int DEFAULT NULL,
                            `idJob` int DEFAULT NULL,
                            `description` varchar(150) DEFAULT NULL,
                            `price` double NOT NULL,
                            `workSchedule` varchar(45) DEFAULT NULL,
                            PRIMARY KEY (`idService`),
                            KEY `idSellerInService_idx` (`idSeller`),
                            KEY `idJobInService_idx` (`idJob`),
                            CONSTRAINT `idJobInService` FOREIGN KEY (`idJob`) REFERENCES `jobs` (`idJob`) ON DELETE SET NULL ON UPDATE CASCADE,
                            CONSTRAINT `idSellerInService` FOREIGN KEY (`idSeller`) REFERENCES `users` (`idUser`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci

CREATE TABLE `services_availabilities` (
                                           `idService` int NOT NULL,
                                           `idCity` int NOT NULL,
                                           PRIMARY KEY (`idService`,`idCity`),
                                           KEY `idCity_idx` (`idCity`),
                                           CONSTRAINT `idCityInServiceAvailability` FOREIGN KEY (`idCity`) REFERENCES `cities` (`idCity`) ON DELETE CASCADE ON UPDATE CASCADE,
                                           CONSTRAINT `idServiceInServiceAvailability` FOREIGN KEY (`idService`) REFERENCES `services` (`idService`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci

CREATE TABLE `users` (
                         `idUser` int NOT NULL AUTO_INCREMENT,
                         `type` varchar(45) NOT NULL,
                         `firstName` varchar(45) DEFAULT NULL,
                         `lastName` varchar(45) DEFAULT NULL,
                         `username` varchar(45) NOT NULL,
                         `email` varchar(45) NOT NULL,
                         `password` varchar(45) NOT NULL,
                         `description` varchar(45) DEFAULT NULL,
                         `phoneNumber` varchar(45) DEFAULT NULL,
                         PRIMARY KEY (`idUser`),
                         UNIQUE KEY `username_UNIQUE` (`username`),
                         UNIQUE KEY `email_UNIQUE` (`email`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci