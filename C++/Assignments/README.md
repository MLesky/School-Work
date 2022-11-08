# C++ ASSIGNMENTS
## 1. ID Generator
### Task
Many organizations have user ids which are constrained in some way. Imagine you work at an internet service provider and the user ids are all two letters followed by two numbers (e.g **aa49). Your task at such an organisation might be to hold a record on the biling activity for each possible user.
Write a function which creates a list of all possible user ids. Assume the letters are all lower case.

    lowercase = 'abcdefghijklmnopqrstuvwxyz'
    digits = '0123456789'
  
 ### Code
 The function uses 4 level nested loops, where each loop generates one of the 4 characters for the ids. The generated ids are concatenated to a string which the function returns
 ### Screenshot
 ![Generated IDs](https://github.com/MLesky/School-Work/blob/Year-2-First-Semester/C%2B%2B/Assignments/generated%20ids.png)