// Factory.h
#pragma once
#include <functional>
#include <iostream>
#include <map>

template <typename T>
struct Factory {
   struct register_t {
    register_t(const std::string &key) {
      Factory::get().map_.emplace(key, [] { return new T(); });
    }

    template <typename... Args>
    register_t(const std::string &key, Args... args) {
      Factory::get().map_.emplace(key, [&] { return new T(args...); });
    }
  };

  static T *produce(const std::string &key) {
    if (map_.find(key) == map_.end())
      throw std::invalid_argument("the message key is not exist!");

    return map_[key]();
  }

private:
  Factory(){};
  Factory(const Factory &) = delete;
  Factory(Factory &&) = delete;

  static Factory &get() {
    static Factory instance;
    return instance;
  }

  std::map<std::string, std::function<T*()>> map_;
};

#define REGISTER_FACTORY_VNAME(T) reg_factory_##T##_
#define REGISTER_FACTORY(T, key, ...)                                          \
  static Factory<T>::register_t REGISTER_FACTORY_VNAME(T)(key, ##__VA_ARGS__);