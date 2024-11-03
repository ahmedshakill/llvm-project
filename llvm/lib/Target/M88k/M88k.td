include "llvm/Target/Target.td"

include "M88kRegisterInfo.td"
include "M88kInstrFormats.td"
include "M88kInstrInfo.td"

def M88kInstrInfo : InstrInfo;

def M88kAsmParser : AsmParser;
def M88kAsmParserVariant : AsmParserVariant{
  let RegisterPrefix = "%";
}

// M88k Subtarget Features
def FeatureISA00
  : SubtargetFeature<"isa-88000", "SubtargetKind", "M88", "Is M88000 ISA supported">;

class Proc<string Name, list<SubtargetFeature> Features>
    : Processor<Name, NoItineraries, Features>;

def : Proc<"generic", []>;

def M88kAsmWriter : AsmWriter {
  string AsmWriterClassName = "InstPrinter";
  int PassSubtarget = 1;
  int Variant = 0;
}

def M88k : Target{
  let InstructionSet = M88kInstrInfo;
  let AssemblyParsers = [M88kAsmParser];
  let AssemblyParserVariants = [M88kAsmParserVariant];
  let AssemblyWriters = [M88kAsmWriter];
}
