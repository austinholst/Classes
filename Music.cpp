//Music.cpp
#include <iostream>
#include "Music.h"

using namespace std;
//all the stuff that music needs and includes the stuff that media class has (title and year)
Music::Music(char* newTitle, char* newArtist, int newYear, int newDuration, char* newPublisher):Media(newTitle, newYear) {
  title = newTitle;
  artist = newArtist;
  year = newYear;
  duration = newDuration;
  publisher = newPublisher;
  type = 1;
}

//deconstructor deletes char* ints take care of themselves
Music::~Music() {
  delete title;
  delete artist;
  delete publisher;
}
//gets artist
char* Music::getArtist() {
  return artist;
}
//gets duration
int Music::getDuration() {
  return duration;
}
//gets publisher
char* Music::getPublisher() {
  return publisher;
}
