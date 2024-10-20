#include "RV32IDAGToDAGISel.h"
#include "llvm/CodeGen/SelectionDAGISel.h"
#include "llvm/Target/TargetMachine.h"
#include <memory> 


using namespace llvm;


void RV32IDAGToDAGISel::Select(SDNode *N) {SelectCode(N); }

RV32IDAGToDAGISelPass::RV32IDAGToDAGISelPass(RV32ITargetMachine &TM)
    : SelectionDAGISelPass(
        std::make_unique<RV32IDAGToDAGISel>(TM, TM.getOptLevel())) {}

PreservedAnalyses RV32IDAGToDAGISelPass::run(MachineFunction &MF,
                                             MachineFunctionAnalysisManager &MFAM){
  return SelectionDAGISelPass::run(MF, MFAM);
} 

