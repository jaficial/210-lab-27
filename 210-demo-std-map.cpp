#include <iostream>
#include <map>
#include <vector>
#include <tuple>
#include <iomanip>
using namespace std;
//
int villager_menu();
void villager_output();

int villager_menu(){
    int choice;
    cout << setw(10) << "" << "1. Add Villager" << endl;
    cout << setw(10) << "" << "2. Delete Villager" << endl;
    cout << setw(10) << "" << "3. Increase Friendship" << endl;
    cout << setw(10) << "" << "4. Decrease Friendship" << endl;
    cout << setw(10) << "" << "5. Search for Villager" << endl;
    cout << setw(10) << "" << "6. Exit" << endl;
    cout << setw(10) << "" << "Enter choice:";
    cin >> choice;
}

void villager_output(map<string, tuple<string, int, string, string>> &villager_map){

}
int main() {
    
    int menu_choice;
    bool menu_flag = true;
    map<string, tuple<string, int, string, string>> villager; // key and value pair right here

    while (menu_flag){
        menu_choice = villager_menu();
        if (menu_choice == 6){ // if the user decides to exit the program
            menu_flag = false;
        }
        
        else if (menu_choice == 1){

        }
        

    }
    /*NOTE: Need to convert the vector into a tuple.
            Also changing the parameters of the villager: 
                - string villager_name, int friendship_points(0-10), 
                  string villager_species, string villager_catchphrase  */ 
    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    // villagerColors["Audie"] = {"Orange", "Yellow", "Red"};
    


    // access the map using a range-based for loop
    cout << "Villagers and their favorite colors (range-based for loop):" << endl;
    for (auto pair : villagerColors) {
        cout << pair.first << ": ";
        for (auto color : pair.second)
            cout << color << " ";
        cout << endl;
    }

    // access the map using iterators
    cout << "\nVillagers and their favorite colors (iterators):" << endl;
    for (map<string, vector<string>>::iterator it = villagerColors.begin(); 
                                               it != villagerColors.end(); ++it) {
        cout << it->first << ": ";
        for (auto color : it->second) {
            cout << color << " ";
        }
        cout << endl;
    }

    // delete an element
    villagerColors.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagerColors.find(searchKey);
    if (it != villagerColors.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s favorite colors: ";
        for (auto color : it->second)  // range loop to traverse the value/vector
            cout << color << " ";
        cout << endl;
    } else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerColors.size() << endl;
    villagerColors.clear();
    cout << "Size after clear: " << villagerColors.size() << endl;

    return 0;
}
