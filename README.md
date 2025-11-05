My code is in pa1.c

My makefile is in makefile

Assignment description is included below:

<p align=center><strong>Programming Assignment 1: Basic C programming (100 points)</strong></p>

The goal of this assignment is to become familiar with C programming by implementing a simple program that processes data from a CSV (comma-separated values) file. The program will compute the mean, maximum, and minimum of a specific row or column of integers.

Your task is to write a C program that follows these specifications:

**Input Arguments:**

Your program must accept three command-line arguments:

1\. The input file (a CSV file containing integers) specified as an absolute path

2\. A single character indicating whether to process a column ('c') or a row ('r')

3\. An integer specifying the index of the row or column (0-based indexing)

**Functionality:**

The program should read the CSV file and compute and output the mean, maximum, and minimum of the specified row or column. The CSV column by row count can go up to 100 x 100. The range of individual integers in the CSV files will be for 32-bit unsigned integers.

**Handling Bad Input:**

If the file cannot be opened, the program should print `“Error opening file”` to stdout and exit with status -1

If the specified row or column does not exist, the program should print the following to stdout, and exit with status -1:

`error in input format at line <line number>`

The line number refers to the row number (not index) that caused the error. This means if a requested column is out of range, the line number is always 1. If the requested row is out of range you print the line number corresponding to that row. For example, if I request row 99 for a 4 x 2 csv file, you would print `error in input format at line 100`

You can assume the input CSV file is properly formatted.

**Output Format:**

The program should print the results to stdout in the following format:

`<filename> <"row"|"column"> <mean> <maximum> <minimum>`

The mean should be saved to a double value and displayed with 2 decimal places.

**Example Usage:**

Given a CSV file test1.csv with the following content:
```
143,13,120

209,135,26

186,46,225
```
Running the program as:

`./pa1 /autograder/source/tests/test1.csv r 2`

should output:

`/autograder/source/tests/test1.csv row 152.33 225 46`

Given a CSV file test2.csv with the following content:
```
97,78,34,107,215

55,104,171,0,251

198,209,246,233,73

199,37,241,28,1

49,53,43,185,220
```
Running:

`./pa1 /autograder/source/tests/test2.csv c 4`

should output:

`/autograder/source/tests/test2.csv column 152.00 251 1`

**Submission Requirements:**

Submit your C source code in a single `'pa1.c'` file along with a makefile called `'makefile'` that compiles `pa1.c` to a program called `'pa1'`. **You will receive a 0 if these instructions are not followed.**

**Grading:**

Your program will be tested against 10 CSV test cases in increasing order of difficulty. Each test case is worth 10 points for a total of 100 points. The first two test cases are included in the _example_ section of this write-up.

You need to upload the two files `'pa1.c'` and `'makefile'` to Gradescope. Log into canvas and use the Gradescope tool on the left.

_How to add group members in gradescope:_ https://help.gradescope.com/article/m5qz2xsnjy-student-add-group-members
