#include <iostream>
#include <string>
#include <ctime>
#define GREEN "\033[0;32m"
#define BLUE "\033[0;34m"
#define RED "\033[0;31m"
#define RESET "\033[0m"
using namespace std;
template <typename T>
class node
{
public:
    T data;
    node<T>* next;
    node(T data) : data(data), next(nullptr) {}
};
template <typename T>
class linkedList
{
public:
    node<T>* head;
    node<T>* current;
    node<T>* prev;
    linkedList() : head(nullptr), current(nullptr), prev(nullptr) {}
    ~linkedList()
    {
        if (head != nullptr)
        {
            node<T>* temp = head;
            node<T>* nextNode;
            do
            {
                nextNode = temp->next;
                delete temp;
                temp = nextNode;
            }
            while (temp != head);
        }
    }
    void add(T data) 
    {
        node<T>* newNode = new node<T>(data);
        if (head == nullptr) 
        {
            head = newNode;
            newNode->next = head;
        } 
        else 
        {
            node<T>* temp = head;
            while (temp->next != head) 
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }
    node<T>* findPlaylist(string& name)
    {
        if (head == nullptr) 
        {
            return nullptr;
        }
        node<T>* temp = head;
        do
        {
            if (temp->data.playlistName == name)
            {
                return temp;
            }
            temp = temp->next;
        }
        while (temp != head);
        return nullptr;
    }
    void remove(T& data)
    {
        if (head == nullptr)
        {
            return;
        }
        if (head->data == data)
        {
            if (head->next == head)
            {
                delete head;
                head = nullptr;
            }
            else
            {
                node<T>* lastNode = head;
                while (lastNode->next != head)
                {
                    lastNode = lastNode->next;
                }
                node<T>* remove = head;
                head = head->next;
                lastNode->next = head;
                delete remove;
            }
            return;
        }
        node<T>* temp = head->next;
        while (temp != head)
        {
            if (temp->data == data)
            {
                prev->next = temp->next;
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
    }
    bool find(string& name)
    {
        if (head == nullptr)
        {
            return false;
        }
        node<T>* temp = head;
        do 
        {
            if (temp->data == name) 
            {
                current = temp; 
                return true;
            }
            temp = temp->next;
        }
        while (temp != head);
        return false;
    }
    void randomMusic()
    {
        if (head == nullptr)
        {
            return;
        }
        int count = 1;
        current = head->next;
        while (current != head)
        {
            count++;
            current = current->next;
        }
        srand((time(0)));
        int randomIndex = rand() % count;
        current = head;
        for (int i = 0 ; i < randomIndex ; i++)
        {
            current = current->next;
        }
        cout << BLUE << "Music: " << RESET << RED << current->data << RESET << BLUE << " Is Playing." << endl << RESET;
    }
    void nextMusic(bool loop) 
    {
        if (current == nullptr) 
        {
            cout << BLUE << "No Music Is Playing." << endl << RESET;
            return;
        }
        current = current->next;
        if (current == head) 
        {
            if (loop == true)
            {
                cout << BLUE << "Music: " << RESET << RED << current->data << RESET << BLUE << " Is Playing." << endl << RESET;
            } 
            else 
            {
                cout << BLUE << "Playlist Is Over." << endl << RESET;
                current = nullptr;
            }
        } 
        else 
        {
            cout << BLUE << "Music: " << RESET << RED << current->data << RESET << BLUE << " Is Playing." << endl << RESET;
        }
    }
    void prevMusic() 
    {
        if (current == nullptr) 
        {
            cout << BLUE << "No Music Is Playing." << endl << RESET;
            return;
        }
        node<T>* temp = head;
        while (temp->next != current)
        {
            temp = temp->next;
        }
        current = temp;
        cout << BLUE << "Music: " << RESET << RED << current->data << RESET << BLUE << " Is Playing." << endl << RESET;
    }
    void showPlaylist() 
    {
        if (head == nullptr)
        {
            cout << BLUE << "The Playlist Is Empty." << endl << RESET;
            return;
        }
        node<T>* temp = head;
        cout << BLUE << "Musics:" << endl << RESET;
        do 
        {
            cout << RED << temp->data << endl << RESET;
            temp = temp->next;
        } 
        while (temp != head);
        cout << endl;
    }
    void addPlaylist(string& playlistName)
    {
        node<T>* newNode = new node<T>(playlistName);
        if (head == nullptr) 
        {
            head = newNode;
            head->next = head;
        } 
        else 
        {
            node<T>* temp = head;
            while (temp->next != head) 
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
        cout << BLUE << "Playlist Added: " << RESET << RED << playlistName << RESET << BLUE << "." << endl << RESET;
    }
};
class playlist 
{
public:
    string playlistName;
    linkedList<string> musics;
    playlist(string name) : playlistName(name) {}
};
void addMusicToPlaylist(linkedList<playlist>& playlists, string& playlistName, string& musicData)
{
    node<playlist>* playlistNode = playlists.findPlaylist(playlistName);
    if (playlistNode != nullptr) 
    {
        playlistNode->data.musics.add(musicData);
        cout << BLUE << "Music " << RESET << RED << musicData << RESET << BLUE << " Added To Playlist " << RESET << RED << playlistName << RESET << BLUE << "." << endl << RESET;
    } 
    else 
    {
        cout << BLUE << "Playlist Not Found." << endl << RESET;
    }
}
void removeMusicFromPlaylist(linkedList<playlist>& playlists, string& playlistName, string& musicData)
{
    node<playlist>* playlistNode = playlists.findPlaylist(playlistName);
    if (playlistNode != nullptr) 
    {
        playlistNode->data.musics.remove(musicData);
        cout << BLUE << "Music " << RESET << RED << musicData << RESET << BLUE << " Removed From Playlist " << RESET << RED << playlistName << RESET << BLUE << "." << endl << RESET;
    } 
    else 
    {
        cout << BLUE << "Playlist Not Found." << endl << RESET;
    }
}
void findMusic(linkedList<playlist>& playlists, string& playlistName, string& musicData)
{
    node<playlist>* playlistNode = playlists.findPlaylist(playlistName);
    if (playlistNode != nullptr)
    {
        if (playlistNode->data.musics.find(musicData)) 
        {
            cout << BLUE << "Music: " << RESET << RED << musicData << RESET << BLUE << " Is Playing." << endl << RESET;
        } 
        else
        {
            cout << BLUE << "Music: " << RESET << RED << musicData << RESET << BLUE " Not Found In Playlist." << endl << RESET;
        }
    } 
    else 
    {
        cout << BLUE << "Playlist Not Found." << endl << RESET;
    }
}
void shuffleMode(linkedList<playlist>& playlists, string& playlistName)
{
    node<playlist>* playlistNode = playlists.findPlaylist(playlistName);
    if (playlistNode != nullptr) 
    {
        playlistNode->data.musics.randomMusic();
    }
    else
    {
        cout << BLUE << "Playlist Not Found." << endl << RESET;
    }
}
void playNextMusic(linkedList<playlist>& playlists, string& playlistName, bool loop)
{
    node<playlist>* playlistNode = playlists.findPlaylist(playlistName);
    if (playlistNode != nullptr) 
    {
        playlistNode->data.musics.nextMusic(loop);
    } 
    else 
    {
        cout << BLUE << "Playlist Not Found." << endl << RESET;
    }
}
void playPrevMusic(linkedList<playlist>& playlists, string& playlistName)
{
    node<playlist>* playlistNode = playlists.findPlaylist(playlistName);
    if (playlistNode != nullptr) 
    {
        playlistNode->data.musics.prevMusic();
    } 
    else
    {
        cout << BLUE << "Playlist Not Found." << endl << RESET;
    }
}
void showPlaylistMusics(linkedList<playlist>& playlists, string& playlistName)
{
    node<playlist>* playlistNode = playlists.findPlaylist(playlistName);
    if (playlistNode != nullptr) 
    {
        playlistNode->data.musics.showPlaylist();
    } 
    else
    {
        cout << BLUE << "Playlist Not Found." << endl << RESET;
    }
}
int main() 
{
    linkedList<playlist> playlists;
    string playlistName, musicData, choice3;
    int choice = 0;
    int choice2 = 0;
    bool loop = false;
    while (true) 
    {
        cout << GREEN << "1: Add New Playlist" << endl << "2: Show My Playlist" << endl << "3: Add Music" << endl << "4: Remove Music" << endl
        << "5: Play Music" << endl << "6: Play Music In Shuffle Mode" << endl << "7: Exit" << endl << "Choose:" << RESET;
        cin >> choice;
        switch (choice) 
        {
            case 1: 
            {
                cout << GREEN << "Enter Playlist Name:" << RESET;
                cin >> playlistName;
                playlists.addPlaylist(playlistName);
                break;
            }
            case 2: 
            {
                cout << GREEN << "Enter Playlist Name:" << RESET;
                cin >> playlistName;
                showPlaylistMusics(playlists, playlistName);
                break;
            }
            case 3: 
            {
                cout << GREEN << "Enter Playlist Name:" << RESET;
                cin >> playlistName;
                cout << GREEN << "Enter (Music Name - Music Singer):" RESET;
                cin >> musicData;
                addMusicToPlaylist(playlists, playlistName, musicData);
                break;
            }
            case 4:
            {
                cout << GREEN << "Enter Playlist Name:" << RESET;
                cin >> playlistName;
                cout << GREEN << "Enter (Music Name - Music Singer):" << RESET;
                cin >> musicData;
                removeMusicFromPlaylist(playlists, playlistName, musicData);
                break;
            }
            case 5:
            {
                cout << GREEN << "Enter Playlist Name:" << RESET;
                cin >> playlistName;
                cout << GREEN << "Enter (Music Name - Music Singer):" << RESET;
                cin >> musicData;
                findMusic(playlists, playlistName, musicData);
                while(true)
                {
                    cout << GREEN << "1: Next Music" << endl << "2: Previous Music" << endl << "3: Loop" << endl << "4: Back" << endl << "Choose:" << RESET;
                    cin >> choice2;
                    switch (choice2)
                    {
                        case 1:
                        {
                            playNextMusic(playlists, playlistName, loop);
                            break;
                        }
                        case 2:
                        {
                            playPrevMusic(playlists, playlistName);
                            break;
                        }
                        case 3:
                        {
                            cout << GREEN << "Do You Want To Turn On Loop? (yes / no):" << RESET;
                            cin >> choice3;
                            if (choice3 == "yes")
                            {
                                loop = true;
                            }
                            else if (choice3 == "no")
                            {
                                loop = false;
                            }
                            break;
                        }
                        case 4:
                        {
                            break;
                        }
                    }
                    break;
                }
                break;
            }
            case 6:
            {
                cout << GREEN << "Enter Playlist Name: " << RESET;
                cin >> playlistName;
                shuffleMode(playlists, playlistName);
                break;
            }
            case 7:
            {
                cout << RED << "Exit." << endl << RESET;
                return 0;
            }
            default:
                cout << RED << "Invalid Option." << endl << RESET;
        }
    }
}