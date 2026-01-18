#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

#include "OutputPerson.h"
#include "InputPerson.h"

using namespace std;

int main()
{
    // Seed random number generator
    srand(time(0));

    int studentInputChoice = 0;

    // Main menu
    cout << "1. Input students from file" << endl;
    cout << "2. Output random students to file" << endl;
    cout << "3. Input students manually" << endl << endl;

    // Ask user for menu choice
    while (true)
    {
        cout << "Please choose option 1, 2 or 3: ";
        cin >> studentInputChoice;

        if (cin.fail())
        {
            clearWrongInputs();   // clear bad input
        }
        else if (studentInputChoice >= 1 && studentInputChoice <= 3)
        {
            break;   // valid input
        }
        else
        {
            cout << "Invalid selection!" << endl;
        }
    }

    // OPTION 1: Read students from file
    if (studentInputChoice == 1)
    {
        string fileName;
        cout << "Enter file name (example: students.txt): ";
        cin >> fileName;

        int containerChoice = 0;

        cout << "\nChoose container:" << endl;
        cout << "1. Vector" << endl;
        cout << "2. List" << endl;
        cout << "3. Deque" << endl << endl;

        // Ask user for container choice
        while (true)
        {
            cout << "Please choose option 1, 2 or 3: ";
            cin >> containerChoice;

            if (cin.fail())
            {
                clearWrongInputs();
            }
            else if (containerChoice >= 1 && containerChoice <= 3)
            {
                break;
            }
            else
            {
                cout << "Invalid selection!" << endl;
            }
        }

        // Process file using chosen container
        if (containerChoice == 1)
        {
            vector<Person> persons = inputFile_Vector(fileName);
            gradeSorter_Vect(persons);
            strategyChooserVector(persons);
        }
        else if (containerChoice == 2)
        {
            list<Person> persons = inputFile_List(fileName);
            gradeSorter_List(persons);
            strategyChooserList(persons);
        }
        else if (containerChoice == 3)
        {
            deque<Person> persons = inputFile_Deque(fileName);
            gradeSorter_Deque(persons);
            strategyChooserDeque(persons);
        }
    }

    // OPTION 2: Create random students and save to file
    else if (studentInputChoice == 2)
    {
        string fileName;
        cout << "Enter name of file to create (example: random.txt): ";
        cin >> fileName;

        vector<Person> randomStudents = randomizePersons();
        outputVectorToFile_HW_EX(fileName, randomStudents);
    }

    // OPTION 3: Manual student input
    else if (studentInputChoice == 3)
    {
        vector<Person> students = manualInputPerson();
        printGrades_AverOrMed(students);
    }

    system("pause");
    return 0;
}
