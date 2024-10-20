add_llvm_component_group(RV32I)

set(LLVM_TARGET_DEFINITIONS 
  RV32I.td
)
tablegen(LLVM RV32IGenSubtargetInfo.inc -gen-subtarget)
tablegen(LLVM RV32IGenDAGISel.inc -gen-dag-isel)
add_public_tablegen_target(RV32ICommonTableGen)

add_llvm_target(RV32ICodeGen
  RV32ITargetMachine.cpp
  RV32IDAGToDAGISel.cpp
)

add_subdirectory(TargetInfo)
add_subdirectory(TargetDesc)

