#pragma once

#include "BetterCandidatesValidator.hpp"
#include "../Candidate.hpp"

class CppRequirements : public Requirement
{
public:
    CppRequirements(unsigned minReq) : minCppRequirements(minReq) {}

    bool validate(const Candidate &c) const override
    {
        return c.cppFluency >= minCppRequirements;
    }
private:
    unsigned minCppRequirements;
};
