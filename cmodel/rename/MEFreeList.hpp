#pragma once

#include "../common.hpp"
#include "../config.hpp"
#include "../bundle.hpp"
#include <vector>

using namespace ca_model::utils;

namespace ca_model::rename {

typedef struct {
  std::vector<bool> allocateReq_i[RenameWidth];
  std::vector<uint32_t> allocatePhyReg_o[RenameWidth];
  bool canAllocate_o;
  bool doAllocate_i;
} allocate_pack_t;

typedef struct {
  std::vector<bool> freeReq_i[RabCommitWidth];
  std::vector<uint32_t> freePhyReg_i[RabCommitWidth];
} free_pack_t;

template <typename T, size_t Size> class MEFreeList {
private:

  // ================ port =======================/
  allocate_pack_t allocate_port;
  free_pack_t free_port;
  RabCommit_t commit_port;
  // ================ port =======================/

  static utils::dff<circularQueuePtr<T, Size>> headPtr;
  static utils::dff<circularQueuePtr<T, Size>> tailPtr;
  static std::vector<dff<T>> free_list[Size];


public:

    MEFreeList() {
        for (int i = 0; i < Size; i++) {
        free_list[i].resize(IntPhyRegs);
        }

        tailPtr = circularQueuePtr<T, Size>(false, Size-1);
        headPtr = circularQueuePtr<T, Size>(false, 0);
    }

  void update() {

  }
};
}; // namespace ca_model::rename


