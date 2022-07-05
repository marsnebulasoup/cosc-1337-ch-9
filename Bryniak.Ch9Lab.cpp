/*
Playlist Sorter
Author: Kevin Bryniak
Status: Incomplete
Completed: N/A
This program prompts the user for a list of song/artist names and sorts and displays them.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

const string TITLE = "Playlist Sorter";
const string DESCRIPTION = "This program prompts the user for a list of song/artist names and sorts and displays them.";
const string PROMPT_TITLE = "Enter a song title: ";
const string PROMPT_ARTIST = "Enter the artist: ";
const string PROMPT_REPEAT = "Add another song? (y/n): ";
const string OUTPUT_HEADER = "       Artist             Title\n======================================";
const string EMPTY_VAL = "N/A";

struct Song
{
  string title;
  string artist;

  Song(string title = EMPTY_VAL, string artist = EMPTY_VAL)
  {
    Song::title = title != "" ? title : EMPTY_VAL;
    Song::artist = artist != "" ? artist : EMPTY_VAL;
  }
};

string input(string prompt = "> ");
void sort(vector<Song> &songs);

int main()
{
  cout << TITLE << endl
       << DESCRIPTION << endl
       << endl;

  vector<Song> songs;

  do
  {
    cout << endl;
    string title = input(PROMPT_TITLE);
    string artist = input(PROMPT_ARTIST);

    songs.push_back(Song(title, artist));
    
  } while (input(PROMPT_REPEAT) != "n");


  sort(songs);

  cout << OUTPUT_HEADER << endl;
  for (Song song : songs)
  {
    cout << setw(20) << left << song.artist << setw(20) << song.title << endl;
  };
  return 0;
}

// Inputs a string from the user
string input(string prompt)
{
  string input;
  cout << prompt;
  getline(cin, input);
  return input;
}

// Sorts the songs in place in alphabetical order by artist, using selection sort
void sort(vector<Song> &songs)
{
  for (int start = 0; start < songs.size(); start++)
  {
    int min = start;
    for (int index = start + 1; index < songs.size(); index++)
    {
      if (songs[index].artist < songs[min].artist)
      {
        min = index;
      }
    }
    swap(songs[start], songs[min]);
  }
}

