//Music.h
#include <iostream>
#include "Media.h"

using namespace std;

class Music: public Media {
 public:
  //constructor for music
  Music(char* title, char* artist, int year, int duration, char* publisher);
  //virtual functions so media can use them
  virtual char* getArtist();
  virtual char* getPublisher();
  virtual int getDuration();
  //deconstructor
  ~Music();
 protected:
  char* artist;
  char* publisher;
  int duration;
};
