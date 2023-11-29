#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream> 
#include "../hpp files/classes.hpp"
#include "../hpp files/functions.hpp"
#include "../hpp files/g_variables.hpp"


struct Node {
    int x, y;
    float cost;
    Node* parent;
};

struct CompareCost {
    bool operator()(Node* a, Node* b) {
        return a->cost > b->cost;
    }
};

std::vector<std::vector<int>> StringToMap(const std::string& game_map) {
    int width = game_map.find('\n');
    int height = std::count(game_map.begin(), game_map.end(), '\n');
    std::vector<std::vector<int>> map(height, std::vector<int>(width, 0));
    int x = 0, y = 0;
    for (char tile : game_map) {
        if (tile == '\n') {
            y++;
            x = 0;
            continue;
        }
        switch (tile) {
            case 'o':
                map[y][x] = 0;
                    break;
            case ' ':
                map[y][x] = 0;
                break;
            default:
                map[y][x] = 1;
                break;
        }
        x++;
    }
    return map;
}


std::vector<Node*> aStar(Node* start, Node* goal, std::vector<std::vector<int>> &map) {

    std::cout << "aStar called with start at (" << start->x << ", " << start->y << ") and goal at (" << goal->x << ", " << goal->y << ")\n";

    std::priority_queue<Node*, std::vector<Node*>, CompareCost> nodesToVisit;
    std::vector<std::vector<bool>> visited(map.size(), std::vector<bool>(map[0].size(), false));
    nodesToVisit.push(start);

    while (!nodesToVisit.empty()) {
        Node* current = nodesToVisit.top();
        std::cout << "Visiting node at (" << current->x << ", " << current->y << ")\n";
        std::cout << "Size of nodesToVisit before pop: " << nodesToVisit.size() << "\n";
        nodesToVisit.pop();
        std::cout << "Size of nodesToVisit after pop: " << nodesToVisit.size() << "\n";
        std::cout << "Current node after pop: (" << current->x << ", " << current->y << ")\n";

        std::cout << "Size of visited: " << visited.size() << "x" << (visited.empty() ? 0 : visited[0].size()) << "\n";
        std::cout << "Current node: (" << current->x << ", " << current->y << ")\n";
        if (current->x < visited.size() && current->y < visited[0].size()) {
            std::cout << "Visited status of current node: " << visited[current->x][current->y] << "\n";
        } else {
            std::cout << "Current node is out of bounds for visited\n";
        }

        if (current->x >= 0 && current->x < visited.size() && current->y >= 0 && current->y < visited[0].size() && visited[current->x][current->y]) {
            std::cout << "Node already visited, skipping\n";
            delete current;
            continue;
        }

        if (current->x >= 0 && current->x < visited.size() && current->y >= 0 && current->y < visited[0].size()) {
            visited[current->x][current->y] = true;
        }

        if (current->x == goal->x && current->y == goal->y) {
            std::cout << "Goal reached\n";
            std::vector<Node*> path;
            while (current != nullptr) {
                path.push_back(current);
                current = current->parent;
            }
            // Delete the remaining nodes in nodesToVisit
            while (!nodesToVisit.empty()) {
                delete nodesToVisit.top();
                nodesToVisit.pop();
            }
            return path;
        }

        std::cout << "Before entering the for loop\n";
        std::cout << "Current node: (" << current->x << ", " << current->y << ")\n";
        std::cout << "Map size: " << map.size() << "x" << (map.empty() ? 0 : map[0].size()) << "\n";

        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                int newX = current->x + dx;
                int newY = current->y + dy;
                std::cout << "Checking node at (" << newX << ", " << newY << ")\n";

                if (newX >= 0 && newX < map.size() && newY >= 0 && newY < map[0].size() && map[newX][newY] != 1 && !visited[newX][newY]) {
                    std::cout << "Adding node at (" << newX << ", " << newY << ") to nodes to visit\n";
                    Node* next = new Node{newX, newY, current->cost + 1, current};
                    nodesToVisit.push(next);
                }
            }
        }
    }

    // If the goal is unreachable, delete the remaining nodes in nodesToVisit
    while (!nodesToVisit.empty()) {
        delete nodesToVisit.top();
        nodesToVisit.pop();
    }

    std::cout << "Goal not reachable\n";
    return std::vector<Node*>();
}

void pathfind(zombies &current) {
    std::cout << "Pathfind called for zombie at (" << current.x << ", " << current.y << ")\n";

    Node start = { current.x, current.y };
    Node goal = { player.x, player.y };
    std::vector<std::vector<int>> map = StringToMap(game_map);
    std::cout << "Map created with size " << map.size() << "x" << (map.empty() ? 0 : map[0].size()) << "\n";

    std::vector<Node*> path = aStar(&start, &goal, map);
    std::cout << "Path calculated with length " << path.size() << "\n";

    if (!path.empty()) {
        Node* nextNode = path.back();
        std::cout << "Next node is at (" << nextNode->x << ", " << nextNode->y << ")\n";

        // Calculate the direction vector from the current position to the next node
        float dx = nextNode->x - current.x;
        float dy = nextNode->y - current.y;

        // Calculate the length of the direction vector
        float length = std::sqrt(dx * dx + dy * dy);

        // Normalize the direction vector
        dx /= length;
        dy /= length;

        // Move the zombie by current.speed units towards the next node
        float move = std::min(length, static_cast<float>(current.speed));
        current.x += dx * move;
        current.y += dy * move;

        std::cout << "Zombie moved to (" << current.x << ", " << current.y << ")\n";
    }

    // Delete the nodes in the path
    for (Node* node : path) {
        delete node;
    }

    std::cout << "Pathfind finished for zombie at (" << current.x << ", " << current.y << ")\n";
}
