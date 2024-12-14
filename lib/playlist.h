#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "song.h"


using namespace std;

class Playlist {
  private:
    Song* head;
    Song* temp;

    Song* findSongByTitle(const string& title) {
      if(!Song::isValidString(title)) {
        cerr << "Invalid title. Title must not be empty and contain only alphabets." << endl;
        return nullptr;
      }

      if (!head) return nullptr;

      Song* current = head;
      do {
          if (current->title == title) {
            return current;
          }
          current = current->next;
      } while (current != head);

      return nullptr;
    }

    void sortSongsByTitle() {
      if (!head) {
        cout << "The playlist is empty. Cannot sort." << endl;
        return;
      }
      Song *current = head;
      do {
        Song *minSong = current;
        Song *temp = current->next;

        while (temp != head) {
          if (temp->title < minSong->title) {
            minSong = temp;
          }
          temp = temp->next;
        }
      if (minSong != current) {
          swap(current->title, minSong->title);
          swap(current->artist, minSong->artist);
          swap(current->genre, minSong->genre);
          swap(current->album, minSong->album);
          swap(current->year, minSong->year);
          swap(current->duration, minSong->duration);
          swap(current->isFavorite, minSong->isFavorite);
        }
        current = current->next;
      }while (current != head);
      cout << "Songs sorted by title." << endl;
    }

    void sortSongsByArtist() {
      if (!head) {
        cout << "The playlist is empty. Cannot sort." << endl;
        return;
      }
      Song *current = head;
      do {
        Song *minSong = current;
        Song *temp = current->next;
        while (temp != head) {
          if (temp->artist < minSong->artist) {
            minSong = temp;
          }
          temp = temp->next;
        }
        if (minSong != current) {
          swap(current->title, minSong->title);
          swap(current->artist, minSong->artist);
          swap(current->genre, minSong->genre);
          swap(current->album, minSong->album);
          swap(current->year, minSong->year);
          swap(current->duration, minSong->duration);
          swap(current->isFavorite, minSong->isFavorite);
        }

        current = current->next;
      } while (current != head);
    
      cout << "Songs sorted by artist." << endl;
    }

    void sortSongsByGenre() {
      if (!head) {
        cout << "The playlist is empty. Cannot sort." << endl;
        return;
      }
      Song *current = head;
      do {
        Song *minSong = current;
        Song *temp = current->next;
        while (temp != head) {
          if (temp->genre < minSong->genre) {
            minSong = temp;
          }
          temp = temp->next;
        }

        if (minSong != current) {
          swap(current->title, minSong->title);
          swap(current->artist, minSong->artist);
          swap(current->genre, minSong->genre);
          swap(current->album, minSong->album);
          swap(current->year, minSong->year);
          swap(current->duration, minSong->duration);
          swap(current->isFavorite, minSong->isFavorite);
        }

        current = current->next;
      } while (current != head);
      cout << "Songs sorted by genre." << endl;
    }
  
    void sortSongsByAlbum() {
      if (!head) {
        cout << "The playlist is empty. Cannot sort." << endl;
        return;
      }
      Song *current = head;
      do {
        Song *minSong = current;
        Song *temp = current->next;
        while (temp != head) {
          if (temp->album < minSong->album) {
            minSong = temp;
          }
          temp = temp->next;
        }
        
        if (minSong != current) {
          swap(current->title, minSong->title);
          swap(current->artist, minSong->artist);
          swap(current->genre, minSong->genre);
          swap(current->album, minSong->album);
          swap(current->year, minSong->year);
          swap(current->duration, minSong->duration);
          swap(current->isFavorite, minSong->isFavorite);
        }

        current = current->next;
      } while (current != head);
      cout << "Songs sorted by album." << endl;
    }
  
