
int main() {
    printf("Enter password to authentic yourself : ");
    fflush(*__TMC_END__);
    __isoc99_scanf(0x400e41, &var_40);
    if (strncmp(&var_40, "kaiokenx20", 0xa) == 0x0) goto loc_400a14;

loc_400a00:
    puts("Incorrect password. Closing connection.");
    rax = exit(0x0);
    return rax;

loc_400a14:
    puts("Enter case number: ");
    printf("\n\t 1) Application_1");
    printf("\n\t 2) Application_2");
    printf("\n\t 3) Application_3");
    printf("\n\t 4) Application_4");
    printf("\n\t 5) Application_5");
    printf("\n\t 6) Application_6");
    printf("\n\t 7) Flag");
    printf("\n\n\t Enter choice :- ");
    fflush(*__TMC_END__);
    __isoc99_scanf(0x400fac, &var_48);
    rax = var_48;
    if (rax > 0x7) goto loc_400cb8;

loc_400ac7:
    goto *0x401028[*(rax * 0x8 + 0x401028)];

loc_400cb8:
    if (print_record(&var_30) == 0xffffffff) {
            printf("\nNo such record exists. Please verify your choice.");
    }
    fflush(*__TMC_END__);
    puts(0x401023);
    rax = 0x0;
    rsi = *0x28 ^ *0x28;
    if (rsi != 0x0) {
            rax = __stack_chk_fail();
    }
    return rax;

loc_400ad3:
    var_30 = 0x3037303838356132;
    *(&var_30 + 0x8) = 0x3566356538656130;
    *(&var_30 + 0x10) = 0x6339666439616331;
    *(&var_30 + 0x18) = 0x6436353334346135;
    *(int32_t *)(&var_30 + 0x20) = 0x7461642e;
    *(int8_t *)(&var_30 + 0x24) = 0x0;
    goto loc_400cb8;

loc_400b1e:
    var_30 = 0x6331656461353863;
    *(&var_30 + 0x8) = 0x3265626263623734;
    *(&var_30 + 0x10) = 0x3934313234366361;
    *(&var_30 + 0x18) = 0x3831623139343931;
    *(int32_t *)(&var_30 + 0x20) = 0x7461642e;
    *(int8_t *)(&var_30 + 0x24) = 0x0;
    goto loc_400cb8;

loc_400b69:
    var_30 = 0x3233613163393238;
    *(&var_30 + 0x8) = 0x3362666133323236;
    *(&var_30 + 0x10) = 0x6236316334336333;
    *(&var_30 + 0x18) = 0x6432373437346162;
    *(int32_t *)(&var_30 + 0x20) = 0x7461642e;
    *(int8_t *)(&var_30 + 0x24) = 0x0;
    goto loc_400cb8;

loc_400bb4:
    var_30 = 0x6438326664343561;
    *(&var_30 + 0x8) = 0x6630386434623862;
    *(&var_30 + 0x10) = 0x6164313136363037;
    *(&var_30 + 0x18) = 0x3036343931383939;
    *(int32_t *)(&var_30 + 0x20) = 0x7461642e;
    *(int8_t *)(&var_30 + 0x24) = 0x0;
    goto loc_400cb8;

loc_400bff:
    var_30 = 0x6362376562333534;
    *(&var_30 + 0x8) = 0x6330396433326630;
    *(&var_30 + 0x10) = 0x6235646333336530;
    *(&var_30 + 0x18) = 0x3063323833303135;
    *(int32_t *)(&var_30 + 0x20) = 0x7461642e;
    *(int8_t *)(&var_30 + 0x24) = 0x0;
    goto loc_400cb8;

loc_400c47:
    var_30 = 0x3663666533333133;
    *(&var_30 + 0x8) = 0x6235643537613239;
    *(&var_30 + 0x10) = 0x6137653661363564;
    *(&var_30 + 0x18) = 0x6337323136323766;
    *(int32_t *)(&var_30 + 0x20) = 0x7461642e;
    *(int8_t *)(&var_30 + 0x24) = 0x0;
    goto loc_400cb8;

loc_400c8f:
    var_30 = 0x7478742e67616c66;
    *(int8_t *)(&var_30 + 0x8) = 0x0;
    puts("You don't have the required privileges to view the flag, yet.");
    rax = exit(0x0);
    return rax;
}

int print_record(int arg0) {
    var_348 = arg0;
    if (strlen(var_348) != 0x24) {
            rax = 0xffffffff;
    }
    else {
            var_338 = fopen(var_348, 0x400d98);
            if (var_338 == 0x0) {
                    rax = 0xffffffff;
            }
            else {
                    printf("\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
                    puts("\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
                    fread(&var_330, 0x30c, 0x1, var_338);
                    printf(0x400e41);
                    printf("\n\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
                    printf("\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
                    fclose(var_338);
                    rax = 0x0;
            }
    }
    rcx = *0x28 ^ *0x28;
    if (rcx != 0x0) {
            rax = __stack_chk_fail();
    }
    return rax;
}