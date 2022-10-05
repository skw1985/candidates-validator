#include <vector>
#include <iostream>

#include "Application.hpp"
#include "Candidate.hpp"

int main()
{
    std::vector<Candidate> candidates {
        {"Adelajda", 15, 87, 0, 12000},
        {"Brunhilda", 85, 42, 1, 11000},
        {"Ciechosław", 97, 92, 1, 25000},
        {"Domażyr", 91, 45, 0, 10000}
    };

    BetterCandidatesValidator requirements;

    requirements.add(std::make_unique<CppRequirements>(20));
    requirements.add(std::make_unique<CRequirements>(0));
    requirements.add(std::make_unique<CooperationNeeded>());
    requirements.add(std::make_unique<WageRequirements>(15000));
    requirements.removeFirstOccurence<CooperationNeeded>();
    requirements.addOrReplace<CRequirements>(std::make_unique<CRequirements>(40));

    for (auto candidate : getFilteredCandidates(candidates, requirements))
    {
        std::cout << "candidate " << candidate.name << " seems to fit\n";
    }
}