    void sortSongsByYear() {
    if (!head) {
      cout << "The playlist is empty. Cannot sort." << endl;
      return;
    }

    Song* current = head;
    bool swapped;
    do {
      swapped = false;
      Song* temp = current->next;
      while (temp != head) {
        if (temp->year < current->year) {
          swap(current->title, temp->title);
          swap(current->artist, temp->artist);
          swap(current->genre, temp->genre);
          swap(current->album, temp->album);
          swap(current->year, temp->year);
          swap(current->duration, temp->duration);
          swap(current->isFavorite, temp->isFavorite);
          swapped = true;
        }
        temp = temp->next;
      }
      current = current->next;
    } while (swapped);

    cout << "Songs sorted by year." << endl;
  }

  void sortSongsByDuration() {
    if (!head) {
      cout << "The playlist is empty. Cannot sort." << endl;
      return;
    }

    Song* current = head;
    bool swapped;
    do {
      swapped = false;
      Song* temp = current->next;
      while (temp != head) {
        if (temp->duration < current->duration) {
          swap(current->title, temp->title);
          swap(current->artist, temp->artist);
          swap(current->genre, temp->genre);
          swap(current->album, temp->album);
          swap(current->year, temp->year);
          swap(current->duration, temp->duration);
          swap(current->isFavorite, temp->isFavorite);
          swapped = true;
        }
        temp = temp->next;
      }
      current = current->next;
    } while (swapped);
    cout << "Songs sorted by duration." << endl;
  }

    void sortSongsByFavorite() {
      if (!head) {
        cout << "The playlist is empty. Cannot sort." << endl;
        return;
      }
      Song *current = head;
      do {
        Song *minSong = current;
        Song *temp = current->next;
        while (temp != head) {
          if (temp->isFavorite && !minSong->isFavorite) {
            minSong = temp;
          }
          temp = temp->next;
        }
        if (minSong != current) {
          swap(current->title, minSong->title);
          swap(current->artist, minSong->artist);
          swap(current->genre, minSong->genre);
          swap(current->album, minSong->album);
          swap(current->year, minSong->year);
          swap(current->duration, minSong->duration);
          swap(current->isFavorite, minSong->isFavorite);
        }
      } while (current != head);
      cout << "Songs sorted by favorite." << endl;
    }

  public:
    Playlist() {
      head = nullptr;
      temp = nullptr;
    }

    void addSong(const string& title, const string& artist, const string& genre, const string& album, int year, double duration) {
      try {
        Song* newSong = new Song(title, artist, genre, album, year, duration);
        if(!head) {
          head = newSong;
          head->next = head;
          head->prev = head;
          cout << "Added song: " << title << " (Playlist initialized)." << endl;
        } else {
          Song* tail = head->prev;
          tail->next = newSong;
          newSong->prev = tail;
          newSong->next = head;
          head->prev = newSong;
          cout << "Added song: " << title << "." << endl;
        }
      } catch(const invalid_argument& e) {
        cerr << "Error adding song: " << e.what() << endl;
      }
    }

    void removeSong(const string& title) {
      if(!head) {
        cout << "Playlist is empty. Cannot remove song." << endl;
        return;
      }

      if(!Song::isValidString(title)) {
        cerr << "Invalid song title: " << title << endl;
        return;
      }

      Song* current = head;
      do{
        if(current->title == title){
          if(current->next == current){
            delete current;
            head = nullptr;
            cout << "Removed song: " << title << " (Playlist is empty now)." << endl;
          } else {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            
            if(current == head) {
              head = current->next;
            }
            
            delete current;
            cout << "Removed song: " << title << "." << endl;
          }
          return;
        }
        current = current->next;
      }while(current != head);
      cout << "Song not found in the playlist." << endl;
    }

    void displayPlaylist() {
      if (!head) {
        cout << "The playlist is empty." << endl;
        return;
      }

      Song* current = head;
      int index = 1;
      do {
        cout << index << ". Title: " << current->title
            << " | Artist: " << current->artist
            << " | Genre: " << current->genre
            << " | Album: " << current->album
            << " | Year: " << current->year
            << " | Duration: " << current->duration << " mins";

        if (current->isFavorite) {
          cout << " | ** Favorite Song **";
        }
        cout <<endl;
        current = current->next;
        index++;
      } while (current != head);
    }

