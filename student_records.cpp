/*
Author: Eddie O'Con
Assignment: Student Records Manager
Description: Student Data Input:
             
-The user enters a student's name, grade level, and GPA.
-The grade level is selected from an enumeration (enum).
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <cctype>
#include <sstream>

enum GradeLevel { FRESHMAN = 1, SOPHOMORE, JUNIOR, SENIOR };

using String = std::string;
using Grade  = GradeLevel;

namespace StudentUtils {

    void formatName(String& name) {
        std::transform(name.begin(), name.end(), name.begin(),
                       [](unsigned char ch){ return static_cast<char>(std::toupper(ch)); });
    }
    
    String gradeToString(Grade level) {
        switch (level) {
            case FRESHMAN:  return "Freshman";
            case SOPHOMORE: return "Sophomore";
            case JUNIOR:    return "Junior";
            case SENIOR:    return "Senior";
            default:        return "Unknown";
        }
    }
  
    String formatGPA(double gpa) {
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(2) << gpa;
        return oss.str(); // return as string per requirement
    }
    
    void displayStudentInfo(const String& nameUpper,
                            Grade level,
                            const String& gpaStr)
    {
        std::cout << "\nStudent Record:\n";
        std::cout << "Name: "        << nameUpper              << "\n";
        std::cout << "Grade Level: " << gradeToString(level)   << "\n";
        std::cout << "GPA: "         << gpaStr                 << "\n";
    }
}

int main() {
    using namespace std; // local using for brevity in main

    String name;
    int gradeInput = 0;
    double gpa = 0.0;

    // --- Input ---
    cout << "Enter student name: ";
    getline(cin, name);

    cout << "Enter grade level (1=Freshman, 2=Sophomore, 3=Junior, 4=Senior): ";
    cin  >> gradeInput;

    cout << "Enter GPA: ";
    cin  >> gpa;
    
    if (gradeInput < 1 || gradeInput > 4) {
        cout << "\nInvalid grade selection. Please enter a number 1-4.\n";
        return 1;
    }
    
    StudentUtils::formatName(name);                 // uppercase the name
    Grade level = static_cast<Grade>(gradeInput);   // numeric -> enum
    String gpaStr = StudentUtils::formatGPA(gpa);   // two decimals as string

    // --- Output ---
    StudentUtils::displayStudentInfo(name, level, gpaStr);

    return 0;
}
