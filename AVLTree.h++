//
// Created by Brett on 6/18/2023.
//

#ifndef ABCUADVISINGASST_AVLTREE_H
#define ABCUADVISINGASST_AVLTREE_H

#include "Course.h++"

struct AVLNode {
    Course* course;
    AVLNode* left;
    AVLNode* right;
    int height;

    explicit AVLNode(Course* course);
};

class AVLTree
{
    AVLNode* root;
private:
    Course * nodeSearch(const AVLNode* node, const std::string& courseNumber) const;

public:
    AVLTree();

    static int height(AVLNode* N);
    static int getBalance(AVLNode* N);
    static AVLNode* rotateRight(AVLNode* y);
    static AVLNode* rotateLeft(AVLNode* x);
    AVLNode* insert(AVLNode* node, Course* course);
    bool insert(const std::string& line);
    void printInOrder(AVLNode* node);
    void printCourseList();
    [[nodiscard]] Course* findCourse(const std::string& courseNumber) const;
    bool isEmpty();

    [[nodiscard]] Course *search(const std::string &key) const;
};


#endif //ABCUADVISINGASST_AVLTREE_H
