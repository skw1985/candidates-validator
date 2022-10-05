#pragma once

class Candidate;

class Requirement {
public:
    virtual ~Requirement() = default;
    virtual bool validate(const Candidate &) const = 0;
};