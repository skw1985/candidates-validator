#pragma once

#include <memory>
#include <list>
#include <typeinfo>
#include "Requirement.hpp"

class Candidate;

class BetterCandidatesValidator
{
public:
    enum Exist {False, True};

    void add(std::unique_ptr<Requirement> req)
    {
        requirements.push_back(std::move(req));
    }

    template <typename Type>
    Exist addOrReplace(std::unique_ptr<Requirement> req)
    {
        auto it = findType<Type>();

        if (it == requirements.end()) {
            requirements.push_back(std::move(req));
            return Exist::False;
        }

        *it = std::move(req);
        return Exist::True;
    }

    template <typename Type>
    bool removeFirstOccurence()
    {
        auto it = findType<Type>();
        
        if (it != requirements.end()) {
            requirements.erase(it);
            return true;
        }

        return false;
    }

    bool shouldBeHired(const Candidate& c) const
    {
        for (auto &v : requirements)
            if (!v->validate(c))
                return false;
        
        return true;
    }
private:
    std::list<std::unique_ptr<Requirement>> requirements;

    template <typename Type>
    auto findType()
    {
        for (auto it = requirements.begin(); it != requirements.end(); ++it)
            if (dynamic_cast<Type *>(it->get()))
                return it;
        
        return requirements.end();
    }
};
