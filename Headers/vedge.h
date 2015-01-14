#ifndef _VEDGE_H_
#define _VEDGE_H_

#pragma once

#include "vnode.h"
#include "edge.h"

using namespace Utilities;

namespace Flow {
    class VEdge : public Edge {
    public:
        VEdge();
        VEdge(VNode*, VNode*, VNode*);
        ~VEdge();

        VNode* kStart;
        VNode* kEnd;
        VNode* kLeft;
        VNode* kRight;
        VEdge* kNeighbor;
        VNode* kDirection;

        /**
        * Directional coefficients satisfying the equation:
        * y = f * x + g
        */
        double kF;
        double kG;
    };
}

#endif