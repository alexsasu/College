/// Sasu Alexandru-Cristian - 142
/// Szmeteanca Eduard-Gabriel
/// Code::Blocks, GNU GCC Compiler
/// g++ (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0
/// gcc version 8.1.0 (x86_64-posix-seh-rev0, Built by MinGW-W64 project)

#include <bits/stdc++.h>
#include <windows.h>
using namespace std;





/// prin intermediul acestei interfete, voi citi datele din celelalte clase
class Interfata
{

public:
    virtual ~Interfata();

    friend istream& operator>>(istream&, Interfata&);
    virtual istream& citire(istream&) = 0;
    friend ostream& operator<<(ostream&, const Interfata&);
    virtual ostream& afisare(ostream&)const = 0;

};

Interfata::~Interfata(){}

istream& operator>>(istream& in, Interfata& ob)
{
    return ob.citire(in);
}
ostream& operator<<(ostream& out, const Interfata& ob)
{
    return ob.afisare(out);
}





class Malware: public Interfata
{

protected:
    float impact = 0;
    string dataInfectare, nume, metodaInfectare;
    vector<string> registrii;

public:
    Malware(string DataInfectare = "-----", string Nume = "-----", string MetodaInfectare = "unknown", vector<string> Registrii = {"-----"});
    Malware(const Malware&) = default;
    ~Malware();

    float getImpact()const;

    Malware& operator=(const Malware&) = default;

    istream& citire(istream&);
    ostream& afisare(ostream&)const;

};

Malware::Malware(string DataInfectare, string Nume, string MetodaInfectare, vector<string> Registrii):
         dataInfectare(DataInfectare), nume(Nume), metodaInfectare(MetodaInfectare), registrii(Registrii)
{
    for (int i = 0; i < registrii.size(); i++)
    {
        if (registrii[i] == "HKLM-run" || registrii[i] == "HKCU-run")
            impact += 20;
    }
}
Malware::~Malware(){}

float Malware::getImpact()const
{
    return impact;
}

istream& Malware::citire(istream& in)
{
    cout<<"Nume: ";
    in>>this->nume;

    cout<<"Data infectare: ";
    in>>this->dataInfectare;

    cout<<"Metoda infectare: ";
    in.sync();
    getline(in, this->metodaInfectare);
    in.sync();

    int nr;
    cout<<"Nr. registrii afectati: ";
    in>>nr;

    string registr;
    cout<<"Registrii afectati:\n";
    for (int i = 0; i < nr; i++)
    {
        in>>registr;
        registrii.push_back(registr);
        if (registr == "HKLM-run" || registr == "HKCU-run")
            impact += 20;
    }

    return in;
}
ostream& Malware::afisare(ostream& out)const
{
    out<<"Nume: "<<nume<<'\n';

    out<<"Data infectare: "<<dataInfectare<<'\n';

    out<<"Impact: "<<impact<<'\n';

    out<<"Metoda infectare: "<<metodaInfectare<<'\n';

    out<<"Registrii infectati:\n";
    for (int i = 0; i < registrii.size(); i++)
        out<<registrii[i]<<'\n';

    return out;
}






class Rootkit: virtual public Malware
{

protected:
    vector<string> importuri, lsStringuri;

public:
    Rootkit(string DataInfectare = "-----", string Nume = "-----", string MetodaInfectare = "-----", vector<string> Registrii = {"-----"}, vector<string> LsStringuri = {"-----"}, vector<string> Importuri = {"-----"});
    Rootkit(const Rootkit&) = default;
    ~Rootkit();

    Rootkit& operator=(const Rootkit&) = default;

    istream& citire(istream&);
    ostream& afisare(ostream&)const;

};

Rootkit::Rootkit(string DataInfectare, string Nume, string MetodaInfectare, vector<string> Registrii, vector<string> Importuri, vector<string> LsStringuri):
         Malware(DataInfectare, Nume, MetodaInfectare, Registrii), importuri(Importuri), lsStringuri(LsStringuri)
{
    for (int i = 0; i < lsStringuri.size(); i++)
    {
        if (lsStringuri[i] == "System Service Descriptor Table" || lsStringuri[i] == "SSDT" || lsStringuri[i] == "NtCreateFile")
            impact += 10;
    }

    for (int i = 0; i < importuri.size(); i++)
    {
        if (importuri[i] == "ntoskrnl.exe")
            impact *= 2;
    }
}
Rootkit::~Rootkit(){}

