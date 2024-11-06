add_llvm_component_group(M88k)

set(LLVM_TARGET_DEFINITIONS M88k.td)

tablegen(LLVM M88kGenAsmMatcher.inc -gen-asm-matcher)
tablegen(LLVM M88kGenAsmWriter.inc -gen-asm-writer)
tablegen(LLVM M88kGenMCCodeEmitter.inc -gen-emitter)
tablegen(LLVM M88kGenDisassemblerTables.inc -gen-disassembler)
tablegen(LLVM M88kGenInstrInfo.inc -gen-instr-info)
tablegen(LLVM M88kGenRegisterInfo.inc -gen-register-info)
tablegen(LLVM M88kGenSubtargetInfo.inc -gen-subtarget)

add_public_tablegen_target(M88kCommonTableGen)

add_llvm_target(M88kCodeGen
  M88kTargetMachine.cpp

  LINK_COMPONENTS
  M88kDesc
  M88kInfo
  CodeGen
  Core
  MC
  Support
  Target

  ADD_TO_COMPONENT
  M88k
  )

add_subdirectory(AsmParser)
add_subdirectory(Disassembler)
add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)


