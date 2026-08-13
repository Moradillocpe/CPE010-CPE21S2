#include "doubly_ll.h"

int main() {
    Song* playlist = nullptr;

    //create a playlist using multiple songs
    addSong("Song A", &playlist);
    addSong("Song B", &playlist);
    addSong("Song C", &playlist);
    addSong("Song D", &playlist);

    std::cout << "Full playlist:" << std::endl;
    playAll(playlist);

    //add a song to the playlist
    std::cout << "\nAdding 'Song E':" << std::endl;
    addSong("Song E", &playlist);
    playAll(playlist);

    //remove a song from the playlist
    std::cout << "\nRemoving 'Song C'" << std::endl;
    removeSong("Song C", &playlist);
    playAll(playlist);

    //demonstrate next and previous from the current song
    Song* current = playlist;
    std::cout << "\nCurrent: " << current->title << std::endl;

    current = nextSong(current);
    std::cout << "Next: " << current->title << std::endl;

    current = nextSong(current);
    std::cout << "Next: " << current->title << std::endl;

    current = prevSong(current);
    std::cout << "Previous: " << current->title << std::endl;

    //delete the whole playlist
    std::cout << "Deleting playlist" << std::endl;
    deletePlaylist(&playlist);
    playAll(playlist);

    return 0;
}