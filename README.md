# 🎵 Music Playlist Manager (C++)

A simple console-based **Playlist Manager** implemented in **C++** using a **doubly linked list**.  
This program allows users to add songs, play the current song, move to the next or previous song, and exit the program.

---

## 🚀 Features

- **Add Song:** Add new songs to the playlist dynamically.  
- **Play Song:** Play the current song in the playlist.  
- **Next Song:** Move forward to the next song.  
- **Previous Song:** Move backward to the previous song.  
- **Exit:** Quit the playlist manager gracefully.

---

## 🧠 Data Structure Used

The program uses a **Doubly Linked List** to represent the playlist.

Each song is represented as a `Song` struct containing:
- `string title` → The name of the song  
- `Song* prev` → Pointer to the previous song  
- `Song* next` → Pointer to the next song  

The `Playlist` class manages the songs and maintains:
- `head` → Pointer to the first song  
- `tail` → Pointer to the last song  
- `current` → Pointer to the currently playing song  

---

## 🧩 Class and Function Overview

### **`struct Song`**
Represents a song node in the playlist.

```cpp
struct Song {
    string title;
    Song* prev;
    Song* next;

    Song(string t) {
        title = t;
        prev = nullptr;
        next = nullptr;
    }
};
