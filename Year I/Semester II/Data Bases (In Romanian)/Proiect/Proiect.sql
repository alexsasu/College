-- 10. & 13.


-- Crearea tabelelor:


CREATE TABLE CATEGORIE
       (id_categorie INTEGER,
        denumire VARCHAR2(40) CONSTRAINT denumire_categorie NOT NULL,
        CONSTRAINT pk_categorie PRIMARY KEY(id_categorie),
        CONSTRAINT u_denumire_categorie UNIQUE(denumire)
        );
        
CREATE TABLE PRODUS
       (id_produs INTEGER,
        id_categorie INTEGER,
        tip VARCHAR(10) CONSTRAINT tip_produs NOT NULL,
        denumire VARCHAR2(200) CONSTRAINT denumire_produs NOT NULL,
        tip_sistem VARCHAR2(30),
        vanzator VARCHAR2(40) CONSTRAINT vanzator_produs NOT NULL,
        recomandat_pentru_gaming VARCHAR2(2),
        pret NUMBER CONSTRAINT pret_produs NOT NULL,
        average_rating NUMBER,
        CONSTRAINT pk_produs PRIMARY KEY(id_produs),
        CONSTRAINT fk_categorie_in_produs FOREIGN KEY(id_categorie) REFERENCES CATEGORIE(id_categorie) ON DELETE CASCADE,
        CONSTRAINT u_denumire_produs UNIQUE(denumire)
        );
        
CREATE TABLE SERVICIU
       (id_serviciu INTEGER,
        tip VARCHAR(13) CONSTRAINT tip_serviciu NOT NULL,
        denumire VARCHAR2(70) CONSTRAINT denumire_serviciu NOT NULL,
        descriere VARCHAR2(1000),
        pret NUMBER CONSTRAINT pret_serviciu NOT NULL,
        CONSTRAINT pk_serviciu PRIMARY KEY(id_serviciu),
        CONSTRAINT u_denumire_serviciu UNIQUE(denumire)
        );
        
CREATE TABLE ADRESA_LIVRARE
       (id_adresa INTEGER,
        localitate VARCHAR2(30) CONSTRAINT localitate_adresa_livrare NOT NULL,
        strada VARCHAR2(80) CONSTRAINT strada_adresa_livrare NOT NULL,
        nr_strada INTEGER CONSTRAINT nr_strada_adresa_livrare NOT NULL,
        CONSTRAINT pk_adresa_livrare PRIMARY KEY(id_adresa)
        );
        
CREATE TABLE CLIENT
       (id_client INTEGER,
        nume VARCHAR2(40) CONSTRAINT nume_client NOT NULL,
        prenume VARCHAR2(40) CONSTRAINT prenume_client NOT NULL,
        CONSTRAINT pk_client PRIMARY KEY(id_client)
        );
        
CREATE TABLE CONT_SITE
       (id_cont INTEGER,
        nume_utilizator VARCHAR2(40),
        id_client INTEGER,
        email VARCHAR2(40) CONSTRAINT email NOT NULL,
        CONSTRAINT pk_compus_cont_site PRIMARY KEY(id_cont, nume_utilizator),
        CONSTRAINT u_nume_utilizator UNIQUE(nume_utilizator),
        CONSTRAINT fk_client_in_cont_site FOREIGN KEY(id_client) REFERENCES CLIENT(id_client) ON DELETE CASCADE
        );
        
CREATE TABLE RECENZIE
       (id_recenzie INTEGER,
        id_produs INTEGER CONSTRAINT id_produs_recenzie NOT NULL,
        nume_utilizator VARCHAR2(40) CONSTRAINT nume_utilizator_recenzie NOT NULL,
        data_scriere DATE CONSTRAINT data_scriere_recenzie NOT NULL,
        nr_stele NUMBER,
        CONSTRAINT pk_compus_recenzie PRIMARY KEY(id_recenzie, id_produs),
        CONSTRAINT fk_produs_in_recenzie FOREIGN KEY(id_produs) REFERENCES PRODUS(id_produs) ON DELETE CASCADE,
        CONSTRAINT fk_cont_site_in_recenzie FOREIGN KEY(nume_utilizator) REFERENCES CONT_SITE(nume_utilizator) ON DELETE CASCADE
        );
    
