#pragma once
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class Song
{
  public:
    string title;
    string artist;
    string genre;
    string album;
    int year;
    double duration;
    bool isFavorite;
    string status;

    Song* next;
    Song* prev;

    Song(const string& title, const string& artist, const string& genre, const string& album, int year, double duration){
      //Validation
      if (!isValidString(title)) {
        cout << "Error: Title cannot be empty." << endl;
        throw invalid_argument("Invalid title");
      }
      if (!isValidString(artist)) {
        cout << "Error: Artist cannot be empty." << endl;
        throw invalid_argument("Invalid artist");
      }
      if (!isValidString(genre)) {
        cout << "Error: Genre cannot be empty." << endl;
        throw invalid_argument("Invalid genre");
      }
      if (!isValidString(album)) {
        cout << "Error: Album cannot be empty." << endl;
        throw invalid_argument("Invalid album");
      }
      if (!isValidYear(year)) {
        cout << "Error: Invalid year. It must be between 1900 and 2024." << endl;
        throw invalid_argument("Invalid year");
      }
      if (!isValidDuration(duration)) {
        cout << "Error: Duration must be a positive number." << endl;
        throw invalid_argument("Invalid duration");
      }
      
      this->title = title;
      this->artist = artist;
      this->genre = genre;
      this->album = album;
      this->year = year;
      this->duration = duration;
      this->isFavorite = false;
      this->status = "paused";
      this->next = nullptr;
      this->prev = nullptr;
    }

    static bool isValidString(const std::string& str) {
      return !str.empty() && str.find_first_not_of(" \t\n\r") != std::string::npos;
    }

    static bool isValidYear(int year) {
      int currentYear = 2024;
      return (year >= 1900 && year <= currentYear);
    } 

    static bool isValidDuration(double duration) {
      return duration > 0;
    }

};