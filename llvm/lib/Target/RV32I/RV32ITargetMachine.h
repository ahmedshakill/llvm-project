#ifndef RV32I_TARGET_MACHINE_H
#define RV32I_TARGET_MACHINE_H

#include "llvm/CodeGen/TargetPassConfig.h"
#include "llvm/Target/TargetMachine.h"
#include <optional>

namespace llvm {
  class RV32ITargetMachine : public LLVMTargetMachine {
  public:
    RV32ITargetMachine(Target const &T, Triple const &TT, StringRef CPU,
                       StringRef FS, TargetOptions const &Options,
                       std::optional<Reloc::Model> RM,
                       std::optional<CodeModel::Model> CM, CodeGenOptLevel OL,
                       bool JIT);
    ~RV32ITargetMachine(){}
  TargetPassConfig *createPassConfig(PassManagerBase &PM) override;
};
} // namespace llvm

#endif // RV32I_TARGET_MACHINE_H

