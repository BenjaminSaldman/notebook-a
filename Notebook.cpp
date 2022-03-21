#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>
#include "Notebook.hpp"
#include "Direction.hpp"
using ariel::Direction;
using namespace std;
const int MAX=100;
const int FIRST=0;
const char ASSIGN='_';
 Node::Node(int num)
    {
        this->page=num;
        this->note.assign(MAX,vector<char>(MAX,ASSIGN));
        this->next=NULL;
    }
namespace ariel{

    Notebook::Notebook()
    {
        this->notebook=new Node(FIRST);
    }
    Notebook::~Notebook()
    {
        Node* temp=notebook;
            while(temp!=NULL){
                notebook=notebook->next;
                delete temp;
                temp=notebook;
            }
    }
    void Notebook::insert(int number){
        Node* temp=new Node(number);
        if(notebook==NULL)
        {
            notebook=temp;
            return;
        }
        Node* tempN=notebook;
        while(tempN->next!=NULL)
        {
            tempN=tempN->next;
        }
        tempN->next=temp;

    }
    Node* Notebook::get(int number){
        Node* tempN=notebook;
        while(tempN!=NULL)
        {
            if(tempN->page==number){
                break;
            }
            tempN=tempN->next;
        }
        return tempN;
    }
    void Notebook::write(int page,int row,int column, Direction dir,const string &text){
      
    }
     string Notebook::read(int page,int row,int column, Direction dir,int length){
        return " ";
    }
    void Notebook::erase(int page,int row,int column, Direction dir,int length){
       
    }
    string Notebook::show(int page){
        return " ";
    }

};