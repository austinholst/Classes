//Header guard
#ifndef HEADERGUARD
#define HEADERGUARD

#include <iostream>

using namespace std;

class Media {
 public:
  //constructor for media
  Media(char* title, int year);
  char* getTitle();
  int getYear();
  int getType();
  //All virtual functions from children
  virtual char* getPublisher();
  virtual int getRating();
  virtual char* getArtist();
  virtual int getDuration();
  virtual char* getDirector();
 protected:
  char* title;
  int year;
  int type;
};

#endif
