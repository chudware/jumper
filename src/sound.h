void jumpSound(void)
{
    NR10_REG = 0x16;
    NR11_REG = 0x40;
    NR12_REG = 0x72;
    NR13_REG = 0x00;
    NR14_REG = 0xC3;
}