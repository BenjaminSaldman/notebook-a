#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <cstdlib>
#include "doctest.h"
#include "Notebook.hpp"
#include "Direction.hpp"
using ariel::Direction;
using namespace std;
using namespace ariel;
const int MAX=10;
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}
TEST_CASE("GOOD IN/OUT"){
    Notebook note1;
    for(int i=0;i<MAX;i++)
    {
        for(int j=0;j<MAX;j++)
        {
            CHECK_NOTHROW(note1.write(0,i,j,Direction::Horizontal,"a"));
        }
    }
    Notebook note2;
    for(int i=0;i<MAX;i++)
    {
        for(int j=0;j<MAX;j+=5)
        {
            CHECK_NOTHROW(note1.write(0,i,j,Direction::Horizontal,"abcde"));
        }
    }
    Notebook note3;
      for(int i=0;i<MAX;i++)
    {
        for(int j=0;j<MAX;j++)
        {
            CHECK_NOTHROW(note3.write(0,i,j,Direction::Vertical,"a"));
        }
    }
    Notebook note4;
     for(int i=0;i<MAX;i+=5)
    {
        for(int j=0;j<MAX;j++)
        {
            CHECK_NOTHROW(note4.write(0,i,j,Direction::Vertical,"abcde"));
        }
    }
    string s=nospaces("a");
      for(int i=0;i<MAX;i++)
    {
        for(int j=0;j<MAX;j++)
        {
            string s2=nospaces(note1.read(0,i,j,Direction::Horizontal,1));
            CHECK(s2==s);
        }
    }
    s=nospaces("abcde");
      for(int i=0;i<MAX;i++)
    {
        for(int j=0;j<MAX;j++)
        {
            string s2=nospaces(note2.read(0,i,j,Direction::Horizontal,5));
            CHECK(s2==s);
        }
    }
    s=nospaces("a");
    for(int i=0;i<MAX;i++)
    {
        for(int j=0;j<MAX;j++)
        {
            string s2=nospaces(note3.read(0,i,j,Direction::Vertical,1));
            CHECK(s2==s);
        }
    }
    s=nospaces("a\n"
               "b\n"
               "c\n"
               "d\n"
               "e");
     for(int i=0;i<MAX;i+=5)
    {
        for(int j=0;j<MAX;j++)
        {
            string s2=nospaces(note4.read(0,i,j,Direction::Vertical,5));
            CHECK(s2==s);
        }
    }
    s=nospaces("~");
     for(int i=0;i<MAX;i++)
    {
        for(int j=0;j<MAX;j++)
        {
            note3.erase(0,i,j,Direction::Vertical,1);
        }
    }
    for(int i=0;i<MAX;i++)
    {
        for(int j=0;j<MAX;j++)
        {
            string s2=nospaces(note3.read(0,i,j,Direction::Vertical,1));
            CHECK(s2==s);
        }
    }
    

}
TEST_CASE("Invalid input"){
    Notebook n1;
    for(int i=-1;i>=-101;i--)
    {
        for(int j=0;j<MAX;j++)
        {
            for(int k=0;k<MAX;k++)
            {
                CHECK_THROWS(n1.write(i,j,k,Direction::Horizontal,"a"));
            }
        }
    }
    for(int j=0;j<MAX;j++)
        {
            for(int k=0;k<MAX;k++)
            {
                n1.write(0,j,k,Direction::Horizontal,"a");
            }
        }
      for(int j=0;j<MAX;j++)
        {
            for(int k=0;k<MAX;k++)
            {
                CHECK_THROWS(n1.write(0,j,k,Direction::Horizontal,"a"));
            }
        }
         for(int j=0;j<MAX;j++)
        {
            for(int k=0;k<MAX;k++)
            {
                n1.erase(0,j,k,Direction::Horizontal,1);
            }
        }
         for(int j=0;j<MAX;j++)
        {
            for(int k=0;k<MAX;k++)
            {
                CHECK_THROWS(n1.write(0,j,k,Direction::Horizontal,"a"));
            }
        }
         for(int j=0;j<MAX;j++)
        {
            for(int k=0;k<MAX;k++)
            {
                CHECK_THROWS(n1.read(0,j,k,Direction::Horizontal,-(j+1)));
            }
        }
         for(int j=0;j<MAX;j++)
        {
            for(int k=0;k<MAX;k++)
            {
                CHECK_THROWS(n1.read(0,j,k,Direction::Vertical,-(j+1)));
            }
        }
    
}