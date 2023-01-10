ENTRY(_Reset)
SECTIONS
{
    . = 0x40000000;
    .startup : {virt_startup.o(.text)}
    .text : {*(.text)}
    .data : {*(.data)}
    .bss : {*(.bss COMMON)}  /* Uninitialized Data Segment */
    . = ALIGN(8);
    . = . + 0x1000; /* 4KB stack memory */
    stack_top = .;
}
