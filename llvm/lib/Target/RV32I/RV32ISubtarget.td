def RV32IInstrInfo : InstrInfo;

def RV32I : Target{
  let InstructionSet = RV32IInstrInfo;
}

