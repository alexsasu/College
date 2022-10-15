-- Cerinta 4.:

CREATE TABLE CATEGORIE
       (id_categorie INTEGER,
        denumire VARCHAR2(40) CONSTRAINT denumire_categorie NOT NULL,
        CONSTRAINT pk_categorie PRIMARY KEY(id_categorie),
        CONSTRAINT u_denumire_categorie UNIQUE(denumire)
        );
        
CREATE TABLE PRODUS
       (id_produs INTEGER,
        id_categorie INTEGER CONSTRAINT id_categorie_produs NOT NULL,
        tip VARCHAR(10) CONSTRAINT tip_produs NOT NULL,
        denumire VARCHAR2(200) CONSTRAINT denumire_produs NOT NULL,
        tip_sistem VARCHAR2(30),
        vanzator VARCHAR2(40) CONSTRAINT vanzator_produs NOT NULL,
        recomandat_pentru_gaming VARCHAR2(2),
        pret NUMBER CONSTRAINT pret_produs NOT NULL,
        average_rating NUMBER,
        CONSTRAINT pk_produs PRIMARY KEY(id_produs),
        CONSTRAINT fk_categorie_in_produs FOREIGN KEY(id_categorie) REFERENCES CATEGORIE(id_categorie) ON DELETE CASCADE
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





-- Cerinta 5.:

-- Secventa pentru inserarea inregistrarilor in tabelul "CATEGORIE":
CREATE SEQUENCE SEQ_CATEGORIE
INCREMENT by 1
START WITH 0
MINVALUE -1
MAXVALUE 399
NOCYCLE;
-- DROP SEQUENCE SEQ_CATEGORIE;

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

-- Secventa pentru inserarea inregistrarilor in tabelul "PRODUS":
CREATE SEQUENCE SEQ_PRODUS
INCREMENT by 5
START WITH 0
MINVALUE -1
NOCYCLE;
-- DROP SEQUENCE SEQ_PRODUS;

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
INSERT INTO PRODUS
VALUES(SEQ_PRODUS.NEXTVAL, 5, 'Accesoriu', 'Adaptor Gembird 1x HDMI 1.4 Male - 1x VGA Female', NULL, 'Vanzator 1', 'Nu', 47.99, 2);

-- ROLLBACK;
-- COMMIT;

-- Secventa pentru inserarea inregistrarilor in tabelul "SERVICIU":
CREATE SEQUENCE SEQ_SERVICIU
INCREMENT by 1
START WITH 0
MINVALUE -1
NOCYCLE;
-- DROP SEQUENCE SEQ_SERVICIU;

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
INSERT INTO CLIENT
VALUES(7, 'Aurel', 'Marcel-Stoian');

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
VALUES(1, 5, 'Utilizator Mihai', TO_DATE('15-01-2021','dd-mm-yyyy'), 3);
INSERT INTO RECENZIE
VALUES(2, 10, 'Utilizator Mihai', TO_DATE('15-01-2021','dd-mm-yyyy'), 5);
INSERT INTO RECENZIE
VALUES(3, 20, 'Darian Stefan', TO_DATE('23-05-2020','dd-mm-yyyy'), 4);
INSERT INTO RECENZIE
VALUES(4, 25, 'Mirela Castan', TO_DATE('02-08-2019','dd-mm-yyyy'), 5);
INSERT INTO RECENZIE
VALUES(5, 25, 'Elena 2008', TO_DATE('11-09-2020','dd-mm-yyyy'), 5);
INSERT INTO RECENZIE
VALUES(6, 15, 'Darian Stefan', TO_DATE('15-02-2020','dd-mm-yyyy'), 3);
INSERT INTO RECENZIE
VALUES(7, 15, 'Utilizator Mihai', TO_DATE('14-07-2020','dd-mm-yyyy'), 3);
INSERT INTO RECENZIE
VALUES(8, 35, 'Utilizator Mihai', TO_DATE('06-09-2021','dd-mm-yyyy'), 4);

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
VALUES(4, 5);
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
INSERT INTO ESTE_COMPATIBIL
VALUES(1, 10);

-- ROLLBACK;
-- COMMIT;

INSERT INTO COMANDA
VALUES(1, 5, 1, 1, TO_DATE('20-09-2020','dd-mm-yyyy'), 14999.99);
INSERT INTO COMANDA
VALUES(11, 5, 1, 1, TO_DATE('20-09-2020','dd-mm-yyyy'), 14999.99);
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
INSERT INTO CUMPARA
VALUES(12, 2, 1, TO_DATE('20-10-2021','dd-mm-yyyy'));

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





-- Cerinta 6.:

-- Enunt:
-- Pentru toti clientii care au acelasi nume ca un nume introdus de la tastatura,
-- sa se afiseze id-ul, numele complet, si pretul tuturor produselor care au fost comandate
-- de catre acestia, in ordine alfabetica a numelor produselor. Pentru fiecare produs
-- al fiecarui client se va afisa un numar de ordine. In cazul in care un anumit client
-- nu a comandat niciun produs, se va afisa un mesaj corespunzator.
-- Sa se trateze exceptii care pot aparea.

CREATE OR REPLACE PROCEDURE EX6_PROC
        (v_nume IN CLIENT.nume%TYPE)
    IS
        v_prenume CLIENT.prenume%TYPE;
        v_id CLIENT.id_client%TYPE;
    
        TYPE tab_imb_id_cli IS TABLE OF CLIENT.id_client%TYPE;
        t_id_cli tab_imb_id_cli;
    
        v_nr_clienti NUMBER;
        
        TYPE tab_imb_id_prod IS TABLE OF PRODUS.id_produs%TYPE;
        t_id_prod tab_imb_id_prod;

        TYPE tab_ind_nume_prod IS TABLE OF PRODUS.denumire%TYPE
                                  INDEX BY PLS_INTEGER;
        t_nume_prod tab_ind_nume_prod;
    
        TYPE vector_pret_prod IS VARRAY(2000) OF PRODUS.pret%TYPE;
        vect_pret_prod vector_pret_prod := vector_pret_prod();
        
        v_contor NUMBER;
    BEGIN
        SELECT COUNT(nume)
        INTO v_nr_clienti
        FROM CLIENT
        WHERE UPPER(nume) = UPPER(v_nume);
    
        IF v_nr_clienti = 0 THEN
            RAISE NO_DATA_FOUND;
        ELSE
            SELECT id_client
            BULK COLLECT INTO t_id_cli
            FROM CLIENT
            WHERE UPPER(nume) = UPPER(v_nume);
                
            FOR i IN t_id_cli.FIRST..t_id_cli.LAST LOOP
                SELECT DISTINCT p.id_produs, denumire, pret
                BULK COLLECT INTO t_id_prod, t_nume_prod, vect_pret_prod
                FROM PRODUS p JOIN COMANDA co ON p.id_produs = co.id_produs
                              JOIN CLIENT cl ON co.id_client = cl.id_client
                WHERE cl.id_client = t_id_cli(i)
                ORDER BY 2;
                    
                SELECT prenume
                INTO v_prenume
                FROM CLIENT
                WHERE id_client = t_id_cli(i);
                
                IF t_id_prod.COUNT = 0 THEN
                    DBMS_OUTPUT.PUT_LINE('------------------------------------------');
                    DBMS_OUTPUT.PUT_LINE('Clientul cu id-ul ' || t_id_cli(i) || ', pe nume ' || v_nume || ' ' || v_prenume || ', nu a comandat niciun produs!');
                    DBMS_OUTPUT.PUT_LINE('------------------------------------------');                
                ELSE
                    v_contor := 1;
                    
                    DBMS_OUTPUT.PUT_LINE('------------------------------------------');
                    DBMS_OUTPUT.PUT_LINE('Clientul cu id-ul ' || t_id_cli(i) || ', pe nume ' || v_nume || ' ' || v_prenume || ', a achizitionat produsele: ');
                    DBMS_OUTPUT.NEW_LINE;
                    
                    FOR i IN t_id_prod.FIRST..t_id_prod.LAST LOOP
                        DBMS_OUTPUT.PUT_LINE(v_contor || '.');
                        DBMS_OUTPUT.PUT_LINE('Id produs: ' || t_id_prod(i));
                        DBMS_OUTPUT.PUT_LINE('Denumire produs: ' || t_nume_prod(i));
                        DBMS_OUTPUT.PUT_LINE('Pret produs: ' || vect_pret_prod(i));
                        
                        IF i <> t_id_prod.LAST THEN
                            DBMS_OUTPUT.NEW_LINE;
                        END IF;
                        
                        v_contor := v_contor + 1;
                    END LOOP;
                    
                    DBMS_OUTPUT.PUT_LINE('------------------------------------------');
                END IF;
                
                DBMS_OUTPUT.NEW_LINE;
            END LOOP;
        END IF;
    EXCEPTION
        WHEN NO_DATA_FOUND THEN
            DBMS_OUTPUT.PUT_LINE('Nu exista niciun client cu numele ' || v_nume || '!');
        WHEN OTHERS THEN
            DBMS_OUTPUT.PUT_LINE('A aparut alta eroare!');
    END EX6_PROC;
/

DECLARE
    v_nume CLIENT.nume%TYPE := '&p_nume';
BEGIN
    EX6_PROC(v_nume);
END;
/





-- Cerinta 7.:

-- Enunt:
-- Prin intermediul unei functii stocate, sa se afiseze, pentru fiecare angajat care a
-- asistat clienti, numele complet al acestuia (nume + prenume), alaturi de lista numelor
-- complete a clientilor asistati, ordonand rezultatele alfabetic dupa numele angajatilor.
-- Tot prin intermediul functiei stocate, se va returna numarul de angajati care au
-- asistat clienti, urmand sa se afiseze mesajul "Personal inactiv!" in cazul in care
-- numarul este mai mic decat jumatate din numarul total de angajati, respectiv mesajul
-- "Personal activ!" in caz contrar, si se va obtine (printr-un parametru de tip OUT) si
-- afisa numarul de clienti asistati de catre un angajat al carui cod este introdus de
-- la tastatura.
-- Sa se trateze exceptii care pot aparea.
-- Rezolvati problema folosind ciclu cursoare cu subcereri, stiind ca nu este permisa
-- folosirea colectiilor de date.

CREATE OR REPLACE FUNCTION EX7_FUNC
        (p_id_ang IN ANGAJAT.id_angajat%TYPE,
         p_nr_cli_asist_ang OUT NUMBER)
        RETURN NUMBER
    IS
        v_nr_ang_activi NUMBER;
        v_nr_cli_asist_ang NUMBER;
    BEGIN
        p_nr_cli_asist_ang := 0;
        
        FOR i IN (SELECT id_angajat, nume || ' ' || prenume nume_ang
                  FROM ANGAJAT a
                  ORDER BY 2) LOOP
            
            SELECT COUNT(DISTINCT nume || ' ' || prenume)
            INTO v_nr_cli_asist_ang
            FROM CLIENT c JOIN ESTE_ASISTAT ea ON c.id_client = ea.id_client
            WHERE ea.id_angajat = i.id_angajat;
            
            IF v_nr_cli_asist_ang > 0 THEN
                    v_nr_ang_activi := v_nr_ang_activi + 1;
                    
                    DBMS_OUTPUT.PUT_LINE('------------------------------------------');
                    DBMS_OUTPUT.PUT_LINE('Id angajat: ' || i.id_angajat);
                    DBMS_OUTPUT.PUT_LINE('Nume angajat: ' || i.nume_ang);
                    DBMS_OUTPUT.NEW_LINE;
                    
                    DBMS_OUTPUT.PUT_LINE('Clienti asistati de catre angajat: ');
            
                    FOR j IN (SELECT DISTINCT nume || ' ' || prenume nume_cli
                              FROM CLIENT c JOIN ESTE_ASISTAT ea ON c.id_client = ea.id_client
                              WHERE ea.id_angajat = i.id_angajat) LOOP
                        
                        DBMS_OUTPUT.PUT_LINE(j.nume_cli);
                    END LOOP;
                    
                    DBMS_OUTPUT.PUT_LINE('------------------------------------------');
                    DBMS_OUTPUT.NEW_LINE;
            END IF;
            
            IF i.id_angajat = p_id_ang THEN
                p_nr_cli_asist_ang := v_nr_cli_asist_ang;
            END IF;
        END LOOP;
        
       RETURN v_nr_ang_activi;
    EXCEPTION
        WHEN OTHERS THEN
            DBMS_OUTPUT.PUT_LINE('A aparut o eroare necunoscuta!');
    END EX7_FUNC;
/

DECLARE
    v_id_ang ANGAJAT.id_angajat%TYPE := &p_id;
    v_nr_cli_asist_ang NUMBER;
    
    v_nr_ang NUMBER;
BEGIN
    SELECT COUNT(id_angajat)
    INTO v_nr_ang
    FROM ANGAJAT;
    
    SELECT id_angajat
    INTO v_id_ang
    FROM ANGAJAT
    WHERE id_angajat = v_id_ang;

    IF EX7_FUNC(v_id_ang, v_nr_cli_asist_ang) < v_nr_ang/2 THEN
        DBMS_OUTPUT.PUT_LINE('Status personal:');
        DBMS_OUTPUT.PUT_LINE('Personal inactiv!');
    ELSE
        DBMS_OUTPUT.PUT_LINE('Status personal:');
        DBMS_OUTPUT.PUT_LINE('Personal activ!');
    END IF;
    
    DBMS_OUTPUT.NEW_LINE;
    
    DBMS_OUTPUT.PUT_LINE('Numarul de clienti asistati de catre angajatul cu id-ul ' || v_id_ang || ': ' || v_nr_cli_asist_ang || '.');
EXCEPTION
    WHEN NO_DATA_FOUND THEN
        DBMS_OUTPUT.PUT_LINE('Nu exista niciun angajat cu id-ul ' || v_id_ang || '!');
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('A aparut alta eroare!');
END;
/





-- Cerinta 8.:

-- Enunt:
-- Pentru un cont al carui nume de utilizator este dat de la tastatura, sa se
-- afiseze id-ul clientului care il detine. In cazul in care contul nu este detinut
-- de catre un client cunoscut, se va afisa un mesaj corespunzator. Totodata, se va
-- afisa, pentru top 3 recenzii (in functie de numarul de stele) scrise de catre cont,
-- id-ul recenziei, numarul de stele, si numele produsului pentru care a fost scrisa
-- recenzia. In caz ca exista mai multe recenzii care au acelasi numar de stele, si
-- sunt eligibile pentru a se afla in top, se vor afisa informatii despre toate aceste
-- recenzii. De asemenea, daca utilizatorul nu a scris nicio recenzie, se va afisa un
-- mesaj corespunzator.
-- Mai mult, pentru numele de utilizator specificat, sa se returneze si afiseze numarul
-- de recenzii scrise de catre contul asociat.
-- Sa se trateze toate exceptiile care pot aparea.

CREATE OR REPLACE FUNCTION EX8_FUNC
        (v_nume_utilizator IN CONT_SITE.nume_utilizator%TYPE)
        RETURN NUMBER
    IS
        v_id_cont CONT_SITE.id_cont%TYPE;
    
        v_id_client CLIENT.id_client%TYPE;
    
        v_id_recenzie RECENZIE.id_recenzie%TYPE;
        v_nr_stele RECENZIE.nr_stele%TYPE;
        v_nr_stele_precedent RECENZIE.nr_stele%TYPE := 0;
        v_nume_produs PRODUS.denumire%TYPE;
    
        v_nr_stele_min RECENZIE.nr_stele%TYPE;
    
        TYPE ref_info_recenzii IS REF CURSOR;
        c_info_recenzii ref_info_recenzii;
    
        CURSOR c_recenzii IS
            SELECT id_client,
                   CURSOR (SELECT id_recenzie, nr_stele, denumire
                           FROM RECENZIE r JOIN PRODUS p ON r.id_produs = p.id_produs
                           WHERE nume_utilizator = v_nume_utilizator
                           ORDER BY 2 DESC)
            FROM CONT_SITE
            WHERE nume_utilizator = v_nume_utilizator;
            
        v_contor NUMBER := 0;
        v_top NUMBER := 0;
    BEGIN
        SELECT id_cont
        INTO v_id_cont
        FROM CONT_SITE
        WHERE nume_utilizator = v_nume_utilizator;
        
        DBMS_OUTPUT.PUT_LINE('Id cont: ' || v_id_cont);
        DBMS_OUTPUT.PUT_LINE('Nume utilizator cont: ' || v_nume_utilizator);
        
        OPEN c_recenzii;
            
        FETCH c_recenzii INTO v_id_client, c_info_recenzii;
        
        IF v_id_client IS NULL THEN
            DBMS_OUTPUT.PUT_LINE('Contul nu este detinut de catre un client cunoscut.');
        ElSE
            DBMS_OUTPUT.PUT_LINE('Id client: ' || v_id_client);
        END IF;
        
        DBMS_OUTPUT.NEW_LINE;
        
        SELECT MIN(distincte)
        INTO v_nr_stele_min
        FROM (SELECT DISTINCT nr_stele distincte
              FROM RECENZIE
              WHERE nume_utilizator = v_nume_utilizator
              ORDER BY distincte DESC)
        WHERE ROWNUM <= 3;
        
        FETCH c_info_recenzii INTO v_id_recenzie, v_nr_stele, v_nume_produs;
        
        IF c_info_recenzii%ROWCOUNT = 1 THEN
            DBMS_OUTPUT.PUT_LINE('Top 3 recenzii ale contului: ');
            
            LOOP
                v_contor := v_contor + 1;
            
                IF v_nr_stele <> v_nr_stele_precedent THEN
                    v_top := v_top + 1;
                    v_nr_stele_precedent := v_nr_stele;
                END IF;
                
                IF v_nr_stele >= v_nr_stele_min THEN
                    DBMS_OUTPUT.PUT_LINE(v_top || '. Id recenzie: ' || v_id_recenzie || ' | Nr. stele: ' || v_nr_stele || ' | Nume produs: ' || v_nume_produs);
                END IF;
                
                FETCH c_info_recenzii INTO v_id_recenzie, v_nr_stele, v_nume_produs;
                
                EXIT WHEN c_info_recenzii%NOTFOUND;
            END LOOP;
        ELSE
            DBMS_OUTPUT.PUT_LINE('Utilizatorul nu a scris nicio recenzie.');
        END IF;
                
        DBMS_OUTPUT.NEW_LINE;
        
        CLOSE c_recenzii;
        
        RETURN v_contor;
    EXCEPTION
        WHEN NO_DATA_FOUND THEN 
            RAISE_APPLICATION_ERROR(-20000, 'Nu exista niciun cont cu numele de utilizator ' || v_nume_utilizator || '!');
        WHEN OTHERS THEN
            RAISE_APPLICATION_ERROR(-20002, 'A aparut alta eroare!');
    END EX8_FUNC;
/

DECLARE
    v_nume_utilizator CONT_SITE.nume_utilizator%TYPE := '&p_nume_utilizator';
    v_nr_recenzii NUMBER;
BEGIN
    v_nr_recenzii := EX8_FUNC(v_nume_utilizator);
    
    IF v_nr_recenzii > 0 THEN
        IF v_nr_recenzii > 1 THEN
            DBMS_OUTPUT.PUT_LINE('Contul cu numele de utilizator ' || v_nume_utilizator || ' a scris ' || v_nr_recenzii || ' recenzii.');
        ELSE
            DBMS_OUTPUT.PUT_LINE('Contul cu numele de utilizator ' || v_nume_utilizator || ' a scris o recenzie.');
        END IF;
    END IF;
END;
/





-- Cerinta 9.:

-- Enunt:
-- Pentru un produs al carui nume este introdus de la tastatura, sa se afiseze id-ul
-- si numele tuturor serviciilor compatibile cu acesta. In plus, sa se afiseze si
-- id-ul, alaturi de numele complet (nume + prenume) al tuturor clientilor care au
-- cumparat un anumit serviciu compatibil cu produsul. In caz ca produsul nu este
-- compatibil cu niciun serviciu, sau in caz ca nu exista clienti care au cumparat
-- un anumit serviciu compatibil cu produsul, se vor afisa mesaje corespunzatoare.
-- Rezultatele se vor afisa in ordine alfabetica a numelor serviciilor, cat si a
-- numelor clientilor.
-- Sa se trateze toate exceptiile care pot aparea.

CREATE OR REPLACE PROCEDURE EX9_PROC
        (v_nume_produs IN PRODUS.denumire%TYPE)
    IS
        v_id_produs PRODUS.id_produs%TYPE;
        
        v_id_serviciu SERVICIU.id_serviciu%TYPE;
        v_nume_serviciu SERVICIU.denumire%TYPE;
        
        TYPE tab_imb_id_cli IS TABLE OF CLIENT.id_client%TYPE;
        t_id_cli tab_imb_id_cli;
    
        TYPE tab_imb_nume_cli IS TABLE OF CLIENT.nume%TYPE;
        t_nume_cli tab_imb_nume_cli;
        
        TYPE ref_info_cli IS REF CURSOR;
        c_info_cli ref_info_cli;
    
        CURSOR c_date_servicii IS
            SELECT s.id_serviciu, s.denumire,
                    CURSOR (SELECT DISTINCT cl.id_client, nume || ' ' || prenume
                            FROM CLIENT cl JOIN CUMPARA cu ON cl.id_client = cu.id_client
                                           JOIN SERVICIU si ON cu.id_serviciu = si.id_serviciu
                            WHERE si.id_serviciu = s.id_serviciu
                            ORDER BY 2)
            FROM SERVICIU s JOIN ESTE_COMPATIBIL ec ON s.id_serviciu = ec.id_serviciu
                            JOIN PRODUS p ON ec.id_produs = p.id_produs
            WHERE UPPER(p.denumire) = UPPER(v_nume_produs)
            ORDER BY 2;
    BEGIN
        SELECT id_produs
        INTO v_id_produs
        FROM PRODUS
        WHERE UPPER(denumire) = UPPER(v_nume_produs);
        
        OPEN c_date_servicii;
        
        DBMS_OUTPUT.PUT_LINE('Id produs: ' || v_id_produs);
        DBMS_OUTPUT.PUT_LINE('Nume produs: ' || v_nume_produs);
        DBMS_OUTPUT.NEW_LINE;
        DBMS_OUTPUT.NEW_LINE;
        DBMS_OUTPUT.PUT_LINE('Lista serviciilor compatibile cu produsul:');
        
        LOOP
            FETCH c_date_servicii INTO v_id_serviciu, v_nume_serviciu, c_info_cli;
            
            IF c_date_servicii%NOTFOUND THEN
                IF c_date_servicii%ROWCOUNT = 0 THEN
                    DBMS_OUTPUT.PUT_LINE('Nu exista servicii compatibile!');
                END IF;
                
                EXIT;
            END IF;
            
            DBMS_OUTPUT.PUT_LINE('------------------------------------------');
            DBMS_OUTPUT.PUT_LINE('Id serviciu: ' || v_id_serviciu);
            DBMS_OUTPUT.PUT_LINE('Nume serviciu: ' || v_nume_serviciu);
            DBMS_OUTPUT.NEW_LINE;
            
            FETCH c_info_cli BULK COLLECT INTO t_id_cli, t_nume_cli;
            
            DBMS_OUTPUT.PUT_LINE('Lista clientilor care au cumparat serviciul:');
            
            IF t_id_cli.COUNT = 0 THEN
                DBMS_OUTPUT.PUT_LINE('Nu exista clienti care au cumparat serviciul.');
            ELSE
                FOR i IN t_id_cli.FIRST..t_id_cli.LAST LOOP
                    DBMS_OUTPUT.PUT_LINE('Id client: ' || t_id_cli(i) || ' | Nume client: ' || t_nume_cli(i));
                END LOOP;
            END IF;
            
            DBMS_OUTPUT.PUT_LINE('------------------------------------------');
            DBMS_OUTPUT.NEW_LINE;
            
        END LOOP;
        
        CLOSE c_date_servicii;
    EXCEPTION
        WHEN NO_DATA_FOUND THEN
            RAISE_APPLICATION_ERROR(-20000, 'Nu exista niciun produs cu numele ' || v_nume_produs || '!');
        WHEN TOO_MANY_ROWS THEN
            RAISE_APPLICATION_ERROR(-20001, 'Exista mai multe produse cu numele ' || v_nume_produs || '!');
        WHEN OTHERS THEN
            RAISE_APPLICATION_ERROR(-20002, 'A aparut alta eroare!');
    END EX9_PROC;
/

DECLARE
    v_nume_produs PRODUS.denumire%TYPE := '&p_nume_produs';
BEGIN
    EX9_PROC(v_nume_produs);
END;
/





-- Cerinta 10.:

CREATE OR REPLACE PROCEDURE EX10_PROC_AUX
    IS
        TYPE tab_imb_tipuri_servicii IS TABLE OF SERVICIU.tip%TYPE;
        t_tipuri_servicii tab_imb_tipuri_servicii;
    
        v_nr_servicii NUMBER;
    BEGIN
        SELECT DISTINCT tip
        BULK COLLECT INTO t_tipuri_servicii
        FROM SERVICIU
        ORDER BY 1;
        
        IF t_tipuri_servicii.COUNT > 0 THEN
            FOR i IN t_tipuri_servicii.FIRST..t_tipuri_servicii.LAST LOOP
                SELECT COUNT(*)
                INTO v_nr_servicii
                FROM SERVICIU
                WHERE tip = t_tipuri_servicii(i);
                
                IF v_nr_servicii = 1 THEN
                    DBMS_OUTPUT.PUT_LINE('  un serviciu de tipul ' || t_tipuri_servicii(i));
                ELSE
                    DBMS_OUTPUT.PUT_LINE('  ' || v_nr_servicii || ' servicii de tipul ' || t_tipuri_servicii(i));
                END IF;
            END LOOP;
        END IF;
    END EX10_PROC_AUX;
/

CREATE OR REPLACE TRIGGER EX10_TRIG_LMD_COM_BEFORE
        BEFORE INSERT OR DELETE ON SERVICIU
    DECLARE
        v_nr_inregistrari NUMBER;
    BEGIN
        SELECT COUNT (*) INTO v_nr_inregistrari FROM SERVICIU;

        IF INSERTING THEN
            IF v_nr_inregistrari >= 1000 THEN
                RAISE_APPLICATION_ERROR(-20003, 'Nu se mai pot insera inregistrari in tabel, deoarece acesta este prea plin!');
            END IF;
            
            DBMS_OUTPUT.PUT_LINE('-----------------------------------');
            
            IF v_nr_inregistrari <> 1 THEN
                DBMS_OUTPUT.PUT('Inainte de inserare, in tabelul SERVICIU se afla ' || v_nr_inregistrari || ' servicii');
                IF v_nr_inregistrari = 0 THEN
                    DBMS_OUTPUT.PUT_LINE('.');
                ELSE
                    DBMS_OUTPUT.PUT_LINE(':');
                END IF;
            ELSE
                DBMS_OUTPUT.PUT_LINE('Inainte de inserare, in tabelul SERVICIU se afla un serviciu:');
            END IF;
        ELSE
            IF v_nr_inregistrari <= 0 THEN
                RAISE_APPLICATION_ERROR(-20003, 'Nu se mai pot sterge inregistrari din tabel, deoarece acesta este gol!');
            END IF;
            
            DBMS_OUTPUT.PUT_LINE('-----------------------------------');
            
            IF v_nr_inregistrari <> 1 THEN
                DBMS_OUTPUT.PUT('Inainte de stergere, in tabelul SERVICIU se afla ' || v_nr_inregistrari || ' servicii');
                IF v_nr_inregistrari = 0 THEN
                    DBMS_OUTPUT.PUT_LINE('.');
                ELSE
                    DBMS_OUTPUT.PUT_LINE(':');
                END IF;
            ELSE
                DBMS_OUTPUT.PUT_LINE('Inainte de stergere, in tabelul SERVICIU se afla un serviciu:');
            END IF;
        END IF;

        EX10_PROC_AUX;
    END EX10_TRIG_LMD_COM_BEFORE;
/

CREATE OR REPLACE TRIGGER EX10_TRIG_LMD_COM_AFTER
        AFTER INSERT OR DELETE ON SERVICIU
    DECLARE
        v_nr_inregistrari NUMBER;
    BEGIN
        SELECT COUNT (*) INTO v_nr_inregistrari FROM SERVICIU;
        
        DBMS_OUTPUT.NEW_LINE;

        IF INSERTING THEN
            IF v_nr_inregistrari <> 1 THEN
                DBMS_OUTPUT.PUT('Dupa inserare, in tabelul SERVICIU se afla ' || v_nr_inregistrari || ' servicii');
                IF v_nr_inregistrari = 0 THEN
                    DBMS_OUTPUT.PUT_LINE('.');
                ELSE
                    DBMS_OUTPUT.PUT_LINE(':');
                END IF;
            ELSE
                DBMS_OUTPUT.PUT_LINE('Dupa inserare, in tabelul SERVICIU se afla un serviciu:');
            END IF;
        ELSE
            IF v_nr_inregistrari <> 1 THEN
                DBMS_OUTPUT.PUT('Dupa stergere, in tabelul SERVICIU au mai ramas ' || v_nr_inregistrari || ' servicii');
                IF v_nr_inregistrari = 0 THEN
                    DBMS_OUTPUT.PUT_LINE('.');
                ELSE
                    DBMS_OUTPUT.PUT_LINE(':');
                END IF;
            ELSE
                DBMS_OUTPUT.PUT_LINE('Dupa stergere, in tabelul SERVICIU a mai ramas un serviciu:');
            END IF;
        END IF;
        
        EX10_PROC_AUX;
        
        DBMS_OUTPUT.PUT_LINE('-----------------------------------');
        DBMS_OUTPUT.NEW_LINE;
    END EX10_TRIG_LMD_COM_AFTER;
/

-- ALTER TRIGGER EX10_TRIG_LMD_COM_BEFORE DISABLE;
-- ALTER TRIGGER EX10_TRIG_LMD_COM_BEFORE ENABLE;
-- DROP TRIGGER EX10_TRIG_LMD_COM_BEFORE;

-- ALTER TRIGGER EX10_TRIG_LMD_COM_AFTER DISABLE;
-- ALTER TRIGGER EX10_TRIG_LMD_COM_AFTER ENABLE;
-- DROP TRIGGER EX10_TRIG_LMD_COM_AFTER;

DELETE
FROM SERVICIU
WHERE id_serviciu >= 2;





-- Cerinta 11.:

CREATE OR REPLACE PACKAGE EX11_PACHET_AUX
    AS
        TYPE tab_imb_id_min IS TABLE OF SERVICIU.id_serviciu%TYPE;
        TYPE tab_imb_id_max IS TABLE OF SERVICIU.id_serviciu%TYPE;
    
        TYPE PRET_SERVICIU_REC IS RECORD 
        (min SERVICIU.pret%TYPE, t_id_min tab_imb_id_min,
         max SERVICIU.pret%TYPE, t_id_max tab_imb_id_max,
         avg SERVICIU.pret%TYPE);
        
        v_pret PRET_SERVICIU_REC;
    END EX11_PACHET_AUX;
/

CREATE OR REPLACE TRIGGER EX11_TRIG_LMD_COM_BEFORE
        BEFORE UPDATE OF pret ON SERVICIU
    BEGIN
        SELECT MIN(pret), MAX(pret), ROUND(AVG(pret), 2)
        INTO EX11_PACHET_AUX.v_pret.min, EX11_PACHET_AUX.v_pret.max, EX11_PACHET_AUX.v_pret.avg
        FROM SERVICIU;
        
        SELECT id_serviciu
        BULK COLLECT INTO EX11_PACHET_AUX.v_pret.t_id_min
        FROM SERVICIU
        WHERE pret = EX11_PACHET_AUX.v_pret.min;
        
        SELECT id_serviciu
        BULK COLLECT INTO EX11_PACHET_AUX.v_pret.t_id_max
        FROM SERVICIU
        WHERE pret = EX11_PACHET_AUX.v_pret.max;
    END EX11_TRIG_LMD_COM_BEFORE;
/

CREATE OR REPLACE TRIGGER EX11_TRIG_LMD_LIN_BEFORE
        BEFORE UPDATE OF pret ON SERVICIU
        FOR EACH ROW
    BEGIN
        DBMS_OUTPUT.PUT_LINE('-----------------------------------');
        DBMS_OUTPUT.PUT_LINE('Serviciul cu id-ul ' || :NEW.id_serviciu || ', si pretul egal cu ' || :OLD.pret || ', va avea pretul egal cu ' || :NEW.pret || '.');

        DBMS_OUTPUT.NEW_LINE;

        DBMS_OUTPUT.PUT_LINE('Date actuale despre preturile din tabelul SERVICIU:');
        
        DBMS_OUTPUT.PUT('  Id-ul serviciilor care au pretul minim, adica pretul de ' || EX11_PACHET_AUX.v_pret.min || ': ');
        FOR i IN EX11_PACHET_AUX.v_pret.t_id_min.FIRST..EX11_PACHET_AUX.v_pret.t_id_min.LAST LOOP
            DBMS_OUTPUT.PUT(EX11_PACHET_AUX.v_pret.t_id_min(i) || ' ');
        END LOOP;
        DBMS_OUTPUT.NEW_LINE;
        
        DBMS_OUTPUT.PUT('  Id-ul serviciilor care au pretul maxim, adica pretul de ' || EX11_PACHET_AUX.v_pret.max || ': ');
        FOR i IN EX11_PACHET_AUX.v_pret.t_id_max.FIRST..EX11_PACHET_AUX.v_pret.t_id_max.LAST LOOP
            DBMS_OUTPUT.PUT(EX11_PACHET_AUX.v_pret.t_id_max(i) || ' ');
        END LOOP;
        DBMS_OUTPUT.NEW_LINE;
        
        DBMS_OUTPUT.PUT('  Pretul mediu al serviciilor: ' || EX11_PACHET_AUX.v_pret.avg);
        DBMS_OUTPUT.NEW_LINE;
        DBMS_OUTPUT.PUT_LINE('-----------------------------------');
        
        DBMS_OUTPUT.NEW_LINE;
        DBMS_OUTPUT.NEW_LINE;
    END EX11_TRIG_LMD_LIN_BEFORE;
/

-- ALTER TRIGGER EX11_TRIG_LMD_COM_BEFORE DISABLE;
-- ALTER TRIGGER EX11_TRIG_LMD_COM_BEFORE ENABLE;
-- DROP TRIGGER EX11_TRIG_LMD_COM_BEFORE;

-- ALTER TRIGGER EX11_TRIG_LMD_LIN_BEFORE DISABLE;
-- ALTER TRIGGER EX11_TRIG_LMD_LIN_BEFORE ENABLE;
-- DROP TRIGGER EX11_TRIG_LMD_LIN_BEFORE;

UPDATE SERVICIU
SET pret = 1.1 * pret
WHERE id_serviciu >= 3;

DELETE
FROM SERVICIU
WHERE id_serviciu >= 1;





-- Cerinta 12.:

CREATE TABLE INFORMATII_COMANDA_LDD
       (nume_bd VARCHAR2(50),
        user_logat VARCHAR2(30),
        eveniment VARCHAR2(20),
        data_comanda TIMESTAMP(3),
        tip_obiect_referit VARCHAR2(30),
        nume_obiect_referit VARCHAR2(30)
        );

CREATE OR REPLACE TRIGGER EX12_TRIG_LDD
        AFTER CREATE OR DROP ON SCHEMA
    BEGIN
        IF SYS.SYSEVENT = 'DROP' THEN
            DBMS_OUTPUT.PUT_LINE('A avut loc un eveniment de tipul DROP asupra schemei personale, pe un obiect de tipul ' || SYS.DICTIONARY_OBJ_TYPE || ', numit ' || SYS.DICTIONARY_OBJ_NAME || '.');
        ELSE
            DBMS_OUTPUT.PUT_LINE('A avut loc un eveniment de tipul CREATE asupra schemei personale, pe un obiect de tipul ' || SYS.DICTIONARY_OBJ_TYPE || ', numit ' || SYS.DICTIONARY_OBJ_NAME || '.');
        END IF;
        
        INSERT INTO INFORMATII_COMANDA_LDD
            VALUES (SYS.DATABASE_NAME,
                    SYS.LOGIN_USER,
                    SYS.SYSEVENT,
                    SYSTIMESTAMP(3),
                    SYS.DICTIONARY_OBJ_TYPE,
                    SYS.DICTIONARY_OBJ_NAME
                    );
    END EX12_TRIG_LDD;
/

-- ALTER TRIGGER EX12_TRIG_LDD DISABLE;
-- ALTER TRIGGER EX12_TRIG_LDD ENABLE;
-- DROP TRIGGER EX12_TRIG_LDD;

DROP TABLE SERVICIU;
SELECT * FROM INFORMATII_COMANDA_LDD;





-- Cerinta 13.:

CREATE OR REPLACE PACKAGE EX13_PACK
    IS
        PROCEDURE EX6_PROC(v_nume IN CLIENT.nume%TYPE);
        FUNCTION EX7_FUNC(p_id_ang IN ANGAJAT.id_angajat%TYPE,
                          p_nr_cli_asist_ang OUT NUMBER)
                          RETURN NUMBER;
        FUNCTION EX8_FUNC(v_nume_utilizator IN CONT_SITE.nume_utilizator%TYPE)
                          RETURN NUMBER;
        PROCEDURE EX9_PROC(v_nume_produs IN PRODUS.denumire%TYPE);
        PROCEDURE EX10_PROC_AUX;
    END EX13_PACK;
/

CREATE OR REPLACE PACKAGE BODY EX13_PACK
    IS
        PROCEDURE EX6_PROC
                (v_nume IN CLIENT.nume%TYPE)
            IS
                v_prenume CLIENT.prenume%TYPE;
                v_id CLIENT.id_client%TYPE;
            
                TYPE tab_imb_id_cli IS TABLE OF CLIENT.id_client%TYPE;
                t_id_cli tab_imb_id_cli;
            
                v_nr_clienti NUMBER;
                
                TYPE tab_imb_id_prod IS TABLE OF PRODUS.id_produs%TYPE;
                t_id_prod tab_imb_id_prod;
        
                TYPE tab_ind_nume_prod IS TABLE OF PRODUS.denumire%TYPE
                                          INDEX BY PLS_INTEGER;
                t_nume_prod tab_ind_nume_prod;
            
                TYPE vector_pret_prod IS VARRAY(2000) OF PRODUS.pret%TYPE;
                vect_pret_prod vector_pret_prod := vector_pret_prod();
                
                v_contor NUMBER;
            BEGIN
                SELECT COUNT(nume)
                INTO v_nr_clienti
                FROM CLIENT
                WHERE UPPER(nume) = UPPER(v_nume);
            
                IF v_nr_clienti = 0 THEN
                    RAISE NO_DATA_FOUND;
                ELSE
                    SELECT id_client
                    BULK COLLECT INTO t_id_cli
                    FROM CLIENT
                    WHERE UPPER(nume) = UPPER(v_nume);
                        
                    FOR i IN t_id_cli.FIRST..t_id_cli.LAST LOOP
                        SELECT DISTINCT p.id_produs, denumire, pret
                        BULK COLLECT INTO t_id_prod, t_nume_prod, vect_pret_prod
                        FROM PRODUS p JOIN COMANDA co ON p.id_produs = co.id_produs
                                      JOIN CLIENT cl ON co.id_client = cl.id_client
                        WHERE cl.id_client = t_id_cli(i)
                        ORDER BY 2;
                            
                        SELECT prenume
                        INTO v_prenume
                        FROM CLIENT
                        WHERE id_client = t_id_cli(i);
                        
                        IF t_id_prod.COUNT = 0 THEN
                            DBMS_OUTPUT.PUT_LINE('------------------------------------------');
                            DBMS_OUTPUT.PUT_LINE('Clientul cu id-ul ' || t_id_cli(i) || ', pe nume ' || v_nume || ' ' || v_prenume || ', nu a comandat niciun produs!');
                            DBMS_OUTPUT.PUT_LINE('------------------------------------------');                
                        ELSE
                            v_contor := 1;
                            
                            DBMS_OUTPUT.PUT_LINE('------------------------------------------');
                            DBMS_OUTPUT.PUT_LINE('Clientul cu id-ul ' || t_id_cli(i) || ', pe nume ' || v_nume || ' ' || v_prenume || ', a achizitionat produsele: ');
                            DBMS_OUTPUT.NEW_LINE;
                            
                            FOR i IN t_id_prod.FIRST..t_id_prod.LAST LOOP
                                DBMS_OUTPUT.PUT_LINE(v_contor || '.');
                                DBMS_OUTPUT.PUT_LINE('Id produs: ' || t_id_prod(i));
                                DBMS_OUTPUT.PUT_LINE('Denumire produs: ' || t_nume_prod(i));
                                DBMS_OUTPUT.PUT_LINE('Pret produs: ' || vect_pret_prod(i));
                                
                                IF i <> t_id_prod.LAST THEN
                                    DBMS_OUTPUT.NEW_LINE;
                                END IF;
                                
                                v_contor := v_contor + 1;
                            END LOOP;
                            
                            DBMS_OUTPUT.PUT_LINE('------------------------------------------');
                        END IF;
                        
                        DBMS_OUTPUT.NEW_LINE;
                    END LOOP;
                END IF;
            EXCEPTION
                WHEN NO_DATA_FOUND THEN
                    DBMS_OUTPUT.PUT_LINE('Nu exista niciun client cu numele ' || v_nume || '!');
                WHEN OTHERS THEN
                    DBMS_OUTPUT.PUT_LINE('A aparut alta eroare!');
            END EX6_PROC;





        FUNCTION EX7_FUNC
                (p_id_ang IN ANGAJAT.id_angajat%TYPE,
                 p_nr_cli_asist_ang OUT NUMBER)
                RETURN NUMBER
            IS
                v_nr_ang_activi NUMBER;
                v_nr_cli_asist_ang NUMBER;
            BEGIN
                p_nr_cli_asist_ang := 0;
                
                FOR i IN (SELECT id_angajat, nume || ' ' || prenume nume_ang
                          FROM ANGAJAT a
                          ORDER BY 2) LOOP
                    
                    SELECT COUNT(DISTINCT nume || ' ' || prenume)
                    INTO v_nr_cli_asist_ang
                    FROM CLIENT c JOIN ESTE_ASISTAT ea ON c.id_client = ea.id_client
                    WHERE ea.id_angajat = i.id_angajat;
                    
                    IF v_nr_cli_asist_ang > 0 THEN
                            v_nr_ang_activi := v_nr_ang_activi + 1;
                            
                            DBMS_OUTPUT.PUT_LINE('------------------------------------------');
                            DBMS_OUTPUT.PUT_LINE('Id angajat: ' || i.id_angajat);
                            DBMS_OUTPUT.PUT_LINE('Nume angajat: ' || i.nume_ang);
                            DBMS_OUTPUT.NEW_LINE;
                            
                            DBMS_OUTPUT.PUT_LINE('Clienti asistati de catre angajat: ');
                    
                            FOR j IN (SELECT DISTINCT nume || ' ' || prenume nume_cli
                                      FROM CLIENT c JOIN ESTE_ASISTAT ea ON c.id_client = ea.id_client
                                      WHERE ea.id_angajat = i.id_angajat) LOOP
                                
                                DBMS_OUTPUT.PUT_LINE(j.nume_cli);
                            END LOOP;
                            
                            DBMS_OUTPUT.PUT_LINE('------------------------------------------');
                            DBMS_OUTPUT.NEW_LINE;
                    END IF;
                    
                    IF i.id_angajat = p_id_ang THEN
                        p_nr_cli_asist_ang := v_nr_cli_asist_ang;
                    END IF;
                END LOOP;
                
               RETURN v_nr_ang_activi;
            EXCEPTION
                WHEN OTHERS THEN
                    DBMS_OUTPUT.PUT_LINE('A aparut o eroare necunoscuta!');
            END EX7_FUNC;





        FUNCTION EX8_FUNC
                (v_nume_utilizator IN CONT_SITE.nume_utilizator%TYPE)
                RETURN NUMBER
            IS
                v_id_cont CONT_SITE.id_cont%TYPE;
            
                v_id_client CLIENT.id_client%TYPE;
            
                v_id_recenzie RECENZIE.id_recenzie%TYPE;
                v_nr_stele RECENZIE.nr_stele%TYPE;
                v_nr_stele_precedent RECENZIE.nr_stele%TYPE := 0;
                v_nume_produs PRODUS.denumire%TYPE;
            
                v_nr_stele_min RECENZIE.nr_stele%TYPE;
            
                TYPE ref_info_recenzii IS REF CURSOR;
                c_info_recenzii ref_info_recenzii;
            
                CURSOR c_recenzii IS
                    SELECT id_client,
                           CURSOR (SELECT id_recenzie, nr_stele, denumire
                                   FROM RECENZIE r JOIN PRODUS p ON r.id_produs = p.id_produs
                                   WHERE nume_utilizator = v_nume_utilizator
                                   ORDER BY 2 DESC)
                    FROM CONT_SITE
                    WHERE nume_utilizator = v_nume_utilizator;
                    
                v_contor NUMBER := 0;
                v_top NUMBER := 0;
            BEGIN
                SELECT id_cont
                INTO v_id_cont
                FROM CONT_SITE
                WHERE nume_utilizator = v_nume_utilizator;
                
                DBMS_OUTPUT.PUT_LINE('Id cont: ' || v_id_cont);
                DBMS_OUTPUT.PUT_LINE('Nume utilizator cont: ' || v_nume_utilizator);
                
                OPEN c_recenzii;
                    
                FETCH c_recenzii INTO v_id_client, c_info_recenzii;
                
                IF v_id_client IS NULL THEN
                    DBMS_OUTPUT.PUT_LINE('Contul nu este detinut de catre un client cunoscut.');
                ElSE
                    DBMS_OUTPUT.PUT_LINE('Id client: ' || v_id_client);
                END IF;
                
                DBMS_OUTPUT.NEW_LINE;
                
                SELECT MIN(distincte)
                INTO v_nr_stele_min
                FROM (SELECT DISTINCT nr_stele distincte
                      FROM RECENZIE
                      WHERE nume_utilizator = v_nume_utilizator
                      ORDER BY distincte DESC)
                WHERE ROWNUM <= 3;
                
                FETCH c_info_recenzii INTO v_id_recenzie, v_nr_stele, v_nume_produs;
                
                IF c_info_recenzii%ROWCOUNT = 1 THEN
                    DBMS_OUTPUT.PUT_LINE('Top 3 recenzii ale contului: ');
                    
                    LOOP
                        v_contor := v_contor + 1;
                    
                        IF v_nr_stele <> v_nr_stele_precedent THEN
                            v_top := v_top + 1;
                            v_nr_stele_precedent := v_nr_stele;
                        END IF;
                        
                        IF v_nr_stele >= v_nr_stele_min THEN
                            DBMS_OUTPUT.PUT_LINE(v_top || '. Id recenzie: ' || v_id_recenzie || ' | Nr. stele: ' || v_nr_stele || ' | Nume produs: ' || v_nume_produs);
                        END IF;
                        
                        FETCH c_info_recenzii INTO v_id_recenzie, v_nr_stele, v_nume_produs;
                        
                        EXIT WHEN c_info_recenzii%NOTFOUND;
                    END LOOP;
                ELSE
                    DBMS_OUTPUT.PUT_LINE('Utilizatorul nu a scris nicio recenzie.');
                END IF;
                        
                DBMS_OUTPUT.NEW_LINE;
                
                CLOSE c_recenzii;
                
                RETURN v_contor;
            EXCEPTION
                WHEN NO_DATA_FOUND THEN 
                    RAISE_APPLICATION_ERROR(-20000, 'Nu exista niciun cont cu numele de utilizator ' || v_nume_utilizator || '!');
                WHEN OTHERS THEN
                    RAISE_APPLICATION_ERROR(-20002, 'A aparut alta eroare!');
            END EX8_FUNC;





        PROCEDURE EX9_PROC
                (v_nume_produs IN PRODUS.denumire%TYPE)
            IS
                v_id_produs PRODUS.id_produs%TYPE;
                
                v_id_serviciu SERVICIU.id_serviciu%TYPE;
                v_nume_serviciu SERVICIU.denumire%TYPE;
                
                TYPE tab_imb_id_cli IS TABLE OF CLIENT.id_client%TYPE;
                t_id_cli tab_imb_id_cli;
            
                TYPE tab_imb_nume_cli IS TABLE OF CLIENT.nume%TYPE;
                t_nume_cli tab_imb_nume_cli;
                
                TYPE ref_info_cli IS REF CURSOR;
                c_info_cli ref_info_cli;
            
                CURSOR c_date_servicii IS
                    SELECT s.id_serviciu, s.denumire,
                            CURSOR (SELECT DISTINCT cl.id_client, nume || ' ' || prenume
                                    FROM CLIENT cl JOIN CUMPARA cu ON cl.id_client = cu.id_client
                                                   JOIN SERVICIU si ON cu.id_serviciu = si.id_serviciu
                                    WHERE si.id_serviciu = s.id_serviciu
                                    ORDER BY 2)
                    FROM SERVICIU s JOIN ESTE_COMPATIBIL ec ON s.id_serviciu = ec.id_serviciu
                                    JOIN PRODUS p ON ec.id_produs = p.id_produs
                    WHERE UPPER(p.denumire) = UPPER(v_nume_produs)
                    ORDER BY 2;
            BEGIN
                SELECT id_produs
                INTO v_id_produs
                FROM PRODUS
                WHERE UPPER(denumire) = UPPER(v_nume_produs);
                
                OPEN c_date_servicii;
                
                DBMS_OUTPUT.PUT_LINE('Id produs: ' || v_id_produs);
                DBMS_OUTPUT.PUT_LINE('Nume produs: ' || v_nume_produs);
                DBMS_OUTPUT.NEW_LINE;
                DBMS_OUTPUT.NEW_LINE;
                DBMS_OUTPUT.PUT_LINE('Lista serviciilor compatibile cu produsul:');
                
                LOOP
                    FETCH c_date_servicii INTO v_id_serviciu, v_nume_serviciu, c_info_cli;
                    
                    IF c_date_servicii%NOTFOUND THEN
                        IF c_date_servicii%ROWCOUNT = 0 THEN
                            DBMS_OUTPUT.PUT_LINE('Nu exista servicii compatibile!');
                        END IF;
                        
                        EXIT;
                    END IF;
                    
                    DBMS_OUTPUT.PUT_LINE('------------------------------------------');
                    DBMS_OUTPUT.PUT_LINE('Id serviciu: ' || v_id_serviciu);
                    DBMS_OUTPUT.PUT_LINE('Nume serviciu: ' || v_nume_serviciu);
                    DBMS_OUTPUT.NEW_LINE;
                    
                    FETCH c_info_cli BULK COLLECT INTO t_id_cli, t_nume_cli;
                    
                    DBMS_OUTPUT.PUT_LINE('Lista clientilor care au cumparat serviciul:');
                    
                    IF t_id_cli.COUNT = 0 THEN
                        DBMS_OUTPUT.PUT_LINE('Nu exista clienti care au cumparat serviciul.');
                    ELSE
                        FOR i IN t_id_cli.FIRST..t_id_cli.LAST LOOP
                            DBMS_OUTPUT.PUT_LINE('Id client: ' || t_id_cli(i) || ' | Nume client: ' || t_nume_cli(i));
                        END LOOP;
                    END IF;
                    
                    DBMS_OUTPUT.PUT_LINE('------------------------------------------');
                    DBMS_OUTPUT.NEW_LINE;
                    
                END LOOP;
                
                CLOSE c_date_servicii;
            EXCEPTION
                WHEN NO_DATA_FOUND THEN
                    RAISE_APPLICATION_ERROR(-20000, 'Nu exista niciun produs cu numele ' || v_nume_produs || '!');
                WHEN TOO_MANY_ROWS THEN
                    RAISE_APPLICATION_ERROR(-20001, 'Exista mai multe produse cu numele ' || v_nume_produs || '!');
                WHEN OTHERS THEN
                    RAISE_APPLICATION_ERROR(-20002, 'A aparut alta eroare!');
            END EX9_PROC;
            
            
            
            
            
        PROCEDURE EX10_PROC_AUX
            IS
                TYPE tab_imb_tipuri_servicii IS TABLE OF SERVICIU.tip%TYPE;
                t_tipuri_servicii tab_imb_tipuri_servicii;
            
                v_nr_servicii NUMBER;
            BEGIN
                SELECT DISTINCT tip
                BULK COLLECT INTO t_tipuri_servicii
                FROM SERVICIU
                ORDER BY 1;
                
                IF t_tipuri_servicii.COUNT > 0 THEN
                    FOR i IN t_tipuri_servicii.FIRST..t_tipuri_servicii.LAST LOOP
                        SELECT COUNT(*)
                        INTO v_nr_servicii
                        FROM SERVICIU
                        WHERE tip = t_tipuri_servicii(i);
                        
                        IF v_nr_servicii = 1 THEN
                            DBMS_OUTPUT.PUT_LINE('  un serviciu de tipul ' || t_tipuri_servicii(i));
                        ELSE
                            DBMS_OUTPUT.PUT_LINE('  ' || v_nr_servicii || ' servicii de tipul ' || t_tipuri_servicii(i));
                        END IF;
                    END LOOP;
                END IF;
            END EX10_PROC_AUX;
    END EX13_PACK;
/

-- DROP PACKAGE EX13_PACK;

-- PENTRU EX13_PACK.EX6_PROC
DECLARE
    v_nume CLIENT.nume%TYPE := '&p_nume';
BEGIN
    EX13_PACK.EX6_PROC(v_nume);
END;
/

-- PENTRU EX13_PACK.EX7_FUNC
DECLARE
    v_id_ang ANGAJAT.id_angajat%TYPE := &p_id;
    v_nr_cli_asist_ang NUMBER;
    
    v_nr_ang NUMBER;
BEGIN
    SELECT COUNT(id_angajat)
    INTO v_nr_ang
    FROM ANGAJAT;
    
    SELECT id_angajat
    INTO v_id_ang
    FROM ANGAJAT
    WHERE id_angajat = v_id_ang;

    IF EX13_PACK.EX7_FUNC(v_id_ang, v_nr_cli_asist_ang) < v_nr_ang/2 THEN
        DBMS_OUTPUT.PUT_LINE('Status personal:');
        DBMS_OUTPUT.PUT_LINE('Personal inactiv!');
    ELSE
        DBMS_OUTPUT.PUT_LINE('Status personal:');
        DBMS_OUTPUT.PUT_LINE('Personal activ!');
    END IF;
    
    DBMS_OUTPUT.NEW_LINE;
    
    DBMS_OUTPUT.PUT_LINE('Numarul de clienti asistati de catre angajatul cu id-ul ' || v_id_ang || ': ' || v_nr_cli_asist_ang || '.');
EXCEPTION
    WHEN NO_DATA_FOUND THEN
        DBMS_OUTPUT.PUT_LINE('Nu exista niciun angajat cu id-ul ' || v_id_ang || '!');
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('A aparut alta eroare!');
END;
/

-- PENTRU EX13_PACK.EX8_FUNC
DECLARE
    v_nume_utilizator CONT_SITE.nume_utilizator%TYPE := '&p_nume_utilizator';
    v_nr_recenzii NUMBER;
BEGIN
    v_nr_recenzii := EX13_PACK.EX8_FUNC(v_nume_utilizator);
    
    IF v_nr_recenzii > 0 THEN
        IF v_nr_recenzii > 1 THEN
            DBMS_OUTPUT.PUT_LINE('Contul cu numele de utilizator ' || v_nume_utilizator || ' a scris ' || v_nr_recenzii || ' recenzii.');
        ELSE
            DBMS_OUTPUT.PUT_LINE('Contul cu numele de utilizator ' || v_nume_utilizator || ' a scris o recenzie.');
        END IF;
    END IF;
END;
/

-- PENTRU EX13_PACK.EX9_PROC
DECLARE
    v_nume_produs PRODUS.denumire%TYPE := '&p_nume_produs';
BEGIN
    EX13_PACK.EX9_PROC(v_nume_produs);
END;
/

-- PENTRU EX13_PACK.EX10_PROC_AUX
BEGIN
    EX13_PACK.EX10_PROC_AUX;
END;
/





-- Cerinta 14.:

-- Enunt:
-- Definiti un pachet, care contine minimum 2 tipuri de date, minimum 2 functii, si minimum 2 proceduri.
-- Prin intermediul pachetului, determinati, pentru un produs al carui id este dat de la tastatura, daca
-- i se poate aplica vreuna din reducerile:
--     - In caz ca produsul are cel mult 10 recenzii, iar numarul mediu de stele al sau este cel mult 3,
--       i se va aplica o reducere de 10%. In caz contrar, produsul nu este eligibil pentru reducere;
--     - In caz ca produsul a fost cumparat de cel mult 10 clienti, i se va aplica o reducere de 10%.
--       In caz contrar, produsul nu este eligibil pentru reducere.
-- Sa se afiseze date despre produs, cat si despre recenziile si comenzile sale.

CREATE OR REPLACE PACKAGE EX14_PACK
    IS
        TYPE DATE_RECENZIE_PROD IS RECORD
        (id_recenzie RECENZIE.id_recenzie%TYPE,
         stele_recenzie RECENZIE.nr_stele%TYPE);
         
        TYPE tab_ind_date_recenzii_prod IS TABLE OF DATE_RECENZIE_PROD
                                           INDEX BY PLS_INTEGER;
        t_date_recenzii_prod tab_ind_date_recenzii_prod;
        v_total_nr_stele_prod NUMBER;
        
        TYPE DATE_COMANDA_PROD IS RECORD
        (id_comanda COMANDA.id_comanda%TYPE,
         pret_comanda COMANDA.pret_total%TYPE);
         
        TYPE tab_ind_date_comenzi_prod IS TABLE OF DATE_COMANDA_PROD
                                          INDEX BY PLS_INTEGER;
        t_date_comenzi_prod tab_ind_date_comenzi_prod;
        
        TYPE DATE_PRODUS IS RECORD
        (id_produs PRODUS.id_produs%TYPE,
         nume_produs PRODUS.denumire%TYPE,
         nume_categorie_produs CATEGORIE.denumire%TYPE,
         pret_produs PRODUS.pret%TYPE);
        v_date_produs DATE_PRODUS;

        FUNCTION EX14_FUNC1
                 (id_prod PRODUS.id_produs%TYPE)
                 RETURN NUMBER;

        FUNCTION EX14_FUNC2
                 (id_prod PRODUS.id_produs%TYPE)
                 RETURN NUMBER;
                 
        PROCEDURE EX14_PROC1
                  (id_prod IN OUT PRODUS.id_produs%TYPE);
                  
        PROCEDURE EX14_PROC2
                  (id_prod PRODUS.id_produs%TYPE,
                   id_apel NUMBER);
    END EX14_PACK;
/

CREATE OR REPLACE PACKAGE BODY EX14_PACK
    IS
        PROCEDURE EX14_PROC2
                (id_prod PRODUS.id_produs%TYPE,
                 id_apel NUMBER)
            IS
                exceptie EXCEPTION;
            BEGIN
                IF id_apel = 1 THEN
                    IF (t_date_recenzii_prod.COUNT <= 10) AND (v_total_nr_stele_prod/t_date_recenzii_prod.COUNT <= 3) THEN
                        UPDATE PRODUS
                        SET pret = pret * 0.9
                        WHERE id_produs = id_prod;
                        
                        DBMS_OUTPUT.PUT_LINE('Produsul cu id-ul ' || id_prod || ' a primit o reducere a pretului de 10%, deoarece are un numar de recenzii mai mic sau egal cu 10, iar media numarului de stele este mai mica sau egala cu 3.');
                        DBMS_OUTPUT.PUT_LINE('Medie nr. stele: ' || ROUND(v_total_nr_stele_prod/t_date_recenzii_prod.COUNT, 2));
                    ELSE
                        DBMS_OUTPUT.PUT_LINE('Produsul nu este eligibil pentru reducere, deoarece fie are un numar de recenzii mai mare decat 10, fie media numarului de stele este mai mare decat 3, fie ambele.');
                        DBMS_OUTPUT.PUT_LINE('Medie nr. stele: ' || ROUND(v_total_nr_stele_prod/t_date_recenzii_prod.COUNT, 2));
                    END IF;
                ELSIF id_apel = 2 THEN
                    IF t_date_comenzi_prod.COUNT <= 10 THEN
                        UPDATE PRODUS
                        SET pret = pret * 0.9
                        WHERE id_produs = id_prod;
                        
                        DBMS_OUTPUT.PUT_LINE('Produsul cu id-ul ' || id_prod || ' a primit o reducere a pretului de 10%, deoarece a fost cumparat de catre un numar mai mic sau egal cu 10 clienti.');
                    ELSE
                        DBMS_OUTPUT.PUT_LINE('Produsul nu este eligibil pentru reducere, deoarece a fost cumparat de catre un numar mai mare de 10 clienti.');
                    END IF;
                ELSIF id_apel <> 1 OR id_apel <> 2 THEN
                    RAISE exceptie;
                END IF;
            EXCEPTION
                WHEN exceptie THEN
                    RAISE_APPLICATION_ERROR(-20003, 'Id-ul apelului este incorect!');
            END EX14_PROC2;
        
        
        FUNCTION EX14_FUNC1
                (id_prod PRODUS.id_produs%TYPE)
                RETURN NUMBER
            IS
                v_recenzie_rec DATE_RECENZIE_PROD;
                v_counter NUMBER := 0;
            BEGIN
                v_total_nr_stele_prod := 0;
            
                FOR i IN (SELECT id_recenzie id
                          FROM RECENZIE
                          WHERE id_produs = id_prod) LOOP
                    v_counter := v_counter + 1;
                          
                    SELECT id_recenzie, nr_stele
                    INTO v_recenzie_rec
                    FROM RECENZIE
                    WHERE id_recenzie = i.id;

                    t_date_recenzii_prod(v_counter) := v_recenzie_rec;
                    v_total_nr_stele_prod := v_total_nr_stele_prod + v_recenzie_rec.stele_recenzie;
                END LOOP;

                EX14_PROC2(id_prod, 1);

                RETURN t_date_recenzii_prod.COUNT;
            END EX14_FUNC1;


        FUNCTION EX14_FUNC2
                (id_prod PRODUS.id_produs%TYPE)
                RETURN NUMBER
            IS
                v_comanda_rec DATE_COMANDA_PROD;
                v_counter NUMBER := 0;
            BEGIN
                FOR i IN (SELECT id_comanda id
                          FROM PRODUS p JOIN COMANDA c ON p.id_produs = c.id_produs
                          WHERE p.id_produs = id_prod) LOOP
                    v_counter := v_counter + 1;
                          
                    SELECT id_comanda, pret_total
                    INTO v_comanda_rec
                    FROM COMANDA
                    WHERE id_comanda = i.id;

                    t_date_comenzi_prod(v_counter) := v_comanda_rec;
                END LOOP;

                EX14_PROC2(id_prod, 2);

                RETURN t_date_comenzi_prod.COUNT;
            END EX14_FUNC2;


        PROCEDURE EX14_PROC1
                (id_prod IN OUT PRODUS.id_produs%TYPE)
            IS
            BEGIN
                SELECT id_produs, p.denumire, c.denumire, pret
                INTO v_date_produs.id_produs, v_date_produs.nume_produs, v_date_produs.nume_categorie_produs, v_date_produs.pret_produs
                FROM PRODUS p JOIN CATEGORIE c USING (id_categorie)
                WHERE id_produs = id_prod;
                
                DBMS_OUTPUT.PUT_LINE('Id produs: ' || v_date_produs.id_produs);
                DBMS_OUTPUT.PUT_LINE('Nume produs: ' || v_date_produs.nume_produs);
                DBMS_OUTPUT.PUT_LINE('Nume categorie: ' || v_date_produs.nume_categorie_produs);
                DBMS_OUTPUT.PUT_LINE('Pret produs: ' || ROUND(v_date_produs.pret_produs, 2));
            
                DBMS_OUTPUT.NEW_LINE;
                DBMS_OUTPUT.NEW_LINE;
            
                DBMS_OUTPUT.PUT_LINE('Nr. recenzii produs = ' || EX14_FUNC1(id_prod) || ':');
                
                FOR i IN t_date_recenzii_prod.FIRST..t_date_recenzii_prod.LAST LOOP
                    DBMS_OUTPUT.PUT_LINE('  Id recenzie: ' || t_date_recenzii_prod(i).id_recenzie || ' | Nr. stele recenzie: ' || t_date_recenzii_prod(i).stele_recenzie);
                END LOOP;
                
                DBMS_OUTPUT.NEW_LINE;
                
                DBMS_OUTPUT.PUT_LINE('Nr. comenzi produs = ' || EX14_FUNC2(id_prod) || ':');
            
                FOR i IN t_date_comenzi_prod.FIRST..t_date_comenzi_prod.LAST LOOP
                    DBMS_OUTPUT.PUT_LINE('  Id comanda: ' || t_date_comenzi_prod(i).id_comanda || ' | Pret comanda: ' || t_date_comenzi_prod(i).pret_comanda);
                END LOOP;
                
                DBMS_OUTPUT.NEW_LINE;
                SELECT pret
                INTO v_date_produs.pret_produs
                FROM PRODUS
                WHERE id_produs = id_prod;
                DBMS_OUTPUT.PUT_LINE('Pretul final al produsului: ' || ROUND(v_date_produs.pret_produs, 2));
                
                t_date_recenzii_prod.DELETE;
                t_date_comenzi_prod.DELETE;
            EXCEPTION
                WHEN NO_DATA_FOUND THEN
                    RAISE_APPLICATION_ERROR(-20000, 'Nu exista niciun produs cu id-ul ' || id_prod || '!');
            END EX14_PROC1;
    END EX14_PACK;
/

-- DROP PACKAGE EX14_PACK;

DECLARE
    v_id_produs PRODUS.id_produs%TYPE := 223;
BEGIN
    EX14_PACK.EX14_PROC1(v_id_produs);
END;