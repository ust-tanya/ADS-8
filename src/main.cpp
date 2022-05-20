// Copyright 2021 NNTU-CS
#include "train.h"

Train::Cage *Train::create(bool light) {
  Cage* carrg = new Cage;
  carrg->light = light;
  carrg->next = carrg->prev = nullptr;
  return carrg;
}

Train::Train() {
  first = current = nullptr;
  countOp = len = Count = 0;
}

void Train::addCage(bool light) {
  if (!(first)) {
  first = create(light);
  current = first;
  } else {
  current->next = create(light);
  current->next->prev = current;
  current = current->next;
  if (!current->next) {
  current->next = first;
  } else {
  first->prev = current;
  }
  }
}

int Train::getLength() {
  first->light = true;
  current = first;
  int num;
  while (true) {
  ++countOp, ++Count;
  current = current->next;
  if (current->light) {
  num = Count;
  current->light = false;
  if ((current->prev) != nullptr) {
  while (current->light == false) {
  current = current->prev;
  --Count, ++countOp;
  }
  }
  if (!current->light) {
  len = num;
  break;
  }
  }
  }
  countOp += len;
  return len;
}

int Train::getOpCount() {
  return countOp;
}
