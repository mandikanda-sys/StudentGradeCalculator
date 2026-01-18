#include "InputPerson.h"

vector<Person> manualInputPerson()
{
    int n = 0;

    // Ask how many students
    while (true)
    {
        cout << "Enter number of students: ";
        cin >> n;

        if (cin.fail() || n <= 0)
        {
            clearWrongInputs();
            cout << "Invalid number. Try again.\n";
        }
        else
        {
            break;
        }
    }

    vector<Person> students;

    // Input each student
    for (int i = 0; i < n; i++)
    {
        Person student;
        cin >> student;      // overloaded >> operator
        students.push_back(student);
    }

    return students;
}
