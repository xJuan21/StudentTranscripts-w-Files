# Student Transcripts with Files Project

**Author:**
Juan Mota.

09/2022

**Programming Language:** C++

**OS:** Linux (Fedora)

**Decription:**
Program that keeps track of students, courses, grade types,
semesters, and the relationship(s) between them.

Consequently, the program initializes multiple txt files that will work as storage 
for Information about Students, Valid Grades, Semester History, and Transcript related 
to a specific student.

The program will essentially prompt the user to enter a one-letter command, and process 
the command as follows:

• **a** (for add), which should then read in one of:
  
  – **c**, which should then read a string representing a course prefix, followed by a positive
    integer representing a course number, followed by a string representing a course title,
    and finally a positive integer representing the number of credits for a new course. So,
    the following:
    
    	a c CSC 30500 Principles_Of_Databases 3
       
  should add the course _'CSC 30500 titled Principles_of_Databases'_ worth 3 credit hours.
    
  – **g**, which should then read a string representing a grade type and a floating point number
    representing a point value. So, the following:
    
    	a g B+ 3.5
	
  should add a grade type of _'B+'_ with a value of _'3.5'_.

  – **m**, which should then read a string representing a semester code, followed by a year
    number as a positive integer, and finally a string as a description. These items describe
    a Semester. So, the following:
    
    	a m Sp89 1989 Spring
       
   should add a semester with code _Sp89_ representing year 1989 with description Spring.
    You should assume that only Spring, Summer, or Fall are possibilities for the description.
   
  – **s**, which should then also read the next string as a last name, the following string as a
    first name, and another string as a phone number. These three items together represent
    a new student. So, the following:
    
    	a s Mota Juan 636-949-4681
	
   it'll add a student named _'Juan Mota'_ with a phone number of _'636-949-4681'_.
    
  – **t**, which should then also read the next string as a last name, the following string as
    a first name, a string as a course prefix, an integer as a course number, a string as
    a course grade, and a semester as a string. These items together represent a student
    having completed a course. So, the following:
    
    	a t Mota Juan CSC 30500 B+ Sp89
	
  should add a course taken for _'Juan Mota'_ of _'CSC 30500'_, with a grade of _'B+'_ in _'Sp89'_.
    
• **l** (that is, the letter ’l’ for ”list”), which should then read in one of:

  – **c**, which should list all of the courses. Each course should have its prefix, number, title
    and number of credit hours printed.

  – **g**, which should list all of the grade types. Each grade type printed out should include
    its code and point value.

  – **m**, which should list all of the semesters. Each semester printed out should include its
    code, description, and year.

  – **s**, which should list all of the students. Each student printed out should include their
    last name, first name, and phone number.

  – **t**, which should list all of the courses that have been taken. For each such course taken,
    the student last name, the student first name, the semester code, the course prefix, the
    course number, the course name, and the grade code earned should be printed.
    
• **t** (for ”transcript”), which should read in a student last name followed by a student first name.
  A transcript should then be printed for this student. The transcript should print out the
  student named, followed by the list of courses the student has taken and their corresponding
  grades in each course. These courses should be grouped by ordered semester taken. At the
  end of the student’s transcript, the total number of credit hours taken should be printed as
  well as the student’s overall GPA.
  
• **q** (for ”quit”), which should stop the running program.

_**Some notes:**_

  • After processing one command, the program will continue to prompt the user for another
  command (and process what the user enters). This repeats until the user enters _'q'_.
  
  • Data should be persistent between runs! That is, if you add a course in one run, it should
  appear in another run without re-entering it in the subsequent run.

# ExampleExecution

# Add and List Students

