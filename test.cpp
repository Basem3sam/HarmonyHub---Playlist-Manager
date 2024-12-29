#include <windows.h>
#include "lib/Playlist.h"
#include <limits>
#include <cstdlib>
// #define NOMINMAX if u are using another compiler like vs community

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

using namespace std;

void clearScreen() {
#ifdef _WIN32
    system("cls");  // Windows Command Prompt
#else
    system("clear");  // Git Bash, Linux, Mac
#endif
}

void enableVirtualTerminalProcessing() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;

    if (GetConsoleMode(hOut, &dwMode)) {
        dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
        SetConsoleMode(hOut, dwMode);
    }
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

void printLine(char ch, int width) {
    cout << string(width, ch) << endl;
}

void printCentered(const string& text, int width = 125) {
    int padding = max((width - (int)text.length()) / 2, 0);
    cout << string(padding, ' ') << text << endl;
}

void printWrappedAndCentered(const string& text, int width = 125, int lineWidth = 100, int indent = 4) {
    int start = 0;
    string indentSpaces(indent, ' ');
    while (start < (int)text.size()) {
        int end = start + lineWidth;
        if (end > (int)text.size()) {
            end = text.size();
        }
        else {
            end = text.rfind(' ', end);
            if (end == string::npos || end <= start) {
                end = start + lineWidth;
            }
        }
        string line = text.substr(start, end - start);
        printCentered(indentSpaces + line, width);
        start = end + 1;
    }
}

void printWelcomeMessage() {
    const int displayWidth = 125;
    const string borderTop = string(displayWidth, '*');
    const string borderMid = string(displayWidth, '=');
    const string padding = string(displayWidth, ' ');

    // Decorative Top Border
    cout << BOLD << GREEN << borderTop << RESET << endl;

    // Empty Padding Line
    cout << padding << endl;

    // Title Section
    printCentered(string(BOLD) + YELLOW + "WELCOME TO HARMONYHUB" + RESET, displayWidth);
    printCentered(string(CYAN) + "Your Personal Music Organizer" + RESET, displayWidth);

    // Empty Padding Line
    cout << padding << endl;

    // Subtitle Section
    printCentered(string(MAGENTA) + "------------------------------------------------------------" + RESET, displayWidth);
    printCentered(string(BOLD) + "Organize, Explore, and Enjoy Your Music Like Never Before!" + RESET, displayWidth);
    printCentered(string(MAGENTA) + "------------------------------------------------------------" + RESET, displayWidth);

    // Empty Padding Line
    cout << padding << endl;

    // Feature Section
    printCentered(string(BOLD) + CYAN + "Features You'll Love:" + RESET, displayWidth);
    cout << endl;
    printCentered(string(GREEN) + "> Create and manage playlists effortlessly." + RESET, displayWidth);
    printCentered(string(GREEN) + "> Browse, search, and sort your music collection." + RESET, displayWidth);
    printCentered(string(GREEN) + "> Personalize with favorites, shuffle, and sort options." + RESET, displayWidth);

    // Empty Padding Line
    cout << padding << endl;

    // Call to Action Section
    cout << BOLD << BLUE << borderMid << RESET << endl;
    printCentered(string(BOLD) + "Start Your Journey with HarmonyHub Today!" + RESET, displayWidth);
    cout << BOLD << BLUE << borderMid << RESET << endl;

    // Empty Padding Line
    cout << padding << endl;

    // Decorative Bottom Border
    cout << BOLD << GREEN << borderTop << RESET << endl;
}




