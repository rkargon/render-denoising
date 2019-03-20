#ifndef CAMERA_PATH_H
#define CAMERA_PATH_H

#include "QuaternionCamera.h"

#include <functional>
#include <iterator>
#include <utility>

// TODO probably doesn't follow exact container/InputIterator semantics
// - e.g. begin() consumes value from update()

class camera_path {
public:
  using update_result = std::pair<QuaternionCamera, bool>;
  using update_func = std::function<update_result, std::size_t>;

  class iterator {
  public:
    using difference_type = long;
    using value_type = QuaternionCamera;
    using pointer = const QuaternionCamera*;
    using reference = const QuaternionCamera*;
    using iterator_category = std::input_iterator_tag;

    iterator();
    iterator(const camera* path, const QuaternionCamera& cam, bool end);

    bool operator==(const iterator& i) const;
    bool operator!=(const iterator& i) const;

    reference operator*() const;
    pointer operator->() const;

    iterator& operator++();
    iterator operator++(int);

  private:
    const camera_path* const m_path;
    const QuaternionCamera m_cam;
    const bool m_end;
  };

  camera_path::iterator begin();
  const camera_path::iterator cbegin() const;
  camera_path::iterator end();
  const camera_path::iterator cend() const;

private:
  update_func m_update;
  QuaternionCameria m_initial_cam;
  const int m_path_length;
  std::size_t m_time = 0;
};

#endif // CAMERA_PATH_H
