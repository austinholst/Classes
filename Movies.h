//Movies.h
#include <iostream>
#include "Media.h"

using namespace std;

class Movies: public Media {
 public:
  //Movies contructor
  Movies(char* title, char* director, int year, int duration, int rating);
  //virtual functions so media can use them
  virtual char* getDirector();
  virtual int getDuration();
  virtual int getRating();
  //movie descructor
  ~Movies();
 private:
  char* director;
  int duration;
  int rating;
};
