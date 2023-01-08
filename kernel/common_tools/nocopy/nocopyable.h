/*
 * Date:2022-09-01
 * Author: Tian yi
 * funtion:  nocopyable
 * Description :  make your class not able to copy and
assignment.  make  your object  is create by you, and used by you.
 * Example:
 * Reference:
 */
#pragma once

class NonCopyable {
 public:
  NonCopyable(const NonCopyable&) = delete;
  NonCopyable& operator=(const NonCopyable&) = delete;

 protected:
  NonCopyable() = default;
  ~NonCopyable() = default;
};