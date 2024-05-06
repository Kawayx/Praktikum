/*************************************************
 * ADS Praktikum 1.2
 * main.cpp
 *
 *************************************************/
#define CATCH_CONFIG_RUNNER
#include "Tree.h"
#include "catch.h"
#include <iostream>

using namespace std;

///////////////////////////////////////
// Hilfsmethoden fürs Menü hier:

/***************************
 ** Vorgegebene  Funktion **
 ***************************
   "mainscreen_addTreeCSV" 
 
Importiert CSV Datei in bestehenden Baum.
Bei Aufruf in der main() Methode, muss der Pointer auf den Anker des Baums, als Parameter übergeben werden.
Es wird die im gleichen Verzeichnis liegende Datei "ExportZielanalyse.csv" geladen.
****************************/

void mainscreen_addTreeCSV(Tree*& ref)
{
    char j;
    cout << "+ Moechten Sie die Daten aus der Datei ExportZielanalyse.csv "
            "importieren(j / n) ? >";
    cin >> j;
    if (j == 'j')
    {
        ifstream csvread;
        csvread.open("ExportZielanalyse.csv", ios::in);
        if (!csvread.is_open())
        {
            cout << "Fehler beim Lesen!" << endl;
            return;
        }
        else
        {
            string name, age, postcode, income;

            while (!csvread.eof())
            {
                getline(csvread, name, ';');
                getline(csvread, age, ';');
                getline(csvread, income, ';');
                getline(csvread, postcode, '\n');
                ref->addNode(name, stoi(age), stod(income), stoi(postcode));
            }
            csvread.close();
        }
        cout << "+ Daten wurden dem Baum hinzugefuegt." << endl;
    }
}

//
///////////////////////////////////////
int main()
{

    int result = Catch::Session().run();
    int in;
    Tree myT;

    do
    {
        cout << "=========================================" << endl <<
        "ADS - ELK - Stack v1.9, by 25th Bam" << endl <<
        "=========================================" << endl;

        cout << "1) Datensatz einfuegen, manuell \n"
                "2) Datensatz einfuegen, CSV Datei \n"
                "3) Datensatz loeschen \n"
                "4) Suchen \n"
                "5) Datenstruktur anzeigen (pre/post/in) \n"
                "6) Level-Order Ausgabe \n"
                "7) Beenden \n"
                "?> ";

        cin >> in;
        switch(in)
        {
            case 1:
            {
                cout << "+ Bitte geben Sie die den Datensatz ein:" << endl;
                string name;
                int alter;
                double einkommen;
                int PLZ;
                cout << "Name ?> ";
                cin >> name;
                cout << "Alter ?> ";
                cin >> alter;
                cout << "Einkommen ?> ";
                cin >> einkommen;
                cout << "PLZ ?> ";
                cin >> PLZ;
                myT.addNode(name, alter, einkommen, PLZ);
                cout << "+ Ihr Datensatz wurde eingefuegt" << endl;
                break;
            }
            case 2:
            {
                Tree *myTptr = &myT;
                mainscreen_addTreeCSV(myTptr);
                break;
            }
            case 3:
            {
                cout << "+ Bitte geben Sie den zu loeschenden Datensatz an" << endl;
                cout << " NodeOrderID ?> ";
                int orderID;
                cin >> orderID;
                myT.deleteNode(orderID);
                cout << "+ Eintrag wurde geloescht." << endl;
                break;
            }
            case 4:
            {
                cout << "+ Bitte geben Sie den zu suchenden Datensatz an " << endl;
                cout << " Name ?> ";
                string name;
                cin >> name;
                cout << "+ Fundstellen: " << endl;
                myT.searchNode(name);
                break;
            }
            case 5:
            {
                cout << "Ausgabereihenfolge ?>";
                string eingabe;
                do
                {
                    if(eingabe == "pre")
                        myT.printPreOrder();
                    if(eingabe == "post")
                        myT.printPostOrder();
                    if(eingabe == "in")
                        myT.printInOrder();

                }while(eingabe != "pre" || eingabe != "post" || eingabe != "in");
                break;
            }
            case 6:
            {
                myT.levelOrder();
                break;
            }
        }

    }while(in != 7);


    system("PAUSE");
    return 0;
}
