#include <iostream>
#include "BST.h"
#include "FileHandler.h"

using namespace std;

void displayMenu() {
    cout << "Menu:" << endl;
    cout << "1. Dodaj element" << endl;
    cout << "2. Usu� element" << endl;
    cout << "3. Usu� ca�e drzewo" << endl;
    cout << "4. Szukaj drogi do podanego elementu" << endl;
    cout << "5. Wy�wietl drzewo (preorder)" << endl;
    cout << "6. Wy�wietl drzewo (inorder)" << endl;
    cout << "7. Wy�wietl drzewo (postorder)" << endl;
    cout << "8. Zapisz drzewo do pliku tekstowego" << endl;
    cout << "9. Wczytaj drzewo z pliku binarnego" << endl;
    cout << "10. Zapisz drzewo do pliku binarnego" << endl;
    cout << "11. Wczytaj plik tekstowy z cyframi i zbuduj drzewo" << endl;
    cout << "0. Wyjd�" << endl;
}

int main() {
    BST bst;
    FileHandler fileHandler;
    int choice, value;
    string filename;

    while (true) {
        displayMenu();
        cout << "Wybierz opcj�: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Podaj warto�� do dodania: ";
            cin >> value;
            bst.insert(value);
            break;
        case 2:
            cout << "Podaj warto�� do usuni�cia: ";
            cin >> value;
            bst.remove(value);
            break;
        case 3:
            bst.clear();
            break;
        case 4:
            cout << "Podaj warto�� do znalezienia �cie�ki: ";
            cin >> value;
            bst.findPath(value);
            break;
        case 5:
            bst.displayPreorder();
            break;
        case 6:
            bst.displayInorder();
            break;
        case 7:
            bst.displayPostorder();
            break;
        case 8:
            cout << "Podaj nazw� pliku do zapisu: ";
            cin >> filename;
            bst.saveToTextFile(filename);
            break;
        case 9:
            cout << "Podaj nazw� pliku do odczytu: ";
            cin >> filename;
            fileHandler.loadFromBinaryFile(bst, filename);
            break;
        case 10:
            cout << "Podaj nazw� pliku do zapisu: ";
            cin >> filename;
            fileHandler.saveToBinaryFile(bst, filename);
            break;
        case 11:
            cout << "Podaj nazw� pliku tekstowego do odczytu: ";
            cin >> filename;
            fileHandler.loadFromTextFile(bst, filename);
            break;
        case 0:
            cout << "Zako�czenie programu." << endl;
            return 0;
        default:
            cout << "Nieprawid�owa opcja. Spr�buj ponownie." << endl;
        }
    }

    return 0;
}
