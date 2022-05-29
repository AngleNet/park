//===----------------------------------------------------------------------===//
//
//                         BusTub
//
// lru_replacer.h
//
// Identification: src/include/buffer/lru_replacer.h
//
// Copyright (c) 2015-2021, Carnegie Mellon University Database Group
//
//===----------------------------------------------------------------------===//

#pragma once

#include <list>
#include <mutex>  // NOLINT
#include <unordered_map>
#include <vector>

#include "buffer/replacer.h"
#include "common/config.h"

namespace bustub {

class LRUReplacer;
class FrameNode;
using FrameNodePtr = FrameNode *;

class FrameNode {
 private:
  unsigned int count;
  frame_id_t frame_id;
  FrameNodePtr prev;
  FrameNodePtr next;
  // A copy constructor is a member function that initializes an object using another
  // object of the same class
  FrameNode(const FrameNode &);
  FrameNode &operator=(FrameNode &);

 public:
  FrameNode(unsigned int count, frame_id_t frame) : count(count), frame_id(frame), prev(NULL), next{NULL} {}
  void InsertBefore(FrameNodePtr node);
  FrameNodePtr RemoveNext();
  void Unlink();
  friend class LRUReplacer;
};

/**
 * LRUReplacer implements the Least Recently Used replacement policy.
 */
class LRUReplacer : public Replacer {
 public:
  /**
   * Create a new LRUReplacer.
   * @param num_pages the maximum number of pages the LRUReplacer will be required to store
   */
  explicit LRUReplacer(size_t num_pages);

  /**
   * Destroys the LRUReplacer.
   */
  ~LRUReplacer() override;

  bool Victim(frame_id_t *frame_id) override;

  void Pin(frame_id_t frame_id) override;

  void Unpin(frame_id_t frame_id) override;

  size_t Size() override;

 private:
  std::unordered_map<frame_id_t, FrameNodePtr> frames;
  FrameNodePtr pins;
  FrameNodePtr unpins;
  unsigned int victims;
};

}  // namespace bustub