CREATE TABLE DEPARTAMENT
       (id_departament INTEGER,
        denumire VARCHAR2(30) CONSTRAINT denumire_departament NOT NULL,
        CONSTRAINT pk_departament PRIMARY KEY(id_departament),
        CONSTRAINT u_denumire_departament UNIQUE(denumire)
        );
    
CREATE TABLE ANGAJAT
       (id_angajat INTEGER,
        id_departament INTEGER,
        tip VARCHAR2(9) CONSTRAINT tip_angajat NOT NULL,
        nume VARCHAR2(30) CONSTRAINT nume_angajat NOT NULL,
        prenume VARCHAR2(30) CONSTRAINT prenume_angajat NOT NULL,
        salariu NUMBER CONSTRAINT salariu_angajat NOT NULL,
        email VARCHAR2(40) CONSTRAINT email_angajat NOT NULL,
        nr_telefon VARCHAR2(10) CONSTRAINT nr_telefon_angajat NOT NULL,
        CONSTRAINT pk_angajat PRIMARY KEY(id_angajat),
        CONSTRAINT fk_departament_in_angajat FOREIGN KEY(id_departament) REFERENCES DEPARTAMENT(id_departament) ON DELETE CASCADE,
        CONSTRAINT u_email_angajat UNIQUE(email)
        );
        
CREATE TABLE ESTE_COMPATIBIL
       (id_serviciu INTEGER,
        id_produs INTEGER,
        CONSTRAINT pk_compus_este_compatibil PRIMARY KEY(id_serviciu, id_produs),
        CONSTRAINT fk_serviciu_in_este_compatibil FOREIGN KEY(id_serviciu) REFERENCES SERVICIU(id_serviciu) ON DELETE CASCADE,
        CONSTRAINT fk_produs_in_este_compatibil FOREIGN KEY(id_produs) REFERENCES PRODUS(id_produs) ON DELETE CASCADE
        );
        
CREATE TABLE COMANDA
       (id_comanda INTEGER,
        id_produs INTEGER,
        id_client INTEGER,
        id_adresa INTEGER,
        data_sosire DATE CONSTRAINT data_sosire_comanda NOT NULL,
        pret_total NUMBER CONSTRAINT pret_total_comanda NOT NULL,
        CONSTRAINT pk_compus_comanda PRIMARY KEY(id_comanda, id_produs, id_client, id_adresa),
        CONSTRAINT fk_produs_in_comanda FOREIGN KEY(id_produs) REFERENCES PRODUS(id_produs) ON DELETE CASCADE,
        CONSTRAINT fk_client_in_comanda FOREIGN KEY(id_client) REFERENCES CLIENT(id_client) ON DELETE CASCADE,
        CONSTRAINT fk_adresa_livrare_in_comanda FOREIGN KEY(id_adresa) REFERENCES ADRESA_LIVRARE(id_adresa) ON DELETE CASCADE
        );
        
CREATE TABLE CUMPARA
       (id_cumpara INTEGER,
        id_serviciu INTEGER,
        id_client INTEGER,
        data_realizare DATE CONSTRAINT data_realizare_cumpara NOT NULL,
        CONSTRAINT pk_compus_cumpara PRIMARY KEY(id_cumpara, id_serviciu, id_client),
        CONSTRAINT fk_serviciu_in_cumpara FOREIGN KEY(id_serviciu) REFERENCES SERVICIU(id_serviciu) ON DELETE CASCADE,
        CONSTRAINT fk_client_in_cumpara FOREIGN KEY(id_client) REFERENCES CLIENT(id_client) ON DELETE CASCADE
        );
        
CREATE TABLE ESTE_ASISTAT
       (id_este_asistat INTEGER,
        id_client INTEGER,
        id_angajat INTEGER,
        CONSTRAINT pk_compus_este_asistat PRIMARY KEY(id_este_asistat, id_client, id_angajat),
        CONSTRAINT fk_client_in_este_asistat FOREIGN KEY(id_client) REFERENCES CLIENT(id_client) ON DELETE CASCADE,
        CONSTRAINT fk_angajat_in_este_asistat FOREIGN KEY(id_angajat) REFERENCES ANGAJAT(id_angajat) ON DELETE CASCADE
        );


-- Inserarea datelor in tabelele create:


-- DROP SEQUENCE SEQ_CATEGORIE;

-- Secventa pentru inserarea inregistrarilor in tabelul "CATEGORIE".
CREATE SEQUENCE SEQ_CATEGORIE
INCREMENT by 1
START WITH 0
MINVALUE -1
MAXVALUE 399
NOCYCLE;

