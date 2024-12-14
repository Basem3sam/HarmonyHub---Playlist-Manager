#include <iostream>
#include "lib/playlist.h"
#include <limits>
#include <cstdlib>

using namespace std;

void clearScreen() {
  system("cls");
}

int getValidIntInput() {
  int value;
  while (!(cin >> value)) {
    cin.clear();  // Clear error flag
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
    cout << "Invalid input. Please enter a valid number: ";
  }
  return value;
}

double getValidDoubleInput() {
  double value;
  while (!(cin >> value)) {
    cin.clear();  // Clear error flag
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
    cout << "Invalid input. Please enter a valid number: ";
  }
  return value;
}

void addSong(Playlist& playlist) {
  string title, artist, genre, album;
  int year;
  double duration;

  cout << "Enter Song Title: ";
  cin.ignore();  // To clear the buffer before getline
  getline(cin, title);

  cout << "Enter Artist: ";
  getline(cin, artist);

  cout << "Enter Genre: ";
  getline(cin, genre);

  cout << "Enter Album: ";
  getline(cin, album);

  cout << "Enter Year: ";
  year = getValidIntInput();

  cout << "Enter Duration (in minutes): ";
  duration = getValidDoubleInput();

  playlist.addSong(title, artist, genre, album, year, duration);
  cout << "Song added successfully!" << endl;
}

void removeSong(Playlist& playlist) {
  string title;
  cout << "Enter the title of the song to remove: ";
  cin.ignore();
  getline(cin, title);
  playlist.removeSong(title);
  cout << "Song removed successfully!" << endl;
}

void searchSongByTitle(Playlist& playlist) {
  string title;
  cout << "Enter the title to search for: ";
  cin.ignore();
  getline(cin, title);
  playlist.searchSongByTitle(title);
}

void editSong(Playlist& playlist) {
  string oldTitle, newTitle, newArtist;
  double newDuration;
  int newYear;

  cout << "Enter the title of the song to edit: ";
  cin.ignore();
  getline(cin, oldTitle);

  cout << "Enter new Title: ";
  getline(cin, newTitle);

  cout << "Enter new Artist: ";
  getline(cin, newArtist);

  cout << "Enter new Duration (in minutes): ";
  newDuration = getValidDoubleInput();

  cout << "Enter new Year: ";
  newYear = getValidIntInput();

  playlist.editSong(oldTitle, newTitle, newArtist, newDuration, newYear);
  cout << "Song updated successfully!" << endl;
}

void toggleFavorite(Playlist& playlist) {
  string title;
  cout << "Enter the title to toggle favorite status: ";
  cin.ignore();
  getline(cin, title);
  playlist.toggleFavorite(title);
}

void loadPlaylistFromFile(Playlist& playlist) {
  string filename;
  cout << "Enter the filename to load the playlist: ";
  cin >> filename;
  playlist.loadPlaylistFromFile(filename);
}

void savePlaylistToFile(Playlist& playlist) {
  string filename;
  cout << "Enter the filename to save the playlist: ";
  cin >> filename;
  playlist.savePlaylistToFile(filename);
}

void displayTotalSongs(Playlist& playlist) {
  int total = playlist.totalSongs();
  cout << "Total number of songs in the playlist: " << total << endl;
}

void displayAverageDuration(Playlist& playlist) {
  double average = playlist.averageDuration();
  cout << "Average duration of songs in the playlist: " << average << " minutes" << endl;
}


void generalMenu() {
  cout << "\n===== General Menu =====" << endl;
  cout << "1. Manage Songs" << endl;
  cout << "2. Navigate Playlist" << endl;
  cout << "3. Display Playlist Info" << endl;
  cout << "4. Playlist Operations (Shuffle, Sort, Save, Load)" << endl;
  cout << "5. Exit" << endl;
  cout << "=========================" << endl;
  cout << "Enter your choice: ";
}

