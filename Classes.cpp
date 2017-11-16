#include <iostream>
#include "Media.h"
#include <cstring>
#include <vector>
#include <string.h>
#include "VideoGames.h"
#include "Music.h"
#include "Movies.h"

using namespace std;

/*
 *Name: Austin Holst
 *Date: 11 - 16 - 17
 *Code: Database for Music, Movies, and Video Games. Using multiple classes and parent class
 */



vector<Media*> vect;
//initializing methods so C++ knows they are there
void add(vector<Media*> &vect);
void search(vector<Media*> &vect);
void erase(vector<Media*> &vect);

int main() {
  
  char input[10];
  bool running = true;
  //While the program is running
  while(running == true) {
    cout << "Do you want to add search delete or quit" << endl;
    cin.getline(input, 10);
    for(int i = 0; i < 10; i++) {
      input[i]  = tolower(input[i]);
    }
    if(strcmp(input, "add") == 0) {
      add(vect);
    }
    else if(strcmp(input, "search") == 0) {
      search(vect);
    }
    else if(strcmp(input, "delete") == 0) {
      erase(vect);
    }
    else if(strcmp(input, "quit") == 0) {
      cout << "quiting program" << endl;
      running = false;
    }
    else {
      cout << "You can only use these commands: add search delete quit" << endl;
    }
  }
  return 0;
}

