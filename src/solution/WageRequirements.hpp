#pragma once

#include "BetterCandidatesValidator.hpp"
#include "../Candidate.hpp"

class WageRequirements : public Requirement
{
public:
    WageRequirements(unsigned wageReq) : maxPreferredWage(wageReq) {}

    bool validate(const Candidate &c) const override
    {
        return c.preferredWage <= maxPreferredWage;
    }
private:
    unsigned maxPreferredWage;
};
