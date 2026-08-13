#ifndef DOUBLY_LL_H
#define DOUBLY_LL_H

#include <iostream>

// a song holds its title and links to the song before and after it
class Song {
public:
    std::string title;
    Song *next;
    Song *prev;
};

// adds a new song to the end of the playlist
void addSong(std::string title, Song **playlist) {
    Song *newNode = new Song;
    newNode->title = title;

    if (*playlist == nullptr) {
        // playlist was empty, so this new song becomes the only song
        newNode->next = newNode; // points to itself since it is circular
        newNode->prev = newNode;
        *playlist = newNode;
    } else {
        Song *head = *playlist;
        Song *tail = head->prev;

        // link the new song in between the tail and the head
        newNode->prev = tail;
        newNode->next = head;
        tail->next = newNode;
        head->prev = newNode;
    }
}

// removes a song from the playlist by title
void removeSong(std::string title, Song **playlist) {
    if (*playlist == nullptr) return;

    Song *temp = *playlist;
    do {
        if (temp->title == title) {
            if (temp->next == temp) {
                // only one song was in the list
                *playlist = nullptr;
            } else {
                // skip over the node being removed
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                if (*playlist == temp) *playlist = temp->next;
            }
            delete temp; // free the memory
            return;
        }
        temp = temp->next;
    } while (temp != *playlist);
}

// prints every song in the playlist separated by a dash
void playAll(Song *playlist) {
    if (playlist == nullptr) {
        std::cout << "Playlist is empty" << std::endl;
        return;
    }
    Song *temp = playlist;
    do {
        std::cout << temp->title;
        if (temp->next != playlist) std::cout << " - ";
        temp = temp->next;
    } while (temp != playlist);
    std::cout << std::endl;
}

// moves to the next song
Song* nextSong(Song *current) {
    return current->next;
}

// moves to the previous song
Song* prevSong(Song *current) {
    return current->prev;
}

// deletes every song in the playlist and frees the memory
void deletePlaylist(Song **playlist) {
    if (*playlist == nullptr) return;

    Song *current = *playlist;
    Song *temp;
    do {
        temp = current;
        current = current->next;
        delete temp;
    } while (current != *playlist);

    *playlist = nullptr;
}

#endif