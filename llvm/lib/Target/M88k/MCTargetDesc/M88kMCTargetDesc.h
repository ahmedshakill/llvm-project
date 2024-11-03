#ifndef LLVM_LIB_TARGET_M88K_TARGETDESC_M88KTARGETDESC_H
#define LLVM_LIB_TARGET_M88K_TARGETDESC_M88KTARGETDESC_H


#include "llvm/ADT/StringRef.h"
#include "llvm/MC/MCAsmBackend.h"
#include "llvm/MC/MCCodeEmitter.h"
#include "llvm/MC/MCContext.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCObjectWriter.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/MCTargetOptions.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/DataTypes.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/TargetParser/Triple.h"

#include <cstdint>
#include <memory>

namespace llvm{

  class MCAsmBackend;
  class MCCodeEmitter;
  class MCContext;
  class MCInstrInfo;
  class MCObjectTargetWriter;
  class MCRegisterInfo;
  class MCSubtargetInfo;
  class MCTargetOptions;
  class StringRef;
  class Target;
  class Triple;
  class raw_pwrite_stream;
  class raw_ostream;

  MCCodeEmitter *createM88kMCCodeEmitter(const MCInstrInfo &MCII,
                                         MCContext &Ctx);

//  MCAsmBackend *createM88kMCAsmBackend(const Target &T,
//                                       const MCSubtargetInfo &STI,
//                                       const MCRegisterInfo &MRI,
//                                       const MCTargetOptions &Options);
//
//  std::unique_ptr<MCObjectTargetWriter> createM88kObjectWriter(uint8_t OSABI);

} // end namespace llvm


#define GET_REGINFO_ENUM
#include "M88kGenRegisterInfo.inc"

#define GET_INSTRINFO_ENUM
#include "M88kGenInstrInfo.inc"

#define GET_SUBTARGETINFO_ENUM
#include "M88kGenSubtargetInfo.inc"


#endif // LLVM_LIB_TARGET_M88K_TARGETDESC_M88KTARGETDESC_H
