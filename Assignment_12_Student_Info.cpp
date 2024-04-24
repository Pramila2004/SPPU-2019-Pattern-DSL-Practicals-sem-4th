#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

class Student{
    public:
        int rollNumber;
        string name;
        char division;
        string address;

};

class Operations{
    public:
        void addStudent(){
            ofstream file("data.txt", ios::app);\
            Student stud;

            cout << "Enter Roll Number: ";
            cin >> stud.rollNumber;
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, stud.name);
            cout << "Enter Division: ";
            cin >> stud.division;
            cout << "Enter Address: ";
            cin.ignore();
            getline(cin, stud.address);

            file<<stud.rollNumber << " " << stud.name << " " << stud.division << " " << stud.address << endl;
            cout << "Student record added successfully!" << endl;
            file.close();
        }

        void deleteStudent(int rollNumberToDelete){
            ifstream inFile("data.txt");
            ofstream tempFile("temp.txt");

            bool found=false;

            Student stud;
            while (inFile >> stud.rollNumber >> stud.name >> stud.division >> stud.address) {
                if (stud.rollNumber != rollNumberToDelete) {
                    tempFile << stud.rollNumber << " " << stud.name << " " << stud.division << " " << stud.address << endl;
                } else {
                    found = true;
                }
            }

            inFile.close();
            tempFile.close();

            remove("data.txt");
            rename("temp.txt", "data.txt");

            if (found) {
                cout << "Student record deleted successfully!" << endl;
            } else {
                cout << "Student record not found!" << endl;
            }

        }

        void displayStudent(int rollNumberToDisplay) {
            ifstream inFile("data.txt");

            bool found = false;
            Student stud;
            while (inFile >> stud.rollNumber >> stud.name >> stud.division >> stud.address) {
                if (stud.rollNumber == rollNumberToDisplay) {
                    cout << "Roll Number: " << stud.rollNumber << endl;
                    cout << "Name: " << stud.name << endl;
                    cout << "Division: " << stud.division << endl;
                    cout << "Address: " << stud.address << endl;
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Student record not found!" << endl;
            }

            inFile.close();
        }

};
int main(){

    int choice;
    bool flag = true;

    Operations o;

    while (flag){
        cout << "\n1. Add Student\n2. Delete Student\n3. Display Student\n4. Exit\nEnter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                o.addStudent();
                break;
            case 2: {
                int rollNumberToDelete;
                cout << "Enter Roll Number of student to delete: ";
                cin >> rollNumberToDelete;

                o.deleteStudent(rollNumberToDelete);
                break;
            }
            case 3: {
                int rollNumberToDisplay;
                cout << "Enter Roll Number of student to display: ";
                cin >> rollNumberToDisplay;

                o.displayStudent(rollNumberToDisplay);
                break;
            }
            case 4:
                cout << "Exiting program.\n";
                flag=false;
                break;
            default:
                cout << "Invalid choice!\n";
        }

    }
        
    

    

    return 0;
}