// COMSC-210 | Jed Aficial | Lab 27
// github link: https://github.com/jaficial/210-lab-27
#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <tuple>
#include <iomanip>
using namespace std;

int villager_menu();
void villager_output(map<string, tuple<int, string, string>> &);

int villager_menu(){
    int choice;
    cout << "1. Add Villager" << endl;
    cout << "2. Delete Villager" << endl;
    cout << "3. Increase Friendship" << endl;
    cout << "4. Decrease Friendship" << endl;
    cout << "5. Search for Villager" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter choice: ";
    cin >> choice;
    return choice;
}

/* NOTE: When outputting the map:
         - pair.first is the key
         - pair.second is the value
         - initialize pair.second in order to access the individual elements of the tuple
*/ 
void villager_output(map<string, tuple<int, string, string>> &villager_map){
    cout << endl;
    cout << setw(5) << "" << "Villager details:" << endl;
    for (auto pair:villager_map){ 
        const auto& tuple_values = pair.second; // CITED: https://en.cppreference.com/w/cpp/utility/tuple to learn how to access individual elements of a tuple/output elements. Also learned tuple manipulation 
        cout << setw(5) << "" << pair.first << " [" << get<0>(tuple_values) << ", " << get<1>(tuple_values) << ", " << get<2>(tuple_values) << "]" << endl; 
    }
    cout << endl;
}

    /*NOTE: Need to convert the vector into a tuple.
            Also changing the parameters of the villager: 
                - string villager_name, int friendship_points(0-10), 
                  string villager_species, string villager_catchphrase  */ 
/* - key of map will be the name of the villager
   - value will be a tuple<int, string, string>
        - int friendship_level, string species, string catchphrase
*/

int main() {
    
    bool menu_flag = true;
    map<string, tuple<int, string, string>> villagers; // key and value pair right here

    while (menu_flag){
        int menu_choice = villager_menu();
        if (menu_choice == 6){ // if the user decides to exit the program
            menu_flag = false;
        }
        
        else if (menu_choice == 1){ // if the user decides to add a villager
            string villager_name;
            int villager_flevel;
            string villager_species;
            string villager_cphrase;
            
            cout << "Villager name: ";
            cin.ignore();
            getline(cin, villager_name);
            cout << "Friendship level: ";
            cin >> villager_flevel;
            cout << "Species: ";
            cin.ignore();
            getline(cin, villager_species);
            cout << "Catchphrase: ";
            getline(cin, villager_cphrase);
            cout << villager_name << " added." << endl;

            tuple <int, string, string> villager_data(villager_flevel, villager_species, villager_cphrase); // must define the tuple first
            villagers.insert(make_pair(villager_name, villager_data)); // then you can pass the tuple as a parameter into the map
            villager_output(villagers);
        }

        else if (menu_choice == 2){ // if the user decides to delete a villager
                                    // asks user for the name of the villager, then uses its name (key) to delete the villager off the map 
            cin.ignore();
            string delete_choice;
            cout << "Who would you like to delete?" << endl << "Choice: ";
            getline(cin, delete_choice);
            villagers.erase(delete_choice);
            villager_output(villagers);
        }

        else if (menu_choice == 3){ // Would like to increase the friendship of a villager
            cin.ignore();
            string villager_choice;
            cout << "Which villager would you like to increase the friendship of?" << endl << "Choice: ";
            getline(cin, villager_choice);
            
        }
        

    }


    return 0;
}
