#pragma once

#include "BetterCandidatesValidator.hpp"
#include "../Candidate.hpp"

class CRequirements : public Requirement
{
public:
    CRequirements(unsigned creq) : minCRequirements(creq) {}

    bool validate(const Candidate &c) const override
    {
        return c.cFluency >= minCRequirements;
    }
private:
    unsigned minCRequirements;
};
