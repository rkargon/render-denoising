#inclue "camera_path.h"

#include "QuaternionCamera.h"

camera_path::iterator() : m_path(nullptr), m_end(true) {}
camera_path::iterator(const camera *path, const QuaternionCamera &cam, bool end)
    : m_path(path), m_cam(cam), m_end(end) {}

bool camera_path::iterator::operator==(const iterator &i) const {
  if (m_end && i.m_end) {
    return true;
  }
  return (m_path == i.m_path) && (m_cam == i.m_cam) && (m_end == i.m_end);
}
bool camera_path::iterator::operator!=(const iterator &i) const {
  return !(*this == i);
}

reference camera_path::iterator::operator*() const { return m_cam; }
pointer camera_path::iterator::operator->() const { return &m_cam; }

iterator &camera_path::iterator::operator++(){
  auto res = m_path->m_update(m_path.m_time);
  m_cam = res.first;
  m_end = res.second;
  return *this;
}
iterator &camera_path::iterator::operator++(int) {
  iterator copy(*this);
  ++(*this);
  return copy;
}

camera_path::iterator camera_path::begin() {
  if(m_path_length == 0){
    return this->end();
  }


}
