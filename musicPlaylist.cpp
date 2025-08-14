#include <iostream>
#include <string>
using namespace std;

struct Song 
{
    string title;   // Song name
    Song* prev;     // Pointer to previous song
    Song* next;     // Pointer to next song

    // Constructor to set song title and initialize pointers
    //explicitly calling the constructor , since the default one will not initialise like what we want 
    Song(string t) 
    {
        title = t;
        prev = nullptr;
        next = nullptr;
    }

};

// Playlist class to manage songs
class Playlist 
{
    Song* head = nullptr; 
    Song* tail = nullptr;     
    Song* current = nullptr;  

public:
    // Add a new song to the end of the playlist
    void addSong(const string& title) 
    {
        Song* song = new Song(title);

        // If playlist is empty, set head & tail to this song
        if (!head) 
            head = tail = song;

        // Otherwise, link the song at the end
        else {
            tail->next = song;   // Current last song points to new song
            song->prev = tail;   // New song points back to old last song
            tail = song;         // Update tail to new song
        }

        // If no song is currently playing, start with this one
        if (!current) 
            current = head;

        cout << "OUTPUT IS ----->"<< "Added: " << title << "\n";
    }

    // Play the current song
    void play() const 
    {
        if (!current) 
            cout <<"OUTPUT IS ----->"<< "Playlist is empty.\n";
        else 
            cout<< "OUTPUT IS ----->"<< "Playing: " << current->title << "\n";
    }

    // Go to the next song in the playlist
    void next() 
    {
        if (current && current->next) 
            current = current->next;  // Move forward
        else 
            cout << "OUTPUT IS ----->"<< "You are at the last song.\n";
        play(); // Show currently playing song
    }

    // Go to the previous song in the playlist
    void prev() 
    {
        if (current && current->prev) 
            current = current->prev;  // Move backward
        else 
            cout << "OUTPUT IS ----->"<< "You are at the first song.\n";

        play(); // Show currently playing song
    }
};

int main() 
{
    Playlist playlist; // playlist is the object of the class Playlist 
    int choice;
    string title;

    while (true) 
    {
        cout << "\n--- Music Playlist Manager ---\n";
        cout << "1. Add Song\n";
        cout << "2. Play Current Song\n";
        cout << "3. Next Song\n";
        cout << "4. Previous Song\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear newline left by cin

        // Perform action based on user choice
        if (choice == 1) 
        {
            cout << "Enter song title: ";
            getline(cin, title);        // Take full song name with spaces
            playlist.addSong(title);
        }

        else if (choice == 2) 
            playlist.play();
        
        else if (choice == 3) 
            playlist.next();
        
        else if (choice == 4) 
            playlist.prev();
        
        else if (choice == 5) 
        {
            cout<< "OUTPUT IS ----->" << "Exiting Playlist Manager.\n";
            break; // Exit loop
        }

        else 
            cout<< "OUTPUT IS ----->" << "Invalid choice. Please try again.\n";
        
    }
}
