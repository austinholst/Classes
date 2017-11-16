//Media.cpp
#include <iostream>
#include "Media.h"

using namespace std;
//Stuff all media hs
Media::Media(char* newTitle, int newYear) {
  title  = newTitle;
  year = newYear;
}
//gets the title
char* Media::getTitle() {
  return title;
}
//gets the year
int Media::getYear() {
  return year;
}
//gets the publisher null b/c its virtual
char* Media::getPublisher() {
  return NULL;
}
//gets the rating null b/c its virtual
int Media::getRating() {
  return NULL;
}
//get the type so you know what media the child is
int Media::getType() {
  return type;
}
//gets the artist null b/c its virtual
char* Media::getArtist() {
  return NULL;
}
//gets the duration null b/c its virtual
int Media::getDuration() {
  return NULL;
}
//gets the director null b/c its virtual
char* Media::getDirector() {
  return NULL;
}
