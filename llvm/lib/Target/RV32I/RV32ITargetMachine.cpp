#include "RV32ITargetMachine.h"
#include "RV32IDAGToDAGISel.h"
#include "llvm/IR/LegacyPassManager.h"
#include <llvm/CodeGen/TargetPassConfig.h>
#include <llvm/MC/TargetRegistry.h>

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

class RV32IPassConfig : public TargetPassConfig {
public:
  RV32IPassConfig(RV32ITargetMachine &TM, legacy::PassManagerBase &PM)
    : TargetPassConfig(TM, PM) {}

  bool addInstSelector() override {
    addPass(new RV32IDAGToDAGISelPass(getTM<RV32ITargetMachine>()));
    return false;
  }
};

TargetPassConfig *RV32ITargetMachine::createPassConfig(PassManagerBase &PM) {
  return new RV32IPassConfig(*this, PM);
}