INSERT INTO CATEGORIE
VALUES(SEQ_CATEGORIE.NEXTVAL, 'Placi video');
INSERT INTO CATEGORIE
VALUES(SEQ_CATEGORIE.NEXTVAL, 'Procesoare');
INSERT INTO CATEGORIE
VALUES(SEQ_CATEGORIE.NEXTVAL, 'Memorii');
INSERT INTO CATEGORIE
VALUES(SEQ_CATEGORIE.NEXTVAL, 'HDD');
INSERT INTO CATEGORIE
VALUES(SEQ_CATEGORIE.NEXTVAL, 'Adaptoare');
INSERT INTO CATEGORIE
VALUES(SEQ_CATEGORIE.NEXTVAL, 'PC-uri');
INSERT INTO CATEGORIE
VALUES(SEQ_CATEGORIE.NEXTVAL, 'Laptop-uri');

-- ROLLBACK;
-- COMMIT;

-- DROP SEQUENCE SEQ_PRODUS;

-- Secventa pentru inserarea inregistrarilor in tabelul "PRODUS".
CREATE SEQUENCE SEQ_PRODUS
INCREMENT by 5
START WITH 0
MINVALUE -1
NOCYCLE;

INSERT INTO PRODUS
VALUES(SEQ_PRODUS.NEXTVAL, 1, 'Componenta', 'Placa video Palit GeForce RTX 3090 GamingPro 24GB GDDR6X 384-bit', NULL, 'GIGABYTE', 'Da', 14999.99, 5);
INSERT INTO PRODUS
VALUES(SEQ_PRODUS.NEXTVAL, 2, 'Componenta', 'Procesor AMD Ryzen 5 3600 3.6GHz box', NULL, 'AMD', 'Da', 999.99, 5);
INSERT INTO PRODUS
VALUES(SEQ_PRODUS.NEXTVAL, 5, 'Accesoriu', 'Adaptor Gembird 1x HDMI 1.4 Male - 1x VGA Female', NULL, 'Gembird', 'Nu', 35.99, NULL);
INSERT INTO PRODUS
VALUES(SEQ_PRODUS.NEXTVAL, 6, 'Sistem', 'PC Gaming Raptor5, Intel i5-9400F 2.9GHz Coffee Lake, 16GB DDR4, 960GB SSD, RX 5600 XT 6GB GDDR6, Iluminare RGB', 'PC', 'Raptor5', 'Da', 4799.99, 4);
INSERT INTO PRODUS
VALUES(SEQ_PRODUS.NEXTVAL, 7, 'Sistem', 'Laptop Lenovo 15.6'' ThinkPad E15 Gen 2, FHD, Procesor Intel® Core™ i5-1135G7 (8M Cache, up to 4.20 GHz), 8GB DDR4, 256GB SSD, Intel Iris Xe, No OS, Black', 'Lenovo', 'Laptop', 'Nu', 3398.99, 5);
INSERT INTO PRODUS
VALUES(SEQ_PRODUS.NEXTVAL, 1, 'Componenta', 'Placa video PowerColor Radeon RX 6900 XT Red Devil 16GB GDDR6 256-bit', NULL, 'Red Devil', 'Da', 11999.99, NULL);
INSERT INTO PRODUS
VALUES(SEQ_PRODUS.NEXTVAL, 3, 'Componenta', 'Memorie Corsair Vengeance LPX Black 16GB DDR4 3200MHz CL16 Dual Channel Kit', NULL, 'Corsair', 'Da', 514.99, NULL);
INSERT INTO PRODUS
VALUES(SEQ_PRODUS.NEXTVAL, 4, 'Componenta', 'Hard disk Seagate BarraCuda 2TB SATA-III 7200RPM 256MB', NULL, 'Seagate', 'Da', 262.99, NULL);

-- ROLLBACK;
-- COMMIT;

-- DROP SEQUENCE SEQ_SERVICIU;

-- Secventa pentru inserarea inregistrarilor in tabelul "SERVICIU".
CREATE SEQUENCE SEQ_SERVICIU
INCREMENT by 1
START WITH 0
MINVALUE -1
NOCYCLE;

