/*COP3503 Group Project
Milestone 3
Group 10:
Daniel Tymecki,
Kyle Bassignani,
Maisha Nabila,
Daniel Bertak,
Josep Marti,
Samantha Lieberman,
Mical Estifanos
*/

#include <iostream>
#include <string>

//rater keeps track of the song after the song after it has been played, it is like the tabs on the manila folders that are used for organization and easy retreival
using namespace std;
struct rater
{
	//string and rating are the only 2 data fields
	string name;
	int rating;
	//rater was built to preserve the rating for each indivual song


	rater(string name, int rating)
	{
		//creates a pointer that points to the string name
		this->name = name;
		//creates a pointer that points to the int rating
		this->rating = rating;
	}

	//Method which takes in a new rating
	void change_rating(int rating)
	{
		//The old rating now points to the new rating instead
		this->rating = rating;
	}
};