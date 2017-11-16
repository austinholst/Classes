//Movies.cpp
#include <iostream>
#include "Movies.h"

using namespace std;
//All the stuff that movies needs including the stuff that media class has (title and year)
Movies::Movies(char* newTitle, char* newDirector, int newYear, int newDuration, int newRating):Media(newTitle, newYear) {
  title = newTitle;
  director = newDirector;
  year = newYear;
  duration = newDuration;
  rating = newRating;
  type = 2;
}
//Movies desturctor
Movies::~Movies() {
  delete title;
  delete director;
}
//gets director
char* Movies::getDirector() {
  return director;
}
//gets duration
int Movies::getDuration() {
  return duration;
}
//gets rating
int Movies::getRating() {
  return rating;
}


