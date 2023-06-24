#include <iostream>
#include <string>
#include <fstream>
#include <limits>

#include "Course.h++"
#include "AVLTree.h++"

// Function to print the main menu
void printMenu() {
    std::cout << "        1. Load Data Structure" << std::endl;
    std::cout << "        2. Print Course List"   << std::endl;
    std::cout << "        3. Print Course"        << std::endl;
    std::cout << "        9. Exit"                << std::endl;
    std::cout << "What would you like to do? ";
}

int main()
{
    int option = 0;

    AVLTree tree;

    std::cout << "Welcome to the course planner." << std::endl;

    while (true) {
        printMenu();
        std::cin >> option;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear(); // reset error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore wrong input
            continue; // skip the rest of the loop and start over
        }

        switch (option) {
            case 1: {
                std::string path;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore leftover '\n'
                std::cout << "Please provide the path to the file: ";
                std::getline(std::cin, path);

                // remove the quotes if present
                path.erase(std::remove(path.begin(), path.end(), '\"' ), path.end());

                std::ifstream file(path);
                if(!file) {
                    std::cout << "Error opening file. Please check the path and try again.\n";
                } else {
                    std::cout << "Loading Data Structure...\n";
                    std::string line;
                    while (std::getline(file, line)) {
                        // error handling while loading the data
                        if(!tree.insert(line)) {
                            std::cout << "Error loading data from line: " << line << "\n";
                        }
                    }
                    std::cout << "Data loaded successfully.\n";
                }
                break;
            }
            case 2:
                if(tree.isEmpty()) {
                    std::cout << "No course data loaded. Please load course data first.\n";
                } else {
                    std::cout << "Here is a sample schedule:\n";
                    tree.printCourseList();
                }
                break;
            case 3: {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore leftover '\n'
                std::cout << "What course do you want to know about? ";
                std::string courseNumber;
                std::getline(std::cin, courseNumber);

                Course* course = tree.findCourse(courseNumber);
                if (course == nullptr) {
                    std::cout << "Course not found.\n";
                } else {
                    std::cout << course->courseNumber << ", " << course->title << '\n';
                    if (!course->prerequisites.empty()) {
                        std::cout << "Prerequisites: ";
                        for (size_t i = 0; i < course->prerequisites.size(); i++) {
                            std::cout << course->prerequisites[i];
                            if (i < course->prerequisites.size() - 1) {
                                std::cout << ", ";
                            }
                        }
                        std::cout << '\n';
                    }
                }
                break;
            }
            case 9:
                std::cout << "Thank you for using the course planner!\n";
                return 0;
            default:
                std::cout << option << " is not a valid option.\n";
                break;
        }
    }
}
