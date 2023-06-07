/**********************************************
 * File: main.cpp                             *
 * Author: Juan Mota                          *
 * Date: 09/2022                              *
 * PURPOSE: Program that will record Students,*
 * Courses, Grades, Semesters, and save them  *
 * into files and print a whole student       *
 * Transcript if needed.		      *
 **********************************************/

#include <string>
#include <iostream>
#include <fstream>
#include <list>

using namespace std;

//Make Ofstream files global so that we can access them from multiple places.
ofstream CoursesFile;
ofstream GradesFile;
ofstream SemestersFile;
ofstream StudentsFile;
ofstream Transcripts;

//Course Entity, compound by a Prefix, Number, Title, and number of credits
struct Course
{
	string CoursePrefix;
	int CourseNum;
	string CourseTitle;
	int NumCredits;
};

//Grade Entity, compound by a Type and a point value
struct Grade
{
	string GradeType;
	double PointValue;
};
// Semester or Academic Period, compound by a Code, Year, and Description (Spring, Summer, or Fall)
struct Semester
{
	string SemesterCode;
	int Year;
	string Description;
};
//Student, which has Last Name, First Name, and Phone Number as attributes.
struct Student
{
	string LastName;
	string FirstName;
	string PhoneNum;
};
//Transcript, which will has a more complex composition, containing similar attributes 
// from the other 4 entities previously defined.
struct Transcript
{
	string LastName;
	string FirstName;
	string CoursePrefix;
	int CourseNum;
	string GradeType;
	string SemesterCode;
};
//Write a new Course into the File
void StoreCourse()
{
	//Open the file in Read-Only mode
	CoursesFile.open("Courses.txt", ios_base::out | ios_base::in);
	
    	// Check if the file already exists
    	if (CoursesFile.is_open()) 
    	{
    		//Close the Read-Only version
     		CoursesFile.close();
     		//Open and start from the bottom
     		CoursesFile.open("Courses.txt", std::ofstream::out | std::ofstream::app );
    	}else // In case that the file has not been created yet.
    	  {
    	  	CoursesFile.clear();// Clear out the previous open call
     		CoursesFile.open("Courses.txt", ios_base::out);// Open the file on a write in version
    	  }
    	  
	//Create a temporary Object and fill in the attributes.
	Course NewCourse;
	
	//Array to store the remaining input.
	string Attributes[4];
	//Counter to set a limit
	int items=0;
	
	//Store until we reach the limit for this list.
	while(items != 4)
	{
		string temp;// Temporary item to store
		cin >> temp;// Assign it next attribute
		Attributes[items] = temp;// Send it to the Array
		items++;// Increase Counter
	}
	
	//Iff we have enough attributes inserted by user
	if(items == 4)
	{
		NewCourse.CoursePrefix = Attributes[0];
		NewCourse.CourseNum = stoi(Attributes[1]);
		NewCourse.CourseTitle = Attributes[2];
		NewCourse.NumCredits = stoi(Attributes[3]);
		
		//Send to file.
		CoursesFile << NewCourse.CoursePrefix << +" " << NewCourse.CourseNum << " "+ 
		NewCourse.CourseTitle +" "<< NewCourse.NumCredits << endl;
	}else //Else, let the user know that we were not able to process the data.
	 	cout << "Invalid Input. Please try again." << endl;
}
//Write a new Grade into the File
void StoreGrade()
{
	//open the file in read only mode
	// only if the file exist
	GradesFile.open("Grades.txt", ios_base::out | ios_base::in);
    
    	if (GradesFile.is_open()) // Check if the file already exists
    	{
    		//Close the Read-Only version
     		GradesFile.close();
     		//Open and start from the bottom
     		GradesFile.open("Grades.txt", std::ofstream::out | std::ofstream::app );
    	}else // In case that the file has not been created yet.
    	  {
    	  	GradesFile.clear();
     		GradesFile.open("Grades.txt", ios_base::out);
    	  }
    	  
    	//Create a temporary Object and fill in the attributes.
	Grade NewGrade;
	
	//Array to store the remaining input.
	string Attributes[2];
	//Counter to set a limit
	int items=0;
	
	while(items != 2)
	{
		string temp;// Temporary item to store
		cin >> temp;// Assign it next attribute
		Attributes[items] = temp;// Send it to the Array
		items++;// Increase Counter
	}
	
	//Iff we have enough attributes inserted by user
	if(items == 2)
	{
		NewGrade.GradeType= Attributes[0];
		NewGrade.PointValue = stod(Attributes[1]);
		
		//Send to file.
		GradesFile << +" "+ NewGrade.GradeType +" " << NewGrade.PointValue << endl;
		
	}else //Else, let the user know that we were not able to process the data.
	 	cout << "Invalid Input. Please try again." << endl;
}
//Write a new Semester into the File
void StoreSemester()
{
	//Open the file in Read-Only mode
	SemestersFile.open("Semesters.txt", ios_base::out | ios_base::in);
	
    	// Check if the file already exists
    	if (SemestersFile.is_open()) 
    	{
    		//Close the Read-Only version
     		SemestersFile.close();
     		//Open and start from the bottom
     		SemestersFile.open("Semesters.txt", std::ofstream::out | std::ofstream::app );
    	}else // In case that the file has not been created yet.
    	  {
    	  	SemestersFile.clear();// Clear out the previous open call
    	  	// Open the file on a write in version
     		SemestersFile.open("Semesters.txt", ios_base::out);
    	  }
    	  
	//Create a temporary Object and fill in the attributes.
	Semester NewPeriod;
	
	//Array to store the remaining input.
	string Attributes[3];
	//Counter to set a limit
	int items=0;
	
	//Store until we reach the limit for this list.
	while(items != 3)
	{
		string temp;// Temporary item to store
		cin >> temp;// Assign it next attribute
		Attributes[items] = temp;// Send it to the Array
		items++;// Increase Counter
	}
	
	//Iff we have enough attributes inserted by user
	if(items == 3)
	{
		NewPeriod.SemesterCode = Attributes[0];
		NewPeriod.Year = stoi(Attributes[1]);
		NewPeriod.Description = Attributes[2];
		
		//Send to file.
		SemestersFile << NewPeriod.SemesterCode +" " << NewPeriod.Year << " "+ NewPeriod.Description << endl;
	}else //Else, let the user know that we were not able to process the data.
	 	cout << "Invalid Input. Please try again." << endl;
}
//Write a new Student into the File
void StoreStudent()
{
	//Open the file in Read-Only mode
	StudentsFile.open("Students.txt", ios_base::out | ios_base::in);
	
    	// Check if the file already exists
    	if (StudentsFile.is_open()) 
    	{
    		//Close the Read-Only version
     		StudentsFile.close();
     		//Open and start from the bottom
     		StudentsFile.open("Students.txt", std::ofstream::out | std::ofstream::app );
    	}else // In case that the file has not been created yet.
    	  {
    	  	StudentsFile.clear();// Clear out the previous open call
     		StudentsFile.open("Students.txt", ios_base::out);// Open the file on a write in version
    	  }
    	  
	//Create a temporary Object and fill in the attributes.
	Student NewStudent;
	
	//Array to store the remaining input.
	string Attributes[3];
	//Counter to set a limit
	int items=0;
	
	//Store until we reach the limit for this list.
	while(items != 3)
	{
		string temp;// Temporary item to store
		cin >> temp;// Assign it next attribute
		Attributes[items] = temp;// Send it to the Array
		items++;// Increase Counter
	}
	
	//Iff we have enough attributes inserted by user
	if(items == 3)
	{
		NewStudent.LastName = Attributes[0];
		NewStudent.FirstName = Attributes[1];
		NewStudent.PhoneNum = Attributes[2];
		
		//Send to file.
		StudentsFile << NewStudent.LastName << " "+ NewStudent.FirstName << " "+ NewStudent.PhoneNum << endl;
	}else //Otherwise, let the user know that we were not able to process the data.
	 	cout << "Invalid Input. Please try again." << endl;
					
	
}
//Write a new Transcript into the File
void StoreTranscript()
{
	//Open the file in Read-Only mode
	Transcripts.open("Transcripts.txt", ios_base::out | ios_base::in);
	
    	// Check if the file already exists
    	if (Transcripts.is_open()) 
    	{
    		//Close the Read-Only version
     		Transcripts.close();
     		//Open and start from the bottom
     		Transcripts.open("Transcripts.txt", std::ofstream::out | std::ofstream::app );
    	}else // In case that the file has not been created yet.
    	  {
    	  	Transcripts.clear();// Clear out the previous open call
     		Transcripts.open("Transcripts.txt", ios_base::out);// Open the file on a write in version
    	  }
    	  
	//Create a temporary Object and fill in the attributes.
	Transcript NewTranscript;
	
	//Array to store the remaining input.
	string Attributes[6];
	//Counter to set a limit
	int items=0;
	
	//Store until we reach the limit for this list.
	while(items != 6)
	{
		string temp;// Temporary item to store
		cin >> temp;// Assign it next attribute
		Attributes[items] = temp;// Send it to the Array
		items++;// Increase Counter
	}
	
	//Iff we have enough attributes inserted by user
	if(items == 6)
	{
		NewTranscript.LastName = Attributes[0];
		NewTranscript.FirstName = Attributes[1];
		NewTranscript.CoursePrefix = Attributes[2];
		
		NewTranscript.CourseNum = stoi(Attributes[3]);
		NewTranscript.GradeType= Attributes[4];
		NewTranscript.SemesterCode = Attributes[5];
		
		//Send to file.
		Transcripts << NewTranscript.LastName << +" " << NewTranscript.FirstName +" "+ 
		NewTranscript.CoursePrefix +" "<< NewTranscript.CourseNum << " "+
		NewTranscript.GradeType << " "+ NewTranscript.SemesterCode << endl;
		
	}else //Else, let the user know that we were not able to process the data.
	 	cout << "Invalid Input. Please try again." << endl;
}
//Method used to return a specific Semester from the records. Needs a Semester Code as parameter.
Semester FindSemester(string SemCode)
{
	Semester NewSem; 
	NewSem.SemesterCode = SemCode;
	
	//Open the file as an ifstream
	ifstream SemestersList("Semesters.txt");
	
	//In case that we never found the item or reach end of file.
	bool Found=false;
	while(!Found || SemestersList)
	{
		string Current;
		SemestersList >> Current;
		//If we found the Item, extract the rest of their attributes.
		if(NewSem.SemesterCode == Current)
		{
			SemestersList >> NewSem.Year;
			SemestersList >> NewSem.Description;
			Found = true;
		}
	}
	//Return the structure
	return NewSem;
}
//Method used to return a specific Course from the records
//Needs a Course prefix and number as a parameter.
Course FindCourse(string Prefix, int Num)
{
	Course ToFind;//Variable to return
	ToFind.CoursePrefix = Prefix;
	ToFind.CourseNum = Num;
	//Open the file as an ifstream
	ifstream CoursesList("Courses.txt");
	//In case that we never found the item or reach end of file.
	bool Found=false;
	while(!Found || CoursesList)
	{
		string CurrentPrefix;
		int CurrentNum;
		
		CoursesList >> CurrentPrefix;
		CoursesList >> CurrentNum;
		//If we found the Item, extract the rest of their attributes.
		if(ToFind.CoursePrefix == CurrentPrefix && ToFind.CourseNum == CurrentNum)
		{
			CoursesList >> ToFind.CourseTitle;
			CoursesList >> ToFind.NumCredits;
			Found = true;
		}
	}
	//Return the structure
	return ToFind;
}
//Function used to return the specific Value of a grade type definition
// Grade type/name required as a parameter to find in the file.
double FindPointVal(string Grade)
{
	double Value; //Value to find.
	string GradeType = Grade;
	//Open the file as an ifstream
	ifstream GradesList("Grades.txt");
	//In case that we never found the item or reach end of file.
	bool Found=false;
	while(!Found || GradesList)
	{
		string Current;
		GradesList >> Current;
		
		if(GradeType == Current)
		{
			GradesList >> Value;
			Found = true;
		}
	}
	//Return the Grade value that represents.
	return Value;
}
//This function will print a more specific and detailed Transcript
//of a Student received as input, Student and their contents must be 
//already in the files to succeed on this request.
void StudentTranscript(string Last, string First)
{
	//Accumulator of all the credit hours done by Student.
	int HoursAcc;
	//Accumulator of all the points obtained from courses taken.
	double GradePoints;
	// First and Last Name from input.
	string LastName = Last;
	string FirstName = First;
	
	//Open the file in Read-Only mode
	ifstream TranscriptList("Transcripts.txt");
	
	//Create a collector of Transcripts that belong to this Student.
	list<Transcript> StudentTranscript;
	//In case that the student does not have any transcripts.
	bool empty = true;
	
	//Run until we reach the end of file.
	while(TranscriptList)
	{
		//Traverse the file and obtained the next two items inside.
		string FirstAtt;
		string SecondAtt;
		TranscriptList >> FirstAtt;
		TranscriptList >> SecondAtt;
		
		//If both items match the Student Credentials
		if(LastName == FirstAtt && FirstName == SecondAtt)
		{
			//Create a new transcript and send it to the List.
			Transcript New;
			New.LastName = LastName;
			New.FirstName = FirstName;
			TranscriptList >> New.CoursePrefix;
			TranscriptList >> New.CourseNum;
			TranscriptList >> New.GradeType;
			TranscriptList >> New.SemesterCode;
			
			//Push to the end of List (We will sort it later)
			StudentTranscript.push_back(New);
			
			//At least we have one item for this student.
			empty = false;
		}
	}
	
	if(empty)//In case that we could not find the Student inserted. Let the User know.
	{
		cout << "Student '"+LastName+" "+FirstName+"' was not found in our records." << endl;
	}else
	 {
	 	//Keep a record of the last Semester Code printed.
	 	string previousCode;
	 	
	 	// Traverse through the list and Print it
		for (auto itr = StudentTranscript.begin(); itr != StudentTranscript.end(); itr++)
		{
			//Compare Current and Previous SemesterCode and check if they are equal
			//If Equal, do not print the Period Header since they are the same semester.
			if(itr->SemesterCode != previousCode)
			{
				Semester Period = FindSemester(itr->SemesterCode);
  				cout << "============ Semester: "<< Period.Description +" " 
  				<< Period.Year << " ============" << endl;
  			}
  			//Finally, Print the Transcript for this Corresponding Semester.
	  		Course TakenCourse = FindCourse(itr->CoursePrefix, itr->CourseNum);
	  		cout << TakenCourse.CoursePrefix << TakenCourse.CourseNum 
	  		<< " "+ TakenCourse.CourseTitle +" (" << TakenCourse.NumCredits << ") "
	  		<< itr->GradeType << endl;
	  		
	  		HoursAcc += TakenCourse.NumCredits;
	  		GradePoints += TakenCourse.NumCredits * FindPointVal(itr->GradeType);
	  		
	  		 //Save the last Semester Code to avoid repeated versions.
	  		 previousCode = itr->SemesterCode;	  			
  		}
  		
  		//Finally, print the Overall GPA of the student and the total number of
  		// credit hours taken.
  		double GPA;
  		//In case that the GPA is 0. Avoid throwing a weird mathematical result from division.
  		if( (int) GradePoints != 0)
  			GPA = GradePoints/HoursAcc;
  		else
  			GPA = 0;
  			
  		//Show results.
  		cout << "  STUDENT HOURS COMPLETED: " << HoursAcc << endl;
  		cout << "  STUDENT GPA: " << GPA << endl;
  	}
}