![2023-06-07_20h35_48](https://github.com/xJuan21/StudentTranscripts-w-Files/assets/64575393/d67307f7-f1c7-4913-ac2d-360161910560)

Suppose the first time you run the program, you do the following (**>>>** is the program’s prompt to
the user):

	>>>l s
	>>>a s Mota Juan 6369494681
	>>>a s Gates William 666-MCR-SOFT
	>>>l s

Output:

	Mota, Juan 6369494681
	Gates, William 666-MCR-SOFT

Then, suppose you run the program again (possibly without stopping the above running program):

	>>>l s
	
Output:

	Mota, Juan 6369494681
	Gates, William 666-MCR-SOFT

Add a new Student and list the existing ones stored.

	>>>a s Simpson Lisa 555-1234567
	>>>l s
	
Output:

	Mota, Juan 6369494681
	Gates, William 666-MCR-SOFT
	Simpsom, Lisa 555-1234567

Add another Student

	>>>a s Simpson Bart 555-7654321
	>>>l s

Output:

	Mota, Juan 6369494681
	Gates, William 666-MCR-SOFT
	Simpsom, Lisa 555-1234567
	Simpson, Bart 555-7654321
	
Quit the program:

	>>>q

**-Second Execution-**

	>>>l s

Output:

	Mota, Juan 6369494681
	Gates, William 666-MCR-SOFT
	Simpsom, Lisa 555-1234567
	Simpson, Bart 555-7654321
	


# Add Grade Types, Courses, and Transcripts

![Demo](https://github.com/xJuan21/StudentTranscripts-w-Files/assets/64575393/7fb09842-c714-4d5a-bca2-ca36bb9508de)

**Example with a sequence of multiple data being stored:**

	>>>a c CSC 14400 Computer_Science_I 4
	>>>a c CSC 24400 Computer_Science_II 4
	>>>a c MTH 27100 Calculus_I 5
	>>>a c CSC 30500 Principles_of_Database_Systems 3
	>>>a c CSC 36000 Algorithms 3
	>>>a g A 4
	>>>a g B 3
	>>>a g C 2
	>>>a g D 1
	>>>a g F 0
	>>>a g B+ 3.5
	>>>a m F86 1986 Fall
	>>>a m Sp87 1987 Spring
	>>>a m Su87 1987 Summer
	>>>a m F87 1987 Fall
	>>>a m S87 1987 Spring
	>>>a t Mota Juan CSC 14400 A F86
	>>>a t Mota Juan MTH 27100 B Sp87
	>>>a t Gates William CSC 14400 F F87
	>>>a t Mota Juan CSC 36000 A F87
	>>>a t Mota Juan CSC 30500 A Sp87
	>>>a t Mota Juan CSC 24400 B Sp87
	
Get a specific Transcript:

	>>>t Mota Juan
	
Output:

	============ Semester: Fall 1986 ============
	CSC14400 Computer_Science_I (4) A
	============ Semester: Spring 1987 ============
	CSC24400 Computer_Science_II (4) B
	CSC30500 Principles_Of_Database_Systems (3) A
	MTH27100 Calculus_I (5) B
	============ Semester: Fall 1987 ============
	CSC36000 Algorithms (3) A
	STUDENT HOURS COMPLETED: 19
	STUDENT GPA: 3.52632
	32
	32
	Dr

# Programming Log

In order to complete this Project, it was necessary to proceed with the following strategies/steps:

Procedure:

	a. It was essential to understand the basics of Entities/Objects and their attributes, and how these items make role in future instances. Therefore, it was beneficial to create 'struct' type objects that would allow to keep better track of the data flowing.
	
	b. Understanding how files, the fstream and iostream libraries work since they facilitated the access and creation of files, which allowed the program to simulate a DataBase.
	
	c.  The basic components of a DataBase and how important it is to have a good management of the data in order to store it and retrieve it later.
	
Bugs found in the Program
	- During the execution of the 't Student_LastName Student_FirstName' Command, the program fails on sorting the Semesters properly, and the Printed transcripts will be based on the order it was inserted into the Transcript File. This was attempted to be fixed by using a STL List to store all the Transcripts related to the Student and sort them later depending on the year, if the year matched, this would have been determined by comparing the semester of each object. However, in order to make this comparison successful, it was needed to create overloads and boolean functions that would allow the Standard Template Library List to work with the default sort() function it comes with. However, this version fails on making this possible.

# Summary

As mentioned above, it was very helpful to start this project by creating a structure for each Object, it allowed to have a better management of the values. It also helped while storing or reading the values from files by allowing to create specific functions for each situation; making the Transcript part (A more complex object) easier to work with.

The debugger used (nemiver) was useful to find specific bugs that appeared during the process and to keep track of the values that were being sent to or received from the files.