INSERT INTO SERVICIU
VALUES(SEQ_SERVICIU.NEXTVAL, 'Asamblare', 'Serviciu Asamblare Standard', 
'Asamblare sistem de calcul desktop de catre un specialist calificat.
 Instalare sistem de operare test. Verificare compatibilitate componente.
 Preinstalare sisteme de operare si aplicatii (daca s-au achizitionat)', 
159);
INSERT INTO SERVICIU
VALUES(SEQ_SERVICIU.NEXTVAL, 'Testare', 'Serviciu Testare Produs',
'Verificare functionalitate produs.
 Aplicabil oricarui produs comercializat.', 
135.99);
INSERT INTO SERVICIU
VALUES(SEQ_SERVICIU.NEXTVAL, 'Montare', 'Serviciu Montare Componenta',
'Montarea diverselor componente in sistemul de calcul: placa video,
 procesor, RAM, HDD, cooler pentru procesor, etc.',
59.99);
INSERT INTO SERVICIU
VALUES(SEQ_SERVICIU.NEXTVAL, 'Diagnosticare', 'Serviciu Diagnosticare Produs',
'Identificarea problemelor de functionare si furnizarea de recomandari.', 
119.99);
INSERT INTO SERVICIU
VALUES(SEQ_SERVICIU.NEXTVAL, 'Asamblare', 'Serviciu Asamblare Premium',
'Asamblare si testare sistem de calcul desktop de catre un specialist calificat.
 Cooling management. Wire management. Instalare sistem de operare test.
 Verificare compatibilitate componente. Testare sistem (rulare in conditii de stres 24 ore).
 Generarea unui raport operatiune asamblare premium. Updateuri la ultimele versiuni stabile (BIOS placa de baza). 
 Preinstalare sisteme de operare si aplicatii (daca s-au achizitionat).', 
249.99);

-- ROLLBACK;
-- COMMIT;

INSERT INTO ADRESA_LIVRARE
VALUES(1, 'Bucuresti', 'Mihai Eminescu', 1);
INSERT INTO ADRESA_LIVRARE
VALUES(2, 'Iasi', 'Morii', 12);
INSERT INTO ADRESA_LIVRARE
VALUES(3, 'Bucuresti', 'Unirii', 34);
INSERT INTO ADRESA_LIVRARE
VALUES(4, 'Constanta', 'Stejarul mic', 2);
INSERT INTO ADRESA_LIVRARE
VALUES(5, 'Bucuresti', 'Eroilor', 10);
INSERT INTO ADRESA_LIVRARE
VALUES(6, 'Bucuresti', 'Mihail Kogalniceanu', 8);

-- ROLLBACK;
-- COMMIT;

INSERT INTO CLIENT
VALUES(1, 'Aurel', 'Popescu-Mihai');
INSERT INTO CLIENT
VALUES(2, 'Carstea', 'Darian-Stefan');
INSERT INTO CLIENT
VALUES(3, 'Castan', 'Mirela');
INSERT INTO CLIENT
VALUES(4, 'Popa', 'Marcel-Radu');
INSERT INTO CLIENT
VALUES(5, 'Manole', 'Iuliana-Elena');
INSERT INTO CLIENT
VALUES(6, 'Florian', 'Andrei-Cosmin');

-- ROLLBACK;
-- COMMIT;

INSERT INTO CONT_SITE
VALUES(1, 'Utilizator Mihai', NULL, 'uzmihai2005@gmail.com');
INSERT INTO CONT_SITE
VALUES(2, 'Darian Stefan', 2, 'carsteastef@yahoo.com');
INSERT INTO CONT_SITE
VALUES(3, 'Mirela Castan', 3, 'mirela_c@gmail.com');
INSERT INTO CONT_SITE
VALUES(4, 'ANTON PAVEL MIHAI', NULL, 'apav_mihai@gmail.com');
INSERT INTO CONT_SITE
VALUES(5, 'Elena 2008', 5, 'elenamanole@yahoo.com');

-- ROLLBACK;
-- COMMIT;

INSERT INTO RECENZIE
VALUES(1, 5, 'Utilizator Mihai', TO_DATE('15-01-2021','dd-mm-yyyy'), 5);
INSERT INTO RECENZIE
VALUES(2, 10, 'Utilizator Mihai', TO_DATE('15-01-2021','dd-mm-yyyy'), 5);
INSERT INTO RECENZIE
VALUES(3, 20, 'Darian Stefan', TO_DATE('23-05-2020','dd-mm-yyyy'), 4);
INSERT INTO RECENZIE
VALUES(4, 25, 'Mirela Castan', TO_DATE('02-08-2019','dd-mm-yyyy'), 5);
INSERT INTO RECENZIE
VALUES(5, 25, 'Elena 2008', TO_DATE('11-09-2020','dd-mm-yyyy'), 5);
INSERT INTO RECENZIE
VALUES(6, 20, 'Darian Stefan', TO_DATE('23-05-2020','dd-mm-yyyy'), 4);

