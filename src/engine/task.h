#ifndef PSY_ENGINE_TASK_
#define PSY_ENGINE_TASK_

#include <functional>

#include <SFML/System.hpp>

namespace psy {

// Task is a functor with priority.
class Task {
 public:
  // Warning: This should NOT be called.
  Task();
  // The higher the priority, the higher up on the stack.
  explicit Task(const std::function<void (const sf::Time& dt)>& func);
  virtual ~Task();

  // Updates this task with an elapsed delta time (dt).
  void Update(const sf::Time& dt);

  // Overloades the function call operator for Task to work as a Functor.
  void operator()(const sf::Time& dt) {
    update_function_(dt);
  } 

  bool finished() { return finished_; }
  void set_finished(bool finished) { finished_ = finished; }

 private:
  std::function<void (const sf::Time& dt)> update_function_;
  bool finished_; // Checks whether it is to be destroyed next frame.
};

} // namespace psy

#endif