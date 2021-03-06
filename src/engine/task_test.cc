// Test case for Task.
//
// @see Task
//

#include "gtest/gtest.h"

#include <engine/task.cc>

// TODO(Renato): Work on more elaborate tests (which require private members).

// Tests the reliability of finishing a Task.
TEST(TaskTest, FinishValidity) {
  psy::engine::Task target_task;
  EXPECT_FALSE(target_task.finished());
  target_task.set_finished(true);
  EXPECT_TRUE(target_task.finished());
  target_task.set_finished(false);
  EXPECT_FALSE(target_task.finished());
}
