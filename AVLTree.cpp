//
// Created by Brett on 6/18/2023.
//

#include "AVLTree.h++"
#include <iostream>
#include <sstream>

AVLNode::AVLNode(Course* course) : course(course), left(nullptr), right(nullptr), height(1) {}

AVLTree::AVLTree() : root(nullptr) {}

int AVLTree::height(AVLNode* N) {
    if (N == nullptr)
        return 0;
    return N->height;
}

int AVLTree::getBalance(AVLNode* N) {
    if (N == nullptr)
        return 0;
    return height(N->left) - height(N->right);
}

AVLNode* AVLTree::rotateRight(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = std::max(height(y->left), height(y->right)) + 1;
    x->height = std::max(height(x->left), height(x->right)) + 1;

    return x;
}

AVLNode* AVLTree::rotateLeft(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = std::max(height(x->left), height(x->right)) + 1;
    y->height = std::max(height(y->left), height(y->right)) + 1;

    return y;
}

AVLNode* AVLTree::insert(AVLNode* node, Course* course) {
    if (node == nullptr)
        return new AVLNode(course);

    if (course->courseNumber < node->course->courseNumber)
        node->left = insert(node->left, course);
    else if (course->courseNumber > node->course->courseNumber)
        node->right = insert(node->right, course);
    else
        return node;

    node->height = 1 + std::max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && course->courseNumber < node->left->course->courseNumber)
        return rotateRight(node);

    if (balance < -1 && course->courseNumber > node->right->course->courseNumber)
        return rotateLeft(node);

    if (balance > 1 && course->courseNumber > node->left->course->courseNumber) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    if (balance < -1 && course->courseNumber < node->right->course->courseNumber) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

bool AVLTree::insert(const std::string& line) {
    std::istringstream iss(line);
    std::string courseNumber, title;
    std::vector<std::string> prerequisites;

    if (!std::getline(iss, courseNumber, ',') || !std::getline(iss, title, ',')) {
        return false; // Return false if the course number or title is missing
    }

    // Remove leading whitespace from the title
    title.erase(title.begin(), std::find_if(title.begin(), title.end(), [](int ch) {
        return !std::isspace(ch);
    }));

    std::string prerequisite;
    while (std::getline(iss, prerequisite, ',')) {
        prerequisite.erase(prerequisite.begin(), std::find_if(prerequisite.begin(), prerequisite.end(), [](int ch) {
            return !std::isspace(ch);
        }));
        prerequisites.push_back(prerequisite);
    }

    auto* course = new Course(courseNumber, title, prerequisites);
    root = insert(root, course);
    return true;
}

void AVLTree::printInOrder(AVLNode* node) {
    if (node != nullptr) {
        printInOrder(node->left);
        std::cout << node->course->courseNumber << ", " << node->course->title << '\n';
        printInOrder(node->right);
    }
}

void AVLTree::printCourseList() {
    printInOrder(root);
}

Course* AVLTree::search(const std::string& key) const {
    std::string lower_key = key;
    std::transform(lower_key.begin(), lower_key.end(), lower_key.begin(), ::tolower);

    return nodeSearch(root, lower_key);
}

Course* AVLTree::nodeSearch(const AVLNode* node, const std::string& key) const {
    if (node == nullptr) {
        return nullptr;
    }

    std::string lower_courseNumber = node->course->courseNumber;
    std::transform(lower_courseNumber.begin(), lower_courseNumber.end(), lower_courseNumber.begin(), ::tolower);

    if (key == lower_courseNumber) {
        return node->course;
    }

    if (key < lower_courseNumber) {
        return nodeSearch(node->left, key);
    } else {
        return nodeSearch(node->right, key);
    }
}


Course* AVLTree::findCourse(const std::string& courseNumber) const {
    return search(courseNumber);
}

bool AVLTree::isEmpty() {
    return root == nullptr;
}
