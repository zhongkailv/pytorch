#include "ATen/ATen.h"
#include "ATen/NativeFunctions.h"
#include "ATen/WrapDimUtils.h"

namespace at {
namespace native {

bool is_same_size(const Tensor& self, const Tensor& other) {
  return self.sizes().equals(other.sizes());
}

int64_t size(const Tensor& self, int64_t dim) {
  dim = maybe_wrap_dim(dim, self.dim());
  // wrap_dim guarantees bounds are correct.
  return self.sizes()[dim];
}

int64_t stride(const Tensor& self, int64_t dim) {
  dim = maybe_wrap_dim(dim, self.dim());
  // wrap_dim guarantees bounds are correct.
  return self.strides()[dim];
}

}
}