istream& Rootkit::citire(istream& in)
{
    Malware::citire(in);

    int nr2;
    cout<<"Nr. string-uri: ";
    in>>nr2;

    string String;
    cout<<"String-uri:\n";
    for (int i = 0; i < nr2; i++)
    {
        in.sync();
        getline(in, String);
        in.sync();
        lsStringuri.push_back(String);
        if (String == "System Service Descriptor Table" || String == "SSDT" || String == "NtCreateFile")
            impact += 100;
    }

    int nr1;
    cout<<"Nr. importuri: ";
    in>>nr1;

    string import;
    cout<<"Import-uri:\n";
    for (int i = 0; i < nr1; i++)
    {
        in>>import;
        importuri.push_back(import);
        if (import == "ntoskrnl.exe")
            impact *= 2;
    }

    return in;
}
ostream& Rootkit::afisare(ostream& out)const
{
    Malware::afisare(out);

    out<<"String-uri:\n";
    for (int i = 0; i < lsStringuri.size(); i++)
        out<<lsStringuri[i]<<'\n';

    out<<"Import-uri:\n";
    for (int i = 0; i < importuri.size(); i++)
        out<<importuri[i]<<'\n';

    return out;
}





class Keylogger: virtual public Malware
{

protected:
    vector<string> functii, tasteSpeciale;

public:
    Keylogger(string DataInfectare = "-----", string Nume = "-----", string MetodaInfectare = "-----", vector<string> Registrii = {"-----"}, vector<string> Functii = {"-----"}, vector<string> TasteSpeciale = {"-----"});
    Keylogger(const Keylogger&) = default;
    ~Keylogger();

    Keylogger& operator=(const Keylogger&) = default;

    istream& citire(istream&);
    ostream& afisare(ostream&)const;

};

Keylogger::Keylogger(string DataInfectare, string Nume, string MetodaInfectare, vector<string> Registrii, vector<string> Functii, vector<string> TasteSpeciale):
         Malware(DataInfectare, Nume, MetodaInfectare, Registrii), functii(Functii), tasteSpeciale(TasteSpeciale)
{
    for (int i = 0; i < functii.size(); i++)
    {
        if (functii[i] == "[Up]" || functii[i] == "[Num Lock]" || functii[i] == "[Down]" || functii[i] == "[Right]" ||functii[i] == "[UP]" ||functii[i] == "[Left]" ||functii[i] == "[PageDown]")
            impact += 10;
    }

    for (int i = 0; i < tasteSpeciale.size(); i++)
    {
        if (tasteSpeciale[i] == "CreateFileW" || tasteSpeciale[i] == "OpenProcess" || tasteSpeciale[i] == "ReadFile" || tasteSpeciale[i] == "WriteFile" ||tasteSpeciale[i] == "RegisterHotKey" ||tasteSpeciale[i] == "SetWindowsHookEx")
            impact += 30;
    }
}
Keylogger::~Keylogger(){}

istream& Keylogger::citire(istream& in)
{
    Malware::citire(in);

    int nr2;
    cout<<"Nr. functii: ";
    in>>nr2;

    string functie;
    cout<<"Functii:\n";
    for (int i = 0; i < nr2; i++)
    {
        in>>functie;
        functii.push_back(functie);
        if (functie == "[Up]" || functie == "[Num Lock]" || functie == "[Down]" || functie == "[Right]" ||functie == "[UP]" ||functie == "[Left]" ||functie == "[PageDown]")
            impact += 10;
    }

    int nr1;
    cout<<"Nr. taste speciale: ";
    in>>nr1;

    string tastaSpeciala;
    cout<<"Taste speciale:\n";
    for (int i = 0; i < nr1; i++)
    {
        in>>tastaSpeciala;
        tasteSpeciale.push_back(tastaSpeciala);
        if (tastaSpeciala == "CreateFileW" || tastaSpeciala == "OpenProcess" || tastaSpeciala == "ReadFile" || tastaSpeciala == "WriteFile" || tastaSpeciala == "RegisterHotKey" || tastaSpeciala == "SetWindowsHookEx")
            impact += 30;
    }

    return in;
}
ostream& Keylogger::afisare(ostream& out)const
{
    Malware::afisare(out);

    out<<"Functii:\n";
    for (int i = 0; i < functii.size(); i++)
        out<<functii[i]<<'\n';

    out<<"Taste speciale:\n";
    for (int i = 0; i < tasteSpeciale.size(); i++)
        out<<tasteSpeciale[i]<<'\n';

    return out;
}





