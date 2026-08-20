SECTIONS
{
    .text 0x00100000 :
    {
        *(.text)
    }
    . = ALIGN(128);
    .data :
    {
        *(.data)
    }
    . = ALIGN(128);
    .rodata :
    {
        *(.rodata)
    }
    . = ALIGN(128);
    .lit4 :
    {
        *(.lit4)
    }
    . = ALIGN(128);
    .sdata :
    {
        *(.sdata)
    }
    . = ALIGN(128);
    .sbss :
    {
        *(.sbss)
    }
    . = ALIGN(128);
    .bss :
    {
        *(.bss)
    }
}