    void nextSong() {
      if (!head) {
        cout << "The playlist is empty. Cannot navigate." << endl;
        return;
      }

      if (!temp) temp = head; 

      temp = temp->next; 
      cout << "Now playing: " << temp->title << " by " << temp->artist << endl;
    }

    void previousSong() {
      if (!head) {
        cout << "The playlist is empty. Cannot navigate." << endl;
        return;
      }

      if (!temp) temp = head; 

      temp = temp->prev;
      cout << "Now playing: " << temp->title << " by " << temp->artist << endl;
    }
    
    void displayCurrentSong() {
      if (!temp) {
        temp = head;
      }
      if (!temp) {
        cout << "No song is currently selected." << endl;
      } else {
        cout << "Currently selected: " << temp->title << " by " << temp->artist << endl;
      }
    }

    void searchSongByTitle(const string& title) {
      if (!head) {
        cout << "The playlist is empty. Cannot search." << endl;
        return;
      }

      if(!Song::isValidString(title)) {
        cerr << "Invalid title: " << title << endl;
        return;
      }

      Song* current = head;
      bool found = false;
      do {
        if (current->title == title) {
          cout << "Song found: " << current->title 
              << " by " << current->artist
              << " | Genre: " << current->genre
              << " | Album: " << current->album
              << " | Year: " << current->year
              << " | Duration: " << current->duration << " mins";
          
          if (current->isFavorite) {
            cout << " | **Favorite Song**";
          }
          cout << endl;
          found = true;
          break;
        }
        current = current->next;
      } while (current != head);

      if (!found) {
        cout << "Song not found in the playlist." << endl;
      }
    }

    bool editSong(const string& oldTitle, const string& newTitle, const string& newArtist, double newDuration, int newYear) {
      if (!head) {
        cout << "The playlist is empty." << endl;
        return false;
      }

      if(!Song::isValidString(oldTitle) ||!Song::isValidString(newTitle) ||!Song::isValidString(newArtist) ||!Song::isValidDuration(newDuration) ||!Song::isValidYear(newYear)) {
        cerr << "Invalid data provided for the update." << endl;
        return false;
      }

      Song* song = findSongByTitle(oldTitle);
      
      if (!song) {
        cout << "Song not found." << endl;
        return false;
      }

      song->title = newTitle;
      song->artist = newArtist;
      song->duration = newDuration;
      song->year = newYear;

      cout << "Song details updated successfully." << endl;
      return true;
    }

    void toggleFavorite(const string& title) {
      if (!head) {
        cout << "The playlist is empty." << endl;
        return;
      }
      Song* current = head;
      do {
        if (current->title == title) {
          current->isFavorite = !current->isFavorite;
          cout << "Song \"" << title << "\" is now "
              << (current->isFavorite ? "marked as favorite." : "unmarked as favorite.") << endl;
          return;
        }
        current = current->next;
      } while (current != head);
      cout << "Song \"" << title << "\" not found." << endl;
    }

    void displayFavorites() {
      if (!head) {
        cout << "The playlist is empty." << endl;
        return;
      }
      Song* current = head;
      bool found = false;
      cout << "Favorite Songs in the Playlist:" << endl;
      do {
        if (current->isFavorite) {
          cout << "Title: " << current->title
              << " | Artist: " << current->artist
              << " | Genre: " << current->genre
              << " | Album: " << current->album
              << " | Year: " << current->year
              << " | Duration: " << current->duration << " mins" << endl;
          found = true;
        }
        current = current->next;
      } while (current != head);
      if (!found) {
        cout << "No favorite songs in the playlist." << endl;
      }
    }

    void toggleSongStatus(const string& title) {
      if (!Song::isValidString(title)) {
        cerr << "Invalid song title: " << title << endl;
        return;
      }
      if (!head) {
        cout << "The playlist is empty." << endl;
        return;
      }
      Song* current = head;
      do {
        if (current->title == title) {
          current->status = (current->status == "Paused") ? "Played" : "Paused";
          cout << "Song \"" << title << "\" is now " << current->status << "." << endl;
          return;
        }
        current = current->next;
      } while (current != head);
      cout << "Song \"" << title << "\" not found." << endl;
    }