-- ROLLBACK;
-- COMMIT;

INSERT INTO DEPARTAMENT
VALUES(1, 'Relationare clienti');
INSERT INTO DEPARTAMENT
VALUES(2, 'Prestare servicii');
INSERT INTO DEPARTAMENT
VALUES(3, 'Intretinere website');
INSERT INTO DEPARTAMENT
VALUES(4, 'Inventar produse');
INSERT INTO DEPARTAMENT
VALUES(5, 'Securitate');

-- ROLLBACK;
-- COMMIT;

INSERT INTO ANGAJAT
VALUES(1, 2, 'Tehnician', 'Aurel', 'Tudor-Mihai', 7000, 'aurel_mihai@gmail.com', '0793333333');
INSERT INTO ANGAJAT
VALUES(2, 1, 'Tehnician', 'Mihail', 'Maria-Andreea', 4500, 'mariaandreea09@yahoo.com', '0791111111');
INSERT INTO ANGAJAT
VALUES(3, 1, 'Tehnician', 'Vladoi', 'Rares', 4000, 'raresVld@gmail.com', '0749999999');
INSERT INTO ANGAJAT
VALUES(4, 4, 'Tehnician', 'Grigorescu', 'Stefan', 4500, 'grgrsc_stf@yahoo.com', '0755555555');
INSERT INTO ANGAJAT
VALUES(5, 5, 'Paznic', 'Marian', 'Alexandru', 3300, 'marianalex3@yahoo.com', '0788888885');

-- ROLLBACK;
-- COMMIT;

INSERT INTO ESTE_COMPATIBIL
VALUES(2, 5);
INSERT INTO ESTE_COMPATIBIL
VALUES(2, 10);
INSERT INTO ESTE_COMPATIBIL
VALUES(2, 20);
INSERT INTO ESTE_COMPATIBIL
VALUES(2, 25);
INSERT INTO ESTE_COMPATIBIL
VALUES(2, 30);
INSERT INTO ESTE_COMPATIBIL
VALUES(4, 20);
INSERT INTO ESTE_COMPATIBIL
VALUES(4, 25);
INSERT INTO ESTE_COMPATIBIL
VALUES(3, 5);
INSERT INTO ESTE_COMPATIBIL
VALUES(3, 10);
INSERT INTO ESTE_COMPATIBIL
VALUES(3, 30);

-- ROLLBACK;
-- COMMIT;

INSERT INTO COMANDA
VALUES(1, 5, 1, 1, TO_DATE('20-09-2020','dd-mm-yyyy'), 14999.99);
INSERT INTO COMANDA
VALUES(2, 10, 1, 1, TO_DATE('20-09-2020','dd-mm-yyyy'), 999.99);
INSERT INTO COMANDA
VALUES(3, 20, 2, 3, TO_DATE('07-12-2019','dd-mm-yyyy'), 4799.99);
INSERT INTO COMANDA
VALUES(4, 25, 3, 4, TO_DATE('16-02-2019','dd-mm-yyyy'), 3398.99);
INSERT INTO COMANDA
VALUES(5, 25, 5, 2, TO_DATE('11-09-2020','dd-mm-yyyy'), 3398.99);
INSERT INTO COMANDA
VALUES(6, 30, 4, 5, TO_DATE('07-02-2021','dd-mm-yyyy'), 11999.99);
INSERT INTO COMANDA
VALUES(7, 15, 1, 5, TO_DATE('07-02-2021','dd-mm-yyyy'), 71.98);
INSERT INTO COMANDA
VALUES(8, 10, 4, 3, TO_DATE('07-02-2021','dd-mm-yyyy'), 999.99);
INSERT INTO COMANDA
VALUES(9, 15, 2, 3, TO_DATE('10-12-2019','dd-mm-yyyy'), 35.99);
INSERT INTO COMANDA
VALUES(10, 20, 6, 6, TO_DATE('20-05-2021','dd-mm-yyyy'), 4799.99);

-- ROLLBACK;
-- COMMIT;