void printAboutTheTeamAndThanks() {
    const int terminalWidth = 125; // Terminal width

    cout << endl;

    // About the Team Section
    printCentered(string(GREEN) + "=====================================================" + RESET, terminalWidth);
    printCentered(string(BOLD) + GREEN + "ABOUT THE TEAM" + RESET, terminalWidth);
    printCentered(string(GREEN) + "=====================================================" + RESET, terminalWidth);
    cout << endl;

    printWrappedAndCentered("This project, " + string(BOLD) + "HarmonyHub" + RESET + ", was developed by a team of seven talented students "
        "from the " + string(BOLD) + "Faculty of Computers and Information (FCI), Suez Canal University (SCU)" + RESET + ".", terminalWidth, 100);
    cout << endl;

    // Team Members Section Header
    printCentered(string(GREEN) + "TEAM MEMBERS" + RESET, terminalWidth);
    printCentered(string(GREEN) + "-----------------------------------------------------" + RESET, terminalWidth);
    cout << endl;

    // Team Member Details
    struct Member {
        string name;
        string role;
    };

    Member team[] = {
        {"Basem Esam", "Project Lead"},
        {"Dina Samy", "Display & Navigation Specialist"},
        {"Esraa Saeid", "Search Functionality Developer"},
        {"Haneen Hatem", "Update & Validation Expert"},
        {"Khaled Ghoneim", "File Operations Specialist"},
        {"Rana Ashraf", "Favorites Manager"},
        {"Ziad Alaa", "Sorting & Shuffling Developer"}
    };

    for (const auto& member : team) {
        printCentered(string(CYAN) + member.name + RESET + " - " + member.role, terminalWidth);
        cout << endl;
    }

    printCentered(string(GREEN) + "-----------------------------------------------------" + RESET, terminalWidth);
    cout << endl;

    // Thanks Section
    printCentered(string(GREEN) + "=====================================================" + RESET, terminalWidth);
    printCentered(string(MAGENTA) + BOLD + "THANK YOU FOR YOUR SUPPORT!" + RESET, terminalWidth);
    printCentered(string(GREEN) + "=====================================================" + RESET, terminalWidth);
    cout << endl;

    printCentered("Special thanks to all the open-source tools and libraries that powered this project!", terminalWidth);
    printCentered("Heartfelt gratitude to our professors and peers for their valuable feedback and guidance.", terminalWidth);
    printCentered("Explore our project on GitHub: " + string(BOLD) + string(CYAN) + "https://github.com/Basem3sam/HarmonyHub" + RESET, terminalWidth);
    cout << endl;

    printCentered(string(GREEN) + "=====================================================" + RESET, terminalWidth);
}


void addSong(Playlist& playlist) {
    string title, artist, genre, album;
    int year;
    double duration;

    cout << BOLD << CYAN << "\n===== Add Song =====" << RESET << endl;

    cout << GREEN << "Enter Song Title: " << RESET;
    cin.ignore();
    getline(cin, title);

    cout << GREEN << "Enter Artist: " << RESET;
    getline(cin, artist);

    cout << GREEN << "Enter Genre: " << RESET;
    getline(cin, genre);

    cout << GREEN << "Enter Album: " << RESET;
    getline(cin, album);

    cout << GREEN << "Enter Year: " << RESET;
    year = getValidIntInput();

    cout << GREEN << "Enter Duration (in minutes): " << RESET;
    duration = getValidDoubleInput();

    playlist.addSong(title, artist, genre, album, year, duration);
    cout << BOLD << MAGENTA << "Song added successfully!" << RESET << endl;
}

void removeSong(Playlist& playlist) {
    string title;
    cout << BOLD << CYAN << "\n===== Remove Song =====" << RESET << endl;
    cout << GREEN << "Enter the title of the song to remove: " << RESET;
    cin.ignore();
    getline(cin, title);

    if (playlist.removeSong(title)) {
        cout << BOLD << MAGENTA << "Song removed successfully!" << RESET << endl;
    }
    else {
        cout << BOLD << RED << "Error: Song not found!" << RESET << endl;
    }
}

void searchSongByTitle(Playlist& playlist) {
    string title;
    cout << BOLD << CYAN << "\n===== Search Song by Title =====" << RESET << endl;
    cout << GREEN << "Enter the title to search for: " << RESET;
    cin.ignore();
    getline(cin, title);

    if (!playlist.searchSongByTitle(title)) {
        cout << BOLD << RED << "No matching song found!" << RESET << endl;
    }
}

void editSong(Playlist& playlist) {
    string oldTitle, newTitle, newArtist;
    double newDuration;
    int newYear;

    cout << BOLD << CYAN << "\n===== Edit Song =====" << RESET << endl;

    cout << GREEN << "Enter the title of the song to edit: " << RESET;
    cin.ignore();
    getline(cin, oldTitle);

    if (!playlist.searchSongByTitle(oldTitle)) {
        cout << BOLD << RED << "Error: Song not found!" << RESET << endl;
        return;
    }

    cout << GREEN << "Enter new Title: " << RESET;
    getline(cin, newTitle);

    cout << GREEN << "Enter new Artist: " << RESET;
    getline(cin, newArtist);

    cout << GREEN << "Enter new Duration (in minutes): " << RESET;
    newDuration = getValidDoubleInput();

    cout << GREEN << "Enter new Year: " << RESET;
    newYear = getValidIntInput();

    playlist.editSong(oldTitle, newTitle, newArtist, newDuration, newYear);
    cout << BOLD << MAGENTA << "Song updated successfully!" << RESET << endl;
}

