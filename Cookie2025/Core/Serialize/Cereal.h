#include <cereal/archives/json.hpp>
#define CEREAL_NVP(value) cereal::make_nvp(#value, value)