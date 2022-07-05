/*
Title
Author: Kevin Bryniak
Status: Incomplete
Completed: N/A
This program prompts the user for a list of song/artist names and sorts and displays them.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

const string TITLE = "Playlist Sorter";
const string DESCRIPTION = "This program prompts the user for a list of song/artist names and sorts and displays them.";
const string PROMPT_TITLE = "Enter a song title: ";
const string PROMPT_ARTIST = "Enter the artist: ";
const string PROMPT_REPEAT = "Add another song? (y/n): ";
const string EMPTY_VAL = "N/A";

string input(string prompt = "> ");

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

int main() {
  return 0;
}

string input(string prompt)
{
  string input;
  cout << prompt;
  getline(cin, input);
  return input;
}
void sort(vector<Song> &songs)
{
  int start = 0;  
  int end = songs.size() - 1;
  for (int start = 0; start < end; start++)
  {
    Song most_alphabetical = songs[start];
    int most_alphabetical_index = start;
    for (int index = start + 1; index <= end; index++)
    {
      Song current = songs[index];
      if (current.artist < most_alphabetical.artist)
      {
        most_alphabetical = current;
        most_alphabetical_index = index;
      }
    }
    songs[most_alphabetical_index] = songs[start];
    songs[start] = most_alphabetical;
  }
}
