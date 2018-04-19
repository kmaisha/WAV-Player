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

#include "menu.h"
#include "SDL.h"
#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include "audio.h"
#include "rater.h"
#include <conio.h>
#include <algorithm>
#include <iterator>
#include <ctime>

using namespace std;


int main(int argc, char* argv[])
{
	//Sets the default color of the console 
	system("COLOR 0F");
	//Initializes a menu object
	menu m;
	//Initializes the vector for songs that were played. 
	vector<song> played;
	//Initializes the vector data structure to implement the rating that a user can assign to every song
	vector<rater> rating;
	//The string choice stores the user selection when the menu is displayed
	string choice;
	//The boolean acts as the master switch of the program
	bool master = true;
	//Increminting count just counts the total number of songs that have been played, it is usefull when the user wants to play the previous song
	int count = 0;
	//The add function adds all the options into the menu
	m.add();
	//Displays welcome prompt with ascii imaging
	cout << "\nWelcome to group 10's WAV player!!" << endl << endl
		<< "			        d8b        " << endl
		<< "			        Y8P        " << endl
		<< "                                   " << endl
		<< "88888b.d88b.  888  888 .d8888b  888 .d8888b" << endl
		<< "888 '888 '88b 888  888 88K      888 d88P" << endl
		<< "888  888  888 888  888 'Y8888b. 888 888  " << endl
		<< "888  888  888 888  888 'Y8888b. 888 888  " << endl
		<< "888  888  888 Y88b 888     X888 88Y 88b." << endl
		<< "888  888  888 'Y88888  88888P'  888 'Y8888P " << endl << endl;
	//While the master switch for the program is on, continue
	while (master)
	{
		//This sets the choice to whatever they picked when the display options were displayed
		choice = (m.display());
		//This exits the program by turning off the master switch boolean
		if (choice.compare("Quit") == 0)
		{
			master = false;
		}
		//If the user choose to customize text color, this calls the setColor() method
		else if (choice.compare("Customize Text Color") == 0)
		{
			m.setColor();
		}
		//Changes the background color by calling the method using the menu object
		else if (choice.compare("Customize Background Color") == 0)
		{
			m.setBackgroundColor();
		}
		//Plays a random song if the user chooses
		else if (choice.compare("Random Song") == 0)
		{
			//Random returns a random song option
			choice = m.random();
			//This playes the song, which is a random
			song playing(choice);
			//If the song plays and all is good in the universe
			if (playing.init() && playing.load() && playing.setDevice())
			{
				cout << "Great Success\n";
			}
			//Otherwise exit the program
			else
			{
				//Exit the program because there was a glitch in the matrix
				return 1;
			}
			//This prompt is to enhance the viewer's listening experience
			cout << "Press 'p' to pause audio, 'u' to unpause, 'v' to change the volume,"
				<< " 'r' to rate the song, and 'q' to quit...\n";

			playing.play();
			bool dup = false;
			rater r = rater(playing.name, playing.rating);
			for (int i = 0; i < rating.size(); i++)
			{
				//If what you are putting in is already in the list, it doesn't allow double input.
				//If you want to change the rating, the previous rating is removed and replaced by the new rating
				if (r.name.compare(rating[i].name) == 0 && r.rating == rating[i].rating)
				{
					dup = true;
				}
				else if (r.name.compare(rating[i].name) == 0)
				{
					dup = true;
					rating[i].change_rating(r.rating);
				}
			}
			//If the song does not have a rating yet, push in the rating
			if (!(dup))
			{
				rating.push_back(r);
			}
			played.push_back(choice);
			//Increminting count just counts the total number of songs that have been played, it is usefull when the user wants to play the previous song
			count++;
		}
		//If the user wants to set the volume
		else if (choice.compare("Set Volume") == 0)
		{
			//The int newVol stores the user's desire, but first initializes it to 0
			int newVol = 0;
			cout << "Please enter the volume you'd like to play the song at (0-8):  ";
			//Takes the users input
			cin >> newVol;
			//If the user does not enter a valid input, they are physically unable to enter a number 1-8 
			if (!(changeVol(newVol)))
			{
				cout << "Invalid volume selection...\n";
			}
		}
		//If the user wants to play the previous song, the method to do that will be called.
		else if (choice.compare("Previous Song") == 0 && count > 0 && played.size() > 0)
		{
			//Removes the next song from the stack so that the song choice remains the same
			song playing = played.back();
			//If its all good, proceed with this if statement
			if (playing.init() && playing.load() && playing.setDevice())
			{
				cout << "Great Success\n";
			}
			//Otherwise exit the program becuase there was a glitch in the matrix
			else
			{
				//Exit the program because there was a glitch in the matrix
				return 1;
			}
			//The user can once again adjust the volume 
			cout << "Press 'p' to pause audio, 'u' to unpause, 'v' to change the volume,"
				<< " 'r' to rate the song, and 'q' to quit...\n";
			//Allows the song to play
			playing.play();
			//Initializes the boolean variable which will be used to check for duplicate songs in the rater
			bool dup = false;
			//Instantiates the rating object
			rater r = rater(playing.name, playing.rating);
			//The for loop checks for duplicate ratings for the same songs in the rater
			for (int i = 0; i < rating.size(); i++)
			{
				//If what you are putting in is already in the list, it doesn't allow double input.
				//If you want to change the rating, the previous rating is removed and replaced by the new rating
				if (r.name.compare(rating[i].name) == 0 && r.rating == rating[i].rating)
				{
					dup = true;
				}
				else if (r.name.compare(rating[i].name) == 0)
				{
					dup = true;
					rating[i].change_rating(r.rating);
				}
			}
			//If the song does not have a rating yet, push in the rating
			if (!(dup))
			{
				rating.push_back(r);
			}
			played.push_back(choice);
			//Increminting count just counts the total number of songs that have been played, it is usefull when the user wants to play the previous song
			count++;
		}
		else if (choice.compare("Autoplay") == 0 && count >= 0)
		{
			//Initializes the autoplay and exit bools so that the songs keep going
			bool autoplay = true, exit = false;
			//The i variable will be used to select the song to play during autoplay and will be incremented after each song because the songs are in a vector
			int i = 0;
			//While autoplay is true and exit is false
			while (autoplay && !(exit))
			{
				//The song that is assigned to choice is the i^(th) song of the playlist
				choice = m.playlist[i];
				//If the user wants to play the previous song, break out of autoplay
				if (choice.compare("Previous Song") == 0)
				{
					autoplay = false;
				}
				//Otherwise just keep swimming and don't touch the  boat
				else
				{
					song playing(choice);
					//This means the song was initialized, loaded properly, and device playback is successful
					if (playing.init() && playing.load() && playing.setDevice())
					{
						cout << "Great Success\n";
					}
					//Exit the program if one of the three requirements from the comment above are unsuccessful
					else
					{
						//Exit the program because there was a glitch in the matrix
						return 1;
					}
					//The user can once again change the volume/pause/exit
					cout << "Press 'p' to pause audio, 'u' to unpause, 'v' to change the volume,"
						<< "\n'r' to rate the song, 'q' to quit, and 'x' to exit back to menu...\n";
					exit = playing.play();
					//Initializes the boolean variable which will be used to check for duplicate songs in the rater
					bool dup = false;
					//Instantiates the rating object, it holds the values for the name of the song and its rating
					rater r = rater(playing.name, playing.rating);
					for (int i = 0; i < rating.size(); i++)
					{
						//If what what you are putting in is already in the list, it doesn't allow double input.
						//If you want to change the rating, the previous rating is removed and replaced by the new rating
						if (r.name.compare(rating[i].name) == 0 && r.rating == rating[i].rating)
						{
							dup = true;
						}
						else if (r.name.compare(rating[i].name) == 0)
						{
							dup = true;
							rating[i].change_rating(r.rating);
						}
					}
					//If the song does not have a rating yet, push in the rating because duplicate == false
					if (!(dup))
					{
						rating.push_back(r);
					}
					played.push_back(playing);
					//Increminting count just counts the total number of songs that have been played, it is usefull when the user wants to play the previous song
					count++;
					//i is incremented so that the next song can be played
					i++;
				}
			}
		}
		//Plays music in random order
		else if (choice.compare("Shuffle Play") == 0 && count >= 0) {
			//Instantiates the vector object
			vector<string> songPlayed;
			//Instantiates variables that will be used to tell the program when to exit the shuffle function and stop playing music
			bool shuffle = true, exit = false;
			//int i is a counter so that the music stops playing once every song has been played as no songs are repeated in shuffle
			int i = 0;
			//When shuffle is true and exit is false
			while (shuffle && !(exit))
			{
				if (m.songs.size() == 0)
				{
					//Puts all songs into a temporary vector
					for (int j = 0; j < songPlayed.size(); j++) {
						m.songs[j] = songPlayed[j];
					}
				}
				if (m.songs.size() == 1) {
					shuffle = false;
				}
				//Chooses random song to play
				int num = m.randRange(m.songs.size());
				choice = m.songs[num];
				//Removes song from playlist so the same song is not played multiple times
				m.songs.erase(m.songs.begin() + num);
				//Adds song to the songs played to keep track of all the songs
				songPlayed.push_back(choice);

				//Plays the song
				song playing(choice);
				//If everything is all good
				if (playing.init() && playing.load() && playing.setDevice())
				{
					cout << "Great Success\n";
				}
				//Something unexpected happened and the program will exit
				else
				{
					system("PAUSE");
					//Exit the program because there was a glitch in the matrix
					return 1;
				}
				cout << "Press 'p' to pause audio, 'u' to unpause, 'v' to change the volume,"
					<< "\n'r' to rate the song, 'q' to quit, and 'x' to exit back to menu...\n";
				//This is how we exit the loop
				//The exit boolean is tied to the choice the user makes in play
				exit = playing.play();

				//Duplicate flags if the song is already in the rater
				bool dup = false;
				//Instantiates the rating object, it holds the values for the name of the song and its rating
				rater r = rater(playing.name, playing.rating);
				//Checks for duplicate ratings by going through each song
				for (int i = 0; i < rating.size(); i++)
				{
					//If what you are putting in is already in the list, it doesn't allow double input.
					//If you want to change the rating, the previous rating is removed and replaced by the new rating
					if (r.name.compare(rating[i].name) == 0 && r.rating == rating[i].rating)
					{
						dup = true;
					}
					else if (r.name.compare(rating[i].name) == 0)
					{
						dup = true;
						rating[i].change_rating(r.rating);
					}
				}
				//If the song does not have a rating yet, push in the rating because duplicate == false
				if (!(dup))
				{
					rating.push_back(r);
				}
				rating.push_back(r);
				played.push_back(playing);
				//Increminting count just counts the total number of songs that have been played, it is usefull when the user wants to play the previous song
				count++;
				//i is incremented so that the next song can be played
				i++;
			}
		}
		//This plays the songs that have have been thumbed up by the user
		else if (count >= 0 && choice.compare("Play Favorites") == 0) {
			bool favorite = true, exit = false;
			//Instantiates a vector object to play the favorite songs
			vector<rater> favorites;
			//int i will be used to know when to stop playing music because no songs are repeated and i will be incremented after each song
			int i = 0;
			//If no songs have been thumbed up, the program cannot play any song
			if (rating.size() == 0) {
				cout << "No songs favorited...\n";
			}
			for (int d = 0; d < rating.size(); d++)
			{
				if (rating[d].rating == 1)
				{
					favorites.push_back(rating[d]);
				}
			}
			//When favorite is true and exit is false and i hasn't surpassed the number of songs
			while (favorite && !(exit) && i < favorites.size())
			{
				//The i^(th) song will be played
				choice = favorites[i].name;
				song playing(choice);
				//If this was successful, print out that it was successful
				if (playing.init() && playing.load() && playing.setDevice())
				{
					cout << "Great Success\n";
				}
				else
				{
					//Exit the program because there was a glitch in the matrix
					return 1;
				}
				cout << "Press 'p' to pause audio, 'u' to unpause, 'v' to change the volume,"
					<< "\n'r' to rate the song, 'q' to quit, and 'x' to exit back to menu...\n";
				//This is how we exit the loop
				//The exit boolean is tied to the choice the user makes in play
				exit = playing.play();
				//Initializes the boolean variable which will be used to check for duplicate songs in the rater
				bool dup = false;
				//Instantiates the rating object, it holds the values for the name of the song and its rating
				rater r = rater(playing.name, playing.rating);
				for (int i = 0; i < rating.size(); i++)
				{
					//If what you are putting in is already in the list, it doesn't allow double input.
					//If you want to change the rating, the previous rating is removed and replaced by the new rating
					if (r.name.compare(rating[i].name) == 0 && r.rating == rating[i].rating)
					{
						dup = true;
					}
					else if (r.name.compare(rating[i].name) == 0)
					{
						dup = true;
						rating[i].change_rating(r.rating);
					}
				}
				//If the song does not have a rating yet, push in the rating
				if (!(dup))
				{
					rating.push_back(r);
				}
				played.push_back(playing);
				//Increminting count just counts the total number of songs that have been played, it is usefull when the user wants to play the previous song
				count++;
				//Increment i so that the next song that has been thumbed up can play
				i++;
			}
		}
		// If the user wants to remove a song from the playlist
		else if (count >= 0 && choice.compare("Remove") == 0)
		{
			// This initializes the variable that the user will then override to remove a song
			int removeNum = 0;
			cout << "Enter song number to be removed: ";
			// User decides which number song to remove
			cin >> removeNum;
			// Error checking so you remove the correct number
			while (removeNum > m.numSongs || removeNum < 1 || !(cin.good()))
			{
				cout << endl << "ERROR: Invalid selection.  Please try again: ";
				cin >> removeNum;
			}
			// Sets the string to check to remove
			string removie = m.songs[removeNum - 1];
			// Extracts the removed song from the played list
			if (played.back().name.compare(removie) == 0)
			{
				played.erase(played.begin() + played.size() - 1);
			}
			// Goes through the rating list and extracts the removed song
			for (int i = 0; i < rating.size(); i++)
			{
				if (rating[i].name.compare(removie) == 0)
				{
					rating.erase(rating.begin() + i);
				}
			}
			// Removes song from songs list
			m.songs.erase(m.songs.begin() + removeNum - 1);
			// Removes song from playlist in general
			m.playlist.erase(m.playlist.begin() + removeNum - 1);
			cout << "Song removed sucessfully..." << endl;
		}
		else if (count >= 0 && choice.compare("Previous Song") != 0)
		{
			song playing(choice);
			if (playing.init() && playing.load() && playing.setDevice())
			{
				cout << "Great Success\n";
			}
			else
			{
				//Exit the program because there was a glitch in the matrix
				return 1;
			}
			//The user can change the volume/pause/quit
			cout << "Press 'p' to pause audio, 'u' to unpause, 'v' to change the volume,"
				<< " 'r' to rate the song, and 'q' to quit...\n";
			//Allows the song to play
			playing.play();
			//Initializes the boolean variable which will be used to check for duplicate songs in the rater
			bool dup = false;
			//Instantiates the rating object, it holds the values for the name of the song and its rating
			rater r = rater(playing.name, playing.rating);
			for (int i = 0; i < rating.size(); i++)
			{
				//If what what you are putting in is already in the list, it doesn't allow double input.
				//If you want to change the rating, the previous rating is removed and replaced by the new rating
				if (r.name.compare(rating[i].name) == 0 && r.rating == rating[i].rating)
				{
					dup = true;
				}
				else if (r.name.compare(rating[i].name) == 0)
				{
					dup = true;
					rating[i].change_rating(r.rating);
				}
			}
			//If the song does not have a rating yet, push in the rating
			if (!(dup))
			{
				rating.push_back(r);
			}
			played.push_back(playing);
			//Increminting count just counts the total number of songs that have been played, it is usefull when the user wants to play the previous song
			count++;
		}
		//No songs have been played yet
		else
		{
			cout << "No previous song found..." << endl;
		}
	}
	//Everything is cool fam, just exit the program gracefully (like LaLa Land)
	return 0;
}