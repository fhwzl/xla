#pragma once

#include "torch_xla/csrc/ir.h"

namespace torch_xla {

// XlaNode for the upper triangular part of a matrix (2-D tensor) or batch of
// matrices input.
class Triu : public XlaNode {
 public:
  Triu(const torch::lazy::Value& input, int64_t diagonal);

  torch::lazy::NodePtr Clone(torch::lazy::OpList operands) const override;

  XlaOpVector Lower(LoweringContext* loctx) const override;

  std::string ToString() const override;

  int64_t diagonal() const { return diagonal_; }

 private:
  int64_t diagonal_;
};

}  // namespace torch_xla
