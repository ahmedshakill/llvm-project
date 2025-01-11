#include "M88kMCAsmInfo.h"
#include "llvm/MC/MCTargetOptions.h"
#include "llvm/TargetParser/Triple.h"

using namespace llvm;

llvm::M88kMCAsmInfo::M88kMCAsmInfo(const Triple &TT){
  IsLittleEndian = false;
  //UseDotAlignForAlignment = true;
  MinInstAlignment = 4;
  CommentString = "|";

  ZeroDirective = "\t.space\t";
  Data64bitsDirective = "t.quad\t";
  UsesELFSectionDirectiveForBSS = true;
  SupportsDebugInformation = false;
  ExceptionsType = ExceptionHandling::SjLj;
}

