#include "llvm/IR/Module.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;
Target RV32ITarget;

extern "C" void LLVMInitializeRV32ITargetInfo(){
  RegisterTarget<Triple::rv32i, true> X(RV32ITarget, "rv32i", "Integer-only 32-bit RISC-V backend", "RV32I");
}