void songMenu(Playlist& playlist) {
  int choice;
  do {
    cout << "\n===== Song Management =====" << endl;
    cout << "1. Add Song" << endl;
    cout << "2. Remove Song" << endl;
    cout << "3. Edit Song" << endl;
    cout << "4. Search Song by Title" << endl;
    cout << "5. Toggle Favorite Status" << endl;
    cout << "6. Back to General Menu" << endl;
    cout << "===========================" << endl;
    cout << "Enter your choice: ";
    choice = getValidIntInput();

    clearScreen();

    switch (choice) {
      case 1:
        addSong(playlist);
        break;
      case 2:
        removeSong(playlist);
        break;
      case 3:
        editSong(playlist);
        break;
      case 4:
        searchSongByTitle(playlist);
        break;
      case 5:
        toggleFavorite(playlist);
        break;
      case 6:
        break;
      default:
      cout << "Invalid choice! Please try again." << endl;
      break;
    }
  } while (choice != 6);
}

void navigationMenu(Playlist& playlist) {
  int choice;
  do {
    cout << "\n===== Playlist Navigation =====" << endl;
    cout << "1. Next Song" << endl;
    cout << "2. Previous Song" << endl;
    cout << "3. Display Current Song" << endl;
    cout << "4. Back to General Menu" << endl;
    cout << "===============================" << endl;
    cout << "Enter your choice: ";
    choice = getValidIntInput();

    clearScreen();  // Clear screen after each action

    switch (choice) {
      case 1:
        playlist.nextSong();
        break;
      case 2:
        playlist.previousSong();
        break;
      case 3:
        playlist.displayCurrentSong();
        break;
      case 4:
        break;
      default:
        cout << "Invalid choice! Please try again." << endl;
        break;
    }
  } while (choice != 4);
}

void displayInfoMenu(Playlist& playlist) {
  int choice;
  do {
    cout << "\n===== Playlist Info =====" << endl;
    cout << "1. Display Song Playlist" << endl;
    cout << "2. Display Favorites" << endl;
    cout << "3. Display Total Songs" << endl;
    cout << "4. Display Average Duration" << endl;
    cout << "5. Back to General Menu" << endl;
    cout << "=========================" << endl;
    cout << "Enter your choice: ";
    choice = getValidIntInput();

    clearScreen();  // Clear screen after each action

    switch (choice) {
      case 1:
        playlist.displayPlaylist();
        break;
      case 2:
        playlist.displayFavorites();
        break;
      case 3:
        displayTotalSongs(playlist);
        break;
      case 4:
        displayAverageDuration(playlist);
        break;
      case 5:
        break;
      default:
        cout << "Invalid choice! Please try again." << endl;
        break;
    }
  } while (choice != 5);
}

void playlistOperationsMenu(Playlist& playlist) {
  int choice;
  do {
    cout << "\n===== Playlist Operations =====" << endl;
    cout << "1. Shuffle Playlist" << endl;
    cout << "2. Sort Playlist" << endl;
    cout << "3. Save Playlist to File" << endl;
    cout << "4. Load Playlist from File" << endl;
    cout << "5. Back to General Menu" << endl;
    cout << "=============================" << endl;
    cout << "Enter your choice: ";
    choice = getValidIntInput();

    clearScreen();

    switch (choice) {
      case 1:
        playlist.shufflePlaylist();
        break;
      case 2:
        playlist.sortSongs();
        break;
      case 3:
        savePlaylistToFile(playlist);
        break;
      case 4:
        loadPlaylistFromFile(playlist);
        break;
      case 5:
        break;
      default:
        cout << "Invalid choice! Please try again." << endl;
        break;
    }
  } while (choice != 5);
}

int main() {
  Playlist playlist;
  int choice;

  do {
    generalMenu();
    choice = getValidIntInput();
    clearScreen();

    switch (choice) {
        case 1:
            songMenu(playlist);
            break;
        case 2:
            navigationMenu(playlist);
            break;
        case 3:
            displayInfoMenu(playlist);
            break;
        case 4:
            playlistOperationsMenu(playlist);
            break;
        case 5:
            cout << "Exiting Playlist Program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
            break;
        }
    } while (choice != 5);

  cout << "Press any key to continue..." << endl;
  system("pause");

  return 0;
}
