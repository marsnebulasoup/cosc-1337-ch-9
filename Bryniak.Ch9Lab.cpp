/*
Playlist Sorter
Author: Kevin Bryniak
Status: Complete
Completed: 6 July 2022
This program prompts the user for a list of song/artist names and sorts and displays them.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

// Program constants
const string TITLE = "Playlist Sorter";
const string DESCRIPTION = "This program prompts the user for a list of song/artist names and sorts and displays them.";
const string PROMPT_TITLE = "Enter a song title: ";
const string PROMPT_ARTIST = "Enter the artist: ";
const string PROMPT_REPEAT = "Add another song? (y/n): ";
const string OUTPUT_HEADER = "       Artist             Title\n======================================";
const string EMPTY_VAL = "N/A";

// Song structure
struct Song
{
  string title; // Title of the song
  string artist; // Artist of the song

  Song(string title = EMPTY_VAL, string artist = EMPTY_VAL) // Constructor
  {
    Song::title = title != "" ? title : EMPTY_VAL; // If title is not empty, assign it to the title variable
    Song::artist = artist != "" ? artist : EMPTY_VAL; // If artist is not empty, assign it to the artist variable
  }
};

// Function prototypes
string input(string prompt = "> "); // Prompts the user for input
void getSongs(vector<Song> &songs); // Gets the songs from the user
void sort(vector<Song> &songs); // Sorts the songs inplace using selection sort
void display(vector<Song> songs); // Displays the songs

int main()
{
  // Output program description
  cout << TITLE << endl
       << DESCRIPTION << endl
       << endl;

  vector<Song> songs; // Vector of songs

  getSongs(songs); // Gets the songs from the user
  sort(songs); // Sort the songs
  display(songs); // Display the songs
  return 0;
}

// Inputs a string from the user
string input(string prompt)
{
  string input; // Input string
  cout << prompt; // Output the prompt
  getline(cin, input); // Get the input
  return input;
}

void getSongs(vector<Song> &songs)
{
  // Prompt the user for song titles and artist names and add them to the vector
  do
  {
    cout << endl;
    string title = input(PROMPT_TITLE); // Prompt the user for the title of the song
    string artist = input(PROMPT_ARTIST); // Prompt the user for the artist of the song

    songs.push_back(Song(title, artist)); // Add the song to the vector
    
  } while (input(PROMPT_REPEAT) != "n"); // Repeat until the user enters "n"
}

// Sorts the songs in place in alphabetical order by artist, using selection sort
void sort(vector<Song> &songs)
{
  for (int start = 0; start < songs.size(); start++) // Loop through the songs
  {
    int min = start; // Minimum index, i.e. the index of the current "smallest" song
    for (int index = start + 1; index < songs.size(); index++) // Loop through the songs
    {
      if (songs[index].artist < songs[min].artist) // If the current song is "smaller" (alphabetically) than the current minimum
      {
        min = index; // Set the minimum index to the current index
      }      
    }
    swap(songs[start], songs[min]); // Swap the current song with the current minimum
  }
}

void display(vector<Song> songs)
{
  cout << OUTPUT_HEADER << endl; // Output the header
  for (Song song : songs) // Loop through the songs and output them
  {
    cout << setw(20) << left << song.artist << setw(20) << song.title << endl;
  };
}