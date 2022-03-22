#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <unordered_map>
#include "Notebook.hpp"
#include "Direction.hpp"
using ariel::Direction;
using namespace std;
const int MAX=100;
const int FIRST=0;
const char ASSIGN='_';

namespace ariel{

    Notebook::Notebook()
    {
        this->notebook[0].assign(MAX,vector<char>(MAX,ASSIGN));
    }
    void Notebook::write(int page,int row,int column, Direction dir,const string &text){
      
    }
     string Notebook::read(int page,int row,int column, Direction dir,int length){
        return " ";
    }
    void Notebook::erase(int page,int row,int column, Direction dir,int length){
       
    }
    void Notebook::show(int page){
        
    }

};