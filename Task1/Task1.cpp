#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Person {
private:
    string name;
    string surname;
    vector<double> homework; 
    double exam;
    double finalGrade;

public:
    
    Person() {
        name = "";
        surname = "";
        exam = 0;
        finalGrade = 0;
    }


    Person(string n, string s, vector<double> hw, double ex) {
        name = n;
        surname = s;
        homework = hw;
        exam = ex;
        finalGrade = 0;
    }


    void calculateFinalGrade() {
        double sum = 0;
  
        for (double h : homework) {
            sum += h;
        }

        double hwAverage;
        if (homework.size() > 0)
            hwAverage = sum / homework.size();
        else
            hwAverage = 0;


        finalGrade = 0.4 * hwAverage + 0.6 * exam;
    }

 
    string getName() { return name; }
    string getSurname() { return surname; }
    double getFinalGrade() { return finalGrade; }
};

int main() {

    int studentNumber;
	cout << "Enter number of students: ";
	cin >> studentNumber;

    for (int i = 0; i < studentNumber; i++) {
        string name, surname;
        int hwCount;
        cout << "Enter name of student " << (i + 1) << ": ";
        cin >> name;
        cout << "Enter surname of student " << (i + 1) << ": ";
		cin >> surname;

        cout << "Enter number of homework grades: ";
        cin >> hwCount;
        vector<double> homeworkGrades;
        for (int j = 0; j < hwCount; j++) {
            double grade;
            cout << "Enter homework grades "<<j+1<<" :";
            cin >> grade;
            homeworkGrades.push_back(grade);
        }


        double examGrade;
        cout << "Enter exam grade: ";
        cin >> examGrade;
        Person student(name, surname, homeworkGrades, examGrade);
        student.calculateFinalGrade();
        cout << student.getName() << " " << student.getSurname()
            << " Final Grade: " << student.getFinalGrade() << endl;
	}

    return 0;
}