INSERT INTO CUMPARA
VALUES(1, 2, 1, TO_DATE('20-09-2020','dd-mm-yyyy'));
INSERT INTO CUMPARA
VALUES(2, 5, 1, TO_DATE('20-09-2020','dd-mm-yyyy'));
INSERT INTO CUMPARA
VALUES(3, 2, 6, TO_DATE('14-04-2020','dd-mm-yyyy'));
INSERT INTO CUMPARA
VALUES(4, 3, 6, TO_DATE('14-04-2020','dd-mm-yyyy'));
INSERT INTO CUMPARA
VALUES(5, 2, 3, TO_DATE('16-02-2019','dd-mm-yyyy'));
INSERT INTO CUMPARA
VALUES(6, 4, 3, TO_DATE('16-02-2019','dd-mm-yyyy'));
INSERT INTO CUMPARA
VALUES(7, 2, 5, TO_DATE('11-09-2020','dd-mm-yyyy'));
INSERT INTO CUMPARA
VALUES(8, 4, 5, TO_DATE('11-09-2020','dd-mm-yyyy'));
INSERT INTO CUMPARA
VALUES(9, 2, 2, TO_DATE('07-12-2019','dd-mm-yyyy'));
INSERT INTO CUMPARA
VALUES(10, 2, 4, TO_DATE('07-02-2021','dd-mm-yyyy'));
INSERT INTO CUMPARA
VALUES(11, 3, 4, TO_DATE('08-02-2021','dd-mm-yyyy'));

-- ROLLBACK;
-- COMMIT;

INSERT INTO ESTE_ASISTAT
VALUES(1, 1, 1);
INSERT INTO ESTE_ASISTAT
VALUES(2, 1, 2);
INSERT INTO ESTE_ASISTAT
VALUES(3, 2, 1);
INSERT INTO ESTE_ASISTAT
VALUES(4, 2, 2);
INSERT INTO ESTE_ASISTAT
VALUES(5, 3, 1);
INSERT INTO ESTE_ASISTAT
VALUES(6, 3, 2);
INSERT INTO ESTE_ASISTAT
VALUES(7, 5, 1);
INSERT INTO ESTE_ASISTAT
VALUES(8, 5, 2);
INSERT INTO ESTE_ASISTAT
VALUES(9, 4, 3);
INSERT INTO ESTE_ASISTAT
VALUES(10, 4, 2);

-- ROLLBACK;
COMMIT;

-- 11.


-- Cererea 1:
-- Sa se afiseze numele vanzatorului si pretul tuturor produselor al caror rating
-- are o valoare egala 5, si care au fost cumparate de catre un client al carui nume
-- este Aurel, care detine o adresa de livrare in localitatea Bucuresti. Rezultatele
-- se vor ordona in ordine descrescatoare dupa pretul produselor.

SELECT vanzator, pret
FROM PRODUS p JOIN COMANDA co ON (p.id_produs = co.id_produs)
              JOIN CLIENT cl ON (co.id_client = cl.id_client)
              JOIN ADRESA_LIVRARE a_l ON (co.id_adresa = a_l.id_adresa)
WHERE (average_rating = 5) AND (INITCAP(nume) = 'Aurel') AND (a_l.localitate = 'Bucuresti')
ORDER BY pret DESC;


-- Cererea 2:
-- Sa se afiseze numele intreg al clientilor carora li s-a realizat un serviciu de la 
-- inceputul anului si pana in prezent, alaturi de data la care s-au realizat serviciile
-- respective, unde serviciul respectiv este compatibil cu un produs recomandat pentru gaming.
-- Rezultatele se vor ordona in ordine crescatoare dupa numele intreg al clientilor.

SELECT CONCAT(nume, CONCAT(' ', prenume)) NUME_INTREG_CLIENT, data_realizare
FROM CLIENT cl JOIN CUMPARA cu ON(cl.id_client = cu.id_client)
WHERE cl.id_client IN (SELECT id_client
                    FROM CUMPARA, DUAL
                    WHERE data_realizare >= TRUNC(SYSDATE, 'YEAR')
                    AND id_serviciu IN (SELECT id_serviciu
                                        FROM SERVICIU
                                        WHERE id_serviciu IN (SELECT id_serviciu
                                                              FROM ESTE_COMPATIBIL
                                                              WHERE id_produs IN (SELECT id_produs
                                                                                 FROM PRODUS
                                                                                 WHERE UPPER(recomandat_pentru_gaming) = 'DA'))))
