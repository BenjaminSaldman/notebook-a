#include <string>
#include <iostream>
#include "Direction.hpp"
#include <vector>
#include <cstdlib>
using ariel::Direction;
using namespace std;

  class Node{
        public:
            int page;
            vector<vector<char>> note;
            Node* next;
            Node(int num);
            
    };
namespace ariel{
   
    class Notebook{
        Node* notebook;
        public:
            Notebook();
            ~Notebook();
            static void write(int page,int row,int column, Direction dir,const string &text);
            static string read(int page,int row,int column, Direction dir,int length);
            static void erase(int page,int row,int column, Direction dir,int length);
            static string show(int page);
            void insert(int number);
             Node* get(int number);
    };

};