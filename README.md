# 🎶 HarmonyHub - Playlist Manager 🎶  

**HarmonyHub** is a collaborative project developed by students of the **Faculty of Computers and Information (FCI), Suez Canal University (SCU)**. This project demonstrates the power of **Circular Doubly Linked Lists (CDLLs)** in managing music playlists efficiently, offering a seamless user experience for music lovers and developers alike.

---

## 🌟 Key Features  

### 🎼 Playlist Management  
- **Add Songs**: Add songs with complete details like title, artist, genre, album, year, and duration.  
- **Remove Songs**: Delete songs by title.  
- **Edit Songs**: Update song information interactively.  
- **Mark Favorites**: Highlight songs as favorites for easy access.  

### 🔀 Navigation  
- **Next & Previous**: Seamlessly move forward or backward through your playlist.  
- **Current Song**: Always know what’s playing.  

### 📊 Analytics & Organization  
- **Sort Playlist**: Sort songs by title, artist, genre, album, year, duration, or favorites.  
- **Statistics**: View total songs and calculate the average duration.  

### 💾 File Operations  
- **Save & Load**: Save your playlist to a file or load an existing playlist.  

---

## ⚙️ Implementation  

At the core of **HarmonyHub** is the **Circular Doubly Linked List (CDLL)**, a robust data structure that ensures efficient navigation and modification of the playlist.  

### Why CDLL?  
1. **Cyclic Nature**: Ideal for playlists that loop back to the start.  
2. **Bidirectional Traversal**: Navigate seamlessly in both forward and backward directions.  
3. **Dynamic Memory Management**: Efficient addition and removal of songs.  

### How It Works  
- Each song is represented as a **node**, storing attributes like title, artist, genre, album, year, and duration.  
- The **list is circular**, where the last node points back to the first, forming a loop.  
- **Bidirectional links** allow smooth transitions in either direction.  

---

## 🚀 Getting Started  

### Prerequisites  
- A C++ compiler (e.g., GCC, Clang).  
- Familiarity with compiling and running C++ programs.  

### Installation  
1. Clone the repository:  
   ```bash
   git clone https://github.com/Basem3sam/HarmonyHub.git  
   cd HarmonyHub
2. Compile the project:
   ```bash
   g++ test.cpp -o HarmonyHub
3. Run the program:
   ```bash  
   ./HarmonyHub  

---

## 🛠️ Usage  

Upon running the program, you'll be able to interact with the following features via the user-friendly menu system:  

1. **Manage Songs**: Add, remove, edit, and mark songs as favorites.  
2. **Navigate Playlist**: Move to the next or previous song or display the current song.  
3. **Sort & Analyze**: Sort the playlist by various attributes and view playlist statistics like total songs and average duration.  
4. **Save/Load Playlist**: Save and load playlists from a file.  

---

## 👥 About the Team  

This project was developed by a team of **seven students** from the **Faculty of Computers and Information (FCI), Suez Canal University (SCU)**.  

### Team Members  
- **[Basem Esam](https://github.com/Basem3sam)** (Project Lead): Coordinated tasks and managed integration.  
  - Core Structure & CRUD Operations: Initialized the Circular Doubly Linked List, implemented `addSong()` and `removeSong()`, and ensured proper data validation.

- **[Dina Samy](https://github.com/DinaSamy5)**: Implemented the display and navigation features.  
  - Developed the method to display the playlist and implemented navigation to move forward or backward through the playlist.

- **[Esraa Saeid](https://github.com/esraasaeid8090)**: Implemented the search functionality.  
  - Developed methods to search songs by title and highlighted favorite songs during the search.

- **[Haneen Hatem](https://github.com/HaneenHaatem)**: Responsible for updating song details and validation.  
  - Implemented the `editSong()` function for editing song details and handled validation for edited details.

- **[Rana Ashraf](https://github.com/rana8-long)**: Handled favorites, filters, and song status.  
  - Developed functionality for marking/unmarking songs as favorites and toggling song status (e.g., played, paused).

- **[Ziad Alaa](https://github.com/ZiadAlaa984)**: Implemented sorting, shuffle, and statistics features.  
  - Developed sorting methods to arrange songs and implemented shuffle functionality, while ensuring the circular list structure remained intact.

- **[Khaled Ghoneim](https://github.com/Khaled01090)**: Implemented file operations and statistics.  
  - Developed methods for saving and loading playlists and calculating statistics like total songs and average duration.

---

## 🌟 Highlights  

- **Educational Purpose**: Built as part of our **Data Structures Practical Exam**, applying theoretical knowledge to a real-world problem.  
- **Team Collaboration**: Showcased effective teamwork, communication, and problem-solving skills in a collaborative development environment.  

---

## 🔧 Future Enhancements  

- Add a graphical user interface (GUI) for a more immersive user experience.  
- Support additional file formats like JSON or XML for playlist storage.  
- Implement advanced search filters and sorting mechanisms.  

---

### 🎵 Dive into **HarmonyHub** and experience the perfect blend of music management and data structure mastery! Built with passion by students of Suez Canal University. 😊
