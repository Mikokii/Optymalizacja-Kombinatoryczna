#pragma once

#include <vector>
#include <iostream>

class Graph{
private:
    int vertices_number;
    std::vector<std::pair<int,int>> vertices_list;
    std::vector<std::vector<float>> adjacency_matrix;
    int ants_number;
    int iterations;
public:
    Graph();
    ~Graph();
    void initRandomGraph(int vertices_number, int range);
    void saveGraphToFile(const char* filename);
    void initGraphFromFile(const char* filename);
    void generateAdjacencyMatrix();
    void printGraph();
    std::pair<float, std::vector<int>> greedyTSP();
    std::vector<std::vector<float>> getAdjacencyMatrix();
    std::pair<float, std::vector<int>> antColonySystem(int ants_number, int iterations, float alpha, float beta, float p, float Q);
    float calculateProbability(int destination, std::vector<int> path, float alpha, float beta, std::vector<std::vector<float>> &trail_matrix);
    int pickNextPoint(std::vector<float> &probabilities);
};

float calculateDistance(std::pair<int, int> point1, std::pair<int, int> point2);
