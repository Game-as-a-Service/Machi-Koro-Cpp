#ifndef REPOS_REPOSITORY_H
#define REPOS_REPOSITORY_H

#include <string>
#include <memory>

#include "models/machikoro_game.h"

class Repository {
public:
    virtual ~Repository() = default;

    virtual MachiKoroGame* findById(const std::string& id) = 0;

    virtual void save(std::unique_ptr<MachiKoroGame> game) = 0;

    virtual void clear(const std::string& id) = 0;
};

#endif  // REPOS_REPOSITORY_H