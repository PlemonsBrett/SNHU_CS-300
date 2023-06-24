# CS 300 DSA: Analysis and Design

## Description

### What was the problem you were solving in the projects for this course?

This project includes my overall analysis of the data structures, Tree, Hash Table, and Vector, and their implementations in building an Advising Assistance Software that helped avising staff to view courses, their prerequisites, and build an example schedule for students.

### How did you approach the problem? Consider why data structures are important to understand.

The `DataStructure-Analysis.docx` shows a simple implementation using pseudocode of the same application using only either a Tree, Hash Table, or Vector. The conclusion shows the analysis of the three data structures and an overall suggestion for this solution.

The remaining files are the C++ application that make up the application.

In the application we have a Course Structure that is used for holding the data that is stored within the application (all in-memory). The Course Structure serves as the basic building block for the rest of the application that utilizes an AVLTree for managing the courses with their prerequisites.

I was able to ensure that returning a course and it prerequisites would always show the prerequisites in order using a simple in-order traversal of the AVLTree.

Finally, in the `main.cpp` I have implemente a simple menu for user interaction that allows users to load a file containing course data (See `ABCU_Advising_Program_Input.txt`), view all courses currently loaded, search and view a specific course, and generate a sample schedule for a student that is organized based on the course's prerequisites.

### How did you overcome any roadblocks you encountered while going through the activities or project?

I did not run into many road-blocks, the most notable was selecting the type of Tree I would use for holding all of the course data in-memory. We could use a simple binary tree for this with prerequisites stored in a Hash Map within each node, but that would require a significant amount of data duplication, without the Hash Map however, it would be impossible to have a complete binary tree causing it to be inefficient in traversal and retrieval. The other options were to use an AVL Tree or a Red-Black tree to ensure that the tree was always balanced and efficient in traversal and retrieval. I chose to use an AVL Tree because it is more efficient in insertion and deletion than a Red-Black tree, and the data is not going to be changing often, so the extra overhead of a Red-Black tree is not necessary.

I believe this led to a very efficient solution that is easy to maintain and extend in the future.

### How has your work on this project expanded your approach to designing software and developing programs?

In terms of overall design and development of software, as an Engineer with a decade of experience, the problem we were solving here was fairly simple. However, the constraints allowed me to be far more creative than I would have been for a production system. Those constraints being:

- The data is stored in-memory as a database would cause the complexity and level of effort to be significantly higher.
- The data is not changing, so we do not need to worry about concurrency or locking.
- The data is not being persisted, so we do not need to worry about serialization or deserialization.
- The purpose of the Project was to highlight an implementation that could demonstrate the outcome of my analysis of different data structures in the same solution.

The project, technically had 7 weeks that could be allocated to the project, however, I believe if I had started it any earlier I would have over-engineered the solution. I believe the solution I have provided is simple, efficient, and highlights the efficiency of the data structures I have chosen.

### How has your work on this project evolved the way you write programs that are maintainable, readable, and adaptable?

Academically speaking, I believe this project has helped me to improve in the way I approach and build solutions so that I can focus on highlighting specific software engineering principles and concepts. I believe this will help me to be more efficient in my professional work. However, in terms of writing more maintainable, readable, and adaptable code, I am not as certain. I am not a proponent of using an extensive amount of in-line or block comments in code. This can actually have the opposite effect of making the code harder to read and producing a lot of noise for readers. Code should be written in such a way that it is obvious what is being done even to novice engineers. There are some more complex tasks that even with proper naming conventions, and code structure, may require some additional comments to help the reader understand what is happening. However, I believe that if you are writing code that requires a lot of comments to explain what is happening, but this shouldn't be common.

For maintainability, the code doesn't use many modern development practices such as dependency injection, inversion of control, or even a proper build system. I believe the only requirements for the project were to use C++ 17 and that you could run the app with `g++ main.cpp -o main && ./main`. This is not how software is written in a professional environment. My solution is more similar to what is required in a production system for a build system, but is still rather simple. I also decided to use C++ 23 (20 would be the standard), but most modern C++ uses Boost unless memory or cpu resources are a concern. Separation of concerns by using a Class (cpp) and Header (h++) file for each class is a good practice that helps with maintainability and extensibility, but this is a minimum.
