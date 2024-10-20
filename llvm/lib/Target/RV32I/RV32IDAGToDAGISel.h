#ifndef RV32I_DAG_TO_DAG_ISEL_H
#define RV32I_DAG_TO_DAG_ISEL_H

#include "RV32ITargetMachine.h"
#include "llvm/ADT/StringRef.h"
#include "llvm/CodeGen/MachineFunction.h"
#include "llvm/IR/Analysis.h"
#include "llvm/Target/TargetMachine.h"

#include <llvm/CodeGen/SelectionDAGISel.h>


namespace llvm{
class RV32IDAGToDAGISel : public SelectionDAGISel {
#include "RV32IGenDAGISel.inc"
  public:
    RV32IDAGToDAGISel() = delete;
    explicit RV32IDAGToDAGISel(RV32ITargetMachine &TM, CodeGenOptLevel OL)
      : SelectionDAGISel(TM, OL){}

    void Select(SDNode *N) override;
};

class RV32IDAGToDAGISelPass : public SelectionDAGISelPass{
  public:
  RV32IDAGToDAGISelPass(RV32ITargetMachine &TM);
    
    PreservedAnalyses run(MachineFunction &MF,
                          MachineFunctionAnalysisManager &MFAM);
};

} // namespace llvm

#endif // RV32I_DAG_TO_DAG_ISEL_H

