#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a song node (Doubly Linked List)
typedef struct Song {
    char title[100];
    struct Song* prev;
    struct Song* next;
} Song;

// Playlist structure holding pointers to head, tail, and current song
typedef struct {
    Song* head;
    Song* tail;
    Song* current;
} Playlist;

// Function to initialize playlist
void initPlaylist(Playlist* playlist) {
    playlist->head = NULL;
    playlist->tail = NULL;
    playlist->current = NULL;
}

// Function to create a new song node
Song* createSong(const char* title) {
    Song* newSong = (Song*)malloc(sizeof(Song));
    if (!newSong) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    strcpy(newSong->title, title);
    newSong->prev = NULL;
    newSong->next = NULL;
    return newSong;
}

// Function to add a song to the playlist
void addSong(Playlist* playlist, const char* title) {
    Song* song = createSong(title);

    if (playlist->head == NULL) {
        playlist->head = playlist->tail = song;
    } else {
        playlist->tail->next = song;
        song->prev = playlist->tail;
        playlist->tail = song;
    }

    if (playlist->current == NULL) {
        playlist->current = playlist->head;
    }

    printf("OUTPUT IS -----> Added: %s\n", title);
}

// Function to play the current song
void play(const Playlist* playlist) {
    if (playlist->current == NULL)
        printf("OUTPUT IS -----> Playlist is empty.\n");
    else
        printf("OUTPUT IS -----> Playing: %s\n", playlist->current->title);
}

// Function to go to the next song
void nextSong(Playlist* playlist) {
    if (playlist->current && playlist->current->next) {
        playlist->current = playlist->current->next;
        play(playlist);
    } else {
        printf("OUTPUT IS -----> You are at the last song.\n");
        play(playlist);
    }
}

// Function to go to the previous song
void prevSong(Playlist* playlist) {
    if (playlist->current && playlist->current->prev) {
        playlist->current = playlist->current->prev;
        play(playlist);
    } else {
        printf("OUTPUT IS -----> You are at the first song.\n");
        play(playlist);
    }
}

// Free all allocated memory
void freePlaylist(Playlist* playlist) {
    Song* temp = playlist->head;
    while (temp) {
        Song* next = temp->next;
        free(temp);
        temp = next;
    }
    playlist->head = playlist->tail = playlist->current = NULL;
}

int main() {
    Playlist playlist;
    initPlaylist(&playlist);

    int choice;
    char title[100];

    while (1) {
        printf("\n--- Music Playlist Manager ---\n");
        printf("1. Add Song\n");
        printf("2. Play Current Song\n");
        printf("3. Next Song\n");
        printf("4. Previous Song\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("OUTPUT IS -----> Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // clear input buffer
            continue;
        }
        getchar(); // consume newline left by scanf

        switch (choice) {
            case 1:
                printf("Enter song title: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = '\0'; // remove trailing newline
                addSong(&playlist, title);
                break;

            case 2:
                play(&playlist);
                break;

            case 3:
                nextSong(&playlist);
                break;

            case 4:
                prevSong(&playlist);
                break;

            case 5:
                printf("OUTPUT IS -----> Exiting Playlist Manager.\n");
                freePlaylist(&playlist);
                return 0;

            default:
                printf("OUTPUT IS -----> Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
