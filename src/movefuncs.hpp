//====================================
//Include Guard
#ifndef _movefuncs_
#define _movefuncs_
//====================================
//Dependencies
#include <iostream>
#include <vector>
#include <string>
#include "orgutils.hpp"
//====================================
//Code

void mark(cell cell, player p) { //Player p marks cell cell.
    if (cell.state.size() == 1 && cell.state.at(0) == "") {
        cell.state.at(0).assign(p.mark);
    }
    return;
};

void b_merge(board b1, board b2, mv mv) { //Merge boards b1 and b2, delete b2.
    if(b1.vals.size() != b2.vals.size()) {
        return; //HANDLE ERROR
    } else {
        for(size_t i = 0; i < b1.vals.size(); ++i) {
            for(size_t j = 0; j < b1.vals[i].size(); ++j) {
                for(size_t k = 0; k < b1.vals[i][j].size(); ++k) {
                    for(size_t l = 0; l < b1.vals[i][j][k].size(); ++l) {
                        for(size_t m = 0; m < b1.vals[i][j][k][l].size(); ++m) {
                            for(size_t n = 0; n < b1.vals[i][j][k][l][m].size(); ++n) {
                                merge_cell(b1.vals[i][j][k][l][m][n], b2.vals[i][j][k][l][m][n]);
                            }
                        }
                    }
                }
            }
        }
    }

    b2.vals.clear();
    
    return;
};

void t_merge(size_t tl1, size_t tl2, mv mv) { //Merge timelines tl1 and tl2, delete tl2.
    if(mv.timeline.at(tl1).size() != mv.timeline.at(tl2).size()) {
        return; //HANDLE ERROR
    } else {
        for(int i = 0; i < mv.timeline.at(tl1).size(); i++) {
            b_merge(mv.timeline.at(tl1).at(i), mv.timeline.at(tl2).at(i), mv);
        }
    }

    rm_uv(mv, tl2);
};
//====================================
//Endif
#endif