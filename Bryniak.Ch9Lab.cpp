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


int main() {
  return 0;
}