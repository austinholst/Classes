//VideoGames.h
#include <iostream>
#include "Media.h"

using namespace std;

class VideoGames: public Media {
 public:
  //contstructor for video games
  VideoGames(char* publisher, int year, int rating, char* title);
  //virtual functions so media can use them
  virtual char* getPublisher();
  virtual  int getRating();
  int getType();
  //deconstructor
  ~VideoGames();
 protected:
  char* publisher;
  int rating;
  int type;
};
