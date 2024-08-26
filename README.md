Project Three: Corner Grocer

The purpose of this project is to create a program that opens and reads a given text file containing a list of grocery items.
After the list is read, the program prompts the user to chose between three methods of displaying the information.
Option one should allow the user to search for an item/word and return a numeric value for the frequency it occured
Option two should print a comprehensive list of all items listed with their corresponding frequencies, such as (Apples, 15)
Option three will print a histogram of all items and frequencies, similar to option two. However, option three will print one * per each iteration instead of a number
Option four will create a backup file, write all listed items and their frequencies, and then close the file. The program will exit.
If either the original or backup file fails to open, an error message will occur. Each step should be followed by user validation.

In this project, I succeeded at presentation and user feedback. Each necessary step reported back what the user input was.
In addition, I seperated each step by a boarder to better user experience, and properly labeled/seperated aspects of my code by function.\
These two facotrs made it easy for me to navigate my program and identify errors when needed. 

If I were to do this project again, I would better follow programming standards. I would not use endl after user input and would create the backup file at the BEGINNING of the program, not the end. 
Similarly, I would create functions to avoid writing so much in the main file. This would further improve program readability.

I found it most challenging to itereate through all items in the list for options 2 and 3. To overcome this challenege, I first identified that I had to use a for loop.
When I got stuck with the loop, I sought out resources. One resource I found especially helpful was this website --https://www.geeksforgeeks.org/traversing-a-map-or-unordered_map-in-cpp-stl/
In specific, Part 2: Traversing using begin() and end(), helped me fix my for loop. With this resource, I learned to iterate through the entire grocery list and print the necessary values.
Given how essential this resource became, I am sure to add it to my support network. Similarly, I will use sites such as W3Schools for general questions and Stack Overflow for code-specific questions.
Consequently, I beleive for and do loops will be particularly transferable to other projects and course work. I believe that needed to cycle through a large file and return values will be an extremely common occurance.
To keep the program maintainable, readable, and adaptable, I clearly outlined and labeled all aspects of the code. I properly nested loops and functions. Additionally, I grouped together declarations and initilizations. 
Additionally, I grouped related functions and/or aspects of the code together. In the future, it will be easy to read my code and see the thought process behind it. Given this, people can easily identify sections they may want to adapt.
