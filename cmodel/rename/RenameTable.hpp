#pragma once

#include "../common.hpp"
#include "../config.hpp"
#include <cstdint>
#include <vector>

using namespace std;
using namespace ca_model::utils;

namespace ca_model::rename {

typedef struct {
  bool hold;
  uint32_t addr;
  uint32_t data;
} RatRead_t;

typedef struct {
  bool wen;
  uint32_t addr;
  uint32_t data;
} RatWrite_t;

template <int readPortsNum, int rdataNums>
class RenameTable {
private:
  // ================ port =======================/
    bool redirect ;
    std::vector<RatRead_t> read_port[RenameWidth * readPortsNum];
    std::vector<RatWrite_t> specWritePorts[RabCommitWidth];
    std::vector<RatWrite_t> archWritePorts[RabCommitWidth];
    std::vector<uint32_t> old_pdest[RabCommitWidth];
    std::vector<bool> need_free[RabCommitWidth];

  // ================ port =======================/

  std::vector<utils::dff<uint32_t>> spec_table;
  
};
}; // namespace ca_model::rename