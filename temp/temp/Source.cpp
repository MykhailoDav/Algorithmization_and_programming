#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int MAX_NAME_LENGTH = 20;

enum Specialty
{
    KN,
    IK,
    IP1,
    IP2
};

struct Student
{
    int studentNumber;
    char lastName[MAX_NAME_LENGTH];
    int course;
    Specialty specialty;
    double physics;
    double math;
    double it;
};

const char* specialtiesToString(Specialty specialty)
{
    switch (specialty)
    {
    case KN:
        return "KN";
    case IK:
        return "IK";
    case IP1:
        return "IP1";
    case IP2:
        return "IP2";
    default:
        return "Unknown Specialty";
    }
}

string inputString(const string& prompt, int maxLength)
{
    string value;
    while (true)
    {
        cout << prompt;
        getline(cin, value);

        if (value.length() <= maxLength)
        {
            return value;
        }
        else
        {
            cout << "Invalid input. Please enter a string with at most " << maxLength << " characters." << endl;
        }
    }
}

void inputStudents(Student* students, int numberOfStudents)
{
    for (int i = 0; i < numberOfStudents; ++i)
    {
        cout << "Enter data for student #" << i + 1 << ":" << endl;

        cout << "Last Name: ";
        cin.ignore();
        cin.getline(students[i].lastName, MAX_NAME_LENGTH);

        cout << "Course: ";
        cin >> students[i].course;

        // Consume the newline character left in the buffer after reading the course
        cin.ignore();

        cout << "Specialty (0 - KN, 1 - IK, 2 - IP1, 3 - IP2): ";
        int specialtyInput;
        cin >> specialtyInput;
        students[i].specialty = static_cast<Specialty>(specialtyInput);

        cout << "Physics Grade: ";
        cin >> students[i].physics;

        cout << "Math Grade: ";
        cin >> students[i].math;

        cout << "IT Grade: ";
        cin >> students[i].it;

        students[i].studentNumber = i + 1;

        cout << endl;
    }
}

void writeStudentsToBinaryFile(const Student* students, int numberOfStudents, const string& filename)
{
    ofstream outFile(filename, ios::binary | ios::out);
    if (!outFile.is_open())
    {
        cerr << "Error opening file for writing." << endl;
        return;
    }

    outFile.write(reinterpret_cast<const char*>(&numberOfStudents), sizeof(int));
    outFile.write(reinterpret_cast<const char*>(students), sizeof(Student) * numberOfStudents);

    outFile.close();
}

bool compareStudents(const Student& a, const Student& b)
{
    // Calculate the average grade for each student
    double avgGradeA = (a.physics + a.math + a.it) / 3.0;
    double avgGradeB = (b.physics + b.math + b.it) / 3.0;

    // Sort by average grade in descending order
    if (avgGradeA != avgGradeB)
        return avgGradeA < avgGradeB;

    // If average grades are equal, sort by specialty
    if (a.specialty != b.specialty)
        return a.specialty < b.specialty;

    // If both average grades and specialties are equal, sort by last name
    int lastNameComparison = strcmp(a.lastName, b.lastName);
    if (lastNameComparison != 0)
        return lastNameComparison < 0;

    // If last names, average grades, and specialties are equal, sort by student number
    return a.studentNumber < b.studentNumber;
}

void sortStudents(Student* students, int numberOfStudents)
{
    std::sort(students, students + numberOfStudents, compareStudents);
}

void displayTable(const Student* students, int numberOfStudents)
{
    cout << "--------------------------------------------------------------------------" << endl;
    cout << "| No |  Surname   |Course|            Speciality          |  P |  M | I  |" << endl;
    cout << "--------------------------------------------------------------------------" << endl;

    for (int i = 0; i < numberOfStudents; ++i)
    {
        cout << "| " << setw(2) << students[i].studentNumber << " | " << setw(10) << students[i].lastName << " | "
            << setw(4) << students[i].course << " | " << setw(30) << specialtiesToString(students[i].specialty) << " | "
            << setw(2) << students[i].physics << " | " << setw(2) << students[i].math << " | "
            << setw(2) << students[i].it << " |" << endl;
    }
    cout << "--------------------------------------------------------------------------" << endl;
}

void buildIndexFile(const Student* students, int numberOfStudents, const string& indexFilename)
{
    Student* indexStudents = new Student[numberOfStudents];
    std::copy(students, students + numberOfStudents, indexStudents);
    std::sort(indexStudents, indexStudents + numberOfStudents, compareStudents);

    writeStudentsToBinaryFile(indexStudents, numberOfStudents, indexFilename);

    delete[] indexStudents;
}

bool binarySearchStudent(const string& indexFilename, const string& lastName, Specialty specialty, double averageGrade, int numberOfStudents)
{
    ifstream indexFile(indexFilename, ios::binary | ios::in);
    if (!indexFile.is_open())
    {
        cerr << "Error opening index file for reading." << endl;
        return false;
    }

    // Obtain the number of students
    int numberOfIndexStudents;
    indexFile.read(reinterpret_cast<char*>(&numberOfIndexStudents), sizeof(int));

    // Create an array of students for reading from the file
    Student* indexStudents = new Student[numberOfIndexStudents];

    indexFile.read(reinterpret_cast<char*>(indexStudents), sizeof(Student) * numberOfIndexStudents);
    indexFile.close();

    // Create a temporary object for searching
    Student searchStudent;
    searchStudent.specialty = specialty;
    searchStudent.physics = averageGrade;
    strcpy_s(searchStudent.lastName, lastName.c_str());

    // Perform binary search in the sorted array
    bool found = binary_search(indexStudents, indexStudents + numberOfIndexStudents, searchStudent, compareStudents);

    delete[] indexStudents;

    return found;
}

int main()
{
    string filename;
    cout << "Enter the name for the data file: ";
    cin >> filename;

    int numberOfStudents;
    cout << "Enter the number of students: ";
    cin >> numberOfStudents;

    Student* students = new Student[numberOfStudents];
    inputStudents(students, numberOfStudents);

    sortStudents(students, numberOfStudents);

    cout << "Sorted Table:" << endl;

    displayTable(students, numberOfStudents);

    string indexFilename;
    cout << "Enter the name for the index file: ";
    cin >> indexFilename;

    buildIndexFile(students, numberOfStudents, indexFilename);

    char searchLastName[MAX_NAME_LENGTH];
    Specialty searchSpecialty;
    double searchAverageGrade;

    cout << "Enter the last name to search: ";
    cin.ignore();
    cin.getline(searchLastName, MAX_NAME_LENGTH);

    cout << "Enter the specialty to search (0 - KN, 1 - IK, 2 - IP1, 3 - IP2): ";
    int specialtyInput;
    cin >> specialtyInput;
    searchSpecialty = static_cast<Specialty>(specialtyInput);

    cout << "Enter the average grade to search: ";
    cin >> searchAverageGrade;

    bool found = binarySearchStudent(indexFilename, searchLastName, searchSpecialty, searchAverageGrade, numberOfStudents);

    if (found)
        cout << "Student found in the sorted list." << endl;
    else
        cout << "Student not found in the sorted list." << endl;

    delete[] students;

    return 0;
}

