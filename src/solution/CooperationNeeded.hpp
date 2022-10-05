#pragma once

#include "BetterCandidatesValidator.hpp"
#include "../Candidate.hpp"

class CooperationNeeded : public Requirement
{
public:
    bool validate(const Candidate &c) const override
    {
        return c.cooperative;
    }
};
