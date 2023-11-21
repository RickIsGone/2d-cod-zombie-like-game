#include <fstream>
#include "../hpp files/functions.hpp"
#include "../hpp files/classes.hpp"
#include "../hpp files/g_variables.hpp"

void game::save::saveTopRound() {
    std::ifstream in("../data/saves.txt");
    int TopRound = 1;
    if (in.is_open()) {
        in >> TopRound;
        in.close();
    }

    if (game_round.round_number > TopRound) TopRound = game_round.round_number;
    
    std::ofstream out("../data/saves.txt");
    if (out.is_open()) {
        out << TopRound;
        out.close();
    }
}

int game::save::loadTopRound() {
    std::ifstream in("../data/saves.txt");
    int TopRound = 1;
    if (in.is_open()) {
        in >> TopRound;
        in.close();
    }
    return TopRound;
}
