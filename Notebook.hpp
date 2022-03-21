#include <string>
#include <iostream>
#include "Direction.hpp"
#include <vector>
#include <unordered_map>
#include <cstdlib>
using ariel::Direction;
using namespace std;

namespace ariel{
   
    class Notebook{
        unordered_map<int,vector<vector<char>>> notebook;
        public:
            Notebook();
            static void write(int page,int row,int column, Direction dir,const string &text);
            static string read(int page,int row,int column, Direction dir,int length);
            static void erase(int page,int row,int column, Direction dir,int length);
            static string show(int page);
    };

};