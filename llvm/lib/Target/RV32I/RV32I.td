include "llvm/Target/Target.td"

include "RV32ISubtarget.td"

def : ProcessorModel<"generic", NoSchedModel, []>;

include "RV32IRegisterInfo.td"
