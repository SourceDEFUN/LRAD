#include "prettyprint.h"
#include <string>

namespace pp
{
	size_t color_printf(const char * color, const char * format, ...)
	{
	        // char stringified = color;
		printf("%d%s", color, format);
	}

	void print_prefix(const char* color, const char* prefix)
	{
		printf("%s%s", color, prefix);
		printf("] ");
	}

	size_t Success(char format, ...)
	{
		print_prefix("\e[0;92m", "+");
		printf("%d\n", format);
	}

	size_t Info(char format, ...)
	{
		print_prefix("\e[0;94m", "*");
		printf("%d\n", format);
	}

	size_t Warning(char format, ...)
	{
		print_prefix("\e[0;93m", "!");
		printf("%d\n", format);
	}

	size_t Error(char format, ...)
	{
		print_prefix("\e[0;91m", "-");
		printf("%d\n", format);
		exit(1);
	}

	size_t Fatal(char format, ...)
	{
		print_prefix("\e[0;31m", "FATAL");
		printf("%d\n", format);
	}

	size_t Hexdump(const unsigned char * base, size_t len)
	{
		size_t i, j, h;
		for (i = 0; i < (len / 0x10) + 1; i++)
		{
			for (j = 0; j < 0x10; j++)
			{
				h = (i * 0x10) + j;

				if (h >= len)
				{
					break;
				}

				if (h % 16 == 0)
				{
					if (h % 0x80 == 0)
					{
						if (i != 0)
						{
							printf("\n");
						}

						color_printf("\e[0;35m", "%- 6X", h);
						printf(" -> ");
					}
					else
					{
						printf("\n%- 6X -> ", (unsigned int)h);
					}
				}
				else
				{
#ifndef _WIN64
					if (h % 4 == 0)
					{
						printf(" ");
					}
#else
					if (h % 8 == 0)
					{
						printf(" ");
					}
#endif
				}

				if (base[h] >= 0x0 && base[h] <= 0x1F) // 0x0 - 0x1F
					color_printf("\e[0;31m", "%02X ", base[h]);
				else if (base[h] >= 0x20 && base[h] <= 0x7E) // 0x20 - 0x7E
					color_printf("\e[0;97m", "%02X ", base[h]);
				else if (base[h] >= 0x7F && base[h] <= 0xFF) // 0x20 - 0x7E
					color_printf("\e[0;90m", "%02X ", base[h]);
			}
			printf("  ");
			for (j = 0; j < 0x10; j++)
			{
				h = (i * 0x10) + j;

				if (h >= len)
				{
					break;
				}

				if (base[h] >= 0x0 && base[h] <= 0x1F) // 0x0 - 0x1F
					color_printf("\e[0;31m", ".");
				else if (base[h] >= 0x20 && base[h] <= 0x7E) // 0x20 - 0x7E
				{
					switch (base[h])
					{
					case 0x25: // Weird stuff with this char
						color_printf("\e[0;97m", "%%%%");
						break;
					default:
						color_printf("\e[0;97m", "%c", base[h]);
						break;
					}
				}
				else if (base[h] >= 0x7F && base[h] <= 0xFF) // 0x20 - 0x7E
					color_printf("\e[0;37m", ".");
			}
		}
		printf("\n");
		return i;
	}
}
