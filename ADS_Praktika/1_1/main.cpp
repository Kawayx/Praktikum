
#define CATCH_CONFIG_RUNNER

#include <iostream>
#include <string>
#include "Ring.h"
#include "catch.h"

using namespace std;

void print_menu()
{
    cout << "====================================" << endl
         << " SuperBackUp-Organizer over 9000, by. Son Goku" << endl
         << "====================================" << endl
         << "1) Backup anlegen" << endl
         << "2) Backup suchen" << endl
         << "3) Alle Backups ausgeben" << endl
         << "?> ";
}
void Backup_anlegen(Ring R)
{
    std::string Beschreibung;
    std::string Daten;
    cout << "+Neuen Datensatz anlegen" << endl
         << "Beschreibung ?> ";
    cin.ignore();
    getline(cin, Beschreibung);
    cout << "Daten ?> ";
    getline(cin, Daten);
    R.addNewNode(Beschreibung,Daten);
    cout << "+Ihr Datensatz wurde hinzugefuegt." << endl;
}
void Backup_suchen(Ring R)
{
    std::string Daten;
    cout << "+Nach welchen Daten soll gesucht werden?" << endl
         << "?> ";
    cin>> Daten;
    if(!R.search(Daten))
        cout << "+ Datensatz konnte nicht gefunden werden."<<endl;
}
void Alle_Backups_ausgeben(Ring R)
{
    R.print();
}


int main()
{
    int result = Catch::Session().run();
    Ring test;
    test.addNewNode("erstes Backup", "echtWichtig1");
    test.addNewNode("zweites Backup", "echtSuperwichtig2");
    test.addNewNode("drittes Backup", "unglaublichWichtig3");
    test.addNewNode("viertes Backup", "unfassbarWichtig4");
    test.addNewNode("fuenftes Backup", "kritischWichtig5");
    test.addNewNode("sechstes Backup", "insolvenzDaten6");
    print_menu();
    int eingabe=0;

    do{
        cin>>eingabe;
    }while(eingabe<1||eingabe>3);

    if(eingabe==1)
    {
        Backup_anlegen(test);
    }
    if(eingabe==2)
    {
        Backup_suchen(test);
    }
    if(eingabe==3)
    {
        Alle_Backups_ausgeben(test);
    }

    system("Pause");
    return result;
}
