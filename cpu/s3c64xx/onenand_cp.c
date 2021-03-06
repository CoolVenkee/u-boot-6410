#include <common.h>

/* jsgood: temporary */
#ifdef CONFIG_BOOT_ONENAND_IROM

#define ONENAND_ReadPage_4burst(a,b,c,d)	(((int(*)(uint, uint, uchar, uint *))(*((uint *)(0x0c004010))))(a,b,c,d))

void onenand_bl2_copy(void)
{
	int block, page;
	volatile unsigned int *base = 0x57e00000;

	for (block = 0; block < 2; block++) {
		for (page = 0; page < 64; page++) {
			ONENAND_ReadPage_4burst(0, block, page, base);
			base += 512;
		}
	}
}

#endif /* CONFIG_BOOT_ONENAND */

