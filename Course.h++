//
// Created by Brett on 6/18/2023.
//

#ifndef ABCUADVISINGASST_COURSE_H
#define ABCUADVISINGASST_COURSE_H

#include <string>
#include <vector>

struct Course {
    std::string courseNumber;
    std::string title;
    std::vector<std::string> prerequisites;

    Course(std::string  courseNumber, std::string  title,
           const std::vector<std::string>& prerequisites);
};


#endif //ABCUADVISINGASST_COURSE_H