ORDER BY CONCAT(nume, CONCAT(' ', prenume));

    
-- Cererea 3:
-- Sa se afiseze numele departamentului, suma salariilor tuturor angajatilor, si numarul
-- de angajati, pentru fiecare departament in care lucreaza cel putin un agnajat. Se va
-- restrictiona afisarea doar la acele departamente pentru care suma tuturor salariilor
-- este mai mare sau egala cu 4000 RON.

WITH tabel_aux AS (SELECT denumire, SUM(salariu) AS suma_salarii, COUNT(id_angajat) AS nr_angajati
                   FROM DEPARTAMENT d join ANGAJAT a ON (d.id_departament = a.id_departament)
                   GROUP BY denumire
                   HAVING SUM(salariu) >= 4000)

SELECT denumire, suma_salarii, nr_angajati
FROM tabel_aux
ORDER BY denumire;


-- Cererea 4:
-- Sa se afiseze numele de utilizator, alaturi de id-ul de client, pentru conturile
-- care au scris recenzii pentru produse, avand un numar de stele egal cu rating-ul mediu
-- al produselor respective. In cazul in care un anumit cont nu este detinut de catre un
-- client cunoscut, se va afisa, in locul id-ului de client, mesajul "Contul nu apartine
-- unui client cunoscut.".

SELECT nume_utilizator, DECODE(TO_CHAR(id_client), NULL, 'Contul nu apartine unui client cunoscut.', TO_CHAR(id_client)) ID_CLIENT
FROM CONT_SITE
WHERE nume_utilizator IN (SELECT nume_utilizator
                          FROM RECENZIE
                          WHERE id_produs IN (SELECT id_produs
                                              FROM PRODUS
                                              WHERE nr_stele = average_rating));


-- Cererea 5:
-- Sa se afiseze denumirea, alaturi de numele vanzatorului, pentru produsele al caror
-- pret depaseste pretul mediu al produselor din aceeasi categorie cu acestea. De asemenea,
-- pentru fiecare produs, se va afisa si mesajul "Produsul este profitabil.", in cazul in
-- care produsul are un rating mai mare decat 3.5, respectiv mesajul "Nu se poate deduce statusul
-- produsului.", in caz contrar. Daca pentru un anumit produs nu se cunoaste numele 
-- vanzatorului, se va afisa mesajul "Vanzator necunoscut.".

SELECT denumire, NVL(vanzator, 'Vanzator necunoscut.') VANZATOR,
       CASE WHEN average_rating >= 3.5 THEN 'Produsul este profitabil.'
            ELSE 'Nu se poate deduce statusul produsului.' END STATUS_PRODUS
FROM PRODUS p
WHERE pret > (SELECT AVG(pret)
              FROM PRODUS
              WHERE p.id_categorie = id_categorie);



-- 12.


SAVEPOINT sp;

-- Sa se stearga toate produsele care fac parte din categoria cu id-ul 1.
DELETE 
FROM PRODUS
WHERE id_categorie IN (SELECT id_categorie
                         FROM PRODUS
                         WHERE id_categorie = 1);
    
-- Sa se stearga toate adresele de livrare la care au fost livrate produse
-- care nu sunt recomandate pentru gaming.
DELETE 
FROM ADRESA_LIVRARE
WHERE id_adresa IN (SELECT id_adresa
                    FROM COMANDA
                    WHERE id_produs IN (SELECT id_produs
                                        FROM PRODUS
                                        WHERE UPPER(recomandat_pentru_gaming) = 'NU'));
    
-- Sa se stearga toate conturile care nu au scris nicio recenzie.
DELETE
FROM CONT_SITE
WHERE nume_utilizator NOT IN (SELECT nume_utilizator
                              FROM RECENZIE);
SELECT * FROM CONT_SITE;
ROLLBACK TO SAVEPOINT sp;



-- 16.


-- Cerere care utilizeaza operatia outer-join pe minimum 4 tabele:

-- Sa se afiseze numele intreg, alaturi de numele de utilizator, al clientilor cunoscuti
-- (adica cei care figureaza in tabelul CLIENT), si numele tuturor produselor carora le-au
-- dat un rating, alaturi de rating-ul respectiv. Daca exista clienti care nu au conuri,
-- se va afisa mesajul "Clientul nu are cont.".