class Kernel_Keylogger: public Rootkit, public Keylogger
{

private:
    string ceAscunde;

public:
    Kernel_Keylogger(string DataInfectare = "-----", string Nume = "-----", string MetodaInfectare = "-----", vector<string> Registrii = {"-----"}, vector<string> LsStringuri = {"-----"}, vector<string> Importuri = {"-----"}, vector<string> Functii = {"-----"}, vector<string> TasteSpeciale = {"-----"}, string CeAscunde = "-----");
    Kernel_Keylogger(const Kernel_Keylogger&) = default;
    ~Kernel_Keylogger();

    Kernel_Keylogger& operator=(const Kernel_Keylogger&) = default;

    istream& citire(istream&);
    ostream& afisare(ostream&)const;

};

Kernel_Keylogger::Kernel_Keylogger(string DataInfectare, string Nume, string MetodaInfectare, vector<string> Registrii, vector<string> LsStringuri, vector<string> Importuri, vector<string> Functii, vector<string> TasteSpeciale, string CeAscunde):
                  Malware(DataInfectare, Nume, MetodaInfectare, Registrii), Rootkit(DataInfectare, Nume, MetodaInfectare, Registrii, Importuri, LsStringuri), Keylogger(DataInfectare, Nume, MetodaInfectare, Registrii, Functii, TasteSpeciale), ceAscunde(CeAscunde)
{
    if (ceAscunde == "fisiere")
        impact += 20;
    else
        impact += 30;
}
Kernel_Keylogger::~Kernel_Keylogger(){}

istream& Kernel_Keylogger::citire(istream& in)
{
    Malware::citire(in);

    Rootkit::citire(in);

    Keylogger::citire(in);

    cout<<"Ce ascunde? ";
    in>>ceAscunde;
    if (ceAscunde == "fisiere")
        impact += 20;
    else
        impact += 30;

    return in;
}
ostream& Kernel_Keylogger::afisare(ostream& out)const
{
    Malware::afisare(out);

    Rootkit::afisare(out);

    Keylogger::afisare(out);

    out<<"Ce ascunde: "<<ceAscunde<<'\n';

    return out;
}





class Ransomware: public Malware
{

private:
    int ratingCriptare;
    float ratingObfuscare;

public:
    Ransomware(string DataInfectare = "-----", string Nume = "-----", string MetodaInfectare = "-----", vector<string> Registrii = {"-----"}, int RatingCriptare = 0, int RatingObfuscare = 0);
    Ransomware(const Ransomware&) = default;
    ~Ransomware();

    Ransomware& operator=(const Ransomware&) = default;

    istream& citire(istream&);
    ostream& afisare(ostream&)const;

};

Ransomware::Ransomware(string DataInfectare, string Nume, string MetodaInfectare, vector<string> Registrii, int RatingCriptare, int RatingObfuscare):
         Malware(DataInfectare, Nume, MetodaInfectare, Registrii), ratingCriptare(RatingCriptare), ratingObfuscare(RatingObfuscare)
{
    impact = impact + ratingCriptare + ratingObfuscare;
}
Ransomware::~Ransomware(){}

istream& Ransomware::citire(istream& in)
{
    Malware::citire(in);

    cout<<"Rating criptare: ";
    in>>ratingCriptare;

    cout<<"Rating obfuscare: ";
    in>>ratingObfuscare;

    return in;
}
ostream& Ransomware::afisare(ostream& out)const
{
    Malware::afisare(out);

    out<<"Rating criptare: "<<ratingCriptare<<'\n';

    out<<"Rating obfuscare: "<<ratingObfuscare<<'\n';

    return out;
}





class Computer: public Interfata
{

private:
    vector<Malware*> lsMalware;
    float ratingFinal = 0;
    const int id;
    static int contorId;

public:
    Computer();
    Computer(const Computer&);
    ~Computer();

    Computer& operator=(const Computer&);

    istream& citire(istream&);
    ostream& afisare(ostream&)const;

};

int Computer::contorId = 1;


Computer::Computer(): id(contorId++){}
Computer::~Computer()
{
    if (!lsMalware.empty())
    {
        for (int i = 0; (unsigned long long)i < lsMalware.size(); i++)
            delete lsMalware[i];

        lsMalware.clear();
        lsMalware.shrink_to_fit();
    }
}