//Function for adding media
void add(vector<Media*> &vect) {
  char mediaType[20];
  cout << "What type of media do you want to add?" << endl;
  cin.getline(mediaType, 20);
  //changes input to lowercase
  for(int i = 0; i < 20; i++) {
    mediaType[i] = tolower(mediaType[i]);
  }
  //if they are adding a video game
  if(strcmp(mediaType, "video game") == 0) {
    char*  title = new char[100];
    int year;
    char* publisher = new char[100];
    int rating;; 

    cout << "What is the title of the game?" << endl;
    cin.getline(title, 100);
    cout << "What year did the game come out?" << endl;
    cin >> year;
    cin.ignore();
    cout << "Who published the game?" << endl;
    cin.getline(publisher, 100);
    cout << "On a scale of 1-10, what would you rate the game?" << endl;
    cin >> rating;
    cin.ignore();
    //create a new video game with all of the information gathered
    VideoGames* videoGamesPointer = new VideoGames(publisher, year, rating, title);
    //Push that video game into the vector
    vect.push_back(videoGamesPointer);
  }
  //if they are adding a movie
  else if(strcmp(mediaType, "movie") == 0) {
    char* title = new char[100];
    int year;
    char* director = new char[100];
    int rating;
    int duration;
    
    cout << "What is the name of the movie?" << endl;
    cin.getline(title, 100);
    cout << "What year did the movie come out?" << endl;
    cin >> year;
    cin.ignore();
    cout << "Who directed the movie?" << endl;
    cin.getline(director, 100);
    cout << "How long was the movie in minutes?" << endl;
    cin >> duration;
    cin.ignore();
    cout << "On a scale of 1-10, what would you rate the movie?" << endl;
    cin >> rating;
    cin.ignore();
    //create a new movie with all of the information gathered
    Movies* moviePointer = new Movies(title, director, year, duration, rating);
    //push the movie into the vector
    vect.push_back(moviePointer);
  }
  //if they are adding a music
  else if(strcmp(mediaType, "music") == 0) {
    char* title = new char[100];
    int year;
    char* publisher = new char[100];
    char* artist = new char[100];
    int duration;
    
    cout << "What is the title of the song?" << endl;
    cin.getline(title, 100);
    cout << "Who was the song by?" << endl;
    cin.getline(artist, 100);
    cout << "Who published the song?" << endl;
    cin.getline(publisher, 100);
    cout << "How long is the song in minutes?" << endl;
    cin >> duration;
    cin.ignore();
    cout << "What year was the song released?" << endl;
    cin >> year;
    cin.ignore();
    //creates a new music with all the information gathered
    Music* musicPointer = new Music(title, artist, year, duration, publisher);
    //pushes that music into the vector
    vect.push_back(musicPointer);
  }
  else {
    cout << "You can't add that type of media" << endl;
  }
}
//Method for searching for media
void search(vector<Media*> &vect) {
  //checks if there is anything in the vector at all
  if(vect.size() == 0) {
    cout << "there is nothing to search for" << endl;
  }
  else {
    cout << "Would you like to search by Title or Year" << endl;
    char answer[10];
    cin.getline(answer, 10);
    //turns their input into lowercase so its not case sensitive
    for(int i = 0; i < 10; i++) {
      answer[i] = tolower(answer[i]);
    }
    //if they are searching by title
    if(strcmp(answer, "title") == 0) {
      cout << "What is the title of the media" << endl;
      bool find = false;
      char temp[100];
      cin.getline(temp, 100);
      //goes through the vector of media
      for(vector<Media*>::iterator it = vect.begin(); it != vect.end(); it++) {
	//if the input title is the same as the iterators title
	if(strcmp(temp, (*it)-> getTitle()) == 0) {
	  //if it is a video game
	  if((*it)-> getType() == 0) {
	    find = true;
	    cout << "Title: " << (*it)-> getTitle() << endl;
	    cout << "Year Released: " << (*it)-> getYear() << endl;
	    cout << "Publisher: " << (*it)-> getPublisher() << endl;
	    cout << "Rating out of 10: " << (*it)-> getRating() << endl;
	  }
	  //if it is music
	  else if((*it)-> getType() == 1) {
	    find = true;
	    cout << "Title: " << (*it)-> getTitle() << endl;
	    cout << "Artist: " << (*it)-> getArtist() << endl;
	    cout << "Year released: " << (*it)-> getYear() << endl;
	    cout << "Time in minutes: " << (*it)-> getDuration() << endl;
	    cout << "Publisher: " << (*it)-> getPublisher() << endl;
	  }
	  //if it is a movie
	  else {
	    find = true;
	    cout << "Director: " << (*it)-> getDirector() << endl;
	    cout << "Year released: " << (*it)-> getYear() << endl;
	    cout << "Time in minutes: " << (*it)-> getDuration() << endl;
	    cout << "Rating out of 10: " << (*it)-> getRating() << endl;
	  }
	}
      }
      //if it couldnt find that title
      if(find == false) {
	cout << "Could not find that media" << endl;
      }
    }
    //everything is the same here except it uses year instead of title
    else if(strcmp(answer, "year") == 0) {
      cout << "What is the year of the media" << endl;
      bool find = false;
      int number = 0;
      cin >> number;
      cin.ignore(10, '\n');
      for(vector<Media*>::iterator it = vect.begin(); it != vect.end(); it++) {
	if(number == (*it)-> getYear()) {
	  if((*it)-> getType() == 0) {
	    find = true;
	    cout << "Title: " << (*it)-> getTitle() << endl;
	    cout << "Year Released: " << (*it)-> getYear() << endl;
	    cout << "Publisher: " << (*it)-> getPublisher() << endl;
	    cout << "Rating out of 10: " << (*it)-> getRating() << endl;
	  }
	  else if((*it)-> getType() == 1) {
	    find = true;
	    cout << "Title: " << (*it)-> getTitle() << endl;
	    cout << "Artist: " << (*it)-> getArtist() << endl;
	    cout << "Year released: " << (*it)-> getYear() << endl;
	    cout << "Time in minutes: " << (*it)-> getDuration() << endl;
	    cout << "Publisher: " << (*it)-> getPublisher() << endl;
	  }
	  else {
	    find = true;
	    cout << "Title: " << (*it)-> getTitle() << endl;
	    cout << "Director: " << (*it)-> getDirector() << endl;
	    cout << "Year released: " << (*it)-> getYear() << endl;
	    cout << "Time in minutes: " << (*it)-> getDuration() << endl;
	    cout << "Rating out of 10: " << (*it)-> getRating() << endl;
	  }
	}
      }
      if(find == false) {
	cout << "Could not find that media" << endl;
      }
    }
    else {
      cout << "You have to search by title or by year" << endl;
    }
  }
}
//Method for deleting media out of the vector and all components
void erase(vector<Media*> &vect) {
  //Checks to see if there is anything in the vector at all
  if(vect.size() == 0) {
    cout << "There is nothing to delte" << endl;
  }
  //if there is
  else {
    cout << "Would you like to delete by title or year" << endl;
    char answer[10];
    cin.getline(answer, 100);
    for(int i = 0; i < 10; i++) {
      answer[i] = tolower(answer[i]);
    }
    //delete by title
    if(strcmp(answer, "title") == 0) {
      cout << "What is the title of the media" << endl;
      bool find = false;
      char temp[100];
      cin.getline(temp, 100);
      for(vector<Media*>::iterator it = vect.begin(); it != vect.end(); it++) {
	if(strcmp(temp, (*it)-> getTitle()) == 0) {
	  if((*it)-> getType() == 0) {
	    find = true;
	    //deletes the components inside of that video game
	    delete static_cast<VideoGames*>(*it);
	    //erases it out of the vector
	    vect.erase(it);
	    cout << "That media has been terminated" << endl;
	    //breaks out of the loop
	    break;
	  }
	  //same as video game except for music
	  else if((*it)-> getType() == 1) {
	    find = true;
	    delete static_cast<Music*>(*it);
	    vect.erase(it);
	    cout << "That media has been terminated" << endl;
	    break;
	  }
	  //same as video game except for movies
	  else {
	    find = true;
	    delete static_cast<Movies*>(*it);
	    vect.erase(it);
	    cout << "That media has been terminated" << endl;
	    break;
	  }
	}
      }
      if(find == false) {
	cout << "Coudn't find that media to delete it" << endl;
      }
    }
    //same as deleting by title except it uses year
    else if(strcmp(answer, "year") == 0) {
      cout << "What is the year of the media" << endl;
      bool find = false;
      int  number = 0;
      cin >> number;
      cin.ignore(10, '\n');
      for(vector<Media*>::iterator it = vect.begin(); it != vect.end(); it++) {
	if((*it)-> getYear() == number) {
	  if((*it)-> getType() == 0) {
	    find = true;
	    delete static_cast<VideoGames*>(*it);
	    vect.erase(it);
	    cout << "That media has been terminated" << endl;
	    break;
	  }
	  else if((*it)-> getType() == 1) {
	    find = true;
	    delete static_cast<Music*>(*it);
	    vect.erase();
	    cout << "That media has been terminated" << endl;
	    break;
	  }
	  else {
	    find = true;
	    delete static_cast<Movies*>(*it);
	    vect.erase();
	    cout << "That media has been terminated" << endl;
	    break;
	  }
	}
      }
      if(find == false) {
	cout << "Coudn't find that media to delete it" << endl;
      }
    }
    else {
      cout << "You have to delete by title or year" << endl;
    }
  }
}