void toggleFavorite(Playlist& playlist) {
    string title;
    cout << BOLD << CYAN << "\n===== Toggle Favorite =====" << RESET << endl;
    cout << GREEN << "Enter the title to toggle favorite status: " << RESET;
    cin.ignore();
    getline(cin, title);

    if (playlist.toggleFavorite(title)) {
        cout << BOLD << MAGENTA << "Favorite status updated!" << RESET << endl;
    }
    else {
        cout << BOLD << RED << "Error: Song not found!" << RESET << endl;
    }
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
    cout << BOLD << CYAN << "\n===== General Menu =====" << RESET << endl;
    cout << GREEN << "1. Manage Songs" << RESET << endl;
    cout << GREEN << "2. Navigate Playlist" << RESET << endl;
    cout << GREEN << "3. Display Playlist Info" << RESET << endl;
    cout << GREEN << "4. Playlist Operations (Shuffle, Sort, Save, Load)" << RESET << endl;
    cout << RED << "5. Exit" << RESET << endl;
    cout << CYAN << "=========================" << RESET << endl;
    cout << "Enter your choice: ";
}


void songMenu(Playlist& playlist) {
    int choice;
    do {
        cout << BOLD << CYAN << "\n===== Song Management =====" << endl;
        cout << GREEN << "1. Add Song" << RESET << endl;
        cout << GREEN << "2. Remove Song" << RESET << endl;
        cout << GREEN << "3. Edit Song" << RESET << endl;
        cout << GREEN << "4. Search Song by Title" << RESET << endl;
        cout << GREEN << "5. Toggle Favorite Status" << RESET << endl;
        cout << RED << "6. Back to General Menu" << RESET << endl;
        cout << CYAN << "===========================" << RESET << endl;
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
        cout << BOLD << CYAN << "\n===== Playlist Navigation =====" << RESET << endl;
        cout << GREEN << "1. Next Song" << RESET << endl;
        cout << GREEN << "2. Previous Song" << RESET << endl;
        cout << GREEN << "3. Display Current Song" << RESET << endl;
        cout << RED << "4. Back to General Menu" << RESET << endl;
        cout << CYAN << "===============================" << RESET << endl;
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
        cout << BOLD << CYAN << "\n===== Playlist Info =====" << RESET << endl;
        cout << GREEN << "1. Display Song Playlist" << RESET << endl;
        cout << GREEN << "2. Display Favorites" << RESET << endl;
        cout << GREEN << "3. Display Total Songs" << RESET << endl;
        cout << GREEN << "4. Display Average Duration" << RESET << endl;
        cout << RED << "5. Back to General Menu" << RESET << endl;
        cout << CYAN << "=========================" << RESET << endl;
        cout << "Enter your choice: ";
        choice = getValidIntInput();

        clearScreen();  // Clear screen after each action

        switch (choice) {
        case 1:
            playlist.displaySongsTable();
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
        cout << BOLD << CYAN << "\n===== Playlist Operations =====" << RESET << endl;
        cout << GREEN << "1. Shuffle Playlist" << RESET << endl;
        cout << GREEN << "2. Sort Playlist" << RESET << endl;
        cout << GREEN << "3. Save Playlist to File" << RESET << endl;
        cout << GREEN << "4. Load Playlist from File" << RESET << endl;
        cout << RED << "5. Back to General Menu" << RESET << endl;
        cout << CYAN << "=============================" << RESET << endl;
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
    enableVirtualTerminalProcessing();

    Playlist playlist;
    int choice;

    printWelcomeMessage();

    cout << "Press any key to start organizing your playlist..." << endl;
    cin.get();

    clearScreen();

    cout << BOLD << GREEN << "Welcome to HarmonyHub!" << RESET << endl;
    cout << GREEN << "Let's start organizing your playlist." << RESET << endl;

    cout << "\n" << MAGENTA << "Check out the project on GitHub: " << RESET;
    cout << CYAN << "https://github.com/Basem3sam/HarmonyHub---Playlist-Manager" << RESET << endl;

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
            cout << BOLD << "Exiting Playlist Program. " << GREEN << "Goodbye!" << RESET << endl;
            break;
        default:
            cout << YELLOW << "Invalid choice! Please try again." << RESET << endl;
            break;
        }
    } while (choice != 5);
    Playlist::showProgressBar("Exiting..");
    clearScreen();
    printAboutTheTeamAndThanks();

    system("pause");

    return 0;
}
