label:
    add x2, x0, x1
    sll x1, x2, x2
    or x2, x2, x1
    andi x2, x1, 16
    addi x3, x2, -243
label2:
    add x2, x0, x1