//====================================
//Include Guard
#ifndef _orgutils_
#define _orgutils_
//====================================
//Dependencies
#include <iostream>
#include <vector>
#include <string>
//====================================
//Code

//====================================
//Structs:

struct timecoord {
    int head = 0;
    int mv = 0;
    int xtemp[4] = {0,0,0,0};
};

struct board { //6D board with timecoord.
    player origin;
    timecoord tc;
    std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<cell>>>>>> vals;
};

struct entang { //Entanglement
    cell x;
    cell y;
};

struct cell {
    std::vector<std::string> state;
    entang ent;
};

struct mv {
    size_t coords = 0;
    std::vector<std::vector<board>> timeline;
};

struct player {
    std::string mark = "";
};
//====================================
//Functions:

void merge_cell(cell c1, cell c2) { //Merge two cells, return in cell 2.
    c2.state.insert(c1.state.end(), c1.state.begin(), c1.state.end());

    return;
};

void add_uv(mv mv, board cpy, player p) { //Add new universe, copy off of cpy.
    mv.coords++; //Add new timeline.
    std::vector<board> new_tl;
    new_tl.push_back(cpy); //Add copy board.
    new_tl.at(0).origin.mark.assign(p.mark); //Reassign origin player.
    new_tl.at(0).tc.mv = mv.coords; //Alter board to contain mv coords.
    mv.timeline.push_back(new_tl); //Add copy board to timeline.

    return;
};

void rm_uv(mv mv, int pos) { //Remove a universe.
    mv.coords--; //Remove timeline.
    mv.timeline.erase(std::next(mv.timeline.begin(), pos)); //Remove timeline from mv.timeline.

    return;
};
//====================================
//Endif
#endif