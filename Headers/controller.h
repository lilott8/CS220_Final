#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#pragma once

#include "problem_object.h"
#include "steiner.h"
#include "spc.h"
#include "hadlock.h"

/**
* Class which handles the progression of algorithms necessary.
* This controls the order and execution of Voronoi generation,
* Steiner point generation, and the SPC solver.
*/

namespace Flow {

    class Controller {
    public:
        // Deprecated for right now
        enum Optimization {H_OPT, U_OPT, DEFAULT};  // kruskal's optimization enum

        Controller();
        Controller(ProblemObject*);
        Controller(ProblemObject*, Optimization);
        ~Controller();

        // "Templated" method to start the program
        void start();
        // interface to print the map, for debugging
        void print_map();

        // static so they are able to be referenced everywhere
        static int calculate_distance(int, int);
        static int calculate_manhattan_distance(VNode*, VNode*);
        static double calculate_euclidean_distance(VNode*, VNode*);

        void set_steiner_calculator(int);

    private:
        // Map object that is derived from the problem object
        Map *kMap;

        set<VEdge*> kEdges;          // generated edges
        set<VNode*> kVertices;      // list of all nodes, steiner and points
        set<MapRoute*> kRoutes;

        FlowAlgorithms::Steiner *kSteiner;  // Steiner point class which handles all steiner point calculations
        FlowAlgorithms::Voronoi *kVoronoi;  // Voronoi class which generates the Voronoi candidate points
        FlowAlgorithms::SPC *kSPC;          // Handles the Kruskal/Dijkstra algorithms
        FlowAlgorithms::Hadlock *kHadlock;
        int kSteinerCalculator;             // Determines which steiner algorithm to run

        Optimization kOpt;                  // Deprecated, for now

        void project_vertices_on_map(set<VNode*>); // Interface for debugging
        void project_edges_on_map(set<VEdge*>);     // Interface for debugging
        void add_to_all_vertices(set<VNode*>);
        void add_to_all_edges(set<VEdge*>);
        void add_to_all_routes(set<MapRoute*>);
    };
}
#endif