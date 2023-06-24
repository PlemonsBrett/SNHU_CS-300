//
// Created by Brett on 6/18/2023.
//

#include <utility>

#include "Course.h++"

Course::Course(std::string  courseNumber, std::string  title,
               const std::vector<std::string>& prerequisites)
               : courseNumber(std::move(courseNumber)), title(std::move(title)), prerequisites(prerequisites) {}