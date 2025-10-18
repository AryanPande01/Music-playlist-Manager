import java.util.Scanner;

// Represents a song in the playlist (Doubly Linked List Node)
class Song {
    String title;
    Song prev;
    Song next;

    // Constructor
    Song(String title) {
        this.title = title;
        this.prev = null;
        this.next = null;
    }
}

// Playlist class to manage songs
class Playlist {
    private Song head = null;
    private Song tail = null;
    private Song current = null;

    // Add a new song to the end of the playlist
    public void addSong(String title) {
        Song song = new Song(title);

        if (head == null) {
            head = tail = song;
        } else {
            tail.next = song;
            song.prev = tail;
            tail = song;
        }

        if (current == null) {
            current = head;
        }

        System.out.println("OUTPUT IS -----> Added: " + title);
    }

    // Play the current song
    public void play() {
        if (current == null) {
            System.out.println("OUTPUT IS -----> Playlist is empty.");
        } else {
            System.out.println("OUTPUT IS -----> Playing: " + current.title);
        }
    }

    // Go to the next song
    public void next() {
        if (current != null && current.next != null) {
            current = current.next;
            play();
        } else {
            System.out.println("OUTPUT IS -----> You are at the last song.");
            play();
        }
    }

    // Go to the previous song
    public void prev() {
        if (current != null && current.prev != null) {
            current = current.prev;
            play();
        } else {
            System.out.println("OUTPUT IS -----> You are at the first song.");
            play();
        }
    }
}

// Main class
public class PlaylistManager {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Playlist playlist = new Playlist();
        int choice;

        while (true) {
            System.out.println("\n--- Music Playlist Manager ---");
            System.out.println("1. Add Song");
            System.out.println("2. Play Current Song");
            System.out.println("3. Next Song");
            System.out.println("4. Previous Song");
            System.out.println("5. Exit");
            System.out.print("Enter your choice: ");

            // Validate numeric input
            if (!sc.hasNextInt()) {
                System.out.println("OUTPUT IS -----> Invalid input. Please enter a number.");
                sc.next(); // discard invalid input
                continue;
            }

            choice = sc.nextInt();
            sc.nextLine(); // clear newline

            switch (choice) {
                case 1:
                    System.out.print("Enter song title: ");
                    String title = sc.nextLine();
                    playlist.addSong(title);
                    break;

                case 2:
                    playlist.play();
                    break;

                case 3:
                    playlist.next();
                    break;

                case 4:
                    playlist.prev();
                    break;

                case 5:
                    System.out.println("OUTPUT IS -----> Exiting Playlist Manager.");
                    sc.close();
                    return;

                default:
                    System.out.println("OUTPUT IS -----> Invalid choice. Please try again.");
            }
        }
    }
}
