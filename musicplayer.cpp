#include <iostream>
#include <string>
using namespace std;

// Node class
class Node
{
public:
    string songTitle;
    string artistName;
    Node* prev;
    Node* next;

    Node(string title, string artist)
    {
        songTitle = title;
        artistName = artist;
        prev = nullptr;
        next = nullptr;
    }
};

// Music Playlist class
class MusicPlaylist
{
private:
    Node* head;
    Node* current;

public:

    MusicPlaylist()
    {
        head = nullptr;
        current = nullptr;
    }

    // Add Song
    void addSong(string title, string artist)
    {
        Node* p = new Node(title, artist);

        if (head == nullptr)
        {
            head = p;
            current = head;
            cout << "Song added successfully.\n";
            return;
        }

        Node* q = head;

        while (q->next != nullptr)
        {
            q = q->next;
        }

        q->next = p;
        p->prev = q;

        cout << "Song added successfully.\n";
    }

    // Delete Song
    void deleteSong(string title)
    {
        if (head == nullptr)
        {
            cout << "Playlist is empty.\n";
            return;
        }

        Node* q = head;

        while (q != nullptr && q->songTitle != title)
        {
            q = q->next;
        }

        if (q == nullptr)
        {
            cout << "Song not found.\n";
            return;
        }

        if (q == head && q->next == nullptr)
        {
            head = nullptr;
            current = nullptr;
        }
        else if (q == head)
        {
            head = q->next;
            head->prev = nullptr;

            if (current == q)
                current = head;
        }
        else
        {
            if (q->prev != nullptr)
                q->prev->next = q->next;

            if (q->next != nullptr)
                q->next->prev = q->prev;

            if (current == q)
            {
                if (q->next != nullptr)
                    current = q->next;
                else
                    current = q->prev;
            }
        }

        delete q;
        cout << "Song deleted successfully.\n";
    }

    // Display Forward
    void displayPlaylist()
    {
        if (head == nullptr)
        {
            cout << "Playlist is empty.\n";
            return;
        }

        Node* q = head;

        cout << "\n--- Playlist (Forward) ---\n";

        while (q != nullptr)
        {
            cout << "Song: " << q->songTitle
                 << " | Artist: " << q->artistName;

            if (q == current)
                cout << " <-- CURRENT";

            cout << endl;
            q = q->next;
        }
    }

    // Display Reverse
    void displayReverse()
    {
        if (head == nullptr)
        {
            cout << "Playlist is empty.\n";
            return;
        }

        Node* q = head;

        while (q->next != nullptr)
        {
            q = q->next;
        }

        cout << "\n--- Playlist (Reverse) ---\n";

        while (q != nullptr)
        {
            cout << "Song: " << q->songTitle
                 << " | Artist: " << q->artistName;

            if (q == current)
                cout << " <-- CURRENT";

            cout << endl;
            q = q->prev;
        }
    }

    // Play Current Song
    void playCurrentSong()
    {
        if (current == nullptr)
        {
            cout << "No song selected.\n";
            return;
        }

        cout << "\nNow Playing: "
             << current->songTitle
             << " - " << current->artistName << endl;
    }

    // Play Next Song
    void playNextSong()
    {
        if (current == nullptr)
        {
            cout << "Playlist is empty.\n";
            return;
        }

        if (current->next != nullptr)
        {
            current = current->next;
            cout << "Moved to next song.\n";
            playCurrentSong();
        }
        else
        {
            cout << "Already at the last song.\n";
        }
    }

    // Play Previous Song
    void playPreviousSong()
    {
        if (current == nullptr)
        {
            cout << "Playlist is empty.\n";
            return;
        }

        if (current->prev != nullptr)
        {
            current = current->prev;
            cout << "Moved to previous song.\n";
            playCurrentSong();
        }
        else
        {
            cout << "Already at the first song.\n";
        }
    }

    // Play Complete Playlist
    void playCompletePlaylist()
    {
        if (head == nullptr)
        {
            cout << "Playlist is empty.\n";
            return;
        }

        cout << "\n--- Playing Complete Playlist ---\n";

        Node* q = head;

        while (q != nullptr)
        {
            cout << "Playing: " << q->songTitle
                 << " - " << q->artistName << endl;

            q = q->next;
        }
    }

    // Repeat All
    void repeatAll()
    {
        if (head == nullptr)
        {
            cout << "Playlist is empty.\n";
            return;
        }

        int repetitions;

        cout << "Enter number of repetitions: ";
        cin >> repetitions;

        if (repetitions <= 0)
        {
            cout << "Invalid number of repetitions.\n";
            return;
        }

        cout << "\n--- Repeat All ---\n";

        for (int i = 1; i <= repetitions; i++)
        {
            cout << "\nRepetition " << i << ":\n";

            Node* q = head;

            while (q != nullptr)
            {
                cout << "Playing: " << q->songTitle
                     << " - " << q->artistName << endl;

                q = q->next;
            }
        }
    }

    // Show Current Song
    void showCurrentSong()
    {
        if (current == nullptr)
        {
            cout << "No current song selected.\n";
            return;
        }

        cout << "\nCurrent Song:\n";
        cout << "Title : " << current->songTitle << endl;
        cout << "Artist: " << current->artistName << endl;
    }

    // Destructor
    ~MusicPlaylist()
    {
        Node* q = head;

        while (q != nullptr)
        {
            Node* temp = q;
            q = q->next;
            delete temp;
        }
    }
};

// Main Function
int main()
{
    MusicPlaylist playlist;

    int choice;
    string title, artist;

    do
    {
        cout << "\n====================================\n";
        cout << "       MUSIC PLAYLIST MANAGER\n";
        cout << "====================================\n";

        cout << "1. Add Song\n";
        cout << "2. Delete Song\n";
        cout << "3. Display Playlist\n";
        cout << "4. Display Playlist in Reverse\n";
        cout << "5. Play Current Song\n";
        cout << "6. Play Next Song\n";
        cout << "7. Play Previous Song\n";
        cout << "8. Play Complete Playlist\n";
        cout << "9. Repeat All\n";
        cout << "10. Show Current Song\n";
        cout << "11. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cin.ignore();

            cout << "Enter song title: ";
            getline(cin, title);

            cout << "Enter artist name: ";
            getline(cin, artist);

            playlist.addSong(title, artist);
            break;

        case 2:
            cin.ignore();

            cout << "Enter song title to delete: ";
            getline(cin, title);

            playlist.deleteSong(title);
            break;

        case 3:
            playlist.displayPlaylist();
            break;

        case 4:
            playlist.displayReverse();
            break;

        case 5:
            playlist.playCurrentSong();
            break;

        case 6:
            playlist.playNextSong();
            break;

        case 7:
            playlist.playPreviousSong();
            break;

        case 8:
            playlist.playCompletePlaylist();
            break;

        case 9:
            playlist.repeatAll();
            break;

        case 10:
            playlist.showCurrentSong();
            break;

        case 11:
            cout << "Exiting Music Playlist Manager...\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 11);

    return 0;
}
