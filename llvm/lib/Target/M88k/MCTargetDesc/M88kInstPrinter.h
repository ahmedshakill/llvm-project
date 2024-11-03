#ifndef LLVM_LIB_TARGET_M88K_MCTARGETDESC_M88KINSTPRINTER_H
#define LLVM_LIB_TARGET_M88K_MCTARGETDESC_M88KINSTPRINTER_H

#include "llvm/MC/MCAsmInfo.h"
#include "llvm/MC/MCInst.h"
#include "llvm/MC/MCInstPrinter.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/Support/raw_ostream.h"
#include <cstdint>
#include <utility>
namespace llvm{
  class MCAsmInfo;
  class MCOperand;

  class M88kInstPrinter : public MCInstPrinter {
    public:
      M88kInstPrinter(const MCAsmInfo &MAI,
                      const MCInstrInfo &MII,
                      const MCRegisterInfo &MRI)
          : MCInstPrinter(MAI, MII, MRI){}

    std::pair<const char *, uint64_t> getMnemonic(const MCInst *MI) override;
    void printInstruction(const MCInst *MI, uint64_t Address,
                          const MCSubtargetInfo &STI, raw_ostream &O);
    static const char *getRegisterName(MCRegister RegNo);

    // Print the given operand
    void printOperand(const MCInst *MI, int opNum, const MCSubtargetInfo &STI,
                      raw_ostream &O);
    static void printOperand(const MCOperand &MO, const MCAsmInfo *MAI,
                             raw_ostream &O);

    //override MCInstPrinter
    // void printRegName(raw_ostream &O, unsigned RegNo) const override;
    void printInst(const MCInst *MI, uint64_t Address, StringRef Annot,
                   const MCSubtargetInfo &STI, raw_ostream &O) override;
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_M88K_MCTARGETDESC_M88KINSTPRINTER_H
