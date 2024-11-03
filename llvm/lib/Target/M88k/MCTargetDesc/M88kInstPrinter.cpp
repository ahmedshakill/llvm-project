
#include "M88kInstPrinter.h"
#include "llvm/MC/MCExpr.h"
#include "llvm/MC/MCInst.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

#define DEBUG_TYPE "asm-printer"

#include "M88kGenAsmWriter.inc"

class MCExpr;

void llvm::M88kInstPrinter::printOperand(const MCInst *MI, int opNum,
                                         const MCSubtargetInfo &STI, raw_ostream &O){
  const MCOperand &MO = MI->getOperand(opNum);

  if(MO.isReg()){
    if(!MO.getReg())
      O<<'0';
    else
      O<<'%'<<getRegisterName(MO.getReg());
  } else if(MO.isImm())
      O<<MO.getImm();
    else if(MO.isExpr())
      MO.getExpr()->print(O, &MAI);
    else
    llvm_unreachable("Invalid operand");
}

void M88kInstPrinter::printOperand(const MCOperand &MO, const MCAsmInfo *MAI,
                                   raw_ostream &O) {
  if(MO.isReg()) {
    if(!MO.getReg())
      O<<'0';
    else
      O<<'%'<<getRegisterName(MO.getReg());
  } else if(MO.isImm())
      O<<MO.getImm();
    else if(MO.isExpr())
      MO.getExpr()->print(O, MAI);
    else
     llvm_unreachable("Invalid operand");
}

void M88kInstPrinter::printInst(const MCInst *MI, uint64_t Address,
                                StringRef Annot, const MCSubtargetInfo &STI,
                                raw_ostream &O){
    printInstruction(MI, Address, STI, O);
    printAnnotation(O, Annot);
}
