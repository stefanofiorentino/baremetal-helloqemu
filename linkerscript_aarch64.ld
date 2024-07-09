/* Use the _start symbol as entry point */
ENTRY(_start)
SECTIONS{
        /* Ram starts at 0x40000000 */
        /* QEMU when given -kernel adds 0x1000 */
        . = 0x40010000 ;
        /* Put startup code at the beginning */
        /* Only put the text section of  build/startup_aarch64.o */
        /* Put all other sections from others */
        .stub : {  build/startup_aarch64.o(.text) }
        .text : { *(.text) }
        .rodata : { *(.rodata) }
        .data : { *(.data) }
        /* Put common symbols from bss on the bss section */
        .bss : { *(.bss COMMON) }

        /* Use 4KB for stack */
        . = ALIGN(8);
        stack_bottom = .;
        . += 0x10000;
        stack_top = .;
}
