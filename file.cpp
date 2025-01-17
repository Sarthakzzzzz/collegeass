#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct Set {
    map<int,bool> elements;

    void Insert(int ne) {
        elements[ne] = true;
    }

    void remove(int ne) {
        elements.erase(ne);
    }

    bool contains(int ne) {
        return elements.find(ne) != elements.end();
    }

    int size() {
        return elements.size();
    }

    map<int,bool>::iterator begin() {
        return elements.begin();
    }

    map<int,bool>::iterator end() {
        return elements.end();
    }

    Set intersection(Set &other) {
        Set res;
        for(auto &pair:elements) {
            if(other.contains(pair.first)) {
                res.Insert(pair.first);
            }
        }
        return res;
    }

    Set Union(Set &other) {
        Set res;
        for(auto &pair:elements) {
            res.Insert(pair.first);
        }
        for(auto &pair:other.elements) {
            res.Insert(pair.first);
        }
        return res;
    }

    Set Difference(Set &other) {
        Set res;
        for(auto &pair:elements) {
            if(!other.contains(pair.first)) {
                res.Insert(pair.first);
            }
        }
        return res;
    }

    bool isSubset(Set &other) {
        for (auto &pair : elements) {
            if (!other.contains(pair.first)) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Set s1, s2;
    int choice, element;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add element to Set 1\n";
        cout << "2. Add element to Set 2\n";
        cout << "3. Remove element from Set 1\n";
        cout << "4. Remove element from Set 2\n";
        cout << "5. Check if element is in Set 1\n";
        cout << "6. Check if element is in Set 2\n";
        cout << "7. Get size of Set 1\n";
        cout << "8. Get size of Set 2\n";
        cout << "9. Intersection of Set 1 and Set 2\n";
        cout << "10. Union of Set 1 and Set 2\n";
        cout << "11. Difference between Set 1 and Set 2\n";
        cout << "12. Check if Set 1 is a subset of Set 2\n";
        cout << "13. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to add to Set 1: ";
                cin >> element;
                s1.Insert(element);
                break;
            case 2:
                cout << "Enter element to add to Set 2: ";
                cin >> element;
                s2.Insert(element);
                break;
            case 3:
                cout << "Enter element to remove from Set 1: ";
                cin >> element;
                s1.remove(element);
                break;
            case 4:
                cout << "Enter element to remove from Set 2: ";
                cin >> element;
                s2.remove(element);
                break;
            case 5:
                cout << "Enter element to check in Set 1: ";
                cin >> element;
                cout << (s1.contains(element) ? "Element is in Set 1" : "Element is not in Set 1") << endl;
                break;
            case 6:
                cout << "Enter element to check in Set 2: ";
                cin >> element;
                cout << (s2.contains(element) ? "Element is in Set 2" : "Element is not in Set 2") << endl;
                break;
            case 7:
                cout << "Size of Set 1: " << s1.size() << endl;
                break;
            case 8:
                cout << "Size of Set 2: " << s2.size() << endl;
                break;
            case 9:
            {
                Set intersect = s1.intersection(s2);
                cout << "Intersection of Set 1 and Set 2: ";
                for (auto &pair : intersect) {
                    cout << pair.first << " ";
                }
                cout << endl;
                break;
            }
            case 10:
            {
                Set unionSet = s1.Union(s2);
                cout << "Union of Set 1 and Set 2: ";
                for (auto &pair : unionSet) {
                    cout << pair.first << " ";
                }
                cout << endl;
                break;
            }
            case 11:
            {
                Set diff = s1.Difference(s2);
                cout << "Difference between Set 1 and Set 2: ";
                for (auto &pair : diff) {
                    cout << pair.first << " ";
                }
                cout << endl;
                break;
            }
            case 12:
                cout << "Is Set 1 a subset of Set 2? " << (s1.isSubset(s2) ? "Yes" : "No") << endl;
                break;
            case 13:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
    }

    return 0;
}

