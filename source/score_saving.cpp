#include <fstream>
#include <vector>
#include "../hpp files/functions.hpp"
#include "../hpp files/classes.hpp"
#include "../hpp files/g_variables.hpp"

void game::save::saveTopRound() {
    std::ifstream in("../data/saves.txt");
    std::string line;
    std::vector<std::string> lines;
    while (std::getline(in, line)) lines.push_back(line);
    
    in.close();

    int TopRound = 1;
    if (!lines.empty())  TopRound = std::stoi(lines[0].substr(lines[0].find(":") + 1));

    if (game_round.round_number > TopRound) TopRound = game_round.round_number;

    lines[0] = "topround: " + std::to_string(TopRound);
    if (lines.size() > 1) lines[1] = "issaved:0";
    

    std::ofstream out("../data/saves.txt");
    for (const auto& line : lines) out << line << std::endl;
    
    out.close();
}

int game::save::loadTopRound() {
    std::ifstream in("../data/saves.txt");
    int TopRound;
    if (in.is_open()) {
        std::string line;
        std::getline(in, line);
        TopRound = std::stoi(line.substr(line.find(":") + 1));
        in.close();
    }
    return TopRound;
}


void game::save::saveGame(){

    std::ifstream fileIn("../data/saves.txt");
    std::string line;   
    std::getline(fileIn, line);  
    std::string topround = line;
    fileIn.close();

    std::ofstream file("../data/saves.txt");

    file << topround << std::endl;
    file << "issaved:1"<< std::endl << std::endl;
    file << "round:" << game_round.round_number << std::endl << std::endl;
    file << "health:" << player.health << std::endl << std::endl;
    file << "money:" << player.money << std::endl << std::endl;
    file << "hascutters:" << player.has_cutters << std::endl << std::endl;
    file << "primary:" << player.WeaponInHand.name << std::endl;
    file << "primary_ammo:" << player.WeaponInHand.ammo << std::endl;
    file << "primary_ammo_left:" << player.WeaponInHand.ammo_left << std::endl << std::endl;
    file << "secondary:" << player.WeaponInInventory.name << std::endl;
    file << "secondary_ammo:" << player.WeaponInInventory.ammo << std::endl;
    file << "secondary_ammo_left:" << player.WeaponInInventory.ammo_left << std::endl << std::endl;
    file << "x:" << player.x << std::endl;
    file << "y:" << player.y << std::endl << std::endl;
    file << "zombie alive:" << game_round.zombie_left << std::endl;

    file.close();
}

bool issaved;

bool game::save::loadGame(){

    std::ifstream file("../data/saves.txt");
    std::string line;   
    std::getline(file, line);  
    std::getline(file, line);  
    issaved = std::stoi(line.substr(line.find(":") + 1)) != 0;

   
    while (std::getline(file, line)&&issaved) {
        if (line.empty()) continue;
        std::string key = line.substr(0, line.find(":"));
        std::string value = line.substr(line.find(":") + 1);

        if (key == "round") game_round.round_number = std::stoi(value);
        else if (key == "health") player.health = std::stoi(value);
        else if (key == "money") player.money=std::stoi(value);
        else if (key == "hascutters") player.has_cutters=std::stoi(value);
        else if (key == "primary"){
            player.WeaponInHand.name=value;
            if(player.WeaponInHand.name=="ak47") player.WeaponInHand=ak47;
            else if(player.WeaponInHand.name=="mp5") player.WeaponInHand=mp5;
            else if(player.WeaponInHand.name=="glock18") player.WeaponInHand=glock18;
            else if(player.WeaponInHand.name=="knife") player.WeaponInHand=knife;
        }
        else if (key == "primary_ammo") player.WeaponInHand.ammo = std::stoi(value);
        else if (key == "primary_ammo_left") player.WeaponInHand.ammo_left = std::stoi(value);
        else if (key == "secondary"){
            player.WeaponInInventory.name=value;
            if(player.WeaponInInventory.name=="ak47") player.WeaponInInventory=ak47;
            else if(player.WeaponInInventory.name=="mp5") player.WeaponInInventory=mp5;
            else if(player.WeaponInInventory.name=="glock18") player.WeaponInInventory=glock18;
            else if(player.WeaponInInventory.name=="knife") player.WeaponInInventory=knife;
        }
        else if (key == "secondary_ammo")  player.WeaponInInventory.ammo = std::stoi(value);
        else if (key == "secondary_ammo_left") player.WeaponInInventory.ammo_left = std::stoi(value);
        else if (key == "x") player.x = std::stoi(value);
        else if (key == "y") player.y = std::stoi(value);
        else if (key == "zombie alive") game_round.zombie_left = std::stoi(value);
        

    }

    file.close();
    return issaved;
}