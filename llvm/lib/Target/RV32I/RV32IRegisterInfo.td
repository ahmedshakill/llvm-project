def Zero : Register<"zero">, DwarfRegNum<[0]>{
  let Namespace="RV32I";
}

def GPR : RegisterClass<"RV32I",[i32], 32, (add Zero)> {}