istream& Computer::citire(istream& in)
{
    int nrMalware;
    cout<<"Numar de malware: ";
    in>>nrMalware;

    string malware;
    for (int i = 0; i < nrMalware; i++)
    {
        cout<<"Introdu malware (Rootkit/Keylogger/Kernel_Keylogger/Ransomware): ";
        in>>malware;

        if (malware == "Rootkit")
            lsMalware.push_back(new Rootkit);
        else
            if (malware == "Rootkit")
                lsMalware.push_back(new Keylogger);
            else
                if (malware == "Rootkit")
                    lsMalware.push_back(new Kernel_Keylogger);
                else
                    lsMalware.push_back(new Ransomware);

        in>>*lsMalware.back();

    }

    for (int i = 0; i < lsMalware.size(); i++)
        ratingFinal += (*lsMalware[i]).getImpact();

    return in;
}
ostream& Computer::afisare(ostream& out)const
{
    cout<<"Lista malware:\n";
    for (int i = 0; i < lsMalware.size(); i++)
    {
        if (typeid(*lsMalware[i]) == typeid(Rootkit))
        {
            out<<"Rootkit:\n";
            out<<*lsMalware[i]<<'\n';
        }
        else
            if (typeid(*lsMalware[i]) == typeid(Keylogger))
            {
                out<<"Keylogger:\n";
                out<<*lsMalware[i]<<'\n';
            }
            else
                if (typeid(*lsMalware[i]) == typeid(Kernel_Keylogger))
                {
                    out<<"Kernel-Keylogger:\n";
                    out<<*lsMalware[i]<<'\n';
                }
                else
                    if (typeid(*lsMalware[i]) == typeid(Ransomware))
                    {
                        out<<"Ransomware:\n";
                        out<<*lsMalware[i]<<'\n';
                    }
    }

    cout<<"Rating final: ";
    out<<ratingFinal<<'\n';

    return out;
}






/// singleton
class Menu
{

private:
    Menu();
    Menu(const Menu&) = delete;
    Menu& operator=(const Menu&) = delete;

    vector<Computer*> calculatoare;
    // vector<Malware*> malwares;
    static Menu* instance;
    vector<pair<string, function<void()>>> Cerinte; /// am invatat cum sa lucrez cu functii lambda de la tutoriatul de POO

public:
    ~Menu();

    static Menu* SetInstance();
    void StartMenu();

};

Menu* Menu::instance = nullptr;

Menu::Menu()
{
    Cerinte.push_back(make_pair("Adaugare calculator - 1", [&]()
    {
        system("cls");

        calculatoare.push_back(new Computer);
        cin>>*calculatoare.back();

        system("pause");
        system("cls");
    }));

    Cerinte.push_back(make_pair("Afisare informatii pentru fiecare calculator - 2", [&]()
    {
        system("cls");

        for (auto it = calculatoare.begin(); it != calculatoare.end(); it++)
            cout<<(**it)<<"----------------------------------------------------------\n";

        system("pause");
        system("cls");
    }));

    Cerinte.push_back(make_pair("Afisare informatii pentru fiecare calculator fiind ordonate dupa ratingul final - 3", [&]()
    {
        system("cls");



        system("pause");
        system("cls");
    }));

    Cerinte.push_back(make_pair("Afisare primele k calculatoare ordonate dupa rating-ul final - 4", [&]()
    {
        system("cls");



        system("pause");
        system("cls");
    }));

    Cerinte.push_back(make_pair("Afisare procent de computere infectate din firma - 5", [&]()
    {
        system("cls");



        system("pause");
        system("cls");
    }));

    Cerinte.push_back(make_pair("Iesi din meniu - 6", [&]()
    {
    }));
}
Menu::~Menu()
{
    if (!calculatoare.empty())
    {
        for (int i = 0; (unsigned long long)i < calculatoare.size(); i++)
            delete calculatoare[i];

        calculatoare.clear();
        calculatoare.shrink_to_fit();
    }

    /*
    if (!malwares.empty())
    {
        for (int i = 0; (unsigned long long)i < malwares.size(); i++)
            delete malwares[i];

        malwares.clear();
        malwares.shrink_to_fit();
    }*/
}

Menu* Menu::SetInstance()
{
    if (!instance)
        instance = new Menu;

    return instance;
}

void Menu::StartMenu()
{
    int opt;
    bool ok = true;

    while (ok)
    {
        try
        {
            for (unsigned long long i = 0; i < Cerinte.size(); i++)
                cout<<Cerinte[i].first<<'\n';

            cout<<"Introdu optiune: ";
            cin>>opt;

            if ((opt < 1) || (opt > 5))
                throw runtime_error("Input gresit!");

            if (opt == 5)
            {
                ok = false;

                system("cls");
                cout<<"La revedere!";
                Sleep(2000);
                system("cls");
            }
            else
                Cerinte[opt-1].second();
        }
        catch (exception& e)
        {
            system("cls");
            cout<<e.what();
            Sleep(2000);
            system("cls");

            continue;
        }
    }
}





int main()
{

Menu* meniu = meniu ->SetInstance();
meniu->StartMenu();

return 0;}
