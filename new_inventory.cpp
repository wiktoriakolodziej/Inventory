

#include <iostream>
#include <cstdlib> //system("cls")
#include <vector>

#include <time.h> 




#include "functions.h"
#include "object.h"
#include "complex_object.h"
#include "vector.h"



using namespace std;
using namespace Inventory;
 
int main()
{

    my_vector inventory; 
    info();
    char character;
    cin >> character;
    while (character != 27) { 
        switch (character) {
        case '1': {
            system("cls");   
            inventory.create_new();
            break;
        }
        case '2':
            system("cls");
            inventory.exportt();
            break;
        case '3':
            system("cls");
            inventory.change_params();
            system("cls");
            break;
        case '4':
            system("cls");
            inventory.iterate_and_find();
            break;
        case '5':
            system("cls");
            inventory.alerts();
            break;
        case '6':
            system("cls");
            inventory.delete_object();
            break;
        case 'q':
            system("cls");
            return 0;
        default:
            system("cls");
            cout << "podales zly parametr, " << endl;
            break;
        }

        info();
        cin >> character;

    }
   
  
}
