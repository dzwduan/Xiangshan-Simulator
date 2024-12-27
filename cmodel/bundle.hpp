#pragma once

#include <cstdint>
#include <vector>
#include "config.hpp"

typedef struct {
    uint32_t ldest;
    uint32_t pdest;
    bool rfWen;
} RabCommitInfo_t;

typedef struct {
    bool isCommit;
    bool isWalk;
    bool walkValid;
    std::vector<bool> commitValid[RabCommitWidth];
    RabCommitInfo_t commitInfo[RabCommitWidth];
} RabCommit_t;