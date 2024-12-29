#pragma once
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <random>
#include <vector>
#include <cmath>
#include <chrono>
#include <thread>
#include "Song.h"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"


using namespace std;

class Playlist {
private:
    Song* head;
    Song* temp;

    Song* findSongByTitle(const string& title) {
        if (!Song::isValidString(title)) {
            cerr << RED << "Invalid title. Title must not be empty and contain only alphabets." << RESET << endl;
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

    bool sortSongsByTitle() {
        if (!head || head->next == head) {
            cout << YELLOW << "The playlist is empty or has only one song. No sorting needed." << RESET << endl;
            return false;
        }
        Song* current = head;
        do {
            Song* minSong = current;
            Song* temp = current->next;

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
        } while (current != head);
        return true;
    }

    bool sortSongsByArtist() {
        if (!head || head->next == head) {
            cout << YELLOW << "The playlist is empty or has only one song. No sorting needed." << RESET << endl;
            return false;
        }
        Song* current = head;
        do {
            Song* minSong = current;
            Song* temp = current->next;
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
        return true;
    }

    bool sortSongsByGenre() {
        if (!head || head->next == head) {
            cout << YELLOW << "The playlist is empty or has only one song. No sorting needed." << RESET << endl;
            return false;
        }
        Song* current = head;
        do {
            Song* minSong = current;
            Song* temp = current->next;
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
        return true;
    }

    bool sortSongsByAlbum() {
        if (!head || head->next == head) {
            cout << YELLOW << "The playlist is empty or has only one song. No sorting needed." << RESET << endl;
            return false;
        }
        Song* current = head;
        do {
            Song* minSong = current;
            Song* temp = current->next;
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
        return true;
    }

    bool sortSongsByYear() {
        if (!head || head->next == head) {
            cout << YELLOW << "The playlist is empty or has only one song. No sorting needed." << RESET << endl;
            return false;
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

        return true;
    }

    bool sortSongsByDuration() {
        if (!head) {
            cout << RED << "The playlist is empty. Cannot sort." << RESET << endl;
            return false;
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
        return true;
    }

    bool sortSongsByFavorite() {
        if (!head) {
            cout << "The playlist is empty. Cannot sort." << endl;
            return false;
        }
        Song* current = head;
        do {
            Song* minSong = current;
            Song* temp = current->next;
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
            current = current->next;
        } while (current != head);
        return true;
    }

public:
    Playlist() {
        head = nullptr;
        temp = nullptr;
    }

    void addSong(const string& title, const string& artist, const string& genre, const string& album, int year, double duration) {
        try {
            Song* newSong = new Song(title, artist, genre, album, year, duration);
            if (!head) {
                head = newSong;
                head->next = head;
                head->prev = head;
                cout << "Added song: " << title << YELLOW << " (Playlist initialized)." << RESET << endl;
            }
            else {
                Song* tail = head->prev;
                tail->next = newSong;
                newSong->prev = tail;
                newSong->next = head;
                head->prev = newSong;
                cout << "Added song: " << title << "." << endl;
            }
        }
        catch (const invalid_argument& e) {
            cerr << RED << "Error adding song: " << RESET << YELLOW << string(e.what()) << RESET << endl;
        }
    }

    bool removeSong(const string& title) {
        if (!head) {
            cout << RED << "Playlist is empty. Cannot remove song." << RESET << endl;
            return false;
        }

        if (!Song::isValidString(title)) {
            cerr << RED << "Invalid song title: " << RESET << title << endl;
            return false;
        }

        char confirm;
        cout << YELLOW << "Are you sure you want to delete this song? (y/n): " << RESET;
        cin >> confirm;
        if (confirm != 'y' && confirm != 'Y') {
            cout << GREEN << "Action canceled." << RESET << endl;
            return false;
        }


        Song* current = head;
        do {
            if (current->title == title) {
                if (current->next == current) {
                    delete current;
                    head = nullptr;
                    cout << "Removed song: " << title << YELLOW << " (Playlist is empty now)." << RESET << endl;
                }
                else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;

                    if (current == head) {
                        head = current->next;
                    }

                    delete current;
                    cout << "Removed song: " << title << "." << endl;
                }
                return true;
            }
            current = current->next;
        } while (current != head);
        return false;
    }

    void displayPlaylist() {
        if (!head) {
            cout << YELLOW << "The playlist is empty." << RESET << endl;
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
            cout << endl;
            current = current->next;
            index++;
        } while (current != head);
    }

    void displaySongsTable() {
        if (!head) {
            cout << RED << "The playlist is empty." << RESET << endl;
            return;
        }

        cout << BOLD << "+-----+------------------------+------------------------+---------+--------+" << RESET << endl;
        cout << BOLD << "| No. | Title                  | Artist                 | Year    | Duration |" << RESET << endl;
        cout << BOLD << "+-----+------------------------+------------------------+---------+--------+" << RESET << endl;
        int index = 1;
        Song* current = head;
        do {
            cout << "| " << setw(3) << index << " | "
                << setw(22) << current->title << " | "
                << setw(22) << current->artist << " | "
                << setw(7) << current->year << " | "
                << setw(6) << fixed << setprecision(1) << current->duration << " |";
            if (current->isFavorite) {
                cout << " ⭐";
            }
            cout << endl;
            index++;
            current = current->next;
        } while (current != head);

        cout << "+-----+------------------------+------------------------+---------+--------+" << endl;
    }


    void nextSong() {
        if (!head) {
            cout << RED << "The playlist is empty. Cannot navigate." << RESET << endl;
            return;
        }

        if (!temp) temp = head;

        temp = temp->next;
        cout << "Now playing: " << temp->title << " by " << temp->artist << endl;
    }

    void previousSong() {
        if (!head) {
            cout << RED << "The playlist is empty. Cannot navigate." << RESET << endl;
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
            cout << YELLOW << "No song is currently selected." << RESET << endl;
        }
        else {
            cout << "Currently selected: " << temp->title << " by " << temp->artist << endl;
        }
    }

    bool searchSongByTitle(const string& title) {
        if (!head) {
            cout << RED << "The playlist is empty. Cannot search." << RESET << endl;
            return false;
        }

        if (!Song::isValidString(title)) {
            cerr << RED << "Invalid title: " << RESET << title << endl;
            return false;
        }

        Song* current = head;
        vector<string> suggestions;
        bool found = false;

        do {
            if (current->title == title) {
                found = true;
                cout << GREEN << "Song found: " << RESET << current->title << " by " << current->artist;
                if (current->isFavorite) {
                    cout << " ⭐";
                }
                cout << endl;
                found = true;
                break;
            }
            if (current->title.find(title) != string::npos) {
                suggestions.push_back(current->title);
            }
            current = current->next;
        } while (current != head);

        if (!found) {
            cout << RED << "Song not found." << RESET << endl;
            if (!suggestions.empty()) {
                cout << YELLOW << "Did you mean: " << RESET;
                for (const auto& suggestion : suggestions) {
                    cout << suggestion << ", ";
                }
                cout << endl;
                return false;
            }
        }
        return true;
    }

    bool editSong(const string& oldTitle, const string& newTitle, const string& newArtist, double newDuration, int newYear) {
        if (!head) {
            cout << RED << "The playlist is empty." << RESET << endl;
            return false;
        }

        if (!Song::isValidString(oldTitle) || !Song::isValidString(newTitle) || !Song::isValidString(newArtist) || !Song::isValidDuration(newDuration) || !Song::isValidYear(newYear)) {
            cerr << RED << "Invalid data provided for the update." << RESET << endl;
            return false;
        }

        Song* song = findSongByTitle(oldTitle);

        if (!song) {
            cout << RED << "Song not found." << RESET << endl;
            return false;
        }

        song->title = newTitle;
        song->artist = newArtist;
        song->duration = newDuration;
        song->year = newYear;

        cout << GREEN << "Song details updated successfully." << RESET << endl;
        return true;
    }

    bool toggleFavorite(const string& title) {
        if (!head) {
            cout << RED << "The playlist is empty." << RESET << endl;
            return false;
        }
        Song* current = head;
        do {
            if (current->title == title) {
                current->isFavorite = !current->isFavorite;
                cout << "Song \"" << title << "\" is now "
                    << (current->isFavorite ? "marked as favorite." : "unmarked as favorite.") << endl;
                return true;
            }
            current = current->next;
        } while (current != head);
        cout << "Song \"" << title << "\" not found." << endl;
        return false;
    }

    void displayFavorites() {
        if (!head) {
            cout << RED << "The playlist is empty." << RESET << endl;
            return;
        }

        Song* current = head;
        int favoriteCount = 0;

        cout << BOLD << CYAN << "\nFavorite Songs in the Playlist:" << RESET << endl;
        cout << BOLD << "+-----+------------------------+------------------------+------------+------+----------+" << RESET << endl;
        cout << BOLD << "| No. | Title                  | Artist                 | Genre      | Year | Duration |" << RESET << endl;
        cout << BOLD << "+-----+------------------------+------------------------+------------+------+----------+" << RESET << endl;

        do {
            if (current->isFavorite) {
                favoriteCount++;
                cout << "| " << setw(3) << favoriteCount << " | "
                    << setw(22) << current->title << " | "
                    << setw(22) << current->artist << " | "
                    << setw(10) << current->genre << " | "
                    << setw(4) << current->year << " | "
                    << setw(8) << fixed << setprecision(1) << current->duration << " mins |" << endl;
            }
            current = current->next;
        } while (current != head);

        cout << BOLD << "+-----+------------------------+------------------------+------------+------+----------+" << RESET << endl;

        if (favoriteCount == 0) {
            cout << YELLOW << "No favorite songs in the playlist." << RESET << endl;
        }
        else {
            cout << GREEN << "You have " << favoriteCount << " favorite song"
                << (favoriteCount > 1 ? "s" : "") << " in the playlist." << RESET << endl;
        }
    }



    void toggleSongStatus(const string& title) {
        if (!Song::isValidString(title)) {
            cerr << RED << "Invalid song title: " << RESET << title << endl;
            return;
        }
        if (!head) {
            cout << RED << "The playlist is empty." << RESET << endl;
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
        cout << "Song \"" << title << RED << "\" not found." << RESET << endl;
    }

    void shufflePlaylist() {
        if (!head)
        {
            cout << YELLOW << "The playlist is empty. Cannot shuffle." << RESET << endl;
            return;
        }

        showProgressBar("Shuffling..");

        random_device rd;
        default_random_engine engine(rd());

        vector<Song*> songs;
        Song* current = head;
        do
        {
            songs.push_back(current);
            current = current->next;
        } while (current != head);
        shuffle(songs.begin(), songs.end(), engine);
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
        cout << GREEN << "Playlist shuffled." << RESET << endl;
    }

    void sortSongs() {
        cout << BOLD << CYAN << "\n===== Sorting Options =====" << RESET << endl;
        cout << GREEN << "1. Sort songs by Title" << RESET << endl;
        cout << GREEN << "2. Sort songs by Artist" << RESET << endl;
        cout << GREEN << "3. Sort songs by Genre" << RESET << endl;
        cout << GREEN << "4. Sort songs by Album" << RESET << endl;
        cout << GREEN << "5. Sort songs by Year" << RESET << endl;
        cout << GREEN << "6. Sort songs by Duration" << RESET << endl;
        cout << GREEN << "7. Sort songs by Favorite Status" << RESET << endl;
        cout << BOLD << CYAN << "===========================" << RESET << endl;

        int choice;
        do {
            cout << BOLD << "Enter your choice (1-7): " << RESET;
            cin >> choice;

            if (cin.fail() || choice < 1 || choice > 7) {
                cin.clear(); // Clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                cout << RED << "Invalid input! Please enter a number between 1 and 7." << RESET << endl;
                continue;
            }

            bool success = false;
            switch (choice) {
            case 1:
                success = sortSongsByTitle();
                break;
            case 2:
                success = sortSongsByArtist();
                break;
            case 3:
                success = sortSongsByGenre();
                break;
            case 4:
                success = sortSongsByAlbum();
                break;
            case 5:
                success = sortSongsByYear();
                break;
            case 6:
                success = sortSongsByDuration();
                break;
            case 7:
                success = sortSongsByFavorite();
                break;
            }

            if (success) {
                cout << BOLD << GREEN << "Songs sorted successfully!" << RESET << endl;
            }
            else {
                cout << BOLD << RED << "Sorting failed. Ensure the playlist has enough songs to sort." << RESET << endl;
            }

            break; // Exit the loop after successful input and sorting
        } while (true);
    }



    int totalSongs() {
        int count = 0;
        if (!head)
        {
            return count;
        }
        Song* current = head;
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
        Song* current = head;
        do
        {
            totalDuration += current->duration;
            count++;
            current = current->next;
        } while (current != head);
        return totalDuration / count;
    }

    void savePlaylistToFile(const string& filename) {
        ofstream outputFile(filename);
        if (!outputFile)
        {
            cerr << RED << "Error opening file for writing." << RESET << endl;
            return;
        }
        if (!head)
        {
            return;
        }

        showProgressBar("SAVEING..");

        Song* current = head;
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
        cout << YELLOW << "Playlist saved to " << RESET << filename << endl;
    }

    void loadPlaylistFromFile(const string& filename) {
        ifstream inputFile(filename);
        if (!inputFile)
        {
            cerr << RED << "Error opening file for reading." << RESET << endl;
            return;
        }

        showProgressBar("LOADING..");

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
            catch (const exception& e)
            {
                cerr << RED << "Error parsing line: " << line << ". Skipping." << RESET << endl;
            }
        }
        inputFile.close();
        cout << YELLOW << "Playlist loaded from " << RESET << filename << endl;
    }

    static void showProgressBar(const string& message, int steps = 10) {
        cout << message;
        for (int i = 0; i < steps; ++i) {
            cout << "." << flush;
            this_thread::sleep_for(chrono::milliseconds(100));
        }
        cout << " Done!" << endl;
    }

    ~Playlist() {
        if (!head) return;

        Song* current = head;
        do {
            Song* nextSong = current->next;
            delete current;
            current = nextSong;
        } while (current != head);
        head = nullptr;
        temp = nullptr;
        cout << "Playlist destroyed. All songs have been removed." << endl;
        system("pause");
    }
};