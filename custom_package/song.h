#ifndef __SONG_H__
#define __SONG_H__

#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include "priority_queue.h"

using namespace std;

class Song {
  public:
    std::string artist,title;
    int count;

    Song() { }
    Song(const Song &s) : artist(s.artist), title(s.title), count(s.count) { }
    Song(std::string artist,std::string title,int count) :  artist(artist), title(title), count(count) { }

    friend std::ostream& operator<<(std::ostream &out,const Song &s) {
      return out << "Artist: " << s.artist << " Title: " << s.title << " count: " << s.count;
    }

};


//  you have to write something below this line 
//  you *MIGHT* have to change the declaration of pq1 and pq2

//way 1

class Comp1{
  public:
    bool operator()(const Song& s1,const Song& s2) const {
      if(s1.artist > s2.artist) return true;
      if(s1.artist == s2.artist && s1.title > s2.title) return true; 
      if(s1.artist == s2.artist && s1.title == s2.title && s1.count > s2.count) return true;
      return false; 
    }
};

class Comp2{
  public:
    bool operator()(const Song &s1,const Song &s2) const {
      if(s1.count < s2.count) return true;
      if(s1.count == s2.count && s1.artist > s2.artist) return true; 
      if(s1.count == s2.count && s1.artist == s2.artist && s1.title > s2.title) return true;
      return false; 
    }
};


std::priority_queue<Song, std::vector<Song>, Comp1> pq1;
std::priority_queue<Song, std::vector<Song>, Comp2> pq2;



#endif
