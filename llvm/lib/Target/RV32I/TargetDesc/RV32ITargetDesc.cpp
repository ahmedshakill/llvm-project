#include "llvm/ADT/StringRef.h"
#include "llvm/MC/MCAsmInfo.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/MCTargetOptions.h"
#include "llvm/MC/TargetRegistry.h"

#define GET_SUBTARGETINFO_MC_DESC
#include "RV32IGenSubtargetInfo.inc"

using namespace llvm;

extern Target RV32ITarget;

static MCAsmInfo *createRV32IMCAsmInfo(MCRegisterInfo const &MRI,
                                       Triple const &TT,
                                       MCTargetOptions const &Options){
  MCAsmInfo *x = new MCAsmInfo();
  return x;
}

static MCSubtargetInfo *createRV32IMCSubtargetInfo(Triple const &TT,
                                                   StringRef CPU, StringRef FS){
  return createRV32IMCSubtargetInfoImpl(TT, CPU, CPU, FS);
}

static MCInstrInfo *createRV32IMCInstrInfo(){
  MCInstrInfo *x = new MCInstrInfo();
  return x;
}

static MCRegisterInfo *createRV32IMCRegisterInfo(Triple const &TT){
  MCRegisterInfo *x = new MCRegisterInfo();
  return x;
}

extern "C" void LLVMInitializeRV32ITargetMC(){
  TargetRegistry::RegisterMCRegInfo(RV32ITarget, 
                                    createRV32IMCRegisterInfo);
  TargetRegistry::RegisterMCInstrInfo(RV32ITarget, createRV32IMCInstrInfo);
  TargetRegistry::RegisterMCSubtargetInfo(RV32ITarget, createRV32IMCSubtargetInfo);
  TargetRegistry::RegisterMCAsmInfo(RV32ITarget, createRV32IMCAsmInfo);
}