//List all the current data stored in the files and print it.
void List(string FileName)
{
	//Create an ifstream file with the name provided.
	ifstream File(FileName);
	//Variable to Extract the Line
	string Line;
	
	//Confirm that File exists and it is open.
	if(File.is_open())
	{
		//Traverse the file and get current line.
		while(getline(File,Line))
			cout << Line << endl;// Print it in the terminal.
		//After we finished printing. Make sure we close it.	
		File.close();
	}
}

int main(int argc, char *argv[])
{ 
	//Get the first command from user
	char Command;
	//Prompt the Command line simulation.
	cout << ">>>";
	cin >> Command;
	
	// q for Quit, execute until q is inserted.
	while(Command != 'q')
	{
		if(Command == 't')// Print an entire transcript from a Student.
		{
			//Obtain Student credentials to access their Transcripts.
			string LastName, FirstName;
			
			cin >> LastName;
			cin >> FirstName;
			
			//Send them to the Transcript File and print it.
			StudentTranscript(LastName, FirstName);
		}
		else if(Command == 'a') //Write into a File
		{
			// Grab the next command that will define what type of data
			// the User wants to store.
			char SecondCommand;
			cin >> SecondCommand;
			
			//Depending on the input, either execute or throw an alert.
			switch(SecondCommand)
			{
				case 'c'://Course
					StoreCourse();
					break;
					
				case 'g':// Grade Type
					StoreGrade();
					break;
					
				case 'm'://Semester or Academic Period
					StoreSemester();					
					break;
					
				case 's':// Student
					StoreStudent();
					break;
				// Transcript (LastName, FirstName, Course, Grade, and SemesterCode)
				case 't':
					StoreTranscript();
					break;
				//In case that User gave an unvalid command.
				default:
					cout << "Invalid Input, something is wrong or missing" << endl;
				
			}
		}
		else if(Command == 'l')// Read from a File and print results.
		{
			// Grab the next command that will define what type of data
			// the User wants to store.
			char SecondCommand;
			cin >> SecondCommand;
			
			//Depending on the input, either execute or throw an alert.
			switch(SecondCommand)
			{
				case 'c'://Course
					List("Courses.txt");
					break;
					
				case 'g':// Grade Type
					List("Grades.txt");
					break;
					
				case 'm'://Semester or Academic Period
					List("Semesters.txt");					
					break;
					
				case 's':// Student
					List("Students.txt");
					break;
				// Transcript (LastName, FirstName, Course, Grade, and SemesterCode)
				case 't':
					List("Transcripts.txt");
					break;
				//In case that User gave an unvalid command.
				default:
					cout << "Invalid Input, something is wrong or missing" << endl;
			}
		}
		//After the task is successfully executed, ask the user for a new Command.
		cout << ">>>";
		cin >> Command;
	}
	
	//Finally, close all possible opened files.
	CoursesFile.close();
	GradesFile.close();
	SemestersFile.close();
	StudentsFile.close();
	Transcripts.close();
	
	return 0;
}
