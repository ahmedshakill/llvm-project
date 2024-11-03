#ifndef LLVM_LIB_TARGET_M88K_MCTARGETDESC_M88KMCASMINFO_H
#define LLVM_LIB_TARGET_M88K_MCTARGETDESC_M88KMCASMINFO_H

#include "llvm/MC/MCAsmInfoELF.h"
#include "llvm/TargetParser/Triple.h"
namespace llvm {
  class Triple;

  class M88kMCAsmInfo : public MCAsmInfoELF{
  public:
    explicit M88kMCAsmInfo(const Triple &TT);
  };
} // namespace llvm

#endif // !LLVM_LIB_TARGET_M88K_MCTARGETDESC_M88KMCASMINFO_H