    void shufflePlaylist(){
      if (!head)
      {
        cout << "The playlist is empty. Cannot shuffle." << endl;
        return;
      }
      vector<Song *> songs;
      Song *current = head;
      do
      {
        songs.push_back(current);
        current = current->next;
      } while (current != head);
      random_shuffle(songs.begin(), songs.end());
      head = songs[0];
      current = head;
      for (int i = 1; i < songs.size(); i++)
      {
        current->next = songs[i];
        songs[i]->prev = current;
        current = current->next;
      }
      current->next = head;
      head->prev = current;
      cout << "Playlist shuffled." << endl;
    }

    void sortSongs() {
      cout << "1-Sorting songs by title..." << endl;
      cout << "2-Sorting songs by artist..." << endl;
      cout << "3-Sorting songs by genre..." << endl;
      cout << "4-Sorting songs by album..." << endl;
      cout << "5-Sorting songs by year..." << endl;
      cout << "6-Sorting songs by duration..." << endl;
      cout << "7-Sorting songs by favorite..." << endl;
      int choice;
      cout << "Enter your choice: ";
      cin >> choice;
      switch (choice) {
      case 1:
        sortSongsByTitle();
        break;

      case 2:
        sortSongsByArtist();
        break;

      case 3:
        sortSongsByGenre();
        break;

      case 4:
        sortSongsByAlbum();
        break;

      case 5:
        sortSongsByYear();
        break;
      case 6:
        sortSongsByDuration();
        break;

      case 7:
        sortSongsByFavorite();
        break;

      default:
        cout << "Invalid choice. Please try again." << endl;
        break;
      }
    }

    int totalSongs() {
      int count = 0;
      if (!head)
      {
        return count;
      }
      Song *current = head;
      do
      {
        count++;
        current = current->next;
      } while (current != head);
      return count;
    }

    double averageDuration() {
      if (!head)
      {
        return 0.0;
      }
      double totalDuration = 0.0;
      int count = 0;
      Song *current = head;
      do
      {
        totalDuration += current->duration;
        count++;
        current = current->next;
      } while (current != head);
      return totalDuration / count;
    }

    void savePlaylistToFile(const string &filename) {
      ofstream outputFile(filename);
      if (!outputFile)
      {
        cerr << "Error opening file for writing." << endl;
        return;
      }
      if (!head)
      {
        return;
      }
      Song *current = head;
      do
      {
        outputFile << current->title << ","
                  << current->artist << ","
                  << current->genre << ","
                  << current->album << ","
                  << current->year << ","
                  << current->duration << ","
                  << (current->isFavorite ? "true" : "false") << endl;
        current = current->next;
      } while (current != head);
      outputFile.close();
      cout << "Playlist saved to " << filename << endl;
    }

    void loadPlaylistFromFile(const string &filename) {
      ifstream inputFile(filename);
      if (!inputFile)
      {
        cerr << "Error opening file for reading." << endl;
        return;
      }
      string line;
      while (getline(inputFile, line))
      {
        istringstream ss(line);
        string title, artist, genre, album, yearStr, durationStr, isFavoriteStr;

        getline(ss, title, ',');
        getline(ss, artist, ',');
        getline(ss, genre, ',');
        getline(ss, album, ',');
        getline(ss, yearStr, ',');
        getline(ss, durationStr, ',');
        getline(ss, isFavoriteStr);

        try
        {
          int year = stoi(yearStr);
          double duration = stod(durationStr);
          bool isFavorite = (isFavoriteStr == "true");
          addSong(title, artist, genre, album, year, duration);
        }
        catch (const exception &e)
        {
          cerr << "Error parsing line: " << line << ". Skipping." << endl;
        }
      }
      inputFile.close();
    cout << "Playlist loaded from " << filename << endl;
    }

    ~Playlist() {
      if(!head) return;

      Song* current = head;
      do {
        Song* nextSong = current->next;
        delete current;
        current = nextSong;
      } while(current != head);
      head = nullptr;
      cout << "Playlist destroyed. All songs have been removed." << endl;
    }
};