SELECT nume||' '||prenume NUME_INTREG,
       CASE WHEN c_s.nume_utilizator IS NOT NULL THEN c_s.nume_utilizator 
            ELSE 'Clientul nu are cont.' END NUME_UTILIZATOR,
       denumire, nr_stele
FROM CLIENT cl LEFT OUTER JOIN CONT_SITE c_s ON (cl.id_client = c_s.id_client)
               LEFT OUTER JOIN RECENZIE r ON (c_s.nume_utilizator = r.nume_utilizator)
               LEFT OUTER JOIN PRODUS p ON (r.id_produs = p.id_produs);


-- Cele doua cereri care utilizeaza operatia division:

-- Sa se afiseze numele intreg, alaturi de salariul angajatilor care au asistat cel putin
-- aceeasi clienti ca si angajatul cu codul 1.
 
SELECT a.nume||' '||a.prenume NUME_ANGAJAT, salariu
FROM ANGAJAT a JOIN ESTE_ASISTAT e_a ON (a.id_angajat = e_a.id_angajat)
               JOIN CLIENT c ON (e_a.id_client = c.id_client)
WHERE c.id_client IN (SELECT id_client
                      FROM ESTE_ASISTAT
                      WHERE id_angajat = 1)
      AND a.id_angajat != 1
GROUP BY a.nume||' '||a.prenume, salariu
HAVING COUNT(*) = (SELECT COUNT(id_client)
                   FROM ESTE_ASISTAT
                   WHERE id_angajat = 1);

-- Sa se afiseze denumirea si pretul produselor care sunt compatibile cu exact aceleasi
-- servicii ca si produsul cu id-ul 5.

SELECT p.denumire, p.pret
FROM PRODUS p JOIN ESTE_COMPATIBIL e_c ON (p.id_produs = e_c.id_produs)
              JOIN SERVICIU s ON (e_c.id_serviciu = s.id_serviciu)
WHERE s.id_serviciu IN (SELECT id_serviciu
                        FROM ESTE_COMPATIBIL
                        WHERE id_produs = 5)
      AND p.id_produs != 5
GROUP BY p.denumire, p.pret
HAVING COUNT(*) = (SELECT COUNT(id_serviciu)
                   FROM ESTE_COMPATIBIL
                   WHERE id_produs = 5)
                    
MINUS

SELECT p.denumire, p.pret
FROM PRODUS p JOIN ESTE_COMPATIBIL e_c ON (p.id_produs = e_c.id_produs)
              JOIN SERVICIU s ON (e_c.id_serviciu = s.id_serviciu)
WHERE s.id_serviciu NOT IN (SELECT id_serviciu
                            FROM ESTE_COMPATIBIL
                            WHERE id_produs = 5);



-- 17.


-- Vom optimiza cererea 1 de la exercitiul 11:

-- Sa se afiseze numele vanzatorului si pretul tuturor produselor al caror rating
-- are o valoare egala 5, si care au fost cumparate de catre un client al carui nume
-- este Aurel, care detine o adresa de livrare in localitatea Bucuresti. Rezultatele
-- se vor ordona in ordine descrescatoare dupa pretul produselor.

-- Cererea SQL:

SELECT vanzator, pret
FROM PRODUS p JOIN COMANDA co ON (p.id_produs = co.id_produs)
              JOIN CLIENT cl ON (co.id_client = cl.id_client)
              JOIN ADRESA_LIVRARE a_l ON (co.id_adresa = a_l.id_adresa)
WHERE (average_rating = 5) AND (INITCAP(nume) = 'Aurel') AND (a_l.localitate = 'Bucuresti')
ORDER BY pret DESC;

-- Expresia algebrica:

R1 = SELECT(ADRESA_LIVRARE, localitate = 'Bucuresti')
R2 = PROJECT(R1, id_adresa)
R3 = PROJECT(COMANDA, id_produs, id_client, id_adresa)
R4 = SEMIJOIN(R3, R2, id_adresa)
R5 = SELECT(CLIENT, nume = 'Aurel')
R6 = PROJECT(R5, id_client)
R7 = SEMIJOIN(R4, R6, id_client)
R8 = SELECT(PRODUS, average_rating = 5)
R9 = PROJECT(R8, vanzator, pret, id_produs)
R10 = SEMIJOIN(R9, R7, id_produs)
REZULTAT = R11 = PROJECT(R10, vanzator, pret)
