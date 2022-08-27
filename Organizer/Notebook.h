#pragma once
#include "Note.h"
#include <vector>

class Notebook
{
public:
	vector<Note> list;

    Notebook(){}
    ~Notebook() {}


    void add_note();
    void remove_note();
    void find_note();
    void print_all();
    void readF(string file);
    void writeF(string file);
    int find_place(string topic);
    Note CreateNote(string topic, string note);
    void edit_note();
};

