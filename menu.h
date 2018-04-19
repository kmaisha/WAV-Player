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
#include <vector>
#include <string>
#include <ctime>
#include <cctype>
#include <iterator>
#include <sstream>
#include "boost/filesystem.hpp"


using namespace std;

struct menu{
	//Creates a main vector that holds everything from the menu
	vector<string> playlist;
	//Creates a subvector that holds all the songs in the directory
	vector<string> songs;
	//initializes the total to be a 0 
	int total = 0;
	int numSongs;
	//initializes the text to be a 0 char
	char text = '0';
	//initializes the background to be a 0 char
	char background = '0'; 

	//this pushes things into the vector string (playlist)
	void menu::add() 
	{	
		//Accesses Boost's filesystem and utilizes recursive_directory_iterator for entry to the specified directory 
		// The iterator also stores the current recursive level 
		for (boost::filesystem::recursive_directory_iterator end, dir("C:/Users/Maisha/Documents/Visual Studio 2015/Projects/Project2/Project2/Playlist");
			dir != end; ++dir) {
			//this functionality adds new elements to the vector each time new strings are read
			playlist.push_back(dir->path().filename().string());
		}
		// This block of code adds the following options in the main vector after the filenames are added
		playlist.push_back("Previous Song");
		playlist.push_back("Random Song");
		playlist.push_back("Set Volume");
		playlist.push_back("Autoplay");
		playlist.push_back("Shuffle Play");
		playlist.push_back("Customize Text Color");
		playlist.push_back("Customize Background Color");
		playlist.push_back("Remove");
		playlist.push_back("Play Favorites");
		playlist.push_back("Quit");
	}
	//Displays menu and returns the user inputs
	string display() {
		//Variable to number the songs
		int song;
		//Index of the vector
		int i = 0;
		//Remove songs from the vector fields according to user choice 
		songs.erase(songs.begin(), songs.end());
		cout << endl << "Songs:  \n";

		while (i < (int)playlist.size())
		{
			//Formats the menu
			if (playlist[i].compare("Previous Song") == 0)
			{
				//Sets the numSongs for later manipulation of the playlist
				numSongs = i;
				cout << endl << "Options:  \n";
				while (i < (int)playlist.size())
				{
					//Prints out songs and menus, also numbers them
					cout << i + 1 << ". " << playlist[i] << endl;
					//Increments i for next option
					i++;
					//Increments total according to the number of elements in the vector
					total++;
				}
			}
			else
			{
			
				cout << i + 1 << ". " << playlist[i] << endl;
				//Pushes songs in the playlist vector
				songs.push_back(playlist[i]);
				//Increments i for next option
				i++;
			}
			// Increments total according to the number of elements in the vector
			total++;
		}
		do
		{
			
			cout << endl << "Please enter your selection: ";
			//takes in user input for the main menu
			cin >> song;
			if (!(cin.good()) || song > total || song < 1)
			{
				//Checks for input validation
				cerr << "ERROR: Invalid selection.\n\n";
				cout << song << "\n";
			}
		} while (song > total || song < 1 || !(cin.good()));
		//Returns the stirnat playlist - 1
		return playlist[(song)-1];
	}
	//Function to play a random song from the directory 
	string random()
	{
		//Intializes ran at 0
		int ran = 0;
		//Initialize random seed
		srand(time(NULL));
		//Selects random numbers from numSongs using the function below
		ran = rand() % numSongs;
		return playlist[ran];
	}

