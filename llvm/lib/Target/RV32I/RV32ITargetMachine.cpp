#include "RV32ITargetMachine.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/CodeGen.h"
#include "llvm/Target/TargetMachine.h"

using namespace llvm;

extern Target RV32ITarget;


extern "C" void LLVMInitializeRV32ITarget(){
  RegisterTargetMachine<RV32ITargetMachine> X(RV32ITarget);
}

RV32ITargetMachine::RV32ITargetMachine(Target const &T,   Triple const &TT, StringRef CPU,
                       StringRef FS, TargetOptions const &Options,
                       std::optional<Reloc::Model> RM,
                       std::optional<CodeModel::Model> CM, CodeGenOptLevel OL,
                       bool JIT)
    : LLVMTargetMachine(T, "e-m:m-p:32:32-i8:8:32-i16:16:32-i64:64-n32-S64", TT,
                        CPU, FS, Options, RM.value_or(Reloc::Static), 
                        getEffectiveCodeModel(CM, CodeModel::Small), OL) {
  initAsmInfo();
}
