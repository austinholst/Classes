//VideoGames.cpp
#include <iostream>
#include "VideoGames.h"

using namespace std;
//all the stuff video games needs and using the stuff from media that it has (title and year)
VideoGames::VideoGames(char* newPublisher, int newYear, int newRating, char* newTitle):Media(newTitle, newYear) {
  publisher = newPublisher;
  rating = newRating;
  title = newTitle;
  year = newYear;
  type = 0;
}
//deconstructor: deletes char*, ints take care of themselves
VideoGames::~VideoGames() {
  delete title;
  delete publisher;
}
//get publisher 
char* VideoGames::getPublisher() {
  return publisher;
}
//get the rating
int VideoGames::getRating() {
  return rating;
}
//gets the type
int VideoGames::getType() {
  return type;
}
