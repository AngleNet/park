//===----------------------------------------------------------------------===//
//
//                         BusTub
//
// lru_replacer.cpp
//
// Identification: src/buffer/lru_replacer.cpp
//
// Copyright (c) 2015-2019, Carnegie Mellon University Database Group
//
//===----------------------------------------------------------------------===//

#include "buffer/lru_replacer.h"

namespace bustub {

void FrameNode::InsertBefore(FrameNodePtr node) {
  node->prev = prev;
  node->next = this;
  prev->next = node;
  prev = node;
}

FrameNodePtr FrameNode::RemoveNext() {
  auto ptr = next;
  auto after = next->next;
  next = after;
  after->prev = this;
  ptr->prev = NULL;
  ptr->next = NULL;
  return ptr;
}

void FrameNode::Unlink() {
  auto ptr = prev->RemoveNext();
  delete ptr;
}

LRUReplacer::LRUReplacer(size_t num_pages) : frames(num_pages), victims(0) {
  pins = new FrameNode(0, 0);
  pins->prev = pins;
  pins->next = pins;
  unpins = new FrameNode(0, 0);
  unpins->prev = unpins;
  unpins->next = unpins;
}

LRUReplacer::~LRUReplacer() {
  auto cur = unpins;
  auto marker = unpins;
  do {
    auto tmp = cur;
    cur = cur->next;
    delete tmp;
  } while (cur->next != NULL && cur->next != marker);
  cur = pins;
  marker = pins;
  do {
    auto tmp = cur;
    cur = cur->next;
    delete tmp;
  } while (cur->next != NULL && cur->next != marker);
};

bool LRUReplacer::Victim(frame_id_t *frame_id) {
  if (victims == 0) {
    return false;
  }
  auto ptr = unpins->RemoveNext();
  victims--;
  *frame_id = ptr->frame_id;
  delete ptr;
  return true;
}

void LRUReplacer::Pin(frame_id_t frame_id) {
  auto found = frames.find(frame_id);
  if (found == frames.end()) {
    return;
  }
  auto node = found->second;
  if (node->count == 0) {
    node->Unlink();
    pins->InsertBefore(node);
    node->count--;
    victims--;
    return;
  }
  node->count--;
}

void LRUReplacer::Unpin(frame_id_t frame_id) {
  auto found = frames.find(frame_id);
  if (found == frames.end()) {
    auto node = new FrameNode(0, frame_id);
    unpins->InsertBefore(node);
    frames[frame_id] = node;
    victims++;
    return;
  }
  auto node = found->second;
  if (node->count == 0) {
    return;
  }
  if (node->count == 1) {
    node->Unlink();
    unpins->InsertBefore(node);
    node->count = 0;
    victims++;
  }
  node->count--;
}

size_t LRUReplacer::Size() { return victims; }

}  // namespace bustub
