multiclass Logic<bits<5> Fun, string OpcStr, SDNode OpNode> {
  let isCommutable = 1 in
    def rr : F_LR<Fun, 0b0, OpcStr,
            [(set i32:$rd,
              (OpNode GPROpnd:$rs1, GPROpnd:$rs2))]>;
  def rrc : F_LR<Fun, 0b1, OpcStr,
            [(set i32:$rd,
            (OpNode GPROpnd:$rs1, (not GPROpnd:$rs2)))] >;
}

defm AND : Logic<0b01000, "and", and>;
defm XOR : Logic<0b01010, "xor", xor>;
defm OR  : Logic<0b01011, "or",  or>;
