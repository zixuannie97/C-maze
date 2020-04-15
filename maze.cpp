#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <ctime>
#include <termios.h>

#define MAX_X 20
#define MAX_Y 30

bool flag = false; // hint if map is successfully touched
bool slow = false; // true means game as slow speed
bool autogame = true; // true means auto play game
int maze[MAX_X][MAX_Y];


using namespace std;

class stack_of_maze{

private:
    struct node
    {
        int x;
        int y;
        char direction; //last step's lujing
        node* next;
    };
    node* head;
public:
    stack_of_maze(){
        head = nullptr;//use c++11 new property
    }

    ~stack_of_maze(){
        node* p = head;
        while(head!=nullptr){
            head = head->next;
            delete p;
            p = head;
        }
    }

    void push(int xx, int yy, char ddirection){

        node* new_node = new node;

        if(new_node!=nullptr){
            new_node->x = xx;
            new_node->y = yy;
            new_node->direction = ddirection;
            new_node->next = nullptr;

            if(head == nullptr)
                head = new_node;
            else{
                new_node->next = head;
                head = new_node; // head insert method
            }
        }
            else
                cout<<"Memory allocation failed!"<<endl;
    }

    node* pop(int& xx, int& yy){ //use refer to pass data to ptr
        if(head!=nullptr){
            node* p = head;
            head = head ->next;
            xx = p->x;
            yy = p->y;

            delete p;
        }
            return head;
    }

    void print(){
        if(head!=nullptr){
            node* p = head;
            while(p!=nullptr){
                cout<<" "<<p -> x << " "<< p->y<<" "<<p->direction<<endl;
                p = p->next;
            }
        }
        else
            cout<<"stack is empty, print failed!"<<endl;
    }

};