	int randRange(int r)
	{
		//Intializes ran at 0 
		int ran = 0;
		//Initialize random seed
		srand(time(NULL));
		//Generates random number
		ran = rand() % r;
		//Returns the random number
		return ran;
	}
	//Sets the color of the text while remembering the users background color through selection
	void setColor()  
	{
		int color;
		cout << "0 = Black\n"
			<< "1 = Blue\n"
			<< "2 = Green\n"
			<< "3 = Aqua\n"
			<< "4 = Red\n"
			<< "5 = Purple\n"
			<< "6 = Yellow\n"
			<< "7 = White\n"
			<< "8 = Gray\n"
			<< "9 = Light Blue\n"
			<< "10 = Light Green\n"
			<< "11 = Light Aqua\n"
			<< "12 = Light Red\n"
			<< "13 = Light Purple\n"
			<< "14 = Light Yellow\n"
			<< "15 = Bright White\n";
		cout << "Please enter what color you'd like the text:  ";
		cin >> color;
		if (color == 0)
		{
			text = '0';
			string color = "COLOR ";
			color += background;
			color += text;
			system(color.c_str());

		}
		else if (color == 1)
		{
			text = '1';
			string color = "COLOR ";
			color += background;
			color += text;
			system(color.c_str());

		}
		else if (color == 2)
		{
			text = '2';
			string color = "COLOR ";
			color += background;
			color += text;
			system(color.c_str());
		}
		else if (color == 3)
		{
			text = '3';
			string color = "COLOR ";
			color += background;
			color += text;
			system(color.c_str());
		}
		else if (color == 4)
		{
			text = '4';
			string color = "COLOR ";
			color += background;
			color += text;
			system(color.c_str());
		}
		else if (color == 5)
		{
			text = '5';
			string color = "COLOR ";
			color += background;
			color += text;
			system(color.c_str());
		}
		else if (color == 6)
		{
			text = '6';
			string color = "COLOR ";
			color += background;
			color += text;
			system(color.c_str());
		}
		else if (color == 7)
		{
			text = '7';
			string color = "COLOR ";
			color += background;
			color += text;
			system(color.c_str());
		}
		else if (color == 8)
		{
			text = '8';
			string color = "COLOR ";
			color += background;
			color += text;
			system(color.c_str());
		}
		else if (color == 9)
		{
			text = '9';
			string color = "COLOR ";
			color += background;
			color += text;
			system(color.c_str());
		}
		else if (color == 10)
		{
			text = 'A';
			string color = "COLOR ";
			color += background;
			color += text;
			system(color.c_str());
		}
		else if (color == 11)
		{
			text = 'B';
			string color = "COLOR ";
			color += background;
			color += text;
			system(color.c_str());
		}
		else if (color == 12)
		{
			text = 'C';
			string color = "COLOR ";
			color += background;
			color += text;
			system(color.c_str());
		}
		else if (color == 13)
		{
			text = 'D';
			string color = "COLOR ";
			color += background;
			color += text;
			system(color.c_str());
		}
		else if (color == 14)
		{
			text = 'E';
			string color = "COLOR ";
			color += background;
			color += text;
			system(color.c_str());
		}
		else if (color == 15)
		{
			text = 'F';
			string color = "COLOR ";
			color += background;
			color += text;
			system(color.c_str());
		}
		else if (!cin.good() || color > 15 || color < 1)
		{
			cout << "Invalid Option... Chosing default color bright white";
			system("COLOR 0F");
		}
	}

	void setBackgroundColor()
	{  
		//Sets the background color while remembering the users text color choice through selection
		int color;
		cout << "1 = Blue\n"
			<< "2 = Green\n"
			<< "3 = Aqua\n"
			<< "4 = Red\n"
			<< "5 = Purple\n"
			<< "6 = Yellow\n"
			<< "7 = White\n"
			<< "8 = Gray\n"
			<< "9 = Light Blue\n"
			<< "10 = Light Green\n"
			<< "11 = Light Aqua\n"
			<< "12 = Light Red\n"
			<< "13 = Light Purple\n"
			<< "14 = Light Yellow\n"
			<< "15 = Bright White\n";
		cout << "Please enter what color you'd like the background:  ";
		cin >> color;
		if (color == 1)
		{
			string color = "COLOR 1";
			color += text;
			system(color.c_str());
			background = '1';
		}
		else if (color == 2)
		{
			string color = "COLOR 2";
			color += text;
			system(color.c_str());
			background = '2';
		}
		else if (color == 3)
		{
			string color = "COLOR 3";
			color += text;
			system(color.c_str());
			background = '3';
		}
		else if (color == 4)
		{
			string color = "COLOR 4";
			color += text;
			system(color.c_str());
			background = '4';
		}
		else if (color == 5)
		{
			string color = "COLOR 5";
			color += text;
			system(color.c_str());
			background = '5';
		}
		else if (color == 6)
		{
			string color = "COLOR 6";
			color += text;
			system(color.c_str());
			background = '6';
		}
		else if (color == 7)
		{
			string color = "COLOR 7";
			color += text;
			system(color.c_str());
			background = '7';
		}
		else if (color == 8)
		{
			string color = "COLOR 8";
			color += text;
			system(color.c_str());
			background = '8';
		}
		else if (color == 9)
		{
			string color = "COLOR 9";
			color += text;
			system(color.c_str());
			background = '9';
		}
		else if (color == 10)
		{
			string color = "COLOR A";
			color += text;
			system(color.c_str());
			background = 'A';
		}
		else if (color == 11)
		{
			string color = "COLOR B";
			color += text;
			system(color.c_str());
			background = 'B';
		}
		else if (color == 12)
		{
			string color = "COLOR C";
			color += text;
			system(color.c_str());
			background = 'C';
		}
		else if (color == 13)
		{
			string color = "COLOR D";
			color += text;
			system(color.c_str());
			background = 'D';
		}
		else if (color == 14)
		{
			string color = "COLOR E";
			color += text;
			system(color.c_str());
			background = 'E';
		}
		else if (color == 15)
		{
			string color = "COLOR F";
			color += text;
			system(color.c_str());
			background = 'F';
		}
		else if (!cin.good() || color > 15 || color < 1)
		{
			cout << "Invalid Option... Chosing default background color black";
			system("COLOR 0F");
		}
		//Does not allow the user to pick same color text and background
		else if (background == text)
		{
			cout << "Cannot add the same color";
		}

	}

};

