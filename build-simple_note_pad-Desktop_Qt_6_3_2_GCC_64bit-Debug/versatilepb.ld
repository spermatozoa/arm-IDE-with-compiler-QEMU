ENTRY(_Reset)
SECTIONS
{
    . = 0x10000;
    .startup : {versatilepb_startup.o(.text)}
    .text : {*(.text)}
    .data : {*(.data)}
    .bss : {*(.bss COMMON)}
    . = ALIGN(8);
    . = . + 0x1000; /* 4KB stack memory */
    stack_top = .;
}